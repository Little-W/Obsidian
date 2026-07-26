#include "npu_engine_data_cycle.h"

#include <limits.h>
#include <string.h>

#define NPU_ENGINE_DATA_FAULT_ADDR_MASK \
    UINT64_C(0x0000ffffffffffff)

static _Thread_local npu_engine_data_cycle_t
    *npu_engine_data_current_capture;

static uint8_t npu_engine_data_select_port(
    const void *context,
    npu_space_t space,
    uint64_t aligned_addr);

static npu_engine_data_cycle_t *
npu_engine_data_active_capture(
    const npu_model_t *functional_model)
{
    npu_bus_trace_t *trace;
    npu_engine_data_cycle_t *model;

    if (npu_engine_data_current_capture !=
            (npu_engine_data_cycle_t *)0 &&
        (functional_model == (const npu_model_t *)0 ||
         npu_engine_data_current_capture
                 ->engine.functional_model ==
             functional_model)) {
        return npu_engine_data_current_capture;
    }
    if (functional_model == (const npu_model_t *)0 ||
        functional_model->internal_bus_trace == (void *)0) {
        return (npu_engine_data_cycle_t *)0;
    }
    trace = (npu_bus_trace_t *)
        functional_model->internal_bus_trace;
    if (trace->active == 0u ||
        trace->select_read_port !=
            npu_engine_data_select_port ||
        trace->select_read_port_context ==
            (const void *)0) {
        return (npu_engine_data_cycle_t *)0;
    }
    model = (npu_engine_data_cycle_t *)
        trace->select_read_port_context;
    if (model->initialized == 0u ||
        &model->trace != trace ||
        model->engine.functional_model !=
            functional_model) {
        return (npu_engine_data_cycle_t *)0;
    }
    return model;
}

void npu_engine_data_record_integer_range(
    const npu_model_t *functional_model,
    npu_dtype_t dtype)
{
    npu_engine_data_cycle_t *model =
        npu_engine_data_active_capture(functional_model);

    if (model == (npu_engine_data_cycle_t *)0) {
        return;
    }
    if (model->engine.engine == NPU_ENGINE_MATRIX) {
        if (dtype == NPU_DTYPE_INT32) {
            model->me_acc_overflow_latched = 1u;
        }
    } else if (model->engine.engine ==
               NPU_ENGINE_VECTOR) {
        model->ive_overflow_latched = 1u;
    } else if (model->engine.engine ==
               NPU_ENGINE_COMPLEX) {
        model->cme_numeric_flags_latched |=
            NPU_ENGINE_DATA_CME_OUTPUT_RANGE;
    }
}

void npu_engine_data_record_cme_numeric(
    const npu_model_t *functional_model,
    uint8_t flags)
{
    npu_engine_data_cycle_t *model =
        npu_engine_data_active_capture(functional_model);
    const uint8_t allowed =
        NPU_ENGINE_DATA_CME_ALL_MASK |
        NPU_ENGINE_DATA_CME_OUTPUT_RANGE |
        NPU_ENGINE_DATA_CME_FP_INF |
        NPU_ENGINE_DATA_CME_FP_NAN |
        NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO;

    if (model == (npu_engine_data_cycle_t *)0 ||
        model->engine.engine != NPU_ENGINE_COMPLEX) {
        return;
    }
    model->cme_numeric_flags_latched |=
        (uint8_t)(flags & allowed);
}

static void npu_engine_data_clear_numeric(
    npu_engine_data_cycle_t *model)
{
    model->me_acc_overflow_latched = 0u;
    model->ive_overflow_latched = 0u;
    model->cme_numeric_flags_latched = 0u;
}

static uint64_t npu_engine_data_add_limit(uint64_t a,
                                          uint64_t b)
{
    return UINT64_MAX - a < b ? UINT64_MAX : a + b;
}

static uint64_t npu_engine_data_mul_limit(uint64_t a,
                                          uint64_t b)
{
    return a != 0u && b > UINT64_MAX / a
               ? UINT64_MAX
               : a * b;
}

static uint32_t npu_engine_data_dtype_bytes(
    npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT32) {
        return 4u;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return 2u;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return 1u;
    }
    return 0u;
}

static uint32_t npu_engine_data_dtype_bits(
    npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return 4u;
    }
    return npu_engine_data_dtype_bytes(dtype) * 8u;
}

static uint64_t npu_engine_data_ceil_div(
    uint64_t value,
    uint64_t divisor)
{
    if (value == 0u || divisor == 0u) {
        return 0u;
    }
    return 1u + (value - 1u) / divisor;
}

static uint64_t npu_engine_data_active_elements(
    uint32_t rows,
    uint32_t length,
    uint32_t valid_length)
{
    if (rows == 0u) {
        return 0u;
    }
    return npu_engine_data_add_limit(
        npu_engine_data_mul_limit(rows - 1u, length),
        valid_length);
}

static uint8_t npu_engine_data_lane_mask(uint32_t lanes)
{
    if (lanes == 0u) {
        return 0u;
    }
    if (lanes >= 8u) {
        return 0xffu;
    }
    return (uint8_t)((UINT32_C(1) << lanes) - 1u);
}

static uint8_t npu_engine_data_popcount8(uint8_t value)
{
    uint8_t count = 0u;

    while (value != 0u) {
        count += (uint8_t)(value & 1u);
        value >>= 1u;
    }
    return count;
}

static uint64_t npu_engine_data_tensor_span(
    const npu_tensor_t *tensor,
    uint32_t batches,
    uint32_t rows,
    uint32_t length)
{
    uint64_t span;
    uint64_t part;
    uint64_t element_part;
    uint32_t element_bytes;

    if (tensor == (const npu_tensor_t *)0 ||
        batches == 0u || rows == 0u || length == 0u) {
        return 0u;
    }
    span = npu_engine_data_mul_limit(
        batches - 1u, tensor->batch_stride_bytes);
    part = npu_engine_data_mul_limit(
        rows - 1u, tensor->row_stride_bytes);
    span = npu_engine_data_add_limit(span, part);
    if (tensor->dtype == NPU_DTYPE_INT4) {
        if (tensor->elem_stride_bytes == 0u) {
            element_part =
                ((uint64_t)tensor->start_nibble +
                 length + 1u) /
                2u;
        } else {
            element_part = npu_engine_data_add_limit(
                npu_engine_data_mul_limit(
                    length - 1u,
                    tensor->elem_stride_bytes),
                1u);
        }
    } else {
        element_bytes =
            npu_engine_data_dtype_bytes(tensor->dtype);
        if (tensor->elem_stride_bytes == 0u) {
            element_part = npu_engine_data_mul_limit(
                length, element_bytes);
        } else {
            element_part = npu_engine_data_add_limit(
                npu_engine_data_mul_limit(
                    length - 1u,
                    tensor->elem_stride_bytes),
                element_bytes);
        }
    }
    span = npu_engine_data_add_limit(span, element_part);
    if (tensor->region_bytes != 0u &&
        span > tensor->region_bytes) {
        span = tensor->region_bytes;
    }
    return span;
}

static int npu_engine_data_range_hits_word(
    npu_space_t range_space,
    uint64_t range_addr,
    uint64_t range_bytes,
    npu_space_t access_space,
    uint64_t aligned_addr)
{
    uint64_t range_end;
    uint64_t word_end;

    if (range_space != access_space ||
        range_bytes == 0u) {
        return 0;
    }
    range_end =
        npu_engine_data_add_limit(range_addr, range_bytes);
    word_end = npu_engine_data_add_limit(
        aligned_addr, NPU_BUS_TRACE_WORD_BYTES);
    return range_addr < word_end &&
           aligned_addr < range_end;
}

static int npu_engine_data_tensor_hits_word(
    const npu_tensor_t *tensor,
    uint32_t batches,
    uint32_t rows,
    uint32_t length,
    npu_space_t access_space,
    uint64_t aligned_addr)
{
    return npu_engine_data_range_hits_word(
        tensor->space, tensor->addr,
        npu_engine_data_tensor_span(
            tensor, batches, rows, length),
        access_space, aligned_addr);
}

static void npu_engine_data_broadcast_shape(
    npu_broadcast_t broadcast,
    uint32_t rows,
    uint32_t length,
    uint32_t *source_rows,
    uint32_t *source_length)
{
    *source_rows = rows;
    *source_length = length;
    if (broadcast == NPU_BROADCAST_SCALAR) {
        *source_rows = 1u;
        *source_length = 1u;
    } else if (broadcast == NPU_BROADCAST_ROW) {
        *source_length = 1u;
    } else if (broadcast == NPU_BROADCAST_FEATURE) {
        *source_rows = 1u;
    }
}

static uint8_t npu_engine_data_vector_port(
    const npu_engine_data_cycle_t *model,
    npu_space_t space,
    uint64_t addr)
{
    const npu_vector_desc_t *desc =
        &model->engine.request.desc.vector;
    uint32_t rows;
    uint32_t length;

    npu_engine_data_broadcast_shape(
        desc->broadcast0, desc->rows, desc->length,
        &rows, &length);
    if (npu_engine_data_tensor_hits_word(
            &desc->src0, 1u, rows, length,
            space, addr)) {
        return 0u;
    }
    if (desc->src1_from_scalar0 == 0u) {
        npu_engine_data_broadcast_shape(
            desc->broadcast1, desc->rows,
            desc->length, &rows, &length);
        if (npu_engine_data_tensor_hits_word(
                &desc->src1, 1u, rows, length,
                space, addr)) {
            return 1u;
        }
    }
    if (desc->src2_from_scalar1 == 0u) {
        npu_engine_data_broadcast_shape(
            desc->broadcast2, desc->rows,
            desc->length, &rows, &length);
        if (npu_engine_data_tensor_hits_word(
                &desc->src2, 1u, rows, length,
                space, addr)) {
            return 2u;
        }
    }
    if (desc->mask_enable != 0u &&
        npu_engine_data_tensor_hits_word(
            &desc->mask, 1u, desc->rows,
            desc->length, space, addr)) {
        return 3u;
    }
    if (desc->mask_false_keep_dst != 0u &&
        npu_engine_data_tensor_hits_word(
            &desc->dst, 1u, desc->rows,
            desc->length, space, addr)) {
        return 2u;
    }
    return NPU_BUS_TRACE_IGNORE_PORT;
}

static uint64_t npu_engine_data_matrix_b_span(
    const npu_engine_data_cycle_t *model,
    const npu_matrix_desc_t *desc)
{
    uint64_t k_tiles;
    uint64_t n_tiles;
    uint64_t elements;
    uint64_t bytes;

    if (desc->b_tiled == 0u) {
        return npu_engine_data_tensor_span(
            &desc->b, desc->batch_count,
            desc->transpose_b != 0u ? desc->n : desc->k,
            desc->transpose_b != 0u ? desc->k : desc->n);
    }
    k_tiles =
        ((uint64_t)desc->k +
         model->engine.functional_model->config.kt - 1u) /
        model->engine.functional_model->config.kt;
    n_tiles =
        ((uint64_t)desc->n +
         model->engine.functional_model->config.nt - 1u) /
        model->engine.functional_model->config.nt;
    elements = npu_engine_data_mul_limit(k_tiles, n_tiles);
    elements = npu_engine_data_mul_limit(
        elements,
        model->engine.functional_model->config.kt);
    elements = npu_engine_data_mul_limit(
        elements,
        model->engine.functional_model->config.nt);
    bytes = desc->b.dtype == NPU_DTYPE_INT4
                ? npu_engine_data_add_limit(elements, 1u) / 2u
                : npu_engine_data_mul_limit(
                      elements,
                      npu_engine_data_dtype_bytes(desc->b.dtype));
    if (desc->batch_count > 1u) {
        bytes = npu_engine_data_add_limit(
            npu_engine_data_mul_limit(
                desc->batch_count - 1u,
                desc->b.batch_stride_bytes),
            bytes);
    }
    return bytes;
}

static uint8_t npu_engine_data_matrix_port(
    const npu_engine_data_cycle_t *model,
    npu_space_t space,
    uint64_t addr)
{
    const npu_matrix_desc_t *desc =
        &model->engine.request.desc.matrix;
    uint32_t a_rows =
        desc->transpose_a != 0u ? desc->k : desc->m;
    uint32_t a_length =
        desc->transpose_a != 0u ? desc->m : desc->k;

    if (npu_engine_data_tensor_hits_word(
            &desc->a, desc->batch_count,
            a_rows, a_length, space, addr)) {
        return 0u;
    }
    if (npu_engine_data_range_hits_word(
            desc->b.space, desc->b.addr,
            npu_engine_data_matrix_b_span(model, desc),
            space, addr)) {
        return 1u;
    }
    if ((desc->residual_enable != 0u ||
         desc->accum_from_src2 != 0u) &&
        npu_engine_data_tensor_hits_word(
            &desc->src2, desc->batch_count,
            desc->m, desc->n, space, addr)) {
        return 2u;
    }
    if (desc->bias_enable != 0u &&
        npu_engine_data_range_hits_word(
            NPU_SPACE_L1, desc->bias_addr,
            npu_engine_data_mul_limit(
                desc->bias_count,
                desc->bias_stride_bytes),
            space, addr)) {
        return 2u;
    }
    if (desc->requant_enable != 0u &&
        desc->inline_requant_enable == 0u &&
        npu_engine_data_range_hits_word(
            NPU_SPACE_L1, desc->requant_addr,
            npu_engine_data_mul_limit(
                desc->requant_count, 8u),
            space, addr)) {
        return 2u;
    }
    return NPU_BUS_TRACE_IGNORE_PORT;
}

static uint8_t npu_engine_data_complex_port(
    const npu_engine_data_cycle_t *model,
    npu_space_t space,
    uint64_t addr)
{
    const npu_complex_desc_t *desc =
        &model->engine.request.desc.complex;

    if (npu_engine_data_tensor_hits_word(
            &desc->src0, 1u, desc->rows,
            desc->length, space, addr)) {
        return 0u;
    }
    if (npu_engine_data_tensor_hits_word(
            &desc->src1, 1u,
            desc->function == NPU_FUNC_LAYERNORM ||
                    desc->function == NPU_FUNC_RMSNORM
                ? 1u
                : desc->rows,
            desc->length, space, addr)) {
        return 1u;
    }
    if (npu_engine_data_tensor_hits_word(
            &desc->src2, 1u,
            desc->function == NPU_FUNC_LAYERNORM ? 1u
                                                 : desc->rows,
            desc->length, space, addr)) {
        return 2u;
    }
    if (desc->mask_mode == NPU_MASK_BOOLEAN &&
        npu_engine_data_tensor_hits_word(
            &desc->mask, 1u, desc->rows,
            desc->length, space, addr)) {
        return 3u;
    }
    if (desc->mask_mode == NPU_MASK_VALID_LENGTH &&
        npu_engine_data_tensor_hits_word(
            &desc->valid_lengths, 1u, desc->rows,
            1u, space, addr)) {
        return 3u;
    }
    if (desc->scale_mode == NPU_SCALE_PER_FEATURE &&
        (npu_engine_data_range_hits_word(
             NPU_SPACE_L1,
             desc->src0_scale_table_addr,
             npu_engine_data_mul_limit(desc->length, 4u),
             space, addr) ||
         npu_engine_data_range_hits_word(
             NPU_SPACE_L1,
             desc->dst_scale_table_addr,
             npu_engine_data_mul_limit(desc->length, 4u),
             space, addr))) {
        return 1u;
    }
    return NPU_BUS_TRACE_IGNORE_PORT;
}

static uint8_t npu_engine_data_select_port(
    const void *context,
    npu_space_t space,
    uint64_t aligned_addr)
{
    const npu_engine_data_cycle_t *model =
        (const npu_engine_data_cycle_t *)context;

    if (model == (const npu_engine_data_cycle_t *)0) {
        return NPU_BUS_TRACE_IGNORE_PORT;
    }
    if (model->engine.engine == NPU_ENGINE_DMA) {
        const npu_dma_desc_t *desc =
            &model->engine.request.desc.dma;

        if (model->engine.opcode == NPU_DMA_FILL) {
            return NPU_BUS_TRACE_IGNORE_PORT;
        }
        return npu_engine_data_range_hits_word(
                   desc->src_space, desc->src_addr,
                   desc->src_region_bytes, space,
                   aligned_addr)
                   ? 0u
                   : NPU_BUS_TRACE_IGNORE_PORT;
    }
    if (model->engine.engine == NPU_ENGINE_MATRIX) {
        return npu_engine_data_matrix_port(
            model, space, aligned_addr);
    }
    if (model->engine.engine == NPU_ENGINE_VECTOR) {
        return npu_engine_data_vector_port(
            model, space, aligned_addr);
    }
    if (model->engine.engine == NPU_ENGINE_COMPLEX) {
        return npu_engine_data_complex_port(
            model, space, aligned_addr);
    }
    return NPU_BUS_TRACE_IGNORE_PORT;
}

#define NPU_PERF_DELTA_FIELD(name) \
    delta->name = after->name - before->name

static void npu_engine_data_perf_delta(
    npu_perf_t *delta,
    const npu_perf_t *before,
    const npu_perf_t *after)
{
    NPU_PERF_DELTA_FIELD(core_active_cycles);
    NPU_PERF_DELTA_FIELD(cmd_accepted);
    NPU_PERF_DELTA_FIELD(task_success);
    NPU_PERF_DELTA_FIELD(task_failed);
    NPU_PERF_DELTA_FIELD(dma_read_bytes);
    NPU_PERF_DELTA_FIELD(dma_write_bytes);
    NPU_PERF_DELTA_FIELD(dma_stall_cycles);
    NPU_PERF_DELTA_FIELD(l1_bank_stall_cycles);
    NPU_PERF_DELTA_FIELD(matrix_mac_active_cycles);
    NPU_PERF_DELTA_FIELD(matrix_operand_stall_cycles);
    NPU_PERF_DELTA_FIELD(ive_active_cycles);
    NPU_PERF_DELTA_FIELD(cme_fp_active_cycles);
    NPU_PERF_DELTA_FIELD(cme_l1_stall_cycles);
    NPU_PERF_DELTA_FIELD(int_saturate_count);
    NPU_PERF_DELTA_FIELD(all_mask_row_count);
    NPU_PERF_DELTA_FIELD(ecc_corrected_count);
}

#undef NPU_PERF_DELTA_FIELD

static uint64_t npu_engine_data_trace_bytes(
    const npu_bus_trace_entry_t *entry,
    size_t count,
    npu_space_t space)
{
    uint64_t bytes = 0u;
    size_t index;

    for (index = 0u; index < count; index++) {
        if (entry[index].space == (uint8_t)space) {
            bytes += npu_engine_data_popcount8(
                entry[index].strb);
        }
    }
    return bytes;
}

static void npu_engine_data_dma_perf_from_trace(
    npu_engine_data_cycle_t *model)
{
    const npu_dma_desc_t *desc;

    if (model->engine.engine != NPU_ENGINE_DMA) {
        return;
    }
    desc = &model->engine.request.desc.dma;
    model->perf_delta.dma_read_bytes =
        desc->src_space == NPU_SPACE_DDR
            ? npu_engine_data_trace_bytes(
                  model->trace.read,
                  model->trace.read_count,
                  NPU_SPACE_DDR)
            : 0u;
    model->perf_delta.dma_write_bytes =
        desc->dst_space == NPU_SPACE_DDR
            ? npu_engine_data_trace_bytes(
                  model->trace.write,
                  model->trace.write_count,
                  NPU_SPACE_DDR)
            : 0u;
}

static uint8_t npu_engine_data_raw_dma_param_write(
    const npu_engine_data_cycle_t *model)
{
    const npu_dma_desc_t *desc;

    if (model->engine.engine != NPU_ENGINE_DMA ||
        (model->engine.opcode != NPU_DMA_COPY_1D &&
         model->engine.opcode != NPU_DMA_COPY_ND)) {
        return 0u;
    }
    desc = &model->engine.request.desc.dma;
    return desc->convert_mode == NPU_DMA_CONVERT_NONE
               ? 1u
               : 0u;
}

static uint8_t npu_engine_data_param_fault(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    uint64_t *fault_addr)
{
    uint64_t base = inputs->param_l1_base;
    uint64_t limit = inputs->param_l1_limit;
    size_t index;

    if (base >= limit ||
        (inputs->param_lock == 0u &&
         npu_engine_data_raw_dma_param_write(model) !=
             0u)) {
        return 0u;
    }
    for (index = 0u; index < model->trace.write_count;
         index++) {
        const npu_bus_trace_entry_t *entry =
            &model->trace.write[index];
        uint64_t end;

        if (entry->space != NPU_SPACE_L1) {
            continue;
        }
        end = entry->addr + NPU_BUS_TRACE_WORD_BYTES;
        if (entry->addr < limit && end > base) {
            *fault_addr =
                entry->addr < base ? base : entry->addr;
            return 1u;
        }
    }
    return 0u;
}

static void npu_engine_data_set_param_fault(
    npu_engine_data_cycle_t *model,
    uint64_t fault_addr)
{
    model->engine.pending_status = NPU_STATUS_ADDR_FAULT;
    model->engine.pending_error_info =
        npu_engine_cycle_error_info(
            NPU_ENGINE_ERROR_EXECUTE,
            NPU_STATUS_ADDR_FAULT,
            NPU_ENGINE_INVALID_DESC_WORD,
            model->engine.opcode);
    model->engine.pending_fault_addr = fault_addr;
    model->engine.pending_done_flags =
        NPU_DONE_FAULT_ADDR_IS_L1;
    model->engine.pending_progress = 0u;
}

#define NPU_PERF_ADD_FIELD(name) model->name += delta->name

static void npu_engine_data_perf_add(
    npu_perf_t *model,
    const npu_perf_t *delta)
{
    NPU_PERF_ADD_FIELD(core_active_cycles);
    NPU_PERF_ADD_FIELD(cmd_accepted);
    NPU_PERF_ADD_FIELD(task_success);
    NPU_PERF_ADD_FIELD(task_failed);
    NPU_PERF_ADD_FIELD(dma_read_bytes);
    NPU_PERF_ADD_FIELD(dma_write_bytes);
    NPU_PERF_ADD_FIELD(dma_stall_cycles);
    NPU_PERF_ADD_FIELD(l1_bank_stall_cycles);
    NPU_PERF_ADD_FIELD(matrix_mac_active_cycles);
    NPU_PERF_ADD_FIELD(matrix_operand_stall_cycles);
    NPU_PERF_ADD_FIELD(ive_active_cycles);
    NPU_PERF_ADD_FIELD(cme_fp_active_cycles);
    NPU_PERF_ADD_FIELD(cme_l1_stall_cycles);
    NPU_PERF_ADD_FIELD(int_saturate_count);
    NPU_PERF_ADD_FIELD(all_mask_row_count);
    NPU_PERF_ADD_FIELD(ecc_corrected_count);
}

#undef NPU_PERF_ADD_FIELD

static uint8_t npu_engine_data_cancel_valid(uint8_t status)
{
    return status == (uint8_t)NPU_STATUS_TIMEOUT ||
                   status == (uint8_t)NPU_STATUS_ABORTED
               ? 1u
               : 0u;
}

static uint8_t npu_engine_data_replay_cancel_ready(
    const npu_engine_data_cycle_t *model,
    uint8_t status)
{
    return model->data_pending != 0u &&
                   model->replay.aborting == 0u &&
                   model->replay.terminal_locked == 0u &&
                   model->replay.state != NPU_BUS_REPLAY_IDLE &&
                   model->replay.state != NPU_BUS_REPLAY_DONE &&
                   npu_engine_data_cancel_valid(status) != 0u
               ? 1u
               : 0u;
}

static void npu_engine_data_pack_done(
    npu_engine_data_cycle_t *model,
    const npu_bus_replay_cycle_outputs_t *replay)
{
    uint32_t error_info;
    uint64_t fault_addr = replay->done_fault_addr;
    uint16_t done_flags = replay->done_flags;
    uint64_t progress = replay->done_progress;
    uint64_t beat0;
    uint64_t beat1;

    if (replay->done_status ==
        (uint8_t)model->engine.pending_status) {
        error_info = model->engine.pending_error_info;
        if (replay->done_status != NPU_STATUS_SUCCESS) {
            fault_addr =
                model->engine.pending_fault_addr;
            done_flags =
                model->engine.pending_done_flags;
            progress =
                model->engine.pending_progress;
        }
    } else {
        error_info = replay->done_status == NPU_STATUS_SUCCESS
                         ? 0u
                         : npu_engine_cycle_error_info(
                               replay->done_status ==
                                       NPU_STATUS_ABORTED
                                   ? NPU_ENGINE_ERROR_ABORT
                                   : NPU_ENGINE_ERROR_EXECUTE,
                               replay->done_status ==
                                       NPU_STATUS_ABORTED
                                   ? 0u
                                   : replay->done_status,
                               NPU_ENGINE_INVALID_DESC_WORD,
                               model->engine.opcode);
    }
    model->engine.pending_status =
        (npu_status_t)replay->done_status;
    model->engine.pending_error_info = error_info;
    model->engine.pending_fault_addr =
        fault_addr &
        NPU_ENGINE_DATA_FAULT_ADDR_MASK;
    model->engine.pending_done_flags =
        done_flags;
    model->engine.pending_progress =
        progress;

    beat0 =
        (uint64_t)(model->engine.task_id & 0x0fffu) |
        ((uint64_t)replay->done_status << 12u) |
        ((uint64_t)error_info << 20u) |
        ((uint64_t)(done_flags & 0x0fffu)
         << 52u);
    beat1 =
        (fault_addr &
         NPU_ENGINE_DATA_FAULT_ADDR_MASK) |
        ((uint64_t)model->engine.engine << 48u) |
        ((uint64_t)model->engine.opcode << 52u);
    model->engine.done_data[0] = beat0;
    model->engine.done_data[1] = beat1;
    model->engine.done_data[2] = progress;
    model->engine.done_beat = 0u;

}

static void npu_engine_data_build_replay_inputs(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    uint8_t cancel_handshake,
    npu_bus_replay_cycle_inputs_t *replay_inputs)
{
    uint32_t port;

    (void)memset(
        replay_inputs, 0, sizeof(*replay_inputs));
    replay_inputs->reset_n = inputs->engine.reset_n;
    replay_inputs->done_ready = 1u;
    replay_inputs->compute_done =
        model->compute_stage ==
                NPU_ENGINE_DATA_COMPUTE_DONE
            ? 1u
            : 0u;
    replay_inputs->abort =
        (uint8_t)(inputs->engine.eng_abort_i != 0u ||
                  cancel_handshake != 0u);
    replay_inputs->abort_status =
        cancel_handshake != 0u
            ? inputs->engine.eng_cancel_status_i
            : (uint8_t)NPU_STATUS_ABORTED;
    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        replay_inputs->l1_read[port] =
            inputs->l1_read[port];
    }
    replay_inputs->l1_write = inputs->l1_write;
    replay_inputs->mif = inputs->mif;
}

static void npu_engine_data_copy_replay_outputs(
    const npu_bus_replay_cycle_outputs_t *replay,
    npu_engine_data_cycle_outputs_t *outputs)
{
    uint32_t port;

    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        outputs->l1_read[port] = replay->l1_read[port];
    }
    outputs->l1_write = replay->l1_write;
    outputs->mif = replay->mif;
    outputs->data_busy = replay->busy;
    outputs->data_quiescent = replay->quiescent;
}

static uint32_t npu_engine_data_vector_lanes(
    const npu_engine_data_cycle_t *model)
{
    const npu_vector_desc_t *desc =
        &model->engine.request.desc.vector;
    uint32_t width =
        npu_engine_data_dtype_bits(desc->src0.dtype);
    uint32_t lanes;

    if (npu_engine_data_dtype_bits(desc->dst.dtype) > width) {
        width = npu_engine_data_dtype_bits(desc->dst.dtype);
    }
    lanes = width == 0u
                ? 0u
                : NPU_REF_BUS_DATA_BITS / width;
    if (lanes > model->engine.functional_model
                    ->config.vector_lanes) {
        lanes = model->engine.functional_model
                    ->config.vector_lanes;
    }
    if (lanes > 8u) {
        lanes = 8u;
    }
    return lanes;
}

static uint64_t npu_engine_data_cme_function_latency(
    npu_function_t function)
{
    if (function == NPU_FUNC_SIGMOID ||
        function == NPU_FUNC_TANH) {
        return 10u;
    }
    if (function == NPU_FUNC_GELU) {
        return 16u;
    }
    if (function == NPU_FUNC_SILU) {
        return 12u;
    }
    if (function == NPU_FUNC_RECIPROCAL_SQRT) {
        return 8u;
    }
    if (function == NPU_FUNC_RECIPROCAL) {
        return 6u;
    }
    return 1u;
}

static uint64_t npu_engine_data_pipeline_cycles(
    uint64_t groups,
    uint64_t latency)
{
    if (groups == 0u || latency == 0u) {
        return 0u;
    }
    return npu_engine_data_add_limit(
        groups, latency - 1u);
}

static uint64_t npu_engine_data_max_u64(
    uint64_t first,
    uint64_t second)
{
    return first > second ? first : second;
}

static uint8_t npu_engine_data_cme_single_pass(
    const npu_complex_desc_t *desc)
{
    return desc->function != NPU_FUNC_SOFTMAX &&
                   desc->function != NPU_FUNC_LAYERNORM &&
                   desc->function != NPU_FUNC_RMSNORM &&
                   desc->function != NPU_FUNC_STAT_SUM &&
                   desc->function != NPU_FUNC_STAT_MAX &&
                   desc->function != NPU_FUNC_STAT_SUMSQ
               ? 1u
               : 0u;
}

static void npu_engine_data_prepare_cme_compute(
    npu_engine_data_cycle_t *model,
    const npu_complex_desc_t *desc,
    uint64_t groups,
    uint32_t lanes)
{
    uint64_t rows = desc->rows;
    uint64_t i2f_launches = groups;
    uint64_t fp_prefix = 0u;
    uint64_t final_latency;
    uint64_t fp_end;
    uint64_t f2i_end;
    uint64_t i2f_end;

    /*
     * The direct-function case is one pipelined launch per four-element
     * group. Composite opcodes use a deterministic reference work schedule:
     *
     * Softmax:
     *   max groups; Exp+sum groups; one Reciprocal per row;
     *   final Exp+multiply groups.
     * LayerNorm TWO_PASS:
     *   mean groups; row Reciprocal; variance groups; row Reciprocal,
     *   multiply and ReciprocalSqrt; final normalize groups.
     * LayerNorm WELFORD:
     *   Welford groups; row Reciprocal/multiply/ReciprocalSqrt;
     *   final normalize groups.
     * RMSNorm:
     *   square+sum groups; row Reciprocal/multiply/add/ReciprocalSqrt;
     *   final two-multiply normalize groups.
     * ADD_RESCALE:
     *   one FP add launch per group.
     *
     * Pipeline(x, L) below means L + x - 1 active cycles. Segments in
     * fp_prefix are issued serially because a later segment consumes a
     * row result from the earlier segment. The final vector segment is
     * pipelined into F2I, so their valid windows overlap for multiple groups.
     */
    if (desc->function == NPU_FUNC_STAT_SUM ||
        desc->function == NPU_FUNC_STAT_MAX ||
        desc->function == NPU_FUNC_STAT_SUMSQ) {
        return;
    }
    if (desc->function == NPU_FUNC_SOFTMAX) {
        i2f_launches =
            npu_engine_data_mul_limit(groups, 3u);
        fp_prefix = groups;
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(groups, 8u));
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(rows, 6u));
        final_latency = 9u;
    } else if (desc->function ==
               NPU_FUNC_LAYERNORM) {
        if (desc->stats_mode == 0u) {
            i2f_launches =
                npu_engine_data_mul_limit(groups, 3u);
            fp_prefix = groups;
            fp_prefix = npu_engine_data_add_limit(
                fp_prefix,
                npu_engine_data_pipeline_cycles(
                    rows, 6u));
            fp_prefix = npu_engine_data_add_limit(
                fp_prefix,
                npu_engine_data_pipeline_cycles(
                    groups, 3u));
        } else {
            i2f_launches =
                npu_engine_data_mul_limit(groups, 2u);
            fp_prefix =
                npu_engine_data_pipeline_cycles(
                    groups, 6u);
        }
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(rows, 6u));
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix, rows);
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(rows, 8u));
        final_latency = 4u;
    } else if (desc->function == NPU_FUNC_RMSNORM) {
        i2f_launches =
            npu_engine_data_mul_limit(groups, 2u);
        fp_prefix =
            npu_engine_data_pipeline_cycles(groups, 2u);
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(rows, 6u));
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_mul_limit(rows, 2u));
        fp_prefix = npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(rows, 8u));
        final_latency = 2u;
    } else {
        final_latency =
            npu_engine_data_cme_function_latency(
                desc->function);
        model->cme_direct_stream = 1u;
        model->cme_direct_fp_latency =
            (uint8_t)final_latency;
    }

    model->cme_i2f_start = 0u;
    model->cme_i2f_cycles =
        npu_engine_data_pipeline_cycles(
            i2f_launches, 3u);
    model->cme_fp_start = 3u;
    model->cme_fp_cycles =
        npu_engine_data_add_limit(
            fp_prefix,
            npu_engine_data_pipeline_cycles(
                groups, final_latency));
    model->cme_f2i_start =
        npu_engine_data_add_limit(
            model->cme_fp_start,
            npu_engine_data_add_limit(
                fp_prefix, final_latency));
    model->cme_f2i_cycles =
        npu_engine_data_pipeline_cycles(groups, 4u);

    i2f_end = npu_engine_data_add_limit(
        model->cme_i2f_start,
        model->cme_i2f_cycles);
    fp_end = npu_engine_data_add_limit(
        model->cme_fp_start,
        model->cme_fp_cycles);
    f2i_end = npu_engine_data_add_limit(
        model->cme_f2i_start,
        model->cme_f2i_cycles);
    model->compute_total_cycles =
        npu_engine_data_max_u64(
            i2f_end,
            npu_engine_data_max_u64(fp_end, f2i_end));
    if (model->compute_total_cycles == 0u) {
        return;
    }
    model->compute_stage =
        NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE;
    model->compute_stage_remaining =
        model->compute_total_cycles;
    model->compute_groups = groups;
    model->compute_lanes = lanes;
}

static void npu_engine_data_clear_compute(
    npu_engine_data_cycle_t *model)
{
    model->compute_stage =
        NPU_ENGINE_DATA_COMPUTE_DONE;
    model->compute_stage_remaining = 0u;
    model->compute_groups = 0u;
    model->compute_groups_issued = 0u;
    model->compute_lanes = 0u;
    model->compute_full_lane_mask = 0u;
    model->compute_tail_lane_mask = 0u;
    model->compute_elapsed = 0u;
    model->compute_total_cycles = 0u;
    model->cme_i2f_start = 0u;
    model->cme_i2f_cycles = 0u;
    model->cme_fp_start = 0u;
    model->cme_fp_cycles = 0u;
    model->cme_f2i_start = 0u;
    model->cme_f2i_cycles = 0u;
    model->stream_compute = 0u;
    model->cme_direct_stream = 0u;
    model->cme_direct_fp_latency = 0u;
    model->cme_i2f_tokens = 0u;
    model->cme_fp_tokens = 0u;
    model->cme_f2i_tokens = 0u;
}

static void npu_engine_data_prepare_compute(
    npu_engine_data_cycle_t *model)
{
    uint64_t elements;
    uint64_t groups;

    npu_engine_data_clear_compute(model);

    if (model->engine.engine == NPU_ENGINE_MATRIX) {
        const npu_matrix_desc_t *desc =
            &model->engine.request.desc.matrix;
        uint64_t groups_m;
        uint64_t groups_n;
        uint64_t groups_k;

        if (model->engine.opcode ==
            NPU_MATRIX_GEMM_ZERO) {
            return;
        }
        groups_m = npu_engine_data_ceil_div(
            desc->m,
            model->engine.functional_model->config.mt);
        groups_n = npu_engine_data_ceil_div(
            desc->n,
            model->engine.functional_model->config.nt);
        groups_k = npu_engine_data_ceil_div(
            desc->k,
            model->engine.functional_model->config.kt);
        groups = npu_engine_data_mul_limit(
            desc->batch_count, groups_m);
        groups = npu_engine_data_mul_limit(groups, groups_n);
        groups = npu_engine_data_mul_limit(groups, groups_k);
        if (groups != 0u) {
            model->compute_stage =
                NPU_ENGINE_DATA_COMPUTE_ME;
            model->compute_stage_remaining = groups;
            model->compute_groups = groups;
            model->stream_compute = 1u;
        }
        return;
    }

    if (model->engine.engine == NPU_ENGINE_VECTOR) {
        const npu_vector_desc_t *desc =
            &model->engine.request.desc.vector;
        uint64_t tail_lanes;
        uint32_t lanes =
            npu_engine_data_vector_lanes(model);

        elements = npu_engine_data_active_elements(
            desc->rows, desc->length,
            desc->valid_length);
        groups = npu_engine_data_ceil_div(elements, lanes);
        if (groups == 0u || lanes == 0u) {
            return;
        }
        tail_lanes = elements % lanes;
        if (tail_lanes == 0u) {
            tail_lanes = lanes;
        }
        model->compute_stage =
            NPU_ENGINE_DATA_COMPUTE_IVE;
        model->compute_stage_remaining = groups;
        model->compute_groups = groups;
        model->compute_lanes = lanes;
        model->compute_full_lane_mask =
            npu_engine_data_lane_mask(lanes);
        model->compute_tail_lane_mask =
            npu_engine_data_lane_mask(
                (uint32_t)tail_lanes);
        model->stream_compute = 1u;
        return;
    }

    if (model->engine.engine == NPU_ENGINE_COMPLEX) {
        const npu_complex_desc_t *desc =
            &model->engine.request.desc.complex;
        uint32_t lanes =
            model->engine.functional_model
                ->config.cme_lanes;

        if (lanes > NPU_REF_CME_LANES) {
            lanes = NPU_REF_CME_LANES;
        }
        elements = npu_engine_data_active_elements(
            desc->rows, desc->length,
            desc->valid_length);
        groups = npu_engine_data_ceil_div(elements, lanes);
        if (groups == 0u || lanes == 0u) {
            return;
        }
        npu_engine_data_prepare_cme_compute(
            model, desc, groups, lanes);
        if (model->compute_stage ==
                NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE &&
            npu_engine_data_cme_single_pass(desc) != 0u) {
            model->stream_compute = 1u;
        }
    }
}

/*
 * Returns floor(a*b/divisor) without an overflowing intermediate.
 * The stream scheduler calls this with a<=divisor, so the result is no
 * greater than b.
 */
static uint64_t npu_engine_data_mul_div_floor(
    uint64_t a,
    uint64_t b,
    uint64_t divisor)
{
    uint64_t result = 0u;
    uint64_t remainder = 0u;
    uint64_t term_result = 0u;
    uint64_t term_remainder;

    if (a == 0u || b == 0u || divisor == 0u) {
        return 0u;
    }
    if (a >= divisor) {
        return b;
    }
    term_remainder = a;
    while (b != 0u) {
        if ((b & 1u) != 0u) {
            uint64_t carry = 0u;

            if (remainder >=
                divisor - term_remainder) {
                remainder -=
                    divisor - term_remainder;
                carry = 1u;
            } else {
                remainder += term_remainder;
            }
            result += term_result + carry;
        }
        b >>= 1u;
        if (b == 0u) {
            break;
        }
        if (term_remainder >=
            divisor - term_remainder) {
            term_remainder -=
                divisor - term_remainder;
            term_result =
                term_result * 2u + 1u;
        } else {
            term_remainder += term_remainder;
            term_result *= 2u;
        }
    }
    return result;
}

static uint64_t npu_engine_data_trace_port_words(
    const npu_engine_data_cycle_t *model,
    uint8_t port)
{
    uint64_t count = 0u;
    size_t index;

    for (index = 0u; index < model->trace.read_count;
         index++) {
        if (model->trace.read[index].port == port) {
            count++;
        }
    }
    return count;
}

static uint64_t npu_engine_data_ready_groups(
    const npu_engine_data_cycle_t *model,
    const npu_bus_replay_cycle_outputs_t *replay)
{
    uint64_t ready = model->compute_groups;
    uint8_t last_port =
        model->engine.engine == NPU_ENGINE_MATRIX
            ? 2u
            : NPU_ENGINE_DATA_READ_PORTS;
    uint8_t any_port = 0u;
    uint8_t port;

    for (port = 0u; port < last_port; port++) {
        uint64_t total =
            npu_engine_data_trace_port_words(
                model, port);
        uint64_t accepted;
        uint64_t port_ready;

        if (total == 0u) {
            continue;
        }
        any_port = 1u;
        accepted =
            replay->accepted_read_words_by_port[port];
        if (accepted > total) {
            accepted = total;
        }
        port_ready = npu_engine_data_mul_div_floor(
            accepted, model->compute_groups, total);
        if (port_ready < ready) {
            ready = port_ready;
        }
    }
    return any_port != 0u
               ? ready
               : model->compute_groups;
}

static uint8_t npu_engine_data_group_launch(
    const npu_engine_data_cycle_t *model,
    const npu_bus_replay_cycle_outputs_t *replay)
{
    if (replay->compute_valid == 0u ||
        model->compute_groups_issued >=
            model->compute_groups) {
        return 0u;
    }
    if (model->stream_compute == 0u) {
        return 1u;
    }
    return model->compute_groups_issued <
                   npu_engine_data_ready_groups(
                       model, replay)
               ? 1u
               : 0u;
}

static uint64_t npu_engine_data_stage_shift(
    uint64_t tokens,
    uint8_t latency,
    uint8_t incoming,
    uint8_t *departing)
{
    uint64_t mask;

    if (latency == 0u || latency >= 64u) {
        *departing = 0u;
        return 0u;
    }
    *departing =
        (uint8_t)((tokens >> (latency - 1u)) & 1u);
    mask = (UINT64_C(1) << latency) - 1u;
    return ((tokens << 1u) | incoming) & mask;
}

static uint64_t npu_engine_data_popcount64(uint64_t value)
{
    uint64_t count = 0u;

    while (value != 0u) {
        count += value & 1u;
        value >>= 1u;
    }
    return count;
}

static void npu_engine_data_advance_cme_stream(
    npu_engine_data_cycle_t *model,
    uint8_t launch)
{
    uint8_t leave_i2f;
    uint8_t leave_fp;
    uint8_t leave_f2i;

    model->cme_i2f_tokens =
        npu_engine_data_stage_shift(
            model->cme_i2f_tokens, 2u, launch,
            &leave_i2f);
    model->cme_fp_tokens =
        npu_engine_data_stage_shift(
            model->cme_fp_tokens,
            model->cme_direct_fp_latency,
            leave_i2f, &leave_fp);
    model->cme_f2i_tokens =
        npu_engine_data_stage_shift(
            model->cme_f2i_tokens, 4u, leave_fp,
            &leave_f2i);
    (void)leave_f2i;
    if (launch != 0u) {
        model->compute_groups_issued++;
    }
    model->compute_elapsed++;
    if (model->compute_groups_issued >=
            model->compute_groups &&
        model->cme_i2f_tokens == 0u &&
        model->cme_fp_tokens == 0u &&
        model->cme_f2i_tokens == 0u) {
        model->compute_stage =
            NPU_ENGINE_DATA_COMPUTE_DONE;
        model->compute_stage_remaining = 0u;
        return;
    }
    model->compute_stage_remaining =
        model->compute_groups -
            model->compute_groups_issued +
        npu_engine_data_popcount64(
            model->cme_i2f_tokens) +
        npu_engine_data_popcount64(
            model->cme_fp_tokens) +
        npu_engine_data_popcount64(
            model->cme_f2i_tokens);
}

static void npu_engine_data_advance_compute(
    npu_engine_data_cycle_t *model,
    uint8_t group_launch)
{
    if (model->compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_DONE) {
        return;
    }
    if (model->compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE) {
        if (model->cme_direct_stream != 0u) {
            if (group_launch != 0u ||
                model->cme_i2f_tokens != 0u ||
                model->cme_fp_tokens != 0u ||
                model->cme_f2i_tokens != 0u) {
                npu_engine_data_advance_cme_stream(
                    model, group_launch);
            }
            return;
        }
        model->compute_elapsed++;
        if (model->compute_elapsed >=
            model->compute_total_cycles) {
            model->compute_stage =
                NPU_ENGINE_DATA_COMPUTE_DONE;
            model->compute_stage_remaining = 0u;
        } else {
            model->compute_stage_remaining =
                model->compute_total_cycles -
                model->compute_elapsed;
        }
        return;
    }
    if (group_launch == 0u) {
        return;
    }
    model->compute_groups_issued++;
    if (model->compute_stage_remaining > 1u) {
        model->compute_stage_remaining--;
        return;
    }

    model->compute_stage =
        NPU_ENGINE_DATA_COMPUTE_DONE;
    model->compute_stage_remaining = 0u;
}

static uint8_t npu_engine_data_window_active(
    uint64_t elapsed,
    uint64_t start,
    uint64_t cycles)
{
    return elapsed >= start &&
                   elapsed - start < cycles
               ? 1u
               : 0u;
}

static void npu_engine_data_activity(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    uint8_t cancel_handshake,
    const npu_bus_replay_cycle_outputs_t *replay,
    npu_engine_data_cycle_outputs_t *outputs)
{
    uint32_t port;
    uint8_t schedule_enabled =
        replay->compute_valid != 0u &&
                inputs->engine.eng_abort_i == 0u &&
                cancel_handshake == 0u
            ? 1u
            : 0u;
    uint8_t group_launch =
        schedule_enabled != 0u
            ? npu_engine_data_group_launch(
                  model, replay)
            : 0u;

    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        if ((outputs->l1_read[port].req_valid != 0u &&
             inputs->l1_read[port].req_ready == 0u) ||
            (outputs->l1_read[port].rsp_ready != 0u &&
             inputs->l1_read[port].rsp_valid == 0u)) {
            outputs->l1_stall = 1u;
        }
    }
    if ((outputs->l1_write.req_valid != 0u &&
         inputs->l1_write.req_ready == 0u) ||
        (outputs->l1_write.data_valid != 0u &&
         inputs->l1_write.data_ready == 0u) ||
        (outputs->l1_write.rsp_ready != 0u &&
         inputs->l1_write.rsp_valid == 0u)) {
        outputs->l1_stall = 1u;
    }
    if ((outputs->mif.req_valid != 0u &&
         inputs->mif.req_ready == 0u) ||
        (outputs->mif.wvalid != 0u &&
         inputs->mif.wready == 0u) ||
        (outputs->mif.rsp_ready != 0u &&
         inputs->mif.rsp_valid == 0u)) {
        outputs->mif_stall = 1u;
    }

    if (model->engine.engine == NPU_ENGINE_DMA) {
        outputs->dma_busy = outputs->engine.eng_busy_o;
        outputs->dma_idle =
            outputs->engine.eng_busy_o == 0u &&
                    outputs->data_busy == 0u
                ? 1u
                : 0u;
    } else if (model->engine.engine ==
               NPU_ENGINE_MATRIX) {
        outputs->me_mac_active =
            group_launch != 0u &&
                    model->compute_stage ==
                        NPU_ENGINE_DATA_COMPUTE_ME
                ? 1u
                : 0u;
        outputs->me_operand_stall =
            (uint8_t)(
                (outputs->l1_read[0].req_valid != 0u &&
                 inputs->l1_read[0].req_ready == 0u) ||
                (outputs->l1_read[0].rsp_ready != 0u &&
                 inputs->l1_read[0].rsp_valid == 0u) ||
                (outputs->l1_read[1].req_valid != 0u &&
                 inputs->l1_read[1].req_ready == 0u) ||
                (outputs->l1_read[1].rsp_ready != 0u &&
                 inputs->l1_read[1].rsp_valid == 0u));
        outputs->me_write_stall =
            (uint8_t)(
                (outputs->l1_write.req_valid != 0u &&
                 inputs->l1_write.req_ready == 0u) ||
                (outputs->l1_write.data_valid != 0u &&
                 inputs->l1_write.data_ready == 0u));
        outputs->me_acc_overflow =
            (outputs->engine.eng_busy_o != 0u ||
             outputs->data_busy != 0u) &&
                    model->me_acc_overflow_latched != 0u
                ? 1u
                : 0u;
    } else if (model->engine.engine ==
               NPU_ENGINE_VECTOR) {
        outputs->ive_alu_active =
            group_launch != 0u &&
                    model->compute_stage ==
                        NPU_ENGINE_DATA_COMPUTE_IVE
                ? 1u
                : 0u;
        outputs->ive_l1_stall = outputs->l1_stall;
        outputs->ive_overflow =
            (outputs->engine.eng_busy_o != 0u ||
             outputs->data_busy != 0u) &&
                    model->ive_overflow_latched != 0u
                ? 1u
                : 0u;
        outputs->ive_lane_valid =
            outputs->ive_alu_active == 0u
                ? 0u
                : (model->compute_groups_issued + 1u >=
                           model->compute_groups
                       ? model->compute_tail_lane_mask
                       : model->compute_full_lane_mask);
    } else if (model->engine.engine ==
               NPU_ENGINE_COMPLEX) {
        uint8_t numeric = 0u;
        uint8_t task_active =
            (outputs->engine.eng_busy_o != 0u ||
             outputs->data_busy != 0u)
                ? 1u
                : 0u;

        if (model->cme_direct_stream != 0u) {
            outputs->cme_i2f_active =
                schedule_enabled != 0u &&
                        (model->cme_i2f_tokens != 0u ||
                         group_launch != 0u)
                    ? 1u
                    : 0u;
            outputs->cme_fp_active =
                schedule_enabled != 0u &&
                        model->cme_fp_tokens != 0u
                    ? 1u
                    : 0u;
            outputs->cme_f2i_active =
                schedule_enabled != 0u &&
                        model->cme_f2i_tokens != 0u
                    ? 1u
                    : 0u;
        } else {
            outputs->cme_i2f_active =
                schedule_enabled != 0u &&
                        model->compute_stage ==
                            NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE &&
                        npu_engine_data_window_active(
                            model->compute_elapsed,
                            model->cme_i2f_start,
                            model->cme_i2f_cycles) != 0u
                    ? 1u
                    : 0u;
            outputs->cme_fp_active =
                schedule_enabled != 0u &&
                        model->compute_stage ==
                            NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE &&
                        npu_engine_data_window_active(
                            model->compute_elapsed,
                            model->cme_fp_start,
                            model->cme_fp_cycles) != 0u
                    ? 1u
                    : 0u;
            outputs->cme_f2i_active =
                schedule_enabled != 0u &&
                        model->compute_stage ==
                            NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE &&
                        npu_engine_data_window_active(
                            model->compute_elapsed,
                            model->cme_f2i_start,
                            model->cme_f2i_cycles) != 0u
                    ? 1u
                    : 0u;
        }
        outputs->cme_l1_stall = outputs->l1_stall;
        if (task_active != 0u &&
            model->engine.pending_status ==
                NPU_STATUS_NUMERIC_EXCEPTION) {
            numeric |=
                NPU_ENGINE_DATA_CME_NUMERIC_EXCEPTION;
        }
        if (task_active != 0u) {
            numeric |= model->cme_numeric_flags_latched;
        }
        outputs->cme_numeric_flag = numeric;
    }
}

static void npu_engine_data_gate_outputs(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    uint8_t data_pending_at_entry,
    uint8_t cancel_handshake,
    uint8_t cancel_ready,
    const npu_bus_replay_cycle_outputs_t *replay,
    npu_engine_data_cycle_outputs_t *outputs)
{
    npu_engine_data_copy_replay_outputs(replay, outputs);
    if (data_pending_at_entry != 0u) {
        outputs->engine.eng_done_valid_o = 0u;
        outputs->engine.eng_done_data_o = 0u;
        outputs->engine.eng_done_first_o = 0u;
        outputs->engine.eng_done_last_o = 0u;
        outputs->engine.eng_cancel_ready_o = cancel_ready;
        outputs->engine.eng_active_o = 1u;
        outputs->engine.eng_busy_o = 1u;
        outputs->engine.eng_quiescent_o = 0u;
    }
    if (model->workspace_bound == 0u &&
        model->engine.state == NPU_ENGINE_CYCLE_IDLE) {
        outputs->engine.eng_req_ready_o = 0u;
    }
    outputs->trace_overflow = model->trace.overflow;
    outputs->captured_read_words =
        model->trace.read_count;
    outputs->captured_write_words =
        model->trace.write_count;
    outputs->cycle = model->cycle;
    npu_engine_data_activity(
        model, inputs, cancel_handshake, replay, outputs);
    outputs->engine.eng_stall_o |=
        (uint8_t)(outputs->l1_stall |
                  outputs->mif_stall);
}

npu_status_t npu_engine_data_cycle_init(
    npu_engine_data_cycle_t *model,
    npu_model_t *functional_model,
    npu_engine_t engine,
    const npu_wire_limits_t *limits)
{
    npu_status_t status;

    if (model == (npu_engine_data_cycle_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    (void)memset(model, 0, sizeof(*model));
    status = npu_engine_cycle_init(
        &model->engine, functional_model, engine, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    npu_bus_replay_cycle_reset(&model->replay);
    model->initialized = 1u;
    return NPU_STATUS_SUCCESS;
}

int npu_engine_data_workspace_valid(
    const npu_engine_data_workspace_t *workspace)
{
    if (workspace ==
            (const npu_engine_data_workspace_t *)0 ||
        workspace->read_entries ==
            (npu_bus_trace_entry_t *)0 ||
        workspace->read_capacity == 0u ||
        workspace->read_hash == (uint32_t *)0 ||
        workspace->read_hash_slots == 0u ||
        (workspace->read_hash_slots &
         (workspace->read_hash_slots - 1u)) != 0u ||
        workspace->read_hash_slots <
            workspace->read_capacity ||
        workspace->write_entries ==
            (npu_bus_trace_entry_t *)0 ||
        workspace->write_capacity == 0u ||
        workspace->write_hash == (uint32_t *)0 ||
        workspace->write_hash_slots == 0u ||
        (workspace->write_hash_slots &
         (workspace->write_hash_slots - 1u)) != 0u ||
        workspace->write_hash_slots <
            workspace->write_capacity) {
        return 0;
    }
    return 1;
}

int npu_engine_data_cycle_bind_workspace(
    npu_engine_data_cycle_t *model,
    const npu_engine_data_workspace_t *workspace)
{
    if (model == (npu_engine_data_cycle_t *)0 ||
        model->initialized == 0u ||
        model->engine.state != NPU_ENGINE_CYCLE_IDLE ||
        model->data_pending != 0u ||
        !npu_engine_data_workspace_valid(workspace)) {
        return 0;
    }
    if (!npu_bus_trace_begin(
            &model->trace,
            workspace->read_entries,
            workspace->read_capacity,
            workspace->read_hash,
            workspace->read_hash_slots,
            workspace->write_entries,
            workspace->write_capacity,
            workspace->write_hash,
            workspace->write_hash_slots,
            NPU_ENGINE_DATA_READ_PORTS,
            npu_engine_data_select_port, model)) {
        return 0;
    }
    npu_bus_trace_end(&model->trace);
    model->workspace = *workspace;
    model->workspace_bound = 1u;
    return 1;
}

void npu_engine_data_cycle_reset(
    npu_engine_data_cycle_t *model)
{
    npu_engine_data_workspace_t workspace;
    uint8_t workspace_bound;
    uint8_t initialized;

    if (model == (npu_engine_data_cycle_t *)0) {
        return;
    }
    workspace = model->workspace;
    workspace_bound = model->workspace_bound;
    initialized = model->initialized;
    npu_engine_cycle_reset(&model->engine);
    npu_bus_replay_cycle_reset(&model->replay);
    (void)memset(&model->trace, 0, sizeof(model->trace));
    (void)memset(&model->perf_delta, 0,
                 sizeof(model->perf_delta));
    model->workspace = workspace;
    model->workspace_bound = workspace_bound;
    model->data_pending = 0u;
    model->data_done_released = 0u;
    model->perf_delta_valid = 0u;
    model->initialized = initialized;
    model->compute_stage =
        NPU_ENGINE_DATA_COMPUTE_DONE;
    model->compute_stage_remaining = 0u;
    model->compute_groups = 0u;
    model->compute_groups_issued = 0u;
    model->compute_lanes = 0u;
    model->compute_full_lane_mask = 0u;
    model->compute_tail_lane_mask = 0u;
    model->compute_elapsed = 0u;
    model->compute_total_cycles = 0u;
    model->cme_i2f_start = 0u;
    model->cme_i2f_cycles = 0u;
    model->cme_fp_start = 0u;
    model->cme_fp_cycles = 0u;
    model->cme_f2i_start = 0u;
    model->cme_f2i_cycles = 0u;
    model->stream_compute = 0u;
    model->cme_direct_stream = 0u;
    model->cme_direct_fp_latency = 0u;
    model->cme_i2f_tokens = 0u;
    model->cme_fp_tokens = 0u;
    model->cme_f2i_tokens = 0u;
    npu_engine_data_clear_numeric(model);
    model->cycle = 0u;
}

static void npu_engine_data_cycle_run(
    npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs,
    int commit)
{
    npu_engine_cycle_inputs_t engine_inputs;
    npu_engine_cycle_outputs_t engine_outputs;
    npu_engine_cycle_outputs_t engine_preview;
    npu_bus_replay_cycle_inputs_t replay_inputs;
    npu_bus_replay_cycle_outputs_t replay_outputs;
    npu_perf_t perf_before;
    npu_perf_t perf_after;
    void *previous_trace;
    npu_engine_data_cycle_t *previous_numeric_capture =
        (npu_engine_data_cycle_t *)0;
    uint8_t data_pending_at_entry;
    uint8_t capture_edge;
    uint8_t request_handshake;
    uint8_t cancel_ready;
    uint8_t cancel_handshake;
    uint64_t param_fault_addr = 0u;
    int trace_started = 0;

    (void)memset(outputs, 0, sizeof(*outputs));
    if (inputs->engine.reset_n == 0u) {
        if (commit != 0) {
            npu_engine_data_cycle_reset(model);
        }
        outputs->engine.eng_quiescent_o = 1u;
        outputs->data_quiescent = 1u;
        return;
    }

    data_pending_at_entry = model->data_pending;
    engine_inputs = inputs->engine;
    if (model->workspace_bound == 0u) {
        engine_inputs.eng_req_valid_i = 0u;
    }
    if (data_pending_at_entry != 0u) {
        engine_inputs.eng_done_ready_i = 0u;
        engine_inputs.eng_cancel_valid_i = 0u;
        engine_inputs.eng_abort_i = 0u;
    }
    npu_engine_cycle_eval(
        &model->engine, &engine_inputs, &engine_preview);
    request_handshake =
        engine_inputs.eng_req_valid_i != 0u &&
                engine_preview.eng_req_ready_o != 0u
            ? 1u
            : 0u;
    cancel_ready =
        data_pending_at_entry != 0u
            ? npu_engine_data_replay_cancel_ready(
                  model,
                  inputs->engine.eng_cancel_status_i)
            : engine_preview.eng_cancel_ready_o;
    cancel_handshake =
        inputs->engine.eng_cancel_valid_i != 0u &&
                cancel_ready != 0u
            ? 1u
            : 0u;
    capture_edge =
        model->workspace_bound != 0u &&
                data_pending_at_entry == 0u &&
                model->engine.state ==
                    NPU_ENGINE_CYCLE_EXECUTE &&
                model->engine.execute_remaining <= 1u &&
                inputs->engine.eng_abort_i == 0u &&
                cancel_handshake == 0u
            ? 1u
            : 0u;

    if (commit == 0) {
        engine_outputs = engine_preview;
        npu_engine_data_build_replay_inputs(
            model, inputs, cancel_handshake,
            &replay_inputs);
        npu_bus_replay_cycle_eval(
            &model->replay, &replay_inputs,
            &replay_outputs);
        outputs->engine = engine_outputs;
        npu_engine_data_gate_outputs(
            model, inputs, data_pending_at_entry,
            cancel_handshake, cancel_ready, &replay_outputs,
            outputs);
        return;
    }

    if (request_handshake != 0u) {
        npu_engine_data_clear_numeric(model);
    }

    if (capture_edge != 0u) {
        trace_started = npu_bus_trace_begin(
            &model->trace,
            model->workspace.read_entries,
            model->workspace.read_capacity,
            model->workspace.read_hash,
            model->workspace.read_hash_slots,
            model->workspace.write_entries,
            model->workspace.write_capacity,
            model->workspace.write_hash,
            model->workspace.write_hash_slots,
            NPU_ENGINE_DATA_READ_PORTS,
            npu_engine_data_select_port, model);
        if (trace_started != 0) {
            previous_trace =
                model->engine.functional_model
                    ->internal_bus_trace;
            perf_before =
                model->engine.functional_model->perf;
            model->engine.functional_model
                ->internal_bus_trace = &model->trace;
            previous_numeric_capture =
                npu_engine_data_current_capture;
            npu_engine_data_current_capture = model;
        }
    }

    npu_engine_cycle_step(
        &model->engine, &engine_inputs, &engine_outputs);

    if (capture_edge != 0u && trace_started != 0) {
        npu_engine_data_current_capture =
            previous_numeric_capture;
        model->engine.functional_model
            ->internal_bus_trace = previous_trace;
        npu_bus_trace_end(&model->trace);
        perf_after =
            model->engine.functional_model->perf;
        model->engine.functional_model->perf =
            perf_before;
        npu_engine_data_perf_delta(
            &model->perf_delta, &perf_before, &perf_after);
        npu_engine_data_dma_perf_from_trace(model);
        model->perf_delta_valid = 1u;
        if (model->engine.pending_status ==
                NPU_STATUS_SUCCESS &&
            npu_engine_data_param_fault(
                model, inputs, &param_fault_addr) != 0u) {
            npu_engine_data_set_param_fault(
                model, param_fault_addr);
            /*
             * A static destination failure is diagnosed before the
             * modeled hardware emits source reads or destination writes.
             */
            model->trace.read_count = 0u;
            model->trace.read_pass_count = 0u;
            model->perf_delta_valid = 0u;
        }
        if (model->engine.pending_status ==
            NPU_STATUS_SUCCESS) {
            npu_engine_data_prepare_compute(model);
        } else {
            npu_engine_data_clear_compute(model);
        }
        if (npu_bus_replay_cycle_start_stream(
                &model->replay, &model->trace,
                model->engine.task_id, 0u,
                model->engine.pending_status,
                model->engine.pending_progress,
                model->engine.engine != NPU_ENGINE_DMA &&
                        model->engine.pending_status ==
                            NPU_STATUS_SUCCESS
                    ? 1u
                    : 0u,
                model->stream_compute)) {
            model->data_pending = 1u;
            model->data_done_released = 0u;
        } else {
            model->perf_delta_valid = 0u;
            model->data_pending = 0u;
            model->data_done_released = 1u;
            model->compute_stage =
                NPU_ENGINE_DATA_COMPUTE_DONE;
            model->compute_stage_remaining = 0u;
        }
    }

    (void)memset(&replay_outputs, 0,
                 sizeof(replay_outputs));
    if (data_pending_at_entry != 0u) {
        npu_engine_data_build_replay_inputs(
            model, inputs, cancel_handshake,
            &replay_inputs);
        npu_bus_replay_cycle_step(
            &model->replay, &replay_inputs,
            &replay_outputs);
        if (replay_outputs.done_valid != 0u) {
            uint8_t original_status =
                (uint8_t)model->engine.pending_status;

            npu_engine_data_pack_done(
                model, &replay_outputs);
            if (model->perf_delta_valid != 0u &&
                replay_outputs.done_status ==
                    original_status) {
                npu_engine_data_perf_add(
                    &model->engine.functional_model->perf,
                    &model->perf_delta);
            }
            model->perf_delta_valid = 0u;
            model->data_pending = 0u;
            model->data_done_released = 1u;
        }
    } else {
        replay_outputs.quiescent = 1u;
    }

    if (model->engine.state == NPU_ENGINE_CYCLE_EXECUTE &&
        data_pending_at_entry == 0u &&
        capture_edge == 0u &&
        model->workspace_bound != 0u) {
        model->engine.execute_remaining = 1u;
    }
    if (model->engine.state == NPU_ENGINE_CYCLE_IDLE) {
        model->data_done_released = 0u;
        model->perf_delta_valid = 0u;
        model->compute_stage =
            NPU_ENGINE_DATA_COMPUTE_DONE;
        model->compute_stage_remaining = 0u;
    }

    outputs->engine = engine_outputs;
    npu_engine_data_gate_outputs(
        model, inputs, data_pending_at_entry,
        cancel_handshake, cancel_ready, &replay_outputs,
        outputs);
    if (data_pending_at_entry != 0u &&
        replay_outputs.compute_valid != 0u &&
        inputs->engine.eng_abort_i == 0u &&
        cancel_handshake == 0u) {
        npu_engine_data_advance_compute(
            model,
            npu_engine_data_group_launch(
                model, &replay_outputs));
    }
    model->cycle++;
}

void npu_engine_data_cycle_step(
    npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs)
{
    if (model == (npu_engine_data_cycle_t *)0 ||
        inputs ==
            (const npu_engine_data_cycle_inputs_t *)0 ||
        outputs == (npu_engine_data_cycle_outputs_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    npu_engine_data_cycle_run(
        model, inputs, outputs, 1);
}

void npu_engine_data_cycle_eval(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs)
{
    npu_engine_data_cycle_t preview;

    if (model == (const npu_engine_data_cycle_t *)0 ||
        inputs ==
            (const npu_engine_data_cycle_inputs_t *)0 ||
        outputs == (npu_engine_data_cycle_outputs_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    preview = *model;
    npu_engine_data_cycle_run(
        &preview, inputs, outputs, 0);
}
