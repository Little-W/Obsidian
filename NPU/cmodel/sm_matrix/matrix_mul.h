#ifndef _matrix_mul_h
#define _matrix_mul_h

#include "dop_ops.h"
#include "matrix_opcode.h"
#include "matrix_struct.h"
#include "pproc_opcode.h"
#include <cstddef> // 包含 size_t 类型
#include <cstdint> // 包含 uint32_t, uint8_t 等类型

namespace operators {
void matmul_subcmd_128_k(uint16_t **&mat_a, uint16_t **&mat_b,
                         uint64_t **dst_mat, int common_k, int mat_a_nr,
                         int mat_b_nc, DataType datatype);

void matmul_subcmd_128_k_T(uint16_t **&mat_a, uint16_t **&mat_b,
                           uint64_t **dst_mat, int common_k, int mat_a_nr,
                           int mat_b_nc, DataType datatype);

void matmul_subcmd_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             matrix_opcode *matrix_opcode);

void matmul_subcmd_T_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                               uint64_t **dst_mat, uint16_t **a_scale,
                               uint16_t **b_scale, int common_k, int mat_a_m,
                               int mat_b_n, DataType datatype,
                               matrix_opcode *matrix_opcode);

void matmul_subcmd_sym_quant_raw_scale(uint16_t **mat_a, uint16_t **mat_b,
                                       uint64_t **dst_mat, uint16_t **a_scale,
                                       uint16_t **b_scale, int common_k,
                                       int mat_a_m, int mat_b_n,
                                       DataType datatype,
                                       matrix_opcode *matrix_opcode,
                                       int b_scale_row, int b_scale_col);
uint8_t get_dop_blocksize(DataType datatype);
fp_general_t vector_sum(fp_general_t a, fp_general_t b);

void otile_to_mn(size_t otile_count, size_t otile_inner_i, size_t otile_inner_j,
                 DataType data_type, size_t m_size, size_t n_size,
                 otile_location_t &otile_location);
void matmul_subcmd_for_log(uint16_t **mat_a, uint16_t **mat_b,
                           uint64_t **dst_mat, uint16_t **a_scale,
                           uint16_t **b_scale, int common_k, int mat_a_m,
                           int mat_b_n, DataType datatype,
                           matrix_opcode *matrix_opcode, int b_scale_row,
                           int b_scale_col, otile_location_t &otile_location);
void matmul_subcmd_T_for_log(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             matrix_opcode *matrix_opcode, int m_count_i,
                             int n_count_j);

} // namespace operators

#endif