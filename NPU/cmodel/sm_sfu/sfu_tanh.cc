#include "sfu_tanh.h"

namespace operators {

uint32_t sfu_tanh(uint32_t x) {
  uint32_t result;
  uint32_t man_ext; // org frac 24bits
  uint32_t x_flit;  // poly input
  uint32_t exp_flit;
  uint32_t frac_flit;

  bool sign = signF32UI(x);
  uint32_t exp = expF32UI(x);
  uint32_t frac = fracF32UI(x);

  // exception
  if ((!exp) && (!frac)) {
    // cmodel_exceptionFlags |= softfloat_flag_underflow; // den，0 //
    // 20251209:id=1786
    return packToF32UI(sign, 0, 0); //+0,-0
  }
  if (exp == 0xFF) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF32UI; // NAN
    } else {
      return packToF32UI(sign, expBias32UI, 0); //+1,-1
    }
  }
  if (exp > 129) {
    // cmodel_exceptionFlags |=  softfloat_flag_overflow;
    return packToF32UI(sign, expBias32UI, 0); //+1,-1
  }

  man_ext = (1 << 23) | frac;
  // pre-process   // normal range[0,8)
  int8_t seg_addr = get_tanh_seg_addr(exp);
  int8_t bsize = get_tanh_seg_bsize(seg_addr);
  uint64_t coef_addr = get_tanh_coef_addr(exp, frac, seg_addr);
  uint32_t man_tmp = get_tanh_man_tmp(exp, frac, seg_addr);
  uint8_t lzd_num = count_leading_zeros(man_tmp, 24);
  if (lzd_num == 24) {
    exp_flit = 0;
    frac_flit = 0;
  } else {
    if (seg_addr >= 2 && seg_addr <= 6) {
      exp_flit = (expBias32UI - bsize - (lzd_num + 1));
    } else if (seg_addr == 1) {
      exp_flit = (expBias32UI - 8 - (lzd_num + 1));
    } else {
      if (exp < 117) {
        exp_flit = exp;
      } else {
        exp_flit = (expBias32UI - 10 - (lzd_num + 1));
      }
    }
    uint32_t man_sft =
        (seg_addr == 0 && exp < 117) ? man_ext : (man_tmp << (lzd_num + 1));
    frac_flit = (seg_addr == 0 && exp < 117) ? get_bits(man_sft, 0, 23)
                                             : get_bits(man_sft, 1, 23);
  }
  x_flit = packToF32UI(0, exp_flit, frac_flit);
  info_coef_fp32 info = get_info_coef_fp32(tanh_coef_info_f32, 188, coef_addr);
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp32(info);
  // poly and post process
  uint32_t res_rlt = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  uint32_t exp_rlt = expF32UI(res_rlt);
  uint32_t frac_rlt = fracF32UI(res_rlt);
  result = packToF32UI(sign, exp_rlt, frac_rlt);

  return result;
}

} // namespace operators