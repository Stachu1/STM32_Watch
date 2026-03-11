#include "stm32l0x1_peripherals.h"
#include "intrin.h"
#include "types.h"

#define EVER (;;)
#define SYSCLK 32000000
#define BAUD 115200
#define TS_CAL1 *((u16*) 0x1FF8007A)
#define TS_CAL2 *((u16*) 0x1FF8007E)
#define VREFINT_CAL *((u16*) 0x1FF80078)
#define FIXED_SHIFT 16
#define FIXED_ONE (1 << FIXED_SHIFT)
#define IMU_ADDR 0x6A               // I2C address of the LSM6DSM IMU (SA0 pulled low)
#define MAX_BRIGHTNESS_LEVEL 6      // 1 << MAX_BRIGHTNESS_LEVEL = BRIGHTNESS_STEPS
#define MIN_BRIGHTNESS_LEVEL 3      // Lowest brightness level (too low causes flickering and instability in the effect)
#define BRIGHTNESS_STEPS (1 << MAX_BRIGHTNESS_LEVEL) // Number of steps in the brightness control (Also changes frame rate)
#define DEBOUNCE_TIME 50            // ms to debounce button presses
#define STATS_FRAME_TIME 50         // ms between each frame in the stats animation
#define PENDULUM_SIM_DT 8           // ms between each physics update in pendulum sim mode
#define PENDULUM_FRICTION 330       // Friction applied to pendulums in pendulum sim mode (Q32)
#define INACTIVITY_TIMEOUT 5000     // ms of inactivity before entering Stop Mode
#define STATISTIC_MODE_TIMEOUT 15000    // ms before switching entering Stope Mode from stats mode due to inactivity
#define PENDULUM_SIM_INACTIVITY_SPEED 5500  // min speed before entering Stop Mode (Q32)1 = 2*Pi/s


typedef i32 q32;

typedef struct {
    u8 new_value;           // New value to set the hand to (1->12 0 for off)
    u8 value;               // Value of the hand (1-12 0 for off)
    u8 brightness;          // Brightness of the hand (0-(BRIGHTNESS_STEPS-1))
    u8 tick;                // Tick counter for breathing effect
    u8 tick_div;            // Tick divider for breathing speed control
    b8 fading_in;           // Whether the hand is currently fading in or out
} Hand;

typedef struct {
    volatile u32* port;     // Pointer to GPIO port
    u8 pin;                 // Pin number for the LED
} LED;

typedef struct {
    b8 pressed;             // Button was pressed flag (set after release if press was valid)
    u32 press_time;         // Time when the button was pressed (in ms)
} BTN;

Hand hands[3] = {
    {0, 0, 0, 0, 0, true},  // Hour hand is static
    {0, 0, 0, 0, 5, true},  // Minute hand oscillates with tick_div of 5
    {0, 0, 0, 0, 1, true}   // Second hand oscillates with tick_div of 1
};

const volatile LED leds[] = {
    {(volatile u32*)GPIOB, 5},   // LED 1: PB5
    {(volatile u32*)GPIOB, 3},   // LED 2: PB3
    {(volatile u32*)GPIOA, 12},  // LED 3: PA12
    {(volatile u32*)GPIOB, 2},   // LED 4: PB2
    {(volatile u32*)GPIOA, 7},   // LED 5: PA7
    {(volatile u32*)GPIOA, 6},   // LED 6: PA6
    {(volatile u32*)GPIOA, 5},   // LED 7: PA5
    {(volatile u32*)GPIOA, 4},   // LED 8: PA4
    {(volatile u32*)GPIOA, 1},   // LED 9: PA1
    {(volatile u32*)GPIOB, 8},   // LED 10: PB8
    {(volatile u32*)GPIOB, 7},   // LED 11: PB7
    {(volatile u32*)GPIOB, 6}    // LED 12: PB6
};

// Sine LUT with 64 entries for 0-360 degrees (scaled to Q32)
const q32 SIN_LUT[64] = {
    0, 6423, 12785, 19024, 25079, 30893, 36409, 41575,
    46340, 50660, 54491, 57800, 60564, 62755, 64348, 65323,
    65636, 65323, 64348, 62755, 60564, 57800, 54491, 50660,
    46340, 41575, 36409, 30893, 25079, 19024, 12785, 6423,
    0, -6423, -12785, -19024, -25079, -30893, -36409, -41575,
    -46340, -50660, -54491, -57800, -60564, -62755, -64348, -65323,
    -65636, -65323, -64348, -62755, -60564, -57800, -54491, -50660,
    -46340, -41575, -36409, -30893, -25079, -19024, -12785, -6423
};

const u8 hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
BTN btn_up, btn_down;
volatile u32 pwm_step = BRIGHTNESS_STEPS * 3;
volatile u8 sub_millis = 0;
u32 millis = 0;
u32 last_activity = 0;
u8 brightness_level = MAX_BRIGHTNESS_LEVEL;

enum Mode {
    MODE_TIME,
    MODE_VOLTAGE,
    MODE_TEMPERATURE,
    MODE_TIME_SETTING,
    MODE_PENDULUM_SIM
} current_mode;


void Spin(u32);
void Delay_us(u32);
void Delay_ms(u32);
void GPIO_Init(void);
void TIM21_Init(void);
void Hand_Set(u8, u8);
void UART_Init(void);
void UART_Deinit(void);
void Print_char(u8);
void Print_str(c*);
void Print_u32(u32);
void Print_i32(i32);
void Print_q32(q32);
u8 Ambient_Sense(void);
void ADC_Init(void);
void ADC_Deinit(void);
u32 ADC_Get_VDDA(void);
i32 ADC_Get_Temp(void);
void I2C_Init(void);
void I2C_Write(u8, u8, u8*, u8);
void I2C_Read(u8, u8, u8*, u8);
void IMU_Init(void);
void IMU_Get_Accel(i16*, i16*, i16*);
i32 IMU_Get_Temp(void);
void RTC_Init(void);
void RTC_Set_Time(u8, u8, u8);
void RTC_Get_Time(u8*, u8*, u8*);
void RTC_Wakeup_Init(void);
void RTC_Set_Hands(void);
void BTN_Init(void);
void Mode_Handler(void);
void Mode_Voltage_Handler(b8);
void Mode_Temperature_Handler(b8);
void Mode_Time_Setting_Handler(b8);
void Mode_Particle_Sim_Handler(b8);
void Enter_Stop_Mode(void);
void Wakeup_Handler(void);

// TODO: Lower Accel freq when going to sleep & disable double tap
// TODO: Power and speed optimization


void main(void)
{
    GPIO_Init();
    TIM21_Init();
    UART_Init();
    ADC_Init();
    RTC_Init();
    RTC_Wakeup_Init();
    I2C_Init();
    IMU_Init();
    BTN_Init();

    RTC_Set_Time(10, 15, 30);
    RTC_Set_Hands();


    for EVER
    {
        Mode_Handler();

        if ((current_mode != MODE_VOLTAGE && current_mode != MODE_TEMPERATURE &&
            millis - last_activity > INACTIVITY_TIMEOUT) || (millis - last_activity > STATISTIC_MODE_TIMEOUT))
        {
            Enter_Stop_Mode();
            Wakeup_Handler();
        }
    }
}

// === ISR ===

// TIM21 Interrupt Handler for SW PWM control of LEDs
// (1.8% CPU | 3us ~ 96 cycles @ 6kHz)
void TIM21_IRQ_Handler(void)
{
    // Clear flag
    TIM21->SR &= ~TIM21_SR_UIF;

    // Update millis
    sub_millis++;
    if (sub_millis == 10) // ~10 kHz / 10 ~= 1 kHz for millis update
    {
        sub_millis = 0;
        millis++;
    }

    // Begin new PWM cycle
    pwm_step++;
    if (pwm_step >= BRIGHTNESS_STEPS * 3)
    {
        // Reset pwm_step
        pwm_step = 0;
        for (u8 i=0; i<3; i++)
        {
            // Update hand value to new_value
            // (prevents ghosting when hand value changes durring its time slot)
            if (hands[i].new_value != 255)
            {
                hands[i].value = hands[i].new_value;    // Update hand value to new_value
                hands[i].new_value = 255;               // Reset new_value
                if ((1 << brightness_level) < hands[i].brightness)
                {
                    // Make sure max brightness is not exceeded (Hands are reset every brightness change)
                    hands[i].brightness = (1 << brightness_level);
                }
            }

            // Set brightness and continue if hand is static
            if (hands[i].tick_div == 0)
            {
                hands[i].brightness = (1 << brightness_level);
                continue;
            };

            // Update tick and handle breathing effect
            hands[i].tick++;
            if (hands[i].tick == hands[i].tick_div)
            {
                // Reset tick and update brightness
                hands[i].tick = 0;
                u8 b_step = (1 << (brightness_level - MIN_BRIGHTNESS_LEVEL));
                if (hands[i].fading_in)
                {
                    // Increase brightness until max, then start fading out
                    if (hands[i].brightness + b_step > (1 << brightness_level))
                    {
                        hands[i].fading_in = false;
                        hands[i].brightness -= b_step;
                    }
                    else hands[i].brightness += b_step;
                }
                else
                {
                    // Decrease brightness until min, then start fading in
                    if (hands[i].brightness - b_step < 0)
                    {
                        hands[i].fading_in = true;
                        hands[i].brightness += b_step;
                    }
                    else hands[i].brightness -= b_step;
                }
            }
        }
    }

    // Get hand index for the current time slot
    u8 hand_idx = pwm_step / BRIGHTNESS_STEPS;
    u8 local_step = pwm_step % BRIGHTNESS_STEPS;

    // Turn off previous hand LED and turn on the LED for the current hand at the start of its brightness cycle
    if (local_step == 0)
    {
        // Turn off all LEDs
        GPIOA->BSRR = 0b1000011110010 << 16;
        GPIOB->BSRR = 0b111101100 << 16;

        if (hands[hand_idx].brightness > 0 && hands[hand_idx].value > 0)
        {
            u8 led_on = hands[hand_idx].value - 1;
            leds[led_on].port[6] = (1 << leds[led_on].pin);
        }
    }

    // Turn off the LED for the current hand at the end of its brightness cycle
    if (local_step >= hands[hand_idx].brightness && hands[hand_idx].value > 0)
    {
        u8 led_off = hands[hand_idx].value - 1;
        leds[led_off].port[6] = (1 << (leds[led_off].pin + 16));
    }
}

// 1Hz RTC Interrupt Handler for hands update
// (5.25us ~ 168 cycles)
void RTC_IRQ_Handler(void)
{
    // Clear EXTI Pending bit FIRST
    EXTI->PR = EXTI_PR_PIF20;

    // Check if Wakeup Timer caused the interrupt
    if (RTC->ISR & RTC_ISR_WUTF) 
    {
        // Clear RTC Wakeup Flag
        RTC->WPR = 0xCA;
        RTC->WPR = 0x53;
        RTC->ISR &= ~RTC_ISR_WUTF;
        RTC->WPR = 0xFF; // Re-lock

        if (current_mode == MODE_TIME)
        {
            RTC_Set_Hands();
        }
    }
}

// EXTI Interrupt Handler for buttons
// (2us ~ 64 cycles)
void EXTI0_1_IRQ_Handler(void)
{
    // Check PB0 btn_down
    if (EXTI->PR & (1 << 0))
    {
        if (!(GPIOB->IDR & (1 << 0)))
        {
            // LOW -> Falling Edge (PRESSED)
            btn_down.press_time = millis;
        }
        else
        {
            // HIGH -> Rising Edge (RELEASED)
            if (millis > btn_down.press_time && millis - btn_down.press_time >= DEBOUNCE_TIME)
            {
                btn_down.pressed = true;
            }
        }
        EXTI->PR = (1 << 0); // Clear the flag
    }

    // Check PB1 btn_up
    if (EXTI->PR & (1 << 1))
    {
        if (!(GPIOB->IDR & (1 << 1)))
        {
            // LOW -> Falling Edge (PRESSED)
            btn_up.press_time = millis;
        }
        else
        {
            // HIGH -> Rising Edge (RELEASED)
            if (millis > btn_up.press_time && millis - btn_up.press_time >= DEBOUNCE_TIME)
            {
                btn_up.pressed = true;
            }
        }
        EXTI->PR = (1 << 1); // Clear the flag
    }
    last_activity = millis;
}

// EXTI Interrupt Handler for IMU AWT & Double Tap
void EXTI4_15_IRQ_Handler(void)
{
    // Check PA8 (INT2 - Wrist Tilt)
    if (EXTI->PR & (1 << 8))
    {
        EXTI->PR = (1 << 8); // Clear the flag
    }

    // Check PA15 (INT1 - Double Tap)
    if (EXTI->PR & (1 << 15))
    {
        EXTI->PR = (1 << 15); // Clear the flag
        Print_str("Changing brightness\n");
        brightness_level = (brightness_level == MAX_BRIGHTNESS_LEVEL) ? MIN_BRIGHTNESS_LEVEL : brightness_level + 1;
    }
    last_activity = millis;
}

// === Utility Functions ===

// Do nothing for 4 clock cyles
void Spin(u32 count)
{
    while (count--) __asm__ volatile ("nop");
}

// Delay microseconds based on Spin 
// (for delay above 100ms use Delay_ms)
void Delay_us(u32 us)
{
    u32 spins = (us * (SYSCLK/1000)) / 4000;
    Spin(spins);
}

// Delay milliseconds based on Delay_us
void Delay_ms(u32 ms)
{
    (void)ms;
    u32 hundereds = ms / 100;
    u32 rest = ms - hundereds * 100;
    for (u32 i=0; i<hundereds; i++)
    {
        Delay_us(100000);
    }
    Delay_us(rest * 1000);
}

// Init GPIOs for the LEDs
void GPIO_Init(void)
{
    // Enable GPIOA and GPIOB clocks
    RCC->IOPENR |= RCC_IOPENR_IOPAEN | RCC_IOPENR_IOPBEN;

    // Set PA1, PA4, PA5, PA6, PA7, PA12 to output (MODE = 01)
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE1, 0x1);   // PA1 as output
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE4, 0x1);   // PA4 as output
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE5, 0x1);   // PA5 as output
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE6, 0x1);   // PA6 as output
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE7, 0x1);   // PA7 as output
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE12, 0x1);  // PA12 as output

    // Set PB2, PB3, PB5, PB6, PB7, PB8 to output (MODE = 01)
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE2, 0x1);   // PB2 as output
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE3, 0x1);   // PB3 as output
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE5, 0x1);   // PB5 as output
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE6, 0x1);   // PB6 as output
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE7, 0x1);   // PB7 as output
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE8, 0x1);   // PB8 as output
}

// Init TIM21 and enable its interrupt
// for SW PWM control of the LEDs and ms couunting
void TIM21_Init(void)
{
    // Enable TIM21 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM21EN;

    // Run at full 32MHz
    TIM21->PSC = 0;
    TIM21->ARR = 3200; // 32MHz / 3200 ~ 10kHz for LED PWM updates
    
    // Enable update interrupt and start counter
    TIM21->DIER |= TIM21_DIER_UIE;
    TIM21->CR1 |= TIM21_CR1_CEN;

    // Enable TIM21 interrupt in NVIC
    NVIC->ISER |= (1 << 20);
}

// Set the value of a hand (1-12, 0 for off)
inline void Hand_Set(u8 hand_index, u8 value)
{
    if (hand_index > 2 || value > 12) return;
    if (value > 12) return;
    hands[hand_index].new_value = value;
}

// Init UART at #BUAD
void UART_Init(void)
{
    // Enable clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    
    // Set alterative pin func
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE2, 0x2);   // PA2
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE3, 0x2);   // PA3

    // Enable alterative func
    BF_SET(GPIOA->AFRL, GPIOA_AFRL_AFSEL2, 0x4);    // PA2
    BF_SET(GPIOA->AFRL, GPIOA_AFRL_AFSEL3, 0x4);    // PA3

    // Disable USART
    USART2->CR1 &= ~USART2_CR1_UE;

    // Set word len, Parity ctrl, 1 Stop bit, Enable TX
    USART2->CR1 &= ~(USART2_CR1_M0 | USART2_CR1_M1);
    USART2->CR1 &= ~USART2_CR1_PCE;
    BF_SET(USART2->CR2,USART2_CR2_STOP, 0x0);
    USART2->CR1 |= USART2_CR1_TE;

    // Set USART div (sysclk / baud_rate)
    USART2->BRR = (SYSCLK / BAUD) & 0xFFFF;         

    // Enable USART
    USART2->CR1 |= USART2_CR1_UE;
}

// Deinit UART
void UART_Deinit(void)
{
    // Disable UART
    USART2->CR1 &= ~USART2_CR1_UE;

    // Reset UART
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;

    // Set PA2 and PA3 back to Analog Mode (0x3)
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE2, 0x3);
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE3, 0x3);

    // Clear AF selection
    BF_SET(GPIOA->AFRL, GPIOA_AFRL_AFSEL2, 0x0);
    BF_SET(GPIOA->AFRL, GPIOA_AFRL_AFSEL3, 0x0);

    // Disable clock
    RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
}

// Sends char over UART
void Print_char(u8 c)
{
    while (!(USART2->ISR & USART2_ISR_TXE)) Spin(1);
    BF_SET(USART2->TDR, USART2_TDR_TDR, c);
}

// Sends string over UART
void Print_str(c *str)
{
    while (*str)
    {
        Print_char(*(str++));
    }
}

// Sends u32 over UART
void Print_u32(u32 num)
{
    if (num == 0)
    {
        Print_char('0');
        return;
    }

    u8 digits[10];  
    u32 num_len = 0;

    while (num)
    {
        digits[num_len++] = '0' + (num % 10);
        num /= 10;
    }

    for (u32 i=num_len; i>0; i--)
    {
        Print_char(digits[i - 1]);
    }
}

// Sends i32 over UART
void Print_i32(i32 num)
{
    if (num == 0)
    {
        Print_char('0');
        return;
    }

    b32 is_neg = (num < 0) ? true : false;
    if (is_neg) num = -num;

    u8 digits[10];  
    u32 num_len = 0;

    while (num)
    {
        digits[num_len++] = '0' + (num % 10);
        num /= 10;
    }

    if (is_neg) Print_char('-');
    for (u32 i=num_len; i>0; i--)
    {
        Print_char(digits[i - 1]);
    }
}

// Sends q32 (q16.16) over UART
void Print_q32(q32 num)
{
    if (num == 0)
    {
        Print_str("0.0000");
        return;
    }

    if (num < 0)
    {
        Print_char('-');
        num = -num;
    }

    u32 int_part = (u32)(num >> FIXED_SHIFT);
    u32 frac_part = ((u32)(num & (FIXED_ONE - 1)) * 10000) >> FIXED_SHIFT;

    Print_u32(int_part);
    Print_char('.');

    // Print leading zeros for the fraction
    if (frac_part < 1000) Print_char('0');
    if (frac_part < 100)  Print_char('0');
    if (frac_part < 10)   Print_char('0');
    
    Print_u32(frac_part);
}

// Get Ambient light intensity
// May take a while in low light (~500ms)
u8 Ambient_Sense(void)
{
    u32 ambl = 0;
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE4, 0x1);   // PB4 as output
    GPIOB->BSRR |= GPIOB_BSRR_BS4;
    Delay_ms(1);
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE4, 0x0);   // PB4 as input
    while (GPIOB->IDR & GPIOB_IDR_ID4 && ambl != 2080768) ambl++;
    return (u8)(255 - (ambl >> 13));
}

// Init ADC for measuring battery voltage and core temperature
void ADC_Init(void)
{
    // Enable clock
    RCC->APB2ENR |= RCC_APB2ENR_ADCEN;

    // Disable ADC
    if (ADC->CR & ADC_CR_ADEN)
    {
        ADC->CR |= ADC_CR_ADDIS;
        while (ADC->CR & ADC_CR_ADEN) Spin(1);
    }

    // Calibration
    ADC->CR |= ADC_CR_ADCAL;
    while (ADC->CR & ADC_CR_ADCAL) Spin(1);

    // Config ADC
    ADC->CFGR1 |= ADC_CFGR1_DISCEN;
    ADC->CFGR1 &= ~ADC_CFGR1_CONT;
    ADC->CCR |= (ADC_CCR_TSEN | ADC_CCR_VREFEN);
    ADC->SMPR |= ADC_SMPR_SMPR_WIDTH;

    // Configure Oversampling x256 & 8 bit shift
    ADC->CFGR2 |= ADC_CFGR2_OVSE;
    BF_SET(ADC->CFGR2, ADC_CFGR2_OVSR, 0x7);
    BF_SET(ADC->CFGR2, ADC_CFGR2_OVSS, 0x8);

    // Enable ADC
    ADC->ISR |= ADC_ISR_ADRDY;
    ADC->CR |= ADC_CR_ADEN;
    while (!(ADC->ISR & ADC_ISR_ADRDY)) Spin(1);
}

// Deinit ADC
void ADC_Deinit(void)
{
    // Stop ongoint conversions
    if (ADC->CR & ADC_CR_ADSTART)
    {
        ADC->CR |= ADC_CR_ADSTP;
        while (ADC->CR & ADC_CR_ADSTP) Spin(1);
    }

    // Disable ADC
    if (ADC->CR & ADC_CR_ADEN)
    {
        ADC->CR |= ADC_CR_ADDIS;
        while (ADC->CR & ADC_CR_ADEN) Spin(1);
    }

    // Disable voltage references
    ADC->CCR &= ~(ADC_CCR_TSEN | ADC_CCR_VREFEN);

    // Disable ADC voltage regulator
    ADC->CR |= ADC_CR_ADVREGEN;

    // Disable peripheral clock
    RCC->APB2ENR &= ~RCC_APB2ENR_ADCEN;
}

// Measures VDDA in mV
// (Needs ADC_Init)
u32 ADC_Get_VDDA(void)
{
    // Set Vref & Max conversion time
    ADC->CHSELR = ADC_CHSELR_CHSEL17;

    // Turn off the LEDs to reduce voltage drop druring measurment
    u8 h = hands[0].value;
    u8 m = hands[1].value;
    u8 s = hands[2].value;
    Hand_Set(0, 0);
    Hand_Set(1, 0);
    Hand_Set(2, 0);

    // Wait for hands to update
    while (hands[2].new_value != 255) Spin(1);
    // Start ADC conversion, wait, read
    ADC->CR |= ADC_CR_ADSTART;
    while (!(ADC->ISR & ADC_ISR_EOC)) Spin(1);
    Hand_Set(0, h);
    Hand_Set(1, m);
    Hand_Set(2, s);

    u32 raw_vref = (u32)(ADC->DR & ADC_DR_DATA_MASK);
    u32 vdda_mV = (3000 * VREFINT_CAL) / raw_vref;
    return vdda_mV;
}

// Measures core temperature in m°C
// (Needs ADC_Init)
i32 ADC_Get_Temp(void)
{
    // Get VDDA
    u32 vdda_mV = ADC_Get_VDDA();

    // Set Tsen & Max conversion time
    ADC->CHSELR = ADC_CHSELR_CHSEL18;

    // Start ADC conversion, wait, read
    ADC->CR |= ADC_CR_ADSTART;
    while (!(ADC->ISR & ADC_ISR_EOC)) Spin(1);
    u32 raw_tsen = (u32)(ADC->DR & ADC_DR_DATA_MASK);
    u32 tsen_cal =  raw_tsen * vdda_mV / 3000;

    // (TS_CAL2_TEMP - TS_CAL1_TEMP) / (rav_Tsen - TS_CAL1) + TS_CAL1_TEMP
    i32 core_temp = 100000 / (TS_CAL2 - TS_CAL1) * (tsen_cal - TS_CAL1) + 30000;
    return core_temp;
}

// Init I2C for the IMU
void I2C_Init(void)
{
    // Enable clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    // Set alterative pin func
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE9, 0x2);   // PA9
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE10, 0x2);  // PA10

    // Set output open-drain
    GPIOA->OTYPER |= (GPIOA_OTYPER_OT9 | GPIOA_OTYPER_OT10);

    // Set high speed
    BF_SET(GPIOA->OSPEEDR, GPIOA_OSPEEDR_OSPEED9, 0x2);
    BF_SET(GPIOA->OSPEEDR, GPIOA_OSPEEDR_OSPEED10, 0x2);
    
    // Enable alterative func
    BF_SET(GPIOA->AFRH, GPIOA_AFRH_AFSEL9, 0x1);    // PA9
    BF_SET(GPIOA->AFRH, GPIOA_AFRH_AFSEL10, 0x1);   // PA10

    // Disable I2C
    I2C1->CR1 &= ~I2C1_CR1_PE;
    
    // Configure timing
    BF_SET(I2C1->TIMINGR, I2C1_TIMINGR_PRESC, 0x03);
    BF_SET(I2C1->TIMINGR, I2C1_TIMINGR_SCLL, 0x13);
    BF_SET(I2C1->TIMINGR, I2C1_TIMINGR_SCLH, 0x0F);
    BF_SET(I2C1->TIMINGR, I2C1_TIMINGR_SCLDEL, 0x04);
    BF_SET(I2C1->TIMINGR, I2C1_TIMINGR_SDADEL, 0x02);
    
    // Enable I2C
    I2C1->CR1 |= I2C1_CR1_PE;
}

// Write data to a slave reg @ addr, reg over I2C
void I2C_Write(u8 addr, u8 reg, u8 *data, u8 size)
{
    // Wait until I2C is not busy
    while (I2C1->ISR & I2C1_ISR_BUSY) Spin(1);

    // Set address, number of bytes, and generate START
    I2C1->CR2 = (addr << 1);
    BF_SET(I2C1->CR2, I2C1_CR2_NBYTES, size + 1);
    I2C1->CR2 |= I2C1_CR2_START | I2C1_CR2_AUTOEND;

    // Select the reg
    while (!(I2C1->ISR & I2C1_ISR_TXIS)) Spin(1);
    I2C1->TXDR = reg;

    // Transmit the data
    for (u32 i = 0; i < size; i++)
    {
        while (!(I2C1->ISR & I2C1_ISR_TXIS)) Spin(1);
        I2C1->TXDR = data[i];
    }

    // Wait for stop flag (set by AUTOEND)
    while (!(I2C1->ISR & I2C1_ISR_STOPF)) Spin(1);

    // Clear stop flag
    I2C1->ICR |= I2C1_ICR_STOPCF;            
}

// Read data from a slave reg @ addr, reg over I2C
void I2C_Read(u8 addr, u8 reg, u8 *buf, u8 size)
{
    // Wait until I2C is not busy
    while (I2C1->ISR & I2C1_ISR_BUSY) Spin(1);

    I2C1->CR2 = (addr << 1) | (1 << 16); // NBYTES = 1
    I2C1->CR2 |= I2C1_CR2_START; 
    
    while (!(I2C1->ISR & I2C1_ISR_TXIS)) Spin(1);
    I2C1->TXDR = reg;
    while (!(I2C1->ISR & I2C1_ISR_TC)) Spin(1);

    // Restart and Read
    I2C1->CR2 = (addr << 1) | I2C1_CR2_RD_WRN | (size << 16) | I2C1_CR2_START | I2C1_CR2_AUTOEND;
    
    for (int i = 0; i < size; i++)
    {
        while (!(I2C1->ISR & I2C1_ISR_RXNE)) Spin(1);
        buf[i] = I2C1->RXDR;
    }

    while (!(I2C1->ISR & I2C1_ISR_STOPF)) Spin(1);
    I2C1->ICR |= I2C1_ICR_STOPCF;
}

// Init the LSM6DSM IMU
void IMU_Init(void)
{
    // === Set Accel to 416Hz, +/- 4g ===
    // CTRL1_XL register (ODR_XL) (FS_XL)
    u8 buf = (0x6 << 4) | (0x2 << 2);
    I2C_Write(IMU_ADDR, 0x10, &buf, 1);

    // === Enables double tap detection ===
    // TAP_CFG register (INTERRUPTS_ENABLE) (TAP_Z_EN)
    buf = (0x1 << 7) | (0x7 << 1);
    I2C_Write(IMU_ADDR, 0x58, &buf, 1);

    // TAP_THS_6D register (TAP_THS)
    buf = 0x5;
    I2C_Write(IMU_ADDR, 0x59, &buf, 1);
    // INT_DUR2 register (DUR3:0) (QUIET1:0) (SHOCK1:0)
    buf = (0x5 << 4) | (0x5 << 2) | (0x3);
    I2C_Write(IMU_ADDR, 0x5A, &buf, 1);
    // WAKE_UP_THS register (SINGLE_DOUBLE_TAP)
    buf = (0x1 << 7);
    I2C_Write(IMU_ADDR, 0x5B, &buf, 1);

    // === Enable absolute wrist tilt detection == 
    // CTRL10_C register (WRIST_TILT_EN) (FUNC_EN)
    buf = (0x1 << 7) | (0x1 << 2);
    I2C_Write(IMU_ADDR, 0x19, &buf, 1);
    // FUNC_CFG_ACCESS (FUNC_CFG_EN) ( FUNC_CFG_EN_B)
    buf = (0x1 << 7) | (0x1 << 5);
    I2C_Write(IMU_ADDR, 0x01, &buf, 1);

    // A_WRIST_TILT_THS Absolute Wrist Tilt threshold register 1 LSB = 15.625 mg
    buf = 0x32;
    I2C_Write(IMU_ADDR, 0x58, &buf, 1);
    // A_WRIST_TILT_Mask register (Xneg) (Zpos)
    buf = (0x1 << 3);
    I2C_Write(IMU_ADDR, 0x59, &buf, 1);
    // Disable embedded functions register
    buf = 0x0;
    I2C_Write(IMU_ADDR, 0x01, &buf, 1);

    // === Interrupt routing ===
    // MD1_CFG register (INT1_DOUBLE_TAP)
    buf = (0x1 << 3);
    I2C_Write(IMU_ADDR, 0x5E, &buf, 1);
    // DRDY_PULSE_CFG register (INT2_WRIST_TILT)
    buf = 0x1;
    I2C_Write(IMU_ADDR, 0x0B, &buf, 1);

    // === Setupt MCU interrupts for IMU events ===
    // Enable SYSCFG Clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // Configure PA8 and PA15 as Input
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE8, 0x0);
    BF_SET(GPIOA->MODER, GPIOA_MODER_MODE15, 0x0);

    // Map PA8 and PA15 to EXTI Line 8 and 15
    BF_SET(SYSCFG_COMP->EXTICR3, SYSCFG_COMP_EXTICR3_EXTI8, 0x0);
    BF_SET(SYSCFG_COMP->EXTICR4, SYSCFG_COMP_EXTICR4_EXTI15, 0x0);

    // Enable Rising Edge triggers
    EXTI->RTSR |= (EXTI_RTSR_RT8 | EXTI_RTSR_RT15);
    EXTI->IMR  |= (EXTI_IMR_IM8 | EXTI_IMR_IM15);

    // Enable EXTI4_15 Interrupt (IRQ 7)
    NVIC->ISER |= (1 << 7);
}

// Read acceleration from the IMU
void IMU_Get_Accel(i16 *x, i16 *y, i16 *z)
{
    u8 buf[6];
    I2C_Read(IMU_ADDR, 0x28, buf, 6);
    *x = (i16)((buf[1] << 8) | buf[0]);
    *y = (i16)((buf[3] << 8) | buf[2]);
    *z = (i16)((buf[5] << 8) | buf[4]);
}

// Read temperature from the IMU in m°C
i32 IMU_Get_Temp(void)
{
    u8 buf[2];
    I2C_Read(IMU_ADDR, 0x1E, buf, 1);
    if ((buf[0] & (1 << 2)) == 0) return 0; // Temp data not ready
    I2C_Read(IMU_ADDR, 0x20, buf, 2);

    // Convert raw value to m°C
    // 256 LSB/°C val=0 @25°C =>  m°C = °C*1000 + ((°C/256) * 39 + 5) / 10 + 25000
    return (i32)buf[1] * 1000 + (buf[0] * 39 + 5) / 10 + 25000;
}


// Init RTC for hand updates every second
void RTC_Init(void)
{
    // Disable backup domain write protection
    PWR->CR |= PWR_CR_DBP;

    // Start LSE and wait until ready
    if (!(RCC->CSR & RCC_CSR_LSERDY))
    {
        RCC->CSR |= RCC_CSR_LSEON;
        while (!(RCC->CSR & RCC_CSR_LSERDY)) Spin(10);
    }

    // Set LSE as RTC clock source
    BF_SET(RCC->CSR, RCC_CSR_RTCSEL, 0x1);

    // Enable RTC
    RCC->CSR |= RCC_CSR_RTCEN;
}

// Set RTC time (12h format, hours max 12)
void RTC_Set_Time(u8 hours, u8 minutes, u8 seconds)
{
    // Wait for RTC to be ready
    RTC->ISR &= ~RTC_ISR_RSF;
    while (!(RTC->ISR & RTC_ISR_RSF)) Spin(10);

    // Disable write protection
    RTC->WPR = 0xCA;
    RTC->WPR = 0x53;

    // Enter initialization mode
    RTC->ISR |= RTC_ISR_INIT;
    while (!(RTC->ISR & RTC_ISR_INITF)) Spin(10);

    // Set RTC prescaler for 1Hz time base (LSE is 32.768 kHz)
    BF_SET(RTC->PRER, RTC_PRER_PREDIV_A, 0x7F);
    BF_SET(RTC->PRER, RTC_PRER_PREDIV_S, 0xFF);

    // Set 12h format
    RTC->CR |= RTC_CR_FMT;

    // Set time in BCD format
    u32 temp_tr = 0;
    temp_tr |= ((hours / 10) << RTC_TR_HT_LSB) | ((hours % 10) << RTC_TR_HU_LSB);
    temp_tr |= ((minutes / 10) << RTC_TR_MNT_LSB) | ((minutes % 10) << RTC_TR_MNU_LSB);
    temp_tr |= ((seconds / 10) << RTC_TR_ST_LSB) | (seconds % 10);
    RTC->TR = temp_tr;

    // Exit initialization mode
    RTC->ISR &= ~RTC_ISR_INIT;

    // Wait for synchronization
    RTC->ISR &= ~RTC_ISR_RSF; 
    while (!(RTC->ISR & RTC_ISR_RSF)) Spin(10);

    // Enable write protection
    RTC->WPR = 0xFF;
}

// Get RTC time
void RTC_Get_Time(u8 *hours, u8 *minutes, u8 *seconds)
{
    // Wait for RTC to be ready
    RTC->ISR &= ~RTC_ISR_RSF;
    while (!(RTC->ISR & RTC_ISR_RSF)) Spin(10);

    // Read time
    u32 tr = RTC->TR;
    *hours = ((tr & RTC_TR_HT_MASK) >> RTC_TR_HT_LSB) * 10 + ((tr & RTC_TR_HU_MASK) >> RTC_TR_HU_LSB);
    *minutes = ((tr & RTC_TR_MNT_MASK) >> RTC_TR_MNT_LSB) * 10 + ((tr & RTC_TR_MNU_MASK) >> RTC_TR_MNU_LSB);
    *seconds = ((tr & RTC_TR_ST_MASK) >> RTC_TR_ST_LSB) * 10 + ((tr & RTC_TR_SU_MASK) >> RTC_TR_SU_LSB);
}

// Enable RTC 0.2Hz interrupt for hand updates
void RTC_Wakeup_Init(void)
{
    // Wait for RTC to be ready
    RTC->ISR &= ~RTC_ISR_RSF;
    while (!(RTC->ISR & RTC_ISR_RSF)) Spin(10);

    // Disable Write Protection
    RTC->WPR = 0xCA;
    RTC->WPR = 0x53;

    // Disable Wakeup Timer to configure it
    RTC->CR &= ~RTC_CR_WUTE;

    // Wait for access allowed
    while (!(RTC->ISR & RTC_ISR_WUTWF)) Spin(10);

    // Configure Clock Source for 1Hz
    // WUCKSEL = 0b100 selects the 1Hz clock (RTCCLK div by prescalers)
    RTC->CR &= ~(RTC_CR_WUCKSEL_MASK << RTC_CR_WUCKSEL_LSB);
    RTC->CR |= (0x4 << RTC_CR_WUCKSEL_LSB);

    // Clear Wakeup Timer flag and EXTI pending bit
    RTC->ISR &= ~RTC_ISR_WUTF;
    EXTI->PR = EXTI_PR_PIF20;

    // For 0.2Hz clock, WUTR = 4 means 5 second interval (Interval = WUTR + 1)
    RTC->WUTR = 4;

    // Enable Interrupt and Timer
    RTC->CR |= RTC_CR_WUTIE | RTC_CR_WUTE;

    // Enable Write Protection
    RTC->WPR = 0xFF;

    // RTC Wakeup is connected to EXTI Line 20
    EXTI->IMR |= EXTI_IMR_IM20;    // Interrupt Mask: Enable line 20
    EXTI->RTSR |= EXTI_RTSR_RT20;   // Rising Trigger: Enable

    // Enable RTC global interrupt in NVIC
    NVIC->ISER |= (1 << 2);
}

// Update hand new_values based on current RTC time
void RTC_Set_Hands(void)
{
    u8 h, m, s;
    RTC_Get_Time(&h, &m, &s);

    // Set hand new_values based on current time
    Hand_Set(0, h);
    Hand_Set(1, (m / 5 == 0) ? 12 : (m / 5));
    Hand_Set(2, (s / 5 == 0) ? 12 : (s / 5));
}

// Buttons GPIO and interrupt init
void BTN_Init(void)
{
    // Enable SYSCFG Clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // Configure PB0 and PB1 as Input
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE0, 0x0);   // PB0 as input
    BF_SET(GPIOB->MODER, GPIOB_MODER_MODE1, 0x0);   // PB1 as input

    // Enable Internal Pull-Ups
    BF_SET(GPIOB->PUPDR, GPIOB_PUPDR_PUPD0, 0x1);
    BF_SET(GPIOB->PUPDR, GPIOB_PUPDR_PUPD1, 0x1);

    // Map PB0 and PB1 to EXTI Line 0 and 1
    SYSCFG_COMP->EXTICR1 &= ~(SYSCFG_COMP_EXTICR1_EXTI0_MASK | SYSCFG_COMP_EXTICR1_EXTI1_MASK);
    SYSCFG_COMP->EXTICR1 |= ((1 << SYSCFG_COMP_EXTICR1_EXTI0_LSB) | (1 << SYSCFG_COMP_EXTICR1_EXTI1_LSB));

    // Enable Rising and Falling Edge triggers
    EXTI->FTSR |= (EXTI_FTSR_FT0 | EXTI_FTSR_FT1); // Press
    EXTI->RTSR |= (EXTI_RTSR_RT0 | EXTI_RTSR_RT1); // Release
    EXTI->IMR  |= (EXTI_IMR_IM0 | EXTI_IMR_IM1);   // Unmask

    // Enable EXTI0_1 Interrupt (IRQ 5)
    NVIC->ISER |= (1 << 5);
}

// Handle mode changes and mode-specific logic
void Mode_Handler(void)
{
    switch (current_mode)
    {
        case MODE_TIME:
            if (btn_up.pressed)
            {
                btn_up.pressed = false;
                Print_str("Changing brightness\n");
                brightness_level = (brightness_level == MAX_BRIGHTNESS_LEVEL) ? MIN_BRIGHTNESS_LEVEL : brightness_level + 1;
                RTC_Set_Hands();
            }
            if (btn_down.pressed)
            {
                btn_down.pressed = false;
                Print_str("Mode voltage\n");
                current_mode = MODE_VOLTAGE;
                Mode_Voltage_Handler(true);
            }
            break;
        case MODE_VOLTAGE:
            if (btn_up.pressed)
            {
                btn_up.pressed = false;
                Print_str("Mode temperature\n");
                current_mode = MODE_TEMPERATURE;
                Mode_Temperature_Handler(true);
            }
            if (btn_down.pressed)
            {
                btn_down.pressed = false;
                Print_str("Mode time setting entry\n");
                current_mode = MODE_TIME_SETTING;
                Mode_Time_Setting_Handler(true);
            }
            Mode_Voltage_Handler(false);
            break;
        case MODE_TEMPERATURE:
            if (btn_up.pressed)
            {
                btn_up.pressed = false;
                Print_str("Mode voltage\n");
                current_mode = MODE_VOLTAGE;
                Mode_Voltage_Handler(true);
            }
            if (btn_down.pressed)
            {
                btn_down.pressed = false;
                Print_str("Mode time setting entry\n");
                current_mode = MODE_TIME_SETTING;
                Mode_Time_Setting_Handler(true);
            }
            Mode_Temperature_Handler(false);
            break;
        case MODE_TIME_SETTING:
            Mode_Time_Setting_Handler(false);
            break;
        case MODE_PENDULUM_SIM:
            if (btn_up.pressed)
            {
                btn_up.pressed = false;
                Print_str("Changing brightness\n");
                brightness_level = (brightness_level == MAX_BRIGHTNESS_LEVEL) ? MIN_BRIGHTNESS_LEVEL : brightness_level + 1;
                Hand_Set(0, hands[0].value);
            }
            if (btn_down.pressed)
            {
                btn_down.pressed = false;
                Print_str("Mode time\n");
                current_mode = MODE_TIME;
                RTC_Set_Hands();
            }
            Mode_Particle_Sim_Handler(false);
            break;
    }
}

// Voltage mode: map battery voltage to hand position
void Mode_Voltage_Handler(b8 reset)
{
    static u32 last_update = 0;
    static u8 hand_idx = 0;

    if (reset)
    {
        last_update = 0;
        u32 vdda_mV = ADC_Get_VDDA();
        Print_str("Battery Voltage: ");
        Print_u32(vdda_mV);
        Print_str(" mV\n");

        // Map 2.0V-3.2V to 0-12 hand index (100mV per step)
        hand_idx = ((vdda_mV - 2000) / 100);
        if (hand_idx > 12) hand_idx = 12;
        Hand_Set(0, 1);
        Hand_Set(1, 0);
        Hand_Set(2, 0);
        return;
    }

    // Wait for hands value to be pulled from new_value
    if (hands[0].new_value != 255) last_update = millis;

    // Update hand values gradually for smooth animation
    if (hands[0].value < hand_idx && millis - last_update >= STATS_FRAME_TIME)
    {
        last_update = millis;
        Hand_Set(0, hands[0].value + 1);
    }
}

// Temperature mode: map IMU temperature to hand position
void Mode_Temperature_Handler(b8 reset)
{
    static u32 last_update = 0;
    static u8 hand_h_idx = 0;
    static u8 hand_m_idx = 0;

    if (reset)
    {
        last_update = 0;
        u32 temp_mC = IMU_Get_Temp();
        Print_str("IMU Temperature: ");
        Print_u32(temp_mC);
        Print_str(" mC\n");

        if (temp_mC == 0)
        {
            hand_h_idx = 0;
            hand_m_idx = 0;
            Hand_Set(0, 12);
            Hand_Set(1, 12);
            Hand_Set(2, 0);
            return;
        }

        // Map 0°C-60°C to 0-12 hand_h index (5°C per step)
        // and 0.5°C per step for hand_m index
        hand_h_idx = temp_mC / 5000;
        hand_m_idx = (temp_mC - hand_h_idx * 5000) / 500;
        if (hand_h_idx > 12) hand_h_idx = 12;
        if (hand_m_idx > 12) hand_m_idx = 12;

        Hand_Set(0, 1);
        Hand_Set(1, 1);
        Hand_Set(2, 0);
        return;
    }

    // Wait for hands value to be pulled from new_value
    if (hands[0].new_value != 255) last_update = millis;

    // Update hand values gradually for smooth animation
    if ((hands[0].value < hand_h_idx || hands[1].value < hand_m_idx) && millis - last_update >= STATS_FRAME_TIME)
    {
        last_update = millis;
        if (hands[0].value < hand_h_idx)
        {
            Hand_Set(0, hands[0].value + 1);
        }
        if (hands[1].value < hand_m_idx)
        {
            Hand_Set(1, hands[1].value + 1);
        }
    }
}


void Mode_Time_Setting_Handler(b8 reset)
{
    static u32 last_update = 0;
    static enum {
        ENTRY,
        SET_HOURS,
        SET_MINUTES,
    } stage;
    static u8 h = 0, m = 0;

    if (reset)
    {
        // On entry, read RTC and round min down to nearest 5
        stage = ENTRY;
        Hand_Set(0, 0);
        Hand_Set(1, 0);
        Hand_Set(2, 0);
        return;
    }

    switch (stage)
    {
    case ENTRY:
        if (millis - last_update >= STATS_FRAME_TIME / 2)
        {
            last_update = millis;
            Hand_Set(0, (hands[0].value == 12) ? 1 : hands[0].value + 1);
        }
        if (btn_up.pressed)
        {
            btn_up.pressed = false;
            stage = SET_HOURS;
            Print_str("Setting Hours\n");
            h = 12;
            Hand_Set(0, h);
        }
        if (btn_down.pressed)
        {
            btn_down.pressed = false;
            current_mode = MODE_PENDULUM_SIM;
            Mode_Particle_Sim_Handler(true);
        }
        break;
    case SET_HOURS:
        if (btn_up.pressed)
        {
            btn_up.pressed = false;
            stage = SET_MINUTES;
            Print_str("Setting Minutes\n");
            Hand_Set(0, h);
            m = 60;
            Hand_Set(1, (m / 5 == 0) ? 12 : (m / 5));
        }
        if (btn_down.pressed)
        {
            btn_down.pressed = false;
            h = (h == 12) ? 1 : h + 1;
            Hand_Set(0, h);
        }
        break;
    case SET_MINUTES:
        if (btn_up.pressed)
        {
            btn_up.pressed = false;
            current_mode = MODE_TIME;
            RTC_Set_Time(h, m, 0);

            // Set hand new_values based on current time
            Hand_Set(0, h);
            Hand_Set(1, (m / 5 == 0) ? 12 : (m / 5));
            Hand_Set(2, 12);
            Print_str("Time Set\n");
        }
        if (btn_down.pressed)
        {
            btn_down.pressed = false;
            m = (m > 55) ? 5 : m + 5;
            Hand_Set(1, (m / 5 == 0) ? 12 : (m / 5));
        }
        break;
    }
}

// Particle sim mode: display a simple pendulum simulation
void Mode_Particle_Sim_Handler(b8 reset)
{
    static u32 last_update = 0;
    static q32 alpha = 0;
    static q32 omega = 0;

    if (reset)
    {
        alpha = 0;
        omega = 0;
        Hand_Set(0, 0);
        Hand_Set(1, 0);
        Hand_Set(2, 0);
        return;
    }

    // Update simulation every 10ms for smooth animation
    if (millis - last_update >= PENDULUM_SIM_DT)
    {
        last_update = millis;

        // Get raw accel data from IMU
        i16 raw_x, raw_y, raw_z;
        IMU_Get_Accel(&raw_x, &raw_y, &raw_z);

        // Convert raw accel (+/- 4g) to q32
        q32 accel_x = (q32)raw_x << 3;
        q32 accel_y = (q32)raw_y << 3;

        // Scale down angle to fit 64 sin table
        u8 table_idx = (alpha >> (FIXED_SHIFT - 6))  & 63;
        q32 sin_v = SIN_LUT[table_idx];
        q32 cos_v = SIN_LUT[(table_idx + 16) & 63];

        // Rotate accel vector by alpha to align with hand and apply as acceleration to omega
        q32 accel_aligned = -(accel_x >> (FIXED_SHIFT / 2)) * (sin_v >> (FIXED_SHIFT / 2));
        accel_aligned -= (accel_y >> (FIXED_SHIFT / 2)) * (cos_v >> (FIXED_SHIFT / 2));

        // Integrate accel to get angular velocity
        // Multiply by dt and 1/(2*Pi*r) ~= 11
        // Divide by 1000 to convert ms to s
        omega += (accel_aligned * PENDULUM_SIM_DT * 11) >> 10;

        // Multiply by friction factor (0.98) to prevent runaway and add damping
        omega -= (omega * PENDULUM_FRICTION) >> FIXED_SHIFT;

        // Integrate omega to get angle
        // Multiply by dt and divide by 1000 to convert ms to s
        alpha += (omega * PENDULUM_SIM_DT) >> 10;

        // Add 1/12/2 for proper rounding
        u32 hand_pos = alpha + FIXED_ONE / 24;

        // Map to 0-255
        hand_pos = (hand_pos >> (FIXED_SHIFT - 8)) & 0xFF;

        // Mpa to 1-12 hand index (avoiding division)
        hand_pos = ((hand_pos * 3) >> 6);
        Hand_Set(0, (hand_pos == 0) ? 12 : hand_pos);

        if (omega > PENDULUM_SIM_INACTIVITY_SPEED || -omega > PENDULUM_SIM_INACTIVITY_SPEED)
        {
            last_activity = millis;
        }
    }
}

// Enter Stop Mode for deep sleep with low power consumption
void Enter_Stop_Mode(void)
{
    // Disable RTC wakeup timer
    EXTI->IMR &= ~EXTI_IMR_IM20;

    // Reset Hands
    Hand_Set(0, 0); 
    Hand_Set(1, 0);
    Hand_Set(2, 0);
    while (hands[2].new_value != 255) Spin(1);

    // PWR Control: LPSDSR (Low-power regulator) + Clear PDDS (Stop Mode)
    PWR->CR |= (1 << 0);  
    PWR->CR &= ~(1 << 1); 

    // Set SLEEPDEEP bit in System Control Register
    SCB->SCR |= SCB_SCR_SLEEPDEEP;

    // Clear Wakeup Flag (WUF)
    PWR->CR |= (1 << 3);

    // Wait For Interrupt
    __asm volatile ("wfi");
}

// Restore clock settings after waking up from Stop Mode
void Wakeup_Handler(void) {
    // Restart HSI16
    RCC->CR |= RCC_CR_HSI16ON;
    while (!(RCC->CR & RCC_CR_HSI16RDYF)) Spin(1);

    // Restart the PLL 
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY)) Spin(1);

    // Switch System Clock back to PLL
    BF_SET(RCC->CFGR, RCC_CFGR_SW, 3);
    
    // Wait for switch to complete
    while (BF_GET(RCC->CFGR, RCC_CFGR_SWS) != 3) Spin(1);

    millis = 0;
    last_activity = 0;
    current_mode = MODE_TIME;

    // Re-enable RTC wakeup interrupt and update hands to current time
    EXTI->IMR |= EXTI_IMR_IM20;
    RTC_Set_Hands();
}