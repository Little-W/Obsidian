#ifndef _booth_multiply_h
#define _booth_multiply_h

#include <bitset>
#include <cstdint>
#include <iostream>

namespace operators {

int8_t radix4_booth_encode(int8_t bit_group);
int16_t sign_extend(int16_t x, int bits);
int16_t radix4_booth_mult(int16_t multiplicand, int16_t multiplier,
                          int multiplicand_width, int multiplier_width,
                          int out_width = 14);

} // namespace operators

#endif
