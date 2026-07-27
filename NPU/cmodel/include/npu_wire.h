#ifndef NPU_WIRE_H
#define NPU_WIRE_H

#include "npu_cmodel.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_WIRE_CMD_BYTES 16u
#define NPU_WIRE_CONTROL_DESC_BYTES 64u
#define NPU_WIRE_DMA_DESC_BYTES 256u
#define NPU_WIRE_MATRIX_DESC_BYTES 256u
#define NPU_WIRE_VECTOR_DESC_BYTES 192u
#define NPU_WIRE_COMPLEX_DESC_BYTES 256u

#define NPU_WIRE_DEFAULT_DESC_VERSION 1u
#define NPU_WIRE_HEADER_VERSION 1u
/*
 * Address limits are exclusive. The reference C model uses physical byte
 * offsets from zero for both L1 and DDR storage.
 */
typedef struct {
    uint32_t l1_bytes;
    uint64_t gaddr_limit;
    uint64_t gaddr_base[6];
    uint16_t dma_max_burst_beats;
    uint8_t dma_max_outstanding;
    uint8_t mt;
    uint8_t kt;
    uint8_t nt;
    uint16_t cme_scratch_elems;
    uint8_t desc_version;
} npu_wire_limits_t;

/*
 * These fields exist on the wire but are not currently present in
 * npu_task_request_t.  Keeping them here prevents the decoder from silently
 * discarding information needed by P0 execution or strict validation.
 */
typedef struct {
    /*
     * Valid only when decode returns NPU_STATUS_ADDR_FAULT. fault_addr is
     * the first byte outside the selected address range or declared region.
     */
    uint8_t fault_valid;
    npu_space_t fault_space;
    uint64_t fault_addr;

    uint8_t desc_version;
    uint8_t desc_type;
    uint16_t desc_bytes;
    uint32_t op_flags;
    uint32_t numeric_cfg;

    uint8_t allow_inplace;
    uint8_t allow_partial_dest;
    uint8_t saturate_enable;
    uint8_t scale_mode;
    uint8_t zero_point_enable;
    uint8_t internal_fp32_enable;

    uint8_t control_join_mode;
    uint8_t control_engine_mask;

    uint16_t dma_burst_beats;

    uint32_t matrix_last_tile_valid_m;
    uint32_t matrix_last_tile_valid_n;
    uint32_t matrix_last_tile_valid_k;
    uint8_t matrix_a_pack_format;
    uint8_t matrix_b_pack_format;
    uint8_t matrix_c_pack_format;
    uint8_t matrix_pack_version;
    uint8_t matrix_activation_mode;
    uint8_t matrix_requant_mode;
    uint8_t matrix_residual_mode;
    uint8_t matrix_requant_entry_bytes;

    uint8_t cme_approx_mode;
    uint8_t cme_stats_mode;
    uint64_t cme_src0_scale_table_addr;
    uint64_t cme_dst_scale_table_addr;
} npu_wire_meta_t;

void npu_wire_limits_reference(npu_wire_limits_t *limits);

size_t npu_wire_descriptor_bytes(npu_engine_t engine);

npu_status_t npu_wire_decode_cmd(const uint8_t *wire,
                                 size_t wire_bytes,
                                 const npu_wire_limits_t *limits,
                                 npu_cmd_t *cmd);

/*
 * Extended command decoder that reports an invalid Descriptor address span
 * through meta. The original decoder remains as a compatibility wrapper.
 */
npu_status_t npu_wire_decode_cmd_with_meta(
    const uint8_t *wire,
    size_t wire_bytes,
    const npu_wire_limits_t *limits,
    npu_cmd_t *cmd,
    npu_wire_meta_t *meta);

/*
 * Checks the full Descriptor span of an already decoded command. meta is
 * cleared on entry and carries the first invalid GADDR byte on failure.
 */
npu_status_t npu_wire_validate_cmd_address(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta);

npu_status_t npu_wire_decode_descriptor(const npu_cmd_t *cmd,
                                        const uint8_t *wire,
                                        size_t wire_bytes,
                                        const npu_wire_limits_t *limits,
                                        npu_task_request_t *request,
                                        npu_wire_meta_t *meta);

npu_status_t npu_wire_decode_task(const uint8_t *cmd_wire,
                                  size_t cmd_wire_bytes,
                                  const uint8_t *desc_wire,
                                  size_t desc_wire_bytes,
                                  const npu_wire_limits_t *limits,
                                  npu_task_request_t *request,
                                  npu_wire_meta_t *meta);

#ifdef __cplusplus
}
#endif

#endif
