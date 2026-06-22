#include "dop_ops.h"
#include "sfu_sqrt_rcp.h"
#include "softfloat.h"
#include "vae_common.h"
namespace operators {

/*========================================
Function: vae_elementwise .
model 1:input if BF16,output is BF16
model 2:input if FP16,output is FP16
Information:Author is ZC, 2025/07/20. by qingyan
para:
input:
  src_dataA, dim [row][col], type uint16_t
  src_dataB, dim [row][col], type uint16_t
  row:the row of 2D matrix ,such 1
  col :the col of 2D matrix ,valid data number,such 127
  i_type: input data type,such as FP16 ,BF16
  o_type: input data type,such as FP16 ,BF16
  model: 0, add ; 1, sub;2, mul
output:
  result: a 2D matrix
============================================*/
void vae_elementwise(uint16_t *result, const uint16_t *src_dataA,
                     const uint16_t *src_dataB, int row, int col,
                     DataType i_type, DataType o_type, int model) {
#if TEST_FOR_DE_DV
  deleteTxtFile();
#endif
  char nodeName[100];
  char opName[100] = "vae_elementwise";
  uint16_t data2txt_uint16;
#if TEST_FOR_DE_DV
  strcpy(nodeName, "p0_result");
  FILE *file_p0_result;
  file_p0_result = printfOpenFile(nodeName, opName);
#endif
  float16_t dataA, dataB, result16;
  int tmp;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      tmp = i * col + j;
      dataA.v = src_dataA[tmp];
      dataB.v = src_dataB[tmp];
      if (model == 0) { // add
        if (i_type == FP16) {
          result[tmp] = fp16add(dataA.v, dataB.v);
        } else if (i_type == BF16) {
          result[tmp] = bf16add(dataA.v, dataB.v);
        }
      } else if (model == 1) { // sub
        if (i_type == FP16) {
          result[tmp] = fp16sub(dataA.v, dataB.v);
        } else if (i_type == BF16) {
          result[tmp] = bf16sub(dataA.v, dataB.v);
        }
      } else if (model == 2) { // mul
        float32_t result32;
        if (i_type == FP16) {
          result32.v = fp16mul_resfp32(dataA.v, dataB.v);
          result[tmp] = fp32_to_fp16(result32.v);
        } else if (i_type == BF16) {
          result32.v = bf16mul_resfp32(dataA.v, dataB.v);
          result[tmp] = fp32_to_bf16(result32.v);
        }
      }
#if TEST_FOR_DE_DV
      data2txt_uint16 = result[tmp];
      operators::printfData16bit(data2txt_uint16, file_p0_result);
#endif
    }
  }
#if TEST_FOR_DE_DV
  printfcloseFile(file_p0_result);
#endif
}
} // namespace operators