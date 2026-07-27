# NPU control, storage, and CMD128 RTL

This directory contains the synthesizable control and storage foundation for
one NPU core. Software-visible buses and internal storage transfers use 64-bit
beats. Every local active-low reset input is named `reset_n`.

CMD128 carries an 80-bit operation payload containing task addresses, sizes,
data types, and function options. Every command uses this inline format. A
submitted task does not fetch a parameter block from system memory.

## Source files

| File | Function |
| --- | --- |
| `../npu_rtl_pkg.sv` | Shared widths, status values, integer data types, six-bit command opcodes, and CMD128 field helpers |
| `npu_cmd_frontend.sv` | Reassembles two 64-bit beats into CMD128, checks the header, checks duplicate command IDs, and holds accepted commands in an eight-entry FIFO |
| `npu_inline_desc_decode.sv` | Checks the inline payload and expands it into the internal engine request structure |
| `npu_task_scheduler.sv` | Holds the task table and Event Table, resolves Event generations, dispatches ready tasks, and records terminal results |
| `npu_descriptor_fetch.sv` | Standalone parameter-block fetch unit retained for module-level verification; CMD128 task submission does not request it |
| `npu_lsc.sv` | Implements 64-bit control registers, first-fault state, interrupt state, reset drain control, and exported configuration |
| `npu_crg.sv` | Synchronizes reset release, qualifies local clock enables, and acknowledges an idle DVFS request |
| `npu_wdt.sv` | Detects a lack of observable forward progress and holds a timeout request until software kicks or disables it |
| `../memory/npu_l1buf.sv` | Arbitrates single-beat clients and stores data in banked 64-bit SRAM arrays |
| `../memory/npu_tbu.sv` | Performs identity translation after stream, access-permission, alignment, and address-range checks |
| `../memory/npu_axi_mif_master.sv` | Converts an internal 64-bit global-memory request into an AXI4 read or write |

## CMD ingress

The SoC CPU is outside the NPU. It accesses the NPU through a 64-bit AXI Slave
port. Commands are written to the fixed `CMD_FIFO_DATA` address with
`AWBURST=FIXED`.

One command always uses two adjacent beats:

1. low 64 bits with `first=1,last=0`;
2. high 64 bits with `first=0,last=1`.

A legal burst contains 2 through 16 beats and therefore submits 1 through 8
commands. A command pair cannot be interleaved with another pair.

`npu_cmd_frontend` checks the pair before exposing it to the scheduler. If the
high beat does not arrive within `WAIT_HIGH_TIMEOUT` cycles, whose default is
32, the partial pair is discarded and a `TIMEOUT` response is produced.

The command response contains:

```text
[11:0]   command_id
[19:12]  status
[27:20]  remaining CFE FIFO entries
```

`command_id` comes from CMD128 bits `[121:112]`. The response places it in a
12-bit field whose upper two bits are zero.

The CFE-to-scheduler duplicate-ID query carries `cmd_id_lookup_id[9:0]`.
Scheduler task records and completion messages remain 12 bits wide for the
internal interface; bits 11 and 10 are always zero for a CMD128 command.

## CMD128 header

| CMD128 bits | Field | Meaning |
| ---: | --- | --- |
| `[127:122]` | `opcode` | Six-bit operation selector; values 0 through 32 are assigned |
| `[121:112]` | `command_id` | Ten-bit in-flight task ID, 0 through 1023 |
| `[111:104]` | `wait_event0` | First Event ID; `8'hff` means unused |
| `[103:96]` | `wait_event1` | Second Event ID; `8'hff` means unused |
| `[95:88]` | `signal_event` | Completion Event ID; `8'hff` means unused |
| `[87]` | `irq_success` | Request an interrupt after successful completion |
| `[86]` | `irq_error` | Request an interrupt after failed completion |
| `[85]` | `strict_numeric` | Report enabled complex-function numeric errors |
| `[84]` | `ordered` | Apply ordered issue rules |
| `[83:82]` | `timeout_class` | Select one of four timeout configurations |
| `[81:80]` | `dtype` | `0=INT4`, `1=INT8`, `2=INT32`, `3=INT16` |
| `[79:0]` | `payload` | Operation-specific inline parameters |

The six-bit opcode has the following decode. Values 33 through 63 are illegal.

| Values | Engine | Operations |
| --- | --- | --- |
| 0–4 | Control | NOP, EVENT_SIGNAL, EVENT_REARM, EVENT_JOIN, GLOBAL_FENCE |
| 5–11 | DMA | COPY_1D, COPY_ND, FILL, TRANSPOSE_2D, PACK, SPLIT, GATHER_ND |
| 12–15 | Matrix | GEMM, BMM, GEMM_ACCUM, GEMM_ZERO |
| 16–25 | Vector | ADD, SUB, MUL, FMA, MAX, MIN, CMP, SELECT, CLAMP, RELU |
| 26–32 | Complex | ACT, SOFTMAX, NORM, ROPE, STAT, RECIP, ADD_RESCALE |

GATHER_ND, ROPE, and RECIP have assigned values, while their capability bits
are disabled in this configuration. Opcodes 11, 29, and 31 therefore return
`ILLEGAL_OPCODE`.

## Inline payload expansion

`npu_inline_desc_decode` converts the command fields to the internal
`task_desc_flat[2047:0]` request used by the execution engines. This is a local
implementation interface. It is not an external array and does not create MIF
traffic.

The address references use the following units:

- DMA `AREF28`: one address-space bit, three base-register bits, and a 24-bit
  byte offset;
- Matrix `LREF14`: L1 byte address equals the encoded value multiplied by 64;
- Matrix bias `LREF12`: L1 byte address equals the encoded value multiplied by
  64, with zero meaning that bias is disabled;
- Vector and Complex `LREF16`: L1 byte address equals the encoded value
  multiplied by 16.

Global DMA base selectors are zero, input, weight, work, output, and KV for
codes 0 through 5. Codes 6 and 7 are rejected.

### Matrix fields

GEMM, GEMM_ACCUM, and GEMM_ZERO use:

```text
[79:66] A LREF14
[65:52] B LREF14
[51:38] C LREF14
[37:26] bias LREF12
[25:20] M-1
[19:14] N-1
[13:8]  K-1
[7]     B is INT4 when A is INT8
[6:5]   C dtype
[4:0]   direct requant right shift, 0 through 31
```

BMM replaces the bias field with `batch-1`, then stores `M-1`, `N-1`, `K-1`,
the B-INT4 bit, C dtype, and the direct five-bit shift. Its lowest six payload
bits must be zero.

The accepted multiplier pairs are INT4×INT4, INT8×INT8, INT8×INT4, and
INT16×INT16. An INT32 destination requires a zero right shift. Bias entries are
INT32 and have shape `[N]`; bias entry `b[j]` is added to column `j` in every
one of the `M` output rows.

### Vector fields

The Vector format contains `src0`, `src1`, `src2`, and `dst` LREF16 values,
followed by `rows-1`, `length-1`, and three two-bit broadcast selectors. CMP
uses the top three bits of the `src2` field as the compare mode and produces an
INT8 zero-or-one mask. SELECT reads `src2` as that mask. CLAMP interprets
`src1` and `src2` as signed 16-bit limits and requires their broadcast bits to
be zero.

### Complex fields

The Complex format contains `src0`, `aux`, and `dst` LREF16 values,
`rows-1`, `length-1`, and 19 bits of function metadata. The metadata selects
the activation, signed power-of-two scales, destination type, clipping mode,
Softmax mask mode, Norm mode, and epsilon profile. Complex functions use
integer input, private FP32 intermediate values, and integer output.

## Task Scheduler and Event Table

The scheduler has 16 task entries by default and 255 usable Event entries.
`8'hff` is reserved as the unused Event encoding.

At command acceptance, the scheduler reads each referenced Event entry and
attaches its current four-bit generation to the local task. The generation is
therefore not carried in CMD128.

- a task with `wait_event0` or `wait_event1` remains waiting until both required
  Events succeed;
- a failed required Event terminates the consumer with `DEPENDENCY_FAILED`;
- a task with `signal_event` reserves that Event and completes it when the task
  reaches a terminal state;
- EVENT_JOIN combines two prior Events;
- EVENT_REARM advances an Event to its next generation only after the old
  generation is terminal and its waiter count is zero;
- GLOBAL_FENCE snapshots earlier selected-engine tasks when accepted.

There can be one active task per engine. DMA, Matrix, Vector, and Complex use
the following stable ready/valid interface:

```text
task_valid, task_ready
task_opcode[7:0]
task_command_id[11:0]
task_desc_flat[2047:0]

done_valid, done_ready
done_command_id[11:0]
done_status[7:0]
done_fault_addr[47:0]
done_progress[63:0]
```

`task_valid` and its payload remain stable while `task_ready` is low. A terminal
task remains queryable until software completes the ACK request. The 12-bit
task and completion ID fields carry `{2'b00, command_id[9:0]}`.

## Scheduler control requests

The scheduler accepts one WAIT, QUERY, or FENCE request at a time through
`axi_ctl_*`.

| Operation | `arg0` | `arg1` | Result |
| --- | --- | --- | --- |
| WAIT | Event reference in bits `[11:0]` | Maximum wait cycles in bits `[31:0]` | Terminal Event state and producer task ID, or an error status |
| QUERY | Command ID in bits `[11:0]` | Selector in bits `[2:0]` | Selector-specific task data |
| FENCE | Engine mask in bits `[3:0]` | Maximum wait cycles in bits `[31:0]` | Earliest failed target status, `SUCCESS`, or `TIMEOUT` |

QUERY selectors are:

| Selector | Result |
| ---: | --- |
| 0 | Task state `[3:0]`, status `[11:4]`, command ID `[23:12]` |
| 1 | User tag `[31:0]` and signal Event `[43:32]` |
| 2 | Fault address `[47:0]` |
| 3 | Engine progress `[63:0]` |
| 4 | ACK result: `0=ACKED`, `1=NOT_TERMINAL`, `2=NOT_FOUND` |
| 5 | Error information `[31:0]` |
| 6 | Completion flags `[15:0]` |
| 7 | Reserved and returns `BAD_DESC` |

## L1 interface

`npu_l1buf` exposes one request/response pair per client:

```text
req_valid, req_ready, req_write
req_addr[19:0], req_wdata[63:0], req_wstrb[7:0]
rsp_valid, rsp_ready, rsp_rdata[63:0], rsp_status[2:0]
```

The default SRAM is 1 MiB in 16 banks. The current arbiter accepts one client
request per cycle and rotates its starting client after every accepted request.
Reads and writes return through per-client response holding registers. SRAM
contents are intentionally not reset.

The external L1 window passes AXI Slave accesses through an internal request
adapter. Software must enable the window before use.

## MIF, TBU, and AXI Master

DMA is the global-memory requester. Matrix, Vector, and Complex access L1 only.
CMD128 task submission does not use MIF for parameter-block fetches.

MIF submits a translated address request to TBU before issuing an AXI request.
The AXI Master port connects to the SoC AXI Fabric; DDR and other permitted
targets are outside the NPU.

The current AXI master uses:

- one outstanding request;
- `AxSIZE=3` for 64-bit beats;
- independent AW and W handshakes;
- held B/R readiness until the response arrives;
- AXI ID, response, and `RLAST` checks;
- stable payload while a valid signal waits for ready.

Read data and write completion share the internal response channel. AXI
`SLVERR`, `DECERR`, translation errors, and protocol errors produce distinct
memory status values.

## Implemented limits

- The RTL capability register disables GATHER_ND, ROPE, and RECIP.
- CMD128 shape fields limit Matrix `M`, `N`, `K`, and BMM batch values to 1 through
  64 per instruction. The compiler splits larger work.
- Vector length is 1 through 32 and rows are 1 through 32 per instruction.
- Complex length is 1 through 256 and rows are 1 through 32 per instruction.
- MIF currently accepts one internal request at a time.
- TBU uses a configurable identity rule instead of a page-table walker.
- The current L1 arbiter grants one SRAM access per cycle across its clients.
- ECC status values exist, but the SRAM arrays do not yet store ECC bits.
- Descriptor CRC remains unsupported by the standalone fetch unit.

## Verification

Run the complete RTL regression and lint checks from `NPU/rtl`:

```sh
make clean
make test
make lint
make clean
```

The regression includes:

- atomic command-pair assembly and partial-command timeout;
- command ID `10'h3ff`, disabled opcode values 11, 29, and 31, and illegal
  opcode values 33 through 63;
- CMD128 decode for all engine classes;
- zero Descriptor Fetch Unit requests during CMD128 task submission;
- positive and negative payload checks;
- Event generation resolution and EVENT_REARM;
- INT4, INT8, INT16, and INT32 engine cases;
- Matrix direct five-bit requant shift;
- WAIT, QUERY, FENCE, and ACK;
- L1, TBU, MIF, AXI, CRG, LSC, WDT, and complete single-core tests.

The synced AXI TVIP environment also submits an inline Vector task through
the fixed-address AXI Slave FIFO and confirms that it creates no system-memory
read. The command-FIFO and complete-core UVM tests both finish with zero UVM
warnings, errors, or fatal reports.
