#ifndef DOP_UTILS_H
#define DOP_UTILS_H

#include "dop_ops.h"
#include "internals.h"
#include "sm_data_struct.h"
#include "softfloat.h"
#include <cmath>   // C++ 标准库头文件
#include <cstdint> // C++ 标准库头文件
#include <cstdio>  // C++ 标准库头文件

// 命名空间 dop_utils#include "dop_utils.h"
#include <cmath>    // C++ 标准库头文件
#include <cstdint>  // C++ 标准库头文件
#include <cstdio>   // C++ 标准库头文件
#include <iostream> // 用于输出

namespace operators {

// 打印 128 位无符号整数的十进制表示
void print_uint128(__uint128_t num) {
  if (num == 0) {
    std::putchar('0');
    return;
  }

  char buffer[40]; // 最多 39 位十进制数字
  int i = 0;

  // while (num) {
  //     buffer[i++] = '0' + (num % 10);
  //     num /= 10;
  // }

  // while (i--) std::putchar(buffer[i]); // 逆序输出
  // std::putchar('\n');
}

// 打印 128 位无符号整数的十六进制表示
void print_uint128_hex(__uint128_t num) {
  // 将 128 位数分解为高 64 位和低 64 位
  uint64_t high = static_cast<uint64_t>(num >> 64);
  uint64_t low = static_cast<uint64_t>(num & 0xFFFFFFFFFFFFFFFF);

  // 打印高 64 位和低 64 位
  std::printf("0x%016lX%016lX\n", high, low);
}

// 打印 8 位无符号整数的二进制表示
void print_binary_uint8(uint8_t num) {
  for (int i = 7; i >= 0; i--) {
    std::printf("%d", (num >> i) & 1);
  }
  std::printf("\n");
}

// 将 fp16 转换为 float
float fp16_to_float(uint16_t fp16) {
  // 提取符号位、指数位和尾数位
  uint16_t sign = (fp16 >> 15) & 0x1;
  uint16_t exp = (fp16 >> 10) & 0x1F;
  uint16_t frac = fp16 & 0x3FF;

  // 处理特殊情况
  if (exp == 0) {
    // 非规格化数
    if (frac == 0) {
      return (sign == 0) ? 0.0f : -0.0f; // 正零或负零
    } else {
      // 非规格化数转换为浮点数
      return (sign == 0 ? 1.0f : -1.0f) * static_cast<float>(frac) / (1 << 24);
    }
  } else if (exp == 0x1F) {
    // 无穷大或 NaN
    if (frac == 0) {
      return (sign == 0) ? INFINITY : -INFINITY; // 正无穷或负无穷
    } else {
      return NAN; // NaN
    }
  }

  // 规格化数
  float normalized = 1.0f + static_cast<float>(frac) / (1 << 10);
  int shift = static_cast<int>(exp) - 15;
  float exponent =
      (shift >= 0) ? (1.0f * (1 << shift)) : (1.0f / (1 << -shift));
  return (sign == 0 ? 1.0f : -1.0f) * normalized * exponent;
}

// 计算两个 fp16 向量的点积（结果 fp32）
float32_t dot_product_fp16(uint16_t *array1, uint16_t *array2, int length) {
  float64_t result;
  result.v = 0;
  float16_t temp_1;
  float16_t temp_2;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1.v = array1[i];
    temp_2.v = array2[i];
    float64_t val1 = f16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    float64_t val2 = f16_to_f64(temp_2); // 访问 float16_t 的 v 成员
    // 累加乘积
    result = f64_mulAdd(val1, val2, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_bf16(uint16_t *array1, uint16_t *array2, int length) {
  float64_t result;
  result.v = 0;
  bfloat16_t temp_1;
  bfloat16_t temp_2;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1.v = array1[i];
    temp_2.v = array2[i];
    float64_t val1 = bf16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    float64_t val2 = bf16_to_f64(temp_2); // 访问 float16_t 的 v 成员
    // 累加乘积
    result = f64_mulAdd(val1, val2, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_fp8e4(uint16_t *array1, uint16_t *array2, int length) {
  float64_t result;
  result.v = 0;
  float32_t temp_1;
  float32_t temp_2;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1.v = fp8e4_to_fp32(array1[i]);
    temp_2.v = fp8e4_to_fp32(array2[i]);
    float64_t val1 = f32_to_f64(temp_1); // 访问 float16_t 的 v 成员
    float64_t val2 = f32_to_f64(temp_2); // 访问 float16_t 的 v 成员
    // 累加乘积
    result = f64_mulAdd(val1, val2, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_bf16mxfp4(uint16_t *array1, uint16_t *array2,
                                int length) {
  float64_t result;
  result.v = 0;
  bfloat16_t temp_1;
  bfloat16_t temp_2;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1.v = array1[i];
    temp_2.v = array2[i];
    float64_t val1 = bf16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    float64_t val2 = bf16_to_f64(temp_2); // 访问 float16_t 的 v 成员
    // 累加乘积
    result = f64_mulAdd(val1, val2, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_mxfp4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scale1, uint16_t *scale2, int length) {
  fp_general_t result = 0;
  fp_general_t temp_1;
  fp_general_t temp_2;
  fp_general_t scale_temp1;
  fp_general_t scale_temp2;
  fp_general_t dp_res;
  float32_t fp32;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1 = nvfp4_to_f32(array1[i]);
    temp_2 = nvfp4_to_f32(array2[i]);
    if (!scale1) {
      scale_temp1 = 0x7f;
      scale_temp2 = 0x7f;
    } else {
      scale_temp1 = scale1[i / 32];
      scale_temp2 = scale2[i / 32];
      if (scale_temp1 == 0xff || scale_temp2 == 0xff) {
        fp32.v = defaultNANF32UI;
        return fp32;
      }
    }
    dp_res = fp32mul(temp_1, temp_2);
    dp_res =
        (uint64_t)fp32e8m0mul_resfp32(dp_res, scale_temp1, scale_temp2, true);
    // 累加乘积
    result = fp32add(dp_res, result);
    // result.v += f64_mul(val1, val2).v;
  }
  fp32.v = result;
  return fp32;
}

float32_t dot_product_nvfp4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scale1, uint16_t *scale2, int length) {
  float64_t result;
  result.v = 0;
  float64_t temp_1;
  float64_t temp_2;
  float64_t scale_temp1;
  float64_t scale_temp2;
  float64_t dp_res;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    temp_1.v = fp32_to_fp64(nvfp4_to_f32(array1[i]));
    temp_2.v = fp32_to_fp64(nvfp4_to_f32(array2[i]));
    if (!scale1) {
      scale_temp1.v = fp32_to_fp64(0x3f800000);
      scale_temp2.v = fp32_to_fp64(0x3f800000);
    } else {
      scale_temp1.v = fp32_to_fp64(fp8e4_to_fp32(scale1[i / 16]));
      scale_temp2.v = fp32_to_fp64(fp8e4_to_fp32(scale2[i / 16]));
    }
    dp_res = f64_mul(temp_1, temp_2);
    dp_res = f64_mul(dp_res, scale_temp1);
    dp_res = f64_mul(dp_res, scale_temp2);
    // 累加乘积
    result = f64_add(dp_res, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_fp8e4(uint16_t *array1, uint16_t *array2,
                            uint16_t *scaleA, uint16_t *scaleB, int length) {
  float64_t result;
  float64_t dp_temp;
  result.v = 0;
  float32_t temp_1;
  float32_t temp_2;
  bfloat16_t scaleA_temp;
  bfloat16_t scaleB_temp;
  size_t scale_k;
  float64_t val1;
  float64_t val2;
  float64_t scale_temp;
  for (int k = 0; k < length; k++) {
    // 将 fp16 转换为 fp32
    scale_k = k / 32;
    scaleA_temp.v = scaleA[scale_k];
    scaleB_temp.v = scaleB[scale_k];
    temp_1.v = fp8e4_to_fp32(array1[k]);
    temp_2.v = fp8e4_to_fp32(array2[k]);
    val1 = f32_to_f64(temp_1); // 访问 float16_t 的 v 成员
    val2 = f32_to_f64(temp_2); // 访问 float16_t 的 v 成员
    dp_temp = f64_mul(val1, val2);
    scale_temp = bf16_to_f64(scaleA_temp);
    dp_temp = f64_mul(dp_temp, scale_temp);
    scale_temp = bf16_to_f64(scaleB_temp);
    dp_temp = f64_mul(dp_temp, scale_temp);
    // 累加乘积
    result = f64_add(dp_temp, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_bf16int4(uint16_t *array1, uint16_t *array2,
                               uint16_t *scale, int length) {
  float64_t result;
  float64_t dp_temp;
  result.v = 0;
  bfloat16_t temp_1;
  bfloat16_t temp_2;
  bfloat16_t scale_temp;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    size_t scale_k = i / 32;
    scale_temp.v = scale[scale_k];
    temp_1.v = array1[i];
    float64_t val1 = bf16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    fp_general_t b_bf16 = int4_to_f64(array2[i]);
    temp_2.v = b_bf16;
    float64_t val2 = bf16_to_f64(temp_2); // 访问 float16_t 的 v 成员
    float64_t val3 = bf16_to_f64(scale_temp);
    dp_temp = f64_mul(val1, val2);
    dp_temp = f64_mul(dp_temp, val3);
    // 累加乘积
    result = f64_add(dp_temp, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_bf16int4(uint16_t *array1, uint16_t *array2, int length) {
  float64_t result;
  float64_t dp_temp;
  result.v = 0;
  bfloat16_t temp_1;
  float64_t temp_2;
  for (int i = 0; i < length; i++) {
    temp_1.v = array1[i];
    float64_t val1 = bf16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    fp_general_t b_f64 = int4_to_f64(array2[i]);
    temp_2.v = b_f64;
    dp_temp = f64_mul(val1, temp_2);
    // 累加乘积
    result = f64_add(dp_temp, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float32_t dot_product_bf16uint4(uint16_t *array1, uint16_t *array2,
                                int length) {
  float64_t result;
  float64_t dp_temp;
  result.v = 0;
  bfloat16_t temp_1;
  float64_t temp_2;
  for (int i = 0; i < length; i++) {
    temp_1.v = array1[i];
    float64_t val1 = bf16_to_f64(temp_1); // 访问 float16_t 的 v 成员
    fp_general_t b_f64 = uint4_to_f64(array2[i]);
    temp_2.v = b_f64;
    dp_temp = f64_mul(val1, temp_2);
    // 累加乘积
    result = f64_add(dp_temp, result);
    // result.v += f64_mul(val1, val2).v;
  }
  float32_t fp32 = f64_to_f32(result);
  return fp32;
}

float dot_product_fp16_fp16int4(uint16_t *array1, uint16_t *array2,
                                int length) {
  float result = 0.0f;
  for (int i = 0; i < length; i++) {
    // 将 fp16 转换为 fp32
    float val1 = fp16_to_float(array1[i]); // 访问 float16_t 的 v 成员
    int val2 = array2[i];                  // 访问 float16_t 的 v 成员
    // 累加乘积
    result += val1 * val2;
  }
  return result;
}

int64_t dot_product_int16int4(uint16_t *array1, uint16_t *array2,
                              uint16_t shift_num, uint16_t b_scale,
                              size_t num_elements) {
  int64_t result = 0;
  int64_t temp_a;
  int64_t temp_b;
  int64_t temp_scale;
  for (int i = 0; i < num_elements; i++) {
    temp_a = (int16_t)array1[i];
    temp_b = ((int16_t)(array2[i] << 12)) >> 12;
    result += temp_a * temp_b;
  }
  result *= b_scale;
  result += 1UL << shift_num - 1;
  result >>= shift_num;
  result &= 0xfffffff;
  return result;
}

int64_t dot_product_int16int4_k(uint16_t *array1, uint16_t *array2,
                                uint16_t shift_num, uint16_t *b_scale,
                                size_t num_elements) {
  int64_t result = 0;
  int64_t temp_a;
  int64_t temp_b;
  int64_t temp_scale;
  for (int i = 0; i < num_elements; i++) {
    temp_a = (int16_t)array1[i];
    temp_b = ((int16_t)(array2[i] << 12)) >> 12;
    temp_scale = b_scale[i / 32];
    temp_scale = (int64_t)temp_scale << 48 >> 48;
    result += temp_a * temp_b * temp_scale;
  }
  // result += 1UL << shift_num - 1;
  result >>= shift_num;
  result &= 0xfffffff;
  return result;
}

// 打印 fp16 的二进制表示
void print_fp16_binary(uint16_t fp16) {
  for (int i = 15; i >= 0; i--) {
    std::printf("%d", (fp16 >> i) & 1);
    if (i == 15 || i == 10)
      std::printf(" "); // 分隔符号位、指数位和尾数位
  }
  std::printf("\n");
}

// 打印 fp16 的 float 格式和二进制格式
void print_fp16(uint16_t fp16) {
  // 转换为 float
  float float_value = fp16_to_float(fp16);

  // 打印 float 值
  std::printf("Float value: %f\n", float_value);

  // 打印二进制格式
  std::printf("Binary format: ");
  print_fp16_binary(fp16);
}

// 打印 32 位无符号整数的二进制表示
void print_binary_uint32(uint32_t num) {
  // 从最高位（第31位）开始逐位打印
  for (int i = 31; i >= 0; i--) {
    // 使用位操作检查当前位是否为1
    if (num & (1 << i)) {
      std::printf("1");
    } else {
      std::printf("0");
    }
    // 每4位添加一个空格，方便阅读
    if (i % 4 == 0) {
      std::printf(" ");
    }
  }
  std::printf("\n");
}

} // namespace operators

#endif // DOP_UTILS_H