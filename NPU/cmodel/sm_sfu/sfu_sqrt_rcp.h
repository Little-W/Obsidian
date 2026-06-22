#ifndef _sfu_sqrt_rcp_h
#define _sfu_sqrt_rcp_h

#include "sfu_sqrt_coef_lut.h"
namespace operators {

uint32_t sfu_sqrt(uint32_t x); // fp32
uint32_t sfu_rcp(uint32_t x);
uint32_t sfu_rcpsqrt(uint32_t x);

inline info_coef_double get_sqrt_coef_double(float x) {
  for (int i = 0; i < 56; i++) {
    if (x >= sqrt_coef_info_double[i].a_start &&
        x <= sqrt_coef_info_double[i].a_end) {
      return sqrt_coef_info_double[i];
    }
  }
  return {0, 0, 0, 0, 0, 0, 0, 0, 0};
}
inline info_coef_double get_sqrt_coef_double(uint64_t addr) {
  for (int i = 0; i < 56; i++) {
    if (sqrt_coef_info_double[i].lut_addr == addr)
      return sqrt_coef_info_double[i];
  }
  return {0, 0, 0, 0, 0, 0, 0, 0, 0};
}

} // namespace operators
#endif