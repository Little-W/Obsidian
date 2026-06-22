#ifndef _pproc_opcode_h
#define _pproc_opcode_h

#include <stdint.h>
#include <stdlib.h>
namespace operators {
typedef enum { relu = 0, relu6 = 1, leakrelu = 2, prelu = 3 } y_relu_op_enum;
typedef enum { sigmoid = 0, tanh = 1 } y_sfu_op_enum;
typedef enum { byp = 0, mul = 1, add = 2, sub = 3 } elw_op_enum;

struct pproc_params {
  uint16_t x_scale = 0;
  uint16_t x_bias = 0;
  uint16_t y_elw_scale = 0;
  uint16_t y_elw_bias = 0;
  uint16_t y_relu_scale = 0;
  uint16_t c_scale = 0;
  uint16_t c_bias = 0;
  pproc_params(){};
  pproc_params(uint16_t params0, uint16_t params1, uint16_t params2,
               uint16_t params3, uint16_t params4, uint16_t params5,
               uint16_t params6) {
    set_value(params0, params1, params2, params3, params4, params5, params6);
  }
  pproc_params(uint16_t params0, uint16_t params1, uint16_t params2,
               uint16_t params3) {
    set_value(params0, params1, 0, 0, 0, params2, params3);
  }
  pproc_params(uint16_t *params0) { set_value(params0); }

  void set_value(uint16_t params0, uint16_t params1, uint16_t params2,
                 uint16_t params3, uint16_t params4, uint16_t params5,
                 uint16_t params6) {
    x_scale = params0;
    x_bias = params1;
    y_elw_scale = params2;
    y_elw_bias = params3;
    y_relu_scale = params4;
    c_scale = params5;
    c_bias = params6;
  }
  void set_value(uint16_t *params0) {
    x_scale = params0[0];
    x_bias = params0[1];
    y_elw_scale = params0[2];
    y_elw_bias = params0[3];
    y_relu_scale = params0[4];
    c_scale = params0[5];
    c_bias = params0[6];
  }

  void set_value(uint16_t params0, uint16_t params1, uint16_t params2,
                 uint16_t params3) {
    set_value(params0, params1, 0, 0, 0, params2, params3);
  }
};

struct pproc_en_mode {
  virtual ~pproc_en_mode() = default;
  virtual void decode(uint64_t params0) = 0;
  static pproc_en_mode *generate(uint64_t params0);
  uint64_t raw_cmd = 0;

  bool op_mode = false;      // 0:matmul,1:conv
  bool subcmd_bc_id = false; // 0:bc0,1:bc1

  bool pproc_x_scale_en = false;
  bool pproc_x_bias_en = false;
  bool pproc_y_elw_scale_en = false;
  bool pproc_y_elw_bias_en = false;
  bool pproc_y_relu_scale_en = false;
  bool pproc_c_scale_en = false;
  bool pproc_c_bias_en = false;

  bool pproc_x_scale_en_per_chn = false;
  bool pproc_x_bias_en_per_chn = false;
  bool pproc_y_elw_scale_en_per_chn = false;
  bool pproc_y_elw_bias_en_per_chn = false;
  bool pproc_y_relu_scale_en_per_chn = false;
  bool pproc_c_scale_en_per_chn = false;
  bool pproc_c_bias_en_per_chn = false;

  uint8_t pproc_param_format : 2; // 0:fp16,1:bf16,2:fp32
  bool pp_elw_en = false;
  elw_op_enum elw_op = byp;
  bool pp_pproc_en = false;
  bool pproc_y_relu_en = false;
  y_relu_op_enum y_relu_op = relu;
  bool pproc_y_sfu_en = false;
  y_sfu_op_enum y_sfu_op = sigmoid;
  bool pproc_y_scale_en = false;
  // bool pproc_y_elw_en = false;

  uint8_t o_tile_w = 16;
  uint8_t o_tile_h = 8;
  uint8_t o_tile_c = 128;
  uint8_t o_tile_n = 128;
  uint8_t o_tile_m = 128;

  bool qk_quant_en = false;
  bool pproc_x_scale_pertok = false;
  uint64_t pproc_param_base = 0;
};

struct pproc_en_mode_matmul : public pproc_en_mode {
  explicit pproc_en_mode_matmul(){};
  explicit pproc_en_mode_matmul(uint64_t params0) { decode(params0); };
  void decode(uint64_t params0) override {
    raw_cmd = params0;
    op_mode = (params0 >>= 0) & 1; // 0:matmul,1:conv
    subcmd_bc_id = (params0 >>= 1) & 1;

    pproc_x_scale_en = (params0 >>= 1) & 1;
    pproc_x_bias_en = (params0 >>= 1) & 1;
    pproc_y_elw_scale_en = (params0 >>= 1) & 1;
    pproc_y_elw_bias_en = (params0 >>= 1) & 1;
    pproc_y_relu_scale_en = (params0 >>= 1) & 1;
    pproc_c_scale_en = (params0 >>= 1) & 1;
    pproc_c_bias_en = (params0 >>= 1) & 1;

    pproc_x_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_x_bias_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_elw_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_elw_bias_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_relu_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_c_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_c_bias_en_per_chn = (params0 >>= 1) & 1;

    pproc_param_format = (params0 >>= 1) & 0b11;
    pp_elw_en = (params0 >>= 2) & 1;
    elw_op = static_cast<elw_op_enum>((params0 >>= 1) & 0b11);
    pp_pproc_en = (params0 >>= 2) & 1;
    pproc_y_relu_en = (params0 >>= 1) & 1;
    y_relu_op = static_cast<y_relu_op_enum>((params0 >>= 1) & 0b11);
    pproc_y_sfu_en = (params0 >>= 2) & 1;
    y_sfu_op = static_cast<y_sfu_op_enum>((params0 >>= 1) & 0b11);
    pproc_y_scale_en = (params0 >>= 2) & 1;

    o_tile_m = (params0 >>= 1) & 0xff;
    o_tile_n = (params0 >>= 8) & 0xff;
    qk_quant_en = (params0 >>= 8) & 1;
    pproc_x_scale_pertok = (params0 >>= 1) & 1;
  }
};

struct pproc_en_mode_conv : public pproc_en_mode {

  explicit pproc_en_mode_conv(){};
  explicit pproc_en_mode_conv(uint64_t params0) { decode(params0); };
  void decode(uint64_t params0) override {
    raw_cmd = params0;
    op_mode = (params0 >>= 0) & 1; // 0:matmul,1:conv
    subcmd_bc_id = (params0 >>= 1) & 1;

    pproc_x_scale_en = (params0 >>= 1) & 1;
    pproc_x_bias_en = (params0 >>= 1) & 1;
    pproc_y_elw_scale_en = (params0 >>= 1) & 1;
    pproc_y_elw_bias_en = (params0 >>= 1) & 1;
    pproc_y_relu_scale_en = (params0 >>= 1) & 1;
    pproc_c_scale_en = (params0 >>= 1) & 1;
    pproc_c_bias_en = (params0 >>= 1) & 1;

    pproc_x_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_x_bias_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_elw_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_elw_bias_en_per_chn = (params0 >>= 1) & 1;
    pproc_y_relu_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_c_scale_en_per_chn = (params0 >>= 1) & 1;
    pproc_c_bias_en_per_chn = (params0 >>= 1) & 1;

    pproc_param_format = (params0 >>= 1) & 0b11;
    pp_elw_en = (params0 >>= 2) & 1;
    elw_op = static_cast<elw_op_enum>((params0 >>= 1) & 0b11);
    pp_pproc_en = (params0 >>= 2) & 1;
    pproc_y_relu_en = (params0 >>= 1) & 1;
    y_relu_op = static_cast<y_relu_op_enum>((params0 >>= 1) & 0b11);
    pproc_y_sfu_en = (params0 >>= 2) & 1;
    y_sfu_op = static_cast<y_sfu_op_enum>((params0 >>= 1) & 0b11);
    pproc_y_scale_en = (params0 >>= 2) & 1;

    o_tile_w = (params0 >>= 1) & 0b11111;
    o_tile_h = (params0 >>= 5) & 0b1111;
    o_tile_c = (params0 >>= 4) & 0xff;
  }
};

struct pproc_datatype {
  uint64_t *raw_cmd = nullptr;
  virtual ~pproc_datatype() = default;
  virtual void decode(uint64_t *params0) = 0;
  static pproc_datatype *generate(uint64_t *params0);

  bool op_mode;           // 0:matmul,1:conv
  uint8_t dst_format;     // dst_format	3
                          // 0-i8/1-u8/2-i16/3-u16/4-fp16/5-bf16/6-fp32
  uint8_t src_act_format; // src_act_format	3
                          // 0-u8/1-i8/2-i16/3-u16/4-fp16/5/bf16/6-MXFP8/7-FP8
  uint8_t src_wgt_format; // src_wgt_format	3
                          // 0-i4/1-u4/2-i8/3-fp16/4-bf16/5-MXFP8/6-FP8
  uint8_t pproc_y_elw_format; // pproc_y_elw_format	3
                              // 0-i8/1-u8/2-i16/3-u16/4-fp16/5-bf16
  uint8_t src_act_k;          // src_act_k	26	矩阵乘的k维度
  uint32_t dst_box_m;         // 16
  uint16_t dst_box_n;         // 16
  uint16_t dst_box_b;         // 16
  uint16_t dst_box_channel;   // 16
  uint16_t dst_box_width;     // 16
  uint16_t dst_box_height;    // 16
  uint16_t dst_box_batch;     // 16
  bool quant_param_format;
};

struct pproc_datatype_matmul : public pproc_datatype {
  explicit pproc_datatype_matmul(){};
  explicit pproc_datatype_matmul(uint64_t *params0) { decode(params0); };
  void decode(uint64_t *params0) override {
    raw_cmd = (uint64_t *)malloc(2 * sizeof(uint64_t));
    raw_cmd[0] = params0[0];
    raw_cmd[1] = params0[1];
    op_mode = (params0[0] >>= 0) & 1;                // 0:matmul,1:conv
    dst_format = (params0[0] >> 0) & 0b111;          // 3
    src_act_format = (params0[0] >>= 3) & 0b1111;    // 4
    src_wgt_format = (params0[0] >>= 4) & 0b1111;    // 4
    pproc_y_elw_format = (params0[0] >>= 4) & 0b111; // 3
    src_act_k = (params0[0] >>= 3) & 0x3FFFFFF;      // 26
    dst_box_m = (params0[0] >>= 26) & 0xFFFF;        // 16
    dst_box_n = params0[1] & 0xFFFF;                 // 16
  }

  ~pproc_datatype_matmul() override {
    if (raw_cmd != nullptr) {
      free(raw_cmd);
      raw_cmd = nullptr;
    }
  }
};

struct pproc_datatype_conv : public pproc_datatype {
  explicit pproc_datatype_conv(){};
  explicit pproc_datatype_conv(uint64_t *params0) { decode(params0); };
  void decode(uint64_t *params0) override {
    raw_cmd = (uint64_t *)malloc(2 * sizeof(uint64_t));
    raw_cmd[0] = params0[0];
    raw_cmd[1] = params0[1];

    op_mode = (params0[0] >>= 0) & 1;                // 0:matmul,1:conv
    dst_format = (params0[0] >> 0) & 0b111;          // 3
    src_act_format = (params0[0] >>= 3) & 0b1111;    // 4
    src_wgt_format = (params0[0] >>= 4) & 0b1111;    // 4
    pproc_y_elw_format = (params0[0] >>= 4) & 0b111; // 3
    src_act_k = (params0[0] >>= 3) & 0x3FFFFFF;      // 26
    dst_box_channel = (params0[0] >>= 26) & 0xFFFF;  // 16
    dst_box_width = (params0[1] >>= 0) & 0xFFFF;     // 16
    dst_box_height = (params0[1] >>= 16) & 0xFFFF;   // 16
  }

  ~pproc_datatype_conv() override {
    if (raw_cmd != nullptr) {
      free(raw_cmd);
      raw_cmd = nullptr;
    }
  }
};

struct pproc_tile_mask {
  // mask 用于硬件16*8tile验证,simulator推理中不使用
  explicit pproc_tile_mask(){};
  explicit pproc_tile_mask(uint64_t params0) { decode(params0); };

  uint8_t oc_mask;
  uint16_t wh_mask;

  void decode(uint64_t params0) {
    oc_mask = params0 & 0xff;
    wh_mask = (params0 >>= 8) & 0xFFFF;
  }

  static pproc_tile_mask *generate(uint64_t params0) {
    return new pproc_tile_mask(params0);
  }
};
} // namespace operators

#endif