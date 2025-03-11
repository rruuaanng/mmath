#include <mmath/qxx.h>



const uint_fast16_t sqrt_lookup[96] = {
    0X7F02, 0X7D19, 0X7B46, 0X7986, 0X77D9, 0X763D, 0X74B2, 0X7335, 
    0X71C7, 0X7066, 0X6F11, 0X6DC8, 0X6C8B, 0X6B58, 0X6A2F, 0X690F, 
    0X67F8, 0X66EA, 0X65E4, 0X64E5, 0X63EE, 0X62FE, 0X6214, 0X6131, 
    0X6054, 0X5F7D, 0X5EAB, 0X5DDE, 0X5D17, 0X5C54, 0X5B96, 0X5ADD, 
    0X5A28, 0X5977, 0X58CA, 0X5821, 0X577C, 0X56DA, 0X563C, 0X55A1, 
    0X5509, 0X5475, 0X53E3, 0X5354, 0X52C9, 0X523F, 0X51B9, 0X5135, 
    0X50B3, 0X5034, 0X4FB7, 0X4F3D, 0X4EC4, 0X4E4E, 0X4DDA, 0X4D68, 
    0X4CF7, 0X4C89, 0X4C1D, 0X4BB2, 0X4B49, 0X4AE1, 0X4A7C, 0X4A18, 
    0X49B5, 0X4954, 0X48F4, 0X4896, 0X483A, 0X47DE, 0X4784, 0X472C, 
    0X46D4, 0X467E, 0X4629, 0X45D6, 0X4583, 0X4532, 0X44E1, 0X4492, 
    0X4444, 0X43F7, 0X43AA, 0X435F, 0X4315, 0X42CC, 0X4284, 0X423C, 
    0X41F6, 0X41B0, 0X416B, 0X4127, 0X40E4, 0X40A2, 0X4060, 0X4020
};

int_fast32_t _qxx_sqrt(int_fast32_t x, int_fast32_t y, int8_t qbit, int8_t type)
{
    uint8_t i, u8i;
    int_fast16_t i16e;
    uint_fast32_t q30g, q30res;
    uint_fast32_t res, q32i;

    if (type == 2 || type == 3) {
        uint_fast64_t u64s = _X(x, x) + _X(y, y);

        if (u64s == 0) {
            return 0;
        }

        i16e = type == 2
               ? (32 - qbit)
               : -(32 - qbit);

        while ((uint_fast16_t)(u64s >> 48) < 0x4000) {
            u64s <<= 2;
            i16e += type == 2 ? -1 : 1;
        }

        q32i = (uint_fast32_t)(u64s >> 32);
    } else {
        if (x <= 0) {
            return 0;
        }

        if ((32 - qbit) % 2 == 1) {
            x <<= 1;
            i16e = type == 1
                   ? ((32 - qbit - 1) >> 1)
                   : -((32 - qbit - 1) >> 1);
        } else {
            i16e = type == 1
                   ? ((32 - qbit) >> 1)
                   : -((32 - qbit) >> 1);
        }

        q32i = (uint_fast32_t)x;
        while ((uint_fast16_t)(q32i >> 16) < 0x4000) {
            q32i <<= 2;
            i16e += (type) ? -1 : 1;
        }
    }

    i = (q32i >> 25) - 32;
    q30g = (uint_fast32_t)sqrt_lookup[i] << 16;
    u8i = qbit < 24 ? 2 : 3;

    while (u8i--) {
        res = _UL(q32i, q30g);
        q30res = _UL(res, q30g);
        q30res = -(q30res - 0xC0000000);
        q30g = _UL(q30g, q30res);
    }

    if (type == 1 || type == 2) {
        res = _UL(q30g, q32i);
        i16e -= (31 - qbit);
        if (type == 2 && i16e > 0) {
            return 0x7FFFFFFF;
        }

        if (qbit >= 30 && i16e > 0) {
            res <<= 1;
            return res;
        }
    } else {
        i16e = i16e - (31 - qbit) + 1;
        res = q30g;

        if (i16e > 0) {
            return 0x7FFFFFFF;
        }
    }

    if (i16e <= -32) {
        return 0;
    }
    if (i16e <= -16) {
        res >>= 16;
        i16e += 16;
    }
    if (i16e <= -8) {
        res >>= 8;
        i16e += 8;
    }
    while (i16e < -1) {
        res >>= 1;
        i16e++;
    }
    if (i16e) {
        res++;
        res >>= 1;
    }

    return res;
}
