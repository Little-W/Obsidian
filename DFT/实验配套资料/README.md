---
title: DFT 实验配套资料
type: lab-guide
tags:
  - DFT
  - ISCAS89
  - LBIST
  - Synopsys
updated: 2026-08-12
---

# DFT 实验配套资料

本目录保存与 DFTC Lab 3 至 Lab 9 相配合的开源设计。资料分为两类：小型时序基准电路用于快速检查脚本；带扫描端口和约束文件的 Logic BIST（逻辑内建自测试，Logic Built-In Self-Test）工程用于阅读多扫描链和多时钟设计。

商业工具的运行入口与命令说明见 [[商业工具实验准备]]；术语参照 [[术语与翻译规范]]。

## 已下载的项目

| 目录 | 仓库地址 | 提交编号 | 许可证 | 适用内容 |
| --- | --- | --- | --- | --- |
| `hdl-benchmarks/` | [ispras/hdl-benchmarks](https://github.com/ispras/hdl-benchmarks) | `10c3fb5` | Apache-2.0 | 已按稀疏检出方式保留 `iscas85/` 与 `iscas89/`。其中 ISCAS89（International Symposium on Circuits and Systems 1989）是时序电路基准集。 |
| `logic_bist/` | [dineshannayya/logic_bist](https://github.com/dineshannayya/logic_bist) | `2fdf66c` | Apache-2.0 | 含 SystemVerilog 设计、八条扫描链端口、扫描单元替换脚本、扫描连接脚本、SDC 约束和验证用例。 |

> [!note] 使用范围
> `logic_bist/openlane/scripts/` 中的 Tcl 命令由 OpenROAD/OpenLane 使用，不能直接交给 `dc_shell` 执行。它们适合用来阅读扫描单元替换和多链连接的结构；在 Synopsys DFT Compiler 中应使用 `set_dft_signal`、`preview_dft`、`insert_dft`、`report_scan_path` 等命令完成相应工作。

## 按 Lab 选择资料

| Lab | 目标 | 建议阅读或使用的文件 | 使用提示 |
| --- | --- | --- | --- |
| Lab 3 | 创建测试协议 | `hdl-benchmarks/iscas89/verilog/s27.v` | `s27` 只有一个时钟和 3 个 D 触发器，适合熟悉 `ScanClock` 定义与 `create_test_protocol`。该基准没有复位、测试模式、扫描使能或扫描端口；需要根据实验端口要求包一层顶层模块后再运行 DFTC。 |
| Lab 4 | DFT DRC 与 ATPG 覆盖率 | `s27.v`；`logic_bist/verilog/rtl/lbist/src/lbist_core.sv` | 先对 `s27` 做最小 DRC 检查，再阅读 `lbist_core.sv` 的扫描复位、扫描时钟使能和 `scan_en` 控制。 |
| Lab 5 | 图形化查看与调试 | `logic_bist/verilog/rtl/lbist/src/lbist_top.sv`；`logic_bist/verilog/rtl/lbist/src/lbist_core.sv` | 两级模块层次清晰，适合在 Design Vision 中检查端口、实例和时钟控制。 |
| Lab 6 | 定位和修复 DFT DRC 违规 | `logic_bist/verilog/rtl/lib/reset_sync.sv`；`logic_bist/sta/sdc/scan.sdc` | 对照复位同步模块和多时钟 SDC（Synopsys Design Constraints）文件，分析时钟、复位与异步时钟组的约束。不要把工程中的 OpenLane 专用命令复制到 DFTC 脚本。 |
| Lab 7 | 自顶向下扫描插入 | `logic_bist/openlane/scripts/scan_swap.tcl`；`logic_bist/openlane/scripts/scan_connect.tcl`；`logic_bist/openlane/wb_interconnect/config.tcl` | 依次阅读“普通触发器替换为扫描单元”“按 8 条扫描链轮流接入”的过程；随后用 DFTC 的 `preview_dft` 和 `insert_dft` 对自己的顶层设计完成扫描插入。 |
| Lab 8 | 扫描设计交接 | `logic_bist/openlane/scripts/scan_connect.tcl`；`logic_bist/openlane/wb_interconnect/pin_order.cfg` | 观察 `scan_si[7:0]`、`scan_so[7:0]` 和 `scan_en` 的端口安排。DFTC 侧导出测试协议、SCANDEF 和扫描网表后，核对端口名、链数量与扫描输出。 |
| Lab 9 | 运行时间、容量与链平衡 | `logic_bist/openlane/wb_interconnect/config.tcl`；`logic_bist/openlane/scripts/scan_connect.tcl`；`logic_bist/sta/sdc/scan.sdc` | 工程设定 `SCAN_TOTAL_CHAINS=8`，连接脚本会计算每条链的深度。可修改 DFTC 的扫描链数，比较扫描链长度、插入时间和测试移位时间。 |

## 建议的起步顺序

1. 先阅读 `hdl-benchmarks/iscas89/verilog/s27.v`，确认顶层为 `s27`，时钟端口为 `CK`，输出端口为 `G17`。
2. 为 Lab 3 的脚本建立一个教学顶层模块：保留 `CK`、`G0`、`G1`、`G2`、`G3`、`G17`，并补充实验所需的 `test_mode`、`scan_enable`、`scan_in`、`scan_out` 与复位端口。端口名须与 `set_dft_signal` 中的名称一致。
3. 在配置好 `target_library` 和 `link_library` 后，先运行 `create_test_protocol`、`dft_drc` 与 `preview_dft`，确认问题来源，再执行 `insert_dft`。
4. 阅读 Logic BIST 工程的 `scan_swap.tcl` 与 `scan_connect.tcl`，理解多扫描链的结构，再在自己的 DFTC 工程中设置扫描链数量和最大长度。
5. 依照 Lab 8 导出测试协议、SCANDEF、扫描网表与报告；随后按 Lab 9 比较不同扫描链数量的结果。

## 文件定位速查

```text
实验配套资料/
├── hdl-benchmarks/
│   ├── iscas85/                 # 组合逻辑基准电路
│   └── iscas89/
│       ├── bench/               # .bench 格式
│       └── verilog/             # 时序电路 Verilog，如 s27.v、s298.v、s344.v
└── logic_bist/
    ├── verilog/rtl/lbist/src/   # LBIST 控制器
    ├── verilog/rtl/lib/         # 复位、时钟和通用模块
    ├── openlane/scripts/        # 扫描单元替换与扫描链连接脚本
    ├── openlane/wb_interconnect/config.tcl
    └── sta/sdc/scan.sdc         # 多时钟扫描约束
```

## 本地状态

- 两个项目均为浅层 Git 检出，当前均未改动。
- `hdl-benchmarks/` 仅保留 ISCAS85 和 ISCAS89 子目录，以控制磁盘占用；如需其他基准集，可在该仓库中执行 `git sparse-checkout add <目录名>`。
- 本机已有通过穿通脚本调用的 Synopsys 工具。工艺库设置应使用容器中现有的库文件，不需要为本资料目录另行下载完整开源 PDK。
