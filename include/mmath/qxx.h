#ifndef MMATH_QXX_H_
#define MMATH_QXX_H_

/* standard library */
#include <limits.h>
#include <stdint.h>

/* Configure */
#ifndef CONFIG_QXX_FORMAT
# define CONFIG_QXX_FORMAT 18
#endif /* CONFIG_QXX_FORMAT */

/* Q-format */
typedef int32_t _qxx_t;

/* ----------------------------------------------------------- */
/*                     Conversion functions                    */
/* ----------------------------------------------------------- */

#define FtoQXX(x, qbit) ((_qxx_t)((x) * ((_qxx_t)1U << (qbit))))
#define Q30(x)          FtoQXX(x, 30)
#define Q29(x)          FtoQXX(x, 29)
#define Q28(x)          FtoQXX(x, 28)
#define Q27(x)          FtoQXX(x, 27)
#define Q26(x)          FtoQXX(x, 26)
#define Q25(x)          FtoQXX(x, 25)
#define Q24(x)          FtoQXX(x, 24)
#define Q23(x)          FtoQXX(x, 23)
#define Q22(x)          FtoQXX(x, 22)
#define Q21(x)          FtoQXX(x, 21)
#define Q20(x)          FtoQXX(x, 20)
#define Q19(x)          FtoQXX(x, 19)
#define Q18(x)          FtoQXX(x, 18)
#define Q17(x)          FtoQXX(x, 17)
#define Q16(x)          FtoQXX(x, 16)
#define Q15(x)          FtoQXX(x, 15)
#define Q14(x)          FtoQXX(x, 14)
#define Q13(x)          FtoQXX(x, 13)
#define Q12(x)          FtoQXX(x, 12)
#define Q11(x)          FtoQXX(x, 11)
#define Q10(x)          FtoQXX(x, 10)
#define Q9(x)           FtoQXX(x, 9)
#define Q8(x)           FtoQXX(x, 8)

extern float _qxx_to_float(int_fast32_t x, int8_t qbit);

#define Q30toF(x) _qxx_to_float(x, 30)
#define Q29toF(x) _qxx_to_float(x, 29)
#define Q28toF(x) _qxx_to_float(x, 28)
#define Q27toF(x) _qxx_to_float(x, 27)
#define Q26toF(x) _qxx_to_float(x, 26)
#define Q25toF(x) _qxx_to_float(x, 25)
#define Q24toF(x) _qxx_to_float(x, 24)
#define Q23toF(x) _qxx_to_float(x, 23)
#define Q22toF(x) _qxx_to_float(x, 22)
#define Q21toF(x) _qxx_to_float(x, 21)
#define Q20toF(x) _qxx_to_float(x, 20)
#define Q19toF(x) _qxx_to_float(x, 19)
#define Q18toF(x) _qxx_to_float(x, 18)
#define Q17toF(x) _qxx_to_float(x, 17)
#define Q16toF(x) _qxx_to_float(x, 16)
#define Q15toF(x) _qxx_to_float(x, 15)
#define Q14toF(x) _qxx_to_float(x, 14)
#define Q13toF(x) _qxx_to_float(x, 13)
#define Q12toF(x) _qxx_to_float(x, 12)
#define Q11toF(x) _qxx_to_float(x, 11)
#define Q10toF(x) _qxx_to_float(x, 10)
#define Q9toF(x)  _qxx_to_float(x, 9)
#define Q8toF(x)  _qxx_to_float(x, 8)

/* ----------------------------------------------------------- */
/*         Simple bitwise multiplication and division          */
/* ----------------------------------------------------------- */
#define Qmul2(x)  ((x) << 1U)
#define Qmul4(x)  ((x) << 2U)
#define Qmul8(x)  ((x) << 3U)
#define Qmul16(x) ((x) << 4U)
#define Qmul32(x) ((x) << 5U)
#define Qmul64(x) ((x) << 6U)

#define Qdiv2(x)  ((x) >> 1U)
#define Qdiv4(x)  ((x) >> 2U)
#define Qdiv8(x)  ((x) >> 3U)
#define Qdiv16(x) ((x) >> 4U)
#define Qdiv32(x) ((x) >> 5U)
#define Qdiv64(x) ((x) >> 6U)

/* ----------------------------------------------------------- */
/*                      Helper functions                       */
/* ----------------------------------------------------------- */

#define Qsat(x, max, min) (((x) > (max))    \
                           ? (max)          \
                           : (((x) < (min)) \
                           ? (min) : (x)))

#define Qabs(x)  (((x) < 0) ? -(x) : (x))

#define Qneg(x)  (((x) > 0) ? -(x) : (x))

#define Qsym(x)  ((x) & 0x80000000 ? (1) : (0))

#define Qsign(x) ((x) > (0) ? (1) : (x) < (0) ? (-1) : (0))

/* ----------------------------------------------------------- */
/*             Multiplication and division functions           */
/* ----------------------------------------------------------- */

extern int_fast32_t _qxx_mul(int_fast32_t x1, int_fast32_t x2,
                             int8_t qbit);

#define Q30mul(x1, x2) _qxx_mul(x1, x2, 30)
#define Q29mul(x1, x2) _qxx_mul(x1, x2, 29)
#define Q28mul(x1, x2) _qxx_mul(x1, x2, 28)
#define Q27mul(x1, x2) _qxx_mul(x1, x2, 27)
#define Q26mul(x1, x2) _qxx_mul(x1, x2, 26)
#define Q25mul(x1, x2) _qxx_mul(x1, x2, 25)
#define Q24mul(x1, x2) _qxx_mul(x1, x2, 24)
#define Q23mul(x1, x2) _qxx_mul(x1, x2, 23)
#define Q22mul(x1, x2) _qxx_mul(x1, x2, 22)
#define Q21mul(x1, x2) _qxx_mul(x1, x2, 21)
#define Q20mul(x1, x2) _qxx_mul(x1, x2, 20)
#define Q19mul(x1, x2) _qxx_mul(x1, x2, 19)
#define Q18mul(x1, x2) _qxx_mul(x1, x2, 18)
#define Q17mul(x1, x2) _qxx_mul(x1, x2, 17)
#define Q16mul(x1, x2) _qxx_mul(x1, x2, 16)
#define Q15mul(x1, x2) _qxx_mul(x1, x2, 15)
#define Q14mul(x1, x2) _qxx_mul(x1, x2, 14)
#define Q13mul(x1, x2) _qxx_mul(x1, x2, 13)
#define Q12mul(x1, x2) _qxx_mul(x1, x2, 12)
#define Q11mul(x1, x2) _qxx_mul(x1, x2, 11)
#define Q10mul(x1, x2) _qxx_mul(x1, x2, 10)
#define Q9mul(x1, x2)  _qxx_mul(x1, x2, 9)
#define Q8mul(x1, x2)  _qxx_mul(x1, x2, 8)

extern int_fast32_t _qxx_div(int_fast32_t x1, int_fast32_t x2,
                             uint8_t type, int8_t qbit);

#define Q30udiv(x1, x2) _qxx_div(x1, x2, 1, 30)
#define Q29udiv(x1, x2) _qxx_div(x1, x2, 1, 29)
#define Q28udiv(x1, x2) _qxx_div(x1, x2, 1, 28)
#define Q27udiv(x1, x2) _qxx_div(x1, x2, 1, 27)
#define Q26udiv(x1, x2) _qxx_div(x1, x2, 1, 26)
#define Q25udiv(x1, x2) _qxx_div(x1, x2, 1, 25)
#define Q24udiv(x1, x2) _qxx_div(x1, x2, 1, 24)
#define Q23udiv(x1, x2) _qxx_div(x1, x2, 1, 23)
#define Q22udiv(x1, x2) _qxx_div(x1, x2, 1, 22)
#define Q21udiv(x1, x2) _qxx_div(x1, x2, 1, 21)
#define Q20udiv(x1, x2) _qxx_div(x1, x2, 1, 20)
#define Q19udiv(x1, x2) _qxx_div(x1, x2, 1, 19)
#define Q18udiv(x1, x2) _qxx_div(x1, x2, 1, 18)
#define Q17udiv(x1, x2) _qxx_div(x1, x2, 1, 17)
#define Q16udiv(x1, x2) _qxx_div(x1, x2, 1, 16)
#define Q15udiv(x1, x2) _qxx_div(x1, x2, 1, 15)
#define Q14udiv(x1, x2) _qxx_div(x1, x2, 1, 14)
#define Q13udiv(x1, x2) _qxx_div(x1, x2, 1, 13)
#define Q12udiv(x1, x2) _qxx_div(x1, x2, 1, 12)
#define Q11udiv(x1, x2) _qxx_div(x1, x2, 1, 11)
#define Q10udiv(x1, x2) _qxx_div(x1, x2, 1, 10)
#define Q9udiv(x1, x2)  _qxx_div(x1, x2, 1, 9)
#define Q8udiv(x1, x2)  _qxx_div(x1, x2, 1, 8)

#define Q30sdiv(x1, x2) _qxx_div(x1, x2, 0, 30)
#define Q29sdiv(x1, x2) _qxx_div(x1, x2, 0, 29)
#define Q28sdiv(x1, x2) _qxx_div(x1, x2, 0, 28)
#define Q27sdiv(x1, x2) _qxx_div(x1, x2, 0, 27)
#define Q26sdiv(x1, x2) _qxx_div(x1, x2, 0, 26)
#define Q25sdiv(x1, x2) _qxx_div(x1, x2, 0, 25)
#define Q24sdiv(x1, x2) _qxx_div(x1, x2, 0, 24)
#define Q23sdiv(x1, x2) _qxx_div(x1, x2, 0, 23)
#define Q22sdiv(x1, x2) _qxx_div(x1, x2, 0, 22)
#define Q21sdiv(x1, x2) _qxx_div(x1, x2, 0, 21)
#define Q20sdiv(x1, x2) _qxx_div(x1, x2, 0, 20)
#define Q19sdiv(x1, x2) _qxx_div(x1, x2, 0, 19)
#define Q18sdiv(x1, x2) _qxx_div(x1, x2, 0, 18)
#define Q17sdiv(x1, x2) _qxx_div(x1, x2, 0, 17)
#define Q16sdiv(x1, x2) _qxx_div(x1, x2, 0, 16)
#define Q15sdiv(x1, x2) _qxx_div(x1, x2, 0, 15)
#define Q14sdiv(x1, x2) _qxx_div(x1, x2, 0, 14)
#define Q13sdiv(x1, x2) _qxx_div(x1, x2, 0, 13)
#define Q12sdiv(x1, x2) _qxx_div(x1, x2, 0, 12)
#define Q11sdiv(x1, x2) _qxx_div(x1, x2, 0, 11)
#define Q10sdiv(x1, x2) _qxx_div(x1, x2, 0, 10)
#define Q9sdiv(x1, x2)  _qxx_div(x1, x2, 0, 9)
#define Q8sdiv(x1, x2)  _qxx_div(x1, x2, 0, 8)

/* ----------------------------------------------------------- */
/*                       Basic functions                       */
/* ----------------------------------------------------------- */

static inline int_fast32_t _qxx_frac(int_fast32_t x, int8_t qbit)
{
    return (x - ((uint_fast32_t)x & ((uint_fast32_t)0xFFFFFFFF << qbit)));
}
#define Q30frac(x) _qxx_frac(x, 30)
#define Q29frac(x) _qxx_frac(x, 29)
#define Q28frac(x) _qxx_frac(x, 28)
#define Q27frac(x) _qxx_frac(x, 27)
#define Q26frac(x) _qxx_frac(x, 26)
#define Q25frac(x) _qxx_frac(x, 25)
#define Q24frac(x) _qxx_frac(x, 24)
#define Q23frac(x) _qxx_frac(x, 23)
#define Q22frac(x) _qxx_frac(x, 22)
#define Q21frac(x) _qxx_frac(x, 21)
#define Q20frac(x) _qxx_frac(x, 20)
#define Q19frac(x) _qxx_frac(x, 19)
#define Q18frac(x) _qxx_frac(x, 18)
#define Q17frac(x) _qxx_frac(x, 17)
#define Q16frac(x) _qxx_frac(x, 16)
#define Q15frac(x) _qxx_frac(x, 15)
#define Q14frac(x) _qxx_frac(x, 14)
#define Q13frac(x) _qxx_frac(x, 13)
#define Q12frac(x) _qxx_frac(x, 12)
#define Q11frac(x) _qxx_frac(x, 11)
#define Q10frac(x) _qxx_frac(x, 10)
#define Q9frac(x)  _qxx_frac(x, 9)
#define Q8frac(x)  _qxx_frac(x, 8)

extern int_fast32_t _qxx_sqrt(int_fast32_t x, int_fast32_t y,
                              int8_t qbit, int8_t type);

#define Qmsqrt(x, y)  _qxx_sqrt(x, y, 31, 2)

#define Q30rsqrt(x)  _qxx_sqrt(x, 0, 30, 0)
#define Q29rsqrt(x)  _qxx_sqrt(x, 0, 29, 0)
#define Q28rsqrt(x)  _qxx_sqrt(x, 0, 28, 0)
#define Q27rsqrt(x)  _qxx_sqrt(x, 0, 27, 0)
#define Q26rsqrt(x)  _qxx_sqrt(x, 0, 26, 0)
#define Q25rsqrt(x)  _qxx_sqrt(x, 0, 25, 0)
#define Q24rsqrt(x)  _qxx_sqrt(x, 0, 24, 0)
#define Q23rsqrt(x)  _qxx_sqrt(x, 0, 23, 0)
#define Q22rsqrt(x)  _qxx_sqrt(x, 0, 22, 0)
#define Q21rsqrt(x)  _qxx_sqrt(x, 0, 21, 0)
#define Q20rsqrt(x)  _qxx_sqrt(x, 0, 20, 0)
#define Q19rsqrt(x)  _qxx_sqrt(x, 0, 19, 0)
#define Q18rsqrt(x)  _qxx_sqrt(x, 0, 18, 0)
#define Q17rsqrt(x)  _qxx_sqrt(x, 0, 17, 0)
#define Q16rsqrt(x)  _qxx_sqrt(x, 0, 16, 0)
#define Q15rsqrt(x)  _qxx_sqrt(x, 0, 15, 0)
#define Q14rsqrt(x)  _qxx_sqrt(x, 0, 14, 0)
#define Q13rsqrt(x)  _qxx_sqrt(x, 0, 13, 0)
#define Q12rsqrt(x)  _qxx_sqrt(x, 0, 12, 0)
#define Q11rsqrt(x)  _qxx_sqrt(x, 0, 11, 0)
#define Q10rsqrt(x)  _qxx_sqrt(x, 0, 10, 0)
#define Q9rsqrt(x)   _qxx_sqrt(x, 0, 9, 0)
#define Q8rsqrt(x)   _qxx_sqrt(x, 0, 8, 0)

#define Q30sqrt(x)   _qxx_sqrt(x, 0, 30, 1)
#define Q29sqrt(x)   _qxx_sqrt(x, 0, 29, 1)
#define Q28sqrt(x)   _qxx_sqrt(x, 0, 28, 1)
#define Q27sqrt(x)   _qxx_sqrt(x, 0, 27, 1)
#define Q26sqrt(x)   _qxx_sqrt(x, 0, 26, 1)
#define Q25sqrt(x)   _qxx_sqrt(x, 0, 25, 1)
#define Q24sqrt(x)   _qxx_sqrt(x, 0, 24, 1)
#define Q23sqrt(x)   _qxx_sqrt(x, 0, 23, 1)
#define Q22sqrt(x)   _qxx_sqrt(x, 0, 22, 1)
#define Q21sqrt(x)   _qxx_sqrt(x, 0, 21, 1)
#define Q20sqrt(x)   _qxx_sqrt(x, 0, 20, 1)
#define Q19sqrt(x)   _qxx_sqrt(x, 0, 19, 1)
#define Q18sqrt(x)   _qxx_sqrt(x, 0, 18, 1)
#define Q17sqrt(x)   _qxx_sqrt(x, 0, 17, 1)
#define Q16sqrt(x)   _qxx_sqrt(x, 0, 16, 1)
#define Q15sqrt(x)   _qxx_sqrt(x, 0, 15, 1)
#define Q14sqrt(x)   _qxx_sqrt(x, 0, 14, 1)
#define Q13sqrt(x)   _qxx_sqrt(x, 0, 13, 1)
#define Q12sqrt(x)   _qxx_sqrt(x, 0, 12, 1)
#define Q11sqrt(x)   _qxx_sqrt(x, 0, 11, 1)
#define Q10sqrt(x)   _qxx_sqrt(x, 0, 10, 1)
#define Q9sqrt(x)    _qxx_sqrt(x, 0, 9, 1)
#define Q8sqrt(x)    _qxx_sqrt(x, 0, 8, 1)

#define Q30imsqrt(x, y) _qxx_sqrt(x, y, 30, 3)
#define Q29imsqrt(x, y) _qxx_sqrt(x, y, 29, 3)
#define Q28imsqrt(x, y) _qxx_sqrt(x, y, 28, 3)
#define Q27imsqrt(x, y) _qxx_sqrt(x, y, 27, 3)
#define Q26imsqrt(x, y) _qxx_sqrt(x, y, 26, 3)
#define Q25imsqrt(x, y) _qxx_sqrt(x, y, 25, 3)
#define Q24imsqrt(x, y) _qxx_sqrt(x, y, 24, 3)
#define Q23imsqrt(x, y) _qxx_sqrt(x, y, 23, 3)
#define Q22imsqrt(x, y) _qxx_sqrt(x, y, 22, 3)
#define Q21imsqrt(x, y) _qxx_sqrt(x, y, 21, 3)
#define Q20imsqrt(x, y) _qxx_sqrt(x, y, 20, 3)
#define Q19imsqrt(x, y) _qxx_sqrt(x, y, 19, 3)
#define Q18imsqrt(x, y) _qxx_sqrt(x, y, 18, 3)
#define Q17imsqrt(x, y) _qxx_sqrt(x, y, 17, 3)
#define Q16imsqrt(x, y) _qxx_sqrt(x, y, 16, 3)
#define Q15imsqrt(x, y) _qxx_sqrt(x, y, 15, 3)
#define Q14imsqrt(x, y) _qxx_sqrt(x, y, 14, 3)
#define Q13imsqrt(x, y) _qxx_sqrt(x, y, 13, 3)
#define Q12imsqrt(x, y) _qxx_sqrt(x, y, 12, 3)
#define Q11imsqrt(x, y) _qxx_sqrt(x, y, 11, 3)
#define Q10imsqrt(x, y) _qxx_sqrt(x, y, 10, 3)
#define Q9imsqrt(x, y)  _qxx_sqrt(x, y, 9, 3)
#define Q8imsqrt(x, y)  _qxx_sqrt(x, y, 8, 3)

extern int_fast32_t _qxx_sin_cos(int_fast32_t x, int8_t qbit,
                                 int8_t type, int8_t format);
extern int_fast32_t _qxx_tan(int_fast32_t x, int8_t qbit);
extern int_fast32_t _qxx_asin(int_fast32_t x, int8_t qbit);
extern int_fast32_t _qxx_acos(int_fast32_t x, int8_t qbit);
extern int_fast32_t _qxx_atan2(int_fast32_t y, int_fast32_t x,
                               int8_t qbit);

#define Q29sin(x)   _qxx_sin_cos(x, 29, 0, 0)
#define Q28sin(x)   _qxx_sin_cos(x, 28, 0, 0)
#define Q27sin(x)   _qxx_sin_cos(x, 27, 0, 0)
#define Q26sin(x)   _qxx_sin_cos(x, 26, 0, 0)
#define Q25sin(x)   _qxx_sin_cos(x, 25, 0, 0)
#define Q24sin(x)   _qxx_sin_cos(x, 24, 0, 0)
#define Q23sin(x)   _qxx_sin_cos(x, 23, 0, 0)
#define Q22sin(x)   _qxx_sin_cos(x, 22, 0, 0)
#define Q21sin(x)   _qxx_sin_cos(x, 21, 0, 0)
#define Q20sin(x)   _qxx_sin_cos(x, 20, 0, 0)
#define Q19sin(x)   _qxx_sin_cos(x, 19, 0, 0)
#define Q18sin(x)   _qxx_sin_cos(x, 18, 0, 0)
#define Q17sin(x)   _qxx_sin_cos(x, 17, 0, 0)
#define Q16sin(x)   _qxx_sin_cos(x, 16, 0, 0)
#define Q15sin(x)   _qxx_sin_cos(x, 15, 0, 0)
#define Q14sin(x)   _qxx_sin_cos(x, 14, 0, 0)
#define Q13sin(x)   _qxx_sin_cos(x, 13, 0, 0)
#define Q12sin(x)   _qxx_sin_cos(x, 12, 0, 0)
#define Q11sin(x)   _qxx_sin_cos(x, 11, 0, 0)
#define Q10sin(x)   _qxx_sin_cos(x, 10, 0, 0)
#define Q9sin(x)    _qxx_sin_cos(x, 9, 0, 0)
#define Q8sin(x)    _qxx_sin_cos(x, 8, 0, 0)

#define Q29cos(x)   _qxx_sin_cos(x, 29, 1, 0)
#define Q28cos(x)   _qxx_sin_cos(x, 28, 1, 0)
#define Q27cos(x)   _qxx_sin_cos(x, 27, 1, 0)
#define Q26cos(x)   _qxx_sin_cos(x, 26, 1, 0)
#define Q25cos(x)   _qxx_sin_cos(x, 25, 1, 0)
#define Q24cos(x)   _qxx_sin_cos(x, 24, 1, 0)
#define Q23cos(x)   _qxx_sin_cos(x, 23, 1, 0)
#define Q22cos(x)   _qxx_sin_cos(x, 22, 1, 0)
#define Q21cos(x)   _qxx_sin_cos(x, 21, 1, 0)
#define Q20cos(x)   _qxx_sin_cos(x, 20, 1, 0)
#define Q19cos(x)   _qxx_sin_cos(x, 19, 1, 0)
#define Q18cos(x)   _qxx_sin_cos(x, 18, 1, 0)
#define Q17cos(x)   _qxx_sin_cos(x, 17, 1, 0)
#define Q16cos(x)   _qxx_sin_cos(x, 16, 1, 0)
#define Q15cos(x)   _qxx_sin_cos(x, 15, 1, 0)
#define Q14cos(x)   _qxx_sin_cos(x, 14, 1, 0)
#define Q13cos(x)   _qxx_sin_cos(x, 13, 1, 0)
#define Q12cos(x)   _qxx_sin_cos(x, 12, 1, 0)
#define Q11cos(x)   _qxx_sin_cos(x, 11, 1, 0)
#define Q10cos(x)   _qxx_sin_cos(x, 10, 1, 0)
#define Q9cos(x)    _qxx_sin_cos(x, 9, 1, 0)
#define Q8cos(x)    _qxx_sin_cos(x, 8, 1, 0)

#define Q29tan(x)   _qxx_tan(x, 29)
#define Q28tan(x)   _qxx_tan(x, 28)
#define Q27tan(x)   _qxx_tan(x, 27)
#define Q26tan(x)   _qxx_tan(x, 26)
#define Q25tan(x)   _qxx_tan(x, 25)
#define Q24tan(x)   _qxx_tan(x, 24)
#define Q23tan(x)   _qxx_tan(x, 23)
#define Q22tan(x)   _qxx_tan(x, 22)
#define Q21tan(x)   _qxx_tan(x, 21)
#define Q20tan(x)   _qxx_tan(x, 20)
#define Q19tan(x)   _qxx_tan(x, 19)
#define Q18tan(x)   _qxx_tan(x, 18)
#define Q17tan(x)   _qxx_tan(x, 17)
#define Q16tan(x)   _qxx_tan(x, 16)
#define Q15tan(x)   _qxx_tan(x, 15)
#define Q14tan(x)   _qxx_tan(x, 14)
#define Q13tan(x)   _qxx_tan(x, 13)
#define Q12tan(x)   _qxx_tan(x, 12)
#define Q11tan(x)   _qxx_tan(x, 11)
#define Q10tan(x)   _qxx_tan(x, 10)
#define Q9tan(x)    _qxx_tan(x, 9)
#define Q8tan(x)    _qxx_tan(x, 8)

#define Q29sinPU(x) _qxx_sin_cos(x, 29, 0, 1)
#define Q28sinPU(x) _qxx_sin_cos(x, 28, 0, 1)
#define Q27sinPU(x) _qxx_sin_cos(x, 27, 0, 1)
#define Q26sinPU(x) _qxx_sin_cos(x, 26, 0, 1)
#define Q25sinPU(x) _qxx_sin_cos(x, 25, 0, 1)
#define Q24sinPU(x) _qxx_sin_cos(x, 24, 0, 1)
#define Q23sinPU(x) _qxx_sin_cos(x, 23, 0, 1)
#define Q22sinPU(x) _qxx_sin_cos(x, 22, 0, 1)
#define Q21sinPU(x) _qxx_sin_cos(x, 21, 0, 1)
#define Q20sinPU(x) _qxx_sin_cos(x, 20, 0, 1)
#define Q19sinPU(x) _qxx_sin_cos(x, 19, 0, 1)
#define Q18sinPU(x) _qxx_sin_cos(x, 18, 0, 1)
#define Q17sinPU(x) _qxx_sin_cos(x, 17, 0, 1)
#define Q16sinPU(x) _qxx_sin_cos(x, 16, 0, 1)
#define Q15sinPU(x) _qxx_sin_cos(x, 15, 0, 1)
#define Q14sinPU(x) _qxx_sin_cos(x, 14, 0, 1)
#define Q13sinPU(x) _qxx_sin_cos(x, 13, 0, 1)
#define Q12sinPU(x) _qxx_sin_cos(x, 12, 0, 1)
#define Q11sinPU(x) _qxx_sin_cos(x, 11, 0, 1)
#define Q10sinPU(x) _qxx_sin_cos(x, 10, 0, 1)
#define Q9sinPU(x)  _qxx_sin_cos(x, 9, 0, 1)
#define Q8sinPU(x)  _qxx_sin_cos(x, 8, 0, 1)

#define Q29cosPU(x) _qxx_sin_cos(x, 29, 1, 1)
#define Q28cosPU(x) _qxx_sin_cos(x, 28, 1, 1)
#define Q27cosPU(x) _qxx_sin_cos(x, 27, 1, 1)
#define Q26cosPU(x) _qxx_sin_cos(x, 26, 1, 1)
#define Q25cosPU(x) _qxx_sin_cos(x, 25, 1, 1)
#define Q24cosPU(x) _qxx_sin_cos(x, 24, 1, 1)
#define Q23cosPU(x) _qxx_sin_cos(x, 23, 1, 1)
#define Q22cosPU(x) _qxx_sin_cos(x, 22, 1, 1)
#define Q21cosPU(x) _qxx_sin_cos(x, 21, 1, 1)
#define Q20cosPU(x) _qxx_sin_cos(x, 20, 1, 1)
#define Q19cosPU(x) _qxx_sin_cos(x, 19, 1, 1)
#define Q18cosPU(x) _qxx_sin_cos(x, 18, 1, 1)
#define Q17cosPU(x) _qxx_sin_cos(x, 17, 1, 1)
#define Q16cosPU(x) _qxx_sin_cos(x, 16, 1, 1)
#define Q15cosPU(x) _qxx_sin_cos(x, 15, 1, 1)
#define Q14cosPU(x) _qxx_sin_cos(x, 14, 1, 1)
#define Q13cosPU(x) _qxx_sin_cos(x, 13, 1, 1)
#define Q12cosPU(x) _qxx_sin_cos(x, 12, 1, 1)
#define Q11cosPU(x) _qxx_sin_cos(x, 11, 1, 1)
#define Q10cosPU(x) _qxx_sin_cos(x, 10, 1, 1)
#define Q9cosPU(x)  _qxx_sin_cos(x, 9, 1, 1)
#define Q8cosPU(x)  _qxx_sin_cos(x, 8, 1, 1)

#define Q29asin(x) _qxx_asin(x, 29)
#define Q28asin(x) _qxx_asin(x, 28)
#define Q27asin(x) _qxx_asin(x, 27)
#define Q26asin(x) _qxx_asin(x, 26)
#define Q25asin(x) _qxx_asin(x, 25)
#define Q24asin(x) _qxx_asin(x, 24)
#define Q23asin(x) _qxx_asin(x, 23)
#define Q22asin(x) _qxx_asin(x, 22)
#define Q21asin(x) _qxx_asin(x, 21)
#define Q20asin(x) _qxx_asin(x, 20)
#define Q19asin(x) _qxx_asin(x, 19)
#define Q18asin(x) _qxx_asin(x, 18)
#define Q17asin(x) _qxx_asin(x, 17)
#define Q16asin(x) _qxx_asin(x, 16)
#define Q15asin(x) _qxx_asin(x, 15)
#define Q14asin(x) _qxx_asin(x, 14)
#define Q13asin(x) _qxx_asin(x, 13)
#define Q12asin(x) _qxx_asin(x, 12)
#define Q11asin(x) _qxx_asin(x, 11)
#define Q10asin(x) _qxx_asin(x, 10)
#define Q9asin(x)  _qxx_asin(x, 9)
#define Q8asin(x)  _qxx_asin(x, 8)

#define Q29acos(x) _qxx_acos(x, 29)
#define Q28acos(x) _qxx_acos(x, 28)
#define Q27acos(x) _qxx_acos(x, 27)
#define Q26acos(x) _qxx_acos(x, 26)
#define Q25acos(x) _qxx_acos(x, 25)
#define Q24acos(x) _qxx_acos(x, 24)
#define Q23acos(x) _qxx_acos(x, 23)
#define Q22acos(x) _qxx_acos(x, 22)
#define Q21acos(x) _qxx_acos(x, 21)
#define Q20acos(x) _qxx_acos(x, 20)
#define Q19acos(x) _qxx_acos(x, 19)
#define Q18acos(x) _qxx_acos(x, 18)
#define Q17acos(x) _qxx_acos(x, 17)
#define Q16acos(x) _qxx_acos(x, 16)
#define Q15acos(x) _qxx_acos(x, 15)
#define Q14acos(x) _qxx_acos(x, 14)
#define Q13acos(x) _qxx_acos(x, 13)
#define Q12acos(x) _qxx_acos(x, 12)
#define Q11acos(x) _qxx_acos(x, 11)
#define Q10acos(x) _qxx_acos(x, 10)
#define Q9acos(x)  _qxx_acos(x, 9)
#define Q8acos(x)  _qxx_acos(x, 8)

#define Q29atan2(y, x) _qxx_atan2(y, x, 29)
#define Q28atan2(y, x) _qxx_atan2(y, x, 28)
#define Q27atan2(y, x) _qxx_atan2(y, x, 27)
#define Q26atan2(y, x) _qxx_atan2(y, x, 26)
#define Q25atan2(y, x) _qxx_atan2(y, x, 25)
#define Q24atan2(y, x) _qxx_atan2(y, x, 24)
#define Q23atan2(y, x) _qxx_atan2(y, x, 23)
#define Q22atan2(y, x) _qxx_atan2(y, x, 22)
#define Q21atan2(y, x) _qxx_atan2(y, x, 21)
#define Q20atan2(y, x) _qxx_atan2(y, x, 20)
#define Q19atan2(y, x) _qxx_atan2(y, x, 19)
#define Q18atan2(y, x) _qxx_atan2(y, x, 18)
#define Q17atan2(y, x) _qxx_atan2(y, x, 17)
#define Q16atan2(y, x) _qxx_atan2(y, x, 16)
#define Q15atan2(y, x) _qxx_atan2(y, x, 15)
#define Q14atan2(y, x) _qxx_atan2(y, x, 14)
#define Q13atan2(y, x) _qxx_atan2(y, x, 13)
#define Q12atan2(y, x) _qxx_atan2(y, x, 12)
#define Q11atan2(y, x) _qxx_atan2(y, x, 11)
#define Q10atan2(y, x) _qxx_atan2(y, x, 10)
#define Q9atan2(y, x)  _qxx_atan2(y, x, 9)
#define Q8atan2(y, x)  _qxx_atan2(y, x, 8)

extern int_fast32_t _qxx_log(int_fast32_t x, int_fast32_t min,
                             int8_t qbit);

#define Q30log(x) _qxx_log(x, 3, 30)
#define Q29log(x) _qxx_log(x, 2, 29)
#define Q28log(x) _qxx_log(x, 1, 28)
#define Q27log(x) _qxx_log(x, 0, 27)
#define Q26log(x) _qxx_log(x, 1, 26)
#define Q25log(x) _qxx_log(x, 1, 25)
#define Q24log(x) _qxx_log(x, 1, 24)
#define Q23log(x) _qxx_log(x, 1, 23)
#define Q22log(x) _qxx_log(x, 1, 22)
#define Q21log(x) _qxx_log(x, 1, 21)
#define Q20log(x) _qxx_log(x, 1, 20)
#define Q19log(x) _qxx_log(x, 1, 19)
#define Q18log(x) _qxx_log(x, 1, 18)
#define Q17log(x) _qxx_log(x, 1, 17)
#define Q16log(x) _qxx_log(x, 1, 16)
#define Q15log(x) _qxx_log(x, 1, 15)
#define Q14log(x) _qxx_log(x, 1, 14)
#define Q13log(x) _qxx_log(x, 1, 13)
#define Q12log(x) _qxx_log(x, 1, 12)
#define Q11log(x) _qxx_log(x, 1, 11)
#define Q10log(x) _qxx_log(x, 1, 10)
#define Q9log(x)  _qxx_log(x, 1, 9)
#define Q8log(x)  _qxx_log(x, 1, 8)

/* Compat layer */
#ifdef CONFIG_QXX_FORMAT
# if CONFIG_QXX_FORMAT > 30
#  error "exceed the maximum byte of Q-format"
# endif

# define QtoF(x)       _qxx_to_float(x, CONFIG_QXX_FORMAT)
# define Q(x)          FtoQXX(x, CONFIG_QXX_FORMAT)
# define Qmul(x1, x2)  _qxx_mul(x1, x2, CONFIG_QXX_FORMAT)
# define Qsdiv(x1, x2) _qxx_div(x1, x2, 0, CONFIG_QXX_FORMAT)
# define Qudiv(x1, x2) _qxx_div(x1, x2, 1, CONFIG_QXX_FORMAT)
# define Qfrac(x)      _qxx_frac(x, CONFIG_QXX_FORMAT)
# define Qsqrt(x)      _qxx_sqrt(x, 0, CONFIG_QXX_FORMAT, 1)
# define Qrsqrt(x)     _qxx_sqrt(x, 0, CONFIG_QXX_FORMAT, 0)
# define Qsin(x)       _qxx_sin_cos(x, CONFIG_QXX_FORMAT, 0, 0)
# define Qcos(x)       _qxx_sin_cos(x, CONFIG_QXX_FORMAT, 1, 0)
# define Qtan(x)       _qxx_tan(x, CONFIG_QXX_FORMAT)
# define Qasin(x)      _qxx_asin(x, CONFIG_QXX_FORMAT)
# define Qacos(x)      _qxx_acos(x, CONFIG_QXX_FORMAT)
# define Qatan2(y, x)  _qxx_atan2(y, x, CONFIG_QXX_FORMAT)

# if CONFIG_QXX_FORMAT == 30
#  define Qlog(x)       _qxx_log(x, 3, 30)
# elif CONFIG_QXX_FORMAT == 29
#  define Qlog(x)       _qxx_log(x, 2, 29)
# elif CONFIG_QXX_FORMAT == 27
#  define Qlog(x)       _qxx_log(x, 0, 27)
# else
#  define Qlog(x)       _qxx_log(x, 1, CONFIG_QXX_FORMAT)
# endif
#endif /* CONFIG_QXX_FORMAT */

/* ----------------------------------------------------------- */
/*                        Math constants                       */
/* ----------------------------------------------------------- */
#define Q_SQRT3        Q(1.7320508) /* sqrt(3) */
#define Q_2SQRT3       Q(3.4641016) /* 2*sqrt(3) */
#define Q_PI           Q(3.1415926) /* pi */
#define Q_PI2          Q(6.2831853) /* pi/2 */
#define Q_2HALF_SQRT3  Q(0.8660254) /* sqrt(3)/2 */
#define Q_2HALF1       Q(0.5)       /* 1/2 */

// Private
#define _L(x1, x2)  (int_fast32_t)(((int_fast64_t)x1 * (int_fast64_t)x2) >> 31)
#define _UL(x1, x2) (uint_fast32_t)(((uint_fast64_t)x1 * (uint_fast64_t)x2) >> 31)
#define _X(x1, x2)  ((int_fast64_t)x1 * (int_fast64_t)x2)

#endif /* MMATH_QXX_H_ */
