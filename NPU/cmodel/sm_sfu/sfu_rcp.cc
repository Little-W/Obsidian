#include "sfu_sqrt_rcp.h"

namespace operators {

uint32_t sfu_rcp(uint32_t x) {
  uint32_t rlt_f32; // poly result
  uint32_t result;
  bool exp_op_rcp = false;  // add/sub exp_new
  uint32_t exp_new_rcp = 0; // real exp
  uint32_t x_exp_flit;      // poly exp
  uint32_t x_frac;          // poly frac
  uint32_t x_flit;          // poly input

  bool sign = signF32UI(x);
  uint32_t exp_org = expF32UI(x);
  uint32_t frac = fracF32UI(x);

  if ((!exp_org) && (!frac)) {
    //+inf/-inf
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return packToF32UI(sign, 0xFF, 0);
  }

  if (exp_org == 0xFF) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      result = defaultNANF32UI; // NAN
    } else {
      cmodel_exceptionFlags |= softfloat_flag_underflow;
      result = packToF32UI(sign, 0, 0); // 0
    }
    return result;
  }

  if ((!exp_org) && frac) {
    // denormalized
    uint8_t lzd_num_den = count_leading_zeros(frac, 23);
    frac = frac << (lzd_num_den + 1);
    exp_new_rcp = 126 + (lzd_num_den + 1);
    exp_op_rcp = 0;
  } else {
    frac = (1 << 23) | frac;
    if (0 < exp_org && exp_org < expBias32UI) {
      exp_new_rcp = expBias32UI - exp_org;
      exp_op_rcp = 0;
    } else if (expBias32UI <= exp_org && exp_org < 0xFF) {
      exp_new_rcp = exp_org - expBias32UI;
      exp_op_rcp = 1;
    }
  }
  // get poly input
  int8_t seg_addr, subseg_addr, bsize;
  uint64_t coef_addr;
  uint32_t seg_left_man, man_sub, man_tmp, man_sft;
  if ((((frac >> 20) & 0x7) > 0x1) || ((frac >> 20) & 0x7) == 0x1) {
    seg_addr = 1;
    seg_left_man = (1 << 23) | fracF32UI(0x3F900000); // 1.125
    bsize = 6;
    man_sub = frac - seg_left_man;
    subseg_addr = get_bits(man_sub, 17, 6); // 17~22bits
    man_tmp = get_bits(man_sub, 0, 17);     // 0~16bits
  } else {
    seg_addr = 0;
    seg_left_man = (1 << 23) | fracF32UI(0x3F800000); // 1
    bsize = 7;
    man_sub = frac - seg_left_man;
    subseg_addr = get_bits(man_sub, 16, 6);    // 16~21bits
    man_tmp = (get_bits(man_sub, 0, 16)) << 1; // {0~15,0}
  }
  coef_addr = (seg_addr << SQRT_LUT_ADDR_SUBBITS_F32) | subseg_addr;
  uint8_t lzd_num = count_leading_zeros(man_tmp, 17);
  if (lzd_num == 17) {
    x_exp_flit = 0;
    x_frac = 0;
  } else {
    x_exp_flit = expBias32UI - bsize - (lzd_num + 1);
    man_sft = man_tmp << (lzd_num + 1);
    x_frac = (get_bits(man_sft, 0, 17)) << 6; //{man_sft[16:0],6b'0}
  }
  x_flit = packToF32UI(0, x_exp_flit, x_frac);
  // get coef, poly
  info_coef_fp32 info = get_info_coef_fp32(rcp_coef_info_f32, 72, coef_addr);
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp32(info);
  rlt_f32 = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  bool sign_rlt = signF32UI(rlt_f32);
  uint32_t exp_poly = expF32UI(rlt_f32);
  uint32_t frac_rlt = fracF32UI(rlt_f32);
  uint32_t exp_rlt;
  if (exp_op_rcp) {
    if (exp_poly > exp_new_rcp) {
      exp_rlt = -exp_new_rcp + exp_poly;
    } else if (exp_poly == exp_new_rcp) {
      uint32_t new_frac = (1 << 23) | frac_rlt;
      exp_rlt = 0;
      frac_rlt = get_bits(new_frac, 1, 23);
    } else {
      exp_rlt = 0;
      frac_rlt = get_frac_shift(sign_rlt, frac_rlt, exp_new_rcp, exp_poly);
    }
  } else {
    exp_rlt = exp_new_rcp + exp_poly;
  }
  if (exp_rlt >= 255) {
    // cmodel_exceptionFlags |=  softfloat_flag_overflow;
    return packToF32UI(sign, 0xFF, 0);
  }
  result = packToF32UI(sign, exp_rlt, frac_rlt);

  return result;
}

} // namespace operators