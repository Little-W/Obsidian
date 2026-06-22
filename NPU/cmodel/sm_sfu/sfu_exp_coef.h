#ifndef _exp_common_h
#define _exp_common_h

#include "sfu_common.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace operators {

#define EXP_LUT_SEG_BITS_F32 1     // seg id
#define EXP_LUT_ADDR_SUBBITS_F32 5 // sub seg id
#define EXP_LUT_ADDR_MASK_F32 ((1 << (EXP_LUT_ADDR_SUBBITS_F32)) - 1)
#define EXP_LUT_SEG_BITS_F16 1
#define EXP_LUT_ADDR_SUBBITS_F16 3
#define EXP_LUT_ADDR_MASK_F16 ((1 << (EXP_LUT_ADDR_SUBBITS_F16)) - 1)

class ExpCoef {
public:
  ExpCoef(DataType _type);
  void cal_exp_coef_fp16();
  void cal_exp_coef_fp32();

  DataType data_type;
  vector<info_coef_fp32> coef_info_f32;
  vector<info_coef_fp16> coef_info_f16;
};

inline double exp2_f(double x) { return (pow(2, x)); }

// chebyshew_point_1s
inline float exp_coef_1s_c1(float x_left, float x1, float x0) {
  return ((exp2_f(x1 + x_left) - exp2_f(x0 + x_left)) / (x1 - x0));
}
inline float exp_coef_1s_c0(float x_left, float c1, float x0) {
  return (exp2_f(x0 + x_left) - c1 * x0);
}
//  chebyshew_point_2s
inline double exp_coef_2s_a1(double x_left, double x1, double x0) {
  return ((exp2_f(x1 + x_left) - exp2_f(x0 + x_left)) / (x1 - x0));
}
inline double exp_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((exp2_f(x2 + x_left) - exp2_f(x1 + x_left)) / (x2 - x1) -
           (exp2_f(x1 + x_left) - exp2_f(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}

} // namespace operators

#endif