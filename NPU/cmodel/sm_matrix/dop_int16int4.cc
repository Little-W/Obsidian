#include "dop_rtl_mode.h"

namespace operators {
fp_general_t dop_add_int16int4(uint16_t *a, uint16_t *b, uint16_t *shift_num,
                               uint16_t *b_scale, size_t num_elements) {
  uint64_t final_result = 0;
  int64_t temp_a = 0;
  int64_t temp_b = 0;
  uint16_t temp_shift = shift_num ? *shift_num : 0;
  int64_t temp_b_scale = b_scale ? *b_scale : 1;
  for (size_t i = 0; i < num_elements; i++) {
    temp_a = (int64_t)a[i] << 48 >> 48;
    temp_b = (int64_t)((int8_t)(b[i] << 4)) >> 4;
    final_result = final_result + temp_a * temp_b;
  }

  temp_b_scale = (int64_t)temp_b_scale << 48 >> 48;
  final_result *= temp_b_scale;
  uint64_t offset = (temp_shift == 0) ? 0 : (1 << (temp_shift - 1));
  final_result += offset;
  final_result >>= temp_shift;
  final_result &= 0xfffffff;
  return final_result;
}

} // namespace operators