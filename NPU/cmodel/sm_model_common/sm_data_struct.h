#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include "sm_datatype_utils.h"
#include "softfloat.h"
#include <cstdbool> // C++ 标准库头文件
#include <cstdint>  // C++ 标准库头文件

namespace operators {
// 定义位宽
extern int bit_width_dop_f4dp64;
extern int bit_width_dop_mdp32;
extern int bit_width_dop_fdp16;
extern int bit_width_dop_bf16fp4;
extern int bit_width_dop_idp;
extern bool denormal_out_en;
extern bool denormal_in_en;
extern bool matrix_dp_en;
extern uint_fast8_t cmodel_exceptionFlags;

// 定义联合体 ui16_bf16
union ui16_bf16 {
  uint16_t ui;
  bfloat16_t bf;
};
// 定义结构体 FP16MulIntermediate
struct FP16MulIntermediate {
  bool zero_tag;       // 1 bit
  bool NAN_tag;        // 1 bit
  bool Infinity_tag;   // 1 bit
  uint64_t sign;       // 符号位 (1 bit)
  uint16_t exp;        // 指数位 (16 bit)
  uint32_t frac32;     // 尾数位 (32 bit)
  uint64_t frac64;     // 尾数位 (64 bit)
  __uint128_t frac128; // 尾数位 (128 bit)
};

#define uint64_1 (uint64_t)1
#define expBias32UI 127
#define expBias16UI 15
#define expBias24UI 127
#define int40Pinf 0x7FFFFFFFFF
#define int40Ninf 0x8000000000

#define defaultNANF16UI 0x7E00
#define defaultPINF16UI 0x7C00 //+inf
#define defaultNINF16UI 0xFC00 //-inf
#define defaultPINF32UI 0x7F800000
#define defaultNINF32UI 0xFF800000
#define defaultPINFF24UI 0x7F8000
#define defaultNINFF24UI 0xFF8000
#define defaultNANF32UI 0x7FC00000
#define defaultNANF24UI 0x7FC000

#define signF24UI(a) ((bool)((uint32_t)(a) >> 23))
#define expF24UI(a) ((int_fast16_t)((a) >> 15) & 0xFF)
#define fracF24UI(a) ((a)&0x7FFF)
#define packToF24UI(sign, exp, sig)                                            \
  (((uint32_t)(sign) << 23) + ((uint32_t)(exp) << 15) + (sig))
#define isNaNF24UI(a) (((~(a)&0x7F8000) == 0) && ((a)&0x7FFF))

// general UI
#define expBiasGeneralUI(exp_len) ((uint64_1 << exp_len - 1) - 1)
#define defaultNANGeneralUI(exp_len, sig_len)                                  \
  ((uint64_1 << exp_len + sig_len) - (uint64_1 << sig_len - 1))
#define defaultPINFGeneralUI(exp_len)                                          \
  ((uint64_1 << exp_len) - 1) // 提取指数值的工具位
#define defaultNINFGeneralUI(exp_len)                                          \
  ((uint64_1 << exp_len + 1) - 1) // 提取指数值+符号位的工具位
// #define defaultINFGeneralUI(sign, exp_len, sig_len) ((uint64_1 << exp_len +
// sig_len + sign) - (uint64_1 << sig_len))
// // 正负无穷
#define defaultINFGeneralUI(sign, exp_len, sig_len)                            \
  (((uint64_t)sign << exp_len + sig_len) |                                     \
   ((uint64_1 << exp_len + sig_len) - (uint64_1 << sig_len))) // 正负无穷
#define signGeneralUI(a, exp_len, sig_len)                                     \
  ((bool)(a >> exp_len + sig_len)) //  符号位
#define expGeneralUI(a, exp_len, sig_len)                                      \
  ((a >> sig_len) & defaultPINFGeneralUI(exp_len))
#define fracGeneralUIUI(a, sig_len)                                            \
  (a & ((uint64_1 << sig_len) - 1)) // 提取尾数
#define packToGeneralUIUI(sign, exp_, sig)                                     \
  (((uint32_t)(sign) << (exp_len + sig_len)) + ((uint32_t)(exp_) << sig_len) + \
   (sig)) // 打包成完整fp
#define isNaNGeneralUI(a, exp_len, sig_len)                                    \
  (!((~a >> sig_len) & defaultPINFGeneralUI(exp_len)) &&                       \
   fracGeneralUIUI(a, sig_len)) // 判断是否NAN
#define isINFGeneralUI(a, exp_len, sig_len)                                    \
  (!((~a >> sig_len) & defaultPINFGeneralUI(exp_len)) &&                       \
   (!fracGeneralUIUI(a, sig_len))) // 判断是否INF

#define sigHideGeneralUI(sig_len) (uint64_1 << sig_len)

#define intSignGeneralUI(a, sign_len, sig_len)                                 \
  (bool)(sign_len ? ((a >> sig_len - sign_len)) & 1 : 0) // 提取sint符号位
#define intFracGeneralUI(a, sign_len, sig_len)                                 \
  (intSignGeneralUI(a, sign_len, sig_len)                                      \
       ? defaultPINFGeneralUI(sig_len) & (~a) + 1                              \
       : a & ((uint64_1 << sig_len - sign_len + 1) - 1)) // 提取sint尾数位
// #define intFracGeneralUI(a, sign_tag, sig_len) (a & (~(1 << sig_len -
// sign_tag)))

} // namespace operators

#endif // DATA_DATA_STRUCT_HPPSTRUCT_H