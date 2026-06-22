#include <cstring>
#include "fp8_conversion.h"

namespace operators {

void alu_single_input_exam_fp8e4m3(fp_general_t a) {
  fp8e4m3_t x = (fp8e4m3_t)a;
  uint8_t sign = FP8_SIGN(x);
  uint8_t exp = FP8_EXP(x);
  uint8_t mant = FP8_MANT(x);
  // Handle NaN
  if (FP8_IS_NAN(exp, mant))
    softfloat_exceptionFlags =
        softfloat_exceptionFlags | softfloat_flag_invalid;
}

int round_f8_1(int sign, uint_fast32_t frac, int precision, int inexact,
               int overflow);

float8_1_t f32_to_f8_1(float32_t a) {
  union ui32_f32 uA;
  uint_fast32_t uiA;
  bool sign;
  int_fast16_t exp;
  uint_fast32_t frac;
  struct commonNaN commonNaN;
  uint_fast8_t uiZ;
  union ui8_f8_1 uZ;
  // bool zero;
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  uA.f = a;
  uiA = uA.ui;
  sign = signF32UI(uiA);
  exp = expF32UI(uiA);
  frac = fracF32UI(uiA);
  // zero = (exp == 0) && (frac == 0);
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  int inexact = 0;
  int precision = 0;
  int overflow = 0;

  if (exp <=
      0x78) { // 0x78 is the largest exponent that converts to a denorm in f8_1
    if (exp == 0x00) {
      if (frac != 0x00) {
        inexact = 1;
      }
      exp = 0x0;
      frac = 0x0;
      uiZ = packToF8_1UI(sign, exp, frac);
    } else if (exp <= 0x75) {
      if (exp == 0x75) {
        precision = 1;
        if (frac != 0) {
          inexact = 1;
        }
      } else {
        inexact = 1;
      }
      exp = 0x0;
      frac = 0x0;
      uiZ = packToF8_1UI(sign, exp, frac);
    } else if (exp == 0x76) {
      if (frac != 0x00) {
        inexact = 1;
        if (frac == 0x400000) {
          precision = 1;
          inexact = 0;
        } else if (frac > 0x400000) {
          precision = 1;
        }
      }
      exp = 0x0;
      frac = 0x1;
      uiZ = packToF8_1UI(sign, exp, frac);
    } else if (exp == 0x77) {
      if (frac < 0x400000) {
        if (frac != 0x00) {
          inexact = 1;
          if (frac == 0x200000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x200000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x2;
        uiZ = packToF8_1UI(sign, exp, frac);
      } else {
        if (frac != 0x400000) {
          inexact = 1;
          if (frac == 0x600000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x600000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x3;
        uiZ = packToF8_1UI(sign, exp, frac);
      }
    } else if (exp == 0x78) {
      if (frac < 0x200000) {
        if (frac != 0x000000) {
          inexact = 1;
          if (frac == 0x100000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x100000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x4;
        uiZ = packToF8_1UI(sign, exp, frac);
      } else if (frac < 0x400000) {
        if (frac != 0x200000) {
          inexact = 1;
          if (frac == 0x300000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x300000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x5;
        uiZ = packToF8_1UI(sign, exp, frac);
      } else if (frac < 0x600000) {
        if (frac != 0x400000) {
          inexact = 1;
          if (frac == 0x500000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x500000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x6;
        uiZ = packToF8_1UI(sign, exp, frac);
      } else {
        if (frac != 0x600000) {
          inexact = 1;
          if (frac == 0x700000) {
            precision = 1;
            inexact = 0;
          } else if (frac > 0x700000) {
            precision = 1;
          }
        }
        exp = 0x0;
        frac = 0x7;
        uiZ = packToF8_1UI(sign, exp, frac);
      }
    }
  }
#if E4M3_OFP8 == 1
  else if (exp <= 0x87) { // 0x86 is the biggest number in which mantissa is not
                          // overflowing
    int mask_frac =
        0x700000; // creates a mask equal to 111_0000_0000_0000_0000_0000 which
                  // enables only the mantissa in the core
    int mask_precision =
        0x80000; // creates a mask equal to 000_1000_0000_0000_0000_0000 which
                 // enables only the mantissa in the core
    int mask_inexact =
        0x07FFFF; // creates a mask equal to 000_0111_1111_1111_1111_1111 which
                  // enables only the mantissa in the core
    precision = (frac & mask_precision) >> (3 + 16);
    inexact = ((frac & mask_inexact) > 0);
    exp = exp - 127 + 7;
    frac = (frac & mask_frac) >> (4 + 16);

    uiZ = packToF8_1UI(sign, exp, frac);
  } else if (exp < 0xFF) {
#if OFP8_saturate == 1
    exp = 0xF;
    frac = 0x6; // max normal
    uiZ = packToF8_1UI(sign, exp, frac);
    inexact = 1;
    precision = 1;
#if OFP8_overflow_flag == 1
    overflow = 1;
#else
    overflow = 0;
#endif
    uZ.ui = uiZ;
#if OFP8_overflow_flag == 1
    // softfloat_raiseFlags(softfloat_flag_overflow | softfloat_flag_inexact);
    cmodel_exceptionFlags |= softfloat_flag_overflow;
#else
    // softfloat_raiseFlags(softfloat_flag_inexact);
#endif
    return uZ.f;
#else
    softfloat_f32UIToCommonNaN(uiA, &commonNaN);
    uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
    uZ.ui = uiZ;
    return uZ.f;
#endif
  } else if (exp == 0xFF) {
    if (frac) { // NaN
      softfloat_f32UIToCommonNaN(uiA, &commonNaN);
      uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
      uZ.ui = uiZ;
      return uZ.f;
    } else { // inf
#if OFP8_saturate == 1
      exp = 0xF;
      frac = 0x6;
      uiZ = packToF8_1UI(sign, exp, frac); // max_value
      uZ.ui = uiZ;
#if OFP8_overflow_flag == 1
      // softfloat_raiseFlags(softfloat_flag_overflow | softfloat_flag_inexact);
      // cmodel_exceptionFlags |= softfloat_flag_overflow; //20251118 comply RTL
#else
      // softfloat_raiseFlags(softfloat_flag_inexact);
#endif
      return uZ.f;
#else
      softfloat_f32UIToCommonNaN(uiA, &commonNaN);
      uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
      uZ.ui = uiZ;
      return uZ.f;
#endif
    }
    goto uiZ;
  }
#else
  else if (exp <= 0x86) { // 0x86 is the biggest number in which mantissa is not
                          // overflowing

    int mask_frac =
        0x700000; // creates a mask equal to 111_0000_0000_0000_0000_0000 which
                  // enables only the mantissa in the core
    int mask_precision =
        0x80000; // creates a mask equal to 000_1000_0000_0000_0000_0000 which
                 // enables only the mantissa in the core
    int mask_inexact =
        0x07FFFF; // creates a mask equal to 000_0111_1111_1111_1111_1111 which
                  // enables only the mantissa in the core
    precision = (frac & mask_precision) >> (3 + 16);
    inexact = ((frac & mask_inexact) > 0);
    exp = exp - 127 + 7;
    frac = (frac & mask_frac) >> (4 + 16);
    uiZ = packToF8_1UI(sign, exp, frac);
  } else if (exp < 0xFF) {
    exp = 0xE;
    frac = 0x7;
    uiZ = packToF8_1UI(sign, exp, frac);
    inexact = 1;
    precision = 1;
    overflow = 1;
  } else if (exp == 0xFF) {
    if (frac) {
      softfloat_f32UIToCommonNaN(uiA, &commonNaN);
      uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
      uZ.ui = uiZ;
      return uZ.f;
    } else {
      exp = 0xF;
      frac = 0x0;
      uiZ = packToF8_1UI(sign, exp, frac);
      uZ.ui = uiZ;
      return uZ.f;
    }
    goto uiZ;
  }
#endif

  if ((exp == 0xE && expF8_1UI(uiZ + round_f8_1(sign, frac, precision, inexact,
                                                overflow)) == 1) ||
      overflow == 1) {
    // softfloat_raiseFlags(softfloat_flag_overflow | softfloat_flag_inexact);
    cmodel_exceptionFlags |= softfloat_flag_overflow;
  } else if (inexact == 1 || precision == 1) {
    // softfloat_raiseFlags(softfloat_flag_inexact);
    /*
    if (exp == 0) { // 2025/11/12
      // softfloat_raiseFlags(softfloat_flag_underflow);
      cmodel_exceptionFlags |= softfloat_flag_underflow;
    }*/
  }
uiZ:

#if E4M3_OFP8 == 1
#if OFP8_saturate == 1
#if OFP8_overflow_flag == 1
  if ((uiZ & 0x7F) == 0x7F) {
    uZ.ui = uiZ;
    goto Jumped;
  }
  uZ.ui = uiZ + round_f8_1(sign, frac, precision, inexact, overflow);

Jumped:
  if ((((uZ.ui >> 3) & 0xF) == 0xF) && (((uZ.ui >> 0) & 0x7) == 0x7)) {
    // softfloat_raiseFlags(softfloat_flag_overflow);
    cmodel_exceptionFlags |= softfloat_flag_overflow;
    uZ.ui = 0x7e | sign << 7;
  }
#else
  if ((uiZ & 0x7F) == 0x7F) {
    uZ.ui = uiZ;
    goto Jumped;
  }
  uZ.ui = uiZ + round_f8_1(sign, frac, precision, inexact, overflow);

Jumped:
  if ((((uZ.ui >> 3) & 0xF) == 0xF) && (((uZ.ui >> 0) & 0x7) == 0x7)) {
    uZ.ui = 0x7e | sign << 7;
  }
#endif
#else
#if OFP8_overflow_flag == 1
  if ((uiZ & 0x7F) == 0x7F) {
    uZ.ui = uiZ & 0x7F;
    goto Jumped;
  }
  uZ.ui = uiZ + round_f8_1(sign, frac, precision, inexact, overflow);
Jumped:
  if ((((uZ.ui >> 3) & 0xF) == 0xF) && (((uZ.ui >> 0) & 0x7) == 0x7)) {
    // softfloat_raiseFlags(softfloat_flag_overflow);
    cmodel_exceptionFlags |= softfloat_flag_overflow;
    softfloat_f32UIToCommonNaN(uiA, &commonNaN);
    uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
    uZ.ui = uiZ;
  }
#else
  if ((uiZ & 0x7F) == 0x7F) {
    uZ.ui = uiZ & 0x7F;
    goto Jumped;
  }
  uZ.ui = uiZ + round_f8_1(sign, frac, precision, inexact, overflow);
Jumped:
  if ((((uZ.ui >> 3) & 0xF) == 0xF) && (((uZ.ui >> 0) & 0x7) == 0x7)) {
    softfloat_f32UIToCommonNaN(uiA, &commonNaN);
    uiZ = softfloat_commonNaNToF8_1UI(&commonNaN);
    uZ.ui = uiZ;
  }
#endif
#endif
#else
  uZ.ui = uiZ + round_f8_1(sign, frac, precision, inexact, overflow);
  if (((uZ.ui >> 3) & 0xF) == 0xF) {
    // softfloat_raiseFlags(softfloat_flag_overflow);
    cmodel_exceptionFlags |= softfloat_flag_overflow;
  }
#endif

  // Underflow-on-inexact-zero policy: after final rounding, if result magnitude
  // is zero and rounding occurred, raise underflow
  if ((inexact == 1 || precision == 1) && ((uZ.ui & 0x7F) == 0)) {
    // softfloat_raiseFlags(softfloat_flag_underflow);
    cmodel_exceptionFlags |= softfloat_flag_underflow;
  }

  return uZ.f;
}

int round_f8_1(int sign, uint_fast32_t frac, int precision, int inexact,
               int overflow) {
  // printf("frac = 0x%x, precision = %d, inexact = %x\n", frac, precision,
  // inexact);
  int round = 0; // round down is the default unless we round up based on the
                 // following conditions
  if (softfloat_roundingMode == 0) {
    // printf("softfloat_roundingMode == 0 ");
    if (overflow) {
      round = 1;
    } else {
      int even_mask = 0x1; // used to mask the mantissa to see if the number is
                           // even (i.e. LSB = 0)
      if (inexact == 0) {
        if (precision == 1) {
          if ((frac & even_mask) == 1) {
            round = 1;
          }
        }
      } else {
        if (precision == 1) { // round up
          round = 1;
        }
      }
    }
  } else if (softfloat_roundingMode == 1) {
    // printf("softfloat_roundingMode == 1 ");
    round = 0;
  } else if (softfloat_roundingMode == 2) {

    // printf("softfloat_roundingMode == 2 ");
    if (sign == 0) {
      round = 0;
    } else {
      round = precision | inexact;
    }
  } else if (softfloat_roundingMode == 3) {
    // printf("softfloat_roundingMode == 3 ");
    if (sign == 1) {
      round = 0;
    } else {
      round = precision | inexact;
    }
  } else if (softfloat_roundingMode == 4) {

    // printf("softfloat_roundingMode == 4 ");
    if (precision == 1) {
      round = 1;
    } else {
      round = 0;
    }
  }
  return round;
}

/*
fp_general_t fp8e4m3_to_fp32(fp_general_t x_val) {
    float8_1_t f8;
    f8.v = (uint8_t)x_val;

    float32_t f32 = f8_1_to_f32(f8);
    fp_general_t result = (fp_general_t)f32.v;
    return result;

}
*/
// Convert FP8 to FP32
fp_general_t fp8e4m3_to_fp32(fp_general_t x_val) {
  alu_single_input_exam_fp8e4m3(x_val);
  fp8e4m3_t x = (fp8e4m3_t)x_val;
  uint8_t sign = FP8_SIGN(x);
  uint8_t exp = FP8_EXP(x);
  uint8_t mant = FP8_MANT(x);

  // Handle NaN
  if (FP8_IS_NAN(exp, mant)) {
    uint32_t nan_bits =
        0x7FC00000; // IEEE 754 NaN representation 0_111.1111.1_100.0000
    return (fp_general_t)nan_bits;
  }

  // Handle zero
  if (FP8_IS_ZERO(exp, mant)) {
    uint32_t zero_bits = sign ? 0x80000000 : 0x00000000;
    return (fp_general_t)zero_bits;
  }

  float value;
  if (FP8_IS_DENORMAL(exp, mant)) {
    // Denormal number: (-1)^sign × 2^(-Bias + 1) × (0 + Fraction)
    // Bias=7, so exponent is -7 + 1 = -6
    value = (float)mant / 8.0f * pow(2, -6);
  } else if (FP8_IS_SPECIAL_NORMAL(exp, mant)) {
    // Special normal number (E=1111 and M≠111): (-1)^sign × 2^8 × (1 +
    // Fraction)
    value = (1.0f + (float)mant / 8.0f) * pow(2, 8);
  } else {
    // Normal number: (-1)^sign × 2^(exp-Bias) × (1 + Fraction)
    value = (1.0f + (float)mant / 8.0f) * pow(2, exp - EXP_BIAS_FP8E4);
  }

  // Convert float to uint32_t for fp_general_t
  uint32_t result_bits;
  if (sign)
    value = -value;
  memcpy(&result_bits, &value, sizeof(float));

  return (fp_general_t)result_bits;
}

// Convert single float value to FP8 E4M3
fp_general_t fp32_to_fp8e4m3(fp_general_t f) {
  softfloat_exceptionFlags = 0;
  alu_output_exam(f, 8, 23);
  float32_t f_bits;
  f_bits.v = (uint32_t)f;

  float8_1_t f8 = f32_to_f8_1(f_bits);
  fp_general_t result = (fp_general_t)f8.v;
  return result;
}

} // namespace operators
