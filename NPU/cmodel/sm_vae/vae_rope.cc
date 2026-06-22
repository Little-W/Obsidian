#include "dop_ops.h"
#include "sfu_sincos.h"
#include "softfloat.h"
#include "vae_common.h"
#include <fstream>
#include <iostream>
/*========================================
Function: rope
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/25. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  q: 2d matrx.for rope.
  k_mean: for quantization.
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  blockStep: unit for block calculation in a column
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  paddingVlaue:0, -inf +inf ,and so on .
  scaleFactor: for quantization
  byPassFlag: 0, no quant; 1,need quant.
output:
  rope_outResult: not quantization result.
  quant_outResult: result of quantization.
  ret_scale:quant return scale
============================================*/
namespace operators {

// made by qingyan
void rope(uint16_t *rope_outResult, const uint16_t *src_data, const uint16_t *q,
          uint16_t *k_mean, int src_row, int src_col, int blockStep,
          DataType i_type, DataType o_type, float24_t padding_value,
          float16_t scaleFactor, uint8_t *quant_outResult, int byPassFlag,
          uint16_t *ret_scale) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "rope";
  uint16_t data2txt_uint16;
  uint24_t data2txt_uint24;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_ropeData32");
  FILE *file_p0_ropeData32;
  file_p0_ropeData32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_rope_outResult");
  FILE *file_p1_rope_outResult;
  file_p1_rope_outResult = printfOpenFile(nodeName, opName);
#endif
  int col_copy = src_col * 2;
  int padding_num = (blockStep - (col_copy % blockStep)) % blockStep;
  int all_col =
      col_copy +
      padding_num; // align the number of valid data to a multiple of blockStep
  if (all_col % 4 != 0) {
    all_col = all_col + all_col % 4;
  }
  uint24_t *rope_result24 = new uint24_t[src_row * all_col];
  uint16_t *q_double = new uint16_t[src_row * all_col];
  uint16_t *src_data_copy = new uint16_t[src_row * all_col];
  uint8_t *quant_outResult_tmp = new uint8_t[src_row * all_col];
  int k = 0;
  int ropeResult24_index = 0, rope_outResult_index = 0, rope_64add2_index = 0;
  int q_index = 0, src_index = 0;
  for (int j = 0; j < src_row; j++) // src_data
  {
    for (int i = 0; i < all_col; i += 4) {
      float16_t dataQ0, dataQ1;
      int tmp = j * all_col + i;
      int tmp_src = j * src_col + src_index;
      if (src_index < src_col) {
        dataQ0.v = src_data[tmp_src];
        dataQ1.v = src_data[tmp_src + 1];
      } else {
        dataQ0.v = 0x0000;
        dataQ1.v = 0x0000;
      }
      src_index += 2;
      src_data_copy[tmp] = dataQ0.v;
      src_data_copy[tmp + 1] = dataQ1.v;
      src_data_copy[tmp + 2] = dataQ0.v;
      src_data_copy[tmp + 3] = dataQ1.v;
    }
    src_index = 0;
  }
  q_index = 0;
  for (int j = 0; j < src_row; j++) // copy q
  {
    for (int i = 0; i < all_col; i += 4) {
      float16_t dataQ0, dataQ1;
      int tmp = j * all_col + i;
      int tmp_q = j * src_col + q_index;
      if (q_index < src_col) {
        dataQ0.v = q[tmp_q + 1]; // cos
        dataQ1.v = q[tmp_q];     // sin
      } else {
        dataQ0.v = 0x0000;
        dataQ1.v = 0x0000;
      }
      q_index += 2;
      q_double[tmp] = dataQ0.v; // cos
      q_double[tmp + 1] = dataQ1.v;
      q_double[tmp + 2] = dataQ1.v; // sin
      q_double[tmp + 3] = dataQ0.v; // cos
    }
    q_index = 0;
  }

  int blockNum = 0;
  float16_t padding_value16;
  if (i_type == FP16) {
    padding_value16.v = fp24_to_fp16(padding_value.v);
  } else if (i_type == BF16) {
    padding_value16.v = fp24_to_bf16(padding_value.v);
  }
  uint32_t index = 0;
  for (int j = 0; j < src_row; j++) // rope
  {
    for (int i = 0; i < all_col; i++) {
      int tmp = j * all_col + i;
      float16_t src_dataNow, q16, ropeData;
      float32_t ropeData32;
      if (i >= col_copy) {
        src_dataNow.v = padding_value16.v;
        q16.v = padding_value16.v;
      } else if (i < col_copy) {
        src_dataNow.v = src_data_copy[tmp];
        q16.v = q_double[tmp];
      }
      if (i_type == FP16) {
        ropeData32.v = fp16mul_resfp32(src_dataNow.v, q16.v);
      } else if (i_type == BF16) {
        ropeData32.v = bf16mul_resfp32(src_dataNow.v, q16.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint32 = ropeData32.v;
      operators::printfData32bit(data2txt_uint32, file_p0_ropeData32);
#endif
      rope_result24[tmp] = fp32_to_fp24(ropeData32.v);
      if (index == 1) {
        float24_t neg;
        neg.v = 0xbf8000;
        rope_result24[tmp] = fp24mul(rope_result24[tmp], neg.v); //-sin
      }
      if (index == 3) {
        index = 0;
      } else {
        index++;
      }
    }
  }
  float24_t rope_add_Data24;
  for (int j = 0; j < src_row; j++) // rope  64add2
  {
    for (int i = 0; i < col_copy; i += 2) {
      int tmp = j * all_col + i;
      rope_add_Data24.v = fp24add(rope_result24[tmp], rope_result24[tmp + 1]);
      if (i_type == FP16) {
        rope_outResult[rope_outResult_index] = fp24_to_fp16(rope_add_Data24.v);
      } else if (i_type == BF16) {
        rope_outResult[rope_outResult_index] = fp24_to_bf16(rope_add_Data24.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = rope_outResult[rope_outResult_index];
      operators::printfData16bit(data2txt_uint16, file_p1_rope_outResult);
#endif
      rope_outResult_index++;
    }
  }
  o_type = UINT8;
  if (byPassFlag == 0) { // no_quant
    ;
  } else if (byPassFlag == 1) { // Q_quant
    uint32_t kMeanBypass = 0;
    vae_quant_perToken(quant_outResult_tmp, rope_outResult, k_mean, ret_scale,
                       src_row, src_col, scaleFactor, i_type, o_type,
                       kMeanBypass);
  } else if (byPassFlag == 2) { // k_mean ,k_quant
    vae_perToken_k(quant_outResult_tmp, rope_outResult, ret_scale, k_mean,
                   src_row, src_col, scaleFactor, i_type, o_type);
  }
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < src_col; i++) {
      int tmp = j * src_col + i;
      quant_outResult[tmp] = quant_outResult_tmp[tmp];
    }
  }
  delete[] q_double;
  delete[] rope_result24;
  delete[] quant_outResult_tmp;
  delete[] src_data_copy;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_ropeData32);
  printfcloseFile(file_p1_rope_outResult);
#endif
}
} // namespace operators
