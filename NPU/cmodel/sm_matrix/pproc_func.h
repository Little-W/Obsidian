#ifndef _pproc_func_h
#define _pproc_func_h

#include "dop_ops.h"
#include "matrix_struct.h"
#include "pproc_opcode.h"
#include "sfu_exp.h"
#include "sfu_sqrt_rcp.h"
#include "sfu_tanh.h"

namespace operators {
// 要求输入都转成fp24格式
void pproc_base_stream_alpha(uint16_t *params, pproc_en_mode &en_mode,
                             pproc_datatype &data_info, pproc_tile_mask &mask,
                             uint64_t **res, uint16_t **elw, uint32_t **des,
                             uint32_t row, uint32_t column);
inline uint32_t read_param_32to24(const uint16_t *data, size_t offset) {
  uint32_t tmp32;
  // 从指定偏移量读取32位值
  memcpy(&tmp32, data + offset, sizeof(uint32_t));
  // 提取高24位：右移8位，保留高24位作为低24位
  return (tmp32 >> 8) & 0x00FFFFFF;
}
} // namespace operators

#endif