#include "stm32l0x1_peripherals.h"
#include "intrin.h"
#include "types.h"

#define EVER (;;)
#define SYSCLK 32000000
#define BAUD 115200
#define TS_CAL1 *((uint16_t*) 0x1FF8007A)
#define TS_CAL2 *((uint16_t*) 0x1FF8007E)
#define VREFINT_CAL *((uint16_t*) 0x1FF80078)
#define IMU_ADDR 0x6A

typedef struct {
    u8 pwm;                 // PWM value for the LED (0 to 255)
    volatile u32* port;     // Pointer to GPIO port (GPIOA, GPIOB, etc.)
    u8 pin;                 // Pin number for the LED (e.g., 6 for PB6)
} LED;

LED leds[] = {
    {0, (volatile u32*)GPIOB, 6},   // LED 0: PB6
    {0, (volatile u32*)GPIOB, 5},   // LED 1: PB5
    {0, (volatile u32*)GPIOB, 3},   // LED 2: PB3
    {0, (volatile u32*)GPIOA, 12},  // LED 3: PA12
    {0, (volatile u32*)GPIOB, 2},   // LED 4: PB2
    {0, (volatile u32*)GPIOA, 7},   // LED 5: PA7
    {0, (volatile u32*)GPIOA, 6},   // LED 6: PA6
    {0, (volatile u32*)GPIOA, 5},   // LED 7: PA5
    {0, (volatile u32*)GPIOA, 4},   // LED 8: PA4
    {0, (volatile u32*)GPIOA, 1},   // LED 9: PA1
    {0, (volatile u32*)GPIOB, 8},   // LED 10: PB8
    {0, (volatile u32*)GPIOB, 7}    // LED 11: PB7
};
const u8 hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
u8 led_step = 0;


void Spin(u32);
void Delay_us(u32);
void Delay_ms(u32);
void GPIO_Init(void);
void LED_Set(u8, u8);
void LED_Update(void);
void UART_Init(void);
void UART_Deinit(void);
void Print_char(u8);
void Print_str(c*);
void Print_u32(u32);
void Print_i32(i32);
u8 Ambient_Sense(void);
void ADC_Init(void);
void ADC_Deinit(void);
u32 Get_Battery_Voltage(void);
i32 Get_Core_Temperature(void);
void I2C_Init(void);
void I2C_Write(u8, u8, u8*, u8);
void I2C_Read(u8, u8, u8*, u8);
void IMU_Init(void);
void Get_Acceleration(i16*, i16*, i16*);
i32 Get_IMU_Temperature(void);
// TODO: RTC_Init
// TODO: RTC_Set
// TODO: Sleep Mode
// TODO: Button Interruptr
// TODO: IMU Interrupts
// TODO: HW PWM for LEDs

// TODO: Power and speed optimization


void main(void)
{
    GPIO_Init();
    UART_Init();
    ADC_Init();
    I2C_Init();
    IMU_Init();

    // LED_Set(0, 10);
    // u32 tick = 0;

    for EVER
    {
        Delay_ms(100);
        // i16 x, y, z;
        // x = 0;
        // Get_Acceleration(&x, &y, &z);
        // Print_i32(x);
        // Print_char(' ');
        // Print_i32(y);
        // Print_char(' ');

        // Print_str(">VDDA:");
        // Print_i32(Get_Battery_Voltage());

        Print_str(">IMU_Temp:");
        Print_i32(Get_IMU_Temperature());
        Print_str(",Core_Temp:");
        Print_i32(Get_Core_Temperature());
        Print_char('\r');
        Print_char('\n');
        leds[0].port[6] |= (1 << leds[0].pin);
        Delay_ms(1);
        leds[0].port[6] |= (1 << (leds[0].pin + 16));

        // LED_Update();
        // Delay_us(10);
        
        // if (led_step == 0) tick++;

        // if (tick == 1000)
        // {
        //     tick = 0;
        //     leds[0].port[6] |= (1 << (leds[0].pin + 16));
        //     LED_Set(0, Ambient_Sense());
            // for (u32 i=0; i<12; i++) leds[i].port[6] |= (1 << (leds[i].pin + 16));
            // leds[bright].port[6] |= (1 << leds[bright].pin);
        // }
    }
}

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

// Sets brightness for an LED
// Only works if LED_Update is called frequently (~6kHz)
void LED_Set(u8 index, u8 value)
{
    if (index > 11) return;
    leds[index].pwm = value;
}

// 8-Bit SW PWM for controlling LEDs brightness with LED_Set
// Should be call at ~6kHz
void LED_Update(void)
{
    for (u8 index=0; index<12; index++)
    {
        // Check if the LED should be ON
        if (led_step == 0 && leds[index].pwm != 0)
        {
            // Turn LED ON (set pin high)
            // +6 to go to BSRR reg
            leds[index].port[6] |= (1 << leds[index].pin);  // Set pin high
        }

        // Check if the LED should be OFF
        if (led_step == leds[index].pwm)
        {
            // Turn LED OFF (reset pin to low)
            // +6 to go to BSRR reg +16 to access reset pin reg
            leds[index].port[6] |= (1 << (leds[index].pin + 16));  // Reset pin (shift for BRx)
        }
    }
    led_step++;
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

// Sends uint32 over UART
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

// Sends int32 over UART
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

    // Configure Oversampling (CFGR2)
    // OVSR [2:0] = 111 (256x ratio)
    // OVSS [3:0] = 0100 (Shift right by 4 bits to gain 4 bits of resolution)
    // OVSE = 1 (Enable Oversampling)
    ADC->CFGR2 |= ADC_CFGR2_OVSE;
    ADC->CFGR2 |= (7 << ADC_CFGR2_OVSR_LSB);
    ADC->CFGR2 |= (8 << ADC_CFGR2_OVSS_LSB);

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
u32 Get_Battery_Voltage(void)
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
i32 Get_Core_Temperature(void)
{
    // Get VDDA
    u32 vdda_mV = Get_Battery_Voltage();

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
    while (!(I2C1->ISR & I2C1_ISR_TC)); // Wait for Transfer Complete

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
void Get_Acceleration(i16 *x, i16 *y, i16 *z)
{
    u8 buff[6];
    I2C_Read(IMU_ADDR, 0x28, buff, 6);
    *x = (i16)((buff[1] << 8) | buff[0]);
    *y = (i16)((buff[3] << 8) | buff[2]);
    *z = (i16)((buff[5] << 8) | buff[4]);
}

// Read temperature from the IMU in m°C
i32 Get_IMU_Temperature(void)
{
    u8 buff[2];
    I2C_Read(IMU_ADDR, 0x20, buff, 2);

    // Convert raw value to m°C
    // 256 LSB/°C val=0 @25 °C =>  m°C = °C*1000 + ((°C/256) * 39 + 5) / 10 + 25000
    return (i32)buff[1] * 1000 + (buff[0] * 39 + 5) / 10 + 25000;
}