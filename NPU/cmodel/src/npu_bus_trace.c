#include "npu_bus_trace.h"

#include <string.h>

static int npu_bus_trace_power_of_two(size_t value)
{
    return value != 0u && (value & (value - 1u)) == 0u;
}

static uint64_t npu_bus_trace_mix(uint64_t value)
{
    value ^= value >> 30u;
    value *= UINT64_C(0xbf58476d1ce4e5b9);
    value ^= value >> 27u;
    value *= UINT64_C(0x94d049bb133111eb);
    value ^= value >> 31u;
    return value;
}

static size_t npu_bus_trace_hash_start(uint64_t addr,
                                       uint8_t space,
                                       uint8_t port,
                                       uint32_t read_pass,
                                       size_t slots)
{
    uint64_t key =
        addr ^ ((uint64_t)space << 61u) ^
        ((uint64_t)port << 56u) ^
        ((uint64_t)read_pass *
         UINT64_C(0x9e3779b97f4a7c15));

    return (size_t)(npu_bus_trace_mix(key) & (slots - 1u));
}

static int npu_bus_trace_entry_equal(
    const npu_bus_trace_entry_t *entry,
    uint64_t addr,
    uint8_t space,
    uint8_t port,
    uint32_t read_pass,
    int include_port)
{
    return entry->addr == addr &&
           entry->space == space &&
           entry->read_pass == read_pass &&
           (include_port == 0 || entry->port == port);
}

static int npu_bus_trace_find(
    const npu_bus_trace_entry_t *entries,
    size_t entry_count,
    const uint32_t *hash,
    size_t hash_slots,
    uint64_t addr,
    uint8_t space,
    uint8_t port,
    uint32_t read_pass,
    int include_port,
    size_t *slot,
    uint32_t *entry_index)
{
    size_t index;
    size_t probe;

    index = npu_bus_trace_hash_start(
        addr, space, include_port != 0 ? port : 0u,
        read_pass, hash_slots);
    for (probe = 0u; probe < hash_slots; probe++) {
        uint32_t candidate = hash[index];

        if (candidate == NPU_BUS_TRACE_INVALID_INDEX) {
            *slot = index;
            *entry_index = NPU_BUS_TRACE_INVALID_INDEX;
            return 1;
        }
        if ((size_t)candidate >= entry_count) {
            return 0;
        }
        if (npu_bus_trace_entry_equal(
                &entries[candidate], addr, space, port,
                read_pass, include_port)) {
            *slot = index;
            *entry_index = candidate;
            return 1;
        }
        index = (index + 1u) & (hash_slots - 1u);
    }
    return 0;
}

static int npu_bus_trace_add_byte(
    npu_bus_trace_entry_t *entries,
    size_t capacity,
    size_t *entry_count,
    uint32_t *hash,
    size_t hash_slots,
    npu_space_t space,
    uint64_t addr,
    uint8_t port,
    uint8_t value,
    uint32_t read_pass,
    int include_port)
{
    uint64_t aligned_addr =
        addr & ~(uint64_t)(NPU_BUS_TRACE_WORD_BYTES - 1u);
    uint32_t entry_index;
    size_t hash_slot;
    uint32_t byte_index =
        (uint32_t)(addr & (NPU_BUS_TRACE_WORD_BYTES - 1u));
    uint64_t byte_mask = UINT64_C(0xff) << (byte_index * 8u);

    if (!npu_bus_trace_find(
            entries, *entry_count, hash, hash_slots,
            aligned_addr, (uint8_t)space, port, read_pass,
            include_port,
            &hash_slot, &entry_index)) {
        return 0;
    }
    if (entry_index == NPU_BUS_TRACE_INVALID_INDEX) {
        npu_bus_trace_entry_t *entry;

        if (*entry_count >= capacity ||
            *entry_count >= UINT32_MAX) {
            return 0;
        }
        entry_index = (uint32_t)*entry_count;
        (*entry_count)++;
        hash[hash_slot] = entry_index;
        entry = &entries[entry_index];
        (void)memset(entry, 0, sizeof(*entry));
        entry->addr = aligned_addr;
        entry->space = (uint8_t)space;
        entry->port = port;
        entry->read_pass = read_pass;
    }

    entries[entry_index].data =
        (entries[entry_index].data & ~byte_mask) |
        ((uint64_t)value << (byte_index * 8u));
    entries[entry_index].strb |=
        (uint8_t)(1u << byte_index);
    return 1;
}

int npu_bus_trace_begin(
    npu_bus_trace_t *trace,
    npu_bus_trace_entry_t *read_entries,
    size_t read_capacity,
    uint32_t *read_hash,
    size_t read_hash_slots,
    npu_bus_trace_entry_t *write_entries,
    size_t write_capacity,
    uint32_t *write_hash,
    size_t write_hash_slots,
    uint8_t read_port_count,
    npu_bus_trace_port_fn select_read_port,
    const void *select_read_port_context)
{
    size_t index;

    if (trace == (npu_bus_trace_t *)0 ||
        read_entries == (npu_bus_trace_entry_t *)0 ||
        read_capacity == 0u ||
        read_hash == (uint32_t *)0 ||
        !npu_bus_trace_power_of_two(read_hash_slots) ||
        read_hash_slots < read_capacity ||
        write_entries == (npu_bus_trace_entry_t *)0 ||
        write_capacity == 0u ||
        write_hash == (uint32_t *)0 ||
        !npu_bus_trace_power_of_two(write_hash_slots) ||
        write_hash_slots < write_capacity ||
        read_port_count == 0u ||
        read_port_count > NPU_BUS_TRACE_MAX_READ_PORTS) {
        return 0;
    }

    (void)memset(trace, 0, sizeof(*trace));
    trace->read = read_entries;
    trace->read_capacity = read_capacity;
    trace->read_hash = read_hash;
    trace->read_hash_slots = read_hash_slots;
    trace->write = write_entries;
    trace->write_capacity = write_capacity;
    trace->write_hash = write_hash;
    trace->write_hash_slots = write_hash_slots;
    trace->read_port_count = read_port_count;
    trace->select_read_port = select_read_port;
    trace->select_read_port_context =
        select_read_port_context;
    trace->current_read_pass = 0u;
    trace->read_pass_count = 1u;
    for (index = 0u; index < read_hash_slots; index++) {
        read_hash[index] = NPU_BUS_TRACE_INVALID_INDEX;
    }
    for (index = 0u; index < write_hash_slots; index++) {
        write_hash[index] = NPU_BUS_TRACE_INVALID_INDEX;
    }
    trace->read_capture_enabled = 1u;
    trace->active = 1u;
    return 1;
}

void npu_bus_trace_end(npu_bus_trace_t *trace)
{
    if (trace == (npu_bus_trace_t *)0) {
        return;
    }
    trace->active = 0u;
}

int npu_bus_trace_next_read_pass(npu_bus_trace_t *trace)
{
    size_t index;

    if (trace == (npu_bus_trace_t *)0 ||
        trace->active == 0u) {
        return 1;
    }
    if (trace->current_read_pass == UINT32_MAX) {
        trace->overflow = 1u;
        return 0;
    }
    trace->current_read_pass++;
    trace->read_pass_count++;
    for (index = 0u; index < trace->read_hash_slots;
         index++) {
        trace->read_hash[index] =
            NPU_BUS_TRACE_INVALID_INDEX;
    }
    return 1;
}

uint8_t npu_bus_trace_set_read_capture(
    npu_bus_trace_t *trace,
    uint8_t enable)
{
    uint8_t previous;

    if (trace == (npu_bus_trace_t *)0) {
        return 0u;
    }
    previous = trace->read_capture_enabled;
    trace->read_capture_enabled =
        enable != 0u ? 1u : 0u;
    return previous;
}

int npu_bus_trace_record_read_byte(npu_bus_trace_t *trace,
                                   npu_space_t space,
                                   uint64_t addr,
                                   uint8_t value)
{
    uint8_t port = 0u;

    if (trace == (npu_bus_trace_t *)0 ||
        trace->active == 0u) {
        return 1;
    }
    if (trace->read_capture_enabled == 0u) {
        return 1;
    }
    if (trace->select_read_port !=
        (npu_bus_trace_port_fn)0) {
        port = trace->select_read_port(
            trace->select_read_port_context, space,
            addr & ~(uint64_t)(NPU_BUS_TRACE_WORD_BYTES - 1u));
    }
    if (port == NPU_BUS_TRACE_IGNORE_PORT) {
        return 1;
    }
    if (port >= trace->read_port_count ||
        !npu_bus_trace_add_byte(
            trace->read, trace->read_capacity,
            &trace->read_count, trace->read_hash,
            trace->read_hash_slots, space, addr, port,
            value, trace->current_read_pass, 1)) {
        trace->overflow = 1u;
        return 0;
    }
    return 1;
}

int npu_bus_trace_record_write_byte(npu_bus_trace_t *trace,
                                    npu_space_t space,
                                    uint64_t addr,
                                    uint8_t value)
{
    if (trace == (npu_bus_trace_t *)0 ||
        trace->active == 0u) {
        return 1;
    }
    if (!npu_bus_trace_add_byte(
            trace->write, trace->write_capacity,
            &trace->write_count, trace->write_hash,
            trace->write_hash_slots, space, addr, 0u,
            value, 0u, 0)) {
        trace->overflow = 1u;
        return 0;
    }
    return 1;
}

int npu_bus_trace_lookup_write_byte(const npu_bus_trace_t *trace,
                                    npu_space_t space,
                                    uint64_t addr,
                                    uint8_t *value)
{
    uint64_t aligned_addr;
    uint32_t entry_index;
    uint32_t byte_index;
    size_t hash_slot;

    if (trace == (const npu_bus_trace_t *)0 ||
        value == (uint8_t *)0 ||
        trace->write == (npu_bus_trace_entry_t *)0 ||
        trace->write_hash == (uint32_t *)0) {
        return 0;
    }
    aligned_addr =
        addr & ~(uint64_t)(NPU_BUS_TRACE_WORD_BYTES - 1u);
    if (!npu_bus_trace_find(
            trace->write, trace->write_count,
            trace->write_hash, trace->write_hash_slots,
            aligned_addr, (uint8_t)space, 0u, 0u, 0,
            &hash_slot, &entry_index) ||
        entry_index == NPU_BUS_TRACE_INVALID_INDEX) {
        return 0;
    }
    byte_index =
        (uint32_t)(addr & (NPU_BUS_TRACE_WORD_BYTES - 1u));
    if ((trace->write[entry_index].strb &
         (uint8_t)(1u << byte_index)) == 0u) {
        return 0;
    }
    *value = (uint8_t)(
        trace->write[entry_index].data >>
        (byte_index * 8u));
    return 1;
}
