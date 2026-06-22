#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {

/*========================================
Function: vae_mask .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/20. by qingyan
para:
input:
  src_data, dim [src_row][src_col], type uint16_t
  src_mask, dim [src_row][src_col], type uint16_t
  row:the row of 2D matrix ,such 1
  col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  mask_value0:
  mask_value1:
output:
  result: a 2D matrix
============================================*/
void vae_mask(uint16_t *result, const uint16_t *src_data,
              const uint16_t *src_mask, int row, int col,
              float16_t mask_value0) {
  int tmp;
  uint16_t mask = 15;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      mask = src_mask[tmp] & 0x0001;
      if (mask == 0x0000) { // 0
        result[tmp] = mask_value0.v;
      } else if (mask == 0x0001) { // 1
        result[tmp] = src_data[tmp];
      }
    }
  }
}
} // namespace operators