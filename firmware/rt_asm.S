.syntax unified
.cpu cortex-m0plus
.thumb

.section .text
.global __aeabi_uidiv
.global __aeabi_uidivmod
.global __aeabi_idiv
.global __aeabi_idivmod

@ --- SIGNED DIVISION ---
@ r0 = dividend, r1 = divisor
__aeabi_idiv:
__aeabi_idivmod:
    push    {r4, lr}
    movs    r4, #0          @ r4 bit 0: quotient sign, bit 1: remainder sign

    @ Check divisor (r1) sign
    cmp     r1, #0
    bge     check_dividend
    rsbs    r1, r1, #0      @ r1 = -r1 (make positive)
    movs    r4, #1          @ Mark quotient to be flipped

check_dividend:
    @ Check dividend (r0) sign
    cmp     r0, #0
    bge     do_unsigned_call
    rsbs    r0, r0, #0      @ r0 = -r0 (make positive)
    
    @ If dividend is negative: 
    @ 1. Remainder must be flipped (bit 1)
    @ 2. Quotient sign must be toggled (XOR bit 0)
    movs    r2, #3          @ 0b11
    eors    r4, r4, r2      @ Toggle both bits

do_unsigned_call:
    bl      __aeabi_uidivmod

    @ Restore Quotient (r0) sign (bit 0 of r4)
    lsrs    r2, r4, #1      @ Carry = bit 0
    bcc     check_rem_sign  @ If carry is 0, quotient is positive
    rsbs    r0, r0, #0      @ Negate quotient

check_rem_sign:
    @ Restore Remainder (r1) sign (bit 1 of r4)
    lsrs    r2, r4, #2      @ Carry = bit 1
    bcc     finish          @ If carry is 0, remainder is positive
    rsbs    r1, r1, #0      @ Negate remainder

finish:
    pop     {r4, pc}

@ --- UNSIGNED DIVISION ---
@ r0 = dividend, r1 = divisor
@ Returns: r0 = quotient, r1 = remainder
__aeabi_uidiv:
__aeabi_uidivmod:
    cmp     r1, #0
    beq     div_zero
    
    movs    r2, r1          @ r2 = divisor (current power)
    movs    r1, r0          @ r1 = current remainder (initially dividend)
    movs    r0, #0          @ r0 = quotient
    movs    r3, #1          @ r3 = current bit

loop_shift:
    @ Shift divisor left until it is >= dividend
    cmp     r2, r1
    bhs     loop_div
    lsls    r2, r2, #1
    lsls    r3, r3, #1
    @ Prevent infinite loop if MSB is set
    cmp     r2, #0
    bpl     loop_shift

loop_div:
    cmp     r1, r2
    blo     next_bit
    subs    r1, r1, r2
    orrs    r0, r0, r3

next_bit:
    lsrs    r2, r2, #1
    lsrs    r3, r3, #1
    bne     loop_div
    bx      lr

div_zero:
    movs    r0, #0
    movs    r1, #0
    bx      lr