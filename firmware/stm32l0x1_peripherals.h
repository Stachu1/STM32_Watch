#ifndef STM32L0X1_PERIPHERALS_H_
#define STM32L0X1_PERIPHERALS_H_

#include <stdint.h>

/* === AES ================================= */
typedef struct {
    volatile uint32_t CR; /* 0x000 */
    volatile uint32_t SR; /* 0x004 */
    volatile uint32_t DINR; /* 0x008 */
    volatile uint32_t DOUTR; /* 0x00C */
    volatile uint32_t KEYR0; /* 0x010 */
    volatile uint32_t KEYR1; /* 0x014 */
    volatile uint32_t KEYR2; /* 0x018 */
    volatile uint32_t KEYR3; /* 0x01C */
    volatile uint32_t IVR0; /* 0x020 */
    volatile uint32_t IVR1; /* 0x024 */
    volatile uint32_t IVR2; /* 0x028 */
    volatile uint32_t IVR3; /* 0x02C */
} AES_Type;

#define AES_BASE 0x40026000u
#define AES ((volatile AES_Type*)AES_BASE)

#define AES_CR_DMAOUTEN (1u << 12)
#define AES_CR_DMAINEN (1u << 11)
#define AES_CR_ERRIE (1u << 10)
#define AES_CR_CCFIE (1u << 9)
#define AES_CR_ERRC (1u << 8)
#define AES_CR_CCFC (1u << 7)
#define AES_CR_CHMOD_LSB   5
#define AES_CR_CHMOD_WIDTH 2
#define AES_CR_CHMOD_MASK  (0x60u)
#define AES_CR_MODE_LSB   3
#define AES_CR_MODE_WIDTH 2
#define AES_CR_MODE_MASK  (0x18u)
#define AES_CR_DATATYPE_LSB   1
#define AES_CR_DATATYPE_WIDTH 2
#define AES_CR_DATATYPE_MASK  (0x6u)
#define AES_CR_EN (1u << 0)
#define AES_SR_WRERR (1u << 2)
#define AES_SR_RDERR (1u << 1)
#define AES_SR_CCF (1u << 0)
#define AES_DINR_AES_DINR_LSB   0
#define AES_DINR_AES_DINR_WIDTH 32
#define AES_DINR_AES_DINR_MASK  (0xFFFFFFFFu)
#define AES_DOUTR_AES_DOUTR_LSB   0
#define AES_DOUTR_AES_DOUTR_WIDTH 32
#define AES_DOUTR_AES_DOUTR_MASK  (0xFFFFFFFFu)
#define AES_KEYR0_AES_KEYR0_LSB   0
#define AES_KEYR0_AES_KEYR0_WIDTH 32
#define AES_KEYR0_AES_KEYR0_MASK  (0xFFFFFFFFu)
#define AES_KEYR1_AES_KEYR1_LSB   0
#define AES_KEYR1_AES_KEYR1_WIDTH 32
#define AES_KEYR1_AES_KEYR1_MASK  (0xFFFFFFFFu)
#define AES_KEYR2_AES_KEYR2_LSB   0
#define AES_KEYR2_AES_KEYR2_WIDTH 32
#define AES_KEYR2_AES_KEYR2_MASK  (0xFFFFFFFFu)
#define AES_KEYR3_AES_KEYR3_LSB   0
#define AES_KEYR3_AES_KEYR3_WIDTH 32
#define AES_KEYR3_AES_KEYR3_MASK  (0xFFFFFFFFu)
#define AES_IVR0_AES_IVR0_LSB   0
#define AES_IVR0_AES_IVR0_WIDTH 32
#define AES_IVR0_AES_IVR0_MASK  (0xFFFFFFFFu)
#define AES_IVR1_AES_IVR1_LSB   0
#define AES_IVR1_AES_IVR1_WIDTH 32
#define AES_IVR1_AES_IVR1_MASK  (0xFFFFFFFFu)
#define AES_IVR2_AES_IVR2_LSB   0
#define AES_IVR2_AES_IVR2_WIDTH 32
#define AES_IVR2_AES_IVR2_MASK  (0xFFFFFFFFu)
#define AES_IVR3_AES_IVR3_LSB   0
#define AES_IVR3_AES_IVR3_WIDTH 32
#define AES_IVR3_AES_IVR3_MASK  (0xFFFFFFFFu)

/* === DMA1 ================================= */
typedef struct {
    volatile uint32_t ISR; /* 0x000 */
    volatile uint32_t IFCR; /* 0x004 */
    volatile uint32_t CCR1; /* 0x008 */
    volatile uint32_t CNDTR1; /* 0x00C */
    volatile uint32_t CPAR1; /* 0x010 */
    volatile uint32_t CMAR1; /* 0x014 */
    uint8_t _res_0018[4];
    volatile uint32_t CCR2; /* 0x01C */
    volatile uint32_t CNDTR2; /* 0x020 */
    volatile uint32_t CPAR2; /* 0x024 */
    volatile uint32_t CMAR2; /* 0x028 */
    uint8_t _res_002C[4];
    volatile uint32_t CCR3; /* 0x030 */
    volatile uint32_t CNDTR3; /* 0x034 */
    volatile uint32_t CPAR3; /* 0x038 */
    volatile uint32_t CMAR3; /* 0x03C */
    uint8_t _res_0040[4];
    volatile uint32_t CCR4; /* 0x044 */
    volatile uint32_t CNDTR4; /* 0x048 */
    volatile uint32_t CPAR4; /* 0x04C */
    volatile uint32_t CMAR4; /* 0x050 */
    uint8_t _res_0054[4];
    volatile uint32_t CCR5; /* 0x058 */
    volatile uint32_t CNDTR5; /* 0x05C */
    volatile uint32_t CPAR5; /* 0x060 */
    volatile uint32_t CMAR5; /* 0x064 */
    uint8_t _res_0068[4];
    volatile uint32_t CCR6; /* 0x06C */
    volatile uint32_t CNDTR6; /* 0x070 */
    volatile uint32_t CPAR6; /* 0x074 */
    volatile uint32_t CMAR6; /* 0x078 */
    uint8_t _res_007C[4];
    volatile uint32_t CCR7; /* 0x080 */
    volatile uint32_t CNDTR7; /* 0x084 */
    volatile uint32_t CPAR7; /* 0x088 */
    volatile uint32_t CMAR7; /* 0x08C */
    uint8_t _res_0090[24];
    volatile uint32_t CSELR; /* 0x0A8 */
} DMA1_Type;

#define DMA1_BASE 0x40020000u
#define DMA1 ((volatile DMA1_Type*)DMA1_BASE)

#define DMA1_ISR_TEIF7 (1u << 27)
#define DMA1_ISR_HTIF7 (1u << 26)
#define DMA1_ISR_TCIF7 (1u << 25)
#define DMA1_ISR_GIF7 (1u << 24)
#define DMA1_ISR_TEIF6 (1u << 23)
#define DMA1_ISR_HTIF6 (1u << 22)
#define DMA1_ISR_TCIF6 (1u << 21)
#define DMA1_ISR_GIF6 (1u << 20)
#define DMA1_ISR_TEIF5 (1u << 19)
#define DMA1_ISR_HTIF5 (1u << 18)
#define DMA1_ISR_TCIF5 (1u << 17)
#define DMA1_ISR_GIF5 (1u << 16)
#define DMA1_ISR_TEIF4 (1u << 15)
#define DMA1_ISR_HTIF4 (1u << 14)
#define DMA1_ISR_TCIF4 (1u << 13)
#define DMA1_ISR_GIF4 (1u << 12)
#define DMA1_ISR_TEIF3 (1u << 11)
#define DMA1_ISR_HTIF3 (1u << 10)
#define DMA1_ISR_TCIF3 (1u << 9)
#define DMA1_ISR_GIF3 (1u << 8)
#define DMA1_ISR_TEIF2 (1u << 7)
#define DMA1_ISR_HTIF2 (1u << 6)
#define DMA1_ISR_TCIF2 (1u << 5)
#define DMA1_ISR_GIF2 (1u << 4)
#define DMA1_ISR_TEIF1 (1u << 3)
#define DMA1_ISR_HTIF1 (1u << 2)
#define DMA1_ISR_TCIF1 (1u << 1)
#define DMA1_ISR_GIF1 (1u << 0)
#define DMA1_IFCR_CTEIF7 (1u << 27)
#define DMA1_IFCR_CHTIF7 (1u << 26)
#define DMA1_IFCR_CTCIF7 (1u << 25)
#define DMA1_IFCR_CGIF7 (1u << 24)
#define DMA1_IFCR_CTEIF6 (1u << 23)
#define DMA1_IFCR_CHTIF6 (1u << 22)
#define DMA1_IFCR_CTCIF6 (1u << 21)
#define DMA1_IFCR_CGIF6 (1u << 20)
#define DMA1_IFCR_CTEIF5 (1u << 19)
#define DMA1_IFCR_CHTIF5 (1u << 18)
#define DMA1_IFCR_CTCIF5 (1u << 17)
#define DMA1_IFCR_CGIF5 (1u << 16)
#define DMA1_IFCR_CTEIF4 (1u << 15)
#define DMA1_IFCR_CHTIF4 (1u << 14)
#define DMA1_IFCR_CTCIF4 (1u << 13)
#define DMA1_IFCR_CGIF4 (1u << 12)
#define DMA1_IFCR_CTEIF3 (1u << 11)
#define DMA1_IFCR_CHTIF3 (1u << 10)
#define DMA1_IFCR_CTCIF3 (1u << 9)
#define DMA1_IFCR_CGIF3 (1u << 8)
#define DMA1_IFCR_CTEIF2 (1u << 7)
#define DMA1_IFCR_CHTIF2 (1u << 6)
#define DMA1_IFCR_CTCIF2 (1u << 5)
#define DMA1_IFCR_CGIF2 (1u << 4)
#define DMA1_IFCR_CTEIF1 (1u << 3)
#define DMA1_IFCR_CHTIF1 (1u << 2)
#define DMA1_IFCR_CTCIF1 (1u << 1)
#define DMA1_IFCR_CGIF1 (1u << 0)
#define DMA1_CCR1_MEM2MEM (1u << 14)
#define DMA1_CCR1_PL_LSB   12
#define DMA1_CCR1_PL_WIDTH 2
#define DMA1_CCR1_PL_MASK  (0x3000u)
#define DMA1_CCR1_MSIZE_LSB   10
#define DMA1_CCR1_MSIZE_WIDTH 2
#define DMA1_CCR1_MSIZE_MASK  (0xC00u)
#define DMA1_CCR1_PSIZE_LSB   8
#define DMA1_CCR1_PSIZE_WIDTH 2
#define DMA1_CCR1_PSIZE_MASK  (0x300u)
#define DMA1_CCR1_MINC (1u << 7)
#define DMA1_CCR1_PINC (1u << 6)
#define DMA1_CCR1_CIRC (1u << 5)
#define DMA1_CCR1_DIR (1u << 4)
#define DMA1_CCR1_TEIE (1u << 3)
#define DMA1_CCR1_HTIE (1u << 2)
#define DMA1_CCR1_TCIE (1u << 1)
#define DMA1_CCR1_EN (1u << 0)
#define DMA1_CNDTR1_NDT_LSB   0
#define DMA1_CNDTR1_NDT_WIDTH 16
#define DMA1_CNDTR1_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR1_PA_LSB   0
#define DMA1_CPAR1_PA_WIDTH 32
#define DMA1_CPAR1_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR1_MA_LSB   0
#define DMA1_CMAR1_MA_WIDTH 32
#define DMA1_CMAR1_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR2_MEM2MEM (1u << 14)
#define DMA1_CCR2_PL_LSB   12
#define DMA1_CCR2_PL_WIDTH 2
#define DMA1_CCR2_PL_MASK  (0x3000u)
#define DMA1_CCR2_MSIZE_LSB   10
#define DMA1_CCR2_MSIZE_WIDTH 2
#define DMA1_CCR2_MSIZE_MASK  (0xC00u)
#define DMA1_CCR2_PSIZE_LSB   8
#define DMA1_CCR2_PSIZE_WIDTH 2
#define DMA1_CCR2_PSIZE_MASK  (0x300u)
#define DMA1_CCR2_MINC (1u << 7)
#define DMA1_CCR2_PINC (1u << 6)
#define DMA1_CCR2_CIRC (1u << 5)
#define DMA1_CCR2_DIR (1u << 4)
#define DMA1_CCR2_TEIE (1u << 3)
#define DMA1_CCR2_HTIE (1u << 2)
#define DMA1_CCR2_TCIE (1u << 1)
#define DMA1_CCR2_EN (1u << 0)
#define DMA1_CNDTR2_NDT_LSB   0
#define DMA1_CNDTR2_NDT_WIDTH 16
#define DMA1_CNDTR2_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR2_PA_LSB   0
#define DMA1_CPAR2_PA_WIDTH 32
#define DMA1_CPAR2_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR2_MA_LSB   0
#define DMA1_CMAR2_MA_WIDTH 32
#define DMA1_CMAR2_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR3_MEM2MEM (1u << 14)
#define DMA1_CCR3_PL_LSB   12
#define DMA1_CCR3_PL_WIDTH 2
#define DMA1_CCR3_PL_MASK  (0x3000u)
#define DMA1_CCR3_MSIZE_LSB   10
#define DMA1_CCR3_MSIZE_WIDTH 2
#define DMA1_CCR3_MSIZE_MASK  (0xC00u)
#define DMA1_CCR3_PSIZE_LSB   8
#define DMA1_CCR3_PSIZE_WIDTH 2
#define DMA1_CCR3_PSIZE_MASK  (0x300u)
#define DMA1_CCR3_MINC (1u << 7)
#define DMA1_CCR3_PINC (1u << 6)
#define DMA1_CCR3_CIRC (1u << 5)
#define DMA1_CCR3_DIR (1u << 4)
#define DMA1_CCR3_TEIE (1u << 3)
#define DMA1_CCR3_HTIE (1u << 2)
#define DMA1_CCR3_TCIE (1u << 1)
#define DMA1_CCR3_EN (1u << 0)
#define DMA1_CNDTR3_NDT_LSB   0
#define DMA1_CNDTR3_NDT_WIDTH 16
#define DMA1_CNDTR3_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR3_PA_LSB   0
#define DMA1_CPAR3_PA_WIDTH 32
#define DMA1_CPAR3_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR3_MA_LSB   0
#define DMA1_CMAR3_MA_WIDTH 32
#define DMA1_CMAR3_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR4_MEM2MEM (1u << 14)
#define DMA1_CCR4_PL_LSB   12
#define DMA1_CCR4_PL_WIDTH 2
#define DMA1_CCR4_PL_MASK  (0x3000u)
#define DMA1_CCR4_MSIZE_LSB   10
#define DMA1_CCR4_MSIZE_WIDTH 2
#define DMA1_CCR4_MSIZE_MASK  (0xC00u)
#define DMA1_CCR4_PSIZE_LSB   8
#define DMA1_CCR4_PSIZE_WIDTH 2
#define DMA1_CCR4_PSIZE_MASK  (0x300u)
#define DMA1_CCR4_MINC (1u << 7)
#define DMA1_CCR4_PINC (1u << 6)
#define DMA1_CCR4_CIRC (1u << 5)
#define DMA1_CCR4_DIR (1u << 4)
#define DMA1_CCR4_TEIE (1u << 3)
#define DMA1_CCR4_HTIE (1u << 2)
#define DMA1_CCR4_TCIE (1u << 1)
#define DMA1_CCR4_EN (1u << 0)
#define DMA1_CNDTR4_NDT_LSB   0
#define DMA1_CNDTR4_NDT_WIDTH 16
#define DMA1_CNDTR4_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR4_PA_LSB   0
#define DMA1_CPAR4_PA_WIDTH 32
#define DMA1_CPAR4_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR4_MA_LSB   0
#define DMA1_CMAR4_MA_WIDTH 32
#define DMA1_CMAR4_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR5_MEM2MEM (1u << 14)
#define DMA1_CCR5_PL_LSB   12
#define DMA1_CCR5_PL_WIDTH 2
#define DMA1_CCR5_PL_MASK  (0x3000u)
#define DMA1_CCR5_MSIZE_LSB   10
#define DMA1_CCR5_MSIZE_WIDTH 2
#define DMA1_CCR5_MSIZE_MASK  (0xC00u)
#define DMA1_CCR5_PSIZE_LSB   8
#define DMA1_CCR5_PSIZE_WIDTH 2
#define DMA1_CCR5_PSIZE_MASK  (0x300u)
#define DMA1_CCR5_MINC (1u << 7)
#define DMA1_CCR5_PINC (1u << 6)
#define DMA1_CCR5_CIRC (1u << 5)
#define DMA1_CCR5_DIR (1u << 4)
#define DMA1_CCR5_TEIE (1u << 3)
#define DMA1_CCR5_HTIE (1u << 2)
#define DMA1_CCR5_TCIE (1u << 1)
#define DMA1_CCR5_EN (1u << 0)
#define DMA1_CNDTR5_NDT_LSB   0
#define DMA1_CNDTR5_NDT_WIDTH 16
#define DMA1_CNDTR5_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR5_PA_LSB   0
#define DMA1_CPAR5_PA_WIDTH 32
#define DMA1_CPAR5_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR5_MA_LSB   0
#define DMA1_CMAR5_MA_WIDTH 32
#define DMA1_CMAR5_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR6_MEM2MEM (1u << 14)
#define DMA1_CCR6_PL_LSB   12
#define DMA1_CCR6_PL_WIDTH 2
#define DMA1_CCR6_PL_MASK  (0x3000u)
#define DMA1_CCR6_MSIZE_LSB   10
#define DMA1_CCR6_MSIZE_WIDTH 2
#define DMA1_CCR6_MSIZE_MASK  (0xC00u)
#define DMA1_CCR6_PSIZE_LSB   8
#define DMA1_CCR6_PSIZE_WIDTH 2
#define DMA1_CCR6_PSIZE_MASK  (0x300u)
#define DMA1_CCR6_MINC (1u << 7)
#define DMA1_CCR6_PINC (1u << 6)
#define DMA1_CCR6_CIRC (1u << 5)
#define DMA1_CCR6_DIR (1u << 4)
#define DMA1_CCR6_TEIE (1u << 3)
#define DMA1_CCR6_HTIE (1u << 2)
#define DMA1_CCR6_TCIE (1u << 1)
#define DMA1_CCR6_EN (1u << 0)
#define DMA1_CNDTR6_NDT_LSB   0
#define DMA1_CNDTR6_NDT_WIDTH 16
#define DMA1_CNDTR6_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR6_PA_LSB   0
#define DMA1_CPAR6_PA_WIDTH 32
#define DMA1_CPAR6_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR6_MA_LSB   0
#define DMA1_CMAR6_MA_WIDTH 32
#define DMA1_CMAR6_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CCR7_MEM2MEM (1u << 14)
#define DMA1_CCR7_PL_LSB   12
#define DMA1_CCR7_PL_WIDTH 2
#define DMA1_CCR7_PL_MASK  (0x3000u)
#define DMA1_CCR7_MSIZE_LSB   10
#define DMA1_CCR7_MSIZE_WIDTH 2
#define DMA1_CCR7_MSIZE_MASK  (0xC00u)
#define DMA1_CCR7_PSIZE_LSB   8
#define DMA1_CCR7_PSIZE_WIDTH 2
#define DMA1_CCR7_PSIZE_MASK  (0x300u)
#define DMA1_CCR7_MINC (1u << 7)
#define DMA1_CCR7_PINC (1u << 6)
#define DMA1_CCR7_CIRC (1u << 5)
#define DMA1_CCR7_DIR (1u << 4)
#define DMA1_CCR7_TEIE (1u << 3)
#define DMA1_CCR7_HTIE (1u << 2)
#define DMA1_CCR7_TCIE (1u << 1)
#define DMA1_CCR7_EN (1u << 0)
#define DMA1_CNDTR7_NDT_LSB   0
#define DMA1_CNDTR7_NDT_WIDTH 16
#define DMA1_CNDTR7_NDT_MASK  (0xFFFFu)
#define DMA1_CPAR7_PA_LSB   0
#define DMA1_CPAR7_PA_WIDTH 32
#define DMA1_CPAR7_PA_MASK  (0xFFFFFFFFu)
#define DMA1_CMAR7_MA_LSB   0
#define DMA1_CMAR7_MA_WIDTH 32
#define DMA1_CMAR7_MA_MASK  (0xFFFFFFFFu)
#define DMA1_CSELR_C7S_LSB   24
#define DMA1_CSELR_C7S_WIDTH 4
#define DMA1_CSELR_C7S_MASK  (0xF000000u)
#define DMA1_CSELR_C6S_LSB   20
#define DMA1_CSELR_C6S_WIDTH 4
#define DMA1_CSELR_C6S_MASK  (0xF00000u)
#define DMA1_CSELR_C5S_LSB   16
#define DMA1_CSELR_C5S_WIDTH 4
#define DMA1_CSELR_C5S_MASK  (0xF0000u)
#define DMA1_CSELR_C4S_LSB   12
#define DMA1_CSELR_C4S_WIDTH 4
#define DMA1_CSELR_C4S_MASK  (0xF000u)
#define DMA1_CSELR_C3S_LSB   8
#define DMA1_CSELR_C3S_WIDTH 4
#define DMA1_CSELR_C3S_MASK  (0xF00u)
#define DMA1_CSELR_C2S_LSB   4
#define DMA1_CSELR_C2S_WIDTH 4
#define DMA1_CSELR_C2S_MASK  (0xF0u)
#define DMA1_CSELR_C1S_LSB   0
#define DMA1_CSELR_C1S_WIDTH 4
#define DMA1_CSELR_C1S_MASK  (0xFu)

/* === CRC ================================= */
typedef struct {
    volatile uint32_t DR; /* 0x000 */
    volatile uint32_t IDR; /* 0x004 */
    volatile uint32_t CR; /* 0x008 */
    uint8_t _res_000C[4];
    volatile uint32_t INIT; /* 0x010 */
    volatile uint32_t POL; /* 0x014 */
} CRC_Type;

#define CRC_BASE 0x40023000u
#define CRC ((volatile CRC_Type*)CRC_BASE)

#define CRC_DR_DR_LSB   0
#define CRC_DR_DR_WIDTH 32
#define CRC_DR_DR_MASK  (0xFFFFFFFFu)
#define CRC_IDR_IDR_LSB   0
#define CRC_IDR_IDR_WIDTH 8
#define CRC_IDR_IDR_MASK  (0xFFu)
#define CRC_CR_REV_OUT (1u << 7)
#define CRC_CR_REV_IN_LSB   5
#define CRC_CR_REV_IN_WIDTH 2
#define CRC_CR_REV_IN_MASK  (0x60u)
#define CRC_CR_POLYSIZE_LSB   3
#define CRC_CR_POLYSIZE_WIDTH 2
#define CRC_CR_POLYSIZE_MASK  (0x18u)
#define CRC_CR_RESET (1u << 0)
#define CRC_INIT_CRC_INIT_LSB   0
#define CRC_INIT_CRC_INIT_WIDTH 32
#define CRC_INIT_CRC_INIT_MASK  (0xFFFFFFFFu)
#define CRC_POL_POLYNOMIALCOEFFICIENTS_LSB   0
#define CRC_POL_POLYNOMIALCOEFFICIENTS_WIDTH 32
#define CRC_POL_POLYNOMIALCOEFFICIENTS_MASK  (0xFFFFFFFFu)

/* === GPIOA ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOA_Type;

#define GPIOA_BASE 0x50000000u
#define GPIOA ((volatile GPIOA_Type*)GPIOA_BASE)

#define GPIOA_MODER_MODE0_LSB   0
#define GPIOA_MODER_MODE0_WIDTH 2
#define GPIOA_MODER_MODE0_MASK  (0x3u)
#define GPIOA_MODER_MODE1_LSB   2
#define GPIOA_MODER_MODE1_WIDTH 2
#define GPIOA_MODER_MODE1_MASK  (0xCu)
#define GPIOA_MODER_MODE2_LSB   4
#define GPIOA_MODER_MODE2_WIDTH 2
#define GPIOA_MODER_MODE2_MASK  (0x30u)
#define GPIOA_MODER_MODE3_LSB   6
#define GPIOA_MODER_MODE3_WIDTH 2
#define GPIOA_MODER_MODE3_MASK  (0xC0u)
#define GPIOA_MODER_MODE4_LSB   8
#define GPIOA_MODER_MODE4_WIDTH 2
#define GPIOA_MODER_MODE4_MASK  (0x300u)
#define GPIOA_MODER_MODE5_LSB   10
#define GPIOA_MODER_MODE5_WIDTH 2
#define GPIOA_MODER_MODE5_MASK  (0xC00u)
#define GPIOA_MODER_MODE6_LSB   12
#define GPIOA_MODER_MODE6_WIDTH 2
#define GPIOA_MODER_MODE6_MASK  (0x3000u)
#define GPIOA_MODER_MODE7_LSB   14
#define GPIOA_MODER_MODE7_WIDTH 2
#define GPIOA_MODER_MODE7_MASK  (0xC000u)
#define GPIOA_MODER_MODE8_LSB   16
#define GPIOA_MODER_MODE8_WIDTH 2
#define GPIOA_MODER_MODE8_MASK  (0x30000u)
#define GPIOA_MODER_MODE9_LSB   18
#define GPIOA_MODER_MODE9_WIDTH 2
#define GPIOA_MODER_MODE9_MASK  (0xC0000u)
#define GPIOA_MODER_MODE10_LSB   20
#define GPIOA_MODER_MODE10_WIDTH 2
#define GPIOA_MODER_MODE10_MASK  (0x300000u)
#define GPIOA_MODER_MODE11_LSB   22
#define GPIOA_MODER_MODE11_WIDTH 2
#define GPIOA_MODER_MODE11_MASK  (0xC00000u)
#define GPIOA_MODER_MODE12_LSB   24
#define GPIOA_MODER_MODE12_WIDTH 2
#define GPIOA_MODER_MODE12_MASK  (0x3000000u)
#define GPIOA_MODER_MODE13_LSB   26
#define GPIOA_MODER_MODE13_WIDTH 2
#define GPIOA_MODER_MODE13_MASK  (0xC000000u)
#define GPIOA_MODER_MODE14_LSB   28
#define GPIOA_MODER_MODE14_WIDTH 2
#define GPIOA_MODER_MODE14_MASK  (0x30000000u)
#define GPIOA_MODER_MODE15_LSB   30
#define GPIOA_MODER_MODE15_WIDTH 2
#define GPIOA_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOA_OTYPER_OT15 (1u << 15)
#define GPIOA_OTYPER_OT14 (1u << 14)
#define GPIOA_OTYPER_OT13 (1u << 13)
#define GPIOA_OTYPER_OT12 (1u << 12)
#define GPIOA_OTYPER_OT11 (1u << 11)
#define GPIOA_OTYPER_OT10 (1u << 10)
#define GPIOA_OTYPER_OT9 (1u << 9)
#define GPIOA_OTYPER_OT8 (1u << 8)
#define GPIOA_OTYPER_OT7 (1u << 7)
#define GPIOA_OTYPER_OT6 (1u << 6)
#define GPIOA_OTYPER_OT5 (1u << 5)
#define GPIOA_OTYPER_OT4 (1u << 4)
#define GPIOA_OTYPER_OT3 (1u << 3)
#define GPIOA_OTYPER_OT2 (1u << 2)
#define GPIOA_OTYPER_OT1 (1u << 1)
#define GPIOA_OTYPER_OT0 (1u << 0)
#define GPIOA_OSPEEDR_OSPEED15_LSB   30
#define GPIOA_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOA_OSPEEDR_OSPEED14_LSB   28
#define GPIOA_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOA_OSPEEDR_OSPEED13_LSB   26
#define GPIOA_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOA_OSPEEDR_OSPEED12_LSB   24
#define GPIOA_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOA_OSPEEDR_OSPEED11_LSB   22
#define GPIOA_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOA_OSPEEDR_OSPEED10_LSB   20
#define GPIOA_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOA_OSPEEDR_OSPEED9_LSB   18
#define GPIOA_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOA_OSPEEDR_OSPEED8_LSB   16
#define GPIOA_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOA_OSPEEDR_OSPEED7_LSB   14
#define GPIOA_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOA_OSPEEDR_OSPEED6_LSB   12
#define GPIOA_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOA_OSPEEDR_OSPEED5_LSB   10
#define GPIOA_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOA_OSPEEDR_OSPEED4_LSB   8
#define GPIOA_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOA_OSPEEDR_OSPEED3_LSB   6
#define GPIOA_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOA_OSPEEDR_OSPEED2_LSB   4
#define GPIOA_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOA_OSPEEDR_OSPEED1_LSB   2
#define GPIOA_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOA_OSPEEDR_OSPEED0_LSB   0
#define GPIOA_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOA_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOA_PUPDR_PUPD15_LSB   30
#define GPIOA_PUPDR_PUPD15_WIDTH 2
#define GPIOA_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOA_PUPDR_PUPD14_LSB   28
#define GPIOA_PUPDR_PUPD14_WIDTH 2
#define GPIOA_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOA_PUPDR_PUPD13_LSB   26
#define GPIOA_PUPDR_PUPD13_WIDTH 2
#define GPIOA_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOA_PUPDR_PUPD12_LSB   24
#define GPIOA_PUPDR_PUPD12_WIDTH 2
#define GPIOA_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOA_PUPDR_PUPD11_LSB   22
#define GPIOA_PUPDR_PUPD11_WIDTH 2
#define GPIOA_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOA_PUPDR_PUPD10_LSB   20
#define GPIOA_PUPDR_PUPD10_WIDTH 2
#define GPIOA_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOA_PUPDR_PUPD9_LSB   18
#define GPIOA_PUPDR_PUPD9_WIDTH 2
#define GPIOA_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOA_PUPDR_PUPD8_LSB   16
#define GPIOA_PUPDR_PUPD8_WIDTH 2
#define GPIOA_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOA_PUPDR_PUPD7_LSB   14
#define GPIOA_PUPDR_PUPD7_WIDTH 2
#define GPIOA_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOA_PUPDR_PUPD6_LSB   12
#define GPIOA_PUPDR_PUPD6_WIDTH 2
#define GPIOA_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOA_PUPDR_PUPD5_LSB   10
#define GPIOA_PUPDR_PUPD5_WIDTH 2
#define GPIOA_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOA_PUPDR_PUPD4_LSB   8
#define GPIOA_PUPDR_PUPD4_WIDTH 2
#define GPIOA_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOA_PUPDR_PUPD3_LSB   6
#define GPIOA_PUPDR_PUPD3_WIDTH 2
#define GPIOA_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOA_PUPDR_PUPD2_LSB   4
#define GPIOA_PUPDR_PUPD2_WIDTH 2
#define GPIOA_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOA_PUPDR_PUPD1_LSB   2
#define GPIOA_PUPDR_PUPD1_WIDTH 2
#define GPIOA_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOA_PUPDR_PUPD0_LSB   0
#define GPIOA_PUPDR_PUPD0_WIDTH 2
#define GPIOA_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOA_IDR_ID15 (1u << 15)
#define GPIOA_IDR_ID14 (1u << 14)
#define GPIOA_IDR_ID13 (1u << 13)
#define GPIOA_IDR_ID12 (1u << 12)
#define GPIOA_IDR_ID11 (1u << 11)
#define GPIOA_IDR_ID10 (1u << 10)
#define GPIOA_IDR_ID9 (1u << 9)
#define GPIOA_IDR_ID8 (1u << 8)
#define GPIOA_IDR_ID7 (1u << 7)
#define GPIOA_IDR_ID6 (1u << 6)
#define GPIOA_IDR_ID5 (1u << 5)
#define GPIOA_IDR_ID4 (1u << 4)
#define GPIOA_IDR_ID3 (1u << 3)
#define GPIOA_IDR_ID2 (1u << 2)
#define GPIOA_IDR_ID1 (1u << 1)
#define GPIOA_IDR_ID0 (1u << 0)
#define GPIOA_ODR_OD15 (1u << 15)
#define GPIOA_ODR_OD14 (1u << 14)
#define GPIOA_ODR_OD13 (1u << 13)
#define GPIOA_ODR_OD12 (1u << 12)
#define GPIOA_ODR_OD11 (1u << 11)
#define GPIOA_ODR_OD10 (1u << 10)
#define GPIOA_ODR_OD9 (1u << 9)
#define GPIOA_ODR_OD8 (1u << 8)
#define GPIOA_ODR_OD7 (1u << 7)
#define GPIOA_ODR_OD6 (1u << 6)
#define GPIOA_ODR_OD5 (1u << 5)
#define GPIOA_ODR_OD4 (1u << 4)
#define GPIOA_ODR_OD3 (1u << 3)
#define GPIOA_ODR_OD2 (1u << 2)
#define GPIOA_ODR_OD1 (1u << 1)
#define GPIOA_ODR_OD0 (1u << 0)
#define GPIOA_BSRR_BR15 (1u << 31)
#define GPIOA_BSRR_BR14 (1u << 30)
#define GPIOA_BSRR_BR13 (1u << 29)
#define GPIOA_BSRR_BR12 (1u << 28)
#define GPIOA_BSRR_BR11 (1u << 27)
#define GPIOA_BSRR_BR10 (1u << 26)
#define GPIOA_BSRR_BR9 (1u << 25)
#define GPIOA_BSRR_BR8 (1u << 24)
#define GPIOA_BSRR_BR7 (1u << 23)
#define GPIOA_BSRR_BR6 (1u << 22)
#define GPIOA_BSRR_BR5 (1u << 21)
#define GPIOA_BSRR_BR4 (1u << 20)
#define GPIOA_BSRR_BR3 (1u << 19)
#define GPIOA_BSRR_BR2 (1u << 18)
#define GPIOA_BSRR_BR1 (1u << 17)
#define GPIOA_BSRR_BR0 (1u << 16)
#define GPIOA_BSRR_BS15 (1u << 15)
#define GPIOA_BSRR_BS14 (1u << 14)
#define GPIOA_BSRR_BS13 (1u << 13)
#define GPIOA_BSRR_BS12 (1u << 12)
#define GPIOA_BSRR_BS11 (1u << 11)
#define GPIOA_BSRR_BS10 (1u << 10)
#define GPIOA_BSRR_BS9 (1u << 9)
#define GPIOA_BSRR_BS8 (1u << 8)
#define GPIOA_BSRR_BS7 (1u << 7)
#define GPIOA_BSRR_BS6 (1u << 6)
#define GPIOA_BSRR_BS5 (1u << 5)
#define GPIOA_BSRR_BS4 (1u << 4)
#define GPIOA_BSRR_BS3 (1u << 3)
#define GPIOA_BSRR_BS2 (1u << 2)
#define GPIOA_BSRR_BS1 (1u << 1)
#define GPIOA_BSRR_BS0 (1u << 0)
#define GPIOA_LCKR_LCKK (1u << 16)
#define GPIOA_LCKR_LCK15 (1u << 15)
#define GPIOA_LCKR_LCK14 (1u << 14)
#define GPIOA_LCKR_LCK13 (1u << 13)
#define GPIOA_LCKR_LCK12 (1u << 12)
#define GPIOA_LCKR_LCK11 (1u << 11)
#define GPIOA_LCKR_LCK10 (1u << 10)
#define GPIOA_LCKR_LCK9 (1u << 9)
#define GPIOA_LCKR_LCK8 (1u << 8)
#define GPIOA_LCKR_LCK7 (1u << 7)
#define GPIOA_LCKR_LCK6 (1u << 6)
#define GPIOA_LCKR_LCK5 (1u << 5)
#define GPIOA_LCKR_LCK4 (1u << 4)
#define GPIOA_LCKR_LCK3 (1u << 3)
#define GPIOA_LCKR_LCK2 (1u << 2)
#define GPIOA_LCKR_LCK1 (1u << 1)
#define GPIOA_LCKR_LCK0 (1u << 0)
#define GPIOA_AFRL_AFSEL7_LSB   28
#define GPIOA_AFRL_AFSEL7_WIDTH 4
#define GPIOA_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOA_AFRL_AFSEL6_LSB   24
#define GPIOA_AFRL_AFSEL6_WIDTH 4
#define GPIOA_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOA_AFRL_AFSEL5_LSB   20
#define GPIOA_AFRL_AFSEL5_WIDTH 4
#define GPIOA_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOA_AFRL_AFSEL4_LSB   16
#define GPIOA_AFRL_AFSEL4_WIDTH 4
#define GPIOA_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOA_AFRL_AFSEL3_LSB   12
#define GPIOA_AFRL_AFSEL3_WIDTH 4
#define GPIOA_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOA_AFRL_AFSEL2_LSB   8
#define GPIOA_AFRL_AFSEL2_WIDTH 4
#define GPIOA_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOA_AFRL_AFSEL1_LSB   4
#define GPIOA_AFRL_AFSEL1_WIDTH 4
#define GPIOA_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOA_AFRL_AFSEL0_LSB   0
#define GPIOA_AFRL_AFSEL0_WIDTH 4
#define GPIOA_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOA_AFRH_AFSEL15_LSB   28
#define GPIOA_AFRH_AFSEL15_WIDTH 4
#define GPIOA_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOA_AFRH_AFSEL14_LSB   24
#define GPIOA_AFRH_AFSEL14_WIDTH 4
#define GPIOA_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOA_AFRH_AFSEL13_LSB   20
#define GPIOA_AFRH_AFSEL13_WIDTH 4
#define GPIOA_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOA_AFRH_AFSEL12_LSB   16
#define GPIOA_AFRH_AFSEL12_WIDTH 4
#define GPIOA_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOA_AFRH_AFSEL11_LSB   12
#define GPIOA_AFRH_AFSEL11_WIDTH 4
#define GPIOA_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOA_AFRH_AFSEL10_LSB   8
#define GPIOA_AFRH_AFSEL10_WIDTH 4
#define GPIOA_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOA_AFRH_AFSEL9_LSB   4
#define GPIOA_AFRH_AFSEL9_WIDTH 4
#define GPIOA_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOA_AFRH_AFSEL8_LSB   0
#define GPIOA_AFRH_AFSEL8_WIDTH 4
#define GPIOA_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOA_BRR_BR15 (1u << 15)
#define GPIOA_BRR_BR14 (1u << 14)
#define GPIOA_BRR_BR13 (1u << 13)
#define GPIOA_BRR_BR12 (1u << 12)
#define GPIOA_BRR_BR11 (1u << 11)
#define GPIOA_BRR_BR10 (1u << 10)
#define GPIOA_BRR_BR9 (1u << 9)
#define GPIOA_BRR_BR8 (1u << 8)
#define GPIOA_BRR_BR7 (1u << 7)
#define GPIOA_BRR_BR6 (1u << 6)
#define GPIOA_BRR_BR5 (1u << 5)
#define GPIOA_BRR_BR4 (1u << 4)
#define GPIOA_BRR_BR3 (1u << 3)
#define GPIOA_BRR_BR2 (1u << 2)
#define GPIOA_BRR_BR1 (1u << 1)
#define GPIOA_BRR_BR0 (1u << 0)

/* === GPIOB ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOB_Type;

#define GPIOB_BASE 0x50000400u
#define GPIOB ((volatile GPIOB_Type*)GPIOB_BASE)

#define GPIOB_MODER_MODE15_LSB   30
#define GPIOB_MODER_MODE15_WIDTH 2
#define GPIOB_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOB_MODER_MODE14_LSB   28
#define GPIOB_MODER_MODE14_WIDTH 2
#define GPIOB_MODER_MODE14_MASK  (0x30000000u)
#define GPIOB_MODER_MODE13_LSB   26
#define GPIOB_MODER_MODE13_WIDTH 2
#define GPIOB_MODER_MODE13_MASK  (0xC000000u)
#define GPIOB_MODER_MODE12_LSB   24
#define GPIOB_MODER_MODE12_WIDTH 2
#define GPIOB_MODER_MODE12_MASK  (0x3000000u)
#define GPIOB_MODER_MODE11_LSB   22
#define GPIOB_MODER_MODE11_WIDTH 2
#define GPIOB_MODER_MODE11_MASK  (0xC00000u)
#define GPIOB_MODER_MODE10_LSB   20
#define GPIOB_MODER_MODE10_WIDTH 2
#define GPIOB_MODER_MODE10_MASK  (0x300000u)
#define GPIOB_MODER_MODE9_LSB   18
#define GPIOB_MODER_MODE9_WIDTH 2
#define GPIOB_MODER_MODE9_MASK  (0xC0000u)
#define GPIOB_MODER_MODE8_LSB   16
#define GPIOB_MODER_MODE8_WIDTH 2
#define GPIOB_MODER_MODE8_MASK  (0x30000u)
#define GPIOB_MODER_MODE7_LSB   14
#define GPIOB_MODER_MODE7_WIDTH 2
#define GPIOB_MODER_MODE7_MASK  (0xC000u)
#define GPIOB_MODER_MODE6_LSB   12
#define GPIOB_MODER_MODE6_WIDTH 2
#define GPIOB_MODER_MODE6_MASK  (0x3000u)
#define GPIOB_MODER_MODE5_LSB   10
#define GPIOB_MODER_MODE5_WIDTH 2
#define GPIOB_MODER_MODE5_MASK  (0xC00u)
#define GPIOB_MODER_MODE4_LSB   8
#define GPIOB_MODER_MODE4_WIDTH 2
#define GPIOB_MODER_MODE4_MASK  (0x300u)
#define GPIOB_MODER_MODE3_LSB   6
#define GPIOB_MODER_MODE3_WIDTH 2
#define GPIOB_MODER_MODE3_MASK  (0xC0u)
#define GPIOB_MODER_MODE2_LSB   4
#define GPIOB_MODER_MODE2_WIDTH 2
#define GPIOB_MODER_MODE2_MASK  (0x30u)
#define GPIOB_MODER_MODE1_LSB   2
#define GPIOB_MODER_MODE1_WIDTH 2
#define GPIOB_MODER_MODE1_MASK  (0xCu)
#define GPIOB_MODER_MODE0_LSB   0
#define GPIOB_MODER_MODE0_WIDTH 2
#define GPIOB_MODER_MODE0_MASK  (0x3u)
#define GPIOB_OTYPER_OT15 (1u << 15)
#define GPIOB_OTYPER_OT14 (1u << 14)
#define GPIOB_OTYPER_OT13 (1u << 13)
#define GPIOB_OTYPER_OT12 (1u << 12)
#define GPIOB_OTYPER_OT11 (1u << 11)
#define GPIOB_OTYPER_OT10 (1u << 10)
#define GPIOB_OTYPER_OT9 (1u << 9)
#define GPIOB_OTYPER_OT8 (1u << 8)
#define GPIOB_OTYPER_OT7 (1u << 7)
#define GPIOB_OTYPER_OT6 (1u << 6)
#define GPIOB_OTYPER_OT5 (1u << 5)
#define GPIOB_OTYPER_OT4 (1u << 4)
#define GPIOB_OTYPER_OT3 (1u << 3)
#define GPIOB_OTYPER_OT2 (1u << 2)
#define GPIOB_OTYPER_OT1 (1u << 1)
#define GPIOB_OTYPER_OT0 (1u << 0)
#define GPIOB_OSPEEDR_OSPEED15_LSB   30
#define GPIOB_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOB_OSPEEDR_OSPEED14_LSB   28
#define GPIOB_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOB_OSPEEDR_OSPEED13_LSB   26
#define GPIOB_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOB_OSPEEDR_OSPEED12_LSB   24
#define GPIOB_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOB_OSPEEDR_OSPEED11_LSB   22
#define GPIOB_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOB_OSPEEDR_OSPEED10_LSB   20
#define GPIOB_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOB_OSPEEDR_OSPEED9_LSB   18
#define GPIOB_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOB_OSPEEDR_OSPEED8_LSB   16
#define GPIOB_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOB_OSPEEDR_OSPEED7_LSB   14
#define GPIOB_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOB_OSPEEDR_OSPEED6_LSB   12
#define GPIOB_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOB_OSPEEDR_OSPEED5_LSB   10
#define GPIOB_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOB_OSPEEDR_OSPEED4_LSB   8
#define GPIOB_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOB_OSPEEDR_OSPEED3_LSB   6
#define GPIOB_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOB_OSPEEDR_OSPEED2_LSB   4
#define GPIOB_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOB_OSPEEDR_OSPEED1_LSB   2
#define GPIOB_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOB_OSPEEDR_OSPEED0_LSB   0
#define GPIOB_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOB_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOB_PUPDR_PUPD15_LSB   30
#define GPIOB_PUPDR_PUPD15_WIDTH 2
#define GPIOB_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOB_PUPDR_PUPD14_LSB   28
#define GPIOB_PUPDR_PUPD14_WIDTH 2
#define GPIOB_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOB_PUPDR_PUPD13_LSB   26
#define GPIOB_PUPDR_PUPD13_WIDTH 2
#define GPIOB_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOB_PUPDR_PUPD12_LSB   24
#define GPIOB_PUPDR_PUPD12_WIDTH 2
#define GPIOB_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOB_PUPDR_PUPD11_LSB   22
#define GPIOB_PUPDR_PUPD11_WIDTH 2
#define GPIOB_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOB_PUPDR_PUPD10_LSB   20
#define GPIOB_PUPDR_PUPD10_WIDTH 2
#define GPIOB_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOB_PUPDR_PUPD9_LSB   18
#define GPIOB_PUPDR_PUPD9_WIDTH 2
#define GPIOB_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOB_PUPDR_PUPD8_LSB   16
#define GPIOB_PUPDR_PUPD8_WIDTH 2
#define GPIOB_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOB_PUPDR_PUPD7_LSB   14
#define GPIOB_PUPDR_PUPD7_WIDTH 2
#define GPIOB_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOB_PUPDR_PUPD6_LSB   12
#define GPIOB_PUPDR_PUPD6_WIDTH 2
#define GPIOB_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOB_PUPDR_PUPD5_LSB   10
#define GPIOB_PUPDR_PUPD5_WIDTH 2
#define GPIOB_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOB_PUPDR_PUPD4_LSB   8
#define GPIOB_PUPDR_PUPD4_WIDTH 2
#define GPIOB_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOB_PUPDR_PUPD3_LSB   6
#define GPIOB_PUPDR_PUPD3_WIDTH 2
#define GPIOB_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOB_PUPDR_PUPD2_LSB   4
#define GPIOB_PUPDR_PUPD2_WIDTH 2
#define GPIOB_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOB_PUPDR_PUPD1_LSB   2
#define GPIOB_PUPDR_PUPD1_WIDTH 2
#define GPIOB_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOB_PUPDR_PUPD0_LSB   0
#define GPIOB_PUPDR_PUPD0_WIDTH 2
#define GPIOB_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOB_IDR_ID15 (1u << 15)
#define GPIOB_IDR_ID14 (1u << 14)
#define GPIOB_IDR_ID13 (1u << 13)
#define GPIOB_IDR_ID12 (1u << 12)
#define GPIOB_IDR_ID11 (1u << 11)
#define GPIOB_IDR_ID10 (1u << 10)
#define GPIOB_IDR_ID9 (1u << 9)
#define GPIOB_IDR_ID8 (1u << 8)
#define GPIOB_IDR_ID7 (1u << 7)
#define GPIOB_IDR_ID6 (1u << 6)
#define GPIOB_IDR_ID5 (1u << 5)
#define GPIOB_IDR_ID4 (1u << 4)
#define GPIOB_IDR_ID3 (1u << 3)
#define GPIOB_IDR_ID2 (1u << 2)
#define GPIOB_IDR_ID1 (1u << 1)
#define GPIOB_IDR_ID0 (1u << 0)
#define GPIOB_ODR_OD15 (1u << 15)
#define GPIOB_ODR_OD14 (1u << 14)
#define GPIOB_ODR_OD13 (1u << 13)
#define GPIOB_ODR_OD12 (1u << 12)
#define GPIOB_ODR_OD11 (1u << 11)
#define GPIOB_ODR_OD10 (1u << 10)
#define GPIOB_ODR_OD9 (1u << 9)
#define GPIOB_ODR_OD8 (1u << 8)
#define GPIOB_ODR_OD7 (1u << 7)
#define GPIOB_ODR_OD6 (1u << 6)
#define GPIOB_ODR_OD5 (1u << 5)
#define GPIOB_ODR_OD4 (1u << 4)
#define GPIOB_ODR_OD3 (1u << 3)
#define GPIOB_ODR_OD2 (1u << 2)
#define GPIOB_ODR_OD1 (1u << 1)
#define GPIOB_ODR_OD0 (1u << 0)
#define GPIOB_BSRR_BR15 (1u << 31)
#define GPIOB_BSRR_BR14 (1u << 30)
#define GPIOB_BSRR_BR13 (1u << 29)
#define GPIOB_BSRR_BR12 (1u << 28)
#define GPIOB_BSRR_BR11 (1u << 27)
#define GPIOB_BSRR_BR10 (1u << 26)
#define GPIOB_BSRR_BR9 (1u << 25)
#define GPIOB_BSRR_BR8 (1u << 24)
#define GPIOB_BSRR_BR7 (1u << 23)
#define GPIOB_BSRR_BR6 (1u << 22)
#define GPIOB_BSRR_BR5 (1u << 21)
#define GPIOB_BSRR_BR4 (1u << 20)
#define GPIOB_BSRR_BR3 (1u << 19)
#define GPIOB_BSRR_BR2 (1u << 18)
#define GPIOB_BSRR_BR1 (1u << 17)
#define GPIOB_BSRR_BR0 (1u << 16)
#define GPIOB_BSRR_BS15 (1u << 15)
#define GPIOB_BSRR_BS14 (1u << 14)
#define GPIOB_BSRR_BS13 (1u << 13)
#define GPIOB_BSRR_BS12 (1u << 12)
#define GPIOB_BSRR_BS11 (1u << 11)
#define GPIOB_BSRR_BS10 (1u << 10)
#define GPIOB_BSRR_BS9 (1u << 9)
#define GPIOB_BSRR_BS8 (1u << 8)
#define GPIOB_BSRR_BS7 (1u << 7)
#define GPIOB_BSRR_BS6 (1u << 6)
#define GPIOB_BSRR_BS5 (1u << 5)
#define GPIOB_BSRR_BS4 (1u << 4)
#define GPIOB_BSRR_BS3 (1u << 3)
#define GPIOB_BSRR_BS2 (1u << 2)
#define GPIOB_BSRR_BS1 (1u << 1)
#define GPIOB_BSRR_BS0 (1u << 0)
#define GPIOB_LCKR_LCKK (1u << 16)
#define GPIOB_LCKR_LCK15 (1u << 15)
#define GPIOB_LCKR_LCK14 (1u << 14)
#define GPIOB_LCKR_LCK13 (1u << 13)
#define GPIOB_LCKR_LCK12 (1u << 12)
#define GPIOB_LCKR_LCK11 (1u << 11)
#define GPIOB_LCKR_LCK10 (1u << 10)
#define GPIOB_LCKR_LCK9 (1u << 9)
#define GPIOB_LCKR_LCK8 (1u << 8)
#define GPIOB_LCKR_LCK7 (1u << 7)
#define GPIOB_LCKR_LCK6 (1u << 6)
#define GPIOB_LCKR_LCK5 (1u << 5)
#define GPIOB_LCKR_LCK4 (1u << 4)
#define GPIOB_LCKR_LCK3 (1u << 3)
#define GPIOB_LCKR_LCK2 (1u << 2)
#define GPIOB_LCKR_LCK1 (1u << 1)
#define GPIOB_LCKR_LCK0 (1u << 0)
#define GPIOB_AFRL_AFSEL7_LSB   28
#define GPIOB_AFRL_AFSEL7_WIDTH 4
#define GPIOB_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOB_AFRL_AFSEL6_LSB   24
#define GPIOB_AFRL_AFSEL6_WIDTH 4
#define GPIOB_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOB_AFRL_AFSEL5_LSB   20
#define GPIOB_AFRL_AFSEL5_WIDTH 4
#define GPIOB_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOB_AFRL_AFSEL4_LSB   16
#define GPIOB_AFRL_AFSEL4_WIDTH 4
#define GPIOB_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOB_AFRL_AFSEL3_LSB   12
#define GPIOB_AFRL_AFSEL3_WIDTH 4
#define GPIOB_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOB_AFRL_AFSEL2_LSB   8
#define GPIOB_AFRL_AFSEL2_WIDTH 4
#define GPIOB_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOB_AFRL_AFSEL1_LSB   4
#define GPIOB_AFRL_AFSEL1_WIDTH 4
#define GPIOB_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOB_AFRL_AFSEL0_LSB   0
#define GPIOB_AFRL_AFSEL0_WIDTH 4
#define GPIOB_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOB_AFRH_AFSEL15_LSB   28
#define GPIOB_AFRH_AFSEL15_WIDTH 4
#define GPIOB_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOB_AFRH_AFSEL14_LSB   24
#define GPIOB_AFRH_AFSEL14_WIDTH 4
#define GPIOB_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOB_AFRH_AFSEL13_LSB   20
#define GPIOB_AFRH_AFSEL13_WIDTH 4
#define GPIOB_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOB_AFRH_AFSEL12_LSB   16
#define GPIOB_AFRH_AFSEL12_WIDTH 4
#define GPIOB_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOB_AFRH_AFSEL11_LSB   12
#define GPIOB_AFRH_AFSEL11_WIDTH 4
#define GPIOB_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOB_AFRH_AFSEL10_LSB   8
#define GPIOB_AFRH_AFSEL10_WIDTH 4
#define GPIOB_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOB_AFRH_AFSEL9_LSB   4
#define GPIOB_AFRH_AFSEL9_WIDTH 4
#define GPIOB_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOB_AFRH_AFSEL8_LSB   0
#define GPIOB_AFRH_AFSEL8_WIDTH 4
#define GPIOB_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOB_BRR_BR15 (1u << 15)
#define GPIOB_BRR_BR14 (1u << 14)
#define GPIOB_BRR_BR13 (1u << 13)
#define GPIOB_BRR_BR12 (1u << 12)
#define GPIOB_BRR_BR11 (1u << 11)
#define GPIOB_BRR_BR10 (1u << 10)
#define GPIOB_BRR_BR9 (1u << 9)
#define GPIOB_BRR_BR8 (1u << 8)
#define GPIOB_BRR_BR7 (1u << 7)
#define GPIOB_BRR_BR6 (1u << 6)
#define GPIOB_BRR_BR5 (1u << 5)
#define GPIOB_BRR_BR4 (1u << 4)
#define GPIOB_BRR_BR3 (1u << 3)
#define GPIOB_BRR_BR2 (1u << 2)
#define GPIOB_BRR_BR1 (1u << 1)
#define GPIOB_BRR_BR0 (1u << 0)

/* === GPIOC ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOC_Type;

#define GPIOC_BASE 0x50000800u
#define GPIOC ((volatile GPIOC_Type*)GPIOC_BASE)

#define GPIOC_MODER_MODE15_LSB   30
#define GPIOC_MODER_MODE15_WIDTH 2
#define GPIOC_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOC_MODER_MODE14_LSB   28
#define GPIOC_MODER_MODE14_WIDTH 2
#define GPIOC_MODER_MODE14_MASK  (0x30000000u)
#define GPIOC_MODER_MODE13_LSB   26
#define GPIOC_MODER_MODE13_WIDTH 2
#define GPIOC_MODER_MODE13_MASK  (0xC000000u)
#define GPIOC_MODER_MODE12_LSB   24
#define GPIOC_MODER_MODE12_WIDTH 2
#define GPIOC_MODER_MODE12_MASK  (0x3000000u)
#define GPIOC_MODER_MODE11_LSB   22
#define GPIOC_MODER_MODE11_WIDTH 2
#define GPIOC_MODER_MODE11_MASK  (0xC00000u)
#define GPIOC_MODER_MODE10_LSB   20
#define GPIOC_MODER_MODE10_WIDTH 2
#define GPIOC_MODER_MODE10_MASK  (0x300000u)
#define GPIOC_MODER_MODE9_LSB   18
#define GPIOC_MODER_MODE9_WIDTH 2
#define GPIOC_MODER_MODE9_MASK  (0xC0000u)
#define GPIOC_MODER_MODE8_LSB   16
#define GPIOC_MODER_MODE8_WIDTH 2
#define GPIOC_MODER_MODE8_MASK  (0x30000u)
#define GPIOC_MODER_MODE7_LSB   14
#define GPIOC_MODER_MODE7_WIDTH 2
#define GPIOC_MODER_MODE7_MASK  (0xC000u)
#define GPIOC_MODER_MODE6_LSB   12
#define GPIOC_MODER_MODE6_WIDTH 2
#define GPIOC_MODER_MODE6_MASK  (0x3000u)
#define GPIOC_MODER_MODE5_LSB   10
#define GPIOC_MODER_MODE5_WIDTH 2
#define GPIOC_MODER_MODE5_MASK  (0xC00u)
#define GPIOC_MODER_MODE4_LSB   8
#define GPIOC_MODER_MODE4_WIDTH 2
#define GPIOC_MODER_MODE4_MASK  (0x300u)
#define GPIOC_MODER_MODE3_LSB   6
#define GPIOC_MODER_MODE3_WIDTH 2
#define GPIOC_MODER_MODE3_MASK  (0xC0u)
#define GPIOC_MODER_MODE2_LSB   4
#define GPIOC_MODER_MODE2_WIDTH 2
#define GPIOC_MODER_MODE2_MASK  (0x30u)
#define GPIOC_MODER_MODE1_LSB   2
#define GPIOC_MODER_MODE1_WIDTH 2
#define GPIOC_MODER_MODE1_MASK  (0xCu)
#define GPIOC_MODER_MODE0_LSB   0
#define GPIOC_MODER_MODE0_WIDTH 2
#define GPIOC_MODER_MODE0_MASK  (0x3u)
#define GPIOC_OTYPER_OT15 (1u << 15)
#define GPIOC_OTYPER_OT14 (1u << 14)
#define GPIOC_OTYPER_OT13 (1u << 13)
#define GPIOC_OTYPER_OT12 (1u << 12)
#define GPIOC_OTYPER_OT11 (1u << 11)
#define GPIOC_OTYPER_OT10 (1u << 10)
#define GPIOC_OTYPER_OT9 (1u << 9)
#define GPIOC_OTYPER_OT8 (1u << 8)
#define GPIOC_OTYPER_OT7 (1u << 7)
#define GPIOC_OTYPER_OT6 (1u << 6)
#define GPIOC_OTYPER_OT5 (1u << 5)
#define GPIOC_OTYPER_OT4 (1u << 4)
#define GPIOC_OTYPER_OT3 (1u << 3)
#define GPIOC_OTYPER_OT2 (1u << 2)
#define GPIOC_OTYPER_OT1 (1u << 1)
#define GPIOC_OTYPER_OT0 (1u << 0)
#define GPIOC_OSPEEDR_OSPEED15_LSB   30
#define GPIOC_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOC_OSPEEDR_OSPEED14_LSB   28
#define GPIOC_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOC_OSPEEDR_OSPEED13_LSB   26
#define GPIOC_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOC_OSPEEDR_OSPEED12_LSB   24
#define GPIOC_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOC_OSPEEDR_OSPEED11_LSB   22
#define GPIOC_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOC_OSPEEDR_OSPEED10_LSB   20
#define GPIOC_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOC_OSPEEDR_OSPEED9_LSB   18
#define GPIOC_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOC_OSPEEDR_OSPEED8_LSB   16
#define GPIOC_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOC_OSPEEDR_OSPEED7_LSB   14
#define GPIOC_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOC_OSPEEDR_OSPEED6_LSB   12
#define GPIOC_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOC_OSPEEDR_OSPEED5_LSB   10
#define GPIOC_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOC_OSPEEDR_OSPEED4_LSB   8
#define GPIOC_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOC_OSPEEDR_OSPEED3_LSB   6
#define GPIOC_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOC_OSPEEDR_OSPEED2_LSB   4
#define GPIOC_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOC_OSPEEDR_OSPEED1_LSB   2
#define GPIOC_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOC_OSPEEDR_OSPEED0_LSB   0
#define GPIOC_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOC_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOC_PUPDR_PUPD15_LSB   30
#define GPIOC_PUPDR_PUPD15_WIDTH 2
#define GPIOC_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOC_PUPDR_PUPD14_LSB   28
#define GPIOC_PUPDR_PUPD14_WIDTH 2
#define GPIOC_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOC_PUPDR_PUPD13_LSB   26
#define GPIOC_PUPDR_PUPD13_WIDTH 2
#define GPIOC_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOC_PUPDR_PUPD12_LSB   24
#define GPIOC_PUPDR_PUPD12_WIDTH 2
#define GPIOC_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOC_PUPDR_PUPD11_LSB   22
#define GPIOC_PUPDR_PUPD11_WIDTH 2
#define GPIOC_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOC_PUPDR_PUPD10_LSB   20
#define GPIOC_PUPDR_PUPD10_WIDTH 2
#define GPIOC_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOC_PUPDR_PUPD9_LSB   18
#define GPIOC_PUPDR_PUPD9_WIDTH 2
#define GPIOC_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOC_PUPDR_PUPD8_LSB   16
#define GPIOC_PUPDR_PUPD8_WIDTH 2
#define GPIOC_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOC_PUPDR_PUPD7_LSB   14
#define GPIOC_PUPDR_PUPD7_WIDTH 2
#define GPIOC_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOC_PUPDR_PUPD6_LSB   12
#define GPIOC_PUPDR_PUPD6_WIDTH 2
#define GPIOC_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOC_PUPDR_PUPD5_LSB   10
#define GPIOC_PUPDR_PUPD5_WIDTH 2
#define GPIOC_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOC_PUPDR_PUPD4_LSB   8
#define GPIOC_PUPDR_PUPD4_WIDTH 2
#define GPIOC_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOC_PUPDR_PUPD3_LSB   6
#define GPIOC_PUPDR_PUPD3_WIDTH 2
#define GPIOC_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOC_PUPDR_PUPD2_LSB   4
#define GPIOC_PUPDR_PUPD2_WIDTH 2
#define GPIOC_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOC_PUPDR_PUPD1_LSB   2
#define GPIOC_PUPDR_PUPD1_WIDTH 2
#define GPIOC_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOC_PUPDR_PUPD0_LSB   0
#define GPIOC_PUPDR_PUPD0_WIDTH 2
#define GPIOC_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOC_IDR_ID15 (1u << 15)
#define GPIOC_IDR_ID14 (1u << 14)
#define GPIOC_IDR_ID13 (1u << 13)
#define GPIOC_IDR_ID12 (1u << 12)
#define GPIOC_IDR_ID11 (1u << 11)
#define GPIOC_IDR_ID10 (1u << 10)
#define GPIOC_IDR_ID9 (1u << 9)
#define GPIOC_IDR_ID8 (1u << 8)
#define GPIOC_IDR_ID7 (1u << 7)
#define GPIOC_IDR_ID6 (1u << 6)
#define GPIOC_IDR_ID5 (1u << 5)
#define GPIOC_IDR_ID4 (1u << 4)
#define GPIOC_IDR_ID3 (1u << 3)
#define GPIOC_IDR_ID2 (1u << 2)
#define GPIOC_IDR_ID1 (1u << 1)
#define GPIOC_IDR_ID0 (1u << 0)
#define GPIOC_ODR_OD15 (1u << 15)
#define GPIOC_ODR_OD14 (1u << 14)
#define GPIOC_ODR_OD13 (1u << 13)
#define GPIOC_ODR_OD12 (1u << 12)
#define GPIOC_ODR_OD11 (1u << 11)
#define GPIOC_ODR_OD10 (1u << 10)
#define GPIOC_ODR_OD9 (1u << 9)
#define GPIOC_ODR_OD8 (1u << 8)
#define GPIOC_ODR_OD7 (1u << 7)
#define GPIOC_ODR_OD6 (1u << 6)
#define GPIOC_ODR_OD5 (1u << 5)
#define GPIOC_ODR_OD4 (1u << 4)
#define GPIOC_ODR_OD3 (1u << 3)
#define GPIOC_ODR_OD2 (1u << 2)
#define GPIOC_ODR_OD1 (1u << 1)
#define GPIOC_ODR_OD0 (1u << 0)
#define GPIOC_BSRR_BR15 (1u << 31)
#define GPIOC_BSRR_BR14 (1u << 30)
#define GPIOC_BSRR_BR13 (1u << 29)
#define GPIOC_BSRR_BR12 (1u << 28)
#define GPIOC_BSRR_BR11 (1u << 27)
#define GPIOC_BSRR_BR10 (1u << 26)
#define GPIOC_BSRR_BR9 (1u << 25)
#define GPIOC_BSRR_BR8 (1u << 24)
#define GPIOC_BSRR_BR7 (1u << 23)
#define GPIOC_BSRR_BR6 (1u << 22)
#define GPIOC_BSRR_BR5 (1u << 21)
#define GPIOC_BSRR_BR4 (1u << 20)
#define GPIOC_BSRR_BR3 (1u << 19)
#define GPIOC_BSRR_BR2 (1u << 18)
#define GPIOC_BSRR_BR1 (1u << 17)
#define GPIOC_BSRR_BR0 (1u << 16)
#define GPIOC_BSRR_BS15 (1u << 15)
#define GPIOC_BSRR_BS14 (1u << 14)
#define GPIOC_BSRR_BS13 (1u << 13)
#define GPIOC_BSRR_BS12 (1u << 12)
#define GPIOC_BSRR_BS11 (1u << 11)
#define GPIOC_BSRR_BS10 (1u << 10)
#define GPIOC_BSRR_BS9 (1u << 9)
#define GPIOC_BSRR_BS8 (1u << 8)
#define GPIOC_BSRR_BS7 (1u << 7)
#define GPIOC_BSRR_BS6 (1u << 6)
#define GPIOC_BSRR_BS5 (1u << 5)
#define GPIOC_BSRR_BS4 (1u << 4)
#define GPIOC_BSRR_BS3 (1u << 3)
#define GPIOC_BSRR_BS2 (1u << 2)
#define GPIOC_BSRR_BS1 (1u << 1)
#define GPIOC_BSRR_BS0 (1u << 0)
#define GPIOC_LCKR_LCKK (1u << 16)
#define GPIOC_LCKR_LCK15 (1u << 15)
#define GPIOC_LCKR_LCK14 (1u << 14)
#define GPIOC_LCKR_LCK13 (1u << 13)
#define GPIOC_LCKR_LCK12 (1u << 12)
#define GPIOC_LCKR_LCK11 (1u << 11)
#define GPIOC_LCKR_LCK10 (1u << 10)
#define GPIOC_LCKR_LCK9 (1u << 9)
#define GPIOC_LCKR_LCK8 (1u << 8)
#define GPIOC_LCKR_LCK7 (1u << 7)
#define GPIOC_LCKR_LCK6 (1u << 6)
#define GPIOC_LCKR_LCK5 (1u << 5)
#define GPIOC_LCKR_LCK4 (1u << 4)
#define GPIOC_LCKR_LCK3 (1u << 3)
#define GPIOC_LCKR_LCK2 (1u << 2)
#define GPIOC_LCKR_LCK1 (1u << 1)
#define GPIOC_LCKR_LCK0 (1u << 0)
#define GPIOC_AFRL_AFSEL7_LSB   28
#define GPIOC_AFRL_AFSEL7_WIDTH 4
#define GPIOC_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOC_AFRL_AFSEL6_LSB   24
#define GPIOC_AFRL_AFSEL6_WIDTH 4
#define GPIOC_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOC_AFRL_AFSEL5_LSB   20
#define GPIOC_AFRL_AFSEL5_WIDTH 4
#define GPIOC_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOC_AFRL_AFSEL4_LSB   16
#define GPIOC_AFRL_AFSEL4_WIDTH 4
#define GPIOC_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOC_AFRL_AFSEL3_LSB   12
#define GPIOC_AFRL_AFSEL3_WIDTH 4
#define GPIOC_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOC_AFRL_AFSEL2_LSB   8
#define GPIOC_AFRL_AFSEL2_WIDTH 4
#define GPIOC_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOC_AFRL_AFSEL1_LSB   4
#define GPIOC_AFRL_AFSEL1_WIDTH 4
#define GPIOC_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOC_AFRL_AFSEL0_LSB   0
#define GPIOC_AFRL_AFSEL0_WIDTH 4
#define GPIOC_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOC_AFRH_AFSEL15_LSB   28
#define GPIOC_AFRH_AFSEL15_WIDTH 4
#define GPIOC_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOC_AFRH_AFSEL14_LSB   24
#define GPIOC_AFRH_AFSEL14_WIDTH 4
#define GPIOC_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOC_AFRH_AFSEL13_LSB   20
#define GPIOC_AFRH_AFSEL13_WIDTH 4
#define GPIOC_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOC_AFRH_AFSEL12_LSB   16
#define GPIOC_AFRH_AFSEL12_WIDTH 4
#define GPIOC_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOC_AFRH_AFSEL11_LSB   12
#define GPIOC_AFRH_AFSEL11_WIDTH 4
#define GPIOC_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOC_AFRH_AFSEL10_LSB   8
#define GPIOC_AFRH_AFSEL10_WIDTH 4
#define GPIOC_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOC_AFRH_AFSEL9_LSB   4
#define GPIOC_AFRH_AFSEL9_WIDTH 4
#define GPIOC_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOC_AFRH_AFSEL8_LSB   0
#define GPIOC_AFRH_AFSEL8_WIDTH 4
#define GPIOC_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOC_BRR_BR15 (1u << 15)
#define GPIOC_BRR_BR14 (1u << 14)
#define GPIOC_BRR_BR13 (1u << 13)
#define GPIOC_BRR_BR12 (1u << 12)
#define GPIOC_BRR_BR11 (1u << 11)
#define GPIOC_BRR_BR10 (1u << 10)
#define GPIOC_BRR_BR9 (1u << 9)
#define GPIOC_BRR_BR8 (1u << 8)
#define GPIOC_BRR_BR7 (1u << 7)
#define GPIOC_BRR_BR6 (1u << 6)
#define GPIOC_BRR_BR5 (1u << 5)
#define GPIOC_BRR_BR4 (1u << 4)
#define GPIOC_BRR_BR3 (1u << 3)
#define GPIOC_BRR_BR2 (1u << 2)
#define GPIOC_BRR_BR1 (1u << 1)
#define GPIOC_BRR_BR0 (1u << 0)

/* === GPIOD ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOD_Type;

#define GPIOD_BASE 0x50000C00u
#define GPIOD ((volatile GPIOD_Type*)GPIOD_BASE)

#define GPIOD_MODER_MODE15_LSB   30
#define GPIOD_MODER_MODE15_WIDTH 2
#define GPIOD_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOD_MODER_MODE14_LSB   28
#define GPIOD_MODER_MODE14_WIDTH 2
#define GPIOD_MODER_MODE14_MASK  (0x30000000u)
#define GPIOD_MODER_MODE13_LSB   26
#define GPIOD_MODER_MODE13_WIDTH 2
#define GPIOD_MODER_MODE13_MASK  (0xC000000u)
#define GPIOD_MODER_MODE12_LSB   24
#define GPIOD_MODER_MODE12_WIDTH 2
#define GPIOD_MODER_MODE12_MASK  (0x3000000u)
#define GPIOD_MODER_MODE11_LSB   22
#define GPIOD_MODER_MODE11_WIDTH 2
#define GPIOD_MODER_MODE11_MASK  (0xC00000u)
#define GPIOD_MODER_MODE10_LSB   20
#define GPIOD_MODER_MODE10_WIDTH 2
#define GPIOD_MODER_MODE10_MASK  (0x300000u)
#define GPIOD_MODER_MODE9_LSB   18
#define GPIOD_MODER_MODE9_WIDTH 2
#define GPIOD_MODER_MODE9_MASK  (0xC0000u)
#define GPIOD_MODER_MODE8_LSB   16
#define GPIOD_MODER_MODE8_WIDTH 2
#define GPIOD_MODER_MODE8_MASK  (0x30000u)
#define GPIOD_MODER_MODE7_LSB   14
#define GPIOD_MODER_MODE7_WIDTH 2
#define GPIOD_MODER_MODE7_MASK  (0xC000u)
#define GPIOD_MODER_MODE6_LSB   12
#define GPIOD_MODER_MODE6_WIDTH 2
#define GPIOD_MODER_MODE6_MASK  (0x3000u)
#define GPIOD_MODER_MODE5_LSB   10
#define GPIOD_MODER_MODE5_WIDTH 2
#define GPIOD_MODER_MODE5_MASK  (0xC00u)
#define GPIOD_MODER_MODE4_LSB   8
#define GPIOD_MODER_MODE4_WIDTH 2
#define GPIOD_MODER_MODE4_MASK  (0x300u)
#define GPIOD_MODER_MODE3_LSB   6
#define GPIOD_MODER_MODE3_WIDTH 2
#define GPIOD_MODER_MODE3_MASK  (0xC0u)
#define GPIOD_MODER_MODE2_LSB   4
#define GPIOD_MODER_MODE2_WIDTH 2
#define GPIOD_MODER_MODE2_MASK  (0x30u)
#define GPIOD_MODER_MODE1_LSB   2
#define GPIOD_MODER_MODE1_WIDTH 2
#define GPIOD_MODER_MODE1_MASK  (0xCu)
#define GPIOD_MODER_MODE0_LSB   0
#define GPIOD_MODER_MODE0_WIDTH 2
#define GPIOD_MODER_MODE0_MASK  (0x3u)
#define GPIOD_OTYPER_OT15 (1u << 15)
#define GPIOD_OTYPER_OT14 (1u << 14)
#define GPIOD_OTYPER_OT13 (1u << 13)
#define GPIOD_OTYPER_OT12 (1u << 12)
#define GPIOD_OTYPER_OT11 (1u << 11)
#define GPIOD_OTYPER_OT10 (1u << 10)
#define GPIOD_OTYPER_OT9 (1u << 9)
#define GPIOD_OTYPER_OT8 (1u << 8)
#define GPIOD_OTYPER_OT7 (1u << 7)
#define GPIOD_OTYPER_OT6 (1u << 6)
#define GPIOD_OTYPER_OT5 (1u << 5)
#define GPIOD_OTYPER_OT4 (1u << 4)
#define GPIOD_OTYPER_OT3 (1u << 3)
#define GPIOD_OTYPER_OT2 (1u << 2)
#define GPIOD_OTYPER_OT1 (1u << 1)
#define GPIOD_OTYPER_OT0 (1u << 0)
#define GPIOD_OSPEEDR_OSPEED15_LSB   30
#define GPIOD_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOD_OSPEEDR_OSPEED14_LSB   28
#define GPIOD_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOD_OSPEEDR_OSPEED13_LSB   26
#define GPIOD_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOD_OSPEEDR_OSPEED12_LSB   24
#define GPIOD_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOD_OSPEEDR_OSPEED11_LSB   22
#define GPIOD_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOD_OSPEEDR_OSPEED10_LSB   20
#define GPIOD_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOD_OSPEEDR_OSPEED9_LSB   18
#define GPIOD_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOD_OSPEEDR_OSPEED8_LSB   16
#define GPIOD_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOD_OSPEEDR_OSPEED7_LSB   14
#define GPIOD_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOD_OSPEEDR_OSPEED6_LSB   12
#define GPIOD_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOD_OSPEEDR_OSPEED5_LSB   10
#define GPIOD_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOD_OSPEEDR_OSPEED4_LSB   8
#define GPIOD_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOD_OSPEEDR_OSPEED3_LSB   6
#define GPIOD_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOD_OSPEEDR_OSPEED2_LSB   4
#define GPIOD_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOD_OSPEEDR_OSPEED1_LSB   2
#define GPIOD_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOD_OSPEEDR_OSPEED0_LSB   0
#define GPIOD_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOD_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOD_PUPDR_PUPD15_LSB   30
#define GPIOD_PUPDR_PUPD15_WIDTH 2
#define GPIOD_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOD_PUPDR_PUPD14_LSB   28
#define GPIOD_PUPDR_PUPD14_WIDTH 2
#define GPIOD_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOD_PUPDR_PUPD13_LSB   26
#define GPIOD_PUPDR_PUPD13_WIDTH 2
#define GPIOD_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOD_PUPDR_PUPD12_LSB   24
#define GPIOD_PUPDR_PUPD12_WIDTH 2
#define GPIOD_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOD_PUPDR_PUPD11_LSB   22
#define GPIOD_PUPDR_PUPD11_WIDTH 2
#define GPIOD_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOD_PUPDR_PUPD10_LSB   20
#define GPIOD_PUPDR_PUPD10_WIDTH 2
#define GPIOD_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOD_PUPDR_PUPD9_LSB   18
#define GPIOD_PUPDR_PUPD9_WIDTH 2
#define GPIOD_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOD_PUPDR_PUPD8_LSB   16
#define GPIOD_PUPDR_PUPD8_WIDTH 2
#define GPIOD_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOD_PUPDR_PUPD7_LSB   14
#define GPIOD_PUPDR_PUPD7_WIDTH 2
#define GPIOD_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOD_PUPDR_PUPD6_LSB   12
#define GPIOD_PUPDR_PUPD6_WIDTH 2
#define GPIOD_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOD_PUPDR_PUPD5_LSB   10
#define GPIOD_PUPDR_PUPD5_WIDTH 2
#define GPIOD_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOD_PUPDR_PUPD4_LSB   8
#define GPIOD_PUPDR_PUPD4_WIDTH 2
#define GPIOD_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOD_PUPDR_PUPD3_LSB   6
#define GPIOD_PUPDR_PUPD3_WIDTH 2
#define GPIOD_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOD_PUPDR_PUPD2_LSB   4
#define GPIOD_PUPDR_PUPD2_WIDTH 2
#define GPIOD_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOD_PUPDR_PUPD1_LSB   2
#define GPIOD_PUPDR_PUPD1_WIDTH 2
#define GPIOD_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOD_PUPDR_PUPD0_LSB   0
#define GPIOD_PUPDR_PUPD0_WIDTH 2
#define GPIOD_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOD_IDR_ID15 (1u << 15)
#define GPIOD_IDR_ID14 (1u << 14)
#define GPIOD_IDR_ID13 (1u << 13)
#define GPIOD_IDR_ID12 (1u << 12)
#define GPIOD_IDR_ID11 (1u << 11)
#define GPIOD_IDR_ID10 (1u << 10)
#define GPIOD_IDR_ID9 (1u << 9)
#define GPIOD_IDR_ID8 (1u << 8)
#define GPIOD_IDR_ID7 (1u << 7)
#define GPIOD_IDR_ID6 (1u << 6)
#define GPIOD_IDR_ID5 (1u << 5)
#define GPIOD_IDR_ID4 (1u << 4)
#define GPIOD_IDR_ID3 (1u << 3)
#define GPIOD_IDR_ID2 (1u << 2)
#define GPIOD_IDR_ID1 (1u << 1)
#define GPIOD_IDR_ID0 (1u << 0)
#define GPIOD_ODR_OD15 (1u << 15)
#define GPIOD_ODR_OD14 (1u << 14)
#define GPIOD_ODR_OD13 (1u << 13)
#define GPIOD_ODR_OD12 (1u << 12)
#define GPIOD_ODR_OD11 (1u << 11)
#define GPIOD_ODR_OD10 (1u << 10)
#define GPIOD_ODR_OD9 (1u << 9)
#define GPIOD_ODR_OD8 (1u << 8)
#define GPIOD_ODR_OD7 (1u << 7)
#define GPIOD_ODR_OD6 (1u << 6)
#define GPIOD_ODR_OD5 (1u << 5)
#define GPIOD_ODR_OD4 (1u << 4)
#define GPIOD_ODR_OD3 (1u << 3)
#define GPIOD_ODR_OD2 (1u << 2)
#define GPIOD_ODR_OD1 (1u << 1)
#define GPIOD_ODR_OD0 (1u << 0)
#define GPIOD_BSRR_BR15 (1u << 31)
#define GPIOD_BSRR_BR14 (1u << 30)
#define GPIOD_BSRR_BR13 (1u << 29)
#define GPIOD_BSRR_BR12 (1u << 28)
#define GPIOD_BSRR_BR11 (1u << 27)
#define GPIOD_BSRR_BR10 (1u << 26)
#define GPIOD_BSRR_BR9 (1u << 25)
#define GPIOD_BSRR_BR8 (1u << 24)
#define GPIOD_BSRR_BR7 (1u << 23)
#define GPIOD_BSRR_BR6 (1u << 22)
#define GPIOD_BSRR_BR5 (1u << 21)
#define GPIOD_BSRR_BR4 (1u << 20)
#define GPIOD_BSRR_BR3 (1u << 19)
#define GPIOD_BSRR_BR2 (1u << 18)
#define GPIOD_BSRR_BR1 (1u << 17)
#define GPIOD_BSRR_BR0 (1u << 16)
#define GPIOD_BSRR_BS15 (1u << 15)
#define GPIOD_BSRR_BS14 (1u << 14)
#define GPIOD_BSRR_BS13 (1u << 13)
#define GPIOD_BSRR_BS12 (1u << 12)
#define GPIOD_BSRR_BS11 (1u << 11)
#define GPIOD_BSRR_BS10 (1u << 10)
#define GPIOD_BSRR_BS9 (1u << 9)
#define GPIOD_BSRR_BS8 (1u << 8)
#define GPIOD_BSRR_BS7 (1u << 7)
#define GPIOD_BSRR_BS6 (1u << 6)
#define GPIOD_BSRR_BS5 (1u << 5)
#define GPIOD_BSRR_BS4 (1u << 4)
#define GPIOD_BSRR_BS3 (1u << 3)
#define GPIOD_BSRR_BS2 (1u << 2)
#define GPIOD_BSRR_BS1 (1u << 1)
#define GPIOD_BSRR_BS0 (1u << 0)
#define GPIOD_LCKR_LCKK (1u << 16)
#define GPIOD_LCKR_LCK15 (1u << 15)
#define GPIOD_LCKR_LCK14 (1u << 14)
#define GPIOD_LCKR_LCK13 (1u << 13)
#define GPIOD_LCKR_LCK12 (1u << 12)
#define GPIOD_LCKR_LCK11 (1u << 11)
#define GPIOD_LCKR_LCK10 (1u << 10)
#define GPIOD_LCKR_LCK9 (1u << 9)
#define GPIOD_LCKR_LCK8 (1u << 8)
#define GPIOD_LCKR_LCK7 (1u << 7)
#define GPIOD_LCKR_LCK6 (1u << 6)
#define GPIOD_LCKR_LCK5 (1u << 5)
#define GPIOD_LCKR_LCK4 (1u << 4)
#define GPIOD_LCKR_LCK3 (1u << 3)
#define GPIOD_LCKR_LCK2 (1u << 2)
#define GPIOD_LCKR_LCK1 (1u << 1)
#define GPIOD_LCKR_LCK0 (1u << 0)
#define GPIOD_AFRL_AFSEL7_LSB   28
#define GPIOD_AFRL_AFSEL7_WIDTH 4
#define GPIOD_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOD_AFRL_AFSEL6_LSB   24
#define GPIOD_AFRL_AFSEL6_WIDTH 4
#define GPIOD_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOD_AFRL_AFSEL5_LSB   20
#define GPIOD_AFRL_AFSEL5_WIDTH 4
#define GPIOD_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOD_AFRL_AFSEL4_LSB   16
#define GPIOD_AFRL_AFSEL4_WIDTH 4
#define GPIOD_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOD_AFRL_AFSEL3_LSB   12
#define GPIOD_AFRL_AFSEL3_WIDTH 4
#define GPIOD_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOD_AFRL_AFSEL2_LSB   8
#define GPIOD_AFRL_AFSEL2_WIDTH 4
#define GPIOD_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOD_AFRL_AFSEL1_LSB   4
#define GPIOD_AFRL_AFSEL1_WIDTH 4
#define GPIOD_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOD_AFRL_AFSEL0_LSB   0
#define GPIOD_AFRL_AFSEL0_WIDTH 4
#define GPIOD_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOD_AFRH_AFSEL15_LSB   28
#define GPIOD_AFRH_AFSEL15_WIDTH 4
#define GPIOD_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOD_AFRH_AFSEL14_LSB   24
#define GPIOD_AFRH_AFSEL14_WIDTH 4
#define GPIOD_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOD_AFRH_AFSEL13_LSB   20
#define GPIOD_AFRH_AFSEL13_WIDTH 4
#define GPIOD_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOD_AFRH_AFSEL12_LSB   16
#define GPIOD_AFRH_AFSEL12_WIDTH 4
#define GPIOD_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOD_AFRH_AFSEL11_LSB   12
#define GPIOD_AFRH_AFSEL11_WIDTH 4
#define GPIOD_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOD_AFRH_AFSEL10_LSB   8
#define GPIOD_AFRH_AFSEL10_WIDTH 4
#define GPIOD_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOD_AFRH_AFSEL9_LSB   4
#define GPIOD_AFRH_AFSEL9_WIDTH 4
#define GPIOD_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOD_AFRH_AFSEL8_LSB   0
#define GPIOD_AFRH_AFSEL8_WIDTH 4
#define GPIOD_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOD_BRR_BR15 (1u << 15)
#define GPIOD_BRR_BR14 (1u << 14)
#define GPIOD_BRR_BR13 (1u << 13)
#define GPIOD_BRR_BR12 (1u << 12)
#define GPIOD_BRR_BR11 (1u << 11)
#define GPIOD_BRR_BR10 (1u << 10)
#define GPIOD_BRR_BR9 (1u << 9)
#define GPIOD_BRR_BR8 (1u << 8)
#define GPIOD_BRR_BR7 (1u << 7)
#define GPIOD_BRR_BR6 (1u << 6)
#define GPIOD_BRR_BR5 (1u << 5)
#define GPIOD_BRR_BR4 (1u << 4)
#define GPIOD_BRR_BR3 (1u << 3)
#define GPIOD_BRR_BR2 (1u << 2)
#define GPIOD_BRR_BR1 (1u << 1)
#define GPIOD_BRR_BR0 (1u << 0)

/* === GPIOH ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOH_Type;

#define GPIOH_BASE 0x50001C00u
#define GPIOH ((volatile GPIOH_Type*)GPIOH_BASE)

#define GPIOH_MODER_MODE15_LSB   30
#define GPIOH_MODER_MODE15_WIDTH 2
#define GPIOH_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOH_MODER_MODE14_LSB   28
#define GPIOH_MODER_MODE14_WIDTH 2
#define GPIOH_MODER_MODE14_MASK  (0x30000000u)
#define GPIOH_MODER_MODE13_LSB   26
#define GPIOH_MODER_MODE13_WIDTH 2
#define GPIOH_MODER_MODE13_MASK  (0xC000000u)
#define GPIOH_MODER_MODE12_LSB   24
#define GPIOH_MODER_MODE12_WIDTH 2
#define GPIOH_MODER_MODE12_MASK  (0x3000000u)
#define GPIOH_MODER_MODE11_LSB   22
#define GPIOH_MODER_MODE11_WIDTH 2
#define GPIOH_MODER_MODE11_MASK  (0xC00000u)
#define GPIOH_MODER_MODE10_LSB   20
#define GPIOH_MODER_MODE10_WIDTH 2
#define GPIOH_MODER_MODE10_MASK  (0x300000u)
#define GPIOH_MODER_MODE9_LSB   18
#define GPIOH_MODER_MODE9_WIDTH 2
#define GPIOH_MODER_MODE9_MASK  (0xC0000u)
#define GPIOH_MODER_MODE8_LSB   16
#define GPIOH_MODER_MODE8_WIDTH 2
#define GPIOH_MODER_MODE8_MASK  (0x30000u)
#define GPIOH_MODER_MODE7_LSB   14
#define GPIOH_MODER_MODE7_WIDTH 2
#define GPIOH_MODER_MODE7_MASK  (0xC000u)
#define GPIOH_MODER_MODE6_LSB   12
#define GPIOH_MODER_MODE6_WIDTH 2
#define GPIOH_MODER_MODE6_MASK  (0x3000u)
#define GPIOH_MODER_MODE5_LSB   10
#define GPIOH_MODER_MODE5_WIDTH 2
#define GPIOH_MODER_MODE5_MASK  (0xC00u)
#define GPIOH_MODER_MODE4_LSB   8
#define GPIOH_MODER_MODE4_WIDTH 2
#define GPIOH_MODER_MODE4_MASK  (0x300u)
#define GPIOH_MODER_MODE3_LSB   6
#define GPIOH_MODER_MODE3_WIDTH 2
#define GPIOH_MODER_MODE3_MASK  (0xC0u)
#define GPIOH_MODER_MODE2_LSB   4
#define GPIOH_MODER_MODE2_WIDTH 2
#define GPIOH_MODER_MODE2_MASK  (0x30u)
#define GPIOH_MODER_MODE1_LSB   2
#define GPIOH_MODER_MODE1_WIDTH 2
#define GPIOH_MODER_MODE1_MASK  (0xCu)
#define GPIOH_MODER_MODE0_LSB   0
#define GPIOH_MODER_MODE0_WIDTH 2
#define GPIOH_MODER_MODE0_MASK  (0x3u)
#define GPIOH_OTYPER_OT15 (1u << 15)
#define GPIOH_OTYPER_OT14 (1u << 14)
#define GPIOH_OTYPER_OT13 (1u << 13)
#define GPIOH_OTYPER_OT12 (1u << 12)
#define GPIOH_OTYPER_OT11 (1u << 11)
#define GPIOH_OTYPER_OT10 (1u << 10)
#define GPIOH_OTYPER_OT9 (1u << 9)
#define GPIOH_OTYPER_OT8 (1u << 8)
#define GPIOH_OTYPER_OT7 (1u << 7)
#define GPIOH_OTYPER_OT6 (1u << 6)
#define GPIOH_OTYPER_OT5 (1u << 5)
#define GPIOH_OTYPER_OT4 (1u << 4)
#define GPIOH_OTYPER_OT3 (1u << 3)
#define GPIOH_OTYPER_OT2 (1u << 2)
#define GPIOH_OTYPER_OT1 (1u << 1)
#define GPIOH_OTYPER_OT0 (1u << 0)
#define GPIOH_OSPEEDR_OSPEED15_LSB   30
#define GPIOH_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOH_OSPEEDR_OSPEED14_LSB   28
#define GPIOH_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOH_OSPEEDR_OSPEED13_LSB   26
#define GPIOH_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOH_OSPEEDR_OSPEED12_LSB   24
#define GPIOH_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOH_OSPEEDR_OSPEED11_LSB   22
#define GPIOH_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOH_OSPEEDR_OSPEED10_LSB   20
#define GPIOH_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOH_OSPEEDR_OSPEED9_LSB   18
#define GPIOH_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOH_OSPEEDR_OSPEED8_LSB   16
#define GPIOH_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOH_OSPEEDR_OSPEED7_LSB   14
#define GPIOH_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOH_OSPEEDR_OSPEED6_LSB   12
#define GPIOH_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOH_OSPEEDR_OSPEED5_LSB   10
#define GPIOH_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOH_OSPEEDR_OSPEED4_LSB   8
#define GPIOH_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOH_OSPEEDR_OSPEED3_LSB   6
#define GPIOH_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOH_OSPEEDR_OSPEED2_LSB   4
#define GPIOH_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOH_OSPEEDR_OSPEED1_LSB   2
#define GPIOH_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOH_OSPEEDR_OSPEED0_LSB   0
#define GPIOH_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOH_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOH_PUPDR_PUPD15_LSB   30
#define GPIOH_PUPDR_PUPD15_WIDTH 2
#define GPIOH_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOH_PUPDR_PUPD14_LSB   28
#define GPIOH_PUPDR_PUPD14_WIDTH 2
#define GPIOH_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOH_PUPDR_PUPD13_LSB   26
#define GPIOH_PUPDR_PUPD13_WIDTH 2
#define GPIOH_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOH_PUPDR_PUPD12_LSB   24
#define GPIOH_PUPDR_PUPD12_WIDTH 2
#define GPIOH_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOH_PUPDR_PUPD11_LSB   22
#define GPIOH_PUPDR_PUPD11_WIDTH 2
#define GPIOH_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOH_PUPDR_PUPD10_LSB   20
#define GPIOH_PUPDR_PUPD10_WIDTH 2
#define GPIOH_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOH_PUPDR_PUPD9_LSB   18
#define GPIOH_PUPDR_PUPD9_WIDTH 2
#define GPIOH_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOH_PUPDR_PUPD8_LSB   16
#define GPIOH_PUPDR_PUPD8_WIDTH 2
#define GPIOH_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOH_PUPDR_PUPD7_LSB   14
#define GPIOH_PUPDR_PUPD7_WIDTH 2
#define GPIOH_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOH_PUPDR_PUPD6_LSB   12
#define GPIOH_PUPDR_PUPD6_WIDTH 2
#define GPIOH_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOH_PUPDR_PUPD5_LSB   10
#define GPIOH_PUPDR_PUPD5_WIDTH 2
#define GPIOH_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOH_PUPDR_PUPD4_LSB   8
#define GPIOH_PUPDR_PUPD4_WIDTH 2
#define GPIOH_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOH_PUPDR_PUPD3_LSB   6
#define GPIOH_PUPDR_PUPD3_WIDTH 2
#define GPIOH_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOH_PUPDR_PUPD2_LSB   4
#define GPIOH_PUPDR_PUPD2_WIDTH 2
#define GPIOH_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOH_PUPDR_PUPD1_LSB   2
#define GPIOH_PUPDR_PUPD1_WIDTH 2
#define GPIOH_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOH_PUPDR_PUPD0_LSB   0
#define GPIOH_PUPDR_PUPD0_WIDTH 2
#define GPIOH_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOH_IDR_ID15 (1u << 15)
#define GPIOH_IDR_ID14 (1u << 14)
#define GPIOH_IDR_ID13 (1u << 13)
#define GPIOH_IDR_ID12 (1u << 12)
#define GPIOH_IDR_ID11 (1u << 11)
#define GPIOH_IDR_ID10 (1u << 10)
#define GPIOH_IDR_ID9 (1u << 9)
#define GPIOH_IDR_ID8 (1u << 8)
#define GPIOH_IDR_ID7 (1u << 7)
#define GPIOH_IDR_ID6 (1u << 6)
#define GPIOH_IDR_ID5 (1u << 5)
#define GPIOH_IDR_ID4 (1u << 4)
#define GPIOH_IDR_ID3 (1u << 3)
#define GPIOH_IDR_ID2 (1u << 2)
#define GPIOH_IDR_ID1 (1u << 1)
#define GPIOH_IDR_ID0 (1u << 0)
#define GPIOH_ODR_OD15 (1u << 15)
#define GPIOH_ODR_OD14 (1u << 14)
#define GPIOH_ODR_OD13 (1u << 13)
#define GPIOH_ODR_OD12 (1u << 12)
#define GPIOH_ODR_OD11 (1u << 11)
#define GPIOH_ODR_OD10 (1u << 10)
#define GPIOH_ODR_OD9 (1u << 9)
#define GPIOH_ODR_OD8 (1u << 8)
#define GPIOH_ODR_OD7 (1u << 7)
#define GPIOH_ODR_OD6 (1u << 6)
#define GPIOH_ODR_OD5 (1u << 5)
#define GPIOH_ODR_OD4 (1u << 4)
#define GPIOH_ODR_OD3 (1u << 3)
#define GPIOH_ODR_OD2 (1u << 2)
#define GPIOH_ODR_OD1 (1u << 1)
#define GPIOH_ODR_OD0 (1u << 0)
#define GPIOH_BSRR_BR15 (1u << 31)
#define GPIOH_BSRR_BR14 (1u << 30)
#define GPIOH_BSRR_BR13 (1u << 29)
#define GPIOH_BSRR_BR12 (1u << 28)
#define GPIOH_BSRR_BR11 (1u << 27)
#define GPIOH_BSRR_BR10 (1u << 26)
#define GPIOH_BSRR_BR9 (1u << 25)
#define GPIOH_BSRR_BR8 (1u << 24)
#define GPIOH_BSRR_BR7 (1u << 23)
#define GPIOH_BSRR_BR6 (1u << 22)
#define GPIOH_BSRR_BR5 (1u << 21)
#define GPIOH_BSRR_BR4 (1u << 20)
#define GPIOH_BSRR_BR3 (1u << 19)
#define GPIOH_BSRR_BR2 (1u << 18)
#define GPIOH_BSRR_BR1 (1u << 17)
#define GPIOH_BSRR_BR0 (1u << 16)
#define GPIOH_BSRR_BS15 (1u << 15)
#define GPIOH_BSRR_BS14 (1u << 14)
#define GPIOH_BSRR_BS13 (1u << 13)
#define GPIOH_BSRR_BS12 (1u << 12)
#define GPIOH_BSRR_BS11 (1u << 11)
#define GPIOH_BSRR_BS10 (1u << 10)
#define GPIOH_BSRR_BS9 (1u << 9)
#define GPIOH_BSRR_BS8 (1u << 8)
#define GPIOH_BSRR_BS7 (1u << 7)
#define GPIOH_BSRR_BS6 (1u << 6)
#define GPIOH_BSRR_BS5 (1u << 5)
#define GPIOH_BSRR_BS4 (1u << 4)
#define GPIOH_BSRR_BS3 (1u << 3)
#define GPIOH_BSRR_BS2 (1u << 2)
#define GPIOH_BSRR_BS1 (1u << 1)
#define GPIOH_BSRR_BS0 (1u << 0)
#define GPIOH_LCKR_LCKK (1u << 16)
#define GPIOH_LCKR_LCK15 (1u << 15)
#define GPIOH_LCKR_LCK14 (1u << 14)
#define GPIOH_LCKR_LCK13 (1u << 13)
#define GPIOH_LCKR_LCK12 (1u << 12)
#define GPIOH_LCKR_LCK11 (1u << 11)
#define GPIOH_LCKR_LCK10 (1u << 10)
#define GPIOH_LCKR_LCK9 (1u << 9)
#define GPIOH_LCKR_LCK8 (1u << 8)
#define GPIOH_LCKR_LCK7 (1u << 7)
#define GPIOH_LCKR_LCK6 (1u << 6)
#define GPIOH_LCKR_LCK5 (1u << 5)
#define GPIOH_LCKR_LCK4 (1u << 4)
#define GPIOH_LCKR_LCK3 (1u << 3)
#define GPIOH_LCKR_LCK2 (1u << 2)
#define GPIOH_LCKR_LCK1 (1u << 1)
#define GPIOH_LCKR_LCK0 (1u << 0)
#define GPIOH_AFRL_AFSEL7_LSB   28
#define GPIOH_AFRL_AFSEL7_WIDTH 4
#define GPIOH_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOH_AFRL_AFSEL6_LSB   24
#define GPIOH_AFRL_AFSEL6_WIDTH 4
#define GPIOH_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOH_AFRL_AFSEL5_LSB   20
#define GPIOH_AFRL_AFSEL5_WIDTH 4
#define GPIOH_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOH_AFRL_AFSEL4_LSB   16
#define GPIOH_AFRL_AFSEL4_WIDTH 4
#define GPIOH_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOH_AFRL_AFSEL3_LSB   12
#define GPIOH_AFRL_AFSEL3_WIDTH 4
#define GPIOH_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOH_AFRL_AFSEL2_LSB   8
#define GPIOH_AFRL_AFSEL2_WIDTH 4
#define GPIOH_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOH_AFRL_AFSEL1_LSB   4
#define GPIOH_AFRL_AFSEL1_WIDTH 4
#define GPIOH_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOH_AFRL_AFSEL0_LSB   0
#define GPIOH_AFRL_AFSEL0_WIDTH 4
#define GPIOH_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOH_AFRH_AFSEL15_LSB   28
#define GPIOH_AFRH_AFSEL15_WIDTH 4
#define GPIOH_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOH_AFRH_AFSEL14_LSB   24
#define GPIOH_AFRH_AFSEL14_WIDTH 4
#define GPIOH_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOH_AFRH_AFSEL13_LSB   20
#define GPIOH_AFRH_AFSEL13_WIDTH 4
#define GPIOH_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOH_AFRH_AFSEL12_LSB   16
#define GPIOH_AFRH_AFSEL12_WIDTH 4
#define GPIOH_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOH_AFRH_AFSEL11_LSB   12
#define GPIOH_AFRH_AFSEL11_WIDTH 4
#define GPIOH_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOH_AFRH_AFSEL10_LSB   8
#define GPIOH_AFRH_AFSEL10_WIDTH 4
#define GPIOH_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOH_AFRH_AFSEL9_LSB   4
#define GPIOH_AFRH_AFSEL9_WIDTH 4
#define GPIOH_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOH_AFRH_AFSEL8_LSB   0
#define GPIOH_AFRH_AFSEL8_WIDTH 4
#define GPIOH_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOH_BRR_BR15 (1u << 15)
#define GPIOH_BRR_BR14 (1u << 14)
#define GPIOH_BRR_BR13 (1u << 13)
#define GPIOH_BRR_BR12 (1u << 12)
#define GPIOH_BRR_BR11 (1u << 11)
#define GPIOH_BRR_BR10 (1u << 10)
#define GPIOH_BRR_BR9 (1u << 9)
#define GPIOH_BRR_BR8 (1u << 8)
#define GPIOH_BRR_BR7 (1u << 7)
#define GPIOH_BRR_BR6 (1u << 6)
#define GPIOH_BRR_BR5 (1u << 5)
#define GPIOH_BRR_BR4 (1u << 4)
#define GPIOH_BRR_BR3 (1u << 3)
#define GPIOH_BRR_BR2 (1u << 2)
#define GPIOH_BRR_BR1 (1u << 1)
#define GPIOH_BRR_BR0 (1u << 0)

/* === GPIOE ================================= */
typedef struct {
    volatile uint32_t MODER; /* 0x000 */
    volatile uint32_t OTYPER; /* 0x004 */
    volatile uint32_t OSPEEDR; /* 0x008 */
    volatile uint32_t PUPDR; /* 0x00C */
    volatile uint32_t IDR; /* 0x010 */
    volatile uint32_t ODR; /* 0x014 */
    volatile uint32_t BSRR; /* 0x018 */
    volatile uint32_t LCKR; /* 0x01C */
    volatile uint32_t AFRL; /* 0x020 */
    volatile uint32_t AFRH; /* 0x024 */
    volatile uint32_t BRR; /* 0x028 */
} GPIOE_Type;

#define GPIOE_BASE 0x50001000u
#define GPIOE ((volatile GPIOE_Type*)GPIOE_BASE)

#define GPIOE_MODER_MODE15_LSB   30
#define GPIOE_MODER_MODE15_WIDTH 2
#define GPIOE_MODER_MODE15_MASK  (0xC0000000u)
#define GPIOE_MODER_MODE14_LSB   28
#define GPIOE_MODER_MODE14_WIDTH 2
#define GPIOE_MODER_MODE14_MASK  (0x30000000u)
#define GPIOE_MODER_MODE13_LSB   26
#define GPIOE_MODER_MODE13_WIDTH 2
#define GPIOE_MODER_MODE13_MASK  (0xC000000u)
#define GPIOE_MODER_MODE12_LSB   24
#define GPIOE_MODER_MODE12_WIDTH 2
#define GPIOE_MODER_MODE12_MASK  (0x3000000u)
#define GPIOE_MODER_MODE11_LSB   22
#define GPIOE_MODER_MODE11_WIDTH 2
#define GPIOE_MODER_MODE11_MASK  (0xC00000u)
#define GPIOE_MODER_MODE10_LSB   20
#define GPIOE_MODER_MODE10_WIDTH 2
#define GPIOE_MODER_MODE10_MASK  (0x300000u)
#define GPIOE_MODER_MODE9_LSB   18
#define GPIOE_MODER_MODE9_WIDTH 2
#define GPIOE_MODER_MODE9_MASK  (0xC0000u)
#define GPIOE_MODER_MODE8_LSB   16
#define GPIOE_MODER_MODE8_WIDTH 2
#define GPIOE_MODER_MODE8_MASK  (0x30000u)
#define GPIOE_MODER_MODE7_LSB   14
#define GPIOE_MODER_MODE7_WIDTH 2
#define GPIOE_MODER_MODE7_MASK  (0xC000u)
#define GPIOE_MODER_MODE6_LSB   12
#define GPIOE_MODER_MODE6_WIDTH 2
#define GPIOE_MODER_MODE6_MASK  (0x3000u)
#define GPIOE_MODER_MODE5_LSB   10
#define GPIOE_MODER_MODE5_WIDTH 2
#define GPIOE_MODER_MODE5_MASK  (0xC00u)
#define GPIOE_MODER_MODE4_LSB   8
#define GPIOE_MODER_MODE4_WIDTH 2
#define GPIOE_MODER_MODE4_MASK  (0x300u)
#define GPIOE_MODER_MODE3_LSB   6
#define GPIOE_MODER_MODE3_WIDTH 2
#define GPIOE_MODER_MODE3_MASK  (0xC0u)
#define GPIOE_MODER_MODE2_LSB   4
#define GPIOE_MODER_MODE2_WIDTH 2
#define GPIOE_MODER_MODE2_MASK  (0x30u)
#define GPIOE_MODER_MODE1_LSB   2
#define GPIOE_MODER_MODE1_WIDTH 2
#define GPIOE_MODER_MODE1_MASK  (0xCu)
#define GPIOE_MODER_MODE0_LSB   0
#define GPIOE_MODER_MODE0_WIDTH 2
#define GPIOE_MODER_MODE0_MASK  (0x3u)
#define GPIOE_OTYPER_OT15 (1u << 15)
#define GPIOE_OTYPER_OT14 (1u << 14)
#define GPIOE_OTYPER_OT13 (1u << 13)
#define GPIOE_OTYPER_OT12 (1u << 12)
#define GPIOE_OTYPER_OT11 (1u << 11)
#define GPIOE_OTYPER_OT10 (1u << 10)
#define GPIOE_OTYPER_OT9 (1u << 9)
#define GPIOE_OTYPER_OT8 (1u << 8)
#define GPIOE_OTYPER_OT7 (1u << 7)
#define GPIOE_OTYPER_OT6 (1u << 6)
#define GPIOE_OTYPER_OT5 (1u << 5)
#define GPIOE_OTYPER_OT4 (1u << 4)
#define GPIOE_OTYPER_OT3 (1u << 3)
#define GPIOE_OTYPER_OT2 (1u << 2)
#define GPIOE_OTYPER_OT1 (1u << 1)
#define GPIOE_OTYPER_OT0 (1u << 0)
#define GPIOE_OSPEEDR_OSPEED15_LSB   30
#define GPIOE_OSPEEDR_OSPEED15_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED15_MASK  (0xC0000000u)
#define GPIOE_OSPEEDR_OSPEED14_LSB   28
#define GPIOE_OSPEEDR_OSPEED14_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED14_MASK  (0x30000000u)
#define GPIOE_OSPEEDR_OSPEED13_LSB   26
#define GPIOE_OSPEEDR_OSPEED13_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED13_MASK  (0xC000000u)
#define GPIOE_OSPEEDR_OSPEED12_LSB   24
#define GPIOE_OSPEEDR_OSPEED12_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED12_MASK  (0x3000000u)
#define GPIOE_OSPEEDR_OSPEED11_LSB   22
#define GPIOE_OSPEEDR_OSPEED11_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED11_MASK  (0xC00000u)
#define GPIOE_OSPEEDR_OSPEED10_LSB   20
#define GPIOE_OSPEEDR_OSPEED10_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED10_MASK  (0x300000u)
#define GPIOE_OSPEEDR_OSPEED9_LSB   18
#define GPIOE_OSPEEDR_OSPEED9_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED9_MASK  (0xC0000u)
#define GPIOE_OSPEEDR_OSPEED8_LSB   16
#define GPIOE_OSPEEDR_OSPEED8_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED8_MASK  (0x30000u)
#define GPIOE_OSPEEDR_OSPEED7_LSB   14
#define GPIOE_OSPEEDR_OSPEED7_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED7_MASK  (0xC000u)
#define GPIOE_OSPEEDR_OSPEED6_LSB   12
#define GPIOE_OSPEEDR_OSPEED6_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED6_MASK  (0x3000u)
#define GPIOE_OSPEEDR_OSPEED5_LSB   10
#define GPIOE_OSPEEDR_OSPEED5_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED5_MASK  (0xC00u)
#define GPIOE_OSPEEDR_OSPEED4_LSB   8
#define GPIOE_OSPEEDR_OSPEED4_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED4_MASK  (0x300u)
#define GPIOE_OSPEEDR_OSPEED3_LSB   6
#define GPIOE_OSPEEDR_OSPEED3_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED3_MASK  (0xC0u)
#define GPIOE_OSPEEDR_OSPEED2_LSB   4
#define GPIOE_OSPEEDR_OSPEED2_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED2_MASK  (0x30u)
#define GPIOE_OSPEEDR_OSPEED1_LSB   2
#define GPIOE_OSPEEDR_OSPEED1_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED1_MASK  (0xCu)
#define GPIOE_OSPEEDR_OSPEED0_LSB   0
#define GPIOE_OSPEEDR_OSPEED0_WIDTH 2
#define GPIOE_OSPEEDR_OSPEED0_MASK  (0x3u)
#define GPIOE_PUPDR_PUPD15_LSB   30
#define GPIOE_PUPDR_PUPD15_WIDTH 2
#define GPIOE_PUPDR_PUPD15_MASK  (0xC0000000u)
#define GPIOE_PUPDR_PUPD14_LSB   28
#define GPIOE_PUPDR_PUPD14_WIDTH 2
#define GPIOE_PUPDR_PUPD14_MASK  (0x30000000u)
#define GPIOE_PUPDR_PUPD13_LSB   26
#define GPIOE_PUPDR_PUPD13_WIDTH 2
#define GPIOE_PUPDR_PUPD13_MASK  (0xC000000u)
#define GPIOE_PUPDR_PUPD12_LSB   24
#define GPIOE_PUPDR_PUPD12_WIDTH 2
#define GPIOE_PUPDR_PUPD12_MASK  (0x3000000u)
#define GPIOE_PUPDR_PUPD11_LSB   22
#define GPIOE_PUPDR_PUPD11_WIDTH 2
#define GPIOE_PUPDR_PUPD11_MASK  (0xC00000u)
#define GPIOE_PUPDR_PUPD10_LSB   20
#define GPIOE_PUPDR_PUPD10_WIDTH 2
#define GPIOE_PUPDR_PUPD10_MASK  (0x300000u)
#define GPIOE_PUPDR_PUPD9_LSB   18
#define GPIOE_PUPDR_PUPD9_WIDTH 2
#define GPIOE_PUPDR_PUPD9_MASK  (0xC0000u)
#define GPIOE_PUPDR_PUPD8_LSB   16
#define GPIOE_PUPDR_PUPD8_WIDTH 2
#define GPIOE_PUPDR_PUPD8_MASK  (0x30000u)
#define GPIOE_PUPDR_PUPD7_LSB   14
#define GPIOE_PUPDR_PUPD7_WIDTH 2
#define GPIOE_PUPDR_PUPD7_MASK  (0xC000u)
#define GPIOE_PUPDR_PUPD6_LSB   12
#define GPIOE_PUPDR_PUPD6_WIDTH 2
#define GPIOE_PUPDR_PUPD6_MASK  (0x3000u)
#define GPIOE_PUPDR_PUPD5_LSB   10
#define GPIOE_PUPDR_PUPD5_WIDTH 2
#define GPIOE_PUPDR_PUPD5_MASK  (0xC00u)
#define GPIOE_PUPDR_PUPD4_LSB   8
#define GPIOE_PUPDR_PUPD4_WIDTH 2
#define GPIOE_PUPDR_PUPD4_MASK  (0x300u)
#define GPIOE_PUPDR_PUPD3_LSB   6
#define GPIOE_PUPDR_PUPD3_WIDTH 2
#define GPIOE_PUPDR_PUPD3_MASK  (0xC0u)
#define GPIOE_PUPDR_PUPD2_LSB   4
#define GPIOE_PUPDR_PUPD2_WIDTH 2
#define GPIOE_PUPDR_PUPD2_MASK  (0x30u)
#define GPIOE_PUPDR_PUPD1_LSB   2
#define GPIOE_PUPDR_PUPD1_WIDTH 2
#define GPIOE_PUPDR_PUPD1_MASK  (0xCu)
#define GPIOE_PUPDR_PUPD0_LSB   0
#define GPIOE_PUPDR_PUPD0_WIDTH 2
#define GPIOE_PUPDR_PUPD0_MASK  (0x3u)
#define GPIOE_IDR_ID15 (1u << 15)
#define GPIOE_IDR_ID14 (1u << 14)
#define GPIOE_IDR_ID13 (1u << 13)
#define GPIOE_IDR_ID12 (1u << 12)
#define GPIOE_IDR_ID11 (1u << 11)
#define GPIOE_IDR_ID10 (1u << 10)
#define GPIOE_IDR_ID9 (1u << 9)
#define GPIOE_IDR_ID8 (1u << 8)
#define GPIOE_IDR_ID7 (1u << 7)
#define GPIOE_IDR_ID6 (1u << 6)
#define GPIOE_IDR_ID5 (1u << 5)
#define GPIOE_IDR_ID4 (1u << 4)
#define GPIOE_IDR_ID3 (1u << 3)
#define GPIOE_IDR_ID2 (1u << 2)
#define GPIOE_IDR_ID1 (1u << 1)
#define GPIOE_IDR_ID0 (1u << 0)
#define GPIOE_ODR_OD15 (1u << 15)
#define GPIOE_ODR_OD14 (1u << 14)
#define GPIOE_ODR_OD13 (1u << 13)
#define GPIOE_ODR_OD12 (1u << 12)
#define GPIOE_ODR_OD11 (1u << 11)
#define GPIOE_ODR_OD10 (1u << 10)
#define GPIOE_ODR_OD9 (1u << 9)
#define GPIOE_ODR_OD8 (1u << 8)
#define GPIOE_ODR_OD7 (1u << 7)
#define GPIOE_ODR_OD6 (1u << 6)
#define GPIOE_ODR_OD5 (1u << 5)
#define GPIOE_ODR_OD4 (1u << 4)
#define GPIOE_ODR_OD3 (1u << 3)
#define GPIOE_ODR_OD2 (1u << 2)
#define GPIOE_ODR_OD1 (1u << 1)
#define GPIOE_ODR_OD0 (1u << 0)
#define GPIOE_BSRR_BR15 (1u << 31)
#define GPIOE_BSRR_BR14 (1u << 30)
#define GPIOE_BSRR_BR13 (1u << 29)
#define GPIOE_BSRR_BR12 (1u << 28)
#define GPIOE_BSRR_BR11 (1u << 27)
#define GPIOE_BSRR_BR10 (1u << 26)
#define GPIOE_BSRR_BR9 (1u << 25)
#define GPIOE_BSRR_BR8 (1u << 24)
#define GPIOE_BSRR_BR7 (1u << 23)
#define GPIOE_BSRR_BR6 (1u << 22)
#define GPIOE_BSRR_BR5 (1u << 21)
#define GPIOE_BSRR_BR4 (1u << 20)
#define GPIOE_BSRR_BR3 (1u << 19)
#define GPIOE_BSRR_BR2 (1u << 18)
#define GPIOE_BSRR_BR1 (1u << 17)
#define GPIOE_BSRR_BR0 (1u << 16)
#define GPIOE_BSRR_BS15 (1u << 15)
#define GPIOE_BSRR_BS14 (1u << 14)
#define GPIOE_BSRR_BS13 (1u << 13)
#define GPIOE_BSRR_BS12 (1u << 12)
#define GPIOE_BSRR_BS11 (1u << 11)
#define GPIOE_BSRR_BS10 (1u << 10)
#define GPIOE_BSRR_BS9 (1u << 9)
#define GPIOE_BSRR_BS8 (1u << 8)
#define GPIOE_BSRR_BS7 (1u << 7)
#define GPIOE_BSRR_BS6 (1u << 6)
#define GPIOE_BSRR_BS5 (1u << 5)
#define GPIOE_BSRR_BS4 (1u << 4)
#define GPIOE_BSRR_BS3 (1u << 3)
#define GPIOE_BSRR_BS2 (1u << 2)
#define GPIOE_BSRR_BS1 (1u << 1)
#define GPIOE_BSRR_BS0 (1u << 0)
#define GPIOE_LCKR_LCKK (1u << 16)
#define GPIOE_LCKR_LCK15 (1u << 15)
#define GPIOE_LCKR_LCK14 (1u << 14)
#define GPIOE_LCKR_LCK13 (1u << 13)
#define GPIOE_LCKR_LCK12 (1u << 12)
#define GPIOE_LCKR_LCK11 (1u << 11)
#define GPIOE_LCKR_LCK10 (1u << 10)
#define GPIOE_LCKR_LCK9 (1u << 9)
#define GPIOE_LCKR_LCK8 (1u << 8)
#define GPIOE_LCKR_LCK7 (1u << 7)
#define GPIOE_LCKR_LCK6 (1u << 6)
#define GPIOE_LCKR_LCK5 (1u << 5)
#define GPIOE_LCKR_LCK4 (1u << 4)
#define GPIOE_LCKR_LCK3 (1u << 3)
#define GPIOE_LCKR_LCK2 (1u << 2)
#define GPIOE_LCKR_LCK1 (1u << 1)
#define GPIOE_LCKR_LCK0 (1u << 0)
#define GPIOE_AFRL_AFSEL7_LSB   28
#define GPIOE_AFRL_AFSEL7_WIDTH 4
#define GPIOE_AFRL_AFSEL7_MASK  (0xF0000000u)
#define GPIOE_AFRL_AFSEL6_LSB   24
#define GPIOE_AFRL_AFSEL6_WIDTH 4
#define GPIOE_AFRL_AFSEL6_MASK  (0xF000000u)
#define GPIOE_AFRL_AFSEL5_LSB   20
#define GPIOE_AFRL_AFSEL5_WIDTH 4
#define GPIOE_AFRL_AFSEL5_MASK  (0xF00000u)
#define GPIOE_AFRL_AFSEL4_LSB   16
#define GPIOE_AFRL_AFSEL4_WIDTH 4
#define GPIOE_AFRL_AFSEL4_MASK  (0xF0000u)
#define GPIOE_AFRL_AFSEL3_LSB   12
#define GPIOE_AFRL_AFSEL3_WIDTH 4
#define GPIOE_AFRL_AFSEL3_MASK  (0xF000u)
#define GPIOE_AFRL_AFSEL2_LSB   8
#define GPIOE_AFRL_AFSEL2_WIDTH 4
#define GPIOE_AFRL_AFSEL2_MASK  (0xF00u)
#define GPIOE_AFRL_AFSEL1_LSB   4
#define GPIOE_AFRL_AFSEL1_WIDTH 4
#define GPIOE_AFRL_AFSEL1_MASK  (0xF0u)
#define GPIOE_AFRL_AFSEL0_LSB   0
#define GPIOE_AFRL_AFSEL0_WIDTH 4
#define GPIOE_AFRL_AFSEL0_MASK  (0xFu)
#define GPIOE_AFRH_AFSEL15_LSB   28
#define GPIOE_AFRH_AFSEL15_WIDTH 4
#define GPIOE_AFRH_AFSEL15_MASK  (0xF0000000u)
#define GPIOE_AFRH_AFSEL14_LSB   24
#define GPIOE_AFRH_AFSEL14_WIDTH 4
#define GPIOE_AFRH_AFSEL14_MASK  (0xF000000u)
#define GPIOE_AFRH_AFSEL13_LSB   20
#define GPIOE_AFRH_AFSEL13_WIDTH 4
#define GPIOE_AFRH_AFSEL13_MASK  (0xF00000u)
#define GPIOE_AFRH_AFSEL12_LSB   16
#define GPIOE_AFRH_AFSEL12_WIDTH 4
#define GPIOE_AFRH_AFSEL12_MASK  (0xF0000u)
#define GPIOE_AFRH_AFSEL11_LSB   12
#define GPIOE_AFRH_AFSEL11_WIDTH 4
#define GPIOE_AFRH_AFSEL11_MASK  (0xF000u)
#define GPIOE_AFRH_AFSEL10_LSB   8
#define GPIOE_AFRH_AFSEL10_WIDTH 4
#define GPIOE_AFRH_AFSEL10_MASK  (0xF00u)
#define GPIOE_AFRH_AFSEL9_LSB   4
#define GPIOE_AFRH_AFSEL9_WIDTH 4
#define GPIOE_AFRH_AFSEL9_MASK  (0xF0u)
#define GPIOE_AFRH_AFSEL8_LSB   0
#define GPIOE_AFRH_AFSEL8_WIDTH 4
#define GPIOE_AFRH_AFSEL8_MASK  (0xFu)
#define GPIOE_BRR_BR15 (1u << 15)
#define GPIOE_BRR_BR14 (1u << 14)
#define GPIOE_BRR_BR13 (1u << 13)
#define GPIOE_BRR_BR12 (1u << 12)
#define GPIOE_BRR_BR11 (1u << 11)
#define GPIOE_BRR_BR10 (1u << 10)
#define GPIOE_BRR_BR9 (1u << 9)
#define GPIOE_BRR_BR8 (1u << 8)
#define GPIOE_BRR_BR7 (1u << 7)
#define GPIOE_BRR_BR6 (1u << 6)
#define GPIOE_BRR_BR5 (1u << 5)
#define GPIOE_BRR_BR4 (1u << 4)
#define GPIOE_BRR_BR3 (1u << 3)
#define GPIOE_BRR_BR2 (1u << 2)
#define GPIOE_BRR_BR1 (1u << 1)
#define GPIOE_BRR_BR0 (1u << 0)

/* === LPTIM ================================= */
typedef struct {
    volatile uint32_t ISR; /* 0x000 */
    volatile uint32_t ICR; /* 0x004 */
    volatile uint32_t IER; /* 0x008 */
    volatile uint32_t CFGR; /* 0x00C */
    volatile uint32_t CR; /* 0x010 */
    volatile uint32_t CMP; /* 0x014 */
    volatile uint32_t ARR; /* 0x018 */
    volatile uint32_t CNT; /* 0x01C */
} LPTIM_Type;

#define LPTIM_BASE 0x40007C00u
#define LPTIM ((volatile LPTIM_Type*)LPTIM_BASE)

#define LPTIM_ISR_DOWN (1u << 6)
#define LPTIM_ISR_UP (1u << 5)
#define LPTIM_ISR_ARROK (1u << 4)
#define LPTIM_ISR_CMPOK (1u << 3)
#define LPTIM_ISR_EXTTRIG (1u << 2)
#define LPTIM_ISR_ARRM (1u << 1)
#define LPTIM_ISR_CMPM (1u << 0)
#define LPTIM_ICR_DOWNCF (1u << 6)
#define LPTIM_ICR_UPCF (1u << 5)
#define LPTIM_ICR_ARROKCF (1u << 4)
#define LPTIM_ICR_CMPOKCF (1u << 3)
#define LPTIM_ICR_EXTTRIGCF (1u << 2)
#define LPTIM_ICR_ARRMCF (1u << 1)
#define LPTIM_ICR_CMPMCF (1u << 0)
#define LPTIM_IER_DOWNIE (1u << 6)
#define LPTIM_IER_UPIE (1u << 5)
#define LPTIM_IER_ARROKIE (1u << 4)
#define LPTIM_IER_CMPOKIE (1u << 3)
#define LPTIM_IER_EXTTRIGIE (1u << 2)
#define LPTIM_IER_ARRMIE (1u << 1)
#define LPTIM_IER_CMPMIE (1u << 0)
#define LPTIM_CFGR_ENC (1u << 24)
#define LPTIM_CFGR_COUNTMODE (1u << 23)
#define LPTIM_CFGR_PRELOAD (1u << 22)
#define LPTIM_CFGR_WAVPOL (1u << 21)
#define LPTIM_CFGR_WAVE (1u << 20)
#define LPTIM_CFGR_TIMOUT (1u << 19)
#define LPTIM_CFGR_TRIGEN_LSB   17
#define LPTIM_CFGR_TRIGEN_WIDTH 2
#define LPTIM_CFGR_TRIGEN_MASK  (0x60000u)
#define LPTIM_CFGR_TRIGSEL_LSB   13
#define LPTIM_CFGR_TRIGSEL_WIDTH 3
#define LPTIM_CFGR_TRIGSEL_MASK  (0xE000u)
#define LPTIM_CFGR_PRESC_LSB   9
#define LPTIM_CFGR_PRESC_WIDTH 3
#define LPTIM_CFGR_PRESC_MASK  (0xE00u)
#define LPTIM_CFGR_TRGFLT_LSB   6
#define LPTIM_CFGR_TRGFLT_WIDTH 2
#define LPTIM_CFGR_TRGFLT_MASK  (0xC0u)
#define LPTIM_CFGR_CKFLT_LSB   3
#define LPTIM_CFGR_CKFLT_WIDTH 2
#define LPTIM_CFGR_CKFLT_MASK  (0x18u)
#define LPTIM_CFGR_CKPOL_LSB   1
#define LPTIM_CFGR_CKPOL_WIDTH 2
#define LPTIM_CFGR_CKPOL_MASK  (0x6u)
#define LPTIM_CFGR_CKSEL (1u << 0)
#define LPTIM_CR_CNTSTRT (1u << 2)
#define LPTIM_CR_SNGSTRT (1u << 1)
#define LPTIM_CR_ENABLE (1u << 0)
#define LPTIM_CMP_CMP_LSB   0
#define LPTIM_CMP_CMP_WIDTH 16
#define LPTIM_CMP_CMP_MASK  (0xFFFFu)
#define LPTIM_ARR_ARR_LSB   0
#define LPTIM_ARR_ARR_WIDTH 16
#define LPTIM_ARR_ARR_MASK  (0xFFFFu)
#define LPTIM_CNT_CNT_LSB   0
#define LPTIM_CNT_CNT_WIDTH 16
#define LPTIM_CNT_CNT_MASK  (0xFFFFu)

/* === RTC ================================= */
typedef struct {
    volatile uint32_t TR; /* 0x000 */
    volatile uint32_t DR; /* 0x004 */
    volatile uint32_t CR; /* 0x008 */
    volatile uint32_t ISR; /* 0x00C */
    volatile uint32_t PRER; /* 0x010 */
    volatile uint32_t WUTR; /* 0x014 */
    uint8_t _res_0018[4];
    volatile uint32_t ALRMAR; /* 0x01C */
    volatile uint32_t ALRMBR; /* 0x020 */
    volatile uint32_t WPR; /* 0x024 */
    volatile uint32_t SSR; /* 0x028 */
    volatile uint32_t SHIFTR; /* 0x02C */
    volatile uint32_t TSTR; /* 0x030 */
    volatile uint32_t TSDR; /* 0x034 */
    volatile uint32_t TSSSR; /* 0x038 */
    volatile uint32_t CALR; /* 0x03C */
    volatile uint32_t TAMPCR; /* 0x040 */
    volatile uint32_t ALRMASSR; /* 0x044 */
    volatile uint32_t ALRMBSSR; /* 0x048 */
    volatile uint32_t OR; /* 0x04C */
    volatile uint32_t BKP0R; /* 0x050 */
    volatile uint32_t BKP1R; /* 0x054 */
    volatile uint32_t BKP2R; /* 0x058 */
    volatile uint32_t BKP3R; /* 0x05C */
    volatile uint32_t BKP4R; /* 0x060 */
} RTC_Type;

#define RTC_BASE 0x40002800u
#define RTC ((volatile RTC_Type*)RTC_BASE)

#define RTC_TR_PM (1u << 22)
#define RTC_TR_HT_LSB   20
#define RTC_TR_HT_WIDTH 2
#define RTC_TR_HT_MASK  (0x300000u)
#define RTC_TR_HU_LSB   16
#define RTC_TR_HU_WIDTH 4
#define RTC_TR_HU_MASK  (0xF0000u)
#define RTC_TR_MNT_LSB   12
#define RTC_TR_MNT_WIDTH 3
#define RTC_TR_MNT_MASK  (0x7000u)
#define RTC_TR_MNU_LSB   8
#define RTC_TR_MNU_WIDTH 4
#define RTC_TR_MNU_MASK  (0xF00u)
#define RTC_TR_ST_LSB   4
#define RTC_TR_ST_WIDTH 3
#define RTC_TR_ST_MASK  (0x70u)
#define RTC_TR_SU_LSB   0
#define RTC_TR_SU_WIDTH 4
#define RTC_TR_SU_MASK  (0xFu)
#define RTC_DR_YT_LSB   20
#define RTC_DR_YT_WIDTH 4
#define RTC_DR_YT_MASK  (0xF00000u)
#define RTC_DR_YU_LSB   16
#define RTC_DR_YU_WIDTH 4
#define RTC_DR_YU_MASK  (0xF0000u)
#define RTC_DR_WDU_LSB   13
#define RTC_DR_WDU_WIDTH 3
#define RTC_DR_WDU_MASK  (0xE000u)
#define RTC_DR_MT (1u << 12)
#define RTC_DR_MU_LSB   8
#define RTC_DR_MU_WIDTH 4
#define RTC_DR_MU_MASK  (0xF00u)
#define RTC_DR_DT_LSB   4
#define RTC_DR_DT_WIDTH 2
#define RTC_DR_DT_MASK  (0x30u)
#define RTC_DR_DU_LSB   0
#define RTC_DR_DU_WIDTH 4
#define RTC_DR_DU_MASK  (0xFu)
#define RTC_CR_COE (1u << 23)
#define RTC_CR_OSEL_LSB   21
#define RTC_CR_OSEL_WIDTH 2
#define RTC_CR_OSEL_MASK  (0x600000u)
#define RTC_CR_POL (1u << 20)
#define RTC_CR_COSEL (1u << 19)
#define RTC_CR_BKP (1u << 18)
#define RTC_CR_SUB1H (1u << 17)
#define RTC_CR_ADD1H (1u << 16)
#define RTC_CR_TSIE (1u << 15)
#define RTC_CR_WUTIE (1u << 14)
#define RTC_CR_ALRBIE (1u << 13)
#define RTC_CR_ALRAIE (1u << 12)
#define RTC_CR_TSE (1u << 11)
#define RTC_CR_WUTE (1u << 10)
#define RTC_CR_ALRBE (1u << 9)
#define RTC_CR_ALRAE (1u << 8)
#define RTC_CR_FMT (1u << 6)
#define RTC_CR_BYPSHAD (1u << 5)
#define RTC_CR_REFCKON (1u << 4)
#define RTC_CR_TSEDGE (1u << 3)
#define RTC_CR_WUCKSEL_LSB   0
#define RTC_CR_WUCKSEL_WIDTH 3
#define RTC_CR_WUCKSEL_MASK  (0x7u)
#define RTC_ISR_TAMP2F (1u << 14)
#define RTC_ISR_TAMP1F (1u << 13)
#define RTC_ISR_TSOVF (1u << 12)
#define RTC_ISR_TSF (1u << 11)
#define RTC_ISR_WUTF (1u << 10)
#define RTC_ISR_ALRBF (1u << 9)
#define RTC_ISR_ALRAF (1u << 8)
#define RTC_ISR_INIT (1u << 7)
#define RTC_ISR_INITF (1u << 6)
#define RTC_ISR_RSF (1u << 5)
#define RTC_ISR_INITS (1u << 4)
#define RTC_ISR_SHPF (1u << 3)
#define RTC_ISR_WUTWF (1u << 2)
#define RTC_ISR_ALRBWF (1u << 1)
#define RTC_ISR_ALRAWF (1u << 0)
#define RTC_PRER_PREDIV_A_LSB   16
#define RTC_PRER_PREDIV_A_WIDTH 7
#define RTC_PRER_PREDIV_A_MASK  (0x7F0000u)
#define RTC_PRER_PREDIV_S_LSB   0
#define RTC_PRER_PREDIV_S_WIDTH 16
#define RTC_PRER_PREDIV_S_MASK  (0xFFFFu)
#define RTC_WUTR_WUT_LSB   0
#define RTC_WUTR_WUT_WIDTH 16
#define RTC_WUTR_WUT_MASK  (0xFFFFu)
#define RTC_ALRMAR_MSK4 (1u << 31)
#define RTC_ALRMAR_WDSEL (1u << 30)
#define RTC_ALRMAR_DT_LSB   28
#define RTC_ALRMAR_DT_WIDTH 2
#define RTC_ALRMAR_DT_MASK  (0x30000000u)
#define RTC_ALRMAR_DU_LSB   24
#define RTC_ALRMAR_DU_WIDTH 4
#define RTC_ALRMAR_DU_MASK  (0xF000000u)
#define RTC_ALRMAR_MSK3 (1u << 23)
#define RTC_ALRMAR_PM (1u << 22)
#define RTC_ALRMAR_HT_LSB   20
#define RTC_ALRMAR_HT_WIDTH 2
#define RTC_ALRMAR_HT_MASK  (0x300000u)
#define RTC_ALRMAR_HU_LSB   16
#define RTC_ALRMAR_HU_WIDTH 4
#define RTC_ALRMAR_HU_MASK  (0xF0000u)
#define RTC_ALRMAR_MSK2 (1u << 15)
#define RTC_ALRMAR_MNT_LSB   12
#define RTC_ALRMAR_MNT_WIDTH 3
#define RTC_ALRMAR_MNT_MASK  (0x7000u)
#define RTC_ALRMAR_MNU_LSB   8
#define RTC_ALRMAR_MNU_WIDTH 4
#define RTC_ALRMAR_MNU_MASK  (0xF00u)
#define RTC_ALRMAR_MSK1 (1u << 7)
#define RTC_ALRMAR_ST_LSB   4
#define RTC_ALRMAR_ST_WIDTH 3
#define RTC_ALRMAR_ST_MASK  (0x70u)
#define RTC_ALRMAR_SU_LSB   0
#define RTC_ALRMAR_SU_WIDTH 4
#define RTC_ALRMAR_SU_MASK  (0xFu)
#define RTC_ALRMBR_MSK4 (1u << 31)
#define RTC_ALRMBR_WDSEL (1u << 30)
#define RTC_ALRMBR_DT_LSB   28
#define RTC_ALRMBR_DT_WIDTH 2
#define RTC_ALRMBR_DT_MASK  (0x30000000u)
#define RTC_ALRMBR_DU_LSB   24
#define RTC_ALRMBR_DU_WIDTH 4
#define RTC_ALRMBR_DU_MASK  (0xF000000u)
#define RTC_ALRMBR_MSK3 (1u << 23)
#define RTC_ALRMBR_PM (1u << 22)
#define RTC_ALRMBR_HT_LSB   20
#define RTC_ALRMBR_HT_WIDTH 2
#define RTC_ALRMBR_HT_MASK  (0x300000u)
#define RTC_ALRMBR_HU_LSB   16
#define RTC_ALRMBR_HU_WIDTH 4
#define RTC_ALRMBR_HU_MASK  (0xF0000u)
#define RTC_ALRMBR_MSK2 (1u << 15)
#define RTC_ALRMBR_MNT_LSB   12
#define RTC_ALRMBR_MNT_WIDTH 3
#define RTC_ALRMBR_MNT_MASK  (0x7000u)
#define RTC_ALRMBR_MNU_LSB   8
#define RTC_ALRMBR_MNU_WIDTH 4
#define RTC_ALRMBR_MNU_MASK  (0xF00u)
#define RTC_ALRMBR_MSK1 (1u << 7)
#define RTC_ALRMBR_ST_LSB   4
#define RTC_ALRMBR_ST_WIDTH 3
#define RTC_ALRMBR_ST_MASK  (0x70u)
#define RTC_ALRMBR_SU_LSB   0
#define RTC_ALRMBR_SU_WIDTH 4
#define RTC_ALRMBR_SU_MASK  (0xFu)
#define RTC_WPR_KEY_LSB   0
#define RTC_WPR_KEY_WIDTH 8
#define RTC_WPR_KEY_MASK  (0xFFu)
#define RTC_SSR_SS_LSB   0
#define RTC_SSR_SS_WIDTH 16
#define RTC_SSR_SS_MASK  (0xFFFFu)
#define RTC_SHIFTR_ADD1S (1u << 31)
#define RTC_SHIFTR_SUBFS_LSB   0
#define RTC_SHIFTR_SUBFS_WIDTH 15
#define RTC_SHIFTR_SUBFS_MASK  (0x7FFFu)
#define RTC_TSTR_PM (1u << 22)
#define RTC_TSTR_HT_LSB   20
#define RTC_TSTR_HT_WIDTH 2
#define RTC_TSTR_HT_MASK  (0x300000u)
#define RTC_TSTR_HU_LSB   16
#define RTC_TSTR_HU_WIDTH 4
#define RTC_TSTR_HU_MASK  (0xF0000u)
#define RTC_TSTR_MNT_LSB   12
#define RTC_TSTR_MNT_WIDTH 3
#define RTC_TSTR_MNT_MASK  (0x7000u)
#define RTC_TSTR_MNU_LSB   8
#define RTC_TSTR_MNU_WIDTH 4
#define RTC_TSTR_MNU_MASK  (0xF00u)
#define RTC_TSTR_ST_LSB   4
#define RTC_TSTR_ST_WIDTH 3
#define RTC_TSTR_ST_MASK  (0x70u)
#define RTC_TSTR_SU_LSB   0
#define RTC_TSTR_SU_WIDTH 4
#define RTC_TSTR_SU_MASK  (0xFu)
#define RTC_TSDR_WDU_LSB   13
#define RTC_TSDR_WDU_WIDTH 3
#define RTC_TSDR_WDU_MASK  (0xE000u)
#define RTC_TSDR_MT (1u << 12)
#define RTC_TSDR_MU_LSB   8
#define RTC_TSDR_MU_WIDTH 4
#define RTC_TSDR_MU_MASK  (0xF00u)
#define RTC_TSDR_DT_LSB   4
#define RTC_TSDR_DT_WIDTH 2
#define RTC_TSDR_DT_MASK  (0x30u)
#define RTC_TSDR_DU_LSB   0
#define RTC_TSDR_DU_WIDTH 4
#define RTC_TSDR_DU_MASK  (0xFu)
#define RTC_TSSSR_SS_LSB   0
#define RTC_TSSSR_SS_WIDTH 16
#define RTC_TSSSR_SS_MASK  (0xFFFFu)
#define RTC_CALR_CALP (1u << 15)
#define RTC_CALR_CALW8 (1u << 14)
#define RTC_CALR_CALW16 (1u << 13)
#define RTC_CALR_CALM_LSB   0
#define RTC_CALR_CALM_WIDTH 9
#define RTC_CALR_CALM_MASK  (0x1FFu)
#define RTC_TAMPCR_TAMP2MF (1u << 21)
#define RTC_TAMPCR_TAMP2NOERASE (1u << 20)
#define RTC_TAMPCR_TAMP2IE (1u << 19)
#define RTC_TAMPCR_TAMP1MF (1u << 18)
#define RTC_TAMPCR_TAMP1NOERASE (1u << 17)
#define RTC_TAMPCR_TAMP1IE (1u << 16)
#define RTC_TAMPCR_TAMPPUDIS (1u << 15)
#define RTC_TAMPCR_TAMPPRCH_LSB   13
#define RTC_TAMPCR_TAMPPRCH_WIDTH 2
#define RTC_TAMPCR_TAMPPRCH_MASK  (0x6000u)
#define RTC_TAMPCR_TAMPFLT_LSB   11
#define RTC_TAMPCR_TAMPFLT_WIDTH 2
#define RTC_TAMPCR_TAMPFLT_MASK  (0x1800u)
#define RTC_TAMPCR_TAMPFREQ_LSB   8
#define RTC_TAMPCR_TAMPFREQ_WIDTH 3
#define RTC_TAMPCR_TAMPFREQ_MASK  (0x700u)
#define RTC_TAMPCR_TAMPTS (1u << 7)
#define RTC_TAMPCR_TAMP2_TRG (1u << 4)
#define RTC_TAMPCR_TAMP2E (1u << 3)
#define RTC_TAMPCR_TAMPIE (1u << 2)
#define RTC_TAMPCR_TAMP1TRG (1u << 1)
#define RTC_TAMPCR_TAMP1E (1u << 0)
#define RTC_ALRMASSR_MASKSS_LSB   24
#define RTC_ALRMASSR_MASKSS_WIDTH 4
#define RTC_ALRMASSR_MASKSS_MASK  (0xF000000u)
#define RTC_ALRMASSR_SS_LSB   0
#define RTC_ALRMASSR_SS_WIDTH 15
#define RTC_ALRMASSR_SS_MASK  (0x7FFFu)
#define RTC_ALRMBSSR_MASKSS_LSB   24
#define RTC_ALRMBSSR_MASKSS_WIDTH 4
#define RTC_ALRMBSSR_MASKSS_MASK  (0xF000000u)
#define RTC_ALRMBSSR_SS_LSB   0
#define RTC_ALRMBSSR_SS_WIDTH 15
#define RTC_ALRMBSSR_SS_MASK  (0x7FFFu)
#define RTC_OR_RTC_OUT_RMP (1u << 1)
#define RTC_OR_RTC_ALARM_TYPE (1u << 0)
#define RTC_BKP0R_BKP_LSB   0
#define RTC_BKP0R_BKP_WIDTH 32
#define RTC_BKP0R_BKP_MASK  (0xFFFFFFFFu)
#define RTC_BKP1R_BKP_LSB   0
#define RTC_BKP1R_BKP_WIDTH 32
#define RTC_BKP1R_BKP_MASK  (0xFFFFFFFFu)
#define RTC_BKP2R_BKP_LSB   0
#define RTC_BKP2R_BKP_WIDTH 32
#define RTC_BKP2R_BKP_MASK  (0xFFFFFFFFu)
#define RTC_BKP3R_BKP_LSB   0
#define RTC_BKP3R_BKP_WIDTH 32
#define RTC_BKP3R_BKP_MASK  (0xFFFFFFFFu)
#define RTC_BKP4R_BKP_LSB   0
#define RTC_BKP4R_BKP_WIDTH 32
#define RTC_BKP4R_BKP_MASK  (0xFFFFFFFFu)

/* === USART1 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t CR3; /* 0x008 */
    volatile uint32_t BRR; /* 0x00C */
    volatile uint32_t GTPR; /* 0x010 */
    volatile uint32_t RTOR; /* 0x014 */
    volatile uint32_t RQR; /* 0x018 */
    volatile uint32_t ISR; /* 0x01C */
    volatile uint32_t ICR; /* 0x020 */
    volatile uint32_t RDR; /* 0x024 */
    volatile uint32_t TDR; /* 0x028 */
} USART1_Type;

#define USART1_BASE 0x40013800u
#define USART1 ((volatile USART1_Type*)USART1_BASE)

#define USART1_CR1_M1 (1u << 28)
#define USART1_CR1_EOBIE (1u << 27)
#define USART1_CR1_RTOIE (1u << 26)
#define USART1_CR1_DEAT4 (1u << 25)
#define USART1_CR1_DEAT3 (1u << 24)
#define USART1_CR1_DEAT2 (1u << 23)
#define USART1_CR1_DEAT1 (1u << 22)
#define USART1_CR1_DEAT0 (1u << 21)
#define USART1_CR1_DEDT4 (1u << 20)
#define USART1_CR1_DEDT3 (1u << 19)
#define USART1_CR1_DEDT2 (1u << 18)
#define USART1_CR1_DEDT1 (1u << 17)
#define USART1_CR1_DEDT0 (1u << 16)
#define USART1_CR1_OVER8 (1u << 15)
#define USART1_CR1_CMIE (1u << 14)
#define USART1_CR1_MME (1u << 13)
#define USART1_CR1_M0 (1u << 12)
#define USART1_CR1_WAKE (1u << 11)
#define USART1_CR1_PCE (1u << 10)
#define USART1_CR1_PS (1u << 9)
#define USART1_CR1_PEIE (1u << 8)
#define USART1_CR1_TXEIE (1u << 7)
#define USART1_CR1_TCIE (1u << 6)
#define USART1_CR1_RXNEIE (1u << 5)
#define USART1_CR1_IDLEIE (1u << 4)
#define USART1_CR1_TE (1u << 3)
#define USART1_CR1_RE (1u << 2)
#define USART1_CR1_UESM (1u << 1)
#define USART1_CR1_UE (1u << 0)
#define USART1_CR2_ADD4_7_LSB   28
#define USART1_CR2_ADD4_7_WIDTH 4
#define USART1_CR2_ADD4_7_MASK  (0xF0000000u)
#define USART1_CR2_ADD0_3_LSB   24
#define USART1_CR2_ADD0_3_WIDTH 4
#define USART1_CR2_ADD0_3_MASK  (0xF000000u)
#define USART1_CR2_RTOEN (1u << 23)
#define USART1_CR2_ABRMOD1 (1u << 22)
#define USART1_CR2_ABRMOD0 (1u << 21)
#define USART1_CR2_ABREN (1u << 20)
#define USART1_CR2_MSBFIRST (1u << 19)
#define USART1_CR2_TAINV (1u << 18)
#define USART1_CR2_TXINV (1u << 17)
#define USART1_CR2_RXINV (1u << 16)
#define USART1_CR2_SWAP (1u << 15)
#define USART1_CR2_LINEN (1u << 14)
#define USART1_CR2_STOP_LSB   12
#define USART1_CR2_STOP_WIDTH 2
#define USART1_CR2_STOP_MASK  (0x3000u)
#define USART1_CR2_CLKEN (1u << 11)
#define USART1_CR2_CPOL (1u << 10)
#define USART1_CR2_CPHA (1u << 9)
#define USART1_CR2_LBCL (1u << 8)
#define USART1_CR2_LBDIE (1u << 6)
#define USART1_CR2_LBDL (1u << 5)
#define USART1_CR2_ADDM7 (1u << 4)
#define USART1_CR3_WUFIE (1u << 22)
#define USART1_CR3_WUS_LSB   20
#define USART1_CR3_WUS_WIDTH 2
#define USART1_CR3_WUS_MASK  (0x300000u)
#define USART1_CR3_SCARCNT_LSB   17
#define USART1_CR3_SCARCNT_WIDTH 3
#define USART1_CR3_SCARCNT_MASK  (0xE0000u)
#define USART1_CR3_DEP (1u << 15)
#define USART1_CR3_DEM (1u << 14)
#define USART1_CR3_DDRE (1u << 13)
#define USART1_CR3_OVRDIS (1u << 12)
#define USART1_CR3_ONEBIT (1u << 11)
#define USART1_CR3_CTSIE (1u << 10)
#define USART1_CR3_CTSE (1u << 9)
#define USART1_CR3_RTSE (1u << 8)
#define USART1_CR3_DMAT (1u << 7)
#define USART1_CR3_DMAR (1u << 6)
#define USART1_CR3_SCEN (1u << 5)
#define USART1_CR3_NACK (1u << 4)
#define USART1_CR3_HDSEL (1u << 3)
#define USART1_CR3_IRLP (1u << 2)
#define USART1_CR3_IREN (1u << 1)
#define USART1_CR3_EIE (1u << 0)
#define USART1_BRR_DIV_MANTISSA_LSB   4
#define USART1_BRR_DIV_MANTISSA_WIDTH 12
#define USART1_BRR_DIV_MANTISSA_MASK  (0xFFF0u)
#define USART1_BRR_DIV_FRACTION_LSB   0
#define USART1_BRR_DIV_FRACTION_WIDTH 4
#define USART1_BRR_DIV_FRACTION_MASK  (0xFu)
#define USART1_GTPR_GT_LSB   8
#define USART1_GTPR_GT_WIDTH 8
#define USART1_GTPR_GT_MASK  (0xFF00u)
#define USART1_GTPR_PSC_LSB   0
#define USART1_GTPR_PSC_WIDTH 8
#define USART1_GTPR_PSC_MASK  (0xFFu)
#define USART1_RTOR_BLEN_LSB   24
#define USART1_RTOR_BLEN_WIDTH 8
#define USART1_RTOR_BLEN_MASK  (0xFF000000u)
#define USART1_RTOR_RTO_LSB   0
#define USART1_RTOR_RTO_WIDTH 24
#define USART1_RTOR_RTO_MASK  (0xFFFFFFu)
#define USART1_RQR_TXFRQ (1u << 4)
#define USART1_RQR_RXFRQ (1u << 3)
#define USART1_RQR_MMRQ (1u << 2)
#define USART1_RQR_SBKRQ (1u << 1)
#define USART1_RQR_ABRRQ (1u << 0)
#define USART1_ISR_REACK (1u << 22)
#define USART1_ISR_TEACK (1u << 21)
#define USART1_ISR_WUF (1u << 20)
#define USART1_ISR_RWU (1u << 19)
#define USART1_ISR_SBKF (1u << 18)
#define USART1_ISR_CMF (1u << 17)
#define USART1_ISR_BUSY (1u << 16)
#define USART1_ISR_ABRF (1u << 15)
#define USART1_ISR_ABRE (1u << 14)
#define USART1_ISR_EOBF (1u << 12)
#define USART1_ISR_RTOF (1u << 11)
#define USART1_ISR_CTS (1u << 10)
#define USART1_ISR_CTSIF (1u << 9)
#define USART1_ISR_LBDF (1u << 8)
#define USART1_ISR_TXE (1u << 7)
#define USART1_ISR_TC (1u << 6)
#define USART1_ISR_RXNE (1u << 5)
#define USART1_ISR_IDLE (1u << 4)
#define USART1_ISR_ORE (1u << 3)
#define USART1_ISR_NF (1u << 2)
#define USART1_ISR_FE (1u << 1)
#define USART1_ISR_PE (1u << 0)
#define USART1_ICR_WUCF (1u << 20)
#define USART1_ICR_CMCF (1u << 17)
#define USART1_ICR_EOBCF (1u << 12)
#define USART1_ICR_RTOCF (1u << 11)
#define USART1_ICR_CTSCF (1u << 9)
#define USART1_ICR_LBDCF (1u << 8)
#define USART1_ICR_TCCF (1u << 6)
#define USART1_ICR_IDLECF (1u << 4)
#define USART1_ICR_ORECF (1u << 3)
#define USART1_ICR_NCF (1u << 2)
#define USART1_ICR_FECF (1u << 1)
#define USART1_ICR_PECF (1u << 0)
#define USART1_RDR_RDR_LSB   0
#define USART1_RDR_RDR_WIDTH 9
#define USART1_RDR_RDR_MASK  (0x1FFu)
#define USART1_TDR_TDR_LSB   0
#define USART1_TDR_TDR_WIDTH 9
#define USART1_TDR_TDR_MASK  (0x1FFu)

/* === USART2 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t CR3; /* 0x008 */
    volatile uint32_t BRR; /* 0x00C */
    volatile uint32_t GTPR; /* 0x010 */
    volatile uint32_t RTOR; /* 0x014 */
    volatile uint32_t RQR; /* 0x018 */
    volatile uint32_t ISR; /* 0x01C */
    volatile uint32_t ICR; /* 0x020 */
    volatile uint32_t RDR; /* 0x024 */
    volatile uint32_t TDR; /* 0x028 */
} USART2_Type;

#define USART2_BASE 0x40004400u
#define USART2 ((volatile USART2_Type*)USART2_BASE)

#define USART2_CR1_M1 (1u << 28)
#define USART2_CR1_EOBIE (1u << 27)
#define USART2_CR1_RTOIE (1u << 26)
#define USART2_CR1_DEAT4 (1u << 25)
#define USART2_CR1_DEAT3 (1u << 24)
#define USART2_CR1_DEAT2 (1u << 23)
#define USART2_CR1_DEAT1 (1u << 22)
#define USART2_CR1_DEAT0 (1u << 21)
#define USART2_CR1_DEDT4 (1u << 20)
#define USART2_CR1_DEDT3 (1u << 19)
#define USART2_CR1_DEDT2 (1u << 18)
#define USART2_CR1_DEDT1 (1u << 17)
#define USART2_CR1_DEDT0 (1u << 16)
#define USART2_CR1_OVER8 (1u << 15)
#define USART2_CR1_CMIE (1u << 14)
#define USART2_CR1_MME (1u << 13)
#define USART2_CR1_M0 (1u << 12)
#define USART2_CR1_WAKE (1u << 11)
#define USART2_CR1_PCE (1u << 10)
#define USART2_CR1_PS (1u << 9)
#define USART2_CR1_PEIE (1u << 8)
#define USART2_CR1_TXEIE (1u << 7)
#define USART2_CR1_TCIE (1u << 6)
#define USART2_CR1_RXNEIE (1u << 5)
#define USART2_CR1_IDLEIE (1u << 4)
#define USART2_CR1_TE (1u << 3)
#define USART2_CR1_RE (1u << 2)
#define USART2_CR1_UESM (1u << 1)
#define USART2_CR1_UE (1u << 0)
#define USART2_CR2_ADD4_7_LSB   28
#define USART2_CR2_ADD4_7_WIDTH 4
#define USART2_CR2_ADD4_7_MASK  (0xF0000000u)
#define USART2_CR2_ADD0_3_LSB   24
#define USART2_CR2_ADD0_3_WIDTH 4
#define USART2_CR2_ADD0_3_MASK  (0xF000000u)
#define USART2_CR2_RTOEN (1u << 23)
#define USART2_CR2_ABRMOD1 (1u << 22)
#define USART2_CR2_ABRMOD0 (1u << 21)
#define USART2_CR2_ABREN (1u << 20)
#define USART2_CR2_MSBFIRST (1u << 19)
#define USART2_CR2_TAINV (1u << 18)
#define USART2_CR2_TXINV (1u << 17)
#define USART2_CR2_RXINV (1u << 16)
#define USART2_CR2_SWAP (1u << 15)
#define USART2_CR2_LINEN (1u << 14)
#define USART2_CR2_STOP_LSB   12
#define USART2_CR2_STOP_WIDTH 2
#define USART2_CR2_STOP_MASK  (0x3000u)
#define USART2_CR2_CLKEN (1u << 11)
#define USART2_CR2_CPOL (1u << 10)
#define USART2_CR2_CPHA (1u << 9)
#define USART2_CR2_LBCL (1u << 8)
#define USART2_CR2_LBDIE (1u << 6)
#define USART2_CR2_LBDL (1u << 5)
#define USART2_CR2_ADDM7 (1u << 4)
#define USART2_CR3_WUFIE (1u << 22)
#define USART2_CR3_WUS_LSB   20
#define USART2_CR3_WUS_WIDTH 2
#define USART2_CR3_WUS_MASK  (0x300000u)
#define USART2_CR3_SCARCNT_LSB   17
#define USART2_CR3_SCARCNT_WIDTH 3
#define USART2_CR3_SCARCNT_MASK  (0xE0000u)
#define USART2_CR3_DEP (1u << 15)
#define USART2_CR3_DEM (1u << 14)
#define USART2_CR3_DDRE (1u << 13)
#define USART2_CR3_OVRDIS (1u << 12)
#define USART2_CR3_ONEBIT (1u << 11)
#define USART2_CR3_CTSIE (1u << 10)
#define USART2_CR3_CTSE (1u << 9)
#define USART2_CR3_RTSE (1u << 8)
#define USART2_CR3_DMAT (1u << 7)
#define USART2_CR3_DMAR (1u << 6)
#define USART2_CR3_SCEN (1u << 5)
#define USART2_CR3_NACK (1u << 4)
#define USART2_CR3_HDSEL (1u << 3)
#define USART2_CR3_IRLP (1u << 2)
#define USART2_CR3_IREN (1u << 1)
#define USART2_CR3_EIE (1u << 0)
#define USART2_BRR_DIV_MANTISSA_LSB   4
#define USART2_BRR_DIV_MANTISSA_WIDTH 12
#define USART2_BRR_DIV_MANTISSA_MASK  (0xFFF0u)
#define USART2_BRR_DIV_FRACTION_LSB   0
#define USART2_BRR_DIV_FRACTION_WIDTH 4
#define USART2_BRR_DIV_FRACTION_MASK  (0xFu)
#define USART2_GTPR_GT_LSB   8
#define USART2_GTPR_GT_WIDTH 8
#define USART2_GTPR_GT_MASK  (0xFF00u)
#define USART2_GTPR_PSC_LSB   0
#define USART2_GTPR_PSC_WIDTH 8
#define USART2_GTPR_PSC_MASK  (0xFFu)
#define USART2_RTOR_BLEN_LSB   24
#define USART2_RTOR_BLEN_WIDTH 8
#define USART2_RTOR_BLEN_MASK  (0xFF000000u)
#define USART2_RTOR_RTO_LSB   0
#define USART2_RTOR_RTO_WIDTH 24
#define USART2_RTOR_RTO_MASK  (0xFFFFFFu)
#define USART2_RQR_TXFRQ (1u << 4)
#define USART2_RQR_RXFRQ (1u << 3)
#define USART2_RQR_MMRQ (1u << 2)
#define USART2_RQR_SBKRQ (1u << 1)
#define USART2_RQR_ABRRQ (1u << 0)
#define USART2_ISR_REACK (1u << 22)
#define USART2_ISR_TEACK (1u << 21)
#define USART2_ISR_WUF (1u << 20)
#define USART2_ISR_RWU (1u << 19)
#define USART2_ISR_SBKF (1u << 18)
#define USART2_ISR_CMF (1u << 17)
#define USART2_ISR_BUSY (1u << 16)
#define USART2_ISR_ABRF (1u << 15)
#define USART2_ISR_ABRE (1u << 14)
#define USART2_ISR_EOBF (1u << 12)
#define USART2_ISR_RTOF (1u << 11)
#define USART2_ISR_CTS (1u << 10)
#define USART2_ISR_CTSIF (1u << 9)
#define USART2_ISR_LBDF (1u << 8)
#define USART2_ISR_TXE (1u << 7)
#define USART2_ISR_TC (1u << 6)
#define USART2_ISR_RXNE (1u << 5)
#define USART2_ISR_IDLE (1u << 4)
#define USART2_ISR_ORE (1u << 3)
#define USART2_ISR_NF (1u << 2)
#define USART2_ISR_FE (1u << 1)
#define USART2_ISR_PE (1u << 0)
#define USART2_ICR_WUCF (1u << 20)
#define USART2_ICR_CMCF (1u << 17)
#define USART2_ICR_EOBCF (1u << 12)
#define USART2_ICR_RTOCF (1u << 11)
#define USART2_ICR_CTSCF (1u << 9)
#define USART2_ICR_LBDCF (1u << 8)
#define USART2_ICR_TCCF (1u << 6)
#define USART2_ICR_IDLECF (1u << 4)
#define USART2_ICR_ORECF (1u << 3)
#define USART2_ICR_NCF (1u << 2)
#define USART2_ICR_FECF (1u << 1)
#define USART2_ICR_PECF (1u << 0)
#define USART2_RDR_RDR_LSB   0
#define USART2_RDR_RDR_WIDTH 9
#define USART2_RDR_RDR_MASK  (0x1FFu)
#define USART2_TDR_TDR_LSB   0
#define USART2_TDR_TDR_WIDTH 9
#define USART2_TDR_TDR_MASK  (0x1FFu)

/* === USART4 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t CR3; /* 0x008 */
    volatile uint32_t BRR; /* 0x00C */
    volatile uint32_t GTPR; /* 0x010 */
    volatile uint32_t RTOR; /* 0x014 */
    volatile uint32_t RQR; /* 0x018 */
    volatile uint32_t ISR; /* 0x01C */
    volatile uint32_t ICR; /* 0x020 */
    volatile uint32_t RDR; /* 0x024 */
    volatile uint32_t TDR; /* 0x028 */
} USART4_Type;

#define USART4_BASE 0x40004C00u
#define USART4 ((volatile USART4_Type*)USART4_BASE)

#define USART4_CR1_M1 (1u << 28)
#define USART4_CR1_EOBIE (1u << 27)
#define USART4_CR1_RTOIE (1u << 26)
#define USART4_CR1_DEAT4 (1u << 25)
#define USART4_CR1_DEAT3 (1u << 24)
#define USART4_CR1_DEAT2 (1u << 23)
#define USART4_CR1_DEAT1 (1u << 22)
#define USART4_CR1_DEAT0 (1u << 21)
#define USART4_CR1_DEDT4 (1u << 20)
#define USART4_CR1_DEDT3 (1u << 19)
#define USART4_CR1_DEDT2 (1u << 18)
#define USART4_CR1_DEDT1 (1u << 17)
#define USART4_CR1_DEDT0 (1u << 16)
#define USART4_CR1_OVER8 (1u << 15)
#define USART4_CR1_CMIE (1u << 14)
#define USART4_CR1_MME (1u << 13)
#define USART4_CR1_M0 (1u << 12)
#define USART4_CR1_WAKE (1u << 11)
#define USART4_CR1_PCE (1u << 10)
#define USART4_CR1_PS (1u << 9)
#define USART4_CR1_PEIE (1u << 8)
#define USART4_CR1_TXEIE (1u << 7)
#define USART4_CR1_TCIE (1u << 6)
#define USART4_CR1_RXNEIE (1u << 5)
#define USART4_CR1_IDLEIE (1u << 4)
#define USART4_CR1_TE (1u << 3)
#define USART4_CR1_RE (1u << 2)
#define USART4_CR1_UESM (1u << 1)
#define USART4_CR1_UE (1u << 0)
#define USART4_CR2_ADD4_7_LSB   28
#define USART4_CR2_ADD4_7_WIDTH 4
#define USART4_CR2_ADD4_7_MASK  (0xF0000000u)
#define USART4_CR2_ADD0_3_LSB   24
#define USART4_CR2_ADD0_3_WIDTH 4
#define USART4_CR2_ADD0_3_MASK  (0xF000000u)
#define USART4_CR2_RTOEN (1u << 23)
#define USART4_CR2_ABRMOD1 (1u << 22)
#define USART4_CR2_ABRMOD0 (1u << 21)
#define USART4_CR2_ABREN (1u << 20)
#define USART4_CR2_MSBFIRST (1u << 19)
#define USART4_CR2_TAINV (1u << 18)
#define USART4_CR2_TXINV (1u << 17)
#define USART4_CR2_RXINV (1u << 16)
#define USART4_CR2_SWAP (1u << 15)
#define USART4_CR2_LINEN (1u << 14)
#define USART4_CR2_STOP_LSB   12
#define USART4_CR2_STOP_WIDTH 2
#define USART4_CR2_STOP_MASK  (0x3000u)
#define USART4_CR2_CLKEN (1u << 11)
#define USART4_CR2_CPOL (1u << 10)
#define USART4_CR2_CPHA (1u << 9)
#define USART4_CR2_LBCL (1u << 8)
#define USART4_CR2_LBDIE (1u << 6)
#define USART4_CR2_LBDL (1u << 5)
#define USART4_CR2_ADDM7 (1u << 4)
#define USART4_CR3_WUFIE (1u << 22)
#define USART4_CR3_WUS_LSB   20
#define USART4_CR3_WUS_WIDTH 2
#define USART4_CR3_WUS_MASK  (0x300000u)
#define USART4_CR3_SCARCNT_LSB   17
#define USART4_CR3_SCARCNT_WIDTH 3
#define USART4_CR3_SCARCNT_MASK  (0xE0000u)
#define USART4_CR3_DEP (1u << 15)
#define USART4_CR3_DEM (1u << 14)
#define USART4_CR3_DDRE (1u << 13)
#define USART4_CR3_OVRDIS (1u << 12)
#define USART4_CR3_ONEBIT (1u << 11)
#define USART4_CR3_CTSIE (1u << 10)
#define USART4_CR3_CTSE (1u << 9)
#define USART4_CR3_RTSE (1u << 8)
#define USART4_CR3_DMAT (1u << 7)
#define USART4_CR3_DMAR (1u << 6)
#define USART4_CR3_SCEN (1u << 5)
#define USART4_CR3_NACK (1u << 4)
#define USART4_CR3_HDSEL (1u << 3)
#define USART4_CR3_IRLP (1u << 2)
#define USART4_CR3_IREN (1u << 1)
#define USART4_CR3_EIE (1u << 0)
#define USART4_BRR_DIV_MANTISSA_LSB   4
#define USART4_BRR_DIV_MANTISSA_WIDTH 12
#define USART4_BRR_DIV_MANTISSA_MASK  (0xFFF0u)
#define USART4_BRR_DIV_FRACTION_LSB   0
#define USART4_BRR_DIV_FRACTION_WIDTH 4
#define USART4_BRR_DIV_FRACTION_MASK  (0xFu)
#define USART4_GTPR_GT_LSB   8
#define USART4_GTPR_GT_WIDTH 8
#define USART4_GTPR_GT_MASK  (0xFF00u)
#define USART4_GTPR_PSC_LSB   0
#define USART4_GTPR_PSC_WIDTH 8
#define USART4_GTPR_PSC_MASK  (0xFFu)
#define USART4_RTOR_BLEN_LSB   24
#define USART4_RTOR_BLEN_WIDTH 8
#define USART4_RTOR_BLEN_MASK  (0xFF000000u)
#define USART4_RTOR_RTO_LSB   0
#define USART4_RTOR_RTO_WIDTH 24
#define USART4_RTOR_RTO_MASK  (0xFFFFFFu)
#define USART4_RQR_TXFRQ (1u << 4)
#define USART4_RQR_RXFRQ (1u << 3)
#define USART4_RQR_MMRQ (1u << 2)
#define USART4_RQR_SBKRQ (1u << 1)
#define USART4_RQR_ABRRQ (1u << 0)
#define USART4_ISR_REACK (1u << 22)
#define USART4_ISR_TEACK (1u << 21)
#define USART4_ISR_WUF (1u << 20)
#define USART4_ISR_RWU (1u << 19)
#define USART4_ISR_SBKF (1u << 18)
#define USART4_ISR_CMF (1u << 17)
#define USART4_ISR_BUSY (1u << 16)
#define USART4_ISR_ABRF (1u << 15)
#define USART4_ISR_ABRE (1u << 14)
#define USART4_ISR_EOBF (1u << 12)
#define USART4_ISR_RTOF (1u << 11)
#define USART4_ISR_CTS (1u << 10)
#define USART4_ISR_CTSIF (1u << 9)
#define USART4_ISR_LBDF (1u << 8)
#define USART4_ISR_TXE (1u << 7)
#define USART4_ISR_TC (1u << 6)
#define USART4_ISR_RXNE (1u << 5)
#define USART4_ISR_IDLE (1u << 4)
#define USART4_ISR_ORE (1u << 3)
#define USART4_ISR_NF (1u << 2)
#define USART4_ISR_FE (1u << 1)
#define USART4_ISR_PE (1u << 0)
#define USART4_ICR_WUCF (1u << 20)
#define USART4_ICR_CMCF (1u << 17)
#define USART4_ICR_EOBCF (1u << 12)
#define USART4_ICR_RTOCF (1u << 11)
#define USART4_ICR_CTSCF (1u << 9)
#define USART4_ICR_LBDCF (1u << 8)
#define USART4_ICR_TCCF (1u << 6)
#define USART4_ICR_IDLECF (1u << 4)
#define USART4_ICR_ORECF (1u << 3)
#define USART4_ICR_NCF (1u << 2)
#define USART4_ICR_FECF (1u << 1)
#define USART4_ICR_PECF (1u << 0)
#define USART4_RDR_RDR_LSB   0
#define USART4_RDR_RDR_WIDTH 9
#define USART4_RDR_RDR_MASK  (0x1FFu)
#define USART4_TDR_TDR_LSB   0
#define USART4_TDR_TDR_WIDTH 9
#define USART4_TDR_TDR_MASK  (0x1FFu)

/* === USART5 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t CR3; /* 0x008 */
    volatile uint32_t BRR; /* 0x00C */
    volatile uint32_t GTPR; /* 0x010 */
    volatile uint32_t RTOR; /* 0x014 */
    volatile uint32_t RQR; /* 0x018 */
    volatile uint32_t ISR; /* 0x01C */
    volatile uint32_t ICR; /* 0x020 */
    volatile uint32_t RDR; /* 0x024 */
    volatile uint32_t TDR; /* 0x028 */
} USART5_Type;

#define USART5_BASE 0x40005000u
#define USART5 ((volatile USART5_Type*)USART5_BASE)

#define USART5_CR1_M1 (1u << 28)
#define USART5_CR1_EOBIE (1u << 27)
#define USART5_CR1_RTOIE (1u << 26)
#define USART5_CR1_DEAT4 (1u << 25)
#define USART5_CR1_DEAT3 (1u << 24)
#define USART5_CR1_DEAT2 (1u << 23)
#define USART5_CR1_DEAT1 (1u << 22)
#define USART5_CR1_DEAT0 (1u << 21)
#define USART5_CR1_DEDT4 (1u << 20)
#define USART5_CR1_DEDT3 (1u << 19)
#define USART5_CR1_DEDT2 (1u << 18)
#define USART5_CR1_DEDT1 (1u << 17)
#define USART5_CR1_DEDT0 (1u << 16)
#define USART5_CR1_OVER8 (1u << 15)
#define USART5_CR1_CMIE (1u << 14)
#define USART5_CR1_MME (1u << 13)
#define USART5_CR1_M0 (1u << 12)
#define USART5_CR1_WAKE (1u << 11)
#define USART5_CR1_PCE (1u << 10)
#define USART5_CR1_PS (1u << 9)
#define USART5_CR1_PEIE (1u << 8)
#define USART5_CR1_TXEIE (1u << 7)
#define USART5_CR1_TCIE (1u << 6)
#define USART5_CR1_RXNEIE (1u << 5)
#define USART5_CR1_IDLEIE (1u << 4)
#define USART5_CR1_TE (1u << 3)
#define USART5_CR1_RE (1u << 2)
#define USART5_CR1_UESM (1u << 1)
#define USART5_CR1_UE (1u << 0)
#define USART5_CR2_ADD4_7_LSB   28
#define USART5_CR2_ADD4_7_WIDTH 4
#define USART5_CR2_ADD4_7_MASK  (0xF0000000u)
#define USART5_CR2_ADD0_3_LSB   24
#define USART5_CR2_ADD0_3_WIDTH 4
#define USART5_CR2_ADD0_3_MASK  (0xF000000u)
#define USART5_CR2_RTOEN (1u << 23)
#define USART5_CR2_ABRMOD1 (1u << 22)
#define USART5_CR2_ABRMOD0 (1u << 21)
#define USART5_CR2_ABREN (1u << 20)
#define USART5_CR2_MSBFIRST (1u << 19)
#define USART5_CR2_TAINV (1u << 18)
#define USART5_CR2_TXINV (1u << 17)
#define USART5_CR2_RXINV (1u << 16)
#define USART5_CR2_SWAP (1u << 15)
#define USART5_CR2_LINEN (1u << 14)
#define USART5_CR2_STOP_LSB   12
#define USART5_CR2_STOP_WIDTH 2
#define USART5_CR2_STOP_MASK  (0x3000u)
#define USART5_CR2_CLKEN (1u << 11)
#define USART5_CR2_CPOL (1u << 10)
#define USART5_CR2_CPHA (1u << 9)
#define USART5_CR2_LBCL (1u << 8)
#define USART5_CR2_LBDIE (1u << 6)
#define USART5_CR2_LBDL (1u << 5)
#define USART5_CR2_ADDM7 (1u << 4)
#define USART5_CR3_WUFIE (1u << 22)
#define USART5_CR3_WUS_LSB   20
#define USART5_CR3_WUS_WIDTH 2
#define USART5_CR3_WUS_MASK  (0x300000u)
#define USART5_CR3_SCARCNT_LSB   17
#define USART5_CR3_SCARCNT_WIDTH 3
#define USART5_CR3_SCARCNT_MASK  (0xE0000u)
#define USART5_CR3_DEP (1u << 15)
#define USART5_CR3_DEM (1u << 14)
#define USART5_CR3_DDRE (1u << 13)
#define USART5_CR3_OVRDIS (1u << 12)
#define USART5_CR3_ONEBIT (1u << 11)
#define USART5_CR3_CTSIE (1u << 10)
#define USART5_CR3_CTSE (1u << 9)
#define USART5_CR3_RTSE (1u << 8)
#define USART5_CR3_DMAT (1u << 7)
#define USART5_CR3_DMAR (1u << 6)
#define USART5_CR3_SCEN (1u << 5)
#define USART5_CR3_NACK (1u << 4)
#define USART5_CR3_HDSEL (1u << 3)
#define USART5_CR3_IRLP (1u << 2)
#define USART5_CR3_IREN (1u << 1)
#define USART5_CR3_EIE (1u << 0)
#define USART5_BRR_DIV_MANTISSA_LSB   4
#define USART5_BRR_DIV_MANTISSA_WIDTH 12
#define USART5_BRR_DIV_MANTISSA_MASK  (0xFFF0u)
#define USART5_BRR_DIV_FRACTION_LSB   0
#define USART5_BRR_DIV_FRACTION_WIDTH 4
#define USART5_BRR_DIV_FRACTION_MASK  (0xFu)
#define USART5_GTPR_GT_LSB   8
#define USART5_GTPR_GT_WIDTH 8
#define USART5_GTPR_GT_MASK  (0xFF00u)
#define USART5_GTPR_PSC_LSB   0
#define USART5_GTPR_PSC_WIDTH 8
#define USART5_GTPR_PSC_MASK  (0xFFu)
#define USART5_RTOR_BLEN_LSB   24
#define USART5_RTOR_BLEN_WIDTH 8
#define USART5_RTOR_BLEN_MASK  (0xFF000000u)
#define USART5_RTOR_RTO_LSB   0
#define USART5_RTOR_RTO_WIDTH 24
#define USART5_RTOR_RTO_MASK  (0xFFFFFFu)
#define USART5_RQR_TXFRQ (1u << 4)
#define USART5_RQR_RXFRQ (1u << 3)
#define USART5_RQR_MMRQ (1u << 2)
#define USART5_RQR_SBKRQ (1u << 1)
#define USART5_RQR_ABRRQ (1u << 0)
#define USART5_ISR_REACK (1u << 22)
#define USART5_ISR_TEACK (1u << 21)
#define USART5_ISR_WUF (1u << 20)
#define USART5_ISR_RWU (1u << 19)
#define USART5_ISR_SBKF (1u << 18)
#define USART5_ISR_CMF (1u << 17)
#define USART5_ISR_BUSY (1u << 16)
#define USART5_ISR_ABRF (1u << 15)
#define USART5_ISR_ABRE (1u << 14)
#define USART5_ISR_EOBF (1u << 12)
#define USART5_ISR_RTOF (1u << 11)
#define USART5_ISR_CTS (1u << 10)
#define USART5_ISR_CTSIF (1u << 9)
#define USART5_ISR_LBDF (1u << 8)
#define USART5_ISR_TXE (1u << 7)
#define USART5_ISR_TC (1u << 6)
#define USART5_ISR_RXNE (1u << 5)
#define USART5_ISR_IDLE (1u << 4)
#define USART5_ISR_ORE (1u << 3)
#define USART5_ISR_NF (1u << 2)
#define USART5_ISR_FE (1u << 1)
#define USART5_ISR_PE (1u << 0)
#define USART5_ICR_WUCF (1u << 20)
#define USART5_ICR_CMCF (1u << 17)
#define USART5_ICR_EOBCF (1u << 12)
#define USART5_ICR_RTOCF (1u << 11)
#define USART5_ICR_CTSCF (1u << 9)
#define USART5_ICR_LBDCF (1u << 8)
#define USART5_ICR_TCCF (1u << 6)
#define USART5_ICR_IDLECF (1u << 4)
#define USART5_ICR_ORECF (1u << 3)
#define USART5_ICR_NCF (1u << 2)
#define USART5_ICR_FECF (1u << 1)
#define USART5_ICR_PECF (1u << 0)
#define USART5_RDR_RDR_LSB   0
#define USART5_RDR_RDR_WIDTH 9
#define USART5_RDR_RDR_MASK  (0x1FFu)
#define USART5_TDR_TDR_LSB   0
#define USART5_TDR_TDR_WIDTH 9
#define USART5_TDR_TDR_MASK  (0x1FFu)

/* === IWDG ================================= */
typedef struct {
    volatile uint32_t KR; /* 0x000 */
    volatile uint32_t PR; /* 0x004 */
    volatile uint32_t RLR; /* 0x008 */
    volatile uint32_t SR; /* 0x00C */
    volatile uint32_t WINR; /* 0x010 */
} IWDG_Type;

#define IWDG_BASE 0x40003000u
#define IWDG ((volatile IWDG_Type*)IWDG_BASE)

#define IWDG_KR_KEY_LSB   0
#define IWDG_KR_KEY_WIDTH 16
#define IWDG_KR_KEY_MASK  (0xFFFFu)
#define IWDG_PR_PR_LSB   0
#define IWDG_PR_PR_WIDTH 3
#define IWDG_PR_PR_MASK  (0x7u)
#define IWDG_RLR_RL_LSB   0
#define IWDG_RLR_RL_WIDTH 12
#define IWDG_RLR_RL_MASK  (0xFFFu)
#define IWDG_SR_WVU (1u << 2)
#define IWDG_SR_RVU (1u << 1)
#define IWDG_SR_PVU (1u << 0)
#define IWDG_WINR_WIN_LSB   0
#define IWDG_WINR_WIN_WIDTH 12
#define IWDG_WINR_WIN_MASK  (0xFFFu)

/* === WWDG ================================= */
typedef struct {
    volatile uint32_t CR; /* 0x000 */
    volatile uint32_t CFR; /* 0x004 */
    volatile uint32_t SR; /* 0x008 */
} WWDG_Type;

#define WWDG_BASE 0x40002C00u
#define WWDG ((volatile WWDG_Type*)WWDG_BASE)

#define WWDG_CR_WDGA (1u << 7)
#define WWDG_CR_T_LSB   0
#define WWDG_CR_T_WIDTH 7
#define WWDG_CR_T_MASK  (0x7Fu)
#define WWDG_CFR_EWI (1u << 9)
#define WWDG_CFR_WDGTB1 (1u << 8)
#define WWDG_CFR_WDGTB0 (1u << 7)
#define WWDG_CFR_W_LSB   0
#define WWDG_CFR_W_WIDTH 7
#define WWDG_CFR_W_MASK  (0x7Fu)
#define WWDG_SR_EWIF (1u << 0)

/* === Firewall ================================= */
typedef struct {
    volatile uint32_t FIREWALL_CSSA; /* 0x000 */
    volatile uint32_t FIREWALL_CSL; /* 0x004 */
    volatile uint32_t FIREWALL_NVDSSA; /* 0x008 */
    volatile uint32_t FIREWALL_NVDSL; /* 0x00C */
    volatile uint32_t FIREWALL_VDSSA; /* 0x010 */
    volatile uint32_t FIREWALL_VDSL; /* 0x014 */
    uint8_t _res_0018[8];
    volatile uint32_t FIREWALL_CR; /* 0x020 */
} Firewall_Type;

#define FIREWALL_BASE 0x40011C00u
#define FIREWALL ((volatile Firewall_Type*)FIREWALL_BASE)

#define FIREWALL_FIREWALL_CSSA_ADD_LSB   8
#define FIREWALL_FIREWALL_CSSA_ADD_WIDTH 16
#define FIREWALL_FIREWALL_CSSA_ADD_MASK  (0xFFFF00u)
#define FIREWALL_FIREWALL_CSL_LENG_LSB   8
#define FIREWALL_FIREWALL_CSL_LENG_WIDTH 14
#define FIREWALL_FIREWALL_CSL_LENG_MASK  (0x3FFF00u)
#define FIREWALL_FIREWALL_NVDSSA_ADD_LSB   8
#define FIREWALL_FIREWALL_NVDSSA_ADD_WIDTH 16
#define FIREWALL_FIREWALL_NVDSSA_ADD_MASK  (0xFFFF00u)
#define FIREWALL_FIREWALL_NVDSL_LENG_LSB   8
#define FIREWALL_FIREWALL_NVDSL_LENG_WIDTH 14
#define FIREWALL_FIREWALL_NVDSL_LENG_MASK  (0x3FFF00u)
#define FIREWALL_FIREWALL_VDSSA_ADD_LSB   6
#define FIREWALL_FIREWALL_VDSSA_ADD_WIDTH 10
#define FIREWALL_FIREWALL_VDSSA_ADD_MASK  (0xFFC0u)
#define FIREWALL_FIREWALL_VDSL_LENG_LSB   6
#define FIREWALL_FIREWALL_VDSL_LENG_WIDTH 10
#define FIREWALL_FIREWALL_VDSL_LENG_MASK  (0xFFC0u)
#define FIREWALL_FIREWALL_CR_VDE (1u << 2)
#define FIREWALL_FIREWALL_CR_VDS (1u << 1)
#define FIREWALL_FIREWALL_CR_FPA (1u << 0)

/* === RCC ================================= */
typedef struct {
    volatile uint32_t CR; /* 0x000 */
    volatile uint32_t ICSCR; /* 0x004 */
    uint8_t _res_0008[4];
    volatile uint32_t CFGR; /* 0x00C */
    volatile uint32_t CIER; /* 0x010 */
    volatile uint32_t CIFR; /* 0x014 */
    volatile uint32_t CICR; /* 0x018 */
    volatile uint32_t IOPRSTR; /* 0x01C */
    volatile uint32_t AHBRSTR; /* 0x020 */
    volatile uint32_t APB2RSTR; /* 0x024 */
    volatile uint32_t APB1RSTR; /* 0x028 */
    volatile uint32_t IOPENR; /* 0x02C */
    volatile uint32_t AHBENR; /* 0x030 */
    volatile uint32_t APB2ENR; /* 0x034 */
    volatile uint32_t APB1ENR; /* 0x038 */
    volatile uint32_t IOPSMEN; /* 0x03C */
    volatile uint32_t AHBSMENR; /* 0x040 */
    volatile uint32_t APB2SMENR; /* 0x044 */
    volatile uint32_t APB1SMENR; /* 0x048 */
    volatile uint32_t CCIPR; /* 0x04C */
    volatile uint32_t CSR; /* 0x050 */
} RCC_Type;

#define RCC_BASE 0x40021000u
#define RCC ((volatile RCC_Type*)RCC_BASE)

#define RCC_CR_PLLRDY (1u << 25)
#define RCC_CR_PLLON (1u << 24)
#define RCC_CR_RTCPRE_LSB   20
#define RCC_CR_RTCPRE_WIDTH 2
#define RCC_CR_RTCPRE_MASK  (0x300000u)
#define RCC_CR_CSSLSEON (1u << 19)
#define RCC_CR_HSEBYP (1u << 18)
#define RCC_CR_HSERDY (1u << 17)
#define RCC_CR_HSEON (1u << 16)
#define RCC_CR_MSIRDY (1u << 9)
#define RCC_CR_MSION (1u << 8)
#define RCC_CR_HSI16DIVF (1u << 4)
#define RCC_CR_HSI16DIVEN (1u << 3)
#define RCC_CR_HSI16RDYF (1u << 2)
#define RCC_CR_HSI16KERON (1u << 1)
#define RCC_CR_HSI16ON (1u << 0)
#define RCC_CR_HSI16OUTEN (1u << 5)
#define RCC_ICSCR_MSITRIM_LSB   24
#define RCC_ICSCR_MSITRIM_WIDTH 8
#define RCC_ICSCR_MSITRIM_MASK  (0xFF000000u)
#define RCC_ICSCR_MSICAL_LSB   16
#define RCC_ICSCR_MSICAL_WIDTH 8
#define RCC_ICSCR_MSICAL_MASK  (0xFF0000u)
#define RCC_ICSCR_MSIRANGE_LSB   13
#define RCC_ICSCR_MSIRANGE_WIDTH 3
#define RCC_ICSCR_MSIRANGE_MASK  (0xE000u)
#define RCC_ICSCR_HSI16TRIM_LSB   8
#define RCC_ICSCR_HSI16TRIM_WIDTH 5
#define RCC_ICSCR_HSI16TRIM_MASK  (0x1F00u)
#define RCC_ICSCR_HSI16CAL_LSB   0
#define RCC_ICSCR_HSI16CAL_WIDTH 8
#define RCC_ICSCR_HSI16CAL_MASK  (0xFFu)
#define RCC_CFGR_MCOPRE_LSB   28
#define RCC_CFGR_MCOPRE_WIDTH 3
#define RCC_CFGR_MCOPRE_MASK  (0x70000000u)
#define RCC_CFGR_MCOSEL_LSB   24
#define RCC_CFGR_MCOSEL_WIDTH 3
#define RCC_CFGR_MCOSEL_MASK  (0x7000000u)
#define RCC_CFGR_PLLDIV_LSB   22
#define RCC_CFGR_PLLDIV_WIDTH 2
#define RCC_CFGR_PLLDIV_MASK  (0xC00000u)
#define RCC_CFGR_PLLMUL_LSB   18
#define RCC_CFGR_PLLMUL_WIDTH 4
#define RCC_CFGR_PLLMUL_MASK  (0x3C0000u)
#define RCC_CFGR_PLLSRC (1u << 16)
#define RCC_CFGR_STOPWUCK (1u << 15)
#define RCC_CFGR_PPRE2_LSB   11
#define RCC_CFGR_PPRE2_WIDTH 3
#define RCC_CFGR_PPRE2_MASK  (0x3800u)
#define RCC_CFGR_PPRE1_LSB   8
#define RCC_CFGR_PPRE1_WIDTH 3
#define RCC_CFGR_PPRE1_MASK  (0x700u)
#define RCC_CFGR_HPRE_LSB   4
#define RCC_CFGR_HPRE_WIDTH 4
#define RCC_CFGR_HPRE_MASK  (0xF0u)
#define RCC_CFGR_SWS_LSB   2
#define RCC_CFGR_SWS_WIDTH 2
#define RCC_CFGR_SWS_MASK  (0xCu)
#define RCC_CFGR_SW_LSB   0
#define RCC_CFGR_SW_WIDTH 2
#define RCC_CFGR_SW_MASK  (0x3u)
#define RCC_CIER_CSSLSE (1u << 7)
#define RCC_CIER_MSIRDYIE (1u << 5)
#define RCC_CIER_PLLRDYIE (1u << 4)
#define RCC_CIER_HSERDYIE (1u << 3)
#define RCC_CIER_HSI16RDYIE (1u << 2)
#define RCC_CIER_LSERDYIE (1u << 1)
#define RCC_CIER_LSIRDYIE (1u << 0)
#define RCC_CIFR_CSSHSEF (1u << 8)
#define RCC_CIFR_CSSLSEF (1u << 7)
#define RCC_CIFR_MSIRDYF (1u << 5)
#define RCC_CIFR_PLLRDYF (1u << 4)
#define RCC_CIFR_HSERDYF (1u << 3)
#define RCC_CIFR_HSI16RDYF (1u << 2)
#define RCC_CIFR_LSERDYF (1u << 1)
#define RCC_CIFR_LSIRDYF (1u << 0)
#define RCC_CICR_CSSHSEC (1u << 8)
#define RCC_CICR_CSSLSEC (1u << 7)
#define RCC_CICR_MSIRDYC (1u << 5)
#define RCC_CICR_PLLRDYC (1u << 4)
#define RCC_CICR_HSERDYC (1u << 3)
#define RCC_CICR_HSI16RDYC (1u << 2)
#define RCC_CICR_LSERDYC (1u << 1)
#define RCC_CICR_LSIRDYC (1u << 0)
#define RCC_IOPRSTR_IOPHRST (1u << 7)
#define RCC_IOPRSTR_IOPDRST (1u << 3)
#define RCC_IOPRSTR_IOPCRST (1u << 2)
#define RCC_IOPRSTR_IOPBRST (1u << 1)
#define RCC_IOPRSTR_IOPARST (1u << 0)
#define RCC_IOPRSTR_IOPERST (1u << 4)
#define RCC_AHBRSTR_CRYPRST (1u << 24)
#define RCC_AHBRSTR_CRCRST (1u << 12)
#define RCC_AHBRSTR_MIFRST (1u << 8)
#define RCC_AHBRSTR_DMARST (1u << 0)
#define RCC_APB2RSTR_DBGRST (1u << 22)
#define RCC_APB2RSTR_USART1RST (1u << 14)
#define RCC_APB2RSTR_SPI1RST (1u << 12)
#define RCC_APB2RSTR_ADCRST (1u << 9)
#define RCC_APB2RSTR_TIM22RST (1u << 5)
#define RCC_APB2RSTR_TIM21RST (1u << 2)
#define RCC_APB2RSTR_SYSCFGRST (1u << 0)
#define RCC_APB1RSTR_LPTIM1RST (1u << 31)
#define RCC_APB1RSTR_PWRRST (1u << 28)
#define RCC_APB1RSTR_I2C2RST (1u << 22)
#define RCC_APB1RSTR_I2C1RST (1u << 21)
#define RCC_APB1RSTR_LPUART1RST (1u << 18)
#define RCC_APB1RSTR_USART2RST (1u << 17)
#define RCC_APB1RSTR_SPI2RST (1u << 14)
#define RCC_APB1RSTR_WWDGRST (1u << 11)
#define RCC_APB1RSTR_TIM6RST (1u << 4)
#define RCC_APB1RSTR_TIM2RST (1u << 0)
#define RCC_APB1RSTR_TIM3RST (1u << 1)
#define RCC_APB1RSTR_TIM7RST (1u << 5)
#define RCC_APB1RSTR_USART4RST (1u << 19)
#define RCC_APB1RSTR_USART5RST (1u << 20)
#define RCC_APB1RSTR_CRCRST (1u << 27)
#define RCC_APB1RSTR_I2C3 (1u << 30)
#define RCC_IOPENR_IOPHEN (1u << 7)
#define RCC_IOPENR_IOPDEN (1u << 3)
#define RCC_IOPENR_IOPCEN (1u << 2)
#define RCC_IOPENR_IOPBEN (1u << 1)
#define RCC_IOPENR_IOPAEN (1u << 0)
#define RCC_IOPENR_IOPEEN (1u << 4)
#define RCC_AHBENR_CRYPEN (1u << 24)
#define RCC_AHBENR_CRCEN (1u << 12)
#define RCC_AHBENR_MIFEN (1u << 8)
#define RCC_AHBENR_DMAEN (1u << 0)
#define RCC_APB2ENR_DBGEN (1u << 22)
#define RCC_APB2ENR_USART1EN (1u << 14)
#define RCC_APB2ENR_SPI1EN (1u << 12)
#define RCC_APB2ENR_ADCEN (1u << 9)
#define RCC_APB2ENR_FWEN (1u << 7)
#define RCC_APB2ENR_TIM22EN (1u << 5)
#define RCC_APB2ENR_TIM21EN (1u << 2)
#define RCC_APB2ENR_SYSCFGEN (1u << 0)
#define RCC_APB1ENR_LPTIM1EN (1u << 31)
#define RCC_APB1ENR_PWREN (1u << 28)
#define RCC_APB1ENR_I2C2EN (1u << 22)
#define RCC_APB1ENR_I2C1EN (1u << 21)
#define RCC_APB1ENR_LPUART1EN (1u << 18)
#define RCC_APB1ENR_USART2EN (1u << 17)
#define RCC_APB1ENR_SPI2EN (1u << 14)
#define RCC_APB1ENR_WWDGEN (1u << 11)
#define RCC_APB1ENR_TIM6EN (1u << 4)
#define RCC_APB1ENR_TIM2EN (1u << 0)
#define RCC_APB1ENR_TIM3EN (1u << 2)
#define RCC_APB1ENR_TIM7EN (1u << 5)
#define RCC_APB1ENR_USART4EN (1u << 19)
#define RCC_APB1ENR_USART5EN (1u << 20)
#define RCC_APB1ENR_I2C3EN (1u << 30)
#define RCC_IOPSMEN_IOPHSMEN (1u << 7)
#define RCC_IOPSMEN_IOPDSMEN (1u << 3)
#define RCC_IOPSMEN_IOPCSMEN (1u << 2)
#define RCC_IOPSMEN_IOPBSMEN (1u << 1)
#define RCC_IOPSMEN_IOPASMEN (1u << 0)
#define RCC_IOPSMEN_IOPESMEN (1u << 4)
#define RCC_AHBSMENR_CRYPTSMEN (1u << 24)
#define RCC_AHBSMENR_CRCSMEN (1u << 12)
#define RCC_AHBSMENR_SRAMSMEN (1u << 9)
#define RCC_AHBSMENR_MIFSMEN (1u << 8)
#define RCC_AHBSMENR_DMASMEN (1u << 0)
#define RCC_APB2SMENR_DBGSMEN (1u << 22)
#define RCC_APB2SMENR_USART1SMEN (1u << 14)
#define RCC_APB2SMENR_SPI1SMEN (1u << 12)
#define RCC_APB2SMENR_ADCSMEN (1u << 9)
#define RCC_APB2SMENR_TIM22SMEN (1u << 5)
#define RCC_APB2SMENR_TIM21SMEN (1u << 2)
#define RCC_APB2SMENR_SYSCFGSMEN (1u << 0)
#define RCC_APB1SMENR_LPTIM1SMEN (1u << 31)
#define RCC_APB1SMENR_PWRSMEN (1u << 28)
#define RCC_APB1SMENR_CRSSMEN (1u << 27)
#define RCC_APB1SMENR_I2C2SMEN (1u << 22)
#define RCC_APB1SMENR_I2C1SMEN (1u << 21)
#define RCC_APB1SMENR_LPUART1SMEN (1u << 18)
#define RCC_APB1SMENR_USART2SMEN (1u << 17)
#define RCC_APB1SMENR_SPI2SMEN (1u << 14)
#define RCC_APB1SMENR_WWDGSMEN (1u << 11)
#define RCC_APB1SMENR_TIM6SMEN (1u << 4)
#define RCC_APB1SMENR_TIM2SMEN (1u << 0)
#define RCC_APB1SMENR_TIM3SMEN (1u << 1)
#define RCC_APB1SMENR_TIM7SMEN (1u << 5)
#define RCC_APB1SMENR_USART4SMEN (1u << 19)
#define RCC_APB1SMENR_USART5SMEN (1u << 20)
#define RCC_APB1SMENR_I2C3SMEN (1u << 30)
#define RCC_CCIPR_LPTIM1SEL1 (1u << 19)
#define RCC_CCIPR_LPTIM1SEL0 (1u << 18)
#define RCC_CCIPR_I2C1SEL1 (1u << 13)
#define RCC_CCIPR_I2C1SEL0 (1u << 12)
#define RCC_CCIPR_LPUART1SEL1 (1u << 11)
#define RCC_CCIPR_LPUART1SEL0 (1u << 10)
#define RCC_CCIPR_USART2SEL1 (1u << 3)
#define RCC_CCIPR_USART2SEL0 (1u << 2)
#define RCC_CCIPR_USART1SEL1 (1u << 1)
#define RCC_CCIPR_USART1SEL0 (1u << 0)
#define RCC_CCIPR_I2C3SEL0 (1u << 16)
#define RCC_CCIPR_I2C3SEL1 (1u << 17)
#define RCC_CSR_LPWRSTF (1u << 31)
#define RCC_CSR_WWDGRSTF (1u << 30)
#define RCC_CSR_IWDGRSTF (1u << 29)
#define RCC_CSR_SFTRSTF (1u << 28)
#define RCC_CSR_PORRSTF (1u << 27)
#define RCC_CSR_PINRSTF (1u << 26)
#define RCC_CSR_OBLRSTF (1u << 25)
#define RCC_CSR_FWRSTF (1u << 24)
#define RCC_CSR_RTCRST (1u << 19)
#define RCC_CSR_RTCEN (1u << 18)
#define RCC_CSR_RTCSEL_LSB   16
#define RCC_CSR_RTCSEL_WIDTH 2
#define RCC_CSR_RTCSEL_MASK  (0x30000u)
#define RCC_CSR_CSSLSED (1u << 14)
#define RCC_CSR_CSSLSEON (1u << 13)
#define RCC_CSR_LSEDRV_LSB   11
#define RCC_CSR_LSEDRV_WIDTH 2
#define RCC_CSR_LSEDRV_MASK  (0x1800u)
#define RCC_CSR_LSEBYP (1u << 10)
#define RCC_CSR_LSERDY (1u << 9)
#define RCC_CSR_LSEON (1u << 8)
#define RCC_CSR_LSIRDY (1u << 1)
#define RCC_CSR_LSION (1u << 0)
#define RCC_CSR_LSIIWDGLP (1u << 2)
#define RCC_CSR_RMVF (1u << 23)

/* === SYSCFG_COMP ================================= */
typedef struct {
    volatile uint32_t CFGR1; /* 0x000 */
    volatile uint32_t CFGR2; /* 0x004 */
    volatile uint32_t EXTICR1; /* 0x008 */
    volatile uint32_t EXTICR2; /* 0x00C */
    volatile uint32_t EXTICR3; /* 0x010 */
    volatile uint32_t EXTICR4; /* 0x014 */
    volatile uint32_t COMP1_CSR; /* 0x018 */
    volatile uint32_t COMP2_CSR; /* 0x01C */
    volatile uint32_t CFGR3; /* 0x020 */
} SYSCFG_COMP_Type;

#define SYSCFG_COMP_BASE 0x40010000u
#define SYSCFG_COMP ((volatile SYSCFG_COMP_Type*)SYSCFG_COMP_BASE)

#define SYSCFG_COMP_CFGR1_BOOT_MODE_LSB   8
#define SYSCFG_COMP_CFGR1_BOOT_MODE_WIDTH 2
#define SYSCFG_COMP_CFGR1_BOOT_MODE_MASK  (0x300u)
#define SYSCFG_COMP_CFGR1_MEM_MODE_LSB   0
#define SYSCFG_COMP_CFGR1_MEM_MODE_WIDTH 2
#define SYSCFG_COMP_CFGR1_MEM_MODE_MASK  (0x3u)
#define SYSCFG_COMP_CFGR2_I2C2_FMP (1u << 13)
#define SYSCFG_COMP_CFGR2_I2C1_FMP (1u << 12)
#define SYSCFG_COMP_CFGR2_I2C_PB9_FMP (1u << 11)
#define SYSCFG_COMP_CFGR2_I2C_PB8_FMP (1u << 10)
#define SYSCFG_COMP_CFGR2_I2C_PB7_FMP (1u << 9)
#define SYSCFG_COMP_CFGR2_I2C_PB6_FMP (1u << 8)
#define SYSCFG_COMP_CFGR2_CAPA_LSB   1
#define SYSCFG_COMP_CFGR2_CAPA_WIDTH 3
#define SYSCFG_COMP_CFGR2_CAPA_MASK  (0xEu)
#define SYSCFG_COMP_CFGR2_FWDISEN (1u << 0)
#define SYSCFG_COMP_EXTICR1_EXTI3_LSB   12
#define SYSCFG_COMP_EXTICR1_EXTI3_WIDTH 4
#define SYSCFG_COMP_EXTICR1_EXTI3_MASK  (0xF000u)
#define SYSCFG_COMP_EXTICR1_EXTI2_LSB   8
#define SYSCFG_COMP_EXTICR1_EXTI2_WIDTH 4
#define SYSCFG_COMP_EXTICR1_EXTI2_MASK  (0xF00u)
#define SYSCFG_COMP_EXTICR1_EXTI1_LSB   4
#define SYSCFG_COMP_EXTICR1_EXTI1_WIDTH 4
#define SYSCFG_COMP_EXTICR1_EXTI1_MASK  (0xF0u)
#define SYSCFG_COMP_EXTICR1_EXTI0_LSB   0
#define SYSCFG_COMP_EXTICR1_EXTI0_WIDTH 4
#define SYSCFG_COMP_EXTICR1_EXTI0_MASK  (0xFu)
#define SYSCFG_COMP_EXTICR2_EXTI7_LSB   12
#define SYSCFG_COMP_EXTICR2_EXTI7_WIDTH 4
#define SYSCFG_COMP_EXTICR2_EXTI7_MASK  (0xF000u)
#define SYSCFG_COMP_EXTICR2_EXTI6_LSB   8
#define SYSCFG_COMP_EXTICR2_EXTI6_WIDTH 4
#define SYSCFG_COMP_EXTICR2_EXTI6_MASK  (0xF00u)
#define SYSCFG_COMP_EXTICR2_EXTI5_LSB   4
#define SYSCFG_COMP_EXTICR2_EXTI5_WIDTH 4
#define SYSCFG_COMP_EXTICR2_EXTI5_MASK  (0xF0u)
#define SYSCFG_COMP_EXTICR2_EXTI4_LSB   0
#define SYSCFG_COMP_EXTICR2_EXTI4_WIDTH 4
#define SYSCFG_COMP_EXTICR2_EXTI4_MASK  (0xFu)
#define SYSCFG_COMP_EXTICR3_EXTI11_LSB   12
#define SYSCFG_COMP_EXTICR3_EXTI11_WIDTH 4
#define SYSCFG_COMP_EXTICR3_EXTI11_MASK  (0xF000u)
#define SYSCFG_COMP_EXTICR3_EXTI10_LSB   8
#define SYSCFG_COMP_EXTICR3_EXTI10_WIDTH 4
#define SYSCFG_COMP_EXTICR3_EXTI10_MASK  (0xF00u)
#define SYSCFG_COMP_EXTICR3_EXTI9_LSB   4
#define SYSCFG_COMP_EXTICR3_EXTI9_WIDTH 4
#define SYSCFG_COMP_EXTICR3_EXTI9_MASK  (0xF0u)
#define SYSCFG_COMP_EXTICR3_EXTI8_LSB   0
#define SYSCFG_COMP_EXTICR3_EXTI8_WIDTH 4
#define SYSCFG_COMP_EXTICR3_EXTI8_MASK  (0xFu)
#define SYSCFG_COMP_EXTICR4_EXTI15_LSB   12
#define SYSCFG_COMP_EXTICR4_EXTI15_WIDTH 4
#define SYSCFG_COMP_EXTICR4_EXTI15_MASK  (0xF000u)
#define SYSCFG_COMP_EXTICR4_EXTI14_LSB   8
#define SYSCFG_COMP_EXTICR4_EXTI14_WIDTH 4
#define SYSCFG_COMP_EXTICR4_EXTI14_MASK  (0xF00u)
#define SYSCFG_COMP_EXTICR4_EXTI13_LSB   4
#define SYSCFG_COMP_EXTICR4_EXTI13_WIDTH 4
#define SYSCFG_COMP_EXTICR4_EXTI13_MASK  (0xF0u)
#define SYSCFG_COMP_EXTICR4_EXTI12_LSB   0
#define SYSCFG_COMP_EXTICR4_EXTI12_WIDTH 4
#define SYSCFG_COMP_EXTICR4_EXTI12_MASK  (0xFu)
#define SYSCFG_COMP_CFGR3_REF_LOCK (1u << 31)
#define SYSCFG_COMP_CFGR3_VREFINT_RDYF (1u << 30)
#define SYSCFG_COMP_CFGR3_VREFINT_COMP_RDYF (1u << 29)
#define SYSCFG_COMP_CFGR3_VREFINT_ADC_RDYF (1u << 28)
#define SYSCFG_COMP_CFGR3_SENSOR_ADC_RDYF (1u << 27)
#define SYSCFG_COMP_CFGR3_REF_RC48MHZ_RDYF (1u << 26)
#define SYSCFG_COMP_CFGR3_ENREF_RC48MHZ (1u << 13)
#define SYSCFG_COMP_CFGR3_ENBUF_VREFINT_COMP (1u << 12)
#define SYSCFG_COMP_CFGR3_ENBUF_SENSOR_ADC (1u << 9)
#define SYSCFG_COMP_CFGR3_ENBUF_BGAP_ADC (1u << 8)
#define SYSCFG_COMP_CFGR3_SEL_VREF_OUT_LSB   4
#define SYSCFG_COMP_CFGR3_SEL_VREF_OUT_WIDTH 2
#define SYSCFG_COMP_CFGR3_SEL_VREF_OUT_MASK  (0x30u)
#define SYSCFG_COMP_CFGR3_EN_BGAP (1u << 0)
#define SYSCFG_COMP_COMP1_CSR_COMP1EN (1u << 0)
#define SYSCFG_COMP_COMP1_CSR_COMP1INNSEL_LSB   4
#define SYSCFG_COMP_COMP1_CSR_COMP1INNSEL_WIDTH 2
#define SYSCFG_COMP_COMP1_CSR_COMP1INNSEL_MASK  (0x30u)
#define SYSCFG_COMP_COMP1_CSR_COMP1WM (1u << 8)
#define SYSCFG_COMP_COMP1_CSR_COMP1LPTIMIN1 (1u << 12)
#define SYSCFG_COMP_COMP1_CSR_COMP1POLARITY (1u << 15)
#define SYSCFG_COMP_COMP1_CSR_COMP1VALUE (1u << 30)
#define SYSCFG_COMP_COMP1_CSR_COMP1LOCK (1u << 31)
#define SYSCFG_COMP_COMP2_CSR_COMP2EN (1u << 0)
#define SYSCFG_COMP_COMP2_CSR_COMP2SPEED (1u << 3)
#define SYSCFG_COMP_COMP2_CSR_COMP2INNSEL_LSB   4
#define SYSCFG_COMP_COMP2_CSR_COMP2INNSEL_WIDTH 3
#define SYSCFG_COMP_COMP2_CSR_COMP2INNSEL_MASK  (0x70u)
#define SYSCFG_COMP_COMP2_CSR_COMP2INPSEL_LSB   8
#define SYSCFG_COMP_COMP2_CSR_COMP2INPSEL_WIDTH 3
#define SYSCFG_COMP_COMP2_CSR_COMP2INPSEL_MASK  (0x700u)
#define SYSCFG_COMP_COMP2_CSR_COMP2LPTIMIN2 (1u << 12)
#define SYSCFG_COMP_COMP2_CSR_COMP2LPTIMIN1 (1u << 13)
#define SYSCFG_COMP_COMP2_CSR_COMP2POLARITY (1u << 15)
#define SYSCFG_COMP_COMP2_CSR_COMP2VALUE (1u << 30)
#define SYSCFG_COMP_COMP2_CSR_COMP2LOCK (1u << 31)

/* === SPI1 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SR; /* 0x008 */
    volatile uint32_t DR; /* 0x00C */
    volatile uint32_t CRCPR; /* 0x010 */
    volatile uint32_t RXCRCR; /* 0x014 */
    volatile uint32_t TXCRCR; /* 0x018 */
    volatile uint32_t I2SCFGR; /* 0x01C */
    volatile uint32_t I2SPR; /* 0x020 */
} SPI1_Type;

#define SPI1_BASE 0x40013000u
#define SPI1 ((volatile SPI1_Type*)SPI1_BASE)

#define SPI1_CR1_BIDIMODE (1u << 15)
#define SPI1_CR1_BIDIOE (1u << 14)
#define SPI1_CR1_CRCEN (1u << 13)
#define SPI1_CR1_CRCNEXT (1u << 12)
#define SPI1_CR1_DFF (1u << 11)
#define SPI1_CR1_RXONLY (1u << 10)
#define SPI1_CR1_SSM (1u << 9)
#define SPI1_CR1_SSI (1u << 8)
#define SPI1_CR1_LSBFIRST (1u << 7)
#define SPI1_CR1_SPE (1u << 6)
#define SPI1_CR1_BR_LSB   3
#define SPI1_CR1_BR_WIDTH 3
#define SPI1_CR1_BR_MASK  (0x38u)
#define SPI1_CR1_MSTR (1u << 2)
#define SPI1_CR1_CPOL (1u << 1)
#define SPI1_CR1_CPHA (1u << 0)
#define SPI1_CR2_RXDMAEN (1u << 0)
#define SPI1_CR2_TXDMAEN (1u << 1)
#define SPI1_CR2_SSOE (1u << 2)
#define SPI1_CR2_FRF (1u << 4)
#define SPI1_CR2_ERRIE (1u << 5)
#define SPI1_CR2_RXNEIE (1u << 6)
#define SPI1_CR2_TXEIE (1u << 7)
#define SPI1_SR_RXNE (1u << 0)
#define SPI1_SR_TXE (1u << 1)
#define SPI1_SR_CHSIDE (1u << 2)
#define SPI1_SR_UDR (1u << 3)
#define SPI1_SR_CRCERR (1u << 4)
#define SPI1_SR_MODF (1u << 5)
#define SPI1_SR_OVR (1u << 6)
#define SPI1_SR_BSY (1u << 7)
#define SPI1_SR_TIFRFE (1u << 8)
#define SPI1_DR_DR_LSB   0
#define SPI1_DR_DR_WIDTH 16
#define SPI1_DR_DR_MASK  (0xFFFFu)
#define SPI1_CRCPR_CRCPOLY_LSB   0
#define SPI1_CRCPR_CRCPOLY_WIDTH 16
#define SPI1_CRCPR_CRCPOLY_MASK  (0xFFFFu)
#define SPI1_RXCRCR_RXCRC_LSB   0
#define SPI1_RXCRCR_RXCRC_WIDTH 16
#define SPI1_RXCRCR_RXCRC_MASK  (0xFFFFu)
#define SPI1_TXCRCR_TXCRC_LSB   0
#define SPI1_TXCRCR_TXCRC_WIDTH 16
#define SPI1_TXCRCR_TXCRC_MASK  (0xFFFFu)
#define SPI1_I2SCFGR_I2SMOD (1u << 11)
#define SPI1_I2SCFGR_I2SE (1u << 10)
#define SPI1_I2SCFGR_I2SCFG_LSB   8
#define SPI1_I2SCFGR_I2SCFG_WIDTH 2
#define SPI1_I2SCFGR_I2SCFG_MASK  (0x300u)
#define SPI1_I2SCFGR_PCMSYNC (1u << 7)
#define SPI1_I2SCFGR_I2SSTD_LSB   4
#define SPI1_I2SCFGR_I2SSTD_WIDTH 2
#define SPI1_I2SCFGR_I2SSTD_MASK  (0x30u)
#define SPI1_I2SCFGR_CKPOL (1u << 3)
#define SPI1_I2SCFGR_DATLEN_LSB   1
#define SPI1_I2SCFGR_DATLEN_WIDTH 2
#define SPI1_I2SCFGR_DATLEN_MASK  (0x6u)
#define SPI1_I2SCFGR_CHLEN (1u << 0)
#define SPI1_I2SPR_MCKOE (1u << 9)
#define SPI1_I2SPR_ODD (1u << 8)
#define SPI1_I2SPR_I2SDIV_LSB   0
#define SPI1_I2SPR_I2SDIV_WIDTH 8
#define SPI1_I2SPR_I2SDIV_MASK  (0xFFu)

/* === SPI2 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SR; /* 0x008 */
    volatile uint32_t DR; /* 0x00C */
    volatile uint32_t CRCPR; /* 0x010 */
    volatile uint32_t RXCRCR; /* 0x014 */
    volatile uint32_t TXCRCR; /* 0x018 */
    volatile uint32_t I2SCFGR; /* 0x01C */
    volatile uint32_t I2SPR; /* 0x020 */
} SPI2_Type;

#define SPI2_BASE 0x40003800u
#define SPI2 ((volatile SPI2_Type*)SPI2_BASE)

#define SPI2_CR1_BIDIMODE (1u << 15)
#define SPI2_CR1_BIDIOE (1u << 14)
#define SPI2_CR1_CRCEN (1u << 13)
#define SPI2_CR1_CRCNEXT (1u << 12)
#define SPI2_CR1_DFF (1u << 11)
#define SPI2_CR1_RXONLY (1u << 10)
#define SPI2_CR1_SSM (1u << 9)
#define SPI2_CR1_SSI (1u << 8)
#define SPI2_CR1_LSBFIRST (1u << 7)
#define SPI2_CR1_SPE (1u << 6)
#define SPI2_CR1_BR_LSB   3
#define SPI2_CR1_BR_WIDTH 3
#define SPI2_CR1_BR_MASK  (0x38u)
#define SPI2_CR1_MSTR (1u << 2)
#define SPI2_CR1_CPOL (1u << 1)
#define SPI2_CR1_CPHA (1u << 0)
#define SPI2_CR2_RXDMAEN (1u << 0)
#define SPI2_CR2_TXDMAEN (1u << 1)
#define SPI2_CR2_SSOE (1u << 2)
#define SPI2_CR2_FRF (1u << 4)
#define SPI2_CR2_ERRIE (1u << 5)
#define SPI2_CR2_RXNEIE (1u << 6)
#define SPI2_CR2_TXEIE (1u << 7)
#define SPI2_SR_RXNE (1u << 0)
#define SPI2_SR_TXE (1u << 1)
#define SPI2_SR_CHSIDE (1u << 2)
#define SPI2_SR_UDR (1u << 3)
#define SPI2_SR_CRCERR (1u << 4)
#define SPI2_SR_MODF (1u << 5)
#define SPI2_SR_OVR (1u << 6)
#define SPI2_SR_BSY (1u << 7)
#define SPI2_SR_TIFRFE (1u << 8)
#define SPI2_DR_DR_LSB   0
#define SPI2_DR_DR_WIDTH 16
#define SPI2_DR_DR_MASK  (0xFFFFu)
#define SPI2_CRCPR_CRCPOLY_LSB   0
#define SPI2_CRCPR_CRCPOLY_WIDTH 16
#define SPI2_CRCPR_CRCPOLY_MASK  (0xFFFFu)
#define SPI2_RXCRCR_RXCRC_LSB   0
#define SPI2_RXCRCR_RXCRC_WIDTH 16
#define SPI2_RXCRCR_RXCRC_MASK  (0xFFFFu)
#define SPI2_TXCRCR_TXCRC_LSB   0
#define SPI2_TXCRCR_TXCRC_WIDTH 16
#define SPI2_TXCRCR_TXCRC_MASK  (0xFFFFu)
#define SPI2_I2SCFGR_I2SMOD (1u << 11)
#define SPI2_I2SCFGR_I2SE (1u << 10)
#define SPI2_I2SCFGR_I2SCFG_LSB   8
#define SPI2_I2SCFGR_I2SCFG_WIDTH 2
#define SPI2_I2SCFGR_I2SCFG_MASK  (0x300u)
#define SPI2_I2SCFGR_PCMSYNC (1u << 7)
#define SPI2_I2SCFGR_I2SSTD_LSB   4
#define SPI2_I2SCFGR_I2SSTD_WIDTH 2
#define SPI2_I2SCFGR_I2SSTD_MASK  (0x30u)
#define SPI2_I2SCFGR_CKPOL (1u << 3)
#define SPI2_I2SCFGR_DATLEN_LSB   1
#define SPI2_I2SCFGR_DATLEN_WIDTH 2
#define SPI2_I2SCFGR_DATLEN_MASK  (0x6u)
#define SPI2_I2SCFGR_CHLEN (1u << 0)
#define SPI2_I2SPR_MCKOE (1u << 9)
#define SPI2_I2SPR_ODD (1u << 8)
#define SPI2_I2SPR_I2SDIV_LSB   0
#define SPI2_I2SPR_I2SDIV_WIDTH 8
#define SPI2_I2SPR_I2SDIV_MASK  (0xFFu)

/* === I2C1 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t OAR1; /* 0x008 */
    volatile uint32_t OAR2; /* 0x00C */
    volatile uint32_t TIMINGR; /* 0x010 */
    volatile uint32_t TIMEOUTR; /* 0x014 */
    volatile uint32_t ISR; /* 0x018 */
    volatile uint32_t ICR; /* 0x01C */
    volatile uint32_t PECR; /* 0x020 */
    volatile uint32_t RXDR; /* 0x024 */
    volatile uint32_t TXDR; /* 0x028 */
} I2C1_Type;

#define I2C1_BASE 0x40005400u
#define I2C1 ((volatile I2C1_Type*)I2C1_BASE)

#define I2C1_CR1_PE (1u << 0)
#define I2C1_CR1_TXIE (1u << 1)
#define I2C1_CR1_RXIE (1u << 2)
#define I2C1_CR1_ADDRIE (1u << 3)
#define I2C1_CR1_NACKIE (1u << 4)
#define I2C1_CR1_STOPIE (1u << 5)
#define I2C1_CR1_TCIE (1u << 6)
#define I2C1_CR1_ERRIE (1u << 7)
#define I2C1_CR1_DNF_LSB   8
#define I2C1_CR1_DNF_WIDTH 4
#define I2C1_CR1_DNF_MASK  (0xF00u)
#define I2C1_CR1_ANFOFF (1u << 12)
#define I2C1_CR1_TXDMAEN (1u << 14)
#define I2C1_CR1_RXDMAEN (1u << 15)
#define I2C1_CR1_SBC (1u << 16)
#define I2C1_CR1_NOSTRETCH (1u << 17)
#define I2C1_CR1_WUPEN (1u << 18)
#define I2C1_CR1_GCEN (1u << 19)
#define I2C1_CR1_SMBHEN (1u << 20)
#define I2C1_CR1_SMBDEN (1u << 21)
#define I2C1_CR1_ALERTEN (1u << 22)
#define I2C1_CR1_PECEN (1u << 23)
#define I2C1_CR2_PECBYTE (1u << 26)
#define I2C1_CR2_AUTOEND (1u << 25)
#define I2C1_CR2_RELOAD (1u << 24)
#define I2C1_CR2_NBYTES_LSB   16
#define I2C1_CR2_NBYTES_WIDTH 8
#define I2C1_CR2_NBYTES_MASK  (0xFF0000u)
#define I2C1_CR2_NACK (1u << 15)
#define I2C1_CR2_STOP (1u << 14)
#define I2C1_CR2_START (1u << 13)
#define I2C1_CR2_HEAD10R (1u << 12)
#define I2C1_CR2_ADD10 (1u << 11)
#define I2C1_CR2_RD_WRN (1u << 10)
#define I2C1_CR2_SADD_LSB   0
#define I2C1_CR2_SADD_WIDTH 10
#define I2C1_CR2_SADD_MASK  (0x3FFu)
#define I2C1_OAR1_OA1_LSB   0
#define I2C1_OAR1_OA1_WIDTH 10
#define I2C1_OAR1_OA1_MASK  (0x3FFu)
#define I2C1_OAR1_OA1MODE (1u << 10)
#define I2C1_OAR1_OA1EN (1u << 15)
#define I2C1_OAR2_OA2_LSB   1
#define I2C1_OAR2_OA2_WIDTH 7
#define I2C1_OAR2_OA2_MASK  (0xFEu)
#define I2C1_OAR2_OA2MSK_LSB   8
#define I2C1_OAR2_OA2MSK_WIDTH 3
#define I2C1_OAR2_OA2MSK_MASK  (0x700u)
#define I2C1_OAR2_OA2EN (1u << 15)
#define I2C1_TIMINGR_SCLL_LSB   0
#define I2C1_TIMINGR_SCLL_WIDTH 8
#define I2C1_TIMINGR_SCLL_MASK  (0xFFu)
#define I2C1_TIMINGR_SCLH_LSB   8
#define I2C1_TIMINGR_SCLH_WIDTH 8
#define I2C1_TIMINGR_SCLH_MASK  (0xFF00u)
#define I2C1_TIMINGR_SDADEL_LSB   16
#define I2C1_TIMINGR_SDADEL_WIDTH 4
#define I2C1_TIMINGR_SDADEL_MASK  (0xF0000u)
#define I2C1_TIMINGR_SCLDEL_LSB   20
#define I2C1_TIMINGR_SCLDEL_WIDTH 4
#define I2C1_TIMINGR_SCLDEL_MASK  (0xF00000u)
#define I2C1_TIMINGR_PRESC_LSB   28
#define I2C1_TIMINGR_PRESC_WIDTH 4
#define I2C1_TIMINGR_PRESC_MASK  (0xF0000000u)
#define I2C1_TIMEOUTR_TIMEOUTA_LSB   0
#define I2C1_TIMEOUTR_TIMEOUTA_WIDTH 12
#define I2C1_TIMEOUTR_TIMEOUTA_MASK  (0xFFFu)
#define I2C1_TIMEOUTR_TIDLE (1u << 12)
#define I2C1_TIMEOUTR_TIMOUTEN (1u << 15)
#define I2C1_TIMEOUTR_TIMEOUTB_LSB   16
#define I2C1_TIMEOUTR_TIMEOUTB_WIDTH 12
#define I2C1_TIMEOUTR_TIMEOUTB_MASK  (0xFFF0000u)
#define I2C1_TIMEOUTR_TEXTEN (1u << 31)
#define I2C1_ISR_ADDCODE_LSB   17
#define I2C1_ISR_ADDCODE_WIDTH 7
#define I2C1_ISR_ADDCODE_MASK  (0xFE0000u)
#define I2C1_ISR_DIR (1u << 16)
#define I2C1_ISR_BUSY (1u << 15)
#define I2C1_ISR_ALERT (1u << 13)
#define I2C1_ISR_TIMEOUT (1u << 12)
#define I2C1_ISR_PECERR (1u << 11)
#define I2C1_ISR_OVR (1u << 10)
#define I2C1_ISR_ARLO (1u << 9)
#define I2C1_ISR_BERR (1u << 8)
#define I2C1_ISR_TCR (1u << 7)
#define I2C1_ISR_TC (1u << 6)
#define I2C1_ISR_STOPF (1u << 5)
#define I2C1_ISR_NACKF (1u << 4)
#define I2C1_ISR_ADDR (1u << 3)
#define I2C1_ISR_RXNE (1u << 2)
#define I2C1_ISR_TXIS (1u << 1)
#define I2C1_ISR_TXE (1u << 0)
#define I2C1_ICR_ALERTCF (1u << 13)
#define I2C1_ICR_TIMOUTCF (1u << 12)
#define I2C1_ICR_PECCF (1u << 11)
#define I2C1_ICR_OVRCF (1u << 10)
#define I2C1_ICR_ARLOCF (1u << 9)
#define I2C1_ICR_BERRCF (1u << 8)
#define I2C1_ICR_STOPCF (1u << 5)
#define I2C1_ICR_NACKCF (1u << 4)
#define I2C1_ICR_ADDRCF (1u << 3)
#define I2C1_PECR_PEC_LSB   0
#define I2C1_PECR_PEC_WIDTH 8
#define I2C1_PECR_PEC_MASK  (0xFFu)
#define I2C1_RXDR_RXDATA_LSB   0
#define I2C1_RXDR_RXDATA_WIDTH 8
#define I2C1_RXDR_RXDATA_MASK  (0xFFu)
#define I2C1_TXDR_TXDATA_LSB   0
#define I2C1_TXDR_TXDATA_WIDTH 8
#define I2C1_TXDR_TXDATA_MASK  (0xFFu)

/* === I2C2 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t OAR1; /* 0x008 */
    volatile uint32_t OAR2; /* 0x00C */
    volatile uint32_t TIMINGR; /* 0x010 */
    volatile uint32_t TIMEOUTR; /* 0x014 */
    volatile uint32_t ISR; /* 0x018 */
    volatile uint32_t ICR; /* 0x01C */
    volatile uint32_t PECR; /* 0x020 */
    volatile uint32_t RXDR; /* 0x024 */
    volatile uint32_t TXDR; /* 0x028 */
} I2C2_Type;

#define I2C2_BASE 0x40005800u
#define I2C2 ((volatile I2C2_Type*)I2C2_BASE)

#define I2C2_CR1_PE (1u << 0)
#define I2C2_CR1_TXIE (1u << 1)
#define I2C2_CR1_RXIE (1u << 2)
#define I2C2_CR1_ADDRIE (1u << 3)
#define I2C2_CR1_NACKIE (1u << 4)
#define I2C2_CR1_STOPIE (1u << 5)
#define I2C2_CR1_TCIE (1u << 6)
#define I2C2_CR1_ERRIE (1u << 7)
#define I2C2_CR1_DNF_LSB   8
#define I2C2_CR1_DNF_WIDTH 4
#define I2C2_CR1_DNF_MASK  (0xF00u)
#define I2C2_CR1_ANFOFF (1u << 12)
#define I2C2_CR1_TXDMAEN (1u << 14)
#define I2C2_CR1_RXDMAEN (1u << 15)
#define I2C2_CR1_SBC (1u << 16)
#define I2C2_CR1_NOSTRETCH (1u << 17)
#define I2C2_CR1_WUPEN (1u << 18)
#define I2C2_CR1_GCEN (1u << 19)
#define I2C2_CR1_SMBHEN (1u << 20)
#define I2C2_CR1_SMBDEN (1u << 21)
#define I2C2_CR1_ALERTEN (1u << 22)
#define I2C2_CR1_PECEN (1u << 23)
#define I2C2_CR2_PECBYTE (1u << 26)
#define I2C2_CR2_AUTOEND (1u << 25)
#define I2C2_CR2_RELOAD (1u << 24)
#define I2C2_CR2_NBYTES_LSB   16
#define I2C2_CR2_NBYTES_WIDTH 8
#define I2C2_CR2_NBYTES_MASK  (0xFF0000u)
#define I2C2_CR2_NACK (1u << 15)
#define I2C2_CR2_STOP (1u << 14)
#define I2C2_CR2_START (1u << 13)
#define I2C2_CR2_HEAD10R (1u << 12)
#define I2C2_CR2_ADD10 (1u << 11)
#define I2C2_CR2_RD_WRN (1u << 10)
#define I2C2_CR2_SADD_LSB   0
#define I2C2_CR2_SADD_WIDTH 10
#define I2C2_CR2_SADD_MASK  (0x3FFu)
#define I2C2_OAR1_OA1_LSB   0
#define I2C2_OAR1_OA1_WIDTH 10
#define I2C2_OAR1_OA1_MASK  (0x3FFu)
#define I2C2_OAR1_OA1MODE (1u << 10)
#define I2C2_OAR1_OA1EN (1u << 15)
#define I2C2_OAR2_OA2_LSB   1
#define I2C2_OAR2_OA2_WIDTH 7
#define I2C2_OAR2_OA2_MASK  (0xFEu)
#define I2C2_OAR2_OA2MSK_LSB   8
#define I2C2_OAR2_OA2MSK_WIDTH 3
#define I2C2_OAR2_OA2MSK_MASK  (0x700u)
#define I2C2_OAR2_OA2EN (1u << 15)
#define I2C2_TIMINGR_SCLL_LSB   0
#define I2C2_TIMINGR_SCLL_WIDTH 8
#define I2C2_TIMINGR_SCLL_MASK  (0xFFu)
#define I2C2_TIMINGR_SCLH_LSB   8
#define I2C2_TIMINGR_SCLH_WIDTH 8
#define I2C2_TIMINGR_SCLH_MASK  (0xFF00u)
#define I2C2_TIMINGR_SDADEL_LSB   16
#define I2C2_TIMINGR_SDADEL_WIDTH 4
#define I2C2_TIMINGR_SDADEL_MASK  (0xF0000u)
#define I2C2_TIMINGR_SCLDEL_LSB   20
#define I2C2_TIMINGR_SCLDEL_WIDTH 4
#define I2C2_TIMINGR_SCLDEL_MASK  (0xF00000u)
#define I2C2_TIMINGR_PRESC_LSB   28
#define I2C2_TIMINGR_PRESC_WIDTH 4
#define I2C2_TIMINGR_PRESC_MASK  (0xF0000000u)
#define I2C2_TIMEOUTR_TIMEOUTA_LSB   0
#define I2C2_TIMEOUTR_TIMEOUTA_WIDTH 12
#define I2C2_TIMEOUTR_TIMEOUTA_MASK  (0xFFFu)
#define I2C2_TIMEOUTR_TIDLE (1u << 12)
#define I2C2_TIMEOUTR_TIMOUTEN (1u << 15)
#define I2C2_TIMEOUTR_TIMEOUTB_LSB   16
#define I2C2_TIMEOUTR_TIMEOUTB_WIDTH 12
#define I2C2_TIMEOUTR_TIMEOUTB_MASK  (0xFFF0000u)
#define I2C2_TIMEOUTR_TEXTEN (1u << 31)
#define I2C2_ISR_ADDCODE_LSB   17
#define I2C2_ISR_ADDCODE_WIDTH 7
#define I2C2_ISR_ADDCODE_MASK  (0xFE0000u)
#define I2C2_ISR_DIR (1u << 16)
#define I2C2_ISR_BUSY (1u << 15)
#define I2C2_ISR_ALERT (1u << 13)
#define I2C2_ISR_TIMEOUT (1u << 12)
#define I2C2_ISR_PECERR (1u << 11)
#define I2C2_ISR_OVR (1u << 10)
#define I2C2_ISR_ARLO (1u << 9)
#define I2C2_ISR_BERR (1u << 8)
#define I2C2_ISR_TCR (1u << 7)
#define I2C2_ISR_TC (1u << 6)
#define I2C2_ISR_STOPF (1u << 5)
#define I2C2_ISR_NACKF (1u << 4)
#define I2C2_ISR_ADDR (1u << 3)
#define I2C2_ISR_RXNE (1u << 2)
#define I2C2_ISR_TXIS (1u << 1)
#define I2C2_ISR_TXE (1u << 0)
#define I2C2_ICR_ALERTCF (1u << 13)
#define I2C2_ICR_TIMOUTCF (1u << 12)
#define I2C2_ICR_PECCF (1u << 11)
#define I2C2_ICR_OVRCF (1u << 10)
#define I2C2_ICR_ARLOCF (1u << 9)
#define I2C2_ICR_BERRCF (1u << 8)
#define I2C2_ICR_STOPCF (1u << 5)
#define I2C2_ICR_NACKCF (1u << 4)
#define I2C2_ICR_ADDRCF (1u << 3)
#define I2C2_PECR_PEC_LSB   0
#define I2C2_PECR_PEC_WIDTH 8
#define I2C2_PECR_PEC_MASK  (0xFFu)
#define I2C2_RXDR_RXDATA_LSB   0
#define I2C2_RXDR_RXDATA_WIDTH 8
#define I2C2_RXDR_RXDATA_MASK  (0xFFu)
#define I2C2_TXDR_TXDATA_LSB   0
#define I2C2_TXDR_TXDATA_WIDTH 8
#define I2C2_TXDR_TXDATA_MASK  (0xFFu)

/* === I2C3 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t OAR1; /* 0x008 */
    volatile uint32_t OAR2; /* 0x00C */
    volatile uint32_t TIMINGR; /* 0x010 */
    volatile uint32_t TIMEOUTR; /* 0x014 */
    volatile uint32_t ISR; /* 0x018 */
    volatile uint32_t ICR; /* 0x01C */
    volatile uint32_t PECR; /* 0x020 */
    volatile uint32_t RXDR; /* 0x024 */
    volatile uint32_t TXDR; /* 0x028 */
} I2C3_Type;

#define I2C3_BASE 0x40007800u
#define I2C3 ((volatile I2C3_Type*)I2C3_BASE)

#define I2C3_CR1_PE (1u << 0)
#define I2C3_CR1_TXIE (1u << 1)
#define I2C3_CR1_RXIE (1u << 2)
#define I2C3_CR1_ADDRIE (1u << 3)
#define I2C3_CR1_NACKIE (1u << 4)
#define I2C3_CR1_STOPIE (1u << 5)
#define I2C3_CR1_TCIE (1u << 6)
#define I2C3_CR1_ERRIE (1u << 7)
#define I2C3_CR1_DNF_LSB   8
#define I2C3_CR1_DNF_WIDTH 4
#define I2C3_CR1_DNF_MASK  (0xF00u)
#define I2C3_CR1_ANFOFF (1u << 12)
#define I2C3_CR1_TXDMAEN (1u << 14)
#define I2C3_CR1_RXDMAEN (1u << 15)
#define I2C3_CR1_SBC (1u << 16)
#define I2C3_CR1_NOSTRETCH (1u << 17)
#define I2C3_CR1_WUPEN (1u << 18)
#define I2C3_CR1_GCEN (1u << 19)
#define I2C3_CR1_SMBHEN (1u << 20)
#define I2C3_CR1_SMBDEN (1u << 21)
#define I2C3_CR1_ALERTEN (1u << 22)
#define I2C3_CR1_PECEN (1u << 23)
#define I2C3_CR2_PECBYTE (1u << 26)
#define I2C3_CR2_AUTOEND (1u << 25)
#define I2C3_CR2_RELOAD (1u << 24)
#define I2C3_CR2_NBYTES_LSB   16
#define I2C3_CR2_NBYTES_WIDTH 8
#define I2C3_CR2_NBYTES_MASK  (0xFF0000u)
#define I2C3_CR2_NACK (1u << 15)
#define I2C3_CR2_STOP (1u << 14)
#define I2C3_CR2_START (1u << 13)
#define I2C3_CR2_HEAD10R (1u << 12)
#define I2C3_CR2_ADD10 (1u << 11)
#define I2C3_CR2_RD_WRN (1u << 10)
#define I2C3_CR2_SADD_LSB   0
#define I2C3_CR2_SADD_WIDTH 10
#define I2C3_CR2_SADD_MASK  (0x3FFu)
#define I2C3_OAR1_OA1_LSB   0
#define I2C3_OAR1_OA1_WIDTH 10
#define I2C3_OAR1_OA1_MASK  (0x3FFu)
#define I2C3_OAR1_OA1MODE (1u << 10)
#define I2C3_OAR1_OA1EN (1u << 15)
#define I2C3_OAR2_OA2_LSB   1
#define I2C3_OAR2_OA2_WIDTH 7
#define I2C3_OAR2_OA2_MASK  (0xFEu)
#define I2C3_OAR2_OA2MSK_LSB   8
#define I2C3_OAR2_OA2MSK_WIDTH 3
#define I2C3_OAR2_OA2MSK_MASK  (0x700u)
#define I2C3_OAR2_OA2EN (1u << 15)
#define I2C3_TIMINGR_SCLL_LSB   0
#define I2C3_TIMINGR_SCLL_WIDTH 8
#define I2C3_TIMINGR_SCLL_MASK  (0xFFu)
#define I2C3_TIMINGR_SCLH_LSB   8
#define I2C3_TIMINGR_SCLH_WIDTH 8
#define I2C3_TIMINGR_SCLH_MASK  (0xFF00u)
#define I2C3_TIMINGR_SDADEL_LSB   16
#define I2C3_TIMINGR_SDADEL_WIDTH 4
#define I2C3_TIMINGR_SDADEL_MASK  (0xF0000u)
#define I2C3_TIMINGR_SCLDEL_LSB   20
#define I2C3_TIMINGR_SCLDEL_WIDTH 4
#define I2C3_TIMINGR_SCLDEL_MASK  (0xF00000u)
#define I2C3_TIMINGR_PRESC_LSB   28
#define I2C3_TIMINGR_PRESC_WIDTH 4
#define I2C3_TIMINGR_PRESC_MASK  (0xF0000000u)
#define I2C3_TIMEOUTR_TIMEOUTA_LSB   0
#define I2C3_TIMEOUTR_TIMEOUTA_WIDTH 12
#define I2C3_TIMEOUTR_TIMEOUTA_MASK  (0xFFFu)
#define I2C3_TIMEOUTR_TIDLE (1u << 12)
#define I2C3_TIMEOUTR_TIMOUTEN (1u << 15)
#define I2C3_TIMEOUTR_TIMEOUTB_LSB   16
#define I2C3_TIMEOUTR_TIMEOUTB_WIDTH 12
#define I2C3_TIMEOUTR_TIMEOUTB_MASK  (0xFFF0000u)
#define I2C3_TIMEOUTR_TEXTEN (1u << 31)
#define I2C3_ISR_ADDCODE_LSB   17
#define I2C3_ISR_ADDCODE_WIDTH 7
#define I2C3_ISR_ADDCODE_MASK  (0xFE0000u)
#define I2C3_ISR_DIR (1u << 16)
#define I2C3_ISR_BUSY (1u << 15)
#define I2C3_ISR_ALERT (1u << 13)
#define I2C3_ISR_TIMEOUT (1u << 12)
#define I2C3_ISR_PECERR (1u << 11)
#define I2C3_ISR_OVR (1u << 10)
#define I2C3_ISR_ARLO (1u << 9)
#define I2C3_ISR_BERR (1u << 8)
#define I2C3_ISR_TCR (1u << 7)
#define I2C3_ISR_TC (1u << 6)
#define I2C3_ISR_STOPF (1u << 5)
#define I2C3_ISR_NACKF (1u << 4)
#define I2C3_ISR_ADDR (1u << 3)
#define I2C3_ISR_RXNE (1u << 2)
#define I2C3_ISR_TXIS (1u << 1)
#define I2C3_ISR_TXE (1u << 0)
#define I2C3_ICR_ALERTCF (1u << 13)
#define I2C3_ICR_TIMOUTCF (1u << 12)
#define I2C3_ICR_PECCF (1u << 11)
#define I2C3_ICR_OVRCF (1u << 10)
#define I2C3_ICR_ARLOCF (1u << 9)
#define I2C3_ICR_BERRCF (1u << 8)
#define I2C3_ICR_STOPCF (1u << 5)
#define I2C3_ICR_NACKCF (1u << 4)
#define I2C3_ICR_ADDRCF (1u << 3)
#define I2C3_PECR_PEC_LSB   0
#define I2C3_PECR_PEC_WIDTH 8
#define I2C3_PECR_PEC_MASK  (0xFFu)
#define I2C3_RXDR_RXDATA_LSB   0
#define I2C3_RXDR_RXDATA_WIDTH 8
#define I2C3_RXDR_RXDATA_MASK  (0xFFu)
#define I2C3_TXDR_TXDATA_LSB   0
#define I2C3_TXDR_TXDATA_WIDTH 8
#define I2C3_TXDR_TXDATA_MASK  (0xFFu)

/* === PWR ================================= */
typedef struct {
    volatile uint32_t CR; /* 0x000 */
    volatile uint32_t CSR; /* 0x004 */
} PWR_Type;

#define PWR_BASE 0x40007000u
#define PWR ((volatile PWR_Type*)PWR_BASE)

#define PWR_CR_LPSDSR (1u << 0)
#define PWR_CR_PDDS (1u << 1)
#define PWR_CR_CWUF (1u << 2)
#define PWR_CR_CSBF (1u << 3)
#define PWR_CR_PVDE (1u << 4)
#define PWR_CR_PLS_LSB   5
#define PWR_CR_PLS_WIDTH 3
#define PWR_CR_PLS_MASK  (0xE0u)
#define PWR_CR_DBP (1u << 8)
#define PWR_CR_ULP (1u << 9)
#define PWR_CR_FWU (1u << 10)
#define PWR_CR_VOS_LSB   11
#define PWR_CR_VOS_WIDTH 2
#define PWR_CR_VOS_MASK  (0x1800u)
#define PWR_CR_DS_EE_KOFF (1u << 13)
#define PWR_CR_LPRUN (1u << 14)
#define PWR_CR_LPDS (1u << 16)
#define PWR_CSR_EWUP3 (1u << 10)
#define PWR_CSR_EWUP2 (1u << 9)
#define PWR_CSR_EWUP1 (1u << 8)
#define PWR_CSR_REGLPF (1u << 5)
#define PWR_CSR_VOSF (1u << 4)
#define PWR_CSR_VREFINTRDYF (1u << 3)
#define PWR_CSR_PVDO (1u << 2)
#define PWR_CSR_SBF (1u << 1)
#define PWR_CSR_WUF (1u << 0)

/* === Flash ================================= */
typedef struct {
    volatile uint32_t ACR; /* 0x000 */
    volatile uint32_t PECR; /* 0x004 */
    volatile uint32_t PDKEYR; /* 0x008 */
    volatile uint32_t PEKEYR; /* 0x00C */
    volatile uint32_t PRGKEYR; /* 0x010 */
    volatile uint32_t OPTKEYR; /* 0x014 */
    volatile uint32_t SR; /* 0x018 */
    volatile uint32_t OPTR; /* 0x01C */
    volatile uint32_t WRPROT1; /* 0x020 */
    uint8_t _res_0024[92];
    volatile uint32_t WRPROT2; /* 0x080 */
} Flash_Type;

#define FLASH_BASE 0x40022000u
#define FLASH ((volatile Flash_Type*)FLASH_BASE)

#define FLASH_ACR_LATENCY (1u << 0)
#define FLASH_ACR_PRFTEN (1u << 1)
#define FLASH_ACR_SLEEP_PD (1u << 3)
#define FLASH_ACR_RUN_PD (1u << 4)
#define FLASH_ACR_DISAB_BUF (1u << 5)
#define FLASH_ACR_PRE_READ (1u << 6)
#define FLASH_PECR_PELOCK (1u << 0)
#define FLASH_PECR_PRGLOCK (1u << 1)
#define FLASH_PECR_OPTLOCK (1u << 2)
#define FLASH_PECR_PROG (1u << 3)
#define FLASH_PECR_DATA (1u << 4)
#define FLASH_PECR_FIX (1u << 8)
#define FLASH_PECR_ERASE (1u << 9)
#define FLASH_PECR_FPRG (1u << 10)
#define FLASH_PECR_PARALLELBANK (1u << 15)
#define FLASH_PECR_EOPIE (1u << 16)
#define FLASH_PECR_ERRIE (1u << 17)
#define FLASH_PECR_OBL_LAUNCH (1u << 18)
#define FLASH_PECR_NZDISABLE (1u << 23)
#define FLASH_PDKEYR_PDKEYR_LSB   0
#define FLASH_PDKEYR_PDKEYR_WIDTH 32
#define FLASH_PDKEYR_PDKEYR_MASK  (0xFFFFFFFFu)
#define FLASH_PEKEYR_PEKEYR_LSB   0
#define FLASH_PEKEYR_PEKEYR_WIDTH 32
#define FLASH_PEKEYR_PEKEYR_MASK  (0xFFFFFFFFu)
#define FLASH_PRGKEYR_PRGKEYR_LSB   0
#define FLASH_PRGKEYR_PRGKEYR_WIDTH 32
#define FLASH_PRGKEYR_PRGKEYR_MASK  (0xFFFFFFFFu)
#define FLASH_OPTKEYR_OPTKEYR_LSB   0
#define FLASH_OPTKEYR_OPTKEYR_WIDTH 32
#define FLASH_OPTKEYR_OPTKEYR_MASK  (0xFFFFFFFFu)
#define FLASH_SR_BSY (1u << 0)
#define FLASH_SR_EOP (1u << 1)
#define FLASH_SR_ENDHV (1u << 2)
#define FLASH_SR_READY (1u << 3)
#define FLASH_SR_WRPERR (1u << 8)
#define FLASH_SR_PGAERR (1u << 9)
#define FLASH_SR_SIZERR (1u << 10)
#define FLASH_SR_OPTVERR (1u << 11)
#define FLASH_SR_RDERR (1u << 13)
#define FLASH_SR_NOTZEROERR (1u << 16)
#define FLASH_SR_FWWERR (1u << 17)
#define FLASH_OPTR_RDPROT_LSB   0
#define FLASH_OPTR_RDPROT_WIDTH 8
#define FLASH_OPTR_RDPROT_MASK  (0xFFu)
#define FLASH_OPTR_WPRMOD (1u << 8)
#define FLASH_OPTR_BOR_LEV_LSB   16
#define FLASH_OPTR_BOR_LEV_WIDTH 4
#define FLASH_OPTR_BOR_LEV_MASK  (0xF0000u)
#define FLASH_OPTR_WDG_SW (1u << 20)
#define FLASH_OPTR_NRST_STOP (1u << 21)
#define FLASH_OPTR_NRST_STDBY (1u << 22)
#define FLASH_OPTR_BFB2 (1u << 23)
#define FLASH_OPTR_NBOOT1 (1u << 31)
#define FLASH_WRPROT1_WRPROT1_LSB   0
#define FLASH_WRPROT1_WRPROT1_WIDTH 32
#define FLASH_WRPROT1_WRPROT1_MASK  (0xFFFFFFFFu)
#define FLASH_WRPROT2_WRPROT2_LSB   0
#define FLASH_WRPROT2_WRPROT2_WIDTH 16
#define FLASH_WRPROT2_WRPROT2_MASK  (0xFFFFu)

/* === EXTI ================================= */
typedef struct {
    volatile uint32_t IMR; /* 0x000 */
    volatile uint32_t EMR; /* 0x004 */
    volatile uint32_t RTSR; /* 0x008 */
    volatile uint32_t FTSR; /* 0x00C */
    volatile uint32_t SWIER; /* 0x010 */
    volatile uint32_t PR; /* 0x014 */
} EXTI_Type;

#define EXTI_BASE 0x40010400u
#define EXTI ((volatile EXTI_Type*)EXTI_BASE)

#define EXTI_IMR_IM0 (1u << 0)
#define EXTI_IMR_IM1 (1u << 1)
#define EXTI_IMR_IM2 (1u << 2)
#define EXTI_IMR_IM3 (1u << 3)
#define EXTI_IMR_IM4 (1u << 4)
#define EXTI_IMR_IM5 (1u << 5)
#define EXTI_IMR_IM6 (1u << 6)
#define EXTI_IMR_IM7 (1u << 7)
#define EXTI_IMR_IM8 (1u << 8)
#define EXTI_IMR_IM9 (1u << 9)
#define EXTI_IMR_IM10 (1u << 10)
#define EXTI_IMR_IM11 (1u << 11)
#define EXTI_IMR_IM12 (1u << 12)
#define EXTI_IMR_IM13 (1u << 13)
#define EXTI_IMR_IM14 (1u << 14)
#define EXTI_IMR_IM15 (1u << 15)
#define EXTI_IMR_IM16 (1u << 16)
#define EXTI_IMR_IM17 (1u << 17)
#define EXTI_IMR_IM18 (1u << 18)
#define EXTI_IMR_IM19 (1u << 19)
#define EXTI_IMR_IM20 (1u << 20)
#define EXTI_IMR_IM21 (1u << 21)
#define EXTI_IMR_IM22 (1u << 22)
#define EXTI_IMR_IM23 (1u << 23)
#define EXTI_IMR_IM24 (1u << 24)
#define EXTI_IMR_IM25 (1u << 25)
#define EXTI_IMR_IM26 (1u << 26)
#define EXTI_IMR_IM28 (1u << 28)
#define EXTI_IMR_IM29 (1u << 29)
#define EXTI_EMR_EM0 (1u << 0)
#define EXTI_EMR_EM1 (1u << 1)
#define EXTI_EMR_EM2 (1u << 2)
#define EXTI_EMR_EM3 (1u << 3)
#define EXTI_EMR_EM4 (1u << 4)
#define EXTI_EMR_EM5 (1u << 5)
#define EXTI_EMR_EM6 (1u << 6)
#define EXTI_EMR_EM7 (1u << 7)
#define EXTI_EMR_EM8 (1u << 8)
#define EXTI_EMR_EM9 (1u << 9)
#define EXTI_EMR_EM10 (1u << 10)
#define EXTI_EMR_EM11 (1u << 11)
#define EXTI_EMR_EM12 (1u << 12)
#define EXTI_EMR_EM13 (1u << 13)
#define EXTI_EMR_EM14 (1u << 14)
#define EXTI_EMR_EM15 (1u << 15)
#define EXTI_EMR_EM16 (1u << 16)
#define EXTI_EMR_EM17 (1u << 17)
#define EXTI_EMR_EM18 (1u << 18)
#define EXTI_EMR_EM19 (1u << 19)
#define EXTI_EMR_EM20 (1u << 20)
#define EXTI_EMR_EM21 (1u << 21)
#define EXTI_EMR_EM22 (1u << 22)
#define EXTI_EMR_EM23 (1u << 23)
#define EXTI_EMR_EM24 (1u << 24)
#define EXTI_EMR_EM25 (1u << 25)
#define EXTI_EMR_EM26 (1u << 26)
#define EXTI_EMR_EM28 (1u << 28)
#define EXTI_EMR_EM29 (1u << 29)
#define EXTI_RTSR_RT0 (1u << 0)
#define EXTI_RTSR_RT1 (1u << 1)
#define EXTI_RTSR_RT2 (1u << 2)
#define EXTI_RTSR_RT3 (1u << 3)
#define EXTI_RTSR_RT4 (1u << 4)
#define EXTI_RTSR_RT5 (1u << 5)
#define EXTI_RTSR_RT6 (1u << 6)
#define EXTI_RTSR_RT7 (1u << 7)
#define EXTI_RTSR_RT8 (1u << 8)
#define EXTI_RTSR_RT9 (1u << 9)
#define EXTI_RTSR_RT10 (1u << 10)
#define EXTI_RTSR_RT11 (1u << 11)
#define EXTI_RTSR_RT12 (1u << 12)
#define EXTI_RTSR_RT13 (1u << 13)
#define EXTI_RTSR_RT14 (1u << 14)
#define EXTI_RTSR_RT15 (1u << 15)
#define EXTI_RTSR_RT16 (1u << 16)
#define EXTI_RTSR_RT17 (1u << 17)
#define EXTI_RTSR_RT19 (1u << 19)
#define EXTI_RTSR_RT20 (1u << 20)
#define EXTI_RTSR_RT21 (1u << 21)
#define EXTI_RTSR_RT22 (1u << 22)
#define EXTI_FTSR_FT0 (1u << 0)
#define EXTI_FTSR_FT1 (1u << 1)
#define EXTI_FTSR_FT2 (1u << 2)
#define EXTI_FTSR_FT3 (1u << 3)
#define EXTI_FTSR_FT4 (1u << 4)
#define EXTI_FTSR_FT5 (1u << 5)
#define EXTI_FTSR_FT6 (1u << 6)
#define EXTI_FTSR_FT7 (1u << 7)
#define EXTI_FTSR_FT8 (1u << 8)
#define EXTI_FTSR_FT9 (1u << 9)
#define EXTI_FTSR_FT10 (1u << 10)
#define EXTI_FTSR_FT11 (1u << 11)
#define EXTI_FTSR_FT12 (1u << 12)
#define EXTI_FTSR_FT13 (1u << 13)
#define EXTI_FTSR_FT14 (1u << 14)
#define EXTI_FTSR_FT15 (1u << 15)
#define EXTI_FTSR_FT16 (1u << 16)
#define EXTI_FTSR_FT17 (1u << 17)
#define EXTI_FTSR_FT19 (1u << 19)
#define EXTI_FTSR_FT20 (1u << 20)
#define EXTI_FTSR_FT21 (1u << 21)
#define EXTI_FTSR_FT22 (1u << 22)
#define EXTI_SWIER_SWI0 (1u << 0)
#define EXTI_SWIER_SWI1 (1u << 1)
#define EXTI_SWIER_SWI2 (1u << 2)
#define EXTI_SWIER_SWI3 (1u << 3)
#define EXTI_SWIER_SWI4 (1u << 4)
#define EXTI_SWIER_SWI5 (1u << 5)
#define EXTI_SWIER_SWI6 (1u << 6)
#define EXTI_SWIER_SWI7 (1u << 7)
#define EXTI_SWIER_SWI8 (1u << 8)
#define EXTI_SWIER_SWI9 (1u << 9)
#define EXTI_SWIER_SWI10 (1u << 10)
#define EXTI_SWIER_SWI11 (1u << 11)
#define EXTI_SWIER_SWI12 (1u << 12)
#define EXTI_SWIER_SWI13 (1u << 13)
#define EXTI_SWIER_SWI14 (1u << 14)
#define EXTI_SWIER_SWI15 (1u << 15)
#define EXTI_SWIER_SWI16 (1u << 16)
#define EXTI_SWIER_SWI17 (1u << 17)
#define EXTI_SWIER_SWI19 (1u << 19)
#define EXTI_SWIER_SWI20 (1u << 20)
#define EXTI_SWIER_SWI21 (1u << 21)
#define EXTI_SWIER_SWI22 (1u << 22)
#define EXTI_PR_PIF0 (1u << 0)
#define EXTI_PR_PIF1 (1u << 1)
#define EXTI_PR_PIF2 (1u << 2)
#define EXTI_PR_PIF3 (1u << 3)
#define EXTI_PR_PIF4 (1u << 4)
#define EXTI_PR_PIF5 (1u << 5)
#define EXTI_PR_PIF6 (1u << 6)
#define EXTI_PR_PIF7 (1u << 7)
#define EXTI_PR_PIF8 (1u << 8)
#define EXTI_PR_PIF9 (1u << 9)
#define EXTI_PR_PIF10 (1u << 10)
#define EXTI_PR_PIF11 (1u << 11)
#define EXTI_PR_PIF12 (1u << 12)
#define EXTI_PR_PIF13 (1u << 13)
#define EXTI_PR_PIF14 (1u << 14)
#define EXTI_PR_PIF15 (1u << 15)
#define EXTI_PR_PIF16 (1u << 16)
#define EXTI_PR_PIF17 (1u << 17)
#define EXTI_PR_PIF19 (1u << 19)
#define EXTI_PR_PIF20 (1u << 20)
#define EXTI_PR_PIF21 (1u << 21)
#define EXTI_PR_PIF22 (1u << 22)

/* === ADC ================================= */
typedef struct {
    volatile uint32_t ISR; /* 0x000 */
    volatile uint32_t IER; /* 0x004 */
    volatile uint32_t CR; /* 0x008 */
    volatile uint32_t CFGR1; /* 0x00C */
    volatile uint32_t CFGR2; /* 0x010 */
    volatile uint32_t SMPR; /* 0x014 */
    uint8_t _res_0018[8];
    volatile uint32_t TR; /* 0x020 */
    uint8_t _res_0024[4];
    volatile uint32_t CHSELR; /* 0x028 */
    uint8_t _res_002C[20];
    volatile uint32_t DR; /* 0x040 */
    uint8_t _res_0044[112];
    volatile uint32_t CALFACT; /* 0x0B4 */
    uint8_t _res_00B8[592];
    volatile uint32_t CCR; /* 0x308 */
} ADC_Type;

#define ADC_BASE 0x40012400u
#define ADC ((volatile ADC_Type*)ADC_BASE)

#define ADC_ISR_ADRDY (1u << 0)
#define ADC_ISR_EOSMP (1u << 1)
#define ADC_ISR_EOC (1u << 2)
#define ADC_ISR_EOS (1u << 3)
#define ADC_ISR_OVR (1u << 4)
#define ADC_ISR_AWD (1u << 7)
#define ADC_ISR_EOCAL (1u << 11)
#define ADC_IER_ADRDYIE (1u << 0)
#define ADC_IER_EOSMPIE (1u << 1)
#define ADC_IER_EOCIE (1u << 2)
#define ADC_IER_EOSIE (1u << 3)
#define ADC_IER_OVRIE (1u << 4)
#define ADC_IER_AWDIE (1u << 7)
#define ADC_IER_EOCALIE (1u << 11)
#define ADC_CR_ADEN (1u << 0)
#define ADC_CR_ADDIS (1u << 1)
#define ADC_CR_ADSTART (1u << 2)
#define ADC_CR_ADSTP (1u << 4)
#define ADC_CR_ADVREGEN (1u << 28)
#define ADC_CR_ADCAL (1u << 31)
#define ADC_CFGR1_AWDCH_LSB   26
#define ADC_CFGR1_AWDCH_WIDTH 5
#define ADC_CFGR1_AWDCH_MASK  (0x7C000000u)
#define ADC_CFGR1_AWDEN (1u << 23)
#define ADC_CFGR1_AWDSGL (1u << 22)
#define ADC_CFGR1_DISCEN (1u << 16)
#define ADC_CFGR1_AUTOFF (1u << 15)
#define ADC_CFGR1_AUTDLY (1u << 14)
#define ADC_CFGR1_CONT (1u << 13)
#define ADC_CFGR1_OVRMOD (1u << 12)
#define ADC_CFGR1_EXTEN_LSB   10
#define ADC_CFGR1_EXTEN_WIDTH 2
#define ADC_CFGR1_EXTEN_MASK  (0xC00u)
#define ADC_CFGR1_EXTSEL_LSB   6
#define ADC_CFGR1_EXTSEL_WIDTH 3
#define ADC_CFGR1_EXTSEL_MASK  (0x1C0u)
#define ADC_CFGR1_ALIGN (1u << 5)
#define ADC_CFGR1_RES_LSB   3
#define ADC_CFGR1_RES_WIDTH 2
#define ADC_CFGR1_RES_MASK  (0x18u)
#define ADC_CFGR1_SCANDIR (1u << 2)
#define ADC_CFGR1_DMACFG (1u << 1)
#define ADC_CFGR1_DMAEN (1u << 0)
#define ADC_CFGR2_OVSE (1u << 0)
#define ADC_CFGR2_OVSR_LSB   2
#define ADC_CFGR2_OVSR_WIDTH 3
#define ADC_CFGR2_OVSR_MASK  (0x1Cu)
#define ADC_CFGR2_OVSS_LSB   5
#define ADC_CFGR2_OVSS_WIDTH 4
#define ADC_CFGR2_OVSS_MASK  (0x1E0u)
#define ADC_CFGR2_TOVS (1u << 9)
#define ADC_CFGR2_CKMODE_LSB   30
#define ADC_CFGR2_CKMODE_WIDTH 2
#define ADC_CFGR2_CKMODE_MASK  (0xC0000000u)
#define ADC_SMPR_SMPR_LSB   0
#define ADC_SMPR_SMPR_WIDTH 3
#define ADC_SMPR_SMPR_MASK  (0x7u)
#define ADC_TR_HT_LSB   16
#define ADC_TR_HT_WIDTH 12
#define ADC_TR_HT_MASK  (0xFFF0000u)
#define ADC_TR_LT_LSB   0
#define ADC_TR_LT_WIDTH 12
#define ADC_TR_LT_MASK  (0xFFFu)
#define ADC_CHSELR_CHSEL18 (1u << 18)
#define ADC_CHSELR_CHSEL17 (1u << 17)
#define ADC_CHSELR_CHSEL16 (1u << 16)
#define ADC_CHSELR_CHSEL15 (1u << 15)
#define ADC_CHSELR_CHSEL14 (1u << 14)
#define ADC_CHSELR_CHSEL13 (1u << 13)
#define ADC_CHSELR_CHSEL12 (1u << 12)
#define ADC_CHSELR_CHSEL11 (1u << 11)
#define ADC_CHSELR_CHSEL10 (1u << 10)
#define ADC_CHSELR_CHSEL9 (1u << 9)
#define ADC_CHSELR_CHSEL8 (1u << 8)
#define ADC_CHSELR_CHSEL7 (1u << 7)
#define ADC_CHSELR_CHSEL6 (1u << 6)
#define ADC_CHSELR_CHSEL5 (1u << 5)
#define ADC_CHSELR_CHSEL4 (1u << 4)
#define ADC_CHSELR_CHSEL3 (1u << 3)
#define ADC_CHSELR_CHSEL2 (1u << 2)
#define ADC_CHSELR_CHSEL1 (1u << 1)
#define ADC_CHSELR_CHSEL0 (1u << 0)
#define ADC_DR_DATA_LSB   0
#define ADC_DR_DATA_WIDTH 16
#define ADC_DR_DATA_MASK  (0xFFFFu)
#define ADC_CALFACT_CALFACT_LSB   0
#define ADC_CALFACT_CALFACT_WIDTH 7
#define ADC_CALFACT_CALFACT_MASK  (0x7Fu)
#define ADC_CCR_PRESC_LSB   18
#define ADC_CCR_PRESC_WIDTH 4
#define ADC_CCR_PRESC_MASK  (0x3C0000u)
#define ADC_CCR_VREFEN (1u << 22)
#define ADC_CCR_TSEN (1u << 23)
#define ADC_CCR_VLCDEN (1u << 24)
#define ADC_CCR_LFMEN (1u << 25)

/* === DBG ================================= */
typedef struct {
    volatile uint32_t IDCODE; /* 0x000 */
    volatile uint32_t CR; /* 0x004 */
    volatile uint32_t APB1_FZ; /* 0x008 */
    volatile uint32_t APB2_FZ; /* 0x00C */
} DBG_Type;

#define DBG_BASE 0x40015800u
#define DBG ((volatile DBG_Type*)DBG_BASE)

#define DBG_IDCODE_DEV_ID_LSB   0
#define DBG_IDCODE_DEV_ID_WIDTH 12
#define DBG_IDCODE_DEV_ID_MASK  (0xFFFu)
#define DBG_IDCODE_REV_ID_LSB   16
#define DBG_IDCODE_REV_ID_WIDTH 16
#define DBG_IDCODE_REV_ID_MASK  (0xFFFF0000u)
#define DBG_CR_DBG_STOP (1u << 1)
#define DBG_CR_DBG_STANDBY (1u << 2)
#define DBG_CR_DBG_SLEEP (1u << 0)
#define DBG_APB1_FZ_DBG_TIMER2_STOP (1u << 0)
#define DBG_APB1_FZ_DBG_TIMER6_STOP (1u << 4)
#define DBG_APB1_FZ_DBG_RTC_STOP (1u << 10)
#define DBG_APB1_FZ_DBG_WWDG_STOP (1u << 11)
#define DBG_APB1_FZ_DBG_IWDG_STOP (1u << 12)
#define DBG_APB1_FZ_DBG_I2C1_STOP (1u << 21)
#define DBG_APB1_FZ_DBG_I2C2_STOP (1u << 22)
#define DBG_APB1_FZ_DBG_LPTIMER_STOP (1u << 31)
#define DBG_APB2_FZ_DBG_TIMER21_STOP (1u << 2)
#define DBG_APB2_FZ_DBG_TIMER22_STO (1u << 6)

/* === TIM2 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SMCR; /* 0x008 */
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    union {
    volatile uint32_t CCMR1_Output; /* 0x018 */
    volatile uint32_t CCMR1_Input; /* 0x018 */
    };
    union {
    volatile uint32_t CCMR2_Output; /* 0x01C */
    volatile uint32_t CCMR2_Input; /* 0x01C */
    };
    volatile uint32_t CCER; /* 0x020 */
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
    uint8_t _res_0030[4];
    volatile uint32_t CCR1; /* 0x034 */
    volatile uint32_t CCR2; /* 0x038 */
    volatile uint32_t CCR3; /* 0x03C */
    volatile uint32_t CCR4; /* 0x040 */
    uint8_t _res_0044[4];
    volatile uint32_t DCR; /* 0x048 */
    volatile uint32_t DMAR; /* 0x04C */
    volatile uint32_t OR; /* 0x050 */
} TIM2_Type;

#define TIM2_BASE 0x40000000u
#define TIM2 ((volatile TIM2_Type*)TIM2_BASE)

#define TIM2_CR1_CKD_LSB   8
#define TIM2_CR1_CKD_WIDTH 2
#define TIM2_CR1_CKD_MASK  (0x300u)
#define TIM2_CR1_ARPE (1u << 7)
#define TIM2_CR1_CMS_LSB   5
#define TIM2_CR1_CMS_WIDTH 2
#define TIM2_CR1_CMS_MASK  (0x60u)
#define TIM2_CR1_DIR (1u << 4)
#define TIM2_CR1_OPM (1u << 3)
#define TIM2_CR1_URS (1u << 2)
#define TIM2_CR1_UDIS (1u << 1)
#define TIM2_CR1_CEN (1u << 0)
#define TIM2_CR2_TI1S (1u << 7)
#define TIM2_CR2_MMS_LSB   4
#define TIM2_CR2_MMS_WIDTH 3
#define TIM2_CR2_MMS_MASK  (0x70u)
#define TIM2_CR2_CCDS (1u << 3)
#define TIM2_SMCR_ETP (1u << 15)
#define TIM2_SMCR_ECE (1u << 14)
#define TIM2_SMCR_ETPS_LSB   12
#define TIM2_SMCR_ETPS_WIDTH 2
#define TIM2_SMCR_ETPS_MASK  (0x3000u)
#define TIM2_SMCR_ETF_LSB   8
#define TIM2_SMCR_ETF_WIDTH 4
#define TIM2_SMCR_ETF_MASK  (0xF00u)
#define TIM2_SMCR_MSM (1u << 7)
#define TIM2_SMCR_TS_LSB   4
#define TIM2_SMCR_TS_WIDTH 3
#define TIM2_SMCR_TS_MASK  (0x70u)
#define TIM2_SMCR_SMS_LSB   0
#define TIM2_SMCR_SMS_WIDTH 3
#define TIM2_SMCR_SMS_MASK  (0x7u)
#define TIM2_DIER_TDE (1u << 14)
#define TIM2_DIER_CC4DE (1u << 12)
#define TIM2_DIER_CC3DE (1u << 11)
#define TIM2_DIER_CC2DE (1u << 10)
#define TIM2_DIER_CC1DE (1u << 9)
#define TIM2_DIER_UDE (1u << 8)
#define TIM2_DIER_TIE (1u << 6)
#define TIM2_DIER_CC4IE (1u << 4)
#define TIM2_DIER_CC3IE (1u << 3)
#define TIM2_DIER_CC2IE (1u << 2)
#define TIM2_DIER_CC1IE (1u << 1)
#define TIM2_DIER_UIE (1u << 0)
#define TIM2_SR_CC4OF (1u << 12)
#define TIM2_SR_CC3OF (1u << 11)
#define TIM2_SR_CC2OF (1u << 10)
#define TIM2_SR_CC1OF (1u << 9)
#define TIM2_SR_TIF (1u << 6)
#define TIM2_SR_CC4IF (1u << 4)
#define TIM2_SR_CC3IF (1u << 3)
#define TIM2_SR_CC2IF (1u << 2)
#define TIM2_SR_CC1IF (1u << 1)
#define TIM2_SR_UIF (1u << 0)
#define TIM2_EGR_TG (1u << 6)
#define TIM2_EGR_CC4G (1u << 4)
#define TIM2_EGR_CC3G (1u << 3)
#define TIM2_EGR_CC2G (1u << 2)
#define TIM2_EGR_CC1G (1u << 1)
#define TIM2_EGR_UG (1u << 0)
#define TIM2_CCMR1_OUTPUT_OC2CE (1u << 15)
#define TIM2_CCMR1_OUTPUT_OC2M_LSB   12
#define TIM2_CCMR1_OUTPUT_OC2M_WIDTH 3
#define TIM2_CCMR1_OUTPUT_OC2M_MASK  (0x7000u)
#define TIM2_CCMR1_OUTPUT_OC2PE (1u << 11)
#define TIM2_CCMR1_OUTPUT_OC2FE (1u << 10)
#define TIM2_CCMR1_OUTPUT_CC2S_LSB   8
#define TIM2_CCMR1_OUTPUT_CC2S_WIDTH 2
#define TIM2_CCMR1_OUTPUT_CC2S_MASK  (0x300u)
#define TIM2_CCMR1_OUTPUT_OC1CE (1u << 7)
#define TIM2_CCMR1_OUTPUT_OC1M_LSB   4
#define TIM2_CCMR1_OUTPUT_OC1M_WIDTH 3
#define TIM2_CCMR1_OUTPUT_OC1M_MASK  (0x70u)
#define TIM2_CCMR1_OUTPUT_OC1PE (1u << 3)
#define TIM2_CCMR1_OUTPUT_OC1FE (1u << 2)
#define TIM2_CCMR1_OUTPUT_CC1S_LSB   0
#define TIM2_CCMR1_OUTPUT_CC1S_WIDTH 2
#define TIM2_CCMR1_OUTPUT_CC1S_MASK  (0x3u)
#define TIM2_CCMR1_INPUT_IC2F_LSB   12
#define TIM2_CCMR1_INPUT_IC2F_WIDTH 4
#define TIM2_CCMR1_INPUT_IC2F_MASK  (0xF000u)
#define TIM2_CCMR1_INPUT_IC2PSC_LSB   10
#define TIM2_CCMR1_INPUT_IC2PSC_WIDTH 2
#define TIM2_CCMR1_INPUT_IC2PSC_MASK  (0xC00u)
#define TIM2_CCMR1_INPUT_CC2S_LSB   8
#define TIM2_CCMR1_INPUT_CC2S_WIDTH 2
#define TIM2_CCMR1_INPUT_CC2S_MASK  (0x300u)
#define TIM2_CCMR1_INPUT_IC1F_LSB   4
#define TIM2_CCMR1_INPUT_IC1F_WIDTH 4
#define TIM2_CCMR1_INPUT_IC1F_MASK  (0xF0u)
#define TIM2_CCMR1_INPUT_IC1PSC_LSB   2
#define TIM2_CCMR1_INPUT_IC1PSC_WIDTH 2
#define TIM2_CCMR1_INPUT_IC1PSC_MASK  (0xCu)
#define TIM2_CCMR1_INPUT_CC1S_LSB   0
#define TIM2_CCMR1_INPUT_CC1S_WIDTH 2
#define TIM2_CCMR1_INPUT_CC1S_MASK  (0x3u)
#define TIM2_CCMR2_OUTPUT_OC4CE (1u << 15)
#define TIM2_CCMR2_OUTPUT_OC4M_LSB   12
#define TIM2_CCMR2_OUTPUT_OC4M_WIDTH 3
#define TIM2_CCMR2_OUTPUT_OC4M_MASK  (0x7000u)
#define TIM2_CCMR2_OUTPUT_OC4PE (1u << 11)
#define TIM2_CCMR2_OUTPUT_OC4FE (1u << 10)
#define TIM2_CCMR2_OUTPUT_CC4S_LSB   8
#define TIM2_CCMR2_OUTPUT_CC4S_WIDTH 2
#define TIM2_CCMR2_OUTPUT_CC4S_MASK  (0x300u)
#define TIM2_CCMR2_OUTPUT_OC3CE (1u << 7)
#define TIM2_CCMR2_OUTPUT_OC3M_LSB   4
#define TIM2_CCMR2_OUTPUT_OC3M_WIDTH 3
#define TIM2_CCMR2_OUTPUT_OC3M_MASK  (0x70u)
#define TIM2_CCMR2_OUTPUT_OC3PE (1u << 3)
#define TIM2_CCMR2_OUTPUT_OC3FE (1u << 2)
#define TIM2_CCMR2_OUTPUT_CC3S_LSB   0
#define TIM2_CCMR2_OUTPUT_CC3S_WIDTH 2
#define TIM2_CCMR2_OUTPUT_CC3S_MASK  (0x3u)
#define TIM2_CCMR2_INPUT_IC4F_LSB   12
#define TIM2_CCMR2_INPUT_IC4F_WIDTH 4
#define TIM2_CCMR2_INPUT_IC4F_MASK  (0xF000u)
#define TIM2_CCMR2_INPUT_IC4PSC_LSB   10
#define TIM2_CCMR2_INPUT_IC4PSC_WIDTH 2
#define TIM2_CCMR2_INPUT_IC4PSC_MASK  (0xC00u)
#define TIM2_CCMR2_INPUT_CC4S_LSB   8
#define TIM2_CCMR2_INPUT_CC4S_WIDTH 2
#define TIM2_CCMR2_INPUT_CC4S_MASK  (0x300u)
#define TIM2_CCMR2_INPUT_IC3F_LSB   4
#define TIM2_CCMR2_INPUT_IC3F_WIDTH 4
#define TIM2_CCMR2_INPUT_IC3F_MASK  (0xF0u)
#define TIM2_CCMR2_INPUT_IC3PSC_LSB   2
#define TIM2_CCMR2_INPUT_IC3PSC_WIDTH 2
#define TIM2_CCMR2_INPUT_IC3PSC_MASK  (0xCu)
#define TIM2_CCMR2_INPUT_CC3S_LSB   0
#define TIM2_CCMR2_INPUT_CC3S_WIDTH 2
#define TIM2_CCMR2_INPUT_CC3S_MASK  (0x3u)
#define TIM2_CCER_CC4NP (1u << 15)
#define TIM2_CCER_CC4P (1u << 13)
#define TIM2_CCER_CC4E (1u << 12)
#define TIM2_CCER_CC3NP (1u << 11)
#define TIM2_CCER_CC3P (1u << 9)
#define TIM2_CCER_CC3E (1u << 8)
#define TIM2_CCER_CC2NP (1u << 7)
#define TIM2_CCER_CC2P (1u << 5)
#define TIM2_CCER_CC2E (1u << 4)
#define TIM2_CCER_CC1NP (1u << 3)
#define TIM2_CCER_CC1P (1u << 1)
#define TIM2_CCER_CC1E (1u << 0)
#define TIM2_CNT_CNT_H_LSB   16
#define TIM2_CNT_CNT_H_WIDTH 16
#define TIM2_CNT_CNT_H_MASK  (0xFFFF0000u)
#define TIM2_CNT_CNT_L_LSB   0
#define TIM2_CNT_CNT_L_WIDTH 16
#define TIM2_CNT_CNT_L_MASK  (0xFFFFu)
#define TIM2_PSC_PSC_LSB   0
#define TIM2_PSC_PSC_WIDTH 16
#define TIM2_PSC_PSC_MASK  (0xFFFFu)
#define TIM2_ARR_ARR_H_LSB   16
#define TIM2_ARR_ARR_H_WIDTH 16
#define TIM2_ARR_ARR_H_MASK  (0xFFFF0000u)
#define TIM2_ARR_ARR_L_LSB   0
#define TIM2_ARR_ARR_L_WIDTH 16
#define TIM2_ARR_ARR_L_MASK  (0xFFFFu)
#define TIM2_CCR1_CCR1_H_LSB   16
#define TIM2_CCR1_CCR1_H_WIDTH 16
#define TIM2_CCR1_CCR1_H_MASK  (0xFFFF0000u)
#define TIM2_CCR1_CCR1_L_LSB   0
#define TIM2_CCR1_CCR1_L_WIDTH 16
#define TIM2_CCR1_CCR1_L_MASK  (0xFFFFu)
#define TIM2_CCR2_CCR2_H_LSB   16
#define TIM2_CCR2_CCR2_H_WIDTH 16
#define TIM2_CCR2_CCR2_H_MASK  (0xFFFF0000u)
#define TIM2_CCR2_CCR2_L_LSB   0
#define TIM2_CCR2_CCR2_L_WIDTH 16
#define TIM2_CCR2_CCR2_L_MASK  (0xFFFFu)
#define TIM2_CCR3_CCR3_H_LSB   16
#define TIM2_CCR3_CCR3_H_WIDTH 16
#define TIM2_CCR3_CCR3_H_MASK  (0xFFFF0000u)
#define TIM2_CCR3_CCR3_L_LSB   0
#define TIM2_CCR3_CCR3_L_WIDTH 16
#define TIM2_CCR3_CCR3_L_MASK  (0xFFFFu)
#define TIM2_CCR4_CCR4_H_LSB   16
#define TIM2_CCR4_CCR4_H_WIDTH 16
#define TIM2_CCR4_CCR4_H_MASK  (0xFFFF0000u)
#define TIM2_CCR4_CCR4_L_LSB   0
#define TIM2_CCR4_CCR4_L_WIDTH 16
#define TIM2_CCR4_CCR4_L_MASK  (0xFFFFu)
#define TIM2_DCR_DBL_LSB   8
#define TIM2_DCR_DBL_WIDTH 5
#define TIM2_DCR_DBL_MASK  (0x1F00u)
#define TIM2_DCR_DBA_LSB   0
#define TIM2_DCR_DBA_WIDTH 5
#define TIM2_DCR_DBA_MASK  (0x1Fu)
#define TIM2_DMAR_DMAB_LSB   0
#define TIM2_DMAR_DMAB_WIDTH 16
#define TIM2_DMAR_DMAB_MASK  (0xFFFFu)
#define TIM2_OR_ETR_RMP_LSB   0
#define TIM2_OR_ETR_RMP_WIDTH 3
#define TIM2_OR_ETR_RMP_MASK  (0x7u)
#define TIM2_OR_TI4_RMP_LSB   3
#define TIM2_OR_TI4_RMP_WIDTH 2
#define TIM2_OR_TI4_RMP_MASK  (0x18u)

/* === TIM3 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SMCR; /* 0x008 */
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    union {
    volatile uint32_t CCMR1_Output; /* 0x018 */
    volatile uint32_t CCMR1_Input; /* 0x018 */
    };
    union {
    volatile uint32_t CCMR2_Output; /* 0x01C */
    volatile uint32_t CCMR2_Input; /* 0x01C */
    };
    volatile uint32_t CCER; /* 0x020 */
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
    uint8_t _res_0030[4];
    volatile uint32_t CCR1; /* 0x034 */
    volatile uint32_t CCR2; /* 0x038 */
    volatile uint32_t CCR3; /* 0x03C */
    volatile uint32_t CCR4; /* 0x040 */
    uint8_t _res_0044[4];
    volatile uint32_t DCR; /* 0x048 */
    volatile uint32_t DMAR; /* 0x04C */
    volatile uint32_t OR; /* 0x050 */
} TIM3_Type;

#define TIM3_BASE 0x40000400u
#define TIM3 ((volatile TIM3_Type*)TIM3_BASE)

#define TIM3_CR1_CKD_LSB   8
#define TIM3_CR1_CKD_WIDTH 2
#define TIM3_CR1_CKD_MASK  (0x300u)
#define TIM3_CR1_ARPE (1u << 7)
#define TIM3_CR1_CMS_LSB   5
#define TIM3_CR1_CMS_WIDTH 2
#define TIM3_CR1_CMS_MASK  (0x60u)
#define TIM3_CR1_DIR (1u << 4)
#define TIM3_CR1_OPM (1u << 3)
#define TIM3_CR1_URS (1u << 2)
#define TIM3_CR1_UDIS (1u << 1)
#define TIM3_CR1_CEN (1u << 0)
#define TIM3_CR2_TI1S (1u << 7)
#define TIM3_CR2_MMS_LSB   4
#define TIM3_CR2_MMS_WIDTH 3
#define TIM3_CR2_MMS_MASK  (0x70u)
#define TIM3_CR2_CCDS (1u << 3)
#define TIM3_SMCR_ETP (1u << 15)
#define TIM3_SMCR_ECE (1u << 14)
#define TIM3_SMCR_ETPS_LSB   12
#define TIM3_SMCR_ETPS_WIDTH 2
#define TIM3_SMCR_ETPS_MASK  (0x3000u)
#define TIM3_SMCR_ETF_LSB   8
#define TIM3_SMCR_ETF_WIDTH 4
#define TIM3_SMCR_ETF_MASK  (0xF00u)
#define TIM3_SMCR_MSM (1u << 7)
#define TIM3_SMCR_TS_LSB   4
#define TIM3_SMCR_TS_WIDTH 3
#define TIM3_SMCR_TS_MASK  (0x70u)
#define TIM3_SMCR_SMS_LSB   0
#define TIM3_SMCR_SMS_WIDTH 3
#define TIM3_SMCR_SMS_MASK  (0x7u)
#define TIM3_DIER_TDE (1u << 14)
#define TIM3_DIER_CC4DE (1u << 12)
#define TIM3_DIER_CC3DE (1u << 11)
#define TIM3_DIER_CC2DE (1u << 10)
#define TIM3_DIER_CC1DE (1u << 9)
#define TIM3_DIER_UDE (1u << 8)
#define TIM3_DIER_TIE (1u << 6)
#define TIM3_DIER_CC4IE (1u << 4)
#define TIM3_DIER_CC3IE (1u << 3)
#define TIM3_DIER_CC2IE (1u << 2)
#define TIM3_DIER_CC1IE (1u << 1)
#define TIM3_DIER_UIE (1u << 0)
#define TIM3_SR_CC4OF (1u << 12)
#define TIM3_SR_CC3OF (1u << 11)
#define TIM3_SR_CC2OF (1u << 10)
#define TIM3_SR_CC1OF (1u << 9)
#define TIM3_SR_TIF (1u << 6)
#define TIM3_SR_CC4IF (1u << 4)
#define TIM3_SR_CC3IF (1u << 3)
#define TIM3_SR_CC2IF (1u << 2)
#define TIM3_SR_CC1IF (1u << 1)
#define TIM3_SR_UIF (1u << 0)
#define TIM3_EGR_TG (1u << 6)
#define TIM3_EGR_CC4G (1u << 4)
#define TIM3_EGR_CC3G (1u << 3)
#define TIM3_EGR_CC2G (1u << 2)
#define TIM3_EGR_CC1G (1u << 1)
#define TIM3_EGR_UG (1u << 0)
#define TIM3_CCMR1_OUTPUT_OC2CE (1u << 15)
#define TIM3_CCMR1_OUTPUT_OC2M_LSB   12
#define TIM3_CCMR1_OUTPUT_OC2M_WIDTH 3
#define TIM3_CCMR1_OUTPUT_OC2M_MASK  (0x7000u)
#define TIM3_CCMR1_OUTPUT_OC2PE (1u << 11)
#define TIM3_CCMR1_OUTPUT_OC2FE (1u << 10)
#define TIM3_CCMR1_OUTPUT_CC2S_LSB   8
#define TIM3_CCMR1_OUTPUT_CC2S_WIDTH 2
#define TIM3_CCMR1_OUTPUT_CC2S_MASK  (0x300u)
#define TIM3_CCMR1_OUTPUT_OC1CE (1u << 7)
#define TIM3_CCMR1_OUTPUT_OC1M_LSB   4
#define TIM3_CCMR1_OUTPUT_OC1M_WIDTH 3
#define TIM3_CCMR1_OUTPUT_OC1M_MASK  (0x70u)
#define TIM3_CCMR1_OUTPUT_OC1PE (1u << 3)
#define TIM3_CCMR1_OUTPUT_OC1FE (1u << 2)
#define TIM3_CCMR1_OUTPUT_CC1S_LSB   0
#define TIM3_CCMR1_OUTPUT_CC1S_WIDTH 2
#define TIM3_CCMR1_OUTPUT_CC1S_MASK  (0x3u)
#define TIM3_CCMR1_INPUT_IC2F_LSB   12
#define TIM3_CCMR1_INPUT_IC2F_WIDTH 4
#define TIM3_CCMR1_INPUT_IC2F_MASK  (0xF000u)
#define TIM3_CCMR1_INPUT_IC2PSC_LSB   10
#define TIM3_CCMR1_INPUT_IC2PSC_WIDTH 2
#define TIM3_CCMR1_INPUT_IC2PSC_MASK  (0xC00u)
#define TIM3_CCMR1_INPUT_CC2S_LSB   8
#define TIM3_CCMR1_INPUT_CC2S_WIDTH 2
#define TIM3_CCMR1_INPUT_CC2S_MASK  (0x300u)
#define TIM3_CCMR1_INPUT_IC1F_LSB   4
#define TIM3_CCMR1_INPUT_IC1F_WIDTH 4
#define TIM3_CCMR1_INPUT_IC1F_MASK  (0xF0u)
#define TIM3_CCMR1_INPUT_IC1PSC_LSB   2
#define TIM3_CCMR1_INPUT_IC1PSC_WIDTH 2
#define TIM3_CCMR1_INPUT_IC1PSC_MASK  (0xCu)
#define TIM3_CCMR1_INPUT_CC1S_LSB   0
#define TIM3_CCMR1_INPUT_CC1S_WIDTH 2
#define TIM3_CCMR1_INPUT_CC1S_MASK  (0x3u)
#define TIM3_CCMR2_OUTPUT_OC4CE (1u << 15)
#define TIM3_CCMR2_OUTPUT_OC4M_LSB   12
#define TIM3_CCMR2_OUTPUT_OC4M_WIDTH 3
#define TIM3_CCMR2_OUTPUT_OC4M_MASK  (0x7000u)
#define TIM3_CCMR2_OUTPUT_OC4PE (1u << 11)
#define TIM3_CCMR2_OUTPUT_OC4FE (1u << 10)
#define TIM3_CCMR2_OUTPUT_CC4S_LSB   8
#define TIM3_CCMR2_OUTPUT_CC4S_WIDTH 2
#define TIM3_CCMR2_OUTPUT_CC4S_MASK  (0x300u)
#define TIM3_CCMR2_OUTPUT_OC3CE (1u << 7)
#define TIM3_CCMR2_OUTPUT_OC3M_LSB   4
#define TIM3_CCMR2_OUTPUT_OC3M_WIDTH 3
#define TIM3_CCMR2_OUTPUT_OC3M_MASK  (0x70u)
#define TIM3_CCMR2_OUTPUT_OC3PE (1u << 3)
#define TIM3_CCMR2_OUTPUT_OC3FE (1u << 2)
#define TIM3_CCMR2_OUTPUT_CC3S_LSB   0
#define TIM3_CCMR2_OUTPUT_CC3S_WIDTH 2
#define TIM3_CCMR2_OUTPUT_CC3S_MASK  (0x3u)
#define TIM3_CCMR2_INPUT_IC4F_LSB   12
#define TIM3_CCMR2_INPUT_IC4F_WIDTH 4
#define TIM3_CCMR2_INPUT_IC4F_MASK  (0xF000u)
#define TIM3_CCMR2_INPUT_IC4PSC_LSB   10
#define TIM3_CCMR2_INPUT_IC4PSC_WIDTH 2
#define TIM3_CCMR2_INPUT_IC4PSC_MASK  (0xC00u)
#define TIM3_CCMR2_INPUT_CC4S_LSB   8
#define TIM3_CCMR2_INPUT_CC4S_WIDTH 2
#define TIM3_CCMR2_INPUT_CC4S_MASK  (0x300u)
#define TIM3_CCMR2_INPUT_IC3F_LSB   4
#define TIM3_CCMR2_INPUT_IC3F_WIDTH 4
#define TIM3_CCMR2_INPUT_IC3F_MASK  (0xF0u)
#define TIM3_CCMR2_INPUT_IC3PSC_LSB   2
#define TIM3_CCMR2_INPUT_IC3PSC_WIDTH 2
#define TIM3_CCMR2_INPUT_IC3PSC_MASK  (0xCu)
#define TIM3_CCMR2_INPUT_CC3S_LSB   0
#define TIM3_CCMR2_INPUT_CC3S_WIDTH 2
#define TIM3_CCMR2_INPUT_CC3S_MASK  (0x3u)
#define TIM3_CCER_CC4NP (1u << 15)
#define TIM3_CCER_CC4P (1u << 13)
#define TIM3_CCER_CC4E (1u << 12)
#define TIM3_CCER_CC3NP (1u << 11)
#define TIM3_CCER_CC3P (1u << 9)
#define TIM3_CCER_CC3E (1u << 8)
#define TIM3_CCER_CC2NP (1u << 7)
#define TIM3_CCER_CC2P (1u << 5)
#define TIM3_CCER_CC2E (1u << 4)
#define TIM3_CCER_CC1NP (1u << 3)
#define TIM3_CCER_CC1P (1u << 1)
#define TIM3_CCER_CC1E (1u << 0)
#define TIM3_CNT_CNT_H_LSB   16
#define TIM3_CNT_CNT_H_WIDTH 16
#define TIM3_CNT_CNT_H_MASK  (0xFFFF0000u)
#define TIM3_CNT_CNT_L_LSB   0
#define TIM3_CNT_CNT_L_WIDTH 16
#define TIM3_CNT_CNT_L_MASK  (0xFFFFu)
#define TIM3_PSC_PSC_LSB   0
#define TIM3_PSC_PSC_WIDTH 16
#define TIM3_PSC_PSC_MASK  (0xFFFFu)
#define TIM3_ARR_ARR_H_LSB   16
#define TIM3_ARR_ARR_H_WIDTH 16
#define TIM3_ARR_ARR_H_MASK  (0xFFFF0000u)
#define TIM3_ARR_ARR_L_LSB   0
#define TIM3_ARR_ARR_L_WIDTH 16
#define TIM3_ARR_ARR_L_MASK  (0xFFFFu)
#define TIM3_CCR1_CCR1_H_LSB   16
#define TIM3_CCR1_CCR1_H_WIDTH 16
#define TIM3_CCR1_CCR1_H_MASK  (0xFFFF0000u)
#define TIM3_CCR1_CCR1_L_LSB   0
#define TIM3_CCR1_CCR1_L_WIDTH 16
#define TIM3_CCR1_CCR1_L_MASK  (0xFFFFu)
#define TIM3_CCR2_CCR2_H_LSB   16
#define TIM3_CCR2_CCR2_H_WIDTH 16
#define TIM3_CCR2_CCR2_H_MASK  (0xFFFF0000u)
#define TIM3_CCR2_CCR2_L_LSB   0
#define TIM3_CCR2_CCR2_L_WIDTH 16
#define TIM3_CCR2_CCR2_L_MASK  (0xFFFFu)
#define TIM3_CCR3_CCR3_H_LSB   16
#define TIM3_CCR3_CCR3_H_WIDTH 16
#define TIM3_CCR3_CCR3_H_MASK  (0xFFFF0000u)
#define TIM3_CCR3_CCR3_L_LSB   0
#define TIM3_CCR3_CCR3_L_WIDTH 16
#define TIM3_CCR3_CCR3_L_MASK  (0xFFFFu)
#define TIM3_CCR4_CCR4_H_LSB   16
#define TIM3_CCR4_CCR4_H_WIDTH 16
#define TIM3_CCR4_CCR4_H_MASK  (0xFFFF0000u)
#define TIM3_CCR4_CCR4_L_LSB   0
#define TIM3_CCR4_CCR4_L_WIDTH 16
#define TIM3_CCR4_CCR4_L_MASK  (0xFFFFu)
#define TIM3_DCR_DBL_LSB   8
#define TIM3_DCR_DBL_WIDTH 5
#define TIM3_DCR_DBL_MASK  (0x1F00u)
#define TIM3_DCR_DBA_LSB   0
#define TIM3_DCR_DBA_WIDTH 5
#define TIM3_DCR_DBA_MASK  (0x1Fu)
#define TIM3_DMAR_DMAB_LSB   0
#define TIM3_DMAR_DMAB_WIDTH 16
#define TIM3_DMAR_DMAB_MASK  (0xFFFFu)
#define TIM3_OR_ETR_RMP_LSB   0
#define TIM3_OR_ETR_RMP_WIDTH 3
#define TIM3_OR_ETR_RMP_MASK  (0x7u)
#define TIM3_OR_TI4_RMP_LSB   3
#define TIM3_OR_TI4_RMP_WIDTH 2
#define TIM3_OR_TI4_RMP_MASK  (0x18u)

/* === TIM6 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    uint8_t _res_0008[4];
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    uint8_t _res_0018[12];
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
} TIM6_Type;

#define TIM6_BASE 0x40001000u
#define TIM6 ((volatile TIM6_Type*)TIM6_BASE)

#define TIM6_CR1_ARPE (1u << 7)
#define TIM6_CR1_OPM (1u << 3)
#define TIM6_CR1_URS (1u << 2)
#define TIM6_CR1_UDIS (1u << 1)
#define TIM6_CR1_CEN (1u << 0)
#define TIM6_CR2_MMS_LSB   4
#define TIM6_CR2_MMS_WIDTH 3
#define TIM6_CR2_MMS_MASK  (0x70u)
#define TIM6_DIER_UDE (1u << 8)
#define TIM6_DIER_UIE (1u << 0)
#define TIM6_SR_UIF (1u << 0)
#define TIM6_EGR_UG (1u << 0)
#define TIM6_CNT_CNT_LSB   0
#define TIM6_CNT_CNT_WIDTH 16
#define TIM6_CNT_CNT_MASK  (0xFFFFu)
#define TIM6_PSC_PSC_LSB   0
#define TIM6_PSC_PSC_WIDTH 16
#define TIM6_PSC_PSC_MASK  (0xFFFFu)
#define TIM6_ARR_ARR_LSB   0
#define TIM6_ARR_ARR_WIDTH 16
#define TIM6_ARR_ARR_MASK  (0xFFFFu)

/* === TIM7 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    uint8_t _res_0008[4];
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    uint8_t _res_0018[12];
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
} TIM7_Type;

#define TIM7_BASE 0x40001400u
#define TIM7 ((volatile TIM7_Type*)TIM7_BASE)

#define TIM7_CR1_ARPE (1u << 7)
#define TIM7_CR1_OPM (1u << 3)
#define TIM7_CR1_URS (1u << 2)
#define TIM7_CR1_UDIS (1u << 1)
#define TIM7_CR1_CEN (1u << 0)
#define TIM7_CR2_MMS_LSB   4
#define TIM7_CR2_MMS_WIDTH 3
#define TIM7_CR2_MMS_MASK  (0x70u)
#define TIM7_DIER_UDE (1u << 8)
#define TIM7_DIER_UIE (1u << 0)
#define TIM7_SR_UIF (1u << 0)
#define TIM7_EGR_UG (1u << 0)
#define TIM7_CNT_CNT_LSB   0
#define TIM7_CNT_CNT_WIDTH 16
#define TIM7_CNT_CNT_MASK  (0xFFFFu)
#define TIM7_PSC_PSC_LSB   0
#define TIM7_PSC_PSC_WIDTH 16
#define TIM7_PSC_PSC_MASK  (0xFFFFu)
#define TIM7_ARR_ARR_LSB   0
#define TIM7_ARR_ARR_WIDTH 16
#define TIM7_ARR_ARR_MASK  (0xFFFFu)

/* === TIM21 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SMCR; /* 0x008 */
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    union {
    volatile uint32_t CCMR1_Output; /* 0x018 */
    volatile uint32_t CCMR1_Input; /* 0x018 */
    };
    uint8_t _res_001C[4];
    volatile uint32_t CCER; /* 0x020 */
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
    uint8_t _res_0030[4];
    volatile uint32_t CCR1; /* 0x034 */
    volatile uint32_t CCR2; /* 0x038 */
    uint8_t _res_003C[20];
    volatile uint32_t OR; /* 0x050 */
} TIM21_Type;

#define TIM21_BASE 0x40010800u
#define TIM21 ((volatile TIM21_Type*)TIM21_BASE)

#define TIM21_CR1_CEN (1u << 0)
#define TIM21_CR1_UDIS (1u << 1)
#define TIM21_CR1_URS (1u << 2)
#define TIM21_CR1_OPM (1u << 3)
#define TIM21_CR1_DIR (1u << 4)
#define TIM21_CR1_CMS_LSB   5
#define TIM21_CR1_CMS_WIDTH 2
#define TIM21_CR1_CMS_MASK  (0x60u)
#define TIM21_CR1_ARPE (1u << 7)
#define TIM21_CR1_CKD_LSB   8
#define TIM21_CR1_CKD_WIDTH 2
#define TIM21_CR1_CKD_MASK  (0x300u)
#define TIM21_CR2_MMS_LSB   4
#define TIM21_CR2_MMS_WIDTH 3
#define TIM21_CR2_MMS_MASK  (0x70u)
#define TIM21_SMCR_SMS_LSB   0
#define TIM21_SMCR_SMS_WIDTH 3
#define TIM21_SMCR_SMS_MASK  (0x7u)
#define TIM21_SMCR_TS_LSB   4
#define TIM21_SMCR_TS_WIDTH 3
#define TIM21_SMCR_TS_MASK  (0x70u)
#define TIM21_SMCR_MSM (1u << 7)
#define TIM21_SMCR_ETF_LSB   8
#define TIM21_SMCR_ETF_WIDTH 4
#define TIM21_SMCR_ETF_MASK  (0xF00u)
#define TIM21_SMCR_ETPS_LSB   12
#define TIM21_SMCR_ETPS_WIDTH 2
#define TIM21_SMCR_ETPS_MASK  (0x3000u)
#define TIM21_SMCR_ECE (1u << 14)
#define TIM21_SMCR_ETP (1u << 15)
#define TIM21_DIER_TIE (1u << 6)
#define TIM21_DIER_CC2IE (1u << 2)
#define TIM21_DIER_CC1IE (1u << 1)
#define TIM21_DIER_UIE (1u << 0)
#define TIM21_SR_CC2OF (1u << 10)
#define TIM21_SR_CC1OF (1u << 9)
#define TIM21_SR_TIF (1u << 6)
#define TIM21_SR_CC2IF (1u << 2)
#define TIM21_SR_CC1IF (1u << 1)
#define TIM21_SR_UIF (1u << 0)
#define TIM21_EGR_TG (1u << 6)
#define TIM21_EGR_CC2G (1u << 2)
#define TIM21_EGR_CC1G (1u << 1)
#define TIM21_EGR_UG (1u << 0)
#define TIM21_CCMR1_OUTPUT_OC2M_LSB   12
#define TIM21_CCMR1_OUTPUT_OC2M_WIDTH 3
#define TIM21_CCMR1_OUTPUT_OC2M_MASK  (0x7000u)
#define TIM21_CCMR1_OUTPUT_OC2PE (1u << 11)
#define TIM21_CCMR1_OUTPUT_OC2FE (1u << 10)
#define TIM21_CCMR1_OUTPUT_CC2S_LSB   8
#define TIM21_CCMR1_OUTPUT_CC2S_WIDTH 2
#define TIM21_CCMR1_OUTPUT_CC2S_MASK  (0x300u)
#define TIM21_CCMR1_OUTPUT_OC1M_LSB   4
#define TIM21_CCMR1_OUTPUT_OC1M_WIDTH 3
#define TIM21_CCMR1_OUTPUT_OC1M_MASK  (0x70u)
#define TIM21_CCMR1_OUTPUT_OC1PE (1u << 3)
#define TIM21_CCMR1_OUTPUT_OC1FE (1u << 2)
#define TIM21_CCMR1_OUTPUT_CC1S_LSB   0
#define TIM21_CCMR1_OUTPUT_CC1S_WIDTH 2
#define TIM21_CCMR1_OUTPUT_CC1S_MASK  (0x3u)
#define TIM21_CCMR1_INPUT_IC2F_LSB   12
#define TIM21_CCMR1_INPUT_IC2F_WIDTH 4
#define TIM21_CCMR1_INPUT_IC2F_MASK  (0xF000u)
#define TIM21_CCMR1_INPUT_IC2PSC_LSB   10
#define TIM21_CCMR1_INPUT_IC2PSC_WIDTH 2
#define TIM21_CCMR1_INPUT_IC2PSC_MASK  (0xC00u)
#define TIM21_CCMR1_INPUT_CC2S_LSB   8
#define TIM21_CCMR1_INPUT_CC2S_WIDTH 2
#define TIM21_CCMR1_INPUT_CC2S_MASK  (0x300u)
#define TIM21_CCMR1_INPUT_IC1F_LSB   4
#define TIM21_CCMR1_INPUT_IC1F_WIDTH 4
#define TIM21_CCMR1_INPUT_IC1F_MASK  (0xF0u)
#define TIM21_CCMR1_INPUT_IC1PSC_LSB   2
#define TIM21_CCMR1_INPUT_IC1PSC_WIDTH 2
#define TIM21_CCMR1_INPUT_IC1PSC_MASK  (0xCu)
#define TIM21_CCMR1_INPUT_CC1S_LSB   0
#define TIM21_CCMR1_INPUT_CC1S_WIDTH 2
#define TIM21_CCMR1_INPUT_CC1S_MASK  (0x3u)
#define TIM21_CCER_CC2NP (1u << 7)
#define TIM21_CCER_CC2P (1u << 5)
#define TIM21_CCER_CC2E (1u << 4)
#define TIM21_CCER_CC1NP (1u << 3)
#define TIM21_CCER_CC1P (1u << 1)
#define TIM21_CCER_CC1E (1u << 0)
#define TIM21_CNT_CNT_LSB   0
#define TIM21_CNT_CNT_WIDTH 16
#define TIM21_CNT_CNT_MASK  (0xFFFFu)
#define TIM21_PSC_PSC_LSB   0
#define TIM21_PSC_PSC_WIDTH 16
#define TIM21_PSC_PSC_MASK  (0xFFFFu)
#define TIM21_ARR_ARR_LSB   0
#define TIM21_ARR_ARR_WIDTH 16
#define TIM21_ARR_ARR_MASK  (0xFFFFu)
#define TIM21_CCR1_CCR1_LSB   0
#define TIM21_CCR1_CCR1_WIDTH 16
#define TIM21_CCR1_CCR1_MASK  (0xFFFFu)
#define TIM21_CCR2_CCR2_LSB   0
#define TIM21_CCR2_CCR2_WIDTH 16
#define TIM21_CCR2_CCR2_MASK  (0xFFFFu)
#define TIM21_OR_ETR_RMP_LSB   0
#define TIM21_OR_ETR_RMP_WIDTH 2
#define TIM21_OR_ETR_RMP_MASK  (0x3u)
#define TIM21_OR_TI1_RMP_LSB   2
#define TIM21_OR_TI1_RMP_WIDTH 3
#define TIM21_OR_TI1_RMP_MASK  (0x1Cu)
#define TIM21_OR_TI2_RMP (1u << 5)

/* === TIM22 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t SMCR; /* 0x008 */
    volatile uint32_t DIER; /* 0x00C */
    volatile uint32_t SR; /* 0x010 */
    volatile uint32_t EGR; /* 0x014 */
    union {
    volatile uint32_t CCMR1_Output; /* 0x018 */
    volatile uint32_t CCMR1_Input; /* 0x018 */
    };
    uint8_t _res_001C[4];
    volatile uint32_t CCER; /* 0x020 */
    volatile uint32_t CNT; /* 0x024 */
    volatile uint32_t PSC; /* 0x028 */
    volatile uint32_t ARR; /* 0x02C */
    uint8_t _res_0030[4];
    volatile uint32_t CCR1; /* 0x034 */
    volatile uint32_t CCR2; /* 0x038 */
    uint8_t _res_003C[20];
    volatile uint32_t OR; /* 0x050 */
} TIM22_Type;

#define TIM22_BASE 0x40011400u
#define TIM22 ((volatile TIM22_Type*)TIM22_BASE)

#define TIM22_CR1_CEN (1u << 0)
#define TIM22_CR1_UDIS (1u << 1)
#define TIM22_CR1_URS (1u << 2)
#define TIM22_CR1_OPM (1u << 3)
#define TIM22_CR1_DIR (1u << 4)
#define TIM22_CR1_CMS_LSB   5
#define TIM22_CR1_CMS_WIDTH 2
#define TIM22_CR1_CMS_MASK  (0x60u)
#define TIM22_CR1_ARPE (1u << 7)
#define TIM22_CR1_CKD_LSB   8
#define TIM22_CR1_CKD_WIDTH 2
#define TIM22_CR1_CKD_MASK  (0x300u)
#define TIM22_CR2_MMS_LSB   4
#define TIM22_CR2_MMS_WIDTH 3
#define TIM22_CR2_MMS_MASK  (0x70u)
#define TIM22_SMCR_SMS_LSB   0
#define TIM22_SMCR_SMS_WIDTH 3
#define TIM22_SMCR_SMS_MASK  (0x7u)
#define TIM22_SMCR_TS_LSB   4
#define TIM22_SMCR_TS_WIDTH 3
#define TIM22_SMCR_TS_MASK  (0x70u)
#define TIM22_SMCR_MSM (1u << 7)
#define TIM22_SMCR_ETF_LSB   8
#define TIM22_SMCR_ETF_WIDTH 4
#define TIM22_SMCR_ETF_MASK  (0xF00u)
#define TIM22_SMCR_ETPS_LSB   12
#define TIM22_SMCR_ETPS_WIDTH 2
#define TIM22_SMCR_ETPS_MASK  (0x3000u)
#define TIM22_SMCR_ECE (1u << 14)
#define TIM22_SMCR_ETP (1u << 15)
#define TIM22_DIER_TIE (1u << 6)
#define TIM22_DIER_CC2IE (1u << 2)
#define TIM22_DIER_CC1IE (1u << 1)
#define TIM22_DIER_UIE (1u << 0)
#define TIM22_SR_CC2OF (1u << 10)
#define TIM22_SR_CC1OF (1u << 9)
#define TIM22_SR_TIF (1u << 6)
#define TIM22_SR_CC2IF (1u << 2)
#define TIM22_SR_CC1IF (1u << 1)
#define TIM22_SR_UIF (1u << 0)
#define TIM22_EGR_TG (1u << 6)
#define TIM22_EGR_CC2G (1u << 2)
#define TIM22_EGR_CC1G (1u << 1)
#define TIM22_EGR_UG (1u << 0)
#define TIM22_CCMR1_OUTPUT_OC2M_LSB   12
#define TIM22_CCMR1_OUTPUT_OC2M_WIDTH 3
#define TIM22_CCMR1_OUTPUT_OC2M_MASK  (0x7000u)
#define TIM22_CCMR1_OUTPUT_OC2PE (1u << 11)
#define TIM22_CCMR1_OUTPUT_OC2FE (1u << 10)
#define TIM22_CCMR1_OUTPUT_CC2S_LSB   8
#define TIM22_CCMR1_OUTPUT_CC2S_WIDTH 2
#define TIM22_CCMR1_OUTPUT_CC2S_MASK  (0x300u)
#define TIM22_CCMR1_OUTPUT_OC1M_LSB   4
#define TIM22_CCMR1_OUTPUT_OC1M_WIDTH 3
#define TIM22_CCMR1_OUTPUT_OC1M_MASK  (0x70u)
#define TIM22_CCMR1_OUTPUT_OC1PE (1u << 3)
#define TIM22_CCMR1_OUTPUT_OC1FE (1u << 2)
#define TIM22_CCMR1_OUTPUT_CC1S_LSB   0
#define TIM22_CCMR1_OUTPUT_CC1S_WIDTH 2
#define TIM22_CCMR1_OUTPUT_CC1S_MASK  (0x3u)
#define TIM22_CCMR1_INPUT_IC2F_LSB   12
#define TIM22_CCMR1_INPUT_IC2F_WIDTH 4
#define TIM22_CCMR1_INPUT_IC2F_MASK  (0xF000u)
#define TIM22_CCMR1_INPUT_IC2PSC_LSB   10
#define TIM22_CCMR1_INPUT_IC2PSC_WIDTH 2
#define TIM22_CCMR1_INPUT_IC2PSC_MASK  (0xC00u)
#define TIM22_CCMR1_INPUT_CC2S_LSB   8
#define TIM22_CCMR1_INPUT_CC2S_WIDTH 2
#define TIM22_CCMR1_INPUT_CC2S_MASK  (0x300u)
#define TIM22_CCMR1_INPUT_IC1F_LSB   4
#define TIM22_CCMR1_INPUT_IC1F_WIDTH 4
#define TIM22_CCMR1_INPUT_IC1F_MASK  (0xF0u)
#define TIM22_CCMR1_INPUT_IC1PSC_LSB   2
#define TIM22_CCMR1_INPUT_IC1PSC_WIDTH 2
#define TIM22_CCMR1_INPUT_IC1PSC_MASK  (0xCu)
#define TIM22_CCMR1_INPUT_CC1S_LSB   0
#define TIM22_CCMR1_INPUT_CC1S_WIDTH 2
#define TIM22_CCMR1_INPUT_CC1S_MASK  (0x3u)
#define TIM22_CCER_CC2NP (1u << 7)
#define TIM22_CCER_CC2P (1u << 5)
#define TIM22_CCER_CC2E (1u << 4)
#define TIM22_CCER_CC1NP (1u << 3)
#define TIM22_CCER_CC1P (1u << 1)
#define TIM22_CCER_CC1E (1u << 0)
#define TIM22_CNT_CNT_LSB   0
#define TIM22_CNT_CNT_WIDTH 16
#define TIM22_CNT_CNT_MASK  (0xFFFFu)
#define TIM22_PSC_PSC_LSB   0
#define TIM22_PSC_PSC_WIDTH 16
#define TIM22_PSC_PSC_MASK  (0xFFFFu)
#define TIM22_ARR_ARR_LSB   0
#define TIM22_ARR_ARR_WIDTH 16
#define TIM22_ARR_ARR_MASK  (0xFFFFu)
#define TIM22_CCR1_CCR1_LSB   0
#define TIM22_CCR1_CCR1_WIDTH 16
#define TIM22_CCR1_CCR1_MASK  (0xFFFFu)
#define TIM22_CCR2_CCR2_LSB   0
#define TIM22_CCR2_CCR2_WIDTH 16
#define TIM22_CCR2_CCR2_MASK  (0xFFFFu)
#define TIM22_OR_ETR_RMP_LSB   0
#define TIM22_OR_ETR_RMP_WIDTH 2
#define TIM22_OR_ETR_RMP_MASK  (0x3u)
#define TIM22_OR_TI1_RMP_LSB   2
#define TIM22_OR_TI1_RMP_WIDTH 2
#define TIM22_OR_TI1_RMP_MASK  (0xCu)

/* === LPUART1 ================================= */
typedef struct {
    volatile uint32_t CR1; /* 0x000 */
    volatile uint32_t CR2; /* 0x004 */
    volatile uint32_t CR3; /* 0x008 */
    volatile uint32_t BRR; /* 0x00C */
    uint8_t _res_0010[8];
    volatile uint32_t RQR; /* 0x018 */
    volatile uint32_t ISR; /* 0x01C */
    volatile uint32_t ICR; /* 0x020 */
    volatile uint32_t RDR; /* 0x024 */
    volatile uint32_t TDR; /* 0x028 */
} LPUART1_Type;

#define LPUART1_BASE 0x40004800u
#define LPUART1 ((volatile LPUART1_Type*)LPUART1_BASE)

#define LPUART1_CR1_M1 (1u << 28)
#define LPUART1_CR1_DEAT4 (1u << 25)
#define LPUART1_CR1_DEAT3 (1u << 24)
#define LPUART1_CR1_DEAT2 (1u << 23)
#define LPUART1_CR1_DEAT1 (1u << 22)
#define LPUART1_CR1_DEAT0 (1u << 21)
#define LPUART1_CR1_DEDT4 (1u << 20)
#define LPUART1_CR1_DEDT3 (1u << 19)
#define LPUART1_CR1_DEDT2 (1u << 18)
#define LPUART1_CR1_DEDT1 (1u << 17)
#define LPUART1_CR1_DEDT0 (1u << 16)
#define LPUART1_CR1_CMIE (1u << 14)
#define LPUART1_CR1_MME (1u << 13)
#define LPUART1_CR1_M0 (1u << 12)
#define LPUART1_CR1_WAKE (1u << 11)
#define LPUART1_CR1_PCE (1u << 10)
#define LPUART1_CR1_PS (1u << 9)
#define LPUART1_CR1_PEIE (1u << 8)
#define LPUART1_CR1_TXEIE (1u << 7)
#define LPUART1_CR1_TCIE (1u << 6)
#define LPUART1_CR1_RXNEIE (1u << 5)
#define LPUART1_CR1_IDLEIE (1u << 4)
#define LPUART1_CR1_TE (1u << 3)
#define LPUART1_CR1_RE (1u << 2)
#define LPUART1_CR1_UESM (1u << 1)
#define LPUART1_CR1_UE (1u << 0)
#define LPUART1_CR2_ADD4_7_LSB   28
#define LPUART1_CR2_ADD4_7_WIDTH 4
#define LPUART1_CR2_ADD4_7_MASK  (0xF0000000u)
#define LPUART1_CR2_ADD0_3_LSB   24
#define LPUART1_CR2_ADD0_3_WIDTH 4
#define LPUART1_CR2_ADD0_3_MASK  (0xF000000u)
#define LPUART1_CR2_MSBFIRST (1u << 19)
#define LPUART1_CR2_TAINV (1u << 18)
#define LPUART1_CR2_TXINV (1u << 17)
#define LPUART1_CR2_RXINV (1u << 16)
#define LPUART1_CR2_SWAP (1u << 15)
#define LPUART1_CR2_STOP_LSB   12
#define LPUART1_CR2_STOP_WIDTH 2
#define LPUART1_CR2_STOP_MASK  (0x3000u)
#define LPUART1_CR2_CLKEN (1u << 11)
#define LPUART1_CR2_ADDM7 (1u << 4)
#define LPUART1_CR3_WUFIE (1u << 22)
#define LPUART1_CR3_WUS_LSB   20
#define LPUART1_CR3_WUS_WIDTH 2
#define LPUART1_CR3_WUS_MASK  (0x300000u)
#define LPUART1_CR3_DEP (1u << 15)
#define LPUART1_CR3_DEM (1u << 14)
#define LPUART1_CR3_DDRE (1u << 13)
#define LPUART1_CR3_OVRDIS (1u << 12)
#define LPUART1_CR3_CTSIE (1u << 10)
#define LPUART1_CR3_CTSE (1u << 9)
#define LPUART1_CR3_RTSE (1u << 8)
#define LPUART1_CR3_DMAT (1u << 7)
#define LPUART1_CR3_DMAR (1u << 6)
#define LPUART1_CR3_HDSEL (1u << 3)
#define LPUART1_CR3_EIE (1u << 0)
#define LPUART1_BRR_BRR_LSB   0
#define LPUART1_BRR_BRR_WIDTH 20
#define LPUART1_BRR_BRR_MASK  (0xFFFFFu)
#define LPUART1_RQR_RXFRQ (1u << 3)
#define LPUART1_RQR_MMRQ (1u << 2)
#define LPUART1_RQR_SBKRQ (1u << 1)
#define LPUART1_ISR_REACK (1u << 22)
#define LPUART1_ISR_TEACK (1u << 21)
#define LPUART1_ISR_WUF (1u << 20)
#define LPUART1_ISR_RWU (1u << 19)
#define LPUART1_ISR_SBKF (1u << 18)
#define LPUART1_ISR_CMF (1u << 17)
#define LPUART1_ISR_BUSY (1u << 16)
#define LPUART1_ISR_CTS (1u << 10)
#define LPUART1_ISR_CTSIF (1u << 9)
#define LPUART1_ISR_TXE (1u << 7)
#define LPUART1_ISR_TC (1u << 6)
#define LPUART1_ISR_RXNE (1u << 5)
#define LPUART1_ISR_IDLE (1u << 4)
#define LPUART1_ISR_ORE (1u << 3)
#define LPUART1_ISR_NF (1u << 2)
#define LPUART1_ISR_FE (1u << 1)
#define LPUART1_ISR_PE (1u << 0)
#define LPUART1_ICR_WUCF (1u << 20)
#define LPUART1_ICR_CMCF (1u << 17)
#define LPUART1_ICR_CTSCF (1u << 9)
#define LPUART1_ICR_TCCF (1u << 6)
#define LPUART1_ICR_IDLECF (1u << 4)
#define LPUART1_ICR_ORECF (1u << 3)
#define LPUART1_ICR_NCF (1u << 2)
#define LPUART1_ICR_FECF (1u << 1)
#define LPUART1_ICR_PECF (1u << 0)
#define LPUART1_RDR_RDR_LSB   0
#define LPUART1_RDR_RDR_WIDTH 9
#define LPUART1_RDR_RDR_MASK  (0x1FFu)
#define LPUART1_TDR_TDR_LSB   0
#define LPUART1_TDR_TDR_WIDTH 9
#define LPUART1_TDR_TDR_MASK  (0x1FFu)

/* === NVIC ================================= */
typedef struct {
    volatile uint32_t ISER; /* 0x000 */
    uint8_t _res_0004[124];
    volatile uint32_t ICER; /* 0x080 */
    uint8_t _res_0084[124];
    volatile uint32_t ISPR; /* 0x100 */
    uint8_t _res_0104[124];
    volatile uint32_t ICPR; /* 0x180 */
    uint8_t _res_0184[380];
    volatile uint32_t IPR0; /* 0x300 */
    volatile uint32_t IPR1; /* 0x304 */
    volatile uint32_t IPR2; /* 0x308 */
    volatile uint32_t IPR3; /* 0x30C */
    volatile uint32_t IPR4; /* 0x310 */
    volatile uint32_t IPR5; /* 0x314 */
    volatile uint32_t IPR6; /* 0x318 */
    volatile uint32_t IPR7; /* 0x31C */
} NVIC_Type;

#define NVIC_BASE 0xE000E100u
#define NVIC ((volatile NVIC_Type*)NVIC_BASE)

#define NVIC_ISER_SETENA_LSB   0
#define NVIC_ISER_SETENA_WIDTH 32
#define NVIC_ISER_SETENA_MASK  (0xFFFFFFFFu)
#define NVIC_ICER_CLRENA_LSB   0
#define NVIC_ICER_CLRENA_WIDTH 32
#define NVIC_ICER_CLRENA_MASK  (0xFFFFFFFFu)
#define NVIC_ISPR_SETPEND_LSB   0
#define NVIC_ISPR_SETPEND_WIDTH 32
#define NVIC_ISPR_SETPEND_MASK  (0xFFFFFFFFu)
#define NVIC_ICPR_CLRPEND_LSB   0
#define NVIC_ICPR_CLRPEND_WIDTH 32
#define NVIC_ICPR_CLRPEND_MASK  (0xFFFFFFFFu)
#define NVIC_IPR0_PRI_0_LSB   0
#define NVIC_IPR0_PRI_0_WIDTH 8
#define NVIC_IPR0_PRI_0_MASK  (0xFFu)
#define NVIC_IPR0_PRI_1_LSB   8
#define NVIC_IPR0_PRI_1_WIDTH 8
#define NVIC_IPR0_PRI_1_MASK  (0xFF00u)
#define NVIC_IPR0_PRI_2_LSB   16
#define NVIC_IPR0_PRI_2_WIDTH 8
#define NVIC_IPR0_PRI_2_MASK  (0xFF0000u)
#define NVIC_IPR0_PRI_3_LSB   24
#define NVIC_IPR0_PRI_3_WIDTH 8
#define NVIC_IPR0_PRI_3_MASK  (0xFF000000u)
#define NVIC_IPR1_PRI_4_LSB   0
#define NVIC_IPR1_PRI_4_WIDTH 8
#define NVIC_IPR1_PRI_4_MASK  (0xFFu)
#define NVIC_IPR1_PRI_5_LSB   8
#define NVIC_IPR1_PRI_5_WIDTH 8
#define NVIC_IPR1_PRI_5_MASK  (0xFF00u)
#define NVIC_IPR1_PRI_6_LSB   16
#define NVIC_IPR1_PRI_6_WIDTH 8
#define NVIC_IPR1_PRI_6_MASK  (0xFF0000u)
#define NVIC_IPR1_PRI_7_LSB   24
#define NVIC_IPR1_PRI_7_WIDTH 8
#define NVIC_IPR1_PRI_7_MASK  (0xFF000000u)
#define NVIC_IPR2_PRI_8_LSB   0
#define NVIC_IPR2_PRI_8_WIDTH 8
#define NVIC_IPR2_PRI_8_MASK  (0xFFu)
#define NVIC_IPR2_PRI_9_LSB   8
#define NVIC_IPR2_PRI_9_WIDTH 8
#define NVIC_IPR2_PRI_9_MASK  (0xFF00u)
#define NVIC_IPR2_PRI_10_LSB   16
#define NVIC_IPR2_PRI_10_WIDTH 8
#define NVIC_IPR2_PRI_10_MASK  (0xFF0000u)
#define NVIC_IPR2_PRI_11_LSB   24
#define NVIC_IPR2_PRI_11_WIDTH 8
#define NVIC_IPR2_PRI_11_MASK  (0xFF000000u)
#define NVIC_IPR3_PRI_12_LSB   0
#define NVIC_IPR3_PRI_12_WIDTH 8
#define NVIC_IPR3_PRI_12_MASK  (0xFFu)
#define NVIC_IPR3_PRI_13_LSB   8
#define NVIC_IPR3_PRI_13_WIDTH 8
#define NVIC_IPR3_PRI_13_MASK  (0xFF00u)
#define NVIC_IPR3_PRI_14_LSB   16
#define NVIC_IPR3_PRI_14_WIDTH 8
#define NVIC_IPR3_PRI_14_MASK  (0xFF0000u)
#define NVIC_IPR3_PRI_15_LSB   24
#define NVIC_IPR3_PRI_15_WIDTH 8
#define NVIC_IPR3_PRI_15_MASK  (0xFF000000u)
#define NVIC_IPR4_PRI_16_LSB   0
#define NVIC_IPR4_PRI_16_WIDTH 8
#define NVIC_IPR4_PRI_16_MASK  (0xFFu)
#define NVIC_IPR4_PRI_17_LSB   8
#define NVIC_IPR4_PRI_17_WIDTH 8
#define NVIC_IPR4_PRI_17_MASK  (0xFF00u)
#define NVIC_IPR4_PRI_18_LSB   16
#define NVIC_IPR4_PRI_18_WIDTH 8
#define NVIC_IPR4_PRI_18_MASK  (0xFF0000u)
#define NVIC_IPR4_PRI_19_LSB   24
#define NVIC_IPR4_PRI_19_WIDTH 8
#define NVIC_IPR4_PRI_19_MASK  (0xFF000000u)
#define NVIC_IPR5_PRI_20_LSB   0
#define NVIC_IPR5_PRI_20_WIDTH 8
#define NVIC_IPR5_PRI_20_MASK  (0xFFu)
#define NVIC_IPR5_PRI_21_LSB   8
#define NVIC_IPR5_PRI_21_WIDTH 8
#define NVIC_IPR5_PRI_21_MASK  (0xFF00u)
#define NVIC_IPR5_PRI_22_LSB   16
#define NVIC_IPR5_PRI_22_WIDTH 8
#define NVIC_IPR5_PRI_22_MASK  (0xFF0000u)
#define NVIC_IPR5_PRI_23_LSB   24
#define NVIC_IPR5_PRI_23_WIDTH 8
#define NVIC_IPR5_PRI_23_MASK  (0xFF000000u)
#define NVIC_IPR6_PRI_24_LSB   0
#define NVIC_IPR6_PRI_24_WIDTH 8
#define NVIC_IPR6_PRI_24_MASK  (0xFFu)
#define NVIC_IPR6_PRI_25_LSB   8
#define NVIC_IPR6_PRI_25_WIDTH 8
#define NVIC_IPR6_PRI_25_MASK  (0xFF00u)
#define NVIC_IPR6_PRI_26_LSB   16
#define NVIC_IPR6_PRI_26_WIDTH 8
#define NVIC_IPR6_PRI_26_MASK  (0xFF0000u)
#define NVIC_IPR6_PRI_27_LSB   24
#define NVIC_IPR6_PRI_27_WIDTH 8
#define NVIC_IPR6_PRI_27_MASK  (0xFF000000u)
#define NVIC_IPR7_PRI_28_LSB   0
#define NVIC_IPR7_PRI_28_WIDTH 8
#define NVIC_IPR7_PRI_28_MASK  (0xFFu)
#define NVIC_IPR7_PRI_29_LSB   8
#define NVIC_IPR7_PRI_29_WIDTH 8
#define NVIC_IPR7_PRI_29_MASK  (0xFF00u)
#define NVIC_IPR7_PRI_30_LSB   16
#define NVIC_IPR7_PRI_30_WIDTH 8
#define NVIC_IPR7_PRI_30_MASK  (0xFF0000u)
#define NVIC_IPR7_PRI_31_LSB   24
#define NVIC_IPR7_PRI_31_WIDTH 8
#define NVIC_IPR7_PRI_31_MASK  (0xFF000000u)

/* === MPU ================================= */
typedef struct {
    volatile uint32_t MPU_TYPER; /* 0x000 */
    volatile uint32_t MPU_CTRL; /* 0x004 */
    volatile uint32_t MPU_RNR; /* 0x008 */
    volatile uint32_t MPU_RBAR; /* 0x00C */
    volatile uint32_t MPU_RASR; /* 0x010 */
} MPU_Type;

#define MPU_BASE 0xE000ED90u
#define MPU ((volatile MPU_Type*)MPU_BASE)

#define MPU_MPU_TYPER_SEPARATE (1u << 0)
#define MPU_MPU_TYPER_DREGION_LSB   8
#define MPU_MPU_TYPER_DREGION_WIDTH 8
#define MPU_MPU_TYPER_DREGION_MASK  (0xFF00u)
#define MPU_MPU_TYPER_IREGION_LSB   16
#define MPU_MPU_TYPER_IREGION_WIDTH 8
#define MPU_MPU_TYPER_IREGION_MASK  (0xFF0000u)
#define MPU_MPU_CTRL_ENABLE (1u << 0)
#define MPU_MPU_CTRL_HFNMIENA (1u << 1)
#define MPU_MPU_CTRL_PRIVDEFENA (1u << 2)
#define MPU_MPU_RNR_REGION_LSB   0
#define MPU_MPU_RNR_REGION_WIDTH 8
#define MPU_MPU_RNR_REGION_MASK  (0xFFu)
#define MPU_MPU_RBAR_REGION_LSB   0
#define MPU_MPU_RBAR_REGION_WIDTH 4
#define MPU_MPU_RBAR_REGION_MASK  (0xFu)
#define MPU_MPU_RBAR_VALID (1u << 4)
#define MPU_MPU_RBAR_ADDR_LSB   5
#define MPU_MPU_RBAR_ADDR_WIDTH 27
#define MPU_MPU_RBAR_ADDR_MASK  (0xFFFFFFE0u)
#define MPU_MPU_RASR_ENABLE (1u << 0)
#define MPU_MPU_RASR_SIZE_LSB   1
#define MPU_MPU_RASR_SIZE_WIDTH 5
#define MPU_MPU_RASR_SIZE_MASK  (0x3Eu)
#define MPU_MPU_RASR_SRD_LSB   8
#define MPU_MPU_RASR_SRD_WIDTH 8
#define MPU_MPU_RASR_SRD_MASK  (0xFF00u)
#define MPU_MPU_RASR_B (1u << 16)
#define MPU_MPU_RASR_C (1u << 17)
#define MPU_MPU_RASR_S (1u << 18)
#define MPU_MPU_RASR_TEX_LSB   19
#define MPU_MPU_RASR_TEX_WIDTH 3
#define MPU_MPU_RASR_TEX_MASK  (0x380000u)
#define MPU_MPU_RASR_AP_LSB   24
#define MPU_MPU_RASR_AP_WIDTH 3
#define MPU_MPU_RASR_AP_MASK  (0x7000000u)
#define MPU_MPU_RASR_XN (1u << 28)

/* === STK ================================= */
typedef struct {
    volatile uint32_t CSR; /* 0x000 */
    volatile uint32_t RVR; /* 0x004 */
    volatile uint32_t CVR; /* 0x008 */
    volatile uint32_t CALIB; /* 0x00C */
} STK_Type;

#define STK_BASE 0xE000E010u
#define STK ((volatile STK_Type*)STK_BASE)

#define STK_CSR_ENABLE (1u << 0)
#define STK_CSR_TICKINT (1u << 1)
#define STK_CSR_CLKSOURCE (1u << 2)
#define STK_CSR_COUNTFLAG (1u << 16)
#define STK_RVR_RELOAD_LSB   0
#define STK_RVR_RELOAD_WIDTH 24
#define STK_RVR_RELOAD_MASK  (0xFFFFFFu)
#define STK_CVR_CURRENT_LSB   0
#define STK_CVR_CURRENT_WIDTH 24
#define STK_CVR_CURRENT_MASK  (0xFFFFFFu)
#define STK_CALIB_TENMS_LSB   0
#define STK_CALIB_TENMS_WIDTH 24
#define STK_CALIB_TENMS_MASK  (0xFFFFFFu)
#define STK_CALIB_SKEW (1u << 30)
#define STK_CALIB_NOREF (1u << 31)

/* === SCB ================================= */
typedef struct {
    volatile uint32_t CPUID; /* 0x000 */
    volatile uint32_t ICSR; /* 0x004 */
    volatile uint32_t VTOR; /* 0x008 */
    volatile uint32_t AIRCR; /* 0x00C */
    volatile uint32_t SCR; /* 0x010 */
    volatile uint32_t CCR; /* 0x014 */
    uint8_t _res_0018[4];
    volatile uint32_t SHPR2; /* 0x01C */
    volatile uint32_t SHPR3; /* 0x020 */
} SCB_Type;

#define SCB_BASE 0xE000ED00u
#define SCB ((volatile SCB_Type*)SCB_BASE)

#define SCB_CPUID_REVISION_LSB   0
#define SCB_CPUID_REVISION_WIDTH 4
#define SCB_CPUID_REVISION_MASK  (0xFu)
#define SCB_CPUID_PARTNO_LSB   4
#define SCB_CPUID_PARTNO_WIDTH 12
#define SCB_CPUID_PARTNO_MASK  (0xFFF0u)
#define SCB_CPUID_ARCHITECTURE_LSB   16
#define SCB_CPUID_ARCHITECTURE_WIDTH 4
#define SCB_CPUID_ARCHITECTURE_MASK  (0xF0000u)
#define SCB_CPUID_VARIANT_LSB   20
#define SCB_CPUID_VARIANT_WIDTH 4
#define SCB_CPUID_VARIANT_MASK  (0xF00000u)
#define SCB_CPUID_IMPLEMENTER_LSB   24
#define SCB_CPUID_IMPLEMENTER_WIDTH 8
#define SCB_CPUID_IMPLEMENTER_MASK  (0xFF000000u)
#define SCB_ICSR_VECTACTIVE_LSB   0
#define SCB_ICSR_VECTACTIVE_WIDTH 9
#define SCB_ICSR_VECTACTIVE_MASK  (0x1FFu)
#define SCB_ICSR_RETTOBASE (1u << 11)
#define SCB_ICSR_VECTPENDING_LSB   12
#define SCB_ICSR_VECTPENDING_WIDTH 7
#define SCB_ICSR_VECTPENDING_MASK  (0x7F000u)
#define SCB_ICSR_ISRPENDING (1u << 22)
#define SCB_ICSR_PENDSTCLR (1u << 25)
#define SCB_ICSR_PENDSTSET (1u << 26)
#define SCB_ICSR_PENDSVCLR (1u << 27)
#define SCB_ICSR_PENDSVSET (1u << 28)
#define SCB_ICSR_NMIPENDSET (1u << 31)
#define SCB_VTOR_TBLOFF_LSB   7
#define SCB_VTOR_TBLOFF_WIDTH 25
#define SCB_VTOR_TBLOFF_MASK  (0xFFFFFF80u)
#define SCB_AIRCR_VECTCLRACTIVE (1u << 1)
#define SCB_AIRCR_SYSRESETREQ (1u << 2)
#define SCB_AIRCR_ENDIANESS (1u << 15)
#define SCB_AIRCR_VECTKEYSTAT_LSB   16
#define SCB_AIRCR_VECTKEYSTAT_WIDTH 16
#define SCB_AIRCR_VECTKEYSTAT_MASK  (0xFFFF0000u)
#define SCB_SCR_SLEEPONEXIT (1u << 1)
#define SCB_SCR_SLEEPDEEP (1u << 2)
#define SCB_SCR_SEVEONPEND (1u << 4)
#define SCB_CCR_NONBASETHRDENA (1u << 0)
#define SCB_CCR_USERSETMPEND (1u << 1)
#define SCB_CCR_UNALIGN__TRP (1u << 3)
#define SCB_CCR_DIV_0_TRP (1u << 4)
#define SCB_CCR_BFHFNMIGN (1u << 8)
#define SCB_CCR_STKALIGN (1u << 9)
#define SCB_SHPR2_PRI_11_LSB   24
#define SCB_SHPR2_PRI_11_WIDTH 8
#define SCB_SHPR2_PRI_11_MASK  (0xFF000000u)
#define SCB_SHPR3_PRI_14_LSB   16
#define SCB_SHPR3_PRI_14_WIDTH 8
#define SCB_SHPR3_PRI_14_MASK  (0xFF0000u)
#define SCB_SHPR3_PRI_15_LSB   24
#define SCB_SHPR3_PRI_15_WIDTH 8
#define SCB_SHPR3_PRI_15_MASK  (0xFF000000u)

#endif /* STM32L0X1_PERIPHERALS_H_ */
