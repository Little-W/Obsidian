---
name: technical-presentation-production
description: Create, restructure, restyle, and visually validate technical PPTX decks that combine native slide content with editable engineering diagrams. Use when template fidelity, readable Chinese typography, Draw.io/SVG/PNG assets, slide order, or page-by-page proofing matter; do not use for presentation ideation without a deck deliverable.
---

# 技术PPT制作与绘图

交付可编辑、可演讲且经过目视检查的技术PPT。技术准确性、模板一致性、实际阅读尺寸下的清晰度和可追溯图源同等重要。

## 先确定交付约束

- 识别当前PPT、指定模板、目标文件、听众、演讲时长、语言、术语约束、字体、配色和图源要求。用户提供的PPT和模板优先于skill默认值。
- 用户要求修改现有PPT时，保留母版、页面尺寸、主题和未涉及内容。以临时输出完成修改和验证，确认无误后再替换正式文件，并保留可恢复副本。
- 需要补充技术内容时，优先读取用户提供的设计文档和规范。易变化或高风险信息按任务要求核验，不凭印象补全编码和信号含义。
- 在制作讲稿前先稳定最终页序和页面内容；讲稿逐页对应，不引用已经删除或移动的页面。

## 内容组织

- 先给出概念、信号定义、有效条件和字段取值，再展示使用这些内容的功能图或事务图。读者不应在尚未理解符号时被要求解读复杂插图。
- 一页只表达一个主问题。表格或代码在可读字号下放不下时拆页，不通过持续缩小字体保留所有内容。
- 标题说明本页结论或对象，避免含义不明的占位词。页内小节标题加粗，正文保持常规字重。
- 解释性标题、段落、卡片、表格、代码和图例使用PPT原生对象；插图只承载拓扑、流程、时序或状态关系，不把大段说明文字烘焙进图片。

## PPT与插图分工

- 修改或新建PPT页面时读取[references/pptx-editing-and-proofing.md](references/pptx-editing-and-proofing.md)。
- 创建、替换或检查技术插图时读取[references/technical-diagrams-in-slides.md](references/technical-diagrams-in-slides.md)。若`technical-diagram-review`可用，同时应用其中的连线与端点验收规则。
- 技术插图保留Draw.io、SVG或其他可编辑矢量图源，并从图源重新导出PNG。不得只修改导出的PNG而让图源失真。

## 工作流程

1. 读取PPT并渲染当前版本，记录页数、标题、模板规则、问题页和已有图源。
2. 建立页序和页面职责清单，确认术语说明、信号表、功能图、事务图、结果页之间的依赖关系。
3. 先完成技术内容和图源，再调整原生PPT对象；删除页面后重新核对页序，不假定页面索引行为。
4. 统一页眉、字体、字号层级、圆角、线宽、颜色、卡片间距和页脚。深色底使用浅色字，黑字只放在浅色底上。
5. 将插图从可编辑图源高清导出并重新嵌入。说明卡和表格保留为PPT原生对象。
6. 渲染全部页面生成总览图，并以较高分辨率检查修改页。发现重叠、越框、裁切、低对比度或连线错误后，回到PPT对象或图源修复并重新渲染。
7. 检查PPTX压缩包结构、页数、标题顺序和禁用内容，确认临时文件通过后再写入正式文件。

可使用[scripts/render_pptx.py](scripts/render_pptx.py)生成PDF、逐页PNG、总览图、文字提取结果和PPTX结构检查记录。

## 硬性验收

- 每页标题位置、尺寸和装饰元素一致，标题不与正文或插图重叠。
- 无文字重叠、越框、裁切、贴边、小到无法在整页视图阅读的正文。
- 方框尺寸与内容匹配；同组卡片尽量对称，但不为追求等大而保留大片无效空白。
- 深色背景不使用黑字；浅色卡片的文字和边框具有足够对比度。
- 表格字段、代码和信号名完整，不以缩小到不可读的方式塞入单页。
- 技术图无箭头穿框、压字、悬空、错误端点、无意义弯折、交叉或无法区分的重合线。
- 全部插图有可编辑图源；发布PNG具有足够分辨率，并在PPT实际显示尺寸下清晰。
- 至少完成一次全页总览检查和一次修改页放大检查。仅检查源文件结构或文本提取结果不能替代目视检查。
