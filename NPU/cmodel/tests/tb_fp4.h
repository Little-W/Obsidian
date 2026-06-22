#ifndef _TB_FP4_H
#define _TB_FP4_H
#include "dop_ops.h"
#include "internals.h"
#include "nvfp4_e2m1.h"
#include "platform.h"
#include "softfloat.h"
#include "specialize.h"

// 测试用例结构 - 仅支持十六进制输入
typedef struct {
  uint32_t hex_input; // 十六进制输入
  uint8_t expected_code;
  const char *description;
  int expect_inexact;
  int expect_overflow;
} test_case_t;

float uint32_to_float(uint32_t bits);
float32_t uint32_to_float32(uint32_t bits);
float nvfp4_code_to_float(uint8_t code);
void print_nvfp4_info(uint8_t code);

void run_test_case_hex(test_case_t test_case, int *passed, int *total);
void test_hex_direct_compare();
void tb_fp4();

#endif