# NPU single-core Synopsys DC flow

This directory holds the 400 MHz synthesis flow for `npu_single_core_top`.
It is copied into an independent `npu` directory under the existing synthesis
environment, so the `matrix_processor` project and its reports are untouched.

## L1 treatment

The functional RTL contains a 1 MiB behavioral array. The DC file list replaces
that array with `npu_l1buf_timing_wrapper.sv`. The wrapper retains arbitration,
bank selection, request/response registers, and sixteen SRAM instances. Each
instance represents an 8192 x 64 bank, for a total of 8,388,608 storage bits.

The SRAM instances are black boxes because the environment does not contain a
characterized SRAM `.db`. Standard-cell area reports therefore exclude SRAM
physical area, and timing reports exclude SRAM internal access time. Before
physical implementation, replace each placeholder with the selected memory
compiler view and rerun synthesis and static timing analysis.

## Run

From the tracked flow directory:

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn"
make sync
cd /home/yusen/opt/xinyuan/syn_env/npu
make syn
```

The fixed report directory is:

```text
/home/yusen/opt/xinyuan/syn_env/npu/reports/baseline_400mhz
```

The timing target is 2.500 ns. Setup uncertainty is 0.150 ns and top-level
input/output delay is 0.250 ns. `summary.txt` records the worst setup slack,
startpoint, and endpoint. Full paths are in
`npu_single_core_top_timing_max.rpt`; QoR and hierarchical area are in the
matching report files.

Use `make clean` in the copied `npu` directory before a clean rerun.
