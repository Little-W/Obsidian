

#include "test_common_vae.h"
#include "booth_multiply.h"
#include "cmodel.h"
#include "conv_func.h"
#include "dop_ops.h"
#include "dop_utils.h"
#include "matrix_struct.h"
#include "sfu_exp.h"
#include "sfu_sincos.h"
#include "sfu_sqrt_rcp.h"
#include "sfu_tanh.h"
#include "sm_data_struct.h"
#include "softfloat.h"
#include "vae_common.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

#if 1 // defined(USE_EXTERN_C)

/*========================================
Function: test softmax online
Information:Author is ZC, 2025/07/15. by qingyan
============================================*/
void fun_test_vae(int row, int col, DataType i_type, DataType o_type,
                  int functionNumber) {
  union ui64_f64_print data64, dataB64, gamma64, eps64, maskValue0, maskValue1,
      bias64, factor64, kMean64, qCmath64, scale_softmax_cmath64,
      softmax_fa2_64;
  union ui32_f32_print data32, mask32;
  union ui16_f16_print data16;

  int dataNum = row * col;
  double *input_cmath = new double[dataNum];
  double *inputB_cmath = new double[dataNum];
  double *q_cmath = new double[dataNum];
  uint16_t *src_mask = new uint16_t[dataNum];
  double *mean = new double[dataNum];
  double scale_softmax_cmath = 1.5;
  double *out_cmath = new double[dataNum];
  double *out_quant_rope_cmath = new double[dataNum];
  int *outIndexReduce = new int[dataNum];
  double *gamma = new double[dataNum];
  double *bias = new double[dataNum];
  int blockStep = 128; // it must be a power of 2
  int flagGamma = 0;
  int maskFlag = 0;
  int scaleFlag = 0; // softmax
  int flagBiasGamma = 0;
  double mask_value0 = -INFINITY;
  double mask_value1 = 2;
  int byPassFlag = 1;
  uint32_t elementModel = 1;
  double eps = 0.000001; // 1e-6
  char operationType[] = "mul";
  char reduceOperatorMode[] = "add32";
  uint16_t *input_cmodel = new uint16_t[dataNum * 2];
  uint24_t *input_cmodel24 = new uint24_t[dataNum];
  uint32_t *input_cmodel32 = new uint32_t[dataNum];
  uint16_t *out_EMRFIFO = new uint16_t[row];
  uint32_t *pre_sum_blk_output = new uint32_t[row];
  uint32_t *pre_sum_blk_input = new uint32_t[row];
  uint16_t *pre_max_input = new uint16_t[row];
  uint16_t *pre_max_output = new uint16_t[row];
  uint16_t *scaleBufferPerToken = new uint16_t[row];
  uint16_t *scaleBufferPerTensor = new uint16_t[1];

  for (uint32_t i = 0; i < row; i++) {
    if (i_type == FP16) {
      pre_max_input[i] = 0xfc00;
    } else if (i_type == BF16) {
      pre_max_input[i] = 0xff80;
    }
  }

  uint16_t *inputB_cmodel = new uint16_t[dataNum];
  uint16_t *src_mask_cmodel = new uint16_t[dataNum];
  uint16_t *k_mean_cmodel = new uint16_t[dataNum];
  uint16_t *qCmodel = new uint16_t[dataNum * 2];

  uint16_t *out_cmodel = new uint16_t[dataNum];
  uint32_t *out_cmodel32 = new uint32_t[dataNum];
  uint16_t *outData = new uint16_t[dataNum];

  uint24_t *out_cmodel24 = new uint24_t[dataNum];

  uint16_t *gamma_cmodel = new uint16_t[dataNum];
  uint16_t *bias_cmodel = new uint16_t[dataNum];
  uint8_t *out_cmodel_quant = new uint8_t[dataNum];
  uint8_t *rope_quant_cmodel = new uint8_t[dataNum];

  double data = 0;
  int addNum = 0;
  float16_t inputCmodel, inputBCmodel, gammaCmodel, biasCmodel, maskCmodel,
      maskCmodelTmp, kMeanCmodel, rope_q_cmodel, scale_softmax;
  cout << "======cmath input data : ===========\n";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      addNum = tmp + 1;
      input_cmath[tmp] = addNum; //-5.321 + operators::random_range_int(1, 5);
      inputB_cmath[tmp] = 4 + operators::random_range_int(1, 10);
      mean[tmp] = 0.5 + operators::random_range_int(1, 10);
      q_cmath[tmp] = -1.326 + operators::random_range_int(0, 2);
      gamma[tmp] = 1;
      bias[tmp] = 1;
      src_mask[tmp] = rand() % 2;
#if 1
      cout << "input_cmath = " << tmp << "," << input_cmath[tmp] << ", "
           << "hex = ";
      data64.dou64 = input_cmath[tmp];
      operators::print_hex_64_union_ui64_dou64(data64);
#endif
    }
  }
#if 0
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < col; j++){
            int tmp = i * col +j;
            cout << "q_cmath = "<< tmp<< "," << q_cmath[tmp] << ", " << "hex = ";
            data64.dou64 = q_cmath[tmp];
            operators::print_hex_64_union_ui64_dou64(data64);
        }
    }
#endif
#if 0 // read data from samuel
  std::string filename = "input.txt";
  std::vector<uint16_t> inputDataGolden;
  inputDataGolden = readDataFromTxt(filename);
  uint32_t dataSize = inputDataGolden.size();
  printf("dataSize = %d \n", dataSize);
  ui64_f64_print dataDouble;
  for (uint32_t i = 0; i < dataSize; i++) {
    input_cmath[i] = bf16_to_double(inputDataGolden[i]);
    dataDouble.dou64 = input_cmath[i];
    if (i < 20) {
      printUint16(&inputDataGolden[i], 1);
      operators::printHexUint64(dataDouble.ui64);
    }
  }
#endif
  // cmath
  // for quantization :start
  double factor = 0.00787401574803149; //  1 / 127
  double paddingValueDouble = 0;
  // mode,0,per token;1,per tensor;2,per group
  int model = 4;
  // for quantization :end
  if (model == 0 || model == 2) {
    printf("ok\n");
    factor = 0.00787401574803149; //  1 / 127
  } else if (model == 1) {
    factor = 0.00223214285714285; // 1 / 448
  }
  uint32_t kMeanBypass = 0;
  if (functionNumber == 0) {
    operators::rmsnorm_cmath_double(out_cmath, input_cmath, gamma, col, row,
                                    eps);
  } else if (functionNumber == 1) {
    operators::softmax_online_double(out_cmath, input_cmath, col, row,
                                     scale_softmax_cmath, scaleFlag, maskFlag,
                                     src_mask, mask_value0); // cmath
  } else if (functionNumber == 2) {
    operators::layernorm_double_no_wel(out_cmath, input_cmath, gamma, eps, bias,
                                       col, row, blockStep, flagBiasGamma);
  } else if (functionNumber == 3) {
    operators::elementwise_cmath(input_cmath, inputB_cmath, out_cmath, row, col,
                                 elementModel);
  } else if (functionNumber == 4) {
    operators::mask_cmath(out_cmath, input_cmath, src_mask, row, col,
                          mask_value0);
  } else if (functionNumber == 5) {
    if (model == 0) {
      operators::quantizationPerToken(input_cmath, out_cmath, factor, model,
                                      row, col, mean, kMeanBypass);
    } else if (model == 1) {
      operators::quantizationPerTensorCmath(input_cmath, out_cmath, factor,
                                            model, row, col, mean, kMeanBypass);
    } else if (model == 2) {
      operators::quantizationPerGroup(input_cmath, out_cmath, factor, model,
                                      row, col);
    }
  } else if (functionNumber == 6) {
    operators::rope_cmath(input_cmath, q_cmath, row, col, out_cmath,
                          out_quant_rope_cmath, paddingValueDouble, factor,
                          mean, byPassFlag);
  } else if (functionNumber == 7) {
    operators::reduce_cmath(input_cmath, out_cmath, outIndexReduce, row, col,
                            reduceOperatorMode);
  } else if (functionNumber == 8) {
    operators::softmax_fa1(out_cmath, input_cmath, col, row,
                           scale_softmax_cmath, scaleFlag, maskFlag, src_mask,
                           mask_value0, byPassFlag, out_quant_rope_cmath,
                           factor);
  } else if (functionNumber == 9) {
    operators::softmax_fa2_cmath(input_cmath, input_cmath, input_cmath,
                                 out_cmath, row, col);
  } else if (functionNumber == 10) {
    operators::softmax_fa3_cmath(input_cmath, input_cmath, out_cmath, row, col);
  }

#if 0
    cout<<"=========cmath out data : ==========\n";
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < col; j++){
            int tmp = i * col + j;
            cout << "out_cmath = "<< out_cmath[tmp] << "\n";

#if 0
            data64.dou64 = out_cmath[tmp];
            operators::print_hex_64_union_ui64_dou64(data64);
#endif
        }
    }
#endif

  float64_t tran, tranB, tranGamma, tranBias, maskValue0_64, maskValue1_64,
      factor_f64, kMean_f64, qCmath_f64, scale_softmax_f64;
  float32_t tan0, maskF32, scale_softmax32;
  uint16_t tan1;
  float16_t mask_value0_cmodel, mask_value1_cmodel, factor_f16_cmodel;
  float24_t factor_f24_cmodel;
  if (functionNumber == 7) { // reduce of avg(mean)
    factor = 1.0 / col;
  }
  maskValue0.dou64 = mask_value0;
  maskValue1.dou64 = mask_value1;
  maskValue0_64.v = maskValue0.ui64;
  maskValue1_64.v = maskValue1.ui64;
  factor64.dou64 = factor;
  factor_f64.v = factor64.ui64;
  scale_softmax_cmath64.dou64 = scale_softmax_cmath;
  scale_softmax_f64.v = scale_softmax_cmath64.ui64;
  float32_t factor_cmodelTmp = f64_to_f32(factor_f64);
  factor_f24_cmodel.v = operators::fp32_to_fp24(factor_cmodelTmp.v);
  if (i_type == FP16) {
    mask_value0_cmodel = f64_to_f16(maskValue0_64);
    mask_value1_cmodel = f64_to_f16(maskValue1_64);
    factor_f16_cmodel = f64_to_f16(factor_f64);
    scale_softmax = f64_to_f16(scale_softmax_f64);
  } else if (i_type == BF16) {
    float32_t mask_value0_cmodelTmp = f64_to_f32(maskValue0_64);
    float32_t mask_value1_cmodelTmp = f64_to_f32(maskValue1_64);
    mask_value0_cmodel.v = operators::fp32_to_bf16(mask_value0_cmodelTmp.v);
    mask_value1_cmodel.v = operators::fp32_to_bf16(mask_value1_cmodelTmp.v);
    factor_f16_cmodel.v = operators::fp32_to_bf16(factor_cmodelTmp.v);
    scale_softmax32 = f64_to_f32(scale_softmax_f64);
    scale_softmax.v = operators::fp32_to_bf16(scale_softmax32.v);
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      data64.dou64 = input_cmath[tmp];
      tran.v = data64.ui64;
      dataB64.dou64 = inputB_cmath[tmp];
      tranB.v = dataB64.ui64;
      gamma64.dou64 = gamma[tmp];
      tranGamma.v = gamma64.ui64;
      bias64.dou64 = bias[tmp];
      tranBias.v = bias64.ui64;
      mask32.ui32 = src_mask[tmp];
      maskF32.v = mask32.ui32;
      kMean64.dou64 = mean[tmp];
      kMean_f64.v = kMean64.ui64;
      qCmath64.dou64 = q_cmath[tmp];
      qCmath_f64.v = qCmath64.ui64;
#if 0
            cout << "dec = "<< input_cmath[tmp] << "\n"  ;
            operators::print_hex_64_union_ui64_dou64(data64);
#endif
#if 0
            tan0 = f64_to_f32(tran);
            data32.ui32 = tan0.v;
            operators::print_hex_32_union_ui32_f32(data32);
#endif
      float32_t inputCmodelTmp, inputBCmodelTmp, gammaTmp, biasTmp, kMeanTMP,
          rope_q_cmodel_32;
      inputCmodelTmp = f64_to_f32(tran);
      input_cmodel32[tmp] = inputCmodelTmp.v;
      if (i_type == FP16) {
        inputCmodel = f64_to_f16(tran);
        inputBCmodel = f64_to_f16(tranB);
        gammaCmodel = f64_to_f16(tranGamma);
        biasCmodel = f64_to_f16(tranBias);
        maskCmodel = i32_to_f16(maskF32.v);
        kMeanCmodel = f64_to_f16(kMean_f64);
        rope_q_cmodel = f64_to_f16(qCmath_f64);
      } else if (i_type == BF16) {
        inputBCmodelTmp = f64_to_f32(tranB);
        gammaTmp = f64_to_f32(tranGamma);
        biasTmp = f64_to_f32(tranBias);
        kMeanTMP = f64_to_f32(kMean_f64);
        rope_q_cmodel_32 = f64_to_f32(qCmath_f64);
        inputCmodel.v = operators::fp32_to_bf16(inputCmodelTmp.v);
        inputBCmodel.v = operators::fp32_to_bf16(inputBCmodelTmp.v);
        gammaCmodel.v = operators::fp32_to_bf16(gammaTmp.v);
        biasCmodel.v = operators::fp32_to_bf16(biasTmp.v);
        maskCmodelTmp = i32_to_f16(maskF32.v);
        maskCmodel.v = fp16_to_bf16(maskCmodelTmp.v);
        kMeanCmodel.v = operators::fp32_to_bf16(kMeanTMP.v);
        rope_q_cmodel.v = operators::fp32_to_bf16(rope_q_cmodel_32.v);
      }
      input_cmodel[tmp] = inputCmodel.v;
      inputB_cmodel[tmp] = inputBCmodel.v;
      gamma_cmodel[tmp] = gammaCmodel.v;
      bias_cmodel[tmp] = biasCmodel.v;
      src_mask_cmodel[tmp] = maskCmodel.v;
      k_mean_cmodel[tmp] = kMeanCmodel.v;
      qCmodel[tmp] = rope_q_cmodel.v;
      softmax_fa2_64.dou64 = input_cmath[tmp];
      input_cmodel24[tmp] = operators::fp64_to_fp24(softmax_fa2_64.ui64);
      printf("input_cmodel[%d] = %d\n", tmp, input_cmodel[tmp]);
    }
  }
  uint32_t dimk_mod128_rec_dimk;
  float24_t paddingValue, dimk_mod128_rec;
  paddingValue.v = 0;
  int paddingNumFlag = 0;
  int paddingNum = 0;
  float32_t rcp_col, blockStepTmp, colTmp;
  blockStepTmp = i32_to_f32(blockStep);
  colTmp = i32_to_f32(col);
  rcp_col.v = operators::sfu_rcp(blockStepTmp.v);
  ; // 0.0078125  = 1/128
  float32_t rec_blockStep;
  rec_blockStep.v = operators::sfu_rcp(blockStepTmp.v);
  uint32_t rec_col = operators::sfu_rcp(colTmp.v);
  float32_t rec_col_rms;
  rec_col_rms.v = operators::sfu_rcp(colTmp.v);
  float32_t rec_lastBlock;
  int rec_lastBlockNum = col % blockStep;
  if (rec_lastBlockNum == 0) {
    rec_lastBlockNum = blockStep;
  }
  float32_t rec_lastBlockTmp;
  rec_lastBlockTmp = i32_to_f32(rec_lastBlockNum);
  rec_lastBlock.v = operators::sfu_rcp(rec_lastBlockTmp.v);
  dimk_mod128_rec.v = operators::fp32_to_fp24(rec_lastBlock.v);
  dimk_mod128_rec_dimk = operators::fp32mul(rec_lastBlockTmp.v, rec_col_rms.v);
#if 0
    printf("rec_lastBlockNum = %d \n", rec_lastBlockNum);
    printUint24(&rec_lastBlockTmp.v, 1);
#endif
  eps64.dou64 = eps;
  float64_t eps64Tmp;
  float32_t eps32;
  eps64Tmp.v = eps64.ui64;
  eps32 = f64_to_f32(eps64Tmp);
// for de debug
#if 0
        input_cmodel[0] = 0xb550;
        input_cmodel[1] = 0x407b;
        input_cmodel[2] = 0xc25c;
        input_cmodel[3] = 0x36c5;
        input_cmodel[4] = 0x3660;
        input_cmodel[5] = 0x3614;
        src_mask[0] = 0x0001;
        src_mask[1] = 0x0001;
        src_mask[2] = 0x0000;
        src_mask[3] = 0x0001;
        src_mask[4] = 0x0001;
        src_mask[5] = 0x0000;
#endif
  uint32_t scaleNum = row * col;
  uint16_t *scaleBuffer = new uint16_t[scaleNum];
  uint8_t *scaleBufferUint8 = new uint8_t[scaleNum];

  uint32_t *retAll = new uint32_t[row * 30];
  // cmodel
  if (functionNumber == 0) {
    operators::vae_rmsnorm(out_cmodel, input_cmodel, gamma_cmodel, row, col,
                           i_type, o_type, eps32.v, paddingValue, blockStep,
                           rec_col_rms, flagGamma);
  } else if (functionNumber == 1) {
    operators::vae_softmax_online(
        out_cmodel, input_cmodel, src_mask, row, col, i_type, o_type, blockStep,
        paddingValue, scaleFlag, scale_softmax, maskFlag, mask_value0_cmodel);
  } else if (functionNumber == 2) {
    operators::vae_layernorm(out_cmodel, input_cmodel, gamma_cmodel,
                             bias_cmodel, row, col, i_type, o_type, blockStep,
                             rec_col, dimk_mod128_rec_dimk, dimk_mod128_rec,
                             eps32.v, paddingValue, flagBiasGamma);
  } else if (functionNumber == 3) {
    operators::vae_elementwise(out_cmodel, input_cmodel, inputB_cmodel, row,
                               col, i_type, o_type, elementModel);
  } else if (functionNumber == 4) {
    operators::vae_mask(out_cmodel, input_cmodel, src_mask, row, col,
                        mask_value0_cmodel);
  } else if (functionNumber == 5) {
    if (model == 0) {
      operators::vae_quant_perToken(
          out_cmodel_quant, input_cmodel, k_mean_cmodel, scaleBufferPerToken,
          row, col, factor_f16_cmodel, i_type, o_type, kMeanBypass);
    } else if (model == 1) {
      operators::vae_quant_perTensor(out_cmodel_quant, input_cmodel,
                                     scaleBufferPerTensor, row, col,
                                     factor_f16_cmodel, i_type, o_type);
    } else if (model == 2) {

      operators::vae_quant_perGroup(out_cmodel_quant, input_cmodel, scaleBuffer,
                                    row, col, factor_f16_cmodel, i_type,
                                    o_type);
    } else if (model == 3) {
      uint16_t *ret_scale;
      operators::vae_perToken_k(out_cmodel_quant, input_cmodel, ret_scale,
                                k_mean_cmodel, row, col, factor_f16_cmodel,
                                i_type, o_type);
    } else if (model == 4) {
      uint32_t globalScale = 0x3f800000;
      operators::vae_quant_NVFP4(out_cmodel_quant, input_cmodel,
                                 scaleBufferUint8, row, col, globalScale,
                                 i_type, o_type);
    }
  } else if (functionNumber == 6) {
    uint16_t ret_scale;
    operators::rope(out_cmodel, input_cmodel, qCmodel, k_mean_cmodel, row, col,
                    blockStep, i_type, o_type, paddingValue, factor_f16_cmodel,
                    rope_quant_cmodel, byPassFlag, &ret_scale);
  } else if (functionNumber == 7) {
    if (strcmp(reduceOperatorMode, "max") == 0) {
      operators::reduce_max(out_cmodel, input_cmodel, row, col, i_type, o_type,
                            blockStep);
    } else if (strcmp(reduceOperatorMode, "min") == 0) {
      operators::reduce_min(out_cmodel, input_cmodel, row, col, i_type, o_type,
                            blockStep);
    } else if (strcmp(reduceOperatorMode, "argmax") == 0) {
      operators::reduce_argmax(out_cmodel32, input_cmodel, row, col, i_type,
                               o_type, blockStep);
    } else if (strcmp(reduceOperatorMode, "add") == 0) {
      operators::reduce_add(out_cmodel, input_cmodel, row, col, i_type, o_type,
                            blockStep, paddingValue);
    } else if (strcmp(reduceOperatorMode, "avg_mean") == 0) {
      operators::reduce_avg_mean(out_cmodel, input_cmodel, row, col, i_type,
                                 o_type, blockStep, paddingValue, rec_col,
                                 dimk_mod128_rec_dimk, dimk_mod128_rec);
    } else if (strcmp(reduceOperatorMode, "add32") == 0) {
      operators::reduce_add32(out_cmodel, input_cmodel, row, col, i_type,
                              o_type, blockStep, paddingValue);
    } else if (strcmp(reduceOperatorMode, "top2") == 0) {
      operators::reduce_top2(out_cmodel32, retAll, input_cmodel, outData, row,
                             col, i_type, o_type, blockStep);
    }
  } else if (functionNumber == 8) {
    // operators::vae_softmax_fa1(
    //     out_cmodel, input_cmodel, row, col, i_type, o_type, byPassFlag,
    //     blockStep, paddingValue, rope_quant_cmodel, scaleFlag, scale_softmax,
    //     out_EMRFIFO, pre_sum_blk_input, pre_sum_blk_output, pre_max_input,
    //     pre_max_output, scaleBufferPerTensor, factor_f16_cmodel);
  } else if (functionNumber == 9) {
    operators::softmax_fa2(out_cmodel24, input_cmodel, input_cmodel24,
                           input_cmodel, col, row, blockStep, o_type, i_type);
  } else if (functionNumber == 10) {
    operators::softmax_fa3(out_cmodel, input_cmodel32, input_cmodel24, col, row,
                           blockStep, o_type, i_type);
  }

  cout << "========cmodel and cmath out data======\n";
  float16_t outCmath;
  float32_t outCmathTmp;

#if 0 // for reduce mim/max/avg-mean/
  col = 1;
#endif
#if 1
  col = (col + ((32 - col % 32) % 32)) / 32;
  printf("col = %d \n", col);
#endif
  // col = 1;
// row = 1;
#if 1 // perTensor,per token
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      cout << "i_row,j_col: " << i << "," << j << "\n";

      cout << "cmodel out,";
      if (o_type == FP16 || o_type == BF16) {
        data16.ui16 = out_cmodel[tmp];
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == UINT8) {
        operators::print_bit_i8(out_cmodel[tmp]);
      }

      cout << "cmath out,";
      float64_t cmath64;
      data64.dou64 = out_cmath[tmp];
      cmath64.v = data64.ui64;
      if (o_type == FP16) {
        outCmath = f64_to_f16(cmath64);
        data16.ui16 = outCmath.v;
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == BF16) {
        outCmathTmp = f64_to_f32(cmath64);
        outCmath.v = operators::fp32_to_bf16(outCmathTmp.v);
        data16.ui16 = outCmath.v;
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == UINT8) {
        outCmathTmp = f64_to_f32(cmath64);
        outCmath.v = operators::f32_to_i8(outCmathTmp.v);
        operators::print_bit_i8(outCmath.v);
      }

      cout << "\n";
    }
  }
#endif
#if 0 // per group
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      cout << "i_row,j_col: " << i << "," << j << "\n";

      cout << "cmodel out,";
      if (o_type == FP16 || o_type == BF16) {
        data16.ui16 = out_cmodel[tmp];
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == FP8E4) {
        operators::print_bit_i8(out_cmodel_quant[tmp]);
      }

      cout << "cmath out,";
      float64_t cmath64;
      data64.dou64 = out_cmath[tmp];
      cmath64.v = data64.ui64;
      if (o_type == FP16) {
        outCmath = f64_to_f16(cmath64);
        data16.ui16 = outCmath.v;
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == BF16) {
        outCmathTmp = f64_to_f32(cmath64);
        outCmath.v = operators::fp32_to_bf16(outCmathTmp.v);
        data16.ui16 = outCmath.v;
        operators::print_hex_16_union_ui16_f16(data16);
      } else if (o_type == FP8E4) {
        outCmathTmp = f64_to_f32(cmath64);
        outCmath.v = operators::fp32_to_fp8e4(outCmathTmp.v);
        operators::print_bit_i8(outCmath.v);
      }

      cout << "\n";
    }
  }
#endif
#if 0 // for reduce argmax / top2
  //col = 2;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int tmp = i * col + j;
      cout << "i_row,j_col: " << i << "," << j << "\n";
      cout << "cmodel out,";
      cout << "out_cmodel32 = " << out_cmodel32[tmp] << ", \n";
      cout << "cmath out,";
      cout << "out_cmath = " << outIndexReduce[tmp] << ", \n";
    }
  }
#endif
#if 0 // for softmax fa2
    uint24_t *tmp24 = new uint24_t[1];
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < col; j++){
            int tmp = i * col + j;
            cout <<"i_row,j_col: " << i <<  "," << j <<"\n";
            cout << "cmodel out,";
            cout << "out_cmodel32 = " ;
            printUint24(out_cmodel24 + tmp, 1);
            cout << ", \n" ;

            cout << "cmath out,";
            cout << "outIndexReduce = ";
            union ui64_f64_print out_cmath64;
            out_cmath64.dou64 = out_cmath[tmp];
            tmp24[0]= operators::fp64_to_fp24(out_cmath64.ui64);
            printUint24(tmp24, 1);
            cout << ", \n" ;

        }
    }
#endif
#if 0 // for reduce add 
    col = 1;
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < col; j++){
            int tmp = i * col + j;
            cout <<"i_row,j_col: " << i <<  "," << j <<"\n";
            cout << "cmodel out,";
            cout << "out_cmodel = " <<std::hex <<  out_cmodel[tmp]  << ", \n";

            cout << "cmath out,";
            float32_t tmpData ;
            union ui64_f64_print data64;
            data64.dou64 = out_cmath[tmp];
            float64_t data_i64;
            data_i64.v = data64.ui64;
            tmpData.v = fp64_to_fp32(data_i64.v );
            cout << "outIndexReduce = " << std::hex << tmpData.v << ", \n";
        }
    }
#endif
#if 0 // for rope
    printf("=========rope quant============\n");
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < col; j++){
            int tmp = i * col + j;
            cout <<"i_row,j_col: " << i <<  "," << j <<"\n";
            o_type = FP8E4;     

            cout << "cmodel out rope,";
            if(o_type == FP16 || o_type == BF16){
                data16.ui16 = rope_quant_cmodel[tmp];
                operators::print_hex_16_union_ui16_f16(data16);
            }else if (o_type == FP8E4){
                operators::print_bit_i8(rope_quant_cmodel[tmp]);
            }

            cout << "cmath out,";
            float64_t cmath64;
            data64.dou64 = out_quant_rope_cmath[tmp];
            cmath64.v = data64.ui64;   
            if(o_type == FP16){
                outCmath = f64_to_f16(cmath64);
                data16.ui16 = outCmath.v;
                operators::print_hex_16_union_ui16_f16(data16);
            }else if(o_type == BF16){
                outCmathTmp = f64_to_f32(cmath64);
                outCmath.v = operators::fp32_to_bf16(outCmathTmp.v);          
                data16.ui16 = outCmath.v;
                operators::print_hex_16_union_ui16_f16(data16);
            }else if(o_type == FP8E4){
                outCmathTmp = f64_to_f32(cmath64);
                outCmath.v = operators::fp32_to_fp8e4(outCmathTmp.v);          
                operators::print_bit_i8(outCmath.v);               
            }
    
            cout << "\n";
        }
    }
#endif
  delete[] retAll;
  delete[] scaleBuffer;
  delete[] scaleBufferUint8;
  delete[] bias;
  delete[] gamma;
  delete[] input_cmath;
  delete[] out_cmath;
  delete[] input_cmodel;
  delete[] input_cmodel32;
  delete[] input_cmodel24;
  delete[] out_cmodel;
  delete[] rope_quant_cmodel;
  delete[] pre_sum_blk_output;
  delete[] pre_sum_blk_input;
  delete[] pre_max_input;
  delete[] pre_max_output;
  delete[] scaleBufferPerToken;
  delete[] scaleBufferPerTensor;
  delete[] outData;
  delete[] out_EMRFIFO;
  delete[] out_cmodel_quant;
  delete[] src_mask;
  delete[] inputB_cmodel;
  delete[] src_mask_cmodel;
  delete[] k_mean_cmodel;
  delete[] qCmodel;
  delete[] gamma_cmodel;
  delete[] bias_cmodel;
  delete[] outIndexReduce;
  delete[] out_cmodel32;
  delete[] out_cmodel24;
  delete[] inputB_cmath;
  delete[] q_cmath;
  delete[] mean;
  delete[] out_quant_rope_cmath;
}

/*========================================
Function: test softmax online
Information:Author is ZC, 2025/07/15. by qingyan
============================================*/
void test_add2(int row, int col, DataType i_type, DataType o_type) {
  /*========================================
   read data from txt.
   ============================================*/
#if 0
      std::string filename = "/workspace/cmodel/tests/vae_data_test.txt";
      std::vector<uint16_t> data_test_v;
      data_test_v = readDataFromTxt(filename);
#endif
  /*========================================
  test cmodel add2
  ============================================*/
#if 0
      float *testData = new float[col];
      /*========================================
      data from rand
      ============================================*/
#if 0
        int low = -5, high = 5;
        std::vector<float> randData;
        randData = oneDimMatrixRand(col, row, low, high);
        //data conversion
        uint16_t *test_data = new uint16_t[col];
        copyDataUint16(randData, test_data);
        float *test_data_tmp = new float[col];
        copyDataFloat(randData, test_data_tmp);
        //printUint16(test_data, col);
        for(int i = 0; i < col; i++){
          testData[i] = operators::ui16_to_float(test_data[i]);
          cout << testData[i] << "\n";
          if(i== 3)
          {
            break;
          }
        }
#endif 
        //printVectoFloat(randData,"0x");



      /*========================================
      read data from specific context.
      ============================================*/
#if 0
        for(int i = 0; i < col; i++)
        {
          testData[i] = 0.1;
        }
#endif 
      /*========================================
      test cmath of  add. 
      ============================================*/
#if 0
        float addRetCmath = operators::vae_cmath_add(testData, col);
        cout << "=====";
        printf("addRetCmath = %f ",addRetCmath);
        cout << "=====\n";
#endif
      /*========================================
      read data from specific context.
      ============================================*/
        
        float24_t *data24 = new float24_t[col];
        float16_t inputData, resultIdeal;
        inputData.v = 0x3800;
        resultIdeal.v = 0x4000;
#if 1
          for(int i = 0; i < col; i++){
            data24[i].v = operators::fp16_to_fp24(inputData.v);//operators::fp32_to_fp24(test_data_float[i]);0x0001,
            // operators::print_binary_uint32(data24[i].v);
          }
#endif   

        /*========================================
        test cmodel of  fp24add. 
        ============================================*/
#if 0
          float24_t data0,data1,ret;
          data0.v = 0x0040000;
          data1.v = 0x0000000;
          ret.v = fp24add(data0.v,data1.v);
          cout << "ret = ";
          operators::print_binary_uint32(ret.v);
#endif 
          /*========================================
        test cmodel of  add2. 
        ============================================*/
          int src_col = 4, paddingNumFlag = 0, paddingNum = 0;
          float24_t paddingValue;
          paddingValue.v = 0;
          float24_t dataRetCmodel = operators::add2(data24, src_col, paddingValue, paddingNumFlag, paddingNum);
          float16_t comparisonNum;
          comparisonNum.v = operators::fp24_to_fp16(dataRetCmodel.v);
          if(resultIdeal.v  == comparisonNum.v)
          {
            cout << "the function of add2 , comparing successful!\n";
          }
          delete[] data24;
          delete[] testData;
#endif
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
    size_t commaPos = input.find(':', start);
    cout << "0x" << std::hex << commaPos << "\n"; // for debug

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
std::vector<uint16_t> extractHexNumbersSimulator(const std::string &input) {
  std::vector<uint16_t> result;
  size_t start = 0;
  int flag = 0;
  // 查找下一个逗号或字符串结束
  size_t commaPos = 4; // input.find(':', start);
  // cout << "0x" << std::hex << commaPos << "\n"; //for debug
  start = 10;
  while (true) {
    // judge index is valid.
    if (start >= 0 && start < input.size()) {
      ;
    } else {
      break;
    }
    if (commaPos == std::string::npos) {
      commaPos = input.length();
    }
    flag++; // for debug
    // 提取子字符串
    std::string hexStr = input.substr(start, commaPos);
    // cout << std::hex << hexStr << "\n"; //for debug

    // 移除前导0x
    // if (hexStr.substr(0, 2) == "0x") {
    //     hexStr = hexStr.substr(2);
    // }
    // cout  << std::hex << hexStr << "\n"; //for debug
    // 转换为uint16
    uint16_t num = static_cast<uint16_t>(std::stoul(hexStr, nullptr, 16));
    result.push_back(num);
    // cout  << num << "\n"; //for debug
    // 更新起始位置
    start = start + commaPos + 1;
    // 检查是否结束
    if (commaPos == std::string::npos) {
      break;
    }
    if (flag == 8) {
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
  int flag = 0;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#')
      continue;
    num++;
    // string to uint16_t
    std::vector<uint16_t> numberUint16 = extractHexNumbersSimulator(line);
#if 0
        std::cout << line << "\n"; //for debug
        //std::cout << std::hex << numberUint16[5] <<"\n";
#endif
    for (const auto &elem : numberUint16) {
      result.push_back(elem);
    }
    // flag++;
    // if(flag == 2)  {
    //     break;
    // }
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
Function: print c data ,uint24
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printUint24(const uint24_t *data, int num) {
  for (int i = 0; i < num; i++) {
    printf("0x%x, ", data[i]);
  }
  printf("end \n");
}

/*========================================
Function: print c data ,uint16
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
void printUint16(const uint16_t *data, int num) {
  for (int i = 0; i < num; i++) {
    printf("0x%x ", data[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
  printf("end \n");
}

#endif // cmodel test end
double bf16_to_double(uint16_t val) {
  // 提取BF16的符号、指数和尾数
  uint16_t sign = val >> 15;
  uint16_t exponent = (val >> 7) & 0xFF;
  uint16_t mantissa = val & 0x7F;

  // 转换为Double的位表示
  uint64_t double_bits = ((uint64_t)sign << 63);
  if (exponent != 0) {
    // 调整指数偏移（BF16偏移127 → Double偏移1023）
    double_bits |= ((uint64_t)(exponent - 127 + 1023) << 52);
  }
  // 扩展尾数（BF16的7位 → Double的52位）
  double_bits |= ((uint64_t)mantissa << 45);

  // 通过内存重新解释转换为double
  return *(double *)&double_bits;
}