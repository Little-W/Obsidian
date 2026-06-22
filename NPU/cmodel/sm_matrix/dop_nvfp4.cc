#include "dop_rtl_mode.h"

using namespace std;
namespace operators {
// 只是用MXFP4MXFP4和NVFP4E2
fp_general_t dop_mdp_base_mul(uint16_t a, uint16_t b) {
  bool signA;
  bool signB;
  bool signZ;
  int16_t expA;
  int16_t expB;
  uint16_t sigA;
  uint16_t sigB;
  fp_general_t sigZ;
  int exp_len_a = 2;
  int sig_len_a = 1;
  int exp_len_b = 2;
  int sig_len_b = 1;

  uint64_t sig_hide_a = sigHideGeneralUI(sig_len_a);
  uint64_t sig_hide_b = sigHideGeneralUI(sig_len_b);
  signA = signGeneralUI(a, exp_len_a, sig_len_a);
  expA = expGeneralUI(a, exp_len_a, sig_len_a);
  sigA = fracGeneralUIUI(a, sig_len_a);
  signB = signGeneralUI(b, exp_len_b, sig_len_b);
  expB = expGeneralUI(b, exp_len_b, sig_len_b);
  sigB = fracGeneralUIUI(b, sig_len_b);
  if (!expA) {
    if (!sigA)
      return 0;
    expA += 1;
  } else {
    sigA |= sig_hide_a; // fp16 的尾数掩码
  }
  if (!expB) {
    if (!sigB)
      return 0;
    expB += 1;
  } else {
    sigB |= sig_hide_b; // fp16 的尾数掩码
  }
  sigA <<= expA - 1;
  sigB <<= expB - 1;
  if (signA) {
    sigA = ~sigA + 1;
  }
  if (signB) {
    sigB = ~sigB + 1;
  }

  sigZ = sigA * sigB;
  return sigZ;
}

FP16MulIntermediate dop_scale_nvfp4(fp_general_t frac, uint16_t a_scale,
                                    uint16_t b_scale) {
  FP16MulIntermediate result = {0};
  uint16_t uiA;
  uint16_t uiB;
  uint8_t signA;
  bool signB;
  bool signZ;
  bool signFrac;
  int16_t expA;
  int16_t expB;
  int16_t expZ;
  uint16_t sigA;
  uint16_t sigB;
  fp_general_t sigZ;
  int exp_len_a = 4;
  int sig_len_a = 3;
  int exp_len_b = 4;
  int sig_len_b = 3;
  uiA = a_scale;
  uiB = b_scale;

  uint64_t sig_hide_a = sigHideGeneralUI(sig_len_a);
  uint64_t sig_hide_b = sigHideGeneralUI(sig_len_b);
  signA = signGeneralUI(uiA, exp_len_a, sig_len_a);
  expA = expGeneralUI(uiA, exp_len_a, sig_len_a);
  sigA = fracGeneralUIUI(uiA, sig_len_a);
  signB = signGeneralUI(uiB, exp_len_b, sig_len_b);
  expB = expGeneralUI(uiB, exp_len_b, sig_len_b);
  sigB = fracGeneralUIUI(uiB, sig_len_b);
  signZ = signA ^ signB;
  if (!expA) {
    if (!sigA)
      return result;
    expA += 1;
  } else {
    sigA |= sig_hide_a; // fp16 的尾数掩码
  }
  if (!expB) {
    if (!sigB)
      return result;
    expB += 1;
  } else {
    sigB |= sig_hide_b; // fp16 的尾数掩码
  }
  expZ = expA + expB;
  sigZ = sigA * sigB;
  signFrac = frac & 0x1000;
  if (signFrac)
    frac = ~frac + 1;
  frac &= 0xfff;
  signZ = signZ ^ signFrac;
  sigZ *= frac;
  if (signZ)
    sigZ = ~sigZ + 1;
  result.sign = signZ;
  result.exp = expZ;
  result.frac32 = sigZ;
  result.frac64 = sigZ;
  result.frac128 = sigZ;
  return result;
}

fp_general_t dop_add_nvfp4(uint16_t *a, uint16_t *b, uint16_t *a_scale,
                           uint16_t *b_scale, size_t num_elements,
                           size_t step_size) {
  // 初始变量准备
  uint16_t block_num = (num_elements - 1) / step_size + 1;
  FP16MulIntermediate *dop_mul_result = new FP16MulIntermediate[block_num];
  uint64_t final_result = 0;
  // 中间变量
  uint64_t block_add_result;
  uint32_t scaleA_temp;
  uint32_t scaleB_temp;
  uint32_t product_temp;
  uint32_t base_locatiion;
  uint16_t exp_max = 0;
  bool sign;
  bool is_inf = false;
  // 16个一组进行相加并scale
  uint32_t upper_bound = 0;
  for (size_t bolock_counter = 0; bolock_counter < block_num;
       bolock_counter++) {
    block_add_result = 0;
    upper_bound = bolock_counter == block_num - 1
                      ? num_elements - (block_num - 1) * step_size
                      : step_size;
    base_locatiion = bolock_counter * step_size;
    for (size_t i = 0; i < upper_bound; i++) {
      product_temp =
          dop_mdp_base_mul(a[i + base_locatiion], b[i + base_locatiion]);
      block_add_result += product_temp;
    }

    if (a_scale && b_scale) {
      scaleA_temp = a_scale[bolock_counter];
      scaleB_temp = b_scale[bolock_counter];
      if (((scaleA_temp & 0x7f) == 0x7f) || ((scaleB_temp & 0x7f) == 0x7f)) {
        cmodel_exceptionFlags |= softfloat_flag_invalid;
        final_result = defaultNANF32UI;
        delete[] dop_mul_result;
        return final_result;
      }
    } else {
      scaleA_temp = 0x38;
      scaleB_temp = 0x38;
    }
    dop_mul_result[bolock_counter] =
        dop_scale_nvfp4(block_add_result, scaleA_temp, scaleB_temp);
    exp_max = exp_max > dop_mul_result[bolock_counter].exp
                  ? exp_max
                  : dop_mul_result[bolock_counter].exp;
  }

  uint16_t move_left_bit =
      bit_width_dop_f4dp64 - 21; // 运算位宽减去尾数最大位宽
  int16_t move_right_bit = 0;
  uint64_t temp_add_result;
  uint64_t frac = 0;
  for (size_t bolock_counter = 0; bolock_counter < block_num;
       bolock_counter++) {
    move_right_bit = exp_max - dop_mul_result[bolock_counter].exp;
    temp_add_result = dop_mul_result[bolock_counter].frac64;
    sign = temp_add_result & (1 << 20);
    if (sign)
      temp_add_result = ~temp_add_result + 1;
    // cout << "temp_add_result before move: " << hex << temp_add_result <<
    // endl;
    temp_add_result = temp_add_result << move_left_bit >> move_right_bit;
    if (sign)
      temp_add_result = ~temp_add_result + 1;
    // cout << "temp_add_result: " << hex << temp_add_result << endl;
    frac += temp_add_result;
  }
  if (frac == 0) {
    delete[] dop_mul_result;
    return 0;
  }
  // 拼装frac和exp,frac此时36位,需要左移至没有先导0=>leadingZeros64,然后去除一位隐藏位+23位尾数
  sign = frac & (1UL << 37);
  if (sign)
    frac = (~frac + 1);
  frac &= (1UL << 37) - 1;
  int16_t leadingZeros64 = softfloat_countLeadingZeros64(frac);
  move_right_bit = 64 - leadingZeros64 - 24;
  if (move_right_bit >= 0) {
    frac >>= move_right_bit;
  } else {
    frac <<= -move_right_bit;
  }
  exp_max += move_right_bit + 127 - 14 - 1;

  final_result |= ((uint64_t)sign << 31); // 符号位
  final_result |= ((exp_max) << 23);      // 指数位（加上偏移量 127）
  final_result += (uint64_t)(frac);       // 尾数位（取低 23 位）

  if (is_inf) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
  } else if (isINFGeneralUI(final_result, 8, 23)) {
    final_result -= 1;
  }
  delete[] dop_mul_result;
  return final_result;
}

} // namespace operators