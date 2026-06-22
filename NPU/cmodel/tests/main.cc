#include "test_head.h"
#include "test_vae.h"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
void test_dop() {
  softfloat_roundingMode = 0;
#if 1
  DataType type[] = {BF16, MXFP8MXFP8, NVFP4E2, MXFP4MXFP4, SINT16SINT4};
  size_t num[] = {16, 16, 64, 64, 32};
  // DataType type[] = {BF16,  FP16,       BF16SINT4, BF16UINT4,
  //                    FP8E4, MXFP8MXFP8, NVFP4E2};
  // size_t num[] = {32, 32, 16, 16, 16, 16, 16};
  int type_size = sizeof(type) / sizeof(type[0]);
  int num_size = sizeof(num) / sizeof(num[0]);
  assert(type_size == num_size && "size dismatch");
  for (int i = 4; i < type_size; i++) {
    printf("=========Test dop for data_type: %d===========\n", type[i]);
    test_dop_unit(type[i], num[i]);
  }
#endif
  uint16_t fp16_array1[] = {0001};
  uint16_t fp16_array2[] = {
      0Xff80
      //     0x00000009, 0x00000007, 0x0000000c, 0x00000006,
  };
  size_t length = sizeof(fp16_array1) / sizeof(fp16_array1[0]);
  cm_exceptionFlags = 0;
  test_dop_unit(SINT16SINT4, length, fp16_array1, fp16_array2);
  printf("cm_exceptionFlags:");
  operators::print_binary_uint32(cm_exceptionFlags);
}

void test_matmul() {
  int dst_m = 17;
  int common_k = 17;
  int dst_n = 17;
  DataType data_type = SINT16SINT4;
  uint64_t mat_opcode;
  mat_opcode = 0x0000;
  uint16_t **mat_a = new uint16_t *[dst_m];
  uint16_t **mat_b = new uint16_t *[common_k];
  uint64_t **dst_mat = new uint64_t *[common_k];
  for (int i = 0; i < dst_m; i++) {
    mat_a[i] = new uint16_t[common_k];
    for (int j = 0; j < common_k; j++) {
      // mat_a[i][j] = 0x3c00+i+j;
      mat_a[i][j] = 0xffff;
    }
  }

  for (int i = 0; i < common_k; i++) {
    mat_b[i] = new uint16_t[dst_n];
    for (int j = 0; j < dst_n; j++) {
      mat_b[i][j] = 0x1;
    }
  }

  for (int i = 0; i < dst_m; i++) {
    dst_mat[i] = new uint64_t[dst_n];
    for (int j = 0; j < dst_n; j++) {
      dst_mat[i][j] = 0;
    }
  }

  // matmul_subcmd_128_k(mat_a, mat_b, dst_mat, col, row, col2, 16, FP16);
  matmul_subcmd_sym_quant(mat_a, mat_b, dst_mat, nullptr, nullptr, common_k,
                          dst_m, dst_n, data_type, mat_opcode);
  operators::otile_location_t otile_location;
  otile_to_mn_c(1, 2, 2, data_type, dst_m, dst_n, otile_location);
  matmul_subcmd_log(mat_a, mat_b, dst_mat, nullptr, nullptr, common_k, dst_m,
                    dst_n, data_type, mat_opcode, 0, 0, otile_location);
  for (int i = 0; i < dst_m; i++) {
    for (int j = 0; j < dst_n; j++)
      printf(" 0x%lx", dst_mat[i][j]);
    delete[] dst_mat[i];
    delete[] mat_a[i];
    printf("\n");
  }
  delete[] dst_mat;
  delete[] mat_a;

  for (int i = 0; i < common_k; i++) {
    delete[] mat_b[i];
  }
  delete[] mat_b;
}
void test_pproc() {
  uint32_t row = 1;
  uint32_t column = 1;
  uint64_t enmode;
  uint64_t data_info;
  uint64_t mask;
  enmode = 0x100120060c;
  mask = 0x000000;
  data_info = 0x80008000002ce1a4;
  uint64_t data_instruct[] = {enmode,
                              data_info}; // uint64_t enmode, uint64_t datainfo

  size_t param_length = 7 * column * sizeof(uint16_t) + 576; // 512+64B pad
  uint16_t *params = (uint16_t *)malloc(param_length);
  uint64_t **res_temp = (uint64_t **)malloc(row * sizeof(uint64_t *));
  uint16_t **elw_temp = (uint16_t **)malloc(row * sizeof(uint16_t *));
  uint32_t **des = (uint32_t **)malloc(row * sizeof(uint32_t *));

  for (int i = 0; i < param_length / 2; i++) {
    params[i] = 0x3c00;
  }
  params[256] = 0x4da0;
  params[257] = 0x9dfe;

  for (int i = 0; i < row; i++) {
    res_temp[i] = (uint64_t *)malloc(row * sizeof(uint64_t));
    for (int j = 0; j < column; j++) {
      res_temp[i][j] = 0x4314b31d;
    }
  }

  for (int i = 0; i < row; i++) {
    elw_temp[i] = (uint16_t *)malloc(row * sizeof(uint16_t));
    for (int j = 0; j < column; j++) {
      elw_temp[i][j] = 0;
    }
  }

  for (int i = 0; i < row; i++) {
    des[i] = (uint32_t *)malloc(row * sizeof(uint32_t));
    for (int j = 0; j < column; j++) {
      des[i][j] = 0;
    }
  }

  res_temp[0][0] = 0x4314b31d;

  printf("resource data as fp32:\n");
  for (int i = 0; i < row; i++) {

    for (int j = 0; j < column; j++) {
      printf("%f        ", *(float *)(&res_temp[i][j]));
      uint32_t a = 0x7c00;
      // printf("%f ", *(float *)(&a));
    }
    printf("\n");
  }
  softfloat_roundingMode = softfloat_round_near_even;
  printf("destination data as hex:\n");
  pproc_subcmd(params, data_instruct[0], data_instruct[1], mask, res_temp,
               elw_temp, des, row, column);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      printf("0x%08x, ", des[i][j]);
    }
    printf("\n");
  }

  printf("destination data as fp32:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      uint32_t res_fp32 = fp16_to_fp32(des[i][j]);
      // uint32_t res_fp32 = fp16_to_fp32_alpha(0x8000);
      printf("%8f ", *(float *)(&res_fp32));
    }
    printf("\n");
  }
  for (int i = 0; i < row; i++) {
    free(res_temp[i]);
    free(elw_temp[i]);
    free(des[i]);
  }
  free(params);
  free(res_temp);
  free(elw_temp);
  free(des);
}

void test_data_convert() {
  // uint32_t a=0x400001FF;
  uint64_t a = 0x40000000;
  uint64_t b;
  uint32_t c;
  a = 0x1284;
  a = 0x2062a80c;
  // a = 0x8adc102;
  a = 0xb603e400;
  a = 0xfc000008;
  a = 0x2011c0;
  a = 0x00;
  a = 0x80000010;
  a = 0xff7ffff;
  a = 0x3f829042;
  a = 0x3f829000;
  a = 0x7f80;
  b = 0x267ffffa;
  c = 0x0;
  uint64_t result = 0;
  softfloat_roundingMode = 0;
  cm_exceptionFlags = 0;
  // fp24cmp(a, b);
  // fp24_0_max(a);
  //  result = bf16add(a, b);
  //  result = fp32mulAdd(a, b,c);
  uint32_t a_beta = bf16max(a, c);
  printf("cm_exceptionFlags:");
  operators::print_binary_uint32(cm_exceptionFlags);
  float32_t temp_a;
  temp_a.v = a;
  // uint32_t result_beta = f32_to_f16(temp_a).v;
  a = fp8e4_to_fp32(a);
  b = fp8e4_to_fp32(b);
  uint32_t result_beta = fp32mul(a, b);
  // result_beta = fp24add(a, b);

  // operators::print_binary_uint32(result_beta);
  operators::print_binary_uint32(a_beta);
  // operators::print_binary_uint32(a_beta);
  // 打印结果
  printf("Final fp32 result: %f\n", *(float *)(&a_beta));
  printf("Result in hex: 0x%08x\n", a_beta);
}

void test_softfp() {
  printf("-- Begin test: softfp\n");
  float16_t f16;
  f16 = ui32_to_f16(1);
  printf("fp16(1) = %04x\n", f16.v);
  float32_t f32;
  f32.v = (0x7f << 23) | 0x7fffff;
  float v32 = *(float *)&f32;
  f16 = f32_to_f16(f32);
  printf("fp16(%.2f) = %04x\n", v32, f16.v);
  printf("\n");
}

void test_sqrt() {
  cout << "\n------TEST SFU SQRT FUNCTION------" << endl;
  // operators::SqrtCoef(FP16, operators::SQRT);
  // operators::SqrtCoef(FP32, operators::SQRT);
  // operators::SqrtCoef(FP16, operators::RCP);
  // operators::SqrtCoef(FP32, operators::RCP);

#if 0
  //// Test poly for a case
  double bsize = 0.03125;
  double nr = sqrt(3) / 2;
  double x0 = bsize / 2 * (1 + nr);
  double x1 = bsize / 2;
  double x2 = bsize / 2 * (1 - nr);
  double diffx2_0 = x2 - x0;
  double diffx1_0 = x1 - x0;
  double diffx2_1 = x2 - x1;
  double y0 = sqrt(x0 + 1);
  double y1 = sqrt(x1 + 1);
  double y2 = sqrt(x2 + 1);
  double diffy1_0 = y1 - y0;
  double diffy2_1 = y2 - y1;
  double a1 = diffy1_0 / diffx1_0;
  double a2 = (diffy2_1 / diffx2_1 - diffy1_0 / diffx1_0) / diffx2_0;
  double c0 = y0 + a2 * x0 * x1 - a1 * x0;
  double c1 = a1 - a2 * (x0 + x1);
  double c2 = a2;
  cout << a2 << "," << a1 << endl;
  cout << c2 << "," << c1 << "," << c0 << endl;
  double x = 1.02;
  double rlt = c2 * (x - 1) * (x - 1) + c1 * (x - 1) + c0;
  double sx = sqrt(x);
  cout << "math sqrt(x) " << sx << ", poly " << rlt << endl;
#endif

#if 0
  // rcp [1.023438,1.03125):  0.0005233383,0.00390625,0.007289162,0.9222736,-0.9546947,0.9770992,0x3
  double x_left = 1.023438;
  double c0 = 0.9770992;
  double c1 = -0.9546947;
  double c2 = 0.9222736;
  // double c0 = 0.9770992; // rtl lut table
  // double c1 = -0.954692;
  // double c2 = 0.9222685;
  double x = 1.03;
  double rlt = c2 * (x - x_left) * (x - x_left) + c1 * (x - x_left) + c0;
  double rx = operators::rcp(x);
  cout << "math rcp(x) " << rx << ", poly " << rlt << endl;
  // rcpsqrt [1.0625,1.078125):  0.001046677,0.0078125,0.01457832,0.3180045,-0.4565266,0.9701425,0x4
  x_left = 1.0625;
  c0 = 0.9701425;
  c1 = -0.4565266;
  c2 = 0.3180045;
  x = 1.065;
  rlt = c2 * (x - x_left) * (x - x_left) + c1 * (x - x_left) + c0;
  rx = operators::rcp_sqrt(x);
  cout << "math rcp_sqrt(x) " << rx << ", poly " << rlt << endl;
#endif

#if 1
  softfloat_roundingMode =
      softfloat_round_near_even; // set round mode
                                 // float x = 1.0;
                                 // uint32_t x_i = operators ::float_to_ui32(x);
                                 // uint32_t rlt = operators ::sfu_sqrt(x_i);
                                 // cout << "in:" << x << ",sqrt(x):" << sqrt(x)
                                 // << endl;
  // cout << hex << "in: 0x" << x_i << ", result:0x" << rlt << "<-->(float)in: "
  // << operators ::ui32_to_float(x_i)
  //      << ", result:" << operators ::ui32_to_float(rlt) << endl;

  // uint32_t rcp_rlt = operators ::sfu_rcp(x_i);
  // cout << "in:" << x << ",rcp(x):" << operators::rcp(x) << endl;
  // cout << hex << "in: 0x" << x_i << ", result:0x" << rcp_rlt <<
  // "<-->(float)in: " << operators ::ui32_to_float(x_i)
  //      << ", result:" << operators ::ui32_to_float(rcp_rlt) << endl;

  float in_arr[11] = {-0.0,  0.0, 0.075, 1.0,      1.5, 3.65,
                      3.875, 7,   16,    30.86345, -1.5};
  // float in_arr[1] = {-1.5};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t sqrt_rlt = operators ::sfu_sqrt(x_i);
    cout << "in:" << in_arr[i] << "<-->cmath sqrt(x):" << sqrt(in_arr[i])
         << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sqrt_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sqrt_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t sub_norm[15] = {0x7f30001f, 0xff30001f, 0xFF800000, 0x7F800000,
                           0xFFC00000, 0x7FC00000, 0x400000,   0x8040000,
                           0x10400000, 0x400,      0x576,      0x90616efa,
                           0x90100000, 0xff070fab, 0x7c0000};
  // uint32_t sub_norm[1] = {0x3f900000};
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t sqrt_rlt = operators ::sfu_sqrt(x_i);
    cout << "in:" << x_f << "<-->cmath sqrt(x):" << sqrt(x_f) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sqrt_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sqrt_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
#endif
}
void test_rcp() {
  cout << "\n------TEST SFU RCP FUNCTION------" << endl;
  float in_arr[11] = {-0.0,  0.0, 0.075, 1.0,      1.5, 3.65,
                      3.875, 7,   16,    30.86345, -1.5};
  // float in_arr[1] = {-1.5};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t rcp_rlt = operators ::sfu_rcp(x_i);
    cout << "in:" << in_arr[i]
         << "<-->cmath rcp(x):" << operators::rcp(in_arr[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << rcp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(rcp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t sub_norm[20] = {0x7f30001f, 0xff30001f, 0xFF800000, 0x7F800000,
                           0xFFC00000, 0x7FC00000, 0x400000,   0x8040000,
                           0x10400000, 0x400,      0x576,      0x90616efa,
                           0x90100000, 0xff070fab, 0x7c0000,   0x41700000,
                           0x40a00000, 0x41100000, 0x40800000, 0x3e2aaaaa};
  // uint32_t sub_norm[1] = {0x3f900000};
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t rcp_rlt = operators ::sfu_rcp(x_i);
    cout << "in:" << x_f << "<-->cmath rcp(x):" << operators::rcp(x_f) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << rcp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(rcp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
}

void test_rcpsqrt() {
  cout << "\n------TEST SFU RCPSQRT FUNCTION------" << endl;
  // operators::SqrtCoef(FP16, operators::RCPSQRT);
  // operators::SqrtCoef(FP32, operators::RCPSQRT);
  softfloat_roundingMode =
      softfloat_round_max; // set round mode no longer in effect
  float in_arr[11] = {-0.0,  0.0, 0.075, 1.0,      1.5, 3.65,
                      3.875, 7,   16,    30.86345, -1.5};
  // float in_arr[1] = {3.65};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t rcp_rlt = operators ::sfu_rcpsqrt(x_i);
    cout << "in:" << in_arr[i]
         << "<-->cmath rcpsqrt(x):" << operators::rcp_sqrt(in_arr[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << rcp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(rcp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t sub_norm[15] = {0x7f30001f, 0xff30001f, 0xFF800000, 0x7F800000,
                           0xFFC00000, 0x7FC00000, 0x400000,   0x8040000,
                           0x10400000, 0x400,      0x576,      0x90616efa,
                           0x90100000, 0xff070fab, 0x7c0000};
  // uint32_t sub_norm[1] = {0x3f900000};
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t rcp_rlt = operators ::sfu_rcpsqrt(x_i);
    cout << "in:" << x_f << "<-->cmath rcpsqrt(x):" << operators::rcp_sqrt(x_f)
         << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << rcp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(rcp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
}

void test_tanh() {
  cout << "\n------TEST SFU TANH FUNCTION------" << endl;
  // operators::TanhCoef(DataType::FP16);
  // operators::TanhCoef(DataType::FP32);
#if 1
  float in_arr[10] = {-0.0, 0.0, 1.0, -1.5, -3.65, 1.5, 2, 4, 7.5, 60.8};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t tanh_rlt = operators ::sfu_tanh(x_i);
    cout << "in:" << in_arr[i] << "<-->cmath tanh(x):" << tanh(in_arr[i])
         << ", tanh_f(x):" << operators::tanh_f(in_arr[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << tanh_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(tanh_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalizations
  uint32_t sub_norm[10] = {0xFF800000, 0x7F800000, 0xFFC00000, 0x7FC00000,
                           0x400,      0x400000,   0x8040000,  0x10400000,
                           0x807ba457, 0x576};
  // uint32_t sub_norm[1] = {0x576}; //[0,0.0009765625):
  // 0,0.0004882812,0.0009765625,-0.000488281,1,0,0x0
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t tanh_rlt = operators ::sfu_tanh(x_i);
    cout << "in:" << x_f << "<-->cmath tanh(x):" << tanh(x_f)
         << ", tanh_f(x):" << operators::tanh_f(x_f) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << tanh_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(tanh_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
}

void test_sigmoid() {
  cout << "\n------TEST SFU SIGMOID FUNCTION------" << endl;
  // uint8_t mode = 2;
  // operators::TanhCoef(DataType::FP32, mode);

  float in_arr[9] = {-0.0, 0.0, -0.0075, 1.0, -1.5, -3.65, 4, 7.5, 60.8};
  // float in_arr[1] = {4};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t sig_rlt = operators ::sfu_sigmoid(x_i);
    cout << "in:" << in_arr[i]
         << "<-->cmath sigmoid(x):" << operators::sigmoid_f(in_arr[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sig_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sig_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // // denormalization
  uint32_t sub_norm[11] = {0xFF800000, 0x7F800000, 0xFFC00000, 0x7FC00000,
                           0x400,      0x400000,   0x8040000,  0x10400000,
                           0x80000400, 0x576,      0x3ae7eea7};
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t sig_rlt = operators ::sfu_sigmoid(x_i);
    cout << "in:" << x_f << "<-->cmath sigmoid(x):" << operators::sigmoid_f(x_f)
         << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sig_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sig_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;

#if 0
  // fp24 test
  cout << "*****float24 sigmoid test******" << endl;
  uint24_t f24_in_arr[8] = {0x0, 0x7F8000, 0x7FC000, 0xBFC000, 0x412D85, 0x42A10E, 0x804000, 0x576};
  for (int i = 0; i < sizeof(f24_in_arr) / sizeof(uint32_t); i++) {
    cm_exceptionFlags =0;
    uint24_t x_i = f24_in_arr[i];
    uint32_t x_f32 = operators::f24_to_f32(x_i);
    float x_f = operators ::ui32_to_float(x_f32);
    uint24_t sig_rlt = operators ::sfu_sigmoid_f24(x_i);
    uint32_t sig_f32 = operators::f24_to_f32(sig_rlt);
    cout << "in:" << x_f << "<-->cmath sigmoid(x):" << operators::sigmoid_f(x_f) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sig_rlt << "<-->(float)in: " << operators ::ui32_to_float(x_f32)
         << ", result:" << operators ::ui32_to_float(sig_f32) << endl
         << endl;
  }
#endif
}

void test_exp2() {
  cout << "\n------TEST SFU EXP2 FUNCTION------" << endl;
// operators::ExpCoef(DataType::FP16);
// operators::ExpCoef(DataType::FP32);
#if 0
  cout << "Test FP16 type...." << endl;
  float exp_in_arr[14] = {-0.0, 0.0, 0.0075, -0.0685e-5, 1.0, -1.5, -3.65, 4, 7.526, 60.8, -95.856, 128, 200, 510.625};
  // float exp_in_arr[1] = {-0.0685e-5};
  for (int i = 0; i < sizeof(exp_in_arr) / sizeof(float); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = operators ::float_to_ui16(exp_in_arr[i]);
    uint16_t exp_rlt = operators ::sfu_exp(x_i);
    float y_f = operators::exp2_f(exp_in_arr[i]);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << exp_in_arr[i] << "<-->cmath exp(x):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt << "<-->(float)in: " << operators ::ui16_to_float(x_i)
         << ", result:" << operators ::ui16_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint16_t exp_sub_norm[20] = {0xFF80, 0x7F80, 0xFFC0, 0x7FC0, 0x455e, 0xff30, 0x4000, 0x8040, 0x1040, 0x8004,
                               0x576,  0xaee1, 0x3e39, 0x3029, 0x3b4d, 0xc500, 0xc100, 0xc84c, 0xb733, 0xb866};
  // uint16_t exp_sub_norm[1] = {0xb733};
  for (int i = 0; i < sizeof(exp_sub_norm) / sizeof(uint16_t); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = exp_sub_norm[i];
    float x_f = operators ::ui16_to_float(x_i);
    uint16_t exp_rlt = operators ::sfu_exp(x_i);
    float y_f = operators::exp2_f(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << x_f << "<-->cmath exp(x):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt << "<-->(float)in: " << operators ::ui16_to_float(x_i)
         << ", result:" << operators ::ui16_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
#if 1
  cout << "Test FP32 type...." << endl;
  float in_arr[15] = {-0.0, 0.0,   0.0075, -0.685e-7, 1.0, -1.5, -3.65,  3.6,
                      4,    7.526, 60.8,   -95.856,   128, 200,  510.625};
  // float in_arr[1] = {3.6};
  for (int i = 0; i < sizeof(in_arr) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(in_arr[i]);
    uint32_t sig_rlt = operators ::sfu_exp(x_i);
    cout << "in:" << in_arr[i]
         << "<-->cmath exp2(x):" << operators::exp2_f(in_arr[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sig_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sig_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t sub_norm[13] = {0xFF800000, 0x7F800000, 0xFFC00000, 0x7FC00000,
                           0x7f30001f, 0xff30001f, 0x400000,   0x8040000,
                           0x10400000, 0x80000400, 0x576,      0xaee18826,
                           0xc2fd679b};
  // uint32_t sub_norm[1] = {0xc2fd679b};
  for (int i = 0; i < sizeof(sub_norm) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sub_norm[i];
    float x_f = operators ::ui32_to_float(x_i);
    uint32_t sig_rlt = operators ::sfu_exp(x_i);
    cout << "in:" << x_f << "<-->cmath exp2(x):" << operators::exp2_f(x_f)
         << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sig_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(sig_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
#endif
}
void test_expE() {
  cout << "\n------TEST SFU EXP FUNCTION------" << endl;
#if 0
  cout << "Test FP16 type...." << endl;
  // exp(x)
  float exp_in_arr[14] = {-0.0, 0.0, 0.0075, -0.0685e-5, 1.0, -1.5, -3.65, 4, 7.526, 60.8, -95.856, 128, 200, 510.625};
  // float exp_in_arr[1] = {-0.0685e-5};
  for (int i = 0; i < sizeof(exp_in_arr) / sizeof(float); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = operators ::float_to_ui16(exp_in_arr[i]);
    cout << "x/ln2:" << operators::div_ln2(exp_in_arr[i]) << endl;
    uint16_t exp_rlt = operators ::sfu_expE(x_i);
    float y_f = operators::exp_c(exp_in_arr[i]);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << exp_in_arr[i] << "<-->cmath exp(x):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt << "<-->(float)in: " << operators ::ui16_to_float(x_i)
         << ", result:" << operators ::ui16_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint16_t exp_sub_norm[21] = {0xFF80, 0x7F80, 0xFFC0, 0x7FC0, 0x455e, 0xff30, 0x4000, 0x8040, 0x1040, 0x8004, 0x576,
                               0xaee1, 0xb90a, 0x3e39, 0x3029, 0x3b4d, 0xc500, 0xcc0f, 0xc84c, 0xb733, 0xb866};
  // uint16_t exp_sub_norm[1] = {0xcc0f};
  // uint16_t exp_sub_norm[7] = {0x17ff, 0x2bff, 0x3cf7, 0x44d3, 0x4fff, 0x4a01, 0x7bff};
  for (int i = 0; i < sizeof(exp_sub_norm) / sizeof(uint16_t); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = exp_sub_norm[i];
    float x_f = operators ::ui16_to_float(x_i);
    cout << "x/ln2:" << operators::div_ln2(x_f) << endl;
    uint16_t exp_rlt = operators ::sfu_expE(x_i);
    float y_f = operators::exp_c(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << x_f << "<-->cmath exp(x):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt << "<-->(float)in: " << operators ::ui16_to_float(x_i)
         << ", result:" << operators ::ui16_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
#if 1
  cout << "Test FP32 type...." << endl;
  // exp(x)
  float exp_in_arr2[14] = {-0.0, 0.0,   0.0075, -0.0685e-5, 1.0, -1.5, -3.65,
                           4,    7.526, 60.8,   -95.856,    128, 200,  510.625};
  // float exp_in_arr[2] = {-3.65, 60.8};
  for (int i = 0; i < sizeof(exp_in_arr2) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(exp_in_arr2[i]);
    cout << "x/ln2:" << operators::div_ln2(exp_in_arr2[i]) << endl;
    uint32_t exp_rlt = operators ::sfu_expE(x_i);
    cout << "in:" << exp_in_arr2[i]
         << "<-->cmath exp(x):" << operators::exp_c(exp_in_arr2[i]) << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t exp_sub_norm2[13] = {0xFF800000, 0x7F800000, 0xFFC00000, 0x7FC00000,
                                0x7f30001f, 0xff30001f, 0x400000,   0x8040000,
                                0x10400000, 0x80000400, 0x576,      0xaee18826,
                                0x3e3950bb};
  // uint32_t exp_sub_norm[1] = {0x3cf1ea77};
  for (int i = 0; i < sizeof(exp_sub_norm2) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = exp_sub_norm2[i];
    float x_f = operators ::ui32_to_float(x_i);
    cout << "x/ln2:" << operators::div_ln2(x_f) << endl;
    uint32_t exp_rlt = operators ::sfu_expE(x_i);
    cout << "in:" << x_f << "<-->cmath exp(x):" << operators::exp_c(x_f)
         << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << exp_rlt
         << "<-->(float)in: " << operators ::ui32_to_float(x_i)
         << ", result:" << operators ::ui32_to_float(exp_rlt) << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
}

void test_sinx() {
  cout << "\n------TEST SFU SIN FUNCTION------" << endl;
  // operators::SinCoef(DataType::FP16);
  // operators::CosCoef(DataType::FP16);
  // operators::SinCoef(DataType::FP32);
  // operators::CosCoef(DataType::FP32);
#if 0
  // float test
  float c1 = 6.2731, c0 = -8.93393e-10;
  float x = 0.0075; // 0.0125625
  float y = c1 * x + c0;
  cout << "cmath:" << sin(2 * M_PI * x) << ", poly:" << y << endl;
  c1 = -0.308178, c0 = 1;
  y = c1 * x + c0;
  cout << "cmath:" << cos(2 * M_PI * x) << ", poly:" << y << endl;
#endif
#if 0
  cout << "\033[32m" << "Test FP16 type......" << "\033[0m" << endl;
  float sin_in_arr[22] = {-0.0, 0.0, 0.0075, -0.0685e-5, 0.1625, -0.04789, 0.6875, 0.5,     -0.5, 1.0, -1.5,
                          1.5,  2,   -3.65,  3.9876,     4,      7.526,    60.8,   -95.856, 128,  200, 510.625};
  // float sin_in_arr[1] = {-95.856};
  for (int i = 0; i < sizeof(sin_in_arr) / sizeof(float); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = operators ::float_to_ui16(sin_in_arr[i]);
    uint16_t sin_rlt = operators ::sfu_sincos(x_i, 0);
    // uint16_t sin_rlt = sfu_func_fp16(x_i, 8);
    float x_f = operators ::ui16_to_float(x_i);
    float y_f = operators ::sin2pi(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << sin_in_arr[i] << "(" << x_f << ")<-->cmath sin(2Πx):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sin_rlt << "<-->(float)in: " << x_f
         << ", result:" << operators ::ui16_to_float(sin_rlt) << " <error:" << dec << abs(sin_rlt - y_c) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint16_t sin_sub_norm[19] = {0xFF80, 0x7F80, 0xFC00, 0x7C00, 0x4fbd, 0x576, 0x3bc0, 0x800a, 0x3e39, 0x64df,
                               0x998d, 0x8465, 0x24c6, 0x84c5, 0x100,  0x180, 0xa401, 0x2403, 0x1c00};
  // uint16_t sin_sub_norm[6] = {0x2403, 0x0080, 0x0001, 0x2001, 0x03ff, 0x4e9f};
  for (int i = 0; i < sizeof(sin_sub_norm) / sizeof(uint16_t); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = sin_sub_norm[i];
    float x_f = operators ::ui16_to_float(x_i);
    uint16_t sin_rlt = operators ::sfu_sincos(x_i, 0);
    float y_f = operators ::sin2pi(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << x_f << "<-->cmath sin(2Πx):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sin_rlt << "<-->(float)in: " << x_f
         << ", result:" << operators ::ui16_to_float(sin_rlt) << " <error:" << dec << abs(sin_rlt - y_c) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
  cout << "\033[32m"
       << "Test FP32 type......"
       << "\033[0m" << endl;
  float sin_in_arr2[22] = {-0.0,    0.0,   0.0075, -0.0685e-5, 0.1625, -0.04789,
                           0.6875,  -0.5,  0.5,    1.0,        -1.5,   1.5,
                           2,       -3.65, 3.9876, 4,          7.526,  60.8,
                           -95.856, 128,   200,    510.625};
  // float sin_in_arr2[1] = {-0.5};
  for (int i = 0; i < sizeof(sin_in_arr2) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(sin_in_arr2[i]);
    uint32_t sin_rlt2 = operators ::sfu_sincos(x_i, 0);
    // uint32_t sin_rlt2 = sfu_func_fp32(x_i, 8);
    float y_f2 = operators ::sin2pi(sin_in_arr2[i]);
    uint32_t y_c2 = operators::float_to_ui32(y_f2);
    cout << "in:" << sin_in_arr2[i] << "<-->cmath sin(2Πx):" << y_f2 << "<->0x"
         << hex << y_c2 << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sin_rlt2
         << " <error:" << dec << abs((long)sin_rlt2 - y_c2) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t sin_sub_norm2[20] = {0xFF800000, 0x7F800000, 0xFC000000, 0x7C000000,
                                0x4fbdab,   0x576,      0x3bc0efba, 0x800a6543,
                                0x4c8df530, 0x6eaced65, 0x3e396987, 0x998d5462,
                                0x84658752, 0x24c6845,  0x84c50000, 0x100,
                                0x180,      0xa401,     0x2403,     0x1c00};
  // uint32_t sin_sub_norm2[9] = {0x3eae196b, 0x3e000000, 0x16000000,
  // 0x3e0a3d71, 0xc83f6490,
  //                              0xbf000000, 0xbf200002, 0xb9000001,
  //                              0x80000003};
  for (int i = 0; i < sizeof(sin_sub_norm2) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = sin_sub_norm2[i];
    float x_f2 = operators ::ui32_to_float(x_i);
    uint32_t sin_rlt2 = operators ::sfu_sincos(x_i, 0);
    float y_f2 = operators ::sin2pi(x_f2);
    uint32_t y_c2 = operators::float_to_ui32(y_f2);
    cout << "in:" << x_f2 << "<-->cmath sin(2Πx):" << y_f2 << "<->0x" << hex
         << y_c2 << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << sin_rlt2
         << "<-->(float)in: " << x_f2
         << ", result:" << operators ::ui32_to_float(sin_rlt2)
         << " <error:" << dec << abs((long)sin_rlt2 - y_c2) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
}

void test_cosx() {
  cout << "\n------TEST SFU COS FUNCTION------" << endl;
#if 0
  cout << "Test FP16 type......" << endl;
  float cos_in_arr[22] = {-0.0, 0.0, 0.0075, -0.0685e-5, 0.1625, -0.04789, -0.25, 0.25,    0.6875, 1.0, -1.5,
                          1.5,  2,   -3.65,  3.9876,     4,      7.526,    60.8,  -95.856, 128,    200, 510.625};
  // float cos_in_arr[1] = {0.0075};
  for (int i = 0; i < sizeof(cos_in_arr) / sizeof(float); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = operators ::float_to_ui16(cos_in_arr[i]);
    uint16_t cos_rlt = operators ::sfu_sincos(x_i, 1);
    float x_f = operators ::ui16_to_float(x_i);
    float y_f = operators ::cos2pi(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << cos_in_arr[i] << "(" << x_f << ")<-->cmath cos(2Πx):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << cos_rlt << "<-->(float)in: " << x_f
         << ", result:" << operators ::ui16_to_float(cos_rlt) << " <error:" << dec << abs(cos_rlt - y_c) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint16_t cos_sub_norm[14] = {0xFF80, 0x7F80, 0xFC00, 0x7C00, 0x4fbd, 0x576,  0x3bc0,
                               0x800a, 0x3e39, 0x998d, 0x8465, 0x24c6, 0x84c5, 0x100};
  // uint16_t cos_sub_norm[1] = {0x576};
  for (int i = 0; i < sizeof(cos_sub_norm) / sizeof(uint16_t); i++) {
    cm_exceptionFlags =0;
    uint16_t x_i = cos_sub_norm[i];
    float x_f = operators ::ui16_to_float(x_i);
    uint16_t cos_rlt = operators ::sfu_sincos(x_i, 1);
    float y_f = operators ::cos2pi(x_f);
    uint16_t y_c = operators::float_to_ui16(y_f);
    cout << "in:" << x_f << "<-->cmath sin(2Πx):" << y_f << "<->0x" << hex << y_c << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << cos_rlt << "<-->(float)in: " << x_f
         << ", result:" << operators ::ui16_to_float(cos_rlt) << " <error:" << dec << abs(cos_rlt - y_c) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
#endif
  cout << "Test FP32 type......" << endl;
  float cos_in_arr2[22] = {-0.0,    0.0,   0.0075, -0.0685e-5, 0.1625, -0.04789,
                           -0.25,   0.25,  0.6875, 1.0,        -1.5,   1.5,
                           2,       -3.65, 3.9876, 4,          7.526,  60.8,
                           -95.856, 128,   200,    510.625};
  // float cos_in_arr2[1] = {-0.25};
  for (int i = 0; i < sizeof(cos_in_arr2) / sizeof(float); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = operators ::float_to_ui32(cos_in_arr2[i]);
    uint32_t cos_rlt2 = operators ::sfu_sincos(x_i, 1);
    // uint32_t sin_rlt = sfu_func_fp32(x_i, 8);
    float y_f2 = operators ::cos2pi(cos_in_arr2[i]);
    uint32_t y_c2 = operators::float_to_ui32(y_f2);
    cout << "in:" << cos_in_arr2[i] << "<-->cmath cos(2Πx):" << y_f2 << "<->0x"
         << hex << y_c2 << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << cos_rlt2
         << " <error:" << dec << abs((long)cos_rlt2 - y_c2) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  // denormalization
  uint32_t cos_sub_norm2[20] = {0xFF800000, 0x7F800000, 0xFC000000, 0x7C000000,
                                0x4fbdab,   0x576,      0x3bc0efba, 0x800a6543,
                                0x4c8df530, 0x6eaced65, 0x3e396987, 0x998d5462,
                                0x84658752, 0x24c6845,  0x84c50000, 0x100,
                                0x180,      0xa401,     0x2403,     0x1c00};
  // uint32_t cos_sub_norm2[1] = {0x7c000000};
  for (int i = 0; i < sizeof(cos_sub_norm2) / sizeof(uint32_t); i++) {
    cm_exceptionFlags = 0;
    uint32_t x_i = cos_sub_norm2[i];
    float x_f2 = operators ::ui32_to_float(x_i);
    uint32_t cos_rlt2 = operators ::sfu_sincos(x_i, 1);
    float y_f2 = operators ::cos2pi(x_f2);
    uint32_t y_c2 = operators::float_to_ui32(y_f2);
    cout << "in:" << x_f2 << "<-->cmath cos(2Πx):" << y_f2 << "<->0x" << hex
         << y_c2 << endl;
    cout << hex << "in: 0x" << x_i << ", result:0x" << cos_rlt2
         << "<-->(float)in: " << x_f2
         << ", result:" << operators ::ui32_to_float(cos_rlt2)
         << " <error:" << dec << abs((long)cos_rlt2 - y_c2) << ">" << endl;
    cout << "exception flag:" << dec << (int)cm_exceptionFlags << endl << endl;
  }
  cout << endl;
}

void test_booth() {
  cout << "\n------TEST RADIX4 BOOTH MULTIPLY------" << dec << endl;
  uint8_t u8 = 50; // 0011 0010
  int8_t i8 = -10; // 1111 0110
  uint8_t u4 = 4;  // 0100
  int8_t i4 = -3;  // 1101
  // uint8*int4
  int16_t result1 = operators::radix4_booth_mult(u8, i4, 8, 4, 14);
  cout << "result=" << u8 * i4 << ", booth result=" << result1 << endl;
  // uint8*int8
  int16_t result2 = operators::radix4_booth_mult(u8, i8, 8, 8, 14);
  cout << "result=" << u8 * i8 << ", booth result=" << result2 << endl;
  // int8*int4
  int16_t result3 = operators::radix4_booth_mult(i8, i4, 8, 4, 14);
  cout << "result=" << i8 * i4 << ", booth result=" << result3 << endl;
  // int8*uint4
  int16_t result4 = operators::radix4_booth_mult(i8, u4, 8, 4, 14);
  cout << "result=" << i8 * u4 << ", booth result=" << result4 << endl;
  // uint4*int8
  int16_t result5 = operators::radix4_booth_mult(u4, i8, 4, 8, 14);
  cout << "result=" << u4 * i8 << ", booth result=" << result5 << endl;
  // uint4*uint8
  int16_t result6 = operators::radix4_booth_mult(u4, u8, 4, 8, 14);
  cout << "result=" << u4 * u8 << ", booth result=" << result6 << endl;
  // int4*int8
  int16_t result7 = operators::radix4_booth_mult(i4, i8, 4, 8, 14);
  cout << "result=" << i4 * i8 << ", booth result=" << result7 << endl;
  // int4*uint8
  int16_t result8 = operators::radix4_booth_mult(i4, u8, 4, 8, 14);
  cout << "result=" << i4 * u8 << ", booth result=" << result8 << endl;
  // int4*uint4
  int16_t result9 = operators::radix4_booth_mult(i4, u4, 4, 4, 14);
  cout << "result=" << i4 * u4 << ", booth result=" << result9 << endl;

  uint8_t maxU8 = 255; //[0,255] 0 1111 1111
  uint8_t maxU4 = 15;  //[0,15]  0 1111
  int16_t result10 = operators::radix4_booth_mult(maxU8, maxU4, 9, 5, 14);
  cout << "result=" << maxU8 * maxU4 << ", booth result=" << result10 << endl;
  int16_t minN8 = -256; // 1 0000 0000
  int16_t result11 = operators::radix4_booth_mult(minN8, maxU4, 9, 5, 14);
  cout << "result=" << minN8 * maxU4 << ", booth result=" << result11 << endl;

  cout << endl;
}

bool test_conv() {
  // rnd mode
  softfloat_roundingMode = softfloat_round_near_even;
  cout << "rounding mode:" << (int)softfloat_roundingMode << endl;
  // src: 7*7*3, kernel: 2*3*3*3
  float src_arr[147] = {
      0,   1.0, 1.0, 0,   2.0, 2.0, 2.0, 2.0, 2.0,  1.0, 1.0,  0,    0,   2.0,
      0,   0,   1.0, 1.0, 0,   0,   1.0, 2.0, 0,    0,   2.0,  1.0,  0,   2.0,
      2.0, 0,   0,   0,   0,   2.0, 1.0, 2.0, 1.0,  2.0, 1.0,  1.0,  0,   0,
      0,   0,   1.0, 2.0, 1.0, 1.0, 0,   2.0, 2.0,  1.0, 2.0,  0,    0,   1.0,
      0,   0,   1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0,  0,   2.0,  0,    0,   1.0,
      2.0, 1.0, 1.0, 0,   2.0, 0,   1.0, 1.0, 0,    2.0, 2.0,  2.0,  2.0, 2.0,
      1.0, 1.0, 0,   0,   2.0, 0,   0,   1.0, 1.0,  0,   0,    1.0,  2.0, 0,
      0,   2.0, 1.0, 0,   2.0, 2.0, 0,   0,   0,    0,   2.0,  1.0,  2.0, 1.0,
      2.0, 1.0, 1.0, 0,   0,   0,   0,   1.0, 2.0,  1.0, 1.0,  0,    2.0, 2.0,
      1.0, 2.0, 0,   0,   1.0, 0,   2.0, 3.0, -1.0, 0,   -1.0, -2.0, 3.0, 1.0,
      2.0, 0,   0,   1.0, 0,   2.0};
  float k_arr[108] = {
      -1.0, 1.0,  0,  0,    1.0,  0,    0,    1,    1,  -1.0, -1.0, 0,
      0,    0,    0,  0,    -1,   0,    0,    0,    -1, 0,    1.0,  0,
      0,    -1,   -1, 1.0,  0,    1.0,  0,    -1.0, 0,  0,    -1,   1,
      1.0,  -1.0, 0,  1.0,  0,    -1.0, 0,    -1,   0,  0,    0,    -1,
      0,    1.0,  0,  0,    1,    1,    -1.0, 1.0,  0,  0,    1.0,  0,
      0,    1,    1,  -1.0, -1.0, 0,    0,    0,    0,  0,    -1,   0,
      0,    0,    -1, 0,    1.0,  0,    0,    -1,   -1, 1.0,  0,    1.0,
      0,    -1.0, 0,  0,    -1,   1,    1.0,  -1.0, 0,  1.0,  0,    -1.0,
      0,    -1,   0,  0,    0,    -1,   0,    1.0,  0,  0,    1,    1};
  uint16_t u16_src_arr[147], u16_k_arr[108];
  for (int i = 0; i < 147; i++) {
    u16_src_arr[i] = operators::float_to_ui16(src_arr[i]);
  }
  for (int i = 0; i < 108; i++) {
    u16_k_arr[i] = operators::float_to_ui16(k_arr[i]);
  }

  cout << "*********Test no pad, stride=1, dilation=1********" << endl;
  operators::MATRIX_4D<uint64_t> u32_out;
  operators::MATRIX_2D<uint64_t> u32_out_2D;
  bool flag = false;
  int passed = 0;
  cout << "FP16*FP16...." << endl;
  operators::conv3D(u16_src_arr, u16_k_arr, u32_out, FP16, FP16, 1, 3, 7, 7, 2,
                    3, 3, 3);
  operators::im2col(u16_src_arr, u16_k_arr, u32_out_2D, FP16, FP16, 1, 3, 7, 7,
                    2, 3, 3, 3);
  flag = operators::im2col_conv3D_cmp(u32_out_2D, u32_out, 2, 5, 5);
  cout << "im2col and conv3D is the same?:" << flag << endl;
  if (flag)
    passed++;
  // other data type
  cout << "BF16*BF16...." << endl;
  operators::conv3D(u16_src_arr, u16_k_arr, u32_out, BF16, BF16, 1, 3, 7, 7, 2,
                    3, 3, 3);
  operators::im2col(u16_src_arr, u16_k_arr, u32_out_2D, BF16, BF16, 1, 3, 7, 7,
                    2, 3, 3, 3);
  flag = operators::im2col_conv3D_cmp(u32_out_2D, u32_out, 2, 5, 5);
  cout << "im2col and conv3D is the same?:" << flag << endl;
  if (flag)
    passed++;
  cout << "UINT16*SINT8...." << endl;
  for (int i = 0; i < 108; i++) {
    u16_k_arr[i] = (operators::float_to_ui16(k_arr[i])) && 0xFF;
  }
  operators::conv3D(u16_src_arr, u16_k_arr, u32_out, UINT16, SINT8, 1, 3, 7, 7,
                    2, 3, 3, 3);
  operators::im2col(u16_src_arr, u16_k_arr, u32_out_2D, UINT16, SINT8, 1, 3, 7,
                    7, 2, 3, 3, 3);
  flag = operators::im2col_conv3D_cmp(u32_out_2D, u32_out, 2, 5, 5);
  cout << "im2col and conv3D is the same?:" << flag << endl;
  if (flag)
    passed++;
  cout << "\n*********Test pad(1,2,2,1), stride(2,2), dilation(1,1)********"
       << endl;
  // pad(1,2,1,1), stride=2,dilation=1
  operators::conv3D(u16_src_arr, u16_k_arr, u32_out, FP16, FP16, 1, 3, 7, 7, 2,
                    3, 3, 3, 0, 1, 1, 1, 1, 2, 2, 1, 1);
  operators::im2col(u16_src_arr, u16_k_arr, u32_out_2D, FP16, FP16, 1, 3, 7, 7,
                    2, 3, 3, 3, 0, 1, 1, 1, 1, 2, 2, 1, 1);
  flag = operators::im2col_conv3D_cmp(u32_out_2D, u32_out, 2, 5, 5);
  cout << "im2col and conv3D is the same?:" << flag << endl;
  if (flag)
    passed++;

  return (passed == 4);
}

void test_sfu(uint8_t opcode) {
  cm_exceptionFlags = 0;
  switch (opcode) {
  case 0:
    test_sqrt();
    break;
  case 1:
    test_rcpsqrt();
    break;
  case 2:
    test_rcp();
    break;
  case 3:
    test_exp2();
    break;
  case 4:
    test_expE();
    break;
  case 5:
    test_tanh();
    break;
  case 6:
    test_sigmoid();
    break;
  case 7:
    // test_log2();
    break;
  case 8:
    test_sinx();
    break;
  case 9:
    test_cosx();
    break;
  default:
    cerr << "unkown opcode" << endl;
    break;
  }
}

/*========================================
test vae function
input:
  functionNumber:
    0 is rmsnorm test;
    1 is softmax_online;
    2 is laynorm;
    3 is elementwise;
    4 is mask;
    5 is quantization;
    6 is rope;
    7 is reduce;
    8 is softmax fa1;
    9 is softmax fa2;
    10 is softmax fa3;
    11 is softmax online simulator test;
============================================*/
void test_vae() {

  cout << "*********Test VAE FUNCTION********" << endl;
  // softfloat_roundingMode = softfloat_round_near_even;
  // cout << "rounding mode:" << (int)softfloat_roundingMode << endl;
  uint32_t row, col, functionNumber, testOld;
  DataType i_type, o_type;
  functionNumber = 1;
  testOld = 1;
  int64_t seed = 5;
  if (testOld == 1) {
    row = 2;
    col = 128;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = FP16;
    o_type = FP16;
    fun_test_vae(row, col, i_type, o_type, functionNumber);
  }
#if 0
  if (functionNumber == 1) { // softmax online
    row = 40;
    col = 1183;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = FP16;
    o_type = FP16;
    uint32_t layer = 1;
    fun_test_vae_softmaxOnline(row, col, i_type, o_type, functionNumber, seed,
                               scaleFlag, maskFlag, layer);
  }
  if (functionNumber == 2) { // softmax online
    row = 160;
    col = 2112;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = BF16;
    o_type = BF16;
    uint32_t layer = 1;
    fun_test_reduce_add32_160x2112(row, col, i_type, o_type, functionNumber,
                                   seed, scaleFlag, maskFlag);
  }
  if (functionNumber == 11) { // softmax online ，fimulator
    row = 128 * 16;
    col = 128;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = BF16;
    o_type = BF16;
    fun_test_vae_softmaxOnline_simulator(
        row, col, i_type, o_type, functionNumber, seed, scaleFlag, maskFlag);
  }
  if (functionNumber == 12) { // softmax online ，fimulator
    row = 17;
    col = 17;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = BF16;
    o_type = BF16;
    fun_test_vae_softmaxOnline_17x17(row, col, i_type, o_type, functionNumber,
                                     seed, scaleFlag, maskFlag);
  }
  if (functionNumber == 13) { // reduce_top2
    row = 1;
    col = 2888;
    i_type = FP16;
    o_type = FP16;
    seed = 20;
    fun_test_vae_reduce_top2(row, col, i_type, o_type, functionNumber, seed);
  }
  if (functionNumber == 15) { // laynorm
    fun_test_vae_laynorm(row, col, i_type, o_type, functionNumber, seed);
  }
  if (functionNumber == 14) { // softmax online ，fimulator
    row = 128;
    col = 256;
    uint32_t scaleFlag = 1;
    uint32_t maskFlag = 1;
    i_type = BF16;
    o_type = BF16;
    fun_test_vae_reduce_mean(row, col, i_type, o_type, functionNumber, seed,
                             scaleFlag, maskFlag);
  }
#endif
#if 0
uint16_t ina = 0xbccc, inb = 0x3fad, weigha = 0xb83f, weighb = 0x3ac8;
uint32_t mul0 = fp16mul_resfp32(ina, weighb);
uint32_t mul1 = fp16mul_resfp32(inb, weigha);
uint24_t mul0_f24 = fp32_to_fp24(mul0);
uint24_t mul1_f24 = fp32_to_fp24(mul1);
uint24_t sub = fp24sub(mul0_f24, mul1_f24);
uint32_t sub_fp32 = fp32sub(mul0, mul1);
uint32_t sub_f24_f32 = fp32sub(mul0_f24 << 8, mul1_f24 << 8);
printUint24(&mul0, 1);
printUint24(&mul0_f24, 1);
printf("===\n");
printUint24(&mul1, 1);
printUint24(&mul1_f24, 1);
printf("===\n");
printUint24(&sub_fp32, 1);
printUint24(&sub, 1);
printUint24(&sub_f24_f32, 1);
uint32_t data = fp16_to_fp32(0xBC11);
//printUint24(&data, 1);
uint32_t data1 = fp16_to_fp32(0xBC13);
//printUint24(&data1, 1);
#endif
} // test_vae end

void test_conv_subcmd() {
#define CONV_PRINT_ENABLE 1
  // create example
  uint64_t params0 = 0;

  // 设置各个字段的值
  params0 |= (1 << 0);    // op_mode = 1 (conv)
  params0 |= (0 << 1);    // subcmd_bc_id = 1
  params0 |= (16 << 2);   // o_tile_w = 16
  params0 |= (8 << 7);    // o_tile_h = 8
  params0 |= (128 << 11); // o_tile_c = 128
  params0 |= (1 << 19);   // o_tile_n = 1

  std::cout << " params0 = " << std::hex << params0 << std::endl;
  uint16_t common_k = 256;
  uint16_t tile_c = 128;
  uint16_t tile_h = 8;
  uint16_t tile_w = 16;
  uint16_t m_row = tile_h * tile_w;
  uint16_t n_col = tile_c;
  std::cout << " common_k = " << int(common_k) << std::endl;
  std::cout << " tile_c =   " << int(tile_c) << std::endl;
  std::cout << " tile_h =   " << int(tile_h) << std::endl;
  std::cout << " tile_w =   " << int(tile_w) << std::endl;

  uint16_t **mat_a = new uint16_t *[m_row]; // o_tile_h * o_tile_w
  for (int i = 0; i < m_row; i++) {
    mat_a[i] = new uint16_t[common_k];
    for (int j = 0; j < common_k; j++) {
      mat_a[i][j] = static_cast<uint16_t>(i + j);
    }
  }
  std::cout << "Matrix A allocated OK" << std::endl;

  uint16_t **mat_b = new uint16_t *[common_k];
  for (int i = 0; i < common_k; i++) {
    mat_b[i] = new uint16_t[n_col]; // o_tile_c
    for (int j = 0; j < n_col; j++) {
      mat_b[i][j] = static_cast<uint16_t>(i * j);
    }
  }
  std::cout << "Matrix B allocated OK" << std::endl;

  uint64_t **mat_reshape = new uint64_t *[m_row]; // o_tile_h * o_tile_w
  for (int i = 0; i < m_row; i++) {
    mat_reshape[i] = new uint64_t[n_col]; // o_tile_c
    for (int j = 0; j < n_col; j++) {
      mat_reshape[i][j] = 0;
    }
  }
  std::cout << "Matrix ACallocated OK" << std::endl;

  /*=================================print A B
   * ====================================*/
  uint16_t mat_a_rows = tile_h * tile_w;
  uint16_t mat_a_cols = common_k;
  uint16_t mat_b_rows = common_k;
  uint16_t mat_b_cols = tile_c;
  operators::print_matrix_partial(mat_a, "A", mat_a_rows, mat_a_cols, 3, 4);
  operators::print_matrix_partial(mat_b, "B", mat_b_rows, mat_b_cols, 3, 4);

  DataType datatype = FP16; // 示例数据类型
  // operators::MATRIX_4D<uint64_t> result_4d;
  operators::conv_subcmd(params0, mat_a_rows, mat_b_cols, common_k, mat_a,
                         mat_b, mat_reshape, datatype);

  // operators::matrix_opcode *matrix_opcode =
  // operators::matrix_opcode::generate(params0);
  // operators::conv_subcmd(matrix_opcode, mat_a_rows, mat_b_cols, common_k,
  // mat_a,
  //                        mat_b, mat_reshape, datatype, result_4d);

#if CONV_PRINT_ENABLE
  /*=================================print 2D Matrix C
   * ====================================*/
  std::cout << "\n=== Output Matrix C (after computation) ===" << std::endl;
  operators::print_matrix_2d_detail(mat_reshape, "C (after)", mat_a_rows,
                                    mat_b_cols, 16, 8);

  /*=================================print 4D
   * ====================================*/
  // std::cout << "\n--- 4D Matrix - Different Channels ---" << std::endl;
  // operators::print_matrix_4d_detail(result_4d, "First 2 Channels", 1, 4, 8,
  // 8);

  /*=================================validation
   * ====================================*/
  // operators::compare_matrices(mat_reshape, result_4d, 8, 16, 128);

  std::cout << "Convolution completed successfully!" << std::endl;

  // 可以使用输出的 MATRIX_4D 进行后续处理
  // std::cout << "\n=== Using the Output MATRIX_4D ===" << std::endl;
  // std::cout << "Output MATRIX_4D dimensions: batch=" << result_4d.bz
  //           << ", channels=" << result_4d.ch
  //           << ", height=" << result_4d.nr
  //           << ", width=" << result_4d.nc << std::endl;

  // 示例：访问特定元素
  // if (result_4d.bz > 0 && result_4d.ch > 0 && result_4d.nr > 0 &&
  // result_4d.nc > 0) {
  //     std::cout << "Example element [0][0][0][0] = " <<
  //     result_4d.data[0][0][0][0] << std::endl;
  // }
#else
#endif

  // 清理内存
  std::cout << "cleaning up mem" << std::endl;
  for (int i = 0; i < 8 * 16; i++) {
    delete[] mat_a[i];
    delete[] mat_reshape[i];
  }
  for (int i = 0; i < common_k; i++) {
    delete[] mat_b[i];
  }
  delete[] mat_a;
  delete[] mat_b;
  delete[] mat_reshape;
}

int main(int argc, char *argv[]) {
  /*生成数据*/
  //  get_input_data();
  //  int flagGamma = 1;
  //  uint64_t ulp = 0;
  //  test_rmsnorm_compare_txt(flagGamma, ulp);
  // #include <unistd.h>
  //   char buffer[1024] = {0};
  //   if (getcwd(buffer, sizeof(buffer)) != nullptr)
  //     cout << "Current path:" << buffer << endl;

  softfloat_roundingMode = softfloat_round_near_even;

  auto &tests = getTestCases();
  int case_num =
      (argc <= 1) ? tests.size() : (argc - 1); // argc<=1, run all case
  int passed = 0;
  TestStats stats;
  stats.reset();

  cout << "Running  " << case_num << " test cases .....\n" << endl;
  for (int i = 0; i < case_num; i++) {
    int op = (argc <= 1) ? i : stoi(argv[i + 1]);
    try {
      tests.at(op).func();
      cout << "✅✅ " << tests.at(op).name << " PASS..." << endl << endl;
      passed++;
      stats.passed_name.push_back(tests.at(op).name);
    } catch (...) {
      cout << "❌❌ " << tests.at(op).name << " FAIL..." << endl << endl;
      stats.faild_name.push_back(tests.at(op).name);
    }
  }

  for (int i = 0; i < case_num; i++) {
    int op = (argc <= 1) ? i : stoi(argv[i + 1]);
    cout << dec << "|    ID = " << op << ", " << tests.at(op).name << endl;
  }

  cout << "********************************************************************"
          "*******************"
       << endl;
  cout << "|    Summary: " << passed << "/" << case_num << " passed" << endl
       << "| " << endl;
  cout << "|    " << GREEN << "PASSED CASE: " << endl << "|    ";
  for (int i = 0; i < stats.passed_name.size(); i++) {
    cout << stats.passed_name.at(i) << " ";
    if ((i + 1) % 10 == 0)
      cout << endl << "|    ";
  }
  cout << RESET << endl << "|    " << endl;
  cout << "|    " << RED << "FAILED CASE: " << endl << "|    ";
  for (int i = 0; i < stats.faild_name.size(); i++) {
    cout << stats.faild_name.at(i) << " ";
    if ((i + 1) % 10 == 0)
      cout << endl << "|    ";
  }
  cout << RESET << endl << "|    " << endl;
  cout << "********************************************************************"
          "*******************"
       << endl;

  return 0;
}