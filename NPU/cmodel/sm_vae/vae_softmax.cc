#include "dop_ops.h"
#include "sfu_exp.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"

namespace operators {
/*========================================
Function: softmax online .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t.
  src_mask: a data with a mask ,mask value is 0 or 1.
  src_row:the row of 2D matrix ,such 1.
  src_col :the col of 2D matrix ,valid data number,such 127.
  i_type: input data type,such as FP16 ,BF16.
  o_type: input data type,such as FP16 ,BF16.
  blockStep: unit for block calculation in a column.
  paddingVlaue:0, -inf +inf ,and so on .
  scaleFlag: 0, not scale ; 1.need scale .
  scale: scale value.
  maskFlag: 0, not mask;
  mask_value0: value for mask.
output:
  softmax_result： a 2D matrix
============================================*/
void vae_softmax_online(uint16_t *softmax_result, const uint16_t *src_data,
                        const uint16_t *src_mask, uint32_t src_row,
                        uint32_t src_col, DataType i_type, DataType o_type,
                        uint32_t blockStep, float24_t paddingValue,
                        uint32_t scaleFlag, float16_t scale, uint32_t maskFlag,
                        float16_t mask_value0) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "softmax";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_new_max_blk");
  FILE *file_p0_new_max_blk;
  file_p0_new_max_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_data_max_diff_F16");
  FILE *file_p1_data_max_diff_F16;
  file_p1_data_max_diff_F16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_x_max_exp");
  FILE *file_p2_x_max_exp;
  file_p2_x_max_exp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_new_sum_blk");
  FILE *file_p3_new_sum_blk;
  file_p3_new_sum_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_max_diff");
  FILE *file_p4_max_diff;
  file_p4_max_diff = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_max_exp");
  FILE *file_p5_max_exp;
  file_p5_max_exp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_sum_tmp");
  FILE *file_p6_sum_tmp;
  file_p6_sum_tmp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_rcp_row_sum");
  FILE *file_p7_rcp_row_sum;
  file_p7_rcp_row_sum = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p8_data_diff");
  FILE *file_p8_data_diff;
  file_p8_data_diff = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p9_data_diff_exp_fp16");
  FILE *file_p9_data_diff_exp_fp16;
  file_p9_data_diff_exp_fp16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p10_ret_f16");
  FILE *file_p10_ret_f16;
  file_p10_ret_f16 = printfOpenFile(nodeName, opName);
#endif
  uint16_t *src_scale = new uint16_t[src_row * src_col];
  uint16_t *src_mask_data = new uint16_t[src_row * src_col];
  uint16_t *src_maskTmp = new uint16_t[src_row * src_col];
  float24_t *x_max_exp24 = new float24_t[blockStep];
  if (maskFlag == 1) // need mask
  {
    vae_mask(src_maskTmp, src_data, src_mask, src_row, src_col, mask_value0);
  }
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      int tmp = i * src_col + j;
      if (maskFlag == 1) {
        src_mask_data[tmp] = src_maskTmp[tmp];
      } else if (maskFlag == 0) {
        src_mask_data[tmp] = src_data[tmp];
      }
    }
  }
  int num = src_row * src_col;
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      float16_t dataNow;
      int tmp = i * src_col + j;
      if (scaleFlag == 1) {
        dataNow.v = src_mask_data[tmp];
        if (i_type == FP16) {
          src_scale[tmp] = fp16mul(dataNow.v, scale.v);
        } else if (i_type == BF16) {
          src_scale[tmp] = bf16mul(dataNow.v, scale.v);
        }
      } else if (scaleFlag == 0) {
        src_scale[tmp] = src_mask_data[tmp];
      }
    }
  }
  int block_size = blockStep;
  int padding_num = (blockStep - (src_col % blockStep)) % blockStep;
  int all_col =
      src_col +
      padding_num; // align the number of valid data to a multiple of blockStep
  for (int i = 0; i < src_row; i++) {
    float16_t pre_max, new_max, pre_max_blk, new_max_blk; // also bfloat_16
    float32_t row_sum, sum_tmp, pre_sum_blk;
    if (i_type == FP16) {
      pre_max.v = 0xfc00, new_max.v = 0xfc00, pre_max_blk.v = 0xfc00,
      new_max_blk.v = 0xfc00; //-inf
    } else {
      pre_max.v = 0xff80, new_max.v = 0xff80, pre_max_blk.v = 0xff80,
      new_max_blk.v = 0xff80; //-inf
    }
    row_sum.v = 0, sum_tmp.v = 0, pre_sum_blk.v = 0;
    for (int j = 0; j < src_col; j += block_size) {
      float16_t data_f16, data_max_diff_BF16, data_max_diff_FP16, max_diff,
          max_diff_fp16, x_max_exp, max_exp16;
      float32_t max_exp, new_sum_blk;
      float24_t new_sum_blk24;
      new_sum_blk.v = 0; // block sum
      int block_end, block_end_j;
      block_end_j = j + block_size;
      if (block_end_j < src_col) {
        block_end = block_end_j;
      } else {
        block_end = src_col;
      }
      int absFlag = 0;
      new_max_blk.v =
          maxValue(src_scale + j + i * src_col, block_end - j, i_type, absFlag);
      if (i_type == FP16) {
        new_max_blk.v = fp16max(new_max_blk.v, pre_max_blk.v);
      } else if (i_type == BF16) {
        new_max_blk.v = bf16max(new_max_blk.v, pre_max_blk.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_max_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p0_new_max_blk);
#endif
      int tmp = 0;
      for (int n = j; n < block_end; n++) {
        data_f16.v = src_scale[i * src_col + n];

        if (i_type == FP16) {
          data_max_diff_FP16.v = fp16sub(data_f16.v, new_max_blk.v);
          x_max_exp.v = sfu_expE(data_max_diff_FP16.v);
        } else {
          data_max_diff_BF16.v = bf16sub(data_f16.v, new_max_blk.v);
          data_max_diff_FP16.v = bf16_to_fp16(data_max_diff_BF16.v);
          x_max_exp.v = sfu_expE(data_max_diff_FP16.v); // todo:need f16 exp
        }
#if TEST_FOR_DE_DV
        if (i_type == FP16) {
          data2txt_uint16 = data_max_diff_FP16.v;
        } else if (i_type == BF16) {
          data2txt_uint16 = data_max_diff_BF16.v;
        }
        operators::printfData16bit(data2txt_uint16, file_p1_data_max_diff_F16);
#endif
        x_max_exp24[tmp].v = fp16_to_fp24(x_max_exp.v);
#if TEST_FOR_DE_DV
        data2txt_uint16 = x_max_exp.v;
        operators::printfData16bit(data2txt_uint16, file_p2_x_max_exp);
#endif
        tmp++;
      }
      if (block_end == src_col) {
        for (int n = block_end; n < all_col; n++) {
          x_max_exp24[tmp].v = 0;
          tmp++;
        }
      }
      new_sum_blk24 = add2(x_max_exp24, blockStep, paddingValue);
      new_sum_blk.v = fp24_to_fp32(new_sum_blk24.v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = new_sum_blk.v;
      operators::printfData32bit(data2txt_uint32, file_p3_new_sum_blk);
#endif
      if (i_type == FP16) {
        max_diff.v = fp16sub(pre_max_blk.v, new_max_blk.v);
        max_exp16.v = sfu_expE(max_diff.v); // fp16
        max_exp.v = fp16_to_fp32(max_exp16.v);
      } else if (i_type == BF16) {
        max_diff.v = bf16sub(pre_max_blk.v, new_max_blk.v);
        max_diff_fp16.v = bf16_to_fp16(max_diff.v);
        max_exp16.v = sfu_expE(max_diff_fp16.v); // fp16
        max_exp.v = fp16_to_fp32(max_exp16.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = max_diff.v;
      operators::printfData16bit(data2txt_uint16, file_p4_max_diff);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = max_exp.v;
      operators::printfData32bit(data2txt_uint32, file_p5_max_exp);
#endif
      sum_tmp = f32_mulAdd(pre_sum_blk, max_exp, new_sum_blk); // fma
#if TEST_FOR_DE_DV
      data2txt_uint32 = sum_tmp.v;
      operators::printfData32bit(data2txt_uint32, file_p6_sum_tmp);
#endif
      pre_max_blk = new_max_blk;
      pre_sum_blk = sum_tmp;
    }
    new_max = new_max_blk;
    row_sum.v = fp32add(row_sum.v, sum_tmp.v);
    float32_t rcp_row_sum;
    rcp_row_sum.v = sfu_rcp(row_sum.v);
#if TEST_FOR_DE_DV
    data2txt_uint32 = rcp_row_sum.v;
    operators::printfData32bit(data2txt_uint32, file_p7_rcp_row_sum);
#endif
    for (int j = 0; j < src_col; j++) {
      float16_t data_f16, data_diff_exp_fp16, data_diff_exp_bf16, data_diff,
          data_diff_fp16, ret_f16, rcp_row_sum_f16;
      float32_t ret_f32;
      data_f16.v = src_scale[i * src_col + j];
      if (i_type == FP16) {
        data_diff.v = fp16sub(data_f16.v, new_max.v); // x-max
        data_diff_exp_fp16.v = sfu_expE(data_diff.v); // fp16
      } else if (i_type == BF16) {
        data_diff.v = bf16sub(data_f16.v, new_max.v); // x-max
        data_diff_fp16.v = bf16_to_fp16(data_diff.v);
        data_diff_exp_fp16.v = sfu_expE(data_diff_fp16.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = data_diff.v;
      operators::printfData16bit(data2txt_uint16, file_p8_data_diff);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = data_diff_exp_fp16.v;
      operators::printfData16bit(data2txt_uint16, file_p9_data_diff_exp_fp16);
#endif
      rcp_row_sum_f16.v = fp32_to_fp16(rcp_row_sum.v);
      ret_f32.v = fp16mul_resfp32(rcp_row_sum_f16.v, data_diff_exp_fp16.v);
      if (i_type == FP16) {
        ret_f16.v = fp32_to_fp16(ret_f32.v);
      } else if (i_type == BF16) {
        ret_f16.v = fp32_to_bf16(ret_f32.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = ret_f16.v;
      operators::printfData16bit(data2txt_uint16, file_p10_ret_f16);
#endif
      softmax_result[i * src_col + j] = ret_f16.v;
    }
  }
  delete[] src_scale;
  delete[] src_mask_data;
  delete[] src_maskTmp;
  delete[] x_max_exp24;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_new_max_blk);
  printfcloseFile(file_p1_data_max_diff_F16);
  printfcloseFile(file_p2_x_max_exp);
  printfcloseFile(file_p3_new_sum_blk);
  printfcloseFile(file_p4_max_diff);
  printfcloseFile(file_p5_max_exp);
  printfcloseFile(file_p6_sum_tmp);
  printfcloseFile(file_p7_rcp_row_sum);
  printfcloseFile(file_p8_data_diff);
  printfcloseFile(file_p9_data_diff_exp_fp16);
  printfcloseFile(file_p10_ret_f16);
#endif
}

/*========================================
Function: softmax fa1.
model 1:input if BF16,output is BF16.
model 2:input if FP16,output is FP16.
Information:Author is ZC, 2025/07/15. by qingyan.
para:
input:
  src_data, dim [src_row][src_col], type uint16_t.
  src_mask:  a data with a mask ,mask value is 0 or 1.
  src_row:the row of 2D matrix ,such 1.
  src_col :the col of 2D matrix ,valid data number,such 127.
  i_type: input data type,such as FP16 ,BF16.
  o_type: input data type,such as FP16 ,BF16.
  blockStep: unit for block calculation in a column.
  bypassQuant: 0 not quant;1 need quant.
  paddingValue: padding value.
  scaleFlag : 1,need sacle.
  scale: scale value.
  maskFlag； 1，need mask.
  mask_value0: value for mask.
  pre_sum_blk_input： for iteration temporary input.
  pre_sum_blk_output: for iteration temporary input.
  pre_max_input: for iteration temporary input.
  scaleFactor: for quant.
outside parameters output:
  softmax_result： a 2D matrix.
  quant_outResult: quant result.
  out_EMRFIFO: middle result for fa2.
  pre_max_output: for iteration temporary output.
  scaleBuffer: for iteration temporary output.
============================================*/
void vae_softmax_fa1(uint16_t *softmax_result, const uint16_t *src_data,
                     const uint16_t *src_mask, int maskFlag,
                     float16_t mask_value0, int src_row, int src_col,
                     DataType i_type, DataType o_type, int bypassQuant,
                     int blockStep, float24_t paddingValue,
                     uint8_t *quant_outResult, int scaleFlag, float16_t scale,
                     uint16_t *out_EMRFIFO, uint32_t *pre_sum_blk_input,
                     uint32_t *pre_sum_blk_output, uint16_t *pre_max_input,
                     uint16_t *pre_max_output, uint16_t *scaleBuffer,
                     float16_t scaleFactor) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "softmax_fa1";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
  uint24_t data2txt_uint24;
  uint8_t data2txt_uint8;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_new_max_blk");
  FILE *file_p0_new_max_blk;
  file_p0_new_max_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_data_max_diff_F16");
  FILE *file_p1_data_max_diff_F16;
  file_p1_data_max_diff_F16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_x_max_exp");
  FILE *file_p2_x_max_exp;
  file_p2_x_max_exp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_new_sum_blk");
  FILE *file_p3_new_sum_blk;
  file_p3_new_sum_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_max_diff");
  FILE *file_p4_max_diff;
  file_p4_max_diff = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_max_exp");
  FILE *file_p5_max_exp;
  file_p5_max_exp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_sum_tmp");
  FILE *file_p6_sum_tmp;
  file_p6_sum_tmp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_quant_outResult_tmp");
  FILE *file_p7_quant_outResult_tmp;
  file_p7_quant_outResult_tmp = printfOpenFile(nodeName, opName);
#endif
  uint8_t *quant_outResult_tmp = new uint8_t[src_row * src_col];
  uint16_t *src_scale = new uint16_t[src_row * src_col];
  uint16_t *src_mask_data = new uint16_t[src_row * src_col];
  uint16_t *src_maskTmp = new uint16_t[src_row * src_col];
  int num = src_row * src_col;
  if (maskFlag == 1) // need mask
  {
    vae_mask(src_maskTmp, src_data, src_mask, src_row, src_col, mask_value0);
  }
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      int tmp = i * src_col + j;
      if (maskFlag == 1) {
        src_mask_data[tmp] = src_maskTmp[tmp];
      } else if (maskFlag == 0) {
        src_mask_data[tmp] = src_data[tmp];
      }
    }
  }
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      float16_t dataNow;
      int tmp = i * src_col + j;
      if (scaleFlag == 1) {
        dataNow.v = src_mask_data[tmp];
        if (i_type == FP16) {
          src_scale[tmp] = fp16mul(dataNow.v, scale.v);
        } else if (i_type == BF16) {
          src_scale[tmp] = bf16mul(dataNow.v, scale.v);
        }
      } else if (scaleFlag == 0) {
        src_scale[tmp] = src_mask_data[tmp];
      }
    }
  }
  float24_t *x_max_exp24 = new float24_t[blockStep];
  int block_size = blockStep;
  int padding_num = (blockStep - (src_col % blockStep)) % blockStep;
  int all_col =
      src_col +
      padding_num; // align the number of valid data to a multiple of blockStep
  for (int i = 0; i < src_row; i++) {
    float16_t pre_max_blk, new_max_blk,
        max_exp16; // also bfloat_16
    float32_t row_sum, sum_tmp, pre_sum_blk;
    pre_max_blk.v = pre_max_input[i];
    if (i_type == FP16) {
      new_max_blk.v = 0xfc00; //-inf
    } else {
      new_max_blk.v = 0xff80; //-inf
    }
    row_sum.v = 0, sum_tmp.v = 0, pre_sum_blk.v = pre_sum_blk_input[i];
    for (int j = 0; j < src_col; j += block_size) {
      float16_t data_f16, data_max_diff_BF16, data_max_diff_FP16, max_diff,
          max_diff_fp16, x_max_exp;
      float32_t max_exp, new_sum_blk;
      float24_t new_sum_blk24;
      new_sum_blk.v = 0; // block sum
      int block_end, block_end_j;
      block_end_j = j + block_size;
      if (block_end_j < src_col) {
        block_end = block_end_j;
      } else {
        block_end = src_col;
      }
      int absFlag = 0;
      new_max_blk.v =
          maxValue(src_scale + j + i * src_col, block_end - j, i_type, absFlag);
      if (i_type == FP16) {
        new_max_blk.v = fp16max(new_max_blk.v, pre_max_blk.v);
      } else if (i_type == BF16) {
        new_max_blk.v = bf16max(new_max_blk.v, pre_max_blk.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_max_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p0_new_max_blk);
#endif
      int tmp = 0;
      for (int n = j; n < block_end; n++) {
        int tmpResult = i * src_col + n;
        data_f16.v = src_scale[i * src_col + n];
        if (i_type == FP16) {
          data_max_diff_FP16.v = fp16sub(data_f16.v, new_max_blk.v);
          x_max_exp.v = sfu_expE(data_max_diff_FP16.v);
        } else if (i_type == BF16) {
          data_max_diff_BF16.v = bf16sub(data_f16.v, new_max_blk.v);
          data_max_diff_FP16.v = bf16_to_fp16(data_max_diff_BF16.v);
          x_max_exp.v = sfu_expE(data_max_diff_FP16.v);
        }
#if TEST_FOR_DE_DV
        if (i_type == FP16) {
          data2txt_uint16 = data_max_diff_FP16.v;
        } else if (i_type == BF16) {
          data2txt_uint16 = data_max_diff_BF16.v;
        }
        operators::printfData16bit(data2txt_uint16, file_p1_data_max_diff_F16);
#endif
        x_max_exp24[tmp].v = fp16_to_fp24(x_max_exp.v);
#if TEST_FOR_DE_DV
        data2txt_uint16 = x_max_exp.v;
        operators::printfData16bit(data2txt_uint16, file_p2_x_max_exp);
#endif
        if (o_type == BF16 && bypassQuant == 0) {
          softmax_result[tmpResult] = fp16_to_bf16(x_max_exp.v);
        } else {
          softmax_result[tmpResult] = x_max_exp.v;
        }
        tmp++;
      }
      if (block_end == src_col) {
        for (int n = block_end; n < all_col; n++) {
          x_max_exp24[tmp].v = 0;
          tmp++;
        }
      }
      new_sum_blk24 = add2(x_max_exp24, blockStep, paddingValue);
      new_sum_blk.v = fp24_to_fp32(new_sum_blk24.v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = new_sum_blk.v;
      operators::printfData32bit(data2txt_uint32, file_p3_new_sum_blk);
#endif
      if (i_type == FP16) {
        max_diff.v = fp16sub(pre_max_blk.v, new_max_blk.v);
        max_exp16.v = sfu_expE(max_diff.v); // fp16
        max_exp.v = fp16_to_fp32(max_exp16.v);

      } else if (i_type == BF16) {
        max_diff.v = bf16sub(pre_max_blk.v, new_max_blk.v);
        max_diff_fp16.v = bf16_to_fp16(max_diff.v);
        max_exp16.v = sfu_expE(max_diff_fp16.v); // fp16
        max_exp.v = fp16_to_fp32(max_exp16.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = max_diff.v;
      operators::printfData16bit(data2txt_uint16, file_p4_max_diff);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = max_exp.v;
      operators::printfData32bit(data2txt_uint32, file_p5_max_exp);
#endif
      sum_tmp = f32_mulAdd(pre_sum_blk, max_exp, new_sum_blk); // fma
#if TEST_FOR_DE_DV
      data2txt_uint32 = sum_tmp.v;
      operators::printfData32bit(data2txt_uint32, file_p6_sum_tmp);
#endif
      pre_max_blk = new_max_blk;
      pre_sum_blk = sum_tmp;
    }
    out_EMRFIFO[i] = max_exp16.v;
    pre_sum_blk_output[i] = pre_sum_blk.v;
    pre_max_output[i] = pre_max_blk.v;
  }
  if (bypassQuant == 0) { // no_quant
    ;
  } else if (bypassQuant == 1) { // per tensor quant
    vae_quant_perTensor(quant_outResult_tmp, softmax_result, scaleBuffer,
                        src_row, src_col, scaleFactor, FP16, o_type);
  }
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < src_col; i++) {
      int tmp = j * src_col + i;
      quant_outResult[tmp] = quant_outResult_tmp[tmp];
#if TEST_FOR_DE_DV
      data2txt_uint8 = quant_outResult_tmp[tmp];
      operators::printfData8bit(data2txt_uint8, file_p7_quant_outResult_tmp);
#endif
    }
  }
  delete[] x_max_exp24;
  delete[] quant_outResult_tmp;
  delete[] src_scale;
  delete[] src_mask_data;
  delete[] src_maskTmp;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_new_max_blk);
  printfcloseFile(file_p1_data_max_diff_F16);
  printfcloseFile(file_p2_x_max_exp);
  printfcloseFile(file_p3_new_sum_blk);
  printfcloseFile(file_p4_max_diff);
  printfcloseFile(file_p5_max_exp);
  printfcloseFile(file_p6_sum_tmp);
  printfcloseFile(file_p7_quant_outResult_tmp);
#endif
}

/*========================================
Function: softmax fa2 .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
input:
  exp_data, dim [src_row][src_col], type uint16_t
  OSRAM: dim [src_row][src_col], type uint24_t
  pv_ibuffer:dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep: unit for block calculation in a column
output:
  ObufferOut: dim [src_row][src_col], type uint16_t
============================================*/
void softmax_fa2(uint24_t *ObufferOut, const uint16_t *exp_data,
                 const uint24_t *OSRAM, const uint16_t *pv_ibuffer, int src_col,
                 int src_row, int blockStep, int o_type, int i_type) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "softmax_fa2";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
  uint24_t data2txt_uint24;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_exp16");
  FILE *file_p0_exp16;
  file_p0_exp16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_Obuffer24");
  FILE *file_p1_Obuffer24;
  file_p1_Obuffer24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_mul24");
  FILE *file_p2_mul24;
  file_p2_mul24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_pv24");
  FILE *file_p3_pv24;
  file_p3_pv24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_ObufferOut");
  FILE *file_p4_ObufferOut;
  file_p4_ObufferOut = printfOpenFile(nodeName, opName);
#endif
  float24_t block_sum;
  uint24_t *exp24 = new uint24_t[src_row * src_col];
  float16_t exp16;
  float24_t Obuffer24, mul24, pv24, pv24Tmp;
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      int tmp = i * src_col + j;
      exp16.v = exp_data[i];
      exp24[tmp] = fp16_to_fp24(exp16.v);
      Obuffer24.v = OSRAM[tmp];
      mul24.v = fp24mul(exp24[tmp], Obuffer24.v);
      if (i_type == FP16) {
        pv24.v = fp16_to_fp24(pv_ibuffer[tmp]);
      } else if (i_type == BF16) {
        pv24.v = bf16_to_fp24(pv_ibuffer[tmp]);
      }
      ObufferOut[tmp] = fp24add(mul24.v, pv24.v);
#if TEST_FOR_DE_DV
      data2txt_uint16 = exp16.v;
      operators::printfData16bit(data2txt_uint16, file_p0_exp16);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = Obuffer24.v;
      operators::printfData24bit(data2txt_uint24, file_p1_Obuffer24);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = mul24.v;
      operators::printfData24bit(data2txt_uint24, file_p2_mul24);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = pv24.v;
      operators::printfData24bit(data2txt_uint24, file_p3_pv24);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = ObufferOut[tmp];
      operators::printfData24bit(data2txt_uint24, file_p4_ObufferOut);
#endif
    }
  }
  delete[] exp24;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_exp16);
  printfcloseFile(file_p1_Obuffer24);
  printfcloseFile(file_p2_mul24);
  printfcloseFile(file_p3_pv24);
  printfcloseFile(file_p4_ObufferOut);
#endif
}
/*========================================
Function: softmax fa3 .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  diag, dim [src_row][src_col], type uint32_t.
  Obuffer: dim [src_row][src_col], type uint24_t.
  src_row:the row of 2D matrix ,such 1.
  src_col :the col of 2D matrix ,valid data number,such 127.
  i_type: input data type,such as FP16 ,BF16.
  o_type: input data type,such as FP16 ,BF16.
  blockStep: unit for block calculation in a column
output:
  result : a 2D matrix.
============================================*/
void softmax_fa3(uint16_t *result, const uint32_t *diag,
                 const uint24_t *Obuffer, int src_col, int src_row,
                 int blockStep, int o_type, int i_type) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "softmax_fa3";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
  uint24_t data2txt_uint24;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_diag32");
  FILE *file_p0_diag32;
  file_p0_diag32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_diag32rcp");
  FILE *file_p1_diag32rcp;
  file_p1_diag32rcp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_diag24rcp");
  FILE *file_p2_diag24rcp;
  file_p2_diag24rcp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_result");
  FILE *file_p3_result;
  file_p3_result = printfOpenFile(nodeName, opName);
#endif
  float32_t diag32rcp, diag32;
  float24_t Obuffer24, mul24, diag24rcp;
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < src_col; i++) {
      int tmp = j * src_col + i;
      diag32.v = diag[j];
      diag32rcp.v = sfu_rcp(diag32.v);
      diag24rcp.v = fp32_to_fp24(diag32rcp.v);
      Obuffer24.v = Obuffer[tmp];
      mul24.v = fp24mul(diag24rcp.v, Obuffer24.v);
      if (o_type == FP16) {
        result[tmp] = fp24_to_fp16(mul24.v);
      } else if (o_type == BF16) {
        result[tmp] = fp24_to_bf16(mul24.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint32 = diag32.v;
      operators::printfData32bit(data2txt_uint32, file_p0_diag32);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = diag32rcp.v;
      operators::printfData32bit(data2txt_uint32, file_p1_diag32rcp);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = diag24rcp.v;
      operators::printfData24bit(data2txt_uint24, file_p2_diag24rcp);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = result[tmp];
      operators::printfData16bit(data2txt_uint16, file_p3_result);
#endif
    }
  }
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_diag32);
  printfcloseFile(file_p1_diag32rcp);
  printfcloseFile(file_p2_diag24rcp);
  printfcloseFile(file_p3_result);
#endif
}
} // namespace operators