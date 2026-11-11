# 量化方法报告图表

三张图分别读取 accuracy.csv、block_error.csv 和 performance.csv。数据来自保留的历史实验，未新增推理测量；CSV 的 source 字段相对于 docs 主目录，`#10.xx` 表示日志小节编号而非浏览器锚点。性能图按 frequency_hz/cycles 重新计算，不使用人工四舍五入的吞吐值。

```sh
python3 docs/_assets/llm_quantization_method/render_figures.py
```

脚本需要 Matplotlib，输出 SVG 和 PNG。Top-k 对照不表示长对话质量；两个 block 子图保留集不同；性能图输入与周期模型不同，不表示同条件加速倍数。原始文件与校验值见 [报告证据索引](../../logs/LLM量化报告证据索引.md)。
