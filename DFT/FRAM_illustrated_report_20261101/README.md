# FRAM 特殊故障与测试算法研究｜图文报告包

日期：2026年11月1日

## 阅读入口

- **FRAM_图文报告_20261101.html**：无需联网的完整阅读版，正文、14张插图、中文字体与公式均已嵌入。可直接用浏览器打开。
- **FRAM_特殊故障与测试算法调研_20261101.md**：可编辑的完整 Markdown 报告，12章、42条参考文献。公式使用 `$...$` 和 `$$...$$`；正文图片使用相对路径。
- **插图总览.png**：14张图的缩略总览，用于快速定位主题。

请先解压整个目录，再打开 Markdown；不要只移动MD文件，否则相对路径图片会丢失。离线HTML的正文显示不依赖其他文件；其中原文文献链接需联网，可编辑SVG链接在完整解压包中使用。

## 内容结构

| 目录／文件 | 内容 |
| --- | --- |
| `figures/svg/` | 14张可编辑SVG，保留文字、形状与连接线，并嵌入中文子集字体 |
| `figures/png/` | 对应的14张高清PNG，宽度2800像素，可直接用于文档与演示 |
| `source/` | Python绘图源码、字体处理与PNG导出脚本、HTML生成源码、插图清单 |
| `source/original_*.mmd` | 原报告两张Mermaid流程图源码 |
| `source/report_before_illustration.md` | 插图加入前的报告底稿，供重新生成完整报告 |
| `assets/fonts/` | 中文字体、嵌入用子集字体和开放许可证 |
| `assets/licenses/` | HTML构建所用工具的许可证 |

SVG内的文字仍是文字对象，并未全部转成不可编辑轮廓。支持内嵌字体的浏览器可直接显示；部分矢量编辑器可能忽略SVG内嵌字体，此时可安装随附的 `FRAMDiagramSans-Regular.otf`，或使用原始 `NotoSansCJKsc-Regular.otf` 作为替代字体。修改文字后若使用了子集外的新字符，应重新运行字体生成脚本。

## 新增的研究不足与方向

第10章具体讨论：带时间与历史的故障原语和自动测试生成；多观测量标定、参数可辨识性与快速模型；首次读及拓扑感知测试；联合缺陷、相关读出和参考校准；测试代价与运行可靠性；独立验证和可重放基准。每个方向配有研究问题、方法、对照、指标及资源边界，并给出适合MBIST课题的最小研究闭环。

## 插图主题

1. 电容型FRAM的单元连接与读后恢复。
2. 读信号、有效参考与读裕量。
3. 正常回线、印记与可切换幅度变化。
4. 物理状态、电路响应与功能故障原语。
5. March C−掩盖恢复故障的最小反例。
6. PUND脉冲与切换电荷提取。
7. 保持测试的独立恢复组与首次读。
8. RAD访问间隔与终点首次读。
9. 共享板线、浮置节点与半选分压。
10. FeFET窗口收窄与阈值共同漂移。
11. FeFET专用序列与模拟参考测试。
12. 可配置FRAM MBIST与可选宏内DfT。
13. 已有证据与仍需验证的问题。
14. 按可获得资源选择研究路线。

图中曲线为定性示意，未新增器件实验。图5是报告中的教学状态机反例，图8和图12等工程设计仍按正文限定范围理解。每张图均保留来源或“本文设计”说明。

## 重新生成

### 生成SVG

绘图脚本只使用Python标准库：

```bash
python source/draw_physics_figures.py
python source/draw_margin_figure.py
python source/draw_test_figures.py
python source/draw_fefet_figures.py
python source/draw_gap_figure.py
python source/draw_research_roadmap.py
```

### 生成报告与嵌入字体

安装Python依赖，然后运行：

```bash
python -m pip install -r source/requirements.txt
python source/integrate_figures.py
python source/embed_fonts.py
```

`embed_fonts.py` 从随附的原始字体重新生成子集，并更新SVG。生成的子集使用“FRAM Diagram Sans”和“FRAM Report Sans”名称；原始许可证及版权信息随包提供。

### 导出高清PNG

安装Inkscape并确保命令行可以调用 `inkscape`：

```bash
python source/render_figures.py
```

也可以仅重新导出一张：

```bash
python source/render_figures.py fig05_march_restore_escape.svg
```

### 生成离线HTML

安装本目录声明的Node.js依赖：

```bash
npm install
node source/build_html.mjs
```

公式在构建时转换为SVG，最终HTML不依赖MathJax脚本、CDN或在线字体。原始Markdown公式保留在MD文件中。

### 生成插图总览

```bash
python source/build_overview.py
```

## 校验范围

交付前已检查14张插图的渲染、主要文字布局和连接关系；检查Markdown图片路径与42条编号引用；生成离线HTML时检查所有展示公式与行内公式的排版；压缩包按完整目录组织。

参考文献逐项说明全文、关键段和摘要证据范围。第10章扩展为九类证据缺口、六个研究方向、资源条件与最小交付，并新增自动提参研究文献[42]；作者明示局限、本文推断和本次资料限制分别标记。插图用于解释机理与研究方案，没有扩大原算法的故障覆盖声明。

