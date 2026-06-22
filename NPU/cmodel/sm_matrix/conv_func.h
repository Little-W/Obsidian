#ifndef _conv_func_h
#define _conv_func_h

#include "matrix_mul.h"
#include "matrix_opcode.h"
#include "matrix_struct.h"

namespace operators {

DataType getDop_type(DataType src_type, DataType kernel_type);
// convolation calulatea
void conv3D(uint16_t src_arr[], uint16_t kernel_arr[],
            operators::MATRIX_4D<uint64_t> &out, DataType src_type = FP16,
            DataType kernel_type = FP16, int src_batchsize = 1,
            int src_channel = 1, int src_height = 1, int src_width = 1,
            int kernel_cout = 1, int kernel_cin = 1, int kernel_height = 1,
            int kernel_width = 1, uint16_t pad_value = 0x0,
            uint32_t pad_top = 0, uint32_t pad_bottom = 0,
            uint32_t pad_left = 0, uint32_t pad_right = 0,
            uint32_t stride_h = 1, uint32_t stride_w = 1,
            uint32_t dilation_h = 1, uint32_t dilation_w = 1);
void im2col(uint16_t src_arr[], uint16_t kernel_arr[],
            operators::MATRIX_2D<uint64_t> &out, DataType src_type = FP16,
            DataType kernel_type = FP16, int src_batchsize = 1,
            int src_channel = 1, int src_height = 1, int src_width = 1,
            int kernel_cout = 1, int kernel_cin = 1, int kernel_height = 1,
            int kernel_width = 1, uint16_t pad_value = 0x0,
            uint32_t pad_top = 0, uint32_t pad_bottom = 0,
            uint32_t pad_left = 0, uint32_t pad_right = 0,
            uint32_t stride_h = 1, uint32_t stride_w = 1,
            uint32_t dilation_h = 1, uint32_t dilation_w = 1);

void im2col_src_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                   MATRIX_2D<uint16_t> &src_mt, conv_stride &stride,
                   conv_dilation &dilation);
void col2img_dst(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                 MATRIX_2D<uint32_t> &src_mt, MATRIX_4D<uint32_t> &dst,
                 conv_stride &stride, conv_dilation &dilation);
void im2col_kernel_mt(MATRIX_4D<uint16_t> &kernel,
                      MATRIX_2D<uint16_t> &kernel_mt);
void im2col_elw_mt(MATRIX_4D<uint16_t> &elw, MATRIX_2D<uint16_t> &elw_mt);
void im2col_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
               MATRIX_2D<uint64_t> &result, conv_padding &pad,
               conv_stride &stride, conv_dilation &dilation);
void conv3D_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
               MATRIX_4D<uint64_t> &result, conv_padding &pad,
               conv_stride &stride, conv_dilation &dilation);
bool im2col_conv3D_cmp(MATRIX_2D<uint64_t> &im2col_r,
                       MATRIX_4D<uint64_t> &conv3D_r, int out_channel,
                       int out_height, int out_width);

void print_info(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                MATRIX_4D<uint64_t> &result);
void print_info(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                MATRIX_2D<uint64_t> &result);

} // namespace operators

#endif