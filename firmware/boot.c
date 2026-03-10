#include "types.h"
#include "stm32l0x1_peripherals.h"
#include "intrin.h"



void Reset_Handler();
void RTC_IRQ_Handler(void);
void TIM21_IRQ_Handler(void);
void EXTI0_1_IRQ_Handler(void);
void EXTI4_15_IRQ_Handler(void);
void main();

void ISR_Stub(void) {
    while (1) {
        __asm__ volatile ("wfi");
    }
}

extern u32 _stack_top[];
extern u8 volatile _data_rom[];
extern u8 volatile _data_ram_end[];
extern u8 volatile _data_ram[];
extern u8 volatile _sbss[];
extern u8 volatile _ebss[];

const u32 isr_vector[79] __attribute__((section(".isr_vector"))) = {
    (u32)_stack_top,
    (u32)&Reset_Handler,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&RTC_IRQ_Handler,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&EXTI0_1_IRQ_Handler,
    (u32)&ISR_Stub,
    (u32)&EXTI4_15_IRQ_Handler,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&ISR_Stub,
    (u32)&TIM21_IRQ_Handler
};

void BootPLL(void) {
    RCC->CR |= RCC_CR_HSI16ON;
    while (!(RCC->CR & RCC_CR_HSI16RDYF)) { __asm__ volatile ("nop"); }

    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    BF_SET(PWR->CR, PWR_CR_VOS, 1);
    FLASH->ACR |= FLASH_ACR_LATENCY;

    RCC->CR |= RCC_CR_HSI16DIVF | RCC_CR_HSI16DIVEN;

    RCC->CR &= ~RCC_CR_PLLON;

    BF_SET(RCC->CFGR, RCC_CFGR_PLLDIV, 1);
    BF_SET(RCC->CFGR, RCC_CFGR_PLLMUL, 5);
    RCC->CFGR &= ~RCC_CFGR_PLLSRC;

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY)) { __asm__ volatile ("nop"); }

    BF_SET(RCC->CFGR, RCC_CFGR_SW, 3);
    while (BF_GET(RCC->CFGR, RCC_CFGR_SWS) != 3) { __asm__ volatile ("nop"); }
}

void InitFlashData(void)
{
    const size_t data_size = (size_t)_data_ram_end - (size_t)_data_ram;
    for (size_t i = 0; i < data_size; ++i) {
        _data_ram[i] = _data_rom[i];
    }

    const size_t bss_size = (size_t)_ebss - (size_t)_sbss;
    for (size_t i = 0; i < bss_size; ++i) {
        _sbss[i] = 0;
    }
}

void Reset_Handler(void)
{
    InitFlashData();
    BootPLL();
    main();
}
