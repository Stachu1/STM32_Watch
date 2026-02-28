#ifndef _INTRIN_H
#define _INTRIN_H

#define BF_PREP(val, field)   (((val) << field##_LSB) & field##_MASK)
#define BF_GET(x, field)      (((x) & field##_MASK) >> field##_LSB)
#define BF_SET(x, field, v)   do { (x) = ((x) & ~(field##_MASK)) | BF_PREP((v), field); } while (0)
#define BF_CLEAR(x, field)    do { (x) &= ~(field##_MASK); } while (0)

#define NOP() __asm__ volatile ("nop")

#endif