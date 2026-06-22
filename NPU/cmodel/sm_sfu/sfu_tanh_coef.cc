#include "sfu_tanh_coef.h"
#include <cmath>
#include <iomanip>
#include <string.h>

namespace operators {

TanhCoef::TanhCoef(DataType _type, uint8_t mode) {
  data_type = _type;
  coef_info_f16.clear();
  coef_info_f32.clear();
  if (data_type == FP16) {
    cal_tanh_coef_fp16(mode);
  } else if (data_type == FP32) {
    cal_tanh_coef_fp32(mode);
  } else {
    // fp24
    cout << "Error data type!!!" << endl;
  }
}
void TanhCoef::cal_tanh_coef_fp16(uint8_t mode) {
  cout << "fp16 tanh coefficient" << endl;
  coef_info_f16.resize(32);
  info_coef_fp16 info;
  // FIXME:addr increase or decrease
  uint64_t lut_base1 = 0x0;  // 000000~001111
  uint64_t lut_base2 = 0x10; // 010000~010111
  uint64_t lut_base3 = 0x20; // 100000~100111
  float b_size1 = pow(2, -4);
  float b_size2 = pow(2, -3);
  float b_size3 = pow(2, -2);
  float x0, x1;
  float c0, c1;
  // section1:[0,1)
  for (float x = 0; x < 1; x = x + b_size1) {
    float y = x + b_size1;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = tanh_coef_1s_c1(x, x1, x0);
    c0 = tanh_coef_1s_c0(x, c1, x0);
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
  // section2:[1,2)
  for (float x = 1; x < 2; x = x + b_size2) {
    float y = x + b_size2;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = tanh_coef_1s_c1(x, x1, x0);
    c0 = tanh_coef_1s_c0(x, c1, x0);
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
  // section3:[2,4)
  for (float x = 2; x < 4; x = x + b_size3) {
    float y = x + b_size3;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = tanh_coef_1s_c1(x, x1, x0);
    c0 = tanh_coef_1s_c0(x, c1, x0);
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

void TanhCoef::cal_tanh_coef_fp32(uint8_t mode) {
  cout << "fp32 tanh coefficient" << endl;
  coef_info_f32.resize(188);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;   // 000 0000000~000 0000001
  uint64_t lut_base2 = 0x80;  // 001 0000000
  uint64_t lut_base3 = 0x100; // 010 0000000~010 0000010
  uint64_t lut_base4 = 0x180; // 011 0000000 ~ 011 0001011
  uint64_t lut_base5 = 0x200; // 100 0000000~100 0010111
  uint64_t lut_base6 = 0x280; // 101 0000000~101 1100111
  uint64_t lut_base7 = 0x300; // 110 0000000~110 0011111
  double b_size1 = pow(2, -10);
  double b_size2 = pow(2, -9);
  double b_size3 = pow(2, -8);
  double b_size4 = pow(2, -7);
  double b_size5 = pow(2, -6);
  double b_size6 = pow(2, -5);
  double b_size7 = pow(2, -3);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:[0,2^-9)
  for (double x = 0; x < pow(2, -9); x = x + b_size1) {
    double y = x + b_size1;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
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
#endif
  }
  // section2:[2^-9,2^-8)
  for (double x = pow(2, -9); x < pow(2, -8); x = x + b_size2) {
    double y = x + b_size2;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
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
  // section3:[2^-8,2^-6)
  for (double x = pow(2, -8); x < pow(2, -6); x = x + b_size3) {
    double y = x + b_size3;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
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
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
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
  // section5:[2^-3,2^-1)
  for (double x = pow(2, -3); x < 0.5; x = x + b_size5) {
    double y = x + b_size5;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base5;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base5++;
  }
  // section6:[0.5,4)
  for (double x = 0.5; x < 4; x = x + b_size6) {
    double y = x + b_size6;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base6;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base6++;
  }
  // section7:[4,8)
  for (double x = 4; x < 8; x = x + b_size7) {
    double y = x + b_size7;
    x0 = end_interpolation_x0(x, y);
    x1 = end_interpolation_x1(x, y);
    x2 = end_interpolation_x2(x, y);
    a1 = tanh_coef_2s_a1(x, x1, x0);
    a2 = tanh_coef_2s_a2(x, x2, x1, x0);
    c0 = tanh_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
    c1 = a1 - a2 * (x0 + x1);
    c2 = a2;
    if (mode == 1) {
      c0 = c0 + 1;
    } else if (mode == 2) {
      c0 = c0 - 1;
    }
    // record info
    info.a_start.f = float_to_float32(x);
    info.a_end.f = float_to_float32(y);
    info.x0.f = float_to_float32(x0);
    info.x1.f = float_to_float32(x1);
    info.x2.f = float_to_float32(x2);
    info.c0.ui = ui64_to_coefWidth(c0, FP32_EXP_BITS, FP32_C0_FRAC_BITS);
    info.c1.ui = ui64_to_coefWidth(c1, FP32_EXP_BITS, FP32_C1_FRAC_BITS);
    info.c2.ui = ui64_to_coefWidth(c2, FP32_EXP_BITS, FP32_C2_FRAC_BITS);
    info.lut_addr = lut_base7;
    print_coef_info_fp32(info);
    coef_info_f32.push_back(info);
    lut_base7++;
  }
}

} // namespace operators