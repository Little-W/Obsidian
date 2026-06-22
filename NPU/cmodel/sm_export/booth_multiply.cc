#include "booth_multiply.h"
#include "cmodel.h"
#include <assert.h>

int16_t radix4_booth_multiplier(int16_t multiplicand, int16_t multiplier,
                                int multiplicand_width, int multiplier_width,
                                int out_width) {
  return operators::radix4_booth_mult(multiplicand, multiplier,
                                      multiplicand_width, multiplier_width,
                                      out_width);
}

namespace operators {

int8_t radix4_booth_encode(int8_t bit_group) {
  switch (bit_group) {
  case 0b000:
  case 0b111:
    return 0;
    break;
  case 0b001:
  case 0b010:
    return 1;
    break;
  case 0b011:
    return 2;
    break;
  case 0b100:
    return -2;
    break;
  case 0b101:
  case 0b110:
    return -1;
    break;
  default:
    break;
  }
  return 0;
}

int16_t sign_extend(int16_t x, int bits) {
  // MSB is sign
  int16_t shift = sizeof(int16_t) * 8 - bits;
  return (x << shift) >> shift;
}

int16_t radix4_booth_mult(int16_t multiplicand, int16_t multiplier,
                          int multiplicand_width, int multiplier_width,
                          int out_width) {
  assert(multiplicand_width <= 16 && multiplier_width <= 16 &&
         out_width <= 16 && " bits must <= 16 used int16");
  // out range[-32768,32767]

  int16_t mcand_sign_ext = sign_extend(multiplicand, multiplicand_width);
  int16_t mer_sign_ext = sign_extend(multiplier, multiplier_width);

#if 0
  return (mcand_sign_ext*mer_sign_ext);
#endif

  int16_t product = 0;
  int16_t partical = 0;
  int8_t k_max = (multiplier_width + 1) / 2;
  for (int8_t k = 0; k < k_max; k++) {
    int16_t i = 2 * k;
    int8_t current_bit = (mer_sign_ext >> i) & 0x1;
    int8_t next_bit = (mer_sign_ext >> (i + 1)) & 0x1;
    int8_t prev_bit = (k == 0) ? 0 : ((mer_sign_ext >> (i - 1)) & 0x1);
    int8_t bit_group = (next_bit << 2) | (current_bit << 1) | prev_bit;
    partical = mcand_sign_ext * radix4_booth_encode(bit_group);
    partical <<= i;
    product += partical;
  }

  product = sign_extend(product, out_width);

  std::cout << "(Binary): " << std::bitset<16>(multiplicand) << "*"
            << std::bitset<16>(multiplier)
            << ", booth multiplier result(Dec):" << product
            << ", (Binary): " << std::bitset<16>(product) << std::endl;

  return product;
}

} // namespace operators