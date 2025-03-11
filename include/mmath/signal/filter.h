#ifndef MMATH_SIGNAL_FILTER_H_
#define MMATH_SIGNAL_FILTER_H_

#include <mmath/qxx.h>


static inline
_qxx_t _q16_low_pass_filter(_qxx_t measured, _qxx_t alpha, _qxx_t *last)
{
    _qxx_t out = *last + Qmul(alpha, measured - (*last));
    *last = out;
    return out;
}

#define low_pass_filter(measured, alpha, last_out_ptr) \
    _q15_low_pass_filter(Q(measured), Q(alpha), last_out_ptr)

#endif // MMATH_SIGNAL_FILTER_H_
