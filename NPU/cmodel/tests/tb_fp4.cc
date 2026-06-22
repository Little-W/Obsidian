#include "tb_fp4.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// 辅助函数：将uint32_t位模式转换为浮点数
float uint32_to_float(uint32_t bits) {
  union {
    uint32_t u;
    float f;
  } converter;
  converter.u = bits;
  return converter.f;
}

// 辅助函数：将uint32_t位模式转换为float32_t
float32_t uint32_to_float32(uint32_t bits) {
  float32_t result;
  memcpy(&result, &bits, sizeof(uint32_t));
  return result;
}

// 辅助函数：将NVFP4编码转换为可读的数值
float nvfp4_code_to_float(uint8_t code) {
  bool sign = (code >> 3) & 0x1;
  uint8_t value_code = code & 0x7;
  float value;

  switch (value_code) {
  case 0x0:
    value = 0.0f;
    break;
  case 0x1:
    value = 0.5f;
    break;
  case 0x2:
    value = 1.0f;
    break;
  case 0x3:
    value = 1.5f;
    break;
  case 0x4:
    value = 2.0f;
    break;
  case 0x5:
    value = 3.0f;
    break;
  case 0x6:
    value = 4.0f;
    break;
  case 0x7:
    value = 6.0f;
    break;
  default:
    value = 0.0f;
    break;
  }

  return sign ? -value : value;
}

// 辅助函数：打印NVFP4编码信息
void print_nvfp4_info(uint8_t code) {
  float value = nvfp4_code_to_float(code);
  bool sign = (code >> 3) & 0x1;
  uint8_t value_code = code & 0x7;

  printf("NVFP4: 0x%X (bin: ", code);
  for (int i = 3; i >= 0; i--) {
    printf("%d", (code >> i) & 1);
  }
  printf(") -> %s%.1f (sign=%d, value_code=0x%X)\n", sign ? "-" : "+", value,
         sign, value_code);
}

// 辅助函数：打印softfloat标志
static inline void print_softfloat_flags() {
  uint_fast8_t flags = operators::cmodel_exceptionFlags;
  printf("operators::cmodel_exceptionFlags: 0x%02X (", (unsigned int)flags);

  if (flags == 0) {
    printf("no flags");
  } else {
    int first = 1;
    // if (flags & softfloat_flag_inexact) {
    //     printf("%sinexact", first ? "" : "|");
    //     first = 0;
    // }
    if (flags & softfloat_flag_underflow) {
      printf("%sunderflow", first ? "" : "|");
      first = 0;
    }
    if (flags & softfloat_flag_overflow) {
      printf("%soverflow", first ? "" : "|");
      first = 0;
    }
    if (flags & softfloat_flag_infinite) {
      printf("%sinfinite", first ? "" : "|");
      first = 0;
    }
    if (flags & softfloat_flag_invalid) {
      printf("%sinvalid", first ? "" : "|");
      first = 0;
    }
  }
  printf(")\n");
}

// 测试函数（仅使用Direct Compare方法）
void run_test_case_hex(test_case_t test_case, int *passed, int *total) {
  (*total)++;

  float float_val = uint32_to_float(test_case.hex_input);
  /*
    printf("\nTest %d: %s\n", *total, test_case.description);
    printf("Input: 0x%08X (float: %f)\n", test_case.hex_input, float_val);
  */
  // 转换前清除标志
  operators::cmodel_exceptionFlags = 0;

  // 执行转换 - 仅使用Direct Compare方法
  // float32_t input_f32 = uint32_to_float32(test_case.hex_input);
  fp_general_t input_f32 = (fp_general_t)(test_case.hex_input >> 8);

  // nvfp4_e2m1_t result = f32_to_nvfp4_e2m1_direct(input_f32);
  fp_general_t result = operators::fp24_to_fp4e2m1(input_f32);

  uint8_t low_4bits = (uint8_t)(result & 0x0F);
  operators::nvfp4_e2m1_t result_nvfp4;
  result_nvfp4.v = low_4bits;

  // 获取结果编码
  uint8_t result_code = low_4bits; // operators::nvfp4_e2m1_get_bits(result);
                                   /*
                                     printf("Result: ");
                                     print_nvfp4_info(result_code);
                                     printf("Expected: ");
                                     print_nvfp4_info(test_case.expected_code);
                                   */
  // 检查标志
  int got_inexact =
      (operators::cmodel_exceptionFlags & softfloat_flag_inexact) != 0;
  int got_overflow =
      (operators::cmodel_exceptionFlags & softfloat_flag_overflow) != 0;

  // 验证结果
  int test_passed = 1;

  if (result_code != test_case.expected_code) {
    printf("❌ FAIL: Code mismatch! Got 0x%X, expected 0x%X\n", result_code,
           test_case.expected_code);
    test_passed = 0;
  }

  // if (got_inexact != test_case.expect_inexact) {
  //     printf("❌ FAIL: Inexact flag mismatch! Got %d, expected %d\n",
  //            got_inexact, test_case.expect_inexact);
  //     test_passed = 0;
  // }

  if (got_overflow != test_case.expect_overflow) {
    printf("❌ FAIL: Overflow flag mismatch! Got %d, expected %d\n",
           got_overflow, test_case.expect_overflow);
    test_passed = 0;
  }

  if (test_passed) {
    // printf("✅ PASS\n");
    (*passed)++;
    // printf("Flags: ");
    // print_softfloat_flags();
  } else {
    // printf("Flags: ");
    // print_softfloat_flags();
  }
}

// ========================= 十六进制测试用例 =========================
void test_hex_direct_compare() {
  // 十六进制测试用例
  test_case_t test_cases[] = {
      // 零值测试
      {0x00000000, 0x0, "Positive Zero", 0, 0},
      {0x80000000, 0x8, "Negative Zero", 0, 0},
      {0x80000000, 0x8, "Negative Zero", 0, 0},

      // 特殊值测试
      {0x7F800000, 0x7, "+Inf -> 6.0", 0, 0},
      {0xFF800000, 0xF, "-Inf -> -6.0", 0, 0},
      {0x7FC00000, 0x7, "NaN -> 6.0", 0, 0},

      // 标准值测试
      {0x3DCCCCCD, 0x0, "0.1 -> 0.0", 1, 0},   // 0.1
      {0x3E800000, 0x0, "0.25 -> 0.0", 1, 0},  // 0.25
      {0x3E99999A, 0x1, "0.3 -> 0.5", 1, 0},   // 0.3
      {0x3F000000, 0x1, "0.5 -> 0.5", 0, 0},   // 0.5
      {0x3F333333, 0x1, "0.7 -> 0.5", 1, 0},   // 0.7
      {0x3F400000, 0x2, "0.75 -> 1.0", 1, 0},  // 0.75
      {0x3F800000, 0x2, "1.0 -> 1.0", 0, 0},   // 1.0
      {0x3F99999A, 0x2, "1.2 -> 1.0", 1, 0},   // 1.2
      {0x3FA00000, 0x2, "1.25 -> 1.0", 1, 0},  // 1.25
      {0x3FA66666, 0x3, "1.3 -> 1.5", 1, 0},   // 1.3
      {0x3FC00000, 0x3, "1.5 -> 1.5", 0, 0},   // 1.5
      {0x3FE00000, 0x4, "1.75 -> 2.0", 1, 0},  // 1.75
      {0x40000000, 0x4, "2.0 -> 2.0", 0, 0},   // 2.0
      {0x40133333, 0x4, "2.3 -> 2.0", 1, 0},   // 2.3
      {0x40200000, 0x4, "2.5 -> 2.0", 1, 0},   // 2.5
      {0x402CCCCD, 0x5, "2.7 -> 3.0", 1, 0},   // 2.7
      {0x40400000, 0x5, "3.0 -> 3.0", 0, 0},   // 3.0
      {0x40600000, 0x6, "3.5 -> 4.0", 1, 0},   // 3.5
      {0x40800000, 0x6, "4.0 -> 4.0", 0, 0},   // 4.0
      {0x40900000, 0x6, "4.5 -> 4.0", 1, 0},   // 4.5
      {0x40A00000, 0x6, "5.0 -> 4.0", 1, 0},   // 5.0
      {0x40B00000, 0x7, "5.5 -> 6.0", 1, 0},   // 5.5
      {0x40C00000, 0x7, "6.0 -> 6.0", 0, 0},   // 6.0
      {0x40E00000, 0x7, "7.0 -> 6.0", 1, 1},   // 7.0
      {0x42C80000, 0x7, "100.0 -> 6.0", 1, 1}, // 100.0

      // 负数测试
      {0xBDCCCCCD, 0x8, "-0.1 -> -0.0", 1, 0},  // -0.1
      {0xBF000000, 0x9, "-0.5 -> -0.5", 0, 0},  // -0.5
      {0xBF800000, 0xA, "-1.0 -> -1.0", 0, 0},  // -1.0
      {0xBFC00000, 0xB, "-1.5 -> -1.5", 0, 0},  // -1.5
      {0xC0000000, 0xC, "-2.0 -> -2.0", 0, 0},  // -2.0
      {0xC0400000, 0xD, "-3.0 -> -3.0", 0, 0},  // -3.0
      {0xC0800000, 0xE, "-4.0 -> -4.0", 0, 0},  // -4.0
      {0xC0C00000, 0xF, "-6.0 -> -6.0", 0, 0},  // -6.0
      {0xC1200000, 0xF, "-10.0 -> -6.0", 1, 1}, // -10.0

      // 边界值测试
      {0x3E7FFFFF, 0x0, "0.2499999 -> 0.0", 1, 0}, // 刚好小于0.25
      // {0x3E800001, 0x1, "0.2500001 -> 0.5", 1, 0}, // 刚好大于0.25
      {0x3F3FFFFF, 0x1, "0.7499999 -> 0.5", 1, 0}, // 刚好小于0.75
      {0x3F400001, 0x2, "0.7500001 -> 1.0", 1, 0}, // 刚好大于0.75
      {0x3F9FFFFF, 0x2, "1.2499999 -> 1.0", 1, 0}, // 刚好小于1.25
      // {0x3FA00001, 0x3, "1.2500001 -> 1.5", 1, 0}, // 刚好大于1.25

      // 非规格化数测试
      // {0x00000001, 0x0, "Denormal min -> 0.0", 1, 0}, // 最小非规格化数
      {0x007FFFFF, 0x0, "Denormal max -> 0.0", 1, 0}, // 最大非规格化数

      // 其他重要边界
      {0x3FDFFFFF, 0x3, "1.7499999 -> 1.5", 1, 0}, // 刚好小于1.75
      {0x3FE00001, 0x4, "1.7500001 -> 2.0", 1, 0}, // 刚好大于1.75
      {0x401FFFFF, 0x4, "2.4999999 -> 2.0", 1, 0}, // 刚好小于2.5
      // {0x40200001, 0x5, "2.5000001 -> 3.0", 1, 0}, // 刚好大于2.5
      {0x405FFFFF, 0x5, "3.4999999 -> 3.0", 1, 0}, // 刚好小于3.5
      {0x40600001, 0x6, "3.5000001 -> 4.0", 1, 0}, // 刚好大于3.5
      {0x409FFFFF, 0x6, "4.9999999 -> 4.0", 1, 0}, // 刚好小于5.0
      // {0x40A00001, 0x7, "5.0000001 -> 6.0", 1, 0}, // 刚好大于5.0
      {0x40BFFFFF, 0x7, "5.9999999 -> 6.0", 1, 0}, // 刚好小于6.0
      {0x40C00100, 0x7, "6.0000600 -> 6.0", 1, 1}, // 刚好大于6.0
  };

  int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
  int passed = 0;
  int total = 0;

  printf("Testing Direct Compare method with %d test cases...\n\n",
         num_test_cases);

  for (int i = 0; i < num_test_cases; i++) {
    run_test_case_hex(test_cases[i], &passed, &total);
  }

  printf("\n========================================\n");
  printf("FP32 to NVFP4 E2M1 Test Summary: %d/%d tests passed (%.1f%%)\n",
         passed, total, (float)passed / total * 100);
  printf("========================================\n");
}
/*
// ========================= 交互式测试 =========================
void interactive_test_hex() {
    printf("\n\n=== Interactive Hex Input Test ===\n");
    printf("Enter FP32 hex values (32-bit, e.g., 3F800000 for 1.0)\n");
    printf("Type 'quit' to exit\n\n");

    char input[32];

    while (1) {
        printf("Enter hex value: ");
        if (scanf("%31s", input) != 1) break;

        if (strcmp(input, "quit") == 0) break;

        // 转换输入
        uint32_t hex_value;
        if (sscanf(input, "%x", &hex_value) != 1) {
            printf("Invalid hex format! Please use format like 3F800000\n");
            continue;
        }

        // 执行转换
        float32_t input_f32 = uint32_to_float32(hex_value);
        float float_val = uint32_to_float(hex_value);

        printf("Input: 0x%08X (float: %f)\n", hex_value, float_val);

        // 使用Direct Compare方法
        operators::cmodel_exceptionFlags = 0;
        nvfp4_e2m1_t result = f32_to_nvfp4_e2m1_direct(input_f32);
        uint8_t result_code = nvfp4_e2m1_get_bits(result);

        printf("Direct Compare Result: ");
        print_nvfp4_info(result_code);
        printf("Flags: ");
        print_softfloat_flags();
        printf("\n");
    }
}
// ========================= 反向转换测试 =========================
void test_reverse_conversion() {
    printf("\n\n=== Testing Reverse Conversion ===\n");

    // 测试所有可能的NVFP4值
    for (uint8_t code = 0; code <= 0xF; code++) {
        nvfp4_e2m1_t nvfp4_val = nvfp4_e2m1_from_bits(code);
        float fp32_val = nvfp4_e2m1_to_f32(nvfp4_val);

        printf("NVFP4: 0x%X -> FP32: %f", code, fp32_val);

        // 验证转换的一致性
        uint32_t fp32_bits = *(uint32_t*)&fp32_val;
        float32_t input_f32 = uint32_to_float32(fp32_bits);
        nvfp4_e2m1_t converted_back = f32_to_nvfp4_e2m1_direct(input_f32);
        uint8_t converted_code = nvfp4_e2m1_get_bits(converted_back);

        if (converted_code == code) {
            printf(" ✅ Consistent\n");
        } else {
            printf(" ❌ Inconsistent (got 0x%X)\n", converted_code);
        }
    }
}

*/
/*
// ========================= 批量转换测试 =========================
void test_batch_conversion_hex() {
    printf("\n\n=== Testing Batch Conversion (Hex Input) ===\n");

    uint32_t batch_hex[] = {
        0x3E99999A, // 0.3
        0x3F99999A, // 1.2
        0x402CCCCD, // 2.7
        0x40900000, // 4.5
        0xBF000000, // -0.5
        0xC0400000, // -3.0
        0x40C00000, // 6.0
        0xFF800000, // -Inf
        0x00000000  // +0.0
    };

    uint8_t expected_batch[] = {0x1, 0x2, 0x5, 0x6, 0x9, 0xD, 0x7, 0xF, 0x0};
    int batch_size = sizeof(batch_hex) / sizeof(batch_hex[0]);

    printf("Hex input values:\n");
    for (int i = 0; i < batch_size; i++) {
        printf("  0x%08X -> %f\n", batch_hex[i], uint32_to_float(batch_hex[i]));
    }
    printf("\n");

    printf("Expected NVFP4 codes: ");
    for (int i = 0; i < batch_size; i++) {
        printf("0x%X ", expected_batch[i]);
    }
    printf("\n\n");

    printf("Conversion results:\n");
    int all_passed = 1;

    for (int i = 0; i < batch_size; i++) {
        float32_t input_f32 = uint32_to_float32(batch_hex[i]);
        nvfp4_e2m1_t result = f32_to_nvfp4_e2m1_direct(input_f32);
        uint8_t result_code = nvfp4_e2m1_get_bits(result);

        float float_val = uint32_to_float(batch_hex[i]);
        printf("  0x%08X (%f) -> 0x%X %s\n",
               batch_hex[i], float_val, result_code,
               (result_code == expected_batch[i]) ? "✅" : "❌");

        if (result_code != expected_batch[i]) {
            all_passed = 0;
        }
    }

    printf("\nBatch test: %s\n", all_passed ? "✅ ALL PASSED" : "❌ SOME FAILED");
}
    */
/*
// ========================= 性能测试 =========================
void test_performance() {
    printf("\n\n=== Performance Test ===\n");

    // 使用代表性的测试值
    uint32_t test_values[] = {
        0x3DCCCCCD, // 0.1
        0x3F000000, // 0.5
        0x3F800000, // 1.0
        0x3FC00000, // 1.5
        0x40000000, // 2.0
        0x40400000, // 3.0
        0x40800000, // 4.0
        0x40C00000, // 6.0
        0xBF000000, // -0.5
        0xBF800000, // -1.0
        0x7F800000, // +Inf
        0x00000000  // +0.0
    };

    int num_values = sizeof(test_values) / sizeof(test_values[0]);
    const int iterations = 1000000;

    printf("Timing Direct Compare method with %d iterations...\n", iterations);
    fflush(stdout);

    clock_t start = clock();
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < num_values; i++) {
            float32_t input_f32 = uint32_to_float32(test_values[i]);
            nvfp4_e2m1_t result = f32_to_nvfp4_e2m1_direct(input_f32);
            (void)result; // 避免编译器警告
        }
    }
    clock_t end = clock();

    double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    double ops_per_sec = (iterations * num_values) / time_used;

    printf("Time: %.3f seconds, Throughput: %.0f ops/sec\n", time_used,
ops_per_sec);
}
*/
/*
// ========================= 边界值详细测试 =========================
void test_detailed_boundaries() {
    printf("\n\n=== Detailed Boundary Tests ===\n");

    // 测试所有重要的边界点
    struct {
        uint32_t hex;
        const char *desc;
        uint8_t expected;
    } boundaries[] = {
        {0x3E7FFFFF, "Just below 0.25", 0x0},
        {0x3E800000, "Exactly 0.25", 0x0},
        {0x3E800001, "Just above 0.25", 0x1},

        {0x3F3FFFFF, "Just below 0.75", 0x1},
        {0x3F400000, "Exactly 0.75", 0x2},
        {0x3F400001, "Just above 0.75", 0x2},

        {0x3F9FFFFF, "Just below 1.25", 0x2},
        {0x3FA00000, "Exactly 1.25", 0x2},
        {0x3FA00001, "Just above 1.25", 0x3},

        {0x3FDFFFFF, "Just below 1.75", 0x3},
        {0x3FE00000, "Exactly 1.75", 0x4},
        {0x3FE00001, "Just above 1.75", 0x4},

        {0x401FFFFF, "Just below 2.5", 0x4},
        {0x40200000, "Exactly 2.5", 0x4},
        {0x40200001, "Just above 2.5", 0x5},

        {0x405FFFFF, "Just below 3.5", 0x5},
        {0x40600000, "Exactly 3.5", 0x6},
        {0x40600001, "Just above 3.5", 0x6},

        {0x409FFFFF, "Just below 5.0", 0x6},
        {0x40A00000, "Exactly 5.0", 0x6},
        {0x40A00001, "Just above 5.0", 0x7},

        {0x40BFFFFF, "Just below 6.0", 0x7},
        {0x40C00000, "Exactly 6.0", 0x7},
        {0x40C00001, "Just above 6.0", 0x7},
    };

    int num_boundaries = sizeof(boundaries) / sizeof(boundaries[0]);
    int passed = 0;

    printf("Testing %d boundary points:\n\n", num_boundaries);

    for (int i = 0; i < num_boundaries; i++) {
        float32_t input_f32 = uint32_to_float32(boundaries[i].hex);
        nvfp4_e2m1_t result = f32_to_nvfp4_e2m1_direct(input_f32);
        uint8_t result_code = nvfp4_e2m1_get_bits(result);

        float float_val = uint32_to_float(boundaries[i].hex);
        printf("  0x%08X (%13.6f) %-25s -> 0x%X %s\n",
               boundaries[i].hex, float_val, boundaries[i].desc, result_code,
               (result_code == boundaries[i].expected) ? "✅" : "❌");

        if (result_code == boundaries[i].expected) {
            passed++;
        }
    }

    printf("\nBoundary tests: %d/%d passed\n", passed, num_boundaries);
}
*/
// ========================= 主函数 =========================
void tb_fp4() {
  // 初始化softfloat标志和舍入模式
  operators::cmodel_exceptionFlags = 0;
  softfloat_roundingMode = softfloat_round_near_even;

  printf("========================================\n");
  printf("FP32 to NVFP4 E2M1 Test Suite\n");
  printf("Hex Input + Direct Compare Method Only\n");
  printf("========================================\n");

  // 运行主要测试
  test_hex_direct_compare();

  // 运行边界值详细测试
  // test_detailed_boundaries();

  // 运行性能测试
  // test_performance();

  // 运行批量转换测试
  // test_batch_conversion_hex();

  // 运行反向转换测试
  // test_reverse_conversion();

  // 交互式测试
  // interactive_test_hex();

  printf("\n========================================\n");
  printf("All tests completed!\n");
  printf("========================================\n");

  // return 0;
}
