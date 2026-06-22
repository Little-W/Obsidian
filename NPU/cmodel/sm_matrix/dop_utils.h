#ifndef DOP_UTILS_H
#define DOP_UTILS_H

#include "dop_ops.h"
#include "internals.h"
#include "sm_data_struct.h"
#include "softfloat.h"
#include <cmath>   // C++ 标准库头文件
#include <cstdint> // C++ 标准库头文件
#include <cstdio>  // C++ 标准库头文件

// 命名空间 dop_utils
namespace operators {
// 通用数学方法

// 通用测试方法
void print_uint128(__uint128_t num);
void print_uint128_hex(__uint128_t num);
void print_binary_uint8(uint8_t num);
float fp16_to_float(uint16_t fp16);
void print_fp16_binary(uint16_t fp16);
void print_fp16(uint16_t fp16);
void print_binary_uint32(uint32_t num);
float32_t dot_product_fp16(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_bf16(uint16_t *array1, uint16_t *array2, int length);
float dot_product_fp16_fp16int4(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_bf16int4(uint16_t *array1, uint16_t *array2,
                               uint16_t *scale, int length);
float32_t dot_product_fp8e4(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_fp8e4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scaleA, uint16_t *scaleB, int length);
float32_t dot_product_bf16int4(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_bf16uint4(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_bf16mxfp4(uint16_t *array1, uint16_t *array2, int length);
float32_t dot_product_mxfp4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scale1, uint16_t *scale2, int length);
float32_t dot_product_nvfp4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scale1, uint16_t *scale2, int length);
int64_t dot_product_int16int4(uint16_t *array1, uint16_t *array2,
                              uint16_t shift_num, uint16_t b_scale,
                              size_t num_elements);
int64_t dot_product_int16int4_k(uint16_t *array1, uint16_t *array2,
                                uint16_t shift_num, uint16_t *b_scale,
                                size_t num_elements);

} // namespace operators

#endif // DOP_UTILS_H