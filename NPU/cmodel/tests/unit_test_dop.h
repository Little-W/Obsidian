#ifndef UNIT_TEST_DOP_H
#define UNIT_TEST_DOP_H

#include "cmodel.h"
#include "dop_ops.h"
#include "dop_utils.h"
#include "matrix_struct.h"
#include "sm_data_struct.h"
#include "softfloat.h"
#include <random>
#include <stdint.h>
#include <stdio.h>
#include <string>

void test_dop_unit(DataType data_type, size_t arraysize) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint16_t> dist;
  uint16_t *fp16_array1 = new uint16_t[arraysize];
  uint16_t *fp16_array2 = new uint16_t[arraysize];
  uint16_t ascale[] = {0x1, 0x1, 0x1, 0x1};
  uint16_t bscale[] = {0x1, 0x1, 0x1, 0x1};
  uint32_t resultsym;
  for (int counter = 0; counter < 99999; counter++) {
    for (int i = 0; i < arraysize; i++) {
      fp16_array1[i] = dist(gen);
      fp16_array2[i] = dist(gen);
    }
    for (int i = 0; i < 4; i++) {
      ascale[i] = dist(gen);
      bscale[i] = dist(gen);
    }
    uint32_t real_ans =
        operators::dot_product_bf16(fp16_array1, fp16_array2, arraysize).v;
    switch (data_type) {
    case FP16:
      real_ans =
          operators::dot_product_fp16(fp16_array1, fp16_array2, arraysize).v;
      break;
    case BF16:
      real_ans =
          operators::dot_product_bf16(fp16_array1, fp16_array2, arraysize).v;
      break;
    case BF16SINT4:
      for (int i = 0; i < arraysize; i++) {
        fp16_array2[i] &= 0b1111;
      }
      real_ans =
          operators::dot_product_bf16int4(fp16_array1, fp16_array2, arraysize)
              .v;
      break;
    case BF16UINT4:
      for (int i = 0; i < arraysize; i++) {
        fp16_array2[i] &= 0b1111;
      }
      real_ans =
          operators::dot_product_bf16uint4(fp16_array1, fp16_array2, arraysize)
              .v;
      break;
    case FP8E4:
    case MXFP8MXFP8:
      for (int i = 0; i < arraysize; i++) {
        fp16_array1[i] &= 0xff;
        fp16_array2[i] &= 0xff;
      }
      real_ans =
          operators::dot_product_fp8e4(fp16_array1, fp16_array2, arraysize).v;
      break;
    case NVFP4E2:
      for (int i = 0; i < arraysize; i++) {
        fp16_array1[i] &= 0xf;
        fp16_array2[i] &= 0xf;
      }
      for (int i = 0; i < 4; i++) {
        ascale[i] = dist(gen);
        bscale[i] = dist(gen);
        ascale[i] &= 0xff;
        bscale[i] &= 0xff;
      }
      real_ans = operators::dot_product_nvfp4(fp16_array1, fp16_array2, ascale,
                                              bscale, arraysize)
                     .v;
    case MXFP4MXFP4:
      for (int i = 0; i < arraysize; i++) {
        fp16_array1[i] &= 0xf;
        fp16_array2[i] &= 0xf;
      }
      for (int i = 0; i < 4; i++) {
        ascale[i] = dist(gen);
        bscale[i] = dist(gen);
        ascale[i] &= 0xff;
        bscale[i] &= 0xff;
      }
      real_ans = operators::dot_product_mxfp4(fp16_array1, fp16_array2, ascale,
                                              bscale, arraysize)
                     .v;
      resultsym = operators::dop_product(fp16_array1, fp16_array2, arraysize,
                                         data_type, ascale, bscale);
      break;
    case SINT16SINT4:
      ascale[0] &= 7;
      for (int i = 0; i < arraysize; i++) {
        fp16_array2[i] &= 0xf;
      }
      for (int i = 0; i < 4; i++) {
        bscale[i] = dist(gen);
      }
      real_ans = operators::dot_product_int16int4_k(
                     fp16_array1, fp16_array2, ascale[0], bscale, arraysize) &
                 0xfffffff;
      break;
    }

    resultsym = operators::dop_product(fp16_array1, fp16_array2, arraysize,
                                       data_type, ascale, bscale);

    if (4 >= resultsym - real_ans || 4 >= real_ans - resultsym)
      continue;
    printf("fp16_array1:");
    for (int i = 0; i < arraysize; i++) {
      printf(" 0x%08x,", fp16_array1[i]);
    }
    printf("fp16_array2:");
    for (int i = 0; i < arraysize; i++) {
      printf(" 0x%08x,", fp16_array2[i]);
    }
    printf("\nascale:");
    for (int i = 0; i < 4; i++) {
      printf(" 0x%08x,", ascale[i]);
    }
    printf("\nbscale:");
    for (int i = 0; i < 4; i++) {
      printf(" 0x%08x,", bscale[i]);
    }
    printf("\n");
    operators::print_binary_uint32(resultsym);
    operators::print_binary_uint32(real_ans);
    printf("Final fp32 resultsym: %f\n", *(float *)(&resultsym));
    printf("Final fp32 result: %f\n", *(float *)(&real_ans));
    printf("resultsym in hex: 0x%08x\n", resultsym);
    printf("Result in hex: 0x%08x\n", real_ans);
  }

  delete[] fp16_array1;
  delete[] fp16_array2;
}

void test_dop_unit(DataType data_type, size_t arraysize, uint16_t *fp16_array1,
                   uint16_t *fp16_array2) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint16_t> dist;
  // uint32_t ascale = 0x7f;
  // uint16_t bscale = 0x7f;
  // uint32_t ascale = 0x29;
  // uint16_t bscale = 0x29;
  // uint32_t ascale = 0x3c;
  // uint16_t bscale = 0x3c;
  uint16_t ascale[] = {0x4d, 0xe4};
  uint16_t bscale[] = {0xdc, 0x61};
  ascale[0] = 15;
  bscale[0] = 0X0;

  // uint64_t result = dop_product(fp16_array1, fp16_array2, arraysize,
  // data_type);
  uint64_t result = 0;
  softfloat_exceptionFlags = 0;
  uint64_t resultsym = operators::dop_product(
      fp16_array1, fp16_array2, arraysize, data_type, ascale, bscale);
  printf("softfloat_exceptionFlags: %d\n", softfloat_exceptionFlags);
  uint32_t real_ans =
      operators::dot_product_bf16(fp16_array1, fp16_array2, arraysize).v;
  switch (data_type) {
  case FP16:
    real_ans =
        operators::dot_product_fp16(fp16_array1, fp16_array2, arraysize).v;
    break;
  case BF16:
    real_ans =
        operators::dot_product_bf16(fp16_array1, fp16_array2, arraysize).v;
    break;
  case BF16UINT4:
    real_ans =
        operators::dot_product_bf16uint4(fp16_array1, fp16_array2, arraysize).v;
    break;
  case BF16SINT4:
    real_ans =
        operators::dot_product_bf16int4(fp16_array1, fp16_array2, arraysize).v;
    break;
  case FP8E4:
    real_ans =
        operators::dot_product_fp8e4(fp16_array1, fp16_array2, arraysize).v;
    break;
  case BF16MXFP4:
    real_ans =
        operators::dot_product_bf16mxfp4(fp16_array1, fp16_array2, arraysize).v;
    break;
  case MXFP8MXFP8:
    real_ans =
        operators::dot_product_fp8e4(fp16_array1, fp16_array2, arraysize).v;
    break;
  case NVFP4E2:
    real_ans = operators::dot_product_nvfp4(fp16_array1, fp16_array2, ascale,
                                            bscale, arraysize)
                   .v;
    break;
  case MXFP4MXFP4:
    real_ans = operators::dot_product_mxfp4(fp16_array1, fp16_array2, ascale,
                                            bscale, arraysize)
                   .v;
    break;
  case SINT16SINT4:
    real_ans = operators::dot_product_int16int4(
        fp16_array1, fp16_array2, ascale[0], bscale[0], arraysize);
    break;
  }

#if 0
  printf("fp16_array1:");
  for (int i = 0; i < arraysize; i++) {
    printf(" 0x%08x,", fp16_array1[i]);
  }
  printf("fp16_array2:");
  for (int i = 0; i < arraysize; i++) {
    printf(" 0x%08x,", fp16_array2[i]);
  }
#endif
  printf("\n");

  operators::print_binary_uint32(resultsym);
  operators::print_binary_uint32(real_ans);
  printf("Final fp32 sym_quant: %f\n", *(float *)(&resultsym));
  printf("Final fp32 result: %f\n", *(float *)(&real_ans));
  printf("sym_quant in hex: 0x%lx\n", resultsym);
  printf("Result in hex: 0x%lx\n", real_ans);
}

#endif