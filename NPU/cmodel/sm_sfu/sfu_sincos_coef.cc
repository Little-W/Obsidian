#include "sfu_sincos_coef.h"
#include <cmath>
#include <iomanip>
#include <string.h>

namespace operators {

SinCoef::SinCoef(DataType _type) {
  data_type = _type;
  coef_info_f16.clear();
  coef_info_f32.clear();
  if (data_type == FP16) {
    cal_sin_coef_fp16();
  } else if (data_type == FP32) {
    cal_sin_coef_fp32();
  } else {
    cout << "Error data type!!!" << endl;
  }
}

void SinCoef::cal_sin_coef_fp16() {
  cout << "fp16 sin coefficient" << endl;
  coef_info_f16.resize(8);
  info_coef_fp16 info;
  uint64_t lut_base1 = 0x0; // 000~111
  float b_size1 = pow(2, -6);
  float x0, x1;
  float c0, c1;
  // section:(0,2^-3)
  for (float x = 0; x < pow(2, -3); x = x + b_size1) {
    float y = x + b_size1;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x2(x, y);
    c1 = sin_coef_1s_c1(x, x1, x0);
    c0 = sin_coef_1s_c0(x, c1, x0);
    // record info
    info.a_start.f = float_to_float16(x);
    info.a_end.f = float_to_float16(y);
    info.x0.f = float_to_float16(x0);
    info.x1.f = float_to_float16(x1);
    info.c0.ui = ui32_to_coefWidth(c0, FP16_EXP_BITS, FP16_C0_FRAC_BITS);
    info.c1.ui = ui32_to_coefWidth(c1, FP16_EXP_BITS, FP16_C1_FRAC_BITS);
    info.lut_addr = lut_base1;
    print_coef_info_fp16(info);
    coef_info_f16.push_back(info);
    lut_base1++;
    // // print float
    // cout << "c1=" << c1 << ",c0=" << c0 << endl;
  }
}

void SinCoef::cal_sin_coef_fp32() {
  cout << "fp32 sin coefficient" << endl;
  coef_info_f32.resize(75);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 00000000~00000001
  uint64_t lut_base2 = 0x40; // 01000000~01000010
  uint64_t lut_base3 = 0x80; // 10000000~10001101
  uint64_t lut_base4 = 0xC0; // 11000000~11110111
  double b_size1 = pow(2, -12);
  double b_size2 = pow(2, -11);
  double b_size3 = pow(2, -10);
  double b_size4 = pow(2, -9);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:[0,2^-11)
  for (double x = 0; x < pow(2, -11); x = x + b_size1) {
    double y = x + b_size1;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = sin_coef_2s_a1(x, x1, x0);
    a2 = sin_coef_2s_a2(x, x2, x1, x0);
    c0 = sin2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base1;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base1++;
  }
  // section2:[2^-11,2^-9)
  for (double x = pow(2, -11); x < pow(2, -9); x = x + b_size2) {
    double y = x + b_size2;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = sin_coef_2s_a1(x, x1, x0);
    a2 = sin_coef_2s_a2(x, x2, x1, x0);
    c0 = sin2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base2;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base2++;
  }
  // section3:[2^-9,2^-6)
  for (double x = pow(2, -9); x < pow(2, -6); x = x + b_size3) {
    double y = x + b_size3;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = sin_coef_2s_a1(x, x1, x0);
    a2 = sin_coef_2s_a2(x, x2, x1, x0);
    c0 = sin2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base3;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base3++;
  }
  // section4:[2^-6,2^-3)
  for (double x = pow(2, -6); x < pow(2, -3); x = x + b_size4) {
    double y = x + b_size4;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = sin_coef_2s_a1(x, x1, x0);
    a2 = sin_coef_2s_a2(x, x2, x1, x0);
    c0 = sin2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base4;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base4++;
  }
}

CosCoef::CosCoef(DataType _type) {
  data_type = _type;
  coef_info_f16.clear();
  coef_info_f32.clear();
  if (data_type == FP16) {
    cal_cos_coef_fp16();
  } else if (data_type == FP32) {
    cal_cos_coef_fp32();
  } else {
    cout << "Error data type!!!" << endl;
  }
}

void CosCoef::cal_cos_coef_fp16() {
  cout << "fp16 cos coefficient" << endl;
  coef_info_f16.resize(8);
  info_coef_fp16 info;
  uint64_t lut_base1 = 0x0; // 000~111
  float b_size1 = pow(2, -6);
  float x0, x1;
  float c0, c1;
  // section:(0,2^-3)
  for (float x = 0; x < pow(2, -3); x = x + b_size1) {
    float y = x + b_size1;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x2(x, y);
    c1 = cos_coef_1s_c1(x, x1, x0);
    c0 = cos_coef_1s_c0(x, c1, x0);
    // record info
    info.a_start.f = float_to_float16(x);
    info.a_end.f = float_to_float16(y);
    info.x0.f = float_to_float16(x0);
    info.x1.f = float_to_float16(x1);
    info.c0.ui = ui32_to_coefWidth(c0, FP16_EXP_BITS, FP16_C0_FRAC_BITS);
    info.c1.ui = ui32_to_coefWidth(c1, FP16_EXP_BITS, FP16_C1_FRAC_BITS);
    info.lut_addr = lut_base1;
    print_coef_info_fp16(info);
    coef_info_f16.push_back(info);
    lut_base1++;
    // // print float
    // cout << "c1=" << c1 << ",c0=" << c0 << endl;
  }
}

void CosCoef::cal_cos_coef_fp32() {
  cout << "fp32 cos coefficient" << endl;
  coef_info_f32.resize(32);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 00000000~00000001
  uint64_t lut_base2 = 0x40; // 01000000~01000010
  uint64_t lut_base3 = 0x80; // 10000000~10001101
  uint64_t lut_base4 = 0xC0; // 11000000~11110111
  double b_size1 = pow(2, -12);
  double b_size2 = pow(2, -11);
  double b_size3 = pow(2, -10);
  double b_size4 = pow(2, -9);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:[0,2^-11)
  for (double x = 0; x < pow(2, -11); x = x + b_size1) {
    double y = x + b_size1;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = cos_coef_2s_a1(x, x1, x0);
    a2 = cos_coef_2s_a2(x, x2, x1, x0);
    c0 = cos2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base1;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base1++;
  }
  // section2:[2^-11,2^-9)
  for (double x = pow(2, -11); x < pow(2, -9); x = x + b_size2) {
    double y = x + b_size2;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = cos_coef_2s_a1(x, x1, x0);
    a2 = cos_coef_2s_a2(x, x2, x1, x0);
    c0 = cos2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base2;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base2++;
  }
  // section3:[2^-9,2^-6)
  for (double x = pow(2, -9); x < pow(2, -6); x = x + b_size3) {
    double y = x + b_size3;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = cos_coef_2s_a1(x, x1, x0);
    a2 = cos_coef_2s_a2(x, x2, x1, x0);
    c0 = cos2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base3;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base3++;
  }
  // section4:[2^-6,2^-3)
  for (double x = pow(2, -6); x < pow(2, -3); x = x + b_size4) {
    double y = x + b_size4;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = cos_coef_2s_a1(x, x1, x0);
    a2 = cos_coef_2s_a2(x, x2, x1, x0);
    c0 = cos2pi(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base4;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base4++;
  }
}

} // namespace operators
