
## 技术方案

## 0 编制说明

本技术方案围绕 AI SSD 在大模型训练场景中的应用需求，研究训练算法与训练框架如何生成更适合 SSD 处理的数据访问模式。方案重点不在 SSD 控制器或固件实现，而在 PyTorch、DeepSpeed、ZeRO、Activation 管理、Checkpoint 管理和训练数据调度等上层训练系统中识别训练数据对象，分析其生命周期、读写模式、可重算性和访问优先级，并据此设计 SSD 友好的 Offload、预取、写回、Checkpoint 和 I/O 组织方法。

大模型训练中的 SSD 适配不能简单理解为“把数据写入 SSD”。真实训练系统中，参数、梯度、优化器状态、激活值、Checkpoint、数据集缓存和日志/Profile 数据具有不同的生命周期和访问模式。若训练框架不区分这些对象，而是以普通文件或无语义块 I/O 的方式混合写入 SSD，将导致训练侧难以控制小随机写、临时写、重复写和 Checkpoint 突发写对训练吞吐的影响，SSD 侧也难以区分短生命周期数据、长期训练状态和持久化恢复数据。

本方案的核心思路是将训练数据由“无差别 I/O 请求”提升为“带训练语义的数据流”。训练侧负责识别数据对象、输出语义标签、组织 I/O 形态、控制调度优先级，并提供可复现实验指标；AI SSD 侧可基于这些信息开展放置、调度、缓存和寿命相关优化。方案中涉及的性能收益均以实验测量和可复现 trace 为依据，不使用未经验证的绝对提升承诺。

---

# 1 发展现状（研究现状）

## 1.1 大模型训练对存储系统的新需求

### 1.1.1 显存容量瓶颈与分层存储趋势

以 Transformer 为核心架构的大模型训练已经从单纯计算密集型任务演进为计算、显存、内存、存储和互连共同受限的复杂系统任务。训练过程中，GPU 显存不仅需要容纳模型参数，还需要容纳前向传播产生的激活值、反向传播产生的梯度、优化器状态、混合精度训练中的 FP32 master weight、通信缓冲区以及框架运行时产生的临时张量。Adam 和 AdamW 等优化器通常需要为每个参数维护一阶矩和二阶矩，在混合精度训练中还可能保留 FP32 权重副本，使训练状态规模显著大于模型参数本身。

随着参数规模、序列长度和 batch size 增长，单卡 GPU 显存容量逐渐成为训练系统瓶颈。为缓解该问题，业界和学术界提出了模型并行、流水线并行、张量并行、ZeRO 分片、Activation Checkpointing、CPU Offload 和 NVMe Offload 等技术。DeepSpeed ZeRO 系列通过分片优化器状态、梯度和参数降低单卡冗余显存占用；ZeRO-Infinity 进一步将 NVMe SSD 纳入 GPU、CPU、NVMe 组成的异构内存层级，说明 SSD 可作为大模型训练容量扩展的重要组成部分。

SSD 进入训练运行时后，问题从“是否有足够容量”进一步扩展为“数据以什么形态进入 SSD”。大模型训练中的 SSD 适配需要同时考虑训练正确性、显存占用、训练吞吐、I/O 等待、写入粒度、写入频率和数据生命周期。训练侧若能提前提供数据语义，SSD 侧才有可能区分临时 activation、长期 optimizer state、低频 checkpoint 和读密集 dataset cache。

表 1 给出了典型训练数据对象及其存储适配关注点。

| 序号 | 数据对象 | 产生阶段 | 生命周期特征 | 压力来源 | SSD 适配关注点 |
|---|---|---|---|---|---|
| 1 | 模型参数 | 初始化后长期存在 | 贯穿训练过程 | 参数规模随模型增大增长 | 分片、预取、按层访问、冷热区分 |
| 2 | 梯度 | 反向传播阶段 | 从 backward 到 optimizer step | 与参数规模接近 | 优先避免高频短生命周期 SSD 写入 |
| 3 | 优化器状态 | 优化器初始化后长期存在 | 周期更新 | Adam/AdamW 状态规模大 | fixed shard、批量写回、缓存 |
| 4 | 激活值 | 前向传播阶段 | forward 产生、backward 消费 | 长序列和深层模型下占用显著 | 重算优先、选择性 offload、ring buffer |
| 5 | Checkpoint | 周期保存阶段 | 按版本持久化 | 单次写入规模大 | 分片、大块顺序写、异步写、版本管理 |
| 6 | 数据集缓存 | 数据加载阶段 | 跨 step 或 epoch 存在 | 读吞吐影响 GPU 供数 | 预取、缓存布局、读多写少 |
| 7 | 日志/Profile | 训练监控阶段 | 可丢弃或短期保留 | 高频小写干扰主训练流 | 缓冲、采样、低优先级写入 |

### 1.1.2 训练 I/O 瓶颈与关键路径耦合

大模型训练的 I/O 瓶颈主要来自四类路径：训练数据加载、训练状态迁移、Checkpoint 保存和日志/Profile 输出。数据加载负责持续向 GPU 提供 batch 输入，若读取吞吐不足，GPU 会出现供数等待；训练状态迁移负责在 GPU、CPU 与 SSD 之间移动参数、优化器状态和 activation，若预取不及时或写回阻塞，会直接增加 step time；Checkpoint 具有低频、大块、突发写入特征，若与 Offload 流共享同一路径，可能形成 I/O 峰值冲击；日志和 Profile 单次规模较小，但高频小写和元数据更新会在长时间训练中形成干扰。

与传统离线存储不同，训练 I/O 与 GPU 计算存在强耦合关系。SSD 的理论吞吐只有在数据迁移能够与计算重叠时才可能转化为训练收益。对于参数和优化器状态 Offload，训练框架必须在数据被使用前完成预取，并在使用完成后及时释放或写回。对于 Activation Offload，训练框架需要比较保存到 SSD 的代价与重新计算的代价。对于 Checkpoint，训练框架需要尽量将写入从训练关键路径中移出，并保证恢复正确性。

表 2 对比了几类典型训练 I/O 流。

| I/O 流类型 | 主要数据 | 读写特征 | 关键路径关系 | 主要风险 | 优化方向 |
|---|---|---|---|---|---|
| Dataset Read | tokenized dataset、样本索引 | 读密集，部分随机读 | 通常在关键路径上 | GPU 等待数据 | 预取、缓存、顺序化读取 |
| Parameter Prefetch | 参数分片 | 按 layer 读取 | 关键路径 | 预取不及时 | 提前量控制、分层缓存 |
| Optimizer State Offload | Adam m/v、master weight | 周期读写 | optimizer step 相关 | 状态读写拖慢 step | fixed shard、批量写回 |
| Activation Offload | 中间激活值 | 写一次读一次 | 部分关键 | 高频临时写 | 选择性 offload、ring buffer、重算 |
| Checkpoint Write | 模型与优化器状态 | 低频大块写 | 可异步化 | 突发写影响训练 | 分片、异步、大块顺序写 |
| Log/Profile Write | 日志、trace | 高频小写 | 非关键 | 元数据和小写干扰 | 缓冲、采样、低优先级 |

### 1.1.3 SSD 在训练系统中的角色变化

SSD 在大模型训练中的角色正在从“数据集存储介质”和“Checkpoint 保存介质”扩展为“训练状态容量扩展层”和“训练语义承载层”。传统训练流程中，SSD 主要用于保存训练语料和模型 Checkpoint，GPU 计算所需的中间状态主要驻留在 HBM 或 CPU DRAM 中。随着模型规模增长，CPU 内存和 SSD 被逐步纳入训练运行时，使训练系统能够在显存不足时继续运行更大模型或更长序列。

DeepSpeed ZeRO-3 支持参数和优化器状态向 CPU 或 NVMe Offload，ZeRO-Infinity 将 GPU、CPU 和 NVMe 组织为异构内存层级。PyTorch Distributed Checkpoint 面向分布式训练提供并行保存、加载和 resharding 能力。NVIDIA GPUDirect Storage 和 RAPIDS KvikIO 从 GPU 与存储高效数据通路角度优化大规模数据访问。SSDTrain 等研究说明 activation 也可通过 hook、预取和计算重叠机制向 SSD 卸载。这些工作共同说明，训练系统与 SSD 的关系已经从简单文件读写转向计算、显存和存储协同。

SSD 本身仍是具有写入约束的持久化介质。写入粒度、随机性、覆盖写、冷热数据混放和垃圾回收会影响性能与寿命。AI SSD 的价值在于利用存储侧能力适配 AI 负载，但训练侧必须提供明确语义，避免让底层从普通读写请求中被动推断数据含义。

## 1.2 大模型训练框架与存储适配技术现状

### 1.2.1 PyTorch 训练框架现状

PyTorch 是大模型训练最主要的框架之一，其动态图机制、自动求导机制和丰富的 GPU 后端支持使其成为研究和工程训练系统的共同基础。PyTorch autograd 在前向传播过程中保存反向传播所需的中间张量，并在 backward 阶段读取这些保存张量计算梯度。这一机制使 PyTorch 成为观察 activation 生命周期的天然入口。

PyTorch 提供 module hook、parameter hook、torch.profiler、saved_tensors_hooks 等工具，能够在不改变模型数学定义的前提下采集训练过程中的张量元数据。通过 forward hook 可以获得模块输出 activation 的 shape、dtype、device 和大小；通过 gradient hook 可以获得参数梯度产生时间和规模；通过 saved_tensors_hooks 可以观察 autograd 保存和取回的中间张量；通过 optimizer state_dict 可以分析优化器状态结构；通过 profiler 可以记录 step 内算子、显存和时间开销。

PyTorch 原生 Tensor 管理主要关注设备间拷贝和自动求导正确性，并不会自动输出 SSD 写入粒度、生命周期标签或 AI SSD 语义接口。因此，本方案需要在 PyTorch 之上构建 Profiler、分类器和调度模块，将框架内部可见的训练语义提取出来，并转化为 SSD 友好的访问策略。

### 1.2.2 DeepSpeed 与 ZeRO 系列技术现状

DeepSpeed 是面向大模型训练的系统级优化框架，ZeRO 系列技术是当前具有代表性的训练状态分片机制。ZeRO-1 分片优化器状态，ZeRO-2 在此基础上分片梯度，ZeRO-3 进一步分片模型参数。通过逐步消除数据并行副本中的冗余状态，ZeRO 显著降低单卡显存压力。ZeRO-Offload 和 ZeRO-Infinity 将训练状态迁移至 CPU 或 NVMe，从而进一步扩大可训练模型规模。

ZeRO-Infinity 的重要意义在于证明 NVMe SSD 可以参与大模型训练运行时，而不仅是保存训练数据和 Checkpoint。它通过异构内存调度、数据预取和带宽重叠机制，在 GPU、CPU 和 NVMe 之间管理模型状态。现有 DeepSpeed Offload 配置通常以 offload device、nvme_path、buffer_count、buffer_size、max_in_cpu 等参数为核心，强调数据是否放入 NVMe 以及如何配置缓冲区，但没有直接表达“该写入属于 optimizer state”“该数据短生命周期”“该 Checkpoint 可后台保存”“该 activation 可重算”等训练语义。

本方案将在 DeepSpeed 默认 NVMe Offload 基础上分析其 I/O 模式，并增加语义分类、写入组织、调度优先级和元数据输出能力，使训练状态 Offload 不只是容量扩展机制，也成为可被 AI SSD 利用的语义化数据流。

### 1.2.3 Activation 管理与 Offload 技术现状

Activation 是 Transformer 训练中显存占用的重要来源，尤其在长序列、多层网络和大 batch size 场景中，前向传播保存的中间张量可能带来显著显存压力。Activation Checkpointing 通过减少保存中间结果并在反向传播时重新计算，以额外计算换取显存节省。Activation Offload 则通过将部分中间结果迁移到 CPU 或 SSD，降低 GPU 常驻激活值规模。

FlashNeuron 和 SSDTrain 是 Activation SSD Offload 的代表性研究。SSDTrain 针对大语言模型训练提出将 activation offload 到 NVMe SSD，并通过 PyTorch hook、预取、计算与 I/O 重叠、张量转发和去重等机制降低开销。相关研究证明 activation 写入 SSD 具有可行性，同时也说明短生命周期数据高频写入会带来写入压力和调度挑战。

本方案不将 Activation Offload 作为孤立问题处理，而是把 activation 放入参数、优化器状态、Checkpoint、数据集缓存和日志共同构成的训练数据分类体系中。对于 activation，默认策略不是“能写就写”，而是根据大小、重用距离、可重算性、显存压力和 SSD 负载进行选择：可重算且代价低的数据优先重算，必须保存且规模较大的数据才进入 SSD 临时缓冲，并采用 ring buffer 降低文件系统和写入碎片开销。

### 1.2.4 Checkpoint 优化技术现状

Checkpoint 是大模型训练可靠性的基础。大规模训练任务通常运行时间长、资源昂贵，硬件故障、通信异常或软件错误都可能导致训练中断，因此需要定期保存可恢复状态。Checkpoint 内容不仅包括模型参数，还包括优化器状态、学习率调度器状态、随机数状态和分布式训练元数据。随着模型和并行规模增大，Checkpoint 文件数量、单次写入规模和恢复复杂度显著增加。

PyTorch Distributed Checkpoint 面向分布式训练提供并行保存和加载能力，并支持在不同并行拓扑之间进行状态重新分片。DeepSpeed 也提供面向 ZeRO 分片训练的 Checkpoint 能力。现有优化方向包括异步 Checkpoint、增量 Checkpoint、分片 Checkpoint 和快速恢复，目标是降低 Checkpoint 对训练主循环的阻塞。

本方案将 Checkpoint 作为独立数据流处理，而不是将其与训练状态 Offload 混为一类。Checkpoint 的低频、大块、持久化特征适合大块顺序写；Activation 的短生命周期与 Optimizer State 的周期更新具有完全不同的 I/O 规律。因此，训练框架应为 Checkpoint 设置独立调度策略，避免其与关键路径 Offload 争用 SSD 带宽，并通过元数据提示持久化级别和可靠性要求。

## 1.3 现有方案不足与本方案切入点

现有训练框架和系统使用 SSD 的方式主要包括训练数据读取、Checkpoint 持久化和训练状态 Offload。DeepSpeed 支持 NVMe Offload，PyTorch Distributed Checkpoint 支持分布式状态保存，NVIDIA GPUDirect Storage 和 KvikIO 优化 GPU 与存储之间的数据通路，SSDTrain 和 FlashNeuron 关注 Activation Offload，BaM 和 G10 探索 GPU 与存储之间更直接或统一的访问架构。这些工作提供了重要基础，但多数方案仍以“训练框架使用 SSD”为主，尚未充分解决“训练框架如何适配 AI SSD”的问题。

不足主要体现在四个方面。第一，训练数据缺乏统一语义分类。参数、梯度、优化器状态、Activation、Checkpoint、数据集缓存和日志在训练框架内部是不同对象，但在存储层往往表现为普通文件读写。第二，Offload 策略主要关注显存和吞吐，对 SSD 写入粒度、生命周期隔离和写入削减关注不足。第三，多类 I/O 流之间缺少协调，Checkpoint 写入、Activation 临时写入、Optimizer State 更新和 Dataset Read 可能同时争用 SSD。第四，缺少面向 AI SSD 的接口规范，训练侧拥有语义但缺少稳定方式传递给底层。

表 3 总结现有方向与本方案切入点。

| 方向 | 代表技术或系统 | 已解决问题 | 仍存在不足 | 本方案切入点 |
|---|---|---|---|---|
| ZeRO/ZeRO-Infinity | DeepSpeed | 训练状态分片与 Offload | 语义标签和 SSD 友好性不足 | 增加语义分类和调度策略 |
| Activation Offload | FlashNeuron、SSDTrain | 降低 activation 显存占用 | 主要关注单类数据 | 放入多类训练数据统一调度框架 |
| Checkpoint 优化 | PyTorch DCP、DeepSpeed Checkpoint | 分布式保存和恢复 | 与 Offload 流协同不足 | 独立调度并提供持久化语义 |
| GPU-Storage 通路 | GDS、KvikIO、BaM | 提升数据移动效率 | 不直接解决训练数据分类 | 与训练语义调度结合 |
| SSD 放置优化 | FDP、ZNS、多流写入 | 支持主机侧放置提示 | 缺少训练框架语义来源 | 输出类型、生命周期和优先级标签 |

---

# 2 需求分析（研究目的及意义）

## 2.1 项目背景与核心问题

![[2.1.png]]

大模型训练已经形成 GPU HBM、CPU DRAM、NVMe SSD 和远端存储共同组成的多级存储体系。GPU HBM 带宽高、延迟低但容量有限；CPU DRAM 容量较大但与 GPU 间传输受 PCIe/NVLink 等通路限制；NVMe SSD 容量大、成本低并具备持久化能力，但延迟高于内存且存在写入寿命约束；远端存储适合归档和共享，但不适合训练关键路径上的高频访问。训练算法必须根据数据对象的访问特征决定其所在层级，不能只依据容量大小进行放置。

本方案要解决的核心问题可以概括为：训练框架如何把内部可见的训练语义转化为 SSD 可利用的数据流。具体包括：哪些数据适合进入 SSD，哪些数据应留在 GPU 或 CPU，哪些数据应通过重算替代保存，哪些数据必须持久化保存；进入 SSD 的数据应以什么粒度、顺序、优先级和生命周期标签写入；训练侧如何输出可验证、可统计、可联调的语义元数据。

表 4 描述训练存储层级和适合承载的数据。

| 存储层级     | 主要优势       | 主要限制        | 适合承载的数据                  | 训练侧策略        |
| -------- | ---------- | ----------- | ------------------------ | ------------ |
| GPU HBM  | 带宽高、延迟低    | 容量有限、成本高    | 当前计算所需参数、activation、梯度   | 保留关键路径数据     |
| CPU DRAM | 容量较大、访问较快  | GPU 传输受通路限制 | 热状态缓存、Offload staging    | 作为中间缓存层      |
| NVMe SSD | 容量大、持久化    | 延迟高、写入受限    | 冷参数、优化器状态、Checkpoint、数据集 | 大块化、顺序化、语义标注 |
| 远端存储     | 容量可扩展、便于共享 | 延迟高、依赖网络    | 归档 Checkpoint、大数据集       | 异步传输、本地缓存    |

## 2.2 研究需求

![[2.2.png|697]]
### 2.2.1 训练数据分类需求

训练数据分类是后续调度的前提。没有分类，就无法判断哪些数据适合 SSD，哪些数据应留在 GPU 或 CPU，哪些数据应重算，哪些数据可延迟写入。分类不仅要基于数据名称，还要基于生命周期、大小、访问频率、可重算性、可靠性要求和关键路径关系。

分类模型需要覆盖训练运行时的主要对象，并兼容 PyTorch、DeepSpeed 和 ZeRO 等常用训练栈。对于 PyTorch，可利用 module hook、parameter hook、saved_tensors_hooks 和 profiler 采集对象来源与生命周期；对于 DeepSpeed，可分析 ZeRO-3、CPU/NVMe Offload、buffer 管理和 checkpoint 保存过程中的数据流；对于 activation，可参考 SSDTrain 的 hook 与预取思路，同时加入生命周期标签、可重算判断和写入削减策略。

表 5 给出训练数据分类维度。

| 分类维度 | 可选取值 | 说明 | 对调度的影响 |
|---|---|---|---|
| 数据类型 | parameter、gradient、optimizer_state、activation、checkpoint、dataset_cache、log_profile | 表示训练语义 | 决定默认策略 |
| 生命周期 | temporary、short_lived、long_lived、persistent | 表示存活时间 | 决定隔离、回收和持久化策略 |
| 访问模式 | read_heavy、write_heavy、read_write、append_only、write_once_read_once | 表示读写规律 | 决定写入组织和预取方式 |
| 可重算性 | recomputable、non_recomputable | 表示能否用计算替代保存 | 决定是否减少 SSD 写入 |
| 关键性 | critical、delayable、discardable | 表示对训练主路径影响 | 决定 I/O 优先级 |
| 数据规模 | small、medium、large、huge | 表示写入粒度 | 决定合并、分片或直接保留 |

### 2.2.2 训练数据调度需求

训练数据调度需要在显存、吞吐和 SSD 写入压力之间做权衡。如果显存充足，过度 Offload 会增加不必要 I/O；如果显存不足，不 Offload 会导致 OOM；若重算过多，会增加 GPU 计算时间；若写 SSD 过多，会增加 I/O 等待和写入压力。因此，调度策略必须基于运行时状态和数据语义进行决策。

调度策略至少需要回答四个问题：数据是否进入 SSD；何时写入 SSD；以何种粒度和顺序写入；何时预取回 GPU 或 CPU。对于参数，依据是 layer 执行顺序、显存压力和缓存命中；对于优化器状态，依据是 optimizer step 的更新窗口和分片布局；对于 activation，依据是 backward 重用距离、重算代价和显存峰值；对于 checkpoint，依据是保存周期、异步写入能力和恢复可靠性。

调度模块还需要具备降级机制。当 SSD 队列积压或 checkpoint 写入占用带宽时，activation offload 应减少或推迟；当 GPU 显存压力上升时，选择性 offload 可提高优先级；当日志或 profile 写入影响主循环时，应转为采样或缓冲输出。该机制能够提高长时间训练过程中的稳定性。

### 2.2.3 训练方法适配 SSD 需求

训练方法适配 SSD 的核心是改变训练侧数据输出形态。传统训练框架中的很多写入是按对象自然产生的，例如一个 Tensor 保存一次、一个状态文件写一次、一个日志事件写一次。这种方式便于实现，但不一定适合 SSD。方案需要将这些自然产生的数据流重新组织为 SSD 友好的数据流。

小 Tensor 写入应合并为大 block；短生命周期数据应进入可复用缓冲区；长期状态应按固定分片组织；Checkpoint 应采用分片顺序写；日志应缓冲后异步写。训练侧还应避免多个大规模 I/O 流在同一时间集中发生，例如 Checkpoint 保存应与 optimizer state 高峰写回错峰，日志写入应降低优先级，dataset prefetch 应与 activation offload 进行带宽隔离或限速。

适配策略不改变模型数学定义、损失函数或优化目标。所有策略都以保持训练正确性为前提，优先作用于数据放置、保存、预取、写回和元数据标注。Checkpoint 等可靠性关键数据必须保留完整性校验和恢复验证；Activation 等临时数据只有在读取时机和复用规则清晰时才进入 SSD 缓冲；Optimizer state 必须保证分片映射和更新顺序与训练框架一致。

### 2.2.4 与 AI SSD 协同需求

AI SSD 需要训练侧提供可解释、可记录、可测试的语义信息。训练侧不能只输出读写量，还要输出这些数据的类型、生命周期、访问模式、优先级、可重算性和可靠性要求。协同接口可采用分阶段方式建设：早期通过目录约定、sidecar JSON 元数据、I/O trace 和离线报告验证语义字段；中期通过用户态库或训练框架插件在 I/O 发起时携带标签；后期根据 AI SSD 的接口能力映射到底层设备或驱动机制。

表 6 给出训练语义提示示例。

| 提示类别 | 示例标签 | 典型数据 | 可能用途 |
|---|---|---|---|
| 数据类型 | optimizer_state | Adam m/v | 与短生命周期数据区分放置 |
| 生命周期 | short_lived | activation offload | 临时区管理、快速回收 |
| 访问模式 | append_only | checkpoint | 顺序写、版本管理 |
| 优先级 | critical | 参数预取、activation 取回 | 降低关键路径排队时间 |
| 可丢弃性 | discardable | debug log、profile trace | 延迟处理或低优先级处理 |
| 可靠性 | persistent | checkpoint | 持久化和一致性保障 |

## 2.3 研究目的

本方案的目标是建立一套从训练数据识别、生命周期建模、SSD 友好调度到 AI SSD 语义接口的完整方法。具体包括：构建面向 AI SSD 的训练数据语义分类模型；设计 SSD 友好的 Offload、预取、写回和 Checkpoint 调度方法；优化训练过程中的 I/O 访问模式；降低无效写入、小随机写和关键路径 I/O 等待；建立训练框架与 AI SSD 之间的语义协同接口机制。

这些目标共同服务于一个原则：在不改变模型结构和训练目标的情况下，让训练系统更可观测、更可调度、更适合 SSD。方案不以“尽量写入 SSD”为目标，而是在显存、计算和 I/O 之间进行选择。可重算 activation 优先重算，长期 optimizer state 采用分片和批量写回，checkpoint 采用异步分片顺序写，日志和 profile 采用缓冲与采样，数据集缓存采用预取和读缓存。

目标验证采用同环境 baseline 对比。对比对象包括 PyTorch 原生策略、DeepSpeed 默认 NVMe Offload 策略和本方案策略。评价指标包括 tokens/s、step time、GPU memory peak、Host writes、Small write ratio、Average write size、Checkpoint stall、Offload wait time 和 Tag coverage。所有结论以可复现实验和 trace 为依据。

## 2.4 研究意义

本方案对大模型训练的意义在于提升训练系统资源使用的可控性。通过数据分类和调度，有限 GPU 显存可以承载更大模型、更长序列或更大 batch size；通过 SSD 友好 I/O 组织，训练系统可以降低因 Offload 和 Checkpoint 带来的吞吐损失；通过语义化调度，训练过程可以减少 I/O 随机性和抖动，提高长时间训练稳定性。

对 AI SSD 应用而言，训练侧输出的数据分类、生命周期提示和访问模式报告能够提供更接近真实训练负载的输入。相比通用 fio 或普通文件读写测试，训练语义 trace 能体现 activation、optimizer state、checkpoint、dataset cache 和 log/profile 等不同数据流的差异，为设备侧放置、调度、缓存和寿命相关优化提供依据。

对软硬件协同而言，该方案建立了训练算法侧与 AI SSD 侧之间的共同语言。训练侧说明数据含义、访问规律和调度意图；存储侧反馈设备统计、瓶颈现象和接口约束；双方基于统一 trace 和元数据迭代策略，使模型训练到存储设备之间形成端到端优化链路。

---

# 3 关键技术方案

## 3.1 总体技术路线

### 3.1.1 技术路线概述

总体技术路线采用“采集分析、语义建模、策略生成、框架适配、实验验证”的流程。首先，在 PyTorch 和 DeepSpeed 训练流程中插桩，采集参数、梯度、优化器状态、activation、checkpoint、dataset cache 和日志/Profile 数据的生命周期与 I/O 行为。其次，基于采集结果建立训练数据语义分类模型，形成数据类型、生命周期、访问模式、优先级、可重算性和持久化要求等标签。再次，根据分类结果设计 SSD 友好的 Offload、Prefetch、Write-back、Checkpoint 和日志管理策略。最后，将策略集成到训练框架中，并通过普通 NVMe SSD、软件 trace 和可用的 AI SSD 接口开展验证。在 AI SSD 接口明确后，可将训练语义标签映射到用户态库、驱动或设备接口；在联合测试中，可根据设备反馈调整调度阈值和 I/O 组织方式。

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

### 3.1.3 数据流闭环

训练数据流从对象产生开始进入闭环。模型 forward 产生 activation，参数参与计算，optimizer state 在 optimizer step 中更新，checkpoint 在保存周期触发，dataset cache 在数据加载时被读取，日志/Profile 在训练过程中追加。Profiler 记录对象元数据和事件顺序，分类模块为对象生成标签，调度模块基于标签和资源状态选择策略，I/O 模块执行实际读写并输出 trace，评估模块再将结果反馈给分类阈值和调度策略。

闭环中包含两类反馈。第一类是训练侧反馈，例如显存峰值、step time、offload wait time、checkpoint stall 和 GPU utilization；第二类是存储侧反馈，例如 Host writes、请求大小分布、小写比例、队列深度和设备延迟。两类反馈共同决定后续策略是否需要调整。若 SSD 队列积压，则降低可延迟写入优先级；若显存峰值接近 OOM，则提高可安全 offload 数据的比例；若 checkpoint stall 明显，则调整 checkpoint 异步写和带宽限制。


## 3.2 大模型训练数据生命周期分析技术

### 3.2.1 训练数据类型识别

训练数据类型识别覆盖 Tensor 对象和文件对象两类数据。Tensor 对象包括模型参数、梯度、优化器状态和 activation；文件对象包括 checkpoint、dataset cache、日志和 profile 文件。Tensor 对象通过 PyTorch 和 DeepSpeed 插桩采集，文件对象通过训练框架回调、路径规则、I/O 日志和系统监控采集。

每个数据对象生成统一描述，字段包括 object_id、name、data_type、layer_id、rank_id、shape、dtype、size_bytes、device、created_at、last_used_at、access_count、read_write_pattern、recomputable、criticality 和 persistence。统一描述用于支撑分类、调度和接口输出。

对象识别需处理别名和共享存储问题。PyTorch 中多个 Tensor 对象可能指向同一底层 storage，activation 可能被 view、slice 或 reshape 形成多个引用。Profiler 应基于 storage id、shape、dtype、创建时间和层级上下文建立对象唯一标识，避免重复统计和重复写入。SSDTrain 中针对张量标识和去重的设计表明，activation offload 若不处理标识冲突，可能产生冗余 I/O 或错误读取。

### 3.2.2 Tensor 生命周期采集方法

Tensor 生命周期采集分为模型层、autograd 层、优化器层、DeepSpeed 层和系统 I/O 层。模型层通过 forward hook 采集模块输出 activation；autograd 层通过 saved_tensors_hooks 采集保存和取回事件；参数层通过 parameter hook 采集梯度产生；优化器层采集 optimizer state 初始化和更新；DeepSpeed 层采集 ZeRO 分片参数、分片优化器状态、NVMe Offload buffer 和状态迁移事件；系统层采集文件写入、SSD 读写量和 I/O 延迟。

表 8 给出生命周期采集方法。

| 层级             | 采集对象            | 采集方法                     | 采集信息                            |
| -------------- | --------------- | ------------------------ | ------------------------------- |
| PyTorch Module | activation      | forward hook             | shape、dtype、size、layer、device   |
| Autograd       | saved tensor    | saved_tensors_hooks      | 保存时间、取回时间、大小、重用距离               |
| Parameter      | gradient        | parameter hook           | 梯度产生时间、大小、所属参数                  |
| Optimizer      | optimizer state | state_dict 或内部状态         | m/v/master weight 大小和更新窗口       |
| DeepSpeed ZeRO | shard state     | DeepSpeed engine 状态      | 分片参数、offload buffer、prefetch 事件 |
| Checkpoint     | 状态文件            | framework callback       | 文件大小、写入时间、版本信息                  |
| 系统 I/O         | SSD 请求          | iostat、nvme-cli、eBPF 或日志 | 读写量、请求大小、延迟、队列深度                |

采集开销必须受控。方案采用只记录元数据、不复制数据内容、按 step 聚合、按 layer 采样、异步写日志和开关化采集等方式降低 overhead。Profiler 默认不记录 Tensor 内容，只记录类型、大小、设备、层级、时间戳和事件关系。对于高频事件，可采用采样或窗口聚合方式，避免 profiler 本身成为训练瓶颈。

### 3.2.3 生命周期特征建模

生命周期建模将训练对象转化为可计算特征。通用特征包括 size_bytes、lifetime_steps、lifetime_layers、reuse_distance、read_count、write_count、write_frequency、critical_path_flag、recompute_cost_estimate 和 offload_candidate_flag。类型特定特征包括 activation 的 backward 重用距离、optimizer state 的 step 更新频率、checkpoint 的保存周期与版本保留时间、dataset cache 的命中率和顺序读比例、log/profile 的事件频率和可丢弃性。

生命周期特征用于离线分析，也用于在线调度。如果某个 activation 大小较大、反向重用距离较长且重算代价高，可考虑 SSD 临时缓冲；如果某个 activation 较小或容易重算，则避免写入 SSD；如果某个 optimizer shard 近期不会访问，可以延迟预取；如果 checkpoint 正在写入且 SSD 带宽占用高，则降低日志写入和可延迟 activation 写回优先级。

特征建模还应输出风险标记。例如，高频短生命周期写入标记为 write_pressure_risk；checkpoint 与 offload 时间重叠标记为 bandwidth_conflict_risk；大量小文件写入标记为 metadata_overhead_risk；频繁覆盖同一状态分片标记为 update_hotspot_risk。这些风险标记用于指导调度模块和实验分析。

### 3.2.4 训练数据语义分类模型

语义分类模型采用规则驱动和 profiling 反馈结合的方式。第一阶段使用可解释规则，便于实现和调试；第二阶段使用 profiler 统计调整阈值，例如 activation 大小阈值、重用距离阈值、SSD 带宽阈值和显存压力阈值。规则示例包括：checkpoint 默认归类为 persistent、append_only、large_write；activation 默认归类为 short_lived、write_once_read_once，并根据可重算性决定是否写入；optimizer state 默认归类为 long_lived、read_write、periodic_update；dataset cache 默认归类为 read_mostly。

表 9 给出分类与策略映射。

| 数据类别 | 生命周期标签 | 访问模式标签 | 默认策略 | SSD 友好组织方式 |
|---|---|---|---|---|
| Parameter | long_lived | read_heavy/read_write | 分层缓存、按需预取 | layer-wise shard |
| Gradient | short_lived | write_then_read | 优先 GPU/CPU 管理 | 谨慎 offload，聚合后写 |
| Optimizer State | long_lived | periodic_read_write | 分片 offload | fixed-size shard、批量写回 |
| Activation | short_lived | write_once_read_once | 重算优先，选择性 offload | ring buffer、预分配 slot |
| Checkpoint | persistent | append_only | 异步分片保存 | 大块顺序写、版本管理 |
| Dataset Cache | persistent/read_mostly | read_heavy | 预取与缓存 | 大文件 shard、mmap |
| Log/Profile | temporary/discardable | small_write | 缓冲与采样 | 批量追加、低优先级 |

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

### 3.5.1 接口目标与边界

语义提示接口的目标是把训练侧已经掌握的数据含义传递给 AI SSD 或中间层工具。接口不假设底层一定具备特定硬件能力，也不绑定单一 SSD 实现。早期可通过 sidecar metadata、路径约定和 trace 文件验证；具备条件后，可映射到用户态库、驱动接口或设备侧提示机制。

接口边界包括三点。第一，接口传递语义和建议，不改变训练数据内容。第二，接口不替代训练框架的正确性管理，checkpoint、optimizer state 等仍需由训练侧保证一致性。第三，接口字段应稳定、可扩展、可解析，避免过度依赖某一模型结构或框架内部命名。

### 3.5.2 数据类型与生命周期提示

数据类型提示包括 parameter、gradient、optimizer_state、activation、checkpoint、dataset_cache 和 log_profile。生命周期提示包括 temporary、short_lived、long_lived、persistent、append_only 和 read_mostly。二者共同用于区分临时数据、长期状态、持久化数据和读密集数据。

例如，activation offload 通常标注为 data_type=activation、lifecycle=short_lived、access_pattern=write_once_read_once；optimizer state 通常标注为 data_type=optimizer_state、lifecycle=long_lived、access_pattern=periodic_read_write；checkpoint 通常标注为 data_type=checkpoint、lifecycle=persistent、access_pattern=append_only 或 sequential_write。

### 3.5.3 访问模式与优先级提示

访问模式提示描述数据读写行为，包括 read_heavy、write_heavy、read_write、sequential_write、random_read、write_once_read_once 和 discardable。优先级提示用于减少关键路径等待，取值可包括 critical、high、normal、low 和 background。

参数预取、即将用于 backward 的 activation 读取、optimizer step 必需状态属于高优先级；checkpoint 后台写入、日志和可延迟 profile 属于较低优先级。调度器可在 SSD 负载高时优先保证 critical 和 high 数据，推迟 low 和 background 数据。

### 3.5.4 接口字段定义

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

字段可分为必选字段和扩展字段。必选字段包括 object_id、data_type、lifecycle、access_pattern、priority、size_bytes 和 persistence；扩展字段包括 recomputable、rank_id、layer_id、reuse_distance、suggested_io、version 和 checksum。早期验证可只实现必选字段，后续根据 AI SSD 能力扩展。

### 3.5.5 接口实现方式

接口实现分三阶段。第一阶段使用软件元数据文件和路径约定，例如不同数据类型写入不同目录，并为每个大块写入生成 JSON 元数据。第二阶段使用用户态库或训练框架插件，在 I/O 请求发起时附带标签。第三阶段根据 AI SSD 能力将标签映射到底层设备接口。

软件元数据样例可采用 JSON Lines，每条记录对应一个对象或大块 I/O。训练完成后，评估模块读取元数据与 I/O trace，统计标签覆盖率、不同数据流写入量、优先级分布和请求大小分布。若底层设备能够反馈统计信息，则将设备统计与训练侧标签关联，分析不同语义流的延迟、写入量和排队情况。

## 3.6 训练框架适配与原型系统实现

### 3.6.1 PyTorch 适配

PyTorch 适配围绕模型层、autograd 层和优化器层展开。模型层提供 hook 注册工具，自动记录模块输出、参数引用和 layer 信息；autograd 层通过 saved_tensors_hooks 捕捉 activation 保存和取回；优化器层采集 optimizer state 的结构、大小和更新时机。对于常见 Transformer 模型，适配模块提供 embedding、attention、MLP、LayerNorm、residual 和输出层的识别规则。

PyTorch 适配还需要支持 activation 管理策略。saved_tensors_hooks 可用于替换默认保存行为，将部分 activation 保存到 CPU、SSD 或标记为重算。策略模块根据 activation 大小、重用距离、可重算性和显存压力决定处理方式。为避免影响训练正确性，适配模块必须保证 backward 取回的 Tensor 与原始计算所需一致，并对异常情况提供回退路径。

### 3.6.2 DeepSpeed 适配

DeepSpeed 适配围绕 ZeRO-3 和 NVMe Offload 展开。方案分析 DeepSpeed 默认 Offload 的 I/O 行为，识别参数分片、优化器状态、NVMe buffer 和 checkpoint 的读写模式。在此基础上增加语义标签输出和 SSD 友好调度策略。对于 optimizer state，重点研究 fixed shard 和批量写回；对于 parameter，重点研究预取时机和分层缓存；对于 checkpoint，重点研究异步分片保存和与 Offload 流解耦。

DeepSpeed 适配应尽量以配置扩展和 wrapper 方式实现，避免深度修改框架核心。可通过 engine 状态读取分片信息，通过配置文件指定 offload 路径、buffer 大小、策略阈值和语义元数据输出路径。适配模块应保留关闭开关，使同一训练脚本能够在默认策略和本方案策略之间切换，便于 baseline 对比。

### 3.6.3 Profiler 工具实现

Profiler 工具输出训练数据生命周期报告和 I/O 行为报告。生命周期报告包括各类数据大小占比、生命周期分布、重用距离、可重算比例、显存贡献和进入 SSD 的比例。I/O 行为报告包括 SSD 读写量、请求大小分布、写入频率、checkpoint 峰值、offload 阻塞时间和日志写入开销。

Profiler 需要支持多粒度报告。step 级报告用于分析训练波动；layer 级报告用于识别 activation 和参数热点；rank 级报告用于分布式训练负载均衡；数据类型级报告用于判断不同语义流对 SSD 的压力。报告应同时输出 Markdown/CSV/JSON，方便人工阅读和后续脚本处理。

### 3.6.4 调度策略模块实现

调度策略模块第一阶段采用规则驱动方式。典型规则包括：checkpoint 使用顺序异步写；activation 大于阈值、不可重算且重用距离较长时进入 ring buffer；optimizer state 使用 fixed shard；log/profile 采用缓冲采样；参数按 layer 执行顺序预取。第二阶段引入代价模型，根据显存压力、SSD 当前负载、数据大小和重用距离动态调整策略。

调度模块需要维护资源状态，包括 GPU memory pressure、CPU cache occupancy、SSD queue pressure、checkpoint_active、offload_wait_time 和 data_loader_wait_time。策略选择不是静态开关，而是根据状态进行动态降级或升级。例如，当 checkpoint_active 为真且 SSD queue pressure 高时，低优先级日志延迟写入，activation offload 阈值提高；当 GPU memory pressure 高时，activation offload 阈值降低，但仍优先选择不可重算或重算代价高的数据。

### 3.6.5 实验评估模块实现

实验评估模块统计训练性能、显存收益、SSD 友好性和接口覆盖率。训练性能包括 tokens/s、step time、GPU utilization 和尾延迟；显存收益包括 GPU memory peak 和 OOM 规避情况；SSD 友好性包括 Host writes、平均写入请求大小、小随机写比例、I/O 等待时间、checkpoint stall 和 offload wait time；接口覆盖率包括 Tag coverage、字段完整率和 trace 可解析率。

评估模块至少支持三类 baseline：PyTorch 原生训练或无 offload 策略、DeepSpeed 默认 NVMe Offload 策略、本方案 SSD 友好策略。所有实验应记录模型配置、训练配置、硬件环境、软件版本、策略参数和随机种子。若某项硬件侧指标无法直接采集，应使用训练侧 trace 或系统 I/O 工具作为替代，并在报告中说明限制。

---

# 4 技术创新点

## 4.1 面向 AI SSD 的训练数据语义分类方法

第一项创新是建立面向 AI SSD 的训练数据语义分类方法。与现有训练框架只在内部区分 Tensor 和状态不同，本方案将数据类型、生命周期、访问模式、可重算性、持久化要求和优先级统一为可输出的语义标签，使底层存储侧能够理解训练数据的真实含义。

该方法把训练框架内部可见信息转化为标准化字段，使 AI SSD 能够区分 short_lived activation、long_lived optimizer state、persistent checkpoint 和 read_mostly dataset cache。分类结果不仅用于统计，还直接驱动调度策略。例如 checkpoint 默认进入 append-only sequential write，activation 默认先判断 recomputable，optimizer state 默认采用 fixed shard 或批量写回，log/profile 默认标为 delayable 或 discardable。

该创新点的输出包括分类规则、生命周期特征、语义标签字段、标签覆盖率统计和数据画像报告。通过这些输出，训练数据不再只是普通 I/O 请求，而是具有可调度、可解释和可验证的语义对象。

## 4.2 SSD 友好的训练数据 Offload 与调度方法

![[4.2.png]]

第二项创新是将 Offload 从容量扩展机制提升为 SSD 友好调度机制。方案在显存、计算和 I/O 之间进行选择，形成参数预取、优化器状态 fixed shard、activation ring buffer、checkpoint 异步顺序写和日志缓冲采样等组合策略。

现有 Offload 技术通常首先解决显存不足问题，关注训练能否运行和显存峰值能否降低。本方案进一步关注 Offload 后的数据是否适合 SSD：写入是否过碎、生命周期是否可区分、是否与 checkpoint 抢占带宽、是否造成关键路径等待。该思路把 Offload 从单一容量手段扩展为显存、计算、I/O 和设备写入压力之间的综合调度问题。

调度方法具备动态降级能力。当 SSD 负载高或 checkpoint 正在写入时，低优先级数据延迟写入；当 GPU 显存压力接近阈值时，选择性 offload 提高优先级；当某类 activation 可重算时，优先使用计算替代保存。该策略能够避免简单 offload 带来的无效写入和训练抖动。

## 4.3 面向训练过程的 I/O 大块化、顺序化与削减机制

![[4.3.png]]

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

第一阶段完成实验环境搭建、模型选择、插桩工具开发和生命周期分析。验证对象可选取 GPT、BERT、T5 或 LLaMA-like 小中型模型，基于 PyTorch 和 DeepSpeed 采集参数、梯度、优化器状态、activation 和 checkpoint 的生命周期信息。阶段输出包括 Profiler 原型、数据分类模型初稿和典型模型训练数据画像报告。

本阶段重点是建立可信观测基础。先在可控规模模型上验证 hook、profiler 和 I/O trace 是否能够稳定采集数据，再逐步引入 DeepSpeed ZeRO 和 NVMe Offload 配置。采集内容包括对象大小、产生阶段、释放阶段、重用距离、读写次数、是否进入 checkpoint、是否可重算以及是否参与训练关键路径。

阶段内形成初版分类规则和数据画像模板。分类规则用于把训练对象映射为 parameter、gradient、optimizer_state、activation、checkpoint、dataset_cache 和 log_profile 等类别；数据画像模板用于展示不同模型和训练配置下各类数据的规模占比、生命周期分布和 I/O 行为。第一阶段重点不在性能提升，而在观测准确性、分类覆盖率和报告可复现性。

## 5.2 第二阶段：SSD 友好训练调度方法研发

![[5.2.png]]

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

---

# 6 预期成果

## 6.1 技术成果

技术成果包括大模型训练数据生命周期分析方法、面向 SSD 的训练数据分类模型、SSD 友好的 Offload 调度算法、训练框架与 AI SSD 语义协同接口，以及基于 PyTorch/DeepSpeed 的原型系统。这些成果共同为 AI SSD 在大模型训练场景中的应用提供训练侧支撑。

生命周期分析方法用于识别训练对象的产生、复用、释放和写回规律；分类模型用于把不同训练数据映射到可调度语义；Offload 调度算法用于在显存、计算和 I/O 之间做选择；语义协同接口用于把训练侧意图传递给 AI SSD；原型系统用于验证上述方法是否可运行、可观测、可对比。

技术成果以不改变模型数学定义和训练目标为前提。方案关注数据放置、预取、写回、缓冲、checkpoint 和语义标注，不改变模型结构、损失函数或优化器数学语义。性能收益以可复现实验数据为依据，不以未测试的绝对提升作为结论。

## 6.2 软件成果

软件成果包括 Tensor 生命周期 Profiler、训练数据分类与标注模块、SSD 友好数据调度模块、DeepSpeed 适配插件或扩展模块、实验评估脚本和可视化工具。软件应具备可复现实验能力，能够在联合验证环境中运行。

Profiler 负责采集模型层级、Tensor 元数据、生命周期事件和 I/O 行为；分类与标注模块负责输出数据类型、生命周期、访问模式、优先级和可重算性；调度模块负责执行选择性 offload、预取、批量写回、ring buffer 和 checkpoint 异步写；评估脚本负责生成指标表、trace 报告和 baseline 对比。

软件成果支持分模块使用。即使 AI SSD 接口尚未接入，也应能够单独运行 Profiler 和分类报告；即使调度策略暂未全部启用，也应能够输出语义元数据和 I/O trace。配置文件应包含模型、batch size、DeepSpeed 选项、offload 路径、策略阈值和日志输出等参数。

## 6.3 性能与评估指标

评估指标覆盖训练性能、显存收益、SSD 友好性、接口覆盖率和可靠性五个方面。训练性能包括 tokens/s、step time、GPU utilization 和尾延迟；显存收益包括 GPU memory peak、OOM 规避情况和可支持 batch size 变化；SSD 友好性包括 Host writes、小随机写比例、平均写入请求大小、checkpoint stall 和 offload wait time；接口覆盖率包括 Tag coverage、字段完整率和 trace 可解析率；可靠性包括 checkpoint 完整性和恢复成功率。

表 14 给出建议指标体系。

| 指标类别    | 指标名称                | 含义               | 评价方式               |
| ------- | ------------------- | ---------------- | ------------------ |
| 训练性能    | tokens/s            | 单位时间训练 token 数   | 与 baseline 对比      |
| 训练性能    | step time           | 单步训练耗时           | 均值和尾延迟             |
| 训练性能    | GPU utilization     | GPU 利用率          | profiler 或系统工具统计   |
| 显存收益    | GPU memory peak     | GPU 显存峰值         | 降低比例或峰值变化          |
| SSD 友好性 | Host writes         | SSD 主机侧写入量       | 每 step 或每 epoch 统计 |
| SSD 友好性 | Small write ratio   | 小写请求比例           | 请求大小分布             |
| SSD 友好性 | Average write size  | 平均写入请求大小         | 与 baseline 对比      |
| I/O 干扰  | Checkpoint stall    | Checkpoint 对训练阻塞 | 阻塞时间               |
| I/O 干扰  | Offload wait time   | Offload 导致等待     | profiler 统计        |
| 协同接口    | Tag coverage        | 语义标签覆盖率          | 标注数据量比例            |
| 可靠性     | Checkpoint recovery | Checkpoint 恢复能力  | 恢复测试结果             |

指标解释应结合正确性和稳定性。若显存降低但 step time 显著恶化，需要分析是否过度 offload；若平均写入块变大但 checkpoint 恢复失败，则策略不可接受；若 Host writes 下降但训练正确性受影响，也不符合目标。因此，性能指标必须与正确性、稳定性和可恢复性共同评价。

## 6.4 协同成果

协同成果包括面向 AI SSD 的数据语义接口规范、训练侧 I/O 访问模式报告、联合评估数据集与测试用例、联合验证报告和问题反馈清单。这些成果帮助 AI SSD 设计方理解真实训练负载，并据此优化底层能力。

协同成果覆盖“规范、样例、流程、反馈”四个层面。规范定义字段和语义；样例展示典型训练对象如何标注；流程说明如何采集和重放 trace；反馈清单记录设备侧发现的问题及训练侧调整建议。联合评估数据集与测试用例可采用公开模型结构、小中型验证模型、合成 token 数据或合作方认可的数据集，重点验证数据流形态和调度策略。

协同目标是让 AI SSD 侧能够回答三个问题：训练数据流有哪些类型；每类数据的生命周期、优先级和访问模式是什么；底层设备优化后如何通过训练侧指标体现收益。若这些问题能被 trace、元数据和实验报告共同回答，则协同成果具备可验证性。

## 6.5 知识产权与文档成果

知识产权重点可围绕训练数据生命周期分类、SSD 友好 Offload 调度、Activation ring buffer、Optimizer fixed shard、Checkpoint 顺序化写入和训练语义接口展开。重点突出训练侧贡献，而不是泛泛声明 SSD 硬件能力。

可凝练的方向包括：面向大模型训练的语义标签体系；基于生命周期和重用距离的 SSD offload 决策方法；面向短生命周期 activation 的缓冲复用策略；面向优化器状态的分片写回策略；面向 checkpoint 的训练干扰降低方法；训练框架到 AI SSD 的协同接口。


---

# 7 参考资料

[1] DeepSpeed ZeRO 官方文档。https://deepspeed.readthedocs.io/en/stable/zero3.html

[2] DeepSpeed ZeRO-Offload 官方教程。https://www.deepspeed.ai/tutorials/zero-offload/

[3] DeepSpeed ZeRO 官方教程。https://www.deepspeed.ai/tutorials/zero/

[4] ZeRO-Infinity: Breaking the GPU Memory Wall for Extreme Scale Deep Learning。https://arxiv.org/abs/2104.07857

[5] PyTorch Distributed Checkpoint 官方文档。https://docs.pytorch.org/docs/stable/distributed.checkpoint.html

[6] PyTorch saved tensors hooks 教程。https://docs.pytorch.org/tutorials/intermediate/autograd_saved_tensors_hooks_tutorial.html

[7] NVIDIA GPUDirect Storage 官方文档。https://docs.nvidia.com/gpudirect-storage/

[8] RAPIDS KvikIO 官方文档。https://docs.rapids.ai/api/kvikio/stable/

[9] SSDTrain: An Activation Offloading Framework to SSDs for Faster Large Language Model Training。https://arxiv.org/abs/2408.10013

[10] BaM: GPU-Initiated On-Demand High-Throughput Storage Access in the BaM System Architecture。https://arxiv.org/abs/2203.04910

[11] Samsung Flexible Data Placement 技术介绍。https://semiconductor.samsung.com/news-events/tech-blog/flexible-data-placement/

[12] NVM Express Flexible Data Placement 相关资料。https://nvmexpress.org/nvmeflexible-data-placement-fdp-blog/

[13] PyTorch 官方文档。https://docs.pytorch.org/docs/stable/index.html

[14] G10: Enabling An Efficient Unified GPU Memory and Storage Architecture with Smart Tensor Migrations。https://arxiv.org/abs/2310.09443
