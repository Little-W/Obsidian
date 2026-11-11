# NPU PE-LBIST 研究报告包

检索截止：2026-11-03。

## 阅读

主文档：`NPU_PE_LBIST_研究报告.md`。解压后保持其与 `figures/` 的相对位置，可在 Obsidian、Typora、VS Code 等 Markdown 阅读器中阅读；公式采用 `$...$` / `$$...$$`。

`NPU_PE_LBIST_阅读预览.html` 内嵌正文和全部 PNG，无需外部图片即可阅读。公式离线保留 LaTeX；联网后可通过页面顶部按钮加载 MathJax。HTML 是便捷预览，不取代 Markdown 主文档。

## 文件

```text
NPU_PE_LBIST_研究报告.md       主报告与 25 条来源
NPU_PE_LBIST_阅读预览.html     内嵌插图的便捷预览
figures/                     12 张 PNG + 12 张可编辑 SVG
  manifest.json              插图目录与画布尺寸
diagram_src/
  render_figures.py           全部 SVG / PNG 的精确生成源码
  build_package.py            参考文献、来源表与预览生成
mermaid/                     6 个主要逻辑结构的 Mermaid 版本
sources.csv                  可检索的来源核验表（UTF-8 BOM）
sources.json                 同一来源表的 JSON 版本
QA.md                        文件与引用检查结果
SHA256SUMS.txt               文件校验值
```

## 编辑插图

SVG 保留可编辑图形和文字，不需要从 PNG 重新绘制。修改精确布局可编辑 `diagram_src/render_figures.py`。Mermaid 文件提供逻辑关系，不保证渲染布局与 SVG 完全相同。

重建图像：

```bash
python -m pip install cairosvg
python diagram_src/render_figures.py
```

重建来源表和 HTML：

```bash
python -m pip install markdown-it-py
python diagram_src/build_package.py
```

中文显示依赖本机中文字体；包内不含字体文件。全部插图是原创说明图，未复制论文原图。包内不分发论文全文。

## 结果性质

报告对原文、原始摘要、题录与专利分别标注证据等级。架构建议与实验流程尚未在用户硬件上验证；没有编造 ATPG、故障覆盖、PPA 或上板结果。
