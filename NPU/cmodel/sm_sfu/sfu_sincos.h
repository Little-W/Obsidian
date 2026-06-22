#ifndef _sfu_sincos_h
#define _sfu_sincos_h

#include "sfu_sincos_coef_lut.h"
namespace operators {

uint16_t sfu_sincos(uint16_t x, uint8_t op = 0); // op=0, sin; op=1, cos
uint32_t sfu_sincos(uint32_t x, uint8_t op = 0); // op=0, sin; op=1, cos

} // namespace operators
#endif