# Alkaid 缺陷回归约束提示词

以下内容整体作为另一个 AI 修改 Alkaid RTL、验证代码或性能配置时的约束提示词。

---

你正在修改 Alkaid CPU 工程。开始工作前先检查当前分支和未提交修改，保留与任务无关的内容。必须先理解受影响模块及其已有定向测试，不得通过删除测试、减少检查项、放宽正则表达式、降低性能门槛、缩短测试程序、增加跳过条件或隐藏超时来取得通过结果。

验证清单以 `verif/tb_conf/bug_regression_gate.json` 为唯一依据，使用稳定用例名称，不使用数字编号。先执行 `make -f verif/Makefile bug-regression-list` 检查清单。修改期间执行 `make -f verif/Makefile bug-regression-targeted PARALLEL_JOBS=<并行数>`；准备交付前必须执行 `make -f verif/Makefile bug-regression-gate PARALLEL_JOBS=<并行数>`。只有全部用例返回 PASS，且没有跳过、超时、编译失败或检查程序失败，才能声明修改完成。

必须保持以下设计行为：

1. `bjp_req_i` 有效且分支结果尚未确定时可以推迟中断；分支目标确定的周期必须接受中断。MEPC（Machine Exception Program Counter，机器异常程序计数器）必须记录已经确定的分支目标，不能记录顺序地址或较早的 PC。
2. 中断请求对 dispatch 和 EXU 的阻止、取消必须发生在同一个周期。`mret` 返回后第一条有效指令不能被误删，RT-Thread 定时器中断返回后必须继续正常执行。
3. AXI 写地址通道（AW）和写数据通道（W）可以独立完成握手。W 先完成时不得重复发送写数据；AW 恢复后必须完成该请求；写响应通道（B）的未完成事务数不得超过队列容量。
4. LSU 按对齐后的字地址检查数据冒险。同一字内确有相关性的访问必须等待，不同字访问不得因队列中存在其他存储而全部暂停。读取直接返回以及队列返回都必须带回准确的数据、目标寄存器号和 commit id。
5. 其他 hart 写入 DTCM 时，匹配的 LSU L0 Cache 表项必须失效；失效与热命中同时发生时必须取消该命中。较早发出的读取响应只能完成原读取，不能覆盖随后写入 LSU L0 Cache 的较新数据。
6. DCache 热命中应按既定快速时序返回。响应端暂停时，响应有效状态和数据必须保持稳定。写探测与失效同时发生时不得误用上一次探测结果；本 hart 的原子写必须清除相应缓存行。
7. ICache 热命中应按既定快速时序返回。响应端暂停时必须保持响应；全 Cache 失效必须清除已有缓存行；未命中等待响应期间发生失效时，可以交付本次返回数据，但不得把该数据重新填入 ICache。
8. 仲裁器为请求分配共享 ID 后，必须保存请求端信息，依据响应 ID 把 R、B 响应准确返回原请求端。四笔 outstanding 请求同时存在以及响应次序变化时，不得错配响应。
9. 一级 AXI4-Lite Cache与乒乓缓存开启时，AW、W、B、AR、R 五个通道的暂停行为必须符合各自握手条件。Crossbar 对从端的选择必须保持到相应未完成事务结束，不能让其他从端的响应进入当前请求端。
10. 性能测试必须保持注册用例规定的 ISA、编译参数、CRC、单 hart 最低分数和 SMP 最低加速比。不得修改测试设置来掩盖功能退化。

RTL 定向组必须通过以下命名用例支持的全部流水线配置：

- `module/special/exu_lsu_data_first_edge`
- `module/special/exu_lsu_hot_store_order_edge`
- `module/special/exu_lsu_direct_response_edge`
- `module/special/exu_lsu_queue_edge`
- `module/special/perf_probe`
- `module/directed/dispatch_hot_cache`
- `module/directed/axi_buffer_cache_bug_edges`
- `module/directed/clint_resolved_branch_irq`
- `module/directed/axi_interconnect_m1_p1_order`
- `module/directed/axi_dual_read_arbiter`
- `module/directed/axi_dual_coherency`
- `module/directed/clint_multihart`

程序自检组必须通过以下命名用例支持的全部流水线配置：

- `program/limit/hazard_edges`
- `program/limit/lsu_queue_token_edges`
- `program/limit/trap_pipeline_edges`
- `program/limit/mmio_dtcm_order_edges`
- `program/limit/writeback_pressure`
- `program/boundary/O3/trap_pipeline_edges`

系统组必须通过以下五级流水线用例：

- `system/performance/baremetal_coremark_p5_tage`
- `system/multicore/rtthread_coremark_up`
- `system/multicore/rtthread_coremark_fair_compare`

真实性能配置保持 RV32、五级流水线、A/Zba/Zbb/Zbs/Zbc 开启、C 关闭、非对齐访问开启；LSU L0 Cache 为 64 项 1 way；ICache 为 2048 项 2 way；DCache 为 1024 项 2 way；Cache outstanding 深度为 4；M0/M1 AXI ping-pong 均为 1 级且关闭 fall-through；CSR read predecode 开启；Enhanced BPU + TAGE 使用 4 张表，每张 128 项，tag 为 7，history 为 4/8/12/16，BTB 为 128 项，BHT 为 256 项，GHR 为 2。

如果某项失败，先给出失败用例的稳定名称、日志位置、首个有效错误和原因分析，再修复实现并重跑失败用例，随后重新运行完整必过清单。缺少仿真器、编译器、外部程序或许可证时，应明确报告阻塞原因；不得把未执行视为通过。最终答复必须列出实际执行命令、每组 PASS 数、失败数、跳过数及关键日志位置。未经用户明确要求，不得提交或推送修改。

---
