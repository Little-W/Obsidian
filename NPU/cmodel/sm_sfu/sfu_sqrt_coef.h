#ifndef _sqrt_coef_h
#define _sqrt_coef_h

#include "sfu_common.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace operators {

#define SQRT_LUT_ADDR_SUBBITS_F32 6
#define SQRT_LUT_ADDR_MASK_F32 ((1 << (SQRT_LUT_ADDR_SUBBITS_F32)) - 1)
#define SQRT_LUT_ADDR_SUBBITS_F16 3
#define SQRT_LUT_ADDR_MASK_F16 ((1 << (SQRT_LUT_ADDR_SUBBITS_F16)) - 1)

enum FUNC_TYPE { SQRT, RCPSQRT, RCP, FUNC_NUM };

class SqrtCoef {
public:
  SqrtCoef(DataType _type, FUNC_TYPE _ftype);
  void cal_sqrt_coef_fp16();
  void cal_sqrt_coef_fp32();
  void cal_rcpsqrt_coef_fp16();
  void cal_rcpsqrt_coef_fp32();
  void cal_rcp_coef_fp16();
  void cal_rcp_coef_fp32();

  DataType data_type;
  FUNC_TYPE func_type;
  vector<info_coef_fp32> coef_info_f32;
  vector<info_coef_fp16> coef_info_f16;
};

inline double rcp_sqrt(double x) { return 1.0 / sqrt(x); }
inline double rcp(double x) { return 1.0 / x; }
inline float sqrt_coef_1s_c1(float x_left, float x1, float x0) {
  return ((sqrt(x1 + x_left) - sqrt(x0 + x_left)) / (x1 - x0));
}
inline float sqrt_coef_1s_c0(float x_left, float c1, float x0) {
  return (sqrt(x0 + x_left) - c1 * x0);
}
inline float rcpsqrt_coef_1s_c1(float x_left, float x1, float x0) {
  return ((rcp_sqrt(x1 + x_left) - rcp_sqrt(x0 + x_left)) / (x1 - x0));
}
inline float rcpsqrt_coef_1s_c0(float x_left, float c1, float x0) {
  return (rcp_sqrt(x0 + x_left) - c1 * x0);
}
inline float rcp_coef_1s_c1(float x_left, float x1, float x0) {
  return ((rcp(x1 + x_left) - rcp(x0 + x_left)) / (x1 - x0));
}
inline float rcp_coef_1s_c0(float x_left, float c1, float x0) {
  return (rcp(x0 + x_left) - c1 * x0);
}

inline double sqrt_coef_2s_a1(double x_left, double x1, double x0) {
  return ((sqrt(x1 + x_left) - sqrt(x0 + x_left)) / (x1 - x0));
}
inline double sqrt_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((sqrt(x2 + x_left) - sqrt(x1 + x_left)) / (x2 - x1) -
           (sqrt(x1 + x_left) - sqrt(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}
inline double rcpsqrt_coef_2s_a1(double x_left, double x1, double x0) {
  return ((rcp_sqrt(x1 + x_left) - rcp_sqrt(x0 + x_left)) / (x1 - x0));
}
inline double rcpsqrt_coef_2s_a2(double x_left, double x2, double x1,
                                 double x0) {
  return (((rcp_sqrt(x2 + x_left) - rcp_sqrt(x1 + x_left)) / (x2 - x1) -
           (rcp_sqrt(x1 + x_left) - rcp_sqrt(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}
inline double rcp_coef_2s_a1(double x_left, double x1, double x0) {
  return ((rcp(x1 + x_left) - rcp(x0 + x_left)) / (x1 - x0));
}
inline double rcp_coef_2s_a2(double x_left, double x2, double x1, double x0) {
  return (((rcp(x2 + x_left) - rcp(x1 + x_left)) / (x2 - x1) -
           (rcp(x1 + x_left) - rcp(x0 + x_left)) / (x1 - x0)) /
          (x2 - x0));
}

} // namespace operators
#endif
