#include "sfu_sqrt_rcp.h"

namespace operators {

uint32_t sfu_rcpsqrt(uint32_t x) {
  uint32_t rlt_f32;            // poly result
  uint32_t result;             // final result
  uint32_t exp_nobias = 0;     // real exp
  bool exp_op_rcpsqrt = false; // add/sub exp_new
  uint32_t exp_new_rcpsqrt = 0;
  uint32_t x_exp_flit; // poly exp
  uint32_t x_frac;     // poly frac
  uint32_t x_flit;     // poly input

  bool sign = signF32UI(x);
  uint32_t exp_org = expF32UI(x);
  uint32_t frac = fracF32UI(x);

  // exception
  if ((!exp_org) && (!frac)) {
    cmodel_exceptionFlags |= softfloat_flag_infinite;
    return packToF32UI(sign, 0xFF, 0); //+0/-0->+inf/-inf
  }
  if (sign) {
    cerr << "invalid operation for negative in rcpsqrt()" << endl;
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    result = defaultNANF32UI;
    return result;
  }
  if (exp_org == 0xFF) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      result = defaultNANF32UI; // NAN->NAN
    } else {
      cmodel_exceptionFlags |= softfloat_flag_underflow;
      result = 0; // +inf->0
    }
    return result;
  }

  if ((!exp_org) && frac) {
    // denormalized
    uint8_t lzd_num = count_leading_zeros(frac, 23);
    frac = frac << (lzd_num + 1);
    exp_nobias = 126 + (lzd_num + 1);
    if (exp_nobias % 2) {
      exp_new_rcpsqrt = (exp_nobias >> 1) + 1;
    } else {
      exp_new_rcpsqrt = (exp_nobias >> 1);
    }
    exp_op_rcpsqrt = 0;
  } else {
    // normalized
    frac = (1 << 23) | frac;
    if (0 < exp_org && exp_org < expBias32UI) {
      exp_nobias = expBias32UI - exp_org;
      exp_op_rcpsqrt = 0;
      if ((exp_nobias & 0x1) == 1) {
        exp_new_rcpsqrt = (exp_nobias >> 1) + 1;
      } else {
        exp_new_rcpsqrt = (exp_nobias >> 1);
      }
    } else if (expBias32UI <= exp_org && exp_org < 0xFF) {
      exp_nobias = exp_org - expBias32UI;
      exp_new_rcpsqrt = (exp_nobias >> 1);
      exp_op_rcpsqrt = 1;
    }
  }
  // get poly input
  uint32_t man_ext; // 25bits
  int8_t seg_addr, subseg_addr, bsize;
  uint64_t coef_addr;
  uint32_t seg_left_man, man_sub, man_tmp, man_sft;
  if (exp_nobias % 2) {
    man_ext = frac * 2; // 1x.xxxxx
  } else {
    man_ext = frac; // 01.xxxx
  }
  if (((man_ext >> 23) & 0x3) == 0x3) { // [24:23]
    seg_addr = 2;
    seg_left_man = (1 << 24) | (fracF32UI(0x40400000) << 1); // 3.0
    bsize = 4;
    man_sub = man_ext - seg_left_man;
    subseg_addr = get_bits(man_sub, 19, 6); // 19~24bits
    man_tmp = get_bits(man_sub, 0, 19);     // 0~18bits
  } else if (((man_ext >> 23) & 0x3) == 0x2 || ((man_ext >> 22) & 0x3) == 0x3) {
    seg_addr = 1;
    seg_left_man = (1 << 23) | fracF32UI(0x3FC00000); // 1.5
    bsize = 5;
    man_sub = man_ext - seg_left_man;
    subseg_addr = get_bits(man_sub, 18, 6);    // 18~23bits
    man_tmp = (get_bits(man_sub, 0, 18)) << 1; // {0~17,0}
  } else {
    seg_addr = 0;
    seg_left_man = (1 << 23) | fracF32UI(0x3F800000); // 1
    bsize = 6;
    man_sub = man_ext - seg_left_man;
    subseg_addr = get_bits(man_sub, 17, 6);    // 17~22bits
    man_tmp = (get_bits(man_sub, 0, 17)) << 2; // {0~16,0}
  }
  coef_addr = (seg_addr << SQRT_LUT_ADDR_SUBBITS_F32) | subseg_addr;
  uint8_t lzd_num = count_leading_zeros(man_tmp, 19);
  if (lzd_num == 19) {
    x_exp_flit = 0;
    x_frac = 0;
  } else {
    x_exp_flit = expBias32UI - bsize - (lzd_num + 1);
    man_sft = man_tmp << (lzd_num + 1);
    x_frac = (get_bits(man_sft, 0, 19)) << 4; //{man_sft[18:0],4b'0}
  }
  x_flit = packToF32UI(sign, x_exp_flit, x_frac);
  // get coef, poly
  info_coef_fp32 info =
      get_info_coef_fp32(rcpsqrt_coef_info_f32, 96, coef_addr);
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp32(info);
  rlt_f32 = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  bool sign_rlt = signF32UI(rlt_f32);
  uint32_t exp_poly = expF32UI(rlt_f32);
  uint32_t frac_rlt = fracF32UI(rlt_f32);
  uint32_t exp_rlt;
  if (exp_op_rcpsqrt) {
    if (exp_poly > exp_new_rcpsqrt) {
      exp_rlt = -exp_new_rcpsqrt + exp_poly;
    } else if (exp_poly == exp_new_rcpsqrt) {
      uint32_t new_frac = (1 << 23) | frac_rlt;
      exp_rlt = 0;
      frac_rlt = get_bits(new_frac, 1, 23);
    } else {
      exp_rlt = 0;
      frac_rlt = get_frac_shift(sign_rlt, frac_rlt, exp_new_rcpsqrt, exp_poly);
    }
  } else {
    exp_rlt = exp_new_rcpsqrt + exp_poly;
  }
  if (exp_rlt >= 255) {
    // cmodel_exceptionFlags |=  softfloat_flag_overflow;
    return defaultPINF32UI;
  }
  result = packToF32UI(sign_rlt, exp_rlt, frac_rlt);

  return result;
}

} // namespace operators