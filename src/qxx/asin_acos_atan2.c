#include <mmath/qxx.h>



const int_fast32_t asin_lookup[17][5] = {
    {  3149732,   89392309,       962, 536870908,       0},
    {  9526495,   88593699,     40416, 536870004,       8},
    { 16138900,   86937495,    197996, 536863257,     118},
    { 23156787,   84300941,    571586, 536839597,     683},
    { 30770290,   80487362,   1290238, 536779215,    2591},
    { 39200158,   75209531,   2531955, 536649108,    7714},
    { 48710843,   68064494,   4547783, 536395980,   19650},
    { 59627725,   58496679,   7695660, 535935197,   44970},
    { 72359850,   45744506,  12489135, 535133733,   95261},
    { 87431720,   28762778,  19668817, 533783769,  190507},
    {105527689,    6109335,  30308851, 531561517,  364646},
    {127555573,  -24222672,  45978054, 527962405,  674787},
    {154739551,  -65056242,  68987651, 522197749, 1216568},
    {188758701, -120414117, 102778528, 513027743, 2150044},
    {231956922, -196114786, 152538402, 498486871, 3743891},
    {287669673, -300718733, 226205346, 475423960, 6452123},
    {287669673, -300718733, 226205346, 475423960, 6452123}
};

int_fast32_t _qxx_asin(int_fast32_t x, const int8_t qbit)
{
    uint8_t sign = 0;
    uint_fast16_t i;
    int_fast32_t res;
    const int_fast32_t *coef;
    uint_fast32_t u31i;
    uint_fast32_t u31t;

    if (x < 0) {
        sign |= 1;
        x = -x;
    }

    if (x > ((uint_fast32_t)1 << qbit)) {
        return 0;
    }

    u31i = (uint_fast32_t)x << (31 - qbit);
    u31t = 0x80000000 - u31i;
    if (u31t < 0x40000000) {
        u31i = u31t >> 1;
        u31i = _qxx_sqrt(u31i, 0, 31, 1);
        sign |= 2;
    }

    i = (int_fast16_t)(u31i >> 26) & 0x003f;
    coef = asin_lookup[i];
    res = _L(u31i, *coef++);
    res = res + *coef++;
    res = _L(u31i, res);
    res = res + *coef++;
    res = _L(u31i, res);
    res = res + *coef++;
    res = _L(u31i, res);
    res = res + *coef++;

    if (sign & 2) {
        res = res << 1;
        res -= 0x3243F6A8;
        res = -res;
    }

    res >>= 29 - qbit;
    return sign & 1 ? -res : res;
}

int_fast32_t _qxx_acos(int_fast32_t x, int8_t qbit)
{
    const _qxx_t pi2 = FtoQXX(1.570796326794896, qbit);
    const int_fast32_t asin = _qxx_asin(x, qbit);
    return pi2 - asin;
}

int_fast32_t _qxx_atan2(int_fast32_t y, int_fast32_t x, int8_t qbit)
{
    const _qxx_t tmp1 = _qxx_mul(y, y, qbit);
    const _qxx_t tmp2 = _qxx_mul(x, x, qbit);
    const _qxx_t r = _qxx_sqrt((tmp1 + tmp2), 0, qbit, 1);
    _qxx_t res, pi;

    if (x == 0) { return Q_PI2; }
    if (y == 0) { return Q_PI; }

    if (x > 0) {
        return _qxx_asin(_qxx_div(y, r, 0, qbit), qbit);
    }
    if (x < 0) {
        pi = y > 0 ? FtoQXX(3.141592653589, qbit)
                   : FtoQXX(-3.141592653589, qbit);
        res = _qxx_asin(_qxx_div(y, r, 0, qbit), qbit);
        return pi - res;
    }

    return 0;
}
