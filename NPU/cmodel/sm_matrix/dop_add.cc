#include "dop_ops.h"
#include <vector>

namespace operators {
void FP16MulIntermediate_add(FP16MulIntermediate &a, FP16MulIntermediate &b,
                             FP16MulIntermediate &result, int exp_max,
                             int move_bit) {
  uint64_t frac = 0;
  uint64_t sign = 0UL;
  uint16_t exp_diff_a = exp_max - a.exp;
  uint16_t exp_diff_b = exp_max - b.exp;

  uint64_t temp_frac_a = a.frac64;
  uint64_t temp_frac_b = b.frac64;

  // print_uint128_hex(temp_frac);
  if (b.sign != a.sign) {
    sign = temp_frac_a >= temp_frac_b ? a.sign : b.sign;
    sign = temp_frac_a == temp_frac_b ? 0 : sign;
    frac = temp_frac_a >= temp_frac_b ? temp_frac_a - temp_frac_b
                                      : temp_frac_b - temp_frac_a;
  } else {
    sign = a.sign;
    frac = temp_frac_a + temp_frac_b;
  }
  result.sign = sign;
  result.frac64 = frac;
}

void int_type_check(bool &is_int, DataType datatype) {
  switch (datatype) {
  case UINT8:
  case SINT8:
  case SINT8UINT8:
  case UINT8SINT8:
  case SINT16SINT8:
  case UINT16SINT8:
  case SINT16SINT4:
  case SINT16UINT4:
  case UINT16SINT4:
  case UINT16UINT4:
    is_int = true;
    break;
  default:
    is_int = false;
    break;
  }
}

void wallace_add_FP16MulIntermediate(FP16MulIntermediate *a,
                                     FP16MulIntermediate *temp_a,
                                     size_t num_elements, int exp_max,
                                     int move_bit) {

  if (num_elements <= 1) {
    return;
  }
  int temp_num = num_elements;
  int remain = temp_num % 2;
  temp_num /= 2;
  for (int i = 0; i < temp_num; i++) {
    FP16MulIntermediate_add(a[2 * i], a[2 * i + 1], temp_a[i], exp_max,
                            move_bit);
  }
  if (remain) {
    temp_a[temp_num] = a[num_elements - 1];
  }
  for (int i = 0; i < temp_num + remain; i++) {
    a[i] = temp_a[i];
  }
  wallace_add_FP16MulIntermediate(a, temp_a, temp_num + remain, exp_max,
                                  move_bit);
}

uint8_t get_dop_width(DataType data_type) {
  uint8_t result = bit_width_dop_mdp32;
  switch (data_type) {
  case FP16:
  case BF16:
    result = bit_width_dop_fdp16;
    break;
  case NVFP4E2:
    result = bit_width_dop_f4dp64;
    break;
    break;
  }

  return result;
}

uint64_t dop_add(FP16MulIntermediate *uiA, size_t num_elements, uint8_t rnd,
                 DataType data_type) {
  int zero_tag = 0;         // 1 bit
  bool NAN_tag = false;     // 1 bit
  uint8_t Infinity_num = 0; // 1 bit
  bool Infinity_tag = false;
  bool positive_INF_tag = false;
  bool negative_INF_tag = false;
  uint64_t sign = 0UL; // 符号位 (1 bit)
  bool L_add1_en = false;
  bool int_dop_tag = false;
  int exp_max = 0;   // 指数位 (8 bit)
  uint64_t frac = 0; // 尾数位 (128 bit)
  uint8_t dop_width = get_dop_width(data_type);

  uint64_t fp32 = 0;

#pragma max_iterations 128
  for (size_t i = 0; i < num_elements; ++i) {
    zero_tag += uiA[i].zero_tag;
    if (uiA[i].Infinity_tag && uiA[i].sign) {
      negative_INF_tag = true;
      Infinity_num += 1;
    }
    if (uiA[i].Infinity_tag && !uiA[i].sign) {
      positive_INF_tag = true;
      Infinity_num += 1;
    }

    NAN_tag = NAN_tag || uiA[i].NAN_tag;
    // if(NAN_tag) return NAN;
    exp_max = exp_max > uiA[i].exp ? exp_max : uiA[i].exp;
  }
  if (zero_tag == num_elements) {
    return 0;
  }
  // 判断NAN，INF情况
  if (positive_INF_tag && negative_INF_tag) {
    NAN_tag = true;
  }

  if (Infinity_num) {
    Infinity_tag = true;
  }
  // 处理特殊情况（NAN 和 INF）
  if (NAN_tag) {
    return defaultNANF32UI; // 返回 NAN
  }
  if (Infinity_tag) {
    if (positive_INF_tag) {
      return defaultPINF32UI; // 返回 INF
    } else {
      return defaultNINF32UI; // 返回 -INF
    }
  }
  int move_bit = 0;
  switch (data_type) {
  case BF16:
    move_bit = dop_width - 8 - 8;
    break;
  case FP16:
    move_bit = dop_width - 11 - 11;
    break;
  case FP16SINT4:
  case FP16UINT4:
    move_bit = dop_width - 4 - 11;
    break;
  case BF16SINT4:
  case BF16UINT4:
    move_bit = dop_width - 4 - 8;
    break;
  case FP8E4:
  case MXFP8MXFP8:
    move_bit = dop_width - 4 - 4;
    break;
  case NVFP4E2:
    move_bit = dop_width - 4 - 4; // fp4实际上与int5等效
    break;
  case BF16MXFP4:
    move_bit = dop_width - 4 - 8;
    break;
  default:
    move_bit = 0;
    break;
  }

  int_type_check(int_dop_tag, data_type);

  for (size_t i = 0; i < num_elements; ++i) {
    uint16_t exp_diff = exp_max - uiA[i].exp;
    if (exp_diff > 40) {
      uiA[i].frac64 = 0;
    } else {
      uiA[i].frac64 = (uiA[i].frac64 << move_bit) >> exp_diff;
      // printf("uiA[%d].exp:%d, sign:%d before move===", i, uiA[i].exp,
      //        uiA[i].sign);
      // printf("uiA[%d].frac64 after move:", i);
      // print_uint128_hex(uiA[i].frac64);
    }
  }
  int temp_num = num_elements;

  FP16MulIntermediate *temp_a = new FP16MulIntermediate[temp_num];
  wallace_add_FP16MulIntermediate(uiA, temp_a, num_elements, exp_max, move_bit);
  delete[] temp_a;
  FP16MulIntermediate temp_FP16MulIntermediat = uiA[0];
  sign = temp_FP16MulIntermediat.sign;
  frac = temp_FP16MulIntermediat.frac64;

  if (int_dop_tag) {
    if (!frac) {
      return 0;
    }
    if (sign) {
      fp32 = ((1UL << bit_width_dop_idp) - 1UL) & (~frac + 1UL);
      return fp32;
    }
    return frac;
  }
  if (!frac) {
    fp32 |= ((uint64_t)sign << 32 - 1); // 符号位
    // cmodel_exceptionFlags =
    //     softfloat_flag_underflow; // mul结果不全为0,add结果为0,下溢
    return fp32;
  }
  // print_uint128_hex(frac);
  int iter_num = 0;
#pragma max_iterations 64
  while (frac && !(frac & (1UL << 63)) && iter_num < 64) {
    frac <<= 1;
    exp_max--;
    iter_num++;
  }

  switch (data_type) {
  case FP16:
    exp_max = exp_max + 127 - 30 + 64 - dop_width;
    break;
  case BF16:
    exp_max = exp_max + 127 - 254 + 64 - dop_width;
    break;
  case FP24: // 未验证
    exp_max = exp_max + 127 - 254 + 64 - dop_width;
    break;
  case FP16UINT4:
  case FP16SINT4: // 未验证
    exp_max = exp_max + 127 - 15 + 3 + 64 - dop_width;
    break;
  case BF16SINT4:
  case BF16UINT4:
    exp_max = exp_max + 3 + 64 - dop_width;
    break;
  case FP8E4:
  case MXFP8MXFP8:
    exp_max = exp_max + 127 - 14 + 64 - dop_width;
    break;
  case NVFP4E2:
    exp_max = exp_max + 127 + 2 + 64 - dop_width;
    break;
  case BF16MXFP4:
    exp_max = exp_max + 1 + 64 - dop_width;
    break;
  default:
    break;
  }
  frac = frac >> 40;
  if (exp_max < 0) {
#pragma max_iterations 128
    for (int i = 0; i < 24; i++) {
      frac >>= 1;
      exp_max += 1;
      if (exp_max >= 0 || !frac) {
        exp_max = 0;
        break;
      }
    }
  }
  if ((exp_max + (frac >> 23)) >= 255) {
    // cmodel_exceptionFlags = softfloat_flag_overflow;
    fp32 = sign << 31 | defaultPINF32UI;
    fp32 -= 1;
    return fp32;
  }

  fp32 |= ((uint64_t)sign << 31); // 符号位
  fp32 |= ((exp_max) << 23);      // 指数位（加上偏移量 127）
  fp32 += (uint64_t)(frac);       // 尾数位（取低 23 位）
                                  // print_binary_uint32(fp32);
  if (!denormal_out_en) {
    if (!((fp32 >> 23) & 0xff))
      fp32 = ((uint64_t)sign << 31); // 符号位
  }
  if (!((fp32 >> 23) & 0xff)) {
    if (!denormal_out_en) {
      fp32 = ((uint64_t)sign << 31); // 符号位
    }
  }
  // if (fp32 == 0 || fp32 == 0x80000000) {
  //   cmodel_exceptionFlags =
  //       softfloat_flag_underflow; // mul结果不全为0,add结果为0,下溢
  // }
  return fp32; // 将 uint32_t 转换为 float32_t 并返回
}
} // namespace operators