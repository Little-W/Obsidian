#ifndef NVFP4_E2M1_H
#define NVFP4_E2M1_H

#include <cstring>
#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "specialize.h"
#include "softfloat.h"
#include "softfloat_types.h"
#include "dop_ops.h"

namespace operators {
// NVFP4 E2M1 类型定义
typedef struct {
  uint8_t v; // 存储4位NVFP4 E2M1编码（只使用低4位）
} nvfp4_e2m1_t;

// 联合类型，用于在整数和NVFP4格式之间转换
typedef union ui8_nvfp4_e2m1 {
  uint8_t ui;
  nvfp4_e2m1_t f;
} ui8_nvfp4_e2m1;

// union ui32_f32_f4 { uint32_t ui; float f; };
// Common NaN 结构（假设在 softfloat 中定义）
// struct commonNaN;

// NVFP4 E2M1 常量定义
#define NVFP4_E2M1_POS_ZERO 0x0     // +0.0
#define NVFP4_E2M1_POS_HALF 0x1     // +0.5
#define NVFP4_E2M1_POS_ONE 0x2      // +1.0
#define NVFP4_E2M1_POS_ONE_HALF 0x3 // +1.5
#define NVFP4_E2M1_POS_TWO 0x4      // +2.0
#define NVFP4_E2M1_POS_THREE 0x5    // +3.0
#define NVFP4_E2M1_POS_FOUR 0x6     // +4.0
#define NVFP4_E2M1_POS_SIX 0x7      // +6.0

#define NVFP4_E2M1_NEG_ZERO 0x8     // -0.0
#define NVFP4_E2M1_NEG_HALF 0x9     // -0.5
#define NVFP4_E2M1_NEG_ONE 0xA      // -1.0
#define NVFP4_E2M1_NEG_ONE_HALF 0xB // -1.5
#define NVFP4_E2M1_NEG_TWO 0xC      // -2.0
#define NVFP4_E2M1_NEG_THREE 0xD    // -3.0
#define NVFP4_E2M1_NEG_FOUR 0xE     // -4.0
#define NVFP4_E2M1_NEG_SIX 0xF      // -6.0

// 主要转换函数声明
// nvfp4_e2m1_t f32_to_nvfp4_e2m1(float32_t a);
// nvfp4_e2m1_t f32_to_nvfp4_e2m1_bitwise(float32_t a);
nvfp4_e2m1_t f32_to_nvfp4_e2m1_direct(float32_t a);
fp_general_t f24_to_nvfp4_e2m1(fp_general_t a);
float nvfp4_e2m1_to_f32(nvfp4_e2m1_t a);
fp_general_t nvfp4_to_f32(fp_general_t a);
uint_fast8_t softfloat_commonNaNToNVFP4_E2M1UI(struct commonNaN *commonNaN);

// 辅助函数
static inline uint8_t nvfp4_e2m1_get_bits(nvfp4_e2m1_t a) { return a.v & 0x0F; }

static inline bool nvfp4_e2m1_get_sign(nvfp4_e2m1_t a) {
  return (a.v >> 3) & 0x1;
}

static inline uint8_t nvfp4_e2m1_get_value_code(nvfp4_e2m1_t a) {
  return a.v & 0x07;
}

static inline nvfp4_e2m1_t nvfp4_e2m1_from_bits(uint8_t bits) {
  nvfp4_e2m1_t result;
  result.v = bits & 0x0F;
  return result;
}

static inline nvfp4_e2m1_t nvfp4_e2m1_make(bool sign, uint8_t value_code) {
  nvfp4_e2m1_t result;
  result.v = ((sign ? 1 : 0) << 3) | (value_code & 0x07);
  return result;
}
} // namespace operators
#endif // NVFP4_E2M1_H