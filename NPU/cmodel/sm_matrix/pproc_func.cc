#include "pproc_func.h"
#include <functional>

namespace operators {
void pproc_base_stream_alpha(uint16_t *params, pproc_en_mode &en_mode,
                             pproc_datatype &data_info, pproc_tile_mask &mask,
                             uint64_t **res, uint16_t **elw, uint32_t **des,
                             uint32_t row, uint32_t column) {
  std::function<fp_general_t(fp_general_t)> data_convert_in;
  std::function<fp_general_t(fp_general_t)> data_convert_out;
  std::function<fp_general_t(fp_general_t)> data_convert_elw;
  std::function<fp_general_t(fp_general_t)> data_convert_param;
  std::function<fp_general_t(fp_general_t)> data_convert_param_xscale;
  bool intype_tag = true; // int40
  // 根据quant方式，决定param的存储方式，设计对应tag等
  bool perchn_en[] = {(en_mode.pproc_x_scale_en_per_chn |
                       en_mode.pproc_x_scale_pertok), // new for moe mode
                      en_mode.pproc_x_bias_en_per_chn,
                      en_mode.pproc_y_elw_scale_en_per_chn,
                      en_mode.pproc_y_elw_bias_en_per_chn,
                      en_mode.pproc_y_relu_scale_en_per_chn,
                      en_mode.pproc_c_scale_en_per_chn,
                      en_mode.pproc_c_bias_en_per_chn};
  bool switch_en[] = {
      // new
      en_mode.pproc_x_scale_en,      en_mode.pproc_x_bias_en,
      en_mode.pproc_y_elw_scale_en,  en_mode.pproc_y_elw_bias_en,
      en_mode.pproc_y_relu_scale_en, en_mode.pproc_c_scale_en,
      en_mode.pproc_c_bias_en};

  int perchn_tag[] = {-1, -1, -1, -1, -1, -1, -1};
  int chn_tag = 0;
  size_t perchn_addr = 256;
  for (int i = 0; i < sizeof(perchn_en); i++) {
    // if (perchn_en[i]) {
    if (perchn_en[i] && switch_en[i]) {
      perchn_tag[i] = chn_tag;
      chn_tag++;
    }
  }
  // chn_tag++;

  switch (data_info.src_wgt_format) {
  case 0:
  case 1:
  case 2:
    break;
  default:
    intype_tag = false;
    break;
  }

  switch (data_info.src_act_format) {
  case 0:
  case 1:
  case 2:
  case 3:
    break;
  default:
    intype_tag = false;
    break;
  }

  switch (en_mode.pproc_param_format) {
  case 0:
    data_convert_param = [](fp_general_t a) { return fp16_to_fp24(a); };
    data_convert_param_xscale = [](fp_general_t a) { return fp16_to_fp32(a); };
    break;
  case 1:
    data_convert_param = [](fp_general_t a) { return bf16_to_fp24(a); };
    data_convert_param_xscale = [](fp_general_t a) { return bf16_to_fp32(a); };
    break;
  case 2:
    data_convert_param = [](fp_general_t a) { return fp32_to_fp24(a); };
    data_convert_param_xscale = [](fp_general_t a) { return fp32_to_fp32(a); };
    break;
  default:
    data_convert_param = [](fp_general_t a) { return fp32_to_fp24(a); };
    data_convert_param_xscale = [](fp_general_t a) { return fp32_to_fp32(a); };
    break;
  }

  switch (data_info.dst_format) {
  case 0:
    data_convert_out = [](fp_general_t a) { return f24_to_i8(a); };
    break;
  case 1:
    data_convert_out = [](fp_general_t a) { return f24_to_u8(a); };
    break;
  case 2:
    data_convert_out = [](fp_general_t a) { return f24_to_i16(a); };
    break;
  case 3:
    data_convert_out = [](fp_general_t a) { return f24_to_u16(a); };
    break;
  case 4:
    data_convert_out = [](fp_general_t a) { return fp24_to_fp16(a); };
    break;
  case 5:
    data_convert_out = [](fp_general_t a) { return fp24_to_bf16(a); };
    break;
  case 6:
    data_convert_out = [](fp_general_t a) { return fp24_to_fp32(a); };
    break;
  default:
    data_convert_out = [](fp_general_t a) { return fp24_to_fp32(a); };
    break;
  }

  switch (data_info.pproc_y_elw_format) {
  case 0:
    data_convert_elw = [](fp_general_t a) { return u8_to_f24(a); };
    break;
  case 1:
    data_convert_elw = [](fp_general_t a) { return i8_to_f24(a); };
    break;
  case 2:
    data_convert_elw = [](fp_general_t a) { return i16_to_f24(a); };
    break;
  case 3:
    data_convert_elw = [](fp_general_t a) { return u16_to_f24(a); };
    break;
  case 4:
    data_convert_elw = [](fp_general_t a) { return fp16_to_fp24(a); };
    break;
  case 5:
    data_convert_elw = [](fp_general_t a) { return bf16_to_fp24(a); };
    break;
  case 6:
  case 7:
    data_convert_elw = [](fp_general_t a) { return (fp8e4_to_fp32(a) >> 8); };
    break;
  default:
    break;
  }

  uint64_t result;
  uint64_t swish_x;
  int current_param_baseaddr = 0;
  uint32_t param_temp;
  // bool beta_swish_en = en_mode.pproc_x_scale_en && (!en_mode.pproc_x_bias_en)
  // &&
  //                      en_mode.pproc_y_sfu_en && en_mode.pproc_y_scale_en;
  bool beta_swish_en =
      en_mode.pproc_x_scale_en && (!en_mode.pproc_x_bias_en) && // 1024
      en_mode.pproc_y_sfu_en && en_mode.pproc_y_scale_en &&
      (!en_mode.pproc_x_scale_pertok) && (en_mode.pproc_param_format != 2);
  for (uint32_t i = 0; i < row; i++) {
    // mask 用于硬件16*8tile验证,simulator推理中不使用
    if (mask.wh_mask >> i)
      continue;
    for (uint32_t j = 0; j < column; j++) {
      // param(j,n)=j/32*(32*chn_tag)+32*n+j%32+base_addr
      current_param_baseaddr = (j / 32) * (32 * chn_tag) + j % 32 + perchn_addr;
      if (mask.oc_mask >> j)
        continue;
      /*================ pp_pproc_en=0 =====================*/
      if (!en_mode.pp_pproc_en) {
        // cout << hex << res[i][j] << " ";
        result = res[i][j];
        if (intype_tag) {
          result = int40_to_fp32(res[i][j]);
        }
        if (data_info.dst_format == 6) {
          des[i][j] = result;
        } else {
          des[i][j] = fp32_to_bf16(result);
        }

        continue;
      }

      uint64_t elw_temp = 0;
      result = res[i][j];
      if (intype_tag) {
        result = int40_to_fp32(res[i][j]);
      }
      //  qk 模式就是双scale，只进行两次scale
      if (en_mode.qk_quant_en && en_mode.pproc_x_scale_en &&
          en_mode.pproc_x_bias_en && en_mode.pproc_x_scale_en_per_chn &&
          en_mode.pproc_x_bias_en_per_chn) {
        // K^T dequant ：x_scale mul
        param_temp = data_convert_param(params[j]); // n:column low 256B
        result = fp32fp24mul(result, param_temp);
        // Q dequant ：x_bias mul
        param_temp = data_convert_param(params[128 + i]); // m:row high 256B
        result = fp24mul(result, param_temp);
        result = data_convert_out(result);
        des[i][j] = result;
        continue;
      }

      // add PV mode
      if (en_mode.qk_quant_en && en_mode.pproc_x_scale_en &&
          en_mode.pproc_x_bias_en && !en_mode.pproc_x_scale_en_per_chn &&
          !en_mode.pproc_x_bias_en_per_chn) {
        param_temp = data_convert_param(params[0]);
        result = fp32fp24mul(result, param_temp);
        param_temp = data_convert_param(params[128]);
        result = fp24mul(result, param_temp);
        result = data_convert_out(result);
        des[i][j] = result;
        continue;
      }

      // dequant,
      //-------------x_scale-------------//
      swish_x = fp32_to_fp24(result);
      if (en_mode.pproc_x_scale_en) {
        if (en_mode.pproc_x_scale_en_per_chn) // per chn
          param_temp = data_convert_param_xscale(
              params[current_param_baseaddr + perchn_tag[0] * 32]);
        else if (en_mode.pproc_x_scale_pertok) { // per tok
          param_temp = data_convert_param_xscale(
              params[(i / 32) * (32 * chn_tag) + i % 32 + perchn_addr]);
        } else {
          // nvfp4
          if (en_mode.pproc_param_format == 2) {
            param_temp = *(uint32_t *)params;
          } else {
            param_temp = data_convert_param_xscale(params[0]); // tof32
          }
        }
        // f32*f32=f24
        result = fp32mul_resfp24(result, param_temp);
      } else {
        result = fp32_to_fp24(result);
      }
      //-------------x_bias-------------//
      if (en_mode.pproc_x_bias_en) {
        if (en_mode.pproc_x_bias_en_per_chn)
          param_temp = data_convert_param(
              params[current_param_baseaddr + perchn_tag[1] * 32]);
        else                                     // pertensor
          if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
            param_temp = read_param_32to24(params, 1 * 2);
          } else { // normal pertensor
            param_temp = data_convert_param(params[1]);
          }
        result = fp24add(result, param_temp);
      }

      //-------------y_relu----------------//
      if (en_mode.pproc_y_relu_en) {
        switch (en_mode.y_relu_op) {
        case relu:
          result = fp24max(result, 0);
          break;
        case relu6:
          result = fp24min(fp24max(result, 0), 0x40c000);
          break;
        default:
          break;
        }
      }

      // sfu
      uint64_t temp_relu_value =
          result; // 需要转换成fp32 ;temp_relu_value =beta*x
      uint64_t swish_beta_temp;
      if (beta_swish_en) {
        swish_beta_temp = swish_x;
      } else {
        swish_beta_temp = result;
      }

      if (en_mode.pproc_y_sfu_en) {
        result = fp24_to_fp32(result);
        switch (en_mode.y_sfu_op) {
        case sigmoid:
          /*
            if (beta_swish_en) {
              if (en_mode.pproc_x_scale_en_per_chn)
                param_temp = data_convert_param(
                    params[current_param_baseaddr + perchn_tag[0] * 32]);
              else
                param_temp = data_convert_param(params[0]);
              result = fp32fp24mul(result, param_temp);
            }*/
          result = sfu_sigmoid(result);
          break;
        case tanh:
          result = sfu_tanh(result);
          break;
        default:
          break;
        }
        result = fp32_to_fp24(result);
      }

      // swish
      if (en_mode.pproc_y_scale_en) {
        // result = fp24mul(temp_relu_value, result);
        result = fp24mul(swish_beta_temp, result);
      }

      // leakyrelu,prelu
      if (en_mode.pproc_y_relu_en) {
        switch (en_mode.y_relu_op) {
        case leakrelu:
        case prelu:
          if (temp_relu_value & (1 << 23) &&
              en_mode.pproc_y_relu_scale_en) // 如果result为负
          {
            if (en_mode.pproc_y_relu_scale_en_per_chn)
              param_temp = data_convert_param(
                  params[current_param_baseaddr + perchn_tag[4] * 32]);
            else                                     // pertensor
              if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
                param_temp = read_param_32to24(params, 2 * 4);
              } else { // normal pertensor
                param_temp = data_convert_param(params[4]);
              }
            result = fp24mul(temp_relu_value, param_temp);
          }
          break;
        default:
          break;
        }
      }
      // elw dequant
      if (en_mode.pp_elw_en && en_mode.elw_op) {
        elw_temp = data_convert_elw(elw[i][j]);
      }

      if (en_mode.pproc_y_elw_scale_en) {
        if (en_mode.pproc_y_elw_scale_en_per_chn)
          param_temp = data_convert_param(
              params[current_param_baseaddr + perchn_tag[2] * 32]);
        // else
        //   param_temp = data_convert_param(params[2]);
        else                                     // pertensor
          if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
            param_temp = read_param_32to24(params, 2 * 2);
          } else { // normal pertensor
            param_temp = data_convert_param(params[2]);
          }
        elw_temp = fp24mul(elw_temp, param_temp);
      }
      if (en_mode.pproc_y_elw_bias_en) {
        if (en_mode.pproc_y_elw_bias_en_per_chn)
          param_temp = data_convert_param(
              params[current_param_baseaddr + perchn_tag[3] * 32]);
        // else
        //   param_temp = data_convert_param(params[3]);
        else                                     // pertensor
          if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
            param_temp = read_param_32to24(params, 2 * 3);
          } else { // normal pertensor
            param_temp = data_convert_param(params[3]);
          }
        elw_temp = fp24add(elw_temp, param_temp);
      }
      // elw
      if (en_mode.pp_elw_en) {
        switch (en_mode.elw_op) { // mul = 1, add = 2, sub = 3
        case mul:
          result = fp24mul(result, elw_temp);
          break;
        case add:
          result = fp24add(result, elw_temp);
          break;
        case sub:
          result = fp24sub(result, elw_temp);
          break;
        default:
          break;
        }
      }

      // requant
      if (en_mode.pproc_c_scale_en) {
        if (en_mode.pproc_c_scale_en_per_chn)
          param_temp = data_convert_param(
              params[current_param_baseaddr + perchn_tag[5] * 32]);
        // else
        //   param_temp = data_convert_param(params[5]);
        else                                     // pertensor
          if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
            param_temp = read_param_32to24(params, 2 * 5);
          } else { // normal pertensor
            param_temp = data_convert_param(params[5]);
          }
        result = fp24mul(result, param_temp);
      }
      if (en_mode.pproc_c_bias_en) {
        if (en_mode.pproc_c_bias_en_per_chn)
          param_temp = data_convert_param(
              params[current_param_baseaddr + perchn_tag[6] * 32]);
        // else
        //   param_temp = data_convert_param(params[6]);
        else                                     // pertensor
          if (en_mode.pproc_param_format == 2) { // 32bit param pertensor
            param_temp = read_param_32to24(params, 2 * 6);
          } else { // normal pertensor
            param_temp = data_convert_param(params[6]);
          }
        result = fp24add(result, param_temp);
      }
      result = data_convert_out(result);
      des[i][j] = (uint32_t)result;
      // if (i == 0)
      // cout << " i:" << i << " j:" << j << " " << hex << des[i][j];
    }
    // cout << endl;
  }
}

pproc_en_mode *pproc_en_mode::generate(uint64_t params0) {
  if (params0 & 1)
    return new pproc_en_mode_conv(params0);
  else
    return new pproc_en_mode_matmul(params0);
}

pproc_datatype *pproc_datatype::generate(uint64_t *params0) {
  if (params0[0] & 1)
    return new pproc_datatype_conv(params0);
  else
    return new pproc_datatype_matmul(params0);
}
} // namespace operators
