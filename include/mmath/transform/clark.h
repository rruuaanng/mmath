#ifndef MMATH_TRANSFORM_CLARK_H_
#define MMATH_TRANSFORM_CLARK_H_

#include <mmath/qxx.h>
#include <mmath/types.h>


static inline void _qxx_clark_direct(phase_t p, ab_t *ab)
{
    int_fast32_t tmp1, tmp2;
    ab->alpha = p.ia;
    tmp1 = Qsdiv(Qmul(Q_SQRT3, p.ia), Q(3));
    tmp2 = Qsdiv(Qmul(Q_2SQRT3, p.ib), Q(3));
    ab->beta = tmp1 + tmp2;
}

static inline void _qxx_clark_invert(ab_t ab, phase_t *p)
{
    p->ia = ab.alpha;
    p->ib = Qsdiv(-ab.alpha + Qmul(Q_SQRT3, ab.beta), Q(2));
    p->ic = Qsdiv(-ab.alpha - Qmul(Q_SQRT3, ab.beta), Q(2));
}

#define clark_direct(p, ab_ptr) \
    _qxx_clark_direct(p, ab_ptr)

#define clark_invert(ab, p_ptr) \
    _qxx_clark_invert(ab, p_ptr)

#endif // MMATH_TRANSFORM_CLARK_H_
