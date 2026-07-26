# NPU control and memory RTL

This directory set contains the synthesizable control and storage foundation for
one NPU core. All local data transfers are 64 bits wide. Every local reset input
is named `reset_n` and is active low.

## Source files

| File | Function |
| --- | --- |
| `../npu_rtl_pkg.sv` | Shared widths, status values, dtype values, engine values and opcode checks |
| `npu_cmd_frontend.sv` | Reassembles two 64-bit beats into CMD128, checks the header and holds accepted commands in an eight-entry FIFO |
| `npu_descriptor_fetch.sv` | Reads one Descriptor at a time with 64-bit MIF requests, checks the common prefix and returns a 2048-bit packed copy |
| `npu_task_scheduler.sv` | Holds the task table and Event Table, starts Descriptor reads, checks dependencies and sends work to four engines |
| `npu_lsc.sv` | Implements the 64-bit local control registers, first-fault state, interrupt state, reset drain control and exported configuration |
| `npu_crg.sv` | Synchronizes reset release, qualifies local clock enables and acknowledges an idle DVFS request |
| `npu_wdt.sv` | Detects a lack of observable forward progress and holds the timeout request until software kicks or disables it |
| `../memory/npu_l1buf.sv` | Arbitrates multiple single-beat clients and stores data in banked 64-bit SRAM arrays |
| `../memory/npu_tbu.sv` | Performs identity translation after stream, access permission, alignment and address range checks |
| `../memory/npu_axi_mif_master.sv` | Converts one internal 64-bit request into a protocol-complete single-beat AXI4 read or write |

## Command and task flow

`npu_cmd_frontend` accepts CMD low word with `first=1,last=0`, followed by the
high word with `first=0,last=1`. It checks version 1, 64-byte Descriptor
alignment, event references, reserved header bits, engine/opcode agreement and
duplicate command IDs. A response reports `command_id`, an 8-bit status and the
remaining CFE FIFO entries. If the high word does not arrive within
`WAIT_HIGH_TIMEOUT` cycles, whose default is 32, the partial command is
discarded and the response status is `TIMEOUT`. A partial command is never
visible on the scheduler output.

The CFE sends a complete `ts_cmd_o[127:0]` item to
`npu_task_scheduler`. The scheduler contains 16 task entries by default and 255
event entries. It preserves submission order for `ORDERED` and
`GLOBAL_FENCE`, but independent engines can run at the same time. DMA, Matrix,
Vector and Complex each have this interface:

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

There can be one active task per engine. Task output remains stable while
`task_valid=1` and `task_ready=0`. A task entry remains present after its
terminal notification. Software first queries it and then completes the
`task_ack_valid && task_ack_ready` handshake to release the entry.

### Scheduler control requests

The scheduler also accepts one WAIT, QUERY or FENCE request at a time through
`axi_ctl_*`. The operation values on this internal interface are `WAIT=1`,
`QUERY=2` and `FENCE=3`.

| Operation | `arg0` | `arg1` | Result |
| --- | --- | --- | --- |
| WAIT | Event reference in bits `[11:0]` | Maximum wait cycles in bits `[31:0]` | A terminal event returns state in `[2:0]` and producer command ID in `[19:8]`; an invalid reference, missing event or timeout returns the corresponding 8-bit status in `[7:0]` |
| QUERY | Command ID in bits `[11:0]` | Selector in bits `[2:0]` | Selector-specific 64-bit data |
| FENCE | Engine mask in bits `[3:0]`: DMA, Matrix, Vector, Complex | Maximum wait cycles in bits `[31:0]` | The earliest failed target status, `SUCCESS`, or `TIMEOUT` in `[7:0]` |

FENCE captures the selected tasks when its request is accepted. Tasks submitted
later are not added to that request. WAIT and FENCE give a terminal target
priority over a timeout on the same cycle. `axi_ctl_cancel_i` cancels an active
WAIT or FENCE without changing any task or event and without generating a
scheduler response; the AXI control-window block records the cancelled software
operation.

QUERY selectors are:

| Selector | Result |
| ---: | --- |
| 0 | Task state `[3:0]`, status `[11:4]`, command ID `[23:12]`; software states are free, waiting, running and terminal |
| 1 | User tag `[31:0]` and signal event `[43:32]` |
| 2 | Fault address `[47:0]` |
| 3 | Engine progress `[63:0]` |
| 4 | ACK result: `0=ACKED`, `1=NOT_TERMINAL`, `2=NOT_FOUND` |
| 5 | Error information `[31:0]` |
| 6 | Completion flags `[15:0]` |
| 7 | Reserved and returns `BAD_DESC` |

ACK releases a terminal task only after its completion notification has been
accepted. The direct `task_query_*`, `task_ack_*` and `event_query_*` ports
provide the same stored information to local integration and debug logic.

## Descriptor representation and dtype rules

Descriptor byte zero occupies `desc_flat[7:0]`; later bytes follow in increasing
bit positions. The maximum representation is 256 bytes. Control uses 64 bytes,
Vector uses 192 bytes, and DMA, Matrix and Complex use 256 bytes.

All ordinary dtype fields use exactly this two-bit definition:

| Code | Type |
| ---: | --- |
| 0 | INT4 |
| 1 | INT8 |
| 2 | INT32 |
| 3 | reserved; Descriptor fetch returns `BAD_DESC` |

The accumulator field has its own definition and accepts only zero, denoting an
INT32 accumulator. This RTL has no INT16 model-tensor mode.

## L1 single-beat interface

`npu_l1buf` exposes packed copies of one request/response interface:

```text
req_valid, req_ready, req_write
req_addr[19:0], req_wdata[63:0], req_wstrb[7:0]
rsp_valid, rsp_ready, rsp_rdata[63:0], rsp_status[2:0]
```

The default SRAM is 1 MiB in 16 banks. The current arbiter accepts one client
request per cycle and rotates its starting client after every accepted request.
Reads and writes return through a per-client response holding register, so
response backpressure from one client does not consume another client's
response slot. SRAM contents are intentionally not reset.

## MIF and AXI4 behavior

The internal MIF request is one aligned 64-bit access with a 48-bit virtual
address. MIF first sends it to `npu_tbu`. A permitted access receives the same
48-bit address. With the default `AXI_ADDR_W=40`, any nonzero translated bit
above bit 39 returns an address error and creates no AXI request.

The AXI master uses:

- one outstanding request;
- `AxLEN=0`, `AxSIZE=3`, `AxBURST=INCR`;
- independent AW and W handshakes;
- a held B/R ready state until the response arrives;
- ID, response and `RLAST` checks;
- stable request payload while any AXI valid signal is waiting.

Read data and write completion use the same internal response channel. AXI
`SLVERR`, `DECERR`, an address error and a protocol error have distinct 3-bit
memory status values.

## LSC registers implemented by this RTL

The base table follows the main specification from `0x0000` through `0x00f0`.
It includes identification, fixed capabilities, start/stop, status, five
48-bit model region bases, AXI address range, TBU IDs, interrupt state and mask,
first fault, parameter-area control and the host L1 access enable.

Three implementation registers are also provided:

| Offset | Function |
| ---: | --- |
| `0x02c0` | WDT enable and kick |
| `0x02c8` | WDT timeout cycles |
| `0x02d0` | Eight local module clock enables |

The register port returns one response for each accepted request and holds it
until `reg_rsp_ready_i=1`. Misaligned accesses, writes to read-only registers
and invalid field values return `SLVERR`.

## Initial implementation limits

- Descriptor CRC is not implemented. A command that enables it receives
  `BAD_DESC`.
- MIF and Descriptor Fetch each support one request at a time and issue only
  single-beat AXI4 transfers.
- TBU uses one configurable identity rule, not a page-table walker.
- L1 storage has banked arrays, but this first arbiter grants at most one SRAM
  access per cycle across all clients.
- ECC status values are defined, but the SRAM array does not yet store or check
  ECC bits.
- Control tasks use the common Descriptor fetch flow. Event signal and join use
  CMD dependencies; event rearm increments the selected event generation after
  the prior task reaches its terminal state.
- Event rearm is a minimal first implementation. It takes the selected event ID
  from Descriptor byte 32, clears that entry and increments its generation. It
  does not yet count registered task and host waiters.
- The LSC exports parameter-area base, limit and lock state. The current packed
  L1 interface does not carry a client permission bit, so `npu_l1buf` does not
  yet enforce the parameter-area write protection itself.
- AXI cache, protection and QoS values are fixed in this first MIF instance.

## Verification

Each module can be checked with Verilator by placing the package first:

```sh
verilator --lint-only --Wall --top-module npu_cmd_frontend \
  NPU/rtl/npu_rtl_pkg.sv NPU/rtl/control/npu_cmd_frontend.sv

verilator --lint-only --Wall --top-module npu_task_scheduler \
  NPU/rtl/npu_rtl_pkg.sv NPU/rtl/control/npu_task_scheduler.sv

verilator --lint-only --Wall --top-module npu_l1buf \
  NPU/rtl/npu_rtl_pkg.sv NPU/rtl/memory/npu_l1buf.sv

verilator --lint-only --Wall --top-module npu_axi_mif_master \
  NPU/rtl/npu_rtl_pkg.sv NPU/rtl/memory/npu_axi_mif_master.sv
```

The following functional smoke tests were run with Verilator 5.040 and passed:

```sh
CCACHE_DISABLE=1 verilator --binary --timing --assert --Wall --Wno-fatal \
  --top-module tb_cmd_dfu_smoke \
  NPU/rtl/npu_rtl_pkg.sv \
  NPU/rtl/control/npu_cmd_frontend.sv \
  NPU/rtl/control/npu_descriptor_fetch.sv \
  NPU/rtl/control/tb_cmd_dfu_smoke.sv \
  -Mdir /tmp/npu_tb_cmd_dfu --build-jobs 4
/tmp/npu_tb_cmd_dfu/Vtb_cmd_dfu_smoke

CCACHE_DISABLE=1 verilator --binary --timing --assert --Wall --Wno-fatal \
  --top-module tb_scheduler_ctl_smoke \
  NPU/rtl/npu_rtl_pkg.sv \
  NPU/rtl/control/npu_task_scheduler.sv \
  NPU/rtl/control/tb_scheduler_ctl_smoke.sv \
  -Mdir /tmp/npu_tb_scheduler_ctl --build-jobs 4
/tmp/npu_tb_scheduler_ctl/Vtb_scheduler_ctl_smoke

CCACHE_DISABLE=1 verilator --binary --timing --assert --Wall --Wno-fatal \
  --top-module tb_lsc_crg_wdt_smoke \
  NPU/rtl/npu_rtl_pkg.sv \
  NPU/rtl/control/npu_lsc.sv \
  NPU/rtl/control/npu_crg.sv \
  NPU/rtl/control/npu_wdt.sv \
  NPU/rtl/control/tb_lsc_crg_wdt_smoke.sv \
  -Mdir /tmp/npu_tb_lsc_crg_wdt --build-jobs 4
/tmp/npu_tb_lsc_crg_wdt/Vtb_lsc_crg_wdt_smoke

CCACHE_DISABLE=1 verilator --binary --timing --assert --Wall --Wno-fatal \
  --top-module tb_memory_smoke \
  NPU/rtl/npu_rtl_pkg.sv \
  NPU/rtl/memory/npu_l1buf.sv \
  NPU/rtl/memory/npu_tbu.sv \
  NPU/rtl/memory/npu_axi_mif_master.sv \
  NPU/rtl/memory/tb_memory_smoke.sv \
  -Mdir /tmp/npu_tb_memory --build-jobs 4
/tmp/npu_tb_memory/Vtb_memory_smoke
```

The tests cover atomic CMD128 assembly, the 32-cycle partial-command timeout,
Descriptor prefix rejection for dtype code 3, concurrent DMA and Matrix issue,
WAIT/QUERY/FENCE/ACK behavior, completion progress, LSC register and first-fault
state, controlled reset, CRG reset release and DVFS acknowledgement, WDT
timeout/clear, L1 byte strobes, TBU permission and range errors, and AXI read,
write and DECERR responses.
