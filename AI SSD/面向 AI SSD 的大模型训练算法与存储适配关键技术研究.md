
## 技术方案

## 0 编制说明

大模型训练中的 SSD 适配不能简单理解为“把数据写入 SSD”。真实训练系统中，参数、梯度、优化器状态、激活值、Checkpoint、数据集缓存和日志/Profile 数据具有不同的生命周期和访问模式。若训练框架不区分这些对象，而是以普通文件或无语义块 I/O 的方式混合写入 SSD，将导致训练侧难以控制小随机写、临时写、重复写和 Checkpoint 突发写对训练吞吐的影响，SSD 侧也难以区分短生命周期数据、长期训练状态和持久化恢复数据。

本方案的核心思路是将训练数据由“无差别 I/O 请求”提升为“带训练语义的数据流”。训练侧负责识别数据对象、输出语义标签、组织 I/O 形态、控制调度优先级，并提供可复现实验指标；AI SSD 侧可基于这些信息开展放置、调度、缓存和寿命相关优化。

---

# 1 发展现状

## 1.1 大模型训练对存储系统的新需求

### 1.1.1 显存容量瓶颈与分层存储趋势

大模型训练已经从单纯计算密集型任务演进为计算、显存、内存、存储和互连共同受限的复杂系统任务。训练过程中，GPU 显存不仅需要容纳模型参数，还需要容纳前向传播产生的激活值、反向传播产生的梯度、优化器状态、混合精度训练中的 FP32 master weight、通信缓冲区以及框架运行时产生的临时张量，使训练状态规模显著大于模型参数本身。


 ![[Pasted image 20260605121056.png]]
表1-1大模型参数存储需求

![[Pasted image 20260605122014.png]]
图1-1 GPU内存容量增长落后于模型需求。


![[Pasted image 20260605130537.png]]
图1-2 单个NVIDIA DGX-2系统可用内存/存储的分布。相较GPU内存拥有3倍CPU内存和超过50倍的NVMe存储。

可以看出，随着参数规模、训练层数和隐藏层维度增长，单卡 GPU 显存容量逐渐成为训练系统瓶颈。为缓解该问题，业界和学术界提出了模型并行、流水线并行、张量并行、ZeRO 分片、Activation Checkpointing、CPU Offload 和 NVMe Offload 等技术。DeepSpeed ZeRO 系列通过分片优化器状态、梯度和参数降低单卡冗余显存占用；ZeRO-Infinity 进一步将 NVMe SSD 纳入 GPU、CPU、NVMe 组成的异构内存层级，说明 SSD 可作为大模型训练容量扩展的重要组成部分。

### 1.1.2 SSD 在训练系统中的角色变化

SSD 在大模型训练中的角色正在从“数据集存储介质”和“Checkpoint 保存介质”扩展为“训练状态容量扩展层”和“训练语义承载层”。传统训练流程中，SSD 主要用于保存训练语料和模型 Checkpoint，GPU 计算所需的中间状态主要驻留在 HBM 或 CPU DRAM 中。随着模型规模增长，CPU 内存和 SSD 被逐步纳入训练运行时，使训练系统能够在显存不足时继续运行更大模型或更长序列。

Smart-infinity研究把 Adam 等优化器的更新执行位置从 CPU 移到 SSD 内部 FPGA，实现近存运算，并加入Top-K 梯度压缩以节约流量。SSDTrain 研究分析得到activation 参数量增长速度快于其他参数，选择将其卸载到SSD，并将数据传输与计算完全重叠，在不影响性能的情况下降低 GPU 内存使用。这些工作共同说明，训练系统与 SSD 的关系已经从简单文件读写转向计算存储协同以及根据参数特性卸载。

![[Pasted image 20260605124000.png]]
图1-4 Smart-infinity架构图，将更新和解压缩计算卸载到SSD

![[Pasted image 20260605124307.png|552]]
图1-5 SSDTrain卸载和预取激活的流水线示意图
## 1.2 大模型训练框架与存储适配技术现状

### 1.2.1 PyTorch 训练框架现状

PyTorch 是大模型训练最主要的框架之一，其动态图机制、自动求导机制和丰富的 GPU 后端支持使其成为研究和工程训练系统的共同基础。PyTorch autograd 在前向传播过程中保存反向传播所需的中间张量，并在 backward 阶段读取这些保存张量计算梯度。这一机制使 PyTorch 成为观察 activation 生命周期的天然入口。

PyTorch 提供 module hook、parameter hook、torch.profiler、saved_tensors_hooks 等工具，能够在不改变模型数学定义的前提下采集训练过程中的张量元数据。通过 forward hook 可以获得模块输出 activation 的 shape、dtype、device 和大小；通过 gradient hook 可以获得参数梯度产生时间和规模；通过 saved_tensors_hooks 可以观察 autograd 保存和取回的中间张量；通过 optimizer state_dict 可以分析优化器状态结构；通过 profiler 可以记录 step 内算子、显存和时间开销。

PyTorch 原生 Tensor 管理主要关注设备间拷贝和自动求导正确性，并不会自动输出 SSD 写入粒度、生命周期标签或 AI SSD 语义接口。因此，本方案需要在 PyTorch 之上构建 Profiler、分类器和调度模块，将框架内部可见的训练语义提取出来，并转化为 SSD 友好的访问策略。

### 1.2.2 DeepSpeed 与 ZeRO 系列技术现状

DeepSpeed 是面向大模型训练的系统级优化框架，ZeRO 系列技术是当前具有代表性的训练状态分片机制。ZeRO-1 分片优化器状态，ZeRO-2 在此基础上分片梯度，ZeRO-3 进一步分片模型参数。通过逐步消除数据并行副本中的冗余状态，ZeRO 显著降低单卡显存压力。ZeRO-Offload 和 ZeRO-Infinity 将训练状态迁移至 CPU 或 NVMe，从而进一步扩大可训练模型规模。

![[Pasted image 20260605143428.png]]
图1-6 ZeRO系列原理图

ZeRO-Infinity 的重要意义在于证明 NVMe SSD 可以参与大模型训练运行时，而不仅是保存训练数据和 Checkpoint。它通过异构内存调度、数据预取和带宽重叠机制，在 GPU、CPU 和 NVMe 之间管理模型状态。现有 DeepSpeed Offload 配置通常以 offload device、nvme_path、buffer_count、buffer_size、max_in_cpu 等参数为核心，强调数据是否放入 NVMe 以及如何配置缓冲区，但没有直接表达“该写入属于 optimizer state”“该数据短生命周期”“该 activation 可重算”等训练语义。

本方案将在 DeepSpeed 默认 NVMe Offload 基础上分析其 I/O 模式，并增加语义分类、写入组织、调度优先级和元数据输出能力，使训练状态 Offload 不只是容量扩展机制，也成为可被 AI SSD 利用的语义化数据流。

## 1.3 现有方案不足与本方案切入点

现有训练框架和系统使用 SSD 的方式主要包括训练数据读取、Checkpoint 持久化和训练状态 Offload。DeepSpeed 支持 NVMe Offload，NVIDIA GPUDirect Storage 和 KvikIO 优化 GPU 与存储之间的数据通路，SSDTrain 和 FlashNeuron 关注 Activation Offload，BaM 和 G10 探索 GPU 与存储之间更直接或统一的访问架构。这些工作提供了重要基础，但多数方案仍以训练框架使用 SSD为主，尚未解决训练框架如何适配 AI SSD的问题。

不足主要体现在四个方面。第一，训练数据缺乏统一语义分类。参数、梯度、优化器状态、Activation、Checkpoint、数据集缓存和日志在训练框架内部是不同对象，但在存储层往往表现为普通文件读写。第二，Offload 策略主要关注显存和吞吐，对 SSD 写入粒度、生命周期隔离和写入削减关注不足。第三，多类 I/O 流之间缺少协调，Checkpoint 写入、Activation 临时写入、Optimizer State 更新和 Dataset Read 可能同时争用 SSD。第四，缺少面向 AI SSD 的接口规范，训练侧拥有语义但缺少稳定方式传递给底层。

---

# 2 研究目的及意义

## 2.1 研究目的

![[Pasted image 20260605114758.png]]

本方案的目标是建立一套从训练数据识别、生命周期建模、SSD 友好调度到 AI SSD 语义接口的完整方法。具体包括：构建面向 AI SSD 的训练数据语义分类模型；设计 SSD 友好的 Offload、预取、写回和 Checkpoint 调度方法；优化训练过程中的 I/O 访问模式；降低无效写入、小随机写和关键路径 I/O 等待；建立训练框架与 AI SSD 之间的语义协同接口机制。

这些目标共同服务于一个原则：在不改变模型结构和训练目标的情况下，让训练系统更可观测、更可调度、更适合 SSD。可重算 activation 优先重算，长期 optimizer state 采用分片和批量写回，checkpoint 采用异步分片顺序写，日志和 profile 采用缓冲与采样，数据集缓存采用预取和读缓存。

目标验证采用同环境 baseline 对比。对比对象包括 PyTorch 原生策略、DeepSpeed 默认 NVMe Offload 策略和本方案策略。评价指标包括 tokens/s、step time、GPU memory peak、Host writes、Small write ratio、Average write size、Checkpoint stall、Offload wait time 和 Tag coverage。

## 2.2 研究意义

本方案对大模型训练的意义在于提升训练系统资源使用的可控性。通过数据分类和调度，有限 GPU 显存可以承载更大模型、更长序列或更大 batch size；通过 SSD 友好 I/O 组织，训练系统可以降低因 Offload 和 Checkpoint 带来的吞吐损失；通过语义化调度，训练过程可以减少 I/O 随机性和抖动，提高长时间训练稳定性。

对 AI SSD 应用而言，训练侧输出的数据分类、生命周期提示和访问模式报告能够提供更接近真实训练负载的输入。相比通用 fio 或普通文件读写测试，训练语义 trace 能体现 activation、optimizer state、checkpoint、dataset cache 和 log/profile 等不同数据流的差异，为设备侧放置、调度、缓存和寿命相关优化提供依据。

对软硬件协同而言，该方案建立了训练算法侧与 AI SSD 侧之间的共同语言。训练侧说明数据含义、访问规律和调度意图；存储侧反馈设备统计、瓶颈现象和接口约束；双方基于统一 trace 和元数据迭代策略，使模型训练到存储设备之间形成端到端优化链路。

---

# 3 关键技术方案

## 3.1 总体技术路线

### 3.1.1 技术路线概述

总体技术路线采用“采集分析、语义建模、策略生成、框架适配、实验验证”的流程。首先，在 PyTorch 和 DeepSpeed 训练流程中插桩，采集参数、梯度、优化器状态、activation、checkpoint、dataset cache 和日志/Profile 数据的生命周期与 I/O 行为。其次，基于采集结果建立训练数据语义分类模型，形成数据类型、生命周期、访问模式、优先级、可重算性和持久化要求等标签。再次，根据分类结果设计 SSD 友好的 Offload、Prefetch、Write-back、Checkpoint 和日志管理策略。最后，将策略集成到训练框架中，并通过普通 NVMe SSD、软件 trace 和可用的 AI SSD 接口开展验证。在 AI SSD 接口明确后，可将训练语义标签映射到用户态库、驱动或设备接口；在联合测试中，可根据设备反馈调整调度阈值和 I/O 组织方式。
![[Pasted image 20260604192236.png]]
图3-1 总体技术路线图
### 3.1.2 总体架构

总体架构由七个模块组成：训练任务层、训练框架层、生命周期 Profiler、语义分类模块、SSD 友好调度模块、AI SSD 语义接口模块和实验评估模块。训练任务层提供模型、数据集和训练配置；训练框架层基于 PyTorch、DeepSpeed 和 ZeRO 执行训练；Profiler 负责采集元数据和事件；语义分类模块将对象转化为标签；调度模块决定 offload、prefetch、write-back 和写入组织；语义接口模块输出元数据或附带标签的 I/O 请求；评估模块统计训练性能和 I/O 指标。

表 7 给出模块职责。

| 模块            | 输入                     | 输出             | 主要职责                                 |
| ------------- | ---------------------- | -------------- | ------------------------------------ |
| 训练任务层         | 模型、数据集、训练配置            | 训练事件           | 提供真实训练负载                             |
| 训练框架层         | PyTorch/DeepSpeed 运行时  | Tensor 与状态对象   | 执行训练并暴露插桩点                           |
| 生命周期 Profiler | Tensor 元数据、框架事件、I/O 事件 | 生命周期记录         | 采集创建、使用、释放、写回和大小信息                   |
| 语义分类模块        | 生命周期记录、模型结构            | 数据标签           | 标注类型、生命周期、访问模式和优先级                   |
| SSD 友好调度模块    | 数据标签、资源状态              | 调度动作           | 决定 offload、prefetch、write-back 和降级策略 |
| 语义接口模块        | 数据标签、I/O 请求            | 元数据、trace、接口调用 | 向 AI SSD 侧传递训练语义                     |
| 实验评估模块        | 训练日志、I/O 日志、设备统计       | 报告和图表          | 评估吞吐、显存、写入和稳定性                       |

训练数据流从对象产生开始进入闭环。模型 forward 产生 activation，参数参与计算，optimizer state 在 optimizer step 中更新，checkpoint 在保存周期触发，dataset cache 在数据加载时被读取，日志/Profile 在训练过程中追加。Profiler 记录对象元数据和事件顺序，分类模块为对象生成标签，调度模块基于标签和资源状态选择策略，I/O 模块执行实际读写并输出 trace，评估模块再将结果反馈给分类阈值和调度策略。

闭环中包含两类反馈。第一类是训练侧反馈，例如显存峰值、step time、offload wait time、checkpoint stall 和 GPU utilization；第二类是存储侧反馈，例如 Host writes、请求大小分布、小写比例、队列深度和设备延迟。两类反馈共同决定后续策略是否需要调整。若 SSD 队列积压，则降低可延迟写入优先级；若显存峰值接近 OOM，则提高可安全 offload 数据的比例；若 checkpoint stall 明显，则调整 checkpoint 异步写和带宽限制。
![[Pasted image 20260604195050.png|697]]
图3-2 系统架构及数据流示意图
## 3.2 大模型训练数据生命周期分析技术

本节按照“数据类型识别、生命周期采集与特征建模、语义分类模型”的逻辑展开。数据类型识别用于明确训练过程中有哪些对象；生命周期采集与特征建模用于记录对象的产生、访问、迁移、写回和释放行为；语义分类模型则基于对象类型和生命周期特征生成标签、策略和聚合统计，为后续 SSD 友好调度提供输入。

![[Pasted image 20260605114227.png]]
图：生命周期分析技术路径图

### 3.2.1 训练数据类型识别

训练数据类型识别覆盖 Tensor 对象和文件对象两类数据。Tensor 对象主要包括模型参数、梯度、优化器状态和 Activation；文件对象主要包括 Checkpoint、Dataset Cache、日志文件和 Profile 文件。不同类型数据在产生阶段、生命周期、读写模式和存储需求方面存在明显差异，因此需要在采集阶段首先完成类型识别。

Tensor 对象主要通过 PyTorch 和 DeepSpeed 训练流程中的插桩进行识别。模型参数可通过 model.named_parameters()、DeepSpeed 参数管理状态或 ZeRO 分片信息识别；梯度可通过 backward 过程中的 parameter hook 或梯度分片状态识别；优化器状态可通过 optimizer 内部状态、Adam/AdamW 的一阶矩和二阶矩状态、ZeRO optimizer state 等信息识别；Activation 可通过模型 forward hook、autograd 保存张量事件等方式识别。通过这些方法，可以将训练框架内部的 Tensor 对象映射为 parameter、gradient、optimizer_state 和 activation 等基础数据类型。

文件对象主要通过训练框架回调、路径规则、文件命名规则、I/O 日志和系统监控进行识别。Checkpoint 通常由训练框架在固定 step 或 epoch 触发保存，可通过 checkpoint callback、保存路径和文件名识别；Dataset Cache 通常来自数据加载、预处理缓存或 mmap 数据文件，可通过数据集目录和 dataloader 行为识别；日志和 Profile 文件通常由 logger、TensorBoard、性能分析工具或 trace 工具产生，可通过文件路径、写入频率和事件来源进行识别。

表 3-2 给出训练数据类型识别对象。

| 数据类型            | 对象形态         | 主要来源                                | 典型对象                                       | 基本特征                            |
| --------------- | ------------ | ----------------------------------- | ------------------------------------------ | ------------------------------- |
| Parameter       | Tensor       | 模型参数表、DeepSpeed 参数分片                | weight、bias、embedding                      | 长期存在，训练计算高频读取                   |
| Gradient        | Tensor       | backward 过程、parameter hook          | `.grad`、gradient shard                     | 生命周期短，通常在 optimizer step 后释放或清零 |
| Optimizer State | Tensor/State | optimizer 内部状态、ZeRO optimizer state | Adam `exp_avg`、`exp_avg_sq`、master weight  | 长期存在，周期读写，不可重算                  |
| Activation      | Tensor       | forward hook、autograd saved tensor  | hidden states、attention output、MLP output  | forward 产生，backward 使用，部分可重算    |
| Checkpoint      | File         | checkpoint callback、保存路径            | model state、optimizer state、training state | 低频大块写，可靠持久化                     |
| Dataset Cache   | File         | dataloader、缓存目录、数据索引                | tokenized shard、sample index、mmap file     | 读多写少，影响数据加载吞吐                   |
| Log/Profile     | File         | logger、profiler、trace 工具            | event file、trace file、training log         | 高频小写，部分可采样或可丢弃                  |

### 3.2.2 元数据记录与生命周期特征提取

在完成训练数据类型识别后，Profiler 需要进一步记录每个数据对象在训练过程中的产生、访问、迁移、写回和释放过程。该步骤把训练过程中分散在 PyTorch、DeepSpeed、优化器、Checkpoint 机制和系统 I/O 层的信息整理成可用于语义分类的基础输入。

生命周期采集需要覆盖多个层级。模型层通过 forward hook 采集模块输出 Activation；autograd 层通过 `saved_tensors_hooks` 采集中间张量保存和取回事件；参数层通过 parameter hook 采集梯度产生事件；优化器层采集 optimizer state 的初始化、访问和更新；DeepSpeed 层采集 ZeRO 分片参数、分片优化器状态、NVMe Offload buffer、prefetch 和 write-back 等状态迁移事件；系统 I/O 层采集文件写入、SSD 读写量、请求大小、队列深度和 I/O 延迟。

表 3-3 给出生命周期采集方法。

| 层级             | 采集对象            | 采集方法                     | 采集信息                            |
| -------------- | --------------- | ------------------------ | ------------------------------- |
| PyTorch Module | activation      | forward hook             | shape、dtype、size、layer、device   |
| Autograd       | saved tensor    | saved_tensors_hooks      | 保存时间、取回时间、大小、重用距离               |
| Parameter      | gradient        | parameter hook           | 梯度产生时间、大小、所属参数                  |
| Optimizer      | optimizer state | state_dict 或内部状态         | m/v/master weight 大小和更新窗口       |
| DeepSpeed ZeRO | shard state     | DeepSpeed engine 状态      | 分片参数、offload buffer、prefetch 事件 |
| Checkpoint     | 状态文件            | framework callback       | 文件大小、写入时间、版本信息                  |
| 系统 I/O         | SSD 请求          | iostat、nvme-cli、eBPF 或日志 | 读写量、请求大小、延迟、队列深度                |


为了统一描述不同来源的数据对象，建立标准化元数据结构。元数据主要包括三类：第一类是对象身份信息，用于说明该对象是谁、属于哪类数据、来自哪个层和哪个 rank；第二类是规模与位置描述，用于说明该对象的数据大小、数据类型和当前所在设备；第三类是底层存储与视图关系，用于处理 Tensor 别名、view、slice、reshape、transpose 等情况，避免重复统计和重复写入 SSD。

表 3-4 给出训练数据对象统一元数据字段。

| 字段               | 类型      | 含义                         | 示例                                                                 |
| ---------------- | ------- | -------------------------- | ------------------------------------------------------------------ |
| `object_id`      | 对象身份字段  | 训练数据对象的唯一编号                | `rank0_step10_layer3_q`                                            |
| `name`           | 对象身份字段  | 数据对象名称，通常来自模型模块名、参数名或文件名   | `transformer.layers.3.attn.q`                                      |
| `data_type`      | 对象身份字段  | 数据类型                       | `parameter`、`gradient`、`activation`、`optimizer_state`、`checkpoint` |
| `layer_id`       | 对象身份字段  | 所属模型层编号                    | `3`                                                                |
| `rank_id`        | 对象身份字段  | 分布式训练中的进程编号                | `rank0`                                                            |
| `shape`          | 规模与位置字段 | Tensor 的逻辑形状               | `[8, 16, 128, 64]`                                                 |
| `dtype`          | 规模与位置字段 | 数据精度类型                     | `fp32`、`fp16`、`bf16`                                               |
| `size_bytes`     | 规模与位置字段 | 数据大小，单位为字节                 | `16777216`                                                         |
| `device`         | 规模与位置字段 | 当前所在设备或存储位置                | `cuda:0`、`cpu`、`nvme`                                              |
| `created_at`     | 事件字段    | 数据产生的时间或训练阶段               | `step10_forward_layer3`                                            |
| `last_used_at`   | 事件字段    | 数据最后一次被使用的时间或训练阶段          | `step10_backward_layer3`                                           |
| `read_count`     | 事件字段    | 数据被读取的次数                   | `1`                                                                |
| `write_count`    | 事件字段    | 数据被写入的次数                   | `1`                                                                |
| `recomputable`   | 策略辅助字段  | 是否可以通过重新计算得到               | `true`、`false`                                                     |
| `persistence`    | 策略辅助字段  | 数据是否需要持久保存                 | `temporary`、`long_lived`、`persistent`                              |
| `storage_id`     | 底层存储字段  | 底层 storage 的唯一标识           | `cuda0_ptr140390129344512_size50331648`                            |
| `storage_offset` | 底层存储字段  | Tensor 在底层 storage 中的起始偏移  | `0`、`1024`                                                         |
| `stride`         | 底层存储字段  | Tensor 在 storage 中按各维访问的步长 | `[131072, 8192, 64, 1]`                                            |
| `is_view`        | 底层存储字段  | 是否是其他 Tensor 的视图           | `true`、`false`                                                     |
| `base_object_id` | 底层存储字段  | 如果当前对象是视图，指向其基础对象          | `rank0_step10_layer3_qkv`                                          |
| `alias_group_id` | 底层存储字段  | 共享同一底层 storage 的对象组编号      | `alias_group_003`                                                  |

在元数据基础上，生命周期特征提取进一步把训练事件转化为少量可用于分类的行为特征。对于所有对象，重点提取数据规模、生命周期长度、重用距离、读写次数和写入频率；对于不同数据类型，再提取少量类型相关特征。例如，Activation 重点关注 backward 重用距离和可重算性；Optimizer State 重点关注更新频率；Checkpoint 重点关注保存周期和写入规模；Dataset Cache 重点关注读取频率和缓存命中情况；Log/Profile 重点关注事件频率和可丢弃性。

表 3-5 给出生命周期特征提取内容。

| 特征                        | 适用对象            | 含义                           |
| ------------------------- | --------------- | ---------------------------- |
| `size_bytes`              | 全部对象            | 数据对象大小                       |
| `lifetime`                | 全部对象            | 数据从产生到最后使用或释放的时间跨度           |
| `reuse_distance`          | Tensor 对象       | 数据从产生或上次使用到下次使用之间的距离         |
| `read_count`              | 全部对象            | 数据读取次数                       |
| `write_count`             | 全部对象            | 数据写入次数                       |
| `write_frequency`         | 全部对象            | 单位 step 或单位时间内的写入频率          |
| `backward_reuse_distance` | Activation      | forward 产生到 backward 使用之间的距离 |
| `update_frequency`        | Optimizer State | optimizer step 中被更新的频率       |
| `save_interval`           | Checkpoint      | Checkpoint 保存周期              |
| `cache_hit_rate`          | Dataset Cache   | 缓存命中率                        |
| `event_frequency`         | Log/Profile     | 日志或 Profile 事件产生频率           |
| `discardability`          | Log/Profile     | 数据是否可采样、延迟或丢弃                |
### 3.2.3 训练数据语义分类模型

本项目的语义分类模型拟采用“规则驱动 + Profiler 反馈修正”的方式构建。项目初期首先使用可解释规则，以 3.2.1 中识别出的数据类型和 3.2.2 中采集到的生命周期特征为输入，生成面向调度模块和 AI SSD 语义接口的分类标签，对训练数据进行分类，以降低实现复杂度并便于调试。例如，Checkpoint 具有低频、大块、可靠持久化特征，可默认标注为 persistent、append_only 和 large_write；Activation 通常在 forward 阶段产生并在 backward 阶段使用，可默认标注为 short_lived 和 write_once_read_once，并进一步根据是否可重算、大小和重用距离决定是否写入 SSD；Optimizer State 贯穿整个训练过程，并在 optimizer step 中周期性读写，可默认标注为 long_lived、read_write 和 periodic_update；Dataset Cache 主要服务于数据读取，可默认标注为 read_mostly。

在规则运行后，Profiler 会根据实际训练过程中的统计结果修正分类阈值。可用于反馈的指标包括 Activation 大小分布、backward 重用距离、Optimizer State 更新频率、Checkpoint 写入时间、SSD 带宽利用率、GPU 显存压力和关键路径等待时间等。例如，当 GPU 显存峰值接近 OOM 时，可降低安全 Offload 阈值或提高 Activation 重计算比例；当 SSD 队列积压或写入延迟升高时，可提高 Activation Offload 阈值，并降低日志/Profile 等可延迟数据的写入优先级；当 Checkpoint stall 明显时，可调整 Checkpoint 异步写入和带宽限制。通过这种反馈机制，分类规则能够逐步适配具体模型规模、batch size、sequence length、GPU 显存容量和 SSD 性能条件。

表 9 给出规则分类与策略映射。

| 数据类别            | 生命周期标签                 | 访问模式标签                | 默认策略             | SSD 友好组织方式            |
| --------------- | ---------------------- | --------------------- | ---------------- | --------------------- |
| Parameter       | long_lived             | read_heavy/read_write | 分层缓存、按需预取        | layer-wise shard      |
| Gradient        | short_lived            | write_then_read       | 优先 GPU/CPU 管理    | 谨慎 offload，聚合后写       |
| Optimizer State | long_lived             | periodic_read_write   | 分片 offload       | fixed-size shard、批量写回 |
| Activation      | short_lived            | write_once_read_once  | 重算优先，选择性 offload | ring buffer、预分配 slot  |
| Checkpoint      | persistent             | append_only           | 异步分片保存           | 大块顺序写、版本管理            |
| Dataset Cache   | persistent/read_mostly | read_heavy            | 预取与缓存            | 大文件 shard、mmap        |
| Log/Profile     | temporary/discardable  | small_write           | 缓冲与采样            | 批量追加、低优先级             |

分类模块输出应包括单对象标签和聚合统计。单对象标签用于调度，聚合统计用于报告和策略评估。聚合统计包括每类数据大小占比、进入 SSD 的比例、平均生命周期、平均重用距离、写入次数、写入块大小分布和关键路径等待贡献。


## 3.3 SSD 友好的训练数据 Offload 策略

![[3.3.png]]

### 3.3.1 参数数据 Offload 策略

参数数据 Offload 需要与模型执行顺序紧密结合。Transformer 模型通常按 layer 顺序执行 forward 和 backward，ZeRO-3 在使用参数前 gather，在使用完成后释放或重新分片。方案利用这一规律设计 layer-wise 参数预取，使后续 layer 所需参数在计算到达前进入 GPU 或 CPU 缓存，降低 GPU 等待时间。

参数策略综合考虑显存压力、CPU 缓存容量、SSD 读取带宽和 layer 执行时间。如果显存压力较低，更多参数可驻留 GPU，减少 SSD 读取；如果显存压力较高，则采用更积极的释放和预取策略。对频繁访问的热参数，优先保存在 CPU 或 GPU；对冷参数分片，保存在 SSD 并按需读取。训练侧标注参数数据为 long_lived、read_heavy 或 read_write，使其区别于短生命周期 activation。

参数预取窗口可根据 layer 计算时间和 I/O 延迟估算。若下一层参数读取预计耗时小于当前层计算时间，可在当前层计算开始后异步预取；若读取耗时较长，则需要扩大预取提前量或提高缓存驻留比例。若 SSD 负载过高，调度器可优先保证即将使用的参数分片，推迟日志、profile 或可重算 activation 的写入。

### 3.3.2 优化器状态 Offload 策略

优化器状态是 SSD Offload 的重要对象。Adam/AdamW 优化器状态规模大、长期存在、周期读写，适合分片管理，但不适合以大量小 Tensor 文件形式写入 SSD。方案采用固定大小 shard 组织优化器状态，将多个小状态合并为较大连续块，并按 rank、layer 或参数范围管理偏移。这样既减少文件数量和元数据开销，也便于 AI SSD 识别其为长期、周期更新数据。

优化器状态写回采用批量化和异步化机制。在 optimizer step 中，训练框架优先处理当前更新窗口所需状态，其他状态根据依赖关系延迟写回。若 CPU 内存允许，可将近期状态保留在 CPU 缓存中，避免每 step 都完整写回 SSD。对于必须写回的数据，采用大块连续写或日志式追加，减少小随机写。

Fixed shard 布局需要维护稳定索引。每个 shard 记录 rank_id、param_range、state_type、offset、size_bytes、version 和 checksum。读取时根据参数范围定位对应状态块，写回时更新版本和校验。若采用日志式追加，则需要维护新旧版本映射和回收机制；若采用固定 offset 更新，则需要关注覆盖写热点。两种方式可根据设备能力和实验结果选择。

### 3.3.3 激活值管理策略

Activation 管理是 SSD 适配中最需要精细决策的部分。Activation 生命周期短，若不加选择地写入 SSD，可能产生大量临时写入。方案采用“重算优先、选择性 Offload、缓冲复用”的策略。可重算且计算代价相对较低的 activation 使用 checkpointing 或 recomputation；不可重算、尺寸较大、反向重用距离较长且显存压力明显的数据才写入 SSD。

Activation 写入 SSD 时采用 ring buffer。该方式通过预分配固定大小文件或区域，将 activation 按 slot 写入和复用，避免每个 activation 创建独立文件。反向传播读取后，slot 立即标记为空并复用。每个 slot 记录 tensor_id、layer_id、microbatch_id、size_bytes、write_time、read_time 和 valid_flag。这样可以降低文件系统元数据开销，并使短生命周期数据与 checkpoint、optimizer state 等长期数据隔离。

Activation 调度需要处理流水线并行和梯度累积场景。不同 microbatch 的 activation 生命周期可能交错，ring buffer 需要按 microbatch_id 和 layer_id 管理 slot，避免覆盖尚未被 backward 使用的数据。对于后几层 activation，由于 forward 后很快进入 backward，可直接保留在 GPU 或 CPU，不必写入 SSD。SSDTrain 的研究也表明，调度器需要知道微批阶段和即将到来的 backward 顺序，才能提前预取 activation。

### 3.3.4 梯度数据管理策略

梯度通常不作为 SSD Offload 的优先对象。梯度生命周期短，并与 backward、通信和 optimizer step 高度耦合。若大量梯度写入 SSD，容易增加关键路径 I/O。默认策略是梯度优先保留在 GPU 或 CPU 中完成聚合、reduce-scatter 和更新，避免将其作为常规 SSD 写入对象。

在极端显存压力或较大 gradient accumulation 场景下，可探索梯度分片临时写入 SSD，但必须满足两个条件。第一，写入粒度足够大，不能逐小 Tensor 写入；第二，读取时机可预测，避免 optimizer step 等待 SSD。梯度 Offload 应作为可选增强策略，并通过 profiler 证明其收益大于 I/O 代价后才启用。

梯度相关 trace 仍需采集。即使不写入 SSD，梯度产生时间、大小、通信时间和释放时间也影响 optimizer state 调度和显存压力判断。梯度生命周期信息可用于判断 activation 是否需要 offload、参数是否可释放以及 optimizer state 是否应提前预取。

### 3.3.5 Checkpoint 优化策略

Checkpoint 优化重点解决突发写入和训练阻塞问题。方案支持分片 Checkpoint，使不同 rank 并行保存自身状态，避免单点聚合；支持异步 Checkpoint，使写入尽可能脱离训练关键路径；支持大块顺序写，使 SSD 更高效处理持久化数据；支持版本管理，避免保留过多历史状态造成空间和写入压力。

Checkpoint 可靠性不能因写入优化而削弱。每个 checkpoint 版本应包含元数据、状态分片、完整性校验、训练步数、随机数状态和恢复所需的分布式拓扑信息。异步写入完成前，应清晰标记版本状态，避免训练中断后误用未完成 checkpoint。恢复测试应成为实验评估的一部分。

Checkpoint 与 Offload 流需要解耦。若 checkpoint 写入与 optimizer state 写回或 activation offload 同时发生，会形成 I/O 峰值。调度器应在 checkpoint 写入期间降低日志写入优先级，限制可延迟 offload，必要时调整 checkpoint 带宽上限。训练侧应标注 checkpoint 为 persistent、append_only、reliable 和 low_frequency_large_write，帮助 AI SSD 区分其与临时数据。

## 3.4 面向 SSD 特性的训练 I/O 优化方法

![[3.4.png]]

### 3.4.1 大块化写入方法

大块化写入是降低小随机写和元数据开销的基本策略。训练中大量 Tensor 尺寸不一致，若按 Tensor 粒度逐个写入 SSD，会导致请求数量过多。方案将同类数据按 layer、rank、state shard 或时间窗口合并为更大的写入块。Optimizer state 按固定 shard 合并，activation 按 ring buffer slot 写入，日志按时间窗口缓冲追加，checkpoint 按 rank 和 shard 写入大文件。

大块化还可以提高元数据表达能力。每个大块可带有统一的数据类型、生命周期和访问模式标签，而不是为每个小 Tensor 分别维护复杂元数据。这样既便于训练侧恢复数据，也便于 AI SSD 侧识别数据流。

大块化需要设置合理阈值。阈值过小，无法减少小写；阈值过大，可能增加缓冲等待和显存/内存占用。阈值应结合 SSD 带宽、CPU 内存、GPU 等待时间和数据重用距离调整。调度器应记录合并前后请求数量、平均写入大小和等待时间，判断大块化是否真正降低了关键路径开销。

### 3.4.2 顺序化写入方法

顺序化写入适合 SSD 的物理特性，也便于底层写入聚合和垃圾回收。方案对 checkpoint 采用 append-only 或分片顺序写；对 activation 临时数据采用预分配连续区域和 slot 顺序复用；对 optimizer state 探索固定 offset 更新与日志式写入两种方式；对日志和 profile 数据采用缓冲追加。

表 10 对比不同写入组织方式。

| 写入方式 | 适用数据 | 优点 | 风险 | 使用建议 |
|---|---|---|---|---|
| 每 Tensor 独立写 | 小型调试数据 | 实现简单 | 小文件多、随机性强 | 不作为主要策略 |
| Fixed Shard | optimizer state、参数分片 | 稳定、便于索引 | 更新位置需管理 | 重点采用 |
| Ring Buffer | activation 临时数据 | 适合短生命周期复用 | 需要 slot 管理 | 重点采用 |
| Append-only | checkpoint、日志 | 顺序性好 | 需要版本和清理机制 | 重点采用 |
| Log-structured | 频繁更新状态 | 顺序写友好 | 需要 compaction | 作为增强探索 |

顺序化策略还应避免冷热数据混放。短生命周期 activation 与长期 checkpoint 不应共享同一逻辑区域；读密集 dataset cache 不应与写密集 optimizer state 混为一类；日志/Profile 应作为低优先级追加流单独处理。若 AI SSD 支持主机侧放置提示或类似多流写入机制，可将不同语义数据映射到不同放置类别。

### 3.4.3 计算与 I/O 重叠方法

计算与 I/O 重叠是保证训练吞吐的关键。方案通过异步线程、CUDA stream、DeepSpeed offload buffer 和训练阶段调度实现重叠。在 forward 阶段，预取后续 layer 参数或状态；在 backward 阶段，读取即将使用的 activation，并写回已不再需要的数据；在 optimizer step 阶段，批量读写优化器状态，并尽量与 checkpoint 和日志写入错峰。

重叠策略需要基于 profiler 结果动态调整。如果 SSD 带宽已被 checkpoint 占用，则 activation 写回应降级或推迟；如果 GPU utilization 下降且 I/O 队列积压，则说明预取不及时或写入过度；如果 CPU staging buffer 长期满载，则需要调整 CPU 缓存容量或减少同时 offload 的对象。

重叠策略的评估不能只看平均 step time，还要看尾延迟和等待分解。报告应包含 compute time、prefetch wait、offload write wait、checkpoint stall、data loader wait 和 log/profile overhead。只有当 I/O 等待被有效隐藏且训练正确性不受影响时，重叠策略才算有效。

### 3.4.4 写入削减方法

写入削减是降低 SSD 压力的重要目标。方案采用四类削减方法。第一，可重算数据少写，通过 activation checkpointing 和 recomputation 减少 SSD 保存。第二，低价值数据少写，日志和 profile 数据采用采样与缓冲。第三，重复状态少写，优化器状态通过 CPU 缓存和批量写回减少频繁覆盖。第四，checkpoint 有策略地写，通过保存频率、保留版本和增量探索控制写入规模。

表 11 给出写入削减策略。

| 策略 | 适用对象 | 削减逻辑 | 可能代价 |
|---|---|---|---|
| Recomputation | activation | 用计算替代保存 | 增加 GPU 计算 |
| Sampling | log/profile | 降低记录频率 | 诊断粒度下降 |
| Version Management | checkpoint | 控制保留数量 | 历史恢复点减少 |
| CPU Cache | optimizer state | 减少 SSD 写回 | 增加 CPU 内存占用 |
| Write Coalescing | 小 Tensor | 合并后写入 | 增加缓冲管理复杂度 |

写入削减不能牺牲恢复正确性和训练数学语义。Checkpoint、optimizer state 等可靠性关键数据必须保证完整性；activation 可重算策略需要保证反向传播结果一致；日志采样需要保留必要诊断信息。所有削减策略应记录被削减的数据量、削减原因和可能代价，便于实验分析。

## 3.5 面向 AI SSD 的训练语义提示接口

![[images/3.5.png]]
### 3.5.1 接口设计原则与语义模型

训练语义提示接口的目标是将训练框架内部已经掌握的数据含义传递给 AI SSD 或相关存储管理组件，使存储系统能够感知训练数据的生命周期、访问模式和重要程度，从而为数据放置、缓存管理、调度优化和资源分配提供依据。

本接口不依赖特定 SSD 硬件实现，也不改变训练数据本身内容，仅负责传递训练侧已经掌握的语义信息。接口设计遵循可解释、可扩展、可验证和与训练框架解耦的原则，既能够通过元数据文件和离线 Trace 实现验证，也能够进一步扩展到用户态库、驱动程序或 AI SSD 专用接口。

在语义模型方面，训练数据被统一描述为具有数据类型、生命周期、访问模式、优先级、可重算性和持久化要求等属性的语义对象。典型数据类型包括 Parameter、Gradient、Optimizer State、Activation、Checkpoint、Dataset Cache 和 Log/Profile。不同数据对象具有不同的生命周期和访问特征，例如 Activation 通常属于短生命周期且写一次读一次的数据，而 Checkpoint 则属于持久化的大规模顺序写数据。通过统一语义模型，可为后续调度和存储优化提供标准化描述。

### 3.5.2 语义标签体系与接口字段设计

为了准确描述训练数据特征，接口定义了一套统一语义标签体系。标签内容主要包括数据类型、生命周期、访问模式、优先级以及可靠性要求等信息。

数据类型标签用于区分 Parameter、Optimizer State、Activation、Checkpoint 等不同训练对象；生命周期标签用于描述 temporary、short-lived、long-lived 和 persistent 等生命周期特征；访问模式标签用于表示 read-heavy、write-heavy、read-write、append-only、write-once-read-once 等访问行为；优先级标签用于区分 critical、high、normal、low 和 background 等不同等级的数据流。

在接口实现中，每个数据对象对应一个统一描述结构。核心字段包括 object_id、data_type、lifecycle、access_pattern、priority、size_bytes 和 persistence 等必选字段；扩展字段包括 recomputable、rank_id、layer_id、reuse_distance、suggested_io、version 和 checksum 等信息。

通过统一字段定义，训练框架能够持续输出结构化语义信息，为 AI SSD 提供可解析、可统计和可利用的数据依据。

表 12 给出接口字段建议。

| 字段 | 含义 | 示例 |
|---|---|---|
| object_id | 数据对象唯一标识 | rank0_layer12_opt_shard3 |
| data_type | 数据类型 | optimizer_state |
| lifecycle | 生命周期 | long_lived |
| access_pattern | 访问模式 | periodic_read_write |
| priority | 优先级 | critical |
| size_bytes | 数据大小 | 268435456 |
| recomputable | 是否可重算 | false |
| persistence | 是否持久化 | true |
| rank_id | 分布式 rank | 0 |
| layer_id | 模型层编号 | 12 |
| reuse_distance | 重用距离 | backward_layer_gap=8 |
| suggested_io | 建议 I/O 形态 | fixed_shard |
| version | 数据版本 | step_10000 |
| checksum | 完整性校验 | sha256:... |

### 3.5.3 接口实现与协同机制

训练语义接口采用分阶段实现方式。

第一阶段通过目录组织规则、Sidecar Metadata 文件和 I/O Trace 等方式输出训练语义信息，实现训练侧数据分类结果的离线验证。不同类型的数据分别存放于独立目录，并为每次写入生成对应元数据记录。

第二阶段通过用户态库或训练框架插件，在实际 I/O 请求发起时附带语义标签，使训练语义能够与读写请求同步传递。

第三阶段根据 AI SSD 的实际能力，将训练语义进一步映射至驱动层或设备接口，实现训练系统与 AI SSD 的深度协同。

在协同过程中，训练侧负责提供数据类型、生命周期、访问模式和优先级等语义信息；存储侧则根据这些语义信息开展数据放置、缓存管理、调度优化和寿命管理等工作。双方通过统一的元数据格式和 Trace 分析机制形成闭环反馈，不断优化训练过程中的存储访问行为。

通过该接口机制，训练框架内部可见的数据语义能够被存储系统有效利用，为 AI SSD 提供更符合实际训练场景的优化依据，实现训练算法与存储系统的协同优化。

## 3.6 训练框架适配与原型系统实现
![[images/3.6.png]]

### 3.6.1 训练框架适配实现

为了验证所提出的训练数据分类、SSD 友好调度以及语义提示机制，本方案基于 PyTorch 与 DeepSpeed 构建原型系统，并在不改变模型训练逻辑和数学正确性的前提下实现训练框架适配。

PyTorch 适配主要围绕模型层、Autograd 层和优化器层展开。通过 Forward Hook、Parameter Hook 以及 Saved Tensor Hooks 等机制，采集 Activation、Gradient、Parameter 和 Optimizer State 的生命周期信息，并将其转化为统一的数据对象描述。对于 Activation 管理，适配模块能够根据数据大小、重用距离和可重算性判断其采用保留、重算或 SSD Offload 等不同策略。

DeepSpeed 适配重点面向 ZeRO-3 与 NVMe Offload 机制展开。通过分析参数分片、优化器状态分片以及 Offload Buffer 的运行行为，实现训练数据的语义标注和 SSD 友好调度。对于参数数据，重点优化 Layer-wise Prefetch；对于 Optimizer State，重点研究 Fixed Shard 与批量写回机制；对于 Checkpoint，则支持异步分片保存和与 Offload 数据流解耦。

整个适配过程采用插件化和配置化设计方式，尽量减少对训练框架核心代码的修改，使同一训练任务能够在原生策略、DeepSpeed 默认策略和本方案策略之间灵活切换，为后续实验验证提供统一平台。

### 3.6.2 原型系统关键模块设计

原型系统由生命周期 Profiler、语义分类模块、SSD 友好调度模块和语义接口模块组成。

生命周期 Profiler 负责采集训练过程中各类数据对象的创建、访问、释放和写回行为，形成训练数据生命周期画像。采集信息包括对象大小、设备位置、创建时间、释放时间、重用距离以及读写次数等内容，并以结构化日志形式输出。

语义分类模块根据生命周期特征对训练数据进行统一建模，将 Parameter、Gradient、Optimizer State、Activation、Checkpoint、Dataset Cache 和 Log/Profile 等对象映射为标准语义标签。分类结果不仅用于统计分析，同时作为后续调度决策的重要依据。

SSD 友好调度模块根据数据语义和系统资源状态，动态决定数据的 Offload、Prefetch、Write-back 和缓存策略。对于 Activation 采用“重算优先、选择性 Offload”的管理机制；对于 Optimizer State 采用 Fixed Shard 和批量写回策略；对于 Checkpoint 采用异步顺序写和版本管理机制；对于日志和 Profile 数据则采用缓冲与采样策略。

语义接口模块负责将训练侧生成的数据类型、生命周期、访问模式和优先级等信息输出为标准化元数据，为 AI SSD 提供可利用的训练语义输入，实现训练系统与存储系统之间的协同优化。

### 3.6.3 实验评估与验证机制

为了验证方案有效性，原型系统建立完整的实验评估与验证机制，对训练性能、显存利用率、SSD 友好性以及接口覆盖率等指标进行综合分析。

训练性能指标主要包括 Tokens/s、Step Time、GPU Utilization 和尾延迟等，用于评价调度策略对训练效率的影响；显存相关指标包括 GPU Memory Peak 和 OOM 避免能力，用于评估 Offload 策略的容量扩展效果；存储相关指标包括 Host Writes、平均请求大小、小随机写比例、Offload Wait Time 和 Checkpoint Stall，用于衡量训练 I/O 是否更加符合 SSD 特性。

在验证过程中，系统设置三类对照组，包括 PyTorch 原生训练策略、DeepSpeed 默认 NVMe Offload 策略以及本方案提出的 SSD 友好训练策略。所有实验统一记录模型配置、训练参数、硬件环境和软件版本，确保结果可复现和可比较。

除性能测试外，系统还对 Checkpoint 恢复正确性、语义标签完整性以及 Trace 可解析性进行验证，确保优化策略在提升训练效率的同时保持训练正确性和系统可靠性。最终形成训练性能报告、生命周期分析报告、I/O 行为报告和语义接口评估报告，为后续 AI SSD 联合优化提供依据。

---

# 4 技术创新点

## 4.1 面向 AI SSD 的训练数据语义分类方法

第一项创新是建立面向 AI SSD 的训练数据语义分类方法。与现有训练框架只在内部区分 Tensor 和状态不同，本方案将数据类型、生命周期、访问模式、可重算性、持久化要求和优先级统一为可输出的语义标签，使底层存储侧能够理解训练数据的真实含义。

该方法把训练框架内部可见信息转化为标准化字段，使 AI SSD 能够区分 short_lived activation、long_lived optimizer state、persistent checkpoint 和 read_mostly dataset cache。分类结果不仅用于统计，还直接驱动调度策略。通过这些输出，训练数据不再只是普通 I/O 请求，而是具有可调度、可解释和可验证的语义对象。

## 4.2 SSD 友好的训练数据 Offload 与调度方法

第二项创新是将 Offload 从容量扩展机制提升为 SSD 友好调度机制。方案在显存、计算和 I/O 之间进行选择，形成参数预取、优化器状态 fixed shard、activation ring buffer、checkpoint 异步顺序写和日志缓冲采样等组合策略。

现有 Offload 技术通常首先解决显存不足问题，关注训练能否运行和显存峰值能否降低。本方案进一步关注 Offload 后的数据是否适合 SSD：写入是否过碎、生命周期是否可区分、是否与 checkpoint 抢占带宽、是否造成关键路径等待。该思路把 Offload 从单一容量手段扩展为显存、计算、I/O 和设备写入压力之间的综合调度问题。

调度方法具备动态降级能力。当 SSD 负载高或 checkpoint 正在写入时，低优先级数据延迟写入；当 GPU 显存压力接近阈值时，选择性 offload 提高优先级；当某类 activation 可重算时，优先使用计算替代保存。该策略能够避免简单 offload 带来的无效写入和训练抖动。

## 4.3 面向训练过程的 I/O 大块化、顺序化与削减机制

第三项创新是针对训练过程不同数据流设计具体 I/O 形态。通过大块化写入减少小请求，通过顺序化写入降低随机性，通过写入削减减少无效写入，通过优先级控制降低关键路径阻塞。这些机制把训练 I/O 从碎片化模式转化为更适合 SSD 的规整化模式。

大块化机制按数据语义组织，而不是简单合并所有写入。Optimizer state 适合按 rank、layer 或 shard 组织固定块；activation 适合按预分配 ring buffer slot 复用；checkpoint 适合按 rank 分片形成顺序大文件；日志适合按时间窗口缓冲追加。不同组织方式对应不同生命周期和恢复要求，因此需要与语义分类共同设计。

写入削减机制强调“少写比盲目 offload 更重要”。可重算 activation 不优先写入 SSD，低价值日志不与关键训练 I/O 争用资源，重复更新状态通过缓存和批量写回减少覆盖写，checkpoint 通过保存频率和版本管理控制写入规模。削减策略均以训练正确性和恢复可靠性为前提。

## 4.4 训练框架与 AI SSD 之间的语义协同接口

第四项创新是定义训练框架到 AI SSD 的语义协同接口。接口内容包括数据类型、生命周期、访问模式、优先级、可重算性、持久化要求和建议 I/O 形态。该接口不依赖具体 SSD 内部实现，但能够为 AI SSD 底层优化提供训练语义来源。

接口采用分阶段设计。第一阶段以 sidecar metadata、目录约定和 trace 文件实现，确保没有专用硬件接口时也能验证语义完整性；第二阶段通过训练框架插件或用户态库在 I/O 发起时携带标签；第三阶段再结合 AI SSD 实际能力映射到底层接口。该路径既保证早期可落地，也为后续硬件协同保留空间。

接口字段区分必选字段和扩展字段。必选字段保证联合测试的最小可用性，扩展字段用于增强策略判断。字段设计避免绑定单一模型和单一设备，使接口可用于不同 Transformer 变体、不同并行策略和不同 SSD 实现。

## 4.5 基于 PyTorch/DeepSpeed 的可验证原型系统

第五项创新是构建可验证原型系统，而不是停留在概念设计。原型系统基于 PyTorch 和 DeepSpeed，能够运行典型 Transformer 模型，生成生命周期报告和 I/O 报告，并对比默认训练策略和 SSD 友好策略的差异。

原型系统包括生命周期 Profiler、数据分类与标注模块、SSD 友好调度模块、语义接口输出模块和实验评估模块。各模块既可组合运行，也可独立输出报告，便于分阶段验证。原型系统支持策略开关和 baseline 对比，使同一训练任务能够在原生策略、DeepSpeed 默认策略和本方案策略之间切换。

该系统的价值在于可展示、可测试、可迭代。通过 trace、元数据、指标报告和恢复测试，方案能够证明策略是否减少小写和无效写入，是否降低关键路径等待，是否保持训练正确性。

---

# 5 实施计划

## 5.1 第一阶段：训练数据生命周期分析与需求建模

第一阶段完成实验环境搭建、模型选择、插桩工具开发和生命周期分析。验证对象可选取 GPT、BERT、T5 或 LLaMA-like 小中型模型，基于 PyTorch 和 DeepSpeed 采集参数、梯度、优化器状态、activation 和 checkpoint 的生命周期信息。阶段输出包括 Profiler 原型、数据分类模型初稿。

本阶段重点是建立可信观测基础。先在可控规模模型上验证 hook、profiler 和 I/O trace 是否能够稳定采集数据，再逐步引入 DeepSpeed ZeRO 和 NVMe Offload 配置。采集内容包括对象大小、产生阶段、释放阶段、重用距离、读写次数、是否进入 checkpoint、是否可重算以及是否参与训练关键路径。第一阶段重点不在性能提升，而在观测准确性、分类覆盖率和报告可复现性。

## 5.2 第二阶段：SSD 友好训练调度方法研发

第二阶段完成训练侧调度策略设计与实现。重点研发参数预取策略、优化器状态 fixed shard 策略、activation ring buffer 策略、checkpoint 异步顺序写策略和日志缓冲策略。阶段输出包括调度模块、策略配置文件、DeepSpeed 适配扩展和初步性能对比结果。

本阶段以第一阶段的数据画像为依据，优先处理对 SSD 压力和训练稳定性影响最大的数据流。Optimizer state 重点减少小块和频繁覆盖写；activation 重点建立“重算、保留、SSD offload”三选一策略；checkpoint 重点降低突发写入对训练主循环的阻塞；日志和 profile 重点控制高频小写。

调度模块先采用规则驱动方式，确保策略可解释、可开关、可回归测试。典型规则包括：可重算 activation 优先重算；大尺寸且重用距离较长的 activation 才进入 ring buffer；optimizer state 采用 fixed shard 或批量写回；checkpoint 采用分片异步顺序写；log/profile 采用缓冲采样。随后在 profiler 数据基础上加入代价模型，动态调整阈值和优先级。

## 5.3 第三阶段：AI SSD 语义接口与协同机制研发

第三阶段完成语义接口定义和联合调试机制建设。训练侧输出数据类型、生命周期、访问模式和优先级标签，并与 AI SSD 侧能力对接接口格式、字段含义和测试流程。阶段输出包括接口规范、元数据样例、联合测试脚本和语义标签覆盖率报告。

本阶段将训练侧分类和调度结果转化为可使用接口。接口规范明确字段名称、字段类型、取值范围、生成时机和对应数据流。元数据样例覆盖 optimizer state、activation、checkpoint、dataset cache 和 log/profile 等典型对象，避免接口只对单一数据类型有效。

验证采用分层方式。首先通过离线 trace 验证语义字段是否能被解析；其次通过训练运行时日志验证标签生成是否稳定；最后在具备条件时通过用户态库、驱动或设备接口进行联调。该路径能够保证接口在不同硬件条件下都有可验证成果。

## 5.4 第四阶段：系统集成与实验验证

第四阶段完成系统集成和综合验证。系统集成将 Profiler、分类器、调度模块、语义接口和评估脚本串联为完整流程。实验流程包括环境初始化、baseline 训练、策略训练、trace 采集、指标统计、checkpoint 恢复验证和结果报告生成。对于每项策略，应说明启用条件、配置参数、适用数据流和可能代价。

实验验证覆盖功能正确性、性能影响和 SSD 友好性三类内容。功能正确性包括训练是否可运行、loss 是否正常下降、checkpoint 是否可恢复；性能影响包括 tokens/s、step time 和显存峰值；SSD 友好性包括 Host writes、请求大小分布、小随机写比例、checkpoint stall 和 offload wait time。对于无法在当前环境完成的硬件侧指标，应明确说明原因，并以 trace 或软件统计作为替代输入。

表 13 给出阶段计划与成果。

| 阶段 | 主要任务 | 关键成果 | 验证重点 |
|---|---|---|---|
| 第一阶段 | 生命周期采集与建模 | Profiler、分类模型初稿 | 能否识别主要训练数据 |
| 第二阶段 | SSD 友好调度研发 | Offload 调度模块 | 是否减少小写和无效写 |
| 第三阶段 | 语义接口研发 | 接口规范、测试样例 | 标签是否可解析、可统计、可对接 |
| 第四阶段 | 系统集成验证 | 原型系统、实验报告 | 训练性能、正确性和 SSD 友好性 |
