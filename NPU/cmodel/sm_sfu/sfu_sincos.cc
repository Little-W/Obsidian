#include "sfu_sincos.h"

namespace operators {

uint16_t sfu_sincos(uint16_t x, uint8_t op) {
  uint16_t result;      // final result
  uint16_t rlt_f16;     // poly result
  uint16_t x_exp_flit;  // poly exp
  uint16_t x_frac;      // poly frac
  uint16_t x_flit;      // poly input
  bool op_sin;          // sin operator use sin/cos lut
  bool op_cos;          // cos operator use cos/sin lut
  bool res_inv_sin;     //+-sin operator result
  bool res_inv_cos;     //+-cos operator result
  uint8_t special_flag; // 2bits 2b01:cos 0.25->+0;2b10:sin 0.5->+0

  bool sign = signF16UI(x);
  uint8_t exp = expF16UI(x);
  uint16_t frac = fracF16UI(x);
  uint16_t man_ext = (1 << 10) | frac;
  uint64_t coef_addr;
  // exception
  if ((!exp) && (!frac)) {
    if (op == 0) {
      // cmodel_exceptionFlags |= softfloat_flag_underflow;// 20251209:id=1786
      return packToF16UI(sign, 0, 0);
    } else {
      return 0x3C00; // 1
    }
  }
  if (exp == 0x1F) {
    // nan,inf
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return defaultNANF16UI;
  }

  if (exp <= 8) {
    coef_addr = 0;
    res_inv_sin = (op == 0 && sign == 1);
    res_inv_cos = 0;
    op_sin = (op == 0);
    op_cos = (op == 1);
    x_flit = packToF16UI(0, exp, frac);
  } else {
    uint16_t dec_tmp, dec; // 16bits
    if (exp >= 9 && exp <= 14) {
      uint8_t exp_diff = expBias16UI - exp;
      dec_tmp = (man_ext << 5) >> (exp_diff - 1);
    } else if (exp >= expBias16UI && exp <= 24) {
      uint8_t exp_diff = exp - expBias16UI;
      dec_tmp = ((man_ext << 5) << (exp_diff + 1)) & 0xFFFF;
    } else { // exp >24
      dec_tmp = 0;
    }
    uint16_t dec_hig = (dec_tmp >> 12) & 0xF; // dec[15:12]
    if (dec_hig < 2) {                        //[0 0.125)
      res_inv_sin = 0;
      res_inv_cos = 0;
      op_sin = 1;
      op_cos = 1;
      dec = dec_tmp;
      special_flag = 0;
    } else if (dec_hig < 4) { //[0.125 0.25）
      res_inv_sin = 0;
      res_inv_cos = 0;
      op_sin = 0;
      op_cos = 0;
      dec = 0x4000 - dec_tmp; // 0.25-x
      special_flag = 0;
    } else if (dec_hig < 6) { //[0.25 0.375）
      res_inv_sin = 0;
      res_inv_cos = 1;
      op_sin = 0;
      op_cos = 0;
      dec = dec_tmp - 0x4000;     // x-0.25
      special_flag = dec ? 0 : 1; // cos 0.25不取反
    } else if (dec_hig < 8) {     //[0.375 0.5）
      res_inv_sin = 0;
      res_inv_cos = 1;
      op_sin = 1;
      op_cos = 1;
      dec = 0x8000 - dec_tmp; // 0.5-x
      special_flag = 0;
    } else if (dec_hig < 10) { //[0.5 0.625）
      res_inv_sin = 1;
      res_inv_cos = 1;
      op_sin = 1;
      op_cos = 1;
      dec = dec_tmp - 0x8000;            // x-0.5
      special_flag = (dec ? 0 : 1) << 1; // sin 0.5不取反
    } else if (dec_hig < 12) {           //[0.625 0.75）
      res_inv_sin = 1;
      res_inv_cos = 1;
      op_sin = 0;
      op_cos = 0;
      dec = 0xc000 - dec_tmp; // 0.75-x
      special_flag = 0;
    } else if (dec_hig < 14) { //[0.75 0.875)
      res_inv_sin = 1;
      res_inv_cos = 0;
      op_sin = 0;
      op_cos = 0;
      dec = dec_tmp - 0xc000; // x-0.75
      special_flag = 0;
    } else { //[0.875,1)
      res_inv_sin = 1;
      res_inv_cos = 0;
      op_sin = 1;
      op_cos = 1;
      dec = 0x10000 - dec_tmp; // 1-x
      special_flag = 0;
    }
    coef_addr = bitValue(dec, 13) ? 0x7 : ((dec >> 10) & 0x7); // 12:10
    uint16_t frac_mask = (1 << 10) - 1;
    uint16_t dec_low = dec & frac_mask; // 9:0
    uint8_t lzd_num = count_leading_zeros(dec_low, 10);
    uint16_t exp_tmp, frac_tmp;
    if (lzd_num >= 9) {
      exp_tmp = 0;
      frac_tmp = (dec_low << 8) & frac_mask;
    } else {
      exp_tmp = expBias16UI - 6 - (lzd_num + 1);
      frac_tmp = (dec_low << (lzd_num + 1)) & frac_mask;
    }
    x_exp_flit = bitValue(dec, 13) ? (expBias16UI - 6) : exp_tmp;
    x_frac = bitValue(dec, 13) ? 0 : frac_tmp;
    x_flit = packToF16UI(0, x_exp_flit, x_frac);
    // for result
    if (op == 0 && special_flag == 2) {
      res_inv_sin = 0;
    }
    if (op == 1 && special_flag == 1) {
      res_inv_cos = 0;
    }
    res_inv_sin ^= (sign == 1); // x is negative
  }
  // get coef, poly
  bool sin_lut = ((op == 0) && op_sin) || ((op == 1) && (!op_cos));
  bool cos_lut = ((op == 1) && op_cos) || ((op == 0) && (!op_sin));
  info_coef_fp16 info;
  if (sin_lut) {
    info = get_info_coef_fp16(sin_coef_info_f16, 8, coef_addr);
  } else if (cos_lut) {
    info = get_info_coef_fp16(cos_coef_info_f16, 8, coef_addr);
  }
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp16(info);
  rlt_f16 = pol_cal_fp16(x_flit, info.c0.ui, info.c1.ui);
  if ((op == 0 && res_inv_sin) || (op == 1 && res_inv_cos)) {
    bool sign_rlt = signF16UI(rlt_f16);
    uint16_t exp_poly = expF16UI(rlt_f16);
    uint16_t frac_rlt = fracF16UI(rlt_f16);
    result = packToF16UI(!sign_rlt, exp_poly, frac_rlt);
  } else {
    result = rlt_f16;
  }

  return result;
}

uint32_t sfu_sincos(uint32_t x, uint8_t op) {
  uint32_t result;      // final result
  uint32_t rlt_f32;     // poly result
  uint16_t x_exp_flit;  // poly exp
  uint32_t x_frac;      // poly frac
  uint32_t x_flit;      // poly input
  bool op_sin;          // sin operator use sin/cos lut
  bool op_cos;          // cos operator use cos/sin lut
  bool res_inv_sin;     //+-sin operator result
  bool res_inv_cos;     //+-cos operator result
  uint8_t special_flag; // 2bits 2b01:cos 0.25->+0;2b10:sin 0.5->+0

  bool sign = signF32UI(x);
  uint16_t exp = expF32UI(x);
  uint32_t frac = fracF32UI(x);
  uint64_t man_ext = (1 << 23) | frac; // 64bits for shift
  uint64_t seg_addr, sub_addr, coef_addr;
  // exception
  if ((!exp) && (!frac)) {
    if (op == 0) {
      // cmodel_exceptionFlags |= softfloat_flag_underflow; // 20251209:id=1786
      return packToF32UI(sign, 0, 0);
    } else {
      return 0x3F800000; // 1
    }
  }
  if (exp == 0xFF) {
    // nan,inf
    cmodel_exceptionFlags |= softfloat_flag_invalid;
    return defaultNANF32UI;
  }

  if (exp <= 114) {
    coef_addr = 0;
    res_inv_sin = (op == 0 && sign == 1);
    res_inv_cos = 0;
    op_sin = (op == 0);
    op_cos = (op == 1);
    x_flit = packToF32UI(0, exp, frac);
  } else {
    uint64_t dec_tmp, dec; // 35bits
    uint64_t dec_mask = (1UL << 35) - 1;
    if (exp >= 115 && exp <= 126) {
      uint16_t exp_diff = expBias32UI - exp;
      dec_tmp = (man_ext << 11) >> (exp_diff - 1);
    } else if (exp >= expBias32UI && exp <= 149) {
      uint16_t exp_diff = exp - expBias32UI;
      dec_tmp = ((man_ext << 11) << (exp_diff + 1)) & dec_mask;
    } else { // exp >=150
      dec_tmp = 0;
    }
    uint16_t dec_hig = (dec_tmp >> 31) & 0xF; // dec[34:31]
    if (dec_hig < 2) {                        //[0 0.125)
      res_inv_sin = 0;
      res_inv_cos = 0;
      op_sin = 1;
      op_cos = 1;
      dec = dec_tmp;
      special_flag = 0;
    } else if (dec_hig < 4) { //[0.125 0.25）
      res_inv_sin = 0;
      res_inv_cos = 0;
      op_sin = 0;
      op_cos = 0;
      dec = 0x200000000 - dec_tmp; // 0.25-x
      special_flag = 0;
    } else if (dec_hig < 6) { //[0.25 0.375）
      res_inv_sin = 0;
      res_inv_cos = 1;
      op_sin = 0;
      op_cos = 0;
      dec = dec_tmp - 0x200000000; // x-0.25
      special_flag = dec ? 0 : 1;  // cos 0.25不取反
    } else if (dec_hig < 8) {      //[0.375 0.5）
      res_inv_sin = 0;
      res_inv_cos = 1;
      op_sin = 1;
      op_cos = 1;
      dec = 0x400000000 - dec_tmp; // 0.5-x
      special_flag = 0;
    } else if (dec_hig < 10) { //[0.5 0.625）
      res_inv_sin = 1;
      res_inv_cos = 1;
      op_sin = 1;
      op_cos = 1;
      dec = dec_tmp - 0x400000000;       // x-0.5
      special_flag = (dec ? 0 : 1) << 1; // sin 0.5不取反
    } else if (dec_hig < 12) {           //[0.625 0.75）
      res_inv_sin = 1;
      res_inv_cos = 1;
      op_sin = 0;
      op_cos = 0;
      dec = 0x600000000 - dec_tmp; // 0.75-x
      special_flag = 0;
    } else if (dec_hig < 14) { //[0.75 0.875)
      res_inv_sin = 1;
      res_inv_cos = 0;
      op_sin = 0;
      op_cos = 0;
      dec = dec_tmp - 0x600000000; // x-0.75
      special_flag = 0;
    } else { //[0.875,1)
      res_inv_sin = 1;
      res_inv_cos = 0;
      op_sin = 1;
      op_cos = 1;
      dec = 0x800000000 - dec_tmp; // 1-x
      special_flag = 0;
    }
    // get addr
    uint64_t x_sub;    // 35bits
    uint32_t frac_tmp; // 23bits
    uint32_t frac_mask = (1 << 23) - 1;
    uint16_t exp_tmp, bsize;
    if (get_bits(dec, 29, 6)) { // 34:29
      seg_addr = 3;
      x_sub = dec - 0x20000000; // x-0.015625
      sub_addr = bitValue(dec, 32)
                     ? 55
                     : get_bits(x_sub, 26, SIN_LUT_ADDR_SUBBITS_F32); // 31:26
      frac_tmp = get_bits(x_sub, 3, 23);                              // 25:3
      bsize = 9;
    } else if (get_bits(dec, 26, 9)) { // 34:26
      seg_addr = 2;
      x_sub = dec - 0x4000000;                                  // x-0.001953125
      sub_addr = get_bits(x_sub, 25, SIN_LUT_ADDR_SUBBITS_F32); // 30:25
      frac_tmp = get_bits(x_sub, 2, 23);                        // 24:2
      bsize = 10;
    } else if (get_bits(dec, 24, 11)) { // 34:24
      seg_addr = 1;
      x_sub = dec - 0x1000000; // x-0.0004882812
      sub_addr = get_bits(x_sub, 24, SIN_LUT_ADDR_SUBBITS_F32); // 29:24
      frac_tmp = get_bits(x_sub, 1, 23);                        // 23:1
      bsize = 11;
    } else if (get_bits(dec, 24, 11) == 0) { // 34:24
      seg_addr = 0;
      x_sub = dec;                                              // x-0
      sub_addr = get_bits(x_sub, 23, SIN_LUT_ADDR_SUBBITS_F32); // 28:23
      frac_tmp = get_bits(x_sub, 0, 23);                        // 22:0
      bsize = 12;
    }
    coef_addr = (seg_addr << SIN_LUT_ADDR_SUBBITS_F32) | sub_addr;
    uint8_t lzd_num = count_leading_zeros(frac_tmp, 23);
    if (lzd_num == 23) {
      if (bitValue(dec, 32) == 0) {
        exp_tmp = 0;
        frac_tmp = 0;
      } else {
        exp_tmp = expBias32UI - bsize - (lzd_num + 1);
      }
    } else {
      exp_tmp = expBias32UI - bsize - (lzd_num + 1);
    }
    x_exp_flit = bitValue(dec, 32) ? (expBias32UI - 9) : exp_tmp;
    x_frac =
        bitValue(dec, 32) ? frac_tmp : (frac_tmp << (lzd_num + 1)) & frac_mask;
    x_flit = packToF32UI(0, x_exp_flit, x_frac);
    // for result
    if (op == 0 && special_flag == 2) {
      res_inv_sin = 0;
    }
    if (op == 1 && special_flag == 1) {
      res_inv_cos = 0;
    }
    res_inv_sin ^= (sign == 1); // x is negative
  }
  // get coef, poly
  bool sin_lut = ((op == 0) && op_sin) || ((op == 1) && (!op_cos));
  bool cos_lut = ((op == 1) && op_cos) || ((op == 0) && (!op_sin));
  info_coef_fp32 info;
  if (sin_lut) {
    info = get_info_coef_fp32(sin_coef_info_f32, 75, coef_addr);
  } else if (cos_lut) {
    info = get_info_coef_fp32(cos_coef_info_f32, 75, coef_addr);
  }
  // cout << "polynomial input: 0x" << hex << x_flit << ", lut_info : ";
  // print_coef_info_fp32(info);
  rlt_f32 = pol_cal_fp32(x_flit, info.c0.ui, info.c1.ui, info.c2.ui);
  if ((op == 0 && res_inv_sin) || (op == 1 && res_inv_cos)) {
    bool sign_rlt = signF32UI(rlt_f32);
    uint16_t exp_poly = expF32UI(rlt_f32);
    uint32_t frac_rlt = fracF32UI(rlt_f32);
    result = packToF32UI(!sign_rlt, exp_poly, frac_rlt);
  } else {
    result = rlt_f32;
  }

  return result;
}

} // namespace operators