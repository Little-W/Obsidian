#ifndef _TB_FP32TOFP8_H
#define _TB_FP32TOFP8_H
#include "dop_ops.h"
#include "internals.h"
// #include "nvfp4_e2m1.h"
#include "platform.h"
#include "softfloat.h"
#include "specialize.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "fp8_conversion.h"

typedef struct {
  uint8_t v;
} float8_1_t; // 1-4-3
typedef struct {
  uint8_t v;
} float8_2_t; // 1-5-2

union ui8_f8_1 {
  uint8_t ui;
  float8_1_t f;
};
// fp8
void print_binary(uint32_t num, int bits);
void print_fp32(float32_t num);
void print_f8_1(float8_1_t num);
void test_conversion(float32_t fp32_val, const char *test_name);
void tb_f32tof8_1();

#endif