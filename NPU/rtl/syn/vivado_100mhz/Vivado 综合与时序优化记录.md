# Vivado 综合与时序优化记录

## 1. 验证目标

本记录用于追踪 NPU 单核 RTL 在 Xilinx Artix-7 FPGA 上的综合、布局和布线结果，并记录复杂数学单元的结构调整过程。

固定配置如下：

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

`core_clk_i` 与 `noc_clk_i` 均使用 `10.000 ns` 周期。两个时钟属于异步时钟组，因此时序工具不会检查两个时钟域之间的同步时序。

> [!NOTE]
> 综合后的时序报告用于快速判断 RTL 结构。100 MHz 是否满足要求，最终以布局和布线后的报告为准。

## 2. 命令与报告位置

### 2.1 综合快速检查

综合快速检查使用：

```sh
/home/yusen/opt/Xilinx/Vivado/2024.2/bin/vivado \
  -mode batch \
  -notrace \
  -source "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz/run_vivado_synth_only.tcl" \
  -tclargs \
  <RTL_ROOT> \
  "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz/npu_single_core_100mhz.xdc" \
  <REPORT_DIR> \
  xc7a200tfbg484-3 \
  10.000
```

脚本位置：

- `NPU/rtl/syn/vivado_100mhz/run_vivado_synth_only.tcl`
- `NPU/rtl/syn/vivado_100mhz/npu_single_core_100mhz.xdc`

计划保存的文本报告：

- `NPU/rtl/syn/vivado_100mhz/reports/baseline/utilization_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/baseline/timing_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/baseline/critical_paths_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/utilization_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/timing_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/critical_paths_post_synth.rpt`

### 2.2 布局和布线

完整运行命令：

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make clean
make syn \
  BUILD_DIR=build_fp_seq_100mhz \
  JOBS=1 \
  PART=xc7a200tfbg484-3 \
  PERIOD_NS=10.000
```

完整结果将保存在：

- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/summary.txt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/utilization_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/timing_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/critical_paths_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/methodology_post_route.rpt`

## 3. 初始结构

初始版本的 `npu_complex_engine` 直接调用多个组合 FP32 函数。Sigmoid、Tanh、GELU、SiLU、Softmax、LayerNorm 和 RMSNorm 会同时展开多个加法、减法、乘法、倒数、指数和平方根倒数运算。

这种写法产生以下硬件结构：

- 相同 FP32 运算在多个表达式中重复展开；
- 一个时钟周期内串接多级 FP32 运算；
- 次正规数处理包含多次连续移位；
- 指数、倒数和平方根倒数包含多层多项式运算；
- 复杂数学结果继续进入整数转换和数据类型裁剪。

初始版本快照：

| 项目 | 值 |
|---|---|
| Git 提交 | `d9b6315db52ae63c99bcf86f85d33ef689d5d271` |
| 快照目录 | `/tmp/npu_fp_baseline.8cV0xQ/rtl` |
| 首次综合并行度 | 4 |
| 首次运行结果 | 因物理内存不足产生大量主缺页，已中断 |
| 首次运行峰值内存 | `6098.270 MB`，来自 Vivado 日志 |
| 首次运行结束位置 | `Start Timing Optimization` |

> [!WARNING]
> 首次运行出现 Vivado 的 `Thrashing Detected` 提示，主缺页数量超过 70 万。该次运行没有生成最终报告，不用于资源或时序结论。随后把综合并行度改为 1 并重新运行。

## 4. RTL 调整记录

### 4.1 第 1 轮：共享顺序 FP32 加减乘单元

新增 `engines/npu_fp32_alu_seq.sv`。

主要调整：

- ADD、SUB 和 MUL 共用一个 FP32 运算单元；
- 请求使用 `req_valid_i/req_ready_o`；
- 结果使用 `rsp_valid_o/rsp_ready_i`；
- 加法对齐、加减、规格化和舍入分为多个状态；
- 次正规数每个周期移动 1 bit；
- 24-bit × 24-bit 乘法单独占用一个状态；
- 结果保持到接收方确认。

目标是缩短单周期组合数据路径，并减少重复的 FP32 运算硬件。

### 4.2 第 2 轮：复杂数学微操作状态机

新增 `engines/npu_complex_math_seq.sv`。

主要调整：

- Sigmoid、Tanh、GELU、SiLU、EXP、倒数和平方根倒数改为多周期执行；
- 复合函数通过微操作调用共享 ADD、SUB 和 MUL；
- 使用返回状态栈支持函数内部调用；
- I2F 后乘比例值、近似除法和倒数也使用同一请求/响应接口；
- 中间值存放在寄存器中，下一步运算在后续周期发起。

### 4.3 第 3 轮：Complex Engine 接入

修改 `engines/npu_complex_engine.sv`。

主要调整：

- 增加 `ST_MATH_REQ` 和 `ST_MATH_RSP`；
- 增加动作编号，记录每次数学结果的后续处理；
- 激活、Softmax、LayerNorm、RMSNorm 和 ADD_RESCALE 改为逐步发起微操作；
- 四组分段累加值按固定顺序相加；
- Welford 均值和 M2 更新改为多个微操作；
- 输出比例除法完成后再执行 FP32 到整数转换；
- 保留原有数据类型裁剪、异常状态、INT4 读改写和存储请求行为。

### 4.4 第 4 轮：拆分 EXP 的两个转换

`ST_EXP_RANGE_ROUND` 原本在同一周期执行：

1. FP32 到整数舍入；
2. 整数再转换为 FP32。

新增 `ST_EXP_RANGE_FROM_INT`，把两次转换放到两个周期，避免两段可变移位逻辑串接。

## 5. 每轮结果

### 5.1 初始版本综合结果

| 指标 | 结果 |
|---|---|
| Slice LUTs | 待实现结果 |
| Slice Registers | 待实现结果 |
| Block RAM Tile | 待实现结果 |
| DSPs | 待实现结果 |
| WNS | 待实现结果 |
| TNS | 待实现结果 |
| WHS | 待实现结果 |
| THS | 待实现结果 |
| 关键路径起点 | 待实现结果 |
| 关键路径终点 | 待实现结果 |
| 逻辑级数 | 待实现结果 |
| 数据路径延迟 | 待实现结果 |

状态：单线程综合正在运行。

### 5.2 共享顺序 FP32 版本综合结果

| 指标 | 综合后 | 布线后 |
|---|---:|---:|
| Slice LUTs | 待实现结果 | 待实现结果 |
| Slice Registers | 待实现结果 | 待实现结果 |
| Block RAM Tile | 待实现结果 | 待实现结果 |
| DSPs | 待实现结果 | 待实现结果 |
| WNS | 待实现结果 | 待实现结果 |
| TNS | 待实现结果 | 待实现结果 |
| WHS | 待实现结果 | 待实现结果 |
| THS | 待实现结果 | 待实现结果 |

关键路径：

| 项目 | 综合后 | 布线后 |
|---|---|---|
| 起点 | 待实现结果 | 待实现结果 |
| 终点 | 待实现结果 | 待实现结果 |
| 逻辑级数 | 待实现结果 | 待实现结果 |
| 数据路径延迟 | 待实现结果 | 待实现结果 |
| 主要逻辑 | 待实现结果 | 待实现结果 |

100 MHz 结论：待实现结果。

## 6. 功能回归

当前已经完成：

| 测试 | 结果 |
|---|---|
| 顶层 Verilator lint | PASS，无告警 |
| FP32 ADD/SUB/MUL 随机比对 | PASS，6010 项 |
| 复杂数学参考测试 | PASS，71 项 |
| 模块级 Engine 测试 | PASS，L1 握手 156 次，MIF 握手 8 次 |
| 独立 Complex Engine 测试 | PASS |
| Sigmoid、Tanh、Softmax、LayerNorm 示例 | PASS |

Transformer 旧构建的 41 条指令测试结果：

```text
score=[14,-5,-5,30]
probability=[4,0,0,4]
context=[2,-1,3,0,-2,4,1,3]
int8=[7,-8,13,-14,-3,4,1,5]
```

最新 RTL 的 `make clean && make test` 结果：待实现结果。

## 7. 综合警告

初始版本日志已经确认以下类别：

- 前端部分数组无法推断为 Block RAM，工具改用寄存器；
- 部分寄存器同时具有 set 和 reset；
- 若干未使用寄存器被综合工具删除；
- 首次 4 进程运行发生物理内存不足和大量主缺页。

共享顺序 FP32 版本的综合警告：待实现结果。

布局和布线后的 Methodology 报告：待实现结果。

## 8. 当前结论

功能测试表明，共享顺序 FP32 运算单元保持了现有数学参考结果。资源、关键路径和 100 MHz 结果必须等待 Vivado 报告生成后填写，当前不作估算。
