#ifndef DOP_ADD16_H // 防止头文件被重复包含
#define DOP_ADD16_H

#include "dop_utils.h"
#include "sm_data_struct.h"
#include <cstddef> // 包含 size_t 类型
#include <cstdint> // 包含 uint32_t, uint8_t 等类型
#include <stdio.h>
#include <functional>
namespace operators {
// 声明函数
uint64_t dop_add(FP16MulIntermediate *uiA, size_t num_elements, uint8_t rnd,
                 DataType data_type);
FP16MulIntermediate dop16_mul(uint16_t a, uint16_t b, DataType data_type);

uint64_t dop_product_non_sym(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type);
uint64_t dop_product(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                     DataType data_type, uint16_t *scaleA, uint16_t *scaleB);
uint64_t dop_product_scale32(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type, uint32_t *scaleA,
                             uint16_t *scaleB);
uint64_t dop_product_sym_quant(uint16_t *uiA, uint16_t *uiB,
                               size_t num_elements, DataType data_type,
                               uint32_t *scaleA, uint16_t *scaleB);
fp_general_t dop_add_nvfp4(uint16_t *a, uint16_t *b, uint16_t *a_scale,
                           uint16_t *b_scale, size_t num_elements,
                           size_t step_size);
fp_general_t dop_add_mxfp4(uint16_t *a, uint16_t *b, uint16_t *a_scale,
                           uint16_t *b_scale, size_t num_elements,
                           size_t step_size);
fp_general_t dop_add_int16int4(uint16_t *a, uint16_t *b, uint16_t *shift_num,
                               uint16_t *b_scale, size_t num_elements);

fp_general_t low_to_high(fp_general_t a, int low_exp_len, int low_sig_len,
                         int high_exp_len, int high_sig_len);
fp_general_t high_to_low(fp_general_t a, int low_exp_len, int low_sig_len,
                         int high_exp_len, int high_sig_len,
                         bool is_dop = false);
// FP8 conversion Func
fp_general_t fp8e4m3_to_fp32(fp_general_t a);
fp_general_t fp32_to_fp8e4m3(fp_general_t a);
fp_general_t f24_to_nvfp4_e2m1(fp_general_t a); // instead high_to_low
fp_general_t fp24_to_fp4e2m1(fp_general_t a, bool is_innner_use = false);
fp_general_t nvfp4_to_f32(fp_general_t a);

fp_general_t fp32_to_fp32(fp_general_t a);
fp_general_t fp24_to_fp32(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_fp24(fp_general_t a, bool is_innner_use = false);
fp_general_t fp16_to_fp24(fp_general_t a, bool is_innner_use = false);
fp_general_t fp24_to_fp16(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_fp16(fp_general_t a, bool is_innner_use = false);
fp_general_t fp16_to_fp32(fp_general_t a, bool is_innner_use = false);
fp_general_t fp24_to_fp64(fp_general_t a, bool is_innner_use = false);
fp_general_t fp64_to_fp24(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_fp64(fp_general_t a, bool is_innner_use = false);
fp_general_t fp64_to_fp32(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_bf16(fp_general_t a, bool is_innner_use = false);
fp_general_t bf16_to_fp32(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_fp8e5(fp_general_t a, bool is_innner_use = false);
fp_general_t fp8e5_to_fp32(fp_general_t a, bool is_innner_use = false);
fp_general_t fp32_to_fp8e4(fp_general_t a);
fp_general_t fp8e4_to_fp32(fp_general_t a);

fp_general_t bf16_to_fp24(fp_general_t a, bool is_innner_use = false);
fp_general_t fp24_to_bf16(fp_general_t a, bool is_innner_use = false);
fp_general_t bf16_to_fp16(fp_general_t a, bool is_innner_use = false);
fp_general_t fp16_to_bf16(fp_general_t a, bool is_innner_use = false);

float32_t int16_to_fp32(int32_t a);
int_fast16_t fp32_to_int16(float32_t a);

fp_general_t int40_to_fp24(fp_general_t a);
fp_general_t int40_to_fp32(fp_general_t a);
fp_general_t int32_to_bf16(fp_general_t a);
fp_general_t int8_to_fp16(fp_general_t a);
fp_general_t uint8_to_fp16(fp_general_t a);
fp_general_t int8_to_bf16(fp_general_t a);
fp_general_t uint8_to_bf16(fp_general_t a);
fp_general_t int16_to_fp16(fp_general_t a);
fp_general_t uint16_to_fp16(fp_general_t a);
fp_general_t int_convert(fp_general_t a, uint8_t raw_sign_len,
                         uint8_t raw_full_len, uint8_t dest_len);
fp_general_t sint28_to_sint40(fp_general_t a);
fp_general_t sint40sint28_add(fp_general_t a, fp_general_t b);
fp_general_t sint40_add(fp_general_t a, fp_general_t b);

fp_general_t int4_to_f64(fp_general_t a);
fp_general_t uint4_to_f64(fp_general_t a);

fp_general_t f24_to_i32(fp_general_t a);
fp_general_t f24_to_i16(fp_general_t a);
fp_general_t f24_to_i8(fp_general_t a);
fp_general_t f24_to_u32(fp_general_t a);
fp_general_t f24_to_u16(fp_general_t a);
fp_general_t f24_to_u8(fp_general_t a);

fp_general_t i24_to_f24(fp_general_t a);
fp_general_t i16_to_f24(fp_general_t a);
fp_general_t i8_to_f24(fp_general_t a);
fp_general_t u24_to_f24(fp_general_t a);
fp_general_t u16_to_f24(fp_general_t a);
fp_general_t u8_to_f24(fp_general_t a);

fp_general_t f32_to_i8(fp_general_t a);
fp_general_t f32_to_u8(fp_general_t a);

fp_general_t fp16add(fp_general_t a, fp_general_t b);
fp_general_t fp16sub(fp_general_t a, fp_general_t b);
fp_general_t fp16mul(fp_general_t a, fp_general_t b);
fp_general_t fp16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c);
fp_general_t fp24add(fp_general_t a, fp_general_t b);
fp_general_t fp24sub(fp_general_t a, fp_general_t b);
fp_general_t fp24mul(fp_general_t a, fp_general_t b);
fp_general_t fp24mulAdd(fp_general_t a, fp_general_t b, fp_general_t c);
fp_general_t fp32add(fp_general_t a, fp_general_t b, bool is_dop = false);
fp_general_t fp32sub(fp_general_t a, fp_general_t b);
fp_general_t fp32mul(fp_general_t a, fp_general_t b);
fp_general_t fp32mulAdd(fp_general_t a, fp_general_t b, fp_general_t c);
fp_general_t bf16add(fp_general_t a, fp_general_t b);
fp_general_t bf16sub(fp_general_t a, fp_general_t b);
fp_general_t bf16mul(fp_general_t a, fp_general_t b);
fp_general_t bf16mulAdd(fp_general_t a, fp_general_t b, fp_general_t c);
fp_general_t bf16mul_resfp24(fp_general_t a, fp_general_t b);
fp_general_t bf16mul_resfp32(fp_general_t a, fp_general_t b);
fp_general_t fp16mul_resfp32(fp_general_t a, fp_general_t b);

// func below returns fp24
fp_general_t fp24fp16add(fp_general_t a, fp_general_t b);
fp_general_t fp24fp16sub(fp_general_t a, fp_general_t b);
fp_general_t fp24fp16mul(fp_general_t a, fp_general_t b);
fp_general_t fp24bf16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32fp16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32bf16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32fp24mul(fp_general_t a, fp_general_t b);
fp_general_t fp32mul_resfp24(fp_general_t a, fp_general_t b);
fp_general_t fp32fp16mul_resfp32(fp_general_t a, fp_general_t b,
                                 bool is_dop = false);
fp_general_t fp32bf16mul_resfp32(fp_general_t a, fp_general_t b,
                                 bool is_dop = false);
fp_general_t fp32fp24mul_resfp32(fp_general_t a, fp_general_t b,
                                 bool is_dop = false);
fp_general_t fp32e8m0mul_resfp32(fp_general_t a, fp_general_t b, fp_general_t c,
                                 bool is_dop);
fp_general_t fp32e8m0mul_resfp32(fp_general_t a, fp_general_t b, bool is_dop);

void fp24cmp(fp_general_t &a, fp_general_t &b);
fp_general_t fp24max(fp_general_t a, fp_general_t b);
fp_general_t fp24min(fp_general_t a, fp_general_t b);
fp_general_t fp24_0_max(fp_general_t a);
fp_general_t fp24_6_min(fp_general_t a);

fp_general_t bf16max(fp_general_t a, fp_general_t b);
fp_general_t bf16min(fp_general_t a, fp_general_t b);
fp_general_t bf16_0_max(fp_general_t a);
fp_general_t bf16_6_min(fp_general_t a);

fp_general_t fp16max(fp_general_t a, fp_general_t b);
fp_general_t fp16min(fp_general_t a, fp_general_t b);
fp_general_t fp16_0_max(fp_general_t a);
fp_general_t fp16_6_min(fp_general_t a);

void alu_output_exam(fp_general_t a, uint8_t exp_len, uint8_t sig_len,
                     bool is_inf = true);
void convert_input_exam(fp_general_t a, uint8_t exp_len, uint8_t sig_len,
                        bool is_innner_use = false);
void convert_output_exam(fp_general_t input, fp_general_t output,
                         uint8_t exp_len, uint8_t sig_len,
                         bool is_innner_use = false);
void cmp_exception_exam(fp_general_t a, fp_general_t b, fp_general_t &res,
                        uint16_t exp_len, uint16_t frac_len);
void int_type_check(bool &is_int, DataType datatype);

} // namespace operators

#endif // DOP_ADD16_H