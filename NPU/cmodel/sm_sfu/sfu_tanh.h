#ifndef _sfu_tanh_h
#define _sfu_tanh_h

#include "sfu_tanh_coef_lut.h"
namespace operators {

uint32_t sfu_tanh(uint32_t x);
uint32_t sfu_sigmoid(uint32_t x);

int8_t get_tanh_seg_addr(uint32_t exp);
int8_t get_tanh_seg_bsize(int8_t seg_addr);

uint64_t get_tanh_coef_addr(uint32_t exp, uint32_t frac, int8_t seg_addr);
uint32_t get_tanh_man_tmp(uint32_t exp, uint32_t frac, int8_t seg_addr);

} // namespace operators
#endif