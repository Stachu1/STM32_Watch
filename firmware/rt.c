#include <stddef.h>

#include "types.h"
#include "intrin.h"

void __aeabi_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;

    while (n--) *d++ = *s++;
}

void __aeabi_memcpy4(void *dest, const void *src, size_t n) {
     __aeabi_memcpy(dest, src, n);
}