#include "sfu_exp.h"

namespace operators {

uint64_t get_exp_coef_addr(bool sign, uint32_t exp, uint64_t frac,
                           uint64_t dec_frac, uint8_t frac_len) {
  uint64_t coef_addr;
  int8_t seg_addr, subseg_addr, subseg_addr_tmp;
  seg_addr = (sign == 0) ? 1 : 0;
  // get coef, poly
  switch (exp) {
  case 122:
    subseg_addr_tmp = 1;
    break;
  case 123:
    subseg_addr_tmp = (1 << 1) | get_bits(frac, frac_len - 1, 1);
    break;
  case 124:
    subseg_addr_tmp = (1 << 2) | get_bits(frac, frac_len - 2, 2);
    break;
  case 125:
    subseg_addr_tmp = (1 << 3) | get_bits(frac, frac_len - 3, 3);
    break;
  case 126:
    subseg_addr_tmp = (1 << 4) | get_bits(frac, frac_len - 4, 4);
    break;
  default:
    subseg_addr_tmp = 0;
    break;
  }
  if (seg_addr == 0) { // range[-1,0]
    if (exp > 121 && exp <= 126) {
      subseg_addr = 31 - subseg_addr_tmp;
    } else if (exp >= 127 && exp < 135) {
      subseg_addr = 31 - get_bits(dec_frac, frac_len - 5, 5); // 18:22
    } else {
      subseg_addr = 31;
    }
  } else { // range[0,1]
    if (exp > 121 && exp <= 126) {
      subseg_addr = subseg_addr_tmp;
    } else if (exp >= 127 && exp < 135) {
      subseg_addr = get_bits(dec_frac, frac_len - 5, 5); // 18:22
    } else {
      subseg_addr = 0;
    }
  }

  coef_addr = (seg_addr << EXP_LUT_ADDR_SUBBITS_F32) | subseg_addr;
  return coef_addr;
}

uint64_t get_exp_man_tmp(uint32_t exp, uint64_t frac, uint64_t dec_frac,
                         uint8_t frac_len) {
  uint64_t man_tmp;
  if (exp > 121 && exp <= 126) {
    // get coef, poly
    switch (exp) {
    case 122:
      man_tmp = frac;
      break;
    case 123:
      man_tmp = (get_bits(frac, 0, frac_len - 1)) << 1;
      break;
    case 124:
      man_tmp = (get_bits(frac, 0, frac_len - 2)) << 2;
      break;
    case 125:
      man_tmp = (get_bits(frac, 0, frac_len - 3)) << 3;
      break;
    case 126:
      man_tmp = (get_bits(frac, 0, frac_len - 4)) << 4;
      break;
    default:
      man_tmp = 0;
      break;
    }
  } else if (exp >= 127 && exp < 135) {
    man_tmp = (get_bits(dec_frac, 0, frac_len - 5)) << 5;
  } else {
    man_tmp = 0;
  }

  return man_tmp;
}

uint64_t get_exp_coef_addr_f16(bool sign, uint16_t exp, uint32_t frac,
                               uint32_t dec_frac, uint8_t frac_len) {
  uint64_t coef_addr;
  int8_t seg_addr, subseg_addr, subseg_addr_tmp;
  seg_addr = (sign == 0) ? 1 : 0;
  // get coef, poly
  switch (exp) {
  case 12:
    subseg_addr_tmp = 1;
    break;
  case 13:
    subseg_addr_tmp = (1 << 1) | get_bits(frac, frac_len - 1, 1);
    break;
  case 14:
    subseg_addr_tmp = (1 << 2) | get_bits(frac, frac_len - 2, 2);
    break;
  default:
    subseg_addr_tmp = 0;
    break;
  }
  if (seg_addr == 0) { // range[-1,0]
    if (exp > 11 && exp <= 14) {
      subseg_addr = 7 - subseg_addr_tmp;
    } else if (exp >= 15 && exp < 20) {
      subseg_addr = 7 - get_bits(dec_frac, frac_len - 3, 3); // 17:19
    } else {
      subseg_addr = 7;
    }
  } else { // range[0,1]
    if (exp > 11 && exp <= 14) {
      subseg_addr = subseg_addr_tmp;
    } else if (exp >= 15 && exp < 20) {
      subseg_addr = get_bits(dec_frac, frac_len - 3, 3); // 17:19
    } else {
      subseg_addr = 0;
    }
  }

  coef_addr = (seg_addr << EXP_LUT_ADDR_SUBBITS_F16) | subseg_addr;
  return coef_addr;
}

uint32_t get_exp_man_tmp_f16(uint16_t exp, uint32_t frac, uint32_t dec_frac,
                             uint8_t frac_len) {
  uint32_t man_tmp;
  if (exp > 11 && exp <= 14) {
    // get coef, poly
    switch (exp) {
    case 12:
      man_tmp = frac;
      break;
    case 13:
      man_tmp = (get_bits(frac, 0, frac_len - 1)) << 1;
      break;
    case 14:
      man_tmp = (get_bits(frac, 0, frac_len - 2)) << 2;
      break;
    default:
      man_tmp = 0;
      break;
    }
  } else if (exp >= 15 && exp < 20) {
    man_tmp = (get_bits(dec_frac, 0, frac_len - 3)) << 3;
  } else {
    man_tmp = 0;
  }

  return man_tmp;
}
} // namespace operators
