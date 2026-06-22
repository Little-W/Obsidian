#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {
/*========================================
Function: vae_rmsnorm .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_gamma:dim [1][src_col],
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  eps:
  paddingVlaue:0, -inf +inf ,and so on .
  blockStep: unit for block calculation in a column
  rcp_col:
  flagGamma: is 0, not mul gamma; is 1, need mul gamma
output:
  rms_result: a 2D matrix
============================================*/
void vae_rmsnorm(uint16_t *rms_result, const uint16_t *src_data,
                 const uint16_t *src_gamma, int src_row, int src_col,
                 DataType i_type, DataType o_type, uint32_t eps,
                 float24_t padding_value, int blockStep, float32_t rcp_col,
                 int flagGamma) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "rmsnorm";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_squre_tmp32");
  FILE *file_p0_squre_tmp32;
  file_p0_squre_tmp32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_sumSqure_tmp32");
  FILE *file_p1_sumSqure_tmp32;
  file_p1_sumSqure_tmp32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_sumSqure");
  FILE *file_p2_sumSqure;
  file_p2_sumSqure = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_rms_f32");
  FILE *file_p3_rms_f32;
  file_p3_rms_f32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_rcp_rms");
  FILE *file_p4_rcp_rms;
  file_p4_rcp_rms = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_mul_x_rms");
  FILE *file_p5_mul_x_rms;
  file_p5_mul_x_rms = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_result");
  FILE *file_p6_result;
  file_p6_result = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_gamma_fp16");
  FILE *file_p7_gamma_fp16;
  file_p7_gamma_fp16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p8_sumSqureOdd");
  FILE *file_p8_sumSqureOdd;
  file_p8_sumSqureOdd = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p9_sumSqureEven");
  FILE *file_p9_sumSqureEven;
  file_p9_sumSqureEven = printfOpenFile(nodeName, opName);
#endif
  int paddingNumFlag = 0;
  int padding_num = (blockStep - (src_col % blockStep)) % blockStep;
  int all_col =
      src_col +
      padding_num; // align the number of valid data to a multiple of blockStep
  float24_t *squre = new float24_t[src_row * all_col];
  float16_t gamma_fp16, squre_tmp; // fp16
  float32_t eps_fp32, squre_tmp32;
  eps_fp32.v = eps;
  squre_tmp.v = 0;
  for (int i = 0; i < src_row; i++) {
    int blockNumTmp = 0, sumFlag = 0, flagEnd = 0;
    float24_t sumSqure_tmp24;
    float16_t data_fp16;
    float32_t data_fp32, pSum32Tmp, row_mean, rms_f32, sqrt_rms_f32, rcp_rms;
    float32_t sumSqure_tmp32, sumSqure_tmp, sumSqure, sumSqureOdd, sumSqureEven;
    sumSqure_tmp.v = 0;
    sumSqure.v = 0;
    sumSqureOdd.v = 0;
    sumSqureEven.v = 0;
    for (int j = 0; j < all_col; j++) {
      if (j >= src_col) // the last block for padding.
      {
        float16_t padding_value_16;
        if (i_type == FP16) {
          padding_value_16.v = fp24_to_fp16(padding_value.v);
        } else if (i_type == BF16) {
          padding_value_16.v = fp24_to_bf16(padding_value.v);
        }
        data_fp16.v = padding_value_16.v;
      } else if (j < src_col) {
        int index = i * src_col + j;
        data_fp16.v = src_data[index];
      }
      if (i_type == FP16) {
        squre_tmp32.v = fp16mul_resfp32(data_fp16.v, data_fp16.v);
      } else if (i_type == BF16) {
        squre_tmp32.v = bf16mul_resfp32(data_fp16.v, data_fp16.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint32 = squre_tmp32.v;
      operators::printfData32bit(data2txt_uint32, file_p0_squre_tmp32);
#endif
      int index_squre = i * all_col + j;
      squre[index_squre].v = fp32_to_fp24(squre_tmp32.v);
      if ((j + 1) % blockStep == 0) // blockStep if a block for add2.
      {
        if ((blockNumTmp + 1) == all_col / blockStep) {
          flagEnd = 1;
        }
        int tmp = i * all_col + blockNumTmp * blockStep;
        blockNumTmp++;
        sumSqure_tmp24 = add2(squre + tmp, blockStep, padding_value);
        sumSqure_tmp32.v = fp24_to_fp32(sumSqure_tmp24.v);
#if TEST_FOR_DE_DV
        data2txt_uint32 = sumSqure_tmp32.v;
        operators::printfData32bit(data2txt_uint32, file_p1_sumSqure_tmp32);
#endif
        if (src_row > 1) {
          sumSqure.v = fp32add(sumSqure_tmp32.v, sumSqure.v);
#if TEST_FOR_DE_DV
          data2txt_uint32 = sumSqure.v;
          operators::printfData32bit(data2txt_uint32, file_p2_sumSqure);
#endif
        } else if (src_row == 1) {
          if (sumFlag == 0) {
            sumFlag = 1;
            sumSqureOdd.v = fp32add(sumSqure_tmp32.v, sumSqureOdd.v);
#if TEST_FOR_DE_DV
            data2txt_uint32 = sumSqureOdd.v;
            operators::printfData32bit(data2txt_uint32, file_p8_sumSqureOdd);
#endif
          } else if (sumFlag == 1) {
            sumFlag = 0;
            sumSqureEven.v = fp32add(sumSqure_tmp32.v, sumSqureEven.v);
#if TEST_FOR_DE_DV
            data2txt_uint32 = sumSqureEven.v;
            operators::printfData32bit(data2txt_uint32, file_p9_sumSqureEven);
#endif
          }
          if (flagEnd == 1) {
            sumSqure.v = fp32add(sumSqureOdd.v, sumSqureEven.v);
            flagEnd = 0;
#if TEST_FOR_DE_DV
            data2txt_uint32 = sumSqure.v;
            operators::printfData32bit(data2txt_uint32, file_p2_sumSqure);
#endif
          }
        }
      }
    }
    rms_f32.v = fp32mulAdd(rcp_col.v, sumSqure.v, eps_fp32.v);
#if TEST_FOR_DE_DV
    data2txt_uint32 = rms_f32.v;
    operators::printfData32bit(data2txt_uint32, file_p3_rms_f32);
#endif
    sqrt_rms_f32.v = sfu_sqrt(rms_f32.v); // fp32
    rcp_rms.v = sfu_rcp(sqrt_rms_f32.v);
#if TEST_FOR_DE_DV
    data2txt_uint32 = rcp_rms.v;
    operators::printfData32bit(data2txt_uint32, file_p4_rcp_rms);
#endif
    float16_t rcp_rms_tmp;
    if (i_type == FP16) {
      rcp_rms_tmp.v = fp32_to_fp16(rcp_rms.v);
    } else if (i_type == BF16) {
      rcp_rms_tmp.v = fp32_to_bf16(rcp_rms.v);
    }
    for (int k = 0; k < src_col; k++) {
      float16_t data_fp16, padding_valueF16;
      data_fp16.v = src_data[i * src_col + k];
      gamma_fp16.v = src_gamma[k];
      float16_t mul_x_rms, result;
      float32_t mul_x_rms32;
      if (i_type == FP16) {
        mul_x_rms32.v = fp16mul_resfp32(data_fp16.v, rcp_rms_tmp.v);
        mul_x_rms.v = fp32_to_fp16(mul_x_rms32.v);
        if (flagGamma == 1) {
          mul_x_rms32.v = fp16mul_resfp32(mul_x_rms.v, gamma_fp16.v);
          result.v = fp32_to_fp16(mul_x_rms32.v);
        } else {
          result.v = mul_x_rms.v;
        }
      } else if (i_type == BF16) {
        mul_x_rms32.v = bf16mul_resfp32(data_fp16.v, rcp_rms_tmp.v);
        mul_x_rms.v = fp32_to_bf16(mul_x_rms32.v);
        if (flagGamma == 1) {
          mul_x_rms32.v = bf16mul_resfp32(mul_x_rms.v, gamma_fp16.v);
          result.v = fp32_to_bf16(mul_x_rms32.v);
        } else {
          result.v = mul_x_rms.v;
        }
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = mul_x_rms.v;
      operators::printfData16bit(data2txt_uint16, file_p5_mul_x_rms);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = result.v;
      operators::printfData16bit(data2txt_uint16, file_p6_result);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = gamma_fp16.v;
      operators::printfData16bit(data2txt_uint16, file_p7_gamma_fp16);
#endif
      rms_result[i * src_col + k] = result.v;
    }
  }
  delete[] squre;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_squre_tmp32);
  printfcloseFile(file_p1_sumSqure_tmp32);
  printfcloseFile(file_p2_sumSqure);
  printfcloseFile(file_p3_rms_f32);
  printfcloseFile(file_p4_rcp_rms);
  printfcloseFile(file_p5_mul_x_rms);
  printfcloseFile(file_p6_result);
  printfcloseFile(file_p7_gamma_fp16);
  printfcloseFile(file_p8_sumSqureOdd);
  printfcloseFile(file_p9_sumSqureEven);
#endif
}
} // namespace operators
