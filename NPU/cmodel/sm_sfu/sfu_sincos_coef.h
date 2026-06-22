#ifndef _sincos_common_h
#define _sincos_common_h

#include "sfu_common.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace operators {

#define SIN_LUT_ADDR_SUBBITS_F32 6
#define SIN_LUT_ADDR_MASK_F32 ((1 << (SIN_LUT_ADDR_SUBBITS_F32)) - 1)

// end_interpolation
class SinCoef {
public:
  SinCoef(DataType _type);
  void cal_sin_coef_fp16();
  void cal_sin_coef_fp32();

  DataType data_type;
  vector<info_coef_fp32> coef_info_f32;
  vector<info_coef_fp16> coef_info_f16;
};
class CosCoef {
public:
  CosCoef(DataType _type);
  void cal_cos_coef_fp16();
  void cal_cos_coef_fp32();

  DataType data_type;
  vector<info_coef_fp32> coef_info_f32;
  vector<info_coef_fp16> coef_info_f16;
};

inline double sin2pi(double x) {
  double reduced_x = x - std::nearbyint(x); //[-0.5,0.5)
  return sin(2 * M_PI * reduced_x);
}
inline double cos2pi(double x) {
  double reduced_x = std::fmod(x, 1.0); //[-1,1)
  return cos(2 * M_PI * reduced_x);
}

// 1s end interpolation
inline float sin_coef_1s_c1(float x_left, float x1, float x0) {
  return ((sin2pi(x1 + x_left) - sin2pi(x0 + x_left)) / (x1 - x0));
}
inline float sin_coef_1s_c0(float x_left, float c1, float x0) {
  return (sin2pi(x0 + x_left) - c1 * x0);
}
inline float cos_coef_1s_c1(float x_left, float x1, float x0) {
  return ((cos2pi(x1 + x_left) - cos2pi(x0 + x_left)) / (x1 - x0));
}
inline float cos_coef_1s_c0(float x_left, float c1, float x0) {
  return (cos2pi(x0 + x_left) - c1 * x0);
}
// 2s end interpolation
inline double sin_coef_2s_a1(double x_left, double x1, double x0) {
  return ((sin2pi(x1 + x_left) - sin2pi(x0 + x_left)) / (x1 - x0));
}
inline double sin_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((sin2pi(x2 + x_left) - sin2pi(x1 + x_left)) / (x2 - x1) -
           (sin2pi(x1 + x_left) - sin2pi(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}
inline double cos_coef_2s_a1(double x_left, double x1, double x0) {
  return ((cos2pi(x1 + x_left) - cos2pi(x0 + x_left)) / (x1 - x0));
}
inline double cos_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((cos2pi(x2 + x_left) - cos2pi(x1 + x_left)) / (x2 - x1) -
           (cos2pi(x1 + x_left) - cos2pi(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}

} // namespace operators

#endif