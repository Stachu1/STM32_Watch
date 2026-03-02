#include "stm32l0x1_peripherals.h"
#include "intrin.h"
#include "types.h"

#define EVER (;;)
#define SYSCLK 32000000
#define BAUD 115200
#define TS_CAL1 *((u16*) 0x1FF8007A)
#define TS_CAL2 *((u16*) 0x1FF8007E)
#define VREFINT_CAL *((u16*) 0x1FF80078)
#define IMU_ADDR 0x6A
#define BRIGHTNESS_STEPS 16 // Should be a power of 2 for performance


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
    u32 press_start_time;
    b8 is_pressed;
} BTN;

volatile Hand hands[3] = {
    {1, 0, BRIGHTNESS_STEPS-1, 0, 0, true},     // Hour hand
    {2, 0, 0, 0, 8, true},                      // Minute hand
    {3, 0, 0, 0, 1, true}                       // Second hand
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

const volatile u8 hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
volatile BTN upper_btn, lower_btn;
volatile u8 pwm_step = BRIGHTNESS_STEPS * 3;


void Spin(u32);
void Delay_us(u32);
void Delay_ms(u32);
void GPIO_Init(void);
void LED_Init(void);
void Hand_Set(u8, u8);
void UART_Init(void);
void UART_Deinit(void);
void Print_char(u8);
void Print_str(c*);
void Print_u32(u32);
void Print_i32(i32);
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
void BTN_Init(void);

// TODO: Button Interruptr
// TODO: IMU Interrupts
// TODO: Sleep Mode
// TODO: UI for setting time and other features

// TODO: Power and speed optimization


void main(void)
{
    GPIO_Init();
    LED_Init();
    UART_Init();
    ADC_Init();
    RTC_Init();
    I2C_Init();
    IMU_Init();
    BTN_Init();


    RTC_Set_Time(1, 26, 0);
    RTC_Wakeup_Init();

    for EVER
    {
        Delay_ms(500);
        Print_str("elo\n");
        
        // Delay_ms(100);
        // leds[0].port[6] = (1 << leds[0].pin);
        // Delay_ms(1);
        // leds[0].port[6] = (1 << (leds[0].pin + 16)); // Set LED Low
    }
}

// === ISR ===

// TIM21 Interrupt Handler for SW PWM control of LEDs
void TIM21_IRQ_Handler(void)
{
    // Clear flag
    TIM21->SR &= ~TIM21_SR_UIF;

    // Begin new PWM cycle
    pwm_step++;
    if (pwm_step >= BRIGHTNESS_STEPS * 3)
    {
        // Reset pwm_step
        pwm_step = 0;
        for (u8 i=0; i<3; i++)
        {
            // Update hand value to new_value (preventing ghosting when value changes mid hand time slot)
            hands[i].value = hands[i].new_value;

            // Skip if hand is static
            if (hands[i].tick_div == 0) continue;

            // Update tick and handle breathing effect
            hands[i].tick++;
            if (hands[i].tick == hands[i].tick_div)
            {
                // Reset tick and update brightness
                hands[i].tick = 0;
                if (hands[i].fading_in)
                {
                    // Increase brightness until max, then start fading out
                    if (hands[i].brightness < BRIGHTNESS_STEPS - 1) hands[i].brightness++;
                    else hands[i].fading_in = false;
                }
                else
                {
                    // Decrease brightness until min, then start fading in
                    if (hands[i].brightness > 0) hands[i].brightness--;
                    else hands[i].fading_in = true;
                }
            }
        }
    }

    // Get hand index for the current time slot
    u8 hand_idx = pwm_step / BRIGHTNESS_STEPS;
    u8 local_step = pwm_step % BRIGHTNESS_STEPS;

    // Turn on the LED for the current hand at the start of its brightness cycle
    if (local_step == 0 && hands[hand_idx].value > 0 && hands[hand_idx].brightness > 0)
    {
        u8 led_on = hands[hand_idx].value - 1;
        leds[led_on].port[6] = (1 << leds[led_on].pin);
    }

    // Turn off the LED for the current hand at the end of its brightness cycle
    if (local_step >= hands[hand_idx].brightness && hands[hand_idx].value > 0)
    {
        u8 led_off = hands[hand_idx].value - 1;
        leds[led_off].port[6] = (1 << (leds[led_off].pin + 16));
    }
}

// 1Hz RTC Interrupt Handler for hands update
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

        // 3. Update Hand Logic
        u8 h, m, s;
        RTC_Get_Time(&h, &m, &s);

        // Set hand new_values based on current time
        if (h == 0 || h > 12) h = 12;
        hands[0].new_value = h;
        hands[1].new_value = (m / 5 == 0) ? 12 : (m / 5);
        hands[2].new_value = (s / 5 == 0) ? 12 : (s / 5); 
    }
}

// EXTI Interrupt Handler for buttons
void EXTI0_1_IRQ_Handler(void)
{
    u32 pending = EXTI->PR;

    if (pending & (1 << 0)) {
        EXTI->PR = (1 << 0); // Clear Line 0
        leds[11].port[6] = (1 << leds[11].pin); // Set LED High
    }
    if (pending & (1 << 1)) {
        EXTI->PR = (1 << 1); // Clear Line 1
        leds[11].port[6] = (1 << (leds[11].pin + 16)); // Set LED Low
    }
}


// === Utility Functions ===

// Do nothing for 4 clock cyles
void Spin(u32 count)
{
    while (count--) { __asm__ volatile ("nop"); }
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
void LED_Init(void)
{
    // Enable TIM21 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM21EN;

    // Run at full 32MHz
    TIM21->PSC = 0;
    TIM21->ARR = 5333; // 32MHz / 5300 ~ 6kHz for LED PWM updates
    
    // Enable update interrupt and start counter
    TIM21->DIER |= TIM21_DIER_UIE;
    TIM21->CR1 |= TIM21_CR1_CEN;

    // Enable TIM21 interrupt in NVIC
    NVIC->ISER |= (1 << 20);
}

// Set the value of a hand (1-12, 0 for off)
void Hand_Set(u8 hand_index, u8 value)
{
    if (hand_index > 2) return;
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
    while (!(USART2->ISR & USART2_ISR_TXE));
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
    if (ADC->CR & ADC_CR_ADEN) {
        ADC->CR |= ADC_CR_ADDIS;
        while (ADC->CR & ADC_CR_ADEN);
    }

    // Calibration
    ADC->CR |= ADC_CR_ADCAL;
    while (ADC->CR & ADC_CR_ADCAL);

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
    while (!(ADC->ISR & ADC_ISR_ADRDY));
}

// Deinit ADC
void ADC_Deinit(void)
{
    // Stop ongoint conversions
    if (ADC->CR & ADC_CR_ADSTART)
    {
    ADC->CR |= ADC_CR_ADSTP;
    while (ADC->CR & ADC_CR_ADSTP);
    }

    // Disable ADC
    if (ADC->CR & ADC_CR_ADEN)
    {
    ADC->CR |= ADC_CR_ADDIS;
    while (ADC->CR & ADC_CR_ADEN);
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

    // Start ADC conversion, wait, read
    ADC->CR |= ADC_CR_ADSTART;
    while (!(ADC->ISR & ADC_ISR_EOC));
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
    while (!(ADC->ISR & ADC_ISR_EOC));
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
    while (I2C1->ISR & I2C1_ISR_BUSY);

    // Set address, number of bytes, and generate START
    I2C1->CR2 = (addr << 1);
    BF_SET(I2C1->CR2, I2C1_CR2_NBYTES, size + 1);
    I2C1->CR2 |= I2C1_CR2_START | I2C1_CR2_AUTOEND;

    // Select the reg
    while (!(I2C1->ISR & I2C1_ISR_TXIS));
    I2C1->TXDR = reg;

    // Transmit the data
    for (u32 i = 0; i < size; i++) {
        while (!(I2C1->ISR & I2C1_ISR_TXIS));
        I2C1->TXDR = data[i];
    }

    // Wait for stop flag (set by AUTOEND)
    while (!(I2C1->ISR & I2C1_ISR_STOPF));

    // Clear stop flag
    I2C1->ICR |= I2C1_ICR_STOPCF;            
}

// Read data from a slave reg @ addr, reg over I2C
void I2C_Read(u8 addr, u8 reg, u8 *buff, u8 size)
{
    // Wait until I2C is not busy
    while (I2C1->ISR & I2C1_ISR_BUSY);

    I2C1->CR2 = (addr << 1) | (1 << 16); // NBYTES = 1
    I2C1->CR2 |= I2C1_CR2_START; 
    
    while (!(I2C1->ISR & I2C1_ISR_TXIS));
    I2C1->TXDR = reg;
    while (!(I2C1->ISR & I2C1_ISR_TC));

    // Restart and Read
    I2C1->CR2 = (addr << 1) | I2C1_CR2_RD_WRN | (size << 16) | I2C1_CR2_START | I2C1_CR2_AUTOEND;
    
    for (int i = 0; i < size; i++) {
        while (!(I2C1->ISR & I2C1_ISR_RXNE));
        buff[i] = I2C1->RXDR;
    }

    while (!(I2C1->ISR & I2C1_ISR_STOPF));
    I2C1->ICR |= I2C1_ICR_STOPCF;
}

// Init the LSM6DSM IMU
void IMU_Init(void)
{
    // Set Accel to 104Hz, +/- 2g (0x40 to CTRL1_XL)
    u8 buf = 0x40;
    I2C_Write(IMU_ADDR, 0x10, &buf, 1);
}

// Read acceleration from the IMU
void IMU_Get_Accel(i16 *x, i16 *y, i16 *z)
{
    u8 buff[6];
    I2C_Read(IMU_ADDR, 0x28, buff, 6);
    *x = (i16)((buff[1] << 8) | buff[0]);
    *y = (i16)((buff[3] << 8) | buff[2]);
    *z = (i16)((buff[5] << 8) | buff[4]);
}

// Read temperature from the IMU in m°C
i32 IMU_Get_Temp(void)
{
    u8 buff[2];
    I2C_Read(IMU_ADDR, 0x20, buff, 2);

    // Convert raw value to m°C
    // 256 LSB/°C val=0 @25°C =>  m°C = °C*1000 + ((°C/256) * 39 + 5) / 10 + 25000
    return (i32)buff[1] * 1000 + (buff[0] * 39 + 5) / 10 + 25000;
}


// Init RTC for hand updates every second
void RTC_Init(void)
{
    // Disable backup domain write protection
    PWR->CR |= PWR_CR_DBP;

    // Start LSE and wait until ready
    if (!(RCC->CSR & RCC_CSR_LSERDY)) {
        RCC->CSR |= RCC_CSR_LSEON;
        while (!(RCC->CSR & RCC_CSR_LSERDY));
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

// Enable RTC 1Hz interrupt for hand updates
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

    // For 1Hz clock, WUTR = 0 means 1 second interval (Interval = WUTR + 1)
    RTC->WUTR = 0;

    // Enable Interrupt and Timer
    RTC->CR |= RTC_CR_WUTIE | RTC_CR_WUTE;

    // Enable Write Protection
    RTC->WPR = 0xFF;

    // RTC Wakeup is connected to EXTI Line 20
    EXTI->IMR |= (1 << 20);    // Interrupt Mask: Enable line 20
    EXTI->RTSR |= (1 << 20);   // Rising Trigger: Enable

    // Enable RTC global interrupt in NVIC
    NVIC->ISER |= (1 << 2);
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
