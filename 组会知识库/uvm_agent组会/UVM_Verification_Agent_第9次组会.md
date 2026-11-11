---
title: 面向企业级 UVM 功能验证的 Agent 架构决策与关键技术调研
日期: 2026-10-26
文档类型: 组会汇报
阶段: 总体架构设计与技术调研
标签:
  - UVM
  - Agent
  - 数字IC验证
  - 架构设计
  - 组会汇报
---

# 面向企业级 UVM 功能验证的 Agent 架构决策与关键技术调研

**调研时间：2026 年 10 月 25—26 日**  
**项目阶段：需求与总体架构设计，尚未进入完整后端功能开发**

## 1. 项目进展与设计定位

当前项目拟开发一套面向数字 IC 模块/IP 级功能验证的专用 Agent。系统以设计规格说明书（Spec）为验证依据，在已有 SystemVerilog/UVM 环境上完成测试点规划、增量开发、编译仿真、回归分析、缺陷定位、覆盖率闭环和验证报告生成。重点是利用现有验证资产完成工程任务，而不是重新生成一套 UVM Testbench。

近期已完成两轮架构收敛：首先确定企业仿真环境、模型接口和 UVM 工程结构需要解耦；随后进一步明确了验证代码修改审批、回归参数审批和 RAL 生成方式。与此同时，对 UVMarvel、HAVEN、UCAgent、Spec2Cov 和 CovAgent 的公开研究与实现进行了针对性梳理，重点分析其中可转化为领域内核的技术机制。

### 1.1 当前文档版本

| 文档 | 当前版本 | 状态 |
|---|---|---|
| 需求分析与验证标准 | **v0.2** | 已形成需求基线，量化验收阈值尚未正式确定 |
| 总体架构设计 | **v0.5** | 核心架构冻结候选版，尚非企业现场验收版 |
| UVM Domain Core 详细设计 | 未正式编写 | 已形成详细设计启动与资料清单 v0.1 |
| Qt 前端 UI 设计 | v0.4 | 另行推进，不属于本次后端架构调研重点 |

当前总体架构已明确模块职责、业务流程和主要权限原则，具备进入详细设计的条件；企业仿真平台的实际接入和多模型兼容仍需后续工程验证。

### 1.2 首期产品边界

| 项目 | 首期范围 |
|---|---|
| 验证对象 | FIFO、APB Slave、AXI 相关 IP、DMA 等模块/IP 级设计 |
| 主要输入 | PDF/DOCX/Markdown Spec，已有 UVM 工程路径，寄存器 Excel，可选 RTL |
| 验证环境 | 复用已有 VIP、RAL、Scoreboard、Reference Model 和 Sequence 资产 |
| 核心能力 | 需求分析、VPlan、Coverage Plan、增量 UVM 开发、Regression、Debug、Coverage Closure、报告 |
| RTL 权限 | 支持隔离环境中自动试修，正式修改由设计 Owner 审批 |
| 运行方式 | 先在教研室环境验证，再接入企业现有仿真系统 |
| 后续扩展 | 子系统级验证、多 IP 协同以及多专业 Agent 分工 |

首期不以“自动生成完整 UVM 环境”或“多 Agent 数量”为主要目标，而以既有验证工程的可用性、缺陷检出能力和端到端证据为重点。

## 2. 总体架构的主要结论

### 2.1 Codex Core 与 UVM Domain Core 分工

项目确定采用 **Fork Codex 通用 Agent 运行框架 + 自研 UVM Domain Core** 的方式。

Codex Core 保留通用模型交互、Agent Loop、工具调用、上下文与会话管理、文件编辑和基础执行能力。UVM Domain Core 则定义验证领域的工作流程、需求追踪、阶段门禁、执行审批、缺陷生命周期和证据有效性。

两个 Core 在源码和接口上保持明确边界，在运行时共同处理同一验证任务。UVM 业务规则不分散写入 Codex 原有的通用 Agent Loop，以降低 Fork 升级和代码维护难度。

| 组成                     | 职责                                                                      |
| ---------------------- | ----------------------------------------------------------------------- |
| Codex Fork             | 通用 Agent Runtime、模型调用、上下文管理、工具执行、代码修改                                   |
| UVM Domain Core        | Requirement/VPlan、Verification IR、Workflow、Gate、Debug、Coverage、Evidence |
| Gateway / Task Service | 多用户、多项目、任务状态、审批、事件和访问控制                                                 |
| Environment Profiler   | 识别现有 UVM 工程结构和可复用的扩展点                                                   |
| Execution Adapter      | 对接不同仿真框架、调度系统、EDA 与覆盖率工具                                                |
| Model Gateway          | 统一管理各类云端、内网和本地模型的连接配置与能力                                                |

这里的 UVM Domain Core 不是第二套大模型，也不是另一个通用 Agent，而是能够通过程序执行验证规则的领域内核。例如，模型可以建议结束任务，但是否具备签核条件，必须依据回归结果、Coverage 和审批记录确定。

### 2.2 Spec-First 与 RTL 信息隔离

验证规划坚持先由 Spec 确定需求和预期行为，再结合已有 UVM 环境完成实现。RTL 作为可选输入，主要用于环境接口分析、编译调试、缺陷定位以及代码覆盖率空洞分析。

原因在于：如果直接根据 DUT RTL 编写 Reference Model 或 Scoreboard，可能把 RTL 的错误行为当作期望结果，导致 DUT 和验证模型出现一致性错误。Spec-First 并不是完全拒绝白盒信息，而是避免实现细节反向决定功能正确性的标准。

具体划分如下：

| 环节                          | RTL 使用方式                 |
| --------------------------- | ------------------------ |
| 需求提取、功能期望和 VPlan 初稿         | 不以 RTL 行为作为正确性依据         |
| UVM 工程适配、接口连接和增量开发          | 在授权范围内读取结构信息             |
| Debug、波形分析和 Coverage Gap 定位 | 按需读取 RTL 及相关信号依赖         |
| 代码修复                        | 保留 Spec 对照、原始失败证据和修改前后差异 |

### 2.3 原有 UVM 工程的增量开发

企业可能采用不同目录结构、类继承关系、VIP 版本、Factory 配置与仿真入口。因此仅允许用户填写一个“UVM 模板路径”还不足以实现工程兼容。

架构中增加 **UVM Environment Profiler**。它读取文件列表、Package、Class、UVM Component、Sequence 基类、寄存器模型、编译入口和资源约束，生成结构化的 `Project Integration Manifest`，再由 Agent 判断哪些能力可以复用、哪些文件需要增量修改。

既有 VIP 默认作为只读资产；RAL 采用教研室已存在的 **Excel → UVM RAL 生成脚本**。修改寄存器定义时应维护 Excel 源文件，通过原生成器重新生成，而不是直接修改生成的 SV 文件。Scoreboard 和 Reference Model 可以修改，但涉及期望行为的变更需要严格审核。

## 3. 面向企业的执行后端与模型解耦

### 3.1 为什么不能只支持 DVFM

教研室当前可通过自研 DVFM 完成编译和仿真，但企业不一定采用同一套脚本。企业已有项目可能使用 Makefile、Shell/Python 脚本或内部回归平台，并通过 LSF 等集群系统提交作业。

因此，DVFM 保留为**第一套真实执行适配器**，不能成为 UVM Domain Core 的必需依赖。

执行接口在逻辑上划分为三层：

| 抽象层 | 负责内容 | 适配对象 |
|---|---|---|
| Verification Flow Adapter | 编译入口、Testlist、用例/Seed 展开、回归提交、产物归档 | DVFM、Make/Shell、企业自研回归平台 |
| Job Scheduler Adapter | 作业提交、排队、状态查询、取消、超时与恢复 | Local、LSF、Slurm |
| EDA / Coverage Adapter | 仿真器调用差异、日志解析、Coverage 导出及标准化 | VCS、Questa、Xcelium 等 |

其中 **LSF 属于集群调度层，不等同于仿真框架**。如果某企业回归平台本身已经管理 LSF，就由该平台适配器负责调度，不能再额外套一层 LSF 提交，避免重复排队和作业状态混乱。

Domain Core 只使用统一结果模型：`Build Result`、`Regression Result`、`Coverage Summary`、`Artifact Reference` 等。供应商私有文件格式由适配器解析，原始日志和 Coverage DB 仍应保留。

### 3.2 多模型 API 与本地部署

首期模型策略是**用户自主选择模型**，而不是强制使用固定的 Qwen 模型。支持范围可涵盖经过协议兼容测试的 Qwen、GPT、Claude、Gemini，以及企业内部部署的模型服务。

Model Gateway 应处理端点配置、鉴权、消息与工具调用协议、流式输出、超时、异常和能力检查。能够访问某个 API，并不意味着该模型一定支持 Codex 所需的完整工具调用和长任务执行流程，因此每种模型配置需要单独做兼容测试。

企业机密 Spec、RTL、日志和模型上下文不能因本地模型故障而自动切换到未经授权的外部服务。模型访问权限和数据出域策略由服务端统一执行。

### 3.3 跨环境可移植性的验收方式

架构设计中增加两项明确的技术检验：

1. **Execution Swap Test**：同一模块、同一测试矩阵，分别经 DVFM Adapter 和非 DVFM Script Adapter 运行，检查标准化结果与 Gate 判定的一致性。
2. **Model Swap Test**：同一类任务切换两种已通过兼容测试的模型配置，不需要修改 Domain Core 的 Workflow 和 Gate 实现。

这样可移植性由运行结果证明，而不是仅依靠接口抽象作出判断。

## 4. 验证流程、Gate 与审批原则

### 4.1 完整验证流程

整个任务按业务阶段组织：

| 阶段 | 主要工作 | 产出 |
|---|---|---|
| S00 | 项目导入与环境预检 | 工程资产、工具与权限检查结果 |
| S01 | 需求分析 | 结构化需求和来源位置 |
| S02 | 测试点规划 | VPlan、需求到测试点映射 |
| S03 | 覆盖率计划 | Coverpoint、Bin、Cross 与目标策略 |
| S04 | 已有 UVM 环境分析与增量集成 | 工程结构及修改方案 |
| S05 | UVM Case、Checker、SVA 等开发 | SV 代码和变更记录 |
| S06 | 编译与 Smoke Test | 编译结果、基础用例结果 |
| S07 | 多 Seed 回归验证 | Test × Seed × Config 完整运行矩阵 |
| S08 | 失败分析与 Debug | 错误分类、根因分析和复现证据 |
| S09 | 修复与重新验证 | RTL/TB Diff、审批记录、新回归结果 |
| S10 | 覆盖率分析 | Coverage Summary、Gap 列表 |
| S11 | Coverage Closure | 补测计划与再次回归结果 |
| S12 | 验证报告与签核 | 带版本证据的验证报告 |

S08、S09 是遇到错误时进入的分支；S11 发现覆盖率空洞后，可能返回测试点、用例开发或回归阶段，并非简单重新合并 Coverage 数据。

### 4.2 Stage 与 Gate 的区别

Stage 表示“执行什么工作”，Gate 表示“是否满足进入下一阶段的条件”。任务执行结束，不代表 Gate 自动通过。

当前设计使用 G0—G6 七类门禁：项目环境、需求、VPlan/Coverage Plan、编译与 Smoke、完整回归、Coverage、报告签核。各 Gate 要根据可追踪的文件版本、日志、检查结果和审批记录作出判断，而不能仅使用模型生成的文字结论。

关键约束是：**全部必选 Case × Seed × Config PASS 后，才能进入正式 Coverage 评审和闭环签核。** 仿真过程中可以提前收集诊断性覆盖率，但用于签核的数据必须与通过完整回归的有效版本对应。

### 4.3 代码修改与运行计划审批

| 修改对象 | 已确定的处理原则 |
|---|---|
| 新增 Sequence、Case、Covergroup、SVA、Constraint | 在授权工作区允许 Agent 自动编写并执行检查 |
| Scoreboard、Reference Model 的低风险实现性修改 | 可根据策略自动检查与批准 |
| 改变 Expected Result、弱化 Checker/SVA、放宽比较条件 | 必须人工审批，不能用“修改后 Case PASS”替代正确性证明 |
| 企业 VIP | 默认只读 |
| Excel 生成的 RAL | 修改来源 Excel 和生成配置，重新生成 |
| RTL Bug 修复 | 可隔离试修；正式合并由设计 Owner 批准 |
| SL/TL、编译参数、必选 Case 配置 | 变更需人工审核 |
| **Seed、仿真数量、并发数的任何变更** | **每次变更必须人工审批** |

为了兼顾审批要求与自动回归，引入不可变的 `Approved RunPlan`：记录获批的测试矩阵、Seed、数量、并发参数、版本和审批信息。Agent 可自动执行已经批准的计划；任何新增 Seed 或调整并发等行为，都必须先产生新的 RunPlan 版本并获批准。

RTL/TB 修复后，如果 Testlist、Seed、数量和并发等获批执行参数没有变化，可以沿用原 RunPlan 再次回归。但新代码需要新的编译和仿真证据，旧版本 PASS/Coverage 不可直接继承。

## 5. 参考项目的关键技术方法

本轮调研侧重机制本身，不将论文研究原型直接视为可交付的企业软件。各项目的重点与我们的使用方式如下。

| 项目 | 研究或实现重点 | 对当前方案的启发 |
|---|---|---|
| UVMarvel | Verification IR、Bus Protocol Library、Signal Tracker | 规格信息结构化、协议知识复用、精准提取 RTL 上下文 |
| HAVEN | 协议模板、Sequence DSL、规则化代码生成 | 对常见事务和寄存器操作进行受约束代码生成 |
| UCAgent | Stage、Tool、Checker 与分层审核 | 让验证工作流程可执行、可检查、可回退 |
| Spec2Cov | Spec 驱动的激励生成、仿真与 Coverage 反馈 | 将覆盖率空洞转化为新的定向测试任务 |
| CovAgent | Coverage Hole 分类、推理开销与停滞分析 | 区分可通过补激励覆盖与需要其他方法处理的空洞 |

### 5.1 UVMarvel：Verification IR
![[Pasted image 20261026153707.png]]

IR（Intermediate Representation，中间表示）的作用是把 Spec 中分散的接口、寄存器、时序与功能描述统一成结构化信息，避免 LLM 每次直接从长篇原始文档推断整个验证环境。

UVMarvel 的研究包括结构化 IR 与总线协议库，用于从异构规格构造 UVM 验证组件。对本项目更有用的是将两个来源分开：

- **Spec/Verification IR**：表示设计应实现的功能、合法输入、约束、时序和预期行为。
- **Environment IR**：表示现有 UVM 环境中已提供的组件、接口、Sequence、VIP、Checker 和可扩展位置。

由此完成“测试需求—工程能力”匹配：已有的 AXI VIP 与通用事务 Sequence 可以复用，缺少的测试场景和 Checker 才需要增量生成。这种双 IR 匹配方式是针对当前项目的架构归纳，并非声称 UVMarvel 原文采用了同名双 IR 结构。

此外，UVMarvel 的 Signal Tracker 用于提取和覆盖率目标有关的 RTL 逻辑，Verilog Patching Library 用于重建筛选片段的语法上下文。这里的 Verilog Patcher **不是直接替用户修复正式 RTL 功能 Bug**。

### 5.2 HAVEN：DSL 与模板约束生成

DSL（Domain-Specific Language，领域专用语言）将“具体执行哪些验证动作”表达为结构化指令，再由确定性的 Code Generator 转换为 SystemVerilog/UVM 代码。HAVEN 使用协议相关模板和 Sequence DSL，降低直接让 LLM 输出大量协议代码时的出错风险。

以 DMA 基础传输为例，验证操作可以被抽象为：

```text
配置源地址 → 配置目的地址 → 配置长度
      → 启动 DMA → 等待完成/超时 → 检查结果
```

其中，寄存器写入、读回、轮询、延时、参数遍历等属于较容易标准化的操作。工具根据实际 RAL 类、Sequencer、VIP 和项目约定将其展开成 SV Sequence。这样 LLM 主要决定测试场景与参数，模板负责重复、规范的实现细节。

对当前项目，DSL 主要用于 **RAL 访问、协议常用事务和参数边界组合**；复杂 Scoreboard、Reference Model、多通道并发及特殊 SVA，仍保留直接生成或编辑 SV 的路径，不把所有验证代码强制限制在固定 DSL 中。

### 5.3 IR 和 DSL 的上下游关系

IR 与 DSL 解决的是两个不同问题：

| 技术 | 主要回答 | 典型输出 |
|---|---|---|
| Verification IR | 要验证什么，正确行为是什么 | Requirement、Scenario、Oracle、时序与接口约束 |
| VPlan / Coverage Plan | 怎样检查、怎样度量是否覆盖 | Testpoint、Checker、Coverpoint/Bin 映射 |
| Sequence DSL | 具体执行哪些操作 | 寄存器读写、轮询、协议事务、参数组合 |
| CodeGen / Codex | 怎样嵌入现有 UVM 工程 | Sequence、Test、SVA、Checker 等 SV 变更 |

两者之间还需要工程环境映射：同一个 DSL 动作，在不同企业 UVM 环境中可能使用不同的 Sequence API 和寄存器模型对象。

### 5.4 UCAgent：Stage / Tool / Checker

UCAgent 的关键思路是将长任务拆成有输入、输出和检查规则的阶段，并采用 Python Checker、LLM 检查与 Human 审核等分层检查机制。这种组织方式适合参考到 UVM Domain Core 的 Workflow 和 Gate 模块。

当前设计中的一个具体应用是 VPlan 审核：

- 对必选 Spec Requirement 建立唯一 ID。
- 检查每条必选 Requirement 是否映射至少一个 Testpoint。
- 将 Testpoint 与 Case、Coverage 和后续 Run 关联。
- 区分“映射字段齐全”与“验证策略确实有效”，后者仍需要语义审查与必要人工确认。

UCAgent 的一致性标签思想可以进一步扩展为本项目的证据链：

`Requirement → Testpoint → Case/Checker → Coverage Item → Test Run → Evidence`

这样最终验证报告可以追溯到具体的 Spec 依据、测试用例、Seed、日志和代码版本，而不是仅列出 Coverage 百分比。

### 5.5 Spec2Cov / CovAgent：覆盖率反馈

Spec2Cov 将设计 Spec、测试激励生成、仿真执行、Coverage 结果解析和后续激励改进形成循环；其公开实现支持 Verilator 和 QuestaSim 路线。CovAgent 进一步研究覆盖率空洞的类型，以及模型推理资源在覆盖率优化过程中的消耗。

对功能验证而言，Coverage Hole 不能一律通过增加随机 Seed 解决，至少应区分：

1. **可通过激励补齐**：例如尚未构造特定 AXI 错误响应、复杂状态前置条件或稀有边界组合。
2. **不能仅靠增加激励解决**：例如设计集成中的 Tie-off、不可达状态、防御性代码或需要审核的排除项。

Coverage Closure 应据此形成不同处理路径：补充 Case、调整合法约束、增加错误注入能力、进行可达性分析、审查 Waiver 等。补测完成后仍需重新经过完整回归 Gate，不能只因为覆盖率数值提高就判定验证完成。

### 5.6 方法上的组合关系

综合上述调研，当前设计形成以下工作链：

```text
Spec / 寄存器文档
        ↓
Verification IR（需求与预期行为）
        ↓
VPlan + Coverage Plan（检查目标与覆盖目标）
        ↓
Environment Profiler（现有 UVM 工程能力）
        ↓
DSL/模板 + Codex 增量 SV 开发
        ↓
Tool Adapter → 编译 / Regression / Debug
        ↓
Gate 判断与证据记录
        ↓
Coverage Gap 归因 → 补测 / 重验 → 报告
```

这是一条针对当前项目形成的技术方案，并不是某一个现有研究项目已经直接提供的完整实现。

## 6. 企业级验收关注点

本项目不采用“生成代码能编译”或者“覆盖率达到某个数字”作为唯一成功标准。评价范围分成三个维度：

| 维度 | 主要指标 |
|---|---|
| **功能正确性与缺陷检出** | Spec 需求追踪、已知 RTL Bug 检出率、误报率、Checker/Oracle 有效性、回归正确性 |
| **验证工程效率** | 测试点到可运行 Case 的时间、人工修改量、Debug 时间、Coverage Gap 收敛成本 |
| **平台可靠性与可移植性** | 执行后端切换、模型切换、作业恢复、证据完整性、权限与多项目隔离 |

公开 FIFO、APB、AXI 等设计及可控缺陷样本用于研发评测；教研室已有的 DMA 标准验证工程用于独立的端到端考核。评测必须区分开发阶段见过的样本和独立保留的样本，以免高估缺陷检出能力。

在工程实现上，重点保证以下几项：

- 每一次 PASS/FAIL 都关联到对应 Case、Seed、RTL/TB 版本、仿真器与日志。
- 高风险 Checker/Reference Model 修改不能由同一个 Agent 仅凭回归结果自行放行。
- 已审批 RunPlan 以外的 Seed、数量、并发变化必须先经人工审核。
- RTL/TB 改动后，不能将旧回归结果和旧 Coverage 无条件作为新版本签核证据。
- 模型切换不改变验证 Gate 规则；仿真后端切换不改变标准化验证结论的判定逻辑。

## 7. 阶段结论

本轮架构调研明确了四项技术重点。

**第一，采用 Codex Fork 与独立 UVM Domain Core 的组合架构。** 通用 Agent 负责模型和工具执行，Domain Core 负责验证流程、规则、审批与证据，避免把专业逻辑零散耦合进通用运行时。

**第二，采用 Spec-First 的增量验证模式。** 通过结构化需求及现有工程分析复用 VIP、RAL、Sequence、Scoreboard 和 Reference Model，重点补齐缺失测试与检查能力。

**第三，将仿真框架、集群调度、EDA 工具和模型 API 解耦。** DVFM 是当前开发用后端，不是产品的永久依赖；企业可通过适配器保留原有仿真和回归基础设施。

**第四，吸收 Verification IR、Sequence DSL、Stage/Checker 和 Coverage Feedback 等机制。** IR 管理需求表达，DSL 规范常见操作，Checker/Gate 保证流程边界，Coverage 分析负责定位并推动补测。这些机制在现有 UVM 环境上形成互补关系，而不是替代已有验证工程。

**当前状态：** 需求文档 v0.2、总体架构 v0.5（冻结候选版）；下阶段工作是将上述业务规则转化为 Domain Core 的数据模型、状态机、Gate 和适配器接口，并以实际工程测试验证其可用性。

## 参考资料

1. UVMarvel, *An Automated LLM-aided UVM Machine for Subsystem-level RTL Verification*. https://arxiv.org/abs/2605.04704
2. HAVEN, *Hybrid Automated Verification ENgine for UVM Testbench Synthesis with LLMs*. https://arxiv.org/abs/2604.27643
3. UCAgent, GitHub 项目与说明文档. https://github.com/XS-MLVP/UCAgent
4. Spec2Cov, GitHub 项目与论文. https://github.com/advent-lab/Spec2Cov；https://arxiv.org/abs/2604.15606
5. CovAgent, GitHub 项目与方法介绍. https://github.com/advent-lab/CovAgent
6. Codex, 官方开源代码仓库. https://github.com/openai/codex
