#include "npu_axi_mem_target_cycle.h"
#include "npu_single_core_cycle.h"
#include "test_util.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#ifdef NPU_SINGLE_CORE_AXI_TARGET_STANDALONE
#include <stdio.h>
#endif

#define SCAT_DDR_BYTES (1024u * 1024u)
#define SCAT_TRACE_ENTRIES 64u
#define SCAT_TRACE_HASH 128u
#define SCAT_MAX_CYCLES 30000u

#define SCAT_DESC_VADDR UINT64_C(0x00002000)
#define SCAT_DESC_PADDR UINT64_C(0x00008000)
#define SCAT_DMA_DESC_VADDR UINT64_C(0x00003000)
#define SCAT_DMA_DESC_PADDR UINT64_C(0x0000a000)
#define SCAT_GC_ADDR UINT64_C(0x00009040)
#define SCAT_SRC0 0x00000100u
#define SCAT_SRC1 0x00000180u
#define SCAT_DST 0x00000200u
#define SCAT_DMA_L1_DST 0x00000300u
#define SCAT_DMA_L1_SRC 0x00000380u
#define SCAT_DMA_DDR_SRC UINT64_C(0x00010000)
#define SCAT_DMA_DDR_DST UINT64_C(0x00011000)
#define SCAT_DMA_BYTES 32u
#define SCAT_DMA_GUARD_BYTES 8u
#define SCAT_AXI_LOG_ENTRIES 32u
#define SCAT_COMMAND_ID UINT16_C(0x581)
#define SCAT_DMA_READ_COMMAND_ID UINT16_C(0x582)
#define SCAT_DMA_WRITE_COMMAND_ID UINT16_C(0x583)
#define SCAT_RESET_COMMAND_ID UINT16_C(0x584)

#define SCAT_CALL(expression)                  \
    do {                                      \
        int scat_line = (expression);         \
        if (scat_line != 0) {                 \
            return scat_line;                 \
        }                                     \
    } while (0)

typedef struct {
    uint8_t l1[NPU_L1_CYCLE_BYTES];
    uint8_t l1_ecc[NPU_L1_CYCLE_WORDS];
    uint8_t ddr[SCAT_DDR_BYTES];

    npu_bus_trace_entry_t
        read_entry[NPU_TS_ENGINE_COUNT][SCAT_TRACE_ENTRIES];
    npu_bus_trace_entry_t
        write_entry[NPU_TS_ENGINE_COUNT][SCAT_TRACE_ENTRIES];
    uint32_t
        read_hash[NPU_TS_ENGINE_COUNT][SCAT_TRACE_HASH];
    uint32_t
        write_hash[NPU_TS_ENGINE_COUNT][SCAT_TRACE_HASH];
    npu_engine_data_workspace_t workspace[NPU_TS_ENGINE_COUNT];

    npu_model_t functional;
    npu_single_core_cycle_t top;
    npu_axi_mem_target_cycle_t gc_target;
    npu_axi_mem_target_cycle_t mif_target;

    npu_gc_axi_bus_outputs_t last_gc_master;
    npu_mif_axi_outputs_t last_mif_master;

    uint8_t core_rst_ni;
    uint8_t noc_rst_ni;
    uint8_t gc_target_reset_n;
    uint8_t mif_target_reset_n;
    uint64_t core_ticks;
    uint64_t noc_ticks;

    uint32_t gc_ar_handshakes;
    uint32_t gc_r_handshakes;
    uint32_t mif_ar_handshakes;
    uint32_t mif_r_handshakes;
    uint32_t mif_r_last_handshakes;
    uint32_t mif_aw_handshakes;
    uint32_t mif_w_handshakes;
    uint32_t mif_b_handshakes;
    uint32_t tbu_req_handshakes;
    uint32_t tbu_rsp_handshakes;
    uint64_t mif_ar_addr[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_ar_len[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_ar_size[SCAT_AXI_LOG_ENTRIES];
    uint64_t mif_aw_addr[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_aw_len[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_aw_size[SCAT_AXI_LOG_ENTRIES];
    uint64_t mif_w_data[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_w_strb[SCAT_AXI_LOG_ENTRIES];
    uint8_t mif_w_last[SCAT_AXI_LOG_ENTRIES];
    uint64_t tbu_req_vaddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t tbu_req_write[SCAT_AXI_LOG_ENTRIES];
    uint64_t tbu_rsp_paddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t tbu_rsp_status[SCAT_AXI_LOG_ENTRIES];
    uint32_t dfu_core_req_handshakes;
    uint32_t dfu_noc_req_handshakes;
    uint64_t dfu_core_req_vaddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t dfu_core_req_beats[SCAT_AXI_LOG_ENTRIES];
    uint64_t dfu_noc_req_vaddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t dfu_noc_req_beats[SCAT_AXI_LOG_ENTRIES];

    uint32_t dma_core_read_req_handshakes;
    uint32_t dma_core_write_req_handshakes;
    uint32_t dma_core_w_handshakes;
    uint32_t dma_core_read_rsp_handshakes;
    uint32_t dma_core_write_rsp_handshakes;
    uint32_t dma_noc_read_req_handshakes;
    uint32_t dma_noc_write_req_handshakes;
    uint32_t dma_noc_w_handshakes;
    uint32_t dma_noc_read_rsp_handshakes;
    uint32_t dma_noc_write_rsp_handshakes;
    uint32_t dma_l1_read_req_handshakes;
    uint32_t dma_l1_read_rsp_handshakes;
    uint32_t dma_l1_write_req_handshakes;
    uint32_t dma_l1_write_data_handshakes;
    uint32_t dma_l1_write_rsp_handshakes;
    uint64_t dma_core_req_vaddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t dma_core_req_beats[SCAT_AXI_LOG_ENTRIES];
    uint8_t dma_core_req_write[SCAT_AXI_LOG_ENTRIES];
    uint64_t dma_noc_req_vaddr[SCAT_AXI_LOG_ENTRIES];
    uint8_t dma_noc_req_beats[SCAT_AXI_LOG_ENTRIES];
    uint8_t dma_noc_req_write[SCAT_AXI_LOG_ENTRIES];
} scat_env_t;

typedef struct {
    uint32_t mif_ar;
    uint32_t mif_r;
    uint32_t mif_r_last;
    uint32_t mif_aw;
    uint32_t mif_w;
    uint32_t mif_b;
    uint32_t tbu_req;
    uint32_t tbu_rsp;
    uint32_t dfu_core_req;
    uint32_t dfu_noc_req;

    uint32_t dma_core_read_req;
    uint32_t dma_core_write_req;
    uint32_t dma_core_w;
    uint32_t dma_core_read_rsp;
    uint32_t dma_core_write_rsp;
    uint32_t dma_noc_read_req;
    uint32_t dma_noc_write_req;
    uint32_t dma_noc_w;
    uint32_t dma_noc_read_rsp;
    uint32_t dma_noc_write_rsp;
    uint32_t dma_l1_read_req;
    uint32_t dma_l1_read_rsp;
    uint32_t dma_l1_write_req;
    uint32_t dma_l1_write_data;
    uint32_t dma_l1_write_rsp;
} scat_observation_t;

static scat_env_t scat_env;

static void scat_put_u16(uint8_t *data,
                         size_t offset,
                         uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8u);
}

static void scat_put_u32(uint8_t *data,
                         size_t offset,
                         uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void scat_put_u64(uint8_t *data,
                         size_t offset,
                         uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t scat_get_u64(const uint8_t *data,
                             size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        value |= (uint64_t)data[offset + byte]
                 << (byte * 8u);
    }
    return value;
}

static uint32_t scat_numeric(void)
{
    return (uint32_t)NPU_DTYPE_INT8 |
           ((uint32_t)NPU_DTYPE_INT8 << 2u) |
           ((uint32_t)NPU_DTYPE_INT8 << 6u) |
           ((uint32_t)NPU_ROUND_NEAREST_EVEN << 10u) |
           (UINT32_C(1) << 12u) |
           ((uint32_t)NPU_SCALE_PER_TENSOR << 13u);
}

static void scat_make_vector_descriptor(uint8_t *descriptor)
{
    (void)memset(
        descriptor, 0, NPU_WIRE_VECTOR_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_VECTOR;
    scat_put_u16(
        descriptor, 0x02u, NPU_WIRE_VECTOR_DESC_BYTES);
    scat_put_u64(descriptor, 0x08u, SCAT_SRC0);
    scat_put_u64(descriptor, 0x10u, SCAT_SRC1);
    scat_put_u64(descriptor, 0x20u, SCAT_DST);
    scat_put_u32(descriptor, 0x38u, scat_numeric());
    scat_put_u32(descriptor, 0x3cu, 0x53434f52u);
    scat_put_u32(descriptor, 0x40u, 1u);
    scat_put_u32(descriptor, 0x44u, 16u);
    scat_put_u32(descriptor, 0x48u, 16u);
    scat_put_u32(descriptor, 0x50u, 1u);
    scat_put_u32(descriptor, 0x54u, 16u);
    scat_put_u32(descriptor, 0x58u, 1u);
    scat_put_u32(descriptor, 0x5cu, 16u);
    scat_put_u32(descriptor, 0x68u, 1u);
    scat_put_u32(descriptor, 0x6cu, 16u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    descriptor[0x7bu] = 0u;
    scat_put_u32(descriptor, 0x80u, 0x3f800000u);
    scat_put_u32(descriptor, 0x84u, 0x3f800000u);
    scat_put_u32(descriptor, 0x88u, 0u);
    scat_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void scat_make_dma_descriptor(
    uint8_t *descriptor,
    npu_space_t src_space,
    npu_space_t dst_space,
    uint64_t src_addr,
    uint64_t dst_addr)
{
    uint32_t op_flags = 0u;
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT8 << 6u);

    if (src_space == NPU_SPACE_DDR) {
        op_flags |= UINT32_C(1) << 0u;
    }
    if (dst_space == NPU_SPACE_DDR) {
        op_flags |= UINT32_C(1) << 3u;
    }

    (void)memset(
        descriptor, 0, NPU_WIRE_DMA_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_DMA;
    scat_put_u16(
        descriptor, 0x02u, NPU_WIRE_DMA_DESC_BYTES);
    scat_put_u32(descriptor, 0x04u, op_flags);
    scat_put_u64(descriptor, 0x08u, src_addr);
    scat_put_u64(descriptor, 0x20u, dst_addr);
    scat_put_u32(descriptor, 0x38u, numeric);
    scat_put_u32(descriptor, 0x3cu, 0x444d4101u);
    descriptor[0x40u] = 1u;
    descriptor[0x41u] = (uint8_t)src_space;
    descriptor[0x42u] = (uint8_t)dst_space;
    descriptor[0x43u] = NPU_DMA_CONVERT_NONE;
    descriptor[0x44u] =
        NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    descriptor[0x45u] = NPU_REF_DMA_OUTSTANDING;
    scat_put_u32(descriptor, 0x48u, SCAT_DMA_BYTES);
    scat_put_u64(descriptor, 0x98u, SCAT_DMA_BYTES);
    scat_put_u64(descriptor, 0xa0u, SCAT_DMA_BYTES);
}

static void scat_make_command(uint64_t desc_addr,
                              uint16_t command_id,
                              npu_engine_t engine,
                              uint8_t opcode,
                              uint64_t *low,
                              uint64_t *high)
{
    npu_cmd_t command;

    (void)memset(&command, 0, sizeof(command));
    command.desc_addr = desc_addr;
    command.command_id = command_id;
    command.engine = engine;
    command.opcode = opcode;
    command.header_flags = NPU_TS_FLAG_IRQ_ON_SUCCESS;
    command.wait_event[0] = npu_event_none();
    command.wait_event[1] = npu_event_none();
    command.signal_event = npu_event_none();
    command.header_version = NPU_WIRE_HEADER_VERSION;
    command.timeout_class = 0u;
    npu_cmd_encode(&command, low, high);
}

static void scat_core_inputs(
    const scat_env_t *env,
    npu_single_core_cycle_core_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_rst_ni = env->core_rst_ni;
    inputs->noc_rst_ni = env->noc_rst_ni;
    inputs->module_clk_en_i = NPU_SINGLE_CORE_CLK_ALL;
    inputs->dsa_permission_i = 1u;
    inputs->dsa_enable_i = 1u;
}

static void scat_noc_inputs(
    const scat_env_t *env,
    npu_single_core_cycle_noc_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_rst_ni = env->core_rst_ni;
    inputs->noc_rst_ni = env->noc_rst_ni;
    inputs->module_clk_en_i = NPU_SINGLE_CORE_CLK_ALL;
}

static void scat_observe(
    const scat_env_t *env,
    scat_observation_t *observation)
{
    (void)memset(observation, 0, sizeof(*observation));
    observation->mif_ar = env->mif_ar_handshakes;
    observation->mif_r = env->mif_r_handshakes;
    observation->mif_r_last =
        env->mif_r_last_handshakes;
    observation->mif_aw = env->mif_aw_handshakes;
    observation->mif_w = env->mif_w_handshakes;
    observation->mif_b = env->mif_b_handshakes;
    observation->tbu_req = env->tbu_req_handshakes;
    observation->tbu_rsp = env->tbu_rsp_handshakes;
    observation->dfu_core_req =
        env->dfu_core_req_handshakes;
    observation->dfu_noc_req =
        env->dfu_noc_req_handshakes;

    observation->dma_core_read_req =
        env->dma_core_read_req_handshakes;
    observation->dma_core_write_req =
        env->dma_core_write_req_handshakes;
    observation->dma_core_w =
        env->dma_core_w_handshakes;
    observation->dma_core_read_rsp =
        env->dma_core_read_rsp_handshakes;
    observation->dma_core_write_rsp =
        env->dma_core_write_rsp_handshakes;
    observation->dma_noc_read_req =
        env->dma_noc_read_req_handshakes;
    observation->dma_noc_write_req =
        env->dma_noc_write_req_handshakes;
    observation->dma_noc_w =
        env->dma_noc_w_handshakes;
    observation->dma_noc_read_rsp =
        env->dma_noc_read_rsp_handshakes;
    observation->dma_noc_write_rsp =
        env->dma_noc_write_rsp_handshakes;
    observation->dma_l1_read_req =
        env->dma_l1_read_req_handshakes;
    observation->dma_l1_read_rsp =
        env->dma_l1_read_rsp_handshakes;
    observation->dma_l1_write_req =
        env->dma_l1_write_req_handshakes;
    observation->dma_l1_write_data =
        env->dma_l1_write_data_handshakes;
    observation->dma_l1_write_rsp =
        env->dma_l1_write_rsp_handshakes;
}

static void scat_observe_dma_core(
    scat_env_t *env,
    const npu_single_core_cycle_core_outputs_t *outputs)
{
    const npu_mif_owner_inputs_t *engine_mif =
        &outputs->engine[0].mif;
    const npu_mif_owner_outputs_t *cdc_mif =
        &outputs->cdc.owner[NPU_MIF_OWNER_DMA];
    const npu_l1_cycle_read_input_t *engine_l1_read =
        &outputs->engine[0].l1_read[0];
    const npu_l1_cycle_read_output_t *l1_read =
        &outputs->l1.read[NPU_L1_RD_DMA];
    const npu_l1_cycle_write_input_t *engine_l1_write =
        &outputs->engine[0].l1_write;
    const npu_l1_cycle_write_output_t *l1_write =
        &outputs->l1.write[NPU_L1_WR_DMA];

    if (outputs->ts.dfu.req_valid != 0u &&
        outputs->cdc.owner[NPU_MIF_OWNER_DFU].req_ready !=
            0u) {
        if (env->dfu_core_req_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->dfu_core_req_vaddr[
                env->dfu_core_req_handshakes] =
                outputs->ts.dfu.req_addr;
            env->dfu_core_req_beats[
                env->dfu_core_req_handshakes] =
                outputs->ts.dfu.req_beats;
        }
        env->dfu_core_req_handshakes++;
    }

    if (engine_mif->req_valid != 0u &&
        cdc_mif->req_ready != 0u) {
        uint32_t request_index =
            env->dma_core_read_req_handshakes +
            env->dma_core_write_req_handshakes;

        if (request_index < SCAT_AXI_LOG_ENTRIES) {
            env->dma_core_req_vaddr[request_index] =
                engine_mif->req_vaddr;
            env->dma_core_req_beats[request_index] =
                engine_mif->req_beats;
            env->dma_core_req_write[request_index] =
                engine_mif->req_write;
        }
        if (engine_mif->req_write != 0u) {
            env->dma_core_write_req_handshakes++;
        } else {
            env->dma_core_read_req_handshakes++;
        }
    }
    if (engine_mif->wvalid != 0u &&
        cdc_mif->wready != 0u) {
        env->dma_core_w_handshakes++;
    }
    if (engine_mif->rsp_ready != 0u &&
        cdc_mif->rsp_valid != 0u) {
        if (cdc_mif->rsp_is_write != 0u) {
            env->dma_core_write_rsp_handshakes++;
        } else {
            env->dma_core_read_rsp_handshakes++;
        }
    }

    if (engine_l1_read->req_valid != 0u &&
        l1_read->req_ready != 0u) {
        env->dma_l1_read_req_handshakes++;
    }
    if (engine_l1_read->rsp_ready != 0u &&
        l1_read->rsp_valid != 0u) {
        env->dma_l1_read_rsp_handshakes++;
    }
    if (engine_l1_write->req_valid != 0u &&
        l1_write->req_ready != 0u) {
        env->dma_l1_write_req_handshakes++;
    }
    if (engine_l1_write->data_valid != 0u &&
        l1_write->data_ready != 0u) {
        env->dma_l1_write_data_handshakes++;
    }
    if (engine_l1_write->rsp_ready != 0u &&
        l1_write->rsp_valid != 0u) {
        env->dma_l1_write_rsp_handshakes++;
    }
}

/*
 * The memory target is evaluated first to obtain its current target-side
 * pins. The top and target are then committed once with the same ready/valid
 * values, which models one shared Core-domain rising edge.
 */
static void scat_core_tick(
    scat_env_t *env,
    npu_single_core_cycle_core_inputs_t *inputs,
    npu_single_core_cycle_core_outputs_t *outputs)
{
    npu_axi_mem_target_cycle_inputs_t target_inputs;
    npu_axi_mem_target_cycle_outputs_t target_preview;
    npu_axi_mem_target_cycle_outputs_t target_outputs;

    (void)memset(&target_inputs, 0, sizeof(target_inputs));
    target_inputs.reset_n = env->gc_target_reset_n;
    npu_axi_mem_master_from_gc(
        &target_inputs.master, &env->last_gc_master);
    npu_axi_mem_target_cycle_eval(
        &env->gc_target, &target_inputs, &target_preview);
    npu_axi_mem_target_to_gc(
        &inputs->gc_axi.axi, &target_preview.target);

    npu_single_core_cycle_core_tick(
        &env->top, inputs, outputs);
    scat_observe_dma_core(env, outputs);

    target_inputs.reset_n = outputs->core_reset_n;
    npu_axi_mem_master_from_gc(
        &target_inputs.master, &outputs->gc_axi.axi);
    npu_axi_mem_target_cycle_step(
        &env->gc_target, &target_inputs, &target_outputs);

    if (target_inputs.master.arvalid != 0u &&
        target_outputs.target.arready != 0u) {
        env->gc_ar_handshakes++;
    }
    if (target_outputs.target.rvalid != 0u &&
        target_inputs.master.rready != 0u) {
        env->gc_r_handshakes++;
    }
    env->last_gc_master = outputs->gc_axi.axi;
    env->gc_target_reset_n = outputs->core_reset_n;
    env->core_ticks++;
}

/*
 * This is the corresponding NoC-domain edge. The DDR target sees the actual
 * MIF AXI master pins through the public conversion helpers.
 */
static void scat_noc_tick(
    scat_env_t *env,
    npu_single_core_cycle_noc_outputs_t *outputs)
{
    npu_single_core_cycle_noc_inputs_t inputs;
    npu_axi_mem_target_cycle_inputs_t target_inputs;
    npu_axi_mem_target_cycle_outputs_t target_preview;
    npu_axi_mem_target_cycle_outputs_t target_outputs;

    scat_noc_inputs(env, &inputs);
    (void)memset(&target_inputs, 0, sizeof(target_inputs));
    target_inputs.reset_n = env->mif_target_reset_n;
    npu_axi_mem_master_from_mif(
        &target_inputs.master, &env->last_mif_master);
    npu_axi_mem_target_cycle_eval(
        &env->mif_target, &target_inputs, &target_preview);
    npu_axi_mem_target_to_mif(
        &inputs.axi,
        &target_preview.target);

    npu_single_core_cycle_noc_tick(
        &env->top, &inputs, outputs);

    target_inputs.reset_n = outputs->noc_reset_n;
    npu_axi_mem_master_from_mif(
        &target_inputs.master,
        &outputs->mif.axi);
    npu_axi_mem_target_cycle_step(
        &env->mif_target, &target_inputs, &target_outputs);

    if (target_inputs.master.arvalid != 0u &&
        target_outputs.target.arready != 0u) {
        if (env->mif_ar_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->mif_ar_addr[env->mif_ar_handshakes] =
                target_inputs.master.araddr;
            env->mif_ar_len[env->mif_ar_handshakes] =
                target_inputs.master.arlen;
            env->mif_ar_size[env->mif_ar_handshakes] =
                target_inputs.master.arsize;
        }
        env->mif_ar_handshakes++;
    }
    if (target_outputs.target.rvalid != 0u &&
        target_inputs.master.rready != 0u) {
        env->mif_r_handshakes++;
        if (target_outputs.target.rlast != 0u) {
            env->mif_r_last_handshakes++;
        }
    }
    if (target_inputs.master.awvalid != 0u &&
        target_outputs.target.awready != 0u) {
        if (env->mif_aw_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->mif_aw_addr[env->mif_aw_handshakes] =
                target_inputs.master.awaddr;
            env->mif_aw_len[env->mif_aw_handshakes] =
                target_inputs.master.awlen;
            env->mif_aw_size[env->mif_aw_handshakes] =
                target_inputs.master.awsize;
        }
        env->mif_aw_handshakes++;
    }
    if (target_inputs.master.wvalid != 0u &&
        target_outputs.target.wready != 0u) {
        if (env->mif_w_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->mif_w_data[env->mif_w_handshakes] =
                target_inputs.master.wdata;
            env->mif_w_strb[env->mif_w_handshakes] =
                target_inputs.master.wstrb;
            env->mif_w_last[env->mif_w_handshakes] =
                target_inputs.master.wlast;
        }
        env->mif_w_handshakes++;
    }
    if (target_outputs.target.bvalid != 0u &&
        target_inputs.master.bready != 0u) {
        env->mif_b_handshakes++;
    }
    if (outputs->mif.tbu.req_valid != 0u &&
        outputs->tbu.req_ready != 0u) {
        if (env->tbu_req_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->tbu_req_vaddr[env->tbu_req_handshakes] =
                outputs->mif.tbu.req_vaddr;
            env->tbu_req_write[env->tbu_req_handshakes] =
                outputs->mif.tbu.req_write;
        }
        env->tbu_req_handshakes++;
    }
    if (outputs->tbu.rsp_valid != 0u &&
        outputs->mif.tbu.rsp_ready != 0u) {
        if (env->tbu_rsp_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->tbu_rsp_paddr[env->tbu_rsp_handshakes] =
                outputs->tbu.rsp_paddr;
            env->tbu_rsp_status[env->tbu_rsp_handshakes] =
                outputs->tbu.rsp_status;
        }
        env->tbu_rsp_handshakes++;
    }
    if (outputs->cdc.owner[NPU_MIF_OWNER_DFU].req_valid !=
            0u &&
        outputs->mif.owner[NPU_MIF_OWNER_DFU].req_ready !=
            0u) {
        if (env->dfu_noc_req_handshakes <
            SCAT_AXI_LOG_ENTRIES) {
            env->dfu_noc_req_vaddr[
                env->dfu_noc_req_handshakes] =
                outputs->cdc.owner[NPU_MIF_OWNER_DFU]
                    .req_vaddr;
            env->dfu_noc_req_beats[
                env->dfu_noc_req_handshakes] =
                outputs->cdc.owner[NPU_MIF_OWNER_DFU]
                    .req_beats;
        }
        env->dfu_noc_req_handshakes++;
    }
    if (outputs->cdc.owner[NPU_MIF_OWNER_DMA].req_valid !=
            0u &&
        outputs->mif.owner[NPU_MIF_OWNER_DMA].req_ready !=
            0u) {
        uint32_t request_index =
            env->dma_noc_read_req_handshakes +
            env->dma_noc_write_req_handshakes;

        if (request_index < SCAT_AXI_LOG_ENTRIES) {
            env->dma_noc_req_vaddr[request_index] =
                outputs->cdc.owner[NPU_MIF_OWNER_DMA]
                    .req_vaddr;
            env->dma_noc_req_beats[request_index] =
                outputs->cdc.owner[NPU_MIF_OWNER_DMA]
                    .req_beats;
            env->dma_noc_req_write[request_index] =
                outputs->cdc.owner[NPU_MIF_OWNER_DMA]
                    .req_write;
        }
        if (outputs->cdc.owner[NPU_MIF_OWNER_DMA]
                .req_write != 0u) {
            env->dma_noc_write_req_handshakes++;
        } else {
            env->dma_noc_read_req_handshakes++;
        }
    }
    if (outputs->cdc.owner[NPU_MIF_OWNER_DMA].wvalid !=
            0u &&
        outputs->mif.owner[NPU_MIF_OWNER_DMA].wready !=
            0u) {
        env->dma_noc_w_handshakes++;
    }
    if (outputs->cdc.owner[NPU_MIF_OWNER_DMA].rsp_ready !=
            0u &&
        outputs->mif.owner[NPU_MIF_OWNER_DMA].rsp_valid !=
            0u) {
        if (outputs->mif.owner[NPU_MIF_OWNER_DMA]
                .rsp_is_write != 0u) {
            env->dma_noc_write_rsp_handshakes++;
        } else {
            env->dma_noc_read_rsp_handshakes++;
        }
    }
    env->last_mif_master =
        outputs->mif.axi;
    env->mif_target_reset_n = outputs->noc_reset_n;
    env->noc_ticks++;
}

static int scat_env_init(scat_env_t *env)
{
    npu_config_t config;
    npu_wire_limits_t limits;
    npu_lsc_cycle_config_t lsc_config;
    npu_mif_cycle_config_t mif_config;
    npu_axi_mem_target_config_t target_config;
    npu_tbu_rule_t rule;
    uint32_t engine;
    uint32_t index;

    (void)memset(env, 0, sizeof(*env));
    npu_config_reference(&config);
    TEST_CHECK_STATUS(
        npu_model_init(
            &env->functional, &config,
            env->l1, sizeof(env->l1),
            env->ddr, sizeof(env->ddr)),
        NPU_STATUS_SUCCESS);

    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        env->workspace[engine].read_entries =
            env->read_entry[engine];
        env->workspace[engine].read_capacity =
            SCAT_TRACE_ENTRIES;
        env->workspace[engine].read_hash =
            env->read_hash[engine];
        env->workspace[engine].read_hash_slots =
            SCAT_TRACE_HASH;
        env->workspace[engine].write_entries =
            env->write_entry[engine];
        env->workspace[engine].write_capacity =
            SCAT_TRACE_ENTRIES;
        env->workspace[engine].write_hash =
            env->write_hash[engine];
        env->workspace[engine].write_hash_slots =
            SCAT_TRACE_HASH;
    }

    npu_wire_limits_reference(&limits);
    limits.l1_bytes = NPU_L1_CYCLE_BYTES;
    limits.gaddr_limit = SCAT_DDR_BYTES;
    npu_lsc_cycle_config_reference(&lsc_config);
    npu_mif_cycle_config_default(&mif_config);
    mif_config.system_addr_enable = 1u;
    mif_config.system_addr_base = 0u;
    mif_config.system_addr_limit = SCAT_DDR_BYTES - 8u;
    mif_config.bypass_enable = 0u;

    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &limits, &lsc_config,
            &mif_config, NPU_SINGLE_CORE_TBU_INTERNAL),
        NPU_STATUS_SUCCESS);

    npu_axi_mem_target_config_reference(&target_config);
    TEST_CHECK(npu_axi_mem_target_cycle_init(
        &env->gc_target, env->ddr, sizeof(env->ddr),
        0u, &target_config));
    TEST_CHECK(npu_axi_mem_target_cycle_init(
        &env->mif_target, env->ddr, sizeof(env->ddr),
        0u, &target_config));

    (void)memset(&rule, 0, sizeof(rule));
    rule.valid = 1u;
    rule.virtual_page = SCAT_DESC_VADDR >> 12u;
    rule.physical_page =
        (uint32_t)(SCAT_DESC_PADDR >> 12u);
    rule.stream_id = 0x1234u;
    rule.substream_id = 0x5678u;
    rule.read_enable = 1u;
    rule.write_enable = 1u;
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env->top.tbu, 0u, &rule));

    rule.virtual_page = SCAT_DMA_DESC_VADDR >> 12u;
    rule.physical_page =
        (uint32_t)(SCAT_DMA_DESC_PADDR >> 12u);
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env->top.tbu, 1u, &rule));

    rule.virtual_page = SCAT_DMA_DDR_SRC >> 12u;
    rule.physical_page =
        (uint32_t)(SCAT_DMA_DDR_SRC >> 12u);
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env->top.tbu, 2u, &rule));

    rule.virtual_page = SCAT_DMA_DDR_DST >> 12u;
    rule.physical_page =
        (uint32_t)(SCAT_DMA_DDR_DST >> 12u);
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env->top.tbu, 3u, &rule));

    scat_make_vector_descriptor(
        &env->ddr[(size_t)SCAT_DESC_PADDR]);
    for (index = 0u; index < 16u; index++) {
        env->l1[SCAT_SRC0 + index] =
            (uint8_t)(index + 1u);
        env->l1[SCAT_SRC1 + index] =
            (uint8_t)(index + 10u);
        env->l1[SCAT_DST + index] = 0xa5u;
    }
    env->l1[SCAT_SRC0 + 15u] = 120u;
    env->l1[SCAT_SRC1 + 15u] = 20u;
    for (index = 0u; index < SCAT_DMA_BYTES; index++) {
        env->ddr[(size_t)SCAT_DMA_DDR_SRC + index] =
            (uint8_t)(0x31u + index * 3u);
        env->l1[SCAT_DMA_L1_SRC + index] =
            (uint8_t)(0xe1u - index * 2u);
    }
    (void)memset(
        &env->l1[SCAT_DMA_L1_DST -
                 SCAT_DMA_GUARD_BYTES],
        0xc5, SCAT_DMA_BYTES +
                  2u * SCAT_DMA_GUARD_BYTES);
    (void)memset(
        &env->ddr[(size_t)SCAT_DMA_DDR_DST -
                  SCAT_DMA_GUARD_BYTES],
        0x6a, SCAT_DMA_BYTES +
                  2u * SCAT_DMA_GUARD_BYTES);
    scat_put_u64(
        env->ddr, (size_t)SCAT_GC_ADDR,
        UINT64_C(0xfedcba9876543210));

    env->core_rst_ni = 0u;
    env->noc_rst_ni = 0u;
    return 0;
}

static int scat_release_reset(scat_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;

    scat_core_inputs(env, &core_inputs);
    scat_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n == 0u);
    scat_noc_tick(env, &noc_outputs);
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);

    env->core_rst_ni = 1u;
    env->noc_rst_ni = 1u;
    scat_core_inputs(env, &core_inputs);
    scat_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n == 0u);
    scat_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n != 0u);

    scat_noc_tick(env, &noc_outputs);
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    scat_core_tick(env, &core_inputs, &core_outputs);
    scat_noc_tick(env, &noc_outputs);
    TEST_CHECK(noc_outputs.noc_reset_n != 0u);
    TEST_CHECK(env->core_ticks != env->noc_ticks);
    return 0;
}

static int scat_gc_read(scat_env_t *env)
{
    const uint64_t expected =
        UINT64_C(0xfedcba9876543210);
    const uint16_t tag = UINT16_C(0x2a5);
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t request_accepted = 0u;
    uint8_t response_seen = 0u;
    uint32_t cycle;

    for (cycle = 0u; cycle < 256u; cycle++) {
        scat_core_inputs(env, &inputs);
        if (request_accepted == 0u) {
            inputs.gc_axi.icache_req.valid = 1u;
            inputs.gc_axi.icache_req.addr = SCAT_GC_ADDR;
            inputs.gc_axi.icache_req.beats = 0u;
            inputs.gc_axi.icache_req.tag = tag;
            inputs.gc_axi.icache_req.cache = 0xau;
            inputs.gc_axi.icache_req.prot = 4u;
        }
        inputs.gc_axi.icache_rsp_ready = response_seen;
        scat_core_tick(env, &inputs, &outputs);

        if ((cycle % 3u) == 0u) {
            scat_noc_tick(env, &noc_outputs);
        }
        if (inputs.gc_axi.icache_req.valid != 0u &&
            outputs.gc_axi.icache_req_ready != 0u) {
            request_accepted = 1u;
        }
        if (outputs.gc_axi.icache_rsp.valid != 0u) {
            TEST_CHECK(outputs.gc_axi.icache_rsp.data ==
                       expected);
            TEST_CHECK(outputs.gc_axi.icache_rsp.tag == tag);
            TEST_CHECK(outputs.gc_axi.icache_rsp.last != 0u);
            TEST_CHECK(outputs.gc_axi.icache_rsp.status ==
                       NPU_STATUS_SUCCESS);
            if (response_seen != 0u) {
                break;
            }
            response_seen = 1u;
        }
    }

    TEST_CHECK(request_accepted != 0u);
    TEST_CHECK(response_seen != 0u);
    TEST_CHECK(env->gc_ar_handshakes == 1u);
    TEST_CHECK(env->gc_r_handshakes == 1u);
    TEST_CHECK(npu_axi_mem_target_cycle_is_idle(
                   &env->gc_target) != 0u);
    return 0;
}

static int scat_system_write(scat_env_t *env,
                             uint32_t address,
                             uint64_t data,
                             uint8_t id)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint32_t cycle;
    uint8_t accepted = 0u;

    for (cycle = 0u; cycle < 64u; cycle++) {
        scat_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_awvalid = 1u;
        inputs.system_axi.s_axi_awid = id;
        inputs.system_axi.s_axi_awaddr = address;
        inputs.system_axi.s_axi_awlen = 0u;
        inputs.system_axi.s_axi_awsize = 3u;
        inputs.system_axi.s_axi_awburst =
            NPU_SYS_AXI_BURST_INCR;
        scat_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_awready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 64u; cycle++) {
        scat_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_wvalid = 1u;
        inputs.system_axi.s_axi_wdata = data;
        inputs.system_axi.s_axi_wstrb = 0xffu;
        inputs.system_axi.s_axi_wlast = 1u;
        scat_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_wready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        scat_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_bready = 1u;
        scat_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_bvalid != 0u) {
            TEST_CHECK(outputs.system_axi.s_axi_bid == id);
            TEST_CHECK(outputs.system_axi.s_axi_bresp ==
                       NPU_SYS_AXI_RESP_OKAY);
            return 0;
        }
    }
    return __LINE__;
}

static int scat_issue_submit(scat_env_t *env,
                             uint64_t desc_addr,
                             uint16_t command_id,
                             npu_engine_t engine,
                             uint8_t opcode)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint32_t cycle;
    uint8_t accepted = 0u;

    scat_make_command(
        desc_addr, command_id, engine, opcode,
        &low, &high);
    for (cycle = 0u; cycle < 64u; cycle++) {
        scat_core_inputs(env, &inputs);
        inputs.issue_valid_i = 1u;
        inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
        inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
        inputs.issue_funct7_i = 0u;
        inputs.issue_rs1_i = low;
        inputs.issue_rs2_i = high;
        inputs.issue_rd_i = 9u;
        scat_core_tick(env, &inputs, &outputs);
        if (outputs.issue.issue_ready_o != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        scat_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = 1u;
        scat_core_tick(env, &inputs, &outputs);
        if (outputs.issue.issue_rsp_valid_o != 0u) {
            TEST_CHECK(outputs.issue.issue_rsp_exception_o == 0u);
            TEST_CHECK(outputs.issue.issue_rsp_rd_o == 9u);
            TEST_CHECK(
                ((outputs.issue.issue_rsp_data_o >> 12u) &
                 0xffu) == NPU_STATUS_SUCCESS);
            return 0;
        }
    }
    return __LINE__;
}

static int scat_descriptor_fetch(scat_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t terminal_seen = 0u;
    uint32_t cycle;
    uint32_t index;

    SCAT_CALL(scat_issue_submit(
        env, SCAT_DESC_VADDR, SCAT_COMMAND_ID,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD));

    for (cycle = 0u;
         cycle < SCAT_MAX_CYCLES && terminal_seen == 0u;
         cycle++) {
        scat_core_inputs(env, &core_inputs);
        core_inputs.issue_rsp_ready_i = 1u;
        scat_core_tick(env, &core_inputs, &core_outputs);

        if ((cycle % 3u) != 1u) {
            scat_noc_tick(env, &noc_outputs);
        }
        if ((cycle % 17u) == 0u) {
            scat_core_inputs(env, &core_inputs);
            core_inputs.issue_rsp_ready_i = 1u;
            scat_core_tick(env, &core_inputs, &core_outputs);
        }
        if (core_outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(core_outputs.ts.terminal_task_id ==
                       SCAT_COMMAND_ID);
            TEST_CHECK(core_outputs.ts.terminal_status ==
                       NPU_STATUS_SUCCESS);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(env->mif_ar_handshakes == 2u);
    TEST_CHECK(env->mif_r_handshakes ==
               NPU_WIRE_VECTOR_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    TEST_CHECK(env->mif_ar_addr[0] == SCAT_DESC_PADDR);
    TEST_CHECK(env->mif_ar_addr[1] ==
               SCAT_DESC_PADDR +
                   NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->tbu_req_handshakes == 2u);
    TEST_CHECK(env->tbu_rsp_handshakes == 2u);
    TEST_CHECK(npu_axi_mem_target_cycle_is_idle(
                   &env->mif_target) != 0u);

    for (index = 0u; index < 15u; index++) {
        TEST_CHECK(env->l1[SCAT_DST + index] ==
                   (uint8_t)((index + 1u) +
                             (index + 10u)));
    }
    TEST_CHECK(env->l1[SCAT_DST + 15u] == 127u);
    TEST_CHECK(env->core_ticks != env->noc_ticks);
    return 0;
}

static int scat_dma_after_core_tick(
    scat_env_t *env,
    const npu_single_core_cycle_core_outputs_t *outputs,
    uint8_t ddr_to_l1,
    uint16_t command_id,
    uint8_t *previous_data_pending,
    uint8_t *destination_scrubbed,
    uint8_t *terminal_seen)
{
    uint8_t data_pending =
        env->top.engine[0].data_pending;

    if (*destination_scrubbed == 0u &&
        *previous_data_pending == 0u &&
        data_pending != 0u) {
        uint32_t index;

        if (ddr_to_l1 != 0u) {
            for (index = 0u; index < SCAT_DMA_BYTES;
                 index++) {
                TEST_CHECK(
                    env->l1[SCAT_DMA_L1_DST + index] ==
                    0xc5u);
            }
            (void)memset(
                &env->l1[SCAT_DMA_L1_DST],
                0xd7, SCAT_DMA_BYTES);
        } else {
            for (index = 0u; index < SCAT_DMA_BYTES;
                 index++) {
                TEST_CHECK(
                    env->ddr[(size_t)SCAT_DMA_DDR_DST +
                             index] == 0x6au);
            }
            (void)memset(
                &env->ddr[(size_t)SCAT_DMA_DDR_DST],
                0x7b, SCAT_DMA_BYTES);
        }
        *destination_scrubbed = 1u;
    }
    *previous_data_pending = data_pending;

    if (outputs->ts.terminal_valid != 0u) {
        TEST_CHECK(outputs->ts.terminal_task_id ==
                   command_id);
        TEST_CHECK(outputs->ts.terminal_status ==
                   NPU_STATUS_SUCCESS);
        TEST_CHECK(outputs->ts.terminal_engine ==
                   NPU_ENGINE_DMA);
        TEST_CHECK(outputs->ts.terminal_opcode ==
                   NPU_DMA_COPY_1D);
        *terminal_seen = 1u;
    }
    return 0;
}

static int scat_dma_check_trace(
    const scat_env_t *env,
    uint8_t ddr_to_l1)
{
    const npu_bus_trace_t *trace =
        &env->top.engine[0].trace;
    uint64_t src_addr =
        ddr_to_l1 != 0u ? SCAT_DMA_DDR_SRC
                        : SCAT_DMA_L1_SRC;
    uint64_t dst_addr =
        ddr_to_l1 != 0u ? SCAT_DMA_L1_DST
                        : SCAT_DMA_DDR_DST;
    uint8_t src_space =
        ddr_to_l1 != 0u ? NPU_SPACE_DDR
                        : NPU_SPACE_L1;
    uint8_t dst_space =
        ddr_to_l1 != 0u ? NPU_SPACE_L1
                        : NPU_SPACE_DDR;
    size_t index;

    TEST_CHECK(trace->overflow == 0u);
    TEST_CHECK(trace->read_count ==
               SCAT_DMA_BYTES / NPU_REF_BUS_BYTES);
    TEST_CHECK(trace->write_count ==
               SCAT_DMA_BYTES / NPU_REF_BUS_BYTES);
    for (index = 0u; index < trace->read_count; index++) {
        TEST_CHECK(trace->read[index].addr ==
                   src_addr +
                       index * NPU_REF_BUS_BYTES);
        TEST_CHECK(trace->read[index].space == src_space);
        TEST_CHECK(trace->read[index].strb == 0xffu);
        TEST_CHECK(trace->write[index].addr ==
                   dst_addr +
                       index * NPU_REF_BUS_BYTES);
        TEST_CHECK(trace->write[index].space == dst_space);
        TEST_CHECK(trace->write[index].strb == 0xffu);
    }
    return 0;
}

static int scat_dma_check_transport(
    const scat_env_t *env,
    const scat_observation_t *before,
    uint8_t ddr_to_l1)
{
    uint32_t core_req_index =
        before->dma_core_read_req +
        before->dma_core_write_req;
    uint32_t noc_req_index =
        before->dma_noc_read_req +
        before->dma_noc_write_req;
    uint32_t dfu_core_index = before->dfu_core_req;
    uint32_t dfu_noc_index = before->dfu_noc_req;
    uint32_t ar_index = before->mif_ar;
    uint64_t data_addr =
        ddr_to_l1 != 0u ? SCAT_DMA_DDR_SRC
                        : SCAT_DMA_DDR_DST;

    TEST_CHECK(env->tbu_req_handshakes -
                   before->tbu_req ==
               3u);
    TEST_CHECK(env->tbu_rsp_handshakes -
                   before->tbu_rsp ==
               3u);
    TEST_CHECK(before->tbu_req + 2u <
               SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(before->tbu_rsp + 2u <
               SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(env->tbu_req_vaddr[before->tbu_req] ==
               SCAT_DMA_DESC_VADDR);
    TEST_CHECK(env->tbu_req_vaddr[before->tbu_req + 1u] ==
               SCAT_DMA_DESC_VADDR +
                   NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->tbu_req_vaddr[before->tbu_req + 2u] ==
               data_addr);
    TEST_CHECK(env->tbu_req_write[before->tbu_req] == 0u);
    TEST_CHECK(
        env->tbu_req_write[before->tbu_req + 1u] == 0u);
    TEST_CHECK(
        env->tbu_req_write[before->tbu_req + 2u] ==
        (uint8_t)(ddr_to_l1 == 0u));
    TEST_CHECK(env->tbu_rsp_paddr[before->tbu_rsp] ==
               SCAT_DMA_DESC_PADDR);
    TEST_CHECK(env->tbu_rsp_paddr[before->tbu_rsp + 1u] ==
               SCAT_DMA_DESC_PADDR +
                   NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->tbu_rsp_paddr[before->tbu_rsp + 2u] ==
               data_addr);
    TEST_CHECK(env->tbu_rsp_status[before->tbu_rsp] ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(
        env->tbu_rsp_status[before->tbu_rsp + 1u] ==
        NPU_STATUS_SUCCESS);
    TEST_CHECK(
        env->tbu_rsp_status[before->tbu_rsp + 2u] ==
        NPU_STATUS_SUCCESS);

    TEST_CHECK(env->dfu_core_req_handshakes -
                   before->dfu_core_req ==
               2u);
    TEST_CHECK(env->dfu_noc_req_handshakes -
                   before->dfu_noc_req ==
               2u);
    TEST_CHECK(dfu_core_index + 1u <
               SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(dfu_noc_index + 1u <
               SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(env->dfu_core_req_vaddr[dfu_core_index] ==
               SCAT_DMA_DESC_VADDR);
    TEST_CHECK(
        env->dfu_core_req_vaddr[dfu_core_index + 1u] ==
        SCAT_DMA_DESC_VADDR +
            NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->dfu_core_req_beats[dfu_core_index] ==
               NPU_WIRE_CONTROL_DESC_BYTES /
                       NPU_REF_BUS_BYTES -
                   1u);
    TEST_CHECK(
        env->dfu_core_req_beats[dfu_core_index + 1u] ==
        (NPU_WIRE_DMA_DESC_BYTES -
         NPU_WIRE_CONTROL_DESC_BYTES) /
                NPU_REF_BUS_BYTES -
            1u);
    TEST_CHECK(env->dfu_noc_req_vaddr[dfu_noc_index] ==
               SCAT_DMA_DESC_VADDR);
    TEST_CHECK(
        env->dfu_noc_req_vaddr[dfu_noc_index + 1u] ==
        SCAT_DMA_DESC_VADDR +
            NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->dfu_noc_req_beats[dfu_noc_index] ==
               NPU_WIRE_CONTROL_DESC_BYTES /
                       NPU_REF_BUS_BYTES -
                   1u);
    TEST_CHECK(
        env->dfu_noc_req_beats[dfu_noc_index + 1u] ==
        (NPU_WIRE_DMA_DESC_BYTES -
         NPU_WIRE_CONTROL_DESC_BYTES) /
                NPU_REF_BUS_BYTES -
            1u);

    TEST_CHECK(core_req_index < SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(noc_req_index < SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(env->dma_core_req_vaddr[core_req_index] ==
               data_addr);
    TEST_CHECK(env->dma_core_req_beats[core_req_index] ==
               SCAT_DMA_BYTES / NPU_REF_BUS_BYTES - 1u);
    TEST_CHECK(env->dma_core_req_write[core_req_index] ==
               (uint8_t)(ddr_to_l1 == 0u));
    TEST_CHECK(env->dma_noc_req_vaddr[noc_req_index] ==
               data_addr);
    TEST_CHECK(env->dma_noc_req_beats[noc_req_index] ==
               SCAT_DMA_BYTES / NPU_REF_BUS_BYTES - 1u);
    TEST_CHECK(env->dma_noc_req_write[noc_req_index] ==
               (uint8_t)(ddr_to_l1 == 0u));

    TEST_CHECK(ar_index + 2u < SCAT_AXI_LOG_ENTRIES);
    TEST_CHECK(env->mif_ar_addr[ar_index] ==
               SCAT_DMA_DESC_PADDR);
    TEST_CHECK(env->mif_ar_addr[ar_index + 1u] ==
               SCAT_DMA_DESC_PADDR +
                   NPU_WIRE_CONTROL_DESC_BYTES);
    TEST_CHECK(env->mif_ar_addr[ar_index + 2u] ==
               SCAT_DMA_DESC_PADDR +
                   NPU_WIRE_CONTROL_DESC_BYTES +
                   NPU_MIF_AXI_MAX_BURST_BEATS *
                       NPU_REF_BUS_BYTES);
    TEST_CHECK(env->mif_ar_len[ar_index] ==
               NPU_WIRE_CONTROL_DESC_BYTES /
                       NPU_REF_BUS_BYTES -
                   1u);
    TEST_CHECK(env->mif_ar_len[ar_index + 1u] ==
               NPU_MIF_AXI_MAX_BURST_BEATS - 1u);
    TEST_CHECK(env->mif_ar_len[ar_index + 2u] ==
               (NPU_WIRE_DMA_DESC_BYTES -
                NPU_WIRE_CONTROL_DESC_BYTES -
                NPU_MIF_AXI_MAX_BURST_BEATS *
                    NPU_REF_BUS_BYTES) /
                       NPU_REF_BUS_BYTES -
                   1u);
    TEST_CHECK(env->mif_ar_size[ar_index] == 3u);
    TEST_CHECK(env->mif_ar_size[ar_index + 1u] == 3u);
    TEST_CHECK(env->mif_ar_size[ar_index + 2u] == 3u);

    if (ddr_to_l1 != 0u) {
        TEST_CHECK(env->mif_ar_handshakes -
                       before->mif_ar ==
                   4u);
        TEST_CHECK(env->mif_r_handshakes -
                       before->mif_r ==
                   36u);
        TEST_CHECK(env->mif_r_last_handshakes -
                       before->mif_r_last ==
                   4u);
        TEST_CHECK(ar_index + 3u <
                   SCAT_AXI_LOG_ENTRIES);
        TEST_CHECK(env->mif_ar_addr[ar_index + 3u] ==
                   SCAT_DMA_DDR_SRC);
        TEST_CHECK(env->mif_ar_len[ar_index + 3u] ==
                   SCAT_DMA_BYTES /
                           NPU_REF_BUS_BYTES -
                       1u);
        TEST_CHECK(env->mif_ar_size[ar_index + 3u] ==
                   3u);
        TEST_CHECK(env->mif_aw_handshakes ==
                   before->mif_aw);
        TEST_CHECK(env->mif_w_handshakes ==
                   before->mif_w);
        TEST_CHECK(env->mif_b_handshakes ==
                   before->mif_b);

        TEST_CHECK(env->dma_core_read_req_handshakes -
                       before->dma_core_read_req ==
                   1u);
        TEST_CHECK(env->dma_core_read_rsp_handshakes -
                       before->dma_core_read_rsp ==
                   4u);
        TEST_CHECK(env->dma_core_write_req_handshakes ==
                   before->dma_core_write_req);
        TEST_CHECK(env->dma_core_w_handshakes ==
                   before->dma_core_w);
        TEST_CHECK(env->dma_core_write_rsp_handshakes ==
                   before->dma_core_write_rsp);
        TEST_CHECK(env->dma_noc_read_req_handshakes -
                       before->dma_noc_read_req ==
                   1u);
        TEST_CHECK(env->dma_noc_read_rsp_handshakes -
                       before->dma_noc_read_rsp ==
                   4u);
        TEST_CHECK(env->dma_noc_write_req_handshakes ==
                   before->dma_noc_write_req);
        TEST_CHECK(env->dma_noc_w_handshakes ==
                   before->dma_noc_w);
        TEST_CHECK(env->dma_noc_write_rsp_handshakes ==
                   before->dma_noc_write_rsp);

        TEST_CHECK(env->dma_l1_write_req_handshakes -
                       before->dma_l1_write_req ==
                   1u);
        TEST_CHECK(
            env->dma_l1_write_data_handshakes -
                    before->dma_l1_write_data ==
                4u);
        TEST_CHECK(env->dma_l1_write_rsp_handshakes -
                       before->dma_l1_write_rsp ==
                   1u);
        TEST_CHECK(env->dma_l1_read_req_handshakes ==
                   before->dma_l1_read_req);
        TEST_CHECK(env->dma_l1_read_rsp_handshakes ==
                   before->dma_l1_read_rsp);
    } else {
        uint32_t aw_index = before->mif_aw;
        uint32_t w_index = before->mif_w;
        uint32_t beat;

        TEST_CHECK(env->mif_ar_handshakes -
                       before->mif_ar ==
                   3u);
        TEST_CHECK(env->mif_r_handshakes -
                       before->mif_r ==
                   32u);
        TEST_CHECK(env->mif_r_last_handshakes -
                       before->mif_r_last ==
                   3u);
        TEST_CHECK(env->mif_aw_handshakes -
                       before->mif_aw ==
                   1u);
        TEST_CHECK(env->mif_w_handshakes -
                       before->mif_w ==
                   4u);
        TEST_CHECK(env->mif_b_handshakes -
                       before->mif_b ==
                   1u);
        TEST_CHECK(aw_index < SCAT_AXI_LOG_ENTRIES);
        TEST_CHECK(env->mif_aw_addr[aw_index] ==
                   SCAT_DMA_DDR_DST);
        TEST_CHECK(env->mif_aw_len[aw_index] ==
                   SCAT_DMA_BYTES /
                           NPU_REF_BUS_BYTES -
                       1u);
        TEST_CHECK(env->mif_aw_size[aw_index] == 3u);
        for (beat = 0u;
             beat < SCAT_DMA_BYTES / NPU_REF_BUS_BYTES;
             beat++) {
            TEST_CHECK(w_index + beat <
                       SCAT_AXI_LOG_ENTRIES);
            TEST_CHECK(
                env->mif_w_data[w_index + beat] ==
                scat_get_u64(
                    env->l1, SCAT_DMA_L1_SRC +
                                 beat *
                                     NPU_REF_BUS_BYTES));
            TEST_CHECK(
                env->mif_w_strb[w_index + beat] ==
                0xffu);
            TEST_CHECK(
                env->mif_w_last[w_index + beat] ==
                (uint8_t)(
                    beat + 1u ==
                    SCAT_DMA_BYTES /
                        NPU_REF_BUS_BYTES));
        }

        TEST_CHECK(env->dma_core_write_req_handshakes -
                       before->dma_core_write_req ==
                   1u);
        TEST_CHECK(env->dma_core_w_handshakes -
                       before->dma_core_w ==
                   4u);
        TEST_CHECK(env->dma_core_write_rsp_handshakes -
                       before->dma_core_write_rsp ==
                   1u);
        TEST_CHECK(env->dma_core_read_req_handshakes ==
                   before->dma_core_read_req);
        TEST_CHECK(env->dma_core_read_rsp_handshakes ==
                   before->dma_core_read_rsp);
        TEST_CHECK(env->dma_noc_write_req_handshakes -
                       before->dma_noc_write_req ==
                   1u);
        TEST_CHECK(env->dma_noc_w_handshakes -
                       before->dma_noc_w ==
                   4u);
        TEST_CHECK(env->dma_noc_write_rsp_handshakes -
                       before->dma_noc_write_rsp ==
                   1u);
        TEST_CHECK(env->dma_noc_read_req_handshakes ==
                   before->dma_noc_read_req);
        TEST_CHECK(env->dma_noc_read_rsp_handshakes ==
                   before->dma_noc_read_rsp);

        TEST_CHECK(env->dma_l1_read_req_handshakes -
                       before->dma_l1_read_req ==
                   1u);
        TEST_CHECK(env->dma_l1_read_rsp_handshakes -
                       before->dma_l1_read_rsp ==
                   4u);
        TEST_CHECK(env->dma_l1_write_req_handshakes ==
                   before->dma_l1_write_req);
        TEST_CHECK(
            env->dma_l1_write_data_handshakes ==
            before->dma_l1_write_data);
        TEST_CHECK(env->dma_l1_write_rsp_handshakes ==
                   before->dma_l1_write_rsp);
    }
    return 0;
}

static int scat_dma_copy(scat_env_t *env,
                         uint8_t ddr_to_l1)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    scat_observation_t before;
    npu_space_t src_space =
        ddr_to_l1 != 0u ? NPU_SPACE_DDR
                        : NPU_SPACE_L1;
    npu_space_t dst_space =
        ddr_to_l1 != 0u ? NPU_SPACE_L1
                        : NPU_SPACE_DDR;
    uint64_t src_addr =
        ddr_to_l1 != 0u ? SCAT_DMA_DDR_SRC
                        : SCAT_DMA_L1_SRC;
    uint64_t dst_addr =
        ddr_to_l1 != 0u ? SCAT_DMA_L1_DST
                        : SCAT_DMA_DDR_DST;
    uint16_t command_id =
        ddr_to_l1 != 0u ? SCAT_DMA_READ_COMMAND_ID
                        : SCAT_DMA_WRITE_COMMAND_ID;
    uint8_t previous_data_pending = 0u;
    uint8_t destination_scrubbed = 0u;
    uint8_t terminal_seen = 0u;
    uint64_t core_ticks_before = env->core_ticks;
    uint64_t noc_ticks_before = env->noc_ticks;
    uint32_t cycle;
    uint32_t index;

    TEST_CHECK(env->top.engine[0].data_pending == 0u);
    scat_make_dma_descriptor(
        &env->ddr[(size_t)SCAT_DMA_DESC_PADDR],
        src_space, dst_space, src_addr, dst_addr);
    scat_observe(env, &before);
    SCAT_CALL(scat_issue_submit(
        env, SCAT_DMA_DESC_VADDR, command_id,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D));

    for (cycle = 0u;
         cycle < SCAT_MAX_CYCLES && terminal_seen == 0u;
         cycle++) {
        scat_core_inputs(env, &core_inputs);
        core_inputs.issue_rsp_ready_i = 1u;
        scat_core_tick(env, &core_inputs, &core_outputs);
        SCAT_CALL(scat_dma_after_core_tick(
            env, &core_outputs, ddr_to_l1, command_id,
            &previous_data_pending, &destination_scrubbed,
            &terminal_seen));

        if (terminal_seen == 0u &&
            (cycle % 4u) != 2u) {
            scat_noc_tick(env, &noc_outputs);
        }
        if (terminal_seen == 0u &&
            (cycle % 19u) == 0u) {
            scat_core_inputs(env, &core_inputs);
            core_inputs.issue_rsp_ready_i = 1u;
            scat_core_tick(env, &core_inputs, &core_outputs);
            SCAT_CALL(scat_dma_after_core_tick(
                env, &core_outputs, ddr_to_l1,
                command_id, &previous_data_pending,
                &destination_scrubbed, &terminal_seen));
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(destination_scrubbed != 0u);
    TEST_CHECK(env->core_ticks - core_ticks_before !=
               env->noc_ticks - noc_ticks_before);
    TEST_CHECK(npu_axi_mem_target_cycle_is_idle(
                   &env->mif_target) != 0u);
    SCAT_CALL(scat_dma_check_trace(env, ddr_to_l1));
    SCAT_CALL(scat_dma_check_transport(
        env, &before, ddr_to_l1));

    if (ddr_to_l1 != 0u) {
        TEST_CHECK(memcmp(
                       &env->l1[SCAT_DMA_L1_DST],
                       &env->ddr[(size_t)SCAT_DMA_DDR_SRC],
                       SCAT_DMA_BYTES) == 0);
        for (index = 0u; index < SCAT_DMA_GUARD_BYTES;
             index++) {
            TEST_CHECK(
                env->l1[SCAT_DMA_L1_DST -
                            SCAT_DMA_GUARD_BYTES +
                        index] == 0xc5u);
            TEST_CHECK(
                env->l1[SCAT_DMA_L1_DST +
                        SCAT_DMA_BYTES + index] == 0xc5u);
        }
    } else {
        TEST_CHECK(memcmp(
                       &env->ddr[(size_t)SCAT_DMA_DDR_DST],
                       &env->l1[SCAT_DMA_L1_SRC],
                       SCAT_DMA_BYTES) == 0);
        for (index = 0u; index < SCAT_DMA_GUARD_BYTES;
             index++) {
            TEST_CHECK(
                env->ddr[(size_t)SCAT_DMA_DDR_DST -
                             SCAT_DMA_GUARD_BYTES +
                         index] == 0x6au);
            TEST_CHECK(
                env->ddr[(size_t)SCAT_DMA_DDR_DST +
                         SCAT_DMA_BYTES + index] == 0x6au);
        }
    }
    return 0;
}

static int scat_core_only_reset_release(scat_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint32_t old_epoch = env->top.cdc.reset_epoch;

    env->core_rst_ni = 0u;
    scat_core_inputs(env, &inputs);
    npu_single_core_cycle_core_tick(
        &env->top, &inputs, &outputs);
    env->core_ticks++;
    TEST_CHECK(outputs.core_reset_n == 0u);
    TEST_CHECK(env->top.cdc.reset_epoch == old_epoch + 1u);

    env->core_rst_ni = 1u;
    scat_core_inputs(env, &inputs);
    npu_single_core_cycle_core_tick(
        &env->top, &inputs, &outputs);
    env->core_ticks++;
    TEST_CHECK(outputs.core_reset_n == 0u);
    npu_single_core_cycle_core_tick(
        &env->top, &inputs, &outputs);
    env->core_ticks++;
    TEST_CHECK(outputs.core_reset_n != 0u);
    return 0;
}

static int scat_mif_reset_stale_read_wait_rlast(
    scat_env_t *env)
{
    const uint8_t old_id = 0x35u;
    npu_single_core_cycle_noc_inputs_t noc_inputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    npu_mif_request_entry_t *old_request =
        &env->top.mif.requests[0];
    npu_mif_axi_entry_t *old_axi =
        &env->top.mif.axi_entries[0];
    uint8_t captured = 0u;
    uint32_t cycle;

    (void)memset(old_request, 0, sizeof(*old_request));
    old_request->valid = 1u;
    old_request->phase = NPU_MIF_REQ_AXI;
    old_request->owner = NPU_MIF_OWNER_DFU;
    old_request->tag = SCAT_RESET_COMMAND_ID;
    old_request->task_id = SCAT_RESET_COMMAND_ID;
    old_request->total_beats = 1u;
    old_request->remaining_beats = 1u;
    (void)memset(old_axi, 0, sizeof(*old_axi));
    old_axi->valid = 1u;
    old_axi->addr_sent = 1u;
    old_axi->axi_id = old_id;
    old_axi->req_slot = 0u;
    old_axi->beats = 1u;
    old_axi->vaddr = SCAT_DESC_VADDR;
    old_axi->paddr = SCAT_DESC_PADDR;

    SCAT_CALL(scat_core_only_reset_release(env));
    for (cycle = 0u; cycle < 8u; cycle++) {
        scat_noc_inputs(env, &noc_inputs);
        npu_single_core_cycle_noc_tick(
            &env->top, &noc_inputs, &noc_outputs);
        env->noc_ticks++;
        if (env->top.stale_axi_read_beats
                [old_id] != 0u) {
            captured = 1u;
            break;
        }
    }
    TEST_CHECK(captured != 0u);
    TEST_CHECK(env->top.stale_axi_read_beats
                   [old_id] == 1u);
    TEST_CHECK(env->top.stale_axi_read_wait_rlast
                   [old_id] == 0u);
    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);
    TEST_CHECK(env->top.mif_idle_source_noc == 0u);

    scat_noc_inputs(env, &noc_inputs);
    noc_inputs.axi.rvalid = 1u;
    noc_inputs.axi.rid = old_id;
    noc_inputs.axi.rdata =
        UINT64_C(0xdeadbeefbad0c0de);
    noc_inputs.axi.rresp =
        NPU_MIF_AXI_RESP_OKAY;
    noc_inputs.axi.rlast = 0u;
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(
        noc_outputs.mif.axi.rready != 0u);
    TEST_CHECK(
        noc_outputs.mif.owner[NPU_MIF_OWNER_DFU].rsp_valid ==
        0u);
    TEST_CHECK(env->top.stale_axi_read_beats
                   [old_id] == 0u);
    TEST_CHECK(env->top.stale_axi_read_wait_rlast
                   [old_id] != 0u);
    TEST_CHECK(env->top.stale_axi_read_drop_count == 1u);

    scat_noc_inputs(env, &noc_inputs);
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(env->top.stale_axi_read_wait_rlast
                   [old_id] != 0u);
    TEST_CHECK(env->top.mif_idle_source_noc == 0u);

    scat_noc_inputs(env, &noc_inputs);
    noc_inputs.axi.rvalid = 1u;
    noc_inputs.axi.rid = old_id;
    noc_inputs.axi.rdata =
        UINT64_C(0x0123456789abcdef);
    noc_inputs.axi.rresp =
        NPU_MIF_AXI_RESP_OKAY;
    noc_inputs.axi.rlast = 1u;
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(
        noc_outputs.mif.axi.rready != 0u);
    TEST_CHECK(
        noc_outputs.mif.owner[NPU_MIF_OWNER_DFU].rsp_valid ==
        0u);
    TEST_CHECK(env->top.stale_axi_read_wait_rlast
                   [old_id] == 0u);
    TEST_CHECK(env->top.stale_axi_read_drop_count == 2u);
    TEST_CHECK(env->top.mif.protocol_error_valid == 0u);
    TEST_CHECK(env->top.mif.first_error_valid == 0u);

    scat_noc_inputs(env, &noc_inputs);
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(env->top.mif_idle_source_noc != 0u);
    return 0;
}

static int scat_mif_reset_stale_write_drain(
    scat_env_t *env)
{
    const uint8_t old_id = 0x36u;
    const uint8_t expected_wlast[2] = {0u, 1u};
    npu_single_core_cycle_noc_inputs_t noc_inputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    npu_mif_request_entry_t *old_request =
        &env->top.mif.requests[0];
    npu_mif_axi_entry_t *old_axi =
        &env->top.mif.axi_entries[0];
    uint8_t captured = 0u;
    uint32_t cycle;
    uint32_t beat;

    (void)memset(old_request, 0, sizeof(*old_request));
    old_request->valid = 1u;
    old_request->phase = NPU_MIF_REQ_AXI;
    old_request->owner = NPU_MIF_OWNER_DMA;
    old_request->write = 1u;
    old_request->tag = SCAT_RESET_COMMAND_ID;
    old_request->task_id = SCAT_RESET_COMMAND_ID;
    old_request->total_beats = 3u;
    old_request->remaining_beats = 3u;
    old_request->write_beats_accepted = 1u;
    (void)memset(old_axi, 0, sizeof(*old_axi));
    old_axi->valid = 1u;
    old_axi->addr_sent = 1u;
    old_axi->write = 1u;
    old_axi->axi_id = old_id;
    old_axi->req_slot = 0u;
    old_axi->beats = 3u;
    old_axi->beats_done = 1u;
    old_axi->vaddr = SCAT_DMA_DESC_VADDR;
    old_axi->paddr = SCAT_DMA_DESC_PADDR;
    env->top.mif.write_fifo[0] = 0u;
    env->top.mif.write_fifo_head = 0u;
    env->top.mif.write_fifo_tail = 1u;
    env->top.mif.write_fifo_count = 1u;

    SCAT_CALL(scat_core_only_reset_release(env));
    for (cycle = 0u; cycle < 8u; cycle++) {
        scat_noc_inputs(env, &noc_inputs);
        npu_single_core_cycle_noc_tick(
            &env->top, &noc_inputs, &noc_outputs);
        env->noc_ticks++;
        if (env->top.stale_axi_write_drain_count != 0u) {
            captured = 1u;
            break;
        }
    }
    TEST_CHECK(captured != 0u);
    TEST_CHECK(env->top.stale_axi_write_pending
                   [old_id] != 0u);
    TEST_CHECK(env->top.stale_axi_write_drain_count == 1u);
    TEST_CHECK(
        env->top.stale_axi_write_drain[0].axi_id == old_id);
    TEST_CHECK(
        env->top.stale_axi_write_drain[0].beats_remaining ==
        2u);

    for (beat = 0u; beat < 2u; beat++) {
        scat_noc_inputs(env, &noc_inputs);
        noc_inputs.axi.wready = 1u;
        npu_single_core_cycle_noc_tick(
            &env->top, &noc_inputs, &noc_outputs);
        env->noc_ticks++;
        TEST_CHECK(
            noc_outputs.mif.axi.wvalid !=
            0u);
        TEST_CHECK(
            noc_outputs.mif.axi.wdata == 0u);
        TEST_CHECK(
            noc_outputs.mif.axi.wstrb == 0u);
        TEST_CHECK(
            noc_outputs.mif.axi.wlast ==
            expected_wlast[beat]);
    }
    TEST_CHECK(env->top.stale_axi_write_drain_count == 0u);
    TEST_CHECK(env->top.stale_axi_w_drain_count == 2u);
    TEST_CHECK(env->top.mif_idle_source_noc == 0u);

    scat_noc_inputs(env, &noc_inputs);
    noc_inputs.axi.bvalid = 1u;
    noc_inputs.axi.bid = old_id;
    noc_inputs.axi.bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(
        noc_outputs.mif.axi.bready != 0u);
    TEST_CHECK(
        noc_outputs.mif.owner[NPU_MIF_OWNER_DMA].rsp_valid ==
        0u);
    TEST_CHECK(env->top.stale_axi_write_pending
                   [old_id] == 0u);
    TEST_CHECK(env->top.stale_axi_write_drop_count == 1u);
    TEST_CHECK(env->top.mif.protocol_error_valid == 0u);
    TEST_CHECK(env->top.mif.first_error_valid == 0u);

    scat_noc_inputs(env, &noc_inputs);
    npu_single_core_cycle_noc_tick(
        &env->top, &noc_inputs, &noc_outputs);
    env->noc_ticks++;
    TEST_CHECK(env->top.mif_idle_source_noc != 0u);
    return 0;
}

int test_single_core_axi_target(void)
{
    scat_env_t *env = &scat_env;

    SCAT_CALL(scat_env_init(env));
    SCAT_CALL(scat_release_reset(env));
    SCAT_CALL(scat_system_write(
        env, NPU_LSC_REG_M_AXI_ADDR_LIMIT,
        UINT64_C(0x00000000000ffff8), 0x61u));
    SCAT_CALL(scat_system_write(
        env, NPU_LSC_REG_TBU_STREAM_ID,
        UINT64_C(0x56781234), 0x62u));
    SCAT_CALL(scat_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x63u));
    SCAT_CALL(scat_gc_read(env));
    SCAT_CALL(scat_descriptor_fetch(env));
    SCAT_CALL(scat_dma_copy(env, 1u));
    SCAT_CALL(scat_dma_copy(env, 0u));

    SCAT_CALL(scat_env_init(env));
    SCAT_CALL(scat_release_reset(env));
    SCAT_CALL(scat_mif_reset_stale_read_wait_rlast(env));

    SCAT_CALL(scat_env_init(env));
    SCAT_CALL(scat_release_reset(env));
    SCAT_CALL(scat_mif_reset_stale_write_drain(env));
    return 0;
}

#ifdef NPU_SINGLE_CORE_AXI_TARGET_STANDALONE
int main(void)
{
    int line = test_single_core_axi_target();

    if (line != 0) {
        (void)printf(
            "single core AXI target test failed at line %d\n",
            line);
        return 1;
    }
    (void)printf("single core AXI target test passed\n");
    return 0;
}
#endif
