# 高精度量化策略 RTL 适配设计

## 1. 修改目标与实施条件

本设计给出当前高精度 CPU/CModel 候选进入原生 NPU、SoC 程序的修改方案。静态输出量化的
QFR2 整数流水已经实现，结构与数值规则见第 10 节；其余待完成项仍以各节说明为准，不能
据此认定整模型或整机已通过。首先保持参考程序规定的数值次序，再通过流水与数据复用降低成本。
完整长对话内容仍需验收；在此之前，不更换默认硬件模型，也不把单前缀 logits 改善视为整机通过。
数值实验及证据保存在[精度排查记录](logs/CModel长对话精度排查与修复_20261108.md)，不在此重复运行日志。

候选保留 Decoder 的原 AWQ W4 code、zero point 和 scale，使用 per-token dynamic A8。
嵌入保留原 FP16 数值；输出 Head 可使用由两个 W4 项表示的有效 W8；激活可选择两次 A8
残差计算。精度选择必须由模型编译参数明确规定，不按模型名称硬编码，也不依靠环境变量改变硬件计算。

CPU 参考包的 marker 4 只是文件版本标识，不是硬件操作码。RTL 能力、指令版本、程序所需
的存储范围与算术选择必须分别检查。硬件不支持的配置应在导出或加载时拒绝。

## 2. 现有能力和实际缺口

| 项目 | 当前实现 | 需要补齐的部分 |
| --- | --- | --- |
| Decoder W4A8 | 共用 PE、组 zero point 修正和宽定点累加 | 双 A8 的静态程序、两份结果状态和权重复用 |
| 动态 A8 | 两遍 FP32 扫描，公共两路 FMA，发布 token scale | 残差专用融合；不能假定当前已有整行驻留缓存 |
| FP32 残差 | 现有 FP32_MAC 能数值转换 INT32，并应用行 scale | 当前 INT8→INT32 高速 DMA 转换不完备，展开流程较长 |
| 有效 W8 Head | 可以分解为两个现有 W4 项 | 原生 Head 仍需改用宽分组缩放，保持低/高两项合并后一次舍入 |
| FP16 嵌入 | CPU 在读取静态常量时精确展开到 FP32 | 原生导出需保留相同数值，不能把 FP16 位串当 INT16 数字做 I2F |
| 最终 logits 静态量化 | 硬件参考模式使用 QFR2 整数流水；旧浮点参考保留 double | 原生整模型导出仍需采用相同指令与参数版本 |
| 输出选择 | 原生程序已有分片 ARGMAX | ARGMAX 不能替代正式 Top-K/Top-P sampling 的质量检查 |

上述缺口不要求立即增加 PE。现有 SoC 已有 1024 W4A8 MAC/拍的物理峰值；先检查数据供给、
组缩放、结果回收与程序采用的实际模式，避免增加 PE 后仍被后处理阻塞。

## 3. 必须保持的数值次序

### 3.1 双 A8 的定义

对一个输入行，首遍量化为

$$
s_0=\max\left(\alpha\max_i|x_i|/127,2^{-24}\right),\qquad
q_{0,i}=\operatorname{clip}_{[-128,127]}
\left(\operatorname{RNE}(\operatorname{FP32}(x_i\widehat{s_0^{-1}}))\right).
$$

其中 scale 的形成、FP32 乘法及近似倒数须采用已有 DYNAMIC_A8 的确切步骤。
不能用实数除法公式代替实际倒数算法。残差为

$$
r_i=\operatorname{FMA}(\operatorname{FP32}(q_{0,i}),-s_0,x_i),
\qquad (q_1,s_1)=Q_{\mathrm{A8}}(r).
$$

INT8 转 FP32 可以精确完成；此处取负通过符号处理保持有效 FP32 scale 的值，FMA 还要保持
正零、负零的规则。第二遍也使用该 Linear 的 clipping 设置及 scale 下限，不自行换成另一种算法。

两个整数 GEMM 分别执行现有组缩放、公共指数对齐、动态 INT16 输出与最终 RNE，再按参考
程序恢复数值并相加。当前参考对带 bias 的第二遍结果还执行一次去除重复 bias 的 Complex ADD。
原生第一版应复现这一规定次序；把 bias 改为只在末端加入，是另一个需要先验证的数值改进。

**不能直接把两遍的宽部分和相加、只做一次总 RNE 来替换当前候选。** 这种组织可能更准确，
但改变了已测试的舍入位置；必须先修改 CPU/CModel、复核 logits 与长对话，再决定是否用于 RTL。

### 3.2 两项 W4 表示有效 W8

输出 Head 的有效 INT8 权重可以写成

$$
q_8=(q_{\mathrm{lo}}-z_{\mathrm{lo}})
+16(q_{\mathrm{hi}}-z_{\mathrm{hi}}),\qquad
z_{\mathrm{lo}}=-8,\quad z_{\mathrm{hi}}=0,
$$

其中两个存储码都在有符号 INT4 范围内。两项 scale 分别为 $s_w$ 和 $16s_w$，作为同一次
逻辑 GEMM 的不同 K-group 进入现有宽累加通路。低项、高项必须合并后才输出，不能分别窄化。

这不需要新增 8×8 物理乘法器，但相对 W4 Head，权重字节及乘法次数约加倍。
若 Head 本身也启用双 A8，则相对单遍 W4 Head，计算项数约为四倍；不能只按两倍估算。
两遍 A8 共用同一份已转换权重，DDR 权重读取则仍以有效 W8 的两项数据为基数。

CPU 包以重复输入形成逻辑 2K。原生编译可先用 DMA 复制 A8 行验证，随后让取数器重放同一
地址范围，消除复制；重放不得改变 absmax、group 编号、有效长度和 zero point 修正。

### 3.3 输出尺度的范围也是数值定义

CPU 包按 `vocab_chunk` 划分 Head，默认 4096 列；每段内部才决定动态输出 scale。
不能因硬件方便把一次统计范围改成 16 列 tile 或 256 列写回批次。
不同段的动态码在恢复物理数值前不能直接比较。当前参考随后还进行一次全词表共享的静态
INT16 量化，原生程序必须同时保留该步骤，或先在参考端验证移除它的影响。

## 4. 第一阶段：用已有计算资源完成数值一致的原生程序

### 4.1 嵌入与常量格式

最短的功能实现是编译期将 FP16 嵌入精确展开为 FP32 常量表，SoC 仅 DMA 读取当前 token
对应行。它保留原 FP16 数值，增加静态表空间和每次查表字节数，但不会要求 CPU 做逐元素转换。
一行只有 hidden-size 项，不能把整个嵌入表容量计入每个 decode token 的读取量。

若需要保留 FP16 存储，新增通用 `npu_fp16_to_fp32` 格式展开小模块，接入 Complex 读入或
通用转换流。有限 FP16 可精确表示为 FP32；模块负责符号、normal/subnormal、零和非有限值
规则，不需要乘法器。普通 64-bit 输出最多容纳两项 FP32/拍，输入一拍的四项 FP16 要排队。
当前 mixed-FMA 的 I2F/F2I 标志并不等于已有 FP16→FP32 存储格式转换，不能复用错误的类型解释。

### 4.2 先完整展开两个 Matrix 程序

编译器为每个 Linear 形成以下静态操作：

1. DYNAMIC_A8 产生 `q0` 和状态 `S0`。
2. INT8→INT32 转换及现有 FP32_MAC 计算残差，DYNAMIC_A8 产生 `q1` 和 `S1`。
3. 同一权重对应的两份组计算，分别使用各自 A8 码、scale、宽累加和结果区域。
4. 两次结果按参考规定去除重复 bias、合并，再进入下一算子。

参数地址、尺寸、pass 数和 clipping 静态内联，或由一次配置命令装入片内配置。
动态 scale 存在 L1 状态中，指令只引用它的地址，不需要 CPU 实时改写指令。
新字段应做完整 bit 分配，不能假定原 128-bit 基本命令能容纳两份全部地址，也不能静默占用
旧版本保留位。优先利用已有扩展内联及配置机制，避免引入每次 pass 再访问 DDR 的新描述符。

`S0/S1`、wide、shift、输出和归约状态必须分离。现有状态记录有 Matrix 可写字段，不能
只因 Q/K/V 的 A8 scale 相同，就让三个投影同时改写同一整份状态。第一版可用 DMA 复制
小规模初始状态；后续再把只读激活参数与投影私有归约状态明确分开。

### 4.3 Head 统一到宽分组缩放

优先修改 `qwen25_static_full_token.py` 和相关 compositor，使 Head 采用与 Decoder 相同的
ACCUM/REDUCE/FINAL 数值规则。原生旧 Direct 输出即使换为 INT16，仍可能逐 group 舍入，
不能作为新 CPU/CModel 的等价实现。先用两项 W4 权重通过当前 PE，不新增专用 W8 Head 阵列。

### 4.4 消除最终静态量化中的宿主数值差异

`LinearEngine::quantize_static` 当前计算

$$
q=\operatorname{clip}_{\mathrm{INT16}}\left(
\operatorname{RNE}(\operatorname{double}(y)/\operatorname{double}(s_Y))\right).
$$

`npu_complex_fp32_requant_stream` 则通过近似 reciprocal 和 FP32 乘法得到整数码。
接近半整数的输入可能得到不同结果。CPU/CModel 共用同一宿主函数，不证明 RTL 已覆盖此操作。

首选评估在现有 requant 流后增加精确阈值修正，而非引入完整 FP64 除法器。编译器预先形成
静态倒数；硬件先生成候选整数 $q_e$，再用 binary32 的整数尾数与指数比较

$$
2y\quad\text{与}\quad(2q_e-1)s_Y,\ (2q_e+1)s_Y,
$$

按 ties-to-even 修正候选。若已证明候选最多偏一，则只需一次增减；该误差条件必须先证明，
不能直接套用任意近似倒数。INT16 阈值乘积最多需要约 17×24 bit 的尾数乘法，并处理指数、
符号和饱和，不必新增通用 FP64 算术。实现前要覆盖全部已用 scale 的舍入临界样本。

对规范范围内的两个 binary32 数，在有限 INT16 商附近可用精确整数有理数比较复现上述
double→RNE；还需单独验证 subnormal、上溢和下溢。恢复 FP32 数值时，零码的符号也应与
参考一致。如果改用现有硬件近似规则作为共同定义，必须先在 CPU/CModel 完整复核，不能
只调整参考输出以掩盖错误。

## 5. 第二阶段：融合 A8 残差并复用片内数据

### 5.1 采用三次局部遍历

建议在现有动态量化流旁增加通用可选的残差模式，控制器只划分行阶段，各阶段内部采用
ready/valid 流水，数据及 tag 共同前进：

| 阶段 | 算术与统计 | 保留内容 |
| --- | --- | --- |
| 输入统计 | 读取 FP32 行，求 absmax，形成 `s0` | 原输入行 |
| 首码与残差 | 产生 `q0`；FMA 计算 `r`，同时求 residual absmax | `q0`、残差行、`s0` |
| 次码输出 | 形成 `s1`，产生 `q1`，写回两份状态 | 两份 A8 码及独立 scale |

复用公共 FMA 和转换基础组件，不为该模式再复制完整浮点乘加器。直接数值展开 INT8 到
FMA 输入，省去 INT32 中转数组；保留首遍量化结果，省去当前功能参考辅助重算首遍 A8。
相比现有展开程序，融合节省的是重复访问和指令间等待，不会消除求整行最大值的真实依赖。

若输入/残差共用一份 FP32 行 RAM，两份 A8 码另存，则最少数据容量约为 $6K$ byte。
K=4864 的算例为 29,184 byte，双行约 58,368 byte，尚不包含 FIFO、状态和对齐损耗。
K 是通用指令长度，不固定为某模型尺寸；物理容量由可综合配置确定，编译器检查是否可驻留。
优先使用现有 L1 暂存与规范 BRAM 子模块，不使用大 LUT RAM。

`q0` 已产生不代表整个融合命令完成。第一版等两份码和 scale 都写入可见后才发布完成，
避免直接增加 scheduler 的中途完成事件。需要提前启动 Matrix 时，再以明确的分片操作和
独立状态定义事件；不得让消费者读取仍在更新的 scale。

### 5.2 B 保持驻留，A 和结果上下文分开

双 A8 的推荐内层次序为：装载 `B[g,tile]`，计算 `q0[g]×B`，计算 `q1[g]×B`，再装载
下一组 B。两份宽累加保持各自 group 顺序；不同 pass 之间可以交错，不能打乱同一 pass
的 scale 对齐次序。这样增加运算次数，但不必把同一 Decoder 权重从 DDR 再读一遍。

当前 `npu_matrix_parallel_group_buffer` 有两个 context，但 A/B 使用同一个 context 选择；
重新装载 A 首拍还会清除该 context 的 B valid。因此现有双缓冲不能直接当作 B 重用能力。
需要分离 A/B 的选择和有效位，保留 B 至两个 pass 都退休；出错、取消及模式切换后使相关
有效位失效。PE bank 已有四个并行累加 context，不代表组缩放控制器也已有两份行状态。

每个 N16 tile 的两个宽结果与 shift，仅数据项约为 $2\times16\times(8+1)=288$ byte；
这不是整行存储总数，还须计算所有 N tile、归约状态、输出及在途结果。
`activation_sum_cache` 目前依赖首 tile 失效及 K 长度检查；双 pass 交错时不能仅按相同 K
命中。应分两份 cache，或同时检查 A 版本、pass、行和 group，防止错误 zero point 修正。

Q/K/V 或 gate/up 只有在输入数值、clipping、dtype、scale 算法和有效长度全部相同时才可
共享 A8 结果。长度相同不等于数据相同；共享只读参数也不等于共享可写归约状态。

Head 的各词表分段通常读取同一输入行，在上述条件满足时，应只形成一次 `q0/q1` 和
`s0/s1`，供所有分段重用；每段的归约和最终输出 scale 仍保持独立。不能为省指令而把
原 4096 列的输出统计改成全词表一次统计。是否只对少数敏感投影启用第二遍 A8，须由
独立精度实验确定；第一版应完整执行当前候选，再考虑选择性减少计算，不能静默关闭第二遍。

## 6. 计算、组缩放与最终输出的吞吐配比

以 SoC 1024 MAC/拍、K128/N16 为例，每组有 2048 MAC，理想 PE 服务时间为两拍。
当前 ACCUM 四 lane 至少需四个发射拍处理十六列；仅比较两级理想服务率，就不能持续
吸收每两拍一个 group。RTL 已支持叶模块 8/16 lane，但父控制、数组宽度、提交口和存储
必须一起修改，不能只把一个参数改成 8。

| 阶段 | 当前理想服务需求 | 建议评估 |
| --- | --- | --- |
| PE 组计算 | 2048/1024=2 拍/group | 保持现有 PE，先确认供数是否足够 |
| ACCUM | 16/4=4 发射拍/group | 评估 8 lane 与分 bank 的 wide 提交 |
| FINAL | 当前一路，16 列至少 16 个结果服务拍/tile | 评估两路与输出缓冲；REDUCE 也须计入 |
| Complex 普通写回 | 64 bit 最多两项 FP32/拍 | 融合与减少中间张量优先于盲目加 FMA |

这些都是局部理想下限，尚未包含填充/排空、profile、归约、零点修正、L1 冲突或命令切换。
例如 K=896 有七个 group，PE 理想计算十四拍；单 lane FINAL 的十六列服务本身就与它
相当。K=4864 有三十八个 group，PE 理想七十六拍，比例不同。双 A8 按两份工作分别计入。

ACCUM lane 0 当前与 REDUCE/FINAL 共享乘法器。只扩大 lane 数不会让三个阶段自动重叠；
需要有限的结果队列、独立 tile 状态和资源仲裁。建议先实现 ACCUM 与结果退休解耦，再由
实测 stall 选择 FINAL 并行数，保持 24-bit 有效 scale 乘法和现有溢出检查，不扩大成通用
128-bit 乘法器。

DDR 读取量要单独统计。双 A8 增加计算量不等于权重流量必然翻倍；有效 W8 Head 的两项
存储却确实增加字节，不能依靠重放 A 消掉。只有消除重复读后，才按有效 DDR 吞吐与总
计算工作分别估算时间；不由单项峰值保证 10 token/s。

## 7. Sampling 与持续会话

原生静态图当前将各 Head 分片交给 ARGMAX。这适合数值和速度诊断，不能用于宣称已经
复现官方 sampling。正式实现需保留 repetition penalty、temperature、Top-K、Top-P 和随机
状态；先只取原始 Top-K 再补 repetition penalty 可能丢失正确候选，处理次序必须明确。

候选的最终共享 INT16 scale 可使最终码可比较，但中间动态 scale 不同的片仍不能直接
比较。Top-K 的输入应是共同数值域，并保持索引与相等分数规则。Sampling 算术与 PRNG 的
选择也要先同步 CPU/CModel；它不是把现有 ARGMAX 更名即可完成的 RTL 修改。

CPU 可以处理串口字节、控制和明确规定的整数随机状态；张量搬运交给 DMA，模型浮点
计算交给 NPU。UART 输出可与下一 token 推理重叠，但下一 token 的计算必须等本次采样
确定输入 ID，不能把这一依赖隐藏在吞吐估计中。KV 的数据类型、32K 容量、实际长度和
各会话状态分别保留，不借固定前缀缓存掩盖真实 prefill。

## 8. 修改顺序与验证要求

| 顺序 | 修改范围 | 进入下一阶段的条件 |
| --- | --- | --- |
| 1 | CModel 长回答、事实保持与同历史 logits；补最终静态量化的硬件等价定义 | 无未解释的新增内容混淆，数值规则可执行 |
| 2 | 原生编译器与驱动：FP16 数值、双程序、宽缩放 Head、独立状态 | 静态指令 CModel 与 CPU 参考逐算子一致 |
| 3 | RTL 最小补齐：格式转换、确切 requant 规则及接口校验 | 小模块/整引擎与 CModel 位型一致 |
| 4 | 融合 A8 残差、A/B 独立上下文、B 重放与状态 cache | 数值不变，权重读取次数和等待拍有证据改善 |
| 5 | ACCUM/FINAL 配比与跨引擎流水 | 停顿计数改善，资源及 200 MHz OOC 满足要求 |
| 6 | DDR 时序模型 SoC：真实 prefill、持续三轮、UART 输出 | 回答、记忆和实际完整文字耗时分别验收 |

功能用例首先覆盖负数、零与负零、半整数及 tie、clipping、scale 下限、K/N 尾项、group
抵消与溢出、两 pass 相同 K 不同数据、独立状态、相同 token 重复输入、取消及随机反压。
两个 W4 项须与独立 INT8 点积参考一致；残差需与既有 FMA 位型一致；final scale 的统计
范围必须与模型包一致。对 Head 和敏感层，再做同历史 logits 与完整回答核验。

性能计数至少区分：有用权重字节、同地址重复读、B 驻留命中、PE 等待 A/B、等待组缩放、
等待结果退休、Complex 等待统计/公共 FMA/L1，以及 UART 完整输出周期。只检查程序正常
退出、token ID 相同或某个 MAC 流水达到 II=1，都不能替代这些验收。

新增模块按行缓存、转换、算术流水和控制拆分，使用规范 FIFO/RAM 和 package；单模块
不超过 1000 行非注释代码，公共端口及关键状态编写中文注释。CPU 和 SoC cache 设计不在
本次修改范围内。

建议将残差新增部分拆成 `npu_complex_a8_residual_stream`（阶段与请求控制）、
`npu_complex_a8_row_store`（同步行存储及信用）和可复用的整数码/浮点格式转换小模块。
Matrix 侧在现有 operand buffer 中分离 A/B 生命周期，由独立批次控制模块选择 pass，
group requant 只接收明确的 pass/context，不再把两套控制复制到一个大型 always 块。
这些是待实现的模块划分，不是当前已存在的文件。

## 9. 源码依据

- [动态 A8](../rtl/engines/complex/streams/npu_complex_dynamic_a8_stream.sv)、[FP32_MAC](../rtl/engines/complex/streams/npu_complex_fp32_mac_stream.sv)、[FP32 requant](../rtl/engines/complex/streams/npu_complex_fp32_requant_stream.sv)。
- [混合浮点流](../rtl/engines/complex/streams/npu_complex_mixed_fma_stream.sv)、[DMA 快速转换准入](../rtl/engines/dma/datapath/npu_dma_l1_convert_admission.sv)。
- [A/B 组缓冲](../rtl/engines/matrix/memory/npu_matrix_parallel_group_buffer.sv)、[PE bank](../rtl/engines/matrix/array/npu_matrix_parallel_pe_bank.sv)。
- [组缩放控制定义](../rtl/engines/matrix/group_requant/control/npu_matrix_group_requant_control_pkg.sv)、[组累加流水](../rtl/engines/matrix/group_requant/datapath/npu_matrix_group_requant_parallel_accum.sv)、[激活和 cache 控制](../rtl/engines/matrix/group_requant/control/npu_matrix_group_requant_accum_step.sv)。
- [高精度 CPU/CModel 运行程序](../compiler/examples/qwen3_int8/qwen3_chat_runtime.cpp)、[硬件算子程序](../compiler/examples/qwen3_int8/qwen_hardware_float_ops.hpp)、[量化包导出](../compiler/examples/qwen3_int8/export_awq_cpu_package.py)。
- [原生整模型编译器](../compiler/tvm_backend/qwen25_static_full_token.py)、[Matrix 现有设计与限制](module_spec/06_Matrix矩阵计算单元.md)。

## 10. 精确静态输出量化：QFR2 整数流水

### 10.1 与近似倒数模式的区别

`FP32_REQUANTIZE` 保留原操作码。64 byte 参数记录的 magic 为 `0x31524651` 时，继续使用
QFR1 的共享 RECIP、FP32 乘法和 F2I；为 `0x32524651` 时，选择 QFR2。两者的参数位置完全
相同，包含输出 scale 位串、zero point、激活下限及上限，其余保留字必须为零。编译器通过
`prepare_qfp32_requant_parameters(..., exact=True)` 明确选择新模式，不能让旧程序静默改变算法。

QFR2 对有限 binary32 输入和有限正 binary32 scale 执行

$$
q=\operatorname{clip}_{[q_{\min},q_{\max}]}
\left(\operatorname{RNE}_{\mathrm{even}}(x/s)+z\right).
$$

除法按两份 binary32 表示的精确有理数定义，不先形成近似倒数。zero point 在舍入后相加。
结果仅支持 INT8、INT16；NaN 或无穷输入报告数值异常，并且不提交该行的任何输出。
QFR1 的特殊值规则不变，两种模式不能混为同一种精度保证。

### 10.2 从 binary32 到整数商

把 normal 与 subnormal 的非零尾数统一规格化为 24 bit 整数 $m_x,m_s$，并校正相应指数，得到

$$
\frac{|x|}{s}=\frac{m_x}{m_s}2^{\Delta},\qquad
2^{23}\le m_x,m_s<2^{24}.
$$

若 $\Delta<-1$，比值严格小于 $1/2$，舍入整数为零；若 $\Delta\ge17$，比值大于 65536，
在合法 INT8/INT16 zero point 下必定饱和，可以用带符号的大整数代替后续除法。其余情况构造

$$
N=m_x2^{\max(\Delta,0)},\qquad
D=m_s2^{[\Delta=-1]}.
$$

依次处理商的第 16 位至第 0 位。每一级只执行 $N\ge D2^k$ 的比较、条件减法和商位设置，
级间寄存剩余数、除数及任务 tag。最后由整数商 $u$、余数 $r$ 执行一次 RNE：

$$
\widehat u=u+
\left[2r>D\ \lor\ (2r=D\land(u\bmod2=1))\right].
$$

剩余数寄存采用 41 bit，除数 25 bit，商 17 bit，舍入后幅值 18 bit；带 zero point 的公共
输出采用 34 bit，之后由现有激活范围检查裁剪。这些宽度针对 INT8/INT16 的输出范围推导，
不表示可以无条件用于 INT32 输出。零输入最终恢复成规范的正零。

### 10.3 流水、缓存和异常处理

[整数算术模块](../rtl/engines/complex/arithmetic/npu_complex_exact_requant_pipeline.sv)
包含规格化准备、分子/除数准备、17 级商位运算及最终舍入，共 20 个寄存阶段。单实例每拍
可接受一项；现有 64-bit Complex 输入中放置两份实例，对应每拍两项 FP32。无浮点乘法器、
倒数器或 FP64 硬件，QFR2 执行期间不会请求共享 FMA/RECIP。

两份结果通过原同步 RAM 保持，整行检查通过后才写回 L1。接收的数据与返回 tag 必须一一
对应；输入失败后停止新的读请求，并等待已接受请求和算术结果排空。数值异常报告具体
32-bit 元素地址，读访问错误报告 64-bit 请求地址。完成信息保持到下游接受。

当前只对齐单行高速流开放 QFR2：长度 16～256，输入与输出 8 byte 对齐，普通 INT8 长度
为 8 的倍数，INT16 或 compact-A 为 4 的倍数。输出不得覆盖输入或参数记录。其他形状由
编译器分片并补齐；不允许回退到 QFR1 的近似算法。流水 II=1 不等于整条指令每拍完成两项，
参数读取、启动、排空、整行写回以及共享 L1 端口仍产生额外周期。

### 10.4 CPU/CModel 使用与尚未完成的工作

硬件参考模式的 `quantize_static` 现在发出 QFR2，再使用 DMA 把 INT8/INT16 数值扩展到 INT32，
最后由实际 `FP32_MAC` 恢复 $\operatorname{FP32}(q\times s+0)$。不足一片的逻辑长度补零至
高速流要求，恢复时只取有效元素。CModel 用相同整数商位算法执行 QFR2，独立 Fraction
参考用于测试，不参与推理。旧浮点参考的宿主 double 计算仅用于对照。

模型参数中的常量计算、词表选择与 Top-K/Top-P sampling 仍须逐项检查。当前 sampling
仍含宿主浮点计算，原生 SoC 程序也尚未完整采用本候选；不能据此宣称完整对话只需已有 RTL
就可无修改部署。CModel 的功能调用耗时也不能代替真实指令取数、DMA 及流水周期测量。
逐项数值、完整 Complex 回归和单路 FPGA 实现结果见
[精确整数重量化验证记录](logs/精确整数重量化RTL与CModel验证_20261108.md)。
