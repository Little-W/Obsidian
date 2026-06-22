#include "conv_func.h"
#include "dop_ops.h"

namespace operators {

// src:[1,C_in,H,W]->[Ho*Wo,C_in*KH*KW]
void im2col_src_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                   MATRIX_2D<uint16_t> &src_mt, conv_stride &stride,
                   conv_dilation &dilation) {
  int out_row =
      (src.nr - dilation.h_rate * (kernel.nr - 1) - 1) / stride.stride_h + 1;
  int out_col =
      (src.nc - dilation.w_rate * (kernel.nc - 1) - 1) / stride.stride_w + 1;
#if ENABLE_OPENMP
#pragma omp parallel for collapse(3)
#endif
  for (int ic = 0; ic < src.ch; ic++) { // channel loop
    for (int i = 0; i < out_row; i++) {
      for (int j = 0; j < out_col; j++) {
        int row_id = i * out_col + j;
        for (int kh = 0; kh < kernel.nr; kh++) {
          for (int kw = 0; kw < kernel.nc; kw++) {
            int h = i * stride.stride_h + dilation.h_rate * kh;
            int w = j * stride.stride_w + dilation.w_rate * kw;
            int col_id = kh * kernel.nc + kw + ic * kernel.nr * kernel.nc;
            if (h >= 0 && h < src.nr && w >= 0 && w < src.nc) {
              src_mt.data[row_id][col_id] = src.data[0][ic][h][w];
            }
          }
        }
      }
    }
  }
  return;
}
// [Ho*Wo,C_in*KH*KW]-> dst:[1,C_out,H,W]
// src: FP16 [1,C_in,H,W]->[Ho*Wo,C_in*KH*KW]
// kernel:FP16  [C_out,C_in,KH,KW]->[C_in*KH*KW,C_out]
// pad, stride, dilation
void col2img_dst(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                 MATRIX_2D<uint32_t> &src_mt, MATRIX_4D<uint32_t> &dst,
                 conv_stride &stride, conv_dilation &dilation) {
  int out_row = dst.nr;
  int out_col = dst.nc;
#if ENABLE_OPENMP
#pragma omp parallel for collapse(3)
#endif
  for (int ic = 0; ic < kernel.bz; ic++) { // channel loop
    for (int h = 0; h < out_row; h++) {
      for (int w = 0; w < out_col; w++) {
        int col_id = ic;
        int row_id = h * out_row + w;
        dst.data[0][ic][h][w] = src_mt.data[row_id][col_id];
      }
    }
  }
  return;
}
// kernel:[C_out,C_in,KH,KW]->[C_in*KH*KW,C_out]
void im2col_kernel_mt(MATRIX_4D<uint16_t> &kernel,
                      MATRIX_2D<uint16_t> &kernel_mt) {
#if ENABLE_OPENMP
#pragma omp parallel for collapse(4) schedule(static)
#endif
  for (int oc = 0; oc < kernel.bz; oc++) {
    for (int ic = 0; ic < kernel.ch; ic++) {
      for (int kh = 0; kh < kernel.nr; kh++) {
        for (int kw = 0; kw < kernel.nc; kw++) {
          int ki = kernel.nr * kernel.nc * ic + kh * kernel.nc + kw;
          kernel_mt.data[ki][oc] = kernel.data[oc][ic][kh][kw];
        }
      }
    }
  }

  return;
}
// ELW:[1,C_out,H,W]->[H*W,C_out]
void im2col_elw_mt(MATRIX_4D<uint16_t> &elw, MATRIX_2D<uint16_t> &elw_mt) {
  assert(elw.bz == 1 && "only support batch=1");
  int elw_mt_row = elw.nr * elw.nc;
  assert(elw_mt.nr == elw_mt_row && "mt row num error");
#if ENABLE_OPENMP
#pragma omp parallel for collapse(3)
#endif
  for (int c = 0; c < elw.ch; c++) {
    for (int h = 0; h < elw.nr; h++) {
      for (int w = 0; w < elw.nc; w++) {
        int id = h * elw.nc + w;
        elw_mt.data[id][c] = elw.data[0][c][h][w];
      }
    }
  }

  return;
}

// src: FP16 [1,C_in,H,W]->[Ho*Wo,C_in*KH*KW]
// kernel:FP16  [C_out,C_in,KH,KW]->[C_in*KH*KW,C_out]
// pad, stride, dilation
void im2col_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
               MATRIX_2D<uint64_t> &result, conv_padding &pad,
               conv_stride &stride, conv_dilation &dilation) {
  // pad src_data->input
  MATRIX_4D<uint16_t> input;
  src.mat_padding(input, pad);
  // conditional compare
  assert(input.bz == 1 && "batch size must be 1");
  assert(kernel.ch == input.ch);
  DataType dop_type = getDop_type(input.type, kernel.type);
  int out_row =
      (input.nr - dilation.h_rate * (kernel.nr - 1) - 1) / stride.stride_h + 1;
  int out_col =
      (input.nc - dilation.w_rate * (kernel.nc - 1) - 1) / stride.stride_w + 1;
  if (out_row <= 0 || out_col <= 0) {
    std::cerr << "Error: output size is non-positive.Check input parameters."
              << std::endl;
    return;
  }
  // 4D->2D
  MATRIX_2D<uint16_t> input_mt, kernel_mt;
  int in_rows = out_row * out_col;
  int in_cols = kernel.ch * kernel.nr * kernel.nc;
  input_mt.reset(in_rows, in_cols, input.type);
  kernel_mt.reset(in_cols, kernel.bz, kernel.type);
  result.reset(in_rows, kernel.bz, FP32);
  // 2D input
  im2col_src_mt(input, kernel, input_mt, stride, dilation);
  // 2D kernel
  im2col_kernel_mt(kernel, kernel_mt);

  // gemm
  uint16_t **in1 = new uint16_t *[in_rows];
  uint16_t **in2 = new uint16_t *[in_cols];
  for (int i = 0; i < in_rows; i++) {
    in1[i] = new uint16_t[in_cols];
    for (int j = 0; j < in_cols; j++) {
      in1[i][j] = input_mt.data[i][j];
    }
  }
  for (int i = 0; i < in_cols; i++) {
    in2[i] = new uint16_t[kernel.bz];
    for (int j = 0; j < kernel.bz; j++) {
      in2[i][j] = kernel_mt.data[i][j];
    }
  }
  matrix_opcode *m_opcode = matrix_opcode::generate(0x0);
  matmul_subcmd_sym_quant(in1, in2, result.data, nullptr, nullptr, in_cols,
                          in_rows, kernel.bz, dop_type, m_opcode);

  delete m_opcode;
  for (int i = 0; i < in_rows; i++) {
    delete[] in1[i];
  }
  delete[] in1;
  for (int i = 0; i < in_cols; i++) {
    delete[] in2[i];
  }
  delete[] in2;

  // print_info
  // print_info(src, kernel, result);
}

// src: FP16 [1,C_in,H,W]
// kernel: FP16 [C_out,C_in,KH,KW]
// pad, stride, dilation
// FIXME: dop_size
void conv3D_mt(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
               MATRIX_4D<uint64_t> &result, conv_padding &pad,
               conv_stride &stride, conv_dilation &dilation) {
  // pad src_data->input
  MATRIX_4D<uint16_t> input;
  src.mat_padding(input, pad);
  // conditional compare
  assert(kernel.ch == input.ch);
  DataType dop_type = getDop_type(input.type, kernel.type);
  int out_row =
      (input.nr - dilation.h_rate * (kernel.nr - 1) - 1) / stride.stride_h + 1;
  int out_col =
      (input.nc - dilation.w_rate * (kernel.nc - 1) - 1) / stride.stride_w + 1;
  if (out_row <= 0 || out_col <= 0) {
    std::cerr << "Error: output size is non-positive.Check input parameters."
              << std::endl;
    return;
  }
  // convolution
  int c_out = kernel.bz;
  result.reset(input.bz, c_out, out_row, out_col, FP32);
  size_t dop_elmsize = kernel.nr * kernel.nc;

#if ENABLE_OPENMP
#pragma omp parallel for collapse(4) schedule(static)
#endif
  for (int ob = 0; ob < input.bz; ob++) {
    for (int och = 0; och < c_out; och++) {
      for (int oh = 0; oh < out_row; oh++) {
        for (int ow = 0; ow < out_col; ow++) {
          float32_t result_f32, dop_f32;
          result_f32.v = 0;
          // input channel sum of mul_add
          for (int ich = 0; ich < input.ch; ich++) {
            uint16_t input_arr[dop_elmsize];
            uint16_t kernel_arr[dop_elmsize];
            for (int kh = 0; kh < kernel.nr; kh++) {
              for (int kw = 0; kw < kernel.nc; kw++) {
                int ih = oh * stride.stride_h + kh * dilation.h_rate;
                int iw = ow * stride.stride_w + kw * dilation.w_rate;
                if (ih >= 0 && ih < input.nr && iw >= 0 && iw < input.nc) {
                  input_arr[kh * kernel.nc + kw] = input.data[ob][ich][ih][iw];
                  kernel_arr[kh * kernel.nc + kw] =
                      kernel.data[och][ich][kh][kw];
                }
              }
            }
            dop_f32.v = operators::dop_product_non_sym(input_arr, kernel_arr,
                                                       dop_elmsize, dop_type);
            result_f32.v = fp32add(result_f32.v, dop_f32.v);
          }
          result.data[ob][och][oh][ow] = result_f32.v;
        }
      }
    }
  }
  // print_info
  // print_info(src, kernel, result);
}

bool im2col_conv3D_cmp(MATRIX_2D<uint64_t> &im2col_r,
                       MATRIX_4D<uint64_t> &conv3D_r, int out_channel,
                       int out_height, int out_width) {
  // 2D:[out_height*out_width, out_channel]
  // 4D:[out_batchsize, out_channel, out_height,out_width]
  assert(conv3D_r.bz == 1 && "only support batch_size=1");
  for (int c = 0; c < conv3D_r.ch; c++) {
    for (int h = 0; h < conv3D_r.nr; h++) {
      for (int w = 0; w < conv3D_r.nc; w++) {
        int im2_row = h * conv3D_r.nc + w;
        int im2_col = c;
        uint64_t im2_value, conv3D_value;
        im2_value = im2col_r.data[im2_row][im2_col];
        conv3D_value = conv3D_r.data[0][c][h][w];
        if (im2_value != conv3D_value) {
          cout << "different result:" << hex << im2_value << " " << conv3D_value
               << "->im2_col[" << im2_row << "," << im2_col << "], conv3D[" << c
               << "," << h << "," << w << "]" << endl;
          return false;
        }
      }
    }
  }
  return true;
}

void print_info(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                MATRIX_4D<uint64_t> &result) {
  cout << "   Input size:[N,C_in,H,W]:[" << src.bz << "," << src.ch << ","
       << src.nr << "," << src.nc << "]" << endl;
  cout << "   Kernel size:[C_out,C_in,H,W]:[" << kernel.bz << "," << kernel.ch
       << "," << kernel.nr << "," << kernel.nc << "]" << endl;
  cout << "   Result(Conv3D): out size[N,C_out,H,W]:[" << src.bz << ","
       << result.ch << "," << result.nr << "," << result.nc << "]" << endl;
  cout << "   Print data************" << endl;
  src.print_mt_hex();
  kernel.print_mt_hex();
  result.print_mt_hex();
}

void print_info(MATRIX_4D<uint16_t> &src, MATRIX_4D<uint16_t> &kernel,
                MATRIX_2D<uint64_t> &result) {
  cout << "   Input size:[N,C_in,H,W]:[" << src.bz << "," << src.ch << ","
       << src.nr << "," << src.nc << "]" << endl;
  cout << "   Kernel size:[C_out,C_in,H,W]:[" << kernel.bz << "," << kernel.ch
       << "," << kernel.nr << "," << kernel.nc << "]" << endl;
  cout << "   Result(Im2col): out size[H*W,C_out]:[" << result.nr << ","
       << result.nc << "]" << endl;
  cout << "   Print data************" << endl;
  src.print_mt_hex();
  kernel.print_mt_hex();
  result.print_mt_hex();
}

DataType getDop_type(DataType src_type, DataType kernel_type) {
  if (src_type == kernel_type) {
    return src_type;
  } else if (src_type == FP8E5 && kernel_type == FP6E3) {
    return FP8E5FP6E3;
  } else if (src_type == FP8E5 && kernel_type == FP6E2) {
    return FP8E5FP6E2;
  } else if (src_type == FP8E4 && kernel_type == FP6E3) {
    return FP8E4FP6E3;
  } else if (src_type == FP8E4 && kernel_type == FP6E2) {
    return FP8E4FP6E2;
  } else if (src_type == FP16 && kernel_type == UINT4) {
    return FP16UINT4;
  } else if (src_type == FP16 && kernel_type == SINT4) {
    return FP16SINT4;
  } else if (src_type == BF16 && kernel_type == UINT4) {
    return BF16UINT4;
  } else if (src_type == BF16 && kernel_type == SINT4) {
    return BF16SINT4;
  } else if (src_type == SINT8 && kernel_type == UINT8) {
    return SINT8UINT8;
  } else if (src_type == UINT8 && kernel_type == SINT8) {
    return UINT8SINT8;
  } else if (src_type == SINT16 && kernel_type == SINT8) {
    return SINT16SINT8;
  } else if (src_type == UINT16 && kernel_type == SINT8) {
    return UINT16SINT8;
  } else if (src_type == SINT16 && kernel_type == UINT4) {
    return SINT16UINT4;
  } else if (src_type == SINT16 && kernel_type == SINT4) {
    return SINT16SINT4;
  } else if (src_type == UINT16 && kernel_type == UINT4) {
    return UINT16UINT4;
  } else if (src_type == UINT16 && kernel_type == SINT4) {
    return UINT16SINT4;
  } else {
    cout << "Invalid src_type " << src_type << ", kernel_type " << kernel_type
         << ",  return FP16" << endl;
    return FP16;
  }
}

void set_data(MATRIX_2D<uint16_t> &dat, uint16_t arr[], DataType type, int row,
              int col) {
  // W->H
  dat.reset(row, col, type);
  for (int h = 0; h < row; h++) {
    for (int w = 0; w < col; w++) {
      dat.data[h][w] = arr[h * col + w];
    }
  }
}

void set_data(MATRIX_4D<uint16_t> &dat, uint16_t arr[], DataType type,
              int batchz, int channel, int row, int col) {
  // W->H->C->B
  dat.reset(batchz, channel, row, col, type);
  for (int b = 0; b < batchz; b++) {
    for (int c = 0; c < channel; c++) {
      for (int h = 0; h < row; h++) {
        for (int w = 0; w < col; w++) {
          int id = b * channel * row * col + c * row * col + h * col + w;
          if (type == SINT8 || type == UINT8) {
            dat.data[b][c][h][w] =
                (id % 2) ? ((arr[id / 2] >> 8) & 0xff) : (arr[id / 2] & 0xff);
          } else {
            dat.data[b][c][h][w] = arr[id];
          }
        }
      }
    }
  }
}
void set_data(uint64_t arr[], MATRIX_2D<uint64_t> &dat, int row, int col) {
  // W->H
  for (int h = 0; h < row; h++) {
    for (int w = 0; w < col; w++) {
      arr[h * col + w] = dat.data[h][w];
    }
  }
}

void set_data(uint64_t arr[], MATRIX_4D<uint64_t> &dat, int batchz, int channel,
              int row, int col) {
  // W->H->C->B
  for (int b = 0; b < batchz; b++) {
    for (int c = 0; c < channel; c++) {
      for (int h = 0; h < row; h++) {
        for (int w = 0; w < col; w++) {
          arr[b * channel * row * col + c * row * col + h * col + w] =
              dat.data[b][c][h][w];
        }
      }
    }
  }
}

void conv3D(uint16_t src_arr[], uint16_t kernel_arr[],
            operators::MATRIX_4D<uint64_t> &out, DataType src_type,
            DataType kernel_type, int src_batchsize, int src_channel,
            int src_height, int src_width, int kernel_cout, int kernel_cin,
            int kernel_height, int kernel_width, uint16_t pad_value,
            uint32_t pad_top, uint32_t pad_bottom, uint32_t pad_left,
            uint32_t pad_right, uint32_t stride_h, uint32_t stride_w,
            uint32_t dilation_h, uint32_t dilation_w) {
  operators::MATRIX_4D<uint16_t> u16_src_mt, u16_k_mt;
  operators::conv_stride stride;
  operators::conv_dilation dilation;
  operators::conv_padding pad;
  operators::set_data(u16_src_mt, src_arr, src_type, src_batchsize, src_channel,
                      src_height, src_width);
  operators::set_data(u16_k_mt, kernel_arr, kernel_type, kernel_cout,
                      kernel_cin, kernel_height, kernel_width);
  pad.set_padv(pad_value);
  pad.set(pad_top, pad_bottom, pad_left, pad_right);
  stride.set(stride_h, stride_w);
  dilation.set(dilation_h, dilation_w);
  operators::conv3D_mt(u16_src_mt, u16_k_mt, out, pad, stride, dilation);
}

void im2col(uint16_t src_arr[], uint16_t kernel_arr[],
            operators::MATRIX_2D<uint64_t> &out, DataType src_type,
            DataType kernel_type, int src_batchsize, int src_channel,
            int src_height, int src_width, int kernel_cout, int kernel_cin,
            int kernel_height, int kernel_width, uint16_t pad_value,
            uint32_t pad_top, uint32_t pad_bottom, uint32_t pad_left,
            uint32_t pad_right, uint32_t stride_h, uint32_t stride_w,
            uint32_t dilation_h, uint32_t dilation_w) {
  operators::MATRIX_4D<uint16_t> u16_src_mt, u16_k_mt;
  operators::conv_stride stride;
  operators::conv_dilation dilation;
  operators::conv_padding pad;
  operators::set_data(u16_src_mt, src_arr, src_type, src_batchsize, src_channel,
                      src_height, src_width);
  operators::set_data(u16_k_mt, kernel_arr, kernel_type, kernel_cout,
                      kernel_cin, kernel_height, kernel_width);
  pad.set_padv(pad_value);
  pad.set(pad_top, pad_bottom, pad_left, pad_right);
  stride.set(stride_h, stride_w);
  dilation.set(dilation_h, dilation_w);
  operators::im2col_mt(u16_src_mt, u16_k_mt, out, pad, stride, dilation);
}

} // namespace operators