
#include "tb_fp32_to_f8_1.h"
#include "fp8_conversion.h"

// Helper function to print binary representation of a number
void print_binary(uint32_t num, int bits) {
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if (i == bits - 1)
      printf(" "); // Space after sign bit
    if (i == bits - 5)
      printf(" "); // Space after exponent for f8
    if (i == 7)
      printf(" "); // Space after every byte
  }
  printf("\n");
}

// Helper function to print fp32 in binary
void print_fp32(float32_t num) {
  union ui32_f32 u;
  u.f = num;
  printf("FP32:  ");
  print_binary(u.ui, 32);
}

// Helper function to print f8_1 in binary
void print_f8_1(float8_1_t num) {
  union ui8_f8_1 u;
  u.f = num;
  printf("F8_1:  ");
  print_binary(u.ui, 8);
}

void test_conversion(float32_t fp32_val, const char *test_name) {
  printf("\nTest Case: %s\n", test_name);
  print_fp32(fp32_val);

  operators::float8_1_t f8_result0 = (operators::f32_to_f8_1(fp32_val));
  float8_1_t f8_result; //= static_cast<float8_1_t>(f8_result0);
  f8_result.v = f8_result0.v;
  print_f8_1(f8_result);

  // Print flags if any were raised
  if (softfloat_exceptionFlags) {
    printf("Flags: ");
    if (softfloat_exceptionFlags & softfloat_flag_inexact)
      printf("Inexact ");
    if (softfloat_exceptionFlags & softfloat_flag_underflow)
      printf("Underflow ");
    if (softfloat_exceptionFlags & softfloat_flag_overflow)
      printf("Overflow ");
    if (softfloat_exceptionFlags & softfloat_flag_infinite)
      printf("Infinite ");
    if (softfloat_exceptionFlags & softfloat_flag_invalid)
      printf("Invalid ");
    printf("\n");
  }
  if (operators::cmodel_exceptionFlags) {
    printf("Flags: ");
    if (operators::cmodel_exceptionFlags & softfloat_flag_inexact)
      printf("Inexact ");
    if (operators::cmodel_exceptionFlags & softfloat_flag_underflow)
      printf("Underflow ");
    if (operators::cmodel_exceptionFlags & softfloat_flag_overflow)
      printf("Overflow ");
    if (operators::cmodel_exceptionFlags & softfloat_flag_infinite)
      printf("Infinite ");
    if (operators::cmodel_exceptionFlags & softfloat_flag_invalid)
      printf("Invalid ");
    printf("\n");
  }

  // Reset flags for next test
  softfloat_exceptionFlags = 0;
  operators::cmodel_exceptionFlags = 0;
}

void tb_f32tof8_1() {
  // Initialize softfloat state
  softfloat_roundingMode = softfloat_round_near_even;
  softfloat_exceptionFlags = 0;
  operators::cmodel_exceptionFlags = 0;
  printf("Testing FP32 to F8_1 Conversion\n");
  printf("================================\n");
  printf("Format: Sign Exponent Mantissa\n\n");

  // Test case : 0x400000
  union ui32_f32 test_din;
  test_din.ui = 0x400000; //
  test_conversion(test_din.f, "Normal Number (0x400000)");

  // Test case : 0x7f800000
  test_din.ui = 0x7f800000; //
  test_conversion(test_din.f, " (+inf)");

  // Test case 11: Normal number (1.0)
  union ui32_f32 one1;
  one1.ui = 0x3c700000; //
  test_conversion(one1.f, "Normal Number (0.0146484375)");

  // Test case 12: 0x00000001
  union ui32_f32 d12;
  d12.ui = 0x00000001; //
  test_conversion(d12.f, "Normal Number (0x00000001)");

  // Test case 13: 0x00000001
  union ui32_f32 d13;
  d13.ui = 0x3A000000; //
  test_conversion(d13.f, "Normal Number (0x3A000000)");

  // Test case 4: Small number (potentially becomes denormal)
  union ui32_f32 small;
  small.ui = 0x35000000; // Very small positive number
  test_conversion(small.f, "Small Number (Potential Denormal)");

  // Test case 1: Normal number (1.0)
  union ui32_f32 one;
  one.ui = 0x3F800000; // 1.0 in fp32
  test_conversion(one.f, "Normal Number (1.0)");

  // Test case 2: Zero
  union ui32_f32 zero;
  zero.ui = 0x00000000;
  test_conversion(zero.f, "Zero");

  // Test case 3: Negative number (-2.0)
  union ui32_f32 neg_two;
  neg_two.ui = 0xC0000000; // -2.0 in fp32
  test_conversion(neg_two.f, "Negative Number (-2.0)");

  // Test case 4: Small number (potentially becomes denormal)
  // union ui32_f32 small;
  // small.ui = 0x35000000; // Very small positive number
  // test_conversion(small.f, "Small Number (Potential Denormal)");

  // Test case 5: Large number (potential overflow)
  union ui32_f32 large;
  large.ui = 0x47800000; // Large positive number
  test_conversion(large.f, "Large Number (Potential Overflow)");

  // Test case 6: Infinity
  union ui32_f32 inf;
  inf.ui = 0x7F800000; // Positive infinity
  test_conversion(inf.f, "Positive Infinity");

  // Test case 7: NaN
  union ui32_f32 nan;
  nan.ui = 0x7FC00000; // NaN
  test_conversion(nan.f, "NaN");

  // Test case 8: Negative infinity
  union ui32_f32 neg_inf;
  neg_inf.ui = 0xFF800000; // Negative infinity
  test_conversion(neg_inf.f, "Negative Infinity");

  // Test case 9: Number requiring rounding
  union ui32_f32 round_num;
  round_num.ui = 0x3F900000; // 1.125 in fp32
  test_conversion(round_num.f, "Number Requiring Rounding (1.125)");

  // Test case 10: PI
  union ui32_f32 pi;
  pi.ui = 0x40490FDB; // π in fp32
  test_conversion(pi.f, "PI (3.14159...)");

  // return 0;
}
