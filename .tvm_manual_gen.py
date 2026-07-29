from __future__ import annotations

from pathlib import Path
import re
import textwrap


ROOT = Path("/home/yusen/Obsidian Vault/NPU/TVM 使用与自研 NPU 接入手册")
ROOT.mkdir(parents=True, exist_ok=True)

BASE_URL = "https://tvm.apache.org/docs"
GITHUB = "https://github.com/apache/tvm/tree/v0.24.0"
GITHUB_BLOB = "https://github.com/apache/tvm/blob/v0.24.0"


def clean(text: str) -> str:
    terminology = {
        "建议落库位置": "建议的文件存放位置",
        "先定义六份合同": "先明确六类规范",
        "算子合同": "算子规格说明",
        "运算合同": "算子规格说明",
        "数值合同": "数值计算规则",
        "错误合同": "错误处理规范",
        "测试合同": "测试规范",
        "硬件合同": "硬件规格说明",
        "函数合同": "函数调用约定",
        "项目合同": "项目技术规范",
        "舍入合同": "舍入规则",
        "合同最清楚": "规格最明确",
        "合同清楚": "规格明确",
        "同结构不同合同": "结构相同但规格不同",
        "作为不同合同测试": "作为不同规格分别测试",
        "合同需要": "规格说明要求",
        "按合同处理": "按规格说明处理",
        "从合同生成": "根据规格说明生成",
        "合同": "规格说明",
        "operator-contracts": "operator-specs",
        "全景": "整体说明",
        "批维": "批次维度",
        "排布": "布局",
        "轴": "维度",
        "下沉": "逐级转换",
        "首版": "第一版",
        "首个": "第一个",
    }
    for source, target in terminology.items():
        text = text.replace(source, target)
    text = textwrap.dedent(text).strip() + "\n"

    # Translate common explanatory words only in prose.  Fenced code,
    # inline code and Markdown link targets keep their exact spelling.
    in_fence = False
    prose_terms = {
        "Runtime Module": "运行时模块",
        "JSON Runtime": "JSON 运行时",
        "Matrix Engine": "矩阵计算单元",
        "Vector Engine": "向量计算单元",
        "Conv Engine": "卷积计算单元",
        "Activation Engine": "激活计算单元",
        "Pooling Engine": "池化计算单元",
        "Runtime": "运行时",
        "tile": "分块",
        "pipeline": "编译流程",
        "host": "主机",
        "schema": "结构规范",
        "artifact": "编译产物",
        "dtype": "数据类型",
        "shape": "形状",
        "layout": "数据布局",
        "codegen": "代码生成",
        "backend": "后端",
        "frontend": "前端",
        "fallback": "改由其他后端执行",
        "halo": "邻接扩展区",
        "burst": "突发传输",
        "lane": "向量通道",
        "mask": "掩码",
        "head": "注意力头",
        "query": "查询",
        "decode": "解码",
        "token": "词元",
    }
    normalized_lines = []
    for line in text.splitlines():
        if line.lstrip().startswith("```"):
            in_fence = not in_fence
            normalized_lines.append(line)
            continue
        if in_fence:
            normalized_lines.append(line)
            continue
        parts = re.split(r"(`[^`]*`|!?\[\[[^\]]+\]\]|\]\([^)]+\))", line)
        for i in range(0, len(parts), 2):
            for source, target in prose_terms.items():
                parts[i] = re.sub(rf"\b{source}\b", target, parts[i])
                parts[i] = re.sub(
                    rf"(?<=[\u3400-\u9fff]) +{target}", target, parts[i]
                )
                parts[i] = re.sub(
                    rf"{target} +(?=[\u3400-\u9fff])", target, parts[i]
                )
        normalized_lines.append("".join(parts))

    text = "\n".join(normalized_lines) + "\n"
    text = text.replace("主机 编译流程", "主机编译流程")
    text = text.replace("向量向量通道", "向量通道")
    text = text.replace("。。", "。")
    return re.sub(r"\n{3,}", "\n\n", text)


def write(name: str, text: str) -> None:
    (ROOT / name).write_text(clean(text), encoding="utf-8")


def callout(kind: str, title: str, body: str) -> str:
    lines = body.strip().splitlines()
    return f"> [!{kind}] {title}\n" + "\n".join(f"> {line}" if line else ">" for line in lines)


frontmatter = """\
---
tags:
  - TVM
  - NPU
  - 编译器
  - Relax
  - TensorIR
status: maintained
baseline: Apache TVM v0.24.0
updated: 2026-07-29
---
"""


overview = f"""
{frontmatter}
# TVM 使用与自研 NPU 接入手册

{callout("abstract", "手册目标", "这是一套面向初学者、编译器开发者、NPU 架构师、驱动与运行时开发者的分册手册。内容从安装、模型导入和第一个 Relax 程序开始，逐步讲到 IRModule、Relax、TensorIR、调度、Pass、Target、代码生成、运行时、虚拟机，以及如何把自研 NPU 作为外部后端或原生设备加入 TVM。")}

{callout("important", "版本基准", "正文以 Apache TVM v0.24.0（Git 提交 `af3e4ba`）为源码基准，网络资料核对日期为 2026-07-29。网上大量旧文章仍使用 Relay、旧版 `tir` 和早期 BYOC API；照抄旧代码很容易遇到名称、函数签名及目录不一致的问题。")}

## 先给出结论

对大多数已有 NPU，推荐先采用 Relax BYOC：前端与通用图优化仍由 TVM 完成，接纳的子图交给自研编译器或 SDK，不被接纳的节点继续交给 CPU、GPU 或 TVM 自带内核。只有在确实需要让 TensorIR 直接产生 NPU 指令、需要 TVM 统一管理设备内存，或需要把 NPU 当作完整执行设备时，才增加 `TargetKind`、目标代码生成器和 `DeviceAPI`。

```mermaid
flowchart LR
    A["PyTorch / ONNX / TFLite"] --> B["Relax IRModule"]
    B --> C["图级变换"]
    C --> D{{"后端选择"}}
    D -->|BYOC 子图| E["自研 NPU 编译器"]
    D -->|其余节点| F["TVM TIR 内核"]
    E --> G["NPU 运行时模块"]
    F --> H["CPU / GPU Module"]
    G --> I["Relax VM 或应用运行时"]
    H --> I
```

## 阅读路线

| 读者 | 建议顺序 | 读完后的能力 |
| --- | --- | --- |
| 第一次接触 TVM | 01 → 02 → 03 → 04 → 11 → 12 | 能安装、导入模型、查看 IR、编译并运行 |
| 编译器开发者 | 02 → 04 → 05 → 06 → 07 → 14 → 15 → 16 | 能设计图级变换、分区规则与外部代码生成 |
| NPU 架构师 | 02 → 08 → 18 → 19 → 20 → 21 → 算子分册 | 能把硬件能力写成可执行的编译约束 |
| 驱动与固件开发者 | 09 → 10 → 17 → 18 → 19 → 24 | 能实现模块加载、内存、提交、同步与诊断 |
| 验证开发者 | 20 → 21 → 22 → 24 → 实验分册 | 能建立逐层对照、异常测试和性能测量 |

## 分册目录

### 第一部分：TVM 的使用与设计

1. [[01-版本基准与学习准备]]
2. [[02-从模型到可执行文件的完整流程]]
3. [[03-IRModule 与统一对象系统]]
4. [[04-Relax 图级 IR]]
5. [[05-TensorIR 程序表示]]
6. [[06-调度 Tensor Intrin 与自动搜索]]
7. [[07-Pass 基础设施与编译流程]]
8. [[08-Target Device 与代码生成]]
9. [[09-PackedFunc Module 与运行时]]
10. [[10-Relax VM 导出与加载]]
11. [[11-源码构建与第一个程序]]
12. [[12-导入 PyTorch ONNX 与 TFLite]]
13. [[13-DLight MetaSchedule 与性能调优]]

### 第二部分：自研 NPU 接入

14. [[14-接入路线选择与总体设计]]
15. [[15-Relax DPL 子图识别与分区]]
16. [[16-BYOC 代码生成器]]
17. [[17-NPU 运行时与驱动适配]]
18. [[18-原生 TargetKind DeviceAPI 与 TIR 后端]]
19. [[19-命令流 内存规划 与数据排布]]
20. [[20-低比特整数计算与数值规则]]
21. [[21-动态形状 控制流 与异构回退]]
22. [[22-正确性测试与持续集成]]
23. [[23-性能建模与自动调优接入]]
24. [[24-调试 可观测性 与故障定位]]
25. [[25-工程目录 版本策略 与交付计划]]
26. [[26-端到端参考实现骨架]]
27. [[27-从旧版 Relay 迁移到 Relax]]
28. [[28-常见问题]]
29. [[29-官方资料与源码导航]]

### 第三部分：按算子查阅

- [[30-自研 NPU 算子接入分册]]

### 第四部分：动手实验

- [[31-循序渐进实验分册]]

### 第五部分：速查

- [[32-故障速查表]]
- [[33-术语与 API 速查]]
- [[34-评审检查表]]
- [[35-编译流程逐阶段检查手册]]
- [[36-模型家族接入指南]]
- [[37-设计文档与配置模板]]

### 第六部分：BYOC 专题

- [[38-BYOC 官方教程逐步解析]]
- [[39-模式注册与优先级设计]]
- [[40-PatternCheckContext 与能力检查]]
- [[41-FuseOpsByPattern 与组合函数]]
- [[42-MergeCompositeFunctions 与外部函数分组]]
- [[43-RunCodegen 源码解析]]
- [[44-JSONSerializer 与编译产物]]
- [[45-外部运行时模块与调用约定]]
- [[46-常量 动态形状 与缓存]]
- [[47-从 Example NPU 改造成真实后端]]
- [[48-BYOC 分阶段实验]]
- [[49-BYOC 测试 调试 与版本升级]]

## Obsidian 标记说明

| 标记 | 用途 | 阅读建议 |
| --- | --- | --- |
| `> [!abstract]` | 本节摘要 | 第一次阅读先看 |
| `> [!note]` | 补充背景 | 需要时展开 |
| `> [!tip]` | 可直接采用的做法 | 实现时核对 |
| `> [!important]` | 会影响正确性的要求 | 不应跳过 |
| `> [!warning]` | 容易造成错误的做法 | 修改代码前确认 |
| `> [!example]` | 完整或缩小后的例子 | 可复制到实验工程 |
| `> [!question]` | 自测题或设计问题 | 评审前回答 |
| `[[页面名]]` | Vault 内部跳转 | 在 Obsidian 中直接打开 |
| `![[页面名#标题]]` | 嵌入另一页的小节 | 用于聚合专题 |

{callout("tip", "初学者的最短路线", "先完成 [[11-源码构建与第一个程序]]，把 `mod.show()`、`tvm.compile()` 和 VM 调用跑通；随后阅读 [[02-从模型到可执行文件的完整流程]]。看到某个名词不清楚时，用 [[33-术语与 API 速查]] 查找，不必一开始就阅读全部 C++ 源码。")}

## 如何使用这套手册

第一次学习时，建议把“看懂一切”改成“完成一次可观察的编译”。先运行一个只有矩阵乘和激活函数的小模型，依次保存导入后的 Relax、图级变换后的 Relax、生成的 PrimFunc、最终模块信息与运行结果。每保存一个阶段，就回答三个问题：程序的输入和输出是什么，哪一次变换改变了程序，改变后的表示由谁继续处理。这样能够把大量类名和函数名放回实际流程中理解。

阅读 IR 时不要只盯着文本长度。先找函数入口、参数的 `StructInfo`、返回值、数据流块和函数属性，再沿变量定义向前追踪。遇到 `call_tir` 时，转到同一 `IRModule` 中对应的 `PrimFunc`；遇到带 `Codegen` 属性的函数时，转到外部代码生成部分；遇到 `call_dps_packed` 时，确认被调用函数由哪个运行时模块提供。每一种调用形式都表示明确的责任划分。

阅读 Pass 时，应同时准备变换前模块、变换后模块和最小输入。仅看 Pass 名称容易形成错误理解，因为一个 Pass 可能依赖前置规范化，也可能只处理特定表达式形态。使用 `PassContext` 插桩保存每一步 IR，并用结构比较验证预期的局部变化。发现结果不同于预期时，先检查输入是否满足该 Pass 的前置条件，再检查 Pass 顺序和配置项。

开发 NPU 后端时，把模型拆成逐级增加难度的集合。第一组只包含单个运算，验证属性读取、形状与数据类型；第二组验证常见组合；第三组验证多个子图、主机回退和跨设备数据传递；第四组加入动态尺寸、控制流和真实网络。每组都保留固定输入、参考输出、编译日志和产物摘要。出现差异时，可以快速确认问题属于模型导入、图变换、NPU 编译器、运行时还是驱动。

硬件能力不要散落在模式检查、代码生成和运行时代码中。把数据类型、布局、维度范围、对齐、片上存储容量、指令版本和固件要求整理成有版本的能力描述，并由各组件读取同一份信息。静态检查负责拒绝无法证明可执行的子图，运行时负责再次核对设备能力与产物要求。错误信息应指出具体函数、运算、属性与硬件限制，不能只返回一个失败状态。

做性能分析时，先区分编译时间、首次运行准备时间和稳定运行时间。运行阶段再拆分为主机准备、数据传输、设备执行、同步等待和结果回读。模型总体时延下降很少时，不要立即修改调度；先确认 NPU 实际接纳了多少计算、设备间复制是否过多、命令提交是否被频繁同步。只有测量项足够清楚，优化选择才有依据。

每次升级 TVM 都应重跑最小模型集，并比较注册名、Pass 输入形态、函数属性、导出格式与运行时加载行为。发布版之间可能移动源文件或调整推荐 API，因此本手册把版本号、提交号和在线资料日期写在首页。项目内若使用其他提交，应先阅读发布说明和相关测试，再对手册中的代码片段作相应调整。

建议在每章末尾记录自己的答案和实验结果，但不要直接改写基准说明。可以新建项目专用页面，通过 Obsidian 内部链接指向本手册，再写入芯片型号、工具版本、模型名称、失败原因和解决办法。基准资料与项目记录分开维护后，团队既能共享稳定知识，也能保留每次开发活动的真实条件。

## 本地 NPU 资料连接

- [[NPU 指令与硬件架构设计 Spec]]
- [[NPU 验证：从 BT 到算子]]
- [[分块矩阵外积数据流]]
- [[面向Transformer和LSTM加速的NPU设计目标]]

这些资料定义本地硬件、指令、存储和验证背景。本手册不假定某个具体 RTL 参数已经固定；接入时应以能力寄存器、编译配置和目标描述共同提供的数值为准。

## 完成标准

当下列结果都能稳定复现时，可认为首版接入已经可用：

1. 同一模型在参考后端与 NPU 后端的输出满足各数据类型的误差要求；
2. 编译日志能说明每个子图为何进入 NPU 或保留在主机；
3. 编译产物可独立导出、重新加载并多次运行；
4. 驱动能报告提交、完成、超时和硬件错误；
5. 非整 tile、空尺寸、极值、动态尺寸和不被支持的算子都有明确处理；
6. 端到端时延、数据搬运时间和各执行单元利用率可被测量；
7. 源码版本、构建选项、模型散列值、编译配置和固件版本可追溯。
"""
write("00-目录.md", overview)


chapter_specs = [
    {
        "no": "01",
        "title": "版本基准与学习准备",
        "summary": "解释 v0.24.0 与旧教程的差异，建立可复现环境，并给出阅读源码的方法。",
        "mental": "把 TVM 看成一组可组合的 IR 变换与运行时模块，而不是一个只能按固定命令使用的黑盒工具。",
        "points": [
            "主线 IR 是 Relax 与 TensorIR；v0.24.0 将旧 `tir` 代码组织拆成 `tirx` 与 `s_tir`。",
            "Python 用于组织编译流程，C++ 实现大量核心数据结构、变换、代码生成与运行时。",
            "编译主机与执行设备可以不同，因此所有硬件特征都应由 Target 或编译配置显式提供。",
            "版本号、提交号、LLVM 版本、构建开关和 Python 环境必须一起记录。",
        ],
        "actions": [
            "固定 TVM tag 或 commit，不在同一项目中混用 main 分支与发布版二进制。",
            "保存 `tvm.support.libinfo()` 输出，确认 Python 包加载的是预期的动态库。",
            "阅读 API 时先看当前版本文档，再用 `rg` 找注册名和测试。",
            "为自研后端建立最小模型集，避免首次联调就使用完整大模型。",
        ],
        "sources": [
            ("官方源码安装说明", f"{BASE_URL}/install/from_source.html"),
            ("v0.24.0 发布源码", "https://github.com/apache/tvm/releases/tag/v0.24.0"),
            ("设计与架构", f"{BASE_URL}/arch/index.html"),
        ],
        "pitfalls": [
            "旧文章常用 `relay.build`、旧 Pass 名称或旧目录，不能据此判断当前源码缺少功能。",
            "只记录 `pip freeze` 不足以复现本地构建，CMake 开关和本机 LLVM 同样重要。",
            "编译成功不等于运行设备可见；设备探测属于运行时检查。",
        ],
    },
    {
        "no": "02",
        "title": "从模型到可执行文件的完整流程",
        "summary": "从模型导入开始，解释图级变换、算子下沉、TensorIR、目标翻译、模块打包和运行。",
        "mental": "IRModule 是贯穿流程的工程容器；Relax 函数描述图与控制，PrimFunc 描述具体张量程序，runtime.Module 保存可运行函数。",
        "points": [
            "模型前端创建含 Relax 函数的 IRModule，并可把参数作为常量或函数参数。",
            "图级 Pass 完成常量折叠、布局调整、组合运算识别、未使用代码删除等工作。",
            "`LegalizeOps` 把高层算子改写为 `call_tir` 或外部函数调用。",
            "TensorIR 继续进行循环、缓冲区、线程和硬件指令相关处理。",
            "代码生成结果放入 runtime.Module，并与 VM 字节码和常量共同组成可执行对象。",
        ],
        "actions": [
            "在每个关键 Pass 后保存 `mod.script()`，用结构比较定位第一次出现差异的位置。",
            "把主机 Target 与设备 Target 分开描述，避免交叉编译时使用主机自动探测结果。",
            "在 NPU 分区前先完成必要的图规范化，使等价写法呈现为稳定结构。",
            "将编译与执行分成两个测试，以确认导出文件没有依赖编译进程内的临时状态。",
        ],
        "sources": [
            ("架构总览", f"{BASE_URL}/arch/index.html"),
            ("快速开始", f"{BASE_URL}/get_started/tutorials/quick_start.html"),
            ("代码生成", f"{BASE_URL}/arch/codegen.html"),
        ],
        "pitfalls": [
            "把 Relax VM 当作数学计算引擎会造成错误理解；计算由 TIR 内核或外部函数完成。",
            "只看最终汇编无法解释图分区问题，应从导入后的 Relax 开始检查。",
            "先做图融合再注册更具体的 NPU 组合运算，可能使所需结构消失。",
        ],
    },
    {
        "no": "03",
        "title": "IRModule 与统一对象系统",
        "summary": "说明 IRModule、GlobalVar、Function、StructInfo、结构相等、反射、序列化和 FFI 的关系。",
        "mental": "IRModule 类似一个可被编译器反复改写的程序包，内部函数可以属于不同 IR，但通过统一的类型、属性和全局名称互相调用。",
        "points": [
            "`IRModule` 保存全局函数、类型定义、全局信息与模块属性。",
            "`relax.Function` 与 `tirx.PrimFunc` 可以共存，调用约定让图级函数调用张量内核。",
            "结构相等比较程序结构而非 Python 对象地址，适合 Pass 单元测试。",
            "Object 系统提供反射、属性访问、散列和跨语言传递。",
            "全局注册表把 Python、编译器 C++ 与运行时 C++ 的函数接在一起。",
        ],
        "actions": [
            "为每个外部函数设置稳定且唯一的 `global_symbol`。",
            "单元测试同时检查结构与数值，避免只比较打印文本。",
            "修改节点时使用 BlockBuilder、Mutator 或标准 Pass，不直接改不可变对象字段。",
            "为自研属性设计清晰名称空间，防止与 TVM 内置属性重名。",
        ],
        "sources": [
            ("IRModule 入门", f"{BASE_URL}/get_started/tutorials/ir_module.html"),
            ("TVMScript 架构", f"{BASE_URL}/arch/tvmscript.html"),
            ("运行时系统", f"{BASE_URL}/arch/runtime.html"),
        ],
        "pitfalls": [
            "打印结果相同不保证结构完全相同，隐藏属性可能影响后续 Pass。",
            "全局符号重复会在打包或加载阶段才暴露，定位成本较高。",
            "把 Python 字典当作稳定二进制协议，会造成版本兼容问题。",
        ],
    },
    {
        "no": "04",
        "title": "Relax 图级 IR",
        "summary": "解释 Relax 表达式、数据流块、StructInfo、符号尺寸、函数属性和图级改写。",
        "mental": "Relax 关注要计算什么、张量之间如何依赖、形状与数据类型已知到什么程度；它不要求过早决定每个循环如何执行。",
        "points": [
            "`Var`、`DataflowVar`、`Call`、`Tuple`、`If`、`SeqExpr` 组成 Relax 程序。",
            "`StructInfo` 保存形状、类型、设备等可静态推断的信息。",
            "`R.dataflow()` 内部值主要供局部计算，`R.output()` 把需要的值带到块外。",
            "`call_tir` 调用 PrimFunc，`call_dps_packed` 调用采用目标缓冲区风格的外部函数。",
            "规范化与推断应在自定义改写后执行，保证后续 Pass 获得一致信息。",
        ],
        "actions": [
            "先用 TVMScript 写最小 Relax 模块，再对照前端导入结果。",
            "检查组合运算时同时查看调用属性、输入 StructInfo 和常量信息。",
            "将硬件接纳条件放入纯函数，便于单测和日志解释。",
            "不确定形状应显式保留符号变量，不用任意常数代替。",
        ],
        "sources": [
            ("Relax 深入说明", f"{BASE_URL}/deep_dive/relax/index.html"),
            ("Relax DPL", f"{BASE_URL}/deep_dive/relax/dpl.html"),
            ("Relax Python API", f"{BASE_URL}/reference/api/python/relax/relax.html"),
        ],
        "pitfalls": [
            "把数据流块外的普通变量与块内 DataflowVar 混为一谈，会影响改写有效性。",
            "只按算子名接纳子图会忽略 dtype、轴、布局、广播和动态尺寸。",
            "自定义 Pass 返回未规范化表达式时，错误常在很后面的阶段才出现。",
        ],
    },
    {
        "no": "05",
        "title": "TensorIR 程序表示",
        "summary": "从 PrimFunc、Buffer、循环、SBlock、归约轴和内存区域理解低层张量程序。",
        "mental": "TensorIR 把一个算子展开为带有循环与缓冲区访问的程序，并保留足够的结构信息供调度器安全地改变执行次序。",
        "points": [
            "`PrimFunc` 是可独立编译的低层函数，参数通常对应缓冲区或标量。",
            "`Buffer` 描述形状、数据类型、步长、偏移和存储区域。",
            "`SBlock` 标出读取、写入、迭代轴和归约关系，是调度分析的核心。",
            "初始化块与归约更新必须被正确识别，才能进行归约拆分和局部累加。",
            "动态尺寸可以出现在循环范围和缓冲区形状中，但硬件后端必须说明接受范围。",
        ],
        "actions": [
            "为矩阵单元先写一个清晰、未优化的 PrimFunc，再逐步施加调度。",
            "使用 `reads` 与 `writes` 检查访问区域是否符合预期。",
            "对非整 tile 保留保护条件或填充策略，并把选择写入测试。",
            "在引入硬件内建函数前保存调度 trace，便于复现。",
        ],
        "sources": [
            ("TensorIR 总览", f"{BASE_URL}/deep_dive/tensor_ir/index.html"),
            ("TensorIR 变换教程", f"{BASE_URL}/deep_dive/tensor_ir/tutorials/tir_transformation.html"),
            ("TensorIR API", f"{BASE_URL}/reference/api/python/s_tir/schedule.html"),
        ],
        "pitfalls": [
            "循环长得相似不表示可随意交换；依赖关系与归约性质必须满足要求。",
            "缓存区作用域名称必须与代码生成器和运行时对存储区域的理解一致。",
            "只测试 tile 整除尺寸会遗漏尾部写越界和累加缺项。",
        ],
    },
    {
        "no": "06",
        "title": "调度 Tensor Intrin 与自动搜索",
        "summary": "说明调度原语、调度 trace、Tensor Intrin、DLight 和 MetaSchedule 各自负责什么。",
        "mental": "计算定义说明结果是什么，调度说明如何组织循环和存储；Tensor Intrin 再把特定小块计算替换成硬件指令或外部内建函数。",
        "points": [
            "`split`、`reorder`、`fuse`、`compute_at`、`cache_read`、`cache_write` 改变程序组织。",
            "`tensorize` 要求目标块与 Tensor Intrin 描述的计算结构一致。",
            "调度 trace 是一串可重放的决定，可用于数据库保存与问题复现。",
            "DLight 使用规则快速给出可用调度，MetaSchedule 搜索并在真实设备测量候选。",
            "自研 NPU 可以把 tile 尺寸、片上容量、对齐和并行度写入规则与搜索空间。",
        ],
        "actions": [
            "先固定一个可证明正确的基础调度，再增加搜索自由度。",
            "将硬件不允许的组合从设计空间生成阶段排除，减少无效编译。",
            "Runner 必须在真实 NPU 或可信周期模型上测量，不用主机时间替代。",
            "记录编译失败候选的原因，区分非法调度与设备执行失败。",
        ],
        "sources": [
            ("TensorIR 变换", f"{BASE_URL}/deep_dive/tensor_ir/tutorials/tir_transformation.html"),
            ("MetaSchedule", f"{BASE_URL}/deep_dive/tensor_ir/tutorials/meta_schedule.html"),
            ("自定义优化", f"{BASE_URL}/how_to/tutorials/customize_opt.html"),
        ],
        "pitfalls": [
            "只追求最短单次时间会选中波动大或偶然受缓存影响的候选。",
            "Tensor Intrin 的描述函数与实现函数若在 dtype 或步长上不同，结果可能静默错误。",
            "搜索数据库未包含固件和硬件版本时，旧记录可能被错误复用。",
        ],
    },
    {
        "no": "07",
        "title": "Pass 基础设施与编译流程",
        "summary": "解释 ModulePass、FunctionPass、PassContext、Sequential、依赖与插桩。",
        "mental": "每个 Pass 都应接收一种清楚的程序状态，产生另一种清楚的程序状态；完整编译是这些小变换按约定顺序组合。",
        "points": [
            "Pass 可以作用于模块、函数或更低层结构，并可声明所需前置变换。",
            "`PassContext` 控制优化级别、配置、禁用项和插桩。",
            "`Sequential` 让项目定义自己的可审计流水，而不是依赖隐式默认顺序。",
            "分析结果应有明确失效规则，程序被改写后不能继续使用过期信息。",
            "NPU 分区通常放在通用规范化之后、可能破坏组合结构的融合之前。",
        ],
        "actions": [
            "为流水各阶段命名并输出 IR 快照散列值。",
            "自定义 Pass 在空模块、无匹配、动态尺寸和重复执行时都应稳定。",
            "用 PassInstrument 记录耗时、IR 大小和外部函数数量。",
            "把接入流程写成一个可调用 pipeline，供 CLI、测试和服务共用。",
        ],
        "sources": [
            ("Pass 架构", f"{BASE_URL}/arch/pass_infra.html"),
            ("Relax 变换 API", f"{BASE_URL}/reference/api/python/relax/transform.html"),
            ("算子融合", f"{BASE_URL}/arch/fusion.html"),
        ],
        "pitfalls": [
            "Pass 顺序改变可能使匹配数量变化，不能只看每个 Pass 的局部测试。",
            "在全局可变对象中保存分析结果会污染并行编译。",
            "把所有工作塞进一个大型 Pass 会使定位、复用和单测都变困难。",
        ],
    },
    {
        "no": "08",
        "title": "Target Device 与代码生成",
        "summary": "区分编译期 Target、运行期 Device、主机代码生成与设备代码生成。",
        "mental": "Target 是给编译器看的硬件说明书，Device 是运行时操作某个实际设备的句柄，两者相互关联但不是同一个对象。",
        "points": [
            "Target 属性保存架构、能力、库和编译选项，Pass 与代码生成器都可读取。",
            "DeviceAPI 负责内存、复制、流、同步和设备属性查询。",
            "目标构建函数以 `target.build.<kind>` 注册，输入 IRModule 与 Target，输出 runtime.Module。",
            "主机模块可以导入设备模块，导出时一起打包。",
            "交叉编译时不可从编译主机猜测 NPU 属性。",
        ],
        "actions": [
            "把阵列尺寸、片上容量、对齐、支持 dtype 和固件 ABI 作为版本化目标信息。",
            "区分可由用户覆盖的调优参数与不可违反的硬件限制。",
            "为 Target 字符串、JSON 配置和目标标签编写解析测试。",
            "只有在需要 TVM 直接管理 NPU 设备资源时才实现完整 DeviceAPI。",
        ],
        "sources": [
            ("Device 与 Target 交互", f"{BASE_URL}/arch/device_target_interactions.html"),
            ("Target API", f"{BASE_URL}/reference/api/python/target.html"),
            ("代码生成架构", f"{BASE_URL}/arch/codegen.html"),
        ],
        "pitfalls": [
            "把运行时设备查询放入代码生成器会破坏远程编译与构建复现。",
            "同名 Target 属性若在不同固件版本中改变含义，会导致旧缓存不可用。",
            "设备内存复制若默认同步，可能隐藏并发能力并造成时延误判。",
        ],
    },
    {
        "no": "09",
        "title": "PackedFunc Module 与运行时",
        "summary": "说明 PackedFunc、runtime.Module、Tensor、DLPack、全局注册和最小部署运行时。",
        "mental": "PackedFunc 是统一调用接口，Module 是一组可查询函数及其被导入模块，Tensor 是带设备和形状信息的数据容器。",
        "points": [
            "PackedFunc 用类型擦除方式跨 Python、C++ 与其他语言传递常见对象。",
            "编译器 API 与生成后的函数都使用同一注册和调用机制。",
            "runtime.Module 可按名称取得函数、导入其他模块、保存并重新加载。",
            "DLPack 允许与 PyTorch 等框架共享张量，是否零复制取决于设备与所有权条件。",
            "部署端可只链接较小的 TVM runtime，而不带完整编译器。",
        ],
        "actions": [
            "把 NPU 提交接口包装成粗粒度 PackedFunc，避免每个标量运算都跨接口调用。",
            "规定 Tensor 所有权、生命周期、对齐和缓存维护责任。",
            "实现模块的二进制保存与加载，并在新进程中测试。",
            "为每个全局注册函数添加存在性检查和清晰错误信息。",
        ],
        "sources": [
            ("TVM 运行时系统", f"{BASE_URL}/arch/runtime.html"),
            ("模块序列化", f"{BASE_URL}/arch/introduction_to_module_serialization.html"),
            ("runtime Python API", f"{BASE_URL}/reference/api/python/runtime/runtime.html"),
        ],
        "pitfalls": [
            "返回指向临时内存的 Tensor 会在异步执行时产生难以复现的错误。",
            "运行时模块未实现保存函数时，内存内执行成功但导出失败。",
            "函数名注册成功不表示参数协议正确，必须做类型与数量检查。",
        ],
    },
    {
        "no": "10",
        "title": "Relax VM 导出与加载",
        "summary": "解释 Relax VM 字节码、TIR 本地函数、常量、寄存器、控制指令和可执行对象。",
        "mental": "VM 负责函数调用与控制流程，真正的张量计算由已经编译好的内核或外部模块执行。",
        "points": [
            "默认字节码模式使用 `Call`、`Ret`、`Goto`、`If` 组织执行。",
            "编译模式可把 VM 控制改成 TIR，以减少解释分派开销，但会增加代码量。",
            "VMExecutable 组合字节码、常量池与本地或外部模块。",
            "多设备调用需要明确每个 Tensor 所在设备与复制位置。",
            "状态型调用和普通纯函数调用的生命周期不同。",
        ],
        "actions": [
            "先用字节码模式调试，再评估是否需要编译模式。",
            "导出后在干净进程加载，确认外部 NPU 模块也被恢复。",
            "用 VM 的计时接口测量设备执行，排除网络传输。",
            "控制流模型要分别覆盖两个分支和循环极端次数。",
        ],
        "sources": [
            ("Relax VM 架构", f"{BASE_URL}/arch/relax_vm.html"),
            ("导出与加载", f"{BASE_URL}/how_to/tutorials/export_and_load_executable.html"),
            ("交叉编译与 RPC", f"{BASE_URL}/how_to/tutorials/cross_compilation_and_rpc.html"),
        ],
        "pitfalls": [
            "只序列化主机模块而遗漏外部 NPU 模块，会在加载后找不到函数。",
            "在主机计时器中包含 RPC 传输会高估设备执行时间。",
            "将动态分支错误地在编译期固定，会使部分输入得到错误结果。",
        ],
    },
]


def render_chapter(spec: dict) -> str:
    src_rows = "\n".join(f"| [{name}]({url}) | 官方资料 |" for name, url in spec["sources"])
    point_rows = "\n".join(f"{i}. {x}" for i, x in enumerate(spec["points"], 1))
    action_rows = "\n".join(f"- [ ] {x}" for x in spec["actions"])
    pit_rows = "\n".join(f"- {x}" for x in spec["pitfalls"])
    detail_guides = [
        "阅读时先定位产生该信息的函数，再查找消费它的下一阶段。把两处代码和中间 IR 放在一起观察，比单独记忆类名更容易理解。",
        "把变换前后的 IR 并排比较，重点查看函数参数、调用、属性、StructInfo 和返回值。只记录最终 IR 会丢失变化发生的位置。",
        "实现时将硬件固定限制放入 Target 或能力文件，把用户可选策略放入编译配置；二者发生冲突时应报告具体字段。",
        "测试至少包含一个正常样本和一个只改变单一条件的反向样本。这样，结构或结果变化时能直接找到对应规则。",
        "保存可由工具读取的阶段报告，其中包含输入摘要、输出摘要、Pass 配置、Target、耗时和错误；文本日志用于辅助阅读。",
    ]
    detail_sections = []
    for i, point in enumerate(spec["points"], 1):
        action = spec["actions"][(i - 1) % len(spec["actions"])]
        pit = spec["pitfalls"][(i - 1) % len(spec["pitfalls"])]
        guide = detail_guides[(i - 1) % len(detail_guides)]
        detail_sections.append(
            f"""\
### {i}. {point.split('，')[0]}

{point}

{guide}

**实现建议：** {action}

{callout("warning", "本小节常见问题", pit)}
"""
        )
    details = "\n".join(detail_sections)
    return f"""
{frontmatter}
# {spec['no']}. {spec['title']}

{callout("abstract", "本章内容", spec["summary"])}

## 一句话理解

{spec["mental"]}

## 核心要点

{point_rows}

```mermaid
flowchart LR
    A["输入程序状态"] --> B["分析信息"]
    B --> C["本章所述处理"]
    C --> D["输出程序状态"]
    D --> E["日志与可复现记录"]
```

## 逐项解析

{details}

## 实施清单

{action_rows}

## 设计评审问题

1. 本阶段接收哪一种 IR，要求哪些属性已经存在？
2. 本阶段产生哪些新函数、属性、常量或模块？
3. 遇到不被支持的输入时，是保留给其他后端、报告编译错误，还是插入转换？
4. 哪些配置属于硬件固定限制，哪些配置允许自动搜索？
5. 如何证明重复执行本阶段不会产生额外变化？
6. 如何在日志中解释每个重要决定？

## 自测

{callout("question", "请先独立回答", "把一个两层 MLP 的 IR 在本章处理前后分别打印出来，指出函数数量、调用形式、张量类型和模块属性发生了什么变化。如果无法运行代码，可先画出预期结构，再与实际输出比较。")}

## 参考资料

| 资料 | 类型 |
| --- | --- |
{src_rows}

## 章末小结

本章的重点不是记住所有类名，而是明确输入状态、处理动作、输出状态和失败处理。接入自研 NPU 时，每一层都应保留可检查的中间结果，使图分区、代码生成、设备提交和数值对照可以分别验证。
"""


for spec in chapter_specs:
    write(f"{spec['no']}-{spec['title']}.md", render_chapter(spec))


more_chapter_specs = [
    {
        "no": "11",
        "title": "源码构建与第一个程序",
        "summary": "给出 Linux 上的源码构建、环境确认、最小 Relax 模型、编译、运行和排错步骤。",
        "mental": "首次构建的目标是建立可信工具环境，不是立即打开所有后端；最小配置稳定后再逐项增加自研模块。",
        "points": [
            "v0.24.0 要求 CMake 3.24 或更高版本、Python 3.10 或更高版本，并建议 LLVM 15 或更新版本。",
            "使用 SSH 与 `--recursive` 取得源码，确保子模块与主仓库提交一致。",
            "`config.cmake` 决定编译器、运行时和第三方后端是否进入动态库。",
            "`tvm-ffi` 与 TVM Python 包都必须指向当前构建。",
            "最小程序应覆盖创建 IRModule、运行 pipeline、编译、建立 VM 和读取结果。",
        ],
        "actions": [
            "使用 `git clone --recursive git@github.com:apache/tvm.git` 并切到固定 tag。",
            "先启用 LLVM，关闭暂时不用的 GPU 与外部库。",
            "运行 `tvm.support.libinfo()` 保存实际构建信息。",
            "使用 NumPy 对照输出并打印 `mod.script()`。",
            "为后端 CMake 开关编写存在性检查。",
        ],
        "sources": [
            ("源码安装", f"{BASE_URL}/install/from_source.html"),
            ("快速开始", f"{BASE_URL}/get_started/tutorials/quick_start.html"),
            ("TVM v0.24.0", "https://github.com/apache/tvm/tree/v0.24.0"),
        ],
        "pitfalls": [
            "系统中多个 `libtvm` 并存时，Python 可能加载到旧库。",
            "遗漏子模块有时到链接阶段才报错。",
            "把目标设备交叉编译器设为构建 TVM 本体的 C++ 编译器，通常不是所需做法。",
        ],
    },
    {
        "no": "12",
        "title": "导入 PyTorch ONNX 与 TFLite",
        "summary": "说明三类常见前端、参数处理、动态尺寸、未被支持的运算和导入后核对。",
        "mental": "前端导入不是文件格式转换结束点，而是建立可信 Relax 程序的第一步；导入后必须检查结构和数值。",
        "points": [
            "PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。",
            "ONNX 使用 `from_onnx`，可用 `shape_dict` 固定所需输入尺寸。",
            "TFLite 适合已有移动端模型，但需要关注布局与内置算子版本。",
            "参数可嵌入模块，也可保留为函数参数后用 `detach_params` 分离。",
            "未被支持的 PyTorch 运算可通过 `custom_convert_map` 增加转换函数。",
        ],
        "actions": [
            "在源框架 `.eval()` 状态下导出推理模型。",
            "保存输入名称、形状、dtype、动态范围和 opset。",
            "导入后先用最小 pipeline 在 CPU 对照结果。",
            "列出 Relax 算子集合，再与 NPU 能力表逐项比较。",
            "为每个自定义前端转换编写单算子测试。",
        ],
        "sources": [
            ("模型导入教程", f"{BASE_URL}/how_to/tutorials/import_model.html"),
            ("端到端优化", f"{BASE_URL}/how_to/tutorials/e2e_opt_model.html"),
            ("Relax 前端 API", f"{BASE_URL}/reference/api/python/relax/frontend.html"),
        ],
        "pitfalls": [
            "训练状态的 BatchNorm 与 Dropout 会使对照结果不稳定。",
            "ONNX 输入名与实际模型输入名不一致时，尺寸覆盖不会生效。",
            "把所有参数嵌入常量会增加 IR 打印体积，也可能妨碍权重复用。",
        ],
    },
    {
        "no": "13",
        "title": "DLight MetaSchedule 与性能调优",
        "summary": "对比规则调度与搜索调度，说明任务提取、候选构建、设备测量、数据库和结果复用。",
        "mental": "DLight 快速给出合理方案，MetaSchedule 用更多编译与测量时间寻找更快方案；两者都建立在正确的 TensorIR 与可信测量之上。",
        "points": [
            "DLight 适合快速基线和未调优任务的默认处理。",
            "MetaSchedule 由任务、TuneContext、空间生成器、搜索策略、代价模型、Builder、Runner 和数据库组成。",
            "数据库保存工作负载结构、调度 trace 与测量时间。",
            "RPC Runner 可在远程设备执行候选，主机负责生成和编译。",
            "自研 NPU 若采用 BYOC 图编译，可在自研编译器内部调优，也可为 TIR 路线增加规则。",
        ],
        "actions": [
            "先验证每个候选的数值，再纳入性能比较。",
            "测量前预热并使用多次重复，保存分布而非单个最小值。",
            "数据库键加入硬件、固件、编译器和目标配置版本。",
            "对未找到记录的任务提供基础调度或主机处理。",
            "把片上容量、指令限制和对齐要求写入候选生成。",
        ],
        "sources": [
            ("MetaSchedule", f"{BASE_URL}/deep_dive/tensor_ir/tutorials/meta_schedule.html"),
            ("自定义优化", f"{BASE_URL}/how_to/tutorials/customize_opt.html"),
            ("交叉编译与 RPC", f"{BASE_URL}/how_to/tutorials/cross_compilation_and_rpc.html"),
        ],
        "pitfalls": [
            "候选在主机上编译成功不表示 NPU 固件接受命令。",
            "使用旧数据库但不核对硬件版本会得到无效调度。",
            "测量时间包含日志打印时，排序结果可能反映日志量而非计算速度。",
        ],
    },
    {
        "no": "23",
        "title": "性能建模与自动调优接入",
        "summary": "建立计算、片外访问、片上搬运、提交和同步的时间模型，并说明如何把 NPU 测量接入搜索。",
        "mental": "端到端时延由多个部分组成，单看运算次数或峰值吞吐不能解释真实表现。",
        "points": [
            "屋顶线模型可帮助判断任务主要受算力还是带宽限制。",
            "tile 选择会同时影响复用、片上占用、尾部开销和并行度。",
            "组合运算减少中间写回，但也可能增加片上同时存活数据。",
            "异步执行需要分别测量提交、排队、设备执行和等待。",
            "搜索 Runner 应返回稳定时间与明确错误类别。",
        ],
        "actions": [
            "为每个外部函数统计输入输出字节、MAC 数、命令数和估计 tile 数。",
            "从设备计数器读取周期、忙碌周期、读写字节和停顿原因。",
            "分别建立冷启动与稳态测试。",
            "用真实常见尺寸训练代价模型，不只用规则方阵。",
            "保留基础方案，调优记录不可用时仍能编译。",
        ],
        "sources": [
            ("MetaSchedule", f"{BASE_URL}/deep_dive/tensor_ir/tutorials/meta_schedule.html"),
            ("自定义优化", f"{BASE_URL}/how_to/tutorials/customize_opt.html"),
            ("RPC 教程", f"{BASE_URL}/how_to/tutorials/cross_compilation_and_rpc.html"),
        ],
        "pitfalls": [
            "只报告 TOPS 利用率会忽略外部函数之间的数据搬运。",
            "预热次数不足会把频率提升和缓存填充算入结果。",
            "把失败候选记成极大时间而不保存原因，会掩盖生成器缺陷。",
        ],
    },
    {
        "no": "24",
        "title": "调试 可观测性 与故障定位",
        "summary": "给出从导入、分区、代码生成、打包、加载、提交到设备完成的逐层定位方法。",
        "mental": "先确定错误第一次出现在哪一层，再检查该层输入与输出；不要从最终错误码同时猜测所有阶段。",
        "points": [
            "编译日志应列出候选子图、接纳结果和拒绝原因。",
            "代码生成日志应包含外部函数名、输入输出、数据排布、工作区和命令摘要。",
            "运行时日志应含模块版本、设备、提交序号、事件和错误寄存器。",
            "IR 快照、命令反汇编与参考输出是三类互补证据。",
            "最小失败模型可显著缩短定位时间。",
        ],
        "actions": [
            "为每个编译阶段保存带序号的 IR 文件。",
            "给每个外部函数生成稳定散列值并贯穿日志。",
            "实现命令流离线解析器，禁止只以十六进制转储作为诊断。",
            "错误发生后保存首个失败 tile 的输入、预期输出和实际输出。",
            "为超时、设备复位和驱动返回码建立统一错误分类。",
        ],
        "sources": [
            ("TVM 错误指南", f"{BASE_URL}/errors.html"),
            ("Pass 基础设施", f"{BASE_URL}/arch/pass_infra.html"),
            ("运行时系统", f"{BASE_URL}/arch/runtime.html"),
        ],
        "pitfalls": [
            "日志只写成功或失败，无法解释图为何未进入 NPU。",
            "多个异步任务复用同一临时缓冲区会产生偶发错误。",
            "错误后继续读取已失效输出，会制造二次症状。",
        ],
    },
    {
        "no": "25",
        "title": "工程目录 版本策略 与交付计划",
        "summary": "给出后端源码布局、组件责任、ABI 版本、测试资产和分阶段交付建议。",
        "mental": "可维护后端应把图规则、编译器、运行时、驱动协议和测试分开，同时使用一个明确版本集合确认相互兼容。",
        "points": [
            "Python 目录保存 Relax 组合运算与流水入口，C++ 编译器目录保存外部代码生成。",
            "运行时目录只依赖部署所需组件，不应带入模型前端与完整编译器。",
            "命令格式、模块二进制、驱动 ioctl 和固件能力都需要版本字段。",
            "测试资产应按单运算、组合运算、子图、模型和系统压力分层。",
            "每个阶段都应有可运行产物，不等待全部算子完成后才开始集成。",
        ],
        "actions": [
            "以 Example NPU 目录为起点复制结构，但重新实现空壳逻辑。",
            "为各组件指定维护人和公开输入输出协议。",
            "发布产物附带源码提交、工具版本、能力表和已知限制。",
            "首版选择少量高收益组合运算并提供主机处理。",
            "在 CI 中同时构建编译器版与仅运行时版。",
        ],
        "sources": [
            ("Example NPU Python 目录", f"{GITHUB}/python/tvm/relax/backend/contrib/example_npu"),
            ("Example NPU 编译器", f"{GITHUB}/src/relax/backend/contrib/example_npu"),
            ("Example NPU 运行时", f"{GITHUB}/src/runtime/contrib/example_npu"),
        ],
        "pitfalls": [
            "编译器与固件各自升级但没有兼容表，会出现难以解释的设备拒绝。",
            "仅运行时构建意外链接完整编译器，会增大部署体积。",
            "项目只有端到端模型测试时，任一失败都难以定位。",
        ],
    },
    {
        "no": "27",
        "title": "从旧版 Relay 迁移到 Relax",
        "summary": "帮助读者识别 Relay 时代文档与 v0.24.0 Relax 主线的对应概念，避免机械替换 API。",
        "mental": "迁移不是改导入语句，而是重新确认前端、IR、分区属性、代码生成入口和执行器的完整流程。",
        "points": [
            "旧 BYOC 文档常以 Relay Function、AnnotateTarget 和 PartitionGraph 为中心。",
            "当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。",
            "旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。",
            "旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。",
            "已有 Relay 后端可保留一段兼容期，但新功能应在 Relax 路线实现。",
        ],
        "actions": [
            "先为旧后端建立现有行为测试，再逐项替换。",
            "把旧算子白名单改写成带形状、dtype 和属性检查的 FusionPattern。",
            "把旧 JSON Runtime 所需字段与新序列化器输出逐项对照。",
            "用同一模型比较旧后端与 Relax 后端的子图数量和结果。",
            "文档明确标注支持的 TVM tag。",
        ],
        "sources": [
            ("当前 BYOC 教程", f"{BASE_URL}/how_to/tutorials/bring_your_own_codegen.html"),
            ("外部库分派", f"{BASE_URL}/arch/external_library_dispatch.html"),
            ("旧 BYOC 博文", "https://tvm.apache.org/2020/07/15/how-to-bring-your-own-codegen-to-tvm"),
        ],
        "pitfalls": [
            "把 Relay Pass 名直接替换成相似 Relax 名，可能改变处理次序。",
            "旧运行时函数注册名若继续保留，容易与新模块同时加载时冲突。",
            "只迁移编译器而不迁移导出加载测试，会遗漏模块保存问题。",
        ],
    },
    {
        "no": "28",
        "title": "常见问题",
        "summary": "集中回答安装、IR、分区、外部代码生成、运行时、动态尺寸、数值和性能方面的常见疑问。",
        "mental": "先按阶段分类，再依据 IR、模块和设备证据回答；不要把所有问题都归因于硬件或 TVM。",
        "points": [
            "模型能在 CPU 运行但 NPU 无子图，通常先检查图结构与接纳函数。",
            "分区成功但 RunCodegen 找不到函数，通常检查注册名和构建开关。",
            "内存内运行成功但导出失败，通常检查 Module 保存与加载注册。",
            "小尺寸更慢，可能是提交和复制固定开销占比过高。",
            "动态尺寸不进入 NPU，可能是后端没有声明可接受范围或运行时缺少形状参数。",
        ],
        "actions": [
            "按 [[32-故障速查表]] 收集最小证据。",
            "检查 `get_global_func` 和 `tvm.support.libinfo()`。",
            "分别测试分区、代码生成、模块加载与设备提交。",
            "把不被接纳原因打印成结构化日志。",
            "对照 [[30-自研 NPU 算子接入分册]] 的运算合同。",
        ],
        "sources": [
            ("BYOC 教程", f"{BASE_URL}/how_to/tutorials/bring_your_own_codegen.html"),
            ("Relax VM", f"{BASE_URL}/arch/relax_vm.html"),
            ("Target 与 Device", f"{BASE_URL}/arch/device_target_interactions.html"),
        ],
        "pitfalls": [
            "只提供最终异常栈而没有中间 IR，通常无法判断分区阶段问题。",
            "只用一个随机输入对照，不能覆盖极值与尾部。",
            "忽略版本信息会让相同代码在不同构建中表现不同。",
        ],
    },
    {
        "no": "29",
        "title": "官方资料与源码导航",
        "summary": "按学习主题给出 Apache TVM 官方网页、v0.24.0 源码目录和建议阅读顺序。",
        "mental": "官方文档用于理解设计和公开 API，源码测试用于确认当前版本的精确行为，二者应一起阅读。",
        "points": [
            "先读架构总览，再分别进入 Relax、TensorIR、代码生成与运行时。",
            "BYOC 以当前 Example NPU 教程、源码和测试三者互相核对。",
            "每个 Python API 都可追到 FFI 注册名，再追到 C++ 实现。",
            "测试往往给出最小可运行输入，是确认函数签名的高价值资料。",
            "发布 tag 比 main 分支更适合项目基线。",
        ],
        "actions": [
            "在本地源码使用 `rg` 搜索注册字符串。",
            "阅读实现前先阅读同目录测试。",
            "把关键源码路径记录到设计文档。",
            "升级版本时重新核对所有路径和函数签名。",
            "只从官方网页和 Apache TVM 仓库引用当前技术细节。",
        ],
        "sources": [
            ("Apache TVM 文档首页", f"{BASE_URL}/"),
            ("Apache TVM v0.24.0", "https://github.com/apache/tvm/tree/v0.24.0"),
            ("Apache TVM 发布页", "https://github.com/apache/tvm/releases"),
        ],
        "pitfalls": [
            "搜索结果可能优先显示多年前的 Relay 文章。",
            "main 分支文档可能已经包含发布版没有的 API。",
            "只阅读 README 不足以确认错误处理和序列化行为。",
        ],
    },
]

for spec in more_chapter_specs:
    write(f"{spec['no']}-{spec['title']}.md", render_chapter(spec))


write(
    "14-接入路线选择与总体设计.md",
    f"""
{frontmatter}
# 14. 接入路线选择与总体设计

{callout("abstract", "本章内容", "本章把自研 NPU 接入拆成三条路线，给出选择方法、组件关系、阶段成果和接口责任。读完后应能回答：为何选择 BYOC 或原生 TIR 后端，哪些工作由 TVM 完成，哪些工作由自研编译器、运行时、驱动和固件完成。")}

## 14.1 三条路线

| 路线 | 适合情况 | TVM 侧主要工作 | 自研侧主要工作 | 首版建议 |
| --- | --- | --- | --- | --- |
| Relax BYOC + 已有 SDK | 已有图编译器或网络执行引擎 | 组合运算注册、分区、外部模块打包 | 图编译、命令生成、运行时提交 | 最推荐 |
| Relax BYOC + 自定义命令编译器 | 硬件已定，尚无完整软件栈 | 分区、JSON 或二进制序列化、外部函数调用 | 子图编译、内存规划、命令流、驱动 | 推荐 |
| 原生 Target + TensorIR | 希望 TVM 直接产生设备代码，设备可编程性强 | TargetKind、调度、内建函数、代码生成、DeviceAPI | 汇编器或编码器、驱动、固件 | 第二阶段 |

{callout("important", "不要被“原生”二字误导", "原生 Target 并不自动带来更高性能。若 NPU 的最优执行单位是多算子子图，且已有成熟子图编译器，BYOC 往往更自然。原生 TIR 路线更适合指令可编程、循环与存储层次可由编译器直接控制的设备。")}

## 14.2 决策树

```mermaid
flowchart TD
    A["已有 NPU SDK 或图编译器？"] -->|是| B["优先 Relax BYOC"]
    A -->|否| C["硬件可由循环级程序直接控制？"]
    C -->|否| D["BYOC + 自研子图编译器"]
    C -->|是| E["是否需要 TVM 管理设备内存与队列？"]
    E -->|否| D
    E -->|是| F["原生 Target + DeviceAPI"]
    B --> G["先接 MatMul / Conv / Activation 组合"]
    D --> G
    F --> H["先接最小 PrimFunc 与单设备执行"]
```

## 14.3 推荐的软件分层

```mermaid
flowchart TB
    subgraph Compiler["编译主机"]
      FE["模型前端"]
      RX["Relax Pass 与分区"]
      CG["NPU 子图编译器"]
      PKG["模块打包器"]
      FE --> RX --> CG --> PKG
    end
    subgraph Target["执行设备"]
      APP["应用 / Relax VM"]
      RT["NPU 运行时模块"]
      DRV["用户态驱动 / 内核驱动"]
      FW["固件与命令处理器"]
      HW["矩阵 / 向量 / DMA / 片上存储"]
      APP --> RT --> DRV --> FW --> HW
    end
    PKG --> APP
```

每一层只承担自己能稳定完成的工作：

- 模型前端负责把源框架程序转换成 Relax，并保留形状、dtype 和参数。
- Relax Pass 负责通用图处理、组合运算识别、NPU 子图选择与主机保留部分。
- NPU 子图编译器负责数据排布选择、tile、片上内存分配、命令生成与静态检查。
- Runtime Module 负责加载编译产物、绑定实际 Tensor、分配设备资源、提交和等待。
- 驱动负责地址与权限、队列、同步、复位、错误上报和缓存维护。
- 固件负责解析版本化命令、调度硬件单元和报告完成状态。

## 14.4 先定义六份合同

### 14.4.1 运算合同

每个可交给 NPU 的运算都要写明：

1. Relax 运算名和允许的组合形式；
2. 输入、输出数量；
3. 允许的秩、尺寸范围和动态维度；
4. dtype、累加类型、舍入、饱和与特殊值处理；
5. 数据排布、对齐和步长限制；
6. 属性要求，例如卷积 stride、padding、dilation、groups；
7. 非整 tile 的处理；
8. 工作区计算方法；
9. 结果误差要求；
10. 不满足条件时的处理。

### 14.4.2 外部函数 ABI

外部函数必须有稳定的名称与参数顺序。建议所有 Tensor 仍通过 DLTensor 或 TVM Tensor 传入，标量配置放入模块元数据或显式参数。异步提交需要返回事件对象或由调用方提供事件槽；同步函数则必须在返回前保证输出可读取。

### 14.4.3 编译产物格式

至少包含以下字段：

| 字段 | 目的 |
| --- | --- |
| magic 与格式版本 | 拒绝错误文件 |
| 编译器版本与目标型号 | 追溯来源 |
| 所需固件 ABI 版本 | 加载前兼容检查 |
| 外部函数目录 | 按符号查找 |
| 常量目录与校验值 | 防止权重错配 |
| 命令段与重定位项 | 加载到实际地址 |
| 工作区要求 | 运行前分配 |
| 输入输出描述 | 绑定 Tensor |
| 调试信息 | 命令反汇编与故障定位 |

### 14.4.4 Target 能力描述

不要让编译器从型号名称猜参数。建议使用可版本化 JSON：

```json
{{
  "kind": "acme_npu",
  "arch": "npu_v1",
  "matrix_m": 16,
  "matrix_n": 16,
  "matrix_k": 32,
  "sram_bytes": 1048576,
  "dma_alignment": 64,
  "supported_dtypes": ["int8", "int16", "int32"],
  "firmware_abi": 3
}}
```

### 14.4.5 错误合同

错误至少分为：模型不被接受、编译约束不满足、产物不兼容、内存不足、设备忙、提交失败、设备超时、命令格式错误、地址错误、计算单元错误和结果对照失败。每个错误要有机器可读码与面向开发者的详细文本。

### 14.4.6 测试合同

测试不仅确认“能跑”，还应确认：

- 分区前后函数结构符合预期；
- 只接纳能力范围内的子图；
- 编译产物可保存和重新加载；
- 正常、极值、尾部、动态尺寸和异常输入得到预期处理；
- 主机保留部分与 NPU 部分的数据传递正确；
- 多次运行、并发、取消、超时和复位后恢复稳定。

## 14.5 分阶段成果

| 阶段 | 产物 | 必须通过的演示 |
| --- | --- | --- |
| A | 仅 Python 分区 | MatMul+ReLU 形成一个外部函数，其他运算留在主机 |
| B | 空壳代码生成与运行时 | 可导出、加载、调用，输出形状正确 |
| C | 单运算真实执行 | MatMul 的随机、极值和尾部尺寸正确 |
| D | 多运算子图 | MatMul+Bias+Activation 不写回中间结果 |
| E | 完整内存与异步提交 | 多次运行和并发稳定 |
| F | 模型覆盖 | 代表模型达到功能与性能目标 |
| G | 调优与长期维护 | 目标配置、数据库和版本升级可复现 |

## 14.6 与本地 NPU 规格协同

本 Vault 已有 [[NPU 指令与硬件架构设计 Spec]]、[[分块矩阵外积数据流]] 和 [[NPU 验证：从 BT 到算子]]。接入时应从这些资料提取矩阵 tile、L1BUF 容量、DMA 对齐、任务槽、数据类型、累加规则和错误状态，并放入目标配置与运算合同。编译器不能依赖未写入能力描述的默认值。

{callout("question", "评审前必须回答", "NPU 最优执行单位是单条指令、单个 TensorIR 内核，还是包含多个 Relax 运算的子图？权重何时重排？谁负责设备内存？执行是否异步？不被接受的节点由谁执行？产物如何在不同固件版本间做兼容检查？")}

## 14.7 官方依据

- [Bring Your Own Codegen]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html)
- [External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html)
- [Device/Target Interactions]({BASE_URL}/arch/device_target_interactions.html)
- [Code Generation]({BASE_URL}/arch/codegen.html)
""",
)


write(
    "15-Relax DPL 子图识别与分区.md",
    f"""
{frontmatter}
# 15. Relax DPL 子图识别与分区

{callout("abstract", "本章内容", "本章以 `matmul + bias + relu` 为例，说明如何用 Relax DPL 描述结构、用检查函数核对硬件条件、注册 FusionPattern、完成分区，并解释每个子图为何被接纳或保留在主机。")}

## 15.1 为什么不能只做算子白名单

同一个 `relax.matmul` 可能具有不同秩、dtype、转置形式、K 维、批维广播与动态尺寸。硬件也可能要求 K 是 32 的倍数、输入连续、权重使用特定排布、输出最后一维对齐。只检查运算名会把无法执行的实例交给 NPU，错误要到很后面才出现。

一个可靠的接纳函数应按以下次序检查：

1. 运算结构是否匹配；
2. 输入输出 StructInfo 是否完整；
3. dtype 是否被硬件接受；
4. 秩、维度和广播形式是否可处理；
5. 属性是否在允许集合内；
6. 常量要求是否满足；
7. 片上容量或分块方案是否存在；
8. 预期收益是否覆盖提交与数据搬运开销。

## 15.2 最小 DPL 结构

```python
from tvm.relax.dpl import wildcard, is_op
from tvm.relax.transform import FusionPattern

x = wildcard()
w = wildcard()
bias = wildcard()
mm = is_op("relax.matmul")(x, w)
add = is_op("relax.add")(mm, bias)
root = is_op("relax.nn.relu")(add)

pattern = FusionPattern(
    name="acme_npu.matmul_bias_relu",
    pattern=root,
    annotation_patterns={{
        "x": x,
        "w": w,
        "bias": bias,
        "matmul": mm,
        "root": root,
    }},
    check=check_matmul_bias_relu,
)
```

`wildcard()` 接受任意表达式；`is_op()` 限定调用的 Relax 运算。`annotation_patterns` 给子表达式命名，检查函数通过这些名称取得实际节点。组合名称应包含后端前缀，`RunCodegen` 使用前缀找到 `relax.ext.acme_npu`。

## 15.3 检查函数骨架

```python
from tvm import relax

SUPPORTED = {{"int8", "int16"}}

def tensor_info(expr):
    info = expr.struct_info
    if not isinstance(info, relax.TensorStructInfo):
        return None
    return info

def check_matmul_bias_relu(ctx):
    x_info = tensor_info(ctx.annotated_expr["x"])
    w_info = tensor_info(ctx.annotated_expr["w"])
    out_info = tensor_info(ctx.annotated_expr["root"])
    if x_info is None or w_info is None or out_info is None:
        return False
    if str(x_info.dtype) not in SUPPORTED:
        return False
    if x_info.ndim != 2 or w_info.ndim != 2:
        return False
    if x_info.shape is None or w_info.shape is None:
        return False
    # 示例只接收静态二维尺寸；正式实现应输出拒绝原因。
    x_shape = x_info.shape.values
    w_shape = w_info.shape.values
    if not all(hasattr(v, "value") for v in [*x_shape, *w_shape]):
        return False
    m, k = [int(v.value) for v in x_shape]
    wk, n = [int(v.value) for v in w_shape]
    if k != wk or k % 32 != 0 or n % 16 != 0:
        return False
    return m > 0 and k > 0 and n > 0
```

{callout("warning", "示例不是最终规则", "上面代码为了教学只接收静态二维输入。正式项目应检查 bias 形状、广播、对齐、内存占用、累加类型和固件能力；还应返回结构化拒绝原因，而不是只给 `False`。")}

## 15.4 让拒绝原因可观察

FusionPattern 的 `check` 返回布尔值。为了保存原因，可以把纯检查逻辑写成返回结果对象的函数，DPL 包装层只取 `accepted`：

```python
from dataclasses import dataclass

@dataclass(frozen=True)
class CheckResult:
    accepted: bool
    code: str
    detail: str

def inspect_matmul(spec) -> CheckResult:
    if spec.dtype not in SUPPORTED:
        return CheckResult(False, "dtype", f"unsupported dtype: {{spec.dtype}}")
    if spec.k % 32:
        return CheckResult(False, "k_tail", f"K={{spec.k}} is not divisible by 32")
    return CheckResult(True, "ok", "accepted")
```

编译服务可在预检查阶段遍历候选并记录结果；真正的 DPL check 再调用同一纯函数。这样不会把日志副作用塞入模式匹配器，也便于单测。

## 15.5 注册与优先级

```python
from tvm.relax.backend.pattern_registry import register_patterns

register_patterns([
    standalone_matmul,
    matmul_bias,
    matmul_bias_relu,
])
```

Apache TVM v0.24.0 的 Example NPU 源码注明：列表中越靠后的模式优先级越高。因此一般运算先放，具体组合后放。需要为优先级写测试，不能依赖读者记忆。

## 15.6 分区流水

```python
import tvm.relax.backend.contrib.acme_npu
from tvm.relax.backend.pattern_registry import get_patterns_with_prefix
from tvm.relax.transform import (
    FuseOpsByPattern,
    MergeCompositeFunctions,
    RunCodegen,
)

patterns = get_patterns_with_prefix("acme_npu")
mod = FuseOpsByPattern(
    patterns,
    bind_constants=False,
    annotate_codegen=True,
)(mod)
mod = MergeCompositeFunctions()(mod)
mod = RunCodegen()(mod)
```

关键参数：

- `bind_constants=False`：权重仍作为外部函数参数，便于主机管理、共享和单独打包；
- `annotate_codegen=True`：增加 `Codegen` 与外部符号信息，否则 `RunCodegen` 不知道调用哪个后端；
- `MergeCompositeFunctions`：把相邻且属于同一外部后端的组合函数整理成外部调用单元；
- `RunCodegen`：调用 `relax.ext.acme_npu`，把外部函数替换为 `ExternFunc` 调用并附加运行时模块。

## 15.7 Pass 次序

推荐的简化次序：

```text
导入 Relax
  → 基础规范化
  → 常量折叠与与硬件无关的图改写
  → NPU FuseOpsByPattern
  → MergeCompositeFunctions
  → RunCodegen
  → 剩余运算 LegalizeOps
  → 普通 FuseOps / FuseTIR
  → VM 与本地代码构建
```

若在 NPU 分区之前执行会改变所需结构的通用融合，DPL 可能看不到原始组合。反过来，若在必要的规范化之前分区，同一数学计算可能呈现多种写法，模式数量会快速膨胀。

## 15.8 分区测试

结构测试至少覆盖：

| 测试 | 预期 |
| --- | --- |
| 完整 `matmul+bias+relu` | 一个组合函数 |
| K 不满足硬件步长 | 不进入 NPU |
| dtype 不被接受 | 不进入 NPU |
| bias 广播不被接受 | 不进入 NPU |
| MatMul 结果有两个使用者 | 按组合规则决定是否拆分 |
| 更具体组合与普通 MatMul 同时注册 | 更具体组合优先 |
| 连续两个可接纳子图 | 外部函数数量符合设计 |
| 重复执行分区 Pass | 结构不继续变化 |

```python
assert any(
    f.attrs and f.attrs.get("Codegen") == "acme_npu"
    for _, f in mod.functions.items()
    if isinstance(f, relax.Function)
)
```

不要只用字符串包含检查。更稳妥的方式是构造期望 IRModule，使用 `tvm.ir.assert_structural_equal` 比较结构。

## 15.9 Example NPU 的价值与限制

v0.24.0 自带 Example NPU，包含 `patterns.py`、C++ JSON 序列化器、JSON Runtime、CMake 和测试。它是教学空壳，运行时主要记录分派信息，并不产生真实数值。复制目录后必须替换：

- 返回固定 `True` 的内存与 dtype 检查；
- 仅记录日志的执行函数；
- 示例 SRAM、阵列和向量宽度；
- 模糊的字符串运算分派；
- 没有真实设备内存与同步的部分。

## 15.10 官方依据

- [Relax DPL]({BASE_URL}/deep_dive/relax/dpl.html)
- [Operator Fusion]({BASE_URL}/arch/fusion.html)
- [External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html)
- [Example NPU patterns]({GITHUB_BLOB}/python/tvm/relax/backend/contrib/example_npu/patterns.py)
- [Example NPU tests]({GITHUB_BLOB}/tests/python/contrib/test_example_npu.py)
""",
)


write(
    "16-BYOC 代码生成器.md",
    f"""
{frontmatter}
# 16. BYOC 代码生成器

{callout("abstract", "本章内容", "本章说明 `RunCodegen` 如何找到外部编译器，如何遍历组合函数、生成 JSON 或二进制产物、建立 runtime.Module，以及真实 NPU 编译器应补充的形状、常量、工作区、重定位和版本信息。")}

## 16.1 调用位置

分区后的外层 Relax 函数带有 `Codegen="acme_npu"`。`RunCodegen` 收集这些函数，通过全局注册表取得 `relax.ext.acme_npu`，再把函数数组、选项和常量名称传给后端。后端返回一个或多个 runtime.Module，TVM 把这些模块接入最终可执行对象。

```mermaid
sequenceDiagram
    participant P as RunCodegen
    participant R as 全局注册表
    participant C as acme_npu 编译器
    participant M as 运行时模块
    P->>R: 查找 relax.ext.acme_npu
    R-->>P: PackedFunc
    P->>C: functions, options, constant_names
    C->>C: 子图分析与命令生成
    C->>M: 创建模块
    M-->>P: Module 数组
```

## 16.2 与 v0.24.0 Example NPU 一致的函数形态

```cpp
ffi::Array<ffi::Module> AcmeNPUCompiler(
    ffi::Array<relax::Function> functions,
    ffi::Map<ffi::String, ffi::Any> options,
    ffi::Map<relax::Constant, ffi::String> constant_names) {{
  ffi::Array<ffi::Module> modules;
  auto create = tvm::ffi::Function::GetGlobalRequired(
      "runtime.AcmeNPURuntimeCreate");

  for (const auto& func : functions) {{
    auto symbol = relax::GetExtSymbol(func);
    auto artifact = CompileSubgraph(func, options, constant_names);
    modules.push_back(
        create(symbol, artifact.binary, artifact.metadata,
               artifact.constant_names).cast<ffi::Module>());
  }}
  return modules;
}}

TVM_FFI_STATIC_INIT_BLOCK() {{
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef().def("relax.ext.acme_npu", AcmeNPUCompiler);
}}
```

这是接口骨架，`CompileSubgraph` 是项目的核心。它应是确定性的：相同 IR、Target、常量与编译器版本产生相同产物，或至少产生功能相同且可追溯的产物。

## 16.3 JSON 还是二进制

| 格式 | 优点 | 缺点 | 推荐使用阶段 |
| --- | --- | --- | --- |
| JSON 图 | 容易查看、适合早期联调 | 体积大、解析慢、字段类型限制多 | 空壳与首个真实运算 |
| FlatBuffer / 自定义表 | 兼顾可扩展与读取速度 | 需要格式工具与兼容策略 | 稳定的图级运行时 |
| 命令二进制 | 加载快、接近硬件 | 调试困难、重定位复杂 | 固件协议稳定后 |
| 混合包 | 元数据可读，命令段紧凑 | 打包器更复杂 | 产品阶段 |

{callout("tip", "建议", "早期先输出可读 JSON，同时生成命令反汇编文本。硬件执行稳定后再把命令段改为二进制，但保留元数据、版本、散列值和离线解析工具。")}

## 16.4 子图编译步骤

### 步骤 1：读取函数接口

收集每个参数和返回值的：

- 名称与顺序；
- shape、dtype、设备；
- 是否为常量；
- 允许的步长；
- 别名与原地写要求；
- 动态维度及其上限。

缺少必要 StructInfo 时，代码生成器应给出编译错误，不应猜测。

### 步骤 2：建立内部图

把 Relax 组合函数转换成自研内部节点。内部节点需要保存运算类型、属性、输入输出值、常量引用和源位置。转换表要版本化，并为每个运算写单测。

### 步骤 3：选择数据排布

根据运算、dtype、tile 和消费者选择排布。若生产者与消费者在同一个组合函数内，可保留 NPU 私有排布；外部函数输入输出必须遵守 ABI，或显式插入重排运算。

### 步骤 4：工作区与生命周期

对内部值做存活区间分析，复用不重叠的缓冲区。片上存储不足时选择更小 tile、分阶段执行或使用片外工作区。工作区大小应是输入尺寸的确定函数，并写入元数据。

### 步骤 5：命令生成

生成 DMA、矩阵、向量、复杂函数和同步命令。每条命令引用逻辑缓冲区或重定位项，不直接写入编译主机虚拟地址。命令序号与源节点保持关联，便于设备错误反查。

### 步骤 6：静态检查

检查命令字段、地址范围、对齐、缓冲区越界、依赖事件、工作区上限、命令数和固件 ABI。静态检查失败必须阻止产物输出。

### 步骤 7：模块构造

创建 runtime.Module，保存外部符号、命令、元数据、常量名称和所需版本。模块必须支持导出与重新加载。

## 16.5 常量处理

`constant_names` 让代码生成器用稳定名称引用 Relax Constant。常见选择：

1. 常量仍由 TVM 保存，运行时 `Init` 时传入；
2. 编译器预重排后把常量嵌入 NPU 模块；
3. 常量单独保存为权重包，多个模型函数共享。

预重排可以减少每次启动工作，但必须把源常量散列值、目标排布、dtype、编译器版本和硬件型号写入缓存键。常量内容变化后不得复用旧结果。

## 16.6 选项与 Target

编译选项不应散落在环境变量。建议统一成：

```python
npu_options = {{
    "arch": "npu_v1",
    "firmware_abi": 3,
    "opt_level": 2,
    "sram_bytes": 1048576,
    "enable_fused_activation": True,
    "debug_artifacts": "/tmp/acme_npu_debug",
}}
```

硬件固定限制来自 Target 或能力文件；用户可选策略来自 PassContext 或后端 options。两类信息发生冲突时，固定限制优先，并报告具体字段。

## 16.7 JSONSerializer 起点

若后端接受图结构，可继承 TVM 的 `JSONSerializer`。v0.24.0 Example NPU 的访问器取得组合函数 `Composite` 属性，把调用参数变为 JSON 节点输入，再以 `runtime.ExampleNPUJSONRuntimeCreate` 建立模块。这条路线适合快速搭建，但真实项目通常还要写入：

- 完整运算属性；
- 每个输入输出的 shape 与 dtype；
- 常量索引；
- 数据排布；
- 工作区；
- 设备版本；
- 编译选项；
- 错误定位信息。

## 16.8 构建开关

```cmake
if(USE_ACME_NPU_CODEGEN)
  tvm_file_glob(
    GLOB COMPILER_ACME_NPU_SRCS
    src/relax/backend/contrib/acme_npu/*.cc
  )
  list(APPEND COMPILER_SRCS ${{COMPILER_ACME_NPU_SRCS}})
endif()

if(USE_ACME_NPU_RUNTIME)
  tvm_file_glob(
    GLOB RUNTIME_ACME_NPU_SRCS
    src/runtime/contrib/acme_npu/*.cc
  )
  list(APPEND RUNTIME_SRCS ${{RUNTIME_ACME_NPU_SRCS}})
endif()
```

编译器版通常同时需要代码生成与运行时创建函数；仅部署版只带运行时。CI 应分别构建两种配置。

## 16.9 测试

1. 注册函数存在性：`tvm.get_global_func("relax.ext.acme_npu", True)`；
2. 一个组合函数生成一个带预期 type key 的 Module；
3. 同一输入多次编译产物散列值稳定；
4. 属性和常量正确进入产物；
5. 非法尺寸、dtype、对齐和 ABI 得到明确错误；
6. 导出后在新进程加载；
7. 调试产物能从命令序号回到 Relax 节点；
8. 仅运行时构建不包含编译器依赖。

## 16.10 官方依据

- [External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html)
- [Code Generation]({BASE_URL}/arch/codegen.html)
- [Example NPU codegen]({GITHUB_BLOB}/src/relax/backend/contrib/example_npu/codegen.cc)
- [Example NPU CMake]({GITHUB_BLOB}/cmake/modules/contrib/ExampleNPU.cmake)
""",
)


write(
    "17-NPU 运行时与驱动适配.md",
    f"""
{frontmatter}
# 17. NPU 运行时与驱动适配

{callout("abstract", "本章内容", "本章从 runtime.Module 的角度说明模块创建、常量初始化、输入输出绑定、设备内存、命令提交、事件同步、序列化和错误处理。BYOC 首版通常不需要实现完整 DeviceAPI，但仍需一个可靠的 NPU Runtime Module。")}

## 17.1 运行时的责任

运行时接收已经编译的外部函数产物，不再决定复杂图优化。它主要负责：

1. 检查产物格式与设备兼容性；
2. 加载常量与命令；
3. 为每次调用绑定实际 Tensor；
4. 分配或复用设备工作区；
5. 处理主机与设备的数据复制；
6. 进行地址重定位；
7. 提交命令并取得事件；
8. 等待、查询或回收事件；
9. 把设备错误转换成 TVM 可见错误；
10. 保存与恢复模块状态。

{callout("important", "编译期与运行期分工", "tile、组合运算、静态工作区布局和命令结构尽量在编译期决定；实际地址、设备编号、队列、事件与本次输入尺寸在运行期决定。若运行时重新做大型图优化，产物将难以复现。")}

## 17.2 Module 骨架

```cpp
class AcmeNPURuntimeNode final : public tvm::runtime::ModuleNode {{
 public:
  const char* type_key() const final {{ return "acme_npu"; }}

  ffi::Function GetFunction(
      const ffi::String& name,
      const ffi::ObjectPtr<ffi::Object>& self) final {{
    if (name == symbol_) {{
      return ffi::Function::FromPacked(
          [sptr_to_self = ffi::GetRef<ffi::Module>(this)]
          (ffi::PackedArgs args, ffi::Any* rv) {{
            auto* node =
                static_cast<AcmeNPURuntimeNode*>(sptr_to_self.operator->());
            node->Run(args);
          }});
    }}
    return nullptr;
  }}

  void SaveToBinary(dmlc::Stream* stream) final {{
    stream->Write(symbol_);
    stream->Write(artifact_);
    stream->Write(metadata_);
  }}

 private:
  void Run(ffi::PackedArgs args);
  ffi::String symbol_;
  std::string artifact_;
  std::string metadata_;
}};
```

具体基类与签名应以 v0.24.0 当前头文件和相邻模块为准。若采用 JSON 图，可继承 `JSONRuntimeBase`；若产物已经是设备命令，直接实现 ModuleNode 往往更清楚。

## 17.3 初始化

初始化分为模块级与设备级：

- 模块级：解析元数据、校验 magic、版本、函数目录、常量目录和命令段；
- 设备级：打开设备、取得能力、创建上下文、队列或流；
- 常量级：分配设备内存、执行预重排或上传已重排权重；
- 缓存级：建立权重与命令缓存，记录引用计数。

初始化应支持重复调用或明确拒绝重复调用。失败后必须释放已经取得的资源，不能留下半初始化对象。

## 17.4 Tensor 绑定

每次调用先核对：

| 检查项 | 说明 |
| --- | --- |
| 参数数量 | 与外部函数 ABI 一致 |
| dtype | 与编译产物一致，或允许的动态集合 |
| ndim | 与描述一致 |
| shape | 静态值一致，动态值在范围内 |
| strides | 连续要求或明确支持的非连续步长 |
| byte_offset | 设备是否支持带偏移 Tensor |
| device | 主机、NPU 或共享内存 |
| alignment | 基地址与每行步长 |
| 可写性 | 输出与原地写约束 |

若输入在主机内存，运行时可以分配设备缓冲区并复制；若输入已经在 NPU 内存，直接绑定可避免往返复制。两种情况必须在日志与性能统计中区分。

## 17.5 设备内存

推荐把内存分成四类：

1. 常量内存：模块生命周期内保持；
2. 输入输出内存：调用方拥有或运行时暂时创建；
3. 工作区：外部函数调用期间使用，可由内存池复用；
4. 命令与描述符内存：通常只读，可跨调用复用。

内存池按设备、对齐和用途分组。异步调用完成之前，不得回收仍被设备使用的缓冲区。若运行时允许并发，同一模块的可变工作区不能被两个调用同时覆盖。

## 17.6 提交与事件

```mermaid
sequenceDiagram
    participant VM as Relax VM
    participant RT as NPU Runtime
    participant D as Driver
    participant F as Firmware
    VM->>RT: external_func(inputs, outputs)
    RT->>RT: 校验与重定位
    RT->>D: submit(queue, commands)
    D->>F: doorbell
    F-->>D: event complete / error
    D-->>RT: wait or query
    RT-->>VM: return
```

同步调用可以在函数返回前等待事件。异步调用应把事件与输入输出生命周期绑定，并提供后续同步点。不要仅依赖全设备同步，这会破坏不同队列间的并行。

## 17.7 缓存一致性

非一致性 SoC 需要明确：

- CPU 写入输入后由谁 clean；
- NPU 写入输出后由谁 invalidate；
- 命令缓冲区何时可见；
- 设备写完成与中断到达的先后保证；
- 地址是物理地址、IOVA 还是设备虚拟地址；
- scatter-gather 是否被硬件支持。

这些规则属于驱动 ABI，不能由每个算子自行处理。错误的缓存维护常表现为输入相关的偶发数值错误。

## 17.8 错误与恢复

推荐错误对象包含：

```text
stage           = submit | execute | wait | copy | load
host_code       = 统一软件错误码
driver_code     = ioctl 或 SDK 返回码
device_code     = 固件错误码
function        = 外部函数符号
submission_id   = 提交序号
command_index   = 首个失败命令
engine          = DMA | Matrix | Vector | CME
detail          = 可读说明
recoverable     = true | false
```

可恢复错误可以终止当前调用并保留设备；不可恢复错误应停止新提交、收集状态、复位设备、清空失效事件与内存，再允许上层重新加载模块。复位后不能继续使用复位前的设备地址和事件。

## 17.9 模块保存与加载

`export_library` 会把被导入模块一并打包。自定义 Module 若需要在加载后恢复命令和元数据，必须实现二进制保存，并注册：

```cpp
TVM_FFI_STATIC_INIT_BLOCK() {{
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef()
      .def("runtime.AcmeNPURuntimeCreate", AcmeNPURuntimeCreate)
      .def("ffi.Module.load_from_bytes.acme_npu",
           AcmeNPURuntimeLoadFromBytes);
}}
```

type key、加载注册名与模块返回值必须一致。测试应在另一个进程加载共享库，防止全局对象残留掩盖缺失注册。

## 17.10 多线程与多设备

- 设备上下文按 device id 区分；
- 模块不可变部分可共享；
- 每次调用状态独立；
- 队列选择有明确策略；
- 常量缓存使用线程安全引用计数；
- 设备复位只影响对应设备；
- 错误日志包含线程、队列和提交序号。

## 17.11 运行时最小测试

1. 创建与销毁模块一万次无泄漏；
2. 常量初始化成功与失败均可清理；
3. 零长度、最小尺寸、最大允许尺寸；
4. 输入输出地址未对齐；
5. 驱动返回忙、超时、非法命令和设备复位；
6. 两线程调用同一模块；
7. 两个设备并行；
8. 导出、进程退出、重新加载；
9. 连续运行后结果不受上一次工作区残留影响；
10. 运行时仅构建配置可以独立链接。

## 17.12 官方依据

- [TVM Runtime System]({BASE_URL}/arch/runtime.html)
- [Module Serialization]({BASE_URL}/arch/introduction_to_module_serialization.html)
- [Example NPU runtime]({GITHUB_BLOB}/src/runtime/contrib/example_npu/example_npu_runtime.cc)
- [Relax VM]({BASE_URL}/arch/relax_vm.html)
""",
)


write(
    "18-原生 TargetKind DeviceAPI 与 TIR 后端.md",
    f"""
{frontmatter}
# 18. 原生 TargetKind DeviceAPI 与 TIR 后端

{callout("abstract", "本章内容", "本章面向需要让 TVM 把 NPU 当作完整目标设备的项目，说明 TargetKind、Target 属性、TIR 调度、目标构建函数、runtime.Module 和 DeviceAPI 的职责与最小实现顺序。")}

## 18.1 何时采用

满足多个条件时再进入本路线：

- NPU 指令可由循环级程序稳定表达；
- 编译器能够直接控制片上缓冲区、DMA、矩阵或向量单元；
- 希望 TVM 调度和自动搜索决定 tile 与执行次序；
- 需要 TVM Tensor 直接驻留在 NPU 设备内存；
- 需要多个 TIR 内核以统一设备队列执行；
- 团队可以长期维护 Target、代码生成、运行时和测试。

若 NPU 只接受封装好的网络或大型子图，继续使用 BYOC 更合适。

## 18.2 四个必要组件

```mermaid
flowchart LR
    A["TargetKind<br/>编译期能力"] --> B["TIR 编译流程<br/>调度与逐级转换"]
    B --> C["target.build.acme_npu<br/>目标翻译"]
    C --> D["runtime.Module<br/>设备函数"]
    D --> E["DeviceAPI<br/>内存/复制/流/同步"]
```

### TargetKind

声明目标名称、默认设备类型与合法属性。属性示例：

- `arch`：硬件代次；
- `matrix_m/n/k`：矩阵基本块；
- `sram_bytes`：编译可用片上空间；
- `vector_bytes`：向量宽度；
- `dma_alignment`：DMA 对齐；
- `max_commands`：单函数命令上限；
- `firmware_abi`：所需固件协议版本；
- `supports_async_copy`：异步复制能力。

### TIR 编译流程

把通用 PrimFunc 转为设备可处理的形式，包括循环规范化、内存作用域、缓冲区展平、内建函数降低和主机设备函数分离。每个 Pass 的输入条件要明确。

### 目标构建函数

以 `target.build.acme_npu` 注册，接收 IRModule 与 Target，返回 runtime.Module。它可以生成汇编、C 源码、设备二进制或命令包。

### DeviceAPI

在运行期实现设备属性、内存、复制、流与同步。Python 的 `tvm.runtime.device("acme_npu", 0)` 最终依赖设备类型与 DeviceAPI 注册。

## 18.3 TargetKind 注册骨架

官方架构文档要求在目标类型注册处增加：

```cpp
TVM_REGISTER_TARGET_KIND("acme_npu", kDLAcmeNPU)
    .add_attr_option<ffi::String>("arch")
    .add_attr_option<Integer>("matrix_m", Integer(16))
    .add_attr_option<Integer>("matrix_n", Integer(16))
    .add_attr_option<Integer>("matrix_k", Integer(32))
    .add_attr_option<Integer>("sram_bytes")
    .add_attr_option<Integer>("dma_alignment", Integer(64))
    .add_attr_option<Integer>("firmware_abi");
```

设备类型值必须按当前 TVM 与 DLPack 规则选择，并同步更新 C++ 与 Python 的设备名称表。不要私自与现有值冲突。

Python 侧使用：

```python
target = tvm.target.Target({{
    "kind": "acme_npu",
    "arch": "npu_v1",
    "matrix_m": 16,
    "matrix_n": 16,
    "matrix_k": 32,
    "sram_bytes": 1048576,
    "dma_alignment": 64,
    "firmware_abi": 3,
}})
```

## 18.4 调度与内存作用域

可定义类似 `npu.sram`、`npu.accumulator` 的存储区域名称，并在调度中使用：

```python
sch = tvm.s_tir.Schedule(mod)
block = sch.get_block("matmul")
i, j, k = sch.get_loops(block)
io, ii = sch.split(i, factors=[None, 16])
jo, ji = sch.split(j, factors=[None, 16])
ko, ki = sch.split(k, factors=[None, 32])
sch.reorder(io, jo, ko, ii, ji, ki)
aa = sch.cache_read(block, 0, "npu.sram")
bb = sch.cache_read(block, 1, "npu.sram")
cc = sch.cache_write(block, 0, "npu.sram")
```

调度只是建立程序组织。要真正使用矩阵指令，还需 Tensor Intrin 或后端内建调用，并保证描述函数、实现函数、缓冲区步长和 dtype 完全一致。

## 18.5 Tensor Intrin

一个 Tensor Intrin 通常包含：

- 描述：小块计算结果如何得到；
- 实现：用硬件内建函数或外部调用完成相同工作；
- 缓冲区形状与步长要求；
- 作用域与对齐要求。

```python
TensorIntrin.register(
    "acme_npu.mma_i8_16x16x32",
    desc_func,
    impl_func,
)
sch.tensorize(loop_or_block, "acme_npu.mma_i8_16x16x32")
```

非整尺寸可以选择外层保护、填充到物理块、尾部使用向量单元，或保留给主机。选择必须与成本模型及数值规则一致。

## 18.6 目标构建函数

```cpp
tvm::runtime::Module BuildAcmeNPU(
    IRModule mod, Target target) {{
  ValidateTarget(target);
  auto lowered = RunAcmeLowering(mod, target);
  auto binary = EmitAcmeBinary(lowered, target);
  return AcmeModuleCreate(binary, target);
}}

TVM_FFI_STATIC_INIT_BLOCK() {{
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef().def("target.build.acme_npu", BuildAcmeNPU);
}}
```

构建函数不得查询本机实际 NPU，因为编译主机可能没有设备。所有需要的能力由 Target 提供。若某个属性缺失，应报告明确错误。

## 18.7 DeviceAPI 方法

| 方法类别 | 关键责任 |
| --- | --- |
| `GetAttr` | 设备存在、名称、总内存等运行期属性 |
| `SetDevice` | 选择当前设备 |
| `AllocDataSpace` / `FreeDataSpace` | 设备内存 |
| `CopyDataFromTo` | 主机与设备、设备内部复制 |
| `CreateStream` / `FreeStream` | 队列或流 |
| `SetStream` | 后续函数提交到当前流 |
| `StreamSync` | CPU 等待某个流 |
| `SyncStreamFromTo` | 建立两个流之间的先后关系 |

如果硬件只有一个队列，`CreateStream` 可返回空句柄，但同步行为仍需正确。异步复制必须保证源与目的缓冲区在事件完成前有效。

注册名称：

```cpp
TVM_FFI_STATIC_INIT_BLOCK() {{
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef().def("device_api.acme_npu",
                        AcmeNPUDeviceAPI::Global);
}}
```

## 18.8 主机与设备函数

最终程序常包含：

- 主机函数：参数检查、设备内存准备、内核发射；
- 设备函数：NPU 可执行内核；
- 导入关系：主机 Module 导入设备 Module；
- VM：按 Relax 控制流程调用主机包装或外部函数。

导出共享库时设备 Module 作为被导入模块序列化。加载后恢复导入关系，再由设备驱动创建实际执行对象。

## 18.9 最小实现顺序

1. 注册 TargetKind，能构造并读取属性；
2. 注册目标构建函数，返回只含空函数的 Module；
3. 实现一个向量加法 PrimFunc；
4. 实现设备内存与同步复制；
5. 执行单内核并对照 CPU；
6. 增加矩阵 Tensor Intrin；
7. 增加片上存储和 DMA；
8. 增加多流、异步复制和自动搜索；
9. 接到 Relax pipeline；
10. 测试导出、加载和远程运行。

## 18.10 官方依据

- [Device/Target Interactions]({BASE_URL}/arch/device_target_interactions.html)
- [Target API]({BASE_URL}/reference/api/python/target.html)
- [Code Generation]({BASE_URL}/arch/codegen.html)
- [TensorIR]({BASE_URL}/deep_dive/tensor_ir/index.html)
""",
)


write(
    "19-命令流 内存规划 与数据布局.md",
    f"""
{frontmatter}
# 19. 命令流、内存规划与数据排布

{callout("abstract", "本章内容", "本章把 Relax 子图转成可执行 NPU 任务，重点说明逻辑缓冲区、生命周期、片上存储、DMA、tile、命令依赖、地址重定位和数据排布。")}

## 19.1 从图到命令的中间层

不要让 Relax 节点直接写成硬件命令。建议先建立 NPU 内部 IR：

```text
Relax composite function
  → NPU graph IR
  → 排布与 dtype 规划
  → 分块计划
  → 逻辑缓冲区与生命周期
  → 引擎任务 DAG
  → 命令编码
  → 静态检查
  → 模块产物
```

内部 IR 给编译器留下插入重排、DMA、填充、尾部处理和同步的空间。硬件命令格式变化时，也不必重写整个 Relax 前端。

## 19.2 逻辑缓冲区

每个值先用逻辑缓冲区表示：

| 字段 | 说明 |
| --- | --- |
| id | 模块内唯一编号 |
| role | input、output、constant、workspace、scratch |
| shape | 逻辑尺寸 |
| dtype | 元素类型 |
| layout | 数据排布 |
| size_bytes | 包含填充后的实际字节数 |
| alignment | 最小对齐 |
| memory_class | 主机、设备片外、片上 |
| lifetime | 首次写到最后一次读 |
| relocatable | 加载时是否需要重定位 |

编译期命令引用 buffer id 与偏移，运行时再把 buffer id 换成实际设备地址。这样同一模块可以在不同调用、不同设备地址下复用。

## 19.3 生命周期与复用

对任务 DAG 做拓扑排序后，可用首写位置与末读位置计算生命周期。两个生命周期不重叠的工作区可以共享同一物理区域，但下列情况需要保守处理：

- 异步 DMA 与计算仍在使用旧数据；
- 一个值有多个消费者；
- 原地写会覆盖仍需读取的输入；
- 多队列缺少明确事件关系；
- 调试模式要求保留中间值。

片上存储规划可采用线性扫描、空闲区列表或图着色。首版建议使用容易验证的线性扫描，并在日志中打印每个缓冲区的偏移和生命周期。

## 19.4 tile 选择

以矩阵乘法 `C[M,N] = A[M,K] × B[K,N]` 为例，tile 至少受以下因素制约：

```text
A_tile_bytes + B_tile_bytes + C_partial_bytes
+ 双缓冲空间 + 对齐空隙 + 指令暂存
<= 可分配片上空间
```

选择 `Mt, Nt, Kt` 时同时考虑：

- 矩阵阵列的物理块；
- DMA burst 与行对齐；
- B 权重复用；
- C 部分和宽度；
- 双缓冲；
- M、N、K 尾部；
- 多核或多引擎并行；
- 工作区和命令数量。

较大 tile 不一定更快。它提高复用，也会占用更多片上空间，降低同时驻留任务数，并可能增加尾部浪费。

## 19.5 双缓冲

```mermaid
gantt
    title 双缓冲示意
    dateFormat X
    axisFormat %s
    section DMA
    载入分块 0 :a0, 0, 2
    载入分块 1 :a1, 2, 4
    载入分块 2 :a2, 4, 6
    section Matrix
    计算分块 0 :b0, 2, 4
    计算分块 1 :b1, 4, 6
    计算分块 2 :b2, 6, 8
```

双缓冲需要两个物理区域与明确事件。DMA 写入 buffer 1 时，矩阵单元读取 buffer 0；下一轮交换。编译器必须保证写端不会提前覆盖读端，固件必须正确实现事件等待。

## 19.6 命令依赖

推荐命令使用显式事件或前序位图，而不是依赖“提交次序自然正确”。示例：

```text
cmd 10: DMA_LOAD_A    signal=e10
cmd 11: DMA_LOAD_B    signal=e11
cmd 12: MATMUL        wait={{e10,e11}} signal=e12
cmd 13: VECTOR_RELU   wait={{e12}}     signal=e13
cmd 14: DMA_STORE_C   wait={{e13}}     signal=e14
```

编译器静态检查：

- 每个被等待事件都有生产者；
- 事件不会在仍被等待时错误复用；
- DAG 无环；
- 失败能传播到依赖命令；
- 最终输出命令可被主机等待；
- 命令数量不超过硬件上限。

## 19.7 数据排布

逻辑形状相同的数据可以有不同物理排列。例如二维权重 `[K,N]` 可按 `Ko, No, Ki, Ni` 分块，使 `Ki×Ni` 与矩阵单元一致。排布描述必须给出：

1. 逻辑轴与物理轴的对应关系；
2. 分块因子；
3. 轴次序；
4. 对齐与填充；
5. 元素打包方式；
6. 地址计算式；
7. 尾部未使用位置的写入规则。

建议把排布做成结构化对象，禁止只使用含糊字符串。编译器、权重转换工具、运行时和验证参考模型共同使用一份定义。

## 19.8 外部函数接口处的排布

有三种选择：

- 输入输出使用标准连续排布，外部函数内部转换；
- 模型参数预先转换，激活仍使用标准排布；
- 相邻 NPU 子图共享私有排布，只在主机与 NPU 交界处转换。

第三种可减少转换，但需要图级排布传播与更复杂的主机保留处理。首版通常先选择第二种：权重离线转换，激活接口保持简单。

## 19.9 非整 tile

四种方法：

| 方法 | 优点 | 成本 |
| --- | --- | --- |
| 硬件掩码 | 无额外填充 | 指令与 RTL 需要支持 |
| 填充输入 | 主计算规则简单 | 增加内存与 DMA |
| 小 tile 尾部 | 浪费较少 | 命令与调度更复杂 |
| 主机处理尾部 | 便于初期实现 | 增加主机设备交互 |

矩阵归约 K 尾部填充时，填充值必须使计算结果不变。带 zero point 的整数计算不能简单假定填 0 总是正确，应根据数值公式选择。

## 19.10 地址与安全

运行时重定位必须检查：

- `offset + size` 不溢出；
- 访问落在已分配缓冲区内；
- 读写权限正确；
- 对齐满足命令要求；
- 物理地址或 IOVA 位宽合法；
- 不允许命令访问任意主机地址；
- 常量区不可被写命令覆盖。

固件还应进行独立检查，不能只信任编译器。编译器检查提高开发效率，固件检查保护系统。

## 19.11 与本地规格对应

[[NPU 指令与硬件架构设计 Spec]] 定义了命令头、任务槽、L1BUF、DMA、Matrix、Vector、CME 与事件。编译器应把其中稳定规则实现为：

- Target 能力字段；
- NPU 内部 IR 约束；
- tile 选择器；
- 命令编码器；
- 静态检查器；
- 命令反汇编器；
- 参考模型；
- 模块级与系统级测试。

## 19.12 评审清单

- [ ] 每个命令地址都由逻辑缓冲区重定位得到；
- [ ] 每个缓冲区大小包含对齐、填充与打包；
- [ ] 生命周期考虑异步执行；
- [ ] 非整 tile 有明确方法；
- [ ] 事件无未定义生产者与错误复用；
- [ ] 排布地址公式有正反向测试；
- [ ] 片上占用不超过能力值；
- [ ] 命令可离线解析；
- [ ] 静态检查与固件检查各自存在；
- [ ] 性能日志能分解 DMA 与计算时间。
""",
)


write(
    "20-低比特整数计算与数值规则.md",
    f"""
{frontmatter}
# 20. 低比特整数计算与数值规则

{callout("abstract", "本章内容", "本章讨论 INT4、INT8、INT16、INT32 的表示、scale、zero point、累加、舍入、饱和、组合运算和测试。重点是让 Relax 图、自研编译器、参考模型、固件与 RTL 对同一组位级规则达成一致。")}

## 20.1 为什么数值规则必须先写

两个实现都声称支持 INT8，不表示结果一定相同。差异可能来自：

- 有符号或无符号输入；
- per-tensor 或 per-channel scale；
- zero point 的轴；
- 乘积宽度与累加宽度；
- bias 处于哪个缩放域；
- 右移前是否加舍入偏置；
- 负数右移的定义；
- 中间步骤是否饱和；
- 激活前还是激活后裁剪；
- 特殊函数使用查表、分段多项式还是浮点内部计算。

因此，编译器不能只携带 dtype 名称，还要携带完整数值参数与操作次序。

## 20.2 基本公式

整数值 `q` 表示的实数可写为：

$$
x=(q-z)s
$$

其中 `s>0` 是 scale，`z` 是 zero point。把实数结果重新写为整数：

$$
q_y=\operatorname{{clip}}\left(
\operatorname{{round}}\left(\frac{{y}}{{s_y}}\right)+z_y,
q_{{min}},q_{{max}}
\right)
$$

`round` 的方式必须显式指定。推荐使用最接近偶数，或严格采用硬件已经定义的方式。不能用宿主语言默认转换代替协议定义。

## 20.3 矩阵乘法

设：

$$
A_r=(A_q-z_a)s_a,\quad
B_r=(B_q-z_b)s_b
$$

则：

$$
C_r[m,n]=
s_a s_b
\sum_k (A_q[m,k]-z_a)(B_q[k,n]-z_b)
$$

若 `z_a=z_b=0`，整数核心只需有符号乘加。非零 zero point 会引入行和、列和与常数修正，编译器可以展开修正项，也可以只接收对称形式。无论选择哪种，都应在组合运算检查函数中明确。

### 累加宽度

INT8 乘积需要至少有符号 16 bit，但 K 维累加可能远超 16 bit。可用上界估算：

$$
|acc|_{{max}} \le K\cdot
\max|A_q-z_a|\cdot\max|B_q-z_b|+|bias|
$$

编译器根据 K 和输入范围检查 INT32 是否足够；若硬件内部使用更宽累加，再在写回时按规则裁剪。

## 20.4 bias

bias 常使用 INT32，所代表的实数 scale 应与乘积域一致：

$$
s_{{bias}}=s_a s_b
$$

若权重采用 per-channel scale，则每个输出通道有自己的 `s_b[n]`，bias scale 也随输出通道变化。编译器必须验证 bias 长度、轴和 scale 数量。

## 20.5 固定乘数与移位

输出换算常把实数比例：

$$
r=\frac{{s_a s_b}}{{s_y}}
$$

近似成整数乘数 `M` 与移位 `n`：

$$
q_y \approx
\operatorname{{clip}}\left(
\operatorname{{RoundShift}}(acc\cdot M,n)+z_y
\right)
$$

需要定义：

1. `M` 的位宽和取值范围；
2. 乘法产生的临时宽度；
3. `n` 正负时分别表示左移还是右移；
4. 舍入发生在移位前还是后；
5. 负数的舍入；
6. 溢出时饱和还是截断。

## 20.6 INT4 打包

常见方法是一字节保存两个有符号 4 bit 元素。必须规定：

- 偶数元素位于低半字节还是高半字节；
- 使用二进制补码；
- 读取后如何符号扩展；
- 奇数元素个数时未使用半字节如何处理；
- DMA 与向量写入能否只更新一个半字节；
- 权重离线转换与硬件读取的轴次序。

建议为每一种打包与排布实现正向编码和反向解码，并做随机往返测试。

## 20.7 per-tensor 与 per-channel

| 方式 | 参数数量 | 优点 | 编译与硬件代价 |
| --- | ---: | --- | --- |
| per-tensor | 每个 Tensor 一组 | 简单 | 精度可能较低 |
| per-output-channel | 每个输出通道一组 | 权重常有更好精度 | 后处理需逐通道参数 |
| per-group | 每个通道组一组 | 折中 | 需要组索引 |
| per-token | 每个 token 一组 | 适合部分 Transformer 场景 | 运行期统计与参数存储较多 |

Relax 组合运算应把 scale 与 zero point 当作明确输入或属性，代码生成器再决定放入常量区、参数区或指令字段。

## 20.8 激活函数与复杂函数

ReLU 可直接比较整数与对应零点。Sigmoid、Tanh、GELU、SiLU、Exp、Reciprocal、Softmax 与 Norm 需要更多规则。可选实现：

- 整数查找表；
- 分段线性；
- 分段多项式；
- 内部转 FP32，再转回整数；
- 调用固件数学库。

无论实现方式，都要写明输入区间、输出区间、最大绝对误差、平均误差、饱和点和单调性要求。Softmax 还要检查一行总和、全相等输入、大正负差值和长序列。

## 20.9 图中的显式转换

Relax v0.24.0 可能出现 `relax.quantize` 与 `relax.dequantize` 运算名。本文保留其英文 API 名称，以便和源码一致。后端可以：

1. 把这些节点接到设备转换单元；
2. 与前后运算组合，消除中间浮点 Tensor；
3. 在不接受时保留给主机；
4. 在模型导入后通过自定义 Pass 建立项目需要的低比特整数图。

禁止仅因节点名存在就接纳，仍需检查 axis、scale dtype、zero point、目标 dtype 与设备规则。

## 20.10 误差要求

按数据类型和运算分别定义：

- 位级相同；
- 最大绝对误差；
- 最大相对误差；
- ULP；
- Top-k 一致率；
- 余弦相似度；
- 模型任务指标变化。

整数基础运算若协议完全明确，通常可要求位级相同。使用近似特殊函数时，采用数值误差与函数性质检查。

## 20.11 必测输入

1. 全零、全一、全负一；
2. dtype 最小值与最大值；
3. 恰好位于舍入中点两侧；
4. 会导致累加最大正值和最大负值的输入；
5. bias 单独触发饱和；
6. per-channel 参数差异很大；
7. INT4 奇数元素数；
8. K 为 0、1、tile-1、tile、tile+1；
9. scale 很小或很大；
10. Softmax 全相等与单个极大值；
11. Norm 方差接近 0；
12. 随机长时间对照。

## 20.12 参考模型

参考模型应避免复用硬件实现中的位运算代码，否则相同缺陷可能同时存在。推荐：

- Python 或 C++ 高精度公式作为数学参考；
- 独立的位准确模型作为协议参考；
- RTL 或设备结果作为被测对象；
- TVM 后端结果与三者逐层比较。

每个失败样本保存输入、参数、期望、实际、首个不同元素和对应命令。

## 20.13 与本地资料

[[NPU 指令与硬件架构设计 Spec]] 已定义 INT4、INT8、INT16、INT32、内部 FP32 特殊函数和舍入选项。TVM 接入应直接引用该规格的稳定字段，并在编译器中做静态检查，避免固件收到不被接受的 dtype 或参数组合。
""",
)


write(
    "21-动态形状 控制流 与异构回退.md",
    f"""
{frontmatter}
# 21. 动态形状、控制流与异构回退

{callout("abstract", "本章内容", "本章说明 Relax 如何保留符号尺寸与控制流，自研 NPU 后端如何选择静态特化、范围编译或运行期分派，以及不被接受的节点怎样安全地交给主机。")}

## 21.1 三类尺寸

| 类型 | 例子 | 编译策略 |
| --- | --- | --- |
| 完全静态 | 图像模型 `1×3×224×224` | 直接编译 |
| 有限集合 | batch ∈ {{1,2,4,8}} | 多版本特化 |
| 范围动态 | sequence ∈ `[1,4096]` | 范围产物或运行期选择 |

完全未知的维度会影响工作区、tile、命令数和设备时间。首版可以拒绝范围动态，但必须由分区检查函数明确拒绝，不能在代码生成器深处崩溃。

## 21.2 Relax 符号尺寸

Relax TensorStructInfo 可包含符号变量。后端检查时区分：

- 是否已知秩；
- 每个维度是常量、符号还是表达式；
- 是否存在上限；
- 维度之间是否有相等或整除关系；
- 运行期是否需要把尺寸传给外部函数。

若硬件要求 K 为 32 的倍数，符号 K 可以携带约束，也可以在运行时加守卫：

```text
if K % 32 == 0 and K <= 4096:
    call acme_npu_matmul
else:
    call host_matmul
```

运行期守卫增加控制开销，但允许一个可执行对象处理更多输入。

## 21.3 多版本特化

对常见 batch 或 sequence 长度分别编译：

```mermaid
flowchart TD
    A["运行期输入 shape"] --> B{{"选择版本"}}
    B -->|seq <= 128| C["npu_prefill_s128"]
    B -->|seq <= 512| D["npu_prefill_s512"]
    B -->|seq <= 2048| E["npu_prefill_s2048"]
    B -->|其他| F["主机或通用版本"]
```

较大版本可以使用填充处理较小输入，但要评估额外计算和数据搬运。版本选择表应进入模块元数据，运行时只做简单查询。

## 21.4 动态工作区

工作区大小可表示成符号尺寸函数，例如：

$$
W(B,S,H)=\operatorname{{align}}(B\cdot S\cdot H,64)+W_{{temp}}
$$

编译器保存表达式或上限，运行时取得实际尺寸后计算。必须检查乘法溢出与上限。若申请失败，返回内存不足，不能缩小缓冲区继续执行。

## 21.5 控制流

Relax 支持 `If` 等控制。常见策略：

- 分支整体留在 VM，分支内部的可接纳子图进入 NPU；
- 两个分支都编译成外部函数，VM 在运行期选择；
- 若条件在编译期已知，先折叠不可能分支；
- NPU 有原生控制能力时，可在子图编译器内部处理，但调试复杂度更高。

VM 只组织控制，不执行张量计算。分支返回的 TensorStructInfo 必须兼容。

## 21.6 主机保留

异构模型通常包含：

```text
主机算子
  → 复制到 NPU
  → NPU 子图
  → 复制到主机
  → 主机算子
  → 复制到 NPU
  → NPU 子图
```

每次设备切换都有固定开销。分区成本模型需要估算复制字节和提交次数，小运算即使硬件支持，也可能留在主机更快。

## 21.7 设备间 Tensor

若使用 BYOC 且运行时内部管理 NPU 内存，外部函数输入输出可能仍以主机 Tensor 呈现，由运行时复制。若实现 DeviceAPI，Tensor 可直接处于 NPU 设备。两种设计的差别：

| 方面 | BYOC 内部复制 | DeviceAPI |
| --- | --- | --- |
| 首版工作量 | 较小 | 较大 |
| 跨外部函数保持设备数据 | 需运行时自建机制 | 更自然 |
| TVM 统一设备复制 | 较弱 | 完整 |
| 与已有 SDK 配合 | 容易 | 需适配 |
| 多设备控制 | 后端自管 | TVM 设备模型 |

## 21.8 不被接受时的原则

1. 在分区阶段发现不符合条件，保留原 Relax 节点；
2. 在代码生成阶段发现内部编译失败，可配置为报告编译错误，或重新编译时禁用该模式；
3. 运行期设备执行失败一般不能自动改用主机重算，除非输出尚未对外可见、输入仍有效且调用被设计为可重试；
4. 任何重试都应记录原因，避免静默隐藏设备缺陷。

{callout("warning", "不要把运行期失败等同于普通主机保留", "分区阶段的主机保留是编译计划的一部分；运行期设备失败可能已经部分写入输出或改变状态，直接重算需要严格的事务与状态设计。")}

## 21.9 状态型模型

KV Cache、RNN state、随机数状态和设备驻留参数具有跨调用状态。需要说明：

- 状态的拥有者；
- 初始化与销毁；
- 多会话隔离；
- 形状增长；
- 设备复位后的恢复；
- 并发访问；
- 导出可执行文件是否包含初始状态。

状态更新失败后不能只返回旧状态继续运行，否则后续输出会持续错误。

## 21.10 测试矩阵

| 维度 | 值 |
| --- | --- |
| batch | 1、常见值、上限、上限+1 |
| sequence | 0、1、tile-1、tile、tile+1、最大 |
| 分支 | true、false、编译期常量 |
| 后端组合 | 全 NPU、部分 NPU、全主机 |
| 工作区 | 正常、刚好上限、申请失败 |
| 状态 | 首次、重复、多会话、复位后 |
| 设备 | 0、1、不存在 |

## 21.11 设计问题

{callout("question", "请写入项目设计", "哪些维度静态？哪些允许有限集合？是否生成运行期守卫？守卫失败交给哪个后端？设备间复制由 VM、DeviceAPI 还是 NPU Runtime 完成？状态由谁拥有？设备失败是否允许重试？")}
""",
)


write(
    "22-正确性测试与持续集成.md",
    f"""
{frontmatter}
# 22. 正确性测试与持续集成

{callout("abstract", "本章内容", "本章建立从模式注册、分区、代码生成、模块保存、运行时、驱动到模型结果的测试金字塔，并给出 CI 配置、随机测试、异常注入和回归资产管理方法。")}

## 22.1 测试金字塔

```mermaid
flowchart TB
    A["少量完整模型与系统压力"] 
    B["子图与组合运算"]
    C["单运算设备对照"]
    D["代码生成与命令静态检查"]
    E["分区 / Pass / IR 结构"]
    F["纯函数与数据排布"]
    F --> E --> D --> C --> B --> A
```

越靠下的测试数量越多、执行越快、定位越直接。完整模型测试不能替代数据排布和命令字段单测。

## 22.2 Python 编译器测试

### 模式注册

```python
patterns = get_patterns_with_prefix("acme_npu")
names = {{p.name for p in patterns}}
assert "acme_npu.matmul_bias_relu" in names
```

### 结构比较

构造输入模块、运行单个 Pass，并与期望模块执行：

```python
tvm.ir.assert_structural_equal(actual, expected)
```

覆盖被接纳与不被接纳的情况。每条硬件限制至少有一个刚好满足和一个刚好不满足的样本。

### 重复执行

同一 Pass 连续运行两次，第二次不应继续产生新函数或多套属性。相同输入和配置应得到结构相同的输出。

## 22.3 C++ 代码生成测试

不连接真实设备也可测试：

- 外部函数符号；
- 运算属性读取；
- 常量索引；
- 排布选择；
- 工作区大小；
- 命令数量；
- 地址重定位项；
- 固件 ABI；
- 非法输入错误；
- 二进制保存与加载。

对命令包做“编译 → 反汇编 → 再编码”往返测试，保证字段工具与编码器一致。

## 22.4 单运算设备测试

每个运算按 [[30-自研 NPU 算子接入分册]] 的合同建立尺寸集合。以 MatMul 为例：

- M、N、K 等于 1；
- 每个维度为物理 tile 的前一值、整值和后一值；
- 长条矩阵、方阵、批矩阵；
- 极值、随机值、稀疏值；
- bias、激活与无 bias；
- 重复运行和并发；
- 输入输出地址对齐与故意未对齐。

设备结果同时与高精度参考和位准确参考比较。

## 22.5 组合运算测试

组合运算应证明中间值未写回片外，而不仅是结果正确。可通过：

- 命令反汇编中不存在中间 store/load；
- 设备性能计数器的片外字节减少；
- 中间逻辑缓冲区被分配到片上；
- 与拆分执行结果比较；
- 组合开关关闭时仍能正确运行。

## 22.6 模型测试

模型集按网络结构选择，不只按知名度：

| 结构 | 代表关注点 |
| --- | --- |
| CNN | Conv、Depthwise、Pool、残差 |
| MLP | MatMul、bias、激活 |
| Transformer encoder | Attention、Norm、GELU |
| Decoder | KV Cache、动态 sequence、状态 |
| RNN / LSTM | 循环状态、门函数 |
| 检测模型 | 多输出、NMS 主机保留 |

保存模型来源、散列值、输入预处理、源框架版本和参考输出。

## 22.7 属性测试与随机测试

适合自动生成的性质：

- 打包后解包得到原始值；
- 重排后反排得到原始 Tensor；
- tile 切分覆盖每个逻辑元素恰好一次；
- 生命周期分配的同时存活缓冲区不重叠；
- 命令依赖图无环；
- 每个读取都有先前写入或输入来源；
- 静态检查接受的命令可被参考解释器执行；
- 同一输入多次编译结构稳定。

失败的随机种子必须保存为固定回归样本。

## 22.8 异常注入

| 注入位置 | 示例 |
| --- | --- |
| 编译器 | 不受支持 dtype、缺少属性、过大工作区 |
| 模块加载 | 错误 magic、截断文件、ABI 不兼容 |
| 内存 | 申请失败、未对齐、越界重定位 |
| 驱动 | busy、timeout、ioctl 错误 |
| 固件 | 非法 opcode、事件不存在、看门狗 |
| 硬件 | DMA fault、执行单元错误、中断丢失 |

异常测试确认错误码、资源清理、设备状态和后续恢复，而不只是确认进程退出。

## 22.9 CI 构建矩阵

```text
1. TVM compiler + acme codegen + acme runtime
2. TVM runtime-only + acme runtime
3. compiler without acme flags
4. Debug + assertions
5. RelWithDebInfo
6. Python unit tests
7. C++ unit tests
8. 模块导出/新进程加载
9. 模拟器设备测试
10. 每日真实板卡测试
```

真实板卡数量有限时，提交级 CI 运行编译器与模拟器，每日或合入队列运行板卡。板卡任务要锁定设备、记录温度频率和固件版本。

## 22.10 精度与性能门限

功能门限与性能门限分开。功能不通过时性能结果无效。建议门限包括：

- 位级或误差要求；
- 子图接纳数量不得意外下降；
- 编译时间；
- 产物大小；
- 峰值内存；
- 端到端时延；
- 片外字节；
- 设备错误率；
- 长时间运行稳定性。

性能波动要使用统计范围，避免一次测量造成误报。

## 22.11 回归资产

每个失败问题留下：

1. 最小模型或 IRModule；
2. 输入与常量；
3. Target 和后端配置；
4. 期望结果；
5. 失败产物或命令摘要；
6. 软件、固件和硬件版本；
7. 首次失败阶段；
8. 修复后的测试名称。

## 22.12 官方依据

- [Testing TVM]({BASE_URL}/contribute/testing.html)
- [Example NPU tests]({GITHUB_BLOB}/tests/python/contrib/test_example_npu.py)
- [Pass Infrastructure]({BASE_URL}/arch/pass_infra.html)
""",
)


write(
    "26-端到端参考实现骨架.md",
    f"""
{frontmatter}
# 26. 端到端参考实现骨架

{callout("abstract", "本章内容", "本章把前面章节组合成一个可落地的目录、构建开关、Python 分区入口、C++ 代码生成入口、运行时入口和测试命令。代码是项目骨架，需要用真实硬件合同替换示例检查和空壳执行。")}

## 26.1 建议目录

```text
tvm/
├── cmake/modules/contrib/AcmeNPU.cmake
├── python/tvm/relax/backend/contrib/acme_npu/
│   ├── __init__.py
│   ├── patterns.py
│   ├── pipeline.py
│   └── diagnostics.py
├── src/relax/backend/contrib/acme_npu/
│   ├── codegen.cc
│   ├── compiler.cc
│   ├── compiler.h
│   ├── artifact.cc
│   └── artifact.h
├── src/runtime/contrib/acme_npu/
│   ├── runtime.cc
│   ├── driver_api.cc
│   ├── driver_api.h
│   └── module_format.cc
├── tests/python/contrib/
│   ├── test_acme_npu_patterns.py
│   ├── test_acme_npu_codegen.py
│   └── test_acme_npu_runtime.py
└── tests/cpp/contrib/
    └── acme_npu/
```

## 26.2 Python 初始化

```python
# python/tvm/relax/backend/contrib/acme_npu/__init__.py
from .patterns import *  # 注册 FusionPattern
from .pipeline import partition_for_acme_npu
```

## 26.3 模式与检查

```python
# patterns.py
from tvm import relax
from tvm.relax.dpl import is_op, wildcard
from tvm.relax.transform import FusionPattern
from tvm.relax.backend.pattern_registry import register_patterns

def make_matmul_relu():
    x, w = wildcard(), wildcard()
    mm = is_op("relax.matmul")(x, w)
    out = is_op("relax.nn.relu")(mm)

    def check(ctx):
        xi = ctx.annotated_expr["x"].struct_info
        wi = ctx.annotated_expr["w"].struct_info
        if not isinstance(xi, relax.TensorStructInfo):
            return False
        if not isinstance(wi, relax.TensorStructInfo):
            return False
        if str(xi.dtype) != "int8" or str(wi.dtype) != "int8":
            return False
        return xi.ndim == 2 and wi.ndim == 2

    return FusionPattern(
        name="acme_npu.matmul_relu",
        pattern=out,
        annotation_patterns={{"x": x, "w": w, "matmul": mm, "root": out}},
        check=check,
    )

register_patterns([make_matmul_relu()])
```

正式版本把 shape、排布、对齐、bias、累加、尾部和能力寄存器加入检查。纯函数返回详细结果，DPL 包装只返回布尔值。

## 26.4 分区入口

```python
# pipeline.py
from tvm.relax.backend.pattern_registry import get_patterns_with_prefix
from tvm.relax.transform import (
    FuseOpsByPattern,
    MergeCompositeFunctions,
    RunCodegen,
)


def partition_for_acme_npu(mod, run_codegen=True):
    patterns = get_patterns_with_prefix("acme_npu")
    mod = FuseOpsByPattern(
        patterns,
        bind_constants=False,
        annotate_codegen=True,
    )(mod)
    mod = MergeCompositeFunctions()(mod)
    if run_codegen:
        mod = RunCodegen()(mod)
    return mod
```

## 26.5 编译脚本

```python
import numpy as np
import torch
import tvm
from tvm import relax
from tvm.relax.frontend.torch import from_exported_program
from tvm.relax.backend.contrib.acme_npu import partition_for_acme_npu

model = MyModel().eval()
example = (torch.randn(1, 128),)

with torch.no_grad():
    ep = torch.export.export(model, example)
    mod = from_exported_program(
        ep,
        keep_params_as_input=True,
        unwrap_unit_return_tuple=True,
    )

mod, params = relax.frontend.detach_params(mod)
mod = relax.get_pipeline("zero")(mod)
mod = partition_for_acme_npu(mod)

host = tvm.target.Target("llvm")
ex = tvm.compile(mod, target=host)
ex.export_library("model_acme.so")
np.savez("model_params.npz", *params["main"])
```

实际低比特模型需要在导入前或自定义 Pass 中建立所需整数图；示例 `torch.randn` 仅说明前端调用。

## 26.6 C++ 编译器注册

```cpp
ffi::Array<ffi::Module> AcmeNPUCompiler(
    ffi::Array<relax::Function> functions,
    ffi::Map<ffi::String, ffi::Any> options,
    ffi::Map<relax::Constant, ffi::String> constant_names) {{
  ffi::Array<ffi::Module> result;
  auto create = ffi::Function::GetGlobalRequired(
      "runtime.AcmeNPURuntimeCreate");
  for (const auto& func : functions) {{
    auto artifact = acme::Compile(func, options, constant_names);
    result.push_back(create(
        relax::GetExtSymbol(func),
        artifact.bytes,
        artifact.metadata,
        artifact.constants).cast<ffi::Module>());
  }}
  return result;
}}

TVM_FFI_STATIC_INIT_BLOCK() {{
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef().def("relax.ext.acme_npu", AcmeNPUCompiler);
}}
```

## 26.7 运行时入口

运行时模块应向 TVM 暴露外部符号对应函数：

```cpp
void Run(ffi::PackedArgs args) {{
  Invocation inv = ValidateAndBind(args, metadata_);
  DeviceWorkspace ws = workspace_pool_->Acquire(inv.workspace_bytes);
  RelocatedProgram prog = Relocate(program_, inv, ws);
  Event event = driver_->Submit(prog, inv.queue);
  driver_->Wait(event, timeout_ms_);
  driver_->CheckResult(event);
}}
```

`ValidateAndBind` 核对 Tensor；`Relocate` 只处理逻辑地址；`Submit` 返回事件；`Wait` 有超时；`CheckResult` 把设备状态转换为详细错误。

## 26.8 CMake

```cmake
# config.cmake
set(USE_LLVM "llvm-config --ignore-libllvm --link-static")
set(USE_ACME_NPU_CODEGEN ON)
set(USE_ACME_NPU_RUNTIME ON)
```

```cmake
# cmake/modules/contrib/AcmeNPU.cmake
if(USE_ACME_NPU_CODEGEN)
  tvm_file_glob(GLOB ACME_COMPILER
    src/relax/backend/contrib/acme_npu/*.cc)
  list(APPEND COMPILER_SRCS ${{ACME_COMPILER}})
endif()

if(USE_ACME_NPU_RUNTIME)
  tvm_file_glob(GLOB ACME_RUNTIME
    src/runtime/contrib/acme_npu/*.cc)
  list(APPEND RUNTIME_SRCS ${{ACME_RUNTIME}})
endif()
```

还需在顶层 CMake 选项区声明 `USE_ACME_NPU_CODEGEN` 与 `USE_ACME_NPU_RUNTIME`，并 include 本模块。

## 26.9 构建与检查

```bash
git clone --recursive git@github.com:apache/tvm.git
cd tvm
git checkout v0.24.0
mkdir -p build
cp cmake/config.cmake build/config.cmake
cd build
cmake ..
cmake --build . --parallel
```

```python
import tvm
print(tvm.get_global_func("relax.ext.acme_npu", True))
print(tvm.get_global_func("runtime.AcmeNPURuntimeCreate", True))
print(tvm.support.libinfo()["GIT_COMMIT_HASH"])
```

## 26.10 测试命令

```bash
python -m pytest tests/python/contrib/test_acme_npu_patterns.py -v
python -m pytest tests/python/contrib/test_acme_npu_codegen.py -v
python -m pytest tests/python/contrib/test_acme_npu_runtime.py -v
```

板卡测试应通过设备锁或专用测试服务运行，保存固件版本、设备编号和运行日志。

## 26.11 首个真实演示

建议选择 INT8 MatMul+ReLU：

1. M=3、K=33、N=17，强制覆盖三个维度尾部；
2. 输入包含最小值、最大值、0、1、-1；
3. bias 可开关；
4. 编译日志显示一个外部组合；
5. 命令反汇编显示 DMA、Matrix、ReLU、Store；
6. 设备结果与位准确参考相同；
7. 导出共享库后在新进程重复运行；
8. 故意修改 ABI 版本时加载被拒绝；
9. 故意触发超时时资源可恢复；
10. 性能报告分离复制、提交、执行和等待时间。

## 26.12 后续扩展

按收益依次增加：MatMul+Bias+Activation、BMM、Softmax、Norm、逐元素、数据排布传播、动态 sequence、多外部函数设备驻留、异步执行、自动调优。每次扩展都同步更新运算合同、Target 能力、编译器、运行时、参考模型和测试。

## 26.13 官方起点

- [BYOC NPU tutorial]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html)
- [Example NPU Python]({GITHUB}/python/tvm/relax/backend/contrib/example_npu)
- [Example NPU codegen]({GITHUB_BLOB}/src/relax/backend/contrib/example_npu/codegen.cc)
- [Example NPU runtime]({GITHUB_BLOB}/src/runtime/contrib/example_npu/example_npu_runtime.cc)
- [Example NPU test]({GITHUB_BLOB}/tests/python/contrib/test_example_npu.py)
""",
)

operators = [
    {
        "name": "MatMul",
        "relax": "`relax.matmul`",
        "engine": "Matrix Engine",
        "contract": "对最后两个轴执行矩阵乘法，可选前导批维；二维情形为 C[M,N]=A[M,K]×B[K,N]。",
        "attrs": "输入秩、批维广播、M/N/K、两个输入 dtype、输出 dtype、是否转置、bias 与激活组合。",
        "accept": "K 维一致；dtype 被硬件接受；批维广播属于固件支持集合；K 与 N 可由矩阵块或尾部方案覆盖；累加上界安全。",
        "tile": "优先按物理矩阵块拆分 M/N/K，B tile 在 N 方向复用，C 部分和在 K tile 间保持。片上空间同时容纳 A、B、C 与双缓冲。",
        "tail": "M/N 尾部可掩码或填充；K 尾部的填充值必须符合 zero point 规则；若硬件不支持，保留给主机或生成向量尾部。",
        "numeric": "明确乘积宽度、累加宽度、bias 域、固定乘数、右移、舍入和饱和；per-channel 参数沿 N 轴。",
        "tests": "M/N/K 分别取 1、块前一值、整块、块后一值；长条矩阵；极值；有无 bias；批维广播；动态 K；多次累加。",
        "fallback": "无法证明尺寸、广播或累加安全时不接纳；代码生成阶段不应静默改成不同数学计算。",
        "perf": "MAC 数、A/B/C 字节、权重复用、部分和写回、矩阵忙碌周期、DMA 等待与尾部利用率。",
    },
    {
        "name": "Batch MatMul",
        "relax": "`relax.matmul` 的批维形式",
        "engine": "Matrix Engine + DMA",
        "contract": "对每个批索引独立完成矩阵乘法，批维可以完全一致或按 Relax 规则广播。",
        "attrs": "批维数量、每个批维尺寸、广播方向、M/N/K、输入排布和 stride。",
        "accept": "硬件可以表达批 stride；广播输入可被重复引用；批数与命令数不超过上限；每个批项工作区可复用。",
        "tile": "内层仍按 M/N/K 分块，外层批索引可串行、并行或由命令 repeat 字段处理。权重批为 1 时优先复用。",
        "tail": "批尾部通常无需特殊处理；矩阵尾部沿用 MatMul 规则；动态批要有上限。",
        "numeric": "每批可共享或独立 scale；若参数按批变化，元数据和设备读取必须表达该轴。",
        "tests": "批为 1、2、上限；A 广播、B 广播、无广播；批 stride 不连续；M/N/K 尾部；不同批输入极值。",
        "fallback": "复杂广播无法直接执行时，可在图中显式扩展，但需比较复制成本；收益不足时交给主机。",
        "perf": "每批提交数、权重复用命中、批间空隙、队列占用、总 MAC 与片外字节。",
    },
    {
        "name": "Conv2D",
        "relax": "`relax.nn.conv2d`",
        "engine": "Conv Engine 或 Matrix Engine",
        "contract": "按指定数据排布、kernel、stride、padding、dilation 与 groups 计算二维卷积。",
        "attrs": "data_layout、kernel_layout、out_layout、strides、padding、dilation、groups、channels、kernel_size。",
        "accept": "布局在允许集合；kernel 与 dilation 被支持；groups 为 1 或有专用模式；通道与空间尺寸可分块；输出尺寸为正。",
        "tile": "按输出高宽与输出通道分块，输入 tile 加入 halo；权重按输出通道块预排；卷积可改写为矩阵运算或直接滑窗。",
        "tail": "空间尾部由 padding 与掩码处理；输入通道和输出通道尾部需填充或小块命令；不得读取逻辑 padding 外的非法地址。",
        "numeric": "卷积累加与 MatMul 类似；bias 多沿输出通道；padding 值在非零 zero point 情况下要取对应整数。",
        "tests": "1×1、3×3、非方 kernel；stride 1/2；各类 padding；dilation；通道尾部；极小空间；大图分块。",
        "fallback": "不被支持的布局、dilation、groups 或动态 kernel 直接保留；不要在运行时临时改变卷积定义。",
        "perf": "有效 MAC、halo 重复载入、权重字节、输入复用、输出写回、卷积单元忙碌与尾部浪费。",
    },
    {
        "name": "Conv1D",
        "relax": "`relax.nn.conv1d`",
        "engine": "Conv Engine 或 Vector Engine",
        "contract": "沿一个空间或时间轴执行卷积，常用于音频、时序和部分序列模型。",
        "attrs": "NCW/NWC、kernel layout、stride、padding、dilation、groups、输入长度和通道。",
        "accept": "输入秩为 3；布局明确；kernel 和通道满足硬件；长度可分块；状态型流式模式与普通全序列模式分开。",
        "tile": "按输出长度与通道分块，输入 tile 加入左右 halo；流式场景可保留前一段历史样本。",
        "tail": "长度尾部按 padding 规则；通道尾部按向量或矩阵块处理；空输出应在编译期识别。",
        "numeric": "累加、bias、输出换算与 Conv2D 一致；流式状态不能重复换算。",
        "tests": "长度 1、kernel-1、kernel、长序列；causal padding；stride；dilation；通道尾部；分段与整段结果一致。",
        "fallback": "固件无历史状态或不支持 dilation 时留给主机；不把因果卷积当作普通对称 padding。",
        "perf": "每输出样本 MAC、历史状态读取、halo 重复、通道利用率和流式启动开销。",
    },
    {
        "name": "Depthwise Conv2D",
        "relax": "`relax.nn.conv2d` 且 groups 与输入通道相关",
        "engine": "Depthwise/Conv Engine",
        "contract": "每个输入通道独立卷积，可带 channel multiplier；它不是普通 groups>1 的唯一情况。",
        "attrs": "groups、输入通道、输出通道、channel multiplier、布局、kernel、stride、padding、dilation。",
        "accept": "严格核对 groups 与通道关系；硬件接受 multiplier；通道排列符合专用单元；空间分块可覆盖 halo。",
        "tile": "按通道组和输出空间分块，权重很小但输入复用有限；避免转换成巨大稀疏普通卷积。",
        "tail": "通道不足物理并行宽度时使用掩码或填充；空间尾部与 Conv2D 相同。",
        "numeric": "每个输出通道有独立 bias 和 scale；累加 K 为 kernel 元素数，通常小于普通卷积。",
        "tests": "multiplier 1 和大于 1；通道前一值、整块、后一值；3×3/5×5；stride 2；不同 padding。",
        "fallback": "普通 grouped conv 不得误当 depthwise；不符合专用关系时尝试普通 Conv 或主机。",
        "perf": "通道并行利用率、输入字节、权重缓存、空间边缘开销和专用单元忙碌。",
    },
    {
        "name": "Add",
        "relax": "`relax.add`",
        "engine": "Vector Engine",
        "contract": "按 Relax 广播规则逐元素相加。",
        "attrs": "两个输入 shape、广播轴、dtype、输出 shape、是否为 bias 加法。",
        "accept": "广播形式可由硬件 stride 表达；dtype 相容；输出元素数与地址范围合法；输入别名安全。",
        "tile": "沿连续末轴按向量宽度处理，外层轴由循环或描述符推进；标量和 bias 广播可复用小输入。",
        "tail": "最后一个向量使用 lane mask 或标量尾部；禁止写出输出缓冲区。",
        "numeric": "定义加法临时宽度、是否立即饱和、两个输入 scale 不同时如何对齐，以及输出 scale。",
        "tests": "同形、标量广播、通道 bias、多个前导 1、尾部 lane、正负饱和、输入输出别名。",
        "fallback": "无法表达的多轴广播或不同 dtype 组合留给主机，或先插入显式扩展。",
        "perf": "元素数、读 2 写 1 字节、向量 lane 利用率、广播缓存命中和启动周期。",
    },
    {
        "name": "Subtract",
        "relax": "`relax.subtract`",
        "engine": "Vector Engine",
        "contract": "按广播规则执行有序的 x-y，两个输入不可交换。",
        "attrs": "输入顺序、shape、广播、dtype、输出换算参数。",
        "accept": "与 Add 类似，但必须保留操作数顺序；硬件减法或加负数实现的溢出规则一致。",
        "tile": "连续末轴采用向量并行，广播输入复用；可与前后逐元素运算组合。",
        "tail": "向量尾部掩码；标量广播值保持有效；别名时先确认读完成。",
        "numeric": "负数、最小值取反和饱和是重点；若用 x+(-y)，最小整数取反需更宽临时值。",
        "tests": "x-y 与 y-x；最小值；结果刚好越界；广播；尾部；原地 x=x-y。",
        "fallback": "硬件只能无饱和减法而合同要求饱和时，不得接纳。",
        "perf": "读写带宽、lane 利用率、组合后中间写回减少量。",
    },
    {
        "name": "Multiply",
        "relax": "`relax.multiply`",
        "engine": "Vector Engine / 共享 MAC",
        "contract": "按广播规则逐元素相乘。",
        "attrs": "shape、广播、输入 dtype、乘积宽度、输出 dtype 与换算参数。",
        "accept": "乘积临时宽度足够；广播可表达；缩放参数可由硬件后处理。",
        "tile": "沿连续轴采用向量并行；若与 Add 组合可生成 FMA；常量乘法可预计算固定乘数。",
        "tail": "lane mask 或标量尾部；INT4 半字节写需要读改写或专用掩码。",
        "numeric": "明确乘积是全精度后换算，还是先截断；FMA 是否只舍入一次。",
        "tests": "0、1、-1、最小最大值、刚好溢出、不同 scale、广播、FMA 对照。",
        "fallback": "合同需要宽乘积而硬件只保留低位时留给主机。",
        "perf": "乘法器利用率、共享 PE 冲突、读写字节与 FMA 组合收益。",
    },
    {
        "name": "Divide",
        "relax": "`relax.divide`",
        "engine": "Vector/CME",
        "contract": "逐元素除法并遵守广播；整数与浮点输入的行为不同。",
        "attrs": "dtype、除数范围、除零处理、舍入方式、广播和输出类型。",
        "accept": "设备实现与 Relax 期望一致；除零行为明确；整数负数除法方向一致。",
        "tile": "向量分块；可将常量除数转换为倒数乘法，但要证明误差和特殊值处理。",
        "tail": "向量尾部与广播同其他逐元素运算。",
        "numeric": "除零、最小整数除以 -1、负数舍入和倒数近似是重点。",
        "tests": "正负组合、除数 0/1/-1、极值、常量除数、很小除数、广播与尾部。",
        "fallback": "特殊值或误差无法满足要求时交给主机，不应用未说明的倒数近似。",
        "perf": "每元素周期、CME 占用、倒数查表命中和与乘法组合收益。",
    },
    {
        "name": "ReLU 与 ReLU6",
        "relax": "`relax.nn.relu`、`relax.nn.relu6`",
        "engine": "Activation/Vector Engine",
        "contract": "ReLU 输出 max(x,0)，ReLU6 输出 min(max(x,0),6)。",
        "attrs": "输入输出 dtype、zero point、实数 6 对应的整数阈值和是否原地写。",
        "accept": "阈值可准确或按合同允许误差表示；数据连续或 stride 可表达；可与生产者组合。",
        "tile": "按向量宽度处理；与 MatMul、Conv、Add 组合时直接处理累加结果，避免中间写回。",
        "tail": "lane mask；INT4 写半字节规则明确。",
        "numeric": "整数零对应 zero point，不一定是存储值 0；ReLU6 阈值由输出 scale 和 zero point 得到。",
        "tests": "阈值两侧、刚好等于阈值、最小最大值、不同 zero point、组合与单独执行一致。",
        "fallback": "若组合后的换算次序与单独执行不同，必须作为不同合同测试。",
        "perf": "组合后减少的字节、比较器利用率、独立启动开销。",
    },
    {
        "name": "Sigmoid",
        "relax": "`relax.nn.sigmoid`",
        "engine": "CME / LUT",
        "contract": "逐元素计算 1/(1+exp(-x))，输出在 0 与 1 之间。",
        "attrs": "输入实数范围、输出 scale、查表或多项式版本、允许误差。",
        "accept": "dtype 和参数格式被固件接受；输入区间有定义；输出表示可以覆盖 0 到 1。",
        "tile": "向量批量送入 CME，片上暂存隐藏函数单元延迟；可与门运算组合。",
        "tail": "向量尾部；超出近似区间的输入按饱和规则。",
        "numeric": "检查单调性、sigmoid(0)、对称关系 f(-x)=1-f(x) 的允许误差及端点饱和。",
        "tests": "0、正负小值、区间端点、超范围、大量随机、单调序列、LSTM 门组合。",
        "fallback": "固件函数版本与编译器表不一致时拒绝加载。",
        "perf": "CME 每元素周期、查表带宽、向量批大小和与周围运算组合收益。",
    },
    {
        "name": "Tanh",
        "relax": "`relax.nn.tanh`",
        "engine": "CME / LUT",
        "contract": "逐元素双曲正切，输出在 -1 与 1 之间。",
        "attrs": "输入区间、输出 scale、近似版本、误差要求。",
        "accept": "设备函数版本一致；有符号输出范围可表示；输入 dtype 被接受。",
        "tile": "与 Sigmoid 类似，可批量执行；RNN 中与门乘法组合。",
        "tail": "超区间按正负饱和；lane 尾部掩码。",
        "numeric": "检查奇函数性质、tanh(0)、单调性、端点和零附近精度。",
        "tests": "正负对称输入、0、区间端点、随机值、RNN 状态极值。",
        "fallback": "输出 scale 无法表示对称范围或误差超限时留给主机。",
        "perf": "每元素周期、CME 队列等待、组合后的片外字节。",
    },
    {
        "name": "GELU 与 SiLU",
        "relax": "`relax.nn.gelu` 与对应 SiLU 表达式",
        "engine": "CME / Vector Engine",
        "contract": "GELU 使用标准或近似公式；SiLU 为 x·sigmoid(x)。具体公式版本必须写入合同。",
        "attrs": "公式版本、输入区间、dtype、近似系数、输出换算参数。",
        "accept": "前端表达式与固件公式版本相同；组合模式没有遗漏常数或不同近似。",
        "tile": "按向量块执行，乘法与特殊函数流水配合；可与 MatMul 输出组合。",
        "tail": "向量尾部；超出设计区间按规定处理。",
        "numeric": "GELU 精确 erf 形式与 tanh 近似不可混为一体；SiLU 的乘法临时精度需明确。",
        "tests": "0、正负端点、公式差异较大区间、随机输入、单调与导数变化附近。",
        "fallback": "模型使用不同公式版本时不接纳组合，保留原图。",
        "perf": "CME 与乘法单元重叠、每元素周期、融合后内存节省。",
    },
    {
        "name": "Softmax",
        "relax": "`relax.nn.softmax`",
        "engine": "CME + Vector + Reduction",
        "contract": "沿指定轴执行稳定 Softmax：先减最大值，再指数、求和和除法。",
        "attrs": "axis、轴长度、输入输出 dtype、scale、是否带 mask、mask 形式。",
        "accept": "axis 可由硬件处理；轴长度在工作区范围；mask 组合被明确支持；归约精度满足要求。",
        "tile": "一行可能分成多个块，第一遍求最大，第二遍求指数和，第三遍归一；也可片上保留中间值减少重读。",
        "tail": "归约轴尾部使用无效 lane；最大值填充值为负无穷的设备对应值；求和忽略无效 lane。",
        "numeric": "必须使用稳定算法；指数近似、和的累加宽度、倒数精度、输出和接近 1 的误差都有要求。",
        "tests": "全相等、单个极大值、很大正负差、轴长 1、tile 前后、带 mask、长序列。",
        "fallback": "不被支持的 axis 或 mask 形式留给主机；不把任意 add mask 都误认成 Attention mask。",
        "perf": "行数、轴长、读取遍数、CME 利用率、片上中间存储和长轴停顿。",
    },
    {
        "name": "LayerNorm",
        "relax": "LayerNorm 组合或 `relax.nn.layer_norm`",
        "engine": "CME + Reduction + Vector",
        "contract": "沿指定轴计算均值与方差，再执行归一和可选 gamma、beta。",
        "attrs": "axes、epsilon、center、scale、gamma/beta shape、dtype 与内部精度。",
        "accept": "轴通常为末轴或连续轴；epsilon 可表示；工作区足够；gamma/beta 广播可处理。",
        "tile": "长轴分块归约，使用稳定的两遍算法或 Welford；最终逐元素归一。",
        "tail": "归约尾部排除无效 lane；统计元素数使用真实长度。",
        "numeric": "方差算法、内部 FP32 或定点格式、epsilon 相加位置、rsqrt 误差和输出换算明确。",
        "tests": "常量输入、方差极小、大均值小方差、轴长 1、长轴、不同 epsilon、gamma/beta 极值。",
        "fallback": "非连续多轴或内部精度不足时留给主机。",
        "perf": "读取遍数、归约周期、CME rsqrt 周期、gamma/beta 带宽与片上复用。",
    },
    {
        "name": "RMSNorm",
        "relax": "RMSNorm 组合表达式",
        "engine": "CME + Reduction + Vector",
        "contract": "计算均方根而不减均值，再乘权重：x·rsqrt(mean(x²)+epsilon)·weight。",
        "attrs": "axis、epsilon、weight shape、内部精度、输入输出 dtype。",
        "accept": "组合结构完整；axis 可处理；平方和不会溢出；weight 广播正确。",
        "tile": "第一遍求平方和，第二遍乘倒数平方根与 weight；输入可片上保留或重读。",
        "tail": "平方和只统计有效元素；向量尾部掩码。",
        "numeric": "平方临时宽度、平方和、除以元素数、epsilon、rsqrt 和最终乘法次序明确。",
        "tests": "全零、常量、极值、长轴、轴长 1、epsilon 边缘、Transformer 隐藏维常见尺寸。",
        "fallback": "模式缺少 weight 或额外 cast 改变行为时，不应用过窄组合。",
        "perf": "读取次数、平方 MAC、归约与 rsqrt 时间、weight 带宽。",
    },
    {
        "name": "Reduce Sum / Max / Mean",
        "relax": "`relax.sum`、`relax.max`、`relax.mean`",
        "engine": "Reduction / Vector Engine",
        "contract": "沿一个或多个轴归约，可保留或删除归约轴。",
        "attrs": "axis、keepdims、输入输出 dtype、初始值、空轴行为。",
        "accept": "轴在允许集合；连续或可经排布处理；归约长度上限明确；输出 shape 正确。",
        "tile": "分块产生部分结果，再进行树形或串行合并；多个轴可先合并为连续段。",
        "tail": "Sum/Mean 无效 lane 填 0，Max 填类型最小值；Mean 除数是真实元素数。",
        "numeric": "Sum 累加宽度、Max 比较规则、Mean 除法和舍入明确；空归约按 Relax 行为。",
        "tests": "每个轴、负 axis、多轴、keepdims、长度 1、长轴、尾部、全最小值。",
        "fallback": "不支持的非连续轴可先转置，但需比较代价；空维行为不一致时留给主机。",
        "perf": "有效元素数、归约树深度、部分结果字节、转置成本和单元利用率。",
    },
    {
        "name": "Reshape / Flatten / Squeeze",
        "relax": "`relax.reshape` 等形状运算",
        "engine": "元数据处理或 DMA",
        "contract": "若元素线性次序不变且输入连续，只改变视图；否则需要真实复制。",
        "attrs": "旧 shape、新 shape、元素总数、stride、byte_offset 与连续性。",
        "accept": "元素数量相同；运行时可表示视图；外部函数 ABI 接受新 shape；无隐含轴次序变化。",
        "tile": "纯视图无需 tile；真实复制按 DMA burst 分块。",
        "tail": "复制尾部按字节数处理；视图不访问数据。",
        "numeric": "不改变元素值，任何 dtype 转换都不属于纯 Reshape。",
        "tests": "包含 1 维、-1 推断、零长度、非连续输入、带 offset、前后往返。",
        "fallback": "无法表达 stride 时插入连续化复制，或保留给主机。",
        "perf": "区分零成本视图与真实复制，禁止把二者统计在一起。",
    },
    {
        "name": "PermuteDims / Transpose",
        "relax": "`relax.permute_dims`",
        "engine": "DMA 重排或 Vector",
        "contract": "按 axes 重新排列维度，改变元素地址次序。",
        "attrs": "输入秩、axes、shape、dtype、目标对齐。",
        "accept": "axes 是合法排列；有对应重排内核；工作区足够；可与前后运算吸收时优先吸收。",
        "tile": "按二维或多维块重排，tile 兼顾连续读和连续写；小块使用片上暂存。",
        "tail": "每个物理轴的尾部都需保护；不能只处理方阵。",
        "numeric": "值不变，位模式应完全相同。",
        "tests": "2D 转置、4D NCHW↔NHWC、任意排列、含 1 轴、非方尺寸、所有轴尾部。",
        "fallback": "组合运算可直接读取源排布时删除独立重排；否则主机或 DMA 内核。",
        "perf": "读写字节、burst 长度、bank 冲突、片上 tile 与组合消除次数。",
    },
    {
        "name": "Concat",
        "relax": "`relax.concat`",
        "engine": "DMA",
        "contract": "沿指定轴连接多个 Tensor，非连接轴必须相等。",
        "attrs": "输入数量、axis、每个 shape、dtype 与输出 shape。",
        "accept": "输入数量和总命令数在上限；非连接轴一致；每段复制可表达；dtype 相同。",
        "tile": "若连接轴是连续末段，可逐输入大块复制；否则按外层索引交错复制。",
        "tail": "每个输入独立处理字节尾部；输出偏移累加不得溢出。",
        "numeric": "位模式不变。",
        "tests": "2 到最大输入数、不同段长度、axis 0/中间/末轴、零长度段、INT4 奇数元素。",
        "fallback": "输入过多或 stride 复杂时主机处理；也可在消费者中直接使用分段输入避免物理连接。",
        "perf": "总复制字节、DMA 命令数、每段长度和消费者吸收收益。",
    },
    {
        "name": "Split",
        "relax": "`relax.split`",
        "engine": "视图或 DMA",
        "contract": "沿轴按索引或等份拆成多个输出。",
        "attrs": "axis、分割点、输出数量、输入 shape、stride。",
        "accept": "分割点有序且范围合法；输出可表示为视图或复制；外部函数支持多输出。",
        "tile": "连续段可使用带 offset 视图；非连续段按外层轴复制。",
        "tail": "每个输出有独立长度与字节尾部。",
        "numeric": "值不变；多输出顺序必须稳定。",
        "tests": "等分、不等分、空段、axis 各位置、多输出绑定、视图 offset。",
        "fallback": "运行时不支持带 offset Tensor 时生成复制；命令数过多时主机处理。",
        "perf": "零复制输出数量、实际复制字节、命令数和后续消费者能否直接读取。",
    },
    {
        "name": "Take / Gather",
        "relax": "`relax.take` 及前端 Gather 形式",
        "engine": "Vector + DMA",
        "contract": "按索引从指定轴取得元素或切片。",
        "attrs": "axis、indices dtype/shape、越界处理、输入 stride、输出 shape。",
        "accept": "索引 dtype 被支持；越界行为一致；访问粒度与地址生成单元能力匹配。",
        "tile": "索引分块，尽量合并连续索引为 burst；随机索引可能需要缓存。",
        "tail": "输出向量尾部；索引本身的尾部；无效索引按合同处理。",
        "numeric": "数据值不变，重点是索引负值和越界规则。",
        "tests": "连续、逆序、重复、随机、负索引、越界、空 indices、多维 indices。",
        "fallback": "硬件只支持 axis 0 或不支持负索引时严格检查，其他情况主机处理。",
        "perf": "有效带宽、burst 合并率、缓存命中、索引解析周期。",
    },
    {
        "name": "Embedding",
        "relax": "权重表上的 `take`/Gather 组合",
        "engine": "DMA / Gather",
        "contract": "按 token id 读取词表行，输出增加隐藏维。",
        "attrs": "vocab、hidden、token dtype、padding id、权重 dtype 和排布。",
        "accept": "token id 范围可检查；隐藏行满足 DMA；权重表在可访问内存；padding 行行为明确。",
        "tile": "按 token 分批读取，每行可分多个 burst；重复 token 可选缓存，但必须保持输出顺序。",
        "tail": "隐藏维字节尾部；最后一批 token；INT4 行打包。",
        "numeric": "值按权重位模式读取；若读取后转换 dtype，应作为显式步骤。",
        "tests": "id 0、最大合法 id、重复 id、padding id、越界、长序列、INT4 奇数 hidden。",
        "fallback": "设备不能随机访问大词表时在主机 Gather，再把激活送 NPU；需计入复制成本。",
        "perf": "词表读字节、重复命中、随机访问时延、token 吞吐和主机复制。",
    },
    {
        "name": "MaxPool / AvgPool",
        "relax": "`relax.nn.max_pool2d`、`relax.nn.avg_pool2d`",
        "engine": "Pooling/Vector Engine",
        "contract": "在滑动窗口内取最大或平均，受 kernel、stride、padding、dilation 和 ceil_mode 影响。",
        "attrs": "pool_size、strides、padding、dilation、ceil_mode、layout、count_include_pad。",
        "accept": "所有属性属于硬件集合；AvgPool 的除数规则一致；布局被支持。",
        "tile": "按输出空间和通道分块，输入 tile 带 halo；窗口重叠时复用输入。",
        "tail": "空间边缘严格按 padding 与 ceil_mode；AvgPool 分母是否包含 padding 必须一致。",
        "numeric": "Max 初始值为类型最小值；Avg 累加宽度和除法舍入明确。",
        "tests": "窗口 1、2、3；stride 1/2；各种 padding；ceil_mode；全负输入；边缘平均。",
        "fallback": "任何属性行为不同都不接纳，尤其是 AvgPool 分母规则。",
        "perf": "输入复用、窗口比较或累加次数、边缘开销、池化单元忙碌。",
    },
    {
        "name": "Resize / Upsampling",
        "relax": "`relax.image.resize2d`",
        "engine": "Vector / 专用图像单元",
        "contract": "按 nearest、linear 等方法改变空间尺寸，坐标变换规则由属性决定。",
        "attrs": "size、layout、method、coordinate_transformation_mode、rounding_method、cubic 参数。",
        "accept": "方法与坐标规则完全匹配固件；输入输出尺寸在范围；布局可处理。",
        "tile": "按输出空间分块，反算输入坐标与 halo；系数可预计算或运行期生成。",
        "tail": "输出空间尾部；输入边缘坐标裁剪；通道尾部。",
        "numeric": "插值权重精度、坐标舍入、边缘裁剪和输出换算明确。",
        "tests": "放大、缩小、相同尺寸、奇偶尺寸、角点、各种坐标规则和最近邻舍入。",
        "fallback": "只支持 nearest 时不得接纳 linear；坐标模式不同会造成系统性差异。",
        "perf": "每输出像素读取数、系数生成、缓存复用和通道利用率。",
    },
    {
        "name": "Attention",
        "relax": "QKᵀ、mask、Softmax、PV 的组合模式",
        "engine": "Matrix + CME + Vector + DMA",
        "contract": "按 head 计算缩放点积注意力，包含 QKᵀ、缩放、可选 mask、Softmax 与概率乘 V。",
        "attrs": "batch、heads、query_len、kv_len、head_dim、mask 类型、causal、scale、dtype。",
        "accept": "组合完整；轴次序可识别；mask 属于支持形式；序列长度与片上计划可处理；Softmax 数值合同一致。",
        "tile": "Flash 风格可按 Q 与 KV 块在线维护行最大值与和，避免保存完整分数矩阵；首版也可分阶段执行。",
        "tail": "head_dim、query、kv 三类尾部；causal tile 的无效区域必须被排除。",
        "numeric": "缩放位置、mask 加法、稳定 Softmax、在线更新公式、输出累加精度明确。",
        "tests": "单 head、多 head、causal 与无 mask、padding mask、query/kv 不同长度、tile 尾部、极端分数。",
        "fallback": "无法可靠识别 mask 或布局时不要接纳整个组合，可让 MatMul 等局部运算进入 NPU。",
        "perf": "Q/K/V 字节、分数矩阵是否写回、矩阵与 CME 重叠、序列长度扩展趋势。",
    },
    {
        "name": "RoPE",
        "relax": "旋转位置编码的 reshape、split、sin/cos、mul、add 组合",
        "engine": "Vector Engine",
        "contract": "按位置和频率对成对通道执行二维旋转，具体交错方式由模型决定。",
        "attrs": "rotary_dim、interleaved、base、position、sin/cos 表 dtype 与 shape。",
        "accept": "组合模式与模型版本一致；rotary_dim 为偶数且不超过 head_dim；表索引合法。",
        "tile": "按 token、head 和通道对采用向量并行；sin/cos 表按位置复用。",
        "tail": "rotary_dim 之外通道原样复制；向量尾部保护。",
        "numeric": "sin/cos 精度、乘加临时宽度、表生成版本和最终换算明确。",
        "tests": "position 0、最大位置、不同 rotary_dim、交错与非交错、表边缘、往返旋转性质。",
        "fallback": "模型使用不同 RoPE 变体时保留原组合，禁止仅凭算子序列相似接纳。",
        "perf": "表读取、向量 MAC、token/head 并行和与 Q/K 排布组合收益。",
    },
    {
        "name": "KV Cache 更新与读取",
        "relax": "状态对象、slice、concat、take 或专用外部函数",
        "engine": "DMA + 状态管理",
        "contract": "在指定层、batch、head、position 写入 K/V，并按当前长度读取注意力所需范围。",
        "attrs": "层数、最大序列、head、head_dim、分页大小、位置、dtype、排布。",
        "accept": "状态生命周期清晰；position 合法；并发会话隔离；分页表与地址可验证。",
        "tile": "按 page 或 token 块传输；Attention 可直接消费缓存私有排布，避免额外转换。",
        "tail": "最后 page 未满；head_dim 尾部；序列达到上限。",
        "numeric": "存入与读出 dtype 规则一致；若使用低比特存储，scale 生命周期与 page 绑定。",
        "tests": "首次写、连续增长、随机 position、多会话、page 交界、最大长度、复位恢复、重复读取。",
        "fallback": "状态型失败不能简单主机重算；首版可把整个缓存和 Attention 留在同一后端。",
        "perf": "每 token 写字节、历史读字节、page 命中、地址翻译和 decode 时延。",
    },
    {
        "name": "低比特转换节点",
        "relax": "`relax.quantize`、`relax.dequantize` 或项目自定义运算",
        "engine": "Vector/CME",
        "contract": "在实数域与整数存储值之间按 scale、zero point、axis、舍入和裁剪规则转换。",
        "attrs": "scale、zero point、axis、输入输出 dtype、舍入方式、饱和范围。",
        "accept": "参数 dtype 与 shape 正确；axis 可处理；输出 dtype 在硬件集合；舍入与固件一致。",
        "tile": "沿连续轴采用向量并行；per-channel 参数缓存；可与生产者或消费者组合消除中间 Tensor。",
        "tail": "向量 lane 和 INT4 半字节尾部；参数轴尾部。",
        "numeric": "严格实现公式与舍入，特别检查负中点、饱和和非零 zero point。",
        "tests": "中点两侧、最小最大值、per-tensor、per-channel、不同 axis、INT4 奇数元素、往返误差。",
        "fallback": "任何参数信息缺失都不接纳；组合消除前比较变换次序。",
        "perf": "每元素换算周期、参数带宽、与周围运算组合后减少的读写。",
    },
    {
        "name": "DMA Copy / Fill / Layout Transform",
        "relax": "由后端内部 IR 插入，或来自 copy、常量填充和排布转换",
        "engine": "DMA",
        "contract": "在主机、片外设备内存与片上缓冲区之间复制、填充或按规则重排数据。",
        "attrs": "源目的地址类、shape、stride、元素字节、burst、fill 值、排布描述。",
        "accept": "地址与长度合法；对齐满足要求；stride 和维度数量在描述符能力内；重叠复制行为明确。",
        "tile": "大传输拆成允许 burst；二维或多维 stride 由嵌套描述符处理；与计算双缓冲。",
        "tail": "最后 burst 的有效字节；INT4 半字节；跨页或地址位宽上限。",
        "numeric": "纯复制位模式不变；Fill 值按目标 dtype 打包；重排不改数值。",
        "tests": "长度 0/1/对齐前后、二维 stride、多维、重叠、跨页、Fill 极值、重排往返。",
        "fallback": "描述符不能表达时拆成更多命令或使用主机，命令数超过上限则编译失败。",
        "perf": "有效字节、burst 数、平均 burst、带宽、等待周期、与计算重叠比例。",
    },
]


def render_operator(op: dict, idx: int) -> str:
    summary_box = callout("abstract", "运算合同", op["contract"])
    review_box = callout(
        "question",
        "本运算评审",
        (
            f"请确认 {op['name']} 的所有属性、动态尺寸、数据排布、数值规则、尾部、"
            "工作区、命令与测试都已经写入项目合同；只写“硬件支持”不足以进入发布版本。"
        ),
    )
    return f"""
## 30.{idx} {op['name']}

{summary_box}

| 项目 | 内容 |
| --- | --- |
| Relax 表达 | {op['relax']} |
| 首选执行单元 | {op['engine']} |
| 必查信息 | {op['attrs']} |

### 30.{idx}.1 图级识别

图级模式应以最小且不歧义的结构为起点。单运算模式用于基础覆盖，带 bias、激活、排布变换或前后处理的组合模式另行注册。组合越大，减少中间数据的机会越多，但误认风险、动态尺寸复杂度和工作区压力也会增加。

检查函数的核心要求是：{op['accept']} 检查过程应生成稳定原因码，如 `dtype`、`shape`、`layout`、`attribute`、`workspace`、`benefit`，使编译日志可以解释决定。

### 30.{idx}.2 数据排布与分块

{op['tile']}

编译器先用逻辑缓冲区表示输入输出，再选择设备排布和物理偏移。若前后运算都在同一外部函数内，可以保留私有排布；若值要交给主机，必须恢复 ABI 约定的排布。分块计划要通过静态地址检查，证明每次读写都在缓冲区内。

### 30.{idx}.3 尾部与特殊尺寸

{op['tail']}

所有物理块相关维度都要覆盖 `block-1`、`block`、`block+1`。零长度的行为依据 Relax 运算定义与项目 ABI 决定；不允许用一次常规随机测试代替尾部测试。

### 30.{idx}.4 数值规则

{op['numeric']}

若运算使用 INT4/INT8，应把 scale、zero point、累加类型、舍入和饱和写入模块元数据或命令字段。近似特殊函数还要记录算法版本。编译器与固件版本不匹配时，运行时应在加载阶段拒绝产物。

### 30.{idx}.5 Runtime 与命令

Runtime 核对参数数量、shape、dtype、stride、设备与对齐，再分配工作区和重定位逻辑缓冲区。命令序号要关联此运算或组合中的源节点。异步模式下，输入、输出和工作区在完成事件到达前保持有效。

对于 {op['engine']}，性能计数至少应覆盖：{op['perf']}。若一个组合声称减少片外访问，测试还要用命令反汇编或设备计数器证明中间写回确实消失。

### 30.{idx}.6 测试设计

基础集合：{op['tests']}

还应加入随机属性测试、错误属性、未对齐地址、工作区不足、驱动超时和模块重新加载。单运算结果正确后，再测试它与前后运算组合的结果与数据访问。

### 30.{idx}.7 主机保留

{op['fallback']}

主机保留是正常编译计划，不是失败。编译报告应列出保留原因与估计成本，便于后续决定是扩展硬件、改进编译器还是维持现状。

{review_box}
"""


operator_toc = "\n".join(
    f"- [[#30.{i} {op['name']}|30.{i} {op['name']}]]"
    for i, op in enumerate(operators, 1)
)
operator_body = "\n".join(
    render_operator(op, i) for i, op in enumerate(operators, 1)
)
write(
    "30-自研 NPU 算子接入分册.md",
    f"""
{frontmatter}
# 30. 自研 NPU 算子接入分册

{callout("abstract", "使用方法", "本分册不是简单算子列表，而是把每个运算拆成图级识别、排布、分块、尾部、数值、Runtime、命令、测试和主机保留。项目应复制相应小节并用真实硬件数值替换通用描述。")}

## 快速目录

{operator_toc}

## 通用要求

每个运算进入 NPU 之前，必须同时满足运算结构、属性、shape、dtype、排布、工作区与收益要求。Relax 模式只负责找到候选，检查函数负责确认硬件能力，代码生成器负责建立命令，Runtime 负责绑定实际 Tensor。任何一层都不能假设上一层已经检查了自己专属的运行期条件。

{operator_body}

## 分册小结

接入顺序建议从 MatMul、Conv2D、Add、ReLU 开始，再增加 Softmax、Norm 和 Attention。每新增一个运算，必须同步增加图结构测试、代码生成测试、设备对照、异常测试、性能统计和主机保留案例。
""",
)


labs = [
    {
        "name": "固定源码与确认构建",
        "goal": "使用 SSH 取得 v0.24.0，完成最小 LLVM 构建，并证明 Python 加载当前动态库。",
        "input": "Linux、Git SSH 权限、CMake 3.24+、Python 3.10+、LLVM 15+。",
        "steps": "克隆 `git@github.com:apache/tvm.git`；切到 `v0.24.0`；复制 `config.cmake`；启用 LLVM；构建；安装 tvm-ffi；以 editable 方式安装 Python 包。",
        "observe": "`git rev-parse HEAD`、`tvm.__file__`、`tvm.base._LOADED_LIBS` 与 `tvm.support.libinfo()` 指向同一构建。",
        "failure": "若提交号正确但库路径错误，先清理 Python 环境中的旧 TVM 包，而不是修改源码。",
        "extend": "建立 Debug 与 RelWithDebInfo 两套构建，并保存配置差异。",
    },
    {
        "name": "手写第一个 Relax 模块",
        "goal": "用 TVMScript 写 `add` 或两层 MLP，理解参数、数据流块、R.output 和返回值。",
        "input": "已完成实验 1。",
        "steps": "定义 `@I.ir_module`；增加 `@R.function`；打印 `mod.script()`；运行 `relax.get_pipeline('zero')`；比较变换前后。",
        "observe": "IRModule 内有一个 Relax 函数，函数参数 StructInfo 与输入一致，数据流块内变量和输出清晰。",
        "failure": "若 parser 报错，核对 v0.24.0 TVMScript 导入方式，不使用旧版 `from tvm.script import tir as T` 示例。",
        "extend": "增加符号 batch，并观察打印结果。",
    },
    {
        "name": "观察 Relax 到 TensorIR",
        "goal": "跟踪 `LegalizeOps` 前后，找到 Relax 运算如何变成 `call_tir` 与 PrimFunc。",
        "input": "一个包含 MatMul 和 ReLU 的 Relax 模块。",
        "steps": "保存原模块；运行规范化；单独运行 `LegalizeOps`；列出模块函数类型；打印 PrimFunc。",
        "observe": "IRModule 同时包含 Relax Function 与 TensorIR PrimFunc，Relax 调用通过低层调用连接。",
        "failure": "若运算仍未下沉，检查 pipeline 次序和运算是否有当前后端的合法化规则。",
        "extend": "对比 Add、Softmax 与 MatMul 的 PrimFunc 结构。",
    },
    {
        "name": "导入 PyTorch",
        "goal": "通过 `torch.export` 与 `from_exported_program` 导入小模型，分离参数并与 PyTorch 对照。",
        "input": "PyTorch、NumPy、一个 eval 模式 CNN 或 MLP。",
        "steps": "导出 ExportedProgram；导入 Relax；`detach_params`；CPU 编译；准备相同输入；执行 VM；`assert_allclose`。",
        "observe": "参数数量、输入名称、输出 shape 与源模型一致，CPU 结果满足误差要求。",
        "failure": "若结果不同，先确认 `.eval()`、随机种子、输入预处理和参数顺序。",
        "extend": "打印 ExportedProgram 图与 Relax 图，建立 ATen 运算到 Relax 运算对照表。",
    },
    {
        "name": "导入 ONNX",
        "goal": "使用 `from_onnx` 导入已有文件，并用 `shape_dict` 固定动态输入。",
        "input": "ONNX 模型、onnx Python 包。",
        "steps": "加载 ModelProto；查看输入名称；提供 shape_dict；导入；CPU 编译；与 ONNX Runtime 或源框架对照。",
        "observe": "动态维被按预期固定，参数是否嵌入与选项一致。",
        "failure": "shape_dict 未生效时，检查名称是否是模型真实输入名。",
        "extend": "保留一个符号维，观察后续 NPU 检查函数如何处理。",
    },
    {
        "name": "编写自定义 Relax Pass",
        "goal": "实现一个小型函数或模块 Pass，记录输入输出并验证重复执行稳定。",
        "input": "一个包含冗余 reshape 或可折叠结构的模块。",
        "steps": "定义 Pass；在 Sequential 中调用；保存前后脚本；用结构比较写期望；连续执行两次。",
        "observe": "第一次产生预期变化，第二次结构不再改变。",
        "failure": "若第二次继续生成新函数，检查全局符号与改写条件。",
        "extend": "加入 PassInstrument，记录耗时和函数数量。",
    },
    {
        "name": "DPL 匹配 MatMul+ReLU",
        "goal": "用 wildcard 与 is_op 找到组合，并通过 annotation 读取输入信息。",
        "input": "MatMul+ReLU 与只有 MatMul 的两个模块。",
        "steps": "建立 DFPattern；注册 FusionPattern；在检查函数中查看 StructInfo；分别运行 FuseOpsByPattern。",
        "observe": "完整组合被分组，只有 MatMul 的模块不匹配组合模式。",
        "failure": "若匹配不到，打印导入后的实际运算名与中间 cast/reshape。",
        "extend": "增加 MatMul+Bias+ReLU，更具体模式放在更高优先级。",
    },
    {
        "name": "实现可解释接纳检查",
        "goal": "把 dtype、M/N/K、对齐与收益检查写成纯函数，输出原因码。",
        "input": "实验 7 的模式和一组尺寸。",
        "steps": "定义 CheckResult；构造刚好满足和刚好不满足的实例；DPL check 调用纯函数；编译报告保存结果。",
        "observe": "每个未进入 NPU 的实例都有稳定原因，满足条件的实例进入外部函数。",
        "failure": "若检查依赖全局可变状态，改为通过 Target 或显式配置传入。",
        "extend": "统计一组模型中各原因数量，确定最有价值的能力扩展。",
    },
    {
        "name": "构建官方 Example NPU",
        "goal": "启用 `USE_EXAMPLE_NPU_CODEGEN` 与 `USE_EXAMPLE_NPU_RUNTIME`，运行官方测试并观察日志。",
        "input": "v0.24.0 源码构建环境。",
        "steps": "打开两个 CMake 开关；重新配置构建；运行 `tests/python/contrib/test_example_npu.py`；检查全局注册函数。",
        "observe": "模式、代码生成和 Runtime 创建函数存在；测试按设计通过。",
        "failure": "Example NPU 输出未初始化，不能把形状测试误当数值测试。",
        "extend": "阅读 patterns.py、codegen.cc、runtime.cc 和 CMake，画出函数调用关系。",
    },
    {
        "name": "复制后端空壳并改名",
        "goal": "建立 acme_npu 目录、注册名与 CMake 开关，避免与 Example NPU 冲突。",
        "input": "实验 9 和项目命名约定。",
        "steps": "复制结构；统一替换 Python 包名、模式前缀、C++ 名称、type key、加载注册名和 CMake 开关；只保留 MatMul 模式。",
        "observe": "`get_patterns_with_prefix('acme_npu')` 只返回项目模式，两个后端可同时构建。",
        "failure": "RunCodegen 找不到函数时，逐项检查 `Codegen` 属性与 `relax.ext.acme_npu`。",
        "extend": "写脚本扫描所有注册字符串，防止残留 example 名称。",
    },
    {
        "name": "生成可读子图产物",
        "goal": "把 MatMul 外部函数转换为 JSON，保存输入输出、shape、dtype 与符号。",
        "input": "acme_npu 空壳代码生成器。",
        "steps": "遍历组合函数；读取 Composite；序列化参数；写入版本；创建 Runtime Module；输出调试 JSON。",
        "observe": "相同 IR 两次编译 JSON 内容稳定，字段可由离线工具读取。",
        "failure": "若常量直接以内存地址写入产物，改为常量名称与索引。",
        "extend": "增加工作区和逻辑缓冲区目录。",
    },
    {
        "name": "实现模块保存与重新加载",
        "goal": "让自定义 Runtime Module 随共享库导出，并在新进程恢复。",
        "input": "实验 11 的模块与加载注册。",
        "steps": "实现 SaveToBinary；实现 LoadFromBytes；注册 type key；export_library；退出进程；load_module；查找外部函数。",
        "observe": "新进程不依赖编译时全局对象，仍可取得函数和元数据。",
        "failure": "加载找不到函数时，核对 type key、注册名和部署库是否包含运行时源文件。",
        "extend": "故意损坏版本和文件长度，确认加载安全失败。",
    },
    {
        "name": "接入真实 INT8 MatMul",
        "goal": "从 Runtime 调用驱动或模拟器，执行一个真实矩阵任务。",
        "input": "设备 SDK、驱动或可执行参考模拟器；明确 MatMul 合同。",
        "steps": "绑定 Tensor；分配设备内存；复制 A/B；重定位命令；提交；等待；复制 C；与位准确参考比较。",
        "observe": "M=N=K=物理块时结果正确，日志可看到提交序号和命令。",
        "failure": "结果错误时先对照输入排布和第一个输出 tile，不从完整矩阵末尾反查。",
        "extend": "把权重预排后作为模块常量加载。",
    },
    {
        "name": "覆盖 MatMul 尾部",
        "goal": "让 M、N、K 不整除物理块时仍安全正确。",
        "input": "实验 13 与尾部策略。",
        "steps": "分别测试 block-1、block+1；检查填充或 mask；用内存保护检测越界；保存命令反汇编。",
        "observe": "所有逻辑元素正确，填充位置不会写入输出之外，K 填充值符合 zero point。",
        "failure": "只有 K 尾部错误时，检查部分和初始化、填充值和最后一轮累加。",
        "extend": "比较 mask、小 tile 和主机尾部的性能。",
    },
    {
        "name": "验证舍入与饱和",
        "goal": "构造正负中点、极值与溢出输入，确认编译器、参考模型与硬件规则一致。",
        "input": "固定乘数、移位、输出 dtype 和舍入合同。",
        "steps": "生成中点两侧样本；计算高精度参考；计算位准确参考；运行设备；保存首个不同值。",
        "observe": "位准确结果一致，尤其是负数与最小值。",
        "failure": "差一错误通常检查舍入偏置、算术右移和中间饱和位置。",
        "extend": "覆盖 per-channel 参数与 INT4 打包。",
    },
    {
        "name": "组合 MatMul+Bias+ReLU",
        "goal": "一个外部函数完成三步，并证明中间值不写回片外。",
        "input": "真实 MatMul、Vector 或后处理能力。",
        "steps": "注册更具体模式；生成组合命令；运行对照；检查命令与计数器；比较拆分版本。",
        "observe": "结果一致，外部函数数量减少，片外字节下降。",
        "failure": "若组合结果不同，检查 bias 加入域、换算与 ReLU 的先后。",
        "extend": "增加 GELU，但保留公式版本检查。",
    },
    {
        "name": "测试主机保留",
        "goal": "构造 NPU 不接受的尺寸或运算，确认模型仍由混合后端正确执行。",
        "input": "含可接纳 MatMul 与不被支持运算的小图。",
        "steps": "分区；打印外部函数；编译剩余运算到 LLVM；运行；统计设备切换。",
        "observe": "未被接纳节点仍存在并由主机处理，最终结果正确。",
        "failure": "主机找不到输入时，检查设备复制与外部函数输出 ABI。",
        "extend": "增加成本阈值，让很小 MatMul 留在主机。",
    },
    {
        "name": "动态 sequence 多版本",
        "goal": "为多个 sequence 范围生成 NPU 版本，并在运行期选择。",
        "input": "带符号 sequence 的小型 Attention 或 MatMul 图。",
        "steps": "定义范围；特化常见长度；生成版本目录；运行期按 shape 选择；超范围走主机。",
        "observe": "每个范围选择正确版本，工作区不超过记录上限。",
        "failure": "版本错选时检查范围是否重叠和优先次序。",
        "extend": "比较填充大版本与多个精确版本的产物大小和时延。",
    },
    {
        "name": "通过 RPC 测量远程设备",
        "goal": "在目标设备启动 RPC server，从主机上传模块并用设备计时接口测量。",
        "input": "主机与目标网络、目标 TVM runtime、设备权限。",
        "steps": "启动 RPC server；连接；上传模块；加载；设置输入；预热；使用 time_evaluator；保存环境。",
        "observe": "报告排除网络传输的设备执行时间，并包含 repeat 分布。",
        "failure": "不要用主机端调用总时间替代设备计时。",
        "extend": "把 RPCRunner 接入 MetaSchedule 或自研调优器。",
    },
    {
        "name": "建立性能分解",
        "goal": "把端到端时间拆成准备、复制、提交、排队、执行与等待。",
        "input": "运行时打点和设备计数器。",
        "steps": "为每阶段记录时间；读取 DMA/Matrix/Vector 计数；执行多个尺寸；计算有效带宽与利用率。",
        "observe": "能够解释小尺寸与大尺寸差异，以及主要停顿来源。",
        "failure": "日志打印本身影响时间时，使用缓冲记录并在执行后输出。",
        "extend": "建立简单屋顶线图，指导下一轮 tile 选择。",
    },
    {
        "name": "异常注入与恢复",
        "goal": "验证加载错误、内存不足、驱动忙、超时和设备复位。",
        "input": "可配置故障的模拟器或驱动测试接口。",
        "steps": "逐种注入；记录软件、驱动、设备错误；检查资源；尝试下一次正常调用；对不可恢复错误执行复位。",
        "observe": "错误分类清楚，资源无泄漏，恢复策略符合设计。",
        "failure": "若超时后下一次调用使用旧事件或地址，复位清理不完整。",
        "extend": "并发调用中只让一个任务失败，检查隔离。",
    },
    {
        "name": "升级 TVM 版本演练",
        "goal": "在不改变项目发布分支的情况下，评估新 TVM tag 对后端的影响。",
        "input": "固定回归集、新源码工作区。",
        "steps": "构建新版本；检查注册函数；运行结构测试；编译产物；运行模拟器和板卡；比较子图数量与性能。",
        "observe": "差异被归类到 API、IR、Pass 次序、代码生成、运行时或性能。",
        "failure": "不要在旧数据库和新编译器之间直接复用调优记录，除非兼容性已证明。",
        "extend": "形成版本升级报告与回退方案。",
    },
]


def render_lab(lab: dict, idx: int) -> str:
    return f"""
## 31.{idx} 实验：{lab['name']}

{callout("abstract", "目标", lab["goal"])}

### 准备

{lab['input']}

开始前建立独立工作目录，记录源码提交、构建类型、CMake 选项、Python 包路径、LLVM 版本和目标设备版本。所有命令应能从干净终端重新执行。

### 操作

{lab['steps']}

建议每完成一个动作就保存对应的 IR、JSON、命令反汇编或运行日志。若实验包含设备执行，固定随机种子并保存输入，不要只保存最终统计数字。

### 预期观察

{lab['observe']}

将预期写成自动断言。结构使用 `tvm.ir.assert_structural_equal`，数值按运算合同选择位级比较或误差比较，模块加载在新进程完成，性能使用预热与多次重复。

### 失败排查

{lab['failure']}

排查顺序固定为：输入与环境 → 导入后 Relax → 分区后 Relax → 外部产物 → 模块加载 → Tensor 绑定 → 命令 → 设备状态 → 输出。找到第一次偏离预期的位置后再深入。

### 完成证据

- [ ] 运行命令与环境文件；
- [ ] 输入、常量与随机种子；
- [ ] 关键 IR 快照；
- [ ] 编译日志与外部函数列表；
- [ ] 产物版本与散列值；
- [ ] 对照结果；
- [ ] 失败样本；
- [ ] 结论与下一步。

### 扩展

{lab['extend']}

{callout("question", "复盘", "本实验证明了哪一层？没有证明哪些层？若结果错误，最小复现需要保留哪些文件？若换一台编译主机或目标板，哪些参数必须固定？")}
"""


lab_toc = "\n".join(
    f"- [[#31.{i} 实验：{lab['name']}|31.{i} {lab['name']}]]"
    for i, lab in enumerate(labs, 1)
)
lab_body = "\n".join(render_lab(lab, i) for i, lab in enumerate(labs, 1))
write(
    "31-循序渐进实验分册.md",
    f"""
{frontmatter}
# 31. 循序渐进实验分册

{callout("abstract", "使用方法", "实验从环境、IR 与模型导入开始，逐步进入 DPL、BYOC、真实 MatMul、尾部、数值、混合执行、动态尺寸、远程测量、异常恢复和版本升级。建议按顺序完成，并把每个实验变成 CI 测试。")}

## 快速目录

{lab_toc}

## 通用记录模板

```yaml
experiment:
  tvm_commit:
  build_type:
  cmake_options:
  python:
  llvm:
  backend_commit:
  firmware:
  hardware:
  model_hash:
  target_config:
  random_seed:
  result:
```

{lab_body}

## 分册小结

完成全部实验后，团队应拥有一套从源码构建到设备恢复的可执行教程。新成员可以按实验复现环境，版本升级可以重复运行同一集合，硬件或固件变化也能快速确定影响阶段。
""",
)


diagnostics = [
    ("Python 导入到旧 TVM", "提交号正确但 API 缺失或行为像旧版", "打印 `tvm.__file__`、已加载动态库路径和 `libinfo`", "环境中残留旧 wheel，或 PYTHONPATH 顺序错误", "先确认 Python 包，再确认动态库；两者都必须指向当前构建", "隔离虚拟环境并在 CI 保存加载路径"),
    ("构建找不到 LLVM", "CMake 报 LLVM 配置缺失", "`llvm-config --version` 与路径", "llvm-config 不在 PATH，或版本不被当前构建接受", "在 config.cmake 写完整 llvm-config 命令并重新配置", "构建镜像固定 LLVM 版本"),
    ("后端模式为空", "`get_patterns_with_prefix` 返回空列表", "检查 Python 后端模块是否被导入", "`__init__.py` 未导入 patterns，或前缀拼写不同", "显式导入后端包并列出注册模式", "增加注册存在性单测"),
    ("候选结构不匹配", "模型含 MatMul 和 ReLU，但未形成组合", "打印导入后的 Relax 绑定", "中间存在 cast、reshape、bias 或运算名不同", "根据真实结构扩展模式，先保持模式精确", "为每种前端保存结构样本"),
    ("检查函数拒绝全部候选", "模式能找到，但外部函数数量为 0", "输出每个检查字段与原因码", "StructInfo 缺失、dtype 字符串或动态形状处理错误", "把检查拆为纯函数并逐项单测", "模型级统计拒绝原因"),
    ("具体组合被普通模式抢先", "只形成 MatMul，ReLU 留在外部", "列出模式顺序与 Composite 名称", "优先级顺序错误", "把更具体组合放到更高优先级并写结构测试", "每次新增模式运行优先级回归"),
    ("RunCodegen 找不到后端", "报缺少 `relax.ext.acme_npu`", "`get_global_func`、CMake `libinfo`", "代码生成源文件未进入编译器库，或注册名不一致", "核对 Codegen 属性、注册字符串和构建开关", "构建后自动检查全局函数"),
    ("运行时创建函数缺失", "代码生成器查找 Runtime Create 失败", "`get_global_func('runtime.AcmeNPURuntimeCreate', True)`", "运行时源文件未编译，或仅打开 codegen 开关", "启用 runtime 开关并确认 CMake 模块", "compiler 与 runtime-only 两套构建测试"),
    ("分区后剩余运算无法编译", "NPU 子图成功，但主机构建失败", "查看 RunCodegen 后 IR 与主机 Target", "剩余运算未 Legalize，或主机缺少实现", "给剩余节点配置完整 host pipeline", "混合图必须进入提交级 CI"),
    ("外部符号重复", "链接或加载报告同名函数", "列出所有 global_symbol", "名称生成只使用算子名，未加入唯一编号", "稳定散列加可读前缀生成符号", "模块级唯一性断言"),
    ("内存内执行成功但导出失败", "`export_library` 报 Module 不可保存", "检查 type key、SaveToBinary 与加载注册", "自定义 Module 只实现 GetFunction", "实现保存和加载，并在新进程测试", "所有外部模块都做导出回归"),
    ("加载后找不到 NPU 函数", "共享库可加载但外部调用缺失", "查看被导入模块与函数目录", "运行时模块未被打包或 type key 不一致", "核对 Module 导入关系与加载函数", "独立部署镜像测试"),
    ("常量数量不一致", "Runtime Init 报常量个数错误", "打印 constant_names 与实际常量", "代码生成阶段绑定常量策略与运行时不同", "统一常量目录和顺序，使用名称而非遍历偶然顺序", "常量清单散列进入模块"),
    ("输入形状正确但设备地址错误", "小输入崩溃或 DMA fault", "打印逻辑缓冲区、重定位后地址和长度", "把主机虚拟地址直接写入命令，或 byte_offset 未处理", "所有命令只引用逻辑缓冲区，运行时重定位并检查", "离线地址静态检查"),
    ("只在非整分块尺寸错误", "整块正确，block±1 错误", "保存最后一块输入、命令与输出", "掩码、填充、真实长度或输出写保护错误", "逐维单独激活尾部，检查第一个失败维度", "每个物理块维度固定三点测试"),
    ("K 尾部结果偏大", "MatMul 只在 K 不整除时有额外贡献", "检查填充值、zero point 与有效 K", "填充值不是实数零对应的整数值", "按输入 zero point 填充或使用硬件掩码", "非零 zero point 尾部测试"),
    ("负数结果差一", "正数一致，负数在右移后差 1", "记录乘数、移位前值、舍入偏置", "负数舍入或算术右移规则不同", "实现位准确 RoundShift 并与 RTL 共同测试", "中点两侧固定向量"),
    ("极值出现翻转", "大正数变负数或相反", "观察每个中间位宽", "乘积或累加在饱和前已溢出", "使用足够临时宽度并明确饱和位置", "上界分析与极值测试"),
    ("多次运行第二次错误", "首次正确，后续结果受前次影响", "清空输出、改变输入、检查工作区", "部分和未清零、事件未等待或工作区过早复用", "明确初始化命令与生命周期", "交替输入长时间测试"),
    ("并发运行偶发错误", "单线程稳定，多线程失败", "记录队列、提交序号、缓冲区和线程", "共享可变工作区、常量加载竞态或事件复用", "调用状态独立并使用线程安全缓存", "并发压力与线程消毒工具"),
    ("设备超时后一直失败", "一次超时后所有任务失败", "读取驱动和固件状态、事件表", "失效队列、旧地址或未清事件继续使用", "停止提交，收集状态，完整复位并重新加载", "异常恢复测试"),
    ("小算子进入 NPU 反而更慢", "设备计算快但端到端慢", "分解复制、提交、执行、等待", "固定开销超过计算收益", "在接纳检查加入成本阈值，或与相邻运算组合", "按形状保存收益模型"),
    ("调优记录变慢", "应用数据库后性能下降", "核对硬件、固件、编译器与 Target", "旧记录被错误复用，或测量噪声选中异常值", "版本化数据库并重新测量热点候选", "记录完整环境与时间分布"),
    ("RPC 测量异常大", "远程结果包含网络时延", "比较主机总时间与设备 time_evaluator", "使用错误计时位置", "用设备侧计时并把上传与初始化分开", "性能脚本固定计时 API"),
    ("动态形状选择错误版本", "某些 sequence 运行崩溃或工作区不足", "打印实际形状、版本范围与工作区公式", "范围重叠、上限开闭错误或乘法溢出", "排序版本并使用显式包含关系", "范围端点测试"),
    ("模型精度下降但单算子通过", "每个基础运算正确，模型指标变化", "保存组合运算中间输出与转换节点", "组合后的舍入次数、公式版本或参数维度不同", "逐层二分定位首次差异，比较拆分与组合", "组合运算独立数值合同"),
    ("权重缓存错误复用", "换模型后结果像旧权重", "核对源常量散列与缓存键", "缓存只按形状或文件名", "键包含内容散列、布局、dtype、目标与编译器版本", "交替加载同形不同值权重"),
    ("部署库体积异常大", "runtime-only 仍包含编译器", "检查链接依赖与 CMake 源文件列表", "运行时引用编译器对象或开关组织错误", "隔离公共格式代码，避免 runtime 依赖 IR", "runtime-only 大小门限"),
    ("设备计数器与命令不一致", "报告的读写字节明显异常", "比较命令静态估算与硬件计数", "计数器范围、复位时机或多任务干扰", "独占设备并在提交前后读取", "计数器自测与空任务基线"),
    ("版本升级结构测试失败", "新 TVM 生成不同 IR", "比较首次差异 Pass 与 API 变更", "默认 pipeline、打印形式或内部节点变化", "先确认功能变化，再更新期望结构", "升级分支完整回归，不直接改发布分支"),
]


def render_diag(item: tuple, idx: int) -> str:
    title, symptom, evidence, cause, action, prevention = item
    return f"""
## 32.{idx} {title}

{callout("warning", "现象", symptom)}

### 先收集

{evidence}。同时保存 TVM 提交、动态库路径、Target、后端配置、模型或 IR 散列值、固件和设备版本。没有这些信息时，不应直接修改编译器或驱动。

### 常见原因

{cause}。该原因属于当前阶段的高概率项，但不是唯一可能。应通过中间 IR、产物、命令或设备状态确认，不能仅根据最终错误文本猜测。

### 定位与处理

{action}。处理后重跑最小样本，再运行相邻层测试与完整回归。若修复会改变外部函数 ABI、模块格式或数值规则，需要提升版本并拒绝旧产物。

### 防止再次出现

{prevention}。把本次最小样本、失败输入、期望结果和环境写入测试资产。

{callout("tip", "停止条件", "当已经找到第一次出现偏离的位置，并且有直接证据指向一个字段、一个 Pass、一个命令或一个运行时状态时，再实施修复；不要同时修改多个层次。")}
"""


diag_toc = "\n".join(
    f"- [[#32.{i} {d[0]}|32.{i} {d[0]}]]"
    for i, d in enumerate(diagnostics, 1)
)
diag_body = "\n".join(
    render_diag(d, i) for i, d in enumerate(diagnostics, 1)
)
write(
    "32-故障速查表.md",
    f"""
{frontmatter}
# 32. 故障速查表

{callout("abstract", "使用顺序", "先按现象找到条目，再收集该条目要求的证据。定位固定遵循模型前端、Relax、分区、代码生成、模块、Runtime、驱动、固件、硬件和输出的次序。")}

## 快速目录

{diag_toc}

## 最小证据包

```text
environment.txt
input_relax.py
partitioned_relax.py
target.json
backend_options.json
artifact_meta.json
commands.disasm
runtime.log
driver.log
reference_output.bin
actual_output.bin
```

{diag_body}
""",
)


glossary = [
    ("Tensor", "张量", "具有统一数据类型的多维数据对象；由形状、数据类型、设备和可选步长描述。"),
    ("Scalar", "标量", "不带张量维度的单个数值。"),
    ("Vector", "向量", "一维张量；在硬件语境中也可指一次并行处理的多个元素。"),
    ("Matrix", "矩阵", "二维张量；批次矩阵则带有一个或多个前导批次维度。"),
    ("Dimension", "维度", "张量形状中的一个位置，不等同于该位置的大小。"),
    ("Dimension size", "维度大小", "某一维度包含的元素数量，例如形状 `[2,3]` 的第 1 维大小为 3。"),
    ("Axis parameter", "维度编号参数", "API 中的 `axis`；正文写成“沿第 k 维”或“归约维度”，保留代码里的参数名。"),
    ("Rank / ndim", "秩 / 维数", "张量拥有的维度数量；形状 `[2,3,4]` 的秩为 3。"),
    ("Shape", "形状", "按顺序列出的各维度大小，例如 `[batch, sequence, hidden]`。"),
    ("Dynamic shape", "动态形状", "至少一个维度大小在编译期不是固定常量。"),
    ("Static shape", "静态形状", "每个维度大小在编译期已经确定。"),
    ("Symbolic shape", "符号形状", "用符号变量和表达式表示维度大小及其关系。"),
    ("Batch", "批次", "一次共同处理的一组样本或请求。"),
    ("Batch size", "批次大小", "一个批次包含的样本或请求数量。"),
    ("Batch dimension", "批次维度", "形状中代表批次的维度；避免使用缩写式中文。"),
    ("Batch dimensions", "批处理维度数", "Gather 等 API 的 `batch_dims`，表示有多少个前导维度按批次独立处理。"),
    ("Sequence length", "序列长度", "序列包含的 token、时间步或采样点数量。"),
    ("Channel", "通道", "特征图或向量的一类特征维度。"),
    ("Hidden size", "隐藏层维度大小", "Transformer 等模型中隐藏表示最后一维的大小。"),
    ("Head", "注意力头", "多头注意力中独立计算的一组 Q、K、V 子空间。"),
    ("Head dimension", "单头维度大小", "每个注意力头的特征维度大小。"),
    ("Data type / dtype", "数据类型", "元素编码与位宽，例如 float32、int8。API 字段保留 `dtype`。"),
    ("Layout", "数据布局", "逻辑维度到物理存储次序、分块和填充的完整组织方式。"),
    ("Data format", "数据格式", "常用于 NCHW、NHWC 等公开布局名称，也可包含数据类型约定。"),
    ("Stride (buffer)", "缓冲区步长", "逻辑索引在某一维增加 1 时，物理地址前进的元素数或字节数。"),
    ("Stride (convolution)", "卷积步幅", "卷积窗口每次在空间维度移动的距离。"),
    ("Padding", "填充", "在输入边缘补充元素，或把维度大小补到硬件所需倍数。"),
    ("Dilation", "膨胀系数", "卷积核相邻采样点之间的间隔。"),
    ("Groups", "分组数", "卷积输入与输出通道被分成多少组独立计算。"),
    ("Kernel (convolution)", "卷积核", "卷积权重及其空间窗口。"),
    ("Kernel (compiled)", "计算内核", "可被运行时调用的一段已编译设备程序。"),
    ("Operator", "算子", "图 IR 中表示一种计算的节点或运算类别。"),
    ("Operation", "运算", "一次具体数学或数据处理动作；与“算子定义”按上下文区分。"),
    ("Elementwise", "逐元素", "对对应元素独立执行同一运算。"),
    ("Broadcasting", "广播", "按规则扩展大小为 1 或缺省的前导维度，以参与逐元素运算。"),
    ("Reduction", "归约", "沿一个或多个维度把多个元素合成较少元素，例如求和或最大值。"),
    ("Permutation", "维度重排", "改变张量各维度的次序。"),
    ("Transpose", "转置", "二维矩阵交换行列，或高维张量按给定维度次序重排。"),
    ("Reshape", "形状变换", "在元素线性次序不变时改变形状；连续 Tensor 可仅修改元数据。"),
    ("Slice", "切片", "从一个或多个维度取得范围子集。"),
    ("Gather", "索引收集", "按照索引从指定维度取得元素或切片。"),
    ("Scatter", "索引写入", "按照索引把更新值写入目标 Tensor。"),
    ("Concatenate", "拼接", "沿指定维度连接多个 Tensor。"),
    ("Split", "拆分", "沿指定维度把一个 Tensor 分为多个 Tensor。"),
    ("Tiling", "分块", "把大计算和大 Tensor 划分为适合片上存储与执行单元的小块。"),
    ("Tile", "分块", "分块处理产生的一个具体小块；代码标识符可保留 `tile`。"),
    ("Tail", "尾部", "维度大小不能整除物理分块或向量宽度时剩余的有效元素。"),
    ("Mask", "掩码", "标出有效元素、允许位置或需要忽略的位置。"),
    ("Alignment", "对齐", "地址、步长或大小需要满足的整数倍要求。"),
    ("Packing", "打包", "把多个低位宽元素放入一个字节或机器字。"),
    ("Unpacking", "解包", "从打包存储中恢复独立元素。"),
    ("Zero point", "零点", "整数存储值中对应实数 0 的值。"),
    ("Scale", "缩放系数", "整数存储值与实数之间换算所用的正数系数。"),
    ("Per-tensor", "按张量", "整个 Tensor 共用一组参数。"),
    ("Per-channel", "按通道", "每个通道拥有独立参数。"),
    ("Accumulator", "累加器", "保存乘加或归约中间结果的寄存器或缓冲区。"),
    ("Rounding", "舍入", "把高精度数值转换为较低精度时选择相邻可表示值的规则。"),
    ("Saturation", "饱和", "超出数据类型范围时限制到最小值或最大值。"),
    ("Clipping", "裁剪", "把数值限制到指定区间。"),
    ("Overflow", "溢出", "结果超过当前表示范围。"),
    ("Underflow", "下溢", "数值绝对值太小，无法由当前格式正常表示。"),
    ("IR", "中间表示", "编译器内部用于分析和变换程序的数据结构。"),
    ("IRModule", "IR 模块", "保存 Relax 函数、TensorIR PrimFunc、全局信息与模块属性的容器。"),
    ("Relax", "Relax 图级 IR", "TVM 中描述模型计算图、控制流、形状和高层调用的 IR。"),
    ("TensorIR", "张量程序 IR", "TVM 中描述循环、缓冲区、计算块和低层张量程序的 IR。"),
    ("PrimFunc", "原始函数", "TensorIR 中可独立编译的低层函数。"),
    ("SBlock", "可调度计算块", "v0.24.0 TensorIR 中带读写区域和迭代变量信息的计算块。"),
    ("StructInfo", "结构信息", "Relax 表达式的形状、数据类型、设备等静态可知信息。"),
    ("GlobalVar", "全局变量", "IRModule 内引用全局函数的符号对象。"),
    ("Dataflow block", "数据流块", "Relax 中主要表达局部无副作用计算依赖的块。"),
    ("TVMScript", "TVM 脚本语言", "使用 Python 语法书写和打印 TVM IR 的领域专用语言。"),
    ("Pass", "编译变换", "把一种程序状态转换为另一种程序状态的编译步骤。"),
    ("PassContext", "编译变换上下文", "控制变换配置、优化级别、禁用项和插桩的上下文。"),
    ("Pipeline", "编译流程", "按明确顺序组合的一组编译变换。"),
    ("Normalization", "规范化", "把多种等价写法整理成后续分析更容易处理的形式。"),
    ("Legalization", "算子逐级转换", "把高层算子转换成 TensorIR 调用或外部函数调用。"),
    ("Lowering", "逐级转换", "逐步把高层程序转换成更接近目标代码的表示。"),
    ("Fusion", "融合", "把多个算子组合成一个计算内核或外部函数，减少中间存储与调用。"),
    ("Pattern", "模式", "用来描述需要在 IR 中识别的结构。"),
    ("DPL", "数据流模式语言", "Relax 用于模式识别与改写的 API 集合。"),
    ("Composite function", "组合函数", "由模式融合得到、带 Composite 属性的 Relax 函数。"),
    ("Partitioning", "图分区", "把模型图划分为由不同后端处理的子图。"),
    ("BYOC", "自定义代码生成接入机制", "让外部硬件编译器或库接收部分 Relax 子图的 TVM 机制。"),
    ("Codegen", "代码生成", "把低层 IR 或外部子图转换成目标可执行形式。"),
    ("Target", "编译目标", "编译期使用的硬件能力和代码生成配置。"),
    ("TargetKind", "编译目标类别", "注册目标名称、默认设备类型和合法属性的类别。"),
    ("Device", "设备", "运行期实际执行计算或保存 Tensor 的硬件实例。"),
    ("DeviceAPI", "设备接口", "TVM 运行时中负责内存、复制、流、同步和设备属性的统一接口。"),
    ("Host", "主机", "组织编译或执行控制的 CPU 环境；交叉编译时编译主机与执行主机还需区分。"),
    ("Runtime", "运行时", "加载模块、管理 Tensor 与设备、调用已编译函数的部署组件。"),
    ("PackedFunc", "统一封装函数", "TVM 跨 Python、C++ 和运行时传递参数与调用函数的类型擦除接口。"),
    ("Module", "运行时模块", "保存可按名称查找函数并可导入其他模块的运行时对象。"),
    ("Tensor object", "张量对象", "运行时中带形状、数据类型、设备和内存引用的对象。"),
    ("DLPack", "DLPack 张量交换协议", "多个框架交换 Tensor 描述和所有权的开放协议。"),
    ("Virtual machine", "虚拟机", "执行 Relax 控制流程并调用已编译内核或外部函数的运行时组件。"),
    ("Bytecode", "字节码", "Relax VM 默认模式使用的紧凑控制指令。"),
    ("Serialization", "序列化", "把运行时模块、命令和元数据保存成可传输形式。"),
    ("Deserialization", "反序列化", "从保存形式恢复运行时模块与导入关系。"),
    ("ABI", "应用二进制接口", "模块、函数、驱动和固件之间的二进制调用与数据约定。"),
    ("Artifact", "编译产物", "代码生成器输出的模块、命令、常量和元数据集合。"),
    ("Relocation", "地址重定位", "加载或调用时把逻辑缓冲区引用转换为实际设备地址。"),
    ("Workspace", "工作区", "调用期间供中间值和临时计算使用的内存。"),
    ("Scratchpad", "片上暂存存储器", "由软件显式管理、靠近计算单元的片上存储。"),
    ("Cache", "缓存", "由硬件或软件保存近期数据以减少下层访问的存储。"),
    ("DMA", "直接存储器访问", "不由通用 CPU 逐元素参与的数据搬运引擎。"),
    ("Command stream", "命令流", "按协议编码并提交给固件或硬件的一组命令。"),
    ("Event", "事件", "表示异步任务完成、错误或任务间先后关系的对象或编号。"),
    ("Stream / queue", "流 / 队列", "按顺序接收设备工作并允许多个工作序列并行的运行时对象。"),
    ("Synchronization", "同步", "建立任务先后关系或等待设备完成。"),
    ("Asynchronous execution", "异步执行", "提交函数先返回事件，设备工作可在主机继续执行时进行。"),
    ("RPC", "远程过程调用", "TVM 用于上传模块、在远程设备运行函数和测量的机制。"),
    ("DLight", "DLight 规则调度", "使用预定义规则快速生成 TensorIR 调度。"),
    ("MetaSchedule", "MetaSchedule 搜索调度", "生成候选、构建、设备测量并保存调度记录的自动调优框架。"),
    ("Schedule", "调度", "在不改变计算结果的前提下组织循环、存储和执行方式。"),
    ("Schedule trace", "调度轨迹", "可重放的一系列调度决定。"),
    ("Tensor Intrin", "张量内建函数", "用小块计算描述与目标硬件实现配对，供 tensorize 使用。"),
    ("Tensorize", "张量指令替换", "把匹配的小块 TensorIR 计算替换为张量内建函数实现。"),
    ("Cost model", "代价模型", "预测候选执行成本或性能的模型。"),
    ("Runner", "运行测量器", "在本地或远程设备执行候选并返回测量结果。"),
    ("Builder", "候选构建器", "把调度候选编译成可运行模块。"),
    ("Database", "调优数据库", "保存工作负载、调度轨迹和测量结果。"),
    ("Fallback", "改由其他后端执行", "当前后端不接纳某个节点或子图时，保留给主机或另一设备。"),
    ("Reference model", "参考模型", "用于给出预期数值或位级结果的独立实现。"),
    ("Golden data", "标准参考数据", "经过确认、供自动测试比较的输入与预期输出。"),
    ("Bit-exact", "位级相同", "输出每一位都与参考结果一致。"),
    ("Tolerance", "允许误差", "近似计算结果相对参考值可接受的数值范围。"),
    ("Throughput", "吞吐率", "单位时间完成的样本、token、运算或数据量。"),
    ("Latency", "时延", "从请求开始到指定完成点所需时间。"),
    ("Bandwidth", "带宽", "单位时间可传输的数据量。"),
    ("Utilization", "利用率", "执行单元忙碌时间或有效工作量占可用能力的比例。"),
    ("Roofline model", "屋顶线模型", "用计算强度、峰值算力和内存带宽判断性能限制来源的模型。"),
]


def render_term(term: tuple, idx: int) -> str:
    english, chinese, meaning = term
    return f"""
### 33.4.{idx} {english}：{chinese}

{meaning}

在 TVM 与自研 NPU 接入文档中，首次出现建议写作“{chinese}（`{english}`）”，后续使用中文；源码标识符、API 参数、属性名和命令字段保持原文。这样既能与代码检索一致，也能避免把概念名称、参数名称和张量中的具体维度混在一起。
"""


term_rows = "\n".join(
    f"| `{e}` | {c} | {m} |" for e, c, m in glossary
)
term_body = "\n".join(
    render_term(term, i) for i, term in enumerate(glossary, 1)
)
write(
    "33-术语与 API 速查.md",
    f"""
{frontmatter}
# 33. 术语与 API 速查

{callout("important", "中文术语约定", "本手册使用“批次”“批次大小”“批次维度”“形状”“秩”“维度编号”“数据布局”“分块”。代码参数 `axis` 保留英文；正文写“沿第 k 维”“归约维度”或“维度编号”，不使用含糊缩写。")}

## 33.1 采用这些写法的依据

- PaddlePaddle 的 [take_along_axis API](https://www.paddlepaddle.org.cn/documentation/docs/zh/api/paddle/take_along_axis_cn.html) 将 `axis` 说明为“指定沿着哪个维度”。
- PaddlePaddle 的 [数据加载文档](https://www.paddlepaddle.org.cn/documentation/docs/zh/2.3/guides/beginner/data_load_cn.html) 使用“批次大小”和“每批次读取样本数”。
- 昇腾 CANN 的 [Gather 文档](https://www.hiascend.com/document/detail/zh/canncommercial/800/apiref/aicpuopapi/atlaste_07_0062.html) 在参数说明中把 `axis` 解释为“指定切片数据所在的维度”，并把 `batch_dims` 解释为“批处理的维度数”。
- Apache TVM 的 [TensorIR 文档]({BASE_URL}/deep_dive/tensor_ir/index.html) 与 [Relax 文档]({BASE_URL}/deep_dive/relax/index.html) 用于确认英文 API 与源码概念。

不同厂商文档偶尔使用不同中文。本手册优先选择能直接说明张量位置或大小的完整表达，并在代码处保留英文参数名。

## 33.2 禁止混用的例子

| 不推荐 | 推荐 | 原因 |
| --- | --- | --- |
| 批次维度的简称 | 批次维度 | 不使用不规范缩写 |
| 英文参数与中文概念混写 | 第 k 维 / 维度编号 | 区分参数名与概念 |
| shape 大小 | 形状 / 某维度大小 | 区分整个形状与单一数值 |
| rank 大小 | 秩 | rank 表示维数 |
| layout 格式 | 数据布局 | 与 dtype、文件格式区分 |
| 英文术语直接作动词 | 分块 | 使用明确中文动作 |
| op | 算子 | 非代码处使用完整名称 |
| 英文术语直接代替处理说明 | 改由主机或其他后端执行 | 说明实际行为 |

## 33.3 快速表

| 英文或 API | 本手册中文 | 定义 |
| --- | --- | --- |
{term_rows}

## 33.4 逐项解释

{term_body}

## 33.5 API 名称保留规则

下列内容保持源码拼写：

- `axis`、`axes`、`batch_dims`、`shape`、`dtype`、`layout`；
- `IRModule`、`Relax`、`TensorIR`、`PrimFunc`、`StructInfo`；
- `FuseOpsByPattern`、`MergeCompositeFunctions`、`RunCodegen`；
- `Target`、`TargetKind`、`DeviceAPI`；
- `PackedFunc`、`runtime.Module`、`VirtualMachine`；
- `relax.quantize`、`relax.dequantize` 等实际算子注册名。

正文解释这些 API 时使用上表中文，避免把代码标识符强行翻成无法检索的名称。
""",
)


review_sections = [
    ("版本与环境", [
        "TVM tag 与完整提交号已经固定",
        "LLVM、CMake、Python、编译器版本已经记录",
        "Python 包与动态库路径属于同一构建",
        "CMake 开关进入构建记录",
        "编译主机与执行设备信息分开",
        "后端、驱动、固件与硬件版本可追溯",
        "构建可在干净环境重复",
        "第三方依赖许可证与版本明确",
    ]),
    ("模型前端", [
        "源模型处于推理状态",
        "输入名称、形状、数据类型和预处理已记录",
        "参数嵌入或分离策略明确",
        "动态维度没有被任意常数替换",
        "未被支持的源框架算子有处理方案",
        "导入后 CPU 结果与源框架对照",
        "模型和权重内容散列值已保存",
        "前端版本升级有结构回归",
    ]),
    ("Relax 程序", [
        "函数参数和返回 StructInfo 完整",
        "数据流块与普通绑定使用正确",
        "符号形状及约束明确",
        "控制流分支返回信息兼容",
        "常量折叠不会破坏所需模式",
        "自定义属性使用项目名称空间",
        "Pass 前后 IR 快照可生成",
        "结构比较测试覆盖关键函数",
    ]),
    ("DPL 与图分区", [
        "每个模式名称带后端前缀",
        "一般模式与具体组合优先级有测试",
        "annotation 覆盖检查所需子表达式",
        "检查函数包含数据类型、形状、属性和布局",
        "动态形状的接受范围明确",
        "检查结果有稳定原因码",
        "不被接纳节点可由主机编译",
        "分区 Pass 重复执行结构稳定",
        "成本阈值考虑复制和提交",
        "模型级外部函数数量有回归门限",
    ]),
    ("Pass 次序", [
        "规范化在模式识别前完成",
        "会改变模式结构的融合位置明确",
        "RunCodegen 在外部函数标记后执行",
        "剩余算子有完整主机 pipeline",
        "每个 Pass 的输入条件已记录",
        "分析信息失效规则明确",
        "默认 pipeline 变化可被测试发现",
        "PassInstrument 可记录耗时与函数数量",
    ]),
    ("外部代码生成", [
        "注册名与 Codegen 属性一致",
        "函数签名符合当前 TVM 版本",
        "输入输出与常量顺序稳定",
        "相同输入编译结果确定",
        "逻辑缓冲区而非主机地址进入产物",
        "布局和工作区由结构化字段描述",
        "命令生成后运行静态检查",
        "失败错误包含外部函数和源节点",
        "调试产物可选且不改变执行结果",
        "仅运行时构建不依赖编译器 IR",
    ]),
    ("模块产物", [
        "magic、格式版本和长度存在",
        "目标型号与固件 ABI 存在",
        "外部函数目录可查",
        "常量目录含内容校验值",
        "命令段与重定位项分开",
        "输入输出 ABI 描述完整",
        "工作区要求可安全计算",
        "未知版本被拒绝",
        "截断或损坏文件安全失败",
        "模块可保存并在新进程加载",
    ]),
    ("常量与权重", [
        "常量所有权与生命周期明确",
        "权重预转换工具使用同一布局定义",
        "缓存键包含内容、数据类型、布局和目标",
        "多函数共享权重的引用计数正确",
        "常量上传失败可清理",
        "常量内存不可被普通写命令覆盖",
        "同形不同值权重不会错误复用",
        "模型卸载后设备常量被释放",
    ]),
    ("数据布局", [
        "逻辑维度与物理维度关系明确",
        "分块因子、维度次序和填充明确",
        "地址公式可独立执行",
        "正向转换与反向转换往返正确",
        "INT4 元素打包次序明确",
        "未使用填充位置的值明确",
        "外部函数接口布局明确",
        "主机处理前能恢复公开布局",
        "布局版本进入缓存键",
        "布局工具与硬件读取共同测试",
    ]),
    ("内存规划", [
        "每个逻辑缓冲区大小含对齐与填充",
        "生命周期包含异步 DMA 与计算",
        "同时存活缓冲区不重叠",
        "输入输出别名规则明确",
        "工作区公式检查整数溢出",
        "片上占用不超过 Target 能力",
        "多调用并发不共享可变工作区",
        "申请失败不继续执行",
        "调试保留中间值时重新计算占用",
        "设备复位后旧地址全部失效",
    ]),
    ("命令与事件", [
        "每条命令字段范围已检查",
        "每个读都有有效数据来源",
        "每个等待事件都有生产者",
        "事件不会过早复用",
        "依赖图无环",
        "失败能传播到后续命令",
        "最终输出有可等待完成事件",
        "命令数不超过上限",
        "命令可离线反汇编",
        "命令序号可关联源节点",
    ]),
    ("运行时", [
        "外部函数参数数量和类型检查完整",
        "形状、步长、byte_offset 和对齐被核对",
        "主机 Tensor 与设备 Tensor 路径分开",
        "同步与异步函数合同明确",
        "输入输出在事件完成前保持有效",
        "Module type key 与加载注册一致",
        "初始化失败可释放部分资源",
        "多线程调用状态独立",
        "多设备按 device id 隔离",
        "部署端只链接所需组件",
    ]),
    ("驱动与固件", [
        "地址类型是物理地址、IOVA 或设备虚拟地址",
        "缓存维护责任明确",
        "队列、门铃、中断和事件协议明确",
        "超时策略与看门狗一致",
        "驱动错误和设备错误都能上报",
        "固件独立检查地址与命令",
        "复位流程会清理失效状态",
        "多进程权限与隔离明确",
        "能力查询与 Target 配置可核对",
        "固件 ABI 不兼容时加载被拒绝",
    ]),
    ("低比特整数数值", [
        "有符号性与二进制表示明确",
        "scale、zero point 及其参数维度明确",
        "乘积和累加位宽明确",
        "bias 所在数值域明确",
        "固定乘数与移位计算明确",
        "正负数舍入方式明确",
        "中间饱和与最终裁剪位置明确",
        "特殊函数版本与输入区间明确",
        "INT4 奇数元素处理明确",
        "位准确参考模型独立实现",
    ]),
    ("动态形状与控制流", [
        "每个动态维度有允许范围",
        "运行期守卫的失败路径可运行",
        "多版本范围不重叠或优先次序明确",
        "动态工作区公式安全",
        "控制流两个分支均测试",
        "状态对象拥有者和生命周期明确",
        "KV Cache 最大长度和分页规则明确",
        "设备失败后的状态恢复明确",
        "动态尺寸端点进入回归",
        "超范围输入得到清晰错误或主机处理",
    ]),
    ("正确性测试", [
        "纯函数、Pass、代码生成、Runtime 分层测试",
        "每条硬件限制有正反样本",
        "每个物理块维度覆盖前一值、整值、后一值",
        "极值、零、正负一和随机输入齐全",
        "组合算子与拆分执行对照",
        "模块导出与新进程加载测试",
        "并发、长时间和重复运行测试",
        "异常注入检查资源与恢复",
        "完整模型覆盖主要结构",
        "失败随机种子保存为固定样本",
    ]),
    ("性能", [
        "功能通过后才运行性能门限",
        "预热、重复和统计方法固定",
        "网络传输不计入设备执行时间",
        "复制、提交、排队、执行、等待分开",
        "计算量与读写字节可静态估算",
        "设备计数器有空任务基线",
        "组合算子减少的片外字节被证明",
        "小形状成本阈值有测量依据",
        "调优数据库包含完整版本",
        "冷启动与稳态分别报告",
    ]),
    ("安全与健壮性", [
        "所有长度与偏移检查整数溢出",
        "重定位不能访问未分配内存",
        "命令输入被编译器和固件双重检查",
        "损坏产物不能造成任意地址访问",
        "超时不会永久占用队列和缓冲区",
        "外部输入不能覆盖常量和命令段",
        "日志不泄露模型敏感内容",
        "设备节点权限最小化",
        "多用户上下文隔离",
        "模糊测试覆盖产物解析器",
    ]),
    ("可观测性", [
        "每个外部函数有稳定散列值",
        "日志包含设备、队列和提交序号",
        "分区日志包含接纳或拒绝原因",
        "代码生成日志包含工作区和命令摘要",
        "运行时日志包含模块和固件版本",
        "首个失败命令可反查源节点",
        "中间 IR 快照可按开关保存",
        "错误对象同时包含软件、驱动和设备码",
        "性能计数与函数符号关联",
        "调试开关不会改变数值行为",
    ]),
    ("发布与升级", [
        "发布包包含版本兼容表",
        "已知限制与主机处理范围公开",
        "运行时与编译器产物分别版本化",
        "旧产物加载策略明确",
        "升级在独立分支运行全套回归",
        "外部函数数量和模型性能比较",
        "调优数据库复用需要兼容证明",
        "出现问题可回到上一稳定版本",
        "文档与代码在同一发布更新",
        "最终产物可由发布记录重新构建",
    ]),
]


def render_review(section: tuple, idx: int) -> str:
    name, items = section
    checks = "\n".join(f"- [ ] {item}" for item in items)
    return f"""
## 34.{idx} {name}

{checks}

{callout("note", "需要保存的证据", f"本节每个已完成项目都应有直接证据，例如 IR 快照、单元测试名称、构建信息、模块元数据、命令反汇编、驱动日志或性能报告。仅在会议记录中写“已确认”不能替代可重复检查的证据。")}
"""


review_body = "\n".join(
    render_review(s, i) for i, s in enumerate(review_sections, 1)
)
review_toc = "\n".join(
    f"- [[#34.{i} {s[0]}|34.{i} {s[0]}]]"
    for i, s in enumerate(review_sections, 1)
)
write(
    "34-评审检查表.md",
    f"""
{frontmatter}
# 34. 评审检查表

{callout("abstract", "用途", "本检查表用于方案评审、功能进入主分支、板卡联调、模型发布和版本升级。项目可以删去不适用项，但应记录原因，不应默认略过。")}

## 快速目录

{review_toc}

## 使用规则

1. 每个项目由负责实现的人提供证据，由另一位开发者复查；
2. 尚未完成的项目保留未选中状态并关联任务；
3. 影响数值、ABI、产物格式、驱动或固件的改动重新检查相关章节；
4. 模型级成功不能自动通过低层项目；
5. 性能项目只在正确性项目通过后生效。

{review_body}

## 最终交付记录

| 字段 | 内容 |
| --- | --- |
| TVM 提交 |  |
| 后端提交 |  |
| Runtime 版本 |  |
| 驱动版本 |  |
| 固件版本 |  |
| 硬件版本 |  |
| Target 配置散列值 |  |
| 模型散列值 |  |
| 测试报告 |  |
| 性能报告 |  |
| 已知限制 |  |
| 复查人 |  |
| 日期 |  |
""",
)


source_items = [
    ("架构", "docs/arch/index.rst", "端到端编译流程、核心数据结构与代码目录关系"),
    ("架构", "docs/arch/pass_infra.rst", "Pass、PassContext、Sequential 与插桩"),
    ("架构", "docs/arch/fusion.rst", "FuseOps、FuseTIR、FuseOpsByPattern 与融合分类"),
    ("架构", "docs/arch/external_library_dispatch.rst", "Relax BYOC 分区、RunCodegen 与外部 Runtime Module"),
    ("架构", "docs/arch/codegen.rst", "TIR pipeline、主机设备拆分和目标构建函数"),
    ("架构", "docs/arch/device_target_interactions.rst", "TargetKind、Target、DeviceAPI 与注册名"),
    ("架构", "docs/arch/runtime.rst", "PackedFunc、Module、Tensor 与最小运行时"),
    ("架构", "docs/arch/relax_vm.rst", "Relax VM 编译、字节码、链接和执行"),
    ("架构", "docs/arch/introduction_to_module_serialization.rst", "模块导入树、二进制保存与加载"),
    ("Relax", "docs/deep_dive/relax/index.rst", "Relax 学习入口"),
    ("Relax", "docs/deep_dive/relax/abstraction.rst", "图抽象、StructInfo 与程序结构"),
    ("Relax", "docs/deep_dive/relax/dpl.rst", "数据流模式语言与 FusionPattern"),
    ("Relax", "docs/deep_dive/relax/tutorials/relax_creation.py", "TVMScript、NNModule 和 BlockBuilder 创建方法"),
    ("Relax", "docs/deep_dive/relax/tutorials/relax_transformation.py", "Relax 自定义变换示例"),
    ("TensorIR", "docs/deep_dive/tensor_ir/index.rst", "tirx 与 s_tir 的当前组织"),
    ("TensorIR", "docs/deep_dive/tensor_ir/abstraction.rst", "PrimFunc、Buffer、SBlock 与迭代变量"),
    ("TensorIR", "docs/deep_dive/tensor_ir/tutorials/tir_creation.py", "创建 TensorIR"),
    ("TensorIR", "docs/deep_dive/tensor_ir/tutorials/tir_transformation.py", "调度原语与变换轨迹"),
    ("调优", "docs/deep_dive/tensor_ir/tutorials/dlight_gpu_scheduling.py", "DLight 规则调度"),
    ("调优", "docs/deep_dive/tensor_ir/tutorials/meta_schedule.py", "MetaSchedule 任务、候选、测量与数据库"),
    ("教程", "docs/how_to/tutorials/import_model.py", "PyTorch、ONNX 与 TFLite 导入"),
    ("教程", "docs/how_to/tutorials/customize_opt.py", "自定义优化流水、DLight 与 MetaSchedule"),
    ("教程", "docs/how_to/tutorials/cross_compilation_and_rpc.py", "交叉编译、上传、远程运行和设备计时"),
    ("教程", "docs/how_to/tutorials/bring_your_own_codegen.py", "v0.24.0 Example NPU BYOC 完整示例"),
    ("Python", "python/tvm/relax/backend/pattern_registry.py", "FusionPattern 注册与前缀查询"),
    ("Python", "python/tvm/relax/backend/utils.py", "BYOC 中间结果使用关系检查等工具"),
    ("Python", "python/tvm/relax/dpl/pattern.py", "DFPattern 类型和构造 API"),
    ("Python", "python/tvm/relax/dpl/context.py", "跨绑定模式上下文"),
    ("Python", "python/tvm/relax/dpl/rewrite.py", "模式改写工具"),
    ("Python", "python/tvm/relax/transform/transform.py", "Relax Pass 的 Python 入口与函数签名"),
    ("Python", "python/tvm/relax/vm_build.py", "Relax build 与 VMExecutable 组织"),
    ("前端", "python/tvm/relax/frontend/torch/exported_program_translator.py", "PyTorch ExportedProgram 转换"),
    ("前端", "python/tvm/relax/frontend/onnx/onnx_frontend.py", "ONNX 转换表与属性处理"),
    ("BYOC", "python/tvm/relax/backend/contrib/example_npu/patterns.py", "Example NPU 模式、检查函数与优先级"),
    ("BYOC", "src/relax/backend/contrib/example_npu/codegen.cc", "Example NPU JSON 代码生成与注册"),
    ("BYOC", "src/relax/backend/contrib/codegen_json/codegen_json.h", "JSONSerializer、节点属性与常量处理"),
    ("BYOC", "src/relax/backend/contrib/codegen_c/codegen_c.h", "C 源码型外部代码生成起点"),
    ("BYOC", "src/runtime/contrib/example_npu/example_npu_runtime.cc", "Example NPU JSON Runtime 空壳"),
    ("BYOC", "cmake/modules/contrib/ExampleNPU.cmake", "代码生成与运行时构建开关"),
    ("BYOC", "tests/python/contrib/test_example_npu.py", "模式、分区、代码生成与运行时测试"),
    ("Relax C++", "src/relax/transform/fuse_ops.cc", "FuseOps 与 FuseOpsByPattern 核心实现"),
    ("Relax C++", "src/relax/transform/merge_composite_functions.cc", "同后端组合函数整理"),
    ("Relax C++", "src/relax/transform/run_codegen.cc", "外部代码生成分派"),
    ("Relax C++", "src/relax/transform/legalize_ops.cc", "高层算子逐级转换入口"),
    ("Relax C++", "src/relax/transform/fuse_tir.cc", "组合后的 TIR 函数融合"),
    ("Relax C++", "src/relax/analysis/graph_partitioner.h", "图分区数据结构"),
    ("Relax C++", "src/relax/ir/dataflow_matcher.cc", "DPL 匹配器实现"),
    ("VM", "src/relax/backend/vm/codegen_vm.cc", "Relax 到 VM 字节码"),
    ("VM", "src/relax/backend/vm/codegen_vm_tir.cc", "VM 编译执行模式"),
    ("VM", "src/runtime/vm/vm.cc", "运行循环与函数调用"),
    ("Target", "src/target/target_kind.cc", "内置 TargetKind 注册"),
    ("Target", "src/target/codegen.cc", "目标代码生成统一入口"),
    ("Target", "src/target/source/codegen_c.cc", "C 源码生成器参考"),
    ("Runtime", "include/tvm/runtime/device_api.h", "DeviceAPI 接口与设备属性"),
    ("Runtime", "src/runtime/module.cc", "Module 公共实现与运行时注册入口"),
    ("Runtime", "src/runtime/metadata.h", "函数信息与运行时元数据结构"),
    ("Runtime", "src/runtime/device_api.cc", "DeviceAPI 获取与设备属性查询"),
    ("Runtime", "src/runtime/contrib/json/json_runtime.h", "JSONRuntimeBase"),
    ("Runtime", "src/runtime/contrib/json/json_node.h", "JSON 图节点与属性表示"),
    ("测试", "tests/python/relax/test_transform_fuse_ops_by_pattern.py", "FusionPattern 结构与属性测试"),
    ("测试", "tests/python/relax/test_transform_codegen_pass.py", "RunCodegen Pass 测试"),
    ("测试", "tests/python/relax/test_vm_build.py", "VM 构建行为"),
    ("测试", "tests/python/relax/test_vm_multi_device.py", "多设备 VM 行为"),
]


def render_source(item: tuple, idx: int) -> str:
    group, path, use = item
    url = f"https://github.com/apache/tvm/blob/v0.24.0/{path}"
    return f"""
### 29.{idx} {path}

- 类别：{group}
- 用途：{use}
- 在线源码：[{path}]({url})

阅读时先搜索本文件公开注册名、类名和关键属性，再查看相邻测试。若文档示例与本文件函数签名不同，以固定 tag 的源码与测试为准。升级 TVM 后，应重新核对该路径是否移动、注册名是否改变、参数是否增加，以及默认 Pass 次序是否变化。
"""


source_table = "\n".join(
    f"| {g} | [`{p}`](https://github.com/apache/tvm/blob/v0.24.0/{p}) | {u} |"
    for g, p, u in source_items
)
source_body = "\n".join(
    render_source(item, i) for i, item in enumerate(source_items, 1)
)
write(
    "29-官方资料与源码导航.md",
    f"""
{frontmatter}
# 29. 官方资料与源码导航

{callout("important", "资料基准", "网络检索与源码核对日期为 2026-07-29。手册固定 Apache TVM v0.24.0，提交 `af3e4ba`。官方网页可能随 main 分支更新；实现时以固定 tag 的源码和测试确认精确 API。")}

## 29.1 官方网页

| 主题 | 官方链接 | 建议用途 |
| --- | --- | --- |
| 文档首页 | [Apache TVM Documentation]({BASE_URL}/) | 查找当前公开 API |
| 安装 | [Install from Source]({BASE_URL}/install/from_source.html) | 依赖、CMake、tvm-ffi |
| 快速开始 | [Quick Start]({BASE_URL}/get_started/tutorials/quick_start.html) | 第一个 Relax 模型 |
| 设计 | [Design and Architecture]({BASE_URL}/arch/index.html) | 端到端设计概览 |
| Relax | [Relax Deep Dive]({BASE_URL}/deep_dive/relax/index.html) | 图级 IR |
| DPL | [Dataflow Pattern Language]({BASE_URL}/deep_dive/relax/dpl.html) | 模式与改写 |
| TensorIR | [TensorIR Deep Dive]({BASE_URL}/deep_dive/tensor_ir/index.html) | 张量程序 |
| Pass | [Pass Infrastructure]({BASE_URL}/arch/pass_infra.html) | 变换组合 |
| 融合 | [Operator Fusion]({BASE_URL}/arch/fusion.html) | FuseOps 与模式融合 |
| BYOC 教程 | [Bring Your Own Codegen]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html) | Example NPU |
| BYOC 设计 | [External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html) | RunCodegen 与 Runtime |
| 代码生成 | [Code Generation]({BASE_URL}/arch/codegen.html) | Target 构建 |
| 设备 | [Device/Target Interactions]({BASE_URL}/arch/device_target_interactions.html) | TargetKind 与 DeviceAPI |
| 运行时 | [TVM Runtime System]({BASE_URL}/arch/runtime.html) | PackedFunc 与 Module |
| VM | [Relax VM]({BASE_URL}/arch/relax_vm.html) | 字节码与执行 |
| 序列化 | [Module Serialization]({BASE_URL}/arch/introduction_to_module_serialization.html) | 模块导出与加载 |
| 模型导入 | [Importing Models]({BASE_URL}/how_to/tutorials/import_model.html) | PyTorch、ONNX、TFLite |
| 调优 | [MetaSchedule]({BASE_URL}/deep_dive/tensor_ir/tutorials/meta_schedule.html) | 搜索与测量 |
| 远程运行 | [Cross Compilation and RPC]({BASE_URL}/how_to/tutorials/cross_compilation_and_rpc.html) | 交叉编译和设备测量 |
| 发布 | [Apache TVM Releases](https://github.com/apache/tvm/releases) | 固定 tag 与升级评估 |

## 29.2 本地 SSH 源码

本手册核对源码时使用：

```text
remote: git@github.com:apache/tvm.git
tag:    v0.24.0
commit: af3e4ba
```

推荐命令：

```bash
git clone --recursive git@github.com:apache/tvm.git
git -C tvm checkout v0.24.0
git -C tvm rev-parse HEAD
```

## 29.3 源码速查表

| 类别 | 路径 | 用途 |
| --- | --- | --- |
{source_table}

## 29.4 逐项导航

{source_body}

## 29.5 搜索方法

```bash
rg -n 'relax.ext.example_npu' .
rg -n 'runtime.ExampleNPUJSONRuntimeCreate' .
rg -n 'FuseOpsByPattern' python src tests docs
rg -n 'target.build.' src include
rg -n 'device_api.' src include
```

搜索注册字符串通常比只搜索类名更快，因为 Python API、C++ 实现、CMake 和测试会通过同一字符串相连。
""",
)


pipeline_stages = [
    ("环境确认", "源码、动态库、Python 包与依赖", "读取提交号、构建选项和加载路径", "版本和路径完全一致", "environment.txt 与 libinfo.txt", "任何版本或路径无法解释时停止后续编译"),
    ("模型冻结", "源框架模型与示例输入", "切换推理状态，固定参数和随机种子", "训练专用节点已消除或固定", "model_hash.txt 与 source_output.npz", "源框架结果不稳定时不进入 TVM"),
    ("前端导入", "ExportedProgram、ONNX 或 TFLite 对象", "调用对应 Relax 前端", "函数参数、返回、形状和数据类型", "00_imported.py", "未被支持的源算子需要自定义转换或更换导出方式"),
    ("参数分离", "导入后的 IRModule", "决定常量嵌入或 `detach_params`", "参数名称、顺序、形状、数据类型和内容散列", "01_params.json 与 params.npz", "参数顺序不稳定时不能继续生成外部 ABI"),
    ("基础规范化", "带前端特征的 Relax", "运行规范化、绑定整理和必要的形状推断", "等价表达式是否变成稳定形式", "02_normalized.py", "规范化后 StructInfo 缺失要先修复"),
    ("常量处理", "规范化模块", "折叠与目标无关的常量计算", "常量数量、体积与是否破坏组合模式", "03_constants.py", "不能把运行期输入错误折叠为常量"),
    ("低比特整数图准备", "浮点或已有整数模型", "按项目流程建立显式转换节点和数值参数", "scale、zero point、参数维度和输出数据类型", "04_integer_graph.py", "数值参数缺失或公式版本不明时停止"),
    ("候选模式发现", "稳定 Relax 图", "运行 DPL 匹配但暂不改变模块", "每类候选数量与结构", "05_candidates.json", "候选为 0 时先检查真实图结构"),
    ("能力检查", "候选子图与 Target", "逐项检查形状、数据类型、属性、布局、工作区和收益", "接纳结果与原因码", "06_decisions.json", "无法证明安全的候选改由其他后端执行"),
    ("模式融合", "候选与 FusionPattern", "执行 FuseOpsByPattern", "Composite 函数数量、参数与返回", "07_fused.py", "具体模式被普通模式抢占时调整优先级"),
    ("外部函数整理", "带 Composite 的模块", "执行 MergeCompositeFunctions", "Codegen、global_symbol 与调用关系", "08_merged.py", "符号重复或函数接口不稳定时停止"),
    ("NPU 外部代码生成", "NPU 外部函数数组", "执行 RunCodegen 与自研编译器", "模块 type key、产物版本、常量目录和命令摘要", "09_codegen.py、artifact.bin、artifact.json", "任何静态地址或命令检查失败都阻止输出"),
    ("剩余算子逐级转换", "NPU 节点已替换的 Relax", "对剩余节点运行 LegalizeOps", "call_tir、外部函数和未处理节点", "10_legalized.py", "主机 Target 缺少实现时补充实现或改变分区"),
    ("普通算子融合", "包含 call_tir 的模块", "执行 AnnotateTIROpPattern、FuseOps 与 FuseTIR", "剩余计算内核数量和函数参数", "11_host_fused.py", "不得跨 NPU 外部函数错误融合"),
    ("TensorIR 调度", "未调度 PrimFunc", "应用 DLight、MetaSchedule 记录或自定义规则", "循环、缓冲区、内存作用域和调度轨迹", "12_scheduled.py 与 schedule_trace.json", "没有记录的任务必须有基础调度"),
    ("TensorIR 逐级转换", "已调度 PrimFunc", "运行目标所需低层 Pass", "内建函数、缓冲区展平、主机与设备标记", "13_tir_lowered.py", "未被支持的内建函数应在代码生成前被发现"),
    ("目标代码生成", "低层 TIR IRModule 与 Target", "调用目标构建函数", "主机 Module、设备 Module 与导入关系", "14_native_modules.txt", "编译期不得查询本机实际 NPU"),
    ("VM 代码生成", "剩余 Relax 控制函数", "生成 VM 字节码或编译模式 TIR", "Call、Ret、Goto、If 和函数目录", "15_vm.astext", "控制流与函数参数数量必须一致"),
    ("模块链接", "VM、主机模块、NPU 模块与常量", "建立 VMExecutable", "所有外部符号可查且导入关系完整", "16_linked_modules.txt", "任一函数缺失时不进入导出"),
    ("导出", "完整可执行对象", "export_library 并保存参数", "共享库、权重文件、元数据和内容散列", "model.so、params.npz、manifest.json", "外部 Module 不可保存时修复序列化"),
    ("独立加载", "部署文件与仅运行时环境", "在新进程 load_module", "函数目录、模块版本和设备能力", "17_load.log", "依赖编译进程内全局状态的产物不合格"),
    ("常量初始化", "已加载模块与权重", "分配设备常量内存并上传", "常量数量、散列、地址和引用计数", "18_init.log", "内容或目标不匹配时拒绝缓存"),
    ("输入绑定", "运行期 Tensor", "检查参数、形状、数据类型、步长、设备和对齐", "动态版本、工作区和复制计划", "19_bind.json", "超范围输入走明确的其他后端或报告错误"),
    ("设备执行", "已重定位命令与实际 Tensor", "复制、提交、等待并读取状态", "提交序号、事件、设备错误和输出", "20_runtime.log 与 commands.disasm", "超时后不得继续使用旧事件和地址"),
    ("结果核对", "源框架、CPU 和 NPU 输出", "按数值合同比较并定位首个差异", "位级结果或误差统计", "21_compare.json 与 failing_case.npz", "功能未通过时性能结果无效"),
    ("性能测量", "功能正确的稳定产物", "预热、多次重复并读取设备计数", "复制、提交、执行、等待、带宽和利用率", "22_perf.json", "网络传输和日志输出不得混入设备执行时间"),
    ("发布归档", "通过回归的产物与报告", "生成兼容表、已知限制和重建信息", "所有版本与散列可追溯", "release_manifest.yaml", "缺少任一关键版本时不作为正式发布"),
]


def render_stage(stage: tuple, idx: int) -> str:
    name, input_state, action, inspect, evidence, stop = stage
    return f"""
## 35.{idx} {name}

{callout("abstract", "阶段目标", f"把“{input_state}”处理成下一阶段可以可靠接收的状态，并留下足够证据。")}

### 输入条件

本阶段输入是：{input_state}。进入前先确认上一阶段的错误已经处理，文件内容散列和配置仍与记录一致。若输入来自缓存，要验证缓存键包含 TVM、后端、Target、模型和数值配置版本。

### 处理动作

{action}。执行动作时使用单独的 Pass 或函数，避免在多个阶段共享不可见的全局可变状态。编译服务并行处理多个模型时，每个任务拥有独立上下文。

### 必查内容

{inspect}。检查既包含“存在什么”，也包含“不应存在什么”。例如外部代码生成后应出现 NPU Module，但原组合函数不应继续作为未处理调用残留。

### 证据文件

保存 `{evidence}`。文本证据使用稳定排序，二进制证据同时保存内容散列和解析摘要。IR 证据优先保存 `mod.script()`，结构测试使用结构相等 API。

### 失败处理

{stop}。失败时保持原始输入、阶段配置、异常栈和部分输出；不要用下一阶段的自动修复掩盖本阶段错误。

### 评审问题

1. 本阶段是否读取了未记录的环境变量？
2. 相同输入重复执行是否得到结构相同的输出？
3. 缓存失效条件是否完整？
4. 错误能否指向函数、节点、字段或命令？
5. 本阶段输出是否能被一个独立小测试消费？

{callout("tip", "初学者检查法", "第一次执行时同时保存处理前后文本，用差异工具只看本阶段变化。若一次出现大量不相关变化，说明阶段职责过大，应继续拆分。")}
"""


stage_toc = "\n".join(
    f"- [[#35.{i} {s[0]}|35.{i} {s[0]}]]"
    for i, s in enumerate(pipeline_stages, 1)
)
stage_body = "\n".join(
    render_stage(s, i) for i, s in enumerate(pipeline_stages, 1)
)
write(
    "35-编译流程逐阶段检查手册.md",
    f"""
{frontmatter}
# 35. 编译流程逐阶段检查手册

{callout("abstract", "用途", "本章把一次完整编译和执行拆成可单独检查的阶段。每一阶段都给出输入条件、处理动作、必查内容、证据文件与停止条件，适合新成员学习、自动化编译服务和问题定位。")}

## 快速目录

{stage_toc}

## 总体状态变化

```mermaid
flowchart LR
    A["源模型"] --> B["Relax"]
    B --> C["NPU 分区"]
    C --> D["外部 Module + TIR"]
    D --> E["VMExecutable"]
    E --> F["部署文件"]
    F --> G["设备执行"]
    G --> H["结果与性能报告"]
```

{stage_body}

## 证据目录建议

```text
build-report/
├── environment/
├── ir/
├── partition/
├── npu-artifact/
├── native-modules/
├── executable/
├── runtime/
├── compare/
└── performance/
```
""",
)


model_guides = [
    ("CNN 图像分类", "Conv2D、bias、ReLU、Pool、残差 Add、最后的 MatMul", "输入通常静态，批次大小可为有限集合", "首版优先融合 Conv+Bias+Activation；Depthwise 单独核对 groups 与通道", "图像预处理、NCHW/NHWC 数据布局和 AvgPool 分母", "多个输入尺寸、残差支路、通道尾部和分类 Top-k", "卷积权重复用、片外带宽和组合后中间写回"),
    ("MobileNet 类网络", "Depthwise Conv、Pointwise Conv、ReLU6、残差", "输入静态或少量分辨率", "Depthwise 与 1×1 Conv 需要不同分块；尽量保留激活片上", "把普通 grouped Conv 误当 Depthwise，以及 ReLU6 阈值", "channel multiplier、通道前后值、stride 2 和不同宽度系数", "Depthwise 通道利用率与 1×1 Conv 矩阵利用率"),
    ("目标检测", "Backbone、FPN、多输出头、Decode 与 NMS", "图像可多尺寸，候选框数量动态", "Backbone 和卷积头进入 NPU；NMS 可先由主机执行", "多输出绑定、Resize 坐标规则、Concat 维度和动态候选数量", "不同图像尺寸、无目标、多目标、最大候选数和 NMS 对照", "设备切换、特征金字塔内存和后处理占比"),
    ("图像分割模型", "Backbone、空洞卷积、Resize、Concat、像素分类", "空间尺寸较大且可能动态", "优先处理卷积主干；Resize 与 dilation 只有行为完全一致才接纳", "高分辨率工作区、插值坐标和输出布局", "奇数空间尺寸、各 dilation、上采样端点和像素级对照", "峰值内存、Resize 带宽与大特征图 DMA"),
    ("纯 MLP 与推荐网络", "MatMul、bias、Activation、Embedding、Concat", "批次大小变化明显，表查找可能随机", "大 MatMul 进入矩阵单元；小逐元素尽量组合；Embedding 评估主机执行", "同形不同权重缓存、稀疏或随机访问和小批次启动开销", "批次 1 到上限、长条矩阵、重复 id、越界 id 和组合数值", "小批次时延、权重带宽、Embedding 有效带宽"),
    ("Transformer Encoder", "QKV MatMul、Attention、残差、LayerNorm、GELU", "批次和序列长度可变，隐藏层维度通常固定", "先接 MatMul 与逐元素，再增加 Softmax、Norm 和完整 Attention", "mask 形式、LayerNorm 公式、Attention 维度次序和动态工作区", "多头、不同 sequence、padding mask、极端分数与 Norm 小方差", "分数矩阵写回、QKV 权重复用、CME 与 Matrix 重叠"),
    ("Transformer Decoder Prefill", "Causal Attention、KV Cache 写入、MLP、RMSNorm、RoPE", "输入 sequence 范围大，批次通常较小", "为常见长度生成多版本；Attention 可逐步从分阶段升级为在线分块", "causal mask、RoPE 变体、KV Cache 布局和工作区上限", "sequence 分块端点、最大上下文、多会话和 Prefill 输出", "长序列扩展趋势、KV 读写、片上占用和命令数量"),
    ("大模型 Decode", "单 token MatMul、KV Cache 读取、Attention、采样前 logits", "query_len 常为 1，历史长度每步增长", "优化小 M 矩阵与权重流；保持 KV 和中间数据驻留设备", "小矩阵利用率、每 token 固定开销、状态错误和并发会话", "逐 token 对照、page 交界、最大历史长度、设备复位后状态", "单 token 时延、权重带宽、KV 带宽和队列提交"),
    ("RNN / GRU / LSTM", "门 MatMul、Sigmoid、Tanh、逐元素乘加、循环状态", "时间步可变，隐藏维度固定", "把多个门 MatMul 合并，状态留在设备；特殊函数版本必须一致", "状态生命周期、时间步失败传播、门顺序和公式差异", "单步与整序列、长序列、状态极值、分段执行一致性", "状态读写、门融合、CME 吞吐与时间步启动"),
    ("语音与音频模型", "Conv1D、频谱前端、RNN 或 Transformer、动态时间长度", "长度变化大，可能要求流式状态", "Conv1D 与帧级矩阵进入 NPU；流式历史缓冲由 Runtime 管理", "causal padding、采样率、分帧参数、状态跨调用", "短于 kernel、整帧前后、分段与整段、静音和极值", "实时因子、历史复制、端到端首帧时延"),
    ("图神经网络", "Gather、Scatter、分段归约、MatMul", "节点和边数量动态，访问不规则", "稠密特征 MatMul 可先进入 NPU；索引类算子视地址单元能力决定", "越界索引、重复写冲突、动态工作区和随机带宽", "空图、孤立节点、重复边、大度数、不同索引顺序", "随机访问带宽、原子冲突、主机设备切换"),
    ("多模态模型", "图像编码器、文本编码器、投影层、跨模态 Attention", "图像 token 和文本 sequence 都可能变化", "各编码器先独立分区，再处理投影和跨模态组合", "不同数据布局、多个输入设备位置、token 拼接顺序", "单模态缺失、不同图像数量、文本长短、跨模态 mask", "两类编码器并行、数据驻留和跨模态 Attention 内存"),
]


def render_model_guide(model: tuple, idx: int) -> str:
    name, structure, dynamic, strategy, risks, tests, perf = model
    return f"""
## 36.{idx} {name}

{callout("abstract", "典型结构", structure)}

### 形状与状态

{dynamic}。导入模型后先列出输入、输出和主要中间 Tensor 的形状表达式，区分固定维度、有限集合和范围动态维度。若模型带状态，还要记录状态拥有者、更新时机和设备复位后的恢复方法。

### 推荐接入次序

{strategy}。首版目标是覆盖高耗时且合同清楚的子图，同时保留主机执行。每次扩大组合范围前，先用编译报告确认新增覆盖来自预期模式，而不是宽松检查造成误认。

### 主要风险

{risks}。这些问题应进入模式检查、代码生成静态检查或 Runtime 参数检查中的明确一层，并有对应原因码。不要只在模型测试中观察最终精度。

### 测试集合

{tests}。除任务指标外，还要抽取关键中间值与 CPU 或源框架对照。动态模型覆盖范围端点，状态型模型覆盖首次、重复、多会话和失败恢复。

### 性能观察

重点记录：{perf}。端到端报告同时列出外部函数数量、设备切换、峰值内存、复制字节和各执行单元忙碌周期。

### 交付清单

- [ ] 代表模型和权重散列值；
- [ ] 输入预处理与输出后处理；
- [ ] 形状集合与动态范围；
- [ ] 模式接纳统计；
- [ ] 主机执行节点清单；
- [ ] 数值对照报告；
- [ ] 峰值内存与工作区；
- [ ] 端到端时延与吞吐率；
- [ ] 长时间和异常恢复结果；
- [ ] 已知限制。

{callout("question", "模型评审", f"{name} 的性能主要受算力、片外带宽、随机访问、特殊函数还是设备切换影响？若某个子图不进入 NPU，当前证据能否说明是能力限制、编译器限制还是收益不足？")}
"""


model_toc = "\n".join(
    f"- [[#36.{i} {m[0]}|36.{i} {m[0]}]]"
    for i, m in enumerate(model_guides, 1)
)
model_body = "\n".join(
    render_model_guide(m, i) for i, m in enumerate(model_guides, 1)
)
write(
    "36-模型家族接入指南.md",
    f"""
{frontmatter}
# 36. 模型家族接入指南

{callout("abstract", "用途", "不同模型家族的算子组合、动态形状、状态和性能限制差异很大。本章按结构给出接入次序、风险、测试与性能观察，帮助团队从单算子走向完整模型。")}

## 快速目录

{model_toc}

## 通用步骤

1. 在源框架固定模型和预处理；
2. 导入 Relax 后统计算子、形状和参数；
3. 运行 NPU 预检查并汇总拒绝原因；
4. 选择覆盖时间最多且合同最清楚的子图；
5. 完成逐层数值对照；
6. 测量设备切换、复制、工作区和执行单元；
7. 扩展组合并重复回归；
8. 对动态形状与状态建立专门测试。

{model_body}

## 结论

模型覆盖不是“支持算子数量”的简单累加。决定端到端效果的是组合范围、数据驻留、动态形状、状态、数值规则和真实设备时间。编译报告与性能报告应共同解释每个模型的结果。
""",
)


document_templates = [
    {
        "name": "Target 能力文件",
        "purpose": "给编译器提供可复现的硬件固定限制和默认参数，禁止从编译主机自动猜测。",
        "fields": "schema_version、arch、device_type、matrix_m/n/k、vector_bytes、sram_bytes、dma_alignment、max_commands、支持的数据类型、固件 ABI、可选功能位。",
        "checks": "字段类型与范围；未知字段处理；缺省值；硬件能力寄存器核对；内容散列；不同型号继承关系。",
        "consumer": "模式检查、分块选择、代码生成、静态检查、运行时加载和性能报告。",
    },
    {
        "name": "算子合同",
        "purpose": "把“支持某算子”展开为前端结构、属性、形状、数据类型、数值、布局、尾部、工作区和错误处理。",
        "fields": "Relax 名称、组合名称、输入输出、属性集合、动态形状范围、布局、累加类型、舍入、饱和、工作区公式、设备命令和其他后端执行规则。",
        "checks": "每个限制有正反样本；公式可独立计算；前端不同写法；组合前后行为；版本变化。",
        "consumer": "DPL 检查函数、自研内部 IR、参考模型、固件、RTL 和测试。",
    },
    {
        "name": "模式接纳报告",
        "purpose": "记录每个候选子图被 NPU 接纳或改由其他后端执行的原因。",
        "fields": "模型函数、候选编号、模式名称、源节点、形状、数据类型、属性摘要、Target、结果、原因码、详细说明、估计收益。",
        "checks": "候选总数守恒；原因码稳定；没有空说明；同一输入重复编译结果一致；敏感模型信息可按需隐藏。",
        "consumer": "编译日志、模型覆盖分析、能力规划、版本回归和性能优化。",
    },
    {
        "name": "编译流程清单",
        "purpose": "固定每个 Pass 的名称、顺序、配置、输入要求和输出证据。",
        "fields": "阶段编号、Pass 名、版本、配置、前置条件、产生属性、删除属性、缓存键、IR 文件名、耗时和错误。",
        "checks": "顺序变化有测试；默认 pipeline 也展开记录；Pass 重复执行稳定；失败停止位置明确。",
        "consumer": "CLI、编译服务、CI、问题定位和版本升级。",
    },
    {
        "name": "编译产物清单",
        "purpose": "描述一个可部署包中共享库、NPU 模块、权重、元数据和调试文件的关系。",
        "fields": "格式版本、每个文件名、字节数、内容散列、函数目录、目标、所需 Runtime、驱动与固件版本、创建时间和构建来源。",
        "checks": "文件完整；散列正确；未知版本拒绝；可在新进程加载；仅运行时环境依赖齐全。",
        "consumer": "发布工具、运行时加载器、模型仓库和现场诊断。",
    },
    {
        "name": "逻辑缓冲区表",
        "purpose": "把输入、输出、常量、工作区和片上暂存区用统一编号描述，供内存规划与重定位。",
        "fields": "buffer_id、名称、角色、形状、数据类型、布局、字节数、对齐、内存类别、生命周期、物理偏移、读写者。",
        "checks": "大小无溢出；同时存活区域不重叠；输入输出 ABI 一致；常量只读；异步生命周期正确。",
        "consumer": "代码生成、Runtime、命令反汇编、静态检查和内存报告。",
    },
    {
        "name": "命令目录",
        "purpose": "让二进制命令可以被独立解析，并从设备错误返回到源节点。",
        "fields": "命令序号、opcode、执行单元、源节点、读取缓冲区、写入缓冲区、偏移、长度、等待事件、完成事件和字段摘要。",
        "checks": "地址在缓冲区内；事件生产者存在；依赖无环；命令数量合法；字段值属于固件版本。",
        "consumer": "固件、模拟器、反汇编器、错误报告和性能分析。",
    },
    {
        "name": "数值规则表",
        "purpose": "统一编译器、参考模型、固件和 RTL 对低比特整数计算的位级处理。",
        "fields": "输入输出数据类型、有符号性、scale、zero point、参数维度、乘积宽度、累加宽度、bias 域、整数乘数、移位、舍入、饱和和特殊函数版本。",
        "checks": "正负中点；最小最大值；临时宽度上界；per-channel 参数数量；INT4 打包；组合运算次序。",
        "consumer": "图转换、代码生成、设备命令、参考模型、单算子测试和模型精度报告。",
    },
    {
        "name": "测试向量清单",
        "purpose": "让每个失败样本可以跨编译器、模拟器、固件和 RTL 重复。",
        "fields": "测试名称、随机种子、输入文件、常量文件、形状、数据类型、Target、编译选项、预期文件、允许误差和预期错误。",
        "checks": "文件散列；端序；打包；预处理；参考模型版本；极值与尾部覆盖；失败样本最小化。",
        "consumer": "Python 测试、C++ 测试、板卡服务、RTL 环境和持续集成。",
    },
    {
        "name": "性能报告",
        "purpose": "把端到端时延拆成可解释部分，并把结果与模型、产物和设备版本关联。",
        "fields": "预热、重复、时间分布、准备、复制、提交、排队、执行、等待、片外字节、命令数、MAC、峰值内存、各单元忙碌周期、温度和频率。",
        "checks": "功能先通过；设备独占；网络传输分开；计数器范围正确；冷启动与稳态分开；统计方法固定。",
        "consumer": "调优器、架构分析、版本门限、模型发布和性能问题定位。",
    },
    {
        "name": "错误报告",
        "purpose": "用统一结构记录编译、加载、复制、提交、执行和等待错误。",
        "fields": "阶段、主机错误码、驱动错误码、设备错误码、外部函数、提交序号、命令序号、执行单元、可恢复性、详细说明和证据目录。",
        "checks": "首个错误不被后续错误覆盖；资源清理结果；设备状态；重试条件；敏感信息处理。",
        "consumer": "Runtime、编译服务、测试平台、现场日志和故障统计。",
    },
    {
        "name": "版本兼容表",
        "purpose": "明确 TVM、后端编译器、模块格式、Runtime、驱动、固件和硬件之间允许的组合。",
        "fields": "组件名称、版本范围、最低版本、最高已测版本、模块 ABI、固件 ABI、功能限制、升级步骤和回退版本。",
        "checks": "加载阶段执行检查；未知组合默认拒绝；兼容声明有自动测试；旧产物处理明确。",
        "consumer": "构建系统、发布工具、Runtime、部署平台和维护人员。",
    },
    {
        "name": "模型发布记录",
        "purpose": "把模型来源、输入输出、编译配置、测试、性能和限制形成一个可重新构建的记录。",
        "fields": "模型名称、源文件散列、权重散列、前端版本、输入预处理、输出后处理、Target、流水、产物散列、测试报告、性能报告、已知限制和维护人。",
        "checks": "从记录可重新构建；部署文件与散列一致；主机执行节点清单存在；动态范围与状态说明完整。",
        "consumer": "模型仓库、部署服务、应用团队、质量团队和版本升级。",
    },
]


def render_doc_template(item: dict, idx: int) -> str:
    return f"""
## 37.{idx} {item['name']}

{callout("abstract", "用途", item["purpose"])}

### 必填内容

{item['fields']}

字段使用稳定名称和明确单位。大小统一注明元素数还是字节数，时间统一注明秒、毫秒、微秒或周期，形状使用完整维度次序，地址说明是逻辑偏移、IOVA 还是其他设备地址。代码中的字段名保留英文，中文说明使用 [[33-术语与 API 速查]] 的写法。

### 核对方法

{item['checks']}。所有自动计算字段同时保存输入和算法版本，使另一工具能够复算。表内的“未设置”与数值 0 必须区分。

### 使用者

{item['consumer']}。不同使用者读取同一份结构化数据，减少手工复制产生的不一致。若某个组件需要额外字段，应先提升 schema 版本并给出旧版本处理方法。

### YAML 骨架

```yaml
document:
  kind: "{item['name']}"
  schema_version: 1
  created_by:
  source_commit:
  target:
  inputs:
  outputs:
  checks:
  evidence:
  notes:
```

### 评审问题

1. 字段是否能由工具自动检查？
2. 是否有含糊单位或隐含默认值？
3. 版本变化后旧文件如何处理？
4. 失败时能否从本文件找到直接证据？
5. 是否存在由多个团队各自维护的重复定义？

{callout("tip", "实施建议", "先用 YAML 或 JSON 建立可读版本，再为性能和加载需求增加紧凑二进制。结构定义放在共享目录，生成 Python、C++ 和固件读取代码，避免三份手写结构逐渐不同。")}
"""


template_toc = "\n".join(
    f"- [[#37.{i} {x['name']}|37.{i} {x['name']}]]"
    for i, x in enumerate(document_templates, 1)
)
template_body = "\n".join(
    render_doc_template(x, i) for i, x in enumerate(document_templates, 1)
)
write(
    "37-设计文档与配置模板.md",
    f"""
{frontmatter}
# 37. 设计文档与配置模板

{callout("abstract", "用途", "本章提供 Target、算子合同、接纳报告、编译产物、缓冲区、命令、数值、测试、性能、错误和版本记录模板。建议把模板转换成仓库内的 schema 与自动检查工具。")}

## 快速目录

{template_toc}

## 编写原则

1. 机器可读字段与面向人的说明同时存在；
2. 每个数值带单位；
3. 每个文件带 schema 版本；
4. 每个产物带来源提交和内容散列；
5. 不使用无法从测试或工具确认的模糊描述；
6. 版本不兼容时默认拒绝，不静默忽略字段。

{template_body}

## 模板自动检查

模板只有在进入自动工具后才真正发挥作用。建议为每一种文档建立 JSON Schema 或等价的类型定义，并在提交时检查必填字段、枚举值、单位、整数范围、文件散列和版本关系。算子合同中的形状限制可以生成 Python 检查函数，Target 能力文件可以生成 C++ 常量读取代码，命令目录可以生成反汇编字段表。这样，文档、编译器和固件不需要分别抄写相同参数。

自动检查工具应输出文件名、字段路径、期望类型、实际值和修复提示。例如 `targets/npu_v1.yaml` 的 `dma_alignment` 若不是 2 的幂，错误应直接指出字段，而不是等到设备提交后报告地址问题。模块格式和命令格式还应加入未知字段、缺失字段、截断输入、超大长度和整数溢出的测试。

对会影响数值的字段，要从合同生成固定测试向量。修改舍入方式、累加宽度、特殊函数版本或 INT4 打包次序时，CI 自动选择相关单算子与组合算子测试。对会影响性能但不改变结果的字段，则运行代表尺寸的性能集合，并保留新旧时间分布。两类改动不能只用同一种门限。

模板升级采用“读取旧版本、写出新版本”的迁移工具。迁移前后保存内容散列和字段差异，禁止运行时在没有日志的情况下丢弃旧字段。若旧版本无法安全解释，新 Runtime 应拒绝加载并给出所需工具版本。发布包同时携带 schema、示例、迁移说明和最小读取器测试。

{callout("important", "共同来源", "硬件固定参数只能有一个受版本控制的共同来源。RTL 参数、固件能力表、编译器 Target 和文档表格由工具从该来源生成，或由自动检查证明一致。手工维护多份相同数值很容易在版本升级时产生差异。")}

## 建议落库位置

```text
acme-npu/
├── schema/
├── targets/
├── operator-contracts/
├── module-format/
├── command-format/
├── test-vectors/
├── performance/
└── releases/
```

这些目录应进入版本控制。二进制大文件可放入有内容寻址能力的制品库，仓库保留清单和散列值。
    """,
)


def bt(
    title: str,
    focus: str,
    official: str,
    project: str,
    inspect: str,
    reject: str,
    test: str,
    evidence: str,
) -> dict:
    return {
        "title": title,
        "focus": focus,
        "official": official,
        "project": project,
        "inspect": inspect,
        "reject": reject,
        "test": test,
        "evidence": evidence,
    }


def render_byoc_topic(chapter_no: int, topic: dict, idx: int) -> str:
    return f"""
## {chapter_no}.{idx} {topic['title']}

{callout("abstract", "本节目标", topic["focus"])}

### 先理解要解决的问题

{topic['focus']}。对初学者而言，可以把这一项看成一次责任交接：前一阶段必须把后续阶段需要的信息写入 IR、属性或结构化参数，后一阶段只能依据这些信息工作，不能猜测模型作者的意图。阅读打印出来的 IR 时，应先找负责交接的函数、属性和调用，再观察普通 TVM 节点与外部后端节点分别保留在哪里。

### 官方实现中的具体行为

{topic['official']}。本手册以 v0.24.0 源码、对应测试和当前在线教程共同核对。若在线教程与固定版本存在目录或接口差异，项目代码以固定提交的函数签名为准，教程用于理解整体方法。检查源码时同时查看注册位置、调用位置和测试，不要只看一个帮助函数。

### 自研 NPU 中的实现方法

{topic['project']}。建议把这一项实现为独立函数或独立类，并把硬件固定限制从 Target 能力文件传入。实现函数返回结构化结果，其中至少包含成功状态、原因码、涉及的 Relax 节点、关键属性摘要和建议处理方式。这样，编译报告、单元测试和模型覆盖统计都能使用同一结果。

### 必须逐项核对的信息

{topic['inspect']}。核对时要记录数值单位、维度次序、数据类型、有符号性、内存类别和版本来源。形状中的符号变量要保留名称及约束，不能用一个示例值替换后继续编译。常量内容很大时可以只记录稳定名称、数据类型、形状和内容散列值，但调试工具应能找到原始权重。

### 拒绝与异常处理

{topic['reject']}。拒绝不是失败，只表示该候选继续由 TVM 自带后端或另一外部后端处理。真正的编译错误只用于模型本身无效、产物内部不一致、所需运行时没有注册、或用户明确要求全部进入 NPU 但仍有节点未被接纳等情况。

### 测试方法

{topic['test']}。每个正向样本至少再配一个只改变单一条件的反向样本，使测试失败时能立即知道是哪条规则失效。对 IR 变换使用结构比较，对编译产物使用字段解析和散列比较，对运行结果使用独立参考实现，对性能使用设备端计时与多次统计。

### 应保留的证据

{topic['evidence']}。按模型、外部函数和编译阶段归档，在总清单中保存内容散列值；推导数值同时保存原始输入与算法版本。

{callout("important", "完成条件", "能从变换前后 IR 追踪到外部产物和运行时调用；能说明接纳结果；能用最小测试复现，并能在新进程加载产物。")}
"""


byoc_deep_chapters = [
    {
        "no": 38,
        "title": "BYOC 官方教程逐步解析",
        "summary": "按照官方 Example NPU 教程的执行顺序，从导入注册模块开始，逐行解释模式查询、模型定义、图分区、外部代码生成、VM 构建和运行，并明确教学空壳与真实设备实现的差别。",
        "official": f"[官方 BYOC 教程]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html)、[External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html) 与 v0.24.0 `docs/how_to/tutorials/bring_your_own_codegen.py`。",
        "extra": r"""
## 38.0 可直接运行的最小流程

```python
import numpy as np
import tvm
import tvm.relax.backend.contrib.example_npu
from tvm import relax
from tvm.relax.backend.pattern_registry import get_patterns_with_prefix
from tvm.relax.transform import (
    FuseOpsByPattern,
    MergeCompositeFunctions,
    RunCodegen,
)
from tvm.script import relax as R

patterns = get_patterns_with_prefix("example_npu")

@tvm.script.ir_module
class MatmulReLU:
    @R.function
    def main(
        x: R.Tensor((2, 4), "float32"),
        w: R.Tensor((4, 8), "float32"),
    ) -> R.Tensor((2, 8), "float32"):
        with R.dataflow():
            y = relax.op.matmul(x, w)
            z = relax.op.nn.relu(y)
            R.output(z)
        return z

mod = FuseOpsByPattern(
    patterns,
    bind_constants=False,
    annotate_codegen=True,
)(MatmulReLU)
mod = MergeCompositeFunctions()(mod)

has_codegen = tvm.get_global_func("relax.ext.example_npu", True)
has_runtime = tvm.get_global_func(
    "runtime.ExampleNPUJSONRuntimeCreate", True
)
if has_codegen and has_runtime:
    mod = RunCodegen()(mod)
    executable = relax.build(mod, tvm.target.Target("llvm"))
    vm = relax.VirtualMachine(executable, tvm.cpu())
    x = tvm.runtime.tensor(np.ones((2, 4), "float32"))
    w = tvm.runtime.tensor(np.ones((4, 8), "float32"))
    result = vm["main"](x, w)
    assert result.numpy().shape == (2, 8)
```

> [!warning] 教学运行时不计算数值
> Example NPU 的 `Run()` 记录内存层次、执行单元和融合选择，但没有写出正确结果。上例只能确认流程和形状。真实 NPU 后端必须与 NumPy、PyTorch 或另一可信实现比较数值。
""",
        "topics": [
            bt(
                "构建开关与功能探测",
                "在运行教程前确认代码生成器与运行时构造函数是否进入当前 TVM 动态库",
                "官方教程要求 `USE_EXAMPLE_NPU_CODEGEN=ON` 与 `USE_EXAMPLE_NPU_RUNTIME=ON`，并用 `tvm.get_global_func` 进行运行时探测",
                "为自研后端分别提供编译器开关和运行时开关，使开发环境、只运行环境和不含 NPU 的环境都能构建",
                "CMake 缓存、实际加载的 `libtvm`、Python 包路径、两个全局注册名、模块 type key",
                "注册函数缺失时跳过相关教程或报告构建配置，不能调用空对象",
                "分别构建全功能版本、只运行版本和关闭后端版本，检查符号存在性及依赖文件",
                "CMake 配置摘要、`libinfo()`、全局函数查询结果和动态库依赖清单",
            ),
            bt(
                "导入模块触发模式注册",
                "理解 `import tvm.relax.backend.contrib.example_npu` 不只是导入名称，还会执行模块末尾的 `register_patterns`",
                "官方教程在查询模式之前显式导入 Example NPU 模块，模式注册表随后可按 `example_npu` 前缀返回项目",
                "把自研模式注册放入清楚的初始化模块，并提供显式 `initialize()` 供大型服务控制加载时机",
                "Python 模块是否被导入、注册次数、模式名称前缀、重复名称处理、解释器退出清理",
                "没有导入注册模块时应得到空模式列表并给出提示，重复注册冲突应在启动阶段报告",
                "新进程分别测试导入前、导入后、重复导入和多后端同时导入",
                "已注册模式名称、有序优先级和注册来源文件",
            ),
            bt(
                "定义最小 Relax 模型",
                "使用 MatMul 与 ReLU 构成足够小且能观察组合效果的 IRModule",
                "v0.24.0 教程用 TVMScript 定义固定形状 `float32` 模型，数据流块中先计算矩阵乘，再计算 ReLU",
                "为每种组合运算建立一个类似的小模块，并把属性写全，使模式失败时不会被前端默认值干扰",
                "函数参数、返回 StructInfo、数据流块、运算顺序、形状可乘条件和数据类型",
                "输入秩错误、约简维度大小不同或返回信息缺失时应在标准 Relax 检查阶段失败",
                "保存原始 IR，并用 CPU 编译运行得到参考结果和结构快照",
                "TVMScript 源码、打印后的 IR、输入数组和参考输出",
            ),
            bt(
                "取得带优先级的模式列表",
                "确认 `get_patterns_with_prefix` 返回的是 `FusionPattern` 对象列表，并且顺序已经反映注册优先级",
                "官方注册表说明后注册的模式优先级更高，查询结果按从高到低返回",
                "启动时打印模式名称、优先级编号和能力版本，防止不同 Python 模块导入顺序改变结果",
                "前缀是否唯一、融合模式是否位于单算子模式之前、同名模式、可选算子是否存在",
                "模式列表为空、含重复名称或高层组合排在基础模式之后时停止 NPU 分区并说明原因",
                "构造同时匹配 MatMul 与 MatMul+ReLU 的模型，确认组合模式胜出",
                "模式清单、优先级清单、实际匹配名称和注册表版本",
            ),
            bt(
                "执行 FuseOpsByPattern",
                "理解模式命中后为何会出现带 `Composite` 属性的内层函数以及可选的 `Codegen` 外层函数",
                "官方教程传入 `bind_constants=False` 和 `annotate_codegen=True`，使权重保留为参数，并让 RunCodegen 能找到后端名称",
                "把两个标志作为分区配置显式记录，不能依赖某个 TVM 版本的默认值",
                "组合函数参数、自由变量、`Composite` 名称、`Codegen` 名称、`global_symbol`、常量是否绑定",
                "接纳后函数缺少后端属性、捕获未声明变量或外部函数接口不完整时视为编译器错误",
                "对分区前后模块做结构比较，并统计普通节点、组合函数和外部函数数量",
                "分区前后 IR、标志值、模式命中报告和函数属性表",
            ),
            bt(
                "执行 MergeCompositeFunctions",
                "观察同一后端的相邻组合函数何时能够被放入一个外部函数，何时因依赖关系而保持分开",
                "官方教程在模式融合之后调用 `MergeCompositeFunctions()`，源实现会避免形成循环依赖",
                "根据设备执行开销与数据驻留需求决定是否使用更大的外部函数，并限制最大节点数和输入输出数",
                "父组依赖、后端名称、函数输入输出、被其他节点使用的中间值、组大小和外部调用数量",
                "合并会造成循环依赖、跨后端混合或超过设备资源上限时保持原组",
                "构造直线、分叉、汇合和跨后端图，检查最终分组及拓扑顺序",
                "分组编号、组依赖表、拒绝合并原因和外部函数接口",
            ),
            bt(
                "执行 RunCodegen",
                "确认带 `Codegen` 属性的 Relax 函数如何变成 ExternFunc 调用并产生外部运行时模块",
                "官方流程调用 `RunCodegen()`；C++ 实现查询 `relax.ext.example_npu`，调用后端编译器并把结果加入模块属性",
                "自研编译函数接收函数数组、目标选项和常量名称，返回与外部函数对应的 runtime.Module 数组",
                "入口函数集合、后端分组、选项、常量稳定名称、外部符号、返回模块 type key 和 `external_mods`",
                "注册名不存在、编译器返回空模块、外部符号重复或产物版本不符时停止编译",
                "在 RunCodegen 前后打印 IR，检查原调用被 `call_dps_packed` 取代，外部模块数量正确",
                "前后 IR、全局注册查询、编译器输入摘要、产物清单和模块属性",
            ),
            bt(
                "构建 VM 并运行",
                "理解主机 Target、Relax VM 与外部运行时模块如何一起组成可执行对象",
                "官方教程仍以 `llvm` 作为主机 Target，VM 在 CPU 上运行，外部函数由 Example NPU JSON Runtime 提供",
                "真实设备需要明确输入所在设备、常量初始化、提交与等待行为，并在导出后由新进程重新加载",
                "主机 Target、设备对象、输入设备、运行时初始化、函数查找、输出 StructInfo 和同步位置",
                "设备不可用、输入设备不符、函数未导出、常量未初始化或执行错误时返回分层错误信息",
                "先检查 Example NPU 形状，再用真实后端检查数值、重复运行、并发运行和导出加载",
                "可执行文件、导入模块树、运行参数、输出摘要、设备日志和错误报告",
            ),
        ],
    },
    {
        "no": 39,
        "title": "模式注册与优先级设计",
        "summary": "深入说明 FusionPattern 的四个组成部分、模式名称规范、注册时机、优先级、可选算子处理和模式表测试，使支持范围能够被稳定维护。",
        "official": f"[External Library Dispatch 的 Pattern Registration]({BASE_URL}/arch/external_library_dispatch.html) 与 `python/tvm/relax/backend/pattern_registry.py`。",
        "extra": r"""
## 39.0 注册项的准确形态

```python
register_patterns(
    [
        (
            "acme_npu.matmul",
            matmul_pattern,
            {"lhs": lhs, "rhs": rhs, "root": matmul_pattern},
            check_matmul,
        ),
        (
            "acme_npu.matmul_bias_relu",
            fused_pattern,
            annotations,
            check_matmul_bias_relu,
        ),
    ]
)
```

一个注册项可以是 `FusionPattern`，也可以是二到四个元素的元组。工程后端建议总是提供名称、主模式、标注字典和检查函数，使模式结构与硬件能力限制各自有清楚位置。
""",
        "topics": [
            bt(
                "模式名称与后端前缀",
                "建立不会与其他后端冲突且能直接说明组合类型的模式名称",
                "注册表用名称前缀筛选后端，`GetCodegenName` 也会从组合名称中取得后端部分",
                "采用 `acme_npu.<operation_or_fusion>` 形式，并禁止在发布后随意改名",
                "前缀、运算名称、融合次序、版本兼容别名、日志显示名称",
                "缺少前缀、前缀与 Codegen 不同、名称重复或只用序号命名时拒绝注册",
                "查询前缀并断言完整名称集合，检查每个名称能得到唯一 FusionPattern",
                "模式名称清单、所有者、开始支持版本和停止支持版本",
            ),
            bt(
                "主模式与 wildcard",
                "用最小但足够准确的 DFPattern 描述候选子图结构",
                "Example NPU 使用 `wildcard()` 表示输入，用 `is_op` 锁定 Relax 运算，再按调用关系组合",
                "输入位置若有不同角色，应使用不同 wildcard 对象并在标注字典中命名",
                "调用节点、参数数量、可选节点、重复输入、元组输出和交换律",
                "模式过宽会接纳错误结构，模式过窄会遗漏等价前端写法；两者都要通过模型统计发现",
                "为正确结构、少一个节点、多一个节点、交换输入和共享中间值分别编写样本",
                "模式图、匹配样本、未匹配样本和每次变更说明",
            ),
            bt(
                "标注字典",
                "为检查函数提供稳定名称，使其不必重新遍历匹配结果",
                "官方模式常把 `input`、`weight`、中间计算和 `root` 放入 annotations",
                "名称反映角色而不是临时变量名，并确保检查所需表达式全部可直接取得",
                "根节点、数据输入、权重、偏置、激活、缩放参数和关键中间结果",
                "同名覆盖、缺少 root、检查函数访问不存在名称或把两个角色指向同一错误节点时拒绝注册",
                "在检查函数中断言标注键集合和每个表达式类型，对组合变化做回归",
                "标注键表、对应节点类型和使用这些键的检查项",
            ),
            bt(
                "后注册模式优先",
                "利用明确顺序让具体组合先于一般单算子被选择",
                "v0.24.0 注册表说明列表后面的模式优先级更高，查询结果按优先级从高到低返回",
                "把基础单算子放前面，把分组卷积等更具体形式放后面，把融合模式放在最后",
                "模式列表位置、实际查询顺序、相互包含关系和命中统计",
                "无法说明两个重叠模式谁应获胜时，不应仅靠偶然导入顺序决定",
                "为每对重叠模式构造一个同时匹配的模块并断言最终 Composite 名称",
                "优先级表、重叠关系表、预期获胜者和测试名称",
            ),
            bt(
                "可选算子注册",
                "处理某些 TVM 构建或版本中不存在的 Relax 运算，而不使整个模块导入失败",
                "Example NPU 对部分运算先调用 `Op.get`，捕获 TVMError 后不加入模式列表",
                "把可选模式与核心模式分开统计，并在启动报告中说明缺失原因",
                "运算注册名、引入版本、构建选项、是否核心能力和替代写法",
                "核心运算缺失应停止后端初始化；可选运算缺失只降低覆盖并报告",
                "在含有和不含有该运算注册的环境中检查导入行为，或用版本条件测试",
                "核心模式集合、可选模式集合、缺失列表和 TVM 版本",
            ),
            bt(
                "模式注册的生命周期",
                "理解 Python 检查函数被 C++ 全局状态引用时为何需要在解释器退出前清理",
                "pattern_registry.py 通过 atexit 调用 RemovePatterns，避免 Python 结束后仍执行引用计数操作",
                "不要绕过官方注册函数直接保存 Python 回调；嵌入式服务要测试多次初始化与销毁",
                "注册表所有权、清理函数是否安装、多解释器限制、进程派生和模块重新加载",
                "发现清理次序不确定或子解释器共享状态时，应采用独立工作进程隔离编译任务",
                "运行短进程反复导入退出，并在调试构建中检查崩溃和引用泄漏",
                "进程生命周期测试、内存检查结果和已知运行方式限制",
            ),
            bt(
                "注册表的确定性",
                "确保相同源码与配置每次得到相同的模式集合和顺序",
                "官方 API 按前缀返回有序列表，但工程中多个导入模块仍可能改变注册时机",
                "用一个总入口按固定顺序导入所有模式文件，并生成模式清单散列值",
                "Python 模块顺序、环境开关、条件注册、插件版本和模式清单散列值",
                "环境变量未记录、文件系统遍历决定顺序或重复安装多个后端版本时停止编译服务启动",
                "在多个新进程中重复导入并比较模式名称、顺序和清单散列值",
                "导入计划、模式清单、配置来源和复现命令",
            ),
            bt(
                "模式表的版本管理",
                "把模式支持变化当作编译器接口变化，而不是普通内部重构",
                "官方测试会检查核心模式集合并验证若干模型可分区",
                "每次新增、删除或调整模式都记录影响的模型、外部产物格式和所需运行时版本",
                "模式版本、开始支持版本、停止支持版本、对应设备能力和兼容产物",
                "旧运行时无法执行新组合时，编译器必须写入最低运行时版本或禁用该模式",
                "用旧模型集比较外部函数数量、组合名称和输出结果，评估变化是否符合预期",
                "模式版本说明、覆盖差异报告、兼容矩阵和升级指导",
            ),
        ],
    },
    {
        "no": 40,
        "title": "PatternCheckContext 与能力检查",
        "summary": "把模式的结构匹配与硬件接纳条件分开，详细介绍标注表达式、匹配值、使用关系、形状、数据类型、属性、动态尺寸和成本检查。",
        "official": f"[DPL 文档]({BASE_URL}/deep_dive/relax/dpl.html)、[External Library Dispatch]({BASE_URL}/arch/external_library_dispatch.html) 与 `PatternCheckContext` 源码。",
        "extra": r"""
## 40.0 推荐的检查函数骨架

```python
from tvm.relax.backend.utils import has_leaking_intermediate_variables
from tvm.relax.transform import PatternCheckContext


def check_matmul(ctx: PatternCheckContext) -> bool:
    root = ctx.annotated_expr["root"]
    lhs = ctx.annotated_expr["lhs"]
    rhs = ctx.annotated_expr["rhs"]

    if has_leaking_intermediate_variables(ctx):
        return False
    lhs_sinfo = lhs.struct_info
    rhs_sinfo = rhs.struct_info
    if lhs_sinfo.dtype not in {"float16", "int8"}:
        return False
    if rhs_sinfo.dtype != lhs_sinfo.dtype:
        return False
    if lhs_sinfo.ndim < 2 or rhs_sinfo.ndim != 2:
        return False
    return check_target_limits(root, lhs_sinfo, rhs_sinfo)
```

实际项目不要只返回布尔值。可让内部函数先返回带原因码的结果，外层适配为 TVM 要求的布尔值，同时把结果写入本次编译的接纳报告。
""",
        "topics": [
            bt(
                "结构命中不等于硬件可执行",
                "区分 DFPattern 只描述图形结构，而检查函数负责具体数据类型、形状和属性限制",
                "官方文档把 check function 作为 FusionPattern 的第四部分，返回 True 才会接纳候选",
                "让模式尽量表达稳定结构，把芯片型号相关限制放入读取 Target 的检查函数",
                "候选根节点、标注表达式、Target、形状、数据类型、属性和使用关系",
                "任何关键字段未知且后端不支持运行时决定时，应拒绝候选",
                "保持图结构不变，逐个改变数据类型、形状或属性，确认只有允许组合被接纳",
                "结构命中计数、最终接纳计数和各原因码数量",
            ),
            bt(
                "annotated_expr 的读取",
                "正确取得标注字典中的 Relax 表达式，并避免依赖生成的临时变量名",
                "PatternCheckContext 通过标注名称提供匹配表达式，Example NPU 读取 root 检查 groups",
                "封装 `require_expr(ctx, name)`，在开发构建中验证名称存在及节点类型",
                "标注键、表达式类型、StructInfo、Span、Call attrs 和被绑定变量",
                "缺键或类型不同说明模式定义与检查函数已不一致，应作为后端开发错误报告",
                "修改模式结构后运行标注键快照测试，防止检查函数静默读错对象",
                "标注键与表达式摘要、源位置和检查函数版本",
            ),
            bt(
                "中间结果外泄检查",
                "防止组合函数内部值同时被外部节点使用，导致隐藏输出或重复计算",
                "官方 BYOC 实现提供 `tvm.relax.backend.utils.has_leaking_intermediate_variables(context)`，用于检查组合内部值是否被外部使用",
                "除非产物 ABI 明确支持多输出，否则发现外泄中间结果就拒绝该组合，或把它提升为外部函数输出",
                "每个中间变量的使用者、函数返回值、多输出能力、原地写要求和复制成本",
                "中间结果被主机节点读取但没有作为外部函数输出时必须拒绝",
                "构造中间 MatMul 同时送入 ReLU 和另一 Add 的分叉模型，确认不会错误融合",
                "使用者列表、外部函数输出表和拒绝说明",
            ),
            bt(
                "数据类型与累加类型",
                "检查输入、权重、偏置、累加和输出类型的完整组合，而不是只检查第一个输入",
                "官方示例的类型检查是教学占位，真实后端应读取 TensorStructInfo 和算子属性",
                "用能力表列出允许组合，并注明隐式转换、累加宽度和输出类型",
                "每个参数 dtype、out_dtype、累加类型、有符号性、混合精度规则和设备版本",
                "只有部分输入类型被支持、类型组合未列出或需要未插入的转换时拒绝",
                "覆盖每个允许组合及相邻不允许组合，加入极值和舍入测试",
                "类型组合编号、实际类型、所选指令和参考结果",
            ),
            bt(
                "静态形状与符号形状",
                "判断哪些维度必须为编译期常量，哪些符号维度可以带范围进入后端",
                "JSONSerializer 的常用路径要求能够取得具体 ShapeExpr；当前官方真实后端可另行处理部分动态维度",
                "为每个运算写静态要求和允许范围，并在产物中保存动态维度名称、最小值和最大值",
                "秩、各维度大小、符号约束、分块整除、工作区上限和命令数上限",
                "无法证明内存安全、运行时没有形状检查或动态值会改变产物结构时拒绝",
                "同一符号使用最小、常用和最大值运行，并测试超出范围时加载或执行失败",
                "符号约束表、实例化尺寸、工作区计算和范围检查日志",
            ),
            bt(
                "算子属性检查",
                "逐项检查 stride、padding、dilation、groups、布局等属性，不依赖默认构造",
                "Example NPU 对 grouped conv 读取 `conv_call.attrs.groups`，其余检查函数主要是教学占位",
                "使用算子合同生成属性检查，并把缺省值正规化为完整列表",
                "属性类型、列表长度、维度次序、允许集合、组合限制和前端来源",
                "属性缺失、长度错误、值超范围或多个属性组合不被设备支持时拒绝",
                "每条属性规则至少配一个允许值和一个不允许值，组合限制用成对测试",
                "正规化属性、合同版本、检查结果和最终命令字段",
            ),
            bt(
                "内存容量与分块可行性",
                "在接纳候选前证明至少存在一种分块方案满足片上存储、对齐和命令数限制",
                "Example NPU 的内存检查直接返回 True，并在注释中说明真实实现应读取 TensorStructInfo",
                "调用快速可行性分析器，只判断是否存在方案；详细调度留给代码生成阶段",
                "输入输出字节数、双缓冲、权重驻留、暂存区、对齐、并行核心和命令上限",
                "所有候选分块都超出存储或命令上限时拒绝，并给出最小所需容量",
                "对临界容量上下各选一个形状，核对可行性分析与完整内存规划一致",
                "容量公式输入、候选分块、峰值占用和拒绝所需容量",
            ),
            bt(
                "收益与设备切换成本",
                "避免把计算量很小但需要多次复制和提交的候选送入 NPU",
                "官方基本 Pass 以模式和检查函数为主，工程后端可以把简单成本条件放入检查或额外分区阶段",
                "估计主机时间、NPU 时间、复制字节和提交固定开销，并设置可配置阈值",
                "运算次数、输入输出字节、驻留状态、提交次数、并发机会和历史测量值",
                "预计收益低于阈值时保留给主机，但记录为性能原因而非能力缺失",
                "用微基准校准固定开销和带宽，在代表模型上比较打开与关闭成本筛选",
                "估计明细、实际时间、误差比例和最终选择",
            ),
        ],
    },
    {
        "no": 41,
        "title": "FuseOpsByPattern 与组合函数",
        "summary": "从 IR 形态出发解释模式命中、组合函数生成、常量绑定、后端标注、函数命名、元组输出和重复执行稳定性。",
        "official": f"[External Library Dispatch 的 Partitioning]({BASE_URL}/arch/external_library_dispatch.html)、[Operator Fusion]({BASE_URL}/arch/fusion.html) 与 `test_transform_fuse_ops_by_pattern.py`。",
        "extra": r"""
## 41.0 两层函数分别负责什么

```text
外层函数
  Codegen = "acme_npu"
  global_symbol = "fused_..."
  负责成为 RunCodegen 的编译单位

内层函数
  Composite = "acme_npu.matmul_bias_relu"
  负责告诉后端内部是哪一种已识别组合
```

`annotate_codegen=True` 时，Pass 可以直接形成这两层结构。采用其他流程时，也可以先只建立 Composite 函数，再由 `MergeCompositeFunctions` 生成带 Codegen 的外层函数。
""",
        "topics": [
            bt(
                "分区前的规范化",
                "保证同一计算不会因不同前端写法而产生完全不同的模式命中结果",
                "FuseOpsByPattern 在 Relax IR 上工作，输入表达式形态会直接影响 DFPattern 是否匹配",
                "固定在分区前运行的规范化、常量折叠和布局处理，并记录 Pass 顺序",
                "算子注册名、属性默认值、元组拆取、别名写法、常量形式和数据流块",
                "输入 IR 仍含后端不认识的等价写法时先执行正规化，不要无限扩张模式",
                "同一模型的多种前端写法经过前置 Pass 后应得到相同关键子图",
                "前置 Pass 清单、规范化前后 IR 和命中差异",
            ),
            bt(
                "Composite 内层函数",
                "理解内层函数是被识别组合的自包含表示，供代码生成器按名称分派",
                "官方输出会在私有 Relax 函数上写 `Composite` 属性，函数体保留原 Relax 运算",
                "检查函数体只依赖参数和内部绑定，组合名称与代码生成访问器一一对应",
                "函数参数顺序、返回值、内部绑定、Composite 名称、纯函数属性和自由变量",
                "函数捕获外部变量、组合名称没有访问器或返回信息不完整时停止代码生成",
                "对每个 Composite 结构保存期望 IR，并用结构比较验证",
                "组合函数 TVMScript、名称、参数表和代码生成处理器",
            ),
            bt(
                "带 Codegen 属性的外层函数",
                "理解外层函数是一个后端编译单位，可以包含一个或多个 Composite 调用",
                "RunCodegen 扫描带 `Codegen` 属性的 Relax 函数，并以该属性组成 `relax.ext.<backend>` 注册名",
                "外层函数只暴露必要输入输出，写入稳定 global_symbol，并限制函数规模",
                "Codegen、global_symbol、参数、返回值、内部组合数量、后端选项和 Span",
                "后端名称与注册名不一致、符号重复或函数接口超出 ABI 时拒绝",
                "多个外层函数同时存在时检查每个符号、模块数量和调用替换",
                "外部函数目录、符号生成输入和唯一性检查结果",
            ),
            bt(
                "bind_constants 的选择",
                "决定权重是外部函数参数还是在分区时成为函数内部常量",
                "官方 Example NPU 使用 False，由主机持有参数；当前 TensorRT 教程使用 True，把权重用于引擎构建",
                "依据权重更新需求、引擎构建方式、模块体积和共享策略选择，并写入编译配置",
                "常量大小、共享函数、更新频率、预处理布局、缓存键和模块格式",
                "运行时需要更新权重却被固定进产物，或设备要求静态权重却仍作为普通参数时拒绝配置",
                "同一模型分别测试两种模式，检查函数参数、常量清单、导出大小和重复加载",
                "选择理由、常量所有权、产物清单和内存占用",
            ),
            bt(
                "annotate_codegen 的选择",
                "明确是在 FuseOpsByPattern 中直接建立后端外层函数，还是稍后统一分组",
                "官方 Example NPU 教程设置 True，文档也说明设置 False 后可由 MergeCompositeFunctions 添加后端属性",
                "需要跨多个组合做较大分组时可先 False；只需一个组合一个调用时可直接 True",
                "Pass 次序、预期函数层数、是否调用 MergeCompositeFunctions 和最终外部函数数量",
                "RunCodegen 前仍没有 Codegen 属性时不得继续执行",
                "为两种配置保存 IR 样本，确认最终外部调用符合设计",
                "配置值、函数层次图、Pass 输出和外部函数数量",
            ),
            bt(
                "多输出与元组",
                "处理组合运算返回多个张量以及主函数使用其中部分结果的情况",
                "Relax 用 TupleStructInfo 描述多输出，JSONSerializer 会把元组字段展平为多个节点入口",
                "产物 ABI 显式列出每个输出的顺序、形状、数据类型和是否可省略",
                "元组字段数量、TupleGetItem 使用、输出顺序、未使用输出和缓冲区分配",
                "运行时模块不支持多输出或只计算部分字段会改变行为时拒绝组合",
                "构造双输出函数，分别使用全部、只使用第一项和交叉使用，检查分区和运行",
                "返回 StructInfo、输出目录、节点 entry 编号和调用参数",
            ),
            bt(
                "函数命名与稳定性",
                "使自动生成的 global_symbol 在一次编译中唯一，并能关联源模型位置",
                "官方 Pass 会生成包含算子和后端信息的函数名，RunCodegen 通过 GetExtSymbol 读取外部符号",
                "对外产物使用确定性符号，必要时追加结构散列短值，避免依赖对象地址",
                "入口函数、模式名称、出现序号、结构散列、字符限制和符号表限制",
                "重复符号、超长名称、非法字符或同结构不同合同共用符号时停止编译",
                "相同模块多次编译比较符号列表，不同模块并入同一包时检查冲突",
                "符号生成规则、输入字段、最终符号表和冲突检查",
            ),
            bt(
                "重复运行 Pass 的稳定性",
                "确认分区 Pass 被意外执行两次时不会继续套入函数或改变已有外部函数",
                "TVM 变换通常在已规范化输入上使用，项目流程仍应明确哪些 Pass 允许重复执行",
                "为分区入口加入状态检查或通过结构测试证明第二次执行没有额外变化",
                "已有 Composite、已有 Codegen、函数数量、属性、模式命中和 Pass 配置",
                "第二次执行增加函数层次、改变符号或重新绑定常量时视为流程错误",
                "对一次和两次执行结果做结构比较，并测试先运行其他后端分区的情况",
                "Pass 次序、结构散列和重复执行差异",
            ),
        ],
    },
    {
        "no": 42,
        "title": "MergeCompositeFunctions 与外部函数分组",
        "summary": "解释组合函数的依赖分组、避免循环、后端一致性、分叉汇合、多入口、分组大小控制和设备驻留收益。",
        "official": "`src/relax/transform/merge_composite_functions.cc`、对应 Relax 变换测试与 External Library Dispatch 文档。",
        "extra": r"""
## 42.0 为什么“相邻且同后端”仍可能不能合并

设左侧 NPU 组的结果同时送入一个主机组和下方 NPU 组，而主机组的结果也送入下方 NPU 组。如果下方 NPU 组合并进左侧组，就会让一个组既依赖主机组，又被主机组依赖，形成循环。源码会传播直接和间接依赖，只有不会产生循环时才合并。

> [!note] 分组与运算融合不是同一件事
> Composite 表示已识别的运算组合；外层 Codegen 函数表示一次交给外部编译器的子图。一个外层函数可以含多个 Composite，外部编译器仍可在内部决定是否进一步融合。
""",
        "topics": [
            bt(
                "父组与当前组",
                "理解当前组合调用可以尝试并入哪些输入来源组",
                "源码为表达式分配 Group，遇到 Composite 调用时检查同后端父组",
                "在调试报告中打印每个表达式的组编号、根组和后端名称",
                "调用参数来源、父组根节点、Codegen 名称、节点数量和返回值",
                "参数不是 Composite 结果或父组属于其他后端时新建组",
                "直线形图验证所有同后端组合可按预期进入一个组",
                "表达式到组的对应表、父组候选和合并结果",
            ),
            bt(
                "直接与间接依赖",
                "保证分组不会改变原图执行先后关系或形成循环",
                "源码维护 group_deps，并传播参数组的间接依赖",
                "若自研分组器增加成本规则，仍必须保留完整依赖传播",
                "组依赖集合、传递依赖、拓扑顺序、跨组值和控制流位置",
                "候选父组出现在其他父组依赖集合中时不得合并",
                "使用菱形、交叉依赖和三层依赖图验证无环",
                "依赖表、拓扑检查结果和未合并原因",
            ),
            bt(
                "同后端限制",
                "防止不同外部编译器的组合进入同一个外部函数",
                "GetCodegenName 从 Composite 名称取得后端，MergeGroup 会检查两组后端相同",
                "后端前缀必须稳定；共享硬件的两个编译器也应通过明确的上层编排合作",
                "Composite 名称、后端前缀、目标选项、产物格式和运行时 type key",
                "后端名称不同或运行时 ABI 不兼容时始终保持分开",
                "交替放置两个后端的组合，检查外部函数没有混合",
                "每组后端、组合名称列表和运行时要求",
            ),
            bt(
                "分叉图",
                "处理一个 NPU 结果被多个后继节点读取时的分组和输出设计",
                "源码依据每个参数组及其依赖判断可合并集合，不会简单按文本相邻合并",
                "评估把共享值作为外部函数内部值还是公开输出，结合后继后端与复制成本决定",
                "共享值使用者、输出数量、驻留设备、主机读取、生命周期和复制次数",
                "隐藏仍被组外使用的值或复制成本超过收益时不进行大组整合",
                "构造一对多图，检查输出接口、结果一致性和数据复制记录",
                "使用者列表、分组图、外部输出表和复制字节",
            ),
            bt(
                "汇合图",
                "处理多个父组结果共同进入一个后继组合的情况",
                "MergeCompositeFunctions 会收集可合并父组，并检查父组之间的依赖",
                "允许无相互依赖的同后端父组与当前组整合，但控制外部输入数",
                "父组数量、相互依赖、输入参数、峰值内存、并行执行和组内调度",
                "任何父组依赖另一个候选父组且整合会成环时保留独立组",
                "使用两路并行计算后相加的模型，比较整合前后函数接口和结果",
                "父组集合、依赖集合、合并顺序和峰值占用",
            ),
            bt(
                "分组大小限制",
                "避免合法但过大的外部函数超过编译时间、内存或固件命令上限",
                "官方 Pass 主要依据依赖和后端名称，项目可在之后增加拆分步骤或让后端编译器拒绝",
                "设置最大 Composite 数、输入输出数、估计命令数和峰值工作区",
                "组节点数、估计命令、常量字节、工作区、编译时间和设备上限",
                "超过任一硬限制时按依赖安全位置拆分，不能任意截断",
                "逐步增加重复层，确认达到阈值后分组数量按预期变化",
                "阈值配置、拆分位置、拆分原因和资源估计",
            ),
            bt(
                "多入口函数",
                "确保模块包含多个公开函数时只处理可到达的外部组合并保持符号唯一",
                "RunCodegen 支持入口函数名称数组，并会补充外部可见且不属于特定后端的 Relax 函数",
                "编译服务显式传入发布入口，内部调试函数不应进入最终包",
                "入口列表、函数可见性、调用图、共享外部函数、符号和常量",
                "入口不存在、私有函数被错误发布或同一外部函数重复编译时报告",
                "包含两个入口和一个共享内部函数，检查最终模块与导出符号",
                "入口清单、可达函数、被删除函数和导出目录",
            ),
            bt(
                "分组结果的收益复核",
                "在正确分组后再确认较大外部函数确实减少复制和提交",
                "官方机制负责功能正确的外部函数组织，不承诺每次合并都带来目标设备性能提升",
                "用成本报告比较整合前后提交数、复制字节、设备驻留和峰值内存",
                "外部调用数量、输入输出字节、工作区、设备执行时间和主机等待",
                "整合造成峰值内存显著增加或阻止并行时，可依据明确策略重新拆分",
                "同一模型生成两种分组配置，在设备上测量并检查结果一致",
                "配置、估计值、实测值和选择理由",
            ),
        ],
    },
    {
        "no": 43,
        "title": "RunCodegen 源码解析",
        "summary": "逐步分析入口函数发现、ExternFunc 替换、常量命名、按后端归组、FFI 查询、目标选项、external_mods 与无用代码删除。",
        "official": f"`src/relax/transform/run_codegen.cc` 与 [External Library Dispatch 的 Code Generation]({BASE_URL}/arch/external_library_dispatch.html)。",
        "extra": r"""
## 43.0 RunCodegen 的关键注册约定

```text
Relax 函数属性: Codegen = "acme_npu"
          ↓
FFI 查询名称: relax.ext.acme_npu
          ↓
编译器输入: functions, options, constant_names
          ↓
编译器输出: Array<runtime.Module>
          ↓
IRModule 属性: external_mods
```

函数调用会被改写为 `relax.call_dps_packed(ExternFunc(symbol), args)`。原外部函数去除 `global_symbol` 与 `Codegen` 后可由无用代码删除清理。常量会按外部符号、后端名称和出现序号生成稳定名称，并通过模块属性提供给需要在初始化阶段取得常量的后端。
""",
        "topics": [
            bt(
                "入口函数发现",
                "弄清 RunCodegen 只改写哪些可到达函数，以及 entry_functions 参数的作用",
                "源码先加入用户指定入口，再按名称确定顺序加入外部可见且不带 Codegen 的 Relax 函数",
                "发布工具显式给出入口清单，禁止依赖未记录的函数可见性",
                "入口名称、linkage、函数类型、Codegen 属性、名称排序和可达调用",
                "用户指定入口不存在或入口不是 Relax 函数时在 Pass 开始前报告",
                "改变函数插入顺序但保持名称相同时，检查编译结果顺序稳定",
                "入口清单、发现来源、遍历顺序和最终保留函数",
            ),
            bt(
                "ExternFunc 替换",
                "理解外部 Relax 函数调用为何变成按符号查找的运行时函数",
                "VisitExpr 遇到带 Codegen 的函数时返回 ExternFunc，调用处建立 `call_dps_packed` 并保留返回 StructInfo",
                "确保外部符号与 runtime.Module 的可调用函数完全一致，并在加载时检查",
                "GlobalVar、外部符号、调用参数元组、返回 StructInfo、Span 和函数查找",
                "运行时模块没有同名函数或返回缓冲区约定不一致时停止加载",
                "在变换前后定位同一调用，检查参数顺序与返回信息不变",
                "调用改写表、符号目录、参数 ABI 和结构比较结果",
            ),
            bt(
                "外部函数缓存",
                "理解同一 GlobalVar 被多次调用时为何只需建立一个 ExternFunc 对象",
                "源码用 `extern_funcs_` 保存 GlobalVarNode 到 ExternFunc 的结果",
                "后端产物也应按外部符号去重，但不得把不同函数仅因形状相同而合并",
                "GlobalVar 身份、外部符号、调用次数、产物模块和常量集合",
                "同一符号对应不同函数内容或不同目标选项时报告冲突",
                "一个外部函数在主函数中调用两次，检查模块数量与调用次数",
                "符号到函数结构散列、调用位置和产物编号",
            ),
            bt(
                "常量稳定命名",
                "理解 RunCodegen 如何为外部函数内部常量生成名称并传给后端",
                "源码按外部符号、Codegen 名称和遍历序号组成常量名，并保存 Constant 到名称的表",
                "将内容散列值加入自研缓存键，不能只依赖遍历序号判断权重是否相同",
                "外部符号、后端名、出现序号、常量 dtype、形状、字节数和内容散列",
                "名称重复或同名常量内容不同必须停止编译",
                "调整无关函数顺序后确认单个外部函数内部名称可预测，改变权重后缓存失效",
                "常量名称表、内容散列、使用节点和产物位置",
            ),
            bt(
                "按后端归组",
                "确认多个 Codegen 名称同时存在时，RunCodegen 会分别调用相应编译器",
                "InvokeCodegen 遍历非 PrimFunc 函数，收集带 Codegen 的 Function，并按 target 名称放入数组",
                "自研 NPU 与其他后端共存时，为每个后端分别配置选项并检查外部模块列表",
                "后端名称、函数数组顺序、每组选项、返回模块数量和组合顺序",
                "某个后端注册缺失只影响含该后端的编译，但整份 IRModule 不能留下半成品",
                "构造两个外部后端和普通 TVM 节点混合模块，检查每个注册函数调用次数",
                "按后端的函数清单、选项、调用日志和模块 type key",
            ),
            bt(
                "target_options",
                "通过 RunCodegen 参数向每个外部编译器传递结构化配置",
                "Pass 接收后端名称到 OptionMap 的二层表，找不到后端项时使用空表",
                "对选项建立 schema、缺省值和版本，固定硬件限制仍来自 Target 能力文件",
                "选项名称、类型、缺省值、允许范围、后端名称和影响的产物字段",
                "未知选项、错误类型或与硬件限制冲突时在调用编译器前报告",
                "分别测试缺省、显式值、未知值和越界值，并确认产物清单记录有效选项",
                "原始选项、正规化选项、schema 版本和产物配置摘要",
            ),
            bt(
                "external_mods 属性",
                "理解外部编译器返回的模块如何附着到 IRModule 并进入最终可执行文件",
                "源码若已有 external_mods，会把旧模块放在新模块之前，再写回模块属性",
                "确保每个模块可序列化、type key 唯一可加载，并记录模块依赖关系",
                "模块数组顺序、type key、外部符号、导入模块、序列化函数和加载注册",
                "模块不能保存、缺少加载函数或符号冲突时禁止导出",
                "连续运行两个外部代码生成 Pass，检查旧模块未丢失并可导出加载",
                "模块树、数组顺序、type key、导出文件和加载测试",
            ),
            bt(
                "常量属性与无用代码删除",
                "理解常量表如何供运行时初始化，以及被替换的 Relax 函数何时移除",
                "源码把名称到 Tensor 的表写入 `kConstNameToConstant`，最后调用 DeadCodeElimination",
                "运行时初始化读取所需常量后核对数量和名称，清理函数不能删除仍被入口引用的内容",
                "常量名称、Tensor、入口函数、引用关系、被删除函数和 Pass 顺序",
                "同名常量多于一个、所需常量缺失或删除后存在悬空调用时停止编译",
                "检查 RunCodegen 后函数集合、常量属性和加载时 Init 参数",
                "删除前后函数清单、常量表和引用检查结果",
            ),
        ],
    },
]


byoc_deep_chapters.extend(
    [
        {
            "no": 44,
            "title": "JSONSerializer 与编译产物",
            "summary": "结合 ExampleNPUJSONSerializer 说明 Relax 函数如何转换为 JSON 图，详细讨论节点、入口、输出、属性、常量、形状、数据类型以及从教学格式升级为真实 NPU 产物的方法。",
            "official": "`src/relax/backend/contrib/codegen_json/codegen_json.h`、`src/relax/backend/contrib/example_npu/codegen.cc` 与 JSON Runtime 源码。",
            "extra": r"""
## 44.0 Example NPU 编译器做了什么

```cpp
ffi::Array<ffi::Module> ExampleNPUCompiler(
    ffi::Array<Function> functions,
    ffi::Map<ffi::String, ffi::Any> options,
    ffi::Map<Constant, ffi::String> constant_names) {
  ffi::Array<ffi::Module> compiled_functions;
  const auto create = tvm::ffi::Function::GetGlobalRequired(
      "runtime.ExampleNPUJSONRuntimeCreate");

  for (const auto& func : functions) {
    ExampleNPUJSONSerializer serializer(
        constant_names, AnalyzeVar2Value(func));
    serializer.serialize(func);
    auto graph_json = serializer.GetJSON();
    auto const_names = serializer.GetConstantNames();
    auto func_name = GetExtSymbol(func);
    compiled_functions.push_back(
        create(func_name, graph_json, const_names).cast<ffi::Module>());
  }
  return compiled_functions;
}
```

Example NPU 不会在这里生成真实机器命令。它把组合函数写成 JSON，再立即创建一个 JSON Runtime Module。真实后端可以保留这套组织方式，也可以把 JSON 换成设备编译器产生的二进制，只要返回值仍是可导出、可加载并能提供外部符号的 `runtime.Module`。
""",
            "topics": [
                bt(
                    "AnalyzeVar2Value 与局部函数",
                    "理解代码生成器为何需要从变量找到其绑定的组合函数",
                    "ExampleNPUJSONSerializer 构造时接收 `AnalyzeVar2Value(func)` 的结果，VisitExpr_ 由 Call 的 Var 取得 Function",
                    "在外部函数进入代码生成前检查所有局部函数调用都有绑定，禁止依赖模块外未传入定义",
                    "调用 op 类型、Var、绑定表达式、Function、Composite 属性和作用域",
                    "callee 不是 Var、找不到绑定或绑定不是 Function 时作为后端输入不合法报告",
                    "测试一个、多个和嵌套局部函数，并为缺失绑定构造开发期异常样本",
                    "变量绑定表、函数属性、调用位置和失败节点",
                ),
                bt(
                    "Composite 访问器",
                    "把不同 Composite 名称转换为后端节点或设备编译器操作",
                    "Example NPU 读取局部函数的 Composite 属性，直接把名称作为 JSON kernel 节点的 op_name",
                    "真实后端建立显式访问器表，为每个组合解析属性、验证输入并生成内部操作",
                    "Composite 名称、处理函数、输入角色、输出数量、属性和最低设备版本",
                    "没有处理函数、名称版本过新或输出数量不一致时停止代码生成",
                    "逐个遍历已注册模式，确认每个可接纳 Composite 都有代码生成处理器",
                    "模式到处理器对应表、处理器版本和产物节点摘要",
                ),
                bt(
                    "JSON 节点与 NodeEntries",
                    "理解一个 Relax 表达式如何产生一个或多个 JSON 图入口",
                    "JSONSerializer 用 JSONGraphNodeEntry 保存节点编号与输出编号，元组结果会展平为多个入口",
                    "内部图也采用稳定值编号，禁止使用原始指针或主机地址作为跨进程标识",
                    "node id、output index、输入入口、输出数量、节点类型和拓扑顺序",
                    "引用不存在节点、输出编号超范围或出现非拓扑顺序依赖时拒绝产物",
                    "解析生成 JSON，逐项检查入口编号和输出编号，并对多输出运算测试",
                    "节点表、入口表、输出表和拓扑检查结果",
                ),
                bt(
                    "形状与数据类型写入",
                    "保证运行时能够为输出分配正确缓冲区并检查输入",
                    "AddNode 从 StructInfo 取得 TensorStructInfo；常用路径要求 shape 已定义，并写入 shape 与 dtype 属性",
                    "除公开逻辑形状外，真实产物还记录设备布局、存储字节数、对齐和动态范围",
                    "逻辑形状、设备形状、dtype、打包位宽、byte_offset、步长和输出数量",
                    "ShapeExpr 无法转为后端支持形式、dtype 未定义或字节数计算溢出时停止编译",
                    "用独立解析器复算每个输出字节数，覆盖标量、空尺寸、多输出和符号尺寸",
                    "StructInfo 摘要、序列化字段、复算结果和内存需求",
                ),
                bt(
                    "算子属性提取",
                    "把卷积、池化、转置等属性准确写入后端表示",
                    "OpAttrExtractor 通过 FFI 反射读取整数、浮点、布尔、字符串、数据类型和数组字段",
                    "只导出合同允许的字段，并在导出前把默认值补全为统一形式",
                    "字段名称、原始类型、序列化类型、列表元素类型、空值和缺省行为",
                    "不支持的字段类型、混合数组无法安全表示或未知属性会影响结果时停止代码生成",
                    "每种属性类型构造一个测试，JSON 往返后与正规化属性比较",
                    "属性表、类型表、JSON 片段和往返差异",
                ),
                bt(
                    "常量节点",
                    "区分普通输入节点与由 RunCodegen 命名的常量节点",
                    "JSONSerializer 使用 constant_names 查找 Constant，并记录实际使用的常量名称",
                    "产物只引用需要的权重，权重内容放在模块、独立权重包或初始化参数中",
                    "常量名称、使用节点、dtype、形状、内容散列、设备布局和存储位置",
                    "常量没有稳定名称、名称重复、内容缺失或预处理版本不符时停止模块创建",
                    "含未使用权重、共享权重和同形不同值权重的模型分别测试",
                    "常量目录、引用计数、内容散列和加载来源",
                ),
                bt(
                    "JSON 格式的限制",
                    "认识教学 JSON 图在安全、体积、解析速度和版本管理方面的不足",
                    "官方 JSONRuntimeBase 适合库调用型后端和教学，但不自动提供真实 NPU 命令格式所需的全部字段",
                    "为 JSON 增加 schema_version、长度限制、未知字段策略和严格解析器，稳定后可转为紧凑二进制",
                    "格式版本、最大节点数、字符串长度、整数范围、可选字段、校验值和端序",
                    "超大长度、重复键、未知必需字段、整数溢出或截断输入必须安全失败",
                    "使用损坏、截断、超大和未知版本文件测试加载器，不只测试正常产物",
                    "格式说明、schema、解析错误、模糊测试结果和迁移工具",
                ),
                bt(
                    "真实 NPU 产物包",
                    "从单一 JSON 升级为包含命令、常量、重定位、函数目录和版本信息的部署包",
                    "BYOC 只要求编译器返回 runtime.Module，并不限制模块内部使用 JSON、源码还是二进制",
                    "设计带文件头和分段目录的容器，元数据可读，命令与权重按对齐存放",
                    "magic、格式版本、函数、命令段、常量段、重定位、工作区、Target 和最低运行时版本",
                    "任何分段越界、重叠、校验失败或版本不兼容都应在设备资源申请前拒绝",
                    "独立打包器与解析器做往返测试，并在新进程及只运行环境加载",
                    "产物清单、分段表、散列值、加载报告和兼容表",
                ),
            ],
        },
        {
            "no": 45,
            "title": "外部运行时模块与调用约定",
            "summary": "详细说明 runtime.Module 的构造、type key、Init、Run、PackedFunc 查询、目标传递式输出调用、Tensor ABI、异步事件、序列化和资源生命周期。",
            "official": f"[TVM Runtime System]({BASE_URL}/arch/runtime.html)、[Module Serialization]({BASE_URL}/arch/introduction_to_module_serialization.html) 与 `example_npu_runtime.cc`。",
            "extra": r"""
## 45.0 从教学 Runtime 到设备 Runtime

```text
runtime.ExampleNPUJSONRuntimeCreate
             ↓
ExampleNPURuntime(symbol, graph_json, const_names)
             ↓
Init(constants)      解析常量并准备状态
             ↓
Run()                教学版本只记录选择
             ↓
真实版本              绑定张量、提交设备、等待或返回事件
```

`kind()` 返回的字符串会成为模块 type key 的一部分。保存模块后，加载器通过 `ffi.Module.load_from_bytes.<type_key>` 找到反序列化函数。创建注册名、type key、加载注册名和 CMake 开关必须成套维护。
""",
            "topics": [
                bt(
                    "运行时模块创建函数",
                    "用 FFI 构造包含外部符号、产物内容和常量名称的 runtime.Module",
                    "Example NPU 注册 `runtime.ExampleNPUJSONRuntimeCreate`，代码生成器通过 GetGlobalRequired 调用",
                    "创建函数只解析并验证主机数据，不应在无法清理的状态下提前占用设备资源",
                    "符号、产物字节、常量名称、Target 要求、type key 和错误返回",
                    "参数类型错误、符号为空、产物格式无效或版本不兼容时不创建模块",
                    "直接通过全局函数创建最小模块，检查 type key、保存和重新加载",
                    "创建参数摘要、验证报告、模块 type key 和加载测试",
                ),
                bt(
                    "kind 与加载注册",
                    "理解自定义模块如何在导出文件中保存并在新进程恢复",
                    "ExampleNPURuntime 的 kind 为 `example_npu_json`，并注册 `ffi.Module.load_from_bytes.example_npu_json`",
                    "选择带厂商与格式的稳定 type key，加载器先验证文件再构造运行时对象",
                    "type key、序列化版本、加载注册名、共享库依赖和模块树",
                    "type key 重复、加载函数未链接或格式版本不受支持时明确失败",
                    "编译进程导出，干净运行进程加载，验证不依赖编译器组件",
                    "导出文件、模块树、注册查询和运行进程依赖清单",
                ),
                bt(
                    "Init 与常量准备",
                    "在第一次运行前按名称取得常量并完成设备侧预处理或上传",
                    "JSONRuntimeBase 提供常量索引，Example NPU Init 检查数量后调用 SetupConstants",
                    "按名称而非偶然顺序绑定权重，并缓存设备句柄与上传完成事件",
                    "常量名称、数量、Tensor 设备、形状、dtype、布局、内容散列和所有权",
                    "数量不同、名称缺失、设备不兼容或上传失败时释放已申请资源并返回错误",
                    "测试零常量、多个常量、共享常量、错误顺序和中途上传失败",
                    "常量绑定表、设备地址类别、上传事件和资源清理结果",
                ),
                bt(
                    "call_dps_packed 调用",
                    "理解目标传递式调用由输入参数和预先分配的输出共同组成",
                    "RunCodegen 以 `relax.call_dps_packed` 包装 ExternFunc，VM 通过 PackedFunc 调用外部模块函数",
                    "运行时解析参数数量，区分输入输出，核对 Tensor 元数据后再提交设备",
                    "函数符号、参数总数、输入数、输出数、Tensor、设备、返回 StructInfo 和同步行为",
                    "参数数量、顺序、类型或设备不符时在任何设备写入发生前失败",
                    "对单输出、多输出、零维张量和错误参数分别调用外部函数",
                    "ABI 表、实际参数摘要、函数查找结果和提交编号",
                ),
                bt(
                    "Tensor ABI 检查",
                    "安全读取 TVM Tensor 的数据指针、形状、数据类型、设备和可选步长",
                    "TVM 运行时以 DLPack 兼容结构表示 Tensor，外部模块通过统一函数接口接收",
                    "将 host、设备和统一内存分别处理，byte_offset 必须计入有效地址",
                    "device_type、device_id、ndim、shape、dtype、strides、byte_offset、对齐和可写性",
                    "负尺寸、字节数溢出、地址未对齐、输出只读或设备类型错误时拒绝",
                    "构造连续、带步长、非零 byte_offset 和不同设备的 Tensor 测试",
                    "Tensor 元数据、计算出的字节范围、转换方式和错误字段",
                ),
                bt(
                    "Run 与设备提交",
                    "把 JSON 节点或二进制命令转换为驱动可接受的设备任务",
                    "Example NPU Run 遍历 kernel 节点，选择执行单元并记录日志，但实际执行函数只有说明作用",
                    "真实运行时应完成重定位、缓冲区绑定、缓存维护、命令提交和设备错误读取",
                    "外部函数、提交编号、命令范围、输入输出地址类别、等待事件、完成事件和设备状态",
                    "重定位失败、地址范围错误、设备不可用或命令检查失败时不得敲门铃",
                    "使用模拟器、驱动空实现和真机逐级验证同一命令产物",
                    "重定位表、提交记录、设备返回码和命令反汇编",
                ),
                bt(
                    "同步与异步",
                    "明确外部函数何时保证输出可读，以及怎样与 VM 或应用事件协调",
                    "教学运行时采用同步外观；TVM 设备接口和外部运行时可以在内部使用流与事件",
                    "第一版可在外部函数返回前等待，稳定后再增加显式事件与跨调用依赖",
                    "提交时间、完成事件、输入输出生命周期、设备流、主机等待和错误传播",
                    "输出尚未完成却提前返回，或输入在设备读取前被释放时属于严重错误",
                    "延迟完成并立即读取输出，验证同步保证；异步版本测试事件等待和并发",
                    "时间线、事件编号、等待点、缓冲区生命周期和错误状态",
                ),
                bt(
                    "资源生命周期与线程安全",
                    "确保模块销毁、执行失败、多线程和设备复位时资源都能正确处理",
                    "runtime.Module 使用对象引用计数管理主机对象，但设备资源仍由后端析构与错误路径负责",
                    "把不可变产物与每次调用状态分开；队列、工作区和事件按设备及线程管理",
                    "模块引用、设备句柄、队列、常量内存、工作区、事件、锁和复位代数",
                    "析构仍有任务运行、失败后状态不明或设备复位后继续使用旧地址时停止后续调用",
                    "并发调用、重复销毁、构造中途失败、超时和设备复位均进行压力测试",
                    "资源计数、线程标识、复位代数、清理日志和泄漏检查",
                ),
            ],
        },
        {
            "no": 46,
            "title": "常量 动态形状 与缓存",
            "summary": "集中处理最容易在真实后端中出错的三类问题：权重所有权与预处理、符号尺寸的允许范围、编译结果缓存键与版本失效。",
            "official": f"`RunCodegen` 常量处理、当前 [BYOC 教程]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html) 中 Example NPU 与 TensorRT 的不同选择，以及 TensorRT 后端源码。",
            "extra": r"""
## 46.0 推荐的缓存键组成

```yaml
cache_key:
  relax_function_structural_hash:
  constant_content_hashes:
  target_capability_hash:
  backend_compiler_version:
  tvm_commit:
  normalized_options:
  dynamic_shape_profile:
  artifact_schema_version:
```

只用模型文件名或函数名不能安全复用产物。权重内容、目标型号、编译选项、动态尺寸范围和格式版本中的任何一项变化，都可能要求重新编译。
""",
            "topics": [
                bt(
                    "常量作为参数",
                    "让主机在每次调用时提供权重，适合可更新参数和教学后端",
                    "Example NPU 教程设置 `bind_constants=False`，权重保留在外部函数参数中",
                    "运行时核对权重 Tensor，并按内容散列选择是否复用设备副本",
                    "参数顺序、常量角色、更新频率、设备副本、内容散列和调用并发",
                    "后端编译需要看到权重内容却仍把它当未知参数时拒绝该配置",
                    "同一函数连续传入相同与不同权重，确认设备缓存更新正确",
                    "参数 ABI、权重散列、上传次数和副本生命周期",
                ),
                bt(
                    "常量固定进产物",
                    "在编译时读取权重并生成设备引擎或预处理格式",
                    "当前官方 TensorRT 教程采用 `bind_constants=True`，因为权重会进入构建出的引擎",
                    "记录源权重与转换后权重散列，并在模块中写明不可运行时更新",
                    "源常量、预处理布局、转换版本、目标型号、产物段和共享策略",
                    "权重需要在线更新、产物体积超限或许可证不允许嵌入时不使用此方式",
                    "导出后不提供源框架与源权重仍能加载运行，并验证改变权重会重新编译",
                    "源与目标散列、转换报告、产物大小和重建记录",
                ),
                bt(
                    "跨函数共享权重",
                    "避免多个外部函数重复占用同一份大权重设备内存",
                    "RunCodegen 为每个 Constant 提供稳定名称，但具体共享由后端模块与运行时设计决定",
                    "建立模型级常量池，函数产物只保存常量编号，运行时引用计数管理副本",
                    "常量身份、内容散列、使用函数、设备布局、设备地址类别和引用计数",
                    "同形不同值不得共享，不同布局版本也不得共享同一设备副本",
                    "两个函数共享同一对象、复制的相同内容和同形不同内容分别测试",
                    "常量池目录、使用者、上传记录、引用计数和释放记录",
                ),
                bt(
                    "动态尺寸范围",
                    "用带上下限的符号维度支持批次大小或序列长度变化",
                    "当前在线 BYOC 教程说明 TensorRT 构建器可为动态前导批次维度建立优化配置",
                    "在分区、产物与运行时三处使用同一范围定义，运行时检查实际尺寸",
                    "符号名、最小值、常用值、最大值、维度编号、工作区公式和引擎配置",
                    "实际尺寸超出范围或符号关系不满足时在提交前拒绝",
                    "对最小、常用、最大、下溢和上溢尺寸分别构建或运行",
                    "动态配置、实际尺寸、所选产物版本和范围检查结果",
                ),
                bt(
                    "动态尺寸与分区",
                    "避免模式检查用示例尺寸接纳一个在其他允许尺寸下无法执行的子图",
                    "PatternCheckContext 可以读取 StructInfo，但教学 Example NPU 的检查主要返回 True",
                    "检查整个允许范围的最坏资源需求，或把候选限制为多个静态规格",
                    "符号约束、最坏存储、最大命令数、分块可行性和运行时选择",
                    "只能在部分未说明尺寸下执行且没有多版本分派时拒绝",
                    "生成范围内随机尺寸并与静态逐尺寸编译结果比较",
                    "范围证明、资源上限、多版本表和随机测试种子",
                ),
                bt(
                    "动态工作区",
                    "根据运行时尺寸安全计算外部函数工作区，防止不足或整数溢出",
                    "Relax 返回 StructInfo 保留形状信息，外部运行时仍需依据产物规则分配设备空间",
                    "把工作区公式编译成受检查表达式或分段上限，并以宽整数计算",
                    "尺寸输入、乘加公式、对齐、上限、内存类别、复用和并发调用",
                    "公式溢出、结果超过设备上限或尺寸关系未验证时拒绝运行",
                    "对各项为 0、1、最大值和会造成溢出的恶意输入测试",
                    "公式版本、输入尺寸、未对齐大小、对齐后大小和申请结果",
                ),
                bt(
                    "缓存命中与失效",
                    "只在所有影响产物行为的输入一致时复用编译结果",
                    "官方 TensorRT 教程提示可用 `TVM_TENSORRT_CACHE_DIR` 避免重复构建引擎",
                    "自研缓存键包含 IR、常量、Target、后端版本、TVM 提交、选项和动态配置",
                    "结构散列、内容散列、能力文件散列、编译器版本、选项和 schema 版本",
                    "任一字段缺失或缓存元数据无法验证时重新编译，不猜测兼容",
                    "逐个改变键字段，确认只有完全一致时命中，并测试损坏缓存自动隔离",
                    "缓存键、命中原因、失效字段、产物散列和重建时间",
                ),
                bt(
                    "缓存并发与安全",
                    "处理多个编译进程同时请求同一产物以及不可信缓存文件",
                    "TVM 不限定厂商缓存实现，后端需要自行保证写入原子性和加载安全",
                    "先写临时文件、完成校验后原子改名；读取时限制大小并验证所有分段",
                    "锁文件、临时文件、最终路径、文件权限、内容散列、最大大小和租户标识",
                    "部分写入、权限错误、来源不可信、路径穿越或内容校验失败时隔离文件",
                    "启动多个进程同时编译同一模型，并注入截断、替换和权限错误",
                    "锁等待、写入者、校验结果、隔离路径和最终唯一产物",
                ),
            ],
        },
        {
            "no": 47,
            "title": "从 Example NPU 改造成真实后端",
            "summary": "给出从官方教学空壳到可部署自研 NPU 的逐项替换计划，说明哪些代码可以保留、哪些只是演示、哪些必须由硬件团队提供正式定义。",
            "official": f"[官方 BYOC 教程的 Next steps]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html)、Example NPU 三个实现文件与 CMake 模块。",
            "extra": r"""
## 47.0 保留、替换与新增

| 部分 | 可以保留 | 必须替换或补充 |
| --- | --- | --- |
| 模式注册框架 | 前缀查询、FusionPattern 组织 | 能力检查、模式集合、版本 |
| 图分区 | FuseOpsByPattern、MergeCompositeFunctions | 成本选择、报告、模型策略 |
| C++ 注册形式 | `relax.ext.<backend>` | 真实编译器调用和产物 |
| JSON Runtime 基类 | 序列化框架可作起点 | 驱动、内存、设备执行、数值 |
| CMake | 编译器与运行时分开开关 | SDK 搜索、版本检查、部署依赖 |
| 测试 | 模式和形状测试结构 | 数值、错误、导出、真机和性能 |

> [!important] 不要把教学日志当成设备实现
> Example NPU 中的存储容量、执行单元宽度和分块数值只是说明用途。真实后端必须从受版本控制的 Target 能力文件取得硬件参数。
""",
            "topics": [
                bt(
                    "复制目录还是从最小文件开始",
                    "选择可维护的后端起点，避免把大量教学占位代码当成产品代码",
                    "官方建议以 Example NPU 为起点，扩展 patterns.py、C++ codegen、runtime 和 CMake",
                    "保留注册和构建骨架，重新编写能力检查、产物结构和设备执行部分",
                    "文件清单、许可证头、命名空间、注册名、CMake 开关和测试目录",
                    "无法说明某段教学代码在真实设备中的作用时先删除，不应原样保留",
                    "最小构建只注册一个 MatMul 模式和一个空运行时，再逐步增加",
                    "保留代码清单、替换清单、负责人和完成状态",
                ),
                bt(
                    "替换占位检查函数",
                    "把始终返回 True 的内存和数值类型检查改为读取 StructInfo 与 Target",
                    "Example NPU 源码注释明确说明这些函数是 placeholder",
                    "从算子合同生成检查项，并为每条失败原因提供稳定编号",
                    "dtype、形状、属性、布局、片上存储、指令版本和收益",
                    "任何未正式定义的硬件能力默认不接纳，不能沿用 True",
                    "为每条能力限制建立正反样本，并统计真实模型拒绝原因",
                    "合同版本、检查函数覆盖表、原因统计和模型差异",
                ),
                bt(
                    "选择外部编译方式",
                    "决定运行时解释 JSON、编译时调用厂商编译器，还是直接生成命令二进制",
                    "TVM 同时提供 JSONSerializer 和 CSourceCodegen 起点，BYOC 允许后端返回任意 runtime.Module",
                    "依据 SDK 接口、部署依赖、加载时间和调试需求选择，并隔离厂商 API",
                    "输入 IR、SDK 版本、产物格式、编译时间、部署依赖和可序列化能力",
                    "厂商 API 只能在目标机运行却被放入主机编译阶段时需要改为远程编译或运行时构建",
                    "同一最小子图经过所选方式生成、导出、加载并在设备执行",
                    "选择记录、API 适配层、产物样本和部署依赖",
                ),
                bt(
                    "实现内部 NPU IR",
                    "在 Relax Composite 与设备命令之间建立稳定的厂商中间表示",
                    "Example NPU 直接写 JSON kernel 名称，适合教学但不足以表达真实调度和内存",
                    "内部 IR 保存操作、值、布局、存储、依赖、分块和源位置，并可打印",
                    "节点编号、操作、输入输出、属性、布局、缓冲区、源 Relax 节点和版本",
                    "不能表达动态尺寸、多个输出或设备控制要求时先扩展内部 IR",
                    "每个 Composite 转换后与期望内部 IR 比较，并做序列化往返",
                    "内部 IR 文本、schema、转换日志和源位置表",
                ),
                bt(
                    "接入厂商 SDK 编译器",
                    "把内部 NPU IR 交给 SDK，并准确处理选项、诊断、产物和线程安全",
                    "RunCodegen 的 options 参数可向外部编译器传递后端配置",
                    "封装 SDK 会话，固定版本，捕获完整诊断，并把有效选项写入产物清单",
                    "SDK 版本、设备型号、输入缓冲区、选项、输出二进制、诊断和并发能力",
                    "SDK 崩溃风险高或全局状态不可重入时放入隔离工作进程",
                    "正常、错误模型、超时、并发和进程异常恢复分别测试",
                    "SDK 请求摘要、标准输出、诊断文件、退出状态和产物散列",
                ),
                bt(
                    "替换 Run 中的教学分派",
                    "把字符串查找和日志输出替换为正式命令加载、缓冲区绑定与设备提交",
                    "Example NPU Run 按 op_name 子串选择执行单元，注释说明真实实现应调度硬件",
                    "运行时只执行经过格式验证的命令，不再根据字符串临时决定硬件行为",
                    "函数目录、命令段、重定位、输入输出、队列、事件、错误码和设备版本",
                    "未知命令、设备版本不符、地址无效或队列状态异常时拒绝提交",
                    "模拟器与真机执行同一产物，比较命令记录和结果",
                    "命令反汇编、重定位结果、提交日志和设备完成状态",
                ),
                bt(
                    "完善 CMake 与部署依赖",
                    "让代码生成器、运行时和 SDK 依赖能够独立选择和准确探测",
                    "ExampleNPU.cmake 分别处理 USE_EXAMPLE_NPU_CODEGEN 与 USE_EXAMPLE_NPU_RUNTIME",
                    "增加 SDK 根目录、头文件、库、版本和平台检查，并输出清楚的配置摘要",
                    "CMake 变量、库路径、静态或动态链接、RPATH、最低版本和交叉编译",
                    "开关开启但依赖不完整时配置阶段失败，不在链接后期给出模糊错误",
                    "开发全功能、部署只运行、交叉编译和关闭后端四种配置进入 CI",
                    "CMake 日志、依赖版本、链接清单和运行时搜索路径",
                ),
                bt(
                    "分阶段交付",
                    "按可验证成果逐步从单算子走到真实模型，避免一次加入全部硬件能力",
                    "官方教程本身按注册、分区、代码生成和运行分步展示",
                    "第一阶段只跑 MatMul，随后增加组合、卷积、动态尺寸、多函数、导出和性能",
                    "阶段目标、支持模式、目标型号、测试数量、模型集合、已知限制和退出条件",
                    "某阶段的数值、资源清理和导出加载未通过前，不扩大模式范围",
                    "每阶段保留独立演示、回归集合和可部署产物",
                    "阶段报告、支持清单、测试报告、性能基线和下一阶段条件",
                ),
            ],
        },
        {
            "no": 48,
            "title": "BYOC 分阶段实验",
            "summary": "提供从纯 Python 模式观察到真实 NPU 空 SDK 适配的连续实验，每一步都列出命令、预期 IR、检查点、常见错误和保存材料。",
            "official": f"[官方 BYOC 可运行教程]({BASE_URL}/how_to/tutorials/bring_your_own_codegen.html) 与 `tests/python/contrib/test_example_npu.py`。",
            "extra": r"""
## 48.0 实验环境

```bash
git clone --depth 1 --branch v0.24.0 \
  git@github.com:apache/tvm.git tvm-v0.24.0
cd tvm-v0.24.0
cp cmake/config.cmake .
```

在 `config.cmake` 中打开 Example NPU 编译器、运行时与 LLVM，然后按 [[11-源码构建与第一个程序]] 完成构建。每个实验在新 Python 进程运行，先打印 `tvm.support.libinfo()` 并保存当前提交号。

> [!tip] 不具备真机也能完成前六个实验
> 模式注册和分区是纯 Python 变换。代码生成和教学 Runtime 需要相应 CMake 开关，但不需要真实 NPU。只有替换为自研 SDK 后的设备执行实验需要驱动与硬件。
""",
            "topics": [
                bt(
                    "实验一：查询模式注册表",
                    "导入 Example NPU 并打印按优先级排列的模式名称",
                    "官方教程第一步导入注册模块，再调用 `get_patterns_with_prefix`",
                    "复制脚本改为自研前缀，输出核心模式、可选模式和版本",
                    "Python 环境、导入路径、模式数量、名称、顺序和检查函数存在性",
                    "列表为空时先检查加载的 TVM 源码和 Python 包，不继续分区",
                    "断言 MatMul、Conv2D 和融合模式存在，断言融合模式优先",
                    "终端输出、模式清单 JSON、TVM 提交和 Python 路径",
                ),
                bt(
                    "实验二：打印原始 Relax",
                    "用 TVMScript 建立 MatMul+ReLU 并熟悉函数、数据流块与 StructInfo",
                    "官方教程使用固定形状 `float32` 的两输入模块",
                    "再增加一个只改变 dtype 的模块，为后续检查函数准备对照",
                    "main 参数、矩阵维度、返回形状、数据流输出和默认属性",
                    "原始模块自身无效时不得用分区结果掩盖错误",
                    "CPU 构建并与 NumPy 比较，保存 `mod.script()`",
                    "TVMScript、打印 IR、输入、输出和结构散列",
                ),
                bt(
                    "实验三：只执行 FuseOpsByPattern",
                    "观察 Composite 与 Codegen 属性出现的位置",
                    "官方教程设置 `bind_constants=False` 与 `annotate_codegen=True`",
                    "分别改变两个标志，整理四种输出的函数层次和参数差异",
                    "函数数量、属性、常量、参数、外部符号和主函数调用",
                    "没有任何命中时不调用 RunCodegen，先查看模式和检查结果",
                    "对四种配置做结构快照，确认理解每个标志",
                    "四份 IR、配置表、命中模式和函数数量",
                ),
                bt(
                    "实验四：加入 MergeCompositeFunctions",
                    "比较加入分组 Pass 前后的外部函数数量和依赖",
                    "官方流程在 FuseOpsByPattern 后执行 MergeCompositeFunctions",
                    "构造两个连续 Composite、一个分叉和一个跨后端示例",
                    "组数量、每组 Composite、输入输出、依赖和符号",
                    "输出形成循环或丢失组外使用值时视为测试失败",
                    "结构比较加上自定义分组报告，逐图核对",
                    "合并前后 IR、分组图、依赖表和原因",
                ),
                bt(
                    "实验五：执行 RunCodegen",
                    "查看调用变成 call_dps_packed，并确认 external_mods 出现",
                    "官方教程仅在两个全局函数均存在时执行此步",
                    "在执行前打印注册查询；执行后遍历模块属性和导入模块",
                    "ExternFunc、外部符号、参数、返回 StructInfo、模块 type key 和常量表",
                    "缺少构建开关时应跳过并给出重建提示，不应把导入错误当模式错误",
                    "断言外部调用存在、模块数大于零、原 Codegen 函数已清理",
                    "RunCodegen 前后 IR、模块属性和注册查询",
                ),
                bt(
                    "实验六：教学运行时",
                    "运行 Example NPU，阅读执行单元、内存层次和融合日志，同时牢记结果数值不可信",
                    "官方教程只断言输出形状，因为 Run 没有真实计算",
                    "把日志关联到 Composite 名称和 JSON 节点，理解真正运行时需替换的位置",
                    "输入形状、日志节点数、执行单元、融合提示、输出形状和初始化信息",
                    "不能用教学 Runtime 的数组内容进行误差比较或作为参考数据",
                    "运行 MatMul+ReLU 与 Conv2D+ReLU，确认日志中的融合名称",
                    "完整日志、JSON 图、输出形状和模块 type key",
                ),
                bt(
                    "实验七：最小自研运行时",
                    "把教学 Run 替换为一个可验证的 CPU 参考实现或 SDK 空适配层",
                    "官方建议替换 example_npu_runtime.cc 中的硬件调用位置",
                    "第一步可在 C++ 中执行 MatMul 参考计算，随后只替换提交函数为 SDK",
                    "Tensor ABI、函数分派、输入输出地址、错误码、同步和资源清理",
                    "仍没有写输出却开始比较数值，或 CPU 参考与设备路径无法切换时停止扩展",
                    "与 NumPy 位级或容差比较，测试错误参数和重复运行",
                    "实现模式、结果对照、SDK 调用日志和错误测试",
                ),
                bt(
                    "实验八：导出与新进程加载",
                    "证明产物不依赖编译进程中的 Python 对象和后端编译器",
                    "官方真实部署教程用 `export_library` 保存，再用 `tvm.runtime.load_module` 加载",
                    "建立两个脚本：一个只编译导出，一个只链接运行时并加载执行",
                    "共享库、导入模块、权重文件、RPATH、运行时注册、设备和入口符号",
                    "加载进程仍需源码框架、编译器 SDK 或临时调试文件时说明部署包不完整",
                    "在干净环境执行加载脚本，重复运行并比较参考结果",
                    "部署目录、依赖清单、加载日志、输出和文件散列",
                ),
            ],
        },
        {
            "no": 49,
            "title": "BYOC 测试 调试 与版本升级",
            "summary": "建立覆盖 Python 模式、Relax 变换、C++ 代码生成、模块序列化、设备执行、错误注入、性能和 TVM 升级的系统测试方法。",
            "official": "`tests/python/contrib/test_example_npu.py`、Relax codegen 测试、TVM 测试指南和各 BYOC 后端测试。",
            "extra": r"""
## 49.0 推荐的测试层次

```mermaid
flowchart TB
    A["模式构造与检查函数"] --> B["分区 IR 结构比较"]
    B --> C["RunCodegen 与产物解析"]
    C --> D["运行时模块单元测试"]
    D --> E["模拟器或 CPU 参考执行"]
    E --> F["真机数值与异常测试"]
    F --> G["模型回归与性能测试"]
    G --> H["导出、部署与版本兼容"]
```

上层模型测试发现差异后，应能回到更小层次复现。每层保存自己的输入和输出，不用完整模型日志代替单元测试。
""",
            "topics": [
                bt(
                    "模式注册测试",
                    "确认核心模式存在、名称正确、优先级稳定且可选模式状态清楚",
                    "Example NPU 测试读取模式名称集合，断言 dense、matmul、conv1d、conv2d 和 max_pool2d 等核心项目",
                    "除集合外再验证顺序、检查函数和模式版本",
                    "核心集合、可选集合、名称前缀、优先级、重复项和导入来源",
                    "核心模式缺失或顺序改变但没有变更说明时阻止合入",
                    "每次新进程导入后执行，避免受到其他测试注册状态影响",
                    "模式快照、差异、TVM 提交和后端版本",
                ),
                bt(
                    "分区结构测试",
                    "用结构比较确认预期子图被组合，未接纳节点仍由普通 TVM 流程处理",
                    "官方测试执行 FuseOpsByPattern 与 MergeCompositeFunctions，并检查产生 Composite",
                    "建立完整期望 IR，而不是只用字符串包含检查",
                    "函数层次、属性、参数、返回值、常量绑定、外部符号和剩余节点",
                    "只断言模块非空无法发现错误组合，应提升为结构级检查",
                    "每个模式一个正样本、多个反样本，外加重叠模式和分叉图",
                    "实际 IR、期望 IR、结构差异和检查原因",
                ),
                bt(
                    "代码生成注册测试",
                    "确认 `relax.ext.<backend>` 接收当前版本规定的三个参数并返回模块数组",
                    "Example NPU 测试用全局函数探测是否启用，再执行 RunCodegen",
                    "增加伪函数直接调用编译器，检查 options 和 constant_names",
                    "FFI 注册名、函数签名、参数类型、返回模块、异常类型和线程安全",
                    "签名与 TVM 版本不同、返回类型错误或注册名冲突时在单元测试发现",
                    "空函数数组、单函数、多函数、常量和未知选项分别测试",
                    "FFI 调用记录、模块 type key、异常文本和函数签名说明",
                ),
                bt(
                    "产物解析测试",
                    "不用运行设备就能确认编译产物结构、字段和值合法",
                    "JSONSerializer 输出可直接解析，真实后端也应提供独立解析或反汇编工具",
                    "对每个分段、命令、缓冲区和重定位项执行静态检查",
                    "格式版本、长度、偏移、对齐、符号、常量、工作区和 Target",
                    "未知版本、截断、分段重叠、字段越界和散列错误全部安全失败",
                    "正常往返、固定标准文件、随机损坏和模糊输入测试",
                    "解析树、静态检查报告、错误位置和标准产物散列",
                ),
                bt(
                    "运行时数值测试",
                    "真实后端必须验证输出数值，而不是沿用 Example NPU 的形状断言",
                    "官方教程明确说明教学 Runtime 不计算，并在 TensorRT 部分与参考结果比较",
                    "为每个算子建立独立高精度或位准确参考，组合运算再做逐层对照",
                    "输入分布、极值、数据类型、舍入、饱和、允许误差、动态尺寸和重复次数",
                    "参考实现与硬件使用同一错误代码路径或相同近似表时不具备独立性",
                    "固定数据、随机数据、极值、临界值、尾部分块和多次运行",
                    "输入、参考输出、设备输出、第一个差异位置和数值规则版本",
                ),
                bt(
                    "错误注入与恢复",
                    "验证编译、加载、申请、复制、提交、执行、等待和清理各阶段的失败行为",
                    "官方教学测试主要覆盖正常流程，真实设备后端需要自行增加系统错误测试",
                    "在 SDK 适配层提供可测试故障点，并保证第一个错误不被清理错误覆盖",
                    "故障阶段、错误码、已申请资源、队列状态、设备状态、重试和清理",
                    "超时后设备状态未知、部分输出被使用或资源泄漏时禁止继续复用会话",
                    "逐个故障点注入一次，并测试连续失败、并发失败和复位后恢复",
                    "注入配置、返回错误、清理清单、设备状态和后续调用结果",
                ),
                bt(
                    "版本升级测试",
                    "在升级 TVM、后端、驱动或固件时及时发现 API、IR 和产物变化",
                    "v0.24.0 已使用 Relax、TVM FFI 新接口以及当前 RunCodegen 签名，旧 Relay 教程不可直接照抄",
                    "固定一组小 IR 与产物标准文件，升级时比较注册名、函数签名、Pass 输出和加载行为",
                    "TVM 提交、Python API、C++ 头文件、目录、FFI 名称、模块格式和固件 ABI",
                    "任何未解释的结构差异、符号差异或旧产物加载变化都需要暂停发布",
                    "新旧版本分别运行同一测试集合，并生成结构化差异报告",
                    "版本组合、API 差异、IR 差异、产物差异和兼容结论",
                ),
                bt(
                    "性能回归测试",
                    "在功能正确后检查分区数量、数据复制、编译时间和设备时间是否退化",
                    "BYOC 机制只决定外部调度方式，最终收益取决于后端接纳范围和设备实现",
                    "为微基准与代表模型保存时间分布和硬件计数器，并设置分级告警",
                    "编译时间、缓存命中、外部函数数、复制字节、提交、执行时间、等待和峰值内存",
                    "只看端到端平均值无法解释变化，应先补齐分项测量再决定是否失败",
                    "固定环境预热，多次测量中位数和高分位，并保留原始样本",
                    "环境、频率温度、原始时间、统计值、版本和差异说明",
                ),
            ],
        },
    ]
)


for chapter in byoc_deep_chapters:
    no = chapter["no"]
    topic_toc = "\n".join(
        f"- [[#{no}.{i} {x['title']}|{no}.{i} {x['title']}]]"
        for i, x in enumerate(chapter["topics"], 1)
    )
    topic_body = "\n".join(
        render_byoc_topic(no, x, i)
        for i, x in enumerate(chapter["topics"], 1)
    )
    write(
        f"{no:02d}-{chapter['title']}.md",
        f"""
{frontmatter}
# {no}. {chapter['title']}

{callout("abstract", "本章内容", chapter["summary"])}

{callout("note", "官方依据", chapter["official"])}

## 本章阅读方法

先运行或阅读本章给出的最小示例，再按快速目录逐项检查。每一节都使用相同的七个观察角度：要解决的问题、官方实现、自研方法、必查信息、拒绝与异常、测试、应保留证据。这样的组织便于初学者从一个可见结果出发，也便于后端开发者直接把内容转成任务与测试。

遇到 API 名称时保留源码拼写，例如 `FusionPattern`、`FuseOpsByPattern`、`RunCodegen` 和 `runtime.Module`；解释文字使用 [[33-术语与 API 速查]] 中的标准中文。若某个接口与本地构建不同，先确认 TVM 提交与 Python 加载的动态库，再查固定 tag 的源码和测试。

## 快速目录

{topic_toc}

{chapter["extra"]}

{topic_body}

## 本章完成检查

- [ ] 能用自己的话说明本章每个 TVM 属性或 API 的作用；
- [ ] 能在变换前后 IR 中找到对应结构；
- [ ] 能指出 Example NPU 中仅用于教学的部分；
- [ ] 能写出自研后端的输入、输出、失败原因和测试；
- [ ] 能保存足以在另一进程或另一台开发机复现的证据；
- [ ] 能说明本章内容与前后章节的关系。

## 继续阅读

本章属于 BYOC 专题。建议同时参照 [[15-Relax DPL 子图识别与分区]]、[[16-BYOC 代码生成器]]、[[17-NPU 运行时与驱动适配]]、[[26-端到端参考实现骨架]] 和 [[29-官方资料与源码导航]]。
""",
    )
