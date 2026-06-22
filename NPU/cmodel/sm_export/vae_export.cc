#include "cmodel.h"
#include "vae_common.h"

// src->matrix[H,W]
// result->matrix[H,W]
void vae_elementwise(uint16_t *result, const uint16_t *src_dataA,
                     const uint16_t *src_dataB, int row, int col,
                     DataType i_type, DataType o_type, int model) {
  return operators::vae_elementwise(result, src_dataA, src_dataB, row, col,
                                    i_type, o_type, model);
}
void vae_pertensorInt16(uint16_t *outData, uint16_t *src_data, uint24_t scale,
                        uint32_t src_row, uint32_t src_col, DataType i_type,
                        DataType o_type) {
  return operators::vae_pertensorInt16(outData, src_data, scale, src_row,
                                       src_col, i_type, o_type);
}
void vae_softmax_online(uint16_t *softmax_result, const uint16_t *src_data,
                        const uint16_t *src_mask, uint32_t src_row,
                        uint32_t src_col, DataType i_type, DataType o_type,
                        uint32_t blockStep, float24_t paddingValue,
                        uint32_t scaleFlag, float16_t scale, uint32_t maskFlag,
                        float16_t mask_value0) {
  return operators::vae_softmax_online(
      softmax_result, src_data, src_mask, src_row, src_col, i_type, o_type,
      blockStep, paddingValue, scaleFlag, scale, maskFlag, mask_value0);
}

void vae_softmax_fa1(uint16_t *softmax_result, const uint16_t *src_data,
                     const uint16_t *src_mask, int maskFlag,
                     float16_t mask_value0, int src_row, int src_col,
                     DataType i_type, DataType o_type, int bypassQuant,
                     int blockStep, float24_t paddingValue,
                     uint8_t *quant_outResult, int scaleFlag, float16_t scale,
                     uint16_t *out_EMRFIFO, uint32_t *pre_sum_blk_input,
                     uint32_t *pre_sum_blk_output, uint16_t *pre_max_input,
                     uint16_t *pre_max_output, uint16_t *scaleBuffer,
                     float16_t scaleFactor) {
  return operators::vae_softmax_fa1(
      softmax_result, src_data, src_mask, maskFlag, mask_value0, src_row,
      src_col, i_type, o_type, bypassQuant, blockStep, paddingValue,
      quant_outResult, scaleFlag, scale, out_EMRFIFO, pre_sum_blk_input,
      pre_sum_blk_output, pre_max_input, pre_max_output, scaleBuffer,
      scaleFactor);
}

void softmax_fa2(uint24_t *ObufferOut, const uint16_t *exp_data,
                 const uint24_t *OSRAM, const uint16_t *pv_ibuffer, int src_col,
                 int src_row, int blockStep, int o_type, int i_type) {
  return operators::softmax_fa2(ObufferOut, exp_data, OSRAM, pv_ibuffer,
                                src_col, src_row, blockStep, o_type, i_type);
}

void softmax_fa3(uint16_t *result, const uint32_t *diag,
                 const uint24_t *Obuffer, int src_col, int src_row,
                 int blockStep, int o_type, int i_type) {
  return operators::softmax_fa3(result, diag, Obuffer, src_col, src_row,
                                blockStep, o_type, i_type);
}

void vae_perToken_k(uint8_t *result, const uint16_t *src_data,
                    uint16_t *ret_scale, uint16_t *k_mean, int src_row,
                    int src_col, float16_t scaleFactor, DataType i_type,
                    DataType o_type) {
  return operators::vae_perToken_k(result, src_data, ret_scale, k_mean, src_row,
                                   src_col, scaleFactor, i_type, o_type);
}
void vae_quant_perToken(uint8_t *oBuffer, uint16_t *src_data, uint16_t *kMean,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type, DataType o_type,
                        uint32_t kMeanBypass) {
  return operators::vae_quant_perToken(oBuffer, src_data, kMean, scaleBuffer,
                                       src_row, src_col, scaleFactor, i_type,
                                       o_type, kMeanBypass);
}
void vae_quant_NVFP4(uint8_t *oBuffer, uint16_t *src_data, uint8_t *scaleBuffer,
                     int src_row, int src_col, uint32_t globalScale,
                     DataType i_type, DataType o_type) {
  return operators::vae_quant_NVFP4(oBuffer, src_data, scaleBuffer, src_row,
                                    src_col, globalScale, i_type, o_type);
}
void vae_quant_perTensor(uint8_t *oBuffer, uint16_t *src_data,
                         uint16_t *scaleBuffer, int src_row, int src_col,
                         float16_t scaleFactor, DataType i_type,
                         DataType o_type) {
  return operators::vae_quant_perTensor(oBuffer, src_data, scaleBuffer, src_row,
                                        src_col, scaleFactor, i_type, o_type);
}
void vae_quant_perGroup(uint8_t *oBuffer, uint16_t *src_data,
                        uint16_t *scaleBuffer, int src_row, int src_col,
                        float16_t scaleFactor, DataType i_type,
                        DataType o_type) {
  return operators::vae_quant_perGroup(oBuffer, src_data, scaleBuffer, src_row,
                                       src_col, scaleFactor, i_type, o_type);
}
void vae_quant(uint8_t *result, uint16_t *src_data, uint16_t *ret_scale,
               int src_row, int src_col, float16_t scaleFactor, DataType i_type,
               DataType o_type) {
  return operators::vae_quant(result, src_data, ret_scale, src_row, src_col,
                              scaleFactor, i_type, o_type);
}

float24_t add2(float24_t *src_data, int src_col, float24_t paddingVlaue) {
  return operators::add2(src_data, src_col, paddingVlaue);
}

void vae_rmsnorm(uint16_t *rms_result, const uint16_t *src_data,
                 const uint16_t *src_gamma, int src_row, int src_col,
                 DataType i_type, DataType o_type, uint32_t eps,
                 float24_t padding_value, int blockStep, float32_t rcp_col,
                 int flagGamma) {
  return operators::vae_rmsnorm(rms_result, src_data, src_gamma, src_row,
                                src_col, i_type, o_type, eps, padding_value,
                                blockStep, rcp_col, flagGamma);
}

void vae_layernorm(uint16_t *laynorm_result, const uint16_t *src_data,
                   const uint16_t *gamma, const uint16_t *bias, int src_row,
                   int src_col, DataType i_type, DataType o_type, int blockStep,
                   uint32_t dimk_rec, uint32_t dimk_mod128_rec_dimk,
                   float24_t dimk_mod128_rec, uint32_t eps,
                   float24_t paddingVlaue, int flagBiasGamma) {
  return operators::vae_layernorm(
      laynorm_result, src_data, gamma, bias, src_row, src_col, i_type, o_type,
      blockStep, dimk_rec, dimk_mod128_rec_dimk, dimk_mod128_rec, eps,
      paddingVlaue, flagBiasGamma);
}

void rope(uint16_t *rope_outResult, const uint16_t *src_data, const uint16_t *q,
          uint16_t *k_mean, int src_row, int src_col, int blockStep,
          DataType i_type, DataType o_type, float24_t padding_value,
          float16_t scaleFactor, uint8_t *quant_outResult, int byPassFlag,
          uint16_t *ret_scale) {
  return operators::rope(rope_outResult, src_data, q, k_mean, src_row, src_col,
                         blockStep, i_type, o_type, padding_value, scaleFactor,
                         quant_outResult, byPassFlag, ret_scale);
}

int maxPowerOfTwo(int n) { return operators::maxPowerOfTwo(n); }

void vae_mask(uint16_t *result, const uint16_t *src_data,
              const uint16_t *src_mask, int row, int col,
              float16_t mask_value0) {
  return operators::vae_mask(result, src_data, src_mask, row, col, mask_value0);
}
void vae_quant_perGroup_mxfp4_mxfp8(uint8_t *oBuffer, uint16_t *src_data,
                                    uint8_t *scaleBuffer, int src_row,
                                    int src_col, DataType i_type,
                                    DataType o_type, uint16_t mxfp4_fp8_flag) {
  return operators::vae_quant_perGroup_mxfp4_mxfp8(
      oBuffer, src_data, scaleBuffer, src_row, src_col, i_type, o_type,
      mxfp4_fp8_flag);
}
void reduce_max(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step) {
  return operators::reduce_max(ret, src_data, src_row, src_col, i_type, o_type,
                               block_step);
}

void reduce_min(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int block_step) {
  return operators::reduce_min(ret, src_data, src_row, src_col, i_type, o_type,
                               block_step);
}

void reduce_argmax(uint32_t *ret, const uint16_t *src_data, int src_row,
                   int src_col, DataType i_type, DataType o_type,
                   int block_step) {
  return operators::reduce_argmax(ret, src_data, src_row, src_col, i_type,
                                  o_type, block_step);
}

void reduce_avg_mean(uint16_t *ret, const uint16_t *src_data, int src_row,
                     int src_col, DataType i_type, DataType o_type,
                     int blockStep, float24_t paddingValue, uint32_t dimk_rec,
                     uint32_t dimk_mod128_rec_dimk, float24_t dimk_mod128_rec) {
  return operators::reduce_avg_mean(ret, src_data, src_row, src_col, i_type,
                                    o_type, blockStep, paddingValue, dimk_rec,
                                    dimk_mod128_rec_dimk, dimk_mod128_rec);
}

void reduce_add(uint16_t *ret, const uint16_t *src_data, int src_row,
                int src_col, DataType i_type, DataType o_type, int blockStep,
                float24_t paddingValue) {
  return operators::reduce_add(ret, src_data, src_row, src_col, i_type, o_type,
                               blockStep, paddingValue);
}

void reduce_add32(uint16_t *ret, const uint16_t *src_data, int src_row,
                  int src_col, DataType i_type, DataType o_type, int blockStep,
                  float24_t paddingValue) {
  return operators::reduce_add32(ret, src_data, src_row, src_col, i_type,
                                 o_type, blockStep, paddingValue);
}
void reduce_top2(uint32_t *ret, uint32_t *retAll, const uint16_t *src_data,
                 uint16_t *outData, int src_row, int src_col, DataType i_type,
                 DataType o_type, int blockStep) {
  return operators::reduce_top2(ret, retAll, src_data, outData, src_row,
                                src_col, i_type, o_type, blockStep);
}