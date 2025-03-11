#include <mmath/qxx.h>



float _qxx_to_float(int_fast32_t x, int8_t qbit)
{
    uint_fast16_t exp;
    uint_fast32_t res;
    uint_fast32_t q31;

    exp = 0x3F80 + ((31 - qbit) * ((uint_fast32_t)1U << (7)));

    if (x == 0) {
        return 0.0f;
    }

    if (x < 0) {
        exp |= 0x8000;
        q31 = -x;
    } else {
        q31 = x;
    }

    while ((uint_fast16_t)(q31 >> 16) < 0x8000) {
        q31 <<= 1;
        exp -= 0x0080;
    }

    res = (q31 + 0x0080) >> 8;
    res &= ~0x00800000;
    res += (uint_fast32_t)exp << 16;

    return *(float *)&res;
}