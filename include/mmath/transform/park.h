#ifndef MMATH_TRANSFORM_PARK_H_
#define MMATH_TRANSFORM_PARK_H_

#include <mmath/qxx.h>
#include <mmath/types.h>


static inline void _qxx_park_direct(ab_t ab, _qxx_t theta, dq_t *dq)
{
    theta = Qmul(theta, Qsdiv(Q_PI, Q(180)));
    dq->d = Qmul(ab.alpha, Qcos(theta)) + Qmul(ab.beta, Qsin(theta));
    dq->q = Qmul(-ab.alpha, Qsin(theta)) + Qmul(ab.beta, Qcos(theta));
}

static inline void _qxx_park_invert(dq_t dq, _qxx_t theta, ab_t *ab)
{
    theta = Qmul(theta, Qsdiv(Q_PI, Q(180)));
    ab->alpha = Qmul(dq.d, Qcos(theta)) - Qmul(dq.q, Qsin(theta));
    ab->beta = Qmul(dq.d, Qsin(theta)) + Qmul(dq.q, Qcos(theta));
}

#define park_direct(ab, theta, dq_ptr) \
    _qxx_park_direct(ab, Q(theta), dq_ptr)

#define park_invert(dq, theta, ab_ptr) \
    _qxx_park_invert(dq, Q(theta), ab_ptr)


#endif // MMATH_TRANSFORM_PARK_H_
