#ifndef MMATH_SIGNAL_PI_CONTROL_H_
#define MMATH_SIGNAL_PI_CONTROL_H_

#include <mmath/qxx.h>


typedef struct {
    _qxx_t kp;
    _qxx_t ki;
    _qxx_t maxerr;
    _qxx_t minerr;
    _qxx_t _errsum;
    _qxx_t _tmp[2];    
}pid_param;

#define PI_PARAM_INIT(_kp, _ki, max, min) \
    { .kp = Q(_kp), .ki = Q(_ki), .maxerr = Q(max), \
      .minerr = Q(min) }

#define PI_PARAM_DEFINE(name, _kp, _ki, max, min) \
    pid_param name = PI_PARAM_INIT(_kp, _ki, max, min)

static inline
_qxx_t _qxx_pi_control(pid_param *param, _qxx_t measured, _qxx_t target)
{
    int_fast32_t err = target - measured;

    param->_errsum += err;
    param->_errsum = Qsat(param->_errsum, param->maxerr, param->minerr);
    param->_tmp[0] = Qmul(param->kp, err);
    param->_tmp[1] = Qmul(param->ki, param->_errsum);

    return param->_tmp[0] + param->_tmp[1];
}

#define pi_control(param_ptr, measured, target) \
    _qxx_pi_control(param_ptr, Q(measured), Q(target))

#endif // MMATH_SIGNAL_PI_CONTROL_H_
