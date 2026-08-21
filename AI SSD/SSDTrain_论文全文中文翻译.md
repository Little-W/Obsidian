# SSDTrain：一种将激活卸载到 SSD 以加速大语言模型训练的框架

Kun Wu∗†∥，Jeongmin Brian Park∗†∥，Xiaofan Zhang∗‡，Mert Hidayetoglu§，Vikram Sharma Mailthody†，Sitao Huang¶，Steve Lumetta∥，Wen-mei Hwu†∥

†NVIDIA　‡Google　§Stanford University　¶University of California, Irvine　∥University of Illinois Urbana-Champaign

∗这些作者贡献相同

## 摘要

GPU 内存容量的增长速度一直无法跟上大语言模型（LLM）规模的增长速度，从而阻碍了模型训练过程。特别是，激活（activations）——在前向传播期间产生并在反向传播中复用的中间张量——占据了 GPU 内存使用的主要部分。这会导致较高的训练开销，例如由于微批大小较小而产生昂贵的权重更新成本。为应对这一挑战，我们提出 SSDTrain，一种面向大容量 NVMe SSD 的自适应激活卸载框架。SSDTrain 通过==将数据传输与计算完全重叠，在不影响性能的情况下降低 GPU 内存使用。==SSDTrain 与 PyTorch、Megatron 和 DeepSpeed 等流行深度学习框架兼容，并==采用张量去重和转发等技术进一步提升效率==。我们使用 GPT、BERT 和 T5 等流行 LLM 进行了大量实验。结果表明，SSDTrain 将激活峰值内存使用量降低了 47%。与此同时，SSDTrain 能够将 I/O 与计算完美重叠，并且只引入可忽略的开销。与将激活保留在 GPU 内存中以及逐层完全重计算相比，SSDTrain 在吞吐量损失可忽略的情况下实现了最佳内存节省。我们进一步分析了如何利用降低后的激活内存使用，通过增大微批大小并减少流水线并行气泡来提升吞吐量。

## I. 引言

LLM 现在驱动着广泛的应用，包括聊天机器人 [1]、搜索 [2]、内容生成 [3]、推理 [4] 等。当这些模型的规模足够大时，它们会表现出涌现能力 [5]，从而具备处理复杂任务的能力。这一现象推动模型设计者持续扩大 LLM 的规模，使其包含更多参数。已经十分高昂的训练成本仍在继续增长：例如，训练 GPT-4 的成本为 1 亿美元，比训练 GPT-3 增加了 21 倍 [6]。

GPU 内存容量已经成为 LLM 持续增长的瓶颈。如图 1 所示，GPU 内存容量的增长速度比 LLM 规模扩展速度和 GPU FP16 吞吐量提升速度低约 60%。用于训练近期 LLM 的 GPU 内存中约 80% 由激活组成 [7]、[8]，这些激活是在前向传播中产生、并在反向传播中复用的中间张量。此外，激活所需内存的增长速度快于其他任何内存使用类型，使得 GPU 内存对于未来 LLM 训练而言成为更加严重的约束（详见第 II-B 节）。

![[AI SSD/_assets/Pasted image 20260527170734.png]]
图1 .用于深度学习训练的GPU的FP16吞吐量的增长与LLM的模型大小保持一致，但GPU的内存容量落后[ 18 ]。横轴表示发布日期。Points代表了自K100以来的Nvidia 100级GPU和Google TPU。

常见的缓解方法是减小批大小或使用梯度累积。在梯度累积中，一个批被划分为多个微批，这些微批在两次梯度更新之间分别处理。尽管许多 LLM 已经采用梯度累积 [9]–[11]，GPU 计算栈并不是为小输入设计的，因此这两种缓解方法都会导致设备利用率不足 [12]、[13] 以及数学库性能次优 [14]。直观地看，较小的批大小可能通过更快收敛来减少总训练计算量。然而，LLM 训练者已经为每个模型识别出一个临界批大小，低于该大小时收敛速度几乎不会增加，甚至会下降 [15]、[16]。值得注意的是，临界批大小会随着训练进行、训练损失降低而增长。

%%梯度累积：把一个 batch 拆成多个 **micro-batch** 分别处理，在多次反向传播后再统一做一次参数更新。训练目标一般为一个batch的平均loss，%%

另一种常见的减少 GPU 内存使用的方法是激活检查点。采用该方法时，仅部分激活保存在 GPU 内存中，其余激活被丢弃，并在反向传播期间重新计算。对于一个 L 层模型，激活检查点将内存需求从 O(L) 降低到 O(√L) [17]。然而，如第 II-B 节所示，仅靠这一方法仍不足以消除 GPU 内存限制给未来 LLM 带来的瓶颈。

%%激活检查点：不保存前向传播时的每一层输出激活，而是舍弃一部分。从最近的checkpoint开始重新计算%%

本文提出 SSDTrain，这是一种软件框架，可将激活卸载到 NVMe SSD，并在反向传播中即将需要这些激活之前重新加载。SSDTrain 能够将激活传输与计算完全重叠，从而在不引入显著性能开销的情况下降低激活内存使用。与主（CPU）内存相比，SSD 是更有吸引力的目标，原因有几点。首先，集群和云实例 [19]–[21] 通常受限于主机内存容量（每 GPU 100–250 GB），而 SSD 提供更高容量。有限的主机内存还会被输入、元数据等占用，这进一步减少了可用于激活卸载的内存量。其次，主机内存带宽在训练管理任务和在主机 CPU 上运行的卸载计算 [22]–[24] 之间共享，并且在保存和恢复激活时可能相当有限，甚至不可预测 [25]。相比之下，在训练期间 SSD 带宽可以专用于激活卸载。第三，SSD 更具弹性，既可以通过增加更多 SSD 甚至必要时增加 PCIe 交换机来扩展，也可以通过可选的远程高吞吐存储 [26]、[27] 来扩展。这种弹性使数据中心能够跟上激活规模的快速增长。相比之下，GPU 云实例和集群节点的内存容量更难扩展。

%%**activation** 是模型每一层前向传播产生的中间张量。%%

本文的主要贡献如下。

1. 我们设计并实现了 SSDTrain 框架，用于将 LLM 激活卸载到 NVMe SSD。我们通过对性能、SSD 寿命以及所需的每 GPU PCIe 带宽进行建模，证明 SSDTrain 在大规模系统上的可行性。

2. 除了一个很小的 CUDA API hook 库外，所有代码均使用 Python 编写，SSDTrain 可与最新的 PyTorch 和分布式框架配合工作。我们在一个具有 2 块 GPU 和 7 块 Intel Optane SSD 的节点上，结合 Megatron-DeepSpeed [28] 开发并测试了 SSDTrain。

3. 评估结果表明，SSDTrain 在将激活峰值内存使用量降低多达 47% 的同时，能够匹配原始系统的训练时间。这证明 SSDTrain 将数据传输与计算完全重叠。与保留激活和逐层完全重计算相比，SSDTrain 获得了最佳性能和最低内存峰值。我们进一步分析了降低的激活内存使用如何通过增大微批大小和减少流水线并行气泡来提升吞吐量。

%%Python 写训练程序；PyTorch 负责深度学习计算和自动求导；CUDA 让 GPU 真正执行计算；DeepSpeed 和 Megatron 让超大模型可以在多 GPU 上高效训练。%%

## II. 背景

### A. 基于 Transformer 的 LLM

大多数 LLM 架构，包括 GPT [29]，都基于 Transformer [30]。这些模型主要由 Transformer 层组成。每个 Transformer 层主要由一个注意力块和一个多层感知机（MLP）块组成。GPT 是仅解码器模型，因为它只包含 Transformer 解码器层。编码器层与解码器层具有相同结构，区别在于后者在注意力掩码上施加因果性。Transformer 模型可分为：（1）仅编码器模型，例如 BERT [31]；（2）仅解码器模型；以及（3）编码器-解码器模型，例如 T5 [32]。在编码器-解码器模型中，解码器层同时接收编码器输出和另一段文本，并应用两个注意力块：自注意力块应用于新文本，交叉注意力块应用于编码器序列中的 token 与新文本中的 token 之间。

并行化 LLM 训练涉及将模型和数据划分和/或复制到不同 GPU 上 [33]。==流水线并行（PP）、数据并行（DP）和张量并行（TP）是适用于所有 LLM 模型的三种广泛采用的并行级别。==PP 将模型划分，并将若干层块放置在不同 GPU 上。在一个 step 中，当 GPU 完成其层后，输出被传递给拥有下一层的 GPU。DP 在不同 GPU 组中复制模型，并为每组分配独立的微批。TP 将权重张量分片，并将这些分片放置到不同 GPU 上。每个 GPU 使用其分片对相应算子执行一部分计算。零冗余优化器（ZeRO）[34] 通过在这些 GPU 间对优化器状态进行分片，并且可选地对梯度和参数进行分片，进一步减少 DP 的内存使用。

### B. GPU 内存容量与模型吞吐量

如第 IV 节图 7 所示，GPU 内存容量限制了模型吞吐量。通过将激活卸载到 SSD，SSDTrain 可以缓解这一限制并提高每 GPU 模型吞吐量。一个重要问题是，根据 LLM 扩展趋势，GPU 内存容量是否将继续成为每 GPU 模型吞吐量的限制因素。本节表明，历史趋势将使 GPU 内存容量成为每 GPU 模型吞吐量更加重要的限制因素。

神经缩放定律 [15]、[16]、[35] 随着计算能力增加指导 LLM 扩展。我们的推理遵循这些定律。全系统 GPU 计算吞吐量满足以下关系：$C \propto N D_{batch}$其中 N 为参数数量，$D_{batch}$ 为一个批中的 token 数量 [36]。Chinchilla Scaling [35] 得出结论：最优模型设计遵循以下关系：$N \propto C^{0.5}$这意味着为了使 GPU 吞吐量饱和，有：$D_{batch} \propto C^{0.5}$全系统 GPU 内存使用由两部分组成：激活，其需求为：
$S_{activations} \propto \frac{N}{h}D_{batchs}$其中 h 是层中的隐藏维度，并且是 N 的缓慢增长函数，例如：$h \propto N^{1/3}$
以及其他所有内存使用,$S_{others} \propto N$包括参数、梯度和优化器状态。比较这些因素，我们可以推导出：（1）$S_{activations}$ 的增长速度快于 Sothers；（2）由激活主导的全系统内存使用增长速度略慢于计算吞吐量 C（近似为$C^{5/6}$）。然而，图 1 显示 GPU 内存容量的历史增长速度（红色虚线）仅为计算吞吐量增长速度（黄色虚线）的 41%。因此，GPU 内存容量将越来越不足以使计算吞吐量饱和，而激活内存将继续主导 GPU 内存使用。激活检查点又如何呢？回顾前面的公式：$S_{activations} \propto \frac{N}{h}D_{batchs} \propto LhD_{batch}$其中 L 为层数。检查点会使新的激活内存使用变为：
$$S'_{activations} \propto \sqrt{L}hD_{batch}$$
由于 L 和 h 会随着 N 增大而增长，并且$$ D_{batch} \propto C^{0.5}$$成比例，$S'_{activations}$ 仍然比$S_{others}$增长得更快。

### C. SSD 耐久性

价格、延迟和带宽方面的趋势推动了 SSD 在云实例和集群 [19]–[21] 中的广泛采用与集成。Flash 的随机写入延迟已降低到几十微秒 [37]，NVMe SSD 数据速率现在达到数 GB/s。

SSD 耐久性仍是一个问题：在写密集型激活卸载中，SSD 能持续使用多久？SSD 耐久性由单元类型和数量、写放大因子（WAF）以及过量预留决定。SSD 单元可用于存储一位或多个电平。通常，单元存储的位数越多，其程序-擦除（PE）周期寿命越短。WAF 是介质写入量与主机写入量之比——SSD 按页写入，但擦除由页组成的块，粒度更粗。擦除一个部分为空的块需要重新定位其中剩余的有效页，从而导致写放大。因此，厂商采用过量预留来保留一些块用于磨损均衡，使写入在块之间更加均匀。

值得注意的是，SSD 耐久性评级使用 JESD 测试方法 [38]，该方法在严格预处理后执行随机写入。在我们的场景中，写入是大规模且顺序的，因为每个被卸载的张量大小很容易达到数百 MB。与用于确定 JESD 评级的写入相比，这类写入对耐久性更加友好。例如，3-DWPD SSD 通常允许的顺序写入量约为 JESD 评级预期值的 2.5 倍 [39]–[41]。厂商指南 [42]–[44] 和经验数据 [45] 证实了这一差异。第 III-D 节使用建模来证明主流数据中心 SSD 是支持 SSDTrain 在大规模 LLM 训练系统中部署的可行选择。

### D. 面向 LLM 的 SSD 卸载系统

GPUDirect Storage（GDS）在 GPU 与 NVMe SSD 之间启用直接数据路径 [48]–[50]，消除了对 CPU bounce buffer 的需求，从而提升带宽，并降低延迟和 CPU 负载。

为缓解 GPU 内存容量限制带来的训练开销，SSDTrain 与相关工作 [50]、[51] 有三项关键区别：SSDTrain 将==（a）激活卸载到（b）SSD，并且（c）带来可忽略的性能开销==。据我们所知，SSDTrain 是第一个利用 SSD 为 LLM 训练卸载激活的工作。表 I 展示了 SSDTrain 的若干其他特性。

![[AI SSD/_assets/Pasted image 20260527203531.png]]
表1：将Ssdtrain与其他具有激活卸载特性的Llm系统进行比较[ 46 ] - [ 48 ]。在没有反向传播的情况下，推理系统可能会在一层完成后丢弃中间的Tensor。我们将"激活"推广为Key - value ( KV )缓存，因为它是跨步骤重用的。

直接且异步的 GPU–SSD 数据传输。如第 I 节所示，经由 CPU 传输会影响效率。此外，现有系统要么在加载卸载数据时阻塞训练，要么在每层同步。因此，I/O 延迟处于关键路径上。SSDTrain 通过将 I/O 与计算重叠来隐藏 I/O 延迟。

互操作性。由于 LLM 训练需要 Python 包之间的协同，并且生态系统快速演化，卸载机制具备良好互操作性至关重要。SSDTrain 逻辑局限于进程内部，并且可以与分布式框架一起工作，例如 Megatron。相比之下，DeepSpeed 的卸载功能（例如 ZeRO-Infinity）仅在某些 ZeRO 阶段可用。ZeRO 阶段决定了哪些内容被分片。例如，图 5 中的 stage-3 ZeRO 会在 GPU 间对优化器状态、梯度和权重进行分片。

## III. 设计与实现

### A. SSDTrain 框架概述

SSDTrain 实现了一个张量缓存，用于管理张量的卸载和重新加载，从而促进内存释放，并在反向传播需要张量之前将张量预取回内存。图 2 示例说明了 SSDTrain 的工作方式。SSDTrain 启动自己的线程来存储张量（①）并重新加载张量（⑤）。在前向传播（F）中，一旦产生激活的算子完成，激活的卸载就开始（①）。当激活在反向传播（B）中被复用时，预取（⑤）按照前向传播期间记录的层的逆序发生（②）。

![[AI SSD/_assets/Pasted image 20260528103505.png]]

如果最后一层在其前向传播后立即开始反向传播（示例中的微批 2 的 L3），则其激活会被保留（④）。SSDTrain 为每个微批保留独立记录。当微批发生变化时（②），SSDTrain 将自己的记录切换为与新微批对应的记录。

%%5指的是预取激活，反向传播L3时需要的激活再正向计算时就有保存%%

图 3 展示了 SSDTrain 工作流。SSDTrain 从模型实例获取模型的计算量和激活大小、GPU 吞吐量以及 SSD 带宽。随后，SSDTrain 相应地设置激活卸载量。张量缓存管理激活并执行张量卸载与加载。为实现这一点，它使用 PyTorch hooks 来改变 PyTorch 执行。第 III-B 节详细介绍张量缓存的设计与实现。SSDTrain 包含面向同一节点内 NVMe SSD 的 SSD offloader，以及面向主机内存的 CPU offloader。每个 offloader 封装了在 CUDA 张量与目标之间传输的逻辑。SSD offloader 利用 GDS Python 绑定 kvikio [52]。通过 LD_PRELOAD 插桩机制，CUDA malloc hook 库改变 CUDA 内存分配和释放 API 调用，使内存被适当地注册和注销，以获得最佳 GDS 性能。这使我们能够保留 PyTorch 内存分配器以便与基线进行比较，而无需在 PyTorch 可插拔内存分配器中复制其实现，也无需修改 PyTorch C++ 代码。CPU offloader 面向未来具有大规模远程 SSD 存储的集群。它由一个带预分配 host-pinned memory 的分配器支持。内存池大小由对第一个训练 step 的分析确定。提示被添加到 Megatron 和 DeepSpeed 的调度器中，例如图 2 中的 ③ 和 ④。例如，对于 DeepSpeed 调度器，会在每个命令执行前后添加提示，如计算微批 i、通信等，使张量缓存能够获知即将到来的阶段以及某个动作的完成。因此，张量缓存可以预取数据或等待 I/O 完成。

![[AI SSD/_assets/Pasted image 20260528103535.png]]

要使用 SSDTrain，只需在现有脚本中添加几行代码：它们注册 PyTorch hooks，记录权重以避免卸载权重，并对调度器进行 monkey-patch [53]。

%%1. Python 训练脚本启动  
2. DataLoader 在 CPU 侧准备 batch  
3. batch 被传到 GPU  
4. Megatron/DeepSpeed 决定当前 micro-batch、pipeline stage、parallel group  
5. PyTorch 执行模型 forward  
6. CUDA kernel 在 GPU 上做 attention、MLP、矩阵乘法  
7. SSDTrain hook 捕捉 activation，tensor cache 决定是否 offload  
8. kvikio/GDS 把 activation 从 GPU 写到 NVMe SSD  
9. PyTorch 执行 backward  
10. SSDTrain 在 backward 前预取 activation  
11. NCCL 做多 GPU 梯度/参数通信  
12. DeepSpeed/optimizer 更新参数  
13. 保存日志和 checkpoint%%

SSDTrain 可以自然扩展到分布式场景，例如与 ZeRO 一起使用，因为 DeepSpeed 和 Megatron 等框架会把工作负载划分到基于 PyTorch 内置张量功能构建的进程中。通过在 PyTorch 之下工作并保持每个进程的活动局部化，SSDTrain 可直接应用于分布式启动。

### B. 张量缓存的基于 Hook 的实现

为了从张量卸载中受益，卸载张量所拥有的 GPU 内存必须在张量未被使用时释放。然而，PyTorch 默认在计算图上保存对所有激活的引用，这使得 GPU 内存无法被回收。张量缓存改变 PyTorch 的执行方式，使激活的标识符被注册到计算图上；当 PyTorch 复用激活张量时，张量缓存使用来自计算图的标识符作为键来返回所请求的张量。在前向传播中，当张量完成卸载后，张量缓存不再持有对它的引用，使得一旦控制流离开使用该张量对象的函数作用域，其内存便可以由 Python 垃圾回收释放。在反向传播中，张量缓存通过在使用之前从 SSD 加载该张量来持有对它的引用；当引用该张量的所有模块作用域都结束后，该引用不再被持有，从而允许其内存被回收。简言之，张量缓存是一个内存中的结构，用于管理对所有激活的引用，并跟踪激活的状态，包括它们是否正在被卸载、文件系统中的路径等。

张量缓存使用 PyTorch hooks 来改变其执行行为。forward hook 对在前向传播中工作：模块开始时触发 forward pre hook，模块完成时触发 forward hook。张量缓存使用 forward hook 对维护当前作用域栈：进入模块时，将模块压入栈；退出模块时，将其弹出。backward hook 对类似。进入模块时，张量缓存会预取即将到来的模块中的激活。第 III-C2 节详细介绍预取。退出模块时，张量缓存从所有激活的作用域列表中移除该模块。不再使用的激活会被移除，其内存随后将由垃圾回收释放。

当一个张量将被注册到计算图上时，会调用 pack hook 来生成一个替代注册的值。当该张量被复用时，会调用 unpack hook 取出计算图上的对象并返回原始张量。图 4 展示了触发 pack 或 unpack hook 时张量缓存的活动。当乘法算子 x·w 完成（①）时，会在输入 x 和权重 w 上调用 pack hook（②）。张量缓存有权重记录，因此返回 w 以使其按原样注册到计算图上。如果张量位于 CPU 上或太小（算法 1 第 2 行），该张量也会按原样返回。如算法 1 第 6 行所示，当模块将被保留在内存中或处于反向传播中时，张量缓存不会卸载张量，而只保留记录。当前一个条件在此 step 中当前张量之前的激活量达到图 3 中设置的大小时为真。第二个条件在启用激活检查点的函数在反向传播中执行重计算以重新生成激活时为真。对于图 4 中的张量 x，张量缓存将其存储到 SSD（③），更新此 step 中已卸载的激活量，并返回一个张量标识符。当在反向传播（A）中触发 unpack hook（B）时，张量缓存要么等待直到预取完成（C），并最终返回张量。

[图 4：此处保留原文图示位置，不作处理]

[算法 1：此处保留原文算法位置，不作处理]

### C. 张量缓存机制与优化

#### 1）张量去重与排除权重

张量缓存具有 get_id() 函数，用于为每个张量分配唯一标识符。PyTorch 原生 id() 的缺点是其返回值与 GPU 内存地址相关。由于 SSDTrain 会卸载激活，一旦控制流离开其使用作用域，后者会被垃圾回收清理。GPU 内存地址可能被复用，从而导致标识符冲突。为解决这个问题，get_id() 将首次处理张量时的时间戳与张量形状组合为唯一标识符：当 get_id() 第一次处理张量 t 时，get_id() 将当前时间戳作为附加属性添加到底层存储 t.untyped_storage()，而不是添加到 t。这是因为 PyTorch 有时会创建新的 torch.Tensor 对象来表示相同张量。所有未来的 get_id() 调用都会获取该属性值。这种去重方案有助于防止冗余 I/O。

PyTorch 会把反向传播所需的所有张量注册到计算图中，其中包括激活和权重。由于本文关注激活，张量缓存排除权重。为此，在训练前，张量缓存会记录所有权重的标识符。由于线性层会存储权重转置用于反向传播，因此转置的唯一标识符也会被记录。我们的 get_id() 方案的一个好处是，同一权重张量的转置标识符在各 step 之间保持一致。这是因为转置使用原始张量的底层存储，而我们在训练前已经为其分配了时间戳。

#### 2）卸载与转发张量

张量缓存有两个线程池——一个用于存储张量，另一个用于加载张量。提交的作业按先进先出（FIFO）顺序执行。为了隐藏 I/O 延迟，张量缓存会在对应模块的反向传播之前开始预取每个激活。最后一个模块中的激活保留在 GPU 内存中，因此无需预取。这一简单方案已经足够，因为在 PyTorch 中，CPU 会在 GPU 执行之前提交 GPU kernel launch 和内存操作。只要 GPU 作业队列中总有 I/O 任务以保持 PCIe 忙碌，预取方案就是等价的。

加载张量时，如果该张量仍在存储中，张量缓存会返回其内存中的引用以跳过从 SSD 加载。我们称之为数据转发。例如，在图 4 中，当 PyTorch 从 MulBWD 节点检索 x 时，如果 x 仍在被存储，则它仍在内存中。张量缓存不会加载该张量，而是将 x 的内存中引用从弱引用转换后返回，并把获得的引用存储在张量缓存中，以便在它被其他作用域使用时使用。

### D. SSD 写入量、带宽与寿命

为了确认我们的设计在大规模系统中是否可行，特别是在 SSD 耐久性和所需带宽方面，我们进行性能建模，以获得每个训练 step 的前向传播时间以及该过程中产生的激活大小。我们扩展了性能模型包 llm-analysis [54]，该包将每个 Transformer 层的前向传播建模为一个简单流水线：

[公式：此处保留原文公式位置，不作处理]

其中 l 表示 Transformer 层内部的任意层。当启用 ZeRO 时，假定 ZeRO 通信时间在 Transformer 层级别与非 ZeRO 操作完美流水线化。

我们将每 GPU 所需 PCIe 写带宽建模为激活总量除以训练时间的一半。寿命则按如下方式预测：

[公式：此处保留原文公式位置，不作处理]

其中 Sendurance 是 SSD 耐久性评级允许的生命周期写入量，Sactivations 是每个训练 step 的激活量，tstep 是 step 时间。我们使用第 IV 节中的实验验证了 Sactivations 公式。我们假设每个 GPU 配备四块 Samsung 980 PRO 1TB，并假设 JESD 评级中的 WAF 为 2.5，而在我们的场景中 WAF 为 1。我们还放宽数据保持期：当数据保持期从 3 年放宽到 1 天时，NAND flash 可获得 86 倍 PE 周期 [55]–[58]。据此得到图 5。我们使用 Megatron-LM [10] 的实测数据。GPU 为 A100 PCIe。在所有情况下，预计寿命都超过 2 年，每 GPU 写带宽不超过 12.1 GB/s。此外，当系统规模和/或模型规模扩大时，所需每 GPU PCIe 写带宽会降低，而预计寿命会增加。这是因为更大的系统意味着通信开销增加和计算效率降低，从而减慢 GPU 上的训练。

[图 5：此处保留原文图示位置，不作处理]

我们还估计每个 GPU 每 step 产生的最大激活大小，假设同一时间只有连续两层位于 GPU 内存中，而所有其他激活都被卸载。然后，图 5 中的菱形标记显示了一个最大微批在一个 step 中产生的激活。每 GPU 最大激活大小范围从 0.4 TB 到 1.8 TB，而微批大小范围从 8 到 32。如此巨大的激活已无法由主内存保存，因此 SSD 是唯一可选的卸载目标。

## IV. 评估

### A. 实验设置

我们使用一台配有 2 块 A100 PCIe GPU 和 7 块 Intel P5800X SSD 的机器，如表 II 所示。SSD 被组织为两个 RAID0 阵列：一个包含 3 块 SSD，另一个包含 4 块 SSD。每个阵列作为一块 A100 的专用目标。在评估期间，我们测量了具有 4 块 SSD 的 A100 的内存使用。为保持一致，GPU 被锁定在基础频率。我们使用最新的 Megatron-DeepSpeed [28]，它将 DeepSpeed 技术集成到 Megatron 中。

[表 II：此处保留原文表格位置，不作处理]

我们测量 BERT [31] 作为仅编码器模型、GPT [29] 作为仅解码器模型，以及 T5 [32] 作为编码器-解码器模型的预训练性能。我们使用 OSCAR 数据集 [59]、[60]。我们使用两块 GPU 进行 TP。每个 step 的微批数量固定为 1，因为在没有 PP 的情况下，新微批不会在前一个微批的前向传播和反向传播都完成之前开始。更多微批只会带来梯度累积，而不会影响激活卸载模式。换言之，除非另有说明，在第 IV 节中微批大小等同于批大小。隐藏维度从 8192 到 16384，我们使用这一范围的典型超参数 [31]、[32]、[61]。注意力头维度为 128。文本序列长度为 1024。对于 T5，解码器数量为总层数的一半并向下取整。无论是否使用 SSDTrain，都使用 FlashAttention-2 [62] 进行优化注意力计算。

由于每块 A100 只有 40GB 设备内存，为了探索更接近真实训练系统中 A100 80GB 和后续 GPU [7]、[10] 的设计空间，我们采取了若干缓解措施。首先，我们使用 FP16 而不是混合精度，从而消除 FP32 权重副本。其次，我们使用 SGD 而不是 Adam 作为优化器，以减少优化器状态。这两项措施仅影响累积操作和权重更新，因此对使用或不使用 SSDTrain 的执行施加一个恒定偏差。

### B. 性能与峰值内存使用

为了理解 SSDTrain 对执行时间和峰值内存使用的影响，我们测量 BERT、T5 和 GPT 的 step 时间，以及前向和反向传播期间的内存峰值。图 6 比较了使用 SSDTrain 与不使用 SSDTrain 的系统所收集的指标。对于每个模型，我们收集了三种不同（隐藏维度，层数）场景：（8192，4）、（12288，3）和（16384，2）。如图所示，SSDTrain 在所有情况下几乎没有性能开销。尽管 SSDTrain 及其优化引入了额外 CPU 逻辑，但性能比较表明该逻辑不在关键路径上。相反，GPU 计算定义了关键路径，CPU 的作用主要是在当前 GPU 操作完成之前启动新的 GPU 作业。因此，CPU 未被充分利用，而 SSDTrain 的额外工作不会导致新任务到达 GPU 的延迟。SSDTrain 在这些情况下有效地将激活内存使用峰值降低了 28%–40%。

[图 6：此处保留原文图示位置，不作处理]

### C. 比较激活放置策略

除了将激活保留在 GPU 内存中以及激活检查点之外，SSDTrain 还提供了将激活卸载到 SSD 的选项。我们在 recompute-offload-keep（ROK）曲线上比较这三种不同策略：图 7 展示了两个 3 层 BERT 模型的训练。其中一个将隐藏维度设置为 12K，另一个设置为 14K。在 ROK 曲线中，每次运行由一个点表示。x 轴为激活内存峰值。y 轴为模型吞吐量 [10]，即训练 step 中涉及的算法计算数量，不考虑软件和硬件实现细节（例如激活是否被重计算），再除以训练 step 时间。在这两种情况下，SSDTrain 降低了 GPU 激活内存峰值，从而允许使用更大的批大小以获得更高吞吐量。在给定相同批大小时，SSDTrain 卸载获得的吞吐量与激活保留在内存中时相同。同时，SSDTrain 得到的激活内存峰值低于重计算。与将激活保留在内存中相比，在相同激活内存预算下，SSDTrain 能够使批大小翻倍。

[图 7：此处保留原文图示位置，不作处理]

除这三种策略外，在 FlashAttention [63] 之前，Megatron [8] 提出了选择性检查点，即重计算核心注意力模块。由于我们使用 FlashAttention，核心注意力模块在一个 kernel 中完成，从而消除了这些中间张量。结合 FlashAttention 的选择性检查点对激活的性能和峰值内存使用影响可忽略。

### D. 讨论

检查建模。为理解第 III-D 节中模型的准确性，我们比较 SSDTrain 的卸载量与模型估计值。如表 III 所示，这些数值接近。我们还计算了所需 PCIe 写带宽，当隐藏维度变大时，该带宽降低。通常，一个超过 60B 参数的模型具有不小于 8K 的隐藏维度 [35]、[61]。PCIe 写带宽与第 III-D 节中的估计一致。

[表 III：此处保留原文表格位置，不作处理]

更大微批大小的影响。为了进一步理解更大的微批大小如何改善性能，我们将图 7(a) 中的无卸载情况与批大小为 1 的相同配置进行比较，并在图 8(a) 中分解吞吐量提升。提升主要来自权重更新带来的时间节省，这与大规模 LLM 训练系统高度相关。微批大小通常被设置得很小，例如在 Paxml [64] 和 BLOOM [11] 预训练中为 1 或 2，以换取 PP 引入的较小气泡。在 BLOOM 训练系统中，每个数据并行 rank 被分配一个包含 32 个样本的小批。当微批大小不小于 4 时，理想 PP 气泡时间比例不低于 11.5%。然而，权重更新和梯度累积成本与微批大小成反比，当微批大小为 1 或 2 时成本很大。SSDTrain 允许在相同激活内存预算下使用更大的微批大小，因此有利于这些启用 PP 的训练系统。

扩展规模的影响。第 II-B 节表明，全系统激活大小 Sactivations 的增长速度慢于全系统 GPU 吞吐量 C，即：

[公式：此处保留原文公式位置，不作处理]

因此，完全重叠计算与 SSD 访问所需的带宽会降低。简而言之，LLM 的扩展本质上是一个弱扩展场景，当其扩展时，SSD I/O 延迟更容易被隐藏。在图 8(b) 中，我们进一步使用 llm-analysis 预测了扩展对每 GPU 写带宽的影响。当 GPU 数量小于 100 时，我们遵循典型并行配置 [10]、[64]。在所有预测情况下，每 GPU 写带宽均小于原始 2-GPU 情况（橙色虚线）。普通 DP 只影响权重更新，因此对写带宽没有影响。ZeRO 可能由于前向和反向传播中产生的通信而降低写带宽需求。

[图 8：此处保留原文图示位置，不作处理]

成本分析。我们研究采用 SSDTrain 卸载相关的 SSD 成本。为了获得图 5 中的耐久性，每块价格为 1 万美元的 A100 [65] 搭配总价 360 美元的 SSD。评估使用 7 块 Intel P5800X 为 2 块 A100 服务。尽管 P5800X 更昂贵，但每 PBW 价格相当 [66]。

## V. 相关工作

许多具备卸载能力的 LLM 系统仅用于推理 [46]、[47]、[67]。在推理中，权重和 KV-cache 从不改变，并且跨迭代复用；这一点被用于增强局部性和内存效率。然而，在训练中，包括权重在内的所有张量都会跨迭代变化。有些工作提供训练卸载 [48]，但主要是为了以牺牲性能为代价容纳更大的模型。它们缺少异步传输来保持性能。另一个方向是将计算卸载到 CPU [22]–[24]。被卸载的计算较轻，被卸载的数据包括梯度、权重中的稀疏元素等。我们的工作与此正交：由于我们通过 GDS 将激活卸载到 SSD，对 CPU 的干扰被最小化。激活用于计算密集型梯度计算，最适合仅在 GPU 上完成。

在 LLM 之前，已有一些面向深度学习的卸载工作 [25]、[68]–[71]：大多数以主内存为目标，而其中一些 [25] 以 SSD 为目标。LLM 的独特之处在于，大规模并行性及其内存影响是设计空间的基础。SSDTrain 自然支持多 GPU。我们展示了它在集群上的可行性。此外，LLM 对计算能力的需求非常高，推动专用硬件和框架快速发展。SSDTrain 确保了良好的互操作性，而大多数先前工作绑定到特定 PyTorch 版本或支持选定层的自定义运行时。

## VI. 结论

在 LLM 训练中，激活主导着日益受限的 GPU 内存。为解决这一问题，我们提出 SSDTrain，作为一种面向 SSD 的自适应激活卸载框架。我们通过建模证明了其在大规模系统中的可行性。评估表明，SSDTrain 将激活峰值内存使用量降低多达 47%，且开销可忽略。我们分析了这种降低如何通过增大微批大小和减少流水线气泡来提升吞吐量。

## 致谢

本工作部分由 IBM-ILLINOIS Center for Cognitive Computing Systems Research（C3SR）、IBM-ILLINOIS Discovery Accelerator Institute（IIDAI）以及 NVIDIA 支持。本工作还部分受到了 Google Cloud、Illinois Computes 项目以及 National Energy Research Scientific Computing Center（NERSC ERCAP0031237）的计算额度支持。

## 参考文献

[1] OpenAI. (2022) ChatGPT. [Online]. Available: https://chatgpt.com/

[2] Microsoft. (2023) Bing Chat — Microsoft Edge. [Online]. Available: https://www.microsoft.com/en-us/edge/features/bing-chat

[3] Midjourney. (2022) Midjourney. [Online]. Available: https://www.midjourney.com/website

[4] LangChain. (2022) LangChain. [Online]. Available: https://github.com/langchain-ai/langchain

[5] J. Wei 等. (2022) Emergent Abilities of Large Language Models. [Online]. Available: http://arxiv.org/abs/2206.07682

[6] D. Meyer. (2024) The cost of training AI could soon become too much to bear. Yahoo Finance. [Online]. Available: https://finance.yahoo.com/news/cost-training-ai-could-soon-101348308.html

[7] Z. Liu 等，“Winner-Take-All Column Row Sampling for Memory Efficient Adaptation of Language Model,” 2023 年 12 月。

[8] V. Korthikanti 等，“Reducing Activation Recomputation in Large Transformer Models,” 2022 年 5 月。

[9] Z. Jiang 等，“MegaScale: Scaling Large Language Model Training to More Than 10,000 GPUs,” 2024 年 2 月。

[10] M. Shoeybi 等，“Megatron-LM: Training Multi-Billion Parameter Language Models Using Model Parallelism,” 2020 年 3 月。

[11] T. L. Scao 等，“BLOOM: A 176B-Parameter Open-Access Multilingual Language Model,” 2023 年 6 月。

[12] L. Chen，“Dissecting Batching Effects in GPT Inference,” https://le.qun.ch/en/blog/2023/05/13/transformer-batching/, 2023。

[13] Q. Anthony 等，“The Case for Co-Designing Model Architectures with Hardware,” 2024 年 1 月。

[14] R. Y. Aminabadi 等，“DeepSpeed Inference: Enabling Efficient Inference of Transformer Models at Unprecedented Scale,” 2022 年 6 月。

[15] J. Kaplan 等，“Scaling Laws for Neural Language Models,” 2020 年 1 月。

[16] S. McCandlish 等，“An Empirical Model of Large-Batch Training,” 2018 年 12 月。

[17] T. Chen 等，“Training Deep Nets with Sublinear Memory Cost,” 2016 年 4 月。

[18] The Epoch AI，“Announcing Epoch AI’s Updated Parameter, Compute and Data Trends Database,” 2023 年 10 月。

[19] Microsoft，“ND A100 v4-series - Azure Virtual Machines,” 2024 年 2 月。

[20] Google，“GPU machine types | Compute Engine Documentation,” 2017。

[21] NCSA，“Delta Project Profile,” https://www.ncsa.illinois.edu/research/project-highlights/delta/, 2022，访问于 2024/07/21。

[22] K. Kamahori 等. (2024) Fiddler: CPU-GPU Orchestration for Fast Inference of Mixture-of-Experts Models.

[23] J. Ren 等，“ZeRO-Offload: Democratizing Billion-Scale Model Training,” in USENIX ATC, 2021。

[24] Y. Song 等. (2023) PowerInfer: Fast Large Language Model Serving with a Consumer-grade GPU. [Online]. Available: http://arxiv.org/abs/2312.12456

[25] J. Bae 等，“FlashNeuron: SSD-Enabled Large-Batch Training of Very Deep Neural Networks,” in FAST, 2021。

[26] Google，“About google cloud hyperdisk — compute engine documentation,” https://cloud.google.com/compute/docs/disks/hyperdisks, 2022。

[27] G. K. Lockwood 等，“Architecture and performance of Perlmutter’s 35 PB ClusterStor E1000 all-flash file system,” CCPE, p. e8143, 2024。

[28] Microsoft. (2019) Megatron-DeepSpeed: Ongoing research training transformer language models at scale, including: BERT & GPT-2.

[29] A. Radford 等. (2019) Language Models are Unsupervised Multitask Learners.

[30] A. Vaswani 等，“Attention is All you Need,” in NeurIPS, vol. 30. Curran Associates, Inc., 2017。

[31] J. Devlin 等，“BERT: Pre-training of Deep Bidirectional Transformers for Language Understanding,” 2019 年 5 月。

[32] C. Raffel 等，“Exploring the Limits of Transfer Learning with a Unified Text-to-Text Transformer,” 2023 年 9 月。

[33] Y. Xu 等，“GSPMD: General and Scalable Parallelization for ML Computation Graphs,” 2021 年 12 月。

[34] S. Rajbhandari 等，“ZeRO: Memory optimizations Toward Training Trillion Parameter Models,” in SC20. IEEE, 2020 年 11 月, pp. 1–16。

[35] Jordan Hoffmann 等. (2022) Training Compute-Optimal Large Language Models. [Online]. Available: http://arxiv.org/abs/2203.15556

[36] T. B. Brown 等，“Language models are few-shot learners,” 2020. [Online]. Available: https://arxiv.org/abs/2005.14165

[37] Samsung，“Ultra-Low Latency with Samsung Z-NAND SSD,” https://download.semiconductor.samsung.com/resources/brochure/Ultra-LowLatencywithSamsungZ-NANDSSD.pdf, 2017。

[38] JEDEC, JESD218B: Solid-State Drive (SSD) Requirements and Endurance Test Method, Std., 2016。

[39] Lenovo. (2023) What do I need to know about SSD endurance and overprovisioning? [Online]. Available: https://thinksystem.lenovofiles.com/storage/help/index.jsp?topic=%2Fde-series-olh-11.80%2Fwhat-do-i-need-to-know-about-ssd-endurance-and-overprovisioning.html

[40] QNAP Systems, Inc.，“QNAP NAS Solution: QTS SSD Extra Over-Provisioning,” 2018。

[41] SMART Modular Technologies, Inc. (2024) Why SMART’s Over-Provisioning? [Online]. Available: https://www.smartm.com/technology/over-provisioning

[42] Solidigm. (2022) Solidigm™ SSD Endurance Estimator. [Online]. Available: https://estimator.solidigm.com/ssdendurance/index.htm

[43] Intel. (2018) Over-Provisioning NAND-Based Intel® SSDs for Better Endurance. [Online]. Available: https://www.ioncomputer.com/ion/body/documents/over-provisioning-nand-based-ssds-better-endurance-whitepaper.pdf

[44] Samsung，“Over-Provisioning Benefits for Samsung Data Center SSDs,” 2019. [Online]. Available: https://download.semiconductor.samsung.com/resources/white-paper/S190311-SAMSUNG-Memory-Over-Provisioning-White-paper.pdf

[45] S. Maneas 等，“Operational Characteristics of SSDs in Enterprise Storage Systems: A Large-Scale Field Study,” in FAST, 2022。

[46] Y. Sheng 等，“FlexGen: High-Throughput Generative Inference of Large Language Models with a Single GPU,” 2023 年 6 月。

[47] K. Alizadeh 等，“LLM in a flash: Efficient Large Language Model Inference with Limited Memory,” 2024 年 1 月。

[48] S. Rajbhandari 等，“ZeRO-infinity: Breaking the GPU memory wall for extreme scale deep learning,” in SC, 2021 年 11 月, pp. 1–14。

[49] D. Inupakutika 等，“Quantifying Performance Gains of GPUDirect Storage,” in NAS, 2022, pp. 1–9。

[50] H. Yang 等. (2024) ProTrain: Efficient LLM Training via Memory-Aware Techniques. [Online]. Available: http://arxiv.org/abs/2406.08334

[51] X. Sun 等，“STRONGHOLD: Fast and affordable billion-scale deep learning model training,” in SC, 2022, pp. 1–17。

[52] Nvidia，“Rapidsai/kvikio: KvikIO - High Performance File IO,” https://github.com/rapidsai/kvikio, 2022，访问于 2024/07/21。

[53] Wikipedia，“Monkey patch,” 2006。

[54] C. Li，“LLM-Analysis: Latency and Memory Analysis of Transformer Models for Training and Inference,” 2023。

[55] Y. Cai 等，“Flash correct-and-refresh: Retention-aware error management for increased flash memory lifetime,” in ICCD, 2012。

[56] ——，“Error patterns in mlc nand flash memory: Measurement, characterization, and analysis,” in DATE. IEEE, 2012, pp. 521–526。

[57] R.-S. Liu 等，“Optimizing NAND Flash-Based SSDs via Retention Relaxation,” in FAST. USENIX Association, 2012。

[58] S. Kim 等，“Behemoth: A Flash-centric Training Accelerator for Extreme-scale DNNs,” 2021, pp. 371–385。

[59] P. J. O. Suárez 等，“A monolingual approach to contextualized word embeddings for mid-resource languages,” in ACL, 2020 年 7 月。

[60] ——，“Asynchronous pipelines for processing huge corpora on medium to low resource infrastructures,” ser. CMLC-7. Mannheim: Leibniz-Institut für Deutsche Sprache, 2019, pp. 9–16。

[61] H. Touvron 等，“Llama 2: Open Foundation and Fine-Tuned Chat Models,” 2023 年 7 月。

[62] T. Dao. (2023) FlashAttention-2: Faster Attention with Better Parallelism and Work Partitioning.

[63] T. Dao 等. (2022) FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness.

[64] Nitin 等. (2023) Scaling large language model training with Pax on GPUs.

[65] Dihuni. (2021) NVIDIA A100 40GB Ampere PCIe GPU.

[66] Newegg. (2021) Intel optane p5800x 1.6TB.

[67] W. Kwon 等，“Efficient Memory Management for Large Language Model Serving with PagedAttention,” in SOSP. ACM, 2023。

[68] X. Peng 等，“Capuchin: Tensor-based GPU Memory Management for Deep Learning,” in ASPLOS. ACM, 2020 年 3 月, pp. 891–905。

[69] L. Wang 等，“SuperNeurons: Dynamic GPU Memory Management for Training Deep Neural Networks,” in PPOPP, 2018 年 2 月, pp. 41–53。

[70] M. Rhu 等，“vDNN: Virtualized Deep Neural Networks for Scalable, Memory-Efficient Neural Network Design,” 2016 年 7 月。

[71] C.-C. Huang 等，“SwapAdvisor: Pushing Deep Learning Beyond the GPU Memory Limit via Smart Swapping,” in ASPLOS, 2020 年 3 月。
