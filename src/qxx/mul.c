#include <mmath/qxx.h>



int_fast32_t _qxx_mul(int_fast32_t x1, int_fast32_t x2, int8_t qbit)
{
    int_fast32_t x1i, x2i;
    int_fast32_t x1h, x2h;
    int_fast64_t res;

    /* Karatsuba */
    x1i = x1 & 0xFFFF;
    x2i = x2 & 0xFFFF;
    x1h = x1 >> 16;
    x2h = x2 >> 16;
    res = x1i * x2i;
    res += (int_fast64_t)(x1h * x2i + x1i * x2h) << 16;
    res += (int_fast64_t)(x1h * x2h) << 32;
    res = res >> qbit;

    return (int_fast32_t)res;
}

