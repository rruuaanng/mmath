#ifndef MMATH_MODULATION_SVPWM_H_
#define MMATH_MODULATION_SVPWM_H_

#include <mmath/qxx.h>
#include <mmath/types.h>


typedef struct {
    _qxx_t Ta;
    _qxx_t Tb;
    _qxx_t Tc;
}svpwm_timer_out;

/* N => sector */
#define SECTOR_1     0x03
#define SECTOR_2     0x01
#define SECTOR_3     0x05
#define SECTOR_4     0x04
#define SECTOR_5     0x06
#define SECTOR_6     0x02

static inline int N(int a, int b, int c)
{
    return a + 2 * b + 4 * c;
}

static inline _qxx_t Uref1(ab_t ab) /* A */
{
    return ab.beta;
}

static inline _qxx_t Uref2(ab_t ab) /* B */
{
    return Qdiv2(ab.beta) + Qmul(ab.alpha, Q_2HALF_SQRT3);
}

static inline _qxx_t Uref3(ab_t ab) /* C */
{
    return Uref2(ab) - Uref1(ab);
}

static inline _qxx_t K(_qxx_t ts, _qxx_t Udc)
{
    return Qsdiv(Qmul(Q_SQRT3, ts), Udc);
}

static inline int svpwm_sector_lookup(ab_t ab)
{
    const _qxx_t u1 = Uref1(ab);
    const _qxx_t u2 = Uref2(ab);
    const _qxx_t u3 = Uref3(ab);
    int sector = 3;

    sector = u2 > 0 ? sector - 1 : sector;
    sector = u3 > 0 ? sector - 1 : sector;
    sector = u1 < 0 ? 7 - sector : sector;
    return sector;
}

static inline int svpwm_gen_pwm_timer(ab_t ab, svpwm_timer_out *out)
{
    const _qxx_t u1 = Uref1(ab);
    const _qxx_t u2 = Uref2(ab);
    const _qxx_t u3 = Uref3(ab);
    const int n = svpwm_sector_lookup(ab);

    switch (n){
    case 1:
    case 4:
        out->Ta = u2;
        out->Tb = u1 - u3;
        out->Tc = -u2;
        return 0;
    case 2:
    case 5:
        out->Ta = u2 + u3;
        out->Tb = u1;
        out->Tc = -u1;
        return 0;
    default:
        out->Ta = u3;
        out->Tb = -u3;
        out->Tc = -(u1 + u2);
        return 0;
    }

    return 1;
}

#endif // MMATH_MODULATION_SVPWM_H_
