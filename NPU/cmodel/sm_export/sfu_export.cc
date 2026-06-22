#include "cmodel.h"
#include "sfu_exp.h"
#include "sfu_sincos.h"
#include "sfu_sqrt_rcp.h"
#include "sfu_tanh.h"

uint32_t sfu_func_fp32(uint32_t uiA, uint8_t opcode) {
  switch (opcode) {
  case 0:
    return operators::sfu_sqrt(uiA);
    break;
  case 1:
    return operators::sfu_rcpsqrt(uiA);
    break;
  case 2:
    return operators::sfu_rcp(uiA);
    break;
  case 3:
    return operators::sfu_exp(uiA);
    break;
  case 4:
    return operators::sfu_expE(uiA);
    break;
  case 5:
    return operators::sfu_tanh(uiA);
    break;
  case 6:
    return operators::sfu_sigmoid(uiA);
    break;
  case 7:
    // return operators::sfu_log2(uiA);
    break;
  case 8:
    return operators::sfu_sincos(uiA);
    break;
  case 9:
    return operators::sfu_sincos(uiA, 1);
    break;
  default:
    cerr << "unkown opcode" << endl;
    break;
  }
  return 0x0;
}

// FIXME: fp16 sin/cos
uint16_t sfu_func_fp16(uint16_t uiA, uint8_t opcode) {
  switch (opcode) {
  case 0:
    // return operators::sfu_sqrt(uiA);
    break;
  case 1:
    // return operators::sfu_rcpsqrt(uiA);
    break;
  case 2:
    // return operators::sfu_rcp(uiA);
    break;
  case 3:
    return operators::sfu_exp(uiA);
    break;
  case 4:
    return operators::sfu_expE(uiA);
    break;
  case 5:
    // return operators::sfu_tanh(uiA);
    break;
  case 6:
    // return operators::sfu_sigmoid(uiA);
    break;
  case 7:
    // return operators::sfu_log2(uiA);
    break;
  case 8:
    return operators::sfu_sincos(uiA);
    break;
  case 9:
    return operators::sfu_sincos(uiA, 1);
    break;
  default:
    cerr << "unkown opcode" << endl;
    break;
  }
  return 0x0;
}