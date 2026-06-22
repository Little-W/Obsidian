#include "dop_ops.h"
#include "internals.h"
#include "specialize.h"
#include <stdbool.h>
#include <stdint.h>

namespace operators {
fp_general_t fp16add(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 5, 10) || isINFGeneralUI(b, 5, 10);
  float16_t a_new;
  float16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f16_add(a_new, b_new).v;
  alu_output_exam(res, 5, 10, is_inf);
  return res;
}

fp_general_t fp16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 5, 10) || isINFGeneralUI(b, 5, 10);
  float16_t a_new;
  float16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f16_mul(a_new, b_new).v;
  alu_output_exam(res, 5, 10, is_inf);
  return res;
}

fp_general_t fp16sub(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 5, 10) || isINFGeneralUI(b, 5, 10);
  float16_t a_new;
  float16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f16_sub(a_new, b_new).v;
  alu_output_exam(res, 5, 10, is_inf);
  return res;
}

fp_general_t fp16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  bool is_inf = isINFGeneralUI(a, 5, 10) || isINFGeneralUI(b, 5, 10) ||
                isINFGeneralUI(c, 5, 10);
  float16_t a_new;
  float16_t b_new;
  float16_t c_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  c_new.v = (uint16_t)c;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f16_mulAdd(a_new, b_new, c_new).v;
  alu_output_exam(res, 5, 10, is_inf);
  return res;
}

fp_general_t fp24add(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 8, 15);
  float64_t f64A;
  float64_t f64B;
  f64A.v = fp24_to_fp64(a, true);
  f64B.v = fp24_to_fp64(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_add(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24sub(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 8, 15);
  float64_t f64A;
  float64_t f64B;
  f64A.v = fp24_to_fp64(a, true);
  f64B.v = fp24_to_fp64(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_sub(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 8, 15);
  float64_t f64A;
  float64_t f64B;
  f64A.v = fp24_to_fp64(a, true);
  f64B.v = fp24_to_fp64(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 8, 15) ||
                isINFGeneralUI(c, 8, 15);
  float64_t f64A;
  float64_t f64B;
  float64_t f64C;
  f64A.v = fp24_to_fp64(a, true);
  f64B.v = fp24_to_fp64(b, true);
  f64C.v = fp24_to_fp64(c, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mulAdd(f64A, f64B, f64C).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32add(fp_general_t a, fp_general_t b, bool is_dop) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23);
  float32_t a_new;
  float32_t b_new;
  a_new.v = (uint32_t)a;
  b_new.v = (uint32_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f32_add(a_new, b_new).v;
  alu_output_exam(res, 8, 23, is_inf);
  if (is_dop && isINFGeneralUI(res, 8, 23) &&
      !(isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23))) {
    res -= 1;
  }
  return res;
}

fp_general_t fp32sub(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23);
  float32_t a_new;
  float32_t b_new;
  a_new.v = (uint32_t)a;
  b_new.v = (uint32_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f32_sub(a_new, b_new).v;
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t fp32mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23);
  float32_t a_new;
  float32_t b_new;
  a_new.v = (uint32_t)a;
  b_new.v = (uint32_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f32_mul(a_new, b_new).v;
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t fp32mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23) ||
                isINFGeneralUI(c, 8, 23);
  float32_t a_new;
  float32_t b_new;
  float32_t c_new;
  a_new.v = (uint32_t)a;
  b_new.v = (uint32_t)b;
  c_new.v = (uint32_t)c;
  softfloat_exceptionFlags = 0;
  fp_general_t res = f32_mulAdd(a_new, b_new, c_new).v;
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t bf16add(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7);
  bfloat16_t a_new;
  bfloat16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = bf16_add(a_new, b_new).v;
  alu_output_exam(res, 8, 7, is_inf);
  return res;
}

fp_general_t bf16sub(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7);
  bfloat16_t a_new;
  bfloat16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = bf16_sub(a_new, b_new).v;
  alu_output_exam(res, 8, 7, is_inf);
  return res;
}

fp_general_t bf16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7);
  bfloat16_t a_new;
  bfloat16_t b_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = bf16_mul(a_new, b_new).v;
  alu_output_exam(res, 8, 7, is_inf);
  return res;
}

fp_general_t bf16mul_resfp24(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7);
  fp_general_t a_new = bf16_to_fp24(a, true);
  fp_general_t b_new = bf16_to_fp24(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp24mul(a_new, b_new);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp16mul_resfp32(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 5, 10) || isINFGeneralUI(b, 5, 10);
  fp_general_t a_new = fp16_to_fp32(a, true);
  fp_general_t b_new = fp16_to_fp32(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp32mul(a_new, b_new);
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t bf16mul_resfp32(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7);
  fp_general_t a_new = bf16_to_fp32(a, true);
  fp_general_t b_new = bf16_to_fp32(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp32mul(a_new, b_new);
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t bf16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  bool is_inf = isINFGeneralUI(a, 8, 7) || isINFGeneralUI(b, 8, 7) ||
                isINFGeneralUI(c, 8, 7);
  bfloat16_t a_new;
  bfloat16_t b_new;
  bfloat16_t c_new;
  a_new.v = (uint16_t)a;
  b_new.v = (uint16_t)b;
  c_new.v = (uint16_t)b;
  softfloat_exceptionFlags = 0;
  fp_general_t res = bf16_mulAdd(a_new, b_new, c_new).v;
  alu_output_exam(res, 8, 7, is_inf);
  return res;
}

fp_general_t fp24fp16add(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 5, 10);
  float64_t f64A;
  float64_t f64B;
  float16_t f16B;
  f16B.v = b;
  f64A.v = fp24_to_fp64(a, true);
  f64B = f16_to_f64(f16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_add(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24fp16sub(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 5, 10);
  float64_t f64A;
  float64_t f64B;
  float16_t f16B;
  f16B.v = b;
  f64A.v = fp24_to_fp64(a, true);
  f64B = f16_to_f64(f16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_sub(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24fp16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 5, 10);
  float64_t f64A;
  float64_t f64B;
  float16_t f16B;
  f16B.v = b;
  f64A.v = fp24_to_fp64(a, true);
  f64B = f16_to_f64(f16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp24bf16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 15) || isINFGeneralUI(b, 8, 7);
  float64_t f64A;
  float64_t f64B;
  float16_t f16B;
  f16B.v = b;
  f64A.v = fp24_to_fp64(a, true);
  f64B = bf16_to_f64(f16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32fp16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 5, 10);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  float16_t f16B;
  f32A.v = a;
  f16B.v = b;
  f64A = f32_to_f64(f32A);
  f64B = f16_to_f64(f16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32bf16mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 7);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  bfloat16_t bf16B;
  f32A.v = a;
  bf16B.v = b;
  f64A = f32_to_f64(f32A);
  f64B = bf16_to_f64(bf16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32fp24mul(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 15);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  f32A.v = a;
  f64A = f32_to_f64(f32A);
  f64B.v = fp24_to_fp64(b, true);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32bf16mul_resfp32(fp_general_t a, fp_general_t b, bool is_dop) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 7);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  bfloat16_t bf16B;
  f32A.v = a;
  bf16B.v = b;
  f64A = f32_to_f64(f32A);
  f64B = bf16_to_f64(bf16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp32(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t fp32mul_resfp24(fp_general_t a, fp_general_t b) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 23);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  float32_t f32B;
  f32A.v = a;
  f32B.v = b;
  f64A = f32_to_f64(f32A);
  f64B = f32_to_f64(f32B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp24(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 15, is_inf);
  return res;
}

fp_general_t fp32fp16mul_resfp32(fp_general_t a, fp_general_t b, bool is_dop) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 5, 10);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  bfloat16_t bf16B;
  f32A.v = a;
  bf16B.v = b;
  f64A = f32_to_f64(f32A);
  f64B = f16_to_f64(bf16B);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp32(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t fp32fp24mul_resfp32(fp_general_t a, fp_general_t b, bool is_dop) {
  bool is_inf = isINFGeneralUI(a, 8, 23) || isINFGeneralUI(b, 8, 15);
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  f32A.v = a;
  f64A = f32_to_f64(f32A);
  f64B.v = fp24_to_fp64(b);
  softfloat_exceptionFlags = 0;
  fp_general_t res = fp64_to_fp32(f64_mul(f64A, f64B).v, true);
  alu_output_exam(res, 8, 23, is_inf);
  return res;
}

fp_general_t fp32e8m0mul_resfp32(fp_general_t a, fp_general_t b, fp_general_t c,
                                 bool is_dop) {
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  f32A.v = a;
  f64A = f32_to_f64(f32A);
  f64B.v = 0x3ff0000000000000UL + (b << 52) + (c << 52) - (254UL << 52);

  return fp64_to_fp32(f64_mul(f64A, f64B).v, true);
}

fp_general_t fp32e8m0mul_resfp32(fp_general_t a, fp_general_t b, bool is_dop) {
  float64_t f64A;
  float64_t f64B;
  float32_t f32A;
  f32A.v = a;
  f64A = f32_to_f64(f32A);
  f64B.v = 0x3ff0000000000000UL + (b << 52) - (127UL << 52);
  fp_general_t kkk = f64_mul(f64A, f64B).v;

  return fp64_to_fp32(f64_mul(f64A, f64B).v, true);
}

void alu_output_exam(fp_general_t a, uint8_t exp_len, uint8_t sig_len,
                     bool is_inf) {
  if (isNaNGeneralUI(a, exp_len, sig_len)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return;
  }
  if (isINFGeneralUI(a, exp_len, sig_len)) {
    if (is_inf)
      cmodel_exceptionFlags |= softfloat_flag_infinite;
    else
      cmodel_exceptionFlags |= softfloat_flag_overflow;
    return;
  }
  if (softfloat_exceptionFlags & softfloat_flag_overflow) {
    cmodel_exceptionFlags |= softfloat_flag_overflow;
  }
  if ((softfloat_exceptionFlags & softfloat_flag_underflow) &&
      ((a & ((1 << sig_len + exp_len) - 1)) == 0)) {
    cmodel_exceptionFlags |= softfloat_flag_underflow;
  }
  softfloat_exceptionFlags = 0;
}

void convert_input_exam(fp_general_t a, uint8_t exp_len, uint8_t sig_len,
                        bool is_innner_use) {
  if (is_innner_use)
    return;
  if (isNaNGeneralUI(a, exp_len, sig_len)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return;
  }
  if (isINFGeneralUI(a, exp_len, sig_len)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return;
  }
}

void convert_output_exam(fp_general_t input, fp_general_t output,
                         uint8_t exp_len, uint8_t sig_len, bool is_innner_use) {
  if (is_innner_use)
    return;
  if ((input & ((1 << exp_len + sig_len) - 1)) && !output &&
      !isNaNGeneralUI(input, exp_len, sig_len)) {
    cmodel_exceptionFlags |= softfloat_flag_underflow;
    return;
  }
  if (softfloat_exceptionFlags & softfloat_flag_invalid) {
    cmodel_exceptionFlags |= softfloat_flag_overflow;
  }
}

} // namespace operators