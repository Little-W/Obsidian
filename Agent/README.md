# Agent 框架设计调研资料包

核对日期：2026-11-01。主题涵盖 Flow、Graph 工作流与智能体团队。

## 阅读

- `Agent框架_Flow与智能体团队_调研报告.md`：完整 Markdown 报告，17 个章节、71 项参考来源。
- `Agent框架_Flow与智能体团队_阅读版.html`：内嵌全部插图的单文件阅读版，可直接用浏览器打开。
- `figures/`：12 张高清 PNG 与 12 张可编辑 SVG。
- `source/`：6 份 Python 绘图源码、来源索引和 HTML 构建脚本。
- `examples/`：建议的 Graph IR 类型接口和 DFT 诊断流程 DSL 摘要。
- `assets/report.css`：HTML 阅读版样式。

Markdown 插图使用相对路径。解压后请保留目录结构；将整个文件夹放入 Obsidian、VS Code 等阅读器即可显示全部插图。单独下载 Markdown 不包含图片文件；HTML 已内嵌图片。

## Graph 专题

第 9 章专门讨论：

- 控制流、数据依赖、共享状态和事件四种图语义。
- DAG、有环图、动态路由、动态实例与程序编排。
- XOR、AND、OR 汇合与空集合、部分失败、取消策略。
- LangGraph Pregel 的分阶段状态可见性及普通边、固定等待集合的区别。
- 设计图、运行实例、业务轮次、执行尝试和网络重发。
- LangGraph、ADK、Pydantic、Microsoft Agent Framework 等框架差异。
- 与 Airflow、Dagster、Prefect、Temporal 的边界。
- Graph IR、声明示例、静态校验、编辑器调试。
- GoT、LLMCompiler、AFlow、2026 年工作流优化综述及 VFlow。

示例为本报告提出的设计草案，不是可直接运行的 SDK 配置。没有实现编译器，也没有在用户工程上执行性能或可靠性基准。

## 图稿

| 图号 | 内容 |
| --- | --- |
| 01 | Flow 控制方式与 Agent 数量 |
| 02 | 团队协作与控制转移 |
| 03 | 外层流程与局部团队 |
| 04 | 设计定义、运行状态与制品 |
| 05 | 外部作业恢复 |
| 06 | 四种图语义 |
| 07 | XOR、AND、OR 分支汇合 |
| 08 | Pregel 分阶段状态更新 |
| 09 | 有环设计图与运行实例 |
| 10 | 官方设计动向时间线 |
| 11 | DFT Agent 分层架构 |
| 12 | DFT 执行、诊断与局部修复 |

PNG 宽度为 1800—3240 像素。SVG 保留原生文字和矢量图形，没有将文字转换为不可编辑轮廓。SVG 中文显示依赖本机字体替换；PNG 是固定版式参考。

## 重新生成插图

需要 Python 3 与 matplotlib；图像校验使用 Pillow。若未指定本机中文字体，PyMuPDF 可以提供后备字体。

```bash
python3 source/diagrams_01_04.py
python3 source/diagrams_05_10_11_12.py
python3 source/diagrams_06_graph_models.py
python3 source/diagrams_07_graph_joins.py
python3 source/diagrams_08_graph_supersteps.py
python3 source/diagrams_09_graph_instances.py
```

可通过环境变量 `AGENT_REPORT_CJK_FONT` 指定中文字体文件的完整路径：

```bash
AGENT_REPORT_CJK_FONT=/path/to/chinese-font.ttf python3 source/diagrams_07_graph_joins.py
```

脚本按自身位置寻找输出目录，不依赖当前工作目录。

## 重新生成 HTML

需要 Pandoc 3 或兼容版本：

```bash
python3 source/build_reading_version.py
```

HTML 内嵌 PNG 与样式，官方资料保留网页链接。修改 PNG 或正文后需重新生成 HTML。

## 证据范围

技术事实来自官方文档、官方仓库和原始论文。动态文档没有被当作功能首次发布日期；论文实验与调查数字保留适用条件。推荐架构、接口伪代码、预算和 DFT 流程属于设计建议。图稿为原创关系示意，不是厂商截图；图上的示例运行也不是实测轨迹。

