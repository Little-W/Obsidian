#include "sfu_exp_coef.h"
#include <cmath>
#include <iomanip>
#include <string.h>

namespace operators {

ExpCoef::ExpCoef(DataType _type) {
  data_type = _type;
  coef_info_f16.clear();
  coef_info_f32.clear();
  if (data_type == FP16) {
    cal_exp_coef_fp16();
  } else if (data_type == FP32) {
    cal_exp_coef_fp32();
  } else {
    // fp24
    cout << "Error data type!!!" << endl;
  }
}
void ExpCoef::cal_exp_coef_fp16() {
  cout << "fp16 exp2 coefficient" << endl;
  coef_info_f16.resize(8);
  info_coef_fp16 info;
  uint64_t lut_base1 = 0x0; // 0000~0111
  uint64_t lut_base2 = 0x8; // 1000~1111
  float b_size1 = pow(2, -3);
  float b_size2 = pow(2, -3);
  float x0, x1;
  float c0, c1;
  // section1:(-1,0)
  for (float x = -1; x < 0; x = x + b_size1) {
    float y = x + b_size1;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = exp_coef_1s_c1(y, x1, x0);
    c0 = exp_coef_1s_c0(y, c1, x0);
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
  // section2:[0,1)
  for (float x = 0; x < 1; x = x + b_size2) {
    float y = x + b_size2;
    x0 = chebyshew_point_1s_x0(x, y);
    x1 = chebyshew_point_1s_x1(x, y);
    c1 = exp_coef_1s_c1(x, x1, x0);
    c0 = exp_coef_1s_c0(x, c1, x0);
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

void ExpCoef::cal_exp_coef_fp32() {
  cout << "fp32 exp2 coefficient" << endl;
  coef_info_f32.resize(64);
  info_coef_fp32 info;
  uint64_t lut_base1 = 0x0;  // 000000~011111
  uint64_t lut_base2 = 0x20; // 100000~11111
  double b_size1 = pow(2, -5);
  double b_size2 = pow(2, -5);
  double x0, x1, x2;
  double c0, c1, c2;
  double a1, a2;
  // section1:(-1,0)
  for (double x = -1; x < -0; x = x + b_size1) {
    double y = x + b_size1;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = exp_coef_2s_a1(y, x1, x0);
    a2 = exp_coef_2s_a2(y, x2, x1, x0);
    c0 = exp2_f(x0 + y) + a2 * x0 * x1 - a1 * x0;
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
  // section2:[0,1)
  for (double x = 0; x < 1; x = x + b_size2) {
    double y = x + b_size2;
    x0 = chebyshew_point_2s_x0(x, y);
    x1 = chebyshew_point_2s_x1(x, y);
    x2 = chebyshew_point_2s_x2(x, y);
    a1 = exp_coef_2s_a1(x, x1, x0);
    a2 = exp_coef_2s_a2(x, x2, x1, x0);
    c0 = exp2_f(x0 + x) + a2 * x0 * x1 - a1 * x0;
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