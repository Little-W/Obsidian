#include "dop_ops.h"
#include <array>
#include <cstdint>  // C++ 标准库头文件
#include <cstdio>   // C++ 标准库头文件
#include <iostream> // 用于输出

namespace operators {
// 实现 dop16_mul 函数
FP16MulIntermediate dop16_mul(uint16_t a, uint16_t b, DataType data_type) {

  uint_fast16_t uiA;
  uint64_t signA;
  int_fast16_t expA;
  uint_fast16_t sigA;
  uint_fast16_t uiB;
  uint64_t signB;
  int_fast16_t expB;
  uint_fast16_t sigB;
  uint64_t signZ;
  int_fast16_t expZ = 0;
  uint_fast16_t sigZ, uiZ;

  __uint128_t sig128Z = 0;
  FP16MulIntermediate result = {0};
  std::array<int, 4> len_list = {0, 0, 0, 0};

  switch (data_type) {
  // 对于fp，两个数字分别代表指数位宽和尾数位宽；对于int，两个数字分别带别是否有符号，以及总位宽
  //  fp*fp
  case FP16:
    len_list = {5, 10, 5, 10};
    break;
  case BF16:
    len_list = {8, 7, 8, 7};
    break;
  case FP8E5:
    len_list = {5, 2, 5, 2};
    break;
  case FP8E4:
  case MXFP8MXFP8:
    len_list = {4, 3, 4, 3};
    break;
  case FP8E5FP6E3:
    len_list = {5, 2, 3, 2};
    break;
  case FP8E5FP6E2:
    len_list = {5, 2, 2, 3};
    break;
  case FP8E4FP6E3:
    len_list = {4, 3, 3, 2};
    break;
  case FP8E4FP6E2:
    len_list = {4, 3, 2, 3};
    break;
  case NVFP4E2:
  case MXFP4MXFP4:
    len_list = {2, 1, 2, 1};
    break;
  case BF16MXFP4:
    len_list = {8, 7, 2, 1};
    break;

  // fp*int
  case FP16SINT4:
    len_list = {5, 10, 1, 4};
    break;
  case FP16UINT4:
    len_list = {5, 10, 0, 4};
    break;
  case BF16SINT4:
    len_list = {8, 7, 1, 4};
    break;
  case BF16UINT4:
    len_list = {8, 7, 0, 4};
    break;

  // int*int
  case UINT8:
    len_list = {0, 8, 0, 8};
    break;
  case SINT8:
    len_list = {1, 8, 1, 8};
    break;
  case SINT8UINT8:
    len_list = {1, 8, 0, 8};
    break;
  case UINT8SINT8:
    len_list = {0, 8, 1, 8};
    break;
  case SINT16SINT8:
    len_list = {1, 16, 1, 8};
    break;
  case UINT16SINT8:
    len_list = {0, 16, 1, 8};
    break;
  case SINT16SINT4:
    len_list = {1, 16, 1, 4};
    break;
  case SINT16UINT4:
    len_list = {1, 16, 0, 4};
    break;
  case UINT16SINT4:
    len_list = {0, 16, 1, 4};
    break;
  case UINT16UINT4:
    len_list = {0, 16, 0, 4};
    break;
  default:
    // 非法数据类型
    result.NAN_tag = true;
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_invalid;
    return result;
  }

  int exp_len_a = len_list[0];
  int sig_len_a = len_list[1];
  int exp_len_b = len_list[2];
  int sig_len_b = len_list[3];

  uiA = a;
  uiB = b;

  uint64_t sig_hide_a = sigHideGeneralUI(sig_len_a);
  uint64_t sig_hide_b = sigHideGeneralUI(sig_len_b);
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  switch (data_type) {
  case FP8E4:
  case MXFP8MXFP8:
  case MXFP4MXFP4:
  case NVFP4E2:
  case BF16MXFP4:
    signA = signGeneralUI(uiA, exp_len_a, sig_len_a);
    expA = expGeneralUI(uiA, exp_len_a, sig_len_a);
    sigA = fracGeneralUIUI(uiA, sig_len_a);

    signB = signGeneralUI(uiB, exp_len_b, sig_len_b);
    expB = expGeneralUI(uiB, exp_len_b, sig_len_b);
    sigB = fracGeneralUIUI(uiB, sig_len_b);
    signZ = signA ^ signB;
    result.sign = signZ;
    if ((data_type == MXFP8MXFP8) || (data_type == FP8E4)) {
      if ((uiA & 0x7f) == 0x7f)
        goto propagateNaN;

      if ((uiB & 0x7f) == 0x7f)
        goto propagateNaN;
    }
    if (data_type == BF16MXFP4) {
      if (expA == defaultPINFGeneralUI(exp_len_a)) { // fp16 的最大指数值
        if (sigA || (!expB && !sigB))
          goto propagateNaN;
        goto infArg;
      }
    }
    break;

  case FP16:
  case BF16:
  case FP8E5:
  case FP8E5FP6E3:
  case FP8E5FP6E2:
  case FP8E4FP6E3:
  case FP8E4FP6E2:
    signA = signGeneralUI(uiA, exp_len_a, sig_len_a);
    expA = expGeneralUI(uiA, exp_len_a, sig_len_a);
    sigA = fracGeneralUIUI(uiA, sig_len_a);

    signB = signGeneralUI(uiB, exp_len_b, sig_len_b);
    expB = expGeneralUI(uiB, exp_len_b, sig_len_b);
    sigB = fracGeneralUIUI(uiB, sig_len_b);
    signZ = signA ^ signB;
    result.sign = signZ;
    if (!denormal_in_en && data_type == BF16) {
      if (!expA)
        sigA = 0;
    }
    if (expA == defaultPINFGeneralUI(exp_len_a)) { // fp16 的最大指数值
      if (sigA || ((expB == defaultPINFGeneralUI(exp_len_b)) && sigB) ||
          (!expB && !sigB))
        goto propagateNaN;
      goto infArg;
    }
    if (expB == defaultPINFGeneralUI(exp_len_b)) { // fp16 的最大指数值
      if (sigB || (!expA && !sigA))
        goto propagateNaN;
      goto infArg;
    }
    break;

  case FP16SINT4:
  case BF16SINT4:
  case FP16UINT4:
  case BF16UINT4:
    signA = signGeneralUI(uiA, exp_len_a, sig_len_a);
    expA = expGeneralUI(uiA, exp_len_a, sig_len_a);
    sigA = fracGeneralUIUI(uiA, sig_len_a);

    signB = intSignGeneralUI(b, exp_len_b, sig_len_b);
    sigB = intFracGeneralUI(b, exp_len_b, sig_len_b);

    signZ = signA ^ signB;
    result.sign = signZ;
    if (expA == defaultPINFGeneralUI(exp_len_a)) { // bf16 的最大指数值
      if (sigA || (!sigB))
        goto propagateNaN; // 0*inf 得到nan
      goto infArg;
    }
    break;

  case UINT8:
  case SINT8:
  case SINT8UINT8:
  case UINT8SINT8:
  case SINT16SINT8:
  case UINT16SINT8:
  case SINT16SINT4:
  case SINT16UINT4:
  case UINT16SINT4:
  case UINT16UINT4:
    signA = intSignGeneralUI(a, exp_len_a, sig_len_a);
    sigA = intFracGeneralUI(a, exp_len_a, sig_len_a);

    signB = intSignGeneralUI(b, exp_len_b, sig_len_b);
    sigB = intFracGeneralUI(b, exp_len_b, sig_len_b);

    signZ = signA ^ signB;
    result.sign = signZ;
    break;
  default:
    // 非法数据类型
    result.NAN_tag = true;
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_invalid;
    return result;
  }

  if (!denormal_in_en) {
    switch (data_type) {
    case BF16:
    case BF16SINT4:
    case BF16UINT4:
      if (!expA)
        sigA = 0;
      break;
    }
  }
  switch (data_type) {
  case BF16:
  case BF16MXFP4:
  case BF16SINT4:
  case BF16UINT4:
    if (!expA && matrix_dp_en) {
      goto zero;
    }
    break;
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  switch (data_type) {
  case NVFP4E2:
  case MXFP4MXFP4:
  case FP16:
  case BF16:
  case FP8E5:
  case FP8E4:
  case MXFP8MXFP8:
  case FP8E5FP6E3:
  case FP8E5FP6E2:
  case FP8E4FP6E3:
  case FP8E4FP6E2:
  case BF16MXFP4:
    if (!expA) {
      if (!sigA)
        goto zero;
      expA += 1;
    } else {
      sigA |= sig_hide_a; // fp16 的尾数掩码
    }
    if (!expB) {
      if (!sigB)
        goto zero;
      expB += 1;
    } else {
      sigB |= sig_hide_b; // fp16 的尾数掩码
    }

    expZ = expA + expB; // fp16 的指数偏置
    break;

  case FP16SINT4:
  case BF16SINT4:
  case FP16UINT4:
  case BF16UINT4:
    if (!expA) {
      if (!sigA)
        goto zero;
      expA += 1;
    } else {
      sigA |= sig_hide_a; // fp16 的尾数掩码
    }
    if (!sigB)
      goto zero;
    expZ = expA; // fp16 的指数偏置
    break;

  case UINT8:
  case SINT8:
  case SINT8UINT8:
  case UINT8SINT8:
  case SINT16SINT8:
  case UINT16SINT8:
  case SINT16SINT4:
  case SINT16UINT4:
  case UINT16SINT4:
  case UINT16UINT4:
    if (!sigB || !sigA)
      goto zero;
    break;
    expZ = 0;
  default:
    // 非法数据类型
    result.NAN_tag = true;
    cmodel_exceptionFlags = cmodel_exceptionFlags | softfloat_flag_invalid;
    return result;
  }

  switch (data_type) {
  case NVFP4E2:
  case MXFP4MXFP4:
    sigA <<= expA - 1;
    sigB <<= expB - 1;
    expZ = 1 + 1; // fp16 的指数偏置
    break;
  case BF16MXFP4:
    sigB <<= expB - 1;
    expZ = expA + 1; // fp16 的指数偏置
    break;
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/

  sig128Z = sigA * sigB;
  result.frac32 = (uint32_t)sig128Z;
  result.frac64 = (uint64_t)sig128Z;
  result.frac128 = (__uint128_t)sig128Z;
  result.exp = expZ;
  return result;
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
propagateNaN:
  result.NAN_tag = true;
  goto uiZ;
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
infArg:
  result.Infinity_tag = true;
  goto uiZ;
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
zero:
  result.sign = 0;
  result.zero_tag = true;
uiZ:
  return result;
}

} // namespace operators