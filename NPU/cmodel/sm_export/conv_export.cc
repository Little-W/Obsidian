#include "conv_func.h"
#include "conv_subcmd_func.h"
#include "matrix_struct.h"

// src_arr: uin16_t input data, size [N,C,H,W]->[src_batchsize,
// src_channel,src_height, src_width] kernel_arr: uint16_t kernel data,
// size[C_out,C_in,H,W]->[kernel_cout, kernel_cin, kernel_height, kernel_width]
// src_type: data type, for dop(data length <=16) fp16/bf16/int
// kernel_type: data type, for dop(data length <=16) fp16/bf16/int
// pad_top, pad_bottom,pad_left,pad_right,pad_value
// stride_h, stride_w
// dilation_h, dilation_w
// result: W->H->C->B  4D:[out_batchsize, out_channel, out_height,out_width]

// void conv_subcmd(uint64_t conv_opcode, uint8_t mat_a_m, uint8_t mat_b_n,
// uint16_t common_k, uint16_t **mat_a,
//                  uint16_t **mat_b, uint32_t **mat_c, DataType datatype,
//                  operators::MATRIX_4D<uint32_t> &result_4d) {
//   operators::conv_subcmd(conv_opcode,  mat_a_m, mat_b_n,  common_k, mat_a,
//                          mat_b, mat_c, datatype, result_4d);
// }

/*
void conv_subcmd(uint64_t conv_opcode, uint8_t mat_a_m, uint8_t mat_b_n,
uint16_t common_k, uint16_t **mat_a, uint16_t **mat_b, uint32_t **mat_c,
DataType datatype, operators::MATRIX_4D<uint32_t> &result_4d) {
  operators::matrix_opcode *matrix_opcode =
operators::matrix_opcode::generate(conv_opcode);
  operators::conv_subcmd(matrix_opcode,  mat_a_m, mat_b_n,  common_k, mat_a,
                         mat_b, mat_c, datatype, result_4d);
  delete matrix_opcode;
}
*/

void conv_subcmd(uint64_t conv_opcode, uint8_t mat_a_m, uint8_t mat_b_n,
                 uint16_t common_k, uint16_t **mat_a, uint16_t **mat_b,
                 uint64_t **mat_reshape, DataType datatype) {
  if (conv_opcode & 1)
    operators::conv_subcmd(conv_opcode, mat_a_m, mat_b_n, common_k, mat_a,
                           mat_b, mat_reshape, datatype);
}

uint64_t *conv_norm3D(uint16_t src_arr[], uint16_t kernel_arr[],
                      DataType src_type, DataType kernel_type,
                      int src_batchsize, int src_channel, int src_height,
                      int src_width, int kernel_cout, int kernel_cin,
                      int kernel_height, int kernel_width, uint16_t pad_value,
                      uint32_t pad_top, uint32_t pad_bottom, uint32_t pad_left,
                      uint32_t pad_right, uint32_t stride_h, uint32_t stride_w,
                      uint32_t dilation_h, uint32_t dilation_w) {
  uint64_t *out_result;
  operators::MATRIX_4D<uint64_t> out_mt;
  operators::conv3D(src_arr, kernel_arr, out_mt, src_type, kernel_type,
                    src_batchsize, src_channel, src_height, src_width,
                    kernel_cout, kernel_cin, kernel_height, kernel_width,
                    pad_value, pad_top, pad_bottom, pad_left, pad_right,
                    stride_h, stride_w, dilation_h, dilation_w);
  operators::set_data(out_result, out_mt, out_mt.bz, out_mt.ch, out_mt.nr,
                      out_mt.nc);
  return out_result;
}

// result  2D:[out_height*out_width, out_channel]
uint64_t *conv_im2col(uint16_t src_arr[], uint16_t kernel_arr[],
                      DataType src_type, DataType kernel_type,
                      int src_batchsize, int src_channel, int src_height,
                      int src_width, int kernel_cout, int kernel_cin,
                      int kernel_height, int kernel_width, uint16_t pad_value,
                      uint32_t pad_top, uint32_t pad_bottom, uint32_t pad_left,
                      uint32_t pad_right, uint32_t stride_h, uint32_t stride_w,
                      uint32_t dilation_h, uint32_t dilation_w) {
  uint64_t *out_result;
  operators::MATRIX_2D<uint64_t> out_mt;
  operators::im2col(src_arr, kernel_arr, out_mt, src_type, kernel_type,
                    src_batchsize, src_channel, src_height, src_width,
                    kernel_cout, kernel_cin, kernel_height, kernel_width,
                    pad_value, pad_top, pad_bottom, pad_left, pad_right,
                    stride_h, stride_w, dilation_h, dilation_w);
  operators::set_data(out_result, out_mt, out_mt.nr, out_mt.nc);
  return out_result;
}
