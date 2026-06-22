#include "sfu_tanh.h"
namespace operators {

int8_t get_tanh_seg_addr(uint32_t exp) {
  int8_t seg_addr;
  if (exp < 130) {
    if (exp < 118) {
      seg_addr = 0;
    } else if (exp < 119) {
      seg_addr = 1;
    } else if (exp < 121) {
      seg_addr = 2;
    } else if (exp < 124) {
      seg_addr = 3;
    } else if (exp < 126) {
      seg_addr = 4;
    } else if (exp < 129) {
      seg_addr = 5;
    } else {
      seg_addr = 6; // 129
    }
  } else { // exp>=130
    seg_addr = 0;
  }
  return seg_addr;
}

int8_t get_tanh_seg_bsize(int8_t seg_addr) {
  int8_t bsize = 0;
  switch (seg_addr) {
  case 0:
    bsize = 10;
    break;
  case 1:
    bsize = 9;
    break;
  case 2:
    bsize = 8;
    break;
  case 3:
    bsize = 7;
    break;
  case 4:
    bsize = 6;
    break;
  case 5:
    bsize = 5;
    break;
  case 6:
    bsize = 3;
    break;
  }

  return bsize;
}

uint64_t get_tanh_coef_addr(uint32_t exp, uint32_t frac, int8_t seg_addr) {
  uint64_t coef_addr;
  int8_t subseg_addr;
  uint32_t man_ext = (1 << 23) | frac;
  uint8_t exp_neg_diff =
      (exp < expBias32UI) ? (expBias32UI - exp) : 0; // exp <127
  uint32_t exp_neg_sft =
      (exp_neg_diff > 31) ? 0 : ((man_ext << 7) >> exp_neg_diff);
  uint32_t sub_tmp0 = man_ext - 0x800000; // exp>127  24bits
  uint32_t sub_tmp1 = (exp == expBias32UI) ? (man_ext - 0x400000)
                                           : (man_ext - 0x200000); // 24bits
  uint32_t sub_data;
  switch (seg_addr) {
  case 0:
    if (exp < 117) {
      subseg_addr = 0;
    } else {
      subseg_addr = 1;
    }
    break;
  case 1:
    subseg_addr = 0;
    break;
  case 2:
    sub_data = get_bits(exp_neg_sft, 0, 31) - 0x400000; // 2^(-8)
    subseg_addr = (sub_data >> 22) & 0x7F;              // 22:28
    break;
  case 3:
    sub_data = get_bits(exp_neg_sft, 0, 31) - 0x1000000; // 2^(-7)
    subseg_addr = (sub_data >> 23) & 0x7F;               // 23:29
    break;
  case 4:
    sub_data = get_bits(exp_neg_sft, 0, 31) - 0x8000000; // 2^(-6)
    subseg_addr = (sub_data >> 24) & 0x7F;               // 24:30
    break;
  case 5: //[0.5,4]
    if (exp <= 126) {
      sub_data = get_bits(exp_neg_sft, 0, 31) - 0x20000000; // 2^(-5)
      subseg_addr = get_bits(sub_data, 25, 6);              // 25:30
    } else if (exp == 127) {
      sub_data = (sub_tmp1 << 7);
      subseg_addr = get_bits(sub_data, 25, 6); // 25:30
    } else {                                   // exp>127
      sub_data = (sub_tmp1 << 7);
      subseg_addr = get_bits(sub_data, 24, 7); // 24:30
    }
    break;
  case 6:
    sub_data = (sub_tmp0 << 7);
    subseg_addr = get_bits(sub_data, 25, 6); // 25:30
    break;
  default:
    subseg_addr = 0;
    break;
  }

  coef_addr = (seg_addr << TANH_LUT_ADDR_SUBBITS_F32) | subseg_addr;
  return coef_addr;
}

uint32_t get_tanh_man_tmp(uint32_t exp, uint32_t frac, int8_t seg_addr) {
  uint32_t man_ext = (1 << 23) | frac;
  uint8_t exp_neg_diff =
      (exp < expBias32UI) ? (expBias32UI - exp) : 0; // exp <127
  uint32_t exp_neg_sft =
      (exp_neg_diff > 31) ? 0 : ((man_ext << 7) >> exp_neg_diff);
  uint32_t sub_tmp0 = man_ext - 0x800000; // exp>127  24bits
  uint32_t sub_tmp1 = (exp == expBias32UI) ? (man_ext - 0x400000)
                                           : (man_ext - 0x200000); // 24bits
  uint32_t sub_data, man_tmp;                                      // 24bits
  switch (seg_addr) {
  case 0:
    if (exp < 117) {
      man_tmp = (1 << 23) | frac;
    } else {
      man_tmp = (frac << 1);
    }
    break;
  case 1:
    sub_data = (sub_tmp0 << 7);
    man_tmp = get_bits(sub_data, 7, 23); //[7:29]
    break;
  case 2:
    sub_data =
        get_bits(exp_neg_sft, 0, 31) - 0x400000; // 2^(-8)            // 22:28
    man_tmp = (get_bits(sub_data, 0, 22)) << 2;
    break;
  case 3:
    sub_data =
        get_bits(exp_neg_sft, 0, 31) - 0x1000000; // 2^(-7)            // 23:29
    man_tmp = (get_bits(sub_data, 0, 23)) << 1;
    break;
  case 4:
    sub_data =
        get_bits(exp_neg_sft, 0, 31) - 0x8000000; // 2^(-6)           // 24:30
    man_tmp = get_bits(sub_data, 0, 24);
    break;
  case 5: //[0.5,4]
    if (exp <= 126) {
      sub_data = get_bits(exp_neg_sft, 0, 31) - 0x20000000; // 2^(-5)
      man_tmp = get_bits(sub_data, 1, 24);                  // 1:24
    } else if (exp == 127) {
      sub_data = (sub_tmp1 << 7);
      man_tmp = get_bits(sub_data, 1, 24); // 1:24
    } else {
      // exp>127
      sub_data = (sub_tmp1 << 7);
      man_tmp = get_bits(sub_data, 0, 24); // 0:23
    }
    break;
  case 6:
    sub_data = (sub_tmp0 << 7);
    man_tmp = get_bits(sub_data, 1, 24); // 1:24
    break;
  default:
    man_tmp = 0;
    break;
  }

  return man_tmp;
}

} // namespace operators
