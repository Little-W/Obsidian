#ifndef _vae_common_h
#define _vae_common_h

#include "internals.h"
#include "matrix_struct.h"
#include "sm_datatype_utils.h"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

#define TEST_FOR_DE_DV 0 // test of DE and DV

union ui64_f64_print {
  uint64_t ui64;
  double dou64;
};

union ui32_f32_print {
  uint32_t ui32;
  float f32;
};

union ui16_f16_print {
  uint16_t ui16;
  short int i16;
};

namespace operators {

#if defined(USE_EXTERN_C)

//=============================
void quant_group_mxfp4_cmath(uint16_t *inputData, uint8_t *outData,
                             uint8_t *outScale, uint32_t row, uint32_t col,
                             DataType i_type);
void reduce_cmath_add32_fp32(float *inputData, float *outData, uint32_t row,
                             uint32_t col);
void reduce_cmath_top2_fp32(float *inputData, float *outData, int *outIndex,
                            uint32_t row, uint32_t col);
float vae_cmath_add(const float *src_data, int dataNum);
void softmax_online_double(double *out, double *input, int col, int row,
                           double scale_softmax_cmath, int sacleFalg,
                           int maskFlag, const uint16_t *src_mask,
                           double mask_value0);
void softmax_online_float(float *out, float *input, uint32_t col, uint32_t row,
                          float scale_softmax_cmath, uint32_t sacleFalg,
                          uint32_t maskFlag, const uint16_t *src_mask,
                          float mask_value0);
void softmax_fa1(double *out, double *input, int col, int row,
                 double scale_softmax_cmath, int scaleFlag, int maskFlag,
                 const uint16_t *src_mask, double mask_value0, int byPassFlag,
                 double *out_rope, double factor);
void softmax_fa2_cmath(double *inputExp, double *OSRAM, double *inputAdd,
                       double *outData, int row, int col);
void softmax_fa3_cmath(double *inputReduce, double *inputOSRAM, double *outData,
                       int row, int col);

void rmsnorm_cmath_double(double *outData, const double *inputData,
                          const double *gamma, int col, int row, double eps);
void elementwise_cmath(const double *inputDataA, const double *inputDataB,
                       double *outData, int row, int col, int model);

void layernorm_double_welford_cmath(double *outData, const double *inputData,
                                    const double *gamma, double eps,
                                    const double *bias, int col, int row,
                                    int blockStep, int flagBiasGamma);
void layernorm_double_no_wel(double *outData, const double *inputData,
                             const double *gamma, double eps,
                             const double *bias, int col, int row,
                             int blockStep, int flagBiasGamma);
void mask_cmath(double *outData, const double *inputData,
                const uint16_t *src_mask, int row, int col, double mask_value0);
void mask_cmath_float(float *outData, const float *inputData,
                      const uint16_t *src_mask, uint32_t row, uint32_t col,
                      float mask_value0);
void quantization(double *inputData, double *outData, double factor, int model,
                  int row, int col, const double *mean);
void quantizationPerToken(double *inputData, double *outData, double factor,
                          int model, int row, int col, const double *mean,
                          uint32_t kMeanBypass);
void quantizationPerTensorCmath(double *inputData, double *outData,
                                double factor, int model, int row, int col,
                                const double *mean, uint32_t kMeanBypass);
void quantizationPerGroup(double *inputData, double *outData, double factor,
                          int model, int row, int col);
void quantizationNVPFP4(float *inputData, float *outData, float *outScale,
                        float factor, int model, int row, int col);
void rope_cmath(double *inputData, double *q_cmath, int row, int col,
                double *out_rope, double *out_quant_rope, double paddingValue,
                double factor, const double *mean, int byPassFlag);
void print_mt_double(MATRIX_2D<double> &mt);
void reduce_cmath(double *inputData, double *outData, int *outIndex, int row,
                  int col, char *model);
void reduce_mean_float(float *inputData, float *outData, int row, int col);
std::vector<uint16_t> extractHexNumbers(const std::string &input);
std::vector<uint16_t> readDataFromTxt(std::string filename);
std::vector<float> oneDimMatrixRand(int col, int row, int low, int high);
void printVectorUint16(std::vector<uint16_t> data, std::string format);
void printVectoFloat(std::vector<float> data, std::string format);
void copyDataUint16(std::vector<float> inputData, uint16_t *outData);
void copyDataFloat(std::vector<float> inputData, float *outData);
void printFloat(const float *data, int num);
void printUint24(const uint24_t *data, int num);
void printUint16(const uint16_t *data, int num);

void printBinaryUint64(const uint64_t num);
void printHexUint64(const uint64_t num);

void print_hex_64(const uint64_t num);
void printMatrixDataUint64OneData(uint64_t data);
void printMatrixDataUint64(const double *data, int col, int row);

void print_hex_64_union_ui64_dou64(const union ui64_f64_print num);
void print_hex_32_union_ui32_f32(const union ui32_f32_print num);
void print_hex_16_union_ui16_f16(const union ui16_f16_print num);
void print_hex_16_union_ui16_f16_input_float16_t(const float16_t datatIn);
void print_hex_16_input_float16_t_value(const float16_t datatIn,
                                        const char *str);
void print_hex_32_input_float32_t_value(const float32_t datatIn,
                                        const char *str);
void print_bit_i8(const char num);

int random_range_int(int min, int max);
//=============================

// cmath double calulation for self-test
void rmsnorm_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src,
                    double gamma = 1.0, double eps = 1e-6);
void layernorm_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src,
                      double gamma = 1.0, double eps = 1e-6, double beta = 0);
void layernorm_double_welford(MATRIX_2D<double> &out, MATRIX_2D<double> &src,
                              double gamma = 1.0, double eps = 1e-6,
                              double beta = 0);
void rope_rotation_matrix(MATRIX_2D<double> &out, int pos, int size = 4096,
                          double base = 10000);
void rope_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src,
                 bool flag = true);
void rope_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src1,
                 MATRIX_2D<double> &src2);

void softmax_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src);
// void softmax_online_double(MATRIX_2D<double> &out, MATRIX_2D<double> &src);

#endif
void funNANChangeToMaxOrMin(uint16_t *data, DataType type);

void funNANChangeToMaxOrMinFP24(uint24_t *data);

float16_t f16abs(float16_t a);

uint32_t **rope_rotation_matrix(int seqlen = 4096, int dims = 128,
                                DataType otype = FP32,
                                bool save_to_file = true);
void vae_pertensorInt16(uint16_t *outData, uint16_t *src_data, uint24_t scale,
                        uint32_t src_row, uint32_t src_col, DataType i_type,
                        DataType o_type);
void vae_softmax_online(uint16_t *softmax_result, const uint16_t *src_data,
                        const uint16_t *src_mask, uint32_t src_row,
                        uint32_t src_col, DataType i_type, DataType o_type,
                        uint32_t blockStep, float24_t paddingValue,
                        uint32_t scaleFlag, float16_t scale, uint32_t maskFlag,
                        float16_t mask_value0);

void vae_softmax_fa1(uint16_t *softmax_result, const uint16_t *src_data,
                     const uint16_t *src_mask, int maskFlag,
                     float16_t mask_value0, int src_row, int src_col,
                     DataType i_type, DataType o_type, int bypassQuant,
                     int blockStep, float24_t paddingValue,
                     uint8_t *quant_outResult, int scaleFlag, float16_t scale,
                     uint16_t *out_EMRFIFO, uint32_t *pre_sum_blk_input,
                     uint32_t *pre_sum_blk_output, uint16_t *pre_max_input,
                     uint16_t *pre_max_output, uint16_t *scaleBuffer,
                     float16_t scaleFactor);
void softmax_fa2(uint24_t *ObufferOut, const uint16_t *src_data,
                 const uint24_t *Obuffer, const uint16_t *pv, int src_col,
                 int src_row, int blockStep, int o_type, int i_type);

void softmax_fa3(uint16_t *result, const uint32_t *diag,
                 const uint24_t *Obuffer, int src_col, int src_row,
                 int blockStep, int o_type, int i_type);
void vae_quant_perToken(uint8_t *oBuffer, uint16_t *src_data, uint16_t *kMean,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type, DataType o_type,
                        uint32_t kMeanBypass);
void vae_quant_perTensor(uint8_t *oBuffer, uint16_t *src_data,
                         uint16_t *scaleBuffer, int src_row, int src_col,
                         float16_t scaleFactor, DataType i_type,
                         DataType o_type);
void vae_quant_perGroup(uint8_t *oBuffer, uint16_t *src_data,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type,
                        DataType o_type);
void vae_quant_perGroup_mxfp4_mxfp8(uint8_t *oBuffer, uint16_t *src_data,
                                    uint8_t *scaleBuffer, int src_row,
                                    int src_col, DataType i_type,
                                    DataType o_type, uint16_t mxfp4_fp8_flag);
void vae_quant_NVFP4(uint8_t *oBuffer, uint16_t *src_data, uint8_t *scaleBuffer,
                     int src_row, int src_col, uint32_t globalScale,
                     DataType i_type, DataType o_type);
void vae_perToken_k(uint8_t *result, const uint16_t *src_data,
                    uint16_t *ret_scale, uint16_t *k_mean, int src_row,
                    int src_col, float16_t scaleFactor, DataType i_type,
                    DataType o_type);

void vae_quant(uint8_t *result, uint16_t *src_data, uint16_t *ret_scale,
               int src_row, int src_col, float16_t scaleFactor, DataType i_type,
               DataType o_type);

float24_t add2(float24_t *src_data, int src_col, float24_t paddingValue);

void matrixMulPointQuantization(const uint16_t *src_data, float32_t point,
                                uint8_t *outData, int src_row, int src_col,
                                DataType i_type, DataType o_type);

int maxPowerOfTwo(int n);

uint16_t maxValue(const uint16_t *inputData, int dataNum, DataType i_type,
                  int absFlag);
uint16_t minValue(const uint16_t *inputData, int dataNum, DataType i_type,
                  int absFlag);
uint16_t maxValue_argmax(const uint16_t *inputData, uint32_t *ret_index,
                         int dataNum, DataType i_type, int absFlag);

void vae_rmsnorm(uint16_t *rms_result, const uint16_t *src_data,
                 const uint16_t *src_gamma, int src_row, int src_col,
                 DataType i_type, DataType o_type, uint32_t eps,
                 float24_t padding_value, int blockStep, float32_t rcp_col,
                 int flagGamma);

void vae_layernorm(uint16_t *laynorm_result, const uint16_t *src_data,
                   const uint16_t *gamma, const uint16_t *bias, int src_row,
                   int src_col, DataType i_type, DataType o_type, int blockStep,
                   uint32_t dimk_rec, uint32_t dimk_mod128_rec_dimk,
                   float24_t dimk_mod128_rec, uint32_t eps,
                   float24_t paddingVlaue, int flagBiasGamma);

void rope(uint16_t *rope_outResult, const uint16_t *src_data, const uint16_t *q,
          uint16_t *k_mean, int src_row, int src_col, int blockStep,
          DataType i_type, DataType o_type, float24_t padding_value,
          float16_t scaleFactor, uint8_t *quant_outResult, int byPassFlag,
          uint16_t *ret_scale);

void vae_elementwise(uint16_t *result, const uint16_t *src_dataA,
                     const uint16_t *src_dataB, int row, int col,
                     DataType i_type, DataType o_type, int model);

void vae_mask(uint16_t *result, const uint16_t *src_data,
              const uint16_t *src_mask, int row, int col,
              float16_t mask_value0);

void reduce_max(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step);

void reduce_min(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step);

void reduce_argmax(uint32_t *ret, const uint16_t *src_data, int src_row,
                   int src_col, DataType i_type, DataType o_type,
                   int blockStep);

void reduce_avg_mean(uint16_t *ret, const uint16_t *src_data, int src_row,
                     int src_col, DataType i_type, DataType o_type,
                     int blockStep, float24_t paddingValue, uint32_t dimk_rec,
                     uint32_t dimk_mod128_rec_dimk, float24_t dimk_mod128_rec);

void reduce_add(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int blockStep,
                float24_t paddingValue);

void reduce_add32(uint16_t *ret, const uint16_t *src_data, int src_row,
                  int src_col, DataType i_type, DataType o_type, int blockStep,
                  float24_t paddingValue);

void reduce_top2(uint32_t *ret, uint32_t *retAll, const uint16_t *src_data,
                 uint16_t *outData, int src_row, int src_col, DataType i_type,
                 DataType o_type, int blockStep);

#if TEST_FOR_DE_DV
void fun_test1_vae(int row, int col, DataType i_type, DataType o_type,
                   int functionNumber);
void printfNodeData16bit(const uint16_t data, char *nodeName, char *opName);
void printfNodeData32bit(const uint32_t data, char *nodeName, char *opName);
int deleteTxtFile();
void printfNodeData8bit(const uint8_t data, char *nodeName, char *opName);
void printfNodeData24bit(const uint24_t data, char *nodeName, char *opName);
FILE *printfOpenFile(char *nodeName, char *opName);
void printfcloseFile(FILE *file);
void printfData8bit(const uint8_t data, FILE *file);
void printfData16bit(const uint16_t data, FILE *file);
void printfData32bit(const uint32_t data, FILE *file);
void printfData24bit(const uint32_t data, FILE *file);
#endif

} // namespace operators

#endif