#ifndef MMATH_TRANSFORM_TYPES_H_
#define MMATH_TRANSFORM_TYPES_H_

#include <mmath/qxx.h>
#include <stdbool.h>

#ifndef NULL
# define NULL ((void *)0)
#endif /* NULL */


typedef struct {
    _qxx_t ia;
    _qxx_t ib;
    _qxx_t ic;
}phase_t;

#define PHASE_INIT(_ia, _ib, _ic)     \
    { .ia = Q(_ia), .ib = Q(_ib), \
      .ic = Q(_ic) }

#define PHASE_DEFINE(name, _ia, _ib, _ic) \
    phase_t name = PHASE_INIT(_ia, _ib, _ic)

typedef struct {
    _qxx_t alpha;
    _qxx_t beta;
}ab_t;

#define AB_INIT(_alpha, _beta) \
    { .alpha = Q(_alpha), .beta = Q(_beta) }

#define AB_DEFINE(name, _alpha, _beta)  \
    ab_t name = AB_INIT(_alpha, _beta)


typedef struct {
    _qxx_t d;
    _qxx_t q;
}dq_t;

#define DQ_INIT(_d, _q) \
    { .d = Q(_d), .q = Q(_q) }

#define DQ_DEFINE(name, _d, _q) \
    ab_t name = DQ_INIT(_d, _q)

#endif // MMATH_TRANSFORM_TYPES_H_
