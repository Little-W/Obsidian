#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define DEBUG_MODE 1
#define CONSTRAINT 1
#define COMPARE_MODE_U16 0
#define COMPARE_MODE_F32 1
#include "test_common_vae_neo.h"
#include "vae_common.h"
/*function: test mxfp4

*/
void float32_to_uint16(float *dataInput, uint16_t *outdata, DataType i_type,
                       uint32_t row, uint32_t col) {
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;

      if (i_type == FP16) {
        outdata[tmp] = float32_to_float16(dataInput[tmp]);
      } else if (i_type == BF16) {
        outdata[tmp] = float32_to_bfloat16(dataInput[tmp]);
      }
    }
  }
}

/*============================
function:get rand mask
==============================*/
uint16_t *fun_getMask(uint32_t row, uint32_t col) {
  uint32_t dataNum = row * col;
  uint16_t *src_mask = new uint16_t[dataNum];
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint32_t tmp = i * col + j;
      src_mask[tmp] = rand() % 2;
    }
  }
  return src_mask;
}
/*============================
function:get rand mask of lower triangle.
matirx dim : blok x row x col.
==============================*/
void fun_getMask_16x128x128(uint16_t *src_mask, uint32_t row, uint32_t col,
                            uint32_t blok) {
  uint32_t dataNum = row * col;
  for (uint32_t b = 0; b < blok; b++) {
    uint32_t mask1_num = 1;
    for (uint32_t i = 0; i < row; i++) {
      for (uint32_t j = 0; j < col; j++) {
        uint32_t tmp = i * col + j;
        if (j < mask1_num) {
          src_mask[tmp] = 1;
        } else {
          src_mask[tmp] = 0;
        }
      }
      mask1_num++;
    }
  }
}
/*========================================
Function: basic information juegment
Information:Author is ZC, 2025/09/08. by qingyan
============================================*/
void basicInfoJudg(const uint32_t row, const uint32_t col,
                   const DataType i_type, const DataType o_type,
                   const uint32_t function_number) {
#if defined(USE_EXTERN_C)
  if (row <= 0 || col <= 0) {
    throw std::invalid_argument(
        "Matrix dimensions must be positive (row > 0 && col > 0).");
  }
  if (i_type != FP16 && i_type != BF16) {
    throw std::invalid_argument("i_type must be FP16 or BF16!");
  }
  if (o_type != FP16 && o_type != BF16 && o_type != UINT8 && o_type != FP8E4) {
    throw std::invalid_argument("o_type must be FP16 or BF16!");
  }
#endif
}
/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_reduce_top2(const uint32_t row, const uint32_t col,
                              const DataType i_type, const DataType o_type,
                              const uint32_t function_number,
                              const int64_t seed) {
  basicInfoJudg(row, col, i_type, o_type, function_number);
  // 1). generate uint16_t input data
  uint16_t *cmodel_in_uint16_t = new uint16_t[row * col];
  generate_matrix_uint16_t(cmodel_in_uint16_t, row, col, seed, i_type, o_type);

  // 2). generate uint16_t cmodel output data by 1)'s input
  uint16_t *cmodel_out_uint16_t = new uint16_t[row * col];
  uint32_t *out_cmodel32 = new uint32_t[row * col];
  uint32_t *retAll = new uint32_t[row * col];

  operators::reduce_top2(out_cmodel32, retAll, cmodel_in_uint16_t,
                         cmodel_out_uint16_t, row, col, i_type, o_type, 128);
#if 0
  printf("===========2. cmodel output=============\n");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as hex", BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as float", BF16, "float");
  printf("========================================\n");
#endif

  // 3). generate fp32 cmath input data from 1)
  float *cmath_in_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmath_in_float32, cmodel_in_uint16_t, row, col,
                               i_type);

  // 4). generate fp32 cmath output data
  float *cmath_outData_float32 = new float[row * col];
  int *cmath_outData_index = new int[row * col];

  operators::reduce_cmath_top2_fp32(cmath_in_float32, cmath_outData_float32,
                                    cmath_outData_index, row, col);
#if 0
  print_float32_matrix_with_mode(cmath_out_float32, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif

  float tolerance = 0.005f;
#if COMPARE_MODE_U16
  compare_uint16_t_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                          o_type, tolerance);
#endif

#if 0
  compare_float32_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                         o_type, tolerance);
#endif
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < 2; j++) {
      int tmp = i * col + j;
      cout << "i_row,j_col: " << i << "," << j << "\n";
      cout << "cmodel out,";
      cout << "out_cmodel32 = " << out_cmodel32[tmp] << ", \n";
      cout << "cmath out,";
      cout << "out_cmath = " << cmath_outData_index[tmp] << ", \n";
    }
  }
  delete[] cmodel_in_uint16_t;
  delete[] cmodel_out_uint16_t;
  delete[] cmath_in_float32;
  delete[] cmath_outData_float32;
  delete[] cmath_outData_index;
  delete[] out_cmodel32;
  delete[] retAll;
}
/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_laynorm(const uint32_t row, const uint32_t col,
                          const DataType i_type, const DataType o_type,
                          const uint32_t function_number, const int64_t seed) {
  basicInfoJudg(row, col, i_type, o_type, function_number);
  // 1). generate uint16_t input data
  uint16_t *cmodel_in_uint16_t = new uint16_t[row * col];
  generate_matrix_uint16_t(cmodel_in_uint16_t, row, col, seed, i_type, o_type);

  // 2). generate uint16_t cmodel output data by 1)'s input
  uint16_t *cmodel_out_uint16_t = new uint16_t[row * col];
  generate_output_layernorm_cmodel_uint16_t(
      cmodel_out_uint16_t, cmodel_in_uint16_t, row, col, i_type, o_type);
#if defined(USE_EXTERN_C)
  printf("===========2. cmodel output=============\n");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as hex", BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as float", BF16, "float");
  printf("========================================\n");
#endif

  // 3). generate fp32 cmath input data from 1)
  float *cmath_in_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmath_in_float32, cmodel_in_uint16_t, row, col,
                               i_type);

  // 4). generate fp32 cmath output data
  float *cmath_out_float32 = new float[row * col];
  float *cmath_gamma_float32 = new float[col];
  float *cmath_bias_float32 = new float[col];
  float eps = 1e-6;
  int flag_bias_gamma = 0;
  layernorm_fp32_no_wel(cmath_out_float32, cmath_in_float32,
                        cmath_gamma_float32, eps, cmath_bias_float32, col, row,
                        flag_bias_gamma);

#if DEBUG_MODE
  print_float32_matrix_with_mode(cmath_out_float32, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif

  float tolerance = 0.005f;
#if COMPARE_MODE_U16
  compare_uint16_t_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                          o_type, tolerance);
#endif

#if COMPARE_MODE_F32
  compare_float32_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                         o_type, tolerance);
#endif

  delete[] cmodel_in_uint16_t;
  delete[] cmodel_out_uint16_t;
  delete[] cmath_in_float32;
  delete[] cmath_out_float32;
  delete[] cmath_gamma_float32;
  delete[] cmath_bias_float32;
}
// cal cmodel of softmax online
uint16_t *cal_cmodel_softmaxOnline(uint16_t *out_cmodel,
                                   const uint16_t *input_cmodel,
                                   const uint16_t *src_mask, const uint32_t row,
                                   const uint32_t col, const DataType i_type,
                                   const DataType o_type, uint32_t scaleFlag,
                                   float16_t scale_softmax, uint32_t maskFlag,
                                   float16_t mask_value0_cmodel) {
  uint32_t blockStep = 128;
  uint32_t dataNum = row * col;
  float24_t paddingValue;
  paddingValue.v = 0;
  operators::vae_softmax_online(
      out_cmodel, input_cmodel, src_mask, row, col, i_type, o_type, blockStep,
      paddingValue, scaleFlag, scale_softmax, maskFlag, mask_value0_cmodel);
}
/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_softmaxOnline(const uint32_t row, const uint32_t col,
                                const DataType i_type, const DataType o_type,
                                const uint32_t function_number,
                                const int64_t seed, uint32_t scaleFlag,
                                uint32_t maskFlag, uint32_t layer) {
  basicInfoJudg(row, col, i_type, o_type, function_number);
  // 1). generate uint16_t input data
  uint16_t *cmodel_in_uint16_t = new uint16_t[row * col];
  generate_matrix_uint16_t(cmodel_in_uint16_t, row, col, seed, i_type, o_type);

  // 2). generate uint16_t cmodel output data by 1)'s input
  uint16_t *cmodel_out_uint16_t = new uint16_t[row * col];
  uint32_t dataNum = row * col * layer;
  uint16_t *src_mask = new uint16_t[dataNum];
  fun_getMask_16x128x128(src_mask, row, col, layer);

  float16_t scale_softmax, mask_value0_cmodel;
  if (i_type == FP16) {
    scale_softmax.v = 0x3ff8; // 1.5
    mask_value0_cmodel.v = 0xfc00;

  } else if (i_type == BF16) {
    scale_softmax.v = 0x3fc0; // 1.5
    mask_value0_cmodel.v = 0xff80;
  }
  cal_cmodel_softmaxOnline(cmodel_out_uint16_t, cmodel_in_uint16_t, src_mask,
                           row, col, i_type, o_type, scaleFlag, scale_softmax,
                           maskFlag, mask_value0_cmodel);
#if 0 // defined(USE_EXTERN_C)
  printf("===========2. cmodel output=============\n");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as hex", BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as float", BF16, "float");
  printf("========================================\n");
#endif

  // 3). generate fp32 cmath input data from 1)
  float *cmath_in_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmath_in_float32, cmodel_in_uint16_t, row, col,
                               i_type);
  float *scale_softmax_cmath = new float[1];
  get_f32_matrix_from_uint16_t(scale_softmax_cmath, &scale_softmax.v, 1, 1,
                               i_type);
  float *mask_value0_cmath = new float[1];
  get_f32_matrix_from_uint16_t(mask_value0_cmath, &mask_value0_cmodel.v, 1, 1,
                               i_type);
  // 4). generate fp32 cmath output data
  float *cmath_out_float32 = new float[dataNum];
  operators::softmax_online_float(cmath_out_float32, cmath_in_float32, col, row,
                                  scale_softmax_cmath[0], scaleFlag, maskFlag,
                                  src_mask, mask_value0_cmath[0]);
#if 0
  print_float32_matrix_with_mode(cmath_out_float32, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif

  float tolerance = 0.0001f;
#if 1
  compare_uint16_t_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                          o_type, tolerance);
#endif

#if 0
  compare_float32_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                         o_type, tolerance);
#endif

  delete[] cmodel_in_uint16_t;
  delete[] cmodel_out_uint16_t;
  delete[] cmath_in_float32;
  delete[] cmath_out_float32;
  delete[] scale_softmax_cmath;
  delete[] mask_value0_cmath;
  delete[] src_mask;
}
/*========================================
Function: get mean para of dimk_rec,dimk_mod128_rec_dimk, dimk_mod128_rec
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void getMeanPara(uint32_t row, uint32_t col, int blockStep, uint32_t *dimk_rec,
                 uint32_t *dimk_mod128_rec_dimk, float24_t *dimk_mod128_rec) {
  float32_t rcp_col, blockStepTmp, colTmp;
  blockStepTmp = i32_to_f32(blockStep);
  colTmp = i32_to_f32(col);
  rcp_col.v = operators::sfu_rcp(blockStepTmp.v);
  float32_t rec_blockStep;
  rec_blockStep.v = operators::sfu_rcp(blockStepTmp.v);
  uint32_t rec_col = operators::sfu_rcp(colTmp.v);
  dimk_rec[0] = rec_col;
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
  dimk_mod128_rec[0].v = operators::fp32_to_fp24(rec_lastBlock.v);
  dimk_mod128_rec_dimk[0] =
      operators::fp32mul(rec_lastBlockTmp.v, rec_col_rms.v);
}
/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_reduce_mean(const uint32_t row, const uint32_t col,
                              const DataType i_type, const DataType o_type,
                              const uint32_t function_number,
                              const int64_t seed, uint32_t scaleFlag,
                              uint32_t maskFlag) {
  basicInfoJudg(row, col, i_type, o_type, function_number);
  float tolerance = 0.0001f;

  uint16_t *goldenData = new uint16_t[row * col];
  uint32_t dataNum = row * col;
  std::string filename = "input.bin";
  goldenData = readDataFromBin(filename, row, col);
#if 0
  print_uint16_t_matrix_with_mode(goldenData, row, col,
                                  "golden BF16 input as hex", BF16, "hex");
#endif
  float *goldenF32 = new float[row * col];
  float *cmathOutf32 = new float[row * 1];

  get_f32_matrix_from_uint16_t(goldenF32, goldenData, row, col, i_type);
  operators::reduce_mean_float(goldenF32, cmathOutf32, row, col);
  uint16_t *cmathOutF16 = new uint16_t[row * col];
  generate_uint16_t_matrix_from_float32(cmathOutF16, cmathOutf32, row, 1,
                                        o_type);
#if 0
  print_uint16_t_matrix_with_mode(cmathOutF16, row, 1,
                                  "golden BF16 input as hex", BF16, "hex");
#endif
  uint16_t *out_cmodel = new uint16_t[row * 1];
  int blockStep = 128;
  uint32_t dimk_rec, dimk_mod128_rec_dimk;
  float24_t paddingValue, dimk_mod128_rec;
  paddingValue.v = 0;
  getMeanPara(row, col, blockStep, &dimk_rec, &dimk_mod128_rec_dimk,
              &dimk_mod128_rec);

  operators::reduce_avg_mean(out_cmodel, goldenData, row, col, i_type, o_type,
                             blockStep, paddingValue, dimk_rec,
                             dimk_mod128_rec_dimk, dimk_mod128_rec);
#if 1
  compare_uint16(out_cmodel, cmathOutF16, row, 1, o_type, tolerance);
#endif
  delete[] goldenData;
  delete[] goldenF32;
  delete[] cmathOutf32;
  delete[] cmathOutF16;
  delete[] out_cmodel;
}
void fun_test_reduce_add32_160x2112(const uint32_t row, const uint32_t col,
                                    const DataType i_type,
                                    const DataType o_type,
                                    const uint32_t function_number,
                                    const int64_t seed, uint32_t scaleFlag,
                                    uint32_t maskFlag) {
  // 1). generate uint16_t input data
  uint32_t dataNum = row * col;
  uint16_t *cmodel_in_uint16 = new uint16_t[row * col];
  std::string filename = "input.bin";
  cmodel_in_uint16 = readDataFromBin(filename, row, col);
#if 0
    print_uint16_swap_matrix_with_mode(cmodel_in_uint16, row, col,
                                    "cmodel BF16 input as hex", BF16, "hex");
#endif
  int col1 = 2064;
  uint16_t *cmodel_in_uint16_no_padding = new uint16_t[row * col1];
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col1; j++) {
      int tmp = i * col + j;
      int tmp1 = i * col1 + j;
      cmodel_in_uint16_no_padding[tmp1] = cmodel_in_uint16[tmp];
    }
  }
#if 0
    print_uint16_swap_matrix_with_mode(cmodel_in_uint16_no_padding, row, col,
                                    "cmodel BF16 input as hex", BF16, "hex");
#endif
  uint16_t *out_cmodel = new uint16_t[row * col1];
  int blockStep;
  float24_t paddingValue;
  paddingValue.v = 0;
  operators::reduce_add32(out_cmodel, cmodel_in_uint16_no_padding, row, col1,
                          i_type, o_type, blockStep, paddingValue);
  int blockStep32 = 32;
  int col_add32 =
      (col1 + (blockStep32 - (col % blockStep32)) % blockStep32) / blockStep32;
#if 1
  print_uint16_swap_matrix_with_mode(out_cmodel, row, col1,
                                     "cmodel BF16 input as hex", BF16, "hex");
#endif
  float *cmath_in_float = new float[row * col1];
  float *outData_cmath = new float[row * col1];

  get_f32_matrix_from_uint16_t(cmath_in_float, cmodel_in_uint16, row, col1,
                               i_type);
  operators::reduce_cmath_add32_fp32(cmath_in_float, outData_cmath, row, col1);
#if 0
  print_float32_matrix_with_mode(outData_cmath, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif
  uint16_t *outdata_cmath_uint16 = new uint16_t[row * col1];

  float32_to_uint16(outData_cmath, outdata_cmath_uint16, BF16, row, col1);
#if 0
  print_uint16_swap_matrix_with_mode(outdata_cmath_uint16, row, col1,
                                  "cmodel BF16 input as hex", BF16, "hex");
#endif
  delete[] cmodel_in_uint16;
  delete[] out_cmodel;
  delete[] cmath_in_float;
  delete[] outData_cmath;
  delete[] outdata_cmath_uint16;
}

/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_softmaxOnline_17x17(const uint32_t row, const uint32_t col,
                                      const DataType i_type,
                                      const DataType o_type,
                                      const uint32_t function_number,
                                      const int64_t seed, uint32_t scaleFlag,
                                      uint32_t maskFlag) {
  basicInfoJudg(row, col, i_type, o_type, function_number);

  // 1). generate uint16_t input data
  uint32_t dataNum = row * 64;
  uint16_t *cmodel_in_uint16_t_Tmp = new uint16_t[row * 64];
  std::string filename = "input.bin";
  cmodel_in_uint16_t_Tmp = readDataFromBin(filename, row, col);
#if 1
  print_uint16_t_matrix_with_mode(cmodel_in_uint16_t_Tmp, row, 64,
                                  "cmodel BF16 input as hex", BF16, "hex");
#endif
  uint16_t *cmodel_in_uint16_t = new uint16_t[row * col];
  for (uint32_t k = 0; k < row; k++) {
    for (uint32_t j = 0; j < col; j++) {
      uint32_t inIndex = k * col + j;
      uint32_t tmpIndex = k * 64 + j;
      cmodel_in_uint16_t[inIndex] = cmodel_in_uint16_t_Tmp[tmpIndex];
    }
  }
#if 1
  print_uint16_t_matrix_with_mode(cmodel_in_uint16_t, row, col,
                                  "cmodel BF16 input as hex", BF16, "hex");
#endif
  // 2). generate uint16_t cmodel output data by 1)'s input
  uint16_t *cmodel_out_uint16_t = new uint16_t[dataNum];
  uint16_t *src_mask = new uint16_t[row * col];
  fun_getMask_16x128x128(src_mask, row, col, 1);
#if 1
  print_uint16_t_matrix_with_mode(src_mask, row, col,
                                  "cmodel BF16 input as hex", BF16, "hex");
#endif
  float16_t scale_softmax, mask_value0_cmodel;
  mask_value0_cmodel.v = 0;
  if (i_type == FP16) {
    scale_softmax.v = 0x3ff8; // 1.5
    mask_value0_cmodel.v = 0xfc00;
  } else if (i_type == BF16) {
    scale_softmax.v = 0x3e78; // 1.5
    mask_value0_cmodel.v = 0xff80;
  }
  cal_cmodel_softmaxOnline(cmodel_out_uint16_t, cmodel_in_uint16_t, src_mask,
                           row, col, i_type, o_type, scaleFlag, scale_softmax,
                           maskFlag, mask_value0_cmodel);
#if 0 // defined(USE_EXTERN_C)
  printf("===========2. cmodel output=============\n");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as hex", BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as float", BF16, "float");
  printf("========================================\n");
#endif

  // 3). generate fp32 cmath input data from 1)
  float *cmath_in_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmath_in_float32, cmodel_in_uint16_t, row, col,
                               i_type);
  float *scale_softmax_cmath = new float[1];
  get_f32_matrix_from_uint16_t(scale_softmax_cmath, &scale_softmax.v, 1, 1,
                               i_type);
  float *mask_value0_cmath = new float[1];
  get_f32_matrix_from_uint16_t(mask_value0_cmath, &mask_value0_cmodel.v, 1, 1,
                               i_type);
  // 4). generate fp32 cmath output data
  float *cmath_out_float32 = new float[dataNum];
  operators::softmax_online_float(cmath_out_float32, cmath_in_float32, col, row,
                                  scale_softmax_cmath[0], scaleFlag, maskFlag,
                                  src_mask, mask_value0_cmath[0]);
#if 0
  print_float32_matrix_with_mode(cmath_out_float32, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif

  float tolerance = 0.01f;

#if 0
  compare_uint16_t_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                          o_type, tolerance);
#endif
  uint16_t *goldenTmp = new uint16_t[row * 64];
  std::string filename_gloden = "bf16_softmax_golden.bin";
  goldenTmp = readDataFromBin(filename_gloden, row, col);
  uint16_t *golden = new uint16_t[row * col];
  for (uint32_t k = 0; k < row; k++) {
    for (uint32_t j = 0; j < col; j++) {
      uint32_t inIndex = k * col + j;
      uint32_t tmpIndex = k * 64 + j;
      golden[inIndex] = goldenTmp[tmpIndex];
    }
  }
#if 0
 compare_uint16(cmodel_out_uint16_t,
                             golden, row,
                            col, o_type,
                             tolerance);
#endif
#if 1
  compare_uint16_t_result(golden, cmath_out_float32, row, col, o_type,
                          tolerance);
#endif
  delete[] cmodel_in_uint16_t;
  delete[] cmodel_out_uint16_t;
  delete[] cmath_in_float32;
  delete[] cmath_out_float32;
  delete[] scale_softmax_cmath;
  delete[] mask_value0_cmath;
  delete[] src_mask;
}
/*========================================
Function: vae test framework neo
Information:Author is ZC, 2025/09/08. by riyo
============================================*/
void fun_test_vae_softmaxOnline_simulator(
    const uint32_t row, const uint32_t col, const DataType i_type,
    const DataType o_type, const uint32_t function_number, const int64_t seed,
    uint32_t scaleFlag, uint32_t maskFlag) {
  basicInfoJudg(row, col, i_type, o_type, function_number);
  // 1). generate uint16_t input data
  uint32_t dataNum = row * col;
  uint16_t *cmodel_in_uint16_t = new uint16_t[dataNum];

  std::string filename = "Q_KT_Sout.bin";
  cmodel_in_uint16_t = readDataFromBin(filename, row, col);
  //  print_uint16_t_matrix_with_mode(cmodel_in_uint16_t, row, col,
  //                                  "cmodel BF16 output as hex", BF16, "hex");
  // 2). generate uint16_t cmodel output data by 1)'s input
  uint16_t *cmodel_out_uint16_t = new uint16_t[dataNum];
  uint16_t *src_mask = new uint16_t[dataNum];
  src_mask = fun_getMask(row, col);
  float16_t scale_softmax, mask_value0_cmodel;
  mask_value0_cmodel.v = 0;
  if (i_type == FP16) {
    scale_softmax.v = 0x3ff8; // 1.5
  } else if (i_type == BF16) {
    scale_softmax.v = 0x3DB5; // 1.5
  }
  cal_cmodel_softmaxOnline(cmodel_out_uint16_t, cmodel_in_uint16_t, src_mask,
                           row, col, i_type, o_type, scaleFlag, scale_softmax,
                           maskFlag, mask_value0_cmodel);
#if 0 // defined(USE_EXTERN_C)
  printf("===========2. cmodel output=============\n");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as hex", BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col,
                                  "cmodel BF16 output as float", BF16, "float");
  printf("========================================\n");
#endif

  // 3). generate fp32 cmath input data from 1)
  float *cmath_in_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmath_in_float32, cmodel_in_uint16_t, row, col,
                               i_type);
  float *scale_softmax_cmath = new float[1];
  get_f32_matrix_from_uint16_t(scale_softmax_cmath, &scale_softmax.v, 1, 1,
                               i_type);
  float *mask_value0_cmath = new float[1];
  get_f32_matrix_from_uint16_t(mask_value0_cmath, &mask_value0_cmodel.v, 1, 1,
                               i_type);
  // 4). generate fp32 cmath output data
  float *cmath_out_float32 = new float[dataNum];
  operators::softmax_online_float(cmath_out_float32, cmath_in_float32, col, row,
                                  scale_softmax_cmath[0], scaleFlag, maskFlag,
                                  src_mask, mask_value0_cmath[0]);
#if 0
  print_float32_matrix_with_mode(cmath_out_float32, row, col,
                                 "cmath float32 output as float", i_type,
                                 "float");
#endif

  float tolerance = 0.01f;

#if 1
  uint16_t *golden_out_uint16_t = new uint16_t[row * col];
  uint16_t *cmodel_out_uint16_t_A = new uint16_t[row * col];
  std::string filename1 = "Q_KT_matmul_output_16_128_128_bf16.bin";
  golden_out_uint16_t = readDataFromBin(filename1, row, col);
  get_f32_matrix_from_uint16_t(cmath_out_float32, golden_out_uint16_t, row, col,
                               i_type);
  operators::softmax_online_float(cmath_out_float32, cmath_in_float32, col, row,
                                  scale_softmax_cmath[0], scaleFlag, maskFlag,
                                  src_mask, mask_value0_cmath[0]);
#endif
#if 0
  compare_uint16_t_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                          o_type, tolerance);
#endif
#if 0
 compare_uint16(cmodel_out_uint16_t,
                             cmodel_out_uint16_t_A, row,
                            col, o_type,
                             tolerance);
#endif
#if 1
  uint16_t *golden_out_uint16_t_B = new uint16_t[row * col];
  std::string filename2 = "softmax_output_16_128_128_bf16.bin";
  golden_out_uint16_t_B = readDataFromBin(filename2, row, col);

#endif
#if 1
  uint16_t *cmodel_in_uint16_t_oneRow = new uint16_t[128];
  uint16_t *cmodel_out_uint16_t_oneRow = new uint16_t[128];

  uint16_t *golden_in_uint16_t_oneRow = new uint16_t[128];

  uint32_t dataStart = 47752 - 8;
  for (uint32_t k = 0; k < 128; k++) {
    cmodel_in_uint16_t_oneRow[k] = cmodel_in_uint16_t[dataStart];
    dataStart++;
  }
  dataStart = 47752 - 8;
  for (uint32_t k = 0; k < 128; k++) {
    golden_in_uint16_t_oneRow[k] = golden_out_uint16_t_B[dataStart];
    dataStart++;
  }
  dataStart = 47752 - 8;

  print_uint16_t_matrix_with_mode(cmodel_in_uint16_t_oneRow, 1, 128,
                                  "Q_K_T_sout:", BF16, "hex");
  print_uint16_t_matrix_with_mode(golden_in_uint16_t_oneRow, 1, 128,
                                  "golden output", BF16, "hex");
  uint16_t *mask = new uint16_t[128];
  uint32_t num = 118;
  for (uint32_t k = 0; k < 128; k++) {
    if (k < num) {
      mask[k] = 1;
    } else {
      mask[k] = 0;
    }
  }
  cal_cmodel_softmaxOnline(
      cmodel_out_uint16_t_oneRow, cmodel_in_uint16_t_oneRow, mask, 1, 128,
      i_type, o_type, scaleFlag, scale_softmax, maskFlag, mask_value0_cmodel);
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t_oneRow, 1, 128,
                                  "cmodel output", BF16, "hex");
  compare_uint16(cmodel_out_uint16_t_oneRow, golden_in_uint16_t_oneRow, 1, 128,
                 o_type, tolerance);
#endif
#if 0
deleteTxtFileCmodel();
  char nodeName[100];
  char opName[100] = "softmax";
  uint16_t data2txt_uint16;
      strcpy(nodeName, "cmodel");
for (uint32_t k = 0; k <dataNum; k++){
      data2txt_uint16 = cmodel_out_uint16_t[k];
      printfNodeData16bitCmodel(data2txt_uint16, nodeName, opName,k);

}
      strcpy(nodeName, "golen");
for (uint32_t k = 0; k <dataNum; k++){
      data2txt_uint16 = golden_out_uint16_t[k];
      printfNodeData16bitCmodel(data2txt_uint16, nodeName, opName, k);
}

#endif
#if 0
  compare_float32_result(cmodel_out_uint16_t, cmath_out_float32, row, col,
                         o_type, tolerance);
#endif
  delete[] cmodel_in_uint16_t_oneRow;
  delete[] golden_in_uint16_t_oneRow;
  delete[] cmodel_in_uint16_t;
  delete[] cmodel_out_uint16_t;
  delete[] cmath_in_float32;
  delete[] cmath_out_float32;
  delete[] scale_softmax_cmath;
  delete[] mask_value0_cmath;
  delete[] golden_out_uint16_t;
  delete[] cmodel_out_uint16_t_A;
  delete[] mask;
}
/*========================================
Function: generate uint16_t random input by seed
Information:Author is ZC, 2025/09/03. by riyo
input:
  row, col, seed
output:
  a uint16_t matrix
============================================*/
uint16_t *generate_matrix_uint16_t(uint16_t *uint16_t_matrix,
                                   const uint32_t row, const uint32_t col,
                                   const int64_t seed, const DataType i_type,
                                   const DataType o_type) {
  uint64_t data_num = row * col;
  for (uint32_t i = 0; i < row; i++) {
    uint32_t state = static_cast<uint32_t>(seed);
    for (int j = 0; j < col; j++) {
      state ^= state << 13;
      state ^= state >> 17;
      state ^= state << 5;
      float random_value =
          (static_cast<float>(state >> 9) * (1.0f / 8388608.0f)) + i * 0.001f;
      uint32_t float_bits;
      memcpy(&float_bits, &random_value, sizeof(float));
      uint16_t_matrix[i * col + j] = static_cast<uint16_t>(float_bits >> 16);
    }
  }

#if 0 // defined(USE_EXTERN_C)
  printf("dataNum = %ld, row = %d, col = %d\n", data_num, row, col);
  printf("===========1. cmodel input==============\n");

#if 0 // printf hex
  if(i_type == BF16 || i_type == FP16){
    print_uint16_t_matrix_with_mode(uint16_t_matrix, row, col,
                                  "cmodel uint16_t input as hex", BF16, "hex");
  }
#endif

#if 0
  if(i_type == BF16){
    print_uint16_t_matrix_with_mode(uint16_t_matrix, row, col,
                                  "cmodel BF16 input as float", BF16, "float");
  }
  if(i_type == FP16)[
    print_uint16_t_matrix_with_mode(uint16_t_matrix, row, col,
                                  "cmodel FP16 input as float", FP16, "float");
  ]

#endif
  printf("========================================\n");
#endif
}

/*========================================
Function: convert cmodel bf16/fp16 input into cmath fp32 input
Information:Author is ZC, 2025/09/03. by riyo
input:
  a uint16_t_matrix, row, col, type
output:
  a fp32 matrix
============================================*/
void get_f32_matrix_from_uint16_t(float *cmath_in_float32,
                                  const uint16_t *cmath_in_uint16_t,
                                  const uint32_t row, const uint32_t col,
                                  const DataType type) {
#if defined(USE_EXTERN_C)
  if (cmath_in_uint16_t == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
#endif
  uint64_t data_num = row * col;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint64_t idx = i * col + j;
      if (type == BF16) {
        cmath_in_float32[idx] = bfloat16_to_float32(cmath_in_uint16_t[idx]);
      } else if (type == FP16) {
        cmath_in_float32[idx] = float16_to_float32(cmath_in_uint16_t[idx]);
      }
    }
  }
#if 0 // defined(USE_EXTERN_C)
  printf("========================================\n");
  print_float32_matrix_with_mode(cmath_in_float32, row, col,
                                 "cmath float32 input as float", type, "float");
  printf("========================================\n");
#endif
}

/*========================================
Function: convert fp32 matrix into bf16/fp16 matrix
Information:Author is ZC, 2025/09/03. by riyo
input:
  a float matrix, row, col, type(BF16/FP16)
output:
  a bf16/fp16 matrix
============================================*/
void generate_uint16_t_matrix_from_float32(uint16_t *cmath_out_uint16_t,
                                           const float *cmath_out_float32,
                                           const uint32_t row,
                                           const uint32_t col,
                                           const DataType type) {
#if defined(USE_EXTERN_C)
  if (cmath_out_float32 == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
#endif

  uint64_t data_num = row * col;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint64_t idx = i * col + j;
      if (type == BF16) {
        cmath_out_uint16_t[idx] = float32_to_bfloat16(cmath_out_float32[idx]);
      } else if (type == FP16) {
        cmath_out_uint16_t[idx] = float32_to_float16(cmath_out_float32[idx]);
      }
    }
  }
#if 0 // defined(USE_EXTERN_C)
  printf("========================================\n");
  print_uint16_t_matrix_with_mode(cmath_out_uint16_t, row, col,
                                  "cmath BF16 output as hex", type, "hex");
  print_uint16_t_matrix_with_mode(cmath_out_uint16_t, row, col,
                                  "cmath BF16 output as float", type, "float");
  printf("========================================\n");
#endif
}

/*========================================
Function: convert bf16 to fp32
Information:Author is ZC, 2025/09/03. by riyo
input:
  a uint16_t_val value (bf16)
output:
  a fp32 value
============================================*/
float bfloat16_to_float32(const uint16_t uint16_t_val) {
  uint32_t sign = (uint16_t_val >> 15) & 1;
  uint32_t exponent = (uint16_t_val >> 7) & 0xFF;
  uint32_t fraction = uint16_t_val & 0x7F;

  if (exponent == 0) {
    if (fraction == 0)
      return sign ? -0.0f : 0.0f;
    float mantissa = fraction / 128.0f;
    uint32_t f = (sign << 31) | ((-126 + 127) << 23) |
                 ((uint32_t)(mantissa * 8388608.0f) & 0x7FFFFF);
    return *(float *)&f;
  } else if (exponent == 0xFF) {
    uint32_t f = (sign << 31) | 0x7F800000 | (fraction ? 0x400000 : 0);
    return *(float *)&f;
  }

  int exp = exponent - 127 + 127;
  float mantissa = 1.0f + fraction / 128.0f;
  uint32_t mantissa_bits = (uint32_t)((mantissa - 1.0f) * 8388608.0f);

  uint32_t result_bits = (sign << 31) | (exp << 23) | mantissa_bits;
  return *(float *)&result_bits;
}

/*========================================
Function: convert fp32 to bf16
Information:Author is ZC, 2025/09/03. by riyo
input:
  a fp32 value
output:
  a uint16_t_val value (bf16)
============================================*/
uint16_t float32_to_bfloat16(const float fp32_val) {
  uint32_t *p = (uint32_t *)&fp32_val;
  uint32_t bits = *p;
  uint16_t bf16 = (bits >> 16) & 0xFFFF;
  uint16_t fraction = bits & 0xFFFF;
  if (fraction > 0x8000 || (fraction == 0x8000 && (bf16 & 1))) {
    bf16 += 1;
  }
  return bf16;
}

/*========================================
Function: convert fp16 to fp32
Information:Author is ZC, 2025/09/03. by riyo
input:
  a uint16_t_val value (fp16)
output:
  a fp32 value
============================================*/
float float16_to_float32(const uint16_t uint16_t_val) {
  uint32_t sign = (uint16_t_val >> 15) & 1;
  uint32_t exponent = (uint16_t_val >> 10) & 0x1F;
  uint32_t fraction = uint16_t_val & 0x3FF;

  if (exponent == 0) {
    if (fraction == 0)
      return sign ? -0.0f : 0.0f;
    float mantissa = fraction / 1024.0f;
    uint32_t f = (sign << 31) | ((-14 + 127) << 23) |
                 ((uint32_t)(mantissa * 8388608.0f) & 0x7FFFFF);
    return *(float *)&f;
  } else if (exponent == 31) {
    uint32_t f = (sign << 31) | 0x7F800000 | (fraction ? 0x400000 : 0);
    return *(float *)&f;
  }

  int exp = exponent - 15 + 127;
  float mantissa = 1.0f + fraction / 1024.0f;
  uint32_t mantissa_bits = (uint32_t)((mantissa - 1.0f) * 8388608.0f);

  uint32_t result_bits = (sign << 31) | (exp << 23) | mantissa_bits;
  return *(float *)&result_bits;
}

/*========================================
Function: convert fp32 to fp16
Information:Author is ZC, 2025/09/03. by riyo
input:
  a fp32 value
output:
  a uint16_t_val value (fp16)
============================================*/
uint16_t float32_to_float16(const float fp32_val) {
  union {
    float f32;
    uint32_t u32;
  } converter;
  converter.f32 = fp32_val;
  uint32_t bits = converter.u32;

  uint32_t sign = (bits >> 31) & 0x1;
  uint32_t exp = (bits >> 23) & 0xFF;
  uint32_t mantissa = bits & 0x7FFFFF;

  uint16_t fp16_exp, fp16_mantissa;
  if (exp == 0 && mantissa == 0) {
    fp16_exp = 0;
    fp16_mantissa = 0;
  } else if (exp == 0xFF) {
    fp16_exp = 0x1F;
    fp16_mantissa = mantissa >> 13;
  } else {
    int32_t new_exp = exp - 127 + 15;
    if (new_exp >= 31) {
      fp16_exp = 0x1F;
      fp16_mantissa = 0;
    } else if (new_exp <= 0) {
      if (new_exp >= -10) {
        fp16_exp = 0;
        fp16_mantissa = (mantissa | 0x800000) >> (1 - new_exp + 13);
      } else {
        fp16_exp = 0;
        fp16_mantissa = 0;
      }
    } else {
      fp16_exp = new_exp;
      fp16_mantissa = mantissa >> 13;
    }
  }
  return (sign << 15) | (fp16_exp << 10) | (fp16_mantissa & 0x3FF);
}
uint16_t swap_hex_bytes(uint16_t num) {
  uint8_t high_byte = (num >> 8) & 0xFF;
  uint8_t low_byte = num & 0xFF;
  return (low_byte << 8) | high_byte;
}
void print_uint16_swap_matrix_with_mode(const uint16_t *uint16_t_matrix,
                                        const uint32_t row, const uint32_t col,
                                        const char *message,
                                        const DataType type,
                                        const char *output_format) {
#if defined(USE_EXTERN_C)
  if (uint16_t_matrix == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
  if (output_format != "hex" && output_format != "float") {
    throw std::invalid_argument("output_format must be hex or float!");
  }
#endif

  printf("%s\n", message);
  for (uint32_t i = 0; i < row; ++i) {
    for (uint32_t j = 0; j < col; ++j) {
      uint64_t idx = i * col + j;
      if (output_format == "hex") {
        uint16_t swapped = swap_hex_bytes(uint16_t_matrix[idx]);
        printf("%0*x ", 4, swapped);
      } else if (output_format == "float") {
        if (type == BF16) {
          printf("%f ", bfloat16_to_float32(uint16_t_matrix[idx]));
        } else if (type == FP16) {
          printf("%f ", float16_to_float32(uint16_t_matrix[idx]));
        }
      }
      if ((j + 1) % 8 == 0) {
        printf("\n");
      }
      // if ((i + 1) % 8 == 0) {
      //   printf("\n");
      // }
    }
  }
}
/*========================================
Function: print matrix as hex or float
Information:Author is ZC, 2025/09/03. by riyo
input:
  a uint16_t_matrix matrix, row, col, i_type(BF16/FP16),
output_format("hex"/"float"), message output: print as hex or float
============================================*/
void print_uint16_t_matrix_with_mode(const uint16_t *uint16_t_matrix,
                                     const uint32_t row, const uint32_t col,
                                     const char *message, const DataType type,
                                     const char *output_format) {
#if defined(USE_EXTERN_C)
  if (uint16_t_matrix == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
  if (output_format != "hex" && output_format != "float") {
    throw std::invalid_argument("output_format must be hex or float!");
  }
#endif

  printf("%s\n", message);
  for (uint32_t i = 0; i < row; ++i) {
    for (uint32_t j = 0; j < col; ++j) {
      uint64_t idx = i * col + j;
      if (output_format == "hex") {
        printf("%0*x ", 4, uint16_t_matrix[idx]);
      } else if (output_format == "float") {
        if (type == BF16) {
          printf("%f ", bfloat16_to_float32(uint16_t_matrix[idx]));
        } else if (type == FP16) {
          printf("%f ", float16_to_float32(uint16_t_matrix[idx]));
        }
      }
      if ((j + 1) % 8 == 0) {
        printf("\n");
      }
      if ((i + 1) % 8 == 0) {
        printf("\n");
      }
    }
  }
}

/*========================================
Function: print cmath fp32 matrix
Information:Author is ZC, 2025/09/03. by riyo
input:
  a float matrix, row, col, type(BF16/FP16), output_format("hex"/"float"),
message output: print as hex or float
============================================*/
void print_float32_matrix_with_mode(const float *float32_matrix,
                                    const uint32_t row, const uint32_t col,
                                    const char *message, const DataType type,
                                    const char *output_format) {
#if defined(USE_EXTERN_C)
  if (float32_matrix == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
  if (output_format != "hex" && output_format != "float") {
    throw std::invalid_argument("output_format must be hex or float!");
  }
#endif

  printf("%s\n", message);
  for (uint32_t i = 0; i < row; ++i) {
    for (uint32_t j = 0; j < col; ++j) {
      uint64_t idx = i * col + j;
      if (output_format == "float") {
        printf("%f ", float32_matrix[idx]);
      } else if (output_format == "hex") {
        if (type == BF16) {
          printf("%x ", float32_to_bfloat16(float32_matrix[idx]));
        } else if (type == FP16) {
          printf("%x ", float32_to_float16(float32_matrix[idx]));
        }
      }
    }
    printf("\n");
  }
}
void compare_uint16(const uint16_t *cmodel_out_uint16_t,
                    const uint16_t *golden_out_uint16_t, const uint32_t row,
                    const uint32_t col, const DataType o_type,
                    const float tolerance) {
  int count = 0;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint64_t idx = i * col + j;
      float n;
      if (o_type == BF16) {
        n = fabsf(bfloat16_to_float32(cmodel_out_uint16_t[idx]) -
                  bfloat16_to_float32(golden_out_uint16_t[idx]));
      } else if (o_type == FP16) {
        n = fabsf(float16_to_float32(cmodel_out_uint16_t[idx]) -
                  float16_to_float32(golden_out_uint16_t[idx]));
      }
      if (n > tolerance) {
        printf("the position is not the same: i: %d, j: %d, diff: %f, "
               "cmath: 0x%x, golden: 0x%x\n",
               i, j, n, cmodel_out_uint16_t[idx], golden_out_uint16_t[idx]);
        count++;
        // printf("\n");
      }
    }
  }

  if (count == 0) {
    printf("all results are the same!\n");
  }
}
/*========================================
Function: COMPARE_MODE_U16 result
Information:Author is ZC, 2025/09/03. by riyo
input:
  cmodel_out_uint16_t, cmath_out_float32, row, col, o_type, tolerance
output:
  print difference
============================================*/
void compare_uint16_t_result(const uint16_t *cmodel_out_uint16_t,
                             const float *cmath_out_float32, const uint32_t row,
                             const uint32_t col, const DataType o_type,
                             const float tolerance) {
#if defined(USE_EXTERN_C)
  if (cmodel_out_uint16_t == NULL || cmath_out_float32 == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
  if (tolerance < 0) {
    throw std::invalid_argument("tolerance must be non-negative!");
  }
#endif
  uint16_t *cmath = new uint16_t[row * col];
  generate_uint16_t_matrix_from_float32(cmath, cmath_out_float32, row, col,
                                        o_type);
#if 0
  print_uint16_t_matrix_with_mode(cmath, row, col, "cmath BF16 output as hex",
                                  BF16, "hex");
  print_uint16_t_matrix_with_mode(cmodel_out_uint16_t, row, col, "golden", BF16,
                                  "hex");
#endif

  compare_uint16(cmath, cmodel_out_uint16_t, row, col, o_type, tolerance);
  delete[] cmath;
}

/*========================================
Function: COMPARE_MODE_F32 result
Information:Author is ZC, 2025/09/03. by riyo
input:
  cmodel_out_uint16_t, cmath_out_float32, row, col, o_type, tolerance
output:
  print difference
============================================*/
void compare_float32_result(const uint16_t *cmodel_out_uint16_t,
                            const float *cmath_out_float32, const uint32_t row,
                            const uint32_t col, const DataType o_type,
                            const float tolerance) {
#if defined(USE_EXTERN_C)
  if (cmodel_out_uint16_t == NULL || cmath_out_float32 == NULL) {
    throw std::invalid_argument("Matrix pointer is null!");
  }
  if (tolerance < 0) {
    throw std::invalid_argument("tolerance must be non-negative!");
  }
#endif
  float *cmodel_out_float32 = new float[row * col];
  get_f32_matrix_from_uint16_t(cmodel_out_float32, cmodel_out_uint16_t, row,
                               col, o_type);

  int count = 0;
  for (uint32_t i = 0; i < row; i++) {
    for (uint32_t j = 0; j < col; j++) {
      uint64_t idx = i * col + j;
      float n = fabsf(cmodel_out_float32[idx] - cmath_out_float32[idx]);
      if (n > tolerance) {
        printf("the position is not the same: i: %d, j: %d, diff: %f, "
               "cmodel_out: 0x%X\n",
               i, j, n, cmodel_out_uint16_t[idx]);
        count++;
      }
      // printf("\n");
    }
  }
  if (count == 0) {
    printf("all results are the same!\n");
  }

  delete[] cmodel_out_float32;
}

// only support no bias & no gamma，bf16
void generate_output_layernorm_cmodel_uint16_t(
    uint16_t *out_cmodel, const uint16_t *input_cmodel, const uint32_t row,
    const uint32_t col, const DataType i_type, const DataType o_type) {

  int flag_bias_gamma = 0; // uint32_t?

  uint16_t *gamma_cmodel = new uint16_t[row * col];
  uint16_t *bias_cmodel = new uint16_t[row * col];
  const int block_step = 128;

  float24_t padding_value;
  padding_value.v = 0;

  union ui64_f64_print eps64;
  eps64.dou64 = 1e-6;
  float64_t eps64_tmp;
  float32_t eps32;
  eps64_tmp.v = eps64.ui64;
  eps32 = f64_to_f32(eps64_tmp);

  uint32_t rec_last_block_num = ((col - 1) % block_step) + 1;
  float32_t rec_last_block_tmp;
  rec_last_block_tmp = i32_to_f32(rec_last_block_num);
  float32_t rec_last_block;
  rec_last_block.v = operators::sfu_rcp(rec_last_block_tmp.v);

  float32_t col_tmp = i32_to_f32(col);
  uint32_t rec_col = operators::sfu_rcp(col_tmp.v);
  float32_t rec_col_rms;
  rec_col_rms.v = operators::sfu_rcp(col_tmp.v);
  uint32_t dimk_mod128_rec_dimk =
      operators::fp32mul(rec_last_block_tmp.v, rec_col_rms.v);
  float24_t dimk_mod128_rec;
  dimk_mod128_rec.v = operators::fp32_to_fp24(rec_last_block.v);

  uint16_t *cmodelInput = new uint16_t[row * col];
  uint32_t dataNum = row * col;
  std::string filename = "input.bin";
  cmodelInput = readDataFromBin(filename, row, col);
#if 0
  print_uint16_t_matrix_with_mode(goldenData, row, col,
                                  "golden BF16 input as hex", BF16, "hex");
#endif

  operators::vae_layernorm(out_cmodel, input_cmodel, gamma_cmodel, bias_cmodel,
                           row, col, i_type, o_type, block_step, rec_col,
                           dimk_mod128_rec_dimk, dimk_mod128_rec, eps32.v,
                           padding_value, flag_bias_gamma);

  delete[] gamma_cmodel;
  delete[] bias_cmodel;
}

/*========================================
Function: simple fp32 layernorm
Information:Author is ZC, 2025/09/03 ,by riyo.
============================================*/
void layernorm_fp32_no_wel(float *out_data, const float *input_data,
                           const float *gamma, float eps, const float *bias,
                           uint32_t col, uint32_t row, int flag_bias_gamma) {
  if (col == 0 || row == 0) {
    throw std::invalid_argument("col and row cannot be 0!");
  }
  if (flag_bias_gamma != 0 && flag_bias_gamma != 1) {
    throw std::invalid_argument("flag_bias_gamma should be 0 or 1!");
  }
  if (!out_data || !input_data) {
    throw std::invalid_argument("input_data or out_data null ptr!");
  }
  if (flag_bias_gamma == 1) {
    if (!gamma || !bias) {
      throw std::invalid_argument("gamma or bias null ptr!");
    }
  }

  for (uint32_t i = 0; i < row; i++) {
    uint64_t base_index = static_cast<uint64_t>(i) * col;

    double row_sum = 0.0f;
    for (uint32_t j = 0; j < col; j++) {
      row_sum += input_data[base_index + j];
    }
    double row_mean = row_sum / col;

    double var_sum = 0.0f;
    for (uint32_t j = 0; j < col; j++) {
      double diff = input_data[base_index + j] - row_mean;
      var_sum += diff * diff;
    }
    double var = var_sum / col;
    double inv_std = 1.0f / sqrtf(var + eps);

    for (uint32_t j = 0; j < col; j++) {
      double normalized = (input_data[base_index + j] - row_mean) * inv_std;
      if (flag_bias_gamma) {
        out_data[base_index + j] =
            static_cast<float>(gamma[j] * normalized + bias[j]);
      } else {
        out_data[base_index + j] = static_cast<float>(normalized);
      }
    }
  }
}

/*========================================
Function: read data from a bin file,
Information:Author is ZC, 2025/07/14. by qingyan
============================================*/
uint16_t *readDataFromBin(std::string filename, uint32_t row, uint32_t col) {
  std::string line;
  int num = 0;
  // 打开二进制文件
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
  }
  // 获取文件大小
  std::streamsize size = file.tellg();
  // file.clear();
  file.seekg(0, std::ios::beg);
  std::cout << "File size: " << size << " bytes\n";
  // 读取文件内容
  std::vector<char> buffer(size);
  if (!file.read(buffer.data(), size)) {
    std::cerr << "Error reading file" << std::endl;
  }
  uint32_t dataNum = size / 2;
  uint16_t *result = new uint16_t[dataNum];
  // uint16_t num = static_cast<uint16_t>(std::stoul(hexStr, nullptr, 16));

  // 按字节解析并输出十六进制和二进制表示
  uint32_t index = 0;
  for (int i = 0; i < size; i += 2) {
    unsigned char byte0 = static_cast<unsigned char>(buffer[i]);
    unsigned char byte1 = static_cast<unsigned char>(buffer[i + 1]);
    result[index] =
        (static_cast<uint16_t>(byte1) << 8) + (static_cast<uint16_t>(byte0));
    // result[index] = (static_cast<uint16_t>(byte0) << 8 ) +
    // (static_cast<uint16_t>(byte1) );

    index++;
    // 输出十六进制
    // std::cout  << "0x" << std::hex << static_cast<int>(byte0);
  }
  // operators::printUint16(result, dataNum);

  file.close();
  return result;
}
/*
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
}
*/

void printfNodeData16bitCmodel(const uint16_t data, char *nodeName,
                               char *opName, uint32_t k) {
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
  fprintf(file, " %0*x ", width, data);
  if ((k + 1) % 8 == 0) {
    fprintf(file, "\n");
  }
  fclose(file);
}

/**/
int deleteTxtFileCmodel() {
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