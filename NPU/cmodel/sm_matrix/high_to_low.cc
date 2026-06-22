#include "dop_ops.h"
#include "internals.h"
#include "specialize.h"
#include <stdbool.h>
#include <stdint.h>

#define packToGeneral(sign, exp, sig, exp_len, sig_len)                        \
  (((uint64_t)(sign) << (exp_len + sig_len)) + ((uint32_t)(exp) << sig_len) +  \
   (sig))

namespace operators {
fp_general_t roundToGeneral(uint64_t sign, int exp, uint64_t frac, int exp_len,
                            int sig_len, bool is_dop = false) {
  fp_general_t result = 0;
  uint_fast8_t rnd = softfloat_roundingMode;
  uint64_t sig_hide = (uint64_t)1 << sig_len;
  int exp_temp = exp;
  bool L_add1_en;
  int exp_max = ((uint64_t)1 << exp_len) - 2;

  // 隐藏位进位到exp
  // print_uint128_hex(frac);
  // bool S = (frac << 25) != 0; // 包含第26位，所以只左移25次
  bool S = frac & 1;
  if (exp_temp <= 0) {
#pragma max_iterations 128
    while (frac && exp_temp < 0) {
      frac >>= 1;
      exp_temp += 1;
      S = S | (frac & 1);
    }
    exp_temp = 0;
  }
  // 舍入
  // 1. 求解L，R，S
  // 2. L：最高位开始第24位，R：最高位开始第25位，S：最高位开始第26位往后是否非0
  //  提取 倒数第3 位（L）
  bool L = (frac >> 2) & 1;

  // 提取 倒数第2 位（R）
  bool R = (frac >> 1) & 1;

  // L_add1_en = (2 == rnd) & ~sign & (R | S) | (3 == rnd) & sign & (R | S) | (0
  // == rnd) & R & ~(0 == L && 1 == R && 0
  // == S);
  L_add1_en = (0 == rnd) & ((1 == L && 1 == R && 0 == S) | (1 == R && 1 == S)) |
              (2 == rnd) & sign & (R | S) | (3 == rnd) & ~sign & (R | S) |
              (4 == rnd) & (R);
  // 1. 将 frac 右移 2 位
  frac >>= 2;
  if (L_add1_en) {
    // 2. 在L位加 1
    frac += 1;

    // 3. 判断首位是否进位成 1
    if (frac & sig_hide << 1) {
      frac >>= 1;
      exp_temp += 1; // 如果首位为 1，则 exp + 1,尾数>>1
    }
  }

  if (exp_temp >= exp_max) {
    frac = 0;
    exp_temp = exp_max + 1; // inf tag为真
    cmodel_exceptionFlags |= softfloat_flag_overflow;
  }

  // 计算下溢标记
  if (R | S) {
    if (!exp_temp && !frac) {
      cmodel_exceptionFlags |= softfloat_flag_underflow;
    }
  }

  // print_binary_uint8(exp_max);
  result |= sign << (exp_len + sig_len); // 符号位
  // print_binary_uint32(result);
  result |= ((uint64_t)exp_temp) << sig_len; // 指数位（加上偏移量 127）
  // print_binary_uint32(result);
  result += frac; // 尾数位（取低 23 位）
  // print_binary_uint32(result);
  if (exp_temp == exp_max + 1 &&
      (rnd == 1 || (sign && rnd == 3) || (!sign && rnd == 2))) {
    result -= 1;
  }
  if (!denormal_out_en && is_dop) {
    // 只服务dop
    if (!((result >> 23) & 0xff))
      return (uint64_t)sign << 31; // 符号位
  }
  return result; // 将 uint32_t 转换为 float32_t 并返回
}

fp_general_t high_to_low(fp_general_t a, int low_exp_len, int low_sig_len,
                         int high_exp_len, int high_sig_len, bool is_dop) {
  // alu_output_exam(a, high_exp_len, high_sig_len);
  uint64_t signA;
  uint32_t expA;
  uint_fast64_t sigA;
  int high_full_len = high_exp_len + high_sig_len + 1;
  int low_full_len = low_exp_len + low_sig_len + 1;

  uint64_t signZ;
  uint32_t magBits;
  uint32_t expZ;
  uint32_t sigZ;
  int_fast16_t exp;

  uint64_t tool_num = 0xFFFFFFFFFFFFFFFF;
  fp_general_t z;
  uint_fast64_t frac;
  int_fast8_t shiftDist;
  int_fast8_t sigDist = high_sig_len - low_sig_len;
  uint64_t sigDist_tool = 0;
  if (sigDist > 2) {
    sigDist_tool = ((uint64_t)1 << (sigDist - 2)) - 1;
  }

  uint64_t low_sig_tool = tool_num << (64 - low_sig_len) >> (64 - low_sig_len);
  uint64_t low_exp_max =
      tool_num << (64 - low_full_len + 1) >> (64 - low_exp_len);
  uint64_t low_exp_tool = low_exp_max << (64 - low_exp_len);
  uint64_t low_sign_tool = (uint64_t)1 << (low_full_len - 1);
  uint64_t low_sig_hiden = (uint64_t)1 << low_sig_len;

  uint64_t high_sig_tool =
      tool_num << (64 - high_sig_len) >> (64 - high_sig_len);
  uint64_t high_exp_max =
      tool_num << (64 - high_full_len + 1) >> (64 - high_exp_len);
  uint64_t high_sign_tool = (uint64_t)1 << (high_full_len - 1);
  uint64_t high_sig_hiden = (uint64_t)1 << high_sig_len;

  __uint128_t sig128Z = 0;
  FP16MulIntermediate result = {0};

  signA = signGeneralUI(a, high_exp_len, high_sig_len);
  expA = expGeneralUI(a, high_exp_len, high_sig_len);
  sigA = fracGeneralUIUI(a, high_sig_len);
  frac = sigA;
  exp = expA;

  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  if (exp == high_exp_max) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      z = defaultNANGeneralUI(low_exp_len, low_sig_len);
    } else {
      z = defaultINFGeneralUI(signA, low_exp_len, low_sig_len);
    }
    goto uiZ;
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  if (!(exp | frac)) {
    z = signA << (low_full_len - 1);
    goto uiZ;
  }

  if (low_exp_len == high_exp_len) {
    if (!exp) {
      shiftDist = softfloat_countLeadingZeros64(sigA) - (64 - high_full_len) -
                  high_exp_len; // 次规格化数的转换
      exp = 1 - shiftDist;
      frac = sigA << shiftDist;
    }
    if (sigDist > 2) {
      frac = (frac >> (sigDist - 2)) | ((frac & sigDist_tool) != 0);
    }

    /*------------------------------------------------------------------------
     *------------------------------------------------------------------------*/
    return roundToGeneral(signA, exp - 1, frac | (low_sig_hiden << 2),
                          low_exp_len, low_sig_len, is_dop);
  } else {
    if (sigDist > 2) {
      frac = (frac >> (sigDist - 2)) | ((frac & sigDist_tool) != 0);
    }

    /*------------------------------------------------------------------------
     *------------------------------------------------------------------------*/
    int exp_dist_low = ((uint64_t)1 << (low_exp_len - 1)) - 1;
    int exp_dist_high = ((uint64_t)1 << (high_exp_len - 1)) - 1;
    z = roundToGeneral(signA, exp + exp_dist_low - exp_dist_high - 1,
                       frac | (low_sig_hiden << 2), low_exp_len, low_sig_len,
                       is_dop);
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/

uiZ:
  return z;
}
} // namespace operators
