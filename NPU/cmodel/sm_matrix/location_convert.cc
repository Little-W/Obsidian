#include "matrix_mul.h"
#include <fstream>

using namespace std;
namespace operators {

// all count start at 0 not 1
void otile_to_mn(size_t otile_count, size_t otile_inner_i, size_t otile_inner_j,
                 DataType data_type, size_t m_size, size_t n_size,
                 otile_location_t &otile_location) {
  fstream file;
  file.open("otile_log.txt", ios::out);
  otile_location.otile_count = otile_count;
  otile_location.otile_inner_i = otile_inner_i;
  otile_location.otile_inner_j = otile_inner_j;
  otile_location.data_type = data_type;
  otile_location.M_tile_size = (m_size - 1) / 8 + 1;
  otile_location.N_tile_size = (n_size - 1) / 8 + 1;
  otile_location.m_size = otile_location.M_tile_size * 8;
  otile_location.n_size = otile_location.N_tile_size * 8;

  size_t M_tile_count = 0;
  size_t N_tile_count = 0;
  size_t temp_value = 0;
  if (otile_location.M_tile_size % 2) {
    M_tile_count = otile_count / (otile_location.N_tile_size * 2);
    if (M_tile_count * 2 == otile_location.M_tile_size - 1) {
      temp_value = otile_count % (otile_location.N_tile_size);
      M_tile_count = M_tile_count * 2;
      N_tile_count = temp_value;
    } else {
      temp_value = otile_count % (otile_location.N_tile_size * 2);
      M_tile_count = M_tile_count * 2 + temp_value % 2;
      N_tile_count = temp_value / 2;
    }
  } else {
    M_tile_count = otile_count / (otile_location.N_tile_size * 2);
    temp_value = otile_count % (otile_location.N_tile_size * 2);
    M_tile_count = M_tile_count * 2 + temp_value % 2;
    N_tile_count = temp_value / 2;
  }
  otile_location.m = M_tile_count * 8 + otile_inner_i;
  otile_location.n = N_tile_count * 8 + otile_inner_j;
  otile_location.M_tile_count = M_tile_count;
  otile_location.N_tile_count = N_tile_count;

  file << "m location in dst mat: " << otile_location.m
       << " ====n location in dst mat: " << otile_location.n << endl;
  file << "cbuf_m: " << otile_location.M_tile_count
       << "====cbuf_n: " << otile_location.N_tile_count << endl;
  file.close();

  // printf("m,n:%d,%d\n", otile_location.m, otile_location.n);
  // printf("cbuf_m,cbuf_n:%d,%d\n", otile_location.M_tile_count,
  // otile_location.N_tile_count);
}

void matmul_subcmd_for_log(uint16_t **mat_a, uint16_t **mat_b,
                           uint64_t **dst_mat, uint16_t **a_scale,
                           uint16_t **b_scale, int common_k, int mat_a_m,
                           int mat_b_n, DataType datatype,
                           matrix_opcode *matrix_opcode, int b_scale_row,
                           int b_scale_col, otile_location_t &otile_location) {
  MATRIX_2D<uint16_t> *b_scale_T = new MATRIX_2D<uint16_t>();
  b_scale_T->transpose(b_scale, b_scale_col, b_scale_row, datatype);
  MATRIX_2D<uint16_t> *b_T = new MATRIX_2D<uint16_t>();
  b_T->transpose(mat_b, mat_b_n, common_k, datatype);
  matmul_subcmd_T_for_log(mat_a, b_T->data, dst_mat, a_scale, b_scale_T->data,
                          common_k, mat_a_m, mat_b_n, datatype, matrix_opcode,
                          otile_location.m, otile_location.n);
  b_T->~MATRIX_2D();
  delete b_T;
  b_scale_T->~MATRIX_2D();
  delete b_scale_T;
}

void matmul_subcmd_T_for_log(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             matrix_opcode *matrix_opcode, int m_count_i,
                             int n_count_j) {
  fstream file;
  file.open("otile_log.txt", ios::out);
  uint8_t dop_blocksize = get_dop_blocksize(datatype);
  uint8_t temp_dop_blocksize = dop_blocksize;
  matrix_opcode_mat *temp_opcode =
      dynamic_cast<matrix_opcode_mat *>(matrix_opcode);
  uint64_t temp_result;
  int act_k_block_size, act_m_block_size, wgt_k_block_size, wgt_n_block_size;
  if (temp_opcode->act_quant_mode) {
    act_k_block_size = 0 == temp_opcode->act_per_group_size
                           ? 32
                           : temp_opcode->act_per_group_size;
    act_m_block_size = 1;
  }
  if (1 == temp_opcode->weight_quant_mode) {
    wgt_k_block_size = 0 == temp_opcode->weight_per_block_size
                           ? 32
                           : temp_opcode->weight_per_block_size;
    wgt_n_block_size = 0 == temp_opcode->weight_per_block_size
                           ? 32
                           : temp_opcode->weight_per_block_size;
  } else if (2 == temp_opcode->weight_quant_mode) {
    wgt_k_block_size = temp_opcode->weight_per_group_size
                           ? temp_opcode->weight_per_group_size
                           : 32;
    wgt_n_block_size = 1;
  }

  bool is_int = false;
  int m_count = 0;
  int n_count = 0;
  int act_k_count = 0;
  int wgt_k_count = 0;
  bool need_padding = (bool)(common_k % dop_blocksize);
  uint8_t tail_blocksize =
      need_padding ? common_k % dop_blocksize : dop_blocksize;
  int_type_check(is_int, datatype);

  fp_general_t sum = 0;
  if (temp_opcode->act_quant_mode) {
    m_count = m_count_i / act_m_block_size;
  }
  if (temp_opcode->weight_quant_mode) {
    n_count = n_count_j / wgt_n_block_size;
  }
  size_t inner_count = 0;
  size_t cbuf_count = 0;
  fp_general_t dp_res_non_quant = 0;
  uint16_t *scale_a_temp = nullptr;
  uint16_t *scale_b_temp = nullptr;
  uint32_t __scale_product;
  uint32_t *_scale_product = &__scale_product;
  uint32_t *scale_product = nullptr;
  for (int k = 0; k < common_k; k += dop_blocksize) {
    inner_count++;
    uint16_t *segment_a = mat_a[m_count_i] + k;
    uint16_t *segment_b = mat_b[n_count_j] + k;
    if (temp_opcode->act_quant_mode) {
      act_k_count = k / act_k_block_size;
      scale_a_temp = (uint16_t *)(a_scale[m_count] + act_k_count);
    }
    if (temp_opcode->weight_quant_mode) {
      wgt_k_count = k / wgt_k_block_size;
      scale_b_temp = (uint16_t *)(b_scale[n_count] + wgt_k_count);
    }
    if (temp_opcode->act_quant_mode && temp_opcode->weight_quant_mode &&
        datatype == FP8E4) {
      scale_product = _scale_product;
      *scale_product = bf16mul_resfp24(*scale_a_temp, *scale_b_temp);
      scale_b_temp = nullptr;
    }
    uint8_t temp_dop_blocksize =
        k < common_k - dop_blocksize ? dop_blocksize : tail_blocksize;
    uint64_t temp_result = 0;
    switch (datatype) {
    case FP8E4:
      temp_result =
          dop_product_scale32(segment_a, segment_b, temp_dop_blocksize,
                              datatype, scale_product, scale_b_temp);
      break;
    default:
      temp_result = dop_product(segment_a, segment_b, temp_dop_blocksize,
                                datatype, scale_a_temp, scale_b_temp);
      break;
    }
    dp_res_non_quant = 0;
    // dop_product(segment_a, segment_b, temp_dop_blocksize, datatype);
    sum = vector_sum(sum, temp_result);
    file << "dp add result " << inner_count << ":" << hex << sum
         << "==dp res:" << temp_result
         << "==dp res without quant:" << dp_res_non_quant << endl;
    if (inner_count % 8 == 0) {
      file << "cbuf update " << cbuf_count << ":" << hex << sum << endl;
      cbuf_count++;
    }
  }
  dst_mat[m_count_i][n_count_j] = sum;
  file << "\n final result:" << hex << dst_mat[m_count_i][n_count_j];
  file.close();
}

} // namespace operators