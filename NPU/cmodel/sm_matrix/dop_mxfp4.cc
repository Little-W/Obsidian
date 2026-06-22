#include "dop_rtl_mode.h"

namespace operators {
FP16MulIntermediate dop_scale_mxfp4(fp_general_t frac, uint16_t a_scale,
                                    uint16_t b_scale) {
  FP16MulIntermediate result = {0};
  int16_t expZ;

  expZ = a_scale + b_scale;
  bool signFrac = frac & 0x1000;
  if (signFrac) {
    frac = ~frac + 1;
    frac &= 0xfff;
    frac = ~frac + 1;
  } else {
    frac &= 0xfff;
  }
  result.sign = signFrac;
  result.exp = expZ;
  result.frac32 = frac;
  result.frac64 = frac;
  result.frac128 = frac;
  return result;
}

fp_general_t dop_add_mxfp4(uint16_t *a, uint16_t *b, uint16_t *a_scale,
                           uint16_t *b_scale, size_t num_elements,
                           size_t scale_step_size) {
  size_t add_scale_size = 16;
  // 初始变量准备
  uint16_t block_num = (num_elements - 1) / add_scale_size + 1;
  FP16MulIntermediate *dop_mul_result = new FP16MulIntermediate[block_num];
  uint64_t final_result = 0;
  // 中间变量
  uint64_t block_add_result;
  uint32_t scaleA_temp;
  uint32_t scaleB_temp;
  uint32_t product_temp;
  uint32_t base_locatiion;
  int16_t exp_max = 0;
  bool sign;
  bool is_inf = false;
  // 16个一组进行相加并scale
  uint32_t upper_bound = 0;
  for (size_t bolock_counter = 0; bolock_counter < block_num;
       bolock_counter++) {
    block_add_result = 0;
    upper_bound = bolock_counter == block_num - 1
                      ? num_elements - (block_num - 1) * add_scale_size
                      : add_scale_size;
    base_locatiion = bolock_counter * add_scale_size;
    for (size_t i = 0; i < upper_bound; i++) {
      product_temp =
          dop_mdp_base_mul(a[i + base_locatiion], b[i + base_locatiion]);
      block_add_result += product_temp;
    }

    if (a_scale && b_scale) {
      scaleA_temp = a_scale[bolock_counter / 2];
      scaleB_temp = b_scale[bolock_counter / 2];
      if (((scaleA_temp & 0xff) == 0xff) || ((scaleB_temp & 0xff) == 0xff)) {
        cmodel_exceptionFlags |= softfloat_flag_invalid;
        final_result = defaultNANF32UI;
        delete[] dop_mul_result;
        return final_result;
      }
    } else {
      scaleA_temp = 0x7f;
      scaleB_temp = 0x7f;
    }
    dop_mul_result[bolock_counter] =
        dop_scale_mxfp4(block_add_result, scaleA_temp, scaleB_temp);
    exp_max = exp_max > dop_mul_result[bolock_counter].exp
                  ? exp_max
                  : dop_mul_result[bolock_counter].exp;
  }

  uint16_t move_left_bit =
      bit_width_dop_f4dp64 - 13; // 运算位宽减去尾数最大位宽
  int16_t move_right_bit = 0;
  uint64_t temp_add_result;
  uint64_t frac = 0;
  for (size_t bolock_counter = 0; bolock_counter < block_num;
       bolock_counter++) {
    move_right_bit = exp_max - dop_mul_result[bolock_counter].exp;
    if (move_right_bit > 40)
      continue;
    temp_add_result = dop_mul_result[bolock_counter].frac64;
    sign = temp_add_result & (1 << 12);
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
  exp_max -= 2; // 小数点在第25位前,现在挪到23位前,相当于指数增加了2,这里减去
  exp_max += move_right_bit + 127 - 254 - 1;
#pragma max_iterations 64
  while ((exp_max < 0) && frac) {
    frac >>= 1;
    exp_max++;
  }
  if (!frac) {
    return (uint64_t)sign << 31;
  }
  if ((exp_max + (frac >> 23)) >= 255) {
    final_result = (uint64_t)sign << 31 | defaultPINF32UI;
    final_result -= 1;
    return final_result;
  }

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