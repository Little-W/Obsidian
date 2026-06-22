#include "dop_ops.h"

namespace operators {
void fp24cmp(fp_general_t &a, fp_general_t &b) {
  if ((a & 0x7fffff) == 0 && (b & 0x7fffff) == 0) {
    return;
  }
  if (isNaNGeneralUI(a, 8, 15) || isNaNGeneralUI(b, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return;
  }
  fp_general_t temp_a = a;
  fp_general_t temp_b = b;
  a = fp24max(temp_a, temp_b);
  b = fp24min(temp_a, temp_b);
}

fp_general_t fp24max(fp_general_t a, fp_general_t b) {
  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = fp24_to_fp32(a, true);
  b_32_t.v = fp24_to_fp32(b, true);
  fp_general_t res = fp32_to_fp24(f32_max(a_32_t, b_32_t).v, true);
  cmp_exception_exam(a, b, res, 8, 15);
  return res;
}

fp_general_t fp24min(fp_general_t a, fp_general_t b) {
  if (isNaNF24UI(a) | isNaNF24UI(b)) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return defaultNANGeneralUI(8, 15);
  }

  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = fp24_to_fp32(a, true);
  b_32_t.v = fp24_to_fp32(b, true);
  fp_general_t res = fp32_to_fp24(f32_min(a_32_t, b_32_t).v, true);
  cmp_exception_exam(b, a, res, 8, 15);
  return res;
}

fp_general_t fp24_0_max(fp_general_t a) {
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  }
  return fp24max(a, 0);
}

fp_general_t fp24_6_min(fp_general_t a) {
  if (isINFGeneralUI(a, 8, 15)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  }
  return fp24min(a, 0x40c000);
}

fp_general_t bf16max(fp_general_t a, fp_general_t b) {
  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = bf16_to_fp32(a, true);
  b_32_t.v = bf16_to_fp32(b, true);
  fp_general_t res = fp32_to_bf16(f32_max(a_32_t, b_32_t).v, true);
  cmp_exception_exam(a, b, res, 8, 7);
  return res;
}

fp_general_t bf16min(fp_general_t a, fp_general_t b) {
  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = bf16_to_fp32(a, true);
  b_32_t.v = bf16_to_fp32(b, true);
  fp_general_t res = fp32_to_bf16(f32_min(a_32_t, b_32_t).v, true);
  cmp_exception_exam(b, a, res, 8, 7);
  return res;
}

fp_general_t bf16_0_max(fp_general_t a) {
  if (isINFGeneralUI(a, 8, 7)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  }
  return bf16max(a, 0);
}
fp_general_t bf16_6_min(fp_general_t a) {
  if (isINFGeneralUI(a, 8, 7)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  }
  return bf16min(a, 0x40c0);
}

fp_general_t fp16max(fp_general_t a, fp_general_t b) {
  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = fp16_to_fp32(a, true);
  b_32_t.v = fp16_to_fp32(b, true);
  fp_general_t res = fp32_to_fp16(f32_max(a_32_t, b_32_t).v, true);
  cmp_exception_exam(a, b, res, 5, 10);
  return res;
}

fp_general_t fp16min(fp_general_t a, fp_general_t b) {
  float32_t a_32_t;
  float32_t b_32_t;
  a_32_t.v = fp16_to_fp32(a, true);
  b_32_t.v = fp16_to_fp32(b, true);
  fp_general_t res = fp32_to_fp16(f32_min(a_32_t, b_32_t).v, true);
  cmp_exception_exam(b, a, res, 5, 10);
  return res;
}

fp_general_t fp16_0_max(fp_general_t a) { return fp16max(a, 0); }
fp_general_t fp16_6_min(fp_general_t a) { return fp16min(a, 0x4640); }

// put a,b,res while max_alu, put b,a,res while min_alu
void cmp_exception_exam(fp_general_t a, fp_general_t b, fp_general_t &res,
                        uint16_t exp_len, uint16_t frac_len) {
  if (isNaNGeneralUI(a, exp_len, frac_len) |
      isNaNGeneralUI(b, exp_len, frac_len)) {
    res = defaultNANGeneralUI(exp_len, frac_len);
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return;
  }
}
} // namespace operators