#include "sfu_exp.h"

namespace operators {

uint32_t sfu_exp(uint32_t x) {
  uint32_t result;
  uint32_t x_dec;    // decimal part
  uint32_t x_int;    // integer part
  uint32_t x_flit;   // poly input
  uint32_t exp_flit; // poly input exp
  uint32_t frac_flit;

  bool sign = signF32UI(x);
  uint32_t exp = expF32UI(x);
  uint32_t frac = fracF32UI(x);
  uint32_t frac_mask = (1 << 23) - 1;

  if ((!exp) && (!frac)) {                 // 0
    return packToF32UI(0, expBias32UI, 0); // 1
  }
  if (exp == 0xFF) {
    if ((!sign) && (!frac)) { //+inf
      cmodel_exceptionFlags |= softfloat_flag_infinite;
      return defaultPINF32UI;
    } else if (sign && (!frac)) {
      cmodel_exceptionFlags |= softfloat_flag_underflow;
      return 0; //-inf
    } else if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF32UI; // nan
    }
  }
  if (exp > 134) { // 2^x
    if (sign) {
      // cmodel_exceptionFlags |=  softfloat_flag_underflow; //FIXME: rtl not
      // set
      return 0;
    } else {
      // cmodel_exceptionFlags |=  softfloat_flag_infinite;
      return defaultPINF32UI;
    }
  }
  // get integer part and decimal part
  int8_t bsize = 5;
  uint64_t coef_addr;
  uint32_t man_ext, man_sft, man_tmp;
  if (exp >= 0 && exp < 127) {
    x_int = 0;
    x_dec = frac;
  } else {
    uint32_t exp_real = exp - expBias32UI;
    man_ext = (1 << 23) | frac;
    man_sft = man_ext << exp_real;
    x_int = get_bits(man_sft, 23, 8); // 23:30
    x_dec = get_bits(man_sft, 0, 23); // 0:22
  }
  // get coef, poly
  coef_addr = get_exp_coef_addr(sign, exp, frac, x_dec, 23);
  man_tmp = get_exp_man_tmp(exp, frac, x_dec, 23);
  // float frac
  uint8_t lzd_num = count_leading_zeros(man_tmp, 23);
  if (lzd_num == 23) {
    exp_flit = 0;
    frac_flit = 0;
  } else {
    exp_flit = expBias32UI - bsize - (lzd_num + 1);
    frac_flit = man_tmp << (lzd_num + 1);
    frac_flit &= frac_mask;
  }
  // for poly
  if (exp <= 121) {
    x_flit = x;
  } else {
    x_flit = packToF32UI(sign, exp_flit, frac_flit);
  }
  info_coef_fp32 info = get_info_coef_fp32(exp_coef_info_f32, 64, coef_addr);
  // cout << "integer exp part:" << dec << x_int << ", polynomial input: 0x" <<
  // hex << x_flit  << "lut_info : "; print_coef_info_fp32(info);
  uint32_t res_rlt = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  // post-precess
  bool sign_rlt = signF32UI(res_rlt);
  uint32_t exp_rlt = expF32UI(res_rlt);
  uint32_t frac_rlt = fracF32UI(res_rlt);
  if (sign == 0) {
    if (exp_rlt + x_int >= 255) {
      // cmodel_exceptionFlags |=  softfloat_flag_overflow;
      return defaultPINF32UI; // +inf
    } else {
      result = packToF32UI(sign_rlt, exp_rlt + x_int, frac_rlt);
    }
  } else { // negative
    if (x_int == exp_rlt) {
      uint32_t new_frac = (1 << 23) | frac_rlt;
      result = packToF32UI(sign_rlt, 0, get_bits(new_frac, 1, 23));
    } else if (x_int > exp_rlt) {
      uint32_t new_frac = get_frac_shift(sign_rlt, frac_rlt, x_int, exp_rlt);
      result = packToF32UI(sign_rlt, 0, new_frac);
    } else {
      result = packToF32UI(sign_rlt, exp_rlt - x_int, frac_rlt);
    }
  }

  return result;
}

uint16_t sfu_exp(uint16_t x) {
  uint16_t result;
  uint16_t x_dec;    // decimal part
  uint16_t x_int;    // integer part
  uint16_t x_flit;   // poly input
  uint16_t exp_flit; // poly input exp
  uint16_t frac_flit;

  bool sign = signF16UI(x);
  uint16_t exp = expF16UI(x);
  uint16_t frac = fracF16UI(x);
  uint16_t frac_mask = (1 << 10) - 1;

  if ((!exp) && (!frac)) {                 // 0
    return packToF16UI(0, expBias16UI, 0); // 1
  }
  if (exp == 0x1F) {
    if ((!sign) && (!frac)) { //+inf
      cmodel_exceptionFlags |= softfloat_flag_infinite;
      return defaultPINF16UI;
    } else if (sign && (!frac)) {
      cmodel_exceptionFlags |= softfloat_flag_underflow;
      return 0; //-inf
    } else if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF16UI; // nan
    }
  }
  if (exp > 19) { // 2^x
    if (sign) {
      // cmodel_exceptionFlags |=  softfloat_flag_underflow;
      return 0;
    } else {
      // cmodel_exceptionFlags |=  softfloat_flag_overflow;
      return defaultPINF16UI;
    }
  }
  // get integer part and decimal part
  int8_t bsize = 3;
  uint64_t coef_addr;
  uint32_t man_ext, man_sft, man_tmp;
  if (exp >= 0 && exp < 15) {
    x_int = 0;
    x_dec = frac;
  } else {
    uint16_t exp_real = exp - expBias16UI;
    man_ext = (1 << 10) | frac;
    man_sft = man_ext << exp_real;
    x_int = get_bits(man_sft, 10, 5); // 10:14
    x_dec = get_bits(man_sft, 0, 10); // 0:9
  }
  // get coef, poly
  coef_addr = get_exp_coef_addr_f16(sign, exp, frac, x_dec, 10);
  man_tmp = get_exp_man_tmp_f16(exp, frac, x_dec, 10);
  // float frac
  uint8_t lzd_num = count_leading_zeros(man_tmp, 10);
  if (lzd_num == 10) {
    exp_flit = 0;
    frac_flit = 0;
  } else {
    exp_flit = expBias16UI - bsize - (lzd_num + 1);
    frac_flit = man_tmp << (lzd_num + 1);
    frac_flit &= frac_mask;
  }
  // for poly
  if (exp <= 11) {
    x_flit = x;
  } else {
    x_flit = packToF16UI(sign, exp_flit, frac_flit);
  }
  info_coef_fp16 info = get_info_coef_fp16(exp_coef_info_f16, 16, coef_addr);
  // cout << "integer exp part:" << dec << x_int << ", polynomial input: 0x" <<
  // hex << x_flit << ", lut_info : "; print_coef_info_fp16(info);
  uint16_t res_rlt = pol_cal_fp16(x_flit, info.c0.ui, info.c1.ui);
  // post-precess
  bool sign_rlt = signF16UI(res_rlt);
  uint32_t exp_rlt = expF16UI(res_rlt);
  uint32_t frac_rlt = fracF16UI(res_rlt);
  if (sign == 0) {
    if (exp_rlt + x_int >= 31) {
      // cmodel_exceptionFlags |=  softfloat_flag_overflow;
      return defaultPINF16UI; // +inf
    } else {
      result = packToF16UI(sign_rlt, exp_rlt + x_int, frac_rlt);
    }
  } else { // negative
    if (x_int == exp_rlt) {
      uint32_t new_frac = (1 << 10) | frac_rlt;
      result = packToF16UI(sign_rlt, 0, get_bits(new_frac, 1, 10));
    } else if (x_int > exp_rlt) {
      uint16_t new_frac =
          get_frac_shift_f16(sign_rlt, frac_rlt, x_int, exp_rlt);
      result = packToF16UI(sign_rlt, 0, new_frac);
    } else {
      result = packToF16UI(sign_rlt, exp_rlt - x_int, frac_rlt);
    }
  }

  return result;
}

} // namespace operators