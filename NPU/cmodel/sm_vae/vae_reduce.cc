#include "dop_ops.h"
#include "sfu_exp.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {
uint32_t kroundData[] = {
    0x3f800000, 0x3f000000, 0x3eaaaaab, 0x3e800000, 0x3e4ccccd, 0x3e2aaaab,
    0x3e124925, 0x3e000000, 0x3de38e39, 0x3dcccccd, 0x3dba2e8c, 0x3daaaaab,
    0x3d9d89d9, 0x3d924925, 0x3d888889, 0x3d800000, 0x3d70f0f1, 0x3d638e39,
    0x3d579436, 0x3d4ccccd, 0x3d430c31, 0x3d3a2e8c, 0x3d321643, 0x3d2aaaab,
    0x3d23d70a, 0x3d1d89d9, 0x3d17b426, 0x3d124925, 0x3d0d3dcb, 0x3d088889,
    0x3d042108, 0x3d000000, 0x3cf83e10, 0x3cf0f0f1, 0x3cea0ea1, 0x3ce38e39,
    0x3cdd67c9, 0x3cd79436, 0x3cd20d21, 0x3ccccccd, 0x3cc7ce0c, 0x3cc30c31,
    0x3cbe82fa, 0x3cba2e8c, 0x3cb60b61, 0x3cb21643, 0x3cae4c41, 0x3caaaaab,
    0x3ca72f05, 0x3ca3d70a, 0x3ca0a0a1, 0x3c9d89d9, 0x3c9a90e8, 0x3c97b426,
    0x3c94f209, 0x3c924925, 0x3c8fb824, 0x3c8d3dcb, 0x3c8ad8f3, 0x3c888889,
    0x3c864b8a, 0x3c842108, 0x3c820821, 0x3c800000, 0x3c7c0fc1, 0x3c783e10,
    0x3c74898d, 0x3c70f0f1, 0x3c6d7304, 0x3c6a0ea1, 0x3c66c2b4, 0x3c638e39,
    0x3c607038, 0x3c5d67c9, 0x3c5a740e, 0x3c579436, 0x3c54c77b, 0x3c520d21,
    0x3c4f6475, 0x3c4ccccd, 0x3c4a4588, 0x3c47ce0c, 0x3c4565c8, 0x3c430c31,
    0x3c40c0c1, 0x3c3e82fa, 0x3c3c5264, 0x3c3a2e8c, 0x3c381703, 0x3c360b61,
    0x3c340b41, 0x3c321643, 0x3c302c0b, 0x3c2e4c41, 0x3c2c7692, 0x3c2aaaab,
    0x3c28e83f, 0x3c272f05, 0x3c257eb5, 0x3c23d70a, 0x3c2237c3, 0x3c20a0a1,
    0x3c1f1166, 0x3c1d89d9, 0x3c1c09c1, 0x3c1a90e8, 0x3c191f1a, 0x3c17b426,
    0x3c164fda, 0x3c14f209, 0x3c139a86, 0x3c124925, 0x3c10fdbc, 0x3c0fb824,
    0x3c0e7835, 0x3c0d3dcb, 0x3c0c08c1, 0x3c0ad8f3, 0x3c09ae41, 0x3c088889,
    0x3c0767ab, 0x3c064b8a, 0x3c053408, 0x3c042108, 0x3c03126f, 0x3c020821,
    0x3c010204, 0x3c000000, 0x3bfe03f8, 0x3bfc0fc1, 0x3bfa232d, 0x3bf83e10,
    0x3bf6603e, 0x3bf4898d, 0x3bf2b9d6, 0x3bf0f0f1, 0x3bef2eb7, 0x3bed7304,
    0x3bebbdb3, 0x3bea0ea1, 0x3be865ac, 0x3be6c2b4, 0x3be52598, 0x3be38e39,
    0x3be1fc78, 0x3be07038, 0x3bdee95c, 0x3bdd67c9, 0x3bdbeb62, 0x3bda740e,
    0x3bd901b2, 0x3bd79436, 0x3bd62b81, 0x3bd4c77b, 0x3bd3680d, 0x3bd20d21,
    0x3bd0b6a0, 0x3bcf6475, 0x3bce168a, 0x3bcccccd, 0x3bcb8728, 0x3bca4588,
    0x3bc907da, 0x3bc7ce0c, 0x3bc6980c, 0x3bc565c8, 0x3bc43730, 0x3bc30c31,
    0x3bc1e4bc, 0x3bc0c0c1, 0x3bbfa030, 0x3bbe82fa, 0x3bbd6910, 0x3bbc5264,
    0x3bbb3ee7, 0x3bba2e8c, 0x3bb92144, 0x3bb81703, 0x3bb70fbb, 0x3bb60b61,
    0x3bb509e7, 0x3bb40b41, 0x3bb30f63, 0x3bb21643, 0x3bb11fd4, 0x3bb02c0b,
    0x3baf3ade, 0x3bae4c41, 0x3bad602b, 0x3bac7692, 0x3bab8f6a, 0x3baaaaab,
    0x3ba9c84a, 0x3ba8e83f, 0x3ba80a81, 0x3ba72f05, 0x3ba655c4, 0x3ba57eb5,
    0x3ba4a9cf, 0x3ba3d70a, 0x3ba3065e, 0x3ba237c3, 0x3ba16b31, 0x3ba0a0a1,
    0x3b9fd80a, 0x3b9f1166, 0x3b9e4cad, 0x3b9d89d9, 0x3b9cc8e1, 0x3b9c09c1,
    0x3b9b4c70, 0x3b9a90e8, 0x3b99d723, 0x3b991f1a, 0x3b9868c8, 0x3b97b426,
    0x3b97012e, 0x3b964fda, 0x3b95a025, 0x3b94f209, 0x3b944581, 0x3b939a86,
    0x3b92f114, 0x3b924925, 0x3b91a2b4, 0x3b90fdbc, 0x3b905a38, 0x3b8fb824,
    0x3b8f177a, 0x3b8e7835, 0x3b8dda52, 0x3b8d3dcb, 0x3b8ca29c, 0x3b8c08c1,
    0x3b8b7034, 0x3b8ad8f3, 0x3b8a42f8, 0x3b89ae41, 0x3b891ac7, 0x3b888889,
    0x3b87f781, 0x3b8767ab, 0x3b86d905, 0x3b864b8a, 0x3b85bf37, 0x3b853408,
    0x3b84a9fa, 0x3b842108, 0x3b839930, 0x3b83126f, 0x3b828cc0, 0x3b820821,
    0x3b81848e, 0x3b810204, 0x3b808081, 0x3b800000};
/*========================================
Function: reduce max .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  block_step：
output:
  ret, dim [row][1]
============================================*/
void reduce_max(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_max";
  uint16_t data2txt_uint16;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_new_max_blk");
  FILE *file_p0_new_max_blk;
  file_p0_new_max_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_new_max_blk");
  FILE *file_p1_new_max_blk;
  file_p1_new_max_blk = printfOpenFile(nodeName, opName);
#endif
  for (int i = 0; i < src_row; i++) {
    float16_t pre_max_blk, new_max_blk; // also bfloat_16
    if (i_type == FP16) {
      pre_max_blk.v = 0xfc00, new_max_blk.v = 0xfc00; //-inf
    } else {
      pre_max_blk.v = 0xff80, new_max_blk.v = 0xff80; //-inf
    }
    for (int j = 0; j < src_col; j += block_step) {
      int block_end, block_end_j;
      block_end_j = j + block_step;
      if (block_end_j < src_col) {
        block_end = block_end_j;
      } else {
        block_end = src_col;
      }
      int absFlag = 0;
      new_max_blk.v =
          maxValue(src_data + j + i * src_col, block_end - j, i_type, absFlag);
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_max_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p0_new_max_blk);
#endif
      if (new_max_blk.v != pre_max_blk.v) {
        if (i_type == FP16) {
          new_max_blk.v = fp16max(new_max_blk.v, pre_max_blk.v);
        } else if (i_type == BF16) {
          new_max_blk.v = bf16max(new_max_blk.v, pre_max_blk.v);
        }
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_max_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p1_new_max_blk);
#endif
      pre_max_blk.v = new_max_blk.v;
    }
    ret[i] = new_max_blk.v;
  }
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_new_max_blk);
  printfcloseFile(file_p1_new_max_blk);
#endif
}

/*========================================
Function: reduce min .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  block_step:
output:
  ret, dim [row][1]
============================================*/
void reduce_min(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_min";
  uint16_t data2txt_uint16;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_new_min_blk");
  FILE *file_p0_new_min_blk;
  file_p0_new_min_blk = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_new_min_blk");
  FILE *file_p1_new_min_blk;
  file_p1_new_min_blk = printfOpenFile(nodeName, opName);
#endif
  for (int i = 0; i < src_row; i++) {
    float16_t pre_min_blk, new_min_blk; // also bfloat_16
    if (i_type == FP16) {
      pre_min_blk.v = 0x7c00, new_min_blk.v = 0x7c00; // inf
    } else {
      pre_min_blk.v = 0x7f80, new_min_blk.v = 0x7f80; // inf
    }
    for (int j = 0; j < src_col; j += block_step) {
      int block_end, block_end_j;
      block_end_j = j + block_step;
      if (block_end_j < src_col) {
        block_end = block_end_j;
      } else {
        block_end = src_col;
      }
      int absFlag = 0;
      new_min_blk.v =
          minValue(src_data + j + i * src_col, block_end - j, i_type, absFlag);
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_min_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p0_new_min_blk);
#endif
      if (new_min_blk.v != pre_min_blk.v) {
        if (i_type == FP16) {
          new_min_blk.v = fp16min(new_min_blk.v, pre_min_blk.v);
        } else if (i_type == BF16) {
          new_min_blk.v = bf16min(new_min_blk.v, pre_min_blk.v);
        }
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_min_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p1_new_min_blk);
#endif
      pre_min_blk.v = new_min_blk.v;
    }
    ret[i] = new_min_blk.v;
  }
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_new_min_blk);
  printfcloseFile(file_p1_new_min_blk);
#endif
}

/*========================================
Function: reduce of argmax. find a max value of index from a row.
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  block_step:
output:
  ret, dim [row][1]
============================================*/
void reduce_argmax(uint32_t *ret, const uint16_t *src_data, int src_row,
                   int src_col, DataType i_type, DataType o_type,
                   int block_step) {
#if 0 // TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_argmax";
  uint16_t data2txt_uint16;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p1_ret");
  FILE *file_p1_ret;
  file_p1_ret = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_new_max_blk");
  FILE *file_p2_new_max_blk;
  file_p2_new_max_blk = printfOpenFile(nodeName, opName);
#endif
  uint32_t *index_maxValue_argmax = new uint32_t[1];
  for (uint32_t i = 0; i < src_row; i++) {
    float16_t pre_max_blk, new_max_blk; // also bfloat_16
    if (i_type == FP16) {
      pre_max_blk.v = 0xfc00, new_max_blk.v = 0xfc00; //-inf
    } else {
      pre_max_blk.v = 0xff80, new_max_blk.v = 0xff80; //-inf
    }
    ret[i] = 0;
    int firstFlag = 0;
    for (uint32_t j = 0; j < src_col; j += block_step) {
      int block_end, block_end_j;
      block_end_j = j + block_step;

      if (block_end_j < src_col) {
        block_end = block_end_j;
      } else {
        block_end = src_col;
      }
      int absFlag = 0;
      new_max_blk.v =
          maxValue_argmax(src_data + j + i * src_col, index_maxValue_argmax,
                          block_end - j, i_type, absFlag);
      if (firstFlag == 0) {
        ret[i] = index_maxValue_argmax[0] + j;
        firstFlag = 1;
        if (i_type == FP16) {
          pre_max_blk.v = fp16max(new_max_blk.v, pre_max_blk.v);
        } else if (i_type == BF16) {
          pre_max_blk.v = bf16max(new_max_blk.v, pre_max_blk.v);
        }
      } else {
        if (new_max_blk.v != pre_max_blk.v) {
          if (i_type == FP16) {
            pre_max_blk.v = fp16max(new_max_blk.v, pre_max_blk.v);
          } else if (i_type == BF16) {
            pre_max_blk.v = bf16max(new_max_blk.v, pre_max_blk.v);
          }
          if (new_max_blk.v == pre_max_blk.v) {
            ret[i] = index_maxValue_argmax[0] + j;
          }
        }
      }

#if TEST_FOR_DE_DV
      data2txt_uint32 = ret[i];
      operators::printfData32bit(data2txt_uint32, file_p1_ret);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = new_max_blk.v;
      operators::printfData16bit(data2txt_uint16, file_p2_new_max_blk);
#endif
    }
  }
  delete[] index_maxValue_argmax;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p1_ret);
  printfcloseFile(file_p2_new_max_blk);
#endif
}

/*========================================
Function: reduce of add.  sum .128 sum to 1 data.
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep:
  paddingValue:
output:
  ret, dim [row][1]
============================================*/
void reduce_add(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int blockStep,
                float24_t paddingValue) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_add";
  uint24_t data2txt_uint24;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_0_sumTmp0");
  FILE *file_p0_0_sumTmp0;
  file_p0_0_sumTmp0 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p0_1_sumTmp1");
  FILE *file_p0_1_sumTmp1;
  file_p0_1_sumTmp1 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p0_sumTmp");
  FILE *file_p0_sumTmp;
  file_p0_sumTmp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_sum");
  FILE *file_p1_sum;
  file_p1_sum = printfOpenFile(nodeName, opName);
#endif
  int all_col = src_col + (blockStep - src_col % blockStep) %
                              blockStep; // align according to blockStep
  float24_t *data24 = new float24_t[all_col * src_row];
  float16_t data16;
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < all_col; i++) // f16 to f24
    {
      int indexPad = j * all_col + i;
      int tmp = j * src_col + i;
      if (i >= src_col) {
        data24[indexPad].v = paddingValue.v; // paddingValue
        continue;
      }
      data16.v = src_data[tmp];
      if (i_type == FP16) {
        data24[indexPad].v = fp16_to_fp24(data16.v);
      } else if (i_type == BF16) {
        data24[indexPad].v = bf16_to_fp24(data16.v);
      }
    }
  }
  float24_t sumTmp;
  float32_t sumTmp32, sum, sumTmp0, sumTmp1;
  int paddingNumFlag = 0, paddingNum = 0, sumFlag = 0;
  if (src_row == 1) {
    for (int j = 0; j < src_row; j++) {
      sumTmp.v = 0;
      sum.v = 0;
      sumTmp0.v = 0;
      sumTmp1.v = 0;
      sumFlag = 0;
      for (int i = 0; i < all_col; i += blockStep) // f16 to f24
      {
        int tmp = j * all_col + i;
        sumTmp = add2(data24 + tmp, blockStep, paddingValue);
#if TEST_FOR_DE_DV
        data2txt_uint24 = sumTmp.v;
        operators::printfData24bit(data2txt_uint24, file_p0_sumTmp);
#endif
        sumTmp32.v = fp24_to_fp32(sumTmp.v);
        if (sumFlag == 0) {
          sumTmp0.v = fp32add(sumTmp0.v, sumTmp32.v);
          sumFlag = 1;
#if TEST_FOR_DE_DV
          data2txt_uint32 = sumTmp0.v;
          operators::printfData32bit(data2txt_uint32, file_p0_0_sumTmp0);
#endif
        } else {
          sumTmp1.v = fp32add(sumTmp1.v, sumTmp32.v);
          sumFlag = 0;
#if TEST_FOR_DE_DV
          data2txt_uint32 = sumTmp1.v;
          operators::printfData32bit(data2txt_uint32, file_p0_1_sumTmp1);
#endif
        }
      }
      sum.v = fp32add(sumTmp0.v, sumTmp1.v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = sum.v;
      operators::printfData32bit(data2txt_uint32, file_p1_sum);
#endif
      if (i_type == FP16) {
        ret[j] = fp32_to_fp16(sum.v);
      } else if (i_type == BF16) {
        ret[j] = fp32_to_bf16(sum.v);
      }
    }
  } else {
    for (int j = 0; j < src_row; j++) {
      sumTmp.v = 0;
      sum.v = 0;
      for (int i = 0; i < all_col; i += blockStep) // f16 to f24
      {
        int tmp = j * all_col + i;
        sumTmp = add2(data24 + tmp, blockStep, paddingValue);
        sumTmp32.v = fp24_to_fp32(sumTmp.v);
        sum.v = fp32add(sum.v, sumTmp32.v);
#if TEST_FOR_DE_DV
        data2txt_uint24 = sumTmp.v;
        operators::printfData24bit(data2txt_uint24, file_p0_sumTmp);
#endif
#if TEST_FOR_DE_DV
        data2txt_uint32 = sum.v;
        operators::printfData32bit(data2txt_uint32, file_p1_sum);
#endif
      }
      if (i_type == FP16) {
        ret[j] = fp32_to_fp16(sum.v);
      } else if (i_type == BF16) {
        ret[j] = fp32_to_bf16(sum.v);
      }
    }
  }
  delete[] data24;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_0_sumTmp0);
  printfcloseFile(file_p0_1_sumTmp1);
  printfcloseFile(file_p0_sumTmp);
  printfcloseFile(file_p1_sum);
#endif
}

/*========================================
Function: reduce of mean(avg).  sum .128 sum to 1 data. then divid col
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep:
  paddingValue:
  factor:  = 1 / src_col.
output:
  ret, dim [row][1]
============================================*/
void reduce_avg_mean(uint16_t *ret, const uint16_t *src_data, int src_row,
                     int src_col, DataType i_type, DataType o_type,
                     int blockStep, float24_t paddingValue, uint32_t dimk_rec,
                     uint32_t dimk_mod128_rec_dimk, float24_t dimk_mod128_rec) {

#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_avg_mean";
  uint16_t data2txt_uint16;
  uint24_t data2txt_uint24;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_block_sum");
  FILE *file_p0_block_sum;
  file_p0_block_sum = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_miuNow");
  FILE *file_p1_miuNow;
  file_p1_miuNow = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_ret");
  FILE *file_p2_ret;
  file_p2_ret = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p15_kround_rcp");
  FILE *file_p15_kround_rcp;
  file_p15_kround_rcp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p16_miuDec");
  FILE *file_p16_miuDec;
  file_p16_miuDec = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p17_miuMiddle");
  FILE *file_p17_miuMiddle;
  file_p17_miuMiddle = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p18_miu");
  FILE *file_p18_miu;
  file_p18_miu = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p19_miuDecmul");
  FILE *file_p19_miuDecmul;
  file_p19_miuDecmul = printfOpenFile(nodeName, opName);
#endif
  uint32_t kround;
  float24_t rec_blockStep, mui_d;
  float32_t eps_f32, blockStepTmp, rec_blockStepTmp, kround_rcp, kroundTmp;
  blockStepTmp = i32_to_f32(blockStep);
  rec_blockStepTmp.v = sfu_rcp(blockStepTmp.v);
  rec_blockStep.v = fp32_to_fp24(rec_blockStepTmp.v);
  uint32_t kround_rcpNum = 256;
  uint32_t *kround_rcp_txt = new uint32_t[kround_rcpNum];
  float24_t *blockInput = new float24_t[blockStep];
  int paddingNum = (blockStep - src_col % blockStep) % blockStep;
  for (int i = 0; i < src_row; i++) {
    float32_t na_f32, nb_f32, miuNA, M2, M2NA, miu;
    miuNA.v = 0;
    M2NA.v = 0;
    int count = 0;
    for (int j = 0; j < src_col; j += blockStep) {
      int block_end = min(j + blockStep, src_col);
      int nb = block_end - j;
      nb_f32 = i32_to_f32(nb);
      float32_t block_mean, block_m2, miuNow32; //  a block
      block_mean.v = 0, block_m2.v = 0;
      // for a block miu :start==============
      int m = 0, n = 0;
      for (n = j; n < block_end; n++) {
        float16_t data_f16;
        data_f16.v = src_data[i * src_col + n];
        float24_t data_fP24;
        if (i_type == FP16) {
          data_fP24.v = fp16_to_fp24(data_f16.v);
        } else if (i_type == BF16) {
          data_fP24.v = bf16_to_fp24(data_f16.v);
        }
        blockInput[m].v = data_fP24.v;
        m++;
      }
      if (block_end == src_col) // padding for add2 ,need to polish zeros
      {
        for (int padding_i = 0; padding_i < paddingNum; padding_i++) {
          blockInput[padding_i + m].v = 0;
        }
      }
      float24_t block_sum, miuNow;
      block_sum = add2(blockInput, nb, paddingValue);
#if TEST_FOR_DE_DV
      data2txt_uint24 = block_sum.v;
      operators::printfData24bit(data2txt_uint24, file_p0_block_sum);
#endif
      if (block_end != src_col) {
        mui_d = rec_blockStep; // 1/nb ,nb = 128. dimk_mod128_rec ,1 /128
        kround = n / blockStep;
        kroundTmp = i32_to_f32(kround);
        kround_rcp.v = kroundData[kround - 1]; //  sfu_rcp(kroundTmp.v);
                                               // 1/blockNum
      } else if (block_end == src_col) {
        mui_d = dimk_mod128_rec; // 1/nb ,nb != 128 ， 1 /（dim_k %128）
        kround_rcp.v = dimk_mod128_rec_dimk; // lastBlockNum / colNum
      }
#if TEST_FOR_DE_DV
      data2txt_uint32 = kround_rcp.v;
      operators::printfData32bit(data2txt_uint32, file_p15_kround_rcp);
#endif
      miuNow.v = fp24mul(block_sum.v, mui_d.v); //
      miuNow32.v = fp24_to_fp32(miuNow.v);
#if TEST_FOR_DE_DV
      data2txt_uint24 = miuNow.v;
      operators::printfData24bit(data2txt_uint24, file_p1_miuNow);
#endif
      float16_t miuNow16;
      if (i_type == FP16) {
        miuNow16.v = fp24_to_fp16(miuNow.v);
      } else if (i_type == BF16) {
        miuNow16.v = fp24_to_bf16(miuNow.v);
      }
      float32_t miuDec;
      miuDec = f32_sub(miuNow32, miuNA);
#if TEST_FOR_DE_DV
      data2txt_uint32 = miuDec.v;
      operators::printfData32bit(data2txt_uint32, file_p16_miuDec);
#endif
      float32_t miuMiddle = f32_mul(miuDec, kround_rcp);
      miu.v = fp32add(miuNA.v, miuMiddle.v);
      miuNA = miu;
#if TEST_FOR_DE_DV
      data2txt_uint32 = miuMiddle.v;
      operators::printfData32bit(data2txt_uint32, file_p17_miuMiddle);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = miu.v;
      operators::printfData32bit(data2txt_uint32, file_p18_miu);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = miuMiddle.v;
      operators::printfData32bit(data2txt_uint32, file_p19_miuDecmul);
#endif
    }
    if (i_type == FP16) {
      ret[i] = fp32_to_fp16(miu.v);
    } else if (i_type == BF16) {
      ret[i] = fp32_to_bf16(miu.v);
    }
#if TEST_FOR_DE_DV
    data2txt_uint16 = ret[i];
    operators::printfData16bit(data2txt_uint16, file_p2_ret);
#endif
  }
  delete[] blockInput;
  delete[] kround_rcp_txt;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_block_sum);
  printfcloseFile(file_p1_miuNow);
  printfcloseFile(file_p2_ret);
  printfcloseFile(file_p15_kround_rcp);
  printfcloseFile(file_p16_miuDec);
  printfcloseFile(file_p17_miuMiddle);
  printfcloseFile(file_p18_miu);
  printfcloseFile(file_p19_miuDecmul);
#endif
}
/*========================================
Function: reduce of add for 32 datas.  sum .32 sum to 1 data.
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep:
  paddingValue:
output:
  ret, dim [row][1]
============================================*/
/*=========reduce of avg. find a max value of index from a row======made by
 * qingyan*/
void reduce_add32(uint16_t *ret, const uint16_t *src_data, int src_row,
                  int src_col, DataType i_type, DataType o_type, int blockStep,
                  float24_t paddingValue) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_add32";
  uint16_t data2txt_uint16;
  uint24_t data2txt_uint24;
  uint32_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_ret_16");
  FILE *file_p0_ret_16;
  file_p0_ret_16 = printfOpenFile(nodeName, opName);
#endif
  blockStep = 32;
  int all_col = src_col + (blockStep - src_col % blockStep) %
                              blockStep; // align according to blockStep
  float24_t *data24 = new float24_t[all_col * src_row];
  float16_t data16, ret_16;
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < all_col; i++) // f16 to f24
    {
      int indexPad = j * all_col + i;
      int tmp = j * src_col + i;
      if (i >= src_col) {
        data24[indexPad].v = paddingValue.v; // paddingValue
        continue;
      }
      data16.v = src_data[tmp];
      if (i_type == FP16) {
        data24[indexPad].v = fp16_to_fp24(data16.v);
      } else if (i_type == BF16) {
        data24[indexPad].v = bf16_to_fp24(data16.v);
      }
    }
  }
  float24_t sumTmp, sum;
  int paddingNumFlag = 0, paddingNum = 0, indexRet = 0;
  for (int j = 0; j < src_row; j++) {
    sumTmp.v = 0;
    for (int i = 0; i < all_col; i += blockStep) // f16 to f24
    {
      int tmp = j * all_col + i;
      sumTmp = add2(data24 + tmp, blockStep, paddingValue);
      if (i_type == FP16) {
        ret_16.v = fp24_to_fp16(sumTmp.v);
      } else if (i_type == BF16) {
        ret_16.v = fp24_to_bf16(sumTmp.v);
      }
      ret[indexRet] = ret_16.v;
      indexRet++;
#if TEST_FOR_DE_DV
      data2txt_uint16 = ret_16.v;
      operators::printfData16bit(data2txt_uint16, file_p0_ret_16);
#endif
    }
  }
  delete[] data24;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_ret_16);
#endif
}

/*========================================
Function: reduce of top2. find two max value of index and value from a row.
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/15. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep： value is 128.
output:
  ret, dim [row][2],out index
  outData, dim [row][2],out data
============================================*/
void reduce_top2(uint32_t *ret, uint32_t *retAll, const uint16_t *src_data,
                 uint16_t *outData, int src_row, int src_col, DataType i_type,
                 DataType o_type, int blockStep) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "reduce_top2";
  uint16_t data2txt_uint16;
  uint16_t data2txt_uint32;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_dataMax1");
  FILE *file_p0_dataMax1;
  file_p0_dataMax1 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p1_dataMax2");
  FILE *file_p1_dataMax2;
  file_p1_dataMax2 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p2_retAll");
  FILE *file_p2_retAll;
  file_p2_retAll = printfOpenFile(nodeName, opName);
#endif
  blockStep = 128;
  int all_col = src_col + (blockStep - src_col % blockStep) %
                              blockStep; // align according to blockStep
  uint32_t *retOne1 = new uint32_t[1];
  uint32_t *retOne2 = new uint32_t[1];
  uint16_t *paddingData = new uint16_t[all_col * src_row];
  int index = 0;
  uint32_t retTmp = 0;
  float16_t data16, dataMax1, dataMax2, data16_1, data16_2;
  // padding
  for (int j = 0; j < src_row; j++) {
    for (int i = 0; i < all_col; i++) {
      int tmp = j * all_col + i;
      int tmp_src = j * src_col + i;
      if (i >= src_col) {
        if (i_type == FP16) {
          paddingData[tmp] = 0xfc00; //-inf fp16, 1,5,10
        } else if (i_type == BF16) {
          paddingData[tmp] = 0xff80; //-inf fp16, 1,8,7
        }
      } else if (i < src_col) {
        paddingData[tmp] = src_data[tmp_src];
      }
    }
  }
  int maxIndex1 = 0, maxIndex2 = 0;
  for (int j = 0; j < src_row; j++) {
    int flag = 1; // =1, is first 128 block. =0, not is first 128 block
    for (int i = 0; i < src_col; i += blockStep) {
      int tmp = j * all_col + i;
      reduce_argmax(retOne1, paddingData + tmp, 1, 128, i_type, o_type,
                    blockStep);
      maxIndex1 = tmp + retOne1[0];
      data16_1.v = paddingData[maxIndex1]; // max value of 128
      if (i_type == FP16) {                // invalid
        paddingData[maxIndex1] = 0xfc00;
      } else if (i_type == BF16) {
        paddingData[maxIndex1] = 0xff80;
      }
      reduce_argmax(retOne2, paddingData + tmp, 1, 128, i_type, o_type,
                    blockStep);
      maxIndex2 = tmp + retOne2[0];
      data16_2.v = paddingData[maxIndex2];
      if (flag == 1) {
        ret[index] = maxIndex1;
        ret[index + 1] = maxIndex2;
        dataMax1.v = data16_1.v;
        dataMax2.v = data16_2.v;
        outData[index] = dataMax1.v;
        outData[index + 1] = dataMax2.v;
        flag = 0;
#if TEST_FOR_DE_DV
        data2txt_uint16 = dataMax1.v;
        operators::printfData16bit(data2txt_uint16, file_p0_dataMax1);
#endif
#if TEST_FOR_DE_DV
        data2txt_uint16 = dataMax2.v;
        operators::printfData16bit(data2txt_uint16, file_p1_dataMax2);
#endif
      } else if (flag == 0) {
        if ((data16_1.v == dataMax1.v) && (data16_1.v != dataMax2.v)) {
          ret[index + 1] = maxIndex1;
          outData[index + 1] = outData[index];
        } else {
          if (data16_1.v != dataMax1.v) {
            if (i_type == FP16) {
              dataMax1.v = fp16max(dataMax1.v, data16_1.v);
            } else if (i_type == BF16) {
              dataMax1.v = bf16max(dataMax1.v, data16_1.v);
            }
            if (dataMax1.v == data16_1.v) {
              ret[index + 1] = ret[index];
              outData[index + 1] = outData[index];
              dataMax2.v = outData[index];
              ret[index] = maxIndex1;
              outData[index] = data16_1.v;
            } else {
              if (dataMax2.v != data16_1.v) {
                if (i_type == FP16) {
                  dataMax2.v = fp16max(data16_1.v, dataMax2.v);
                } else if (i_type == BF16) {
                  dataMax2.v = bf16max(data16_1.v, dataMax2.v);
                }
                if (dataMax2.v == data16_1.v) {
                  ret[index + 1] = maxIndex1;
                  outData[index + 1] = data16_1.v;
                }
              }
            }
          }
#if TEST_FOR_DE_DV
          data2txt_uint16 = dataMax1.v;
          operators::printfData16bit(data2txt_uint16, file_p0_dataMax1);
#endif
          if (dataMax2.v != data16_2.v) {
            if (i_type == FP16) {
              dataMax2.v = fp16max(dataMax2.v, data16_2.v);
            } else if (i_type == BF16) {
              dataMax2.v = bf16max(dataMax2.v, data16_2.v);
            }
            if (dataMax2.v == data16_2.v) {
              ret[index + 1] = maxIndex2;
              outData[index + 1] = dataMax2.v;
            }
          }
        }
        dataMax1.v = outData[index];
        dataMax2.v = outData[index + 1];
#if TEST_FOR_DE_DV
        data2txt_uint16 = dataMax2.v;
        operators::printfData16bit(data2txt_uint16, file_p1_dataMax2);
#endif
      }
    }
    index += 2;
  }
  uint32_t retAllIndex = 0, retIndex = 0;
  for (uint32_t k = 0; k < src_row; k++) {
    retAll[retAllIndex] = ret[retIndex];
    retAll[retAllIndex + 1] = ret[retIndex + 1];
    retAll[retAllIndex + 2] = (outData[retIndex + 1] << 16) + outData[retIndex];
#if TEST_FOR_DE_DV
    data2txt_uint32 = retAll[retAllIndex];
    operators::printfData32bit(data2txt_uint32, file_p2_retAll);
    data2txt_uint32 = retAll[retAllIndex + 1];
    operators::printfData32bit(data2txt_uint32, file_p2_retAll);
    data2txt_uint32 = retAll[retAllIndex + 2];
    operators::printfData32bit(data2txt_uint32, file_p2_retAll);
#endif
    retAllIndex += 3;
    retIndex += 2;
  }
  delete[] paddingData;
  delete[] retOne1;
  delete[] retOne2;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_dataMax1);
  printfcloseFile(file_p1_dataMax2);
  printfcloseFile(file_p2_retAll);
#endif
}
} // namespace operators
