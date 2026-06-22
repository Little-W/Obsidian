#include "sfu_sqrt_coef.h"
#include <cmath>
#include <iomanip>
#include <string.h>

namespace operators {

SqrtCoef::SqrtCoef(DataType _type, FUNC_TYPE _ftype) {
  data_type = _type;
  func_type = _ftype;
  coef_info_f16.clear();
  coef_info_f32.clear();
  if (data_type == FP16) {
    switch (func_type) {
    case SQRT:
      cal_sqrt_coef_fp16();
      break;
    case RCPSQRT:
      cal_rcpsqrt_coef_fp16();
      break;
    case RCP:
      cal_rcp_coef_fp16();
      break;
    default:
      cout << "Error data type!!!" << endl;
      break;
    }
  } else if (data_type == FP32) {
    switch (func_type) {
    case SQRT:
      cal_sqrt_coef_fp32();
      break;
    case RCPSQRT:
      cal_rcpsqrt_coef_fp32();
      break;
    case RCP:
      cal_rcp_coef_fp32();
      break;
    default:
      cout << "Error data type!!!" << endl;
      break;
    }
  } else {
    cout << "Error data type!!!" << endl;
  }
}
void SqrtCoef::cal_sqrt_coef_fp16() {
  cout << "fp16 sqrt coefficient" << endl;
  coef_info_f16.resize(8);
  info_coef_fp16 info;
  // FIXME:addr increase or decrease
  uint64_t lut_base1 = 0x0; // 0000~"0011";
  uint64_t lut_base2 = 0x8; // 1000~"1011";
  float b_size1 = pow(2, -2);
  float b_size2 = pow(2, -1);
  float x0, x1;
  float c0, c1;
  // section1:[1,2)
  //  cout << left << "[1," << setw(16) << "2):" << setw(16) << "x1" << setw(16)
  //  << "x0" << setw(16) << "c1" << setw(16)
  //       << "c0" << endl;
  for (float x = 1; x < 2; x = x + b_size1) {
    float y = x + b_size1;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = sqrt_coef_1s_c1(x, x1, x0);
    c0 = sqrt_coef_1s_c0(x, c1, x0);

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x1 << setw(16) << x0 << setw(16)
    //      << c1 << setw(16) << c0 << endl;
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
  }
  // section2:[2,4)
  for (float x = 2; x < 4; x = x + b_size2) {
    float y = x + b_size2;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = sqrt_coef_1s_c1(x, x1, x0);
    c0 = sqrt_coef_1s_c0(x, c1, x0);
    // record info
    info.a_start.f = float_to_float16(x);
    info.a_end.f = float_to_float16(y);
    info.x0.f = float_to_float16(x0);
    info.x1.f = float_to_float16(x1);
    info.c0.ui = ui32_to_coefWidth(c0, FP16_EXP_BITS, FP16_C0_FRAC_BITS);
    info.c1.ui = ui32_to_coefWidth(c1, FP16_EXP_BITS, FP16_C1_FRAC_BITS);
    info.lut_addr = lut_base2;
    print_coef_info_fp16(info);
    coef_info_f16.push_back(info);
    lut_base2++;
  }
}

void SqrtCoef::cal_sqrt_coef_fp32() {
  cout << "fp32 sqrt coefficient" << endl;
  coef_info_f32.resize(56);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 0000000~"0001111";
  uint64_t lut_base2 = 0x40; // 1000000~"1100111";
  double b_size1 = pow(2, -5);
  double b_size2 = pow(2, -4);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:[1,1.5)
  // cout << left << "[1," << setw(16) << "1.5):" << setw(16) << "x2" <<
  // setw(16) << "x1" << setw(16) << "x0" << setw(16)
  //      << "c2" << setw(16) << "c1" << setw(16) << "c0" << endl;
  for (double x = 1; x < 1.5; x = x + b_size1) {
    double y = x + b_size1;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = sqrt_coef_2s_a1(x, x1, x0);
    a2 = sqrt_coef_2s_a2(x, x2, x1, x0);
    c0 = sqrt(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x2 << setw(16) << x1 << setw(16)
    //      << x0 << setw(16) << c2 << setw(16) << c1 << setw(16) << c0 << endl;
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
#if 0
    info_coef_double info_f;
    info_f.a_start = x;
    info_f.a_end = y;
    info_f.x0 = x0;
    info_f.x1 = x1;
    info_f.x2 = x2;
    info_f.c0 = c0;
    info_f.c1 = c1;
    info_f.c2 = c2;
    info_f.lut_addr = info.lut_addr;
    print_double_info_f32(info_f);
#else
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
#endif
    lut_base1++;
  }
  // section2:[1.5,4)
  for (double x = 1.5; x < 4; x = x + b_size2) {
    double y = x + b_size2;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = sqrt_coef_2s_a1(x, x1, x0);
    a2 = sqrt_coef_2s_a2(x, x2, x1, x0);
    c0 = sqrt(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x2 << setw(16) << x1 << setw(16)
    //      << x0 << setw(16) << c2 << setw(16) << c1 << setw(16) << c0 << endl;
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
#if 0
    info_coef_double info_f;
    info_f.a_start = x;
    info_f.a_end = y;
    info_f.x0 = x0;
    info_f.x1 = x1;
    info_f.x2 = x2;
    info_f.c0 = c0;
    info_f.c1 = c1;
    info_f.c2 = c2;
    info_f.lut_addr = info.lut_addr;
    print_double_info_f32(info_f);
#else
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
#endif
    lut_base2++;
  }
}

void SqrtCoef::cal_rcpsqrt_coef_fp16() {
  cout << "fp16 rcp_sqrt coefficient" << endl;
  coef_info_f16.resize(18);
  info_coef_fp16 info;
  uint64_t lut_base1 = 0x0;  // 00000~"00011"
  uint64_t lut_base2 = 0xa;  // 01010~"01111"
  uint64_t lut_base3 = 0x18; // 11000~"11111"
  float b_size1 = pow(2, -4);
  float b_size2 = pow(2, -3);
  float b_size3 = pow(2, -2);
  float x0, x1;
  float c0, c1;
  // section1:[1,1.25)
  // cout << left << "[1," << setw(16) << "1.25):" << setw(16) << "x1" <<
  // setw(16) << "x0" << setw(16) << "c1" << setw(16)
  //      << "c0" << endl;
  for (float x = 1; x < 1.25; x = x + b_size1) {
    float y = x + b_size1;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = rcpsqrt_coef_1s_c1(x, x1, x0);
    c0 = rcpsqrt_coef_1s_c0(x, c1, x0);

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x1 << setw(16) << x0 << setw(16)
    //      << c1 << setw(16) << c0 << endl;
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
  }
  // section1:[1.25,2)
  for (float x = 1.25; x < 2; x = x + b_size2) {
    float y = x + b_size2;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = rcpsqrt_coef_1s_c1(x, x1, x0);
    c0 = rcpsqrt_coef_1s_c0(x, c1, x0);
    // record info
    info.a_start.f = float_to_float16(x);
    info.a_end.f = float_to_float16(y);
    info.x0.f = float_to_float16(x0);
    info.x1.f = float_to_float16(x1);
    info.c0.ui = ui32_to_coefWidth(c0, FP16_EXP_BITS, FP16_C0_FRAC_BITS);
    info.c1.ui = ui32_to_coefWidth(c1, FP16_EXP_BITS, FP16_C1_FRAC_BITS);
    info.lut_addr = lut_base2;
    print_coef_info_fp16(info);
    coef_info_f16.push_back(info);
    lut_base2++;
  }
  // section1:[2,4)
  for (float x = 2; x < 4; x = x + b_size3) {
    float y = x + b_size3;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = rcpsqrt_coef_1s_c1(x, x1, x0);
    c0 = rcpsqrt_coef_1s_c0(x, c1, x0);
    // record info
    info.a_start.f = float_to_float16(x);
    info.a_end.f = float_to_float16(y);
    info.x0.f = float_to_float16(x0);
    info.x1.f = float_to_float16(x1);
    info.c0.ui = ui32_to_coefWidth(c0, FP16_EXP_BITS, FP16_C0_FRAC_BITS);
    info.c1.ui = ui32_to_coefWidth(c1, FP16_EXP_BITS, FP16_C1_FRAC_BITS);
    info.lut_addr = lut_base3;
    print_coef_info_fp16(info);
    coef_info_f16.push_back(info);
    lut_base3++;
  }
}
void SqrtCoef::cal_rcpsqrt_coef_fp32() {
  cout << "fp32 rcp_sqrt coefficient" << endl;
  coef_info_f32.resize(96);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 0000000~"00011111"
  uint64_t lut_base2 = 0x40; // 0100000~"01101111"
  uint64_t lut_base3 = 0x80; // 1000000~"10001111"
  double b_size1 = pow(2, -6);
  double b_size2 = pow(2, -5);
  double b_size3 = pow(2, -4);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section[1,1.5)
  // cout << left << "[1," << setw(16) << "1.5):" << setw(16) << "x2" <<
  // setw(16) << "x1" << setw(16) << "x0" << setw(16)
  //      << "c2" << setw(16) << "c1" << setw(16) << "c0" << endl;
  for (double x = 1; x < 1.5; x = x + b_size1) {
    double y = x + b_size1;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = rcpsqrt_coef_2s_a1(x, x1, x0);
    a2 = rcpsqrt_coef_2s_a2(x, x2, x1, x0);
    c0 = rcp_sqrt(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x2 << setw(16) << x1 << setw(16)
    //      << x0 << setw(16) << c2 << setw(16) << c1 << setw(16) << c0 << endl;
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
#if 0
    info_coef_double info_f;
    info_f.a_start = x;
    info_f.a_end = y;
    info_f.x0 = x0;
    info_f.x1 = x1;
    info_f.x2 = x2;
    info_f.c0 = c0;
    info_f.c1 = c1;
    info_f.c2 = c2;
    info_f.lut_addr = info.lut_addr;
    print_double_info_f32(info_f);
#else
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
#endif
    lut_base1++;
  }
  // section[1.5,3)
  for (double x = 1.5; x < 3; x = x + b_size2) {
    double y = x + b_size2;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = rcpsqrt_coef_2s_a1(x, x1, x0);
    a2 = rcpsqrt_coef_2s_a2(x, x2, x1, x0);
    c0 = rcp_sqrt(x0 + x) + a2 * x0 * x1 - a1 * x0;
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
  // section[3,4)
  for (double x = 3; x < 4; x = x + b_size3) {
    double y = x + b_size3;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = rcpsqrt_coef_2s_a1(x, x1, x0);
    a2 = rcpsqrt_coef_2s_a2(x, x2, x1, x0);
    c0 = rcp_sqrt(x0 + x) + a2 * x0 * x1 - a1 * x0;
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
}

void SqrtCoef::cal_rcp_coef_fp16() {
  cout << "fp16 rcp coefficient" << endl;
  coef_info_f16.resize(16);
  info_coef_fp16 info;
  uint64_t lut_base1 = 0x0; // 0000~"01111"
  float b_size1 = pow(2, -4);
  float x0, x1;
  float c0, c1;
  // section:[1,2)
  // cout << left << "[1," << setw(16) << "2):" << setw(16) << "x1" << setw(16)
  // << "x0" << setw(16) << "c1" << setw(16)
  //      << "c0" << endl;
  for (float x = 1; x < 2; x = x + b_size1) {
    float y = x + b_size1;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = rcp_coef_1s_c1(x, x1, x0);
    c0 = rcp_coef_1s_c0(x, c1, x0);

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x1 << setw(16) << x0 << setw(16)
    //      << c1 << setw(16) << c0 << endl;
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
  }
}
void SqrtCoef::cal_rcp_coef_fp32() {
  cout << "fp32 rcp coefficient" << endl;
  coef_info_f32.resize(72);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 0000000~"0001111"
  uint64_t lut_base2 = 0x40; // 1000000~"1110111"
  double b_size1 = pow(2, -7);
  double b_size2 = pow(2, -6);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:[1,1.125)
  // cout << "[1,      1.125):            x2            x1           x0 c2 c1
  // c0" << endl;
  for (double x = 1; x < 1.125; x = x + b_size1) {
    double y = x + b_size1;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = rcp_coef_2s_a1(x, x1, x0);
    a2 = rcp_coef_2s_a2(x, x2, x1, x0);
    c0 = rcp(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;

    // cout << left << "[" << x << "," << y << "):" << setw(16) <<
    // setprecision(7) << x2 << setw(16) << x1 << setw(16)
    //      << x0 << setw(16) << c2 << setw(16) << c1 << setw(16) << c0 << endl;
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
#if 0
    info_coef_double info_f;
    info_f.a_start = x;
    info_f.a_end = y;
    info_f.x0 = x0;
    info_f.x1 = x1;
    info_f.x2 = x2;
    info_f.c0 = c0;
    info_f.c1 = c1;
    info_f.c2 = c2;
    info_f.lut_addr = info.lut_addr;
    print_double_info_f32(info_f);
#else
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
#endif
    lut_base1++;
  }
  // section2:[1.125,2)
  for (double x = 1.125; x < 2; x = x + b_size2) {
    double y = x + b_size2;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = rcp_coef_2s_a1(x, x1, x0);
    a2 = rcp_coef_2s_a2(x, x2, x1, x0);
    c0 = rcp(x0 + x) + a2 * x0 * x1 - a1 * x0;
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
}

} // namespace operators