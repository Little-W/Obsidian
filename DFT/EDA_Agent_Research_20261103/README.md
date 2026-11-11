# EDA Agent 研究报告图文包

研究截止日期：2026-11-03。

## 阅读

- `EDA_Agent_研究报告_20261103.md`：完整 Markdown 报告，包含 16 个主题章节、9 篇上传论文解读、补充研究与 44 条参考资料。
- `EDA_Agent_研究报告_阅读版.html`：可离线打开的单文件阅读版，图片已经嵌入，带目录与可跳转的参考文献。
- `figures/`：10 张原创中文示意图，每张同时提供可编辑 SVG 和高分辨率 PNG。
- `sources/`：4 张从上传原论文直接渲染的插图，及页码、坐标和文件哈希记录。
- `figure_source/`：原创图生成程序、原论文插图提取程序、样式和检查记录。

Markdown 中的图片为相对路径。请整体解压并保留目录结构；HTML 阅读版可以单独移动。数学公式采用 `$...$` 和 `$$...$$`。

## 重绘原创图

需要 Python 3 和 Pillow；不指定字体时还需要 PyMuPDF，用其内置中文字体。也可以传入自己的中文 TTF 字体。

```bash
python figure_source/draw_figures.py
```

使用自选字体：

```bash
python figure_source/draw_figures.py --font /path/to/chinese-font.ttf
```

SVG 和 PNG 使用同一套坐标。SVG 保留文字，显示字体由阅读软件的中文字体决定；PNG 用于字体无关的稳定显示。

## 重新提取文献原图

需要原始 `EDA-Agent` 解压目录和 PyMuPDF：

```bash
python figure_source/extract_paper_figures.py --papers /path/to/EDA-Agent
```

本包没有重复打包全部原始 PDF。原图保留原作者内容，来源见报告和 `sources/figure_provenance.json`。本报告提出的工作流和实验方案与原文事实已分别标识；没有声称已独立复现论文的商业 EDA 实验。
