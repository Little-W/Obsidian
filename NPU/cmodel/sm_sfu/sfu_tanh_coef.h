#ifndef _tanh_common_h
#define _tanh_common_h

#include "sfu_common.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace operators {

#define TANH_LUT_SEG_BITS_F32 3     // seg id
#define TANH_LUT_ADDR_SUBBITS_F32 7 // sub seg id
#define TANH_LUT_ADDR_MASK_F32 ((1 << (TANH_LUT_ADDR_SUBBITS_F32)) - 1)
#define TANH_LUT_SEG_BITS_F16 2
#define TANH_LUT_ADDR_SUBBITS_F16 4
#define TANH_LUT_ADDR_MASK_F16 ((1 << (TANH_LUT_ADDR_SUBBITS_F16)) - 1)
#define ZERO_POINT_FIVE_FP32 0x3F000000
#define ZERO_POINT_FIVE_FP24 0x3F0000

class TanhCoef {
public:
  TanhCoef(DataType _type, uint8_t mode = 0);
  void cal_tanh_coef_fp16(
      uint8_t mode); // 0: tanh，1：postive sigmoid, 2:negative sigmoid
  void cal_tanh_coef_fp32(uint8_t mode);

  DataType data_type;
  vector<info_coef_fp32> coef_info_f32;
  vector<info_coef_fp16> coef_info_f16;
};

inline double pow2(int k) {
  double result = 1.0;
  double base = (k >= 0) ? 2.0 : 0.5;
  k = (k >= 0) ? k : -k;
  for (int i = 0; i < k; ++i) {
    result *= base;
  }
  return result;
}
inline double taylor(double r) {
  double result = 1.0;
  double term = 1.0;
  for (int n = 1; n <= 6; ++n) {
    term *= r / n;
    result += term;
  }
  return result;
}
#if defined(USE_EXTERN_C)
inline double exp_c(double x) { return exp(x); }
#else
inline double exp_c(double x) {
  if (x == 0.0f)
    return 1.0f;
  bool is_negative = (x < 0.0f);
  if (is_negative)
    x = -x;

  const float ln2 = 0.69314718056f;
  const float inv_ln2 = 1.44269504089f; // 1/ln2

  int k = static_cast<int>(x * inv_ln2 + 0.5f);
  float r = x - k * ln2;
  float er = taylor(r);
  float ek = pow2(k);
  float result = er * ek;

  if (is_negative)
    result = 1.0f / result;

  return result;
}
#endif

#if defined(USE_EXTERN_C)
inline double tanh_f(double x) {
  return ((exp(x) - exp(-x)) / (exp(x) + exp(-x)));
}

inline double sigmoid_f(double x) {
  if (x >= 0)
    return (1.0 / (1 + exp(-x)));
  else
    return (exp(x) / (1 + exp(x)));
}
#else
inline double tanh_f(double x) {
  return ((exp_c(x) - exp_c(-x)) / (exp_c(x) + exp_c(-x)));
}

inline double sigmoid_f(double x) {
  if (x >= 0)
    return (1.0 / (1 + exp_c(-x)));
  else
    return (exp_c(x) / (1 + exp_c(x)));
}
#endif

// 1s chebyshew_point_1s
inline float tanh_coef_1s_c1(float x_left, float x1, float x0) {
  return ((tanh_f(x1 + x_left) - tanh_f(x0 + x_left)) / (x1 - x0));
}
inline float tanh_coef_1s_c0(float x_left, float c1, float x0) {
  return (tanh_f(x0 + x_left) - c1 * x0);
}
// 2s end interpolation
inline double tanh_coef_2s_a1(double x_left, double x1, double x0) {
  return ((tanh_f(x1 + x_left) - tanh_f(x0 + x_left)) / (x1 - x0));
}
inline double tanh_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((tanh_f(x2 + x_left) - tanh_f(x1 + x_left)) / (x2 - x1) -
           (tanh_f(x1 + x_left) - tanh_f(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}

} // namespace operators
#endif
