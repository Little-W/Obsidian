#include "dop_ops.h"
#include "internals.h"
#include "specialize.h"
#include <stdbool.h>
#include <stdint.h>

namespace operators {
fp_general_t fp32_to_fp32(fp_general_t a) { return a; }

fp_general_t fp24_to_fp32(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 15, is_innner_use);
  return low_to_high(a, 8, 15, 8, 23);
}
fp_general_t fp32_to_fp24(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 23, is_innner_use);
  return high_to_low(a, 8, 15, 8, 23);
}

fp_general_t fp16_to_fp24(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 5, 10, is_innner_use);
  return low_to_high(a, 5, 10, 8, 15);
}
fp_general_t fp24_to_fp16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 15, is_innner_use);
  return high_to_low(a, 5, 10, 8, 15);
}

fp_general_t fp32_to_fp16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 23, is_innner_use);
  return high_to_low(a, 5, 10, 8, 23);
}
fp_general_t fp16_to_fp32(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 5, 10, is_innner_use);
  return low_to_high(a, 5, 10, 8, 23);
}

fp_general_t fp24_to_fp64(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 15, is_innner_use);
  return low_to_high(a, 8, 15, 11, 52);
}
fp_general_t fp64_to_fp24(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 11, 52, is_innner_use);
  return high_to_low(a, 8, 15, 11, 52);
}

fp_general_t fp32_to_fp64(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 23, is_innner_use);
  return low_to_high(a, 8, 23, 11, 52);
}
fp_general_t fp64_to_fp32(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 11, 52, is_innner_use);
  return high_to_low(a, 8, 23, 11, 52);
}

fp_general_t bf16_to_fp32(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 7, is_innner_use);
  return low_to_high(a, 8, 7, 8, 23);
}
fp_general_t fp32_to_bf16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 23, is_innner_use);
  return high_to_low(a, 8, 7, 8, 23);
}

fp_general_t bf16_to_fp24(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 7, is_innner_use);
  return low_to_high(a, 8, 7, 8, 15);
}
fp_general_t fp24_to_bf16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 15, is_innner_use);
  return high_to_low(a, 8, 7, 8, 15);
}

fp_general_t fp8e5_to_fp32(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 5, 2, is_innner_use);
  return low_to_high(a, 5, 2, 8, 23);
}
fp_general_t fp32_to_fp8e5(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 23, is_innner_use);
  return high_to_low(a, 5, 2, 8, 23);
}
// fp_general_t fp8e4_to_fp32(fp_general_t a) { return low_to_high(a, 4, 3, 8,
// 23); } fp_general_t fp32_to_fp8e4(fp_general_t a) { return high_to_low(a, 4,
// 3, 8, 23); }
fp_general_t fp8e4_to_fp32(fp_general_t a) { return fp8e4m3_to_fp32(a); }
fp_general_t fp32_to_fp8e4(fp_general_t a) { return fp32_to_fp8e4m3(a); }

fp_general_t bf16_to_fp16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 7, is_innner_use);
  fp_general_t temp = bf16_to_fp32(a);
  return fp32_to_fp16(temp);
}

fp_general_t fp16_to_bf16(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 5, 10, is_innner_use);
  fp_general_t temp = fp16_to_fp32(a);
  return fp32_to_bf16(temp);
}

float32_t int16_to_fp32(int32_t a) { return i32_to_f32(a); }
int_fast16_t fp32_to_int16(float32_t a) {
  return f32_to_i16(a, softfloat_roundingMode, true);
}

fp_general_t int8_to_fp16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 8, 64);
  float16_t a_16_t = i64_to_f16((int64_t)a_64_int_t);
  return a_16_t.v;
}

fp_general_t uint8_to_fp16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 8, 64);
  float16_t a_16_t = i64_to_f16((int64_t)a_64_int_t);
  return a_16_t.v;
}

fp_general_t int8_to_bf16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 8, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp24_to_bf16(fp64_to_fp24(a_64_t.v));
}

fp_general_t int4_to_f64(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 4, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return a_64_t.v;
}

fp_general_t uint4_to_f64(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 4, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return a_64_t.v;
}

fp_general_t uint8_to_bf16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 8, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp24_to_bf16(fp64_to_fp24(a_64_t.v));
}

fp_general_t int16_to_fp16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 16, 64);
  float16_t a_16_t = i64_to_f16((int64_t)a_64_int_t);

  return a_16_t.v;
}

fp_general_t uint16_to_fp16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 16, 64);
  float16_t a_16_t = i64_to_f16((int64_t)a_64_int_t);
  return a_16_t.v;
}

fp_general_t sint29_add(fp_general_t a, fp_general_t b);

fp_general_t int40_to_fp24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 40, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t int40_to_fp32(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 40, 64);
  float32_t a_32_t = i64_to_f32((int64_t)a_64_int_t);
  return a_32_t.v;
}

fp_general_t int32_to_bf16(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 32, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp24_to_bf16(fp64_to_fp24(a_64_t.v));
}

fp_general_t int_convert(fp_general_t a, uint8_t raw_sign_len,
                         uint8_t raw_full_len,
                         uint8_t dest_len) // 只允许从低位转成64位
{
  uint64_t sign = (uint64_t)intSignGeneralUI(a, raw_sign_len, raw_full_len);
  uint64_t sig = (uint64_t)intFracGeneralUI(a, raw_sign_len, raw_full_len);
  uint64_t a_64_int_t = sign ? ~sig + 1 : sig;
  if (dest_len < 64 && sign) {
    a_64_int_t = a_64_int_t & ((1UL << dest_len) - 1UL);
  }

  return a_64_int_t;
}

fp_general_t sint28_to_sint40(fp_general_t a) {
  return int_convert(a, 1, 28, 40);
}

fp_general_t sint40sint28_add(fp_general_t a, fp_general_t b) {
  fp_general_t b_new = sint28_to_sint40(b);
  fp_general_t result = a + b_new;
  return result & 0xffffffffff;
}

fp_general_t sint40_add(fp_general_t a, fp_general_t b) {
  fp_general_t result = a + b;
  bool signA = a & int40Ninf;
  bool signB = b & int40Ninf;
  if (signA == signB) {
    if (signA) {
      if (!(result & int40Ninf))
        result = int40Ninf;
    } else {
      if (result & int40Ninf)
        result = int40Pinf;
    }
  }
  return result & 0xffffffffff;
}

fp_general_t f24_to_i32(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? i32_fromNegOverflow & 0xffffffff
                                   : i32_fromPosOverflow;
  }

  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;
  int_fast64_t sig32 = f32_to_i64(a_32_t, softfloat_roundingMode, true);
  if (sig32 > INT32_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i32_fromPosOverflow;
  } else if (sig32 < INT32_MIN) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i32_fromNegOverflow & 0xffffffff;
    ;
  }
  return sig32;
}

fp_general_t f24_to_i16(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? i16_fromNegOverflow & 0xffff
                                   : i16_fromPosOverflow;
  }

  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;

  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);
  if (sig32 > INT16_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i16_fromPosOverflow;
  } else if (sig32 < INT16_MIN) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i16_fromNegOverflow & 0xffff;
    ;
  }
  return sig32 & 0xffff;
}

fp_general_t f24_to_i8(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? i8_fromNegOverflow & 0xff
                                   : i8_fromPosOverflow;
  }

  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;
  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);

  if (sig32 > INT8_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i8_fromPosOverflow;
  } else if (sig32 < INT8_MIN) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i8_fromNegOverflow & 0xff;
  } else {
    return int_convert(sig32, 1, 32, 8) & 0xff;
  }
}

fp_general_t f24_to_u32(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? 0 : ui32_fromPosOverflow;
  }
  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;
  int_fast32_t sig32 = f32_to_i64(a_32_t, softfloat_roundingMode, true);
  if (sig32 > UINT32_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return ui32_fromPosOverflow;
  } else if (sig32 < 0) {
    // cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_underflow;
    return ui32_fromNegOverflow;
  } else {
    return sig32;
  }
}

fp_general_t f24_to_u16(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? 0 : ui16_fromPosOverflow;
  }
  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;
  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);
  if (sig32 > UINT16_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return ui16_fromPosOverflow;
  } else if (sig32 < 0) {
    // cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_underflow;
    return ui16_fromNegOverflow;
  } else {
    return sig32;
  }
}

fp_general_t f24_to_u8(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 15) ? 0 : ui8_fromPosOverflow;
  }
  fp_general_t a_32 = fp24_to_fp32(a);
  float32_t a_32_t;
  a_32_t.v = a_32;
  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);

  if (sig32 > UINT8_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return ui8_fromPosOverflow;
  } else if (sig32 < 0) {
    // cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_underflow;
    return ui8_fromNegOverflow;
  } else {
    return sig32;
  }
}

fp_general_t i24_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 24, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t i16_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 16, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t i8_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 1, 8, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t u24_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 24, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t u16_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 16, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t u8_to_f24(fp_general_t a) {
  uint64_t a_64_int_t = int_convert(a, 0, 8, 64);
  float64_t a_64_t = i64_to_f64((int64_t)a_64_int_t);
  return fp64_to_fp24(a_64_t.v);
}

fp_general_t f32_to_i8(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 23)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 23)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 23) ? i8_fromNegOverflow & 0xff
                                   : i8_fromPosOverflow;
  }
  float32_t a_32_t;
  a_32_t.v = a;

  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);

  if (sig32 > INT8_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i8_fromPosOverflow;
  } else if (sig32 < INT8_MIN) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return i8_fromNegOverflow & 0xff;
  } else {
    return int_convert(sig32, 1, 32, 8);
  }
}

fp_general_t f32_to_u8(fp_general_t a) {
  if (isNaNGeneralUI(a, 8, 23)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return 0;
  }
  if (isINFGeneralUI(a, 8, 23)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return signGeneralUI(a, 8, 23) ? 0 : i8_fromPosOverflow;
  }
  float32_t a_32_t;
  a_32_t.v = a;

  int_fast32_t sig32 = f32_to_i32(a_32_t, softfloat_roundingMode, true);

  if (sig32 > UINT8_MAX) {
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_overflow;
    return ui8_fromPosOverflow;
  } else if (sig32 < 0) {
    // cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_underflow;
    return ui8_fromNegOverflow;
  } else {
    return sig32;
  }
}

fp_general_t fp24_to_fp4e2m1(fp_general_t a, bool is_innner_use) {
  convert_input_exam(a, 8, 15, is_innner_use);
  return f24_to_nvfp4_e2m1(a);
}

} // namespace operators
