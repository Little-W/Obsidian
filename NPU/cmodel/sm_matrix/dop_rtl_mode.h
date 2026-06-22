#ifndef DOP_RTL_MODE_H // 防止头文件被重复包含
#define DOP_RTL_MODE_H
#include "dop_ops.h"
#include <array>
#include <cstdint>  // C++ 标准库头文件
#include <cstdio>   // C++ 标准库头文件
#include <iostream> // 用于输出

namespace operators {
fp_general_t dop_mdp_base_mul(uint16_t a, uint16_t b);
FP16MulIntermediate dop_scale_nvfp4(fp_general_t frac, uint16_t a_scale,
                                    uint16_t b_scale);
FP16MulIntermediate dop_scale_mxfp4(fp_general_t frac, uint16_t a_scale,
                                    uint16_t b_scale);
} // namespace operators

#endif // DOP_ADD16_H