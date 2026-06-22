#include "sfu_exp.h"

namespace operators {

uint32_t sfu_expE(uint32_t x) {
  uint32_t result;
  uint32_t rcp_ln2 =
      0x17154765;    // 29bits 1/ln2= 1.0111 0001 0101 0100 0111 0110 0101
  uint64_t mul_frac; // 53bits
  // uint64_t x_flit;    // x/ln2 42bits(1+8+33)
  uint32_t exp_flit;  // x/ln2 exp
  uint64_t frac_flit; // 33bits
  uint64_t x_dec;     // decimal part
  uint32_t x_int;     // integer part
  uint32_t x_ploy;    // poly input 32bits
  uint32_t exp_ploy;  // exp
  uint32_t frac_ploy; // 23bits

  bool sign = signF32UI(x);
  uint32_t exp = expF32UI(x);
  uint32_t frac = fracF32UI(x);

  // exception
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
  // pre-process 32bits-> 42bits
  uint32_t frac_mask = (1 << 23) - 1;
  uint32_t frac_ext = (1 << 23) | frac; // 24bits
                                        // mul 24+29=53bits -> rnd to 33bits
  mul_frac = (uint64_t)frac_ext * rcp_ln2;
  int8_t rnd_bit0 = round_bit(mul_frac, sign, 51, 33);
  int8_t rnd_bit1 = round_bit(mul_frac, sign, 52, 33);
  uint64_t mul_frac_tmp = get_bits(mul_frac, 18, 33); // 18:50
  uint64_t frac_new_mask = (1UL << 33) - 1;
  // denormlization
  if ((!exp) && frac) {
    if (((mul_frac >> 51) & 0x1) == 1) { // mul=01.xxx
      if (mul_frac_tmp == frac_new_mask && rnd_bit0 == 1) {
        exp_flit = 2;
        frac_flit = 0;
      } else {
        exp_flit = 1;
        frac_flit = mul_frac_tmp + rnd_bit0;
      }
    } else { // mul=00.xxx
      if (mul_frac_tmp == frac_new_mask && rnd_bit0 == 1) {
        exp_flit = 1;
        frac_flit = 0;
      } else {
        exp_flit = 0;
        frac_flit = mul_frac_tmp + rnd_bit0;
      }
    }
  }
  // normalization
  else {
    if (((mul_frac >> 51) & 0x3) == 1) { // mul=01.xxx
      if (mul_frac_tmp == frac_new_mask && rnd_bit0 == 1) {
        exp_flit = exp + 1;
        frac_flit = 0;
      } else {
        exp_flit = exp;
        frac_flit = mul_frac_tmp + rnd_bit0;
      }
    } else if (((mul_frac >> 51) & 0x3) == 2) { // mul=10.xxx
      exp_flit = exp + 1;
      frac_flit = get_bits(mul_frac, 19, 33) + rnd_bit1;
    } else {
      exp_flit = 0;
      frac_flit = 0;
    }
  }

  if (exp_flit > 134) { // e^x
    if (sign) {
      // cmodel_exceptionFlags |=  softfloat_flag_underflow;
      return 0;
    } else {
      // cmodel_exceptionFlags |=  softfloat_flag_overflow;
      return defaultPINF32UI;
    }
  }

  // get integer part and decimal part
  int8_t bsize = 5;
  uint64_t coef_addr;
  uint64_t man_ext, man_sft, man_tmp;
  if (exp_flit >= 0 && exp_flit < 127) {
    x_int = 0;
    x_dec = frac_flit;
  } else {
    uint32_t exp_real = exp_flit - expBias32UI;
    man_ext = (1UL << 33) | frac_flit;
    man_sft = man_ext << exp_real;
    x_int = get_bits(man_sft, 33, 8); // 33:40
    x_dec = get_bits(man_sft, 0, 33); // 0:32
  }
  // get coef, poly
  coef_addr = get_exp_coef_addr(sign, exp_flit, frac_flit, x_dec, 33);
  man_tmp = get_exp_man_tmp(exp_flit, frac_flit, x_dec, 33);
  // float frac
  uint8_t lzd_num = count_leading_zeros(man_tmp, 33);
  if (lzd_num == 33) {
    exp_ploy = 0;
    frac_ploy = 0;
    man_sft = 0; // reused
  } else {
    exp_ploy = expBias32UI - bsize - (lzd_num + 1);
    man_sft = (man_tmp << (lzd_num + 1)) & frac_new_mask;
  }
  // 33->23bits
  rnd_bit0 = round_bit(frac_flit, sign, 33, 23);
  rnd_bit1 = round_bit(man_sft, sign, 33, 23);
  if (exp_flit <= 121) {
    if (get_bits(frac_flit, 10, 23) == frac_mask) // 10:32 all 1
    {
      exp_ploy = exp_flit + 1;
      frac_ploy = 0;
    } else {
      exp_ploy = exp_flit;
      frac_ploy = get_bits(frac_flit, 10, 23) + rnd_bit0;
    }
  } else {
    if (get_bits(man_sft, 10, 23) == frac_mask) // 10:32 all 1
    {
      exp_ploy = exp_ploy + 1;
      frac_ploy = 0;
    } else {
      frac_ploy = get_bits(man_sft, 10, 23) + rnd_bit1;
    }
  }
  x_ploy = packToF32UI(sign, exp_ploy, frac_ploy);
  info_coef_fp32 info = get_info_coef_fp32(exp_coef_info_f32, 64, coef_addr);
  // cout << "integer exp part:" << dec << x_int << ", polynomial input: 0x" <<
  // hex << x_ploy  << "lut_info : "; print_coef_info_fp32(info);
  uint32_t res_rlt = pol_cal_fp32(x_ploy, info.c0.ui, info.c1.ui, info.c2.ui);
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
  // result = fp32_check_setExcept(result);

  return result;
}

uint16_t sfu_expE(uint16_t x) {
  uint16_t result;
  uint32_t rcp_ln2 =
      0x17154765;    // 29bits 1/ln2= 1.0111 0001 0101 0100 0111 0110 0101
  uint64_t mul_frac; // 40bits
  // uint32_t x_flit;    // x/ln2 26bits(1+5+20)
  uint16_t exp_flit;  // x/ln2 exp
  uint32_t frac_flit; // 20bits
  uint32_t x_dec;     // decimal part
  uint16_t x_int;     // integer part
  uint16_t x_ploy;    // poly input 16bits
  uint32_t exp_ploy;  // exp
  uint32_t frac_ploy; // 5bits

  bool sign = signF16UI(x);
  uint16_t exp = expF16UI(x);
  uint16_t frac = fracF16UI(x);

  // exception
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
  // pre-process 16bits-> 42bits
  uint32_t frac_mask = (1 << 10) - 1;
  uint32_t frac_ext = (1 << 10) | frac; // 11bits
                                        // mul 11+29=40bits -> rnd to 20bits
  mul_frac = (uint64_t)frac_ext * rcp_ln2;
  int8_t rnd_bit0 = round_bit(mul_frac, sign, 38, 20);
  int8_t rnd_bit1 = round_bit(mul_frac, sign, 39, 20);
  uint32_t mul_frac_tmp = get_bits(mul_frac, 18, 20); // 18:37
  uint32_t frac_new_mask = (1UL << 20) - 1;
  // denormlization
  if ((!exp) && frac) {
    if (((mul_frac >> 38) & 0x1) == 1) { // mul=01.xxx
      exp_flit = 1;
      frac_flit = mul_frac_tmp + rnd_bit0;
    } else { // mul=00.xxx
      if (mul_frac_tmp == frac_new_mask && rnd_bit0 == 1) {
        exp_flit = 1;
        frac_flit = 0;
      } else {
        exp_flit = 0;
        frac_flit = mul_frac_tmp + rnd_bit0;
      }
    }
  }
  // normalization
  else {
    if (((mul_frac >> 38) & 0x3) == 1) { // mul=01.xxx
      if (mul_frac_tmp == frac_new_mask && rnd_bit0 == 1) {
        exp_flit = exp + 1;
        frac_flit = 0;
      } else {
        exp_flit = exp;
        frac_flit = mul_frac_tmp + rnd_bit0;
      }
    } else if (((mul_frac >> 38) & 0x3) == 2) { // mul=10.xxx
      exp_flit = exp + 1;
      frac_flit = get_bits(mul_frac, 19, 20) + rnd_bit1; // 19:38
    } else {
      exp_flit = 0;
      frac_flit = 0;
    }
  }

  if (exp_flit > 19) { // e^x
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
  if (exp_flit >= 0 && exp_flit < 15) {
    x_int = 0;
    x_dec = frac_flit;
  } else {
    uint32_t exp_real = exp_flit - expBias16UI;
    man_ext = (1UL << 20) | frac_flit;
    man_sft = man_ext << exp_real;    // 25bits
    x_int = get_bits(man_sft, 20, 5); // 20:24
    x_dec = get_bits(man_sft, 0, 20); // 0:19
  }
  // get coef, poly
  coef_addr = get_exp_coef_addr_f16(sign, exp_flit, frac_flit, x_dec, 20);
  man_tmp = get_exp_man_tmp_f16(exp_flit, frac_flit, x_dec, 20);

  // float frac
  uint8_t lzd_num = count_leading_zeros(man_tmp, 20);
  if (lzd_num >= 12) {
    exp_ploy = 0;
    frac_ploy = 0;
    man_sft = (man_tmp << 11) & frac_new_mask; // reused
  } else {
    exp_ploy = expBias16UI - bsize - (lzd_num + 1);
    man_sft = (man_tmp << (lzd_num + 1)) & frac_new_mask;
  }
  // 20->10bits
  rnd_bit0 = round_bit(frac_flit, sign, 20, 10);
  rnd_bit1 = round_bit(man_sft, sign, 20, 10);
  if (exp_flit <= 11) {
    if (get_bits(frac_flit, 10, 10) == frac_mask) // 10:19 all 1
    {
      exp_ploy = exp_flit + 1;
      frac_ploy = 0;
    } else {
      exp_ploy = exp_flit;
      frac_ploy = get_bits(frac_flit, 10, 10) + rnd_bit0;
    }
  } else {
    if (get_bits(man_sft, 10, 10) == frac_mask) // 10:19 all 1
    {
      exp_ploy = exp_ploy + 1;
      frac_ploy = 0;
    } else {
      frac_ploy = get_bits(man_sft, 10, 10) + rnd_bit1;
    }
  }
  x_ploy = packToF16UI(sign, exp_ploy, frac_ploy);
  info_coef_fp16 info = get_info_coef_fp16(exp_coef_info_f16, 16, coef_addr);
  // cout << "integer exp part:" << dec << x_int << ", polynomial input: 0x" <<
  // hex << x_ploy << ", lut_info : "; print_coef_info_fp16(info);
  uint16_t res_rlt = pol_cal_fp16(x_ploy, info.c0.ui, info.c1.ui);
  // post-precess
  bool sign_rlt = signF16UI(res_rlt);
  uint16_t exp_rlt = expF16UI(res_rlt);
  uint16_t frac_rlt = fracF16UI(res_rlt);
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