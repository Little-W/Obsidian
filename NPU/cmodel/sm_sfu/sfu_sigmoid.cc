#include "sfu_tanh.h"

namespace operators {

uint32_t sfu_sigmoid(uint32_t x) {
  uint32_t result;  // sigmoid result
  uint32_t exp_new; //  x/2
  uint32_t frac_new;

  uint32_t x_flit; // poly input
  uint32_t exp_flit;
  uint32_t frac_flit;
  info_coef_fp32 info;

  bool sign = signF32UI(x);
  uint32_t exp = expF32UI(x);
  uint32_t frac = fracF32UI(x);

  // exception
  if ((!exp) && (!frac)) {
    return ZERO_POINT_FIVE_FP32;
  }
  if (exp == 0xFF) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF32UI; // NAN
    } else {
      if (sign) {
        cmodel_exceptionFlags |= softfloat_flag_underflow;
        return 0;
      } else {
        return packToF32UI(0, expBias32UI, 0); //+1
      }
    }
  }
  if (exp > 130) {
    // cmodel_exceptionFlags |=  softfloat_flag_overflow;
    if (sign) {
      return 0;
    } else {
      return packToF32UI(0, expBias32UI, 0); //+1
    }
  }

  if ((!exp) && frac) {
    // denormalization
    exp_new = 0;
    frac_new = (frac >> 1);
  } else {
    // normal
    exp_new = exp - 1; // div2
    frac_new = frac;
  }

  int8_t seg_addr = get_tanh_seg_addr(exp_new);
  int8_t bsize = get_tanh_seg_bsize(seg_addr);
  uint64_t coef_addr = get_tanh_coef_addr(exp_new, frac_new, seg_addr);
  uint32_t man_tmp = get_tanh_man_tmp(exp_new, frac_new, seg_addr);
  uint8_t lzd_num = count_leading_zeros(man_tmp, 24);
  if (lzd_num == 24) {
    exp_flit = 0;
    frac_flit = 0;
  } else {
    if (seg_addr >= 2 && seg_addr <= 6) {
      exp_flit = (expBias32UI - bsize - (lzd_num + 1));
    } else if (seg_addr == 1) {
      exp_flit = (expBias32UI - 8 - (lzd_num + 1));
    } else { // seg_addr=0
      if (exp < 117) {
        exp_flit = exp_new;
      } else {
        exp_flit = (expBias32UI - 10 - (lzd_num + 1));
      }
    }
    uint32_t man_sft = (man_tmp << (lzd_num + 1));
    frac_flit = get_bits(man_sft, 1, 23);
  }
  x_flit = packToF32UI(0, exp_flit, frac_flit);
  if (sign) {
    info = get_info_coef_fp32(neg_sg_coef_info_f32, 188, coef_addr);
  } else {
    info = get_info_coef_fp32(pos_sg_coef_info_f32, 188, coef_addr);
  }
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp32(info);
  // poly and post process
  uint32_t res_rlt = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  uint32_t exp_rlt = expF32UI(res_rlt);
  uint32_t frac_rlt = fracF32UI(res_rlt);
  if ((!exp_rlt) && (!frac_rlt)) {
    return packToF32UI(0, 0, 0);
  }
  if ((!exp_rlt) && frac_rlt) {
    // denormalization
    return packToF32UI(0, 0, frac_rlt >> 1);
  }
  result = packToF32UI(0, exp_rlt - 1, frac_rlt); // div2
  // result = fp32_check_setExcept(result);

  return result;
}

} // namespace operators