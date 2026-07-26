#ifndef NPU_L1_CYCLE_H
#define NPU_L1_CYCLE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_L1_CYCLE_BYTES (1024u * 1024u)
#define NPU_L1_CYCLE_WORD_BYTES 8u
#define NPU_L1_CYCLE_WORDS \
    (NPU_L1_CYCLE_BYTES / NPU_L1_CYCLE_WORD_BYTES)
#define NPU_L1_CYCLE_BANKS 16u
#define NPU_L1_CYCLE_READ_LATENCY 2u
#define NPU_L1_CYCLE_STARVE_LIMIT 64u
#define NPU_L1_CYCLE_MAX_BEATS 256u
#define NPU_L1_CYCLE_TAG_MASK 0x0fffu

typedef enum {
    NPU_L1_STATUS_OK = 0,
    NPU_L1_STATUS_ECC_CORRECTED = 1,
    NPU_L1_STATUS_ECC_UNCORRECTABLE = 2,
    NPU_L1_STATUS_PORT_PROTOCOL_ERROR = 3,
    NPU_L1_STATUS_ADDR_FAULT = 4
} npu_l1_cycle_status_t;

/*
 * Read ports follow the reference configuration in Spec section 10.2.
 * Every port carries one independent 64-bit ready/valid interface.
 */
typedef enum {
    NPU_L1_RD_DMA = 0,
    NPU_L1_RD_ME_A = 1,
    NPU_L1_RD_ME_B = 2,
    NPU_L1_RD_ME_AUX = 3,
    NPU_L1_RD_IVE_SRC0 = 4,
    NPU_L1_RD_IVE_SRC1 = 5,
    NPU_L1_RD_IVE_SRC2 = 6,
    NPU_L1_RD_IVE_MASK = 7,
    NPU_L1_RD_CME_SRC0 = 8,
    NPU_L1_RD_CME_SRC1 = 9,
    NPU_L1_RD_CME_SRC2 = 10,
    NPU_L1_RD_CME_MASK = 11,
    NPU_L1_RD_DEBUG = 12,
    NPU_L1_READ_PORT_COUNT = 13
} npu_l1_cycle_read_port_t;

typedef enum {
    NPU_L1_WR_DMA = 0,
    NPU_L1_WR_ME_C = 1,
    NPU_L1_WR_IVE_DST = 2,
    NPU_L1_WR_CME_DST = 3,
    NPU_L1_WR_DEBUG = 4,
    NPU_L1_WRITE_PORT_COUNT = 5
} npu_l1_cycle_write_port_t;

typedef struct {
    uint8_t req_valid;
    uint32_t req_addr;
    uint8_t req_beats;
    uint16_t req_tag;
    uint8_t rsp_ready;
} npu_l1_cycle_read_input_t;

typedef struct {
    uint8_t req_ready;
    uint8_t rsp_valid;
    uint64_t rsp_data;
    uint16_t rsp_tag;
    uint8_t rsp_last;
    uint8_t rsp_status;
} npu_l1_cycle_read_output_t;

typedef struct {
    uint8_t req_valid;
    uint32_t req_addr;
    uint8_t req_beats;
    uint16_t req_tag;
    uint8_t data_valid;
    uint64_t data;
    uint8_t strb;
    uint8_t last;
    uint8_t rsp_ready;
} npu_l1_cycle_write_input_t;

typedef struct {
    uint8_t req_ready;
    uint8_t data_ready;
    uint8_t rsp_valid;
    uint16_t rsp_tag;
    uint8_t rsp_status;
} npu_l1_cycle_write_output_t;

typedef struct {
    uint8_t reset_n;
    /* Clears the persistent uncorrectable-ECC record at this rising edge. */
    uint8_t error_clear;
    uint32_t param_l1_base;
    uint32_t param_l1_limit;
    uint8_t param_lock;
    /*
     * Bit i authorizes write port i to write an unlocked parameter region.
     * A locked region rejects every write regardless of this mask.
     */
    uint8_t param_write_allow_mask;
    npu_l1_cycle_read_input_t read[NPU_L1_READ_PORT_COUNT];
    npu_l1_cycle_write_input_t write[NPU_L1_WRITE_PORT_COUNT];
} npu_l1_cycle_inputs_t;

typedef struct {
    npu_l1_cycle_read_output_t read[NPU_L1_READ_PORT_COUNT];
    npu_l1_cycle_write_output_t write[NPU_L1_WRITE_PORT_COUNT];
    uint8_t idle;
    uint8_t write_idle;
    /*
     * Set only when at least two eligible SRAM operations need the same
     * single-ported bank in this cycle. A waiting response, a full response
     * pipeline, or an inactive producer does not count as a bank stall.
     * Mask bit numbers are the read/write port enum values above.
     */
    uint8_t bank_stall;
    uint16_t read_bank_stall_mask;
    uint8_t write_bank_stall_mask;
    uint8_t ecc_corrected_pulse;
    uint8_t ecc_uncorrectable_pulse;
    /*
     * Number of first-visible ECC responses of each class in this cycle.
     * The pulse fields are the logical OR of the corresponding count.
     */
    uint8_t ecc_corrected_events;
    uint8_t ecc_uncorrectable_events;

    /*
     * First uncorrectable ECC event since reset or error_clear. The payload
     * remains unchanged while valid is one. ECC is currently checked on reads,
     * so ecc_error_write is zero in V1.0.
     */
    uint8_t ecc_error_valid;
    uint8_t ecc_error_status;
    uint32_t ecc_error_addr;
    uint8_t ecc_error_port;
    uint8_t ecc_error_bank;
    uint8_t ecc_error_write;

    uint64_t cycle;
} npu_l1_cycle_outputs_t;

typedef struct {
    uint8_t valid;
    uint64_t data;
    uint16_t tag;
    uint8_t last;
    uint8_t status;
    uint8_t ecc_event_pending;
} npu_l1_cycle_read_pipe_t;

typedef struct {
    uint8_t active;
    uint8_t request_status;
    uint16_t tag;
    uint16_t total_beats;
    uint16_t issued_beats;
    uint16_t retired_beats;
    uint32_t base_addr;
    uint32_t wait_cycles;
} npu_l1_cycle_read_state_t;

typedef struct {
    uint8_t active;
    uint8_t request_status;
    uint16_t tag;
    uint16_t total_beats;
    uint16_t accepted_beats;
    uint32_t base_addr;
    uint32_t wait_cycles;

    uint8_t completion_pending;
    uint16_t completion_tag;
    uint8_t completion_status;

    uint8_t response_valid;
    uint16_t response_tag;
    uint8_t response_status;

    /*
     * One fall-through input slot decouples data_ready from data_valid.
     * A beat that wins bank arbitration may pass directly to SRAM. A beat
     * accepted while its bank is busy is retained here until it can run.
     */
    uint8_t data_buffer_valid;
    uint64_t data_buffer;
    uint8_t strb_buffer;
    uint8_t last_buffer;
} npu_l1_cycle_write_state_t;

typedef struct {
    uint8_t *memory;
    uint8_t *ecc_status;
    size_t memory_bytes;

    npu_l1_cycle_read_state_t
        read_state[NPU_L1_READ_PORT_COUNT];
    npu_l1_cycle_read_pipe_t
        read_pipe[NPU_L1_READ_PORT_COUNT]
                 [NPU_L1_CYCLE_READ_LATENCY];
    npu_l1_cycle_write_state_t
        write_state[NPU_L1_WRITE_PORT_COUNT];

    uint64_t cycle;
    uint64_t ecc_corrected_count;
    uint64_t ecc_uncorrectable_count;

    uint8_t ecc_error_valid;
    uint8_t ecc_error_status;
    uint32_t ecc_error_addr;
    uint8_t ecc_error_port;
    uint8_t ecc_error_bank;
    uint8_t ecc_error_write;
} npu_l1_cycle_t;

/*
 * The caller owns the 1 MiB data array and one status byte per 64-bit word.
 * No heap allocation is performed by this model.
 */
int npu_l1_cycle_init(npu_l1_cycle_t *controller,
                      uint8_t *memory,
                      size_t memory_bytes,
                      uint8_t *ecc_status,
                      size_t ecc_status_bytes);

/*
 * Reset clears queues, pipelines, responses and counters. Parameter-region
 * control is supplied continuously through npu_l1_cycle_inputs_t and is not
 * stored by the controller. Reset does not clear SRAM data or the
 * caller-owned ECC array.
 */
void npu_l1_cycle_reset(npu_l1_cycle_t *controller);

int npu_l1_cycle_inject_ecc(npu_l1_cycle_t *controller,
                            uint32_t aligned_addr,
                            npu_l1_cycle_status_t status);

void npu_l1_cycle_step(npu_l1_cycle_t *controller,
                       const npu_l1_cycle_inputs_t *inputs,
                       npu_l1_cycle_outputs_t *outputs);

uint8_t npu_l1_cycle_idle(const npu_l1_cycle_t *controller);

#ifdef __cplusplus
}
#endif

#endif
