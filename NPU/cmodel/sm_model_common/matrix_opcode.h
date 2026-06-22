#ifndef _matrix_opcode_h
#define _matrix_opcode_h

#include <stdint.h>
namespace operators {
struct matrix_opcode {
  virtual ~matrix_opcode() = default;
  virtual void decode(uint64_t params0) = 0;
  static matrix_opcode *generate(uint64_t params0);
  uint64_t raw_cmd = 0;

  bool op_mode = false;      // 0:matmul,1:conv
  bool subcmd_bc_id = false; // 0:bc0,1:bc1
};

struct matrix_opcode_mat : public matrix_opcode {
  bool is_gemv;     // 1 1表示gemv 0表示gemm；
  uint8_t o_tile_m; // 8 o_tile
                    // m值，一般情况为128，边界情况会变；同时也是subcmd的m值；
  uint8_t o_tile_n; // 8 o_tile
                    // n值，一般情况为128，边界情况会变；同时也是subcmd的n值；
  bool qk_quant_en;         // 1 1'b1,开启QK_QUANT；pproc按照m16n8处理；
  bool is_gather_ld_act;    // 1 0: 常规读/1: 离散读Act(此时Act在L1
                            // Buf中按照HW格式排布)
  bool weight_quant_is_sym; // 1 0: symmetric quantization/1: asymmetric
                            // quantization
  bool act_quant_mode;      // 1 0-None/1-per-group
  uint8_t act_per_group_size;    // 8 activation的 per_group size(32, 64, 128)
  uint8_t act_per_block_size;    // 8 activation的 per_block size(32x32, 64x64,
                                 // 128x128)
  uint8_t weight_quant_mode : 2; // 2 0-None/1-per-block/2-per-group
  uint8_t weight_per_group_size; // 8 weight的 per_group size(32, 64, 128)
  uint8_t weight_per_block_size; // 8 activation的 per_block size(32x32, 64x4,
                                 // 128x128)
  uint8_t
      quant_param_format : 2; // 0-BF16/1-FP16/2-FP8（量化参数的数据格式，wgt和act相同）
  uint8_t last_o_tile : 1;        // dst_box最后一个subcmd的flag；
  uint16_t quant_shift_value : 4; // i16*i4的量化shift值

  explicit matrix_opcode_mat(){};
  explicit matrix_opcode_mat(uint64_t params0) { decode(params0); };

  void decode(uint64_t params0) override {
    raw_cmd = params0;
    op_mode = (params0 >>= 0) & 1; // 0:matmul,1:conv
    subcmd_bc_id = (params0 >>= 1) & 1;
    is_gemv = (params0 >>= 1) & 1;            // 1
    o_tile_m = (params0 >>= 1) & 0xff;        // 8
    o_tile_n = (params0 >>= 8) & 0xff;        // 8
    qk_quant_en = (params0 >>= 8) & 0x1;      // 1
    is_gather_ld_act = (params0 >>= 1) & 0x1; // 1
    weight_quant_is_sym =
        0; // weight_quant_is_sym = (params0 >>= 1) & 0x1;    // 1
    act_quant_mode = (params0 >>= 1) & 0x1; // 1
    act_per_group_size = 0;                 // (params0 >>= 1) & 0xff;    // 8
    act_per_block_size = 0;                 // (params0 >>= 8) & 0xff;    // 8
    weight_quant_mode = (params0 >>= 1) & 0x3; // 2
    weight_per_group_size = 0;                 // (params0 >>= 2) & 0xff; // 8
    weight_per_block_size = 0;                 // (params0 >>= 8) & 0xff; // 8
    quant_param_format = (params0 >>= 2) & 0x3;
    last_o_tile = (params0 >>= 2) & 0x1;
    quant_shift_value = (params0 >>= 1) & 0b1111;
  }
};

struct matrix_opcode_conv : public matrix_opcode {
  uint8_t o_tile_w; // 5	o_tile
                    // w值，一般情况为16，边界情况会变；同时也是subcmd的w值；
  uint8_t o_tile_h; // 4	o_tile
                    // h值，一般情况为8，边界情况会变；同时也是subcmd的h值；
  uint8_t o_tile_c; // 8	o_tile
                    // c值，一般情况为128，边界情况会变；同时也是subcmd的c值；
  uint8_t o_tile_n; // 8	o_tile n值，一般情况为
                    // ，边界情况会变；同时也是subcmd的n值；

  explicit matrix_opcode_conv(){};
  explicit matrix_opcode_conv(uint64_t params0) { decode(params0); };
  void decode(uint64_t params0) override {
    raw_cmd = params0;
    op_mode = (params0 >>= 0) & 1; // 0:matmul,1:conv
    subcmd_bc_id = (params0 >>= 1) & 1;
    o_tile_w = (params0 >>= 1) & 0b11111; // 5
    o_tile_h = (params0 >>= 5) & 0b1111;  // 4
    o_tile_c = (params0 >>= 4) & 0xff;    // 8
    o_tile_n = (params0 >>= 8) & 0xff;    // 8
  }
};
} // namespace operators

#endif