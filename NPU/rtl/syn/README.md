# NPU 单核综合检查

当前 FPGA 目标使用 Vivado 2024.2：

- 器件：`xc7a200tfbg484-3`
- 目标频率：100 MHz
- 时钟周期：10.000 ns
- 入口目录：`vivado_100mhz/`

运行方式：

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make clean
make syn
```

该流程依次执行综合、布局和布线，并生成资源报告、时序摘要和详细 setup
路径。最终结果以 `vivado_100mhz/build/summary.txt` 与
`vivado_100mhz/build/critical_paths_post_route.rpt` 为准。

## DC 参考流程

本目录原有的 `run_dc.tcl`、`filelist.f`、`npu_l1buf_timing_wrapper.sv` 和
`npu_single_core_400mhz.sdc` 用于标准单元库下的逻辑评估。该流程使用
FreePDK45，并把 L1 SRAM 作为外部存储宏处理，因此不能代替当前 Artix-7
器件上的 Vivado 结果。

如需复查 DC 数据，可先把文件复制到独立综合目录，再运行 DC：

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn"
make sync
cd /home/yusen/opt/xinyuan/syn_env/npu
make syn
```

运行任何流程前都应执行相应目录的 `make clean`，避免读取旧报告。
