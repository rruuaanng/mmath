#include <mmath/qxx.h>


const uint_fast32_t log_lookup[15] = {
    0xFB6DB6DB, 0x04EC4EC4, 0xFAAAAAAB, 0x05D1745D, 0xF999999A, 
    0x071c71c7, 0xf8000000, 0x09249249, 0xF5555556, 0x0CCCCCCC,
    0xF0000000, 0x15555555, 0xE0000000, 0x40000000, 0x00000000
};

const uint_fast32_t log_min_lookup[5] = {
    0x00000010, 0x00015FC3, 0x00960AAE, 0x08A95552, 0x2F16AC6D
};

int_fast32_t _qxx_log(int_fast32_t x, int_fast32_t min, const int8_t qbit)
{
#define _L(x1, x2) (int_fast32_t)(((int_fast64_t)x1 * (int_fast64_t)x2) >> 31)
    int_fast16_t exp;
    int_fast32_t res;
    int_fast32_t q30r;
    uint_fast32_t q31i;
    const uint_fast32_t *coef;

    if (x <= 0) {
        return 0;
    }

    if ((qbit > 26 && x <= min) || (qbit <= 26 && x <= 0)) {
        return INT32_MIN;
    }

    min = log_min_lookup[min];
    exp = (31 - qbit);
    q31i = (uint_fast32_t)x;
    while (q31i < 0x55555555) {
        q31i <<= 1;
        exp--;
    }

    coef = log_lookup;
    q30r = *coef++;
    q31i -= 0x7FFFFFFF;
    for (uint8_t cnt = 14; cnt > 0; cnt--) {
        q30r = _L(q31i, q30r);
        q30r += *coef++;
    }

    res = q30r >> (30 - qbit);
    res += _L(0x58B90BFC, ((int_fast32_t)exp << qbit)) * (exp > 0 ? 1 : -1);
#undef _L

    return res;
}