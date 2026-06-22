#ifndef _sfu_exp_h
#define _sfu_exp_h

#include "sfu_exp_coef_lut.h"
namespace operators {

uint32_t sfu_exp(uint32_t x); // exp2(x)<->2^(x)
// poly: x(-1,1),result(0.5,2)
uint16_t sfu_exp(uint16_t x);

uint32_t sfu_expE(uint32_t x); // exp(x)<->e^(x)
uint16_t sfu_expE(uint16_t x);

// for fp32
uint64_t get_exp_coef_addr(bool sign, uint32_t exp, uint64_t frac,
                           uint64_t dec_frac, uint8_t frac_len = 23);
uint64_t get_exp_man_tmp(uint32_t exp, uint64_t frac, uint64_t dec_frac,
                         uint8_t frac_len = 23);

// for fp16
uint64_t get_exp_coef_addr_f16(bool sign, uint16_t exp, uint32_t frac,
                               uint32_t dec_frac, uint8_t frac_len = 10);
uint32_t get_exp_man_tmp_f16(uint16_t exp, uint32_t frac, uint32_t dec_frac,
                             uint8_t frac_len = 10);

inline double div_ln2(double x) { return (x / log(2.0)); }

} // namespace operators
#endif