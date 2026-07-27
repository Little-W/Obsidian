# NPU 单核 Vivado 时序检查

该目录使用 Vivado 2024.2 对 `npu_single_core_top` 执行综合、布局和布线。
目标器件是 `xc7a200tfbg484-3`，两个时钟均按 100 MHz 约束。

运行方式：

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make clean
make syn
```

主要结果位于 `build/`：

- `summary.txt`：器件、目标周期、最差 setup slack 和最差 hold slack；
- `timing_post_synth.rpt`：综合后的时序摘要；
- `critical_paths_post_synth.rpt`：综合后的详细 setup 路径；
- `timing_post_route.rpt`：布线后的时序摘要；
- `critical_paths_post_route.rpt`：布线后的详细 setup 路径；
- `utilization_post_route.rpt`：层次化资源使用报告。

输入、输出延迟均设为 1.0 ns，时钟不确定度设为 0.2 ns。`core_clk_i` 与
`noc_clk_i` 被声明为异步时钟组；跨时钟数据必须通过设计中的异步 FIFO。

运行前先执行 `make clean`，不要复用旧的 `build/` 报告。若源文件发生变化，
必须重新执行综合，最终结论以最新的 `summary.txt` 和详细时序报告为准。
