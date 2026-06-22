#ifndef FP8_CONVERSION_H
#define FP8_CONVERSION_H

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdbool.h>
#include "platform.h"
#include "internals.h"
#include "specialize.h"
#include "softfloat.h"
#include "dop_ops.h"

namespace operators {

typedef uint64_t fp_general_t;
typedef uint8_t fp8e4m3_t;

fp_general_t fp8e4m3_to_fp32(fp_general_t f32);
fp_general_t fp32_to_fp8e4m3(fp_general_t f8);

//---------------------for test----------------------------------//
// SoftFloat-compatible rounding modes
// typedef enum {
//     softfloat_round_near_even   = 0,
//     softfloat_round_minMag      = 1,
//     softfloat_round_min         = 2,
//     softfloat_round_max         = 3,
//     softfloat_round_near_maxMag = 4,
//     softfloat_round_odd         = 5
// } softfloat_rounding_mode_t;

// // Global rounding mode variable
// extern softfloat_rounding_mode_t softfloat_roundingMode;

// 通用宏：提取浮点数的符号位
#define FP_SIGN(bits, exp_bits, mantissa_bits)                                 \
  (((bits) >> ((exp_bits) + (mantissa_bits))) & 0x1)

// 通用宏：提取浮点数的指数位
#define FP_EXP(bits, exp_bits, mantissa_bits)                                  \
  (((bits) >> (mantissa_bits)) & ((1 << (exp_bits)) - 1))

// 通用宏：提取浮点数的尾数位
#define FP_MANT(bits, mantissa_bits) ((bits) & ((1 << (mantissa_bits)) - 1))

// FP32 特定宏
#define FP32_SIGN(bits) FP_SIGN(bits, 8, 23)
#define FP32_EXP(bits) FP_EXP(bits, 8, 23)
#define FP32_MANT(bits) FP_MANT(bits, 23)

// FP8 特定宏
#define FP8_SIGN(x) FP_SIGN(x, 4, 3)
#define FP8_EXP(x) FP_EXP(x, 4, 3)
#define FP8_MANT(x) FP_MANT(x, 3)

// FP32 特殊值判断宏
#define FP32_IS_NAN(bits) ((FP32_EXP(bits) == 0xFF) && (FP32_MANT(bits) != 0))
#define FP32_IS_INF(bits) ((FP32_EXP(bits) == 0xFF) && (FP32_MANT(bits) == 0))
#define FP32_IS_ZERO(bits) ((FP32_EXP(bits) == 0) && (FP32_MANT(bits) == 0))
#define FP32_IS_DENORMAL(bits) ((FP32_EXP(bits) == 0) && (FP32_MANT(bits) != 0))

// Compose FP8 value
#define FP8_COMPOSE(sign, exp, mant) (((sign) << 7) | ((exp) << 3) | (mant))

// Get sign bit of FP32 (ensures 0 or 1) - 保持兼容性
#define GET_FP32_SIGN(f) ((*((uint32_t *)&(f)) >> 31) & 0x1U)

// FP8 特殊值判断宏
#define FP8_IS_NAN(exp, mant) ((exp) == 0xF && (mant) == 0x7)
#define FP8_IS_ZERO(exp, mant) ((exp) == 0 && (mant) == 0)
#define FP8_IS_DENORMAL(exp, mant) ((exp) == 0 && (mant) != 0)
#define FP8_IS_NORMAL(exp, mant)                                               \
  (((exp) > 0 && (exp) < 0xF) || ((exp) == 0xF && (mant) != 0x7))
#define FP8_IS_SPECIAL_NORMAL(exp, mant) ((exp) == 0xF && (mant) != 0x7)

// Exponent bias
#define EXP_BIAS_FP8E4 7

//--------------------------------softfloat_8/softfloat_types.h----------------------------------//
#define E4M3_OFP8                                                              \
  1 // When set to 1, the FP8 will be the OFP/Nvidia one.              	When set
    // to 0, it will be the ieee-like one.
#define E4M3_isSigNaN                                                          \
  0 // When set to 1, the FP8 OFP8 only NaN will be Signaling.         	When set
    // to 0, it will be Quiet.
#define OFP8_saturate                                                          \
  1 // When set to 1, the FP8 OFP8 will saturate on conversions.       	When set
    // to 0, it will overflow to NaN.
#define OFP8_saturate_arith                                                    \
  1 // When set to 1, the FP8 OFP8 will saturate on operation also.    	When set
    // to 0, it will overflow to NaN.
// It only work if also OFP8_saturate is set to 1, as saturation for conversion
// is needed by the standard.
#define OFP8_overflow_flag                                                     \
  1 // When set to 1, the OFP8  set the overflow flag when saturating.  When set
    // to 0, it will not.

typedef struct {
  uint8_t v;
} float8_1_t; // 1-4-3
typedef struct {
  uint8_t v;
} float8_2_t; // 1-5-2

//--------------------------------softfloat_8/specialize.h----------------------------------//

#define softfloat_commonNaNToF8_1UI(aPtr) ((uint_fast8_t)defaultNaNF8_1UI)

#if E4M3_OFP8 == 1
#define defaultNaNF8_1UI 0x7F
#else
#define defaultNaNF8_1UI 0x7C
#endif

//--------------------------------softfloat_8/specialize.h----------------------------------//
float8_1_t f32_to_f8_1(float32_t);

//--------------------------------softfloat_8/internals.h----------------------------------//
union ui8_f8_1 {
  uint8_t ui;
  float8_1_t f;
}; // 1-4-3
union ui8_f8_2 {
  uint8_t ui;
  float8_2_t f;
}; // 1-5-2

/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#define signF8_1UI(a) ((bool)((uint8_t)(a) >> 7))
#define expF8_1UI(a) ((int_fast8_t)((a) >> 3) & 0x0F)
#define fracF8_1UI(a) ((a)&0x07)
#define packToF8_1UI(sign, exp, sig)                                           \
  (((uint8_t)(sign) << 7) + ((uint8_t)(exp) << 3) + (sig))

} // namespace operators

#endif // FP8_CONVERSION_H
