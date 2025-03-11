#include <mmath/qxx.h>



const uint8_t div_lookup[65] = {
    0x7F, 0x7D, 0x7B, 0x79, 0x78, 0x76, 0x74, 0x73, 
    0x71, 0x6F, 0x6E, 0x6D, 0x6B, 0x6A, 0x68, 0x67, 
    0x66, 0x65, 0x63, 0x62, 0x61, 0x60, 0x5F, 0x5E, 
    0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x56, 
    0x55, 0x54, 0x53, 0x52, 0x52, 0x51, 0x50, 0x4F, 
    0x4E, 0x4E, 0x4D, 0x4C, 0x4C, 0x4B, 0x4A, 0x49, 
    0x49, 0x48, 0x48, 0x47, 0x46, 0x46, 0x45, 0x45, 
    0x44, 0x43, 0x43, 0x42, 0x42, 0x41, 0x41, 0x40,
    0x40 /* 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 */
};

int_fast32_t _qxx_div(int_fast32_t x1, int_fast32_t x2, uint8_t type, int8_t qbit)
{
    uint8_t i, sign = 0;
    uint_fast32_t u32t;
    uint_fast32_t u30g;
    uint_fast32_t uq1;
    uint_fast32_t uq2;
    uint_fast32_t res;
    uint_fast64_t u64q;

    if (type == 0) {
        if (x2 <= 0) {
            if (x2 == 0) {
                return INT32_MAX;
            } else {
                sign = 1;
                x2 = -x2;
            }
        }

        if (x1 < 0) {
            sign ^= 1;
            x1 = -x1;
        }
    } else {
        if (x2 == 0) {
            return INT32_MAX;
        }
    }

    u64q = (uint_fast64_t)x1;
    uq2 = (uint_fast32_t)x2;

    while (uq2 < 0x40000000) {
        uq2 <<= 1;
        u64q <<= 1;
    }

    if (qbit < 31) {
        u64q >>= (31 - qbit - 1);
    }
    else {
        u64q <<= 1;
    }

    if (u64q >> 32) {
        return sign ? INT32_MIN : INT32_MAX;
    } else {
        uq1 = (uint_fast32_t)u64q;
    }

    i = uq2 >> 24;
    i -= 64;
    u30g = (uint_fast32_t)div_lookup[i] << 24;
    u32t = _L(u30g, uq2);
    u32t = -((uint_fast32_t)u32t - 0x80000000);
    u32t = u32t << 1;
    u30g = _L(u30g, u32t);
    u32t = _L(u30g, uq2);
    u32t = -((uint_fast32_t)u32t - 0x80000000);
    u32t = u32t << 1;
    u30g = _L(u30g, u32t);
    u32t = _L(u30g, uq2);
    u32t = -((uint_fast32_t)u32t - 0x80000000);
    u32t = u32t << 1;
    u30g = _L(u30g, u32t);
    res = _L(u30g, uq1);

    if (type == 0) {
        if (res > INT32_MAX) {
            return sign ? INT32_MIN : INT32_MAX;
        }
        else {
            return sign ? -(int_fast32_t)res : (int_fast32_t)res;
        }
    }

    return res;
}