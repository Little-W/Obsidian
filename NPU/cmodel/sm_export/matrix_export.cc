#include "cmodel.h"
#include "matrix_mul.h"
#include "matrix_opcode.h"
#include "pproc_func.h"
#include "pproc_opcode.h"
#include "sm_data_struct.h"

void matmul_subcmd_128_k(uint16_t **&mat_a, uint16_t **&mat_b,
                         uint64_t **dst_mat, int common_k, int mat_a_nr,
                         int mat_b_nc, DataType datatype) {
  // operators::matrix_opcode_mat a;
  operators::matmul_subcmd_128_k(mat_a, mat_b, dst_mat, common_k, mat_a_nr,
                                 mat_b_nc, datatype);
}

void matmul_subcmd_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             uint64_t mat_opcode) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(mat_opcode);
  operators::matmul_subcmd_sym_quant(mat_a, mat_b, dst_mat, a_scale, b_scale,
                                     common_k, mat_a_m, mat_b_n, datatype,
                                     matrix_opcode);
  delete matrix_opcode;
}

void matmul_subcmd_sym_quant_raw_scale(uint16_t **mat_a, uint16_t **mat_b,
                                       uint64_t **dst_mat, uint16_t **a_scale,
                                       uint16_t **b_scale, int common_k,
                                       int mat_a_m, int mat_b_n,
                                       DataType datatype, uint64_t mat_opcode,
                                       int b_scale_row, int b_scale_col) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(mat_opcode);
  operators::matmul_subcmd_sym_quant_raw_scale(
      mat_a, mat_b, dst_mat, a_scale, b_scale, common_k, mat_a_m, mat_b_n,
      datatype, matrix_opcode, b_scale_row, b_scale_col);
  delete matrix_opcode;
}

void matmul_pproc_for_validate(
    uint16_t **mat_a, uint16_t **mat_b, uint64_t **dst_mat, uint16_t **a_scale,
    uint16_t **b_scale, int common_k, int mat_a_m, int mat_b_n,
    DataType datatype, uint64_t mat_opcode, int b_scale_row, int b_scale_col,
    uint16_t *params, uint64_t enmode, uint64_t datainfo, uint64_t maskinfo,
    uint16_t **elw, uint32_t **des) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(mat_opcode);
  operators::matmul_subcmd_sym_quant_raw_scale(
      mat_a, mat_b, dst_mat, a_scale, b_scale, common_k, mat_a_m, mat_b_n,
      datatype, matrix_opcode, b_scale_row, b_scale_col);

  pproc_subcmd(params, enmode, datainfo, maskinfo, dst_mat, elw, des, mat_a_m,
               mat_b_n);
  delete matrix_opcode;
}

void otile_to_mn_c(size_t otile_count, size_t otile_inner_i,
                   size_t otile_inner_j, DataType data_type, size_t m_size,
                   size_t n_size, operators::otile_location_t &otile_location) {
  operators::otile_to_mn(otile_count, otile_inner_i, otile_inner_j, data_type,
                         m_size, n_size, otile_location);
}
void matmul_subcmd_log(uint16_t **mat_a, uint16_t **mat_b, uint64_t **dst_mat,
                       uint16_t **a_scale, uint16_t **b_scale, int common_k,
                       int mat_a_m, int mat_b_n, DataType datatype,
                       uint64_t mat_opcode, int b_scale_row, int b_scale_col,
                       operators::otile_location_t &otile_location) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(mat_opcode);
  operators::matmul_subcmd_for_log(
      mat_a, mat_b, dst_mat, a_scale, b_scale, common_k, mat_a_m, mat_b_n,
      datatype, matrix_opcode, b_scale_row, b_scale_col, otile_location);
  delete matrix_opcode;
}