#ifndef _cmodel_h_
#define _cmodel_h_

#include "matrix_struct.h"
#include "pproc_opcode.h"
#include "sm_datatype_utils.h"
#include <unistd.h>

extern THREAD_LOCAL uint_fast8_t &cm_exceptionFlags;

#if defined(__cplusplus) && defined(USE_EXTERN_C)
extern "C" {
#endif

uint64_t dop_product_non_sym(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type); // 不带量化的整型和浮点型dop
uint64_t dop_product_all(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                         DataType data_type, uint16_t *scaleA,
                         uint16_t *scaleB); // SINT16SIN8,NVFP4E2,dop_add_mxfp4
uint64_t dop_product_sym_quant(uint16_t *uiA, uint16_t *uiB,
                               size_t num_elements, DataType data_type,
                               uint32_t *scaleA,
                               uint16_t *scaleB); // dp type 0~7,带量化

fp_general_t fp24_to_fp32(fp_general_t a);
fp_general_t fp32_to_fp24(fp_general_t a);
fp_general_t fp16_to_fp24(fp_general_t a);
fp_general_t fp24_to_fp16(fp_general_t a);
fp_general_t fp32_to_fp16(fp_general_t a);
fp_general_t fp16_to_fp32(fp_general_t a);
fp_general_t fp24_to_fp64(fp_general_t a);
fp_general_t fp64_to_fp24(fp_general_t a);
fp_general_t fp32_to_fp64(fp_general_t a);
fp_general_t fp64_to_fp32(fp_general_t a);
fp_general_t fp32_to_bf16(fp_general_t a);
fp_general_t bf16_to_fp32(fp_general_t a);
fp_general_t bf16_to_fp24(fp_general_t a);
fp_general_t fp24_to_bf16(fp_general_t a);
fp_general_t bf16_to_fp16(fp_general_t a);
fp_general_t fp16_to_bf16(fp_general_t a);

fp_general_t fp32_to_fp8e5(fp_general_t a);
fp_general_t fp8e5_to_fp32(fp_general_t a);
fp_general_t fp32_to_fp8e4(fp_general_t a);
fp_general_t fp8e4_to_fp32(fp_general_t a);

uint32_t int16_to_fp32(int32_t a);
int16_t fp32_to_int16(uint32_t a);

fp_general_t int40_to_fp24(fp_general_t a);
fp_general_t int40_to_fp32(fp_general_t a);
fp_general_t int32_to_bf16(fp_general_t a);
fp_general_t int8_to_fp16(fp_general_t a);
fp_general_t uint8_to_fp16(fp_general_t a);
fp_general_t int8_to_bf16(fp_general_t a);
fp_general_t uint8_to_bf16(fp_general_t a);
fp_general_t int16_to_fp16(fp_general_t a);
fp_general_t uint16_to_fp16(fp_general_t a);

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
fp_general_t fp32add(fp_general_t a, fp_general_t b);
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

fp_general_t fp24fp16add(fp_general_t a, fp_general_t b);
fp_general_t fp24fp16sub(fp_general_t a, fp_general_t b);
fp_general_t fp24fp16mul(fp_general_t a, fp_general_t b);
fp_general_t fp24bf16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32fp16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32bf16mul(fp_general_t a, fp_general_t b);
fp_general_t fp32fp24mul(fp_general_t a, fp_general_t b);
fp_general_t fp32bf16mul_resfp32(fp_general_t a, fp_general_t b);
fp_general_t fp32fp24mul_resfp32(fp_general_t a, fp_general_t b);

uint32_t sfu_func_fp32(uint32_t uiA, uint8_t opcode = 0);
uint16_t sfu_func_fp16(uint16_t uiA, uint8_t opcode = 0);

int16_t radix4_booth_multiplier(int16_t multiplicand, int16_t multiplier,
                                int multiplicand_width, int multiplier_width,
                                int out_width);

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

fp_general_t fp16max(fp_general_t a, fp_general_t b);
fp_general_t fp16min(fp_general_t a, fp_general_t b);
fp_general_t fp16_0_max(fp_general_t a);
fp_general_t fp16_6_min(fp_general_t a);

fp_general_t fp16max(fp_general_t a, fp_general_t b);
fp_general_t fp16min(fp_general_t a, fp_general_t b);
fp_general_t fp16_0_max(fp_general_t a);
fp_general_t fp16_6_min(fp_general_t a);

void matmul_subcmd_128_k(uint16_t **&mat_a, uint16_t **&mat_b,
                         uint64_t **dst_mat, int common_k, int mat_a_nr,
                         int mat_b_nc, DataType datatype);
void matmul_subcmd_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             uint64_t mat_opcode);
void matmul_subcmd_sym_quant_raw_scale(uint16_t **mat_a, uint16_t **mat_b,
                                       uint64_t **dst_mat, uint16_t **a_scale,
                                       uint16_t **b_scale, int common_k,
                                       int mat_a_m, int mat_b_n,
                                       DataType datatype, uint64_t mat_opcode,
                                       int b_scale_row, int b_scale_col);

void pproc_subcmd(uint16_t *params, uint64_t enmode, uint64_t datainfo,
                  uint64_t maskinfo, uint64_t **res, uint16_t **elw,
                  uint32_t **des, uint32_t row, uint32_t column);

void matmul_pproc_for_validate(
    uint16_t **mat_a, uint16_t **mat_b, uint64_t **dst_mat, uint16_t **a_scale,
    uint16_t **b_scale, int common_k, int mat_a_m, int mat_b_n,
    DataType datatype, uint64_t mat_opcode, int b_scale_row, int b_scale_col,
    uint16_t *params, uint64_t enmode, uint64_t datainfo, uint64_t maskinfo,
    uint16_t **elw, uint32_t **des);

void conv_subcmd(uint64_t conv_opcode, uint8_t mat_a_m, uint8_t mat_b_n,
                 uint16_t common_k, uint16_t **mat_a, uint16_t **mat_b,
                 uint64_t **mat_reshape, DataType datatype);

void otile_to_mn_c(size_t otile_count, size_t otile_inner_i,
                   size_t otile_inner_j, DataType data_type, size_t m_size,
                   size_t n_size, operators::otile_location_t &otile_location);
void matmul_subcmd_log(uint16_t **mat_a, uint16_t **mat_b, uint64_t **dst_mat,
                       uint16_t **a_scale, uint16_t **b_scale, int common_k,
                       int mat_a_m, int mat_b_n, DataType datatype,
                       uint64_t mat_opcode, int b_scale_row, int b_scale_col,
                       operators::otile_location_t &otile_location);

#if defined(__cplusplus) && defined(USE_EXTERN_C)
}
#endif

#endif