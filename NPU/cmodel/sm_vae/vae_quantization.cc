
#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {
/*========================================
Function: per tensor int16
Information:Author is ZC, 2025/11/21.
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1 .need less then 128
  src_col :the col of 2D matrix ,valid data number,such 127
  scale:
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int16
output:
  outData: [src_row][src_col]
============================================*/
void vae_pertensorInt16(uint16_t *outData, uint16_t *src_data, uint24_t scale,
                        uint32_t src_row, uint32_t src_col, DataType i_type,
                        DataType o_type) {
  float24_t src24, mul24;
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      if (i_type == FP16) {
        src24.v = fp16_to_fp24(src_data[tmp]);
      } else if (i_type == BF16) {
        src24.v = bf16_to_fp24(src_data[tmp]);
      }
      mul24.v = fp24mul(src24.v, scale);
      outData[tmp] = f24_to_i16(mul24.v);
    }
  }
}
/*========================================
Function: vae_quant_perToken
model 0:input if BF16,output is FP8E4 , scale is FP16
model 1:input if FP16,output is FP8E4, scale is   BF16
Information:Author is ZC, 2025/09/10. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t ,src_row<128,src_col<128
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 .
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int8
  kMean:
  kMeanBypass: 1,need kmean
output:
  oBuffer:[src_row][src_col]
  scaleBuffer: [src_row][1]
============================================*/
void vae_quant_perToken(uint8_t *oBuffer, uint16_t *src_data, uint16_t *kMean,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type, DataType o_type,
                        uint32_t kMeanBypass) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_quant_perToken";
  uint8_t data2txt_uint8;
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_max_blk32_value_row");
  FILE *file_p0_max_blk32_value_row;
  file_p0_max_blk32_value_row = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_scaleBuffer");
  FILE *file_p2_scaleBuffer;
  file_p2_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_scale_f16");
  FILE *file_p3_scale_f16;
  file_p3_scale_f16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_kMeanSub");
  FILE *file_p4_kMeanSub;
  file_p4_kMeanSub = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_oBuffer");
  FILE *file_p5_oBuffer;
  file_p5_oBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_result_tmp32");
  FILE *file_p6_result_tmp32;
  file_p6_result_tmp32 = printfOpenFile(nodeName, opName);
#endif
  uint32_t maxBlkStep = 32;
  uint32_t col_32blk =
      src_col + (maxBlkStep - (src_col % maxBlkStep)) % maxBlkStep;
  uint32_t maxBlkNum = col_32blk / maxBlkStep; // col
  uint16_t *result_scale = new uint16_t[1];
  uint16_t *max_blk32_value = new uint16_t[src_row * maxBlkNum];
  uint16_t *max_blk32_value_row = new uint16_t[src_row];
  uint16_t *kMeanSub = new uint16_t[src_row * src_col];
  float16_t *scale_f16 = new float16_t[src_row];
  float32_t *scale_f32_rcp = new float32_t[src_row];
  float32_t *scale_f32 = new float32_t[src_row];
  int absFlag = 1;
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      if (kMeanBypass == 1) { // need kMean
        if (i_type == FP16) {
          kMeanSub[tmp] = fp16sub(src_data[tmp], kMean[j]);
        } else if (i_type == BF16) {
          kMeanSub[tmp] = bf16sub(src_data[tmp], kMean[j]);
        }
      } else {
        kMeanSub[tmp] = src_data[tmp];
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = kMeanSub[tmp];
      operators::printfData16bit(data2txt_uint16, file_p4_kMeanSub);
#endif
    }
  }
  for (uint32_t i = 0; i < src_row; i++) {
    uint32_t indexTmp = 0;
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      uint32_t dataNum =
          ((j + maxBlkStep) <= src_col) ? maxBlkStep : (src_col % maxBlkStep);
      uint32_t tmpSrc = i * src_col + j;
      max_blk32_value[tmpMaxRet] =
          maxValue(kMeanSub + tmpSrc, dataNum, i_type, absFlag);
      indexTmp++;
    }
  }
  for (uint32_t i = 0; i < src_row; i++) {
    uint32_t tmpSrc = i * maxBlkNum;
    max_blk32_value_row[i] =
        maxValue(max_blk32_value + tmpSrc, maxBlkNum, i_type, absFlag);
#if TEST_FOR_DE_DV
    data2txt_uint16 = max_blk32_value_row[i];
    operators::printfData16bit(data2txt_uint16, file_p0_max_blk32_value_row);
#endif
  }
  for (uint32_t i = 0; i < src_row; i++) {
    if (i_type == FP16) {
      scale_f32[i].v = fp16mul_resfp32(max_blk32_value_row[i], scaleFactor.v);
      scaleBuffer[i] = fp32_to_fp16(scale_f32[i].v);
    } else if (i_type == BF16) {
      scale_f32[i].v = bf16mul_resfp32(max_blk32_value_row[i], scaleFactor.v);
      scaleBuffer[i] = fp32_to_bf16(scale_f32[i].v);
    }
    if (scale_f32[i].v == 0 || scale_f32[i].v == 0x80000000) {
      scale_f32[i].v = 0x3f800000;
    }
    scale_f32_rcp[i].v = sfu_rcp(scale_f32[i].v);
    if (i_type == FP16) {
      scale_f16[i].v = fp32_to_fp16(scale_f32_rcp[i].v);
    } else if (i_type == BF16) {
      scale_f16[i].v = fp32_to_bf16(scale_f32_rcp[i].v);
    }
    funNANChangeToMaxOrMin(&scale_f16[i].v, i_type);
#if TEST_FOR_DE_DV
    data2txt_uint16 = scaleBuffer[i];
    operators::printfData16bit(data2txt_uint16, file_p2_scaleBuffer);
#endif
#if TEST_FOR_DE_DV
    data2txt_uint16 = scale_f16[i].v;
    operators::printfData16bit(data2txt_uint16, file_p3_scale_f16);
#endif
  }
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      float32_t result_tmp32;
      if (i_type == FP16) {
        result_tmp32.v = fp16mul_resfp32(kMeanSub[tmp], scale_f16[i].v);
      } else if (i_type == BF16) {
        result_tmp32.v = bf16mul_resfp32(kMeanSub[tmp], scale_f16[i].v);
      }
      oBuffer[tmp] = f32_to_i8(result_tmp32.v);
#if TEST_FOR_DE_DV
      data2txt_uint8 = oBuffer[tmp];
      operators::printfData8bit(data2txt_uint8, file_p5_oBuffer);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = result_tmp32.v;
      operators::printfData32bit(data2txt_uint32, file_p6_result_tmp32);
#endif
    }
  }
  delete[] result_scale;
  delete[] max_blk32_value;
  delete[] max_blk32_value_row;
  delete[] scale_f32_rcp;
  delete[] scale_f32;
  delete[] kMeanSub;
  delete[] scale_f16;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_max_blk32_value_row);
  printfcloseFile(file_p2_scaleBuffer);
  printfcloseFile(file_p3_scale_f16);
  printfcloseFile(file_p4_kMeanSub);
  printfcloseFile(file_p5_oBuffer);
  printfcloseFile(file_p6_result_tmp32);
#endif
}
/*========================================
Function: vae_quant_perToken
model 0:input if BF16,output is FP8E4 , scale is FP16
model 1:input if FP16,output is FP8E4, scale is   BF16
Information:Author is ZC, 2025/09/10. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t ,src_row<128,src_col<128
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 .
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int8
output:
  oBuffer:[src_row][src_col]
  scaleBuffer:[1]
============================================*/
void vae_quant_perTensor(uint8_t *oBuffer, uint16_t *src_data,
                         uint16_t *scaleBuffer, int src_row, int src_col,
                         float16_t scaleFactor, DataType i_type,
                         DataType o_type) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_quant_perTensor";
  uint8_t data2txt_uint8;
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_max_blk32_value_row");
  FILE *file_p0_max_blk32_value_row;
  file_p0_max_blk32_value_row = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_pre_col_max");
  FILE *file_p1_pre_col_max;
  file_p1_pre_col_max = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_scaleBuffer");
  FILE *file_p2_scaleBuffer;
  file_p2_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_scale_f16");
  FILE *file_p3_scale_f16;
  file_p3_scale_f16 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_oBuffer");
  FILE *file_p5_oBuffer;
  file_p5_oBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_result_tmp32");
  FILE *file_p6_result_tmp32;
  file_p6_result_tmp32 = printfOpenFile(nodeName, opName);
#endif
  uint16_t max_blk32_value_row, pre_col_max, scale_f16;
  uint32_t scale_f32, scale_f32_rcp;
  if (i_type == FP16) {
    pre_col_max = 0xfc00;
  } else if (i_type == BF16) {
    pre_col_max = 0xff80;
  }
  uint32_t maxBlkStep = 32;
  uint32_t col_32blk =
      src_col + (maxBlkStep - (src_col % maxBlkStep)) % maxBlkStep;
  uint32_t maxBlkNum = col_32blk / maxBlkStep; // col
  uint16_t *result_scale = new uint16_t[1];
  uint16_t *max_blk32_value = new uint16_t[src_row * maxBlkNum];
  float16_t *kMeanSub = new float16_t[src_row * src_col];
  int absFlag = 1;
  for (uint32_t i = 0; i < src_row; i++) {
    uint32_t indexTmp = 0, tmpSrc = 0;
    // 4 max from a col
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      uint32_t dataNum =
          ((j + maxBlkStep) <= src_col) ? maxBlkStep : (src_col % maxBlkStep);
      tmpSrc = i * src_col + j;
      max_blk32_value[tmpMaxRet] =
          maxValue(src_data + tmpSrc, dataNum, i_type, absFlag);
      indexTmp++;
    }
    // 1max from 4 max
    tmpSrc = i * maxBlkNum;
    max_blk32_value_row =
        maxValue(max_blk32_value + tmpSrc, maxBlkNum, i_type, absFlag);
#if TEST_FOR_DE_DV
    data2txt_uint16 = max_blk32_value_row;
    operators::printfData16bit(data2txt_uint16, file_p0_max_blk32_value_row);
#endif
    // max compare with pre_col_max
    if (i_type == FP16) {
      max_blk32_value_row = fp16max(max_blk32_value_row, pre_col_max);
    } else if (i_type == BF16) {
      max_blk32_value_row = bf16max(max_blk32_value_row, pre_col_max);
    }
    pre_col_max = max_blk32_value_row;
#if TEST_FOR_DE_DV
    data2txt_uint16 = pre_col_max;
    operators::printfData16bit(data2txt_uint16, file_p1_pre_col_max);
#endif
  }
  max_blk32_value_row = pre_col_max;
  if (i_type == FP16) {
    scale_f32 = fp16mul_resfp32(max_blk32_value_row, scaleFactor.v);
  } else if (i_type == BF16) {
    scale_f32 = bf16mul_resfp32(max_blk32_value_row, scaleFactor.v);
  }
  if (o_type == FP16) {
    scaleBuffer[0] = fp32_to_fp16(scale_f32);
  } else if (o_type == BF16) {
    scaleBuffer[0] = fp32_to_bf16(scale_f32);
  }
  if (scale_f32 == 0x00000000 || scale_f32 == 0x80000000) {
    scale_f32 = 0x3f800000;
  }
  scale_f32_rcp = sfu_rcp(scale_f32);
  if (i_type == FP16) {
    scale_f16 = fp32_to_fp16(scale_f32_rcp);
  } else if (i_type == BF16) {
    scale_f16 = fp32_to_bf16(scale_f32_rcp);
  }
  funNANChangeToMaxOrMin(&scale_f16, i_type);
#if TEST_FOR_DE_DV
  data2txt_uint16 = scaleBuffer[0];
  operators::printfData16bit(data2txt_uint16, file_p2_scaleBuffer);
#endif
#if TEST_FOR_DE_DV
  data2txt_uint16 = scale_f16;
  operators::printfData16bit(data2txt_uint16, file_p3_scale_f16);
#endif
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      float32_t result_tmp32;
      if (i_type == FP16) {
        result_tmp32.v = fp16mul_resfp32(src_data[tmp], scale_f16);
      } else if (i_type == BF16) {
        result_tmp32.v = bf16mul_resfp32(src_data[tmp], scale_f16);
      }
      oBuffer[tmp] = f32_to_i8(result_tmp32.v);
#if TEST_FOR_DE_DV
      data2txt_uint8 = oBuffer[tmp];
      operators::printfData8bit(data2txt_uint8, file_p5_oBuffer);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = result_tmp32.v;
      operators::printfData32bit(data2txt_uint32, file_p6_result_tmp32);
#endif
    }
  }
  delete[] result_scale;
  delete[] max_blk32_value;
  delete[] kMeanSub;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_max_blk32_value_row);
  printfcloseFile(file_p1_pre_col_max);
  printfcloseFile(file_p2_scaleBuffer);
  printfcloseFile(file_p3_scale_f16);
  printfcloseFile(file_p5_oBuffer);
  printfcloseFile(file_p6_result_tmp32);
#endif
}
/*========================================
Function: vae_quant_perToken
model 0:input if BF16,output is FP8E4 , scale is FP16
model 1:input if FP16,output is FP8E4, scale is   BF16
Information:Author is ZC, 2025/09/10. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t ,src_row<128,src_col<128
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 .
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int8
output:
  oBuffer:[src_row][src_col]
  scaleBuffer: [src_row][1]
============================================*/
void vae_quant_perGroup(uint8_t *oBuffer, uint16_t *src_data,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type,
                        DataType o_type) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_quant_perGroup";
  uint8_t data2txt_uint8;
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_max_blk32_value_row");
  FILE *file_p0_max_blk32_value_row;
  file_p0_max_blk32_value_row = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_scaleBuffer");
  FILE *file_p1_scaleBuffer;
  file_p1_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_scale_f32");
  FILE *file_p2_scale_f32;
  file_p2_scale_f32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_oBuffer");
  FILE *file_p3_oBuffer;
  file_p3_oBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_result_tmp32");
  FILE *file_p4_result_tmp32;
  file_p4_result_tmp32 = printfOpenFile(nodeName, opName);
#endif
  uint32_t maxBlkStep = 32;
  uint32_t col_32blk =
      src_col + (maxBlkStep - (src_col % maxBlkStep)) % maxBlkStep;
  uint32_t maxBlkNum = col_32blk / maxBlkStep; // col
  uint16_t *result_scale = new uint16_t[1];
  uint16_t *max_blk32_value = new uint16_t[src_row * maxBlkNum];
  uint16_t *max_blk32_value_row = new uint16_t[src_row];
  float16_t *kMeanSub = new float16_t[src_row * src_col];
  float16_t *scale_f16 = new float16_t[src_row * maxBlkNum];
  float32_t *scale_f32_rcp = new float32_t[src_row * maxBlkNum];
  float32_t *scale_f32 = new float32_t[src_row * maxBlkNum];
  int absFlag = 1;
  uint32_t indexTmp = 0;
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      uint32_t dataNum =
          ((j + maxBlkStep) <= src_col) ? maxBlkStep : (src_col % maxBlkStep);
      uint32_t tmpSrc = i * src_col + j;
      max_blk32_value[tmpMaxRet] =
          maxValue(src_data + tmpSrc, dataNum, i_type, absFlag);
      indexTmp++;
#if TEST_FOR_DE_DV
      data2txt_uint16 = max_blk32_value[tmpMaxRet];
      operators::printfData16bit(data2txt_uint16, file_p0_max_blk32_value_row);
#endif
    }
    indexTmp = 0;
  }
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      if (i_type == FP16) {
        scale_f32[tmpMaxRet].v =
            fp16mul_resfp32(max_blk32_value[tmpMaxRet], scaleFactor.v);
        scaleBuffer[tmpMaxRet] = fp32_to_fp16(scale_f32[tmpMaxRet].v);
      } else if (i_type == BF16) {
        scale_f32[tmpMaxRet].v =
            bf16mul_resfp32(max_blk32_value[tmpMaxRet], scaleFactor.v);
        scaleBuffer[tmpMaxRet] = fp32_to_bf16(scale_f32[tmpMaxRet].v);
      }
      if (scale_f32[tmpMaxRet].v == 0 || scale_f32[tmpMaxRet].v == 0x80000000) {
        scale_f32[tmpMaxRet].v = 0x3f800000;
      }
      scale_f32_rcp[tmpMaxRet].v = sfu_rcp(scale_f32[tmpMaxRet].v);
      if (i_type == FP16) {
        scale_f16[tmpMaxRet].v = fp32_to_fp16(scale_f32_rcp[tmpMaxRet].v);
      } else if (i_type == BF16) {
        scale_f16[tmpMaxRet].v = fp32_to_bf16(scale_f32_rcp[tmpMaxRet].v);
      }
      funNANChangeToMaxOrMin(&scale_f16[tmpMaxRet].v, i_type);
#if TEST_FOR_DE_DV
      data2txt_uint16 = scaleBuffer[tmpMaxRet];
      operators::printfData16bit(data2txt_uint16, file_p1_scaleBuffer);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = scale_f32[tmpMaxRet].v;
      operators::printfData32bit(data2txt_uint32, file_p2_scale_f32);
#endif
      indexTmp++;
    }
    indexTmp = 0;
  }
  uint32_t tmpMaxRet = 0;
  for (uint32_t i = 0; i < src_row; i++) {
    indexTmp = 0;
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      float32_t result_tmp32;
      if (j == 0) {
        tmpMaxRet = i * maxBlkNum;
      }
      if (i_type == FP16) {
        result_tmp32.v = fp16mul_resfp32(src_data[tmp], scale_f16[tmpMaxRet].v);
      } else if (i_type == BF16) {
        result_tmp32.v = bf16mul_resfp32(src_data[tmp], scale_f16[tmpMaxRet].v);
      }
      oBuffer[tmp] = fp32_to_fp8e4(result_tmp32.v);
      if ((j + 1) % maxBlkStep == 0) {
        indexTmp++;
        tmpMaxRet = i * maxBlkNum + indexTmp;
      }
#if TEST_FOR_DE_DV
      data2txt_uint8 = oBuffer[tmp];
      operators::printfData8bit(data2txt_uint8, file_p3_oBuffer);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = result_tmp32.v;
      operators::printfData32bit(data2txt_uint32, file_p4_result_tmp32);
#endif
    }
  }
  delete[] result_scale;
  delete[] max_blk32_value;
  delete[] max_blk32_value_row;
  delete[] scale_f32_rcp;
  delete[] scale_f32;
  delete[] kMeanSub;
  delete[] scale_f16;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_max_blk32_value_row);
  printfcloseFile(file_p1_scaleBuffer);
  printfcloseFile(file_p2_scale_f32);
  printfcloseFile(file_p3_oBuffer);
  printfcloseFile(file_p4_result_tmp32);
#endif
}
/*========================================
Function: vae_quant_pergroup_mxfp4_mxfp8
input data model：
    input if BF16,output is FP8E4 , scale is FP16
    input if FP16,output is FP8E4, scale is   BF16
Information:Author is ZC, 2025/09/10. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t ,src_row<128,src_col<128
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int8
  mxfp4_fp8_flag: 0, if mxfp4; 1, is mafp8.
output:
  oBuffer:[src_row][src_col]
  scaleBuffer: [src_row][1]
============================================*/
void vae_quant_perGroup_mxfp4_mxfp8(uint8_t *oBuffer, uint16_t *src_data,
                                    uint8_t *scaleBuffer, int src_row,
                                    int src_col, DataType i_type,
                                    DataType o_type, uint16_t mxfp4_fp8_flag) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_quant_perGroup_mxfp4_mxfp8";
  uint8_t data2txt_uint8;
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
  uint24_t data2txt_uint24;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_max_blk32_value");
  FILE *file_p0_max_blk32_value;
  file_p0_max_blk32_value = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_scaleBuffer");
  FILE *file_p1_scaleBuffer;
  file_p1_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_oBuffer");
  FILE *file_p2_oBuffer;
  file_p2_oBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_max_blk32_value_fp24");
  FILE *file_p3_max_blk32_value_fp24;
  file_p3_max_blk32_value_fp24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_expo");
  FILE *file_p4_expo;
  file_p4_expo = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_temp_buff");
  FILE *file_p5_temp_buff;
  file_p5_temp_buff = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_scaleBuffer");
  FILE *file_p7_scaleBuffer;
  file_p7_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p8_scale_f24");
  FILE *file_p8_scale_f24;
  file_p8_scale_f24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p9_src_data_f24");
  FILE *file_p9_src_data_f24;
  file_p9_src_data_f24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p10_result_tmp24");
  FILE *file_p10_result_tmp24;
  file_p10_result_tmp24 = printfOpenFile(nodeName, opName);
#endif
  uint32_t maxBlkStep = 32;
  uint32_t col_32blk =
      src_col + (maxBlkStep - (src_col % maxBlkStep)) % maxBlkStep;
  uint32_t maxBlkNum = col_32blk / maxBlkStep; // col
  uint16_t *max_blk32_value = new uint16_t[src_row * maxBlkNum];
  float24_t *scale_f24 = new float24_t[src_row * maxBlkNum];
  int *scaleBufferTmp = new int[src_row * maxBlkNum];
  int temp_buff;
  float24_t *max_blk32_value_fp24 = new float24_t[src_row * maxBlkNum];
  int *expo = new int[src_row * maxBlkNum];
  int absFlag = 1;
  uint32_t indexTmp = 0;
  int emax;
  if (mxfp4_fp8_flag == 0) { // mxfp4
    emax = 2;
  } else if (mxfp4_fp8_flag == 1) { // mxfp8
    emax = 8;
  }
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      uint32_t dataNum =
          ((j + maxBlkStep) <= src_col) ? maxBlkStep : (src_col % maxBlkStep);
      uint32_t tmpSrc = i * src_col + j;
      max_blk32_value[tmpMaxRet] =
          maxValue(src_data + tmpSrc, dataNum, i_type, absFlag);
      indexTmp++;
#if TEST_FOR_DE_DV
      data2txt_uint16 = max_blk32_value[tmpMaxRet];
      operators::printfData16bit(data2txt_uint16, file_p0_max_blk32_value);
#endif
    }
    indexTmp = 0;
  }
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      if (i_type == FP16) {
        max_blk32_value_fp24[tmpMaxRet].v =
            fp16_to_fp24(max_blk32_value[tmpMaxRet]);
      } else if (i_type == BF16) {
        max_blk32_value_fp24[tmpMaxRet].v =
            bf16_to_fp24(max_blk32_value[tmpMaxRet]);
      }
#if TEST_FOR_DE_DV
      data2txt_uint24 = max_blk32_value_fp24[tmpMaxRet].v;
      operators::printfData24bit(data2txt_uint24, file_p3_max_blk32_value_fp24);
#endif
      expo[tmpMaxRet] = (max_blk32_value_fp24[tmpMaxRet].v >> 15) & 0xff;
#if TEST_FOR_DE_DV
      data2txt_uint8 = expo[tmpMaxRet];
      operators::printfData8bit(data2txt_uint8, file_p4_expo);
#endif
      if (expo[tmpMaxRet] == 255) {
        temp_buff = 255;
      } else {
        temp_buff = expo[tmpMaxRet] - emax;
      }
#if TEST_FOR_DE_DV
      data2txt_uint8 = temp_buff;
      operators::printfData8bit(data2txt_uint8, file_p5_temp_buff);
#endif
      if (temp_buff > 254) {
        scaleBuffer[tmpMaxRet] = 255;
      } else if (temp_buff < 0) {
        scaleBuffer[tmpMaxRet] = 0;
      } else {
        scaleBuffer[tmpMaxRet] = temp_buff;
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = scaleBuffer[tmpMaxRet];
      operators::printfData16bit(data2txt_uint16, file_p1_scaleBuffer);
#endif
      if (scaleBuffer[tmpMaxRet] == 255) {
        scaleBufferTmp[tmpMaxRet] = 255;
      } else {
        scaleBufferTmp[tmpMaxRet] = 254 - scaleBuffer[tmpMaxRet];
      }
#if TEST_FOR_DE_DV
      data2txt_uint8 = scaleBuffer[tmpMaxRet];
      operators::printfData8bit(data2txt_uint8, file_p7_scaleBuffer);
#endif
      if (scaleBufferTmp[tmpMaxRet] == 0xff) {
        scale_f24[tmpMaxRet].v = 0x7f8001;
      } else if (scaleBufferTmp[tmpMaxRet] == 0) {
        scale_f24[tmpMaxRet].v = 0x004000;
      } else {
        scale_f24[tmpMaxRet].v = scaleBufferTmp[tmpMaxRet] << 15;
      }
#if TEST_FOR_DE_DV
      data2txt_uint24 = scale_f24[tmpMaxRet].v;
      operators::printfData24bit(data2txt_uint24, file_p8_scale_f24);
#endif
      indexTmp++;
    }
    indexTmp = 0;
  }
  uint32_t tmpMaxRet = 0;
  for (uint32_t i = 0; i < src_row; i++) {
    indexTmp = 0;
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      float32_t result_tmp32;
      float24_t src_data_f24, result_tmp24;
      if (j == 0) {
        tmpMaxRet = i * maxBlkNum;
      }
      if (i_type == FP16) {
        src_data_f24.v = fp16_to_fp24(src_data[tmp]);
      } else if (i_type == BF16) {
        src_data_f24.v = bf16_to_fp24(src_data[tmp]);
      }
#if TEST_FOR_DE_DV
      data2txt_uint24 = src_data_f24.v;
      operators::printfData24bit(data2txt_uint24, file_p9_src_data_f24);
#endif
      result_tmp24.v = fp24mul(src_data_f24.v, scale_f24[tmpMaxRet].v);
#if TEST_FOR_DE_DV
      data2txt_uint24 = result_tmp24.v;
      operators::printfData24bit(data2txt_uint24, file_p10_result_tmp24);
#endif
      if (mxfp4_fp8_flag == 0) { // mxfp4
        oBuffer[tmp] = fp24_to_fp4e2m1(result_tmp24.v, false);
      } else if (mxfp4_fp8_flag == 1) { // mxfp8
        result_tmp32.v = fp24_to_fp32(result_tmp24.v);
        oBuffer[tmp] = fp32_to_fp8e4(result_tmp32.v);
      }
      if ((j + 1) % maxBlkStep == 0) {
        indexTmp++;
        tmpMaxRet = i * maxBlkNum + indexTmp;
      }
#if TEST_FOR_DE_DV
      data2txt_uint8 = oBuffer[tmp]; // p11
      operators::printfData8bit(data2txt_uint8, file_p2_oBuffer);
#endif
    }
  }
  delete[] max_blk32_value;
  delete[] scale_f24;
  delete[] max_blk32_value_fp24;
  delete[] expo;
  delete[] scaleBufferTmp;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_max_blk32_value);
  printfcloseFile(file_p1_scaleBuffer);
  printfcloseFile(file_p2_oBuffer);
  printfcloseFile(file_p3_max_blk32_value_fp24);
  printfcloseFile(file_p4_expo);
  printfcloseFile(file_p5_temp_buff);
  printfcloseFile(file_p7_scaleBuffer);
  printfcloseFile(file_p8_scale_f24);
  printfcloseFile(file_p9_src_data_f24);
  printfcloseFile(file_p10_result_tmp24);
#endif
}
/*========================================
Function: matrix Mul Point for Quantization
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data: dim [src_row][src_col], type uint16_t
  point: a data
  outData: dim [src_row][src_col], type uint8_t
  src_row: the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
output:
   outData: dim [src_row][src_col], type uint8_t
============================================*/
void matrixMulPointQuantization(const uint16_t *src_data, float32_t point,
                                uint8_t *outData, int src_row, int src_col,
                                DataType i_type, DataType o_type) {
#if 0 // TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "quant";
  uint16_t data2txt_uint8;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p5_outData");
  FILE *file_p5_outData;
  file_p5_outData = printfOpenFile(nodeName, opName);
#endif
  float16_t data_f16, scale_f16_rcp, result_tmp16;
  float32_t result_tmp32;
  for (int i = 0; i < src_row; i++) {
    for (int j = 0; j < src_col; j++) {
      int tmp = i * src_col + j;
      data_f16.v = src_data[tmp];
      if (i_type == FP16) {
        scale_f16_rcp.v = fp32_to_fp16(point.v);
        funNANChangeToMaxOrMin(&scale_f16_rcp.v, i_type);
        result_tmp32.v = fp16mul_resfp32(data_f16.v, scale_f16_rcp.v);
      } else if (i_type == BF16) {
        scale_f16_rcp.v = fp32_to_bf16(point.v);
        funNANChangeToMaxOrMin(&scale_f16_rcp.v, i_type);
        result_tmp32.v = bf16mul_resfp32(data_f16.v, scale_f16_rcp.v);
      }
      outData[tmp] = f32_to_i8(result_tmp32.v);
#if TEST_FOR_DE_DV
      data2txt_uint8 = outData[tmp];
      operators::printfData8bit(data2txt_uint8, file_p5_outData);
#endif
    }
  }
#if TEST_FOR_DE_DV
  printfcloseFile(file_p5_outData);
#endif
}
/*========================================
Function: vae_quant_NVFP4
model 0:input if BF16,output is FP8E4 , scale is FP16
model 1:input if FP16,output is FP8E4, scale is   BF16
Information:Author is ZC, 2025/09/10. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t ,src_row<128,src_col<128
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 .
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type, is int8
  preMax: last 128 max value
  K-mean:
output:
  oBuffer:[src_row][src_col]
  scaleBuffer: [src_row][1]
============================================*/
void vae_quant_NVFP4(uint8_t *oBuffer, uint16_t *src_data, uint8_t *scaleBuffer,
                     int src_row, int src_col, uint32_t globalScale,
                     DataType i_type, DataType o_type) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_quant_NVFP4";
  uint8_t data2txt_uint8;
  uint16_t data2txt_uint16;
  uint24_t data2txt_uint24;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_max_blk32_value");
  FILE *file_p0_max_blk32_value;
  file_p0_max_blk32_value = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_rec_scalemul6");
  FILE *file_p1_rec_scalemul6;
  file_p1_rec_scalemul6 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_scale_f32");
  FILE *file_p4_scale_f32;
  file_p4_scale_f32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_scaleBuffer");
  FILE *file_p5_scaleBuffer;
  file_p5_scaleBuffer = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_scaleNow");
  FILE *file_p6_scaleNow;
  file_p6_scaleNow = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_scale_f32_rcp");
  FILE *file_p7_scale_f32_rcp;
  file_p7_scale_f32_rcp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p8_scale_f24");
  FILE *file_p8_scale_f24;
  file_p8_scale_f24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p9_src_data_f24");
  FILE *file_p9_src_data_f24;
  file_p9_src_data_f24 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p10_result_f24");
  FILE *file_p10_result_f24;
  file_p10_result_f24 = printfOpenFile(nodeName, opName);
#endif
  uint32_t DATA = 0x40c00000; // data 6
  uint32_t scalemul6 = fp32mul(DATA, globalScale);
  uint32_t rec_scalemul6;
  if (scalemul6 == 0 || scalemul6 == 0x80000000) {
    scalemul6 = 0;
    rec_scalemul6 = 0;
  } else {
    rec_scalemul6 = sfu_rcp(scalemul6);
  }
  if (rec_scalemul6 == 0x7f800000) { //+inf
    rec_scalemul6 = 0x7f7fffff;      // +max
  }
#if TEST_FOR_DE_DV
  data2txt_uint32 = rec_scalemul6;
  operators::printfData32bit(data2txt_uint32, file_p1_rec_scalemul6);
#endif
  uint32_t maxBlkStep = 16;
  uint32_t col_32blk =
      src_col + (maxBlkStep - (src_col % maxBlkStep)) % maxBlkStep;
  uint32_t maxBlkNum = col_32blk / maxBlkStep; // col
  uint16_t *max_blk32_value = new uint16_t[src_row * maxBlkNum];
  uint16_t *max_blk32_value_row = new uint16_t[src_row];
  float16_t *kMeanSub = new float16_t[src_row * src_col];
  float32_t *scale_f32_rcp = new float32_t[src_row * maxBlkNum];
  float32_t *scale_f32 = new float32_t[src_row * maxBlkNum];
  int absFlag = 1;
  uint32_t indexTmp = 0;
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      uint32_t dataNum =
          ((j + maxBlkStep) <= src_col) ? maxBlkStep : (src_col % maxBlkStep);
      uint32_t tmpSrc = i * src_col + j;
      max_blk32_value[tmpMaxRet] =
          maxValue(src_data + tmpSrc, dataNum, i_type, absFlag);
      indexTmp++;
#if TEST_FOR_DE_DV
      data2txt_uint16 = max_blk32_value[tmpMaxRet];
      operators::printfData16bit(data2txt_uint16, file_p0_max_blk32_value);
#endif
    }
    indexTmp = 0;
  }
  float24_t *scale_f24 = new float24_t[src_row * maxBlkNum];
  for (uint32_t i = 0; i < src_row; i++) {
    for (uint32_t j = 0; j < src_col; j += maxBlkStep) {
      uint32_t tmpMaxRet = i * maxBlkNum + indexTmp;
      float24_t max_f24;
      if (i_type == FP16) {
        max_f24.v = fp16_to_fp24(max_blk32_value[tmpMaxRet]);
      } else if (i_type == BF16) {
        max_f24.v = bf16_to_fp24(max_blk32_value[tmpMaxRet]);
      }
      scale_f32[tmpMaxRet].v = fp32fp24mul_resfp32(rec_scalemul6, max_f24.v);
      scaleBuffer[tmpMaxRet] = fp32_to_fp8e4m3(scale_f32[tmpMaxRet].v);
      uint32_t scaleNow = fp32mul(scale_f32[tmpMaxRet].v, globalScale);
      if (scaleNow == 0 || scaleNow == 0x80000000) {
        scaleNow = 0x3f800000;
      }
      scale_f32_rcp[tmpMaxRet].v = sfu_rcp(scaleNow);
      scale_f24[tmpMaxRet].v = fp32_to_fp24(scale_f32_rcp[tmpMaxRet].v);
      funNANChangeToMaxOrMinFP24(&scale_f24[tmpMaxRet].v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = scale_f32[tmpMaxRet].v;
      operators::printfData32bit(data2txt_uint32, file_p4_scale_f32);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint8 = scaleBuffer[tmpMaxRet];
      operators::printfData8bit(data2txt_uint8, file_p5_scaleBuffer);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = scaleNow;
      operators::printfData32bit(data2txt_uint32, file_p6_scaleNow);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = scale_f32_rcp[tmpMaxRet].v;
      operators::printfData32bit(data2txt_uint32, file_p7_scale_f32_rcp);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = scale_f24[tmpMaxRet].v;
      operators::printfData24bit(data2txt_uint24, file_p8_scale_f24);
#endif
      indexTmp++;
    }
    indexTmp = 0;
  }
  uint32_t tmpMaxRet = 0;
  for (uint32_t i = 0; i < src_row; i++) {
    indexTmp = 0;
    for (uint32_t j = 0; j < src_col; j++) {
      uint32_t tmp = i * src_col + j;
      float32_t result_tmp32;
      float24_t src_data_f24, result_f24;
      if (j == 0) {
        tmpMaxRet = i * maxBlkNum;
      }
      if (i_type == FP16) {
        src_data_f24.v = fp16_to_fp24(src_data[tmp]);
      } else if (i_type == BF16) {
        src_data_f24.v = bf16_to_fp24(src_data[tmp]);
      }
      result_f24.v = fp24mul(src_data_f24.v, scale_f24[tmpMaxRet].v);
      oBuffer[tmp] = fp24_to_fp4e2m1(result_f24.v, false);
      if ((j + 1) % maxBlkStep == 0) {
        indexTmp++;
        tmpMaxRet = i * maxBlkNum + indexTmp;
      }
#if TEST_FOR_DE_DV
      data2txt_uint24 = src_data_f24.v;
      operators::printfData24bit(data2txt_uint24, file_p9_src_data_f24);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint24 = result_f24.v;
      operators::printfData24bit(data2txt_uint24, file_p10_result_f24);
#endif
    }
  }
  delete[] max_blk32_value;
  delete[] max_blk32_value_row;
  delete[] scale_f32_rcp;
  delete[] scale_f32;
  delete[] kMeanSub;
  delete[] scale_f24;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_max_blk32_value);
  printfcloseFile(file_p1_rec_scalemul6);
  printfcloseFile(file_p4_scale_f32);
  printfcloseFile(file_p5_scaleBuffer);
  printfcloseFile(file_p6_scaleNow);
  printfcloseFile(file_p7_scale_f32_rcp);
  printfcloseFile(file_p8_scale_f24);
  printfcloseFile(file_p9_src_data_f24);
  printfcloseFile(file_p10_result_f24);
#endif
}

/*========================================
Function: vae_quant.  model: 0, is per tensor Q; 1, is per group Q . // for fa1
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 or 1/448.
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
output:
  result: a 2D matrix
============================================*/
void vae_quant(uint8_t *result, uint16_t *src_data, uint16_t *ret_scale,
               int src_row, int src_col, float16_t scaleFactor, DataType i_type,
               DataType o_type) {
#if 0 // TEST_FOR_DE_DV
    deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "quant";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p3_new_max_blk_abs");
  FILE *file_p3_new_max_blk_abs;
  file_p3_new_max_blk_abs = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_result_scale");
  FILE *file_p4_result_scale;
  file_p4_result_scale = printfOpenFile(nodeName, opName);
#endif
  uint16_t *result_scale = new uint16_t[1];
  float16_t new_max_blk, new_max_blk_abs, scale_f16;
  float32_t scale_f32, scale_f32_rcp;
  int dataNum = src_row * src_col;
  int absFlag = 1;
  new_max_blk.v = maxValue(src_data, dataNum, i_type, absFlag);
  new_max_blk_abs = f16abs(new_max_blk);
#if TEST_FOR_DE_DV
  data2txt_uint16 = new_max_blk_abs.v;
  operators::printfData16bit(data2txt_uint16, file_p3_new_max_blk_abs);
#endif
  if (i_type == FP16) {
    scale_f32.v =
        fp16mul_resfp32(new_max_blk_abs.v,
                        scaleFactor.v); // get scale_f16 = 1/(2^7 - 1) *max|Vm|;
    result_scale[0] = fp32_to_fp16(scale_f32.v);
  } else if (i_type == BF16) {
    scale_f32.v =
        bf16mul_resfp32(new_max_blk_abs.v,
                        scaleFactor.v); // get scale_f16 = 1/(2^7 - 1) *max|Vm|;
    result_scale[0] = fp32_to_bf16(scale_f32.v);
  }
  if (scale_f32.v == 0 || scale_f32.v == 0x80000000) {
    scale_f32.v = 0x3f800000;
  }
  scale_f32_rcp.v = sfu_rcp(scale_f32.v);
#if TEST_FOR_DE_DV
  data2txt_uint16 = result_scale[0];
  operators::printfData16bit(data2txt_uint16, file_p4_result_scale);
#endif
  matrixMulPointQuantization(src_data, scale_f32_rcp, result, src_row, src_col,
                             i_type, o_type);
  ret_scale[0] = result_scale[0];
  delete[] result_scale;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p3_new_max_blk_abs);
  printfcloseFile(file_p4_result_scale);
#endif
}

/*========================================
Function: vae_perToken_k.  model: 2, is per token k.
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/28. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  k_mean: dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  scaleFactor: 1/127 or 1/448.
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
output:
  result: a 2D matrix
  ret_scale: quant scale
============================================*/
void vae_perToken_k(uint8_t *result, const uint16_t *src_data,
                    uint16_t *ret_scale, uint16_t *k_mean, int src_row,
                    int src_col, float16_t scaleFactor, DataType i_type,
                    DataType o_type) {
#if 0 // TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_perToken_k";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p2_src_data_mean");
  FILE *file_p2_src_data_mean;
  file_p2_src_data_mean = printfOpenFile(nodeName, opName);
#endif
  uint16_t *src_data_mean = new uint16_t[src_row * src_col];
  float16_t src_data_one, src_k_mean_one;
  for (int i = 0; i < src_row; i++) // k_mean
  {
    for (int j = 0; j < src_col; j++) {
      int tmp = i * src_col + j;
      src_data_one.v = src_data[tmp];
      src_k_mean_one.v = k_mean[j];
      if (i_type == FP16) {
        src_data_mean[tmp] = fp16sub(src_data_one.v, src_k_mean_one.v);
      } else if (i_type == BF16) {
        src_data_mean[tmp] = bf16sub(src_data_one.v, src_k_mean_one.v);
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = src_data_mean[tmp];
      operators::printfData16bit(data2txt_uint16, file_p2_src_data_mean);
#endif
    }
  }
  uint32_t kMeanBypass = 0;
  vae_quant_perToken(result, src_data_mean, k_mean, ret_scale, src_row, src_col,
                     scaleFactor, i_type, o_type, kMeanBypass);
  delete[] src_data_mean;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p2_src_data_mean);
#endif
}

} // namespace operators