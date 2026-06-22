#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {
uint32_t kroundDataLaynorm[] = {
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
Function: vae_layernorm .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/20. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  gamma:dim [src_row][src_col], type uint16_t
  bias: dim [src_row][src_col], type uint16_t
  src_row:the row of 2D matrix ,such 1
  src_col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  blockStep: unit for block calculation in a column
  dimk_rec: 1/dim_k.
  dimk_mod128_rec_dimk: (dim_k % 128 )/dim_k;
  dimk_mod128_rec: 1 / (dim_k % 128 )
  eps:
  paddingVlaue:0, -inf +inf ,and so on .
  flagBiasGamma: 0, not need bias and gamma; 1, need.
output:
  laynorm_result: a 2D matrix
============================================*/
void vae_layernorm(uint16_t *laynorm_result, const uint16_t *src_data,
                   const uint16_t *gamma, const uint16_t *bias, int src_row,
                   int src_col, DataType i_type, DataType o_type, int blockStep,
                   uint32_t dimk_rec, uint32_t dimk_mod128_rec_dimk,
                   float24_t dimk_mod128_rec, uint32_t eps,
                   float24_t paddingVlaue, int flagBiasGamma) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "layernorm";
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
  strcpy(nodeName, "p2_miuMiddle");
  FILE *file_p2_miuMiddle;
  file_p2_miuMiddle = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p3_subNow");
  FILE *file_p3_subNow;
  file_p3_subNow = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p4_submUL_TMP");
  FILE *file_p4_submUL_TMP;
  file_p4_submUL_TMP = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p5_addM2Tmp");
  FILE *file_p5_addM2Tmp;
  file_p5_addM2Tmp = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p6_M2NA");
  FILE *file_p6_M2NA;
  file_p6_M2NA = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p7_data_diff");
  FILE *file_p7_data_diff;
  file_p7_data_diff = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p9_q_tmp0");
  FILE *file_p9_q_tmp0;
  file_p9_q_tmp0 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p10_q_tmp1");
  FILE *file_p10_q_tmp1;
  file_p10_q_tmp1 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p11_q");
  FILE *file_p11_q;
  file_p11_q = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p12_row_rst32");
  FILE *file_p12_row_rst32;
  file_p12_row_rst32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p13_Y_tmp32");
  FILE *file_p13_Y_tmp32;
  file_p13_Y_tmp32 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p14_result");
  FILE *file_p14_result;
  file_p14_result = printfOpenFile(nodeName, opName);
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
  strcpy(nodeName, "p20_m2Middle1");
  FILE *file_p20_m2Middle1;
  file_p20_m2Middle1 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p21_m2Middle2");
  FILE *file_p21_m2Middle2;
  file_p21_m2Middle2 = printfOpenFile(nodeName, opName);
  strcpy(nodeName, "p22_M2");
  FILE *file_p22_M2;
  file_p22_M2 = printfOpenFile(nodeName, opName);
#endif
  uint32_t kround;
  float24_t rec_blockStep, mui_d;
  float32_t eps_f32, blockStepTmp, rec_blockStepTmp, kround_rcp, kroundTmp;
  blockStepTmp = i32_to_f32(blockStep);
  rec_blockStepTmp.v = sfu_rcp(blockStepTmp.v);
  rec_blockStep.v = fp32_to_fp24(rec_blockStepTmp.v);
  eps_f32.v = eps;
  float24_t *blockInput = new float24_t[blockStep];
  float24_t *blockM2 = new float24_t[blockStep];
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
      block_sum = add2(blockInput, nb, paddingVlaue);
#if TEST_FOR_DE_DV
      data2txt_uint24 = block_sum.v;
      operators::printfData24bit(data2txt_uint24, file_p0_block_sum);
#endif
      if (block_end != src_col) {
        mui_d = rec_blockStep; // 1/nb ,nb = 128. dimk_mod128_rec ,1 /128
        kround = n / blockStep;
        kroundTmp = i32_to_f32(kround);
        kround_rcp.v =
            kroundDataLaynorm[kround -
                              1]; // sfu_rcp(kroundTmp.v); // 1/blockNum
      } else if (block_end == src_col) {
        mui_d = dimk_mod128_rec; // 1/nb ,nb != 128 ， 1 /（dim_k %128）
        kround_rcp.v = dimk_mod128_rec_dimk; // lastBlockNum / colNum
      }
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
      miuDec.v = fp32sub(miuNow32.v, miuNA.v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = kround_rcp.v;
      operators::printfData32bit(data2txt_uint32, file_p15_kround_rcp);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = miuDec.v;
      operators::printfData32bit(data2txt_uint32, file_p16_miuDec);
#endif
      float32_t miuMiddle;
      miuMiddle.v = fp32mul(miuDec.v, kround_rcp.v);
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
      data2txt_uint32 = miuMiddle.v; // =p19,is p2
      operators::printfData32bit(data2txt_uint32, file_p2_miuMiddle);
#endif
      // for a block miu :end ==============
      // for a block M2 :start ==============
      float32_t miuDecmul;
      miuDecmul.v = fp32mul(miuDec.v, miuMiddle.v);
#if TEST_FOR_DE_DV
      data2txt_uint32 = miuDecmul.v; // =p2
      operators::printfData32bit(data2txt_uint32, file_p19_miuDecmul);
#endif
      float32_t allNum;
      allNum = i32_to_f32(count);
      float32_t m2Middle1;
      m2Middle1.v = fp32mul(miuDecmul.v, allNum.v);
      m = 0;
      for (int n = j; n < block_end; n++) { // in a block to M2
        float16_t data_f16, subNow, subMul;
        float24_t submUL_TMP;
        float32_t subMul32;
        data_f16.v = src_data[i * src_col + n];
        if (i_type == FP16) {
          subNow.v = fp16sub(data_f16.v, miuNow16.v);
          subMul32.v = fp16mul_resfp32(subNow.v, subNow.v);
        } else if (i_type == BF16) {
          subNow.v = bf16sub(data_f16.v, miuNow16.v);
          subMul32.v = bf16mul_resfp32(subNow.v, subNow.v);
        }
        submUL_TMP.v = fp32_to_fp24(subMul32.v);
        blockM2[m] = submUL_TMP;
        m++;
#if TEST_FOR_DE_DV
        data2txt_uint32 = subNow.v;
        operators::printfData32bit(data2txt_uint32, file_p3_subNow);
#endif
#if TEST_FOR_DE_DV
        data2txt_uint24 = submUL_TMP.v;
        operators::printfData24bit(data2txt_uint24, file_p4_submUL_TMP);
#endif
      }
      if (block_end == src_col) // padding for add2 ,need to polish zeros
      {
        for (int padding_i = 0; padding_i < paddingNum; padding_i++) {
          blockM2[padding_i + m].v = 0;
        }
      }
      float24_t addM2;
      addM2 = add2(blockM2, nb, paddingVlaue);
      float32_t addM2Tmp;
      addM2Tmp.v = fp24_to_fp32(addM2.v);
      float32_t m2Middle2;
      m2Middle2.v = fp32add(M2NA.v, addM2Tmp.v);
      M2.v = fp32add(m2Middle1.v, m2Middle2.v);
      M2NA = M2;
      count += nb;
#if TEST_FOR_DE_DV
      data2txt_uint32 = addM2Tmp.v;
      operators::printfData32bit(data2txt_uint32, file_p5_addM2Tmp);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = M2NA.v; // = p22
      operators::printfData32bit(data2txt_uint32, file_p6_M2NA);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = m2Middle1.v;
      operators::printfData32bit(data2txt_uint32, file_p20_m2Middle1);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = m2Middle2.v;
      operators::printfData32bit(data2txt_uint32, file_p21_m2Middle2);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = M2.v;
      operators::printfData32bit(data2txt_uint32, file_p22_M2);
#endif
      // for a block M2 :end ==============
    }
    //======normalization==========
    float32_t q_tmp0, q_tmp1, q;
    q_tmp0.v = fp32mulAdd(dimk_rec, M2.v, eps_f32.v);
    q_tmp1.v = sfu_sqrt(q_tmp0.v);
    q.v = sfu_rcp(q_tmp1.v);
    float16_t q_f16, miu_f16;
#if TEST_FOR_DE_DV
    data2txt_uint32 = q_tmp0.v;
    operators::printfData32bit(data2txt_uint32, file_p9_q_tmp0);
#endif
#if TEST_FOR_DE_DV
    data2txt_uint32 = q_tmp1.v;
    operators::printfData32bit(data2txt_uint32, file_p10_q_tmp1);
#endif
#if TEST_FOR_DE_DV
    data2txt_uint32 = q.v;
    operators::printfData32bit(data2txt_uint32, file_p11_q);
#endif
    if (i_type == FP16) {
      q_f16.v = fp32_to_fp16(q.v);
      miu_f16.v = fp32_to_fp16(miu.v);
    } else if (i_type == BF16) {
      q_f16.v = fp32_to_bf16(q.v);
      miu_f16.v = fp32_to_bf16(miu.v);
    }
    for (int j = 0; j < src_col; j++) { // norm
      float16_t data_f16, gamma_f16, bias_f16, row_rst, Y_tmp, result,
          data_diff;
      float32_t row_rst32, Y_tmp32;
      int tmp = i * src_col + j;
      data_f16.v = src_data[tmp];
      gamma_f16.v = gamma[j];
      bias_f16.v = bias[j];
      if (i_type == FP16) {
        data_diff.v = fp16sub(data_f16.v, miu_f16.v);        // x-u
        row_rst32.v = fp16mul_resfp32(data_diff.v, q_f16.v); // x=(x-u)/q
        row_rst.v = fp32_to_fp16(row_rst32.v);
        if (flagBiasGamma == 1) {
          Y_tmp32.v = fp16mul_resfp32(row_rst.v, gamma_f16.v);
          Y_tmp.v = fp32_to_fp16(Y_tmp32.v);
          result.v = fp16add(Y_tmp.v, bias_f16.v); // gamma*x+beta
        } else {
          result = row_rst;
        }
      } else if (i_type == BF16) {
        data_diff.v = bf16sub(data_f16.v, miu_f16.v);        // x-u
        row_rst32.v = bf16mul_resfp32(data_diff.v, q_f16.v); // x=(x-u)/q
        row_rst.v = fp32_to_bf16(row_rst32.v);
        if (flagBiasGamma == 1) {
          Y_tmp32.v = bf16mul_resfp32(row_rst.v, gamma_f16.v);
          Y_tmp.v = fp32_to_bf16(Y_tmp32.v);
          result.v = bf16add(Y_tmp.v, bias_f16.v); // gamma*x+beta
        } else {
          result = row_rst;
        }
      }
      laynorm_result[tmp] = result.v;
#if TEST_FOR_DE_DV
      data2txt_uint16 = data_diff.v;
      operators::printfData16bit(data2txt_uint16, file_p7_data_diff);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = row_rst32.v;
      operators::printfData32bit(data2txt_uint32, file_p12_row_rst32);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint32 = Y_tmp32.v;
      operators::printfData32bit(data2txt_uint32, file_p13_Y_tmp32);
#endif
#if TEST_FOR_DE_DV
      data2txt_uint16 = result.v;
      operators::printfData16bit(data2txt_uint16, file_p14_result);
#endif
    }
  }
  delete[] blockInput;
  delete[] blockM2;
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_block_sum);
  printfcloseFile(file_p1_miuNow);
  printfcloseFile(file_p2_miuMiddle);
  printfcloseFile(file_p3_subNow);
  printfcloseFile(file_p4_submUL_TMP);
  printfcloseFile(file_p5_addM2Tmp);
  printfcloseFile(file_p6_M2NA);
  printfcloseFile(file_p7_data_diff);
  printfcloseFile(file_p9_q_tmp0);
  printfcloseFile(file_p10_q_tmp1);
  printfcloseFile(file_p11_q);
  printfcloseFile(file_p12_row_rst32);
  printfcloseFile(file_p13_Y_tmp32);
  printfcloseFile(file_p14_result);
  printfcloseFile(file_p15_kround_rcp);
  printfcloseFile(file_p16_miuDec);
  printfcloseFile(file_p17_miuMiddle);
  printfcloseFile(file_p18_miu);
  printfcloseFile(file_p19_miuDecmul);
  printfcloseFile(file_p20_m2Middle1);
  printfcloseFile(file_p21_m2Middle2);
  printfcloseFile(file_p22_M2);
#endif
}
} // namespace operators