#ifndef NPU_BUS_TRACE_H
#define NPU_BUS_TRACE_H

#include "npu_cmodel.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_BUS_TRACE_WORD_BYTES 8u
#define NPU_BUS_TRACE_MAX_READ_PORTS 4u
#define NPU_BUS_TRACE_IGNORE_PORT 0xffu
#define NPU_BUS_TRACE_INVALID_INDEX UINT32_MAX

/*
 * A read entry represents one aligned 64-bit transfer in one ordered read
 * pass. strb marks the bytes that the functional operator consumed. data
 * contains the expected value for those bytes in little-endian order.
 * read_pass distinguishes repeated reads of the same word by a multi-pass
 * unit.
 *
 * A write entry represents the final value of every byte modified in the
 * aligned word. Multiple byte writes to the same word are combined.
 */
typedef struct {
    uint64_t addr;
    uint64_t data;
    uint8_t strb;
    uint8_t space;
    uint8_t port;
    uint8_t reserved;
    uint32_t read_pass;
} npu_bus_trace_entry_t;

/*
 * Returning NPU_BUS_TRACE_IGNORE_PORT suppresses a functional validation
 * read that does not correspond to a hardware data request.
 */
typedef uint8_t (*npu_bus_trace_port_fn)(
    const void *context,
    npu_space_t space,
    uint64_t aligned_addr);

/*
 * All arrays belong to the caller. Hash table slot counts must be powers of
 * two and should be at least twice their corresponding entry capacities.
 * npu_bus_trace_begin() clears the hash tables and entry counters.
 */
typedef struct {
    npu_bus_trace_entry_t *read;
    size_t read_capacity;
    size_t read_count;
    uint32_t *read_hash;
    size_t read_hash_slots;

    npu_bus_trace_entry_t *write;
    size_t write_capacity;
    size_t write_count;
    uint32_t *write_hash;
    size_t write_hash_slots;

    npu_bus_trace_port_fn select_read_port;
    const void *select_read_port_context;
    uint32_t current_read_pass;
    uint32_t read_pass_count;
    uint8_t read_port_count;
    uint8_t read_capture_enabled;
    uint8_t active;
    uint8_t overflow;
} npu_bus_trace_t;

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
    const void *select_read_port_context);

void npu_bus_trace_end(npu_bus_trace_t *trace);

/*
 * Starts another ordered read pass without clearing entries from earlier
 * passes. Reads of the same aligned word are combined only within one pass,
 * so replay can issue the repeated transfers required by multi-pass units.
 */
int npu_bus_trace_next_read_pass(npu_bus_trace_t *trace);

/*
 * Temporarily suppresses trace entries for functional preflight reads.
 * Journal overlay lookup remains active, so a suppressed read still sees
 * bytes written earlier in the same functional transaction.
 */
uint8_t npu_bus_trace_set_read_capture(
    npu_bus_trace_t *trace,
    uint8_t enable);

/*
 * These helpers are used by the functional memory access layer. They are
 * public so focused tests can check capture behavior without starting an
 * Engine Adapter.
 */
int npu_bus_trace_record_read_byte(npu_bus_trace_t *trace,
                                   npu_space_t space,
                                   uint64_t addr,
                                   uint8_t value);

int npu_bus_trace_record_write_byte(npu_bus_trace_t *trace,
                                    npu_space_t space,
                                    uint64_t addr,
                                    uint8_t value);

int npu_bus_trace_lookup_write_byte(const npu_bus_trace_t *trace,
                                    npu_space_t space,
                                    uint64_t addr,
                                    uint8_t *value);

#ifdef __cplusplus
}
#endif

#endif
