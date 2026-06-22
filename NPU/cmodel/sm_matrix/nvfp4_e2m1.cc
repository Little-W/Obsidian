#include "nvfp4_e2m1.h"

namespace operators {

bool isInfiniteF32UI(uint32_t ui) {
  return (expF32UI(ui) == 0xFF) && (fracF32UI(ui) == 0);
}
/*
bool isNaNF32UI(uint32_t ui)
{
    return (expF32UI(ui) == 0xFF) && (fracF32UI(ui) != 0);
}*/

// int round_nvfp4_e2m1(int sign, uint_fast32_t frac, int precision, int
// inexact, int overflow);

//  基于位模式直接比较,// 实现简单，性能高，准确性最好
nvfp4_e2m1_t f32_to_nvfp4_e2m1_direct(float32_t a) {
  union ui32_f32 uA;
  uint_fast32_t uiA;
  bool sign;
  uint_fast8_t uiZ;
  union ui8_nvfp4_e2m1 uZ;

  uA.f = a;
  uiA = uA.ui;
  sign = signF32UI(uiA);

  // Handle special cases first
  if (expF32UI(uiA) == 0xFF) {
    if (fracF32UI(uiA)) { // NaN
      struct commonNaN commonNaN;
      softfloat_f32UIToCommonNaN(uiA, &commonNaN);
      uiZ = softfloat_commonNaNToNVFP4_E2M1UI(&commonNaN);
    } else {                   // Infinity
      uiZ = (sign << 3) | 0x7; // ±6.0
      // softfloat_raiseFlags(softfloat_flag_overflow | softfloat_flag_inexact);
    }
    uZ.ui = uiZ;
    return uZ.f;
  }

  // Clear sign bit for magnitude comparison
  uint32_t abs_ui = uiA & 0x7FFFFFFF;

  // Define boundary values as FP32 bit patterns
  const uint32_t bound_0_25 = 0x3E800000; // 0.25
  const uint32_t bound_0_75 = 0x3F400000; // 0.75
  const uint32_t bound_1_25 = 0x3FA00000; // 1.25
  const uint32_t bound_1_75 = 0x3FE00000; // 1.75
  const uint32_t bound_2_5 = 0x40200000;  // 2.5
  const uint32_t bound_3_5 = 0x40600000;  // 3.5
  const uint32_t bound_5_0 = 0x40A00000;  // 5.0
  const uint32_t bound_6_0 = 0x40C00000;  // 6.0

  const uint32_t FP32_value_0 = 0x00000000;   // 0
  const uint32_t FP32_value_0_5 = 0x3F000000; // 0.5
  const uint32_t FP32_value_1_0 = 0x3F800000; // 1.0
  const uint32_t FP32_value_1_5 = 0x3FC00000; // 1.5
  const uint32_t FP32_value_2_0 = 0x40000000; // 2.0
  const uint32_t FP32_value_3_0 = 0x40400000; // 3.0
  const uint32_t FP32_value_4_0 = 0x40800000; // 4.0
  const uint32_t FP32_value_6_0 = 0x40C00000; // 6.0

  // Determine value code based on bit pattern ranges
  uint_fast8_t value_code;
  int inexact = 0;
  int overflow = 0;
  int underflow = 0;

  if (abs_ui <= bound_0_25) {
    value_code = 0x0; // 0.0
    if (abs_ui != FP32_value_0)
      underflow = 1;
  } else if (abs_ui < bound_0_75) {
    value_code = 0x1; // 0.5
    if (abs_ui != FP32_value_0_5)
      inexact = 1;
  } else if (abs_ui <= bound_1_25) {
    value_code = 0x2; // 1.0
    if (abs_ui != FP32_value_1_0)
      inexact = 1; // 1.0
  } else if (abs_ui < bound_1_75) {
    value_code = 0x3; // 1.5
    if (abs_ui != FP32_value_1_5)
      inexact = 1;
  } else if (abs_ui <= bound_2_5) {
    value_code = 0x4; // 2.0
    if (abs_ui != FP32_value_2_0)
      inexact = 1; // 2.0
  } else if (abs_ui < bound_3_5) {
    value_code = 0x5; // 3.0
    if (abs_ui != FP32_value_3_0)
      inexact = 1;
  } else if (abs_ui <= bound_5_0) {
    value_code = 0x6; // 4.0
    if (abs_ui != FP32_value_4_0)
      inexact = 1; // 4.0
  } else {
    value_code = 0x7; // 6.0
    // 大于 6.0 的值才设置 overflow
    if (abs_ui > bound_6_0) {
      overflow = 1;
      inexact = 1;
    } else if (abs_ui != bound_6_0) {
      inexact = 1;
    }
    // 对于 6.0 本身，不设置 overflow 和 inexact
    if (abs_ui == bound_6_0) {
      overflow = 0;
      inexact = 0;
    }
  }

  // Combine sign and value code
  uiZ = (sign << 3) | value_code;

  // Handle flags
  if (overflow) {
    // softfloat_raiseFlags(softfloat_flag_overflow | softfloat_flag_inexact);
    cmodel_exceptionFlags |= softfloat_flag_overflow;

  } else if (underflow) {
    // softfloat_raiseFlags(softfloat_flag_underflow);
    cmodel_exceptionFlags |= softfloat_flag_underflow;
  }
  // else if (inexact) {
  //   softfloat_raiseFlags(softfloat_flag_inexact);
  // }

  uZ.ui = uiZ;
  return uZ.f;
}

// 将 NVFP4 E2M1 转换为 FP32
float nvfp4_e2m1_to_f32(nvfp4_e2m1_t a) {
  uint8_t code = nvfp4_e2m1_get_bits(a);
  bool sign = nvfp4_e2m1_get_sign(a);
  uint8_t value_code = nvfp4_e2m1_get_value_code(a);

  float value;
  switch (value_code) {
  case 0x0:
    value = 0.0f;
    break;
  case 0x1:
    value = 0.5f;
    break;
  case 0x2:
    value = 1.0f;
    break;
  case 0x3:
    value = 1.5f;
    break;
  case 0x4:
    value = 2.0f;
    break;
  case 0x5:
    value = 3.0f;
    break;
  case 0x6:
    value = 4.0f;
    break;
  case 0x7:
    value = 6.0f;
    break;
  default:
    value = 0.0f;
    break;
  }

  return sign ? -value : value;
}

// Common NaN 转换为 NVFP4 E2M1 UI
uint_fast8_t softfloat_commonNaNToNVFP4_E2M1UI(struct commonNaN *commonNaN) {
  return NVFP4_E2M1_POS_SIX;
}

/*
// Rounding function
int round_nvfp4_e2m1(int sign, uint_fast32_t frac, int precision, int inexact,
int overflow)
{
    int round = 0;

    if (softfloat_roundingMode == softfloat_round_near_even) {
        if (overflow) {
            round = 1;
        } else {
            if (inexact) {
                round = 0;
            }
        }
    } else if (softfloat_roundingMode == softfloat_round_minMag) {
        round = 0;
    } else if (softfloat_roundingMode == softfloat_round_min) {
        if (sign == 0) {
            round = 0;
        } else {
            round = precision | inexact;
        }
    } else if (softfloat_roundingMode == softfloat_round_max) {
        if (sign == 1) {
            round = 0;
        } else {
            round = precision | inexact;
        }
    } else if (softfloat_roundingMode == softfloat_round_near_maxMag) {
        if (precision == 1) {
            round = 1;
        } else {
            round = 0;
        }
    }

    return round;
}
*/
// nvfp4_e2m1_t f24_to_nvfp4_e2m1(uint32_t raw_fp24) {
//     const uint32_t masked_fp24 = raw_fp24 & 0x00FFFFFFu;
//     float32_t widened;
//     widened.v = masked_fp24 << 8;
//     return f32_to_nvfp4_e2m1_direct(widened);
// }

fp_general_t f24_to_nvfp4_e2m1(fp_general_t a) {
  const uint32_t masked_fp24 = a & 0x00FFFFFFu;
  float32_t widened;
  widened.v = masked_fp24 << 8;
  nvfp4_e2m1_t fp4e2m1_result = f32_to_nvfp4_e2m1_direct(widened);
  fp_general_t result = (fp_general_t)fp4e2m1_result.v;
  return result;
}

fp_general_t nvfp4_to_f32(fp_general_t a) {
  const uint32_t masked_fp4 = a & 0x0000000Fu;
  nvfp4_e2m1_t fp4_value;
  fp4_value.v = (uint8_t)masked_fp4;
  float f_value = nvfp4_e2m1_to_f32(fp4_value);
  // Convert float to uint32_t for fp_general_t
  uint32_t result_bits;
  memcpy(&result_bits, &f_value, sizeof(float));
  return (fp_general_t)result_bits;
}

} // namespace operators