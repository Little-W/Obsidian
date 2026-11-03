# Agent Studio 设计文档 · 插图重绘修订版

本版保留“设计目标与架构构想”的定位，不根据当前开发进度编排。

## 阅读

解压后打开 `Agent_Studio_设计目标与架构构想.md`。该文件使用相对路径引用 `assets/` 中的 SVG，请不要单独移动 Markdown 而遗漏插图目录。使用 Obsidian、VS Code 或支持 SVG 的 Markdown 阅读器即可查看。

不支持 SVG 的阅读器可打开 `Agent_Studio_设计目标与架构构想_PNG版.md`。两份正文内容一致，仅插图格式不同。`插图预览.html` 可直接在浏览器中离线打开，点击图片即可查看原尺寸 SVG。

## 文件

| 文件 / 目录 | 内容 |
| --- | --- |
| `Agent_Studio_设计目标与架构构想.md` | 修订后的主文档，引用 SVG |
| `Agent_Studio_设计目标与架构构想_PNG版.md` | PNG 兼容阅读版本 |
| `assets/01_*.svg` 至 `08_*.svg` | 八张独立可编辑的矢量图 |
| `assets/01_*.png` 至 `08_*.png` | 1.5 倍尺寸的 PNG 预览 |
| `assets/总览.png` | 八张图的缩略总览 |
| `插图预览.html` | 离线插图浏览页 |
| `diagrams/generate_svg.py` | 全部图形、文本、端口和连接的生成源码 |
| `diagrams/validate_geometry.py` | 连接与文本几何检查脚本 |
| `diagrams/geometry.json` | 节点、端口、折点、文字范围与连接含义 |
| `diagrams/geometry_check.json` | 本次几何检查结果 |
| `diagrams/连线明细.csv` | 每条连接的源、目标、端口、线型和含义 |

## 本次修订

八张图的布局和连接全部重写，不再沿用原先的公共折线路径。节点端口由节点坐标计算，所有控制线采用明确的正交路线，箭头尖端与目标端口重合。箭头采用固定尺寸的 SVG 三角形，不依赖易受线宽和参考点影响的 marker 缩放。

四类图模型不再串接为执行流程；团队授权与交付协议分区表达；返工从 Rework 回到 Ready；等待人工、外部阻塞、取消分别说明恢复条件。SoC 示例使用正式的并行拆分 / AND 汇合节点，各支路有独立返工通道。时序图明确请求方和接收方，工具请求、真实结果持久化及返回由运行服务衔接。

检查结果：8 张图、94 条连接，端点、方向、正交路线、节点穿越、文字相交、文字范围、文字重叠及非预期连线交叉检查均为 0 项问题。另逐图检查了 PNG 渲染结果。几何检查仅验证绘图关系，不是对设计实现或业务正确性的验收。

## 重新生成

SVG 生成采用 Python 标准库。为复现当前文本宽度检查和 PNG 预览，建议安装 Pillow 与 CairoSVG，并在系统中安装支持中文的字体。

```bash
python -m pip install pillow cairosvg
python diagrams/generate_svg.py --png
python diagrams/validate_geometry.py
```

推荐系统字体为 Noto Sans CJK SC。SVG 保留为文本对象，可在 Inkscape 等编辑器中修改；包内未包含或嵌入字体文件。不同系统的替代字体可能改变字宽，换字体后应重新检查。

生成脚本不执行网络请求，也不需要原项目仓库或旧版文档。修改连接应通过节点 `p(side, fraction)` 端口和显式 `via` 折点进行；不要只移动箭头尖端而不更新源、目标定义。
