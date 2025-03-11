#include <mmath/qxx.h>



const int_fast32_t sin_lookup[52] = {
    0,          33553067,   67097942,   100626436,
    134130364,  167601545,  201031810,  234412995,
    267736951,  300995544,  334180652,  367284176,
    400298032,  433214161,  466024527,  498721120,
    531295957,  563741086,  596048586,  628210568,
    660219183,  692066614,  723745087,  755246868,
    786564267,  817689637,  848615380,  879333946,
    909837834,  940119599,  970171848,  999987242,
    1029558505, 1058878415, 1087939815, 1116735610,
    1145258771, 1173502333, 1201459401, 1229123150,
    1256486826, 1283543749, 1310287313, 1336710990,
    1362808327, 1388572955, 1413998582, 1439079002,
    1463808091, 1488179813, 1512188216, 1535827441
};

const int_fast32_t cos_lookup[52] = {
    2147483647, 2147221509, 2146435157, 2145124784,
    2143290709, 2140933381, 2138053374, 2134651392,
    2130728266, 2126284953, 2121322538, 2115842232,
    2109845374, 2103333428, 2096307983, 2088770754,
    2080723582, 2072168431, 2063107390, 2053542671,
    2043476608, 2032911661, 2021850407, 2010295547,
    1998249902, 1985716414, 1972698141, 1959198262,
    1945220073, 1930766987, 1915842531, 1900450350,
    1884594201, 1868277956, 1851505597, 1834281220,
    1816609030, 1798493340, 1779938574, 1760949261,
    1741530038, 1721685646, 1701420928, 1680740833,
    1659650409, 1638154806, 1616259270, 1593969148,
    1571289881, 1548227007, 1524786154, 1500973048
};

static int_fast32_t _qxx_sin_lookup_fn(uint_fast32_t x)
{
	uint_fast16_t i;
    int_fast32_t q31x, q31s;
    int_fast32_t q31c, res;

    i = (uint_fast16_t)(x >> 25) & 0x003F;
    q31s = sin_lookup[i];
    q31c = cos_lookup[i];

    q31x = x & 0x01FFFFFF;
    res = _L(0x2AAAAAAB, q31x);
    res = _L(q31c, res);
    res = -(q31s + res);
    res = res >> 1;
    res = _L(q31x, res);
    res = q31c + res;
    res = _L(q31x, res);
    res = q31s + res;

    return res;
}

static int_fast32_t _qxx_cos_lookup_fn(uint_fast32_t x)
{
	uint_fast16_t i;
    int_fast32_t q31x;
    int_fast32_t q31s;
    int_fast32_t q31c;
    int_fast32_t res;

    i = (uint_fast16_t)(x >> 25) & 0x003F;
    q31s = sin_lookup[i];
    q31c = cos_lookup[i];

    q31x = x & 0x01FFFFFF;
    res = _L(0x2AAAAAAB, q31x);
    res = _L(q31s, res);
    res = res - q31c;
    res = res >> 1;
    res = _L(q31x, res);
    res = res - q31s;
    res = _L(q31x, res);
    res = q31c + res;
    
    return res;
}

int_fast32_t _qxx_sin_cos(int_fast32_t x, int8_t qbit, int8_t type, int8_t format)
{
    uint8_t s = 0;
    uint_fast32_t u29i, u30i;
    uint_fast32_t u31i, u32i;
    uint_fast32_t res;

    if (x < 0) {
        x = -x;
        if (type == 0) {
            s = 1;
        }
    }

    if (format == 1) {
        u32i = (uint_fast32_t)x << (32 - qbit);
        if (u32i >= 0x80000000) {
            u32i -= 0x80000000;
            s ^= 1;
        }
        u30i = _L(u32i, 0xc90FDAA2);
    } else {
        int_fast16_t exp = 29 - qbit;
        u29i = (uint_fast32_t)x;

        while (exp) {
            u29i -= u29i >= 0x6487ED51 ? 0x6487ED51 : 0;
            u29i <<= 1;
            exp--;
        }

        if (u29i >= 0x6487ED51) {
            u29i -= 0x6487ED51;
            s ^= 1;
        }
        u30i = u29i << 1;
    }

    if (u30i >= 0x6487ED51) {
        u30i = 0xC90FDAA2 - u30i;
        if (type == 1) {
            s ^= 1;
        }
    }

    u31i = u30i << 1;
    if (type == 0) {
        res = u31i > 0x6487ED51
              ? _qxx_cos_lookup_fn(0xC90FDAA2 - u31i)
              : _qxx_sin_lookup_fn(u31i);
    }
    if (type == 1) {
        res = u31i > 0x6487ed51
              ? _qxx_sin_lookup_fn(0xC90FDAA2 - u31i)
              : _qxx_cos_lookup_fn(u31i);
    }

    res >>= (31 - qbit);
    return s ? -res : res;
}

int_fast32_t _qxx_tan(int_fast32_t x, int8_t qbit)
{
    const _qxx_t sin = _qxx_sin_cos(x, qbit, 0, 0);
    const _qxx_t cos = _qxx_sin_cos(x, qbit, 1, 0);
    return _qxx_div(sin, cos, 0, qbit);
}
