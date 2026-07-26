#include "npu_sys_slave_cycle.h"

#include <string.h>

static uint8_t npu_sys_target_for_address(uint32_t addr,
                                          uint8_t *reg_space)
{
    *reg_space = 0u;
    if (addr < NPU_SYS_SLAVE_CSR_LIMIT) {
        return (uint8_t)NPU_SYS_TARGET_REG;
    }
    if (addr < NPU_SYS_SLAVE_DEBUG_LIMIT) {
        *reg_space = 1u;
        return (uint8_t)NPU_SYS_TARGET_REG;
    }
    if (addr == NPU_SYS_SLAVE_CMD_FIFO_ADDR) {
        return (uint8_t)NPU_SYS_TARGET_CMD_FIFO;
    }
    if (addr == NPU_SYS_SLAVE_CMD_RSP_FIFO_ADDR) {
        return (uint8_t)NPU_SYS_TARGET_CMD_RSP_FIFO;
    }
    if (addr == NPU_SYS_SLAVE_CMD_FIFO_STATUS_ADDR) {
        return (uint8_t)NPU_SYS_TARGET_CMD_FIFO_STATUS;
    }
    if (addr < NPU_SYS_SLAVE_L1_BASE) {
        return (uint8_t)NPU_SYS_TARGET_RESERVED;
    }
    if (addr <= NPU_SYS_SLAVE_ADDR_MASK) {
        return (uint8_t)NPU_SYS_TARGET_L1;
    }
    return (uint8_t)NPU_SYS_TARGET_ERROR;
}

static uint8_t npu_sys_cmd_write_format_valid(
    uint32_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t burst,
    uint8_t lock)
{
    uint16_t total_beats = (uint16_t)len + 1u;

    return (uint8_t)(
        addr == NPU_SYS_SLAVE_CMD_FIFO_ADDR &&
        burst == (uint8_t)NPU_SYS_AXI_BURST_FIXED &&
        lock == 0u && size == 3u &&
        total_beats >= 2u &&
        total_beats <= NPU_SYS_SLAVE_CMD_MAX_BURST_BEATS &&
        (total_beats & 1u) == 0u);
}

static uint8_t npu_sys_static_error(
    const npu_sys_slave_cycle_t *adapter,
    const npu_sys_slave_inputs_t *inputs,
    uint8_t write,
    uint32_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t burst,
    uint8_t lock,
    uint8_t target,
    uint8_t reg_space)
{
    uint64_t transfer_bytes;
    uint64_t end;
    uint32_t beat_bytes;
    uint16_t total_beats = (uint16_t)len + 1u;

    if (target == (uint8_t)NPU_SYS_TARGET_CMD_FIFO) {
        if (write == 0u ||
            npu_sys_cmd_write_format_valid(
                addr, len, size, burst, lock) == 0u) {
            return 1u;
        }
        return 0u;
    }
    if (target == (uint8_t)NPU_SYS_TARGET_CMD_RSP_FIFO ||
        target ==
            (uint8_t)NPU_SYS_TARGET_CMD_FIFO_STATUS) {
        if (write != 0u ||
            burst != (uint8_t)NPU_SYS_AXI_BURST_INCR ||
            lock != 0u || size != 3u || len != 0u) {
            return 1u;
        }
        return 0u;
    }

    if (addr > NPU_SYS_SLAVE_ADDR_MASK ||
        burst != (uint8_t)NPU_SYS_AXI_BURST_INCR ||
        lock != 0u ||
        size > 3u ||
        target == (uint8_t)NPU_SYS_TARGET_ERROR) {
        return 1u;
    }

    beat_bytes = 1u << size;
    transfer_bytes =
        (uint64_t)beat_bytes * (uint64_t)total_beats;
    end = (uint64_t)addr + transfer_bytes;
    if ((addr & (beat_bytes - 1u)) != 0u ||
        ((addr & 7u) + beat_bytes) >
            NPU_SYS_SLAVE_WORD_BYTES ||
        end > (uint64_t)NPU_SYS_SLAVE_ADDR_MASK + 1u) {
        return 1u;
    }
    if (size < 3u && len != 0u) {
        return 1u;
    }

    if (target == (uint8_t)NPU_SYS_TARGET_REG) {
        uint32_t limit =
            reg_space == 0u ? NPU_SYS_SLAVE_CSR_LIMIT :
                              NPU_SYS_SLAVE_DEBUG_LIMIT;

        if (len != 0u ||
            (reg_space == 0u && size < 2u) ||
            (reg_space != 0u && size != 3u) ||
            end > limit ||
            (reg_space != 0u &&
             inputs->core_idle_i == 0u &&
             inputs->debug_frozen_i == 0u)) {
            return 1u;
        }
    } else if (target ==
               (uint8_t)NPU_SYS_TARGET_RESERVED) {
        if (len != 0u) {
            return 1u;
        }
    } else if (target == (uint8_t)NPU_SYS_TARGET_L1) {
        uint64_t l1_offset =
            (uint64_t)addr - NPU_SYS_SLAVE_L1_BASE;

        if ((len != 0u && size != 3u) ||
            ((uint64_t)(addr & 0xfffu) +
             transfer_bytes) > 0x1000u ||
            l1_offset + transfer_bytes >
                adapter->l1_bytes ||
            inputs->core_idle_i == 0u ||
            inputs->l1_diag_enable_i == 0u) {
            return 1u;
        }
    } else {
        return 1u;
    }
    return 0u;
}

static uint32_t npu_sys_beat_address(uint32_t base_addr,
                                     uint8_t size,
                                     uint16_t beat)
{
    if (size > 3u) {
        return base_addr;
    }
    return base_addr +
           (uint32_t)beat * (uint32_t)(1u << size);
}

static uint8_t npu_sys_cmd_next_index(uint8_t index,
                                      uint8_t depth)
{
    index++;
    if (index >= depth) {
        index = 0u;
    }
    return index;
}

static uint8_t npu_sys_cmd_free_entries(
    const npu_sys_slave_cycle_t *adapter)
{
    uint8_t used = adapter->cmd_fifo_count;

    if (adapter->write.active != 0u &&
        adapter->write.target ==
            (uint8_t)NPU_SYS_TARGET_CMD_FIFO) {
        used = (uint8_t)(used +
                         adapter->write.cmd_reserved);
    }
    if (used >= NPU_SYS_SLAVE_CMD_FIFO_DEPTH) {
        return 0u;
    }
    return (uint8_t)(
        NPU_SYS_SLAVE_CMD_FIFO_DEPTH - used);
}

static uint8_t npu_sys_cmd_free_beats(
    const npu_sys_slave_cycle_t *adapter)
{
    return (uint8_t)(
        npu_sys_cmd_free_entries(adapter) * 2u);
}

static uint64_t npu_sys_cmd_status(
    const npu_sys_slave_cycle_t *adapter)
{
    uint8_t free_beats = npu_sys_cmd_free_beats(adapter);
    uint64_t status =
        (uint64_t)free_beats
            << NPU_SYS_SLAVE_CMD_STATUS_FREE_BEATS_SHIFT;

    status |=
        (uint64_t)adapter->cmd_rsp_fifo_count
        << NPU_SYS_SLAVE_CMD_STATUS_RSP_COUNT_SHIFT;
    if (adapter->write.cmd_half_pending != 0u) {
        status |= NPU_SYS_SLAVE_CMD_STATUS_HALF_PENDING;
    }
    if (free_beats == 0u) {
        status |= NPU_SYS_SLAVE_CMD_STATUS_INGRESS_FULL;
    }
    if (adapter->cmd_rsp_fifo_count >=
        NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH) {
        status |= NPU_SYS_SLAVE_CMD_STATUS_RSP_FULL;
    }
    if (adapter->cmd_protocol_error_sticky != 0u) {
        status |= NPU_SYS_SLAVE_CMD_STATUS_PROTOCOL_ERROR;
    }
    return status;
}

static uint8_t npu_sys_cmd_enqueue(
    npu_sys_slave_cycle_t *adapter,
    const npu_sys_slave_cmd_entry_t *entry)
{
    if (adapter->cmd_fifo_count >=
        NPU_SYS_SLAVE_CMD_FIFO_DEPTH) {
        adapter->cmd_overflow_sticky = 1u;
        return 0u;
    }
    adapter->cmd_fifo[adapter->cmd_fifo_write_index] =
        *entry;
    adapter->cmd_fifo_write_index = npu_sys_cmd_next_index(
        adapter->cmd_fifo_write_index,
        NPU_SYS_SLAVE_CMD_FIFO_DEPTH);
    adapter->cmd_fifo_count++;
    return 1u;
}

static void npu_sys_cmd_pop(npu_sys_slave_cycle_t *adapter)
{
    npu_sys_slave_cmd_entry_t *entry;

    if (adapter->cmd_fifo_count == 0u) {
        adapter->cmd_overflow_sticky = 1u;
        return;
    }
    entry = &adapter->cmd_fifo[
        adapter->cmd_fifo_read_index];
    (void)memset(entry, 0, sizeof(*entry));
    adapter->cmd_fifo_read_index = npu_sys_cmd_next_index(
        adapter->cmd_fifo_read_index,
        NPU_SYS_SLAVE_CMD_FIFO_DEPTH);
    adapter->cmd_fifo_count--;
}

static uint8_t npu_sys_cmd_rsp_push(
    npu_sys_slave_cycle_t *adapter,
    uint64_t response)
{
    if (adapter->cmd_rsp_fifo_count >=
        NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH) {
        adapter->cmd_overflow_sticky = 1u;
        return 0u;
    }
    adapter->cmd_rsp_fifo[
        adapter->cmd_rsp_fifo_write_index] = response;
    adapter->cmd_rsp_fifo_write_index =
        npu_sys_cmd_next_index(
            adapter->cmd_rsp_fifo_write_index,
            NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH);
    adapter->cmd_rsp_fifo_count++;
    return 1u;
}

static void npu_sys_cmd_rsp_pop(
    npu_sys_slave_cycle_t *adapter)
{
    if (adapter->cmd_rsp_fifo_count == 0u) {
        adapter->cmd_overflow_sticky = 1u;
        return;
    }
    adapter->cmd_rsp_fifo[
        adapter->cmd_rsp_fifo_read_index] = 0u;
    adapter->cmd_rsp_fifo_read_index =
        npu_sys_cmd_next_index(
            adapter->cmd_rsp_fifo_read_index,
            NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH);
    adapter->cmd_rsp_fifo_count--;
}

static void npu_sys_cmd_discard_stage(
    npu_sys_slave_write_state_t *write)
{
    (void)memset(write->cmd_stage, 0,
                 sizeof(write->cmd_stage));
    write->cmd_stage_count = 0u;
    write->cmd_half_pending = 0u;
    write->cmd_half_data = 0u;
}

static uint8_t npu_sys_cmd_commit_stage(
    npu_sys_slave_cycle_t *adapter)
{
    npu_sys_slave_write_state_t *write =
        &adapter->write;
    uint8_t index;

    if (write->cmd_half_pending != 0u ||
        write->cmd_stage_count != write->cmd_reserved) {
        adapter->cmd_protocol_error_sticky = 1u;
        return 0u;
    }
    if ((uint16_t)adapter->cmd_fifo_count +
            write->cmd_stage_count >
        NPU_SYS_SLAVE_CMD_FIFO_DEPTH) {
        adapter->cmd_overflow_sticky = 1u;
        return 0u;
    }
    for (index = 0u; index < write->cmd_stage_count;
         index++) {
        if (npu_sys_cmd_enqueue(
                adapter, &write->cmd_stage[index]) == 0u) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t npu_sys_legal_strobe(uint32_t addr,
                                    uint8_t size)
{
    uint32_t beat_bytes;
    uint32_t lane;
    uint32_t mask;

    if (size >= 3u) {
        return 0xffu;
    }
    beat_bytes = 1u << size;
    lane = addr & 7u;
    mask = ((1u << beat_bytes) - 1u) << lane;
    return (uint8_t)mask;
}

static uint8_t npu_sys_l1_response_ok(uint8_t status)
{
    return (uint8_t)(status ==
                         (uint8_t)NPU_SYS_L1_STATUS_OK ||
                     status ==
                         (uint8_t)
                             NPU_SYS_L1_STATUS_ECC_CORRECTED);
}

static uint64_t npu_sys_read_lane_data(
    const npu_sys_slave_read_state_t *read,
    uint64_t data)
{
    uint32_t addr;
    uint8_t lanes;
    uint64_t mask = 0u;
    uint32_t lane;

    if (read->size >= 3u) {
        return data;
    }
    addr = npu_sys_beat_address(
        read->base_addr, read->size, read->next_beat);
    lanes = npu_sys_legal_strobe(addr, read->size);
    for (lane = 0u; lane < NPU_SYS_SLAVE_WORD_BYTES;
         lane++) {
        if ((lanes & (uint8_t)(1u << lane)) != 0u) {
            mask |= UINT64_C(0xff) << (lane * 8u);
        }
    }
    return data & mask;
}

static uint8_t npu_sys_source_pending(
    const npu_sys_slave_cycle_t *adapter,
    uint8_t owner)
{
    return (uint8_t)(
        (adapter->reg_request.valid != 0u &&
         adapter->reg_request.owner == owner) ||
        (adapter->l1_request.valid != 0u &&
         adapter->l1_request.owner == owner) ||
        adapter->reg_response_owner == owner ||
        adapter->l1_response_owner == owner);
}

static void npu_sys_make_read_response(
    npu_sys_slave_cycle_t *adapter,
    uint64_t data,
    uint8_t response)
{
    npu_sys_slave_read_state_t *read = &adapter->read;

    adapter->rvalid = 1u;
    adapter->rid = read->id;
    adapter->rdata = data;
    adapter->rresp = response;
    adapter->rlast =
        (uint8_t)(read->next_beat + 1u ==
                  read->total_beats);
    read->next_beat++;
}

static void npu_sys_finish_write_beat(
    npu_sys_slave_cycle_t *adapter,
    uint8_t success)
{
    npu_sys_slave_write_state_t *write = &adapter->write;

    if (success == 0u) {
        write->error = 1u;
    }
    write->beat_valid = 0u;
    write->finished_beats++;
}

static void npu_sys_load_reg_request(
    npu_sys_slave_internal_request_t *request,
    uint8_t owner,
    uint8_t write,
    uint8_t space,
    uint32_t addr,
    uint64_t wdata,
    uint8_t wstrb)
{
    request->valid = 1u;
    request->owner = owner;
    request->write = write;
    request->space = space;
    request->addr =
        (addr & 0xffffu) &
        ~(NPU_SYS_SLAVE_WORD_BYTES - 1u);
    request->wdata = wdata;
    request->wstrb = wstrb;
}

static void npu_sys_load_l1_request(
    npu_sys_slave_internal_request_t *request,
    uint8_t owner,
    uint8_t write,
    uint32_t addr,
    uint64_t wdata,
    uint8_t wstrb)
{
    request->valid = 1u;
    request->owner = owner;
    request->write = write;
    request->space = 0u;
    request->addr =
        (addr - NPU_SYS_SLAVE_L1_BASE) &
        ~(NPU_SYS_SLAVE_WORD_BYTES - 1u);
    request->wdata = wdata;
    request->wstrb = wstrb;
}

static uint8_t npu_sys_write_candidate(
    const npu_sys_slave_cycle_t *adapter,
    uint8_t target)
{
    const npu_sys_slave_write_state_t *write =
        &adapter->write;

    return (uint8_t)(
        write->active != 0u &&
        write->beat_valid != 0u &&
        write->error == 0u &&
        write->target == target &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_WRITE) == 0u);
}

static uint8_t npu_sys_read_candidate(
    const npu_sys_slave_cycle_t *adapter,
    uint8_t target)
{
    const npu_sys_slave_read_state_t *read =
        &adapter->read;

    return (uint8_t)(
        read->active != 0u &&
        read->decode_wait == 0u &&
        adapter->rvalid == 0u &&
        read->error == 0u &&
        read->next_beat < read->total_beats &&
        read->target == target &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_READ) == 0u);
}

static void npu_sys_schedule_reg_request(
    npu_sys_slave_cycle_t *adapter)
{
    if (adapter->reg_request.valid != 0u ||
        adapter->reg_response_owner !=
            (uint8_t)NPU_SYS_OWNER_NONE) {
        return;
    }

    if (npu_sys_write_candidate(
            adapter, (uint8_t)NPU_SYS_TARGET_REG) != 0u) {
        npu_sys_slave_write_state_t *write =
            &adapter->write;
        uint32_t addr = npu_sys_beat_address(
            write->base_addr, write->size,
            write->beat_index);

        npu_sys_load_reg_request(
            &adapter->reg_request,
            (uint8_t)NPU_SYS_OWNER_WRITE, 1u,
            write->reg_space, addr, write->beat_data,
            write->beat_strb);
    } else if (npu_sys_read_candidate(
                   adapter,
                   (uint8_t)NPU_SYS_TARGET_REG) != 0u) {
        npu_sys_slave_read_state_t *read =
            &adapter->read;
        uint32_t addr = npu_sys_beat_address(
            read->base_addr, read->size,
            read->next_beat);

        npu_sys_load_reg_request(
            &adapter->reg_request,
            (uint8_t)NPU_SYS_OWNER_READ, 0u,
            read->reg_space, addr, 0u, 0u);
    }
}

static void npu_sys_schedule_l1_request(
    npu_sys_slave_cycle_t *adapter)
{
    if (adapter->l1_request.valid != 0u ||
        adapter->l1_response_owner !=
            (uint8_t)NPU_SYS_OWNER_NONE) {
        return;
    }

    if (npu_sys_write_candidate(
            adapter, (uint8_t)NPU_SYS_TARGET_L1) != 0u) {
        npu_sys_slave_write_state_t *write =
            &adapter->write;
        uint32_t addr = npu_sys_beat_address(
            write->base_addr, write->size,
            write->beat_index);

        npu_sys_load_l1_request(
            &adapter->l1_request,
            (uint8_t)NPU_SYS_OWNER_WRITE, 1u, addr,
            write->beat_data, write->beat_strb);
    } else if (npu_sys_read_candidate(
                   adapter,
                   (uint8_t)NPU_SYS_TARGET_L1) != 0u) {
        npu_sys_slave_read_state_t *read =
            &adapter->read;
        uint32_t addr = npu_sys_beat_address(
            read->base_addr, read->size,
            read->next_beat);

        npu_sys_load_l1_request(
            &adapter->l1_request,
            (uint8_t)NPU_SYS_OWNER_READ, 0u, addr,
            0u, 0u);
    }
}

static void npu_sys_complete_write_if_ready(
    npu_sys_slave_cycle_t *adapter)
{
    npu_sys_slave_write_state_t *write =
        &adapter->write;

    if (write->active != 0u &&
        write->received_beats == write->total_beats &&
        write->finished_beats == write->total_beats &&
        write->beat_valid == 0u &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_WRITE) == 0u) {
        adapter->bvalid = 1u;
        adapter->bid = write->id;
        adapter->bresp =
            write->error != 0u ?
                (uint8_t)NPU_SYS_AXI_RESP_SLVERR :
                (uint8_t)NPU_SYS_AXI_RESP_OKAY;
        write->active = 0u;
    }
}

int npu_sys_slave_cycle_init(npu_sys_slave_cycle_t *adapter,
                             uint32_t l1_bytes)
{
    if (adapter == (npu_sys_slave_cycle_t *)0 ||
        l1_bytes == 0u ||
        l1_bytes > NPU_SYS_SLAVE_L1_WINDOW_BYTES ||
        (l1_bytes & (NPU_SYS_SLAVE_WORD_BYTES - 1u)) !=
            0u) {
        return -1;
    }
    (void)memset(adapter, 0, sizeof(*adapter));
    adapter->l1_bytes = l1_bytes;
    return 0;
}

void npu_sys_slave_cycle_reset(npu_sys_slave_cycle_t *adapter)
{
    uint32_t l1_bytes;

    if (adapter == (npu_sys_slave_cycle_t *)0) {
        return;
    }
    l1_bytes = adapter->l1_bytes;
    if (l1_bytes == 0u ||
        l1_bytes > NPU_SYS_SLAVE_L1_WINDOW_BYTES ||
        (l1_bytes & (NPU_SYS_SLAVE_WORD_BYTES - 1u)) !=
            0u) {
        l1_bytes = NPU_SYS_SLAVE_DEFAULT_L1_BYTES;
    }
    (void)memset(adapter, 0, sizeof(*adapter));
    adapter->l1_bytes = l1_bytes;
}

uint8_t npu_sys_slave_cycle_idle(
    const npu_sys_slave_cycle_t *adapter)
{
    if (adapter == (const npu_sys_slave_cycle_t *)0) {
        return 0u;
    }
    return (uint8_t)(
        adapter->write.active == 0u &&
        adapter->read.active == 0u &&
        adapter->reg_request.valid == 0u &&
        adapter->l1_request.valid == 0u &&
        adapter->reg_response_owner ==
            (uint8_t)NPU_SYS_OWNER_NONE &&
        adapter->l1_response_owner ==
            (uint8_t)NPU_SYS_OWNER_NONE &&
        adapter->bvalid == 0u &&
        adapter->rvalid == 0u &&
        npu_sys_slave_cmd_idle(adapter) != 0u);
}

uint8_t npu_sys_slave_cmd_idle(
    const npu_sys_slave_cycle_t *adapter)
{
    if (adapter == (const npu_sys_slave_cycle_t *)0) {
        return 0u;
    }
    return (uint8_t)(
        adapter->cmd_fifo_count == 0u &&
        adapter->cmd_wait_response == 0u &&
        adapter->cmd_output_beat == 0u &&
        adapter->write.cmd_half_pending == 0u &&
        !(adapter->write.active != 0u &&
          adapter->write.target ==
              (uint8_t)NPU_SYS_TARGET_CMD_FIFO));
}

void npu_sys_slave_cycle_step(npu_sys_slave_cycle_t *adapter,
                              const npu_sys_slave_inputs_t *inputs,
                              npu_sys_slave_outputs_t *outputs)
{
    uint8_t aw_handshake;
    uint8_t ar_handshake;
    uint8_t w_handshake;
    uint8_t reg_request_handshake;
    uint8_t l1_request_handshake;
    uint8_t reg_response_handshake;
    uint8_t l1_response_handshake;
    uint8_t cmd_handshake;
    uint8_t cmd_response_handshake;

    if (adapter == (npu_sys_slave_cycle_t *)0 ||
        inputs == (const npu_sys_slave_inputs_t *)0 ||
        outputs == (npu_sys_slave_outputs_t *)0) {
        return;
    }

    (void)memset(outputs, 0, sizeof(*outputs));
    if (inputs->core_reset_n == 0u) {
        npu_sys_slave_cycle_reset(adapter);
        outputs->idle = 1u;
        outputs->cycle = 0u;
        return;
    }

    outputs->s_axi_awready =
        (uint8_t)(adapter->write.active == 0u &&
                  adapter->bvalid == 0u);
    if (outputs->s_axi_awready != 0u &&
        inputs->s_axi_awvalid != 0u &&
        npu_sys_cmd_write_format_valid(
            inputs->s_axi_awaddr,
            inputs->s_axi_awlen,
            inputs->s_axi_awsize,
            inputs->s_axi_awburst,
            inputs->s_axi_awlock) != 0u &&
        npu_sys_cmd_free_entries(adapter) <
            (uint8_t)(((uint16_t)inputs->s_axi_awlen +
                       1u) /
                      2u)) {
        outputs->s_axi_awready = 0u;
    }
    outputs->s_axi_wready =
        (uint8_t)(
            adapter->write.active != 0u &&
            adapter->write.received_beats <
                adapter->write.total_beats &&
            (adapter->write.target ==
                     (uint8_t)NPU_SYS_TARGET_CMD_FIFO ||
             adapter->write.beat_valid == 0u));
    outputs->s_axi_bid = adapter->bid;
    outputs->s_axi_bresp = adapter->bresp;
    outputs->s_axi_bvalid = adapter->bvalid;

    outputs->s_axi_arready =
        (uint8_t)(adapter->read.active == 0u &&
                  adapter->rvalid == 0u);
    outputs->s_axi_rid = adapter->rid;
    outputs->s_axi_rdata = adapter->rdata;
    outputs->s_axi_rresp = adapter->rresp;
    outputs->s_axi_rlast = adapter->rlast;
    outputs->s_axi_rvalid = adapter->rvalid;

    outputs->reg_req_valid_o = adapter->reg_request.valid;
    outputs->reg_req_write_o = adapter->reg_request.write;
    outputs->reg_req_space_o = adapter->reg_request.space;
    outputs->reg_req_addr_o =
        (uint16_t)adapter->reg_request.addr;
    outputs->reg_req_wdata_o = adapter->reg_request.wdata;
    outputs->reg_req_wstrb_o = adapter->reg_request.wstrb;
    outputs->reg_rsp_ready_o =
        (uint8_t)(
            adapter->reg_response_owner ==
                (uint8_t)NPU_SYS_OWNER_WRITE ||
            (adapter->reg_response_owner ==
                 (uint8_t)NPU_SYS_OWNER_READ &&
             adapter->rvalid == 0u));

    outputs->ssa_l1_req_valid_o =
        adapter->l1_request.valid;
    outputs->ssa_l1_req_write_o =
        adapter->l1_request.write;
    outputs->ssa_l1_req_addr_o =
        adapter->l1_request.addr;
    outputs->ssa_l1_req_wdata_o =
        adapter->l1_request.wdata;
    outputs->ssa_l1_req_wstrb_o =
        adapter->l1_request.wstrb;
    outputs->ssa_l1_rsp_ready_o =
        (uint8_t)(
            adapter->l1_response_owner ==
                (uint8_t)NPU_SYS_OWNER_WRITE ||
            (adapter->l1_response_owner ==
                 (uint8_t)NPU_SYS_OWNER_READ &&
             adapter->rvalid == 0u));

    if (adapter->cmd_fifo_count != 0u &&
        adapter->cmd_wait_response == 0u &&
        adapter->cmd_rsp_fifo_count <
            NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH) {
        const npu_sys_slave_cmd_entry_t *entry =
            &adapter->cmd_fifo[
                adapter->cmd_fifo_read_index];

        outputs->cmd_valid_o = 1u;
        if (adapter->cmd_output_beat == 0u) {
            outputs->cmd_data_o = entry->low;
            outputs->cmd_first_o = 1u;
            outputs->cmd_last_o = 0u;
        } else {
            outputs->cmd_data_o = entry->high;
            outputs->cmd_first_o = 0u;
            outputs->cmd_last_o = 1u;
        }
    }
    outputs->cmd_rsp_ready_o =
        (uint8_t)(
            adapter->cmd_wait_response != 0u &&
            adapter->cmd_rsp_fifo_count <
                NPU_SYS_SLAVE_CMD_RSP_FIFO_DEPTH);

    outputs->idle = npu_sys_slave_cycle_idle(adapter);
    outputs->cycle = adapter->cycle;

    aw_handshake =
        (uint8_t)(outputs->s_axi_awready != 0u &&
                  inputs->s_axi_awvalid != 0u);
    ar_handshake =
        (uint8_t)(outputs->s_axi_arready != 0u &&
                  inputs->s_axi_arvalid != 0u);
    w_handshake =
        (uint8_t)(outputs->s_axi_wready != 0u &&
                  inputs->s_axi_wvalid != 0u);
    reg_request_handshake =
        (uint8_t)(outputs->reg_req_valid_o != 0u &&
                  inputs->reg_req_ready_i != 0u);
    l1_request_handshake =
        (uint8_t)(outputs->ssa_l1_req_valid_o != 0u &&
                  inputs->ssa_l1_req_ready_i != 0u);
    reg_response_handshake =
        (uint8_t)(outputs->reg_rsp_ready_o != 0u &&
                  inputs->reg_rsp_valid_i != 0u);
    l1_response_handshake =
        (uint8_t)(outputs->ssa_l1_rsp_ready_o != 0u &&
                  inputs->ssa_l1_rsp_valid_i != 0u);
    cmd_handshake =
        (uint8_t)(outputs->cmd_valid_o != 0u &&
                  inputs->cmd_ready_i != 0u);
    cmd_response_handshake =
        (uint8_t)(outputs->cmd_rsp_ready_o != 0u &&
                  inputs->cmd_rsp_valid_i != 0u);

    if (inputs->cmd_error_clear_i != 0u) {
        adapter->cmd_protocol_error_sticky = 0u;
        adapter->cmd_overflow_sticky = 0u;
    }

    if (adapter->bvalid != 0u &&
        inputs->s_axi_bready != 0u) {
        adapter->bvalid = 0u;
    }
    if (adapter->rvalid != 0u &&
        inputs->s_axi_rready != 0u) {
        if (adapter->read.cmd_rsp_pop != 0u) {
            npu_sys_cmd_rsp_pop(adapter);
            adapter->read.cmd_rsp_pop = 0u;
        }
        if (adapter->rlast != 0u) {
            adapter->read.active = 0u;
        }
        adapter->rvalid = 0u;
    }

    if (cmd_handshake != 0u) {
        if (adapter->cmd_output_beat == 0u) {
            adapter->cmd_output_beat = 1u;
        } else {
            adapter->cmd_output_beat = 0u;
            adapter->cmd_wait_response = 1u;
        }
    }
    if (cmd_response_handshake != 0u) {
        if (npu_sys_cmd_rsp_push(
                adapter, inputs->cmd_rsp_data_i) != 0u) {
            npu_sys_cmd_pop(adapter);
            adapter->cmd_wait_response = 0u;
        }
    }

    if (aw_handshake != 0u) {
        npu_sys_slave_write_state_t *write =
            &adapter->write;

        (void)memset(write, 0, sizeof(*write));
        write->active = 1u;
        write->id = inputs->s_axi_awid;
        write->base_addr = inputs->s_axi_awaddr;
        write->len = inputs->s_axi_awlen;
        write->size = inputs->s_axi_awsize;
        write->burst = inputs->s_axi_awburst;
        write->lock = inputs->s_axi_awlock;
        write->cache = inputs->s_axi_awcache;
        write->prot = inputs->s_axi_awprot;
        write->qos = inputs->s_axi_awqos;
        write->total_beats =
            (uint16_t)inputs->s_axi_awlen + 1u;
        write->target = npu_sys_target_for_address(
            write->base_addr, &write->reg_space);
        write->error = npu_sys_static_error(
            adapter, inputs, 1u, write->base_addr,
            write->len, write->size, write->burst,
            write->lock, write->target,
            write->reg_space);
        if (write->target ==
            (uint8_t)NPU_SYS_TARGET_CMD_FIFO) {
            if (write->error != 0u) {
                adapter->cmd_protocol_error_sticky = 1u;
            } else {
                write->cmd_reserved =
                    (uint8_t)(write->total_beats / 2u);
            }
        }
    }

    if (ar_handshake != 0u) {
        npu_sys_slave_read_state_t *read =
            &adapter->read;

        (void)memset(read, 0, sizeof(*read));
        read->active = 1u;
        read->id = inputs->s_axi_arid;
        read->base_addr = inputs->s_axi_araddr;
        read->len = inputs->s_axi_arlen;
        read->size = inputs->s_axi_arsize;
        read->burst = inputs->s_axi_arburst;
        read->lock = inputs->s_axi_arlock;
        read->cache = inputs->s_axi_arcache;
        read->prot = inputs->s_axi_arprot;
        read->qos = inputs->s_axi_arqos;
        read->total_beats =
            (uint16_t)inputs->s_axi_arlen + 1u;
        read->decode_wait = 1u;
        read->target = npu_sys_target_for_address(
            read->base_addr, &read->reg_space);
        read->error = npu_sys_static_error(
            adapter, inputs, 0u, read->base_addr,
            read->len, read->size, read->burst,
            read->lock, read->target,
            read->reg_space);
    }

    if (w_handshake != 0u) {
        npu_sys_slave_write_state_t *write =
            &adapter->write;
        uint16_t beat = write->received_beats;
        uint32_t addr = npu_sys_beat_address(
            write->base_addr, write->size, beat);
        uint8_t expected_last =
            (uint8_t)(beat + 1u == write->total_beats);
        uint8_t legal_strobe =
            npu_sys_legal_strobe(addr, write->size);

        write->received_beats++;
        if (write->target ==
            (uint8_t)NPU_SYS_TARGET_CMD_FIFO) {
            uint8_t beat_ok =
                (uint8_t)(
                    write->error == 0u &&
                    ((inputs->s_axi_wlast != 0u) ==
                     (expected_last != 0u)) &&
                    inputs->s_axi_wstrb == 0xffu);

            write->finished_beats++;
            if (beat_ok == 0u) {
                write->error = 1u;
                adapter->cmd_protocol_error_sticky = 1u;
                npu_sys_cmd_discard_stage(write);
            } else if ((beat & 1u) == 0u) {
                write->cmd_half_data =
                    inputs->s_axi_wdata;
                write->cmd_half_pending = 1u;
            } else if (
                write->cmd_half_pending != 0u &&
                write->cmd_stage_count <
                    NPU_SYS_SLAVE_CMD_FIFO_DEPTH) {
                npu_sys_slave_cmd_entry_t *entry =
                    &write->cmd_stage[
                        write->cmd_stage_count];

                entry->low = write->cmd_half_data;
                entry->high = inputs->s_axi_wdata;
                write->cmd_stage_count++;
                write->cmd_half_pending = 0u;
                write->cmd_half_data = 0u;
            } else {
                write->error = 1u;
                adapter->cmd_protocol_error_sticky = 1u;
                npu_sys_cmd_discard_stage(write);
            }

            if (expected_last != 0u) {
                if (write->error == 0u &&
                    npu_sys_cmd_commit_stage(adapter) == 0u) {
                    write->error = 1u;
                }
                npu_sys_cmd_discard_stage(write);
                write->cmd_reserved = 0u;
            }
        } else {
            write->beat_valid = 1u;
            write->beat_index = beat;
            write->beat_data = inputs->s_axi_wdata;
            write->beat_strb = inputs->s_axi_wstrb;
            write->beat_last = inputs->s_axi_wlast;
            if ((inputs->s_axi_wlast != 0u) !=
                    (expected_last != 0u) ||
                (inputs->s_axi_wstrb &
                 (uint8_t)~legal_strobe) != 0u) {
                write->error = 1u;
            }
        }
    }

    if (reg_request_handshake != 0u) {
        adapter->reg_response_owner =
            adapter->reg_request.owner;
        adapter->reg_request.valid = 0u;
    }
    if (l1_request_handshake != 0u) {
        adapter->l1_response_owner =
            adapter->l1_request.owner;
        adapter->l1_request.valid = 0u;
    }

    if (reg_response_handshake != 0u) {
        uint8_t owner = adapter->reg_response_owner;
        uint8_t success =
            (uint8_t)(inputs->reg_rsp_status_i ==
                      (uint8_t)NPU_SYS_AXI_RESP_OKAY);

        adapter->reg_response_owner =
            (uint8_t)NPU_SYS_OWNER_NONE;
        if (owner == (uint8_t)NPU_SYS_OWNER_WRITE) {
            npu_sys_finish_write_beat(adapter, success);
        } else if (owner ==
                   (uint8_t)NPU_SYS_OWNER_READ) {
            if (success == 0u) {
                adapter->read.error = 1u;
            }
            npu_sys_make_read_response(
                adapter,
                npu_sys_read_lane_data(
                    &adapter->read,
                    inputs->reg_rsp_rdata_i),
                success != 0u ?
                    (uint8_t)NPU_SYS_AXI_RESP_OKAY :
                    (uint8_t)NPU_SYS_AXI_RESP_SLVERR);
        }
    }
    if (l1_response_handshake != 0u) {
        uint8_t owner = adapter->l1_response_owner;
        uint8_t success = npu_sys_l1_response_ok(
            inputs->ssa_l1_rsp_status_i);

        adapter->l1_response_owner =
            (uint8_t)NPU_SYS_OWNER_NONE;
        if (owner == (uint8_t)NPU_SYS_OWNER_WRITE) {
            npu_sys_finish_write_beat(adapter, success);
        } else if (owner ==
                   (uint8_t)NPU_SYS_OWNER_READ) {
            if (success == 0u) {
                adapter->read.error = 1u;
            }
            npu_sys_make_read_response(
                adapter,
                npu_sys_read_lane_data(
                    &adapter->read,
                    inputs->ssa_l1_rsp_rdata_i),
                success != 0u ?
                    (uint8_t)NPU_SYS_AXI_RESP_OKAY :
                    (uint8_t)NPU_SYS_AXI_RESP_SLVERR);
        }
    }

    if (adapter->read.decode_wait != 0u &&
        ar_handshake == 0u) {
        adapter->read.decode_wait = 0u;
    }

    if (adapter->read.active != 0u &&
        adapter->read.decode_wait == 0u &&
        adapter->rvalid == 0u &&
        adapter->read.error == 0u &&
        adapter->read.next_beat <
            adapter->read.total_beats &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_READ) == 0u) {
        if (adapter->read.target ==
            (uint8_t)NPU_SYS_TARGET_CMD_FIFO_STATUS) {
            npu_sys_make_read_response(
                adapter, npu_sys_cmd_status(adapter),
                (uint8_t)NPU_SYS_AXI_RESP_OKAY);
        } else if (
            adapter->read.target ==
                (uint8_t)NPU_SYS_TARGET_CMD_RSP_FIFO &&
            adapter->cmd_rsp_fifo_count != 0u) {
            adapter->read.cmd_rsp_pop = 1u;
            npu_sys_make_read_response(
                adapter,
                adapter->cmd_rsp_fifo[
                    adapter->cmd_rsp_fifo_read_index],
                (uint8_t)NPU_SYS_AXI_RESP_OKAY);
        }
    }

    if (adapter->write.active != 0u &&
        adapter->write.beat_valid != 0u &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_WRITE) == 0u &&
        (adapter->write.error != 0u ||
         adapter->write.target ==
             (uint8_t)NPU_SYS_TARGET_RESERVED ||
         adapter->write.target ==
             (uint8_t)NPU_SYS_TARGET_ERROR)) {
        npu_sys_finish_write_beat(
            adapter,
            (uint8_t)(
                adapter->write.error == 0u &&
                adapter->write.target ==
                    (uint8_t)NPU_SYS_TARGET_RESERVED));
    }

    if (adapter->read.active != 0u &&
        adapter->read.decode_wait == 0u &&
        adapter->rvalid == 0u &&
        adapter->read.next_beat <
            adapter->read.total_beats &&
        npu_sys_source_pending(
            adapter, (uint8_t)NPU_SYS_OWNER_READ) == 0u &&
        (adapter->read.error != 0u ||
         adapter->read.target ==
             (uint8_t)NPU_SYS_TARGET_RESERVED ||
         adapter->read.target ==
             (uint8_t)NPU_SYS_TARGET_ERROR)) {
        uint8_t okay =
            (uint8_t)(adapter->read.error == 0u &&
                      adapter->read.target ==
                          (uint8_t)
                              NPU_SYS_TARGET_RESERVED);

        npu_sys_make_read_response(
            adapter, 0u,
            okay != 0u ?
                (uint8_t)NPU_SYS_AXI_RESP_OKAY :
                (uint8_t)NPU_SYS_AXI_RESP_SLVERR);
    }

    npu_sys_complete_write_if_ready(adapter);
    npu_sys_schedule_reg_request(adapter);
    npu_sys_schedule_l1_request(adapter);
    adapter->cycle++;
}
