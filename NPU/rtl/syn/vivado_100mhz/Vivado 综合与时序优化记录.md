# Vivado 综合与时序优化记录

## 1. 验证目标与固定配置

本文记录 NPU 单核 RTL 在 Xilinx Artix-7 FPGA 上的综合、布局和布线结果，并说明各次 RTL 调整针对的数据路径。综合后的报告用于快速检查 RTL 结构；100 MHz 是否满足要求，以布局和布线后的报告为准。

| 项目 | 配置 |
|---|---|
| 顶层模块 | `npu_single_core_top` |
| FPGA 器件 | `xc7a200tfbg484-3` |
| Vivado | `2024.2.1` |
| 目标时钟周期 | `10.000 ns` |
| 目标频率 | `100 MHz` |
| 时钟不确定度 | `0.200 ns` |
| 输入延迟 | `1.000 ns` |
| 输出延迟 | `1.000 ns` |
| 综合方式 | Out-of-Context |
| Vivado 进程数 | `1` |

`core_clk_i` 与 `noc_clk_i` 均使用 `10.000 ns` 周期。两个时钟属于异步时钟组，工具不检查两个时钟域之间的同步时序。当前使用 Out-of-Context 方式，最终接入 SoC 顶层后还需要使用实际时钟资源、芯片引脚位置和外围接口约束再次检查。

## 2. 运行命令与报告目录

### 2.1 综合快速检查

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make synth-only \
  BUILD_DIR=build_pipeline_round3_synth \
  JOBS=1 \
  PART=xc7a200tfbg484-3 \
  PERIOD_NS=10.000
```

round2 与 round3 已保存相同类型的报告。round3 的主要文件如下：

- `build_pipeline_round3_synth/summary_post_synth.txt`
- `build_pipeline_round3_synth/utilization_post_synth.rpt`
- `build_pipeline_round3_synth/utilization_hierarchical_post_synth.rpt`
- `build_pipeline_round3_synth/timing_summary_post_synth.rpt`
- `build_pipeline_round3_synth/timing_paths_setup_post_synth_dedup.rpt`
- `build_pipeline_round3_synth/memory_primitives_post_synth.rpt`
- `build_pipeline_round3_synth/hierarchy_timing/`
- `build_pipeline_round3_synth/post_synth.dcp`

### 2.2 完整布局和布线

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make syn \
  BUILD_DIR=<FINAL_BUILD_DIR> \
  JOBS=1 \
  PART=xc7a200tfbg484-3 \
  PERIOD_NS=10.000
```

完整运行需要检查 `summary_post_route.txt`、`timing_post_route.rpt`、`utilization_post_route.rpt`、`critical_paths_post_route.rpt`、`methodology_post_route.rpt`、`route_status_post_route.rpt` 和 `post_route.dcp`。本文第 7 节为下一次综合和最终完整运行保留了明确标记，数字产生前不填写估计值。

## 3. 结构调整前的完整基线

基线来自 `NPU/rtl/syn/vivado_100mhz/build/`。该次运行完成 Out-of-Context 综合、布局、物理优化和布线，`108272` 条需要布线的网络均已完成，布线错误数为 0。

### 3.1 时序结果

| 指标 | 综合后 | 布线后 |
|---|---:|---:|
| WNS | `-58.981 ns` | `-78.625 ns` |
| TNS | `-601676.673 ns` | `-1044141.190 ns` |
| setup 失败终点数 | `19370` | `49140` |
| WHS | `-0.021 ns` | `+0.009 ns` |
| THS | `-2.256 ns` | `0.000 ns` |
| hold 失败终点数 | `144` | `0` |
| 最差 setup 数据路径延迟 | `68.244 ns` | `88.194 ns` |
| 最差 setup 逻辑级数 | `212` | `205` |

综合后的最差 setup 路径从 `u_task_scheduler/task_submit_seq_q_reg[0][1]/C` 到 `u_task_scheduler/u_task_desc_decode/desc_flat_o0/B[0]`。布线后的最差 setup 路径从 `u_task_scheduler/task_submit_seq_q_reg[0][19]/C` 到 `u_task_scheduler/decode_pending_cmd_q_reg[123]_rep/D`。

基线布线后 WNS 为 `-78.625 ns`，不满足 100 MHz。最差路径的逻辑延迟为 `23.718 ns`，布线延迟为 `64.476 ns`，布线部分约占 `73.1%`。路径经过 Scheduler 的 16 槽扫描、64-bit 提交序号比较和逐项优先选择，并继续驱动命令及多个基地址寄存器。

### 3.2 资源使用

| 层级 | Slice LUTs | Slice Registers | RAMB36 | RAMB18 | DSP48E1 |
|---|---:|---:|---:|---:|---:|
| `npu_single_core_top` | `96374` | `30306` | `256` | `0` | `134` |
| `u_task_scheduler` | `60390` | `18111` | `0` | `0` | `10` |
| `u_axi_slave_frontend` | `11645` | `2740` | `0` | `0` | `0` |
| `u_complex_engine` | `9010` | `2797` | `0` | `0` | `33` |
| `u_matrix_engine` | `4573` | `864` | `0` | `0` | `49` |
| `u_dma_engine` | `3448` | `2535` | `0` | `0` | `0` |
| `u_vector_engine` | `2811` | `835` | `0` | `0` | `42` |
| `u_l1buf` | `2527` | `346` | `256` | `0` | `0` |
| `u_cmd_frontend` | `1551` | `1163` | `0` | `0` | `0` |

器件总体使用率为 Slice LUT `72.03%`、Slice Register `11.33%`、Block RAM Tile `70.14%`、DSP `18.11%`。Scheduler 占基线全部 Slice LUT 的 `62.66%`，也是基线内部最差 setup 路径所在模块。

### 3.3 L1 RAM 原语检查

| 检查项 | 结果 |
|---|---:|
| 全设计 RAMB36E1 | `256` |
| 全设计 RAMB18E1 | `0` |
| 全设计 LUTRAM | `0` |
| L1 RAMB36E1 | `256` |
| L1 RAMB18E1 | `0` |
| L1 LUTRAM | `0` |
| L1 `memory_q` 名称下的触发器 | `0` |

L1 的 16 个 bank 各使用 16 个 RAMB36E1，大容量 L1 存储由 Block RAM 实现。

## 4. 已实施的 RTL 调整

### 4.1 DiP 矩阵计算路径

- Matrix Engine 为适合 DiP 的矩阵任务选择 DiP 脉动阵列，其他任务仍可进入标量执行单元。
- `dip_simd_dot_product` 将基础乘法、分组重组和加法树分到连续寄存阶段，避免乘法和宽加法全部落在一个周期。
- 16 个 4×4 基础乘法器按照数据类型复用：INT16 每次形成 1 个乘积，INT8 每次形成 4 个乘积，INT4 每次形成 16 个乘积。
- PE 累加器按照数据类型分段：INT16 使用 64-bit 累加，INT8 使用两组 32-bit 累加，INT4 使用四组 16-bit 累加。这样不会让某个分段的进位进入相邻分段。
- DiP 结果暂存数组 `accum_rows_q` 使用 `ram_style = "block"`，综合结果为 14 个 RAMB36E1 和 1 个 RAMB18E1，未把该大容量数组展开为大量触发器。
- 分段累加器改为直接表达 64-bit、两组 32-bit 或四组 16-bit 加法，便于综合工具使用 FPGA 的进位资源。

### 4.2 Matrix 标量执行单元

- 乘法和部分和更新分为 `ST_MAC_MUL` 与 `ST_MAC_ACC`，降低单周期内的组合层数。
- 输出后处理依次执行乘法、绝对值、移位、舍入增量、符号恢复、64-bit 缩小、零点相加和数据类型裁剪，128-bit 乘法结果不再直接穿过全部后处理逻辑。
- 检查阶段预先保存 B 矩阵每行的分块数量 `b_n_tiles_q`。
- 发起 A 数据请求时计算并保存完整的 B 数据地址 `b_addr_q`；B 请求、跨 64-bit 数据字检查、故障地址和元素提取均使用该寄存地址。这样把分块地址乘加与 L1 请求分到不同周期。
- 矩阵测试增加 `M=1、N=9、K=2` 的分块 B 输入，覆盖 N 方向跨两个分块的地址计算。

### 4.3 Vector 执行单元

- 快速逐元素乘法复用 16 个 4×4 基础乘法器，并使用两级加法树重组 INT8 和 INT16 结果。
- 写请求阶段保存本次写入后的动作、进度增量、当前行元素数量和末行状态。
- 写响应阶段只执行已保存的动作：继续写一对元素、转到下一个 64-bit 输入数据字、转到下一行或结束任务。
- 地址更新和末行判断不再与 L1 写响应后的全部控制选择串在同一个周期。

### 4.4 Scheduler

- Scheduler 使用共享扫描器检查任务槽，避免为多个执行单元重复展开相同的槽选择网络。
- Control 指令先保存候选槽和提交序号，下一周期重新检查任务状态、执行单元类型、提交序号及顺序约束后再执行。扫描结果不再直接驱动 Event 和任务状态的大量寄存器。
- 指令接收增加一级暂存。前端握手时保存指令、基地址、已解析 Event、静态检查结果、前序任务位图和目标槽，下一周期再写任务表。
- 暂存有效期间停止接收下一条指令，并把该条指令计入任务占用数；命令编号查询也会检查暂存内容。
- AXI 控制访问在指令暂存期间等待，避免 FENCE 与任务表写入在相邻周期产生观察次序问题。
- 当前结构中，前端接收与任务表写入相隔一个周期。指令输入由两个 64-bit 数据拍组成，而执行单元任务通常远长于两个周期，因此该级寄存对当前任务流吞吐影响较小。

### 4.5 Complex Engine

- ADD、SUB 和 MUL 共用 `npu_fp32_alu_seq`，请求和结果均使用 `valid/ready` 握手。
- Sigmoid、Tanh、GELU、SiLU、EXP、倒数和平方根倒数由 `npu_complex_math_seq` 多周期执行，中间结果保存在寄存器中。
- Complex Engine 的 FP32 到整数输出处理分为 `ST_F2I_ROUND`、`ST_F2I_MAG`、`ST_F2I_SIGN`、`ST_F2I_OFFSET` 和 `ST_F2I_FINISH`。
- EXP 的范围计算进一步分为 `ST_EXP_RANGE_ROUND`、`ST_EXP_RANGE_SHIFT`、`ST_EXP_RANGE_INCREMENT`、`ST_EXP_RANGE_COMMIT` 和 `ST_EXP_RANGE_FROM_INT`，避免可变移位、舍入和整数转 FP32 在同一个周期连续执行。
- EXP 输入已经限制在 `[-16,16]`，内部整数幅值按可达到的数值范围保存，不再保留不必要的宽比较逻辑。

### 4.6 L1 Buffer

- 16 个 bank 继续使用 Block RAM，每个 bank 保存 64-bit 数据字。
- 每个客户端分别生成 `grant_fire_oh`、`read_return_oh`、地址对齐错误和地址范围错误。
- 每个客户端的响应寄存器由对应的静态 `always_ff` 写入；公共控制时序只更新轮询位置和待读请求信息。
- 读取返回、写响应和错误响应仍保持原有优先关系和周期数，同时去除“一个客户端的请求可能驱动另一个客户端响应寄存器”的无效组合路径。

## 5. `build_pipeline_round2_synth` 综合结果

本节数字来自已经保存的 `build_pipeline_round2_synth` 报告，器件、周期和 Vivado 配置与基线相同。第 4 节中在该报告产生后继续完成的寄存分级，需要由后续综合和完整布线结果评价，不能用本节数字代替。

### 5.1 顶层时序与资源

| 指标 | 综合后结果 |
|---|---:|
| WNS | `-4.037 ns` |
| TNS | `-24892.776 ns` |
| setup 失败终点数 | `14499` |
| WHS | `-0.021 ns` |
| THS | `-2.967 ns` |
| hold 失败终点数 | `199` |
| 最差 setup 数据路径延迟 | `13.796 ns` |
| 最差 setup 逻辑级数 | `31` |
| Slice LUTs | `97218`，`72.23%` |
| Slice Registers | `45760`，`17.00%` |
| RAMB36E1 | `270` |
| RAMB18E1 | `1` |
| Block RAM Tile | `270.5`，`74.11%` |
| DSP48E1 | `133`，`17.97%` |

WNS 从基线综合后的 `-58.981 ns` 改善到 `-4.037 ns`。该结果仍不满足 100 MHz，而且只是综合后结果，不能代替布局和布线后的结论。

### 5.2 层级资源

| 层级 | LUTs | FFs | RAMB36 | RAMB18 | DSP |
|---|---:|---:|---:|---:|---:|
| `npu_single_core_top` | `97218` | `45760` | `270` | `1` | `133` |
| `u_task_scheduler` | `38915` | `19128` | `0` | `0` | `10` |
| `u_matrix_engine` | `26956` | `13335` | `14` | `1` | `49` |
| `u_axi_slave_frontend` | `11684` | `2741` | `0` | `0` | `0` |
| `u_complex_engine` | `8070` | `3206` | `0` | `0` | `32` |
| `u_vector_engine` | `5015` | `2401` | `0` | `0` | `42` |
| `u_dma_engine` | `3494` | `2532` | `0` | `0` | `0` |
| `u_l1buf` | `1769` | `341` | `256` | `0` | `0` |
| `u_cmd_frontend` | `886` | `1164` | `0` | `0` | `0` |

L1 仍使用 256 个 RAMB36E1，L1 内没有 RAMB18E1、LUTRAM 或 `memory_q` 数据触发器。新增的 14 个 RAMB36E1 和 1 个 RAMB18E1 位于 Matrix Engine 的 DiP 结果暂存数组。顶层 DSP 报告值为 `133`。

### 5.3 各层级最差 setup 路径

下表来自 `hierarchy_timing/` 中保存的综合后报告。报告以指定层级内的寄存器作为起点，因此终点可能位于 L1 或 Scheduler 等其他层级。

| 起点层级 | Slack | 数据路径延迟 | 逻辑级数 | 路径摘要 |
|---|---:|---:|---:|---|
| Matrix | `-4.037 ns` | `13.796 ns` | `31` | DiP 乘积贡献寄存器到同一 PE 的 64-bit 部分和寄存器 |
| Vector | `-2.740 ns` | `12.121 ns` | `14` | Vector 列地址计算经过 DSP 与地址选择后到 L1 Block RAM 使能 |
| Command Frontend | `-2.671 ns` | `12.430 ns` | `25` | 命令 FIFO 数据经过指令检查和 Event 选择后到 Scheduler Event 状态 |
| Complex | `-1.960 ns` | `11.719 ns` | `27` | EXP 舍入整数寄存器经过宽移位和选择后到工作寄存器 |
| Scheduler | `-0.883 ns` | `10.642 ns` | `21` | Event 代次寄存器经过 Event 检查和选择后到 Event 状态 |
| AXI Slave Frontend | `+1.458 ns` | `7.923 ns` | `11` | 读状态经过 L1 仲裁选择后到 Block RAM 使能 |
| DMA | `+1.492 ns` | `7.889 ns` | `9` | DMA 状态经过 L1 仲裁选择后到 Block RAM 使能 |
| L1 | `+1.927 ns` | `7.454 ns` | `9` | 待读客户端寄存器经过 bank 选择后到 Block RAM 使能 |

顶层最差路径是 DiP PE 内的 64-bit 部分和加法。下一组路径是 Matrix 标量执行单元 `k_q` 到 L1 Block RAM 使能，Slack 为 `-2.890 ns`、数据路径延迟为 `12.272 ns`、逻辑级数为 `15`。第 4 节记录的分段加法、B 地址寄存、Vector 写动作寄存、指令接收暂存、Control 执行暂存、EXP 多级舍入和 L1 静态客户端响应，分别针对这些路径继续拆分。

## 6. `build_pipeline_round3_synth` 综合结果

round3 在相同器件、时钟周期、Vivado 版本和进程数下运行。本节所有数字均来自 `build_pipeline_round3_synth` 内保存的报告。

### 6.1 顶层时序与资源

| 指标 | 综合后结果 |
|---|---:|
| WNS | `-2.157 ns` |
| TNS | `-7181.155 ns` |
| setup 失败终点数 | `5845` |
| WHS | `-0.021 ns` |
| THS | `-2.967 ns` |
| hold 失败终点数 | `199` |
| 最差 setup 数据路径延迟 | `11.538 ns` |
| 最差 setup 逻辑级数 | `14` |
| Slice LUTs | `98733`，`73.35%` |
| Slice Registers | `46202`，`17.16%` |
| RAMB36E1 | `270` |
| RAMB18E1 | `1` |
| Block RAM Tile | `270.5`，`74.11%` |
| DSP48E1 | `133`，`17.97%` |

与 round2 相比，WNS 从 `-4.037 ns` 改善到 `-2.157 ns`，TNS 从 `-24892.776 ns` 降到 `-7181.155 ns`，setup 失败终点数从 `14499` 降到 `5845`。Slice LUT 增加 `1515`，Slice Register 增加 `442`；Block RAM 和 DSP 数量保持不变。round3 仍未满足 100 MHz。

### 6.2 各层级最差 setup 路径

| 起点层级 | Slack | 数据路径延迟 | 逻辑级数 | 路径摘要 |
|---|---:|---:|---:|---|
| Matrix | `-2.157 ns` | `11.538 ns` | `14` | Matrix 残差输入地址计算经过 DSP 和 L1 请求选择后到 Block RAM 使能 |
| Complex | `-1.558 ns` | `10.939 ns` | `13` | STAT 输出地址计算经过 DSP 和 L1 请求选择后到 Block RAM 使能 |
| Vector | `-0.167 ns` | `9.548 ns` | `21` | 快速路径目标地址寄存器经过地址增量和请求选择后到 Block RAM 使能 |
| Command Frontend | `+0.006 ns` | `9.406 ns` | `17` | 命令 FIFO 数据经过 Event 解析后到 `cmd_admit_signal_q` |
| Scheduler | `+0.770 ns` | `8.642 ns` | `15` | Event 代次寄存器经过 Event 解析后到 `cmd_admit_signal_q` |
| AXI Slave Frontend | `+1.766 ns` | `7.993 ns` | `14` | 控制参数寄存器经过控制读取选择后到 Scheduler 响应数据 |
| DMA | `+1.991 ns` | `7.591 ns` | `24` | DMA 操作码经过地址计算和错误选择后到故障地址寄存器使能 |
| L1 | `+2.378 ns` | `7.003 ns` | `9` | 轮询客户端寄存器经过 bank 选择后到 Block RAM 使能 |

round2 的 DiP PE 累加路径不再是顶层最差路径，Vector、Command Frontend、Scheduler、AXI Slave Frontend、DMA 和 L1 的层级最差 Slack 均得到改善。round3 的前三条剩余路径集中在 Matrix、Complex 和 Vector 的 L1 地址请求。

### 6.3 round3 报告产生后继续实施的调整

- Matrix 标量执行单元增加输出地址寄存阶段。`ST_START_OUTPUT` 保存输出、残差、bias、缩放参数地址及 INT4 半字节位置，`ST_OUTPUT_CHECK` 使用寄存值检查输出地址；每次乘法前由 `ST_ADDR_PREP` 保存 A 和 B 地址。
- Vector 快速路径增加 `ST_FAST_WRITE_PREP`。该状态保存写地址、64-bit 写数据和字节使能，后续 `ST_FAST_WRITE_REQ` 只使用寄存值发起 L1 写请求。
- Complex Engine 在每行开始时保存 STAT 输出地址。STAT 结果写入、跨 64-bit 数据字检查和故障地址均使用 `stat_dst_addr_q`，不再从行号和行步长组合计算后直接驱动 L1 请求。
- Scheduler 的 `cmd_admit_signal_q` 始终保存已经解析的 signal 引用。无效指令会直接成为结束状态的任务，也不会发布 Event，因此不需要使用整组静态检查结果再次选择 signal 寄存器输入。

这些调整尚未反映在 round3 数字中。下一次综合和最终布线结果必须从对应报告读取。

## 7. 后续综合与最终完整运行

以下标记只表示报告正在生成，不表示已经满足 100 MHz。

| 指标 | 后续综合 | 最终布线 |
|---|---:|---:|
| WNS | `【待后续综合报告】` | `【待最终完整运行】` |
| TNS | `【待后续综合报告】` | `【待最终完整运行】` |
| setup 失败终点数 | `【待后续综合报告】` | `【待最终完整运行】` |
| WHS | `【待后续综合报告】` | `【待最终完整运行】` |
| THS | `【待后续综合报告】` | `【待最终完整运行】` |
| LUTs | `【待后续综合报告】` | `【待最终完整运行】` |
| FFs | `【待后续综合报告】` | `【待最终完整运行】` |
| RAMB36E1 | `【待后续综合报告】` | `【待最终完整运行】` |
| RAMB18E1 | `【待后续综合报告】` | `【待最终完整运行】` |
| DSP48E1 | `【待后续综合报告】` | `【待最终完整运行】` |
| 最差路径起点 | `【待后续综合报告】` | `【待最终完整运行】` |
| 最差路径终点 | `【待后续综合报告】` | `【待最终完整运行】` |
| 最差路径逻辑级数 | `【待后续综合报告】` | `【待最终完整运行】` |
| 最差路径数据延迟 | `【待后续综合报告】` | `【待最终完整运行】` |

最终结论必须同时满足以下检查：完整布局和布线正常结束、路由状态没有错误、setup 与 hold 报告可读取、Block RAM 数量符合预期、功能回归通过。若布线后 WNS 仍小于 0，应继续依据布线后最差路径修改 RTL，不能用综合后 WNS 代替。

## 8. 功能回归

最近一次完整 `make test` 已通过，主要结果如下：

| 测试 | 结果 |
|---|---|
| 顶层 Verilator lint | PASS，无告警 |
| FP32 ADD/SUB/MUL 随机比对 | PASS，`6010` 项 |
| 复杂数学参考测试 | PASS，`87` 项 |
| Matrix、Vector、Complex、DMA、L1 与 Scheduler 模块测试 | PASS |
| 单核系统测试 | PASS，`commands=8` |
| 单核系统 AXI Master 访问 | `system_reads=8`，`system_writes=8` |
| 单核系统 L1 请求统计 | `matrix_l1=56`，`vector_l1=36` |
| Transformer 端到端测试 | `TB_TRANSFORMER_E2E_PASS` |
| Transformer 指令与批次 | `commands=41`，`batches=6` |
| Transformer AXI Master 访问 | `master_reads=1544`，`master_writes=8` |

Transformer 中间值和最终输出：

```text
score=[14,-5,-5,30]
probability=[4,0,0,4]
context=[2,-1,3,0,-2,4,1,3]
int8=[7,-8,13,-14,-3,4,1,5]
```

这些回归结果说明新增寄存阶段没有改变已覆盖任务的结果、错误状态和 AXI 访问次数。时序调整完成后仍需再次运行相同测试，并在最终 RTL 上完成 UVM 回归。

## 9. 工具警告与使用限制

基线 Methodology 报告记录了组合 LUT 驱动异步清除、大量 setup 失败路径、未识别的跨时钟结构、部分 I/O 延迟不完整、Block RAM 输出寄存器未并入 RAM 原语、宽乘法拆成多个 DSP 以及 Block RAM byte write enable 未推断等警告。

Out-of-Context 工程没有 SoC 顶层的真实时钟缓冲位置、芯片引脚位置和全部外围逻辑，因此端口路径与时钟偏差只是当前约束下的估算。不过基线、round2 与 round3 的最差 setup 起点和终点均位于 `core_clk` 时钟域内部，I/O 约束不完整不能解释这些内部失败路径。

## 10. 当前结论

结构调整前的完整布线结果为 WNS `-78.625 ns`。`build_pipeline_round2_synth` 的综合后 WNS 为 `-4.037 ns`，`build_pipeline_round3_synth` 进一步改善到 `-2.157 ns`，但仍未满足 100 MHz。round3 的主要剩余路径位于 Matrix、Complex 和 Vector 到 L1 的地址请求逻辑。

针对上述路径的进一步拆分已经写入 RTL，下一次综合与最终布局布线的数字必须从实际报告填入第 7 节。在最终布线报告生成之前，本文不声明 100 MHz 已经满足。
