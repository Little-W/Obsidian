#include "sfu_common.h"

namespace operators {

info_coef_fp16 get_info_coef_fp16(const info_coef_fp16 *table, int size,
                                  uint64_t addr) {
  for (int i = 0; i < size; i++) {
    if (table[i].lut_addr == addr)
      return table[i];
  }
  return {0, 0, 0, 0, 0, 0, 0};
}

info_coef_fp32 get_info_coef_fp32(const info_coef_fp32 *table, int size,
                                  uint64_t addr) {
  for (int i = 0; i < size; i++) {
    if (table[i].lut_addr == addr)
      return table[i];
  }
  return {0, 0, 0, 0, 0, 0, 0, 0, 0};
}

uint32_t fp32_check_setExcept(uint32_t data) {
  bool sign = signF32UI(data);
  uint32_t exp = expF32UI(data);
  uint32_t frac = fracF32UI(data);
  if (exp == 0 && frac == 0) {
    cmodel_exceptionFlags |= softfloat_flag_underflow; // den，0
    return 0;
  }
  if (exp == 0xFF) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF32UI; // NAN
    } else {
      cmodel_exceptionFlags |= softfloat_flag_infinite;
      return (sign ? defaultNINF32UI : defaultPINF32UI); // inf
    }
  }

  return data;
}
uint16_t fp16_check_setExcept(uint16_t data) {
  bool sign = signF16UI(data);
  uint16_t exp = expF16UI(data);
  uint16_t frac = fracF16UI(data);
  if (exp == 0 && frac == 0) {
    cmodel_exceptionFlags |= softfloat_flag_underflow; // den，0
    return 0;
  }
  if (exp == 0x1F) {
    if (frac) {
      cmodel_exceptionFlags |= softfloat_flag_invalid;
      return defaultNANF16UI; // NAN
    } else {
      cmodel_exceptionFlags |= softfloat_flag_infinite;
      return (sign ? defaultNINF16UI : defaultPINF16UI); // inf
    }
  }

  return data;
}

int8_t round_bit(uint64_t frac, bool sign, int org_frac_len, int frac_len,
                 uint8_t rnd_mode) {
  int8_t rnd_bit = 0;
  int8_t man_LSB; // remaind low 1 bit
  int8_t guard;   //  truncated hig 1bit
  int8_t sticky;  // reamind of truncated bits
  assert(org_frac_len > frac_len);
  int fracBits = (org_frac_len - frac_len);
  man_LSB = (frac >> fracBits) & 0x1;
  guard = (fracBits < 1) ? 0 : (frac >> (fracBits - 1)) & 0x1;
  sticky = (fracBits <= 2) ? 0 : ((get_bits(frac, 0, fracBits - 1)) ? 1 : 0);
  switch (rnd_mode) {
  case softfloat_round_minMag: // round to zero
    rnd_bit = 0;
    break;
  case softfloat_round_max: // round to positive
    if ((!sign) && (sticky || guard)) {
      rnd_bit = 1;
    } else if (sign) {
      rnd_bit = 0;
    } else {
      // sign=0,guard=0,sticky=0
      rnd_bit = 0;
    }
    break;
  case softfloat_round_min: // round to negative
    if (sign && (sticky || (guard && (!sticky)))) {
      rnd_bit = 1;
    } else if (!sign) {
      rnd_bit = 0;
    } else {
      // sign=1,guard=0,sticky=0
      rnd_bit = 0;
    }
    break;
  case softfloat_round_near_even: // round to even
    if (((!man_LSB) && guard && (!sticky)) || (!guard)) {
      rnd_bit = 0;
    } else if ((man_LSB && guard && (!sticky)) || (guard && sticky)) {
      rnd_bit = 1;
    }
    break;
  case softfloat_round_near_maxMag: // round to away
    if (guard) {
      rnd_bit = 1;
    } else {
      rnd_bit = 0;
    }
    break;
  default:
    rnd_bit = 0;
    break;
  }
  return rnd_bit;
}

uint64_t ui64_to_coefWidth(double d, int exp_len, int frac_len, uint8_t rnd) {
  uint64_t ui = double_to_ui64(d);
  // 64bits: 1+11+52, exp_len = 11, frac_len=52
  if ((exp_len == 11 && frac_len == 52) || ui == 0x0)
    return ui;
  uint64_t coef_ui;
  bool sign = signF64UI(ui);
  uint32_t exp = expF64UI(ui);
  uint_fast64_t frac = fracF64UI(ui);
  uint32_t exp_new = 0;
  uint_fast64_t frac_new = 0;
  uint32_t exp_diff = 0;
  if (exp == 0x7FF) {
    if (frac) {
      // NaN
      exp_new = (1 << exp_len) - 1;
      frac_new = 1 << (frac_len - 1);
      goto uiZ;
    } else {
      // inf
      exp_new = (1 << exp_len) - 1;
      frac_new = 0;
      goto uiZ;
    }
  }
  if (exp_len == 11) {
    exp_new = exp;
  } else if (exp_len < 11) {
    exp_diff = (pow(2, 10) - 1) - (pow(2, exp_len - 1) - 1);
    if (exp >= exp_diff) {
      exp_new = exp - exp_diff;
    } else {
      exp_new = 0;
      frac_new = get_frac_shift(sign, frac, exp_diff, exp, rnd); // TODO:
      goto uiZ;
    }
  } else {
    cerr << "errors" << endl;
  }
  if (frac_len < 52) {
    // round to even
    int fracBits = (52 - frac_len);
    frac_new = frac >> fracBits;
    frac_new += round_bit(frac, sign, 52, frac_len, rnd);
    if (frac_new >= (1UL << frac_len)) {
      frac_new = 0;
      exp_new++;
      if (exp_new >= (uint32_t)(1 << exp_len) - 1) {
        exp_new = (1 << exp_len) - 1;
      }
    }
  } else {
    cerr << "errors" << endl;
  }
  goto uiZ;

uiZ:
  coef_ui = (uint64_t)sign << (exp_len + frac_len) |
            (uint64_t)exp_new << frac_len | frac_new;
  return coef_ui;
}

uint32_t ui32_to_coefWidth(float f, int exp_len, int frac_len, uint8_t rnd) {
  uint32_t ui = float_to_ui32(f);
  // 32bits: 1+8+23, exp_len = 8, frac_len=23
  if ((exp_len == 8 && frac_len == 23) || ui == 0x0)
    return ui;
  uint32_t coef_ui;
  bool sign = signF32UI(ui);
  uint32_t exp = expF32UI(ui);
  uint32_t frac = fracF32UI(ui);
  uint32_t exp_new = 0;
  uint32_t frac_new = 0;
  uint32_t exp_diff = 0;
  if (exp == 0xFF) {
    if (frac) {
      // NaN
      exp_new = (1 << exp_len) - 1;
      frac_new = 1 << (frac_len - 1);
      goto uiZ;
    } else {
      // inf
      exp_new = (1 << exp_len) - 1;
      frac_new = 0;
      goto uiZ;
    }
  }
  if (exp_len == 8) {
    exp_new = exp;
  } else if (exp_len < 8) {
    exp_diff = (pow(2, 7) - 1) - (pow(2, exp_len - 1) - 1);
    if (exp >= exp_diff) {
      exp_new = exp - exp_diff;
    } else {
      exp_new = 0;
      frac_new = get_frac_shift(sign, frac, exp_diff, exp, rnd);
      goto uiZ;
    }
  } else {
    cerr << "errors" << endl;
  }
  if (frac_len < 23) {
    // round to even
    int fracBits = (23 - frac_len);
    frac_new = frac >> fracBits;
    frac_new += round_bit(frac, sign, 23, frac_len, rnd);
    if (frac_new >= (uint32_t)(1 << frac_len)) {
      frac_new = 0;
      exp_new++;
      if (exp_new >= (uint32_t)(1 << exp_len) - 1) {
        exp_new = (1 << exp_len) - 1;
      }
    }
  } else {
    cerr << "errors" << endl;
  }
  goto uiZ;

uiZ:
  coef_ui =
      (uint32_t)sign << (exp_len + frac_len) | exp_new << frac_len | frac_new;
  return coef_ui;
}

uint32_t pol_cal_fp32(uint32_t data_flit, uint64_t c0, uint64_t c1, uint64_t c2,
                      uint8_t rnd) {
  uint32_t pol_cal_res; // final result
  uint32_t data_man_ext;
  uint64_t c2_man_ext, c1_man_ext, c0_man_ext; // {1,frac}
  uint64_t frac_pad_mask = (1UL << 57) - 1;
  uint64_t mult_c2_x; // frac pad 57bits
  uint64_t mult_c1_x;
  uint64_t mult_x_x;
  uint64_t acc_frac_mask = (1UL << (FP32_ACC_FRAC_BITS + 1)) - 1;
  uint64_t acc_man_tmp; // 60bits [acc_sign,acc_man]
  uint64_t acc_man;     // 59bits
  bool acc_sign;
  uint16_t me_exp; // 10bits
  uint64_t me_man; // 59bits
  // uint64_t me_exp_norm; // 10bits
  // uint64_t me_man_norm; // 59bits
  bool out_sign;     // result
  uint16_t out_exp;  // 8bits
  uint32_t out_frac; // 23bits

  // pre_process
  bool sign_data = signF32UI(data_flit);
  uint8_t exp_data = expF32UI(data_flit);
  uint32_t frac_data = fracF32UI(data_flit);
  bool sign_c0 = (bool)(c0 >> (FP32_C0_FRAC_BITS + FP32_EXP_BITS));
  uint8_t exp_c0 = (uint8_t)((c0 >> FP32_C0_FRAC_BITS) & 0xFF);
  uint64_t frac_c0 = c0 & ((1UL << FP32_C0_FRAC_BITS) - 1);
  bool sign_c1 = (bool)(c1 >> (FP32_C1_FRAC_BITS + FP32_EXP_BITS));
  uint8_t exp_c1 = (uint8_t)((c1 >> FP32_C1_FRAC_BITS) & 0xFF);
  uint64_t frac_c1 = c1 & ((1UL << FP32_C1_FRAC_BITS) - 1);
  bool sign_c2 = (bool)(c2 >> (FP32_C2_FRAC_BITS + FP32_EXP_BITS));
  uint8_t exp_c2 = (uint8_t)((c2 >> FP32_C2_FRAC_BITS) & 0xFF);
  uint64_t frac_c2 = c2 & ((1UL << FP32_C2_FRAC_BITS) - 1);
  // align
  bool sign_x_c2 = sign_c2;
  bool sign_x_c1 = sign_data ^ sign_c1;
  uint16_t exp_sum_c2_x =
      (!exp_data && frac_data)
          ? (2 + exp_c2)
          : (exp_data + exp_data + exp_c2); // denormalized special
  uint16_t exp_sum_c1_x = (!exp_data && frac_data)
                              ? (1 + exp_c1 + expBias32UI)
                              : (exp_data + exp_c1 + expBias32UI);
  uint16_t exp_sum_c0 = exp_c0 + 2 * expBias32UI;
  uint16_t exp_max = max(exp_sum_c0, max(exp_sum_c1_x, exp_sum_c2_x));
  uint16_t c2_x_exp_diff = exp_max - exp_sum_c2_x;
  uint16_t c1_x_exp_diff = exp_max - exp_sum_c1_x;
  uint16_t c0_exp_diff = exp_max - exp_sum_c0;
  // mult
  data_man_ext = exp_data ? ((1 << 23) | frac_data) : frac_data;
  c2_man_ext = exp_c2 ? ((1UL << FP32_C2_FRAC_BITS) | frac_c2) : frac_c2;
  c1_man_ext = exp_c1 ? ((1UL << FP32_C1_FRAC_BITS) | frac_c1) : frac_c1;
  c0_man_ext = exp_c0 ? ((1UL << FP32_C0_FRAC_BITS) | frac_c0) : frac_c0;
  uint64_t mult_x_x_org = (uint64_t)data_man_ext * data_man_ext;
  uint64_t mult_c1_x_org = c1_man_ext * data_man_ext;
  mult_x_x = get_bits(mult_x_x_org, 23, 25); // [23:47] high 25bit
  mult_c2_x = ((c2_man_ext * mult_x_x) << 15) &
              frac_pad_mask; // 42bit->57bits {man,15b0}
  mult_c1_x = ((get_bits(mult_c1_x_org, 19, 31)) << 25) &
              frac_pad_mask; // 31bit->57bits {1b0,man,25b0}
  c0_man_ext =
      (c0_man_ext << 23) & frac_pad_mask; // 31bit->57bits {2b00, man,23b0}
  uint64_t mult_c2_x_man_ext, mult_c1_x_man_ext,
      mult_c0_man_ext; // 60bits {3b111,man} or {3b0, man}
  mult_c2_x = (c2_x_exp_diff > 60) ? 0 : (mult_c2_x >> c2_x_exp_diff);
  mult_c1_x = (c1_x_exp_diff > 60) ? 0 : (mult_c1_x >> c1_x_exp_diff);
  c0_man_ext = (c0_exp_diff > 60) ? 0 : (c0_man_ext >> c0_exp_diff);
  // binary complement code
  mult_c2_x_man_ext =
      (sign_x_c2 ? ((~mult_c2_x) + 1) : mult_c2_x) & acc_frac_mask;
  mult_c1_x_man_ext =
      (sign_x_c1 ? ((~mult_c1_x) + 1) : mult_c1_x) & acc_frac_mask;
  mult_c0_man_ext =
      (sign_c0 ? ((~c0_man_ext) + 1) : c0_man_ext) & acc_frac_mask;
  acc_man_tmp = (mult_c2_x_man_ext + mult_c1_x_man_ext + mult_c0_man_ext) &
                acc_frac_mask; // acc sum
  acc_sign = (acc_man_tmp >> FP32_ACC_FRAC_BITS) & 0x1;
  acc_man = get_bits(acc_man_tmp, 0, FP32_ACC_FRAC_BITS);
  me_man = acc_sign ? ((~acc_man) + 1) : acc_man; // 0:58
  me_exp = exp_max - 2 * expBias32UI;             // exp_max >=254
  // normal && round: 1bit+10bit+59bits -> 1bit+8bit+23bits
  uint64_t norm_rnd_frac;
  uint16_t norm_rnd_exp;
  norm_round(norm_rnd_exp, norm_rnd_frac, acc_sign, me_exp, me_man, 9, 8, 59,
             23, true, rnd);
  out_sign = acc_sign;
  out_exp = norm_rnd_exp;
  out_frac = norm_rnd_frac;

  pol_cal_res = packToF32UI(out_sign, out_exp, out_frac);
  return pol_cal_res;
}

uint16_t pol_cal_fp16(uint16_t data_flit, uint32_t c0, uint32_t c1,
                      uint8_t rnd) {
  uint16_t pol_cal_res; // final result
  uint16_t data_man_ext;
  uint16_t c1_man_ext, c0_man_ext; // {1,frac}
  uint32_t mult_c1_x;              // frac pad 26bits
  uint32_t acc_c0_ext;
  uint32_t acc_frac_mask = (1UL << (FP16_ACC_FRAC_BITS + 1)) - 1;
  uint32_t acc_man_tmp; // 28bits
  uint32_t acc_man;     // 27bits
  bool acc_sign;
  uint16_t me_exp; // 6bits
  uint32_t me_man; // 27bits
  // uint32_t me_man_norm; // 27bits
  // uint32_t me_man_mask; // 26bits

  bool out_sign;     // result
  uint8_t out_exp;   // 5bits
  uint16_t out_frac; // 10bits

  // pre_process
  bool sign_data = signF16UI(data_flit);
  uint8_t exp_data = expF16UI(data_flit);
  uint32_t frac_data = fracF16UI(data_flit);
  bool sign_c0 = (bool)(c0 >> (FP16_C0_FRAC_BITS + FP16_EXP_BITS));
  uint8_t exp_c0 = (uint8_t)((c0 >> FP16_C0_FRAC_BITS) & 0x1F);
  uint64_t frac_c0 = c0 & ((1UL << FP16_C0_FRAC_BITS) - 1);
  bool sign_c1 = (bool)(c1 >> (FP16_C1_FRAC_BITS + FP16_EXP_BITS));
  uint8_t exp_c1 = (uint8_t)((c1 >> FP16_C1_FRAC_BITS) & 0x1F);
  uint64_t frac_c1 = c1 & ((1UL << FP16_C1_FRAC_BITS) - 1);
  // align
  bool sign_x_c1 = sign_data ^ sign_c1;
  uint16_t exp_sum_c1_x =
      (!exp_data && frac_data) ? (1 + exp_c1) : (exp_data + exp_c1);
  uint16_t exp_sum_c0 = exp_c0 + expBias16UI;
  uint16_t exp_max = max(exp_sum_c0, exp_sum_c1_x);
  uint16_t c1_x_exp_diff = exp_max - exp_sum_c1_x;
  uint16_t c0_exp_diff = exp_max - exp_sum_c0;
  // mult
  data_man_ext = exp_data ? ((1 << 10) | frac_data) : frac_data;
  c1_man_ext = exp_c1 ? ((1UL << FP16_C1_FRAC_BITS) | frac_c1) : frac_c1;
  c0_man_ext = exp_c0 ? ((1UL << FP16_C0_FRAC_BITS) | frac_c0) : frac_c0;
  uint32_t mult_c1_x_org = (uint32_t)c1_man_ext * data_man_ext; // 25bits
  mult_c1_x = (mult_c1_x_org << 1);                             // 26bits
  acc_c0_ext = (c0_man_ext << 9); //{1b0, c0_man,9b0}
  uint32_t mult_c1_x_man_ext,
      mult_c0_man_ext; // 28bits {2b11,man} or {2b0, man}
  mult_c1_x = (c1_x_exp_diff > 26) ? 0 : (mult_c1_x >> c1_x_exp_diff);
  acc_c0_ext = (c0_exp_diff > 26) ? 0 : (acc_c0_ext >> c0_exp_diff);
  mult_c1_x_man_ext =
      (sign_x_c1 ? ((~mult_c1_x) + 1) : mult_c1_x) & acc_frac_mask;
  mult_c0_man_ext =
      (sign_c0 ? ((~acc_c0_ext) + 1) : acc_c0_ext) & acc_frac_mask;
  acc_man_tmp =
      (mult_c1_x_man_ext + mult_c0_man_ext) & acc_frac_mask; // acc sum
  acc_sign = (acc_man_tmp >> FP16_ACC_FRAC_BITS) & 0x1;      // 27
  acc_man = get_bits(acc_man_tmp, 0, FP16_ACC_FRAC_BITS);    // 0:26
  me_man = acc_sign ? ((~acc_man) + 1) : acc_man;            // 0:26
  me_exp = exp_max - expBias16UI;                            // exp_max >=15
  // normal && round: 1bit+6bit+27bits -> 1bit+5bit+10bits
  uint64_t norm_rnd_frac;
  uint16_t norm_rnd_exp;
  norm_round(norm_rnd_exp, norm_rnd_frac, acc_sign, me_exp, me_man, 6, 5, 27,
             10, false, rnd);
  out_sign = acc_sign;
  out_exp = norm_rnd_exp;
  out_frac = norm_rnd_frac;

  pol_cal_res = packToF16UI(out_sign, out_exp, out_frac);
  return pol_cal_res;
}

void norm_round(uint16_t &exp_out, uint64_t &man_out, bool sign,
                uint16_t exp_in, uint64_t man_in, int exp_in_width,
                int exp_out_width, int frac_in_width, int frac_out_width,
                bool f32_format, uint8_t rnd) {
  // frac_in xxxxx.xxx or xx.xxx, frac_out 00/01.xxx
  assert(exp_in_width > 0 && exp_in_width <= 16 && exp_out_width > 0 &&
         exp_out_width <= 16 && exp_in_width >= exp_out_width);
  assert(frac_in_width <= 64 && frac_out_width <= 64 &&
         frac_in_width >= frac_out_width);

  uint16_t exp_in_mask = (1 << exp_in_width) - 1;
  uint16_t exp_out_mask = (1 << exp_out_width) - 1;
  uint64_t frac_out_mask = (1UL << frac_out_width) - 1;
  uint64_t lzd_man = (man_in << 5); // len=frac_in_width+5:59->64,27->32
  int lzd_num = f32_format ? count_leading_zeros(lzd_man, 64)
                           : count_leading_zeros(lzd_man, 32);
  uint16_t bias_exp = f32_format ? (exp_in + 4) : (exp_in + 2);
  uint64_t bias_man = man_in; //{1b0,man_in}
  uint64_t norm_man;
  uint16_t norm_exp;
  bool is_dennorm;
  if (bias_exp <= lzd_num) {
    norm_man = bias_man << bias_exp;
    norm_exp = 1;
    is_dennorm = 1;
  } else {
    norm_man = (bias_man << 1) << lzd_num;
    norm_exp = (bias_exp + (~(lzd_num & exp_in_mask) + 1)) & exp_out_mask;
    is_dennorm = 0;
  }
  // round
  int rnd_in = frac_in_width + 2;
  int rnd_out = frac_out_width + 2;
  uint64_t frac_rnd =
      ((rnd_in - rnd_out) > 64) ? 0 : (norm_man >> (rnd_in - rnd_out));
  int8_t rnd_bit = round_bit(norm_man, sign, rnd_in, rnd_out, rnd);
  frac_rnd = frac_rnd + rnd_bit;
  // judge
  if (is_dennorm) {
    if (bitValue(frac_rnd, frac_out_width)) {
      man_out = frac_rnd & frac_out_mask;
      exp_out = 1;
    } else {
      // uint64_t frac_tmp = frac_rnd << 1;
      // man_out = (frac_rnd << 1) & frac_out_mask;
      // if (bitValue(frac_tmp, frac_out_width)) {
      //   exp_out = 1;
      // } else {
      //   exp_out = 0;
      // }
      man_out = frac_rnd & frac_out_mask;
      exp_out = 0;
    }
  } else {
    if (bitValue(frac_rnd, frac_out_width + 1)) {
      man_out = 0;
      exp_out = norm_exp + 1;
    } else {
      man_out = frac_rnd & frac_out_mask;
      exp_out = norm_exp;
    }
  }
}

uint32_t get_frac_shift(bool sign, uint32_t frac, uint32_t exp_big,
                        uint32_t exp_lit, uint8_t rnd) {
  assert(exp_big >= exp_lit);
  uint32_t frac_new;
  uint8_t post_exp_diff = exp_big - exp_lit;
  uint32_t man_ext = (1 << 23) | frac;
  uint32_t frac_mask = (1 << 23) - 1; // 24bits
  uint64_t frac_sft =
      (post_exp_diff > 48)
          ? 0
          : (((uint64_t)man_ext << 24) >> post_exp_diff);        // 48bits
  int8_t rnd_bit = round_bit(frac_sft, sign, 48, 23, rnd);       // 23bits
  frac_new = (get_bits(frac_sft, 25, 23) + rnd_bit) & frac_mask; // 25:47
  return frac_new;
}
uint16_t get_frac_shift_f16(bool sign, uint16_t frac, uint16_t exp_big,
                            uint16_t exp_lit, uint8_t rnd) {
  assert(exp_big >= exp_lit);
  uint16_t frac_new;
  uint8_t post_exp_diff = exp_big - exp_lit;
  uint16_t man_ext = (1 << 10) | frac;
  uint16_t frac_mask = (1 << 10) - 1; // 11bits
  uint32_t frac_sft =
      (post_exp_diff > 22)
          ? 0
          : (((uint32_t)man_ext << 11) >> post_exp_diff);        // 22bits
  int8_t rnd_bit = round_bit(frac_sft, sign, 22, 10, rnd);       // 10bits
  frac_new = (get_bits(frac_sft, 12, 10) + rnd_bit) & frac_mask; // 12:21
  return frac_new;
}

} // namespace operators
