#include "vae_common.h"
#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include <dirent.h>
#include <string.h>
#include <unistd.h>
namespace operators {
/*========================================
Function:for a data ,if is NAN,changing to max value
if is -NAN, changing to min value
data type : FP24
============================================*/
void funNANChangeToMaxOrMinFP24(uint24_t *data) {
  if (*data == 0xff8000) { // -inf
    *data = 0xff7fff;
  } else if (*data == 0x7f8000) { // inf
    *data = 0x7f7fff;
  }
}
/*========================================
Function:for a data ,if is NAN,changing to max value
if is -NAN, changing to min value
data type : bf16 ,fp16
============================================*/
void funNANChangeToMaxOrMin(uint16_t *data, DataType type) {
  if (type == BF16) {
    if (*data == 0xff80) { // -inf
      *data = 0xff7f;
    } else if (*data == 0x7f80) { // inf
      *data = 0x7f7f;
    }
  } else if (type == FP16) {
    if (*data == 0xfc00) { // -inf
      *data = 0xfbff;
    } else if (*data == 0x7c00) { // inf
      *data = 0x7bff;
    }
  }
}
/*========================================
Function: get abs data
============================================*/
float16_t f16abs(float16_t a) {
  float16_t b;
  b.v = a.v & 0x7fff;
  return b;
}

/*========================================
Function: calculate the smallest power 0f 2 that is not less than n
Information:Author is ZC, 2025/07/14. by qingyan
input:
  n:0,1,2,3,4,5,6,7,8,16s
output:
  p：
test :
   ok
============================================*/
int maxPowerOfTwo(int n) {
  if (n < 0) {
    exit(EXIT_FAILURE);
  }

  if (n <= 1)
    return 2;
  int p = 1;
  while (p < n)
    p <<= 1;
  return p;
}
/*========================================
Function: padding data copy
Information:Author is ZC, 2025/07/14. by qingyan
input:
  data, dim [1][src_col], type uint24_t
  noPaddingNum :valid data number,such 127
  paddingNum : padding num,ifsrc_col =127, paddingNum = 1
  paddingVlaue: 0, -inf +inf ,and so on .
output:
  data : padding Vlaue copy
test:
ok
============================================*/
void paddingDataCopy(float24_t *data, float24_t paddingVlaue, int paddingNum,
                     int noPaddingNum) {
  if (data == NULL) {
    exit(EXIT_FAILURE);
  }

  int dataAllSize = paddingNum + noPaddingNum;
  for (int i = noPaddingNum; i < dataAllSize; i++) {
    data[i] = paddingVlaue;
  }
}

/*========================================
Function: calculate the add2
Information:Author is ZC, 2025/07/14. by qingyan
input:
  src_data, dim [1][src_col], type uint24_t
  src_col :valid data number,such 127
  paddingVlaue:0, -inf +inf ,and so on .
  paddingNumFlag: if paddingNumFlag = 0, paddingNum calcute by add2 inside. if
paddingNumFlag=others, paddingNum from outside parameters paddingNum : padding
num,ifsrc_col =127, paddingNum = 1 output: result , dim [1] , type uint24_t
============================================*/
float24_t add2(float24_t *src_data, int src_col, float24_t paddingValue) {

  if (src_data == NULL) {
    exit(EXIT_FAILURE);
  }

  int powerNum = maxPowerOfTwo(src_col);
  int noPaddingNum = src_col, index = 0;
  ;
  float24_t result;
  float24_t data0, data1;
  int index_tmp;
  int paddingNum = powerNum - src_col;

  paddingDataCopy(src_data, paddingValue, paddingNum, noPaddingNum);

  while (powerNum > 1) {
    for (int j = 0; j < powerNum; j += 2) {
      data0.v = src_data[j].v;
      data1.v = src_data[j + 1].v;
      src_data[index].v = fp24add(data0.v, data1.v);
      index++;
    }
    index = 0;
    powerNum >>= 1;
  }
  result.v = src_data[0].v;
  return result;
}

/*========================================
Function: find max value
Information:Author is ZC, 2025/07/15. by qingyan
input:
inputData , dim [1][Num], type float16_t
dataNum, dim [1],type int
absFlag, if =0, not abs, if ==1, need abs
output:
maxValue, dim [1], type float16_t
============================================*/
uint16_t maxValue(const uint16_t *inputData, int dataNum, DataType i_type,
                  int absFlag) {
  float16_t data, ret;
  if (i_type == FP16) {
    ret.v = 0xfc00; // -inf
  } else if (i_type == BF16) {
    ret.v = 0xff80; // -inf
  }
  for (int i = 0; i < dataNum; i++) {
    data.v = inputData[i];
    if (absFlag == 1) {
      data = f16abs(data);
    }
    // data = f16abs(data);

    if (i_type == FP16) {
      ret.v = fp16max(data.v, ret.v);
    } else if (i_type == BF16) {
      ret.v = bf16max(data.v, ret.v);
    }
  }
  return ret.v;
}
/*========================================
Function: find max value
Information:Author is ZC, 2025/07/15. by qingyan
input:
inputData , dim [1][Num], type float16_t
dataNum, dim [1],type int
absFlag, if =0, not abs, if ==1, need abs
output:
maxValue, dim [1], type float16_t
============================================*/
uint16_t maxValue_argmax(const uint16_t *inputData, uint32_t *ret_index,
                         int dataNum, DataType i_type, int absFlag) {
  float16_t data, ret;
  ret_index[0] = 0;
  if (i_type == FP16) {
    ret.v = 0xfc00; // -inf
  } else if (i_type == BF16) {
    ret.v = 0xff80; // -inf
  }
  for (int i = 0; i < dataNum; i++) {
    data.v = inputData[i];
    if (absFlag == 1) {
      data = f16abs(data);
    }
    if (data.v != ret.v) {
      if (i_type == FP16) {
        ret.v = fp16max(data.v, ret.v);
      } else if (i_type == BF16) {
        ret.v = bf16max(data.v, ret.v);
      }
      if (ret.v == data.v) {
        ret_index[0] = i;
      }
    }
  }
  return ret.v;
}
/*========================================
Function: find min value
Information:Author is ZC, 2025/08/19. by qingyan
input:
inputData , dim [1][Num], type float16_t
dataNum, dim [1],type int
absFlag, if =0, not abs, if ==1, need abs
output:
maxValue, dim [1], type float16_t
============================================*/
uint16_t minValue(const uint16_t *inputData, int dataNum, DataType i_type,
                  int absFlag) {
  float16_t data, ret;
  if (i_type == FP16) {
    ret.v = 0x7c00; // inf
  } else if (i_type == BF16) {
    ret.v = 0x7f80; // inf
  }
  for (int i = 0; i < dataNum; i++) {
    data.v = inputData[i];
    if (absFlag == 1) {
      data = f16abs(data);
    }
    if (i_type == FP16) {
      ret.v = fp16min(data.v, ret.v);
    } else if (i_type == BF16) {
      ret.v = bf16min(data.v, ret.v);
    }
  }
  return ret.v;
}
#if defined(USE_EXTERN_C)
/*========================================
Function:this cmath generates testing data of mxfp4
Information:Author is ZC, 2025/11/5.
parameter:
  inputData: 2d matrix
============================================*/
void quant_group_mxfp4_cmath(uint16_t *inputData, uint8_t *outData,
                             uint8_t *outScale, uint32_t row, uint32_t col,
                             DataType i_type) {
  uint16_t maxValue = 0;
  uint16_t inputDataTmp;
  uint8_t facMulMax, rcp_max;
  uint32_t blkStep = 32;
  int blkIndex = 0;
  uint32_t i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j += blkStep) {
      int blkNumNow = ((j + blkStep) <= col) ? blkStep : (col % blkStep);
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        inputDataTmp = inputData[tmp];
        if (i_type == BF16) {
          maxValue = bf16max(abs(inputDataTmp), maxValue);
        } else if (i_type == FP16) {
          maxValue = fp16max(abs(inputDataTmp), maxValue);
        }
      }
      if (i_type == BF16) {
        facMulMax = (maxValue >> 7) & 0xff;
      } else if (i_type == FP16) {
        facMulMax = (maxValue >> 10) & 0x1f;
      }
      rcp_max = facMulMax - 2;
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        outData[tmp] = inputData[tmp] >> rcp_max;
      }
      blkIndex++;
    }
    blkIndex = 0;
  }
}

/*========================================
Function:this cmath generates testing data of reduce-mean
Information:Author is ZC, 2025/09/19.
parameter:
  inputData: 2d matrix
============================================*/
void reduce_mean_float(float *inputData, float *outData, int row, int col) {
  for (int i = 0; i < row; i++) {
    outData[i] = 0;
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      outData[i] += inputData[tmp];
    }
    outData[i] = outData[i] / col;
  }
}
/*========================================
Function:this cmath generates testing data of rope
Information:Author is ZC, 2025/07/28.
parameter:
  inputData: 2d matrix
============================================*/
void reduce_cmath(double *inputData, double *outData, int *outIndex, int row,
                  int col, char *model) {
  if (strcmp(model, "max") == 0) {
#if 0
      printf("====reduce max cmath=====\n");
#endif
    for (int i = 0; i < row; i++) {
      outData[i] = -INFINITY; //-inf
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        if (inputData[tmp] > outData[i]) {
          outData[i] = inputData[tmp];
        }
#if 0
          printf("outData[%d] = %f,\n", j , outData[i]);
#endif
      }
    }
  }
  if (strcmp(model, "min") == 0) {
    for (int i = 0; i < row; i++) {
      outData[i] = INFINITY; // inf
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        if (inputData[tmp] < outData[i]) {
          outData[i] = inputData[tmp];
        }
      }
    }
  }
  if (strcmp(model, "avg_mean") == 0) {
    for (int i = 0; i < row; i++) {
      outData[i] = 0;
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        outData[i] += inputData[tmp];
      }
      outData[i] = outData[i] / col;
    }
  }
  if (strcmp(model, "argmax") == 0) {
    for (int i = 0; i < row; i++) {
      outData[i] = -INFINITY; //-inf
      outIndex[i] = 0;
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        if (inputData[tmp] > outData[i]) {
          outData[i] = inputData[tmp];
          outIndex[i] = j;
        }
      }
    }
  }
  if (strcmp(model, "add") == 0) {
    for (int i = 0; i < row; i++) {
      outData[i] = 0;
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        outData[i] += inputData[tmp];
      }
    }
  }
  if (strcmp(model, "add32") == 0) {
    int col_now = col + ((32 - col % 32) % 32);
#if 0
      printf("col_now = %d \n", col_now);
#endif
    int index = 0;
    for (int i = 0; i < row; i++) {
      outData[index] = 0;
      for (int j = 0; j < col_now; j++) {
        int tmp = i * col + j;
        double data;
        if (j >= col) {
          data = 0;
        } else {
          data = inputData[tmp];
        }
        outData[index] += data;
        if ((j + 1) % 32 == 0) {
#if 0
            printf("index = %d \n", index);
#endif
          index++;
        }
      }
    }
  }
  if (strcmp(model, "top2") == 0) {
    int index = 0;
    for (int i = 0; i < row; i++) {
      double max1 = -INFINITY; //-inf
      double max2 = -INFINITY; //-inf
      outIndex[index] = 0;
      outIndex[index + 1] = 0;
      for (int j = 0; j < col; j++) {
        int tmp = i * col + j;
        if (inputData[tmp] > max1) {
          max2 = max1;
          max1 = inputData[tmp];
          outIndex[index + 1] = outIndex[index];
          outData[index + 1] = max2;
          outIndex[index] = j;
          outData[index] = max1;
        } else if (inputData[tmp] > max2) {
          max2 = inputData[tmp];
          outIndex[index + 1] = j;
          outData[index + 1] = inputData[tmp];
        }
      }
      index += 2;
    }
  }
}
void reduce_cmath_add32_fp32(float *inputData, float *outData, uint32_t row,
                             uint32_t col) {
  int col_now = col + ((32 - col % 32) % 32);
#if 0
      printf("col_now = %d \n", col_now);
#endif
  int index = 0;
  for (int i = 0; i < row; i++) {
    outData[index] = 0;
    for (int j = 0; j < col_now; j++) {
      int tmp = i * col + j;
      double data;
      if (j >= col) {
        data = 0;
      } else {
        data = inputData[tmp];
      }
      outData[index] += data;
      if ((j + 1) % 32 == 0) {
#if 0
            printf("index = %d \n", index);
#endif
        index++;
      }
    }
  }
}

void reduce_cmath_top2_fp32(float *inputData, float *outData, int *outIndex,
                            uint32_t row, uint32_t col) {
  int index = 0;
  for (int i = 0; i < row; i++) {
    float max1 = -INFINITY; //-inf
    float max2 = -INFINITY; //-inf
    outIndex[index] = 0;
    outIndex[index + 1] = 0;
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      if (inputData[tmp] > max1) {
        max2 = max1;
        max1 = inputData[tmp];
        outIndex[index + 1] = outIndex[index];
        outData[index + 1] = max2;
        outIndex[index] = j;
        outData[index] = max1;
      } else if (inputData[tmp] > max2) {
        max2 = inputData[tmp];
        outIndex[index + 1] = j;
        outData[index + 1] = inputData[tmp];
      }
    }
    index += 2;
  }
}
/*========================================
Function:this cmath generates testing data of quantization
Information:Author is ZC, 2025/07/28.
parameter:
  inputData: 2d matrix
  outData: 2d matrix
  factor: 1/448 or 1/(2^7 -1)
  model: 0, is per tensor Q; 1, is per group Q; 2, is per tensor k
============================================*/
void quantization(double *inputData, double *outData, double factor, int model,
                  int row, int col, const double *mean) {
#if 0
    printf("======quantization cmath=====\n");
#endif
  double maxValue = 0;
  int dataNum = col * row;
  double inputDataTmp;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      inputDataTmp = inputData[tmp];
      if (model == 2) {
        inputDataTmp = inputDataTmp - mean[j];
      }
      maxValue = max(abs(inputDataTmp), maxValue);
    }
  }
  double scale = maxValue * factor;
#if 0
    printf("maxValue = %f \n", maxValue);
    printf("scale = %f \n", scale);
#endif
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      if (model == 1) {
        inputDataTmp = inputData[tmp] - mean[tmp];
      } else {
        inputDataTmp = inputData[tmp];
      }
      outData[tmp] = inputDataTmp / scale;
#if 0
        printf("outData[tmp] = %f \n", outData[tmp]);
#endif
    }
  }
}
/*========================================
Function:test  per token quant
============================================*/
void quantizationPerToken(double *inputData, double *outData, double factor,
                          int model, int row, int col, const double *mean,
                          uint32_t kMeanBypass) {
  double maxValue = 0;
  double inputDataTmp, rcp_max, facMulMax;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      int tmp = i * col + j;
      inputDataTmp = inputData[tmp];
      maxValue = max(abs(inputDataTmp), maxValue);
    }
    facMulMax = maxValue * factor;
    rcp_max = 1.0 / facMulMax;
    for (uint32_t j = 0; j < col; j++) {
      int tmp = i * col + j;
      if (kMeanBypass == 1) {
        inputDataTmp = inputData[tmp] - mean[j];
      } else {
        inputDataTmp = inputData[tmp];
      }
      outData[tmp] = inputDataTmp * rcp_max;
    }
  }
}
/*========================================
Function:test  per tensor
============================================*/
void quantizationPerTensorCmath(double *inputData, double *outData,
                                double factor, int model, int row, int col,
                                const double *mean, uint32_t kMeanBypass) {
  double maxValue = 0;
  double inputDataTmp, rcp_max, facMulMax;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      int tmp = i * col + j;
      inputDataTmp = inputData[tmp];
      maxValue = max(abs(inputDataTmp), maxValue);
    }
  }
  facMulMax = maxValue * factor;
  rcp_max = 1.0 / facMulMax;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      int tmp = i * col + j;
      if (kMeanBypass == 1) {
        inputDataTmp = mean[j] - inputData[tmp];
      } else {
        inputDataTmp = inputData[tmp];
      }
      outData[tmp] = inputDataTmp * rcp_max;
    }
  }
}
/*========================================
Function:test  per group
============================================*/
void quantizationPerGroup(double *inputData, double *outData, double factor,
                          int model, int row, int col) {
  double maxValue = 0;
  double inputDataTmp, rcp_max, facMulMax;
  int blkStep = 32;
  int blkIndex = 0;
  uint32_t i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j += blkStep) {
      int blkNumNow = ((j + blkStep) <= col) ? blkStep : (col % blkStep);
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        inputDataTmp = inputData[tmp];
        maxValue = max(abs(inputDataTmp), maxValue);
      }
      facMulMax = maxValue * factor;
      rcp_max = 1.0 / facMulMax;
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        inputDataTmp = inputData[tmp];
        outData[tmp] = inputDataTmp * rcp_max;
      }
      blkIndex++;
    }
    blkIndex = 0;
  }
}
/*========================================
Function:test  per group fp4
============================================*/
void quantizationNVPFP4(float *inputData, float *outData, float *outScale,
                        float factor, int model, int row, int col) {
  float maxValue = 0;
  float inputDataTmp, rcp_max, scale0_out;
  int blkStep = 16;
  int blkIndex = 0;
  float scale0_0 = 1.0 / (6.0 * factor);
  uint32_t i = 0, j = 0, index = 0;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j += blkStep) {
      int blkNumNow = ((j + blkStep) <= col) ? blkStep : (col % blkStep);
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        inputDataTmp = inputData[tmp];
        maxValue = max(abs(inputDataTmp), maxValue);
      }
      outScale[index] = maxValue * scale0_0;
      rcp_max = 1.0 / (outScale[index] * factor);
      for (uint32_t k = 0; k < blkNumNow; k++) {
        int tmp = i * col + blkIndex * blkStep + k;
        inputDataTmp = inputData[tmp];
        outData[tmp] = inputDataTmp * rcp_max;
      }
      blkIndex++;
      index++;
    }
    blkIndex = 0;
  }
}
/*========================================
Function:this cmath generates testing data of rope
Information:Author is ZC, 2025/07/28.
parameter:
  inputData: 2d matrix
============================================*/
void rope_cmath(double *inputData, double *q_cmath, int row, int col,
                double *out_rope, double *out_quant_rope, double paddingValue,
                double factor, const double *mean, int byPassFlag) {
#if 0
    printf("=====rope cmath ======\n");
#endif
  int col_align_2 = col * 2;
  if (col_align_2 % 4 != 0) {
    col_align_2 = col_align_2 + col_align_2 % 4;
  }
  double *q_cmath_copy = new double[row * col_align_2];
  double *rope_tmp = new double[row * col_align_2];
  double *inputData_copy = new double[row * col_align_2];
  int q_index = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col_align_2; j += 4) {
      int tmp = i * col_align_2 + j;
      q_cmath_copy[tmp] = q_cmath[q_index + 1];     // cos
      q_cmath_copy[tmp + 1] = -q_cmath[q_index];    //-sin
      q_cmath_copy[tmp + 2] = q_cmath[q_index];     // sin
      q_cmath_copy[tmp + 3] = q_cmath[q_index + 1]; // cos
      q_index += 2;
    }
  }
  q_index = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col_align_2; j += 4) {
      int tmp = i * col_align_2 + j;
      inputData_copy[tmp] = inputData[q_index];
      inputData_copy[tmp + 1] = inputData[q_index + 1];
      inputData_copy[tmp + 2] = inputData[q_index];
      inputData_copy[tmp + 3] = inputData[q_index + 1];
      q_index += 2;
    }
  }
#if 0
    printf("col = %d \n", col);
    printf("col_align_2 = %d \n", col_align_2);
#endif
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col_align_2; j++) {
      int tmp = i * col_align_2 + j;
      rope_tmp[tmp] = inputData_copy[tmp] * q_cmath_copy[tmp];
#if 0
        printf("rope_tmp[%d] = %f,q_cmath_copy[%d] = %f \n", tmp, rope_tmp[tmp], tmp, q_cmath_copy[tmp]);
#endif
    }
  }
  int out_rope_index = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col_align_2; j += 2) {
      int tmp = i * col_align_2 + j;
      out_rope[out_rope_index] = rope_tmp[tmp] + rope_tmp[tmp + 1];
#if 0
        printf("out_rope[%d] = %f,\n", out_rope_index, out_rope[out_rope_index]);
#endif
      out_rope_index++;
    }
  }
  int model;
  if (byPassFlag == 0) {
    ;
  } else if (byPassFlag == 1) {
    model = 1;
    quantization(out_rope, out_quant_rope, factor, model, row, col, mean);
  } else if (byPassFlag == 2) {
    model = 2;
    quantization(out_rope, out_quant_rope, factor, model, row, col, mean);
  }

  delete[] q_cmath_copy;
  delete[] rope_tmp;
  delete[] inputData_copy;
}
/*========================================
Function:this cmath generates testing data of mask
Information:Author is ZC, 2025/07/27.
parameter:src_data,dataNum
input, inputDataA: input data address.
input, inputDataB: input data address.
input, row: 2d dim number of row,
input, col: 2d dim number of col,
operationType: such add, mul, sub
output, ret: the result of add.
============================================*/
void mask_cmath(double *outData, const double *inputData,
                const uint16_t *src_mask, int row, int col,
                double mask_value0) {
  uint16_t mask;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      mask = src_mask[tmp] & 0x0001;
      if (mask == 0x0000) {
        outData[tmp] = mask_value0;
      } else if (mask == 0x0001) {
        outData[tmp] = inputData[tmp];
      }
    }
  }
}
/*========================================
Function:this cmath generates testing data of mask ,float
Information:Author is ZC, 2025/07/27.
parameter:src_data,dataNum
input, inputDataA: input data address.
input, inputDataB: input data address.
input, row: 2d dim number of row,
input, col: 2d dim number of col,
operationType: such add, mul, sub
output, ret: the result of add.
============================================*/
void mask_cmath_float(float *outData, const float *inputData,
                      const uint16_t *src_mask, uint32_t row, uint32_t col,
                      float mask_value0) {
  uint16_t mask;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;
      mask = src_mask[tmp] & 0x0001;
      if (mask == 0x0000) {
        outData[tmp] = mask_value0;
      } else if (mask == 0x0001) {
        outData[tmp] = inputData[tmp];
      }
    }
  }
}

/*========================================
Function:this cmath generates testing data of elementwise ,such mul,add,sub
Information:Author is ZC, 2025/07/27.
parameter:src_data,dataNum
input, inputDataA: input data address.
input, inputDataB: input data address.
input, row: 2d dim number of row,
input, col: 2d dim number of col,
operationType: such add, mul, sub
output, ret: the result of add.
============================================*/
void elementwise_cmath(const double *inputDataA, const double *inputDataB,
                       double *outData, int row, int col, int model) {
#if 0
  printf("========elementwise cmath===========\n");
  printf("%s",operationType);
#endif
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      if (model == 0) { // add
        outData[tmp] = inputDataA[tmp] + inputDataB[tmp];
      } else if (model == 1) { // sub
        outData[tmp] = inputDataA[tmp] - inputDataB[tmp];
      } else if (model == 2) { // mul
        outData[tmp] = inputDataA[tmp] * inputDataB[tmp];
      }
    }
  }
}
/*========================================
Function:this cmath generates testing data of add2 128 and 32,inlucding but not
linited to this. Information:Author is ZC, 2025/07/11.
parameter:src_data,dataNum
input, src_data: input data address.
input, dataNum: the amount of input data. dataNum =[0,INF]
output, ret: the result of add.
============================================*/
float vae_cmath_add(const float *src_data, int dataNum) {
  float ret;
  ret = 0;
  if (src_data == NULL) {
    printf("Error!  The pointer is empty!");
    return ret;
  }

  for (int i = 0; i < dataNum; i++) {
    ret += src_data[i];
#if 0
          printf("%f,%f \n",src_data[i], ret);
#endif
  }
#if 0
      printf("%f\n",ret);
#endif
  return ret;
}
/*========================================
Function: rmsnorm  cmath , double
Information:Author is ZC, 2025/07/16. by qingyan
input:
  inputData, 2D matrix, [row][col]
  gamma,     2d matrix, [1][col]
  col,[1]
  row,[1]
  eps, [1]
output:
  outData:
============================================*/
void rmsnorm_cmath_double(double *outData, const double *inputData,
                          const double *gamma, int col, int row, double eps) {
  printf("=======cmath function==========\n");
  int tmp;
  for (int i = 0; i < row; i++) {
    double row_sum = 0;
    double r_mean = 0;
    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      row_sum += pow(inputData[tmp], 2);
    }
    r_mean = row_sum / col;
#if 0
    printf("row_sum = %f\n", row_sum);
    printf("r_mean = %f\n", r_mean);
    printf("eps = %f\n", eps);
#endif
    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      outData[tmp] = gamma[j] * inputData[tmp] / sqrt(r_mean + eps);
    }
  }
}
/*
void rmsnorm_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src, double
gamma, double eps)
{
  out.reset(src.nr, src.nc, src.type);
  for (int i = 0; i < src.nr; i++) {
    double row_sum = 0;
    double r_mean = 0;
    for (int j = 0; j < src.nc; j++) {
      row_sum += pow(src.data[i][j], 2);
    }
    r_mean = row_sum / src.nc;
    for (int j = 0; j < src.nc; j++) {
      out.data[i][j] = gamma * src.data[i][j] / sqrt(r_mean + eps);
    }
  }
}*/
/*
void layernorm_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src, double
gamma, double eps, double beta)
{
  out.reset(src.nr, src.nc, src.type);
  for (int i = 0; i < src.nr; i++) {
    double row_rst = 0;
    double row_sum = 0;
    double row_mean = 0;
    double row_ofs_sum = 0;
    double row_ofs_mean = 0;
    for (int j = 0; j < src.nc; j++) {
      row_sum += src.data[i][j];
    }
    row_mean = row_sum / src.nc;
    for (int j = 0; j < src.nc; j++) {
      row_ofs_sum += std::pow(src.data[i][j] - row_mean, 2);
    }
    row_ofs_mean = row_ofs_sum / src.nc;
    for (int j = 0; j < src.nc; j++) {
      row_rst = (src.data[i][j] - row_mean) / sqrt(row_ofs_mean + eps);
      out.data[i][j] = gamma * row_rst + beta;
    }
  }
}
*/
void layernorm_double_no_wel(double *outData, const double *inputData,
                             const double *gamma, double eps,
                             const double *bias, int col, int row,
                             int blockStep, int flagBiasGamma) {
  for (uint32_t i = 0; i < row; i++) {
    double row_rst = 0;
    double row_sum = 0;
    double row_mean = 0;
    double row_ofs_sum = 0;
    double row_ofs_mean = 0;
    for (uint32_t j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;
      row_sum += inputData[tmp];
    }
    row_mean = row_sum / col;
    for (int j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;
      row_ofs_sum += std::pow(inputData[tmp] - row_mean, 2);
    }
    row_ofs_mean = row_ofs_sum / col;
    for (int j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;
      row_rst = (inputData[tmp] - row_mean) / sqrt(row_ofs_mean + eps);
      if (flagBiasGamma == 1) {
        outData[tmp] = gamma[j] * row_rst + bias[j];
      } else {
        outData[tmp] = row_rst;
      }
    }
  }
}

/*========================================
Function: layernorm
Information:Author is ZC, 2025/07/24 ,by qingyan.
============================================*/

void layernorm_double_welford_cmath(double *outData, const double *inputData,
                                    const double *gamma, double eps,
                                    const double *bias, int col, int row,
                                    int blockStep, int flagBiasGamma) {
#if 0
  printf("===========laynorm cmath==========\n");
#endif
  for (int i = 0; i < row; i++) {
    // welford alg
    double mean = 0;
    double m2 = 0;
    int count = 0;
    int blockNum = 0;
    for (int j = 0; j < col; j += blockStep) {
      int block_end = min(j + blockStep, col);
      int block_cnt = block_end - j;
      double block_mean = 0, block_mean_tmp = 0;
      double block_m2 = 0;

      for (int n = j; n < block_end; n++) {
        int tmp;
        tmp = i * col + n;
        double data = inputData[tmp];
        block_mean_tmp += data;
      }
      block_mean = block_mean_tmp / (block_end - j); // miu

      for (int n = j; n < block_end; n++) {
        int tmp;
        tmp = i * col + n;
        double data = inputData[tmp];
        double delta = data - block_mean;
        block_m2 += delta * delta;
      }

      // merge block
      double delta_mean = block_mean - mean;
      mean += block_cnt * delta_mean / (count + block_cnt);
      m2 += block_m2 +
            delta_mean * delta_mean * count * block_cnt / (count + block_cnt);

#if 0
      printf("=======blockNum = %d ===start=====\n", blockNum);
      printf("block_end = %d \n", block_end);
      printf("j = %d \n", j);
      printf("count = %d \n", count);
      printf("block_cnt = %d \n", block_cnt);

      printf("block_mean_tmp = %f \n", block_mean_tmp);
      printf("block_mean = %f \n", block_mean);
      printf("block_m2 = %f \n", block_m2);
      printf("mean = %f \n", mean);
      printf("m2 = %f \n", m2);
      printf("=======blockNum = %d ===end=====\n", blockNum);
      blockNum++;

#endif
      count += block_cnt;
    }
    //
    double var = m2 / count;
    double stddev = sqrt(var + eps);

#if 0
    printf("var = %f \n", var);
    printf("stddev = %f \n", stddev);
#endif
    // norm
    for (int j = 0; j < col; j++) {
      int tmp;
      tmp = i * col + j;
      double row_rst = (inputData[tmp] - mean) / stddev;
      if (flagBiasGamma == 1) {
        outData[tmp] = gamma[j] * row_rst + bias[j];
      } else {
        outData[tmp] = row_rst;
      }
#if 0
    printf("row_rst = %f \n", row_rst);
    printf("outData[tmp] = %f \n", outData[tmp]);
    printf("bias[j]= %f \n", bias[j]);

#endif
    }
  }
}

/*
void layernorm_double_welford(MATRIX_2D<double> &out, MATRIX_2D<double> &src,
double gamma, double eps, double beta)
{
  out.reset(src.nr, src.nc, src.type);
  for (int i = 0; i < src.nr; i++) {
    // welford alg
    double mean = 0;
    double m2 = 0;
    int count = 0;
    int block_size = 64;
    for (int j = 0; j < src.nc; j += block_size) {
      int block_end = min(j + block_size, src.nc);
      int block_cnt = block_end - j;
      double block_mean = 0;
      double block_m2 = 0;
      for (int n = j; n < block_end; n++) {
        double x = src.data[i][n];
        double delta = x - block_mean;
        block_mean += delta / (n - j + 1);
        double delta2 = x - block_mean;
        block_m2 += delta * delta2;
      }
      // merge block
      double delta_mean = block_mean - mean;
      mean = (count * mean + block_cnt * block_mean) / (count + block_cnt);
      m2 += block_m2 + delta_mean * delta_mean * count * block_cnt / (count +
block_cnt); count += block_cnt;
    }
    //
    double var = m2 / count;
    double stddev = sqrt(var + eps);
    // norm
    for (int j = 0; j < src.nc; j++) {
      double row_rst = (src.data[i][j] - mean) / stddev;
      out.data[i][j] = gamma * row_rst + beta;
    }
  }
}
*/
/*
// GPT-NeoX style
void rope_rotation_matrix(MATRIX_2D<double> &out, int pos, int size, double
base)
{
  //[cos(n*theta) -sin(n*theta)]
  //[sin(n*theta) cos(n*theta)]
  out.reset(size, size, FP32);
  for (int i = 0; i < size / 2; i++) {
    double theta = std ::pow(base, -2 * i / size);
    out.data[i][i] = std::cos(theta * pos);
    out.data[i][i + size / 2] = -std::sin(theta * pos);
    out.data[i + size / 2][i] = std::sin(theta * pos);
    out.data[i + size / 2][i + size / 2] = std::cos(theta * pos);
  }
  // cout << "pos=" << pos << ", rope_matrix:" << endl;
  // print_mt_double(out);
}
*/
/*
void rope_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src, bool flag)
{
  if (flag) {
    out.reset(src.nr, src.nc, src.type);
    double *theta = new double[src.nc / 2];
    for (int i = 0; i < src.nc / 2; i++) {
      theta[i] = std ::pow(10000, -2.0 * i / src.nc);
    }
    // rope
    for (int i = 0; i < src.nr; i++) {
      for (int j = 0; j < src.nc / 2; j++) {
        double theta_n = i * theta[j];
        double cos_val = std::cos(theta_n);
        double sin_val = std::sin(theta_n);
        double src_d0 = src.data[i][2 * j]; // adjacent
        double src_d1 = src.data[i][2 * j + 1];
        out.data[i][2 * j] = src_d0 * cos_val - src_d1 * sin_val;
        out.data[i][2 * j + 1] = src_d0 * sin_val + src_d1 * cos_val;
      }
    }
    delete theta;
  } else {
    //(q0 p0cos q1 p0sin q2 p1cos q2 p1sin....)
    out.reset(src.nr, src.nc / 2, src.type);
    for (int i = 0; i < src.nr; i++) {
      for (int j = 0; j < src.nc; j += 4) {
        double src_d0 = src.data[i][j]; // adjacent
        double src_d1 = src.data[i][j + 2];
        double cos_val = src.data[i][j + 1];
        double sin_val = src.data[i][j + 3];
        out.data[i][j / 4] = src_d0 * cos_val - src_d1 * sin_val;
        out.data[i][j / 4 + 1] = src_d0 * sin_val + src_d1 * cos_val;
      }
    }
  }
}
*/
/*
void rope_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src1,
MATRIX_2D<double> &src2)
{
  assert(src1.nr == src2.nr && src1.nc == src2.nc);
  out.reset(src1.nr, src1.nc, src1.type);
  for (int i = 0; i < src1.nr; i++) {
    for (int j = 0; j < src1.nc / 2; j++) {
      double src_d0 = src1.data[i][2 * j]; // adjacent
      double src_d1 = src1.data[i][2 * j + 1];
      double cos_val = src2.data[i][2 * j + 1];
      double sin_val = src2.data[i][2 * j];
      out.data[i][2 * j] = src_d0 * cos_val - src_d1 * sin_val;
      out.data[i][2 * j + 1] = src_d0 * sin_val + src_d1 * cos_val;
    }
  }
}
*/
/*========================================
Function: out = exp(x - max(x))/sum(exp(x - max(x)))
Information:Author is ZC, 2025/07/11.
parameter:out,src
input, src: input data address. two-dimensional matrix.
output, out: output data address. two-dimensional matrix.
============================================*/
void softmax_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src) {
  out.reset(src.nr, src.nc, src.type);
  for (int i = 0; i < src.nr; i++) {
    double max_value = 0;
    double row_sum = 0;
    for (int j = 0; j < src.nc; j++) {
      max_value = std::max(max_value, src.data[i][j]); // max(x)
    }
    for (int j = 0; j < src.nc; j++) {
      out.data[i][j] = std::exp(src.data[i][j] - max_value); // exp(x - max(x))
      row_sum += out.data[i][j]; // sum(exp(x - max(x)))
    }
    for (int j = 0; j < src.nc; j++) {
      out.data[i][j] /= row_sum; // exp(x - max(x))/sum(exp(x - max(x)))
    }
  }
}
/*
void softmax_online_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src)
{
  out.reset(src.nr, src.nc, src.type);
  for (int i = 0; i < src.nr; i++) {
    double pre_max = 0;
    double new_max = 0;
    double row_sum = 0;
    for (int j = 0; j < src.nc; j++) {
      new_max = std::max(pre_max, src.data[i][j]);
      row_sum = row_sum * std::exp(pre_max - new_max) + std::exp(src.data[i][j]
- new_max); pre_max = new_max;
    }
    for (int j = 0; j < src.nc; j++) {
      out.data[i][j] = std::exp(src.data[i][j] - pre_max) / row_sum;
    }
  }
}*/

/*========================================
Function: softmax online cmath , double
Information:Author is ZC, 2025/07/16. by qingyan
============================================*/
void softmax_online_double(double *out, double *input, int col, int row,
                           double scale_softmax_cmath, int sacleFalg,
                           int maskFlag, const uint16_t *src_mask,
                           double mask_value0) {
  union ui64_f64_print dataa;
  double dataIn;
  int tmp;
  double *outDataMaskTmp = new double[col * row];
  double *outDataMask = new double[col * row];
  if (maskFlag == 1) {
    mask_cmath(outDataMaskTmp, input, src_mask, row, col, mask_value0);
  }
  for (int i = 0; i < row; i++) {
    // printf("outDataMask=============\n");

    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      outDataMask[tmp] = outDataMaskTmp[tmp];
#if 0
        dataa.dou64 = outDataMask[tmp];
        print_hex_64_union_ui64_dou64(dataa) ;
        dataa.dou64 = input[tmp];
        print_hex_64_union_ui64_dou64(dataa) ;
#endif
    }
  }
  for (int i = 0; i < row; i++) {
    double pre_max = HUGE_VAL * (-1);
    double new_max = pre_max;
    double row_sum = 0;
    // printf("row_sum=============\n");

    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (sacleFalg == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      if (dataIn >= pre_max) {
        new_max = dataIn;
      }
      double sub0, sub1;
      if ((pre_max == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = pre_max - new_max;
      }
      if ((dataIn == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub1 = HUGE_VAL * (-1);
      } else {
        sub1 = dataIn - new_max;
      }
      // row_sum = row_sum * exp(pre_max - new_max) + exp(dataIn - new_max);
      row_sum = row_sum * exp(sub0) + exp(sub1);
      pre_max = new_max;
#if 0
            dataa.dou64 = pre_max;
            print_hex_64_union_ui64_dou64(dataa) ;
            
            dataa.dou64 = dataIn;
            print_hex_64_union_ui64_dou64(dataa) ;
            dataa.dou64 = new_max;
            print_hex_64_union_ui64_dou64(dataa) ;
                                    dataa.dou64 = row_sum;
            print_hex_64_union_ui64_dou64(dataa) ;
            printf("==========\n");
#endif
    }

    // printf("out[tmp]=============\n");

    for (int k = 0; k < col; k++) {
      tmp = i * col + k;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (sacleFalg == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      double sub0;
      if ((dataIn == HUGE_VAL * (-1)) && (pre_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = dataIn - pre_max;
      }
      out[tmp] = exp(sub0) / (row_sum);
#if 0
            dataa.dou64 = out[tmp];
            print_hex_64_union_ui64_dou64(dataa) ;
#endif
    }
  }
  delete[] outDataMask;
  delete[] outDataMaskTmp;
}
/*========================================
Function: softmax online cmath , float
Information:Author is ZC, 2025/09/15. by qingyan
============================================*/
void softmax_online_float(float *out, float *input, uint32_t col, uint32_t row,
                          float scale_softmax_cmath, uint32_t sacleFalg,
                          uint32_t maskFlag, const uint16_t *src_mask,
                          float mask_value0) {
  union ui32_f32_print dataa;
  float dataIn;
  uint32_t tmp;
  float *outDataMaskTmp = new float[col * row];
  float *outDataMask = new float[col * row];
  if (maskFlag == 1) {
    mask_cmath_float(outDataMaskTmp, input, src_mask, row, col, mask_value0);
  }
  for (uint32_t i = 0; i < row; i++) {
    // pruint32_tf("outDataMask=============\n");

    for (uint32_t j = 0; j < col; j++) {
      tmp = i * col + j;
      outDataMask[tmp] = outDataMaskTmp[tmp];
#if 0
        dataa.dou64 = outDataMask[tmp];
        print_hex_32_union_ui32_f32(dataa) ;
        dataa.dou64 = input[tmp];
        print_hex_32_union_ui32_f32(dataa) ;
#endif
    }
  }
  for (uint32_t i = 0; i < row; i++) {
    float pre_max = HUGE_VAL * (-1);
    float new_max = pre_max;
    float row_sum = 0;
    // printf("row_sum=============\n");

    for (uint32_t j = 0; j < col; j++) {
      tmp = i * col + j;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (sacleFalg == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      if (dataIn >= pre_max) {
        new_max = dataIn;
      }
      float sub0, sub1;
      if ((pre_max == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = pre_max - new_max;
      }
      if ((dataIn == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub1 = HUGE_VAL * (-1);
      } else {
        sub1 = dataIn - new_max;
      }
      // row_sum = row_sum * exp(pre_max - new_max) + exp(dataIn - new_max);
      row_sum = row_sum * exp(sub0) + exp(sub1);
      pre_max = new_max;
#if 0
            dataa.dou64 = pre_max;
            print_hex_32_union_ui32_f32(dataa) ;
            
            dataa.dou64 = dataIn;
            print_hex_32_union_ui32_f32(dataa) ;
            dataa.dou64 = new_max;
            print_hex_32_union_ui32_f32(dataa) ;
                                    dataa.dou64 = row_sum;
            print_hex_32_union_ui32_f32(dataa) ;
            printf("==========\n");
#endif
    }

    // printf("out[tmp]=============\n");

    for (uint32_t k = 0; k < col; k++) {
      tmp = i * col + k;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (sacleFalg == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      float sub0;
      if ((dataIn == HUGE_VAL * (-1)) && (pre_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = dataIn - pre_max;
      }
      out[tmp] = exp(sub0) / (row_sum);
#if 0
            dataa.dou64 = out[tmp];
            print_hex_32_union_ui32_f32(dataa) ;
#endif
    }
  }
  delete[] outDataMask;
  delete[] outDataMaskTmp;
}
/*========================================
Function: softmax fa1 cmath , double
Information:Author is ZC, 2025/07/16. by qingyan
============================================*/
void softmax_fa1(double *out, double *input, int col, int row,
                 double scale_softmax_cmath, int scaleFlag, int maskFlag,
                 const uint16_t *src_mask, double mask_value0, int byPassFlag,
                 double *out_rope, double factor) {
  union ui64_f64_print dataa;
  double dataIn;
  int tmp;
  double *outDataMaskTmp = new double[col * row];
  double *outDataMask = new double[col * row];
  double *mean = new double[1];

  if (maskFlag == 1) {
    mask_cmath(outDataMaskTmp, input, src_mask, row, col, mask_value0);
  }
  for (int i = 0; i < row; i++) {
    // printf("outDataMask=============\n");

    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      outDataMask[tmp] = outDataMaskTmp[tmp];
#if 0
        dataa.dou64 = outDataMask[tmp];
        print_hex_64_union_ui64_dou64(dataa) ;
        dataa.dou64 = input[tmp];
        print_hex_64_union_ui64_dou64(dataa) ;
#endif
    }
  }
  for (int i = 0; i < row; i++) {
    double pre_max = HUGE_VAL * (-1);
    double new_max = pre_max;
    double row_sum = 0;
    // printf("row_sum=============\n");

    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (scaleFlag == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      if (dataIn >= pre_max) {
        new_max = dataIn;
      }
      double sub0, sub1;
      if ((pre_max == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = pre_max - new_max;
      }
      if ((dataIn == HUGE_VAL * (-1)) && (new_max == HUGE_VAL * (-1))) {
        sub1 = HUGE_VAL * (-1);
      } else {
        sub1 = dataIn - new_max;
      }
      // row_sum = row_sum * exp(pre_max - new_max) + exp(dataIn - new_max);
      row_sum = row_sum * exp(sub0) + exp(sub1);
      pre_max = new_max;
#if 0
            dataa.dou64 = pre_max;
            print_hex_64_union_ui64_dou64(dataa) ;
            
            dataa.dou64 = dataIn;
            print_hex_64_union_ui64_dou64(dataa) ;
            dataa.dou64 = new_max;
            print_hex_64_union_ui64_dou64(dataa) ;
                                    dataa.dou64 = row_sum;
            print_hex_64_union_ui64_dou64(dataa) ;
            printf("==========\n");
#endif
    }

    // printf("out[tmp]=============\n");

    for (int k = 0; k < col; k++) {
      tmp = i * col + k;
      if (maskFlag == 1) { // need mask
        input[tmp] = outDataMask[tmp];
      }
      if (scaleFlag == 1) {
        dataIn = input[tmp] * scale_softmax_cmath;
      } else {
        dataIn = input[tmp];
      }
      double sub0;
      if ((dataIn == HUGE_VAL * (-1)) && (pre_max == HUGE_VAL * (-1))) {
        sub0 = HUGE_VAL * (-1);
      } else {
        sub0 = dataIn - pre_max;
      }
      out[tmp] = exp(sub0);
#if 1
      dataa.dou64 = pre_max;
      print_hex_64_union_ui64_dou64(dataa);
#endif
    }
    int model;
    if (byPassFlag == 0) {
      ;
    } else if (byPassFlag == 1) {
      model = 1;
      quantization(out, out_rope, factor, model, row, col, mean);
    }
  }
  delete[] outDataMask;
  delete[] outDataMaskTmp;
  delete[] mean;
}
/*========================================
Function: softmax fa2 cmath
Information:Author is ZC, 2025/8/24. by qingyan
============================================*/
void softmax_fa2_cmath(double *inputExp, double *OSRAM, double *inputAdd,
                       double *outData, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      outData[tmp] = inputExp[i] * OSRAM[tmp] + inputAdd[tmp];
    }
  }
}
/*========================================
Function: softmax fa3 cmath
Information:Author is ZC, 2025/8/24. by qingyan
============================================*/
void softmax_fa3_cmath(double *inputReduce, double *inputOSRAM, double *outData,
                       int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      outData[tmp] = inputOSRAM[tmp] / inputReduce[i];
    }
  }
}
/*========================================
Function: print matrix
Information:Author is ZC, 2025/07/15. by qingyan
============================================*/
void print_mt_double(MATRIX_2D<double> &mt) {
  for (int i = 0; i < mt.nr; i++) {
    for (int j = 0; j < mt.nc; j++) {
      cout << setw(10) << mt.data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/*========================================
Function: read data from a string ，and  convert to uint16
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
std::vector<uint16_t> extractHexNumbers(const std::string &input) {
  std::vector<uint16_t> result;
  size_t start = 0;
  int flag = 1;
  while (true) {
    // judge index is valid.
    if (start >= 0 && start < input.size()) {
      ;
    } else {
      break;
    }
    // 查找下一个逗号或字符串结束
    size_t commaPos = input.find(',', start);
    // cout << "0x" << std::hex << commaPos << "\n"; //for debug

    if (commaPos == std::string::npos) {
      commaPos = input.length();
    }
    flag = 0; // for debug

    // 提取子字符串
    std::string hexStr = input.substr(start, commaPos - start);
    // cout << std::hex << hexStr << "\n"; //for debug

    // 移除前导0x
    if (hexStr.substr(0, 2) == "0x") {
      hexStr = hexStr.substr(2);
    }
    // cout  << std::hex << hexStr << "\n"; //for debug

    // 转换为uint16
    uint16_t num = static_cast<uint16_t>(std::stoul(hexStr, nullptr, 16));
    result.push_back(num);
    // cout  << num << "\n"; //for debug

    // 更新起始位置
    start = commaPos + 1;

    // 检查是否结束
    if (commaPos == std::string::npos) {
      break;
    }
  }
  // for debug
  /*for (const auto& elem :result){
    cout << elem << " ";
  }*/
  return result;
}

/*========================================
Function: read data from a txt file,
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
std::vector<uint16_t> readDataFromTxt(std::string filename) {
  std::ifstream file(filename);
  std::string line;
  std::vector<uint16_t> result;
  int num = 0;

  if (!file.is_open()) {
    std::cout << filename << "file open error" << std::endl;
  } else {
    std::cout << filename << ","
              << "good, file open correctly!" << std::endl;
  }

  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#')
      continue;
#if 0
        std::cout << line << "\n"; //for debug
#endif
    num++;
    // string to uint16_t
    std::vector<uint16_t> numberUint16 = extractHexNumbers(line);
    for (const auto &elem : numberUint16) {
      result.push_back(elem);
    }
  }

#if 0
    printVectorUint16(result,"0x");
#endif
#if 0
    std::cout <<"=======" << line << "======";
#endif

  file.close();
  return result;
}

/*========================================
Function: print c data ,uint24
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printUint24(const uint24_t *data, int num) {
  for (int i = 0; i < num; i++) {
    printf("0x%X, ", data[i]);
  }
  printf("end \n");
}

/*=========================================
FUNCTION:rand int data
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
int random_range_int(int min, int max) {
  return min + rand() % (max - min + 1);
}
/*=========================================
FUNCTION:printf 32 bit data. type is uint64 end double union
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_32_union_ui32_f32(const union ui32_f32_print num) {
  printf("data_f32_hex:");
  for (int i = 7; i >= 0; i--) {
    printf("%x", (num.ui32 >> (i * 4)) & 0x0F);
    if (i % 4 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}

/*=========================================
FUNCTION:printf 16 bit data.
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_16_input_float16_t_value(const float16_t datatIn,
                                        const char *str) {
  printf("value: %s , ", str);
  union ui16_f16_print num;
  num.ui16 = datatIn.v;
  printf("data_f16_hex:");
  for (int i = 3; i >= 0; i--) {
    printf("%x", (num.ui16 >> (i * 4)) & 0x0F);
    if (i % 2 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*=========================================
FUNCTION:printf 16 bit data.
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_32_input_float32_t_value(const float32_t datatIn,
                                        const char *str) {
  printf("value: %s , ", str);
  union ui32_f32_print num;
  num.ui32 = datatIn.v;
  printf("data_f32_hex:");
  for (int i = 7; i >= 0; i--) {
    printf("%x", (num.ui32 >> (i * 4)) & 0x0F);
    if (i % 2 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*========================================
Function: 打印 64 位无符号整数的二进制表示
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printBinaryUint64(const uint64_t num) {
  printf("binary: ");
  for (int i = 63; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf("\n");
}

/*========================================
Function: 打印 64 位无符号整数的二进制表示
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printHexUint64(const uint64_t num) {
  printf("data_f64_hex:");
  for (int i = 15; i >= 0; i--) {
    printf("%x", (num >> (i * 4)) & 0x0F);
    if (i % 4 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*========================================
Function: 打印 64 位无符号整数的二进制表示
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void print_hex_64(const uint64_t num) {
  for (int i = 15; i >= 0; i--) {
    printf("%x", (num >> (i * 4)) & 0x0F);
    if (i % 4 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*========================================
Function: print c data ,uint64, bit
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printMatrixDataUint64(const double *data, int col, int row) {
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      int tmp = i * row + j;
      printBinaryUint64(data[tmp]);
    }
  }
}

/*========================================
Function: print c data ,uint64, bit
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printMatrixDataUint64OneData(const uint64_t data) {
  printBinaryUint64(data);
}

/*========================================
Function: generate random number.
Information:Author is ZC, 2025/07/14. by qingyan

output is two-dimensional matrix.if need one-dimensional matrix ,row ==1.
============================================*/
std::vector<float> oneDimMatrixRand(int col, int row, int low, int high) {
  std::vector<float> result;
  float data = 0;
  int range = high - low + 1;
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      data = low + rand() % range;

      result.push_back(data);
    }
  }
  return result;
}

/*========================================
Function: print data . support 0x, 0d
Information:Author is ZC, 2025/07/14. by qingyan

============================================*/
void printVectorUint16(std::vector<uint16_t> data, std::string format) {
  if (format == "0x") {
    for (const auto &elem : data) {
      std::cout << std::hex << elem << " ";
    }
  } else if (format == "0d") {
    for (const auto &elem : data) {
      std::cout << std::dec << elem << " ";
    }
  }
  std::cout << "end \n";
}

/*========================================
Function: print data . support 0x, 0d
Information:Author is ZC, 2025/07/14. by qingyan

============================================*/
void printVectoFloat(std::vector<float> data, std::string format) {
  if (format == "0x") {
    for (const auto &elem : data) {
      std::cout << std::hex << elem << " ";
    }
  } else if (format == "0d") {
    for (const auto &elem : data) {
      std::cout << std::dec << elem << " ";
    }
  }
  std::cout << "end \n";
}
/*========================================
Function: vector of c++ data  copy to c data
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void copyDataUint16(std::vector<float> inputData, uint16_t *outData) {
  for (size_t i = 0; i < inputData.size(); ++i) {
    outData[i] = inputData[i];
  }
}
/*========================================
Function: vector of c++ data  copy to c data
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void copyDataFloat(std::vector<float> inputData, float *outData) {
  for (size_t i = 0; i < inputData.size(); ++i) {
    outData[i] = inputData[i];
  }
}

/*========================================
Function: print c data, float
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printFloat(const float *data, int num) {
  for (int i = 0; i < num; i++) {
    printf("%f ", data[i]);
  }
  printf("end \n");
}

/*========================================
Function: print c data ,uint16
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printUint16(const uint16_t *data, int num) {
  for (int i = 0; i < num; i++) {
    printf("%0*x ", 4, data[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
  printf("end \n");
}

/*=========================================
FUNCTION:printf 64 bit data. type is uint64 end double union
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_64_union_ui64_dou64(const union ui64_f64_print num) {
  printf("data_f64_hex:");
  for (int i = 15; i >= 0; i--) {
    printf("%x", (num.ui64 >> (i * 4)) & 0x0F);
    if (i % 4 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}

/*=========================================
FUNCTION:printf 16 bit data. type is uint64 end double union
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_16_union_ui16_f16(const union ui16_f16_print num) {
  printf("data_f16_hex:");
  for (int i = 3; i >= 0; i--) {
    printf("%x", (num.ui16 >> (i * 4)) & 0x0F);
    if (i % 2 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*=========================================
FUNCTION:printf 8 bit data.
AUTHOR:qingyan
DATA:2025-07-28
==========================================*/
void print_bit_i8(const char num) {
  printf("data_f8_hex:");
  for (int i = 7; i >= 0; i--) {
    printf("%d", num >> i & 1);
    if (i % 4 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}
/*=========================================
FUNCTION:printf 16 bit data.
AUTHOR:qingyan
DATA:2025-07-17
==========================================*/
void print_hex_16_union_ui16_f16_input_float16_t(const float16_t datatIn) {
  union ui16_f16_print num;
  num.ui16 = datatIn.v;
  printf("data_f16_hex:");
  for (int i = 3; i >= 0; i--) {
    printf("%x", (num.ui16 >> (i * 4)) & 0x0F);
    if (i % 2 == 0 && i != 0)
      printf("-");
  }
  printf("\n");
}

#endif

/*========================================
Function: print data for DV and DE.
author: made by scott.
data: 2025/8/6
============================================*/
#if TEST_FOR_DE_DV
/*========================================
test vae function
input:
functionNumber:
    0 is rmsnorm test;
    1 is softmax_online;
    2 is laynorm;
    3 is elementwise;
    4 is mask;
    5 is quantization: per token Q quantization with model 0, per group Q
quantization with model 1, and per tensor K quantization with model 2; 6 is
rope; 7 is reduce.
============================================*/
void fun_test1_vae(int row, int col, DataType i_type, DataType o_type,
                   int functionNumber) {

  float24_t paddingValue;
  paddingValue.v = 0xfc00;
  uint16_t *src_data = (uint16_t *)malloc(row * col * sizeof(uint16_t));
  uint16_t *res_data = (uint16_t *)malloc(row * col * sizeof(uint16_t));
  FILE *file = fopen("src_data.txt", "r");
  char buffer[1024];
  int i = 0;
  float16_t scale;
  scale.v = 0x3c00;
  while (fgets(buffer, sizeof(buffer), file)) {
    char *line = buffer;
    src_data[i] = (uint16_t)strtol(line, NULL, 16);
    printf("the src_data = %x   \n", src_data[i++]);
  }
  if (functionNumber == 1) {
    // res_data = operators::vae_softmax_online(src_data, row, col, i_type,
    // o_type,  128, paddingValue , 0, scale);
    for (int i = 0; i < row * col; i++) {
      printf("the res_data = %x   \n", res_data[i]);
    }
  }
}
/*========================================
function: printf node data for DV ,8bit
============================================*/
void printfNodeData8bit(const uint8_t data, char *nodeName, char *opName) {
  char str1[] = "cm_";
  char str2[100];
  strcpy(str2, opName);
  char link[] = "_";
  char str3[100];
  strcpy(str3, nodeName);
  char str4[] = ".txt";
  char fileName[100];
  sprintf(fileName, "%s%s%s%s%s", str1, str2, link, str3, str4);
  FILE *file = fopen(fileName, "a");
  if (file == NULL) {
    printf("file  %s open error\n", fileName);
  }
  if (ftell(file) > 0) {
    // fprintf(file, "\n");
  }
  int width = 2;
  fprintf(file, "%0*x\n", width, data);
  fclose(file);
}
/*========================================
function: printf node data for DV ,16bit
============================================*/
void printfNodeData16bit(const uint16_t data, char *nodeName, char *opName) {
  char str1[] = "cm_";
  char str2[100];
  strcpy(str2, opName);
  char link[] = "_";
  char str3[100];
  strcpy(str3, nodeName);
  char str4[] = ".txt";
  char fileName[100];
  sprintf(fileName, "%s%s%s%s%s", str1, str2, link, str3, str4);
  FILE *file = fopen(fileName, "a");
  if (file == NULL) {
    printf("file  %s open error\n", fileName);
  }
  if (ftell(file) > 0) {
    // fprintf(file, "\n");
  }
  int width = 4;
  fprintf(file, "%0*x\n", width, data);
  fclose(file);
}
/*========================================
function: printf node data for DV ,16bit
============================================*/
FILE *printfOpenFile(char *nodeName, char *opName) {
  char str1[] = "cm_";
  char str2[100];
  strcpy(str2, opName);
  char link[] = "_";
  char str3[100];
  strcpy(str3, nodeName);
  char str4[] = ".txt";
  char fileName[100];
  sprintf(fileName, "%s%s%s%s%s", str1, str2, link, str3, str4);
  FILE *file;
  file = fopen(fileName, "a");
  if (file == NULL) {
    printf("file  %s open error\n", fileName);
  }
  return file;
}
/*========================================
function: printf node data for DV ,16bit
============================================*/
void printfcloseFile(FILE *file) { fclose(file); }
/*========================================
function: printf node data for DV ,8bit
============================================*/
void printfData8bit(const uint8_t data, FILE *file) {
  int width = 2;
  fprintf(file, "%0*x\n", width, data);
}
/*========================================
function: printf node data for DV ,16bit
============================================*/
void printfData16bit(const uint16_t data, FILE *file) {
  int width = 4;
  fprintf(file, "%0*x\n", width, data);
}
/*========================================
function: printf node data for DV ,32bit
============================================*/
void printfData32bit(const uint32_t data, FILE *file) {
  int width = 8;
  fprintf(file, "%0*x\n", width, data);
}
/*========================================
function: printf node data for DV ,24bit
============================================*/
void printfData24bit(const uint32_t data, FILE *file) {
  int width = 6;
  fprintf(file, "%0*x\n", width, data);
}
/*========================================
function: printf node data for DV ,24bit
============================================*/
void printfNodeData24bit(const uint24_t data, char *nodeName, char *opName) {
  char str1[] = "cm_";
  char str2[100];
  strcpy(str2, opName);
  char link[] = "_";
  char str3[100];
  strcpy(str3, nodeName);
  char str4[] = ".txt";
  char fileName[100];
  sprintf(fileName, "%s%s%s%s%s", str1, str2, link, str3, str4);
  FILE *file = fopen(fileName, "a");
  if (file == NULL) {
    printf("file  %s open error\n", fileName);
  }
  if (ftell(file) > 0) {
    // fprintf(file, "\n");
  }
  int width = 3;
  fprintf(file, "%0*x\n", width, data);
  fclose(file);
}
/*========================================
function: printf node data for DV, 32bit
============================================*/
void printfNodeData32bit(const uint32_t data, char *nodeName, char *opName) {
  char str1[] = "cm_";
  char str2[100];
  strcpy(str2, opName);
  char link[] = "_";
  char str3[100];
  strcpy(str3, nodeName);
  char str4[] = ".txt";
  char fileName[100];
  sprintf(fileName, "%s%s%s%s%s", str1, str2, link, str3, str4);
  FILE *file = fopen(fileName, "a");
  if (file == NULL) {
    printf("file  %s open error\n", fileName);
  }
  if (ftell(file) > 0) {
    // fprintf(file, "\n");
  }
  int width = 8;
  fprintf(file, "%0*x\n", width, data);
  fclose(file);
}
/*========================================
function: delete txt file
============================================*/
int deleteTxtFile() {
  DIR *dir;
  struct dirent *entry;
  char path[1024];
  dir = opendir("../cmodel");
  if (dir == NULL) {
    perror("catalog not found");
    return 1;
  }
  while ((entry = readdir(dir)) != NULL) {
    if (strstr(entry->d_name, ".txt") != NULL) {
      snprintf(path, sizeof(path), "%s", entry->d_name);
      if (unlink(path) == 0) {
        printf("haved delete file: %s\n", path);
      } else {
        perror("delete failed!\n");
      }
    }
  }
  closedir(dir);
  return 0;
}
#endif
} // namespace operators