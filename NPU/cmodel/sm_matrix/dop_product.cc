#include "dop_ops.h"
#include <cstddef>  // 包含 size_t 类型
#include <iostream> // 用于输出（如果需要调试）

namespace operators {

// 实现 dop_product 函数
uint64_t dop_product_non_sym(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type) {
  return dop_product_sym_quant(uiA, uiB, num_elements, data_type, nullptr,
                               nullptr);
}

uint64_t dop_product(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                     DataType data_type, uint16_t *scaleA, uint16_t *scaleB) {
  switch (data_type) {
  case NVFP4E2:
    return dop_add_nvfp4(uiA, uiB, scaleA, scaleB, num_elements, 16);
    break;
  case MXFP4MXFP4:
    return dop_add_mxfp4(uiA, uiB, scaleA, scaleB, num_elements, 32);
    break;
  case SINT16SINT4:
    return dop_add_int16int4(uiA, uiB, scaleA, scaleB, num_elements);
    break;
  default:
    if (scaleA) {
      uint32_t scaleA_new = *scaleA;
      return dop_product_sym_quant(uiA, uiB, num_elements, data_type,
                                   &scaleA_new, scaleB);
    } else {
      return dop_product_sym_quant(uiA, uiB, num_elements, data_type, nullptr,
                                   scaleB);
    }
    break;
  }
}

uint64_t dop_product_scale32(uint16_t *uiA, uint16_t *uiB, size_t num_elements,
                             DataType data_type, uint32_t *scaleA,
                             uint16_t *scaleB) {
  return dop_product_sym_quant(uiA, uiB, num_elements, data_type, scaleA,
                               scaleB);
}

// 实现带对称量化的dop_product 函数
uint64_t dop_product_sym_quant(uint16_t *uiA, uint16_t *uiB,
                               size_t num_elements, DataType data_type,
                               uint32_t *scaleA, uint16_t *scaleB) {
  // 创建 FP16MulIntermediate 数组
  FP16MulIntermediate *intermediate_array =
      new FP16MulIntermediate[num_elements];
  // 逐个计算乘法中间结果
  for (size_t i = 0; i < num_elements; i++) {
    intermediate_array[i] = dop16_mul(uiA[i], uiB[i], data_type);
  }

  // 调用 dop_add 将 FP16MulIntermediate 数组累加，生成最终的 fp32 数值
  uint64_t final_result = dop_add(intermediate_array, num_elements,
                                  softfloat_roundingMode, data_type);

  // 释放动态分配的数组
  delete[] intermediate_array;
  std::function<fp_general_t(fp_general_t)> add_dop;
  bool is_int;
  int_type_check(is_int, data_type);
  if (final_result == defaultNANF32UI && !is_int) {
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return defaultNANF32UI;
  }
  bool is_inf =
      (final_result == defaultNINF32UI || final_result == defaultPINF32UI);
  switch (data_type) {
  case MXFP8MXFP8:
    if (scaleA && scaleB) {
      if (*scaleA == 0xff || *scaleB == 0xff) {
        cmodel_exceptionFlags |= softfloat_flag_invalid;
        return defaultNANF32UI;
      }
      final_result = (uint64_t)fp32e8m0mul_resfp32(
          final_result, (fp_general_t)(*scaleA), (fp_general_t)(*scaleB), true);
    }
    break;
  case BF16SINT4:
  case BF16UINT4:
    if (scaleB) {
      final_result = (uint64_t)fp32fp24mul_resfp32(
          final_result, (fp_general_t)(*scaleB << 8), true);
      if (isINFGeneralUI(*scaleB, 8, 7))
        is_inf = true;
    }

    break;
  case FP8E4:
    if (scaleA) {
      final_result = (uint64_t)fp32fp24mul_resfp32(
          final_result, (fp_general_t)(*scaleA), true);
      if (isINFGeneralUI(*scaleA, 8, 15))
        is_inf = true;
    }
    break;
  case BF16MXFP4:
    if (scaleB) {
      if (*scaleB == 0xff) {
        cmodel_exceptionFlags |= softfloat_flag_invalid;
        return defaultNANF32UI;
      }
      final_result = (uint64_t)fp32e8m0mul_resfp32(
          final_result, (fp_general_t)(*scaleB), true);
    }
    break;
  default:
    break;
  }
  if (is_int)
    return final_result;
  if (is_inf) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  } else if (isINFGeneralUI(final_result, 8, 23)) {
    final_result -= 1;
  }
  return final_result;
}

} // namespace operators