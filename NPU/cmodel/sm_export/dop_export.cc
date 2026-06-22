#include "cmodel.h"
#include "dop_ops.h"
#include "sm_data_struct.h"

THREAD_LOCAL uint_fast8_t &cm_exceptionFlags = operators::cmodel_exceptionFlags;

uint64_t dop_product_non_sym(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type) {
  return operators::dop_product_non_sym(uiA, uiB, num_elements, data_type);
}
uint64_t dop_product_all(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                         DataType data_type, uint16_t *scaleA,
                         uint16_t *scaleB) {
  return operators::dop_product(uiA, uiB, num_elements, data_type, scaleA,
                                scaleB);
}
uint64_t dop_product_sym_quant(uint16_t *uiA, uint16_t *uiB,
                               size_t num_elements, DataType data_type,
                               uint32_t *scaleA, uint16_t *scaleB) {
  return operators::dop_product_sym_quant(uiA, uiB, num_elements, data_type,
                                          scaleA, scaleB);
}

fp_general_t fp24_to_fp32(fp_general_t a) { return operators::fp24_to_fp32(a); }
fp_general_t fp32_to_fp24(fp_general_t a) { return operators::fp32_to_fp24(a); }

fp_general_t fp16_to_fp24(fp_general_t a) { return operators::fp16_to_fp24(a); }
fp_general_t fp24_to_fp16(fp_general_t a) { return operators::fp24_to_fp16(a); }

fp_general_t fp32_to_fp16(fp_general_t a) { return operators::fp32_to_fp16(a); }
fp_general_t fp16_to_fp32(fp_general_t a) { return operators::fp16_to_fp32(a); }

fp_general_t fp24_to_fp64(fp_general_t a) { return operators::fp24_to_fp64(a); }
fp_general_t fp64_to_fp24(fp_general_t a) { return operators::fp64_to_fp24(a); }

fp_general_t fp32_to_fp64(fp_general_t a) { return operators::fp32_to_fp64(a); }
fp_general_t fp64_to_fp32(fp_general_t a) { return operators::fp64_to_fp32(a); }
fp_general_t fp32_to_bf16(fp_general_t a) { return operators::fp32_to_bf16(a); }
fp_general_t bf16_to_fp32(fp_general_t a) { return operators::bf16_to_fp32(a); }

fp_general_t bf16_to_fp24(fp_general_t a) { return operators::bf16_to_fp24(a); }
fp_general_t fp24_to_bf16(fp_general_t a) { return operators::fp24_to_bf16(a); }
fp_general_t bf16_to_fp16(fp_general_t a) { return operators::bf16_to_fp16(a); }
fp_general_t fp16_to_bf16(fp_general_t a) { return operators::fp16_to_bf16(a); }

fp_general_t fp32_to_fp8e5(fp_general_t a) {
  return operators::fp32_to_fp8e5(a);
}
fp_general_t fp8e5_to_fp32(fp_general_t a) {
  return operators::fp8e5_to_fp32(a);
}
fp_general_t fp32_to_fp8e4(fp_general_t a) {
  return operators::fp32_to_fp8e4(a);
}
fp_general_t fp8e4_to_fp32(fp_general_t a) {
  return operators::fp8e4_to_fp32(a);
}

uint32_t int16_to_fp32(int32_t a) { return operators::int16_to_fp32(a).v; }
int16_t fp32_to_int16(uint32_t a) {
  float32_t f;
  f.v = a;
  return operators::fp32_to_int16(f);
}

fp_general_t int40_to_fp24(fp_general_t a) {
  return operators::int40_to_fp24(a);
}
fp_general_t int40_to_fp32(fp_general_t a) {
  return operators::int40_to_fp32(a);
}
fp_general_t int32_to_bf16(fp_general_t a) {
  return operators::int32_to_bf16(a);
}
fp_general_t int8_to_fp16(fp_general_t a) { return operators::int8_to_fp16(a); }
fp_general_t uint8_to_fp16(fp_general_t a) {
  return operators::uint8_to_fp16(a);
}
fp_general_t int8_to_bf16(fp_general_t a) { return operators::int8_to_bf16(a); }
fp_general_t uint8_to_bf16(fp_general_t a) {
  return operators::uint8_to_bf16(a);
}
fp_general_t int16_to_fp16(fp_general_t a) {
  return operators::int16_to_fp16(a);
}
fp_general_t uint16_to_fp16(fp_general_t a) {
  return operators::uint16_to_fp16(a);
}

fp_general_t f24_to_i32(fp_general_t a) { return operators::f24_to_i32(a); }
fp_general_t f24_to_i16(fp_general_t a) { return operators::f24_to_i16(a); }
fp_general_t f24_to_i8(fp_general_t a) { return operators::f24_to_i8(a); }
fp_general_t f24_to_u32(fp_general_t a) { return operators::f24_to_u32(a); }
fp_general_t f24_to_u16(fp_general_t a) { return operators::f24_to_u16(a); }
fp_general_t f24_to_u8(fp_general_t a) { return operators::f24_to_u8(a); }

fp_general_t i24_to_f24(fp_general_t a) { return operators::i24_to_f24(a); }
fp_general_t i16_to_f24(fp_general_t a) { return operators::i16_to_f24(a); }
fp_general_t i8_to_f24(fp_general_t a) { return operators::i8_to_f24(a); }
fp_general_t u24_to_f24(fp_general_t a) { return operators::u24_to_f24(a); }
fp_general_t u16_to_f24(fp_general_t a) { return operators::u16_to_f24(a); }
fp_general_t u8_to_f24(fp_general_t a) { return operators::u8_to_f24(a); }

fp_general_t f32_to_i8(fp_general_t a) { return operators::f32_to_i8(a); }
fp_general_t f32_to_u8(fp_general_t a) { return operators::f32_to_u8(a); }

fp_general_t fp16add(fp_general_t a, fp_general_t b) {
  return operators::fp16add(a, b);
}
fp_general_t fp16sub(fp_general_t a, fp_general_t b) {
  return operators::fp16sub(a, b);
}
fp_general_t fp16mul(fp_general_t a, fp_general_t b) {
  return operators::fp16mul(a, b);
}
fp_general_t fp16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  return operators::fp16mulAdd(a, b, c);
}
fp_general_t fp24add(fp_general_t a, fp_general_t b) {
  return operators::fp24add(a, b);
}
fp_general_t fp24sub(fp_general_t a, fp_general_t b) {
  return operators::fp24sub(a, b);
}
fp_general_t fp24mul(fp_general_t a, fp_general_t b) {
  return operators::fp24mul(a, b);
}
fp_general_t fp24mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  return operators::fp24mulAdd(a, b, c);
}
fp_general_t fp32add(fp_general_t a, fp_general_t b) {
  return operators::fp32add(a, b);
}
fp_general_t fp32sub(fp_general_t a, fp_general_t b) {
  return operators::fp32sub(a, b);
}
fp_general_t fp32mul(fp_general_t a, fp_general_t b) {
  return operators::fp32mul(a, b);
}
fp_general_t fp32mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  return operators::fp32mulAdd(a, b, c);
}
fp_general_t bf16add(fp_general_t a, fp_general_t b) {
  return operators::bf16add(a, b);
}
fp_general_t bf16sub(fp_general_t a, fp_general_t b) {
  return operators::bf16sub(a, b);
}
fp_general_t bf16mul(fp_general_t a, fp_general_t b) {
  return operators::bf16mul(a, b);
}
fp_general_t bf16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c) {
  return operators::bf16mulAdd(a, b, c);
}
fp_general_t bf16mul_resfp24(fp_general_t a, fp_general_t b) {
  return operators::bf16mul_resfp24(a, b);
}
fp_general_t bf16mul_resfp32(fp_general_t a, fp_general_t b) {
  return operators::bf16mul_resfp32(a, b);
}
fp_general_t fp16mul_resfp32(fp_general_t a, fp_general_t b) {
  return operators::fp16mul_resfp32(a, b);
}

fp_general_t fp24fp16add(fp_general_t a, fp_general_t b) {
  return operators::fp24fp16add(a, b);
}
fp_general_t fp24fp16sub(fp_general_t a, fp_general_t b) {
  return operators::fp24fp16sub(a, b);
}
fp_general_t fp24fp16mul(fp_general_t a, fp_general_t b) {
  return operators::fp24fp16mul(a, b);
}
fp_general_t fp24bf16mul(fp_general_t a, fp_general_t b) {
  return operators::fp24bf16mul(a, b);
}
fp_general_t fp32fp16mul(fp_general_t a, fp_general_t b) {
  return operators::fp32fp16mul(a, b);
}
fp_general_t fp32bf16mul(fp_general_t a, fp_general_t b) {
  return operators::fp32bf16mul(a, b);
}
fp_general_t fp32fp24mul(fp_general_t a, fp_general_t b) {
  return operators::fp32fp24mul(a, b);
}
fp_general_t fp32bf16mul_resfp32(fp_general_t a, fp_general_t b) {
  return operators::fp32bf16mul_resfp32(a, b);
}
fp_general_t fp32fp24mul_resfp32(fp_general_t a, fp_general_t b) {
  return operators::fp32fp24mul_resfp32(a, b);
}

void fp24cmp(fp_general_t &a, fp_general_t &b) { operators::fp24cmp(a, b); }
fp_general_t fp24max(fp_general_t a, fp_general_t b) {
  return operators::fp24max(a, b);
}
fp_general_t fp24min(fp_general_t a, fp_general_t b) {
  return operators::fp24min(a, b);
}
fp_general_t fp24_0_max(fp_general_t a) { return operators::fp24_0_max(a); }
fp_general_t fp24_6_min(fp_general_t a) { return operators::fp24_6_min(a); }

fp_general_t bf16max(fp_general_t a, fp_general_t b) {
  return operators::bf16max(a, b);
}
fp_general_t bf16min(fp_general_t a, fp_general_t b) {
  return operators::bf16min(a, b);
}
fp_general_t bf16_0_max(fp_general_t a) { return operators::bf16_0_max(a); }
fp_general_t bf16_6_min(fp_general_t a) { return operators::bf16_6_min(a); }

fp_general_t fp16max(fp_general_t a, fp_general_t b) {
  return operators::fp16max(a, b);
}
fp_general_t fp16min(fp_general_t a, fp_general_t b) {
  return operators::fp16min(a, b);
}
fp_general_t fp16_0_max(fp_general_t a) { return operators::fp16_0_max(a); }
fp_general_t fp16_6_min(fp_general_t a) { return operators::fp16_6_min(a); }