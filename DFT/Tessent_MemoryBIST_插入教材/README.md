# Tessent MemoryBIST 插入教材与示例工程

## 阅读入口

- `Tessent_MemoryBIST_插入教材.md`：完整中文教材，18 章与附录；适合 Obsidian。
- `Tessent_MemoryBIST_插入教材_离线阅读.html`：内嵌插图、公式和样式，可独立打开。
- `assets/`：10 幅可编辑 SVG、对应 PNG 和绘图源码。

教材覆盖 Tessent Shell 的 RTL 插入流程、内置算法选择、硬编码/软可编程自定义 March 算法、OperationSet、自动分组参数、外部步骤优化器接入、全地址仿真、故障注入和物理交付。以 2025.1 Revision 36 原厂资料核对命令；其他版本须在安装环境中复核。它不是旧版 MBISTArchitect 教材。

## 离线运行

需要 Python 3.10 或更高版本；算法和配置编辑工具仅使用 Python 标准库。

```bash
cd Tessent_MemoryBIST_插入教材
python tools/selftest.py
python tools/march_reference.py --depth 16 --width 8 --out results/march
python tools/grouping_demo.py examples/memories.csv --method greedy --out results/greedy
python tools/grouping_demo.py examples/memories.csv --method exact --out results/exact
python tools/config_steps.py examples/auto_synthetic.dft_spec \
    results/exact/steps_plan.json results/exact/exact_steps.dft_spec
```

命令选项可用相应工具的 `--help` 查看。六宏数据和 `auto_synthetic.dft_spec` 是教学输入，不是可直接插入真实芯片的经过认证的设计配置。

### 已执行的检查

21 项单元测试通过；其中包括 20 个随机小规模划分与独立枚举的比较，以及 16×8 bit 抽象数组上四类单 bit 故障的全部 512 个位置用例。贪心例子得到 3 个步骤、300 μs；精确例子得到 2 个步骤、200 μs，均是教材模型结果。Tcl 做了文本结构完整性检查，未执行其中的 EDA 命令。记录位于 `results/`。

### 未执行的检查

没有运行 Tessent 配置编译、控制器生成、商业仿真、综合、STA 或布局布线。本资料包不含工艺库、授权宏模型和用户 RTL。离线检查通过不能证明真实 UDA 在目标宏上可用，更不能证明硅片故障覆盖。

## 在真实 Tessent 环境中使用

```bash
cp scripts/site_setup.tcl scripts/site_local.tcl
# 编辑 site_local.tcl，填写真实 RTL、TCD、cell library、时钟和仿真模型。
# 初次将 RUN_STAGE 设为 plan，ALGO_MODE 设为 preserve。
MBIST_WORK="$PWD/work_baseline_001" \
    tessent -shell -dofile scripts/run_mbist.tcl
```

`site_setup.tcl` 刻意将必需输入留空；入口脚本会拒绝缺失输入和覆盖已有 TSDB。先完成单宏库默认算法的基线，再逐步改算法和分组。需要实际运行自定义算法时，必须检查生成的 PatternsSpecification 并填写控制器实际实例路径。

`MANUAL_DFT_SPEC` 接受基于真实自动配置修改的完整 DftSpecification。示例离线编辑器只在既有控制器内部重排匿名 Step，并保留 MemoryInterface；遇到 Step 层属性或未知结构会拒绝修改，不会猜测。

## 目录

| 目录 | 内容 |
|---|---|
| `scripts/` | 环境核对、站点配置、自动分组参数和阶段式 Tessent Tcl |
| `algorithms/` | 六条指令的 `LabMarchCMinus` UDA 教学示例 |
| `tools/` | March 抽象模型、分组演示、配置编辑器、单元测试、HTML 构建器 |
| `examples/` | 六宏属性 CSV、合成配置树、输入说明 |
| `results/` | 实际离线运行结果、日志、配置改写摘要 |
| `assets/` | 原创插图与绘图源代码 |

## 重新生成阅读版与插图

HTML 构建需要 `markdown-it-py`、`Pygments`、`beautifulsoup4` 和 `matplotlib`。PNG 转换另外需要 `cairosvg`。这些依赖仅用于资料排版，不是离线分组算法的运行依赖。

```bash
python assets/generate_figures.py
python tools/build_html.py
```

不随资料包分发字体。机器上有 Noto Sans CJK、思源黑体或常见中文系统字体时，插图和网页中的中文显示更稳定。
