#include "matrix_mul.h"
#include <functional>

namespace operators {
bool is_int = false;
#if ENABLE_OPENMP
#pragma omp declare reduction(vector_sum:fp_general_t                          \
                              : omp_out = vector_sum(omp_out, omp_in))         \
    initializer(omp_priv = 0)

#endif
#define const int *const *int_mat;
void matmul_subcmd_128_k(uint16_t **&mat_a, uint16_t **&mat_b,
                         uint64_t **dst_mat, int common_k, int mat_a_nr,
                         int mat_b_nc, DataType datatype) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(0);
  matmul_subcmd_sym_quant(mat_a, mat_b, dst_mat, nullptr, nullptr, common_k,
                          mat_a_nr, mat_b_nc, datatype, matrix_opcode);
  delete matrix_opcode;
}

void matmul_subcmd_128_k_T(uint16_t **&mat_a, uint16_t **&mat_b,
                           uint64_t **dst_mat, int common_k, int mat_a_nr,
                           int mat_b_nc, DataType datatype) {
  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(0);
  matmul_subcmd_T_sym_quant(mat_a, mat_b, dst_mat, nullptr, nullptr, common_k,
                            mat_a_nr, mat_b_nc, datatype, matrix_opcode);
  delete matrix_opcode;
}

void matmul_subcmd_sym_quant_raw_scale(uint16_t **mat_a, uint16_t **mat_b,
                                       uint64_t **dst_mat, uint16_t **a_scale,
                                       uint16_t **b_scale, int common_k,
                                       int mat_a_m, int mat_b_n,
                                       DataType datatype,
                                       matrix_opcode *matrix_opcode,
                                       int b_scale_row, int b_scale_col) {
  MATRIX_2D<uint16_t> *b_scale_T = new MATRIX_2D<uint16_t>();
  b_scale_T->transpose(b_scale, b_scale_col, b_scale_row, datatype);
  matmul_subcmd_sym_quant(mat_a, mat_b, dst_mat, a_scale, b_scale_T->data,
                          common_k, mat_a_m, mat_b_n, datatype, matrix_opcode);
  // b_scale_T->~MATRIX_2D();
  delete b_scale_T;
}

void matmul_subcmd_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                             uint64_t **dst_mat, uint16_t **a_scale,
                             uint16_t **b_scale, int common_k, int mat_a_m,
                             int mat_b_n, DataType datatype,
                             matrix_opcode *matrix_opcode) {
  MATRIX_2D<uint16_t> *b_T = new MATRIX_2D<uint16_t>();
  b_T->transpose(mat_b, mat_b_n, common_k, datatype);
  matmul_subcmd_T_sym_quant(mat_a, b_T->data, dst_mat, a_scale, b_scale,
                            common_k, mat_a_m, mat_b_n, datatype,
                            matrix_opcode);
  delete b_T;
}

void matmul_subcmd_T_sym_quant(uint16_t **mat_a, uint16_t **mat_b,
                               uint64_t **dst_mat, uint16_t **a_scale,
                               uint16_t **b_scale, int common_k, int mat_a_m,
                               int mat_b_n, DataType datatype,
                               matrix_opcode *matrix_opcode) {
  matrix_dp_en = true;
  uint8_t dop_blocksize = get_dop_blocksize(datatype);
  uint8_t temp_dop_blocksize = dop_blocksize;
  matrix_opcode_mat *temp_opcode =
      dynamic_cast<matrix_opcode_mat *>(matrix_opcode);
  uint16_t shift = temp_opcode->quant_shift_value;
  uint64_t temp_result;
  bool group_size = datatype == NVFP4E2;
  int act_k_block_size, act_m_block_size, wgt_k_block_size, wgt_n_block_size;
  if (temp_opcode->act_quant_mode) {
    act_k_block_size = group_size ? 16 : 32;
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
    wgt_k_block_size = group_size ? 16 : 32;
    wgt_n_block_size = 1;
  }

  int m_count = 0;
  int n_count = 0;
  int act_k_count = 0;
  int wgt_k_count = 0;
  bool need_padding = (bool)(common_k % dop_blocksize);
  uint8_t tail_blocksize =
      need_padding ? common_k % dop_blocksize : dop_blocksize;
  int_type_check(is_int, datatype);

  fp_general_t sum = 0;
#if ENABLE_OPENMP
#pragma omp parallel for OPENMP_SCH collapse(2) reduction(vector_sum           \
                                                          : sum)               \
    num_threads(NUM_THREADS_OPENMP)
#endif
  for (int m = 0; m < mat_a_m; m++) {
    // cout << " \n";
    for (int n = 0; n < mat_b_n; n++) {
      int m_count = 0;
      int n_count = 0;
      if (temp_opcode->act_quant_mode) {
        m_count = m / act_m_block_size;
      }
      if (temp_opcode->weight_quant_mode) {
        n_count = n / wgt_n_block_size;
      }
      sum = 0;
      for (int k = 0; k < common_k; k += dop_blocksize) {
        uint16_t *scale_a_temp = nullptr;
        uint16_t *scale_b_temp = nullptr;
        uint32_t __scale_product;
        uint32_t *_scale_product = &__scale_product;
        uint32_t *scale_product = nullptr;
        uint16_t *segment_a = mat_a[m] + k;
        uint16_t *segment_b = mat_b[n] + k;
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
        case SINT16SINT4:
          temp_result = dop_product(segment_a, segment_b, temp_dop_blocksize,
                                    datatype, &shift, scale_b_temp);
          temp_result = int_convert(temp_result, 1, 28, 40);
          break;
        default:
          temp_result = dop_product(segment_a, segment_b, temp_dop_blocksize,
                                    datatype, scale_a_temp, scale_b_temp);
          break;
        }
        sum = vector_sum(sum, temp_result);
        // cout<< "\n dst_mat["<<m<<"]["<<n<<"]:" << hex << dst_mat[m][n] <<
        // "dop_result:"<<temp_result;
      }
      dst_mat[m][n] = vector_sum(dst_mat[m][n], sum);
      // cout << "\n dst_mat[" << m << "][" << n << "]:" << hex <<
      // dst_mat[m][n]; if (m == 0)
      //   cout << " " << hex << dst_mat[m][n];
    }
    // if (m == 0)
    //   cout << endl;
  }
}

matrix_opcode *matrix_opcode::generate(uint64_t params0) {
  if (params0 & 1)
    return new matrix_opcode_conv(params0);
  else
    return new matrix_opcode_mat(params0);
}

uint8_t get_dop_blocksize(DataType datatype) {
  uint8_t result = 32;
  switch (datatype) {
  case BF16:
  case FP16:
  case SINT16SINT8:
  case UINT16SINT8:
    result = 16;
    break;
  case NVFP4E2:
  case MXFP4MXFP4:
    result = 64;
    break;
  }
  return result;
}

fp_general_t vector_sum(fp_general_t a, fp_general_t b) {
  if (is_int)
    return sint40_add(a, b);
  else
    return fp32add(a, b, true);
}

} // namespace operators