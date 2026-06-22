#ifndef TEST_COMMON_VAE_NEO_H
#define TEST_COMMON_VAE_NEO_H
#include "sm_datatype_utils.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdexcept>
#include <math.h>

#include "vae_common.h"
#include "sfu_sqrt_rcp.h"
#include "dop_ops.h"
void float32_to_uint16(float *dataInput, uint16_t *outdata, DataType i_type,
                       uint32_t row, uint32_t col);

uint16_t swap_hex_bytes(uint16_t num);
void print_uint16_swap_matrix_with_mode(const uint16_t *uint16_t_matrix,
                                        const uint32_t row, const uint32_t col,
                                        const char *message,
                                        const DataType type,
                                        const char *output_format);
void fun_test_vae_reduce_top2(const uint32_t row, const uint32_t col,
                              const DataType i_type, const DataType o_type,
                              const uint32_t function_number,
                              const int64_t seed);
void fun_test_reduce_add32_160x2112(const uint32_t row, const uint32_t col,
                                    const DataType i_type,
                                    const DataType o_type,
                                    const uint32_t function_number,
                                    const int64_t seed, uint32_t scaleFlag,
                                    uint32_t maskFlag);
void getMeanPara(uint32_t row, uint32_t col, int blockStep, uint32_t *dimk_rec,
                 uint32_t *dimk_mod128_rec_dimk, float24_t *dimk_mod128_rec);

uint16_t *cal_cmodel_softmaxOnline(uint16_t *out_cmodel,
                                   const uint16_t *input_cmodel,
                                   const uint16_t *src_mask, const uint32_t row,
                                   const uint32_t col, const DataType i_type,
                                   const DataType o_type, uint32_t scaleFlag,
                                   float16_t scale_softmax, uint32_t maskFlag,
                                   float16_t mask_value0_cmodel);
void fun_test_vae_reduce_mean(const uint32_t row, const uint32_t col,
                              const DataType i_type, const DataType o_type,
                              const uint32_t function_number,
                              const int64_t seed, uint32_t scaleFlag,
                              uint32_t maskFlag);
int deleteTxtFileCmodel();
void fun_getMask_16x128x128(uint16_t *src_mask, uint32_t row, uint32_t col,
                            uint32_t blok);

void printfNodeData16bitCmodel(const uint16_t data, char *nodeName,
                               char *opName, uint32_t k);

void compare_uint16(const uint16_t *cmodel_out_uint16_t,
                    const uint16_t *golden_out_uint16_t, const uint32_t row,
                    const uint32_t col, const DataType o_type,
                    const float tolerance);
void parseBinFile(const std::string &filePath);
uint16_t *readDataFromBin(std::string filename, uint32_t row, uint32_t col);
std::vector<uint16_t> extractHexNumSimulator(const std::string &input);
uint16_t *fun_getMask(uint32_t row, uint32_t col);
void fun_test_vae_laynorm(const uint32_t row, const uint32_t col,
                          const DataType i_type, const DataType o_type,
                          const uint32_t function_number, const int64_t seed);
void basicInfoJudg(const uint32_t row, const uint32_t col,
                   const DataType i_type, const DataType o_type,
                   const uint32_t function_number);
uint16_t *generate_matrix_uint16_t(uint16_t *uint16_t_matrix,
                                   const uint32_t row, const uint32_t col,
                                   const int64_t seed, const DataType i_type,
                                   const DataType o_type);
void get_f32_matrix_from_uint16_t(float *cmath_in_float32,
                                  const uint16_t *cmath_in_uint16_t,
                                  const uint32_t row, const uint32_t col,
                                  const DataType type);
void generate_uint16_t_matrix_from_float32(uint16_t *cmath_out_uint16_t,
                                           const float *cmath_out_float32,
                                           const uint32_t row,
                                           const uint32_t col,
                                           const DataType type);
void fun_test_vae_softmaxOnline(const uint32_t row, const uint32_t col,
                                const DataType i_type, const DataType o_type,
                                const uint32_t function_number,
                                const int64_t seed, uint32_t scaleFlag,
                                uint32_t maskFlag, uint32_t layer);
void fun_test_vae_softmaxOnline_simulator(
    const uint32_t row, const uint32_t col, const DataType i_type,
    const DataType o_type, const uint32_t function_number, const int64_t seed,
    uint32_t scaleFlag, uint32_t maskFlag);
void fun_test_vae_softmaxOnline_17x17(const uint32_t row, const uint32_t col,
                                      const DataType i_type,
                                      const DataType o_type,
                                      const uint32_t function_number,
                                      const int64_t seed, uint32_t scaleFlag,
                                      uint32_t maskFlag);
float bfloat16_to_float32(const uint16_t uint16_t_val);
float float16_to_float32(const uint16_t uint16_t_val);
uint16_t float32_to_bfloat16(const float fp32_val);
uint16_t float32_to_float16(const float fp32_val);

void compare_uint16_t_result(const uint16_t *cmodel_out_uint16_t,
                             const float *cmath_out_float32, const uint32_t row,
                             const uint32_t col, const DataType o_type,
                             const float tolerance);
void compare_float32_result(const uint16_t *cmodel_out_uint16_t,
                            const float *cmath_out_float32, const uint32_t row,
                            const uint32_t col, const DataType o_type,
                            const float tolerance);

void print_uint16_t_matrix_with_mode(const uint16_t *uint16_t_matrix,
                                     const uint32_t row, const uint32_t col,
                                     const char *message, const DataType type,
                                     const char *output_format);
void print_float32_matrix_with_mode(const float *float32_matrix,
                                    const uint32_t row, const uint32_t col,
                                    const char *message, const DataType type,
                                    const char *output_format);

void generate_output_layernorm_cmodel_uint16_t(
    uint16_t *out_cmodel, const uint16_t *input_cmodel, const uint32_t row,
    const uint32_t col, const DataType i_type, const DataType o_type);
void layernorm_fp32_no_wel(float *out_data, const float *input_data,
                           const float *gamma, float eps, const float *bias,
                           uint32_t col, uint32_t row, int flag_bias_gamma);
#endif