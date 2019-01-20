
#include <stdint.h>

#define UINT64_STR_LEN 16
#define UINT32_STR_LEN 8
#define UINT8_STR_LEN  2

uint32_t big_to_little_uint32(uint32_t x) {
    x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);

    return (x << 16) | (x >> 16);
}

uint64_t big_to_little_uint64(uint64_t x) {
    x = ((x << 8) & 0xFF00FF00FF00FF00ULL) | \
        ((x >> 8) & 0x00FF00FF00FF00FFULL);
    x = ((x << 16) & 0xFFFF0000FFFF0000ULL) | \
        ((x >> 16) & 0x0000FFFF0000FFFFULL);

    return (x << 32) | (x >> 32);
}

char *uint8_hex_str(uint8_t n) {

    static char buff[UINT8_STR_LEN + 1] = {0};
    const char  *hex = "0123456789abcdef";
    uint8_t     i;

    buff[UINT8_STR_LEN] = 0;
    i = UINT8_STR_LEN - 1;
    while (i < 16) {
        buff[i] = hex[n % 16];
        n /= 16;
        i--;
    }

    return ((char *)&buff);
}

char *uint32_hex_str(uint32_t n) {

    static char buff[UINT32_STR_LEN + 1] = {0};
    const char  *hex = "0123456789abcdef";
    uint8_t     i;

    buff[UINT32_STR_LEN] = 0;
    i = UINT32_STR_LEN - 1;
    while (i < 16) {
        buff[i] = hex[n % 16];
        n /= 16;
        i--;
    }

    return ((char *)&buff);
}

char *uint64_hex_str(uint64_t n) {

    static char buff[UINT64_STR_LEN + 1] = {0};
    const char  *hex = "0123456789abcdef";
    uint8_t     i;

    buff[UINT64_STR_LEN] = 0;
    i = UINT64_STR_LEN - 1;
    while (i < 16) {
        buff[i] = hex[n % 16];
        n /= 16;
        i--;
    }

    return ((char *)&buff);
}
