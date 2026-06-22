#include "dop_ops.h"
#include "internals.h"
#include "specialize.h"
#include <stdbool.h>
#include <stdint.h>

#define packToGeneral(sign, exp, sig, exp_len, sig_len)                        \
  (((uint64_t)(sign) << (exp_len + sig_len)) + ((uint64_t)(exp) << sig_len) +  \
   (sig))

namespace operators {
fp_general_t low_to_high(fp_general_t a, int low_exp_len, int low_sig_len,
                         int high_exp_len, int high_sig_len) {
  // alu_output_exam(a, low_exp_len, low_sig_len);
  uint64_t signA;
  uint32_t expA;
  uint_fast64_t sigA;
  int high_nan_len = high_exp_len + high_sig_len + 1;

  uint64_t signZ;
  uint32_t magBits;
  uint32_t expZ;
  uint32_t sigZ;
  int_fast16_t exp;

  uint64_t tool_num = 0xFFFFFFFFFFFFFFFF;
  fp_general_t z;
  uint_fast64_t frac;

  uint64_t low_sig_tool = tool_num << (64 - low_sig_len) >> (64 - low_sig_len);
  uint64_t low_exp_max =
      tool_num << (64 - low_sig_len - low_exp_len) >> (64 - low_exp_len);
  uint64_t low_exp_tool = low_exp_max << (64 - low_exp_len);
  uint64_t low_sign_tool = uint64_1 << (low_exp_len + low_sig_len);
  uint64_t low_sig_hiden = uint64_1 << low_sig_len;

  uint64_t high_sig_tool =
      tool_num << (64 - high_sig_len) >> (64 - high_sig_len);
  uint64_t high_exp_max =
      tool_num << (64 - high_sig_len - high_exp_len) >> (64 - high_exp_len);
  uint64_t high_sign_tool = uint64_1 << (high_exp_len + high_sig_len);
  uint64_t high_sig_hiden = uint64_1 << high_sig_len;

  __uint128_t sig128Z = 0;
  FP16MulIntermediate result = {0};

  signA = signGeneralUI(a, low_exp_len, low_sig_len);
  expA = expGeneralUI(a, low_exp_len, low_sig_len);
  sigA = fracGeneralUIUI(a, low_sig_len);
  frac = sigA;
  exp = expA;

  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  if (exp == low_exp_max) {
    if (frac) {
      z = defaultNANGeneralUI(high_exp_len, high_sig_len);
    } else {
      z = defaultINFGeneralUI(signA, high_exp_len, high_sig_len);
    }
    goto uiZ;
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/
  if (low_exp_len == high_exp_len) {
    z = packToGeneral(signA, expA,
                      (uint_fast32_t)frac << (high_sig_len - low_sig_len),
                      high_exp_len, high_sig_len);
    goto uiZ;
  } else {
    if (!exp) {
      if (!frac) {
        z = signA ? high_sign_tool : 0;
        goto uiZ;
      }

      int_fast8_t shiftDist;
      struct exp8_sig16 z;

      shiftDist = softfloat_countLeadingZeros64(sigA) - (64 - low_sig_len - 1);
      exp = -shiftDist;
      frac = (uint64_t)sigA << shiftDist;
    }
    /*------------------------------------------------------------------------
     *------------------------------------------------------------------------*/
    int exp_dist_low = (1 << (low_exp_len - 1)) - 1;
    int exp_dist_high = (1 << (high_exp_len - 1)) - 1;
    z = packToGeneral(signA, exp - exp_dist_low + exp_dist_high,
                      (uint_fast32_t)frac << (high_sig_len - low_sig_len),
                      high_exp_len, high_sig_len);
  }
  /*------------------------------------------------------------------------
   *------------------------------------------------------------------------*/

uiZ:
  return z;
}
} // namespace operators
