# VC Formal 中文教程：案例工程

> **教学案例，不提供虚构的工具运行结果。** 本工程源代码以小模块说明证明、反例与专用应用的输入形式。该容器环境没有已安装、可授权执行的 VC Formal，因此本次未能执行实际形式证明。脚本依据随教程上传的 X-2025.06-SP1 参考文档撰写，执行时仍需核对本地安装版本、许可证及初始化状态。

所有源码已全文内嵌到对应教程；本目录仅提供相同内容的可编辑副本，不是阅读教程时必须来回查找的附件。

## 1. 如何开始

在 Linux 终端进入本目录（**不是项目上一级**），确保 `vcf` 位于 PATH，按需创建日志文件夹：

```bash
cd 案例工程
mkdir -p logs
vcf -f scripts/fpv_counter.tcl -batch 2>&1 | tee logs/fpv_counter.log
```

所有 filelist 文件中的 `./rtl/...`、`./formal/...` 都相对于本目录解析。`-batch` 是否直接等待完整执行按本地版本实际行为确认。因各项目的 reset 模型不同，请审查 `create_reset`、`sim_run -stable` 和 `sim_save_reset` 是否建立正确初始状态。

## 2. 示例选择表

- **应用：** FPV 正确计数器

  **Tcl：**

  ```tcl
  scripts/fpv_counter.tcl
  ```

  **输入（分别列出）：**

  ```text
  counter.sv
  counter_props.sv
  ```

  **预期观察（不是实际运行结果）：** 范围、保持、回绕应可证明；覆盖应可达

- **应用：** FPV 故障计数器

  **Tcl：**

  ```tcl
  scripts/fpv_counter_bad.tcl
  ```

  **输入：**

  ```text
  counter_bad.sv
  ```

  **预期观察（不是实际运行结果）：** `ap_range` 在计数超过 9 时应失败

- **应用：** FPV FIFO

  **Tcl：**

  ```tcl
  scripts/fpv_fifo.tcl
  ```

  **输入（分别列出）：**

  ```text
  fifo_ctrl.sv
  fifo_ctrl_props.sv
  ```

  **预期观察（不是实际运行结果）：** 占用范围、安全接受、标志一致性

- **应用：** AEP 数组越界

  **Tcl：**

  ```tcl
  scripts/aep_bounds.tcl
  ```

  **输入：**

  ```text
  array_demo.sv
  ```

  **预期观察（不是实际运行结果）：** 生成数组访问边界检查；允许索引 2/3 时可能失败

- **应用：** CC 多路选择

  **Tcl：**

  ```tcl
  scripts/cc_mux.tcl
  ```

  **输入（分别列出）：**

  ```text
  mux2.sv
  cc_connections.csv
  ```

  **预期观察（不是实际运行结果）：** 两条条件连接应符合 mux 选择

- **应用：** FXP 未初始化缓存

  **Tcl：**

  ```tcl
  scripts/fxp_uninit.tcl
  ```

  **输入：**

  ```text
  uninit_demo.sv
  ```

  **预期观察（不是实际运行结果）：** 未写入之前缓存的 X 可影响输出

- **应用：** FCA 覆盖可达性

  **Tcl：**

  ```tcl
  scripts/fca_coverage.tcl
  ```

  **输入：**

  ```text
  coverage_demo.sv
  ```

  **预期观察（不是实际运行结果）：** 在无额外约束时讨论四条条件路径；逐个审查目标生成情况

- **应用：** SEQ 正确版本

  **Tcl：**

  ```tcl
  scripts/seq_counter.tcl
  ```

  **输入（分别列出）：**

  ```text
  counter_spec.sv
  counter_impl.sv
  ```

  **预期观察（不是实际运行结果）：** 两种 RTL 描述功能等价

- **应用：** SEQ 故障版本

  **Tcl：**

  ```tcl
  scripts/seq_counter_bad.tcl
  ```

  **输入：**

  ```text
  counter_impl_bad.sv
  ```

  **预期观察（不是实际运行结果）：** en=1 后可以构造输出不一致

## 3. 为什么提供故意错误的版本

形式验证教程不能只展示“所有规则都通过”的脚本。正确版本和故障版本形成对照，便于验证工程师观察断言是否具有发现错误的能力，理解反例的第一个失败周期，以及区分“属性被证明”和“测试场景不可达”。不能在同一次编译中同时读入好版和坏版的同名顶层模块。

## 4. 其他应用的模板

FRV、FTA、FuSa、FSV、DPV、FLP 需要额外的 IP-XACT/RALF、故障数据库、UPF、电源状态、C++ HECTOR 包装模型或信息流策略。`templates/` 目录给出相应流程的**带占位符模板**，没有这些输入的情况下不应宣称已经完成验证。

## 5. 建议的练习顺序

先运行正确 FPV，再运行故障版。解释反例以后，在正确 FIFO 上加入有意错误并观察保护属性；使用 AEP 看非法数组索引，使用 FXP 看未初始化缓存；随后用 CC 检查 mux 路由并用 SEQ 对比两个计数器。进阶练习可用 FCA 检查一条控制分支的可达性，并在完善属性之后评估 FTA 的故障检出能力。

## 6. 关于报告

工具输出是权威结果；本工程 `expected/` 目录存放教学性的“预期现象说明”，不会伪造 `report_fv` 输出。需要提交项目报告时，保留真实 `vcf` 日志、工具版本、任务时限和属性状态，参考 [覆盖与验证验收](../覆盖与验证验收.md)。

## 7. 源码内嵌修订版补充案例

- **所在章节：** FRV

  **脚本或源码：**

  ```text
  scripts/fpv_register_demo.tcl
  ```

  **实际用途：** 手写属性检查简化 RW/W1C 寄存器；不是 FRV 自动生成检查

- **所在章节：** FuSa

  **脚本或源码：**

  ```text
  scripts/fpv_safety_demo.tcl
  ```

  **实际用途：** 教学异或故障模型与奇偶校验；不是 SFF/FDB 故障分析

- **所在章节：** FSV

  **脚本或源码（分别列出）：**

  ```text
  scripts/fsv_debug_good.tcl
  scripts/fsv_debug_bad.tcl
  ```

  **实际用途：** 小型安全信息流正确/泄漏对照；仍须本机工具核实

- **所在章节：** DPV

  **脚本或源码（分别列出）：**

  ```text
  cpp/add_mod256.cc
  cpp/add_mod256_selftest.cc
  ```

  **实际用途：** 普通 C++ 参考函数及穷举自测；不是 HECTOR 包装

- **所在章节：** DPV

  **脚本或源码：**

  ```text
  scripts/fpv_alu_demo.tcl
  ```

  **实际用途：** 流水线结果与有效标志的 SVA；不是 C++—RTL DPV 证明

- **所在章节：** FLP

  **脚本或源码：**

  ```text
  scripts/fpv_lp_logic_demo.tcl
  ```

  **实际用途：** 理想逻辑隔离的 FPV 练习；不替代 UPF 低功耗检查

新增代码均在对应文章中完整列出。运行每个案例前，应确认它属于原生专用应用、配套 FPV 练习还是普通 C++ 自测，不能混用报告含义。
