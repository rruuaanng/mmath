#ifndef MMATH_MODEL_PMSM_H_
#define MMATH_MODEL_PMSM_H_

#include <mmath/qxx.h>
#include <mmath/model/types.h>


static inline _qxx_t F(_qxx_t R, _qxx_t L, _qxx_t ts)
{
    return Q(1) - Qmul(ts, Qsdiv(R, L));
}

static inline _qxx_t G(_qxx_t L, _qxx_t ts)
{
    return Qsdiv(ts, L);
}

static inline _qxx_t R(_qxx_t i, _qxx_t v, _qxx_t b_emf)
{
    return Qsdiv((v - b_emf), i);
}

static inline _qxx_t L(_qxx_t R, _qxx_t i, _qxx_t i_next,
                       _qxx_t v,_qxx_t b_emf)
{
    const _qxx_t dt = i_next - i;
    return Qsdiv((Qmul(R, i) + (v - b_emf)), dt);
}

static inline
_qxx_t _qxx_motor_current_model(motor_obj m, _qxx_t i, _qxx_t v, _qxx_t b_emf)
{
    const _qxx_t f = F(m.R, m.L, m.Ts);
    const _qxx_t g = G(m.L, m.Ts);
    return Qmul(f, i) + Qmul(g, (v - b_emf));
}

#define pmsm_motor_next_tick_current(m, i, v, b_emf) \
    _qxx_motor_current_model(m, Q(i), Q(v), Q(b_emf))

static inline
_qxx_t _qxx_motor_voltage_model(motor_obj m, _qxx_t i, _qxx_t i_next, _qxx_t b_emf)
{
    const _qxx_t dt = Qsdiv((i_next - i), m.Ts);
    return Qmul(m.R, i) + Qmul(m.L, dt) + b_emf;
}

#define pmsm_motor_now_tick_voltage(m, i, i_next, b_emf) \
    _qxx_motor_voltage_model(m, Q(i), Q(i_next), Q(b_emf))

#endif // MMATH_MODEL_PMSM_H_
