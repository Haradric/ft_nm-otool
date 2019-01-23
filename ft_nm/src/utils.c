
#include <stdint.h>

uint32_t btlu32(uint32_t x) {
    x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);

    return (x << 16) | (x >> 16);
}

uint64_t btlu64(uint64_t x) {
    x = ((x << 8) & 0xFF00FF00FF00FF00ULL) | \
        ((x >> 8) & 0x00FF00FF00FF00FFULL);
    x = ((x << 16) & 0xFFFF0000FFFF0000ULL) | \
        ((x >> 16) & 0x0000FFFF0000FFFFULL);

    return (x << 32) | (x >> 32);
}
