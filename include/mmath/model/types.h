#ifndef MMATH_MODEL_TYPES_H_
#define MMATH_MODEL_TYPES_H_

#include <mmath/qxx.h>


typedef struct {
    _qxx_t R;
    _qxx_t L;
    _qxx_t Ts;
}motor_obj;

#define MOTOR_OBJ_INIT(_R, _L, _Ts) \
    { .R = Q(_R), .L = Q(_L), .Ts = Q(_Ts) }

#define MOTOR_OBJ_DEFINE(name, _R, _L, _Ts) \
    motor_obj name = MOTOR_OBJ_INIT(_R, _L, _Ts)

#endif // MMATH_MODEL_TYPES_H_
