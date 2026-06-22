#ifndef _sfu_common_h
#define _sfu_common_h

#include "internals.h"
#include "sm_data_struct.h"
#include "softfloat.h"
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

namespace operators {

#define FP16_EXP_BITS 5
#define FP32_EXP_BITS 8
#define FP16_C1_FRAC_BITS 13
#define FP16_C0_FRAC_BITS 15
#define FP32_C2_FRAC_BITS 16
#define FP32_C1_FRAC_BITS 25
#define FP32_C0_FRAC_BITS 31
#define FP16_ACC_FRAC_BITS 27
#define FP32_ACC_FRAC_BITS 59

union ui16_f {
  uint16_t ui;
  float f;
};
union ui32_f {
  uint32_t ui;
  float f;
};

inline uint32_t float_to_ui32(float f) {
  uint32_t uf;
  memcpy(&uf, &f, sizeof(float));
  return uf;
}

inline float ui32_to_float(uint32_t u) {
  float f;
  memcpy(&f, &u, sizeof(float));
  return f;
}

inline float32_t float_to_float32(float f) {
  float32_t vf;
  memcpy(&vf.v, &f, sizeof(float));
  return vf;
}

inline float float32_to_float(float32_t sf) {
  float f;
  uint32_t bits = sf.v;
  memcpy(&f, &bits, sizeof(float));
  return f;
}

inline ui32_f float_to_f32(float f) {
  ui32_f uf;
  uf.f = f;
  memcpy(&uf.ui, &f, sizeof(float));
  return uf;
}

inline float ui32_to_f32(ui32_f uf) { return uf.f; }

inline float16_t float_to_float16(float f) {
  float32_t f32 = float_to_float32(f);
  return f32_to_f16(f32);
}
inline float float16_to_float(float16_t f16) {

  float32_t f32 = f16_to_f32(f16);
  return float32_to_float(f32);
}
inline ui16_f float_to_f16(float f) {
  ui16_f uf;
  float16_t f16;
  uf.f = f;
  f16 = float_to_float16(f);
  uf.ui = f16.v;
  return uf;
}
inline float ui16_to_f32(ui16_f uf) { return uf.f; }

// define round mode result
int8_t round_bit(uint64_t frac, bool sign, int org_frac_len = 52,
                 int frac_len = 23, uint8_t rnd_mode = 0);
// double<->uint64_t
inline uint64_t double_to_ui64(double d) {
  uint64_t ud;
  memcpy(&ud, &d, sizeof(double));
  return ud;
}
inline double ui64_to_double(uint64_t u) {
  double d;
  memcpy(&d, &u, sizeof(double));
  return d;
}
inline float64_t double_to_float64(double d) {
  float64_t vf;
  memcpy(&vf.v, &d, sizeof(double));
  return vf;
}
inline double float64_to_double(float64_t sf) {
  double d;
  uint64_t bits = sf.v;
  memcpy(&d, &bits, sizeof(double));
  return d;
}
uint64_t ui64_to_coefWidth(double d, int exp_len, int frac_len,
                           uint8_t rnd = 0);
uint32_t ui32_to_coefWidth(float f, int exp_len, int frac_len, uint8_t rnd = 0);

// interpolation
// no bias
inline float chebyshew_point_1s_x0(float x, float y) {
  if (x >= 0)
    return ((y - x) / 2 * (1 + sqrt(2) / 2));
  else
    return (-(y - x) / 2 * (1 - sqrt(2) / 2));
}
inline float chebyshew_point_1s_x1(float x, float y) {
  if (x >= 0)
    return ((y - x) / 2 * (1 - sqrt(2) / 2));
  else
    return (-(y - x) / 2 * (1 + sqrt(2) / 2));
}
inline double chebyshew_point_2s_x0(double x, double y) {
  if (x >= 0) {
    return ((y - x) / 2 * (1 + sqrt(3) / 2));
  } else {
    return (-(y - x) / 2 * (1 - sqrt(3) / 2));
  }
}
inline double chebyshew_point_2s_x1(double x, double y) {
  if (x >= 0)
    return ((y - x) / 2);
  else
    return (-(y - x) / 2);
}
inline double chebyshew_point_2s_x2(double x, double y) {
  if (x >= 0)
    return ((y - x) / 2 * (1 - sqrt(3) / 2));
  else
    return (-(y - x) / 2 * (1 + sqrt(3) / 2));
}
inline double end_interpolation_x0(double x, double y) {
  if (x >= 0)
    return (y - x);
  else
    return 0;
}
inline double end_interpolation_x1(double x, double y) {
  if (x >= 0)
    return ((y - x) / 2);
  else
    return (-(y - x) / 2);
}
inline double end_interpolation_x2(double x, double y) {
  if (x >= 0)
    return 0;
  else
    return (x - y);
}

// for coef
struct seg_para_table_fp32 {
  uint16_t bsize;
  float32_t a_start;
};

struct info_coef_fp16 {
  ui16_f16 a_start;
  ui16_f16 a_end;
  ui16_f16 x1;
  ui16_f16 x0;
  ui32_f32 c1; // frac 13bits
  ui32_f32 c0; // frac 15bits
  uint64_t lut_addr;
};

struct info_coef_fp32 {
  ui32_f32 a_start;
  ui32_f32 a_end;
  ui32_f32 x2;
  ui32_f32 x1;
  ui32_f32 x0;
  ui64_f64 c2; // frac 16bits
  ui64_f64 c1; // frac 25bits
  ui64_f64 c0; // frac 31bits
  uint64_t lut_addr;
};
struct info_coef_double {
  double a_start;
  double a_end;
  double x2;
  double x1;
  double x0;
  double c2;
  double c1;
  double c0;
  uint64_t lut_addr;
};

inline void print_double_info_f32(info_coef_double &info) {
  cout << setprecision(7) << "[" << info.a_start << "," << info.a_end
       << "):  " << info.x2 << "," << info.x1 << "," << info.x0 << ","
       << info.c2 << "," << info.c1 << "," << info.c0 << hex << ",0x"
       << info.lut_addr << dec << endl;
}
inline void print_coef_info_fp16(info_coef_fp16 &info) {
  cout << hex << "[0x" << info.a_start.ui << ",0x" << info.a_end.ui << "):  0x"
       << info.x1.ui << ",0x" << info.x0.ui << ",0x" << info.c1.ui << ",0x"
       << info.c0.ui << ",0x" << info.lut_addr << dec << endl;
}
inline void print_coef_info_fp32(info_coef_fp32 &info) {
  cout << hex << "[0x" << info.a_start.ui << ",0x" << info.a_end.ui << "):  0x"
       << info.x2.ui << ",0x" << info.x1.ui << ",0x" << info.x0.ui << ",0x"
       << info.c2.ui << ",0x" << info.c1.ui << ",0x" << info.c0.ui << ",0x"
       << info.lut_addr << dec << endl;
}

info_coef_fp16 get_info_coef_fp16(const info_coef_fp16 *table, int size,
                                  uint64_t addr);
info_coef_fp32 get_info_coef_fp32(const info_coef_fp32 *table, int size,
                                  uint64_t addr);

// functions for poly
inline double poly_out_double(double x, info_coef_double info) {
  return (info.c2 * x * x + info.c1 * x + info.c0);
}
inline float32_t fp32_mul(float32_t data_flit) {
  return f32_mul(data_flit, data_flit);
}
inline float32_t fp32_fma(float32_t a, float32_t b, float32_t c) {
  return f32_mulAdd(a, b, c);
}
uint32_t pol_cal_fp32(uint32_t data_flit, uint64_t c0, uint64_t c1, uint64_t c2,
                      uint8_t rnd = 0);
uint16_t pol_cal_fp16(uint16_t data_flit, uint32_t c0, uint32_t c1,
                      uint8_t rnd = 0);
uint32_t fp32_check_setExcept(uint32_t data);
uint16_t fp16_check_setExcept(uint16_t data);

// get_bits data[start_bits:start_bits+length]
inline uint32_t get_bits(uint32_t data, int start_bit, int length) {
  uint32_t mask = ((1UL << length) - 1) << start_bit;
  return (data & mask) >> start_bit;
}
inline uint64_t get_bits(uint64_t data, int start_bit, int length) {
  uint64_t mask = ((1UL << length) - 1) << start_bit;
  return (data & mask) >> start_bit;
}
#define bitValue(num, pos) (((num) >> (pos)) & 0x1)

// lzd_num
inline int count_leading_zeros(uint64_t data, uint32_t real_bits) {
  assert(real_bits <= 64);
  if (data == 0)
    return real_bits;
  int count = 0;
  for (int i = real_bits - 1; i >= 0; i--) {
    if ((data >> i) & 1)
      break;
    count++;
  }
  return count;
}

void norm_round(uint16_t &exp_out, uint64_t &man_out, bool sign,
                uint16_t exp_in, uint64_t man_in, int exp_in_width = 9,
                int exp_out_width = 8, int frac_in_width = 59,
                int frac_out_width = 23, bool f32_format = 1,
                uint8_t rnd = 0); // for pol_cal_fp32/fp16
uint32_t get_frac_shift(bool sign, uint32_t frac, uint32_t exp_big,
                        uint32_t exp_lit, uint8_t rnd = 0); // sfu fp32
uint16_t get_frac_shift_f16(bool sign, uint16_t frac, uint16_t exp_big,
                            uint16_t exp_lit, uint8_t rnd = 0); // sfu fp16

} // namespace operators
#endif