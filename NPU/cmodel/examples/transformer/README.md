# Keras 双编码器 Transformer 端到端测试

本目录提供一个面向房间设备命令分类的完整示例。`build_model.py` 使用 Keras `model.fit()` 训练模型，导出含两个 Transformer 编码器的 `.keras` 文件；通用模型编译器生成 C 配置、参数内嵌的 CMD128 数组、权重和输入输出信息；C runner 通过 NPU 驱动提交命令，再从 CModel 的系统内存读取三个输出。

> [!important] 参考结果不会写入 CModel 输出
> `keras_transformer_test_data.h` 中的 Keras 探针值和分类分数只供主控程序比较。runner 初始化系统内存时只复制训练得到的权重、当前语句的词特征和位置特征，绝不把 Keras 预期数据复制到三个 CModel 输出地址。输出必须由本次生成的 CMD128 全部执行后产生。

## 1. 应用目标

模型接收一条英文房间设备命令，把整句分成四类：

| 类别编号 | 类别名 | 含义 | 留出语句示例 |
| ---: | --- | --- | --- |
| 0 | `light_on` | 打开灯 | `please lamp enable now` |
| 1 | `light_off` | 关闭灯 | `in living turn off light` |
| 2 | `fan_on` | 打开风扇 | `room fan on` |
| 3 | `fan_off` | 关闭风扇 | `make blower off immediately` |

语句的词序和长度可以变化。设备词有 `light/lamp`、`fan/blower` 等同义表达，状态既可以写成 `on/off`，也可以用 `enable/activate`、`disable/deactivate` 表示。模型需要综合设备、状态、动作和上下文，而不是只记住固定位置。

## 2. 训练语料和留出语料

训练脚本使用固定随机种子 `20260726` 生成 192 条训练语句，每类 48 条。语料由以下要素组合：

- 设备：`light`、`lamp`、`fan`、`blower`；
- 普通动作：`turn`、`set`、`switch`；
- 打开动作：`enable`、`activate`；
- 关闭动作：`disable`、`deactivate`；
- 上下文：`please`、`now`、`immediately`、`room`、`bedroom`、`living` 等；
- 8 种主要语序模板，以及 4 种状态动作模板。

训练语句含 4～6 个有效 token。另有 24 条留出语句，每类 6 条，含 3～5 个有效 token。留出语句的完整词序没有出现在训练集合中，脚本会直接检查两组语句不存在重复。

留出语句使用的六类结构如下，其中 `device`、`synonym`、`state` 和 `state_action` 会按类别替换：

```text
device state please
immediately switch the synonym state
in living turn state device
please synonym state_action now
room device state
make synonym state immediately
```

> [!note] 标签如何生成
> 每条语句的标签由“设备类型 + 开关状态”决定。`light/lamp` 与打开状态组成 `light_on`，与关闭状态组成 `light_off`；`fan/blower` 采用相同规则。礼貌词、位置词和执行时间不会改变标签。

## 3. 24 词词表

词表含 `<pad>` 在内的 24 个词项：

| 编号 | token | 含义 |
| ---: | --- | --- |
| 0 | `<pad>` | 右侧补齐位置，没有源单词 |
| 1 | `please` | 礼貌请求 |
| 2 | `turn` | 请求改变开关状态 |
| 3 | `set` | 设置指定状态 |
| 4 | `switch` | 切换或指定设备状态 |
| 5 | `make` | 使设备进入指定状态 |
| 6 | `enable` | 请求打开 |
| 7 | `activate` | `enable` 的同义表达 |
| 8 | `disable` | 请求关闭 |
| 9 | `deactivate` | `disable` 的同义表达 |
| 10 | `light` | 灯 |
| 11 | `lamp` | `light` 的同义表达 |
| 12 | `fan` | 风扇 |
| 13 | `blower` | `fan` 的同义表达 |
| 14 | `on` | 打开状态 |
| 15 | `off` | 关闭状态 |
| 16 | `now` | 现在执行 |
| 17 | `immediately` | 立即执行 |
| 18 | `room` | 当前房间 |
| 19 | `bedroom` | 卧室 |
| 20 | `living` | 客厅相关词 |
| 21 | `the` | 英文冠词 |
| 22 | `in` | 位置介词 |
| 23 | `device` | 通用设备词 |

## 4. 两个输入张量

单次推理固定容纳 8 个 token，模型宽度为 32。词特征和位置特征不是在软件中预先相加，而是作为两个独立输入交给 NPU：

| 输入 | 形状 | 每个 token 的内容 |
| --- | --- | --- |
| `word_features` | `[1,8,32]` | 前 24 个分量保存词项 one-hot，后 8 个分量为 0 |
| `position_features` | `[1,8,32]` | 前 24 个分量为 0，后 8 个分量保存位置值 |

### 4.1 词特征

有效 token 的 one-hot 幅值是 0.75。Q5 的步长是 $1/32$，所以设备中保存的非零 INT8 值为：

$$
0.75\times32=24.
$$

例如 `light` 的编号是 10，因此其 32 元词特征只有第 10 个分量为 24，其余分量为 0。

### 4.2 正弦和余弦位置特征

位置编号记为 $p=0,1,\ldots,7$。对 $j=0,1,2,3$：

$$
P_{p,2j}
=
0.25\sin\left(
\frac{p}{10000^{2j/8}}
\right),
$$

$$
P_{p,2j+1}
=
0.25\cos\left(
\frac{p}{10000^{2j/8}}
\right).
$$

八个值按 Q5 取整后放在 `position_features` 的最后八个分量。前两个位置的实际 INT8 数据示例为：

```text
position 0: [0, 8, 0, 8, 0, 8, 0, 8]
position 1: [7, 4, 1, 8, 0, 8, 0, 8]
```

NPU 首先执行：

$$
X=E+P,
$$

其中 $E$ 是词特征，$P$ 是位置特征。相同单词位于不同位置时，进入注意力层的 $X$ 不同，因此网络能够利用词序。

### 4.3 padding 的处理

较短语句在右侧补 `<pad>` 直到 8 个位置。padding 行的词特征和位置特征全部为 0。训练时，这些位置的 MSE 权重为 0；计算整句类别时，runner 也只使用前 $L$ 个有效 token，$L$ 是语句真实长度。

当前模型没有额外的 `attention_mask` 输入。这里采用“padding 输入为零，训练和分类忽略 padding 输出”的方式。注意力仍可能在 padding 行产生非零结果，所以 runner 会清楚标出每个位置是 `valid` 还是 `padding`，但 padding 结果不会参与整句平均值。

## 5. 双编码器模型结构

完整结构如下：

```text
word_features [1,8,32] ─┐
                        ├─ Add ─ Encoder 1 ─ Encoder 2 ─ Dense(4, Linear)
position_features ──────┘            │           │              │
                                     ├─ probe 1  ├─ probe 2     └─ logits
                                     [1,8,32]    [1,8,32]       [1,8,4]
```

每个编码器的宽度为 32，含 4 个注意力 head，每个 head 宽度为 8；前馈网络宽度为 48。每个编码器依次执行：

```text
MultiHeadAttention(4 heads, key_dim=8, use_bias=False)
  -> residual Add
  -> LayerNorm
  -> Dense(48, GELU)
  -> Dense(32, Linear)
  -> residual Add
  -> LayerNorm
```

### 5.1 多头注意力

输入 $X\in\mathbb{R}^{8\times32}$ 先得到 Q、K、V：

$$
Q=XW_Q,\qquad K=XW_K,\qquad V=XW_V.
$$

Q、K、V 都被整理成 4 个 `[8,8]` 的 head。每个 head 计算：

$$
S
=
\frac{QK^\mathsf{T}}{\sqrt{8}},
$$

$$
A=\operatorname{softmax}(S),
$$

$$
H=AV.
$$

$S$ 和 $A$ 的形状都是 `[8,8]`。第一个维度表示正在更新的 token，第二个维度表示它参考的 token。四个 $H$ 合并成 `[8,32]`，再经过输出投影。

### 5.2 残差、LayerNorm 和前馈网络

注意力结果先与输入相加：

$$
N_1=\operatorname{LayerNorm}(X+\operatorname{MHA}(X)).
$$

LayerNorm 的 $\gamma$ 和 $\beta$ 形状均为 `[32]`。同一组参数用于所有 8 个 token，但每个 token 根据自己的 32 个特征计算均值和方差。

前馈网络为：

$$
F
=
W_2\operatorname{GELU}(N_1W_1+b_1)+b_2,
$$

其中 $W_1$ 是 `[32,48]`，$b_1$ 是 `[48]`，$W_2$ 是 `[48,32]`，$b_2$ 是 `[32]`。第二次残差相加与 LayerNorm 得到编码器输出：

$$
X_{\text{out}}
=
\operatorname{LayerNorm}(N_1+F).
$$

### 5.3 参数规模

| 部分 | 参数数 |
| --- | ---: |
| 每个 4-head 注意力层 | 4096 |
| 每个 32→48→32 前馈网络 | 3152 |
| 每个编码器的两组 LayerNorm | 128 |
| 两个完整编码器 | 14752 |
| `Dense(32,4,Linear)` | 132 |
| 合计 | 14884 |

注意力层设置 `use_bias=False`。分类层权重为 `[32,4]`，bias 为 `[4]`；四个 bias 分量分别加到四类分数。

## 6. 三个输出探针

导出的 Keras 模型不是只保留末尾结果，而是保留三个输出：

| 输出 | 系统内存形状 | 元素数 | 作用 |
| --- | --- | ---: | --- |
| `model_output_0` | `[1,8,32]` | 256 | 第一编码器探针 |
| `model_output_1` | `[1,8,32]` | 256 | 第二编码器探针 |
| `model_output_2` | `[1,8,4]` | 32 | 每个 token 的四类分数 |

若末尾分类不一致，两个中间探针可以帮助判断差异首先出现在第一编码器、第二编码器还是分类层。runner 对三个输出分别统计完全相同的元素数、容许误差内的元素数、最大绝对误差、平均绝对误差、均方误差、最小值、最大值、均值、标准差、INT8 两端值数量和不同数值数量。

## 7. 有效 token 的整句分类

第 $p$ 个 token 的四类线性分数记为 $\boldsymbol{z}_p$，有效 token 数记为 $L$。Keras 检查程序和 C runner 都计算：

$$
\overline{\boldsymbol{z}}
=
\frac{1}{L}
\sum_{p=0}^{L-1}\boldsymbol{z}_p.
$$

只使用 $0$ 到 $L-1$，不读取右侧 padding 的分类分数。$\overline{\boldsymbol{z}}$ 的四个分量依次对应 `light_on`、`light_off`、`fan_on` 和 `fan_off`，最大分量所在位置就是整句类别。

训练目标不是简单的 $\pm1$。真实类别 $c^\ast$ 在有效位置 $p$ 的目标为：

$$
y_{p,c^\ast}
=
0.56+0.018L+0.012p,
$$

其余类别 $c$ 的目标为：

$$
y_{p,c}
=
-0.24+0.018c-0.008p+0.004L.
$$

这些目标保留了不同 token 和不同类别之间的数值差异。

## 8. 线性 logits 和数值分布检查

末尾使用 `Dense(4, activation="linear")`，没有 Tanh。这样输出可以大于 1 或小于 -1，不会被 Tanh 压到接近 $\pm1$ 的狭小区域。绝对值不小于 0.95 只作为分布检查阈值，并不是 Linear 的截断上限。

构建脚本要求：

- 三个输出的 INT8 两端值比例不超过 1%；
- 每个输出至少出现 16 种 INT8 数值；
- 每个输出的标准差不小于 0.08；
- 最终分数中绝对值不小于 0.95 的比例不超过 35%；
- 留出语句的第一名与第二名平均分之差不小于 0.12；
- 所有训练权重位于 Q5 INT8 可表示的 `[-4,3.96875]` 范围。

当前 Keras 训练报告中的最终分数分布为：

| 项目 | 结果 |
| --- | ---: |
| 最小值 / 最大值 | -0.6558433 / 1.2765224 |
| 均值 / 标准差 | 0.0041330 / 0.5127850 |
| 绝对值不小于 0.95 | 74 / 768 |
| INT8 两端值 | 0 / 768 |
| 不同 INT8 数值 | 44 |
| 最小第一名分差 / 平均第一名分差 | 0.7661784 / 0.8651000 |
| 训练后权重范围 | `[-0.3824434,1.1463985]` |

## 9. 训练配置和 Keras 结果

训练采用：

- TensorFlow 2.18.0、Keras 3.6.0；
- 固定随机种子 `20260726`；
- Adam，学习率 0.003；
- MSE；
- batch size 16；
- 100 个 epoch；
- 有参数层使用 $2\times10^{-5}$ 的 L2 系数；
- padding 位置的样本权重为 0。

`/tmp/transformer_final_test.log` 中的实际结果为：

| 项目 | 结果 |
| --- | ---: |
| 训练语句 | 192 |
| 留出语句 | 24 |
| 初始 loss | 1.5257810 |
| 最终 loss | 0.0034489 |
| 训练语句整句 accuracy | 192 / 192 |
| 留出语句整句 accuracy | 24 / 24 |

## 10. 编译后的算子和 CMD128

编译器读取 `.keras` 后识别 33 个高层算子：

| 高层算子 | 数量 |
| --- | ---: |
| `MultiHeadAttention` | 2 |
| `LayerNorm` | 4 |
| `MatMul` | 5 |
| `Add` | 10 |
| `GELU` | 2 |
| `Reshape` | 10 |

它们被展开为：

| CMD128 操作 | 数量 | 主要用途 |
| --- | ---: | --- |
| `GEMM` | 13 | Q/K/V、注意力输出、两组前馈网络和分类层 |
| `BMM` | 4 | 两次 $QK^\mathsf{T}$ 与两次 $AV$ |
| `SOFTMAX` | 2 | 两个编码器的注意力权重 |
| `NORM` | 4 | 四次 LayerNorm |
| `ACT` | 2 | 两次 GELU |
| `ADD` | 10 | 位置相加、残差相加和 bias 加法 |
| `PACK` | 8 | 整理四个 head 的 Q |
| `TRANSPOSE_2D` | 8 | 转置四个 head 的 K |
| `SPLIT` | 8 | 合并各 head 的注意力结果 |
| `COPY_ND` | 13 | 输入、V head 数据和三个输出 |
| `COPY_1D` | 11 | 常量及形状整理 |
| `EVENT_JOIN` | 48 | 合并两个前置事件 |
| 合计 | 131 |  |

每组最多提交 8 条命令。前 16 组各有 8 条，最后一组有 3 条，因此每条语句使用 17 个 64-bit FIXED burst。每条 CMD128 使用低 64 bit 和高 64 bit 两个 beat，所以一条语句提交 262 个 beat。

第一条留出语句会打印 131 条任务的名称、命令编号、两个 wait event、signal event、提交响应、完成状态和 ACK。后续 23 条语句执行相同命令，为避免重复大量文字，只打印输入、探针比较和分类结果。

## 11. 当前系统内存地址

当前编译产物声明：

| 内容 | 地址 | 字节数 | 形状 |
| --- | ---: | ---: | --- |
| 权重 | `0x20000` | 16192 B | Q5 INT8 及对齐填充 |
| `word_features` | `0x23f40` | 256 B | `[1,8,32]` |
| `position_features` | `0x24040` | 256 B | `[1,8,32]` |
| 第一编码器探针 | `0x24140` | 256 B | `[1,8,32]` |
| 第二编码器探针 | `0x24240` | 256 B | `[1,8,32]` |
| `intent_logits` | `0x24340` | 32 B | `[1,8,4]` |

每条语句开始前，runner 清空 L1 和系统内存，复制权重和两个输入，再执行缓存同步。三个输出区域保持为清零后的内容，直到 NPU CModel 根据命令写入计算结果。命令采用 `cmd128-inline-v2`，操作参数直接放在 CMD128 中，manifest 的 `external_descriptor_bytes` 为 0。

## 12. 软件与 NPU 的任务分配

### 12.1 软件负责

- 用 Keras 训练并保存模型；
- 生成训练语料、留出语料、词特征和位置特征；
- 调用通用模型编译器；
- 把权重和两个当前输入复制到编译器声明的地址；
- 调用 `npu_drv_sync_for_device()`；
- 通过 `npu_drv_submit_batch()` 提交 17 组命令；
- 对每条任务执行 WAIT、QUERY 和 ACK，最后执行 FENCE；
- 对三个输出调用 `npu_drv_sync_for_cpu()`；
- 只平均有效 token 的四类分数并选择类别；
- 把 CModel 结果与 Keras 参考数据比较。

### 12.2 NPU CModel 负责

- 读取词特征、位置特征和训练权重；
- 执行输入相加；
- 执行两个完整的多头注意力编码器；
- 执行残差相加、LayerNorm、GELU 和前馈网络；
- 计算第一编码器探针、第二编码器探针和最终线性分数；
- 把三个输出写到各自的系统内存地址。

Softmax、LayerNorm 和 GELU 等复杂函数按 `INT8 → FP32 → INT8` 处理，FP32 只作为函数计算中的临时数值。

## 13. 运行方法

TensorFlow 和 Keras 使用 Conda 环境 `tf_2_18`：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/transformer"
make clean
make test
```

也可以分步执行：

```bash
make model
make compile
make check
make test
```

- `make model`：训练 Keras 模型，生成 `.keras`、测试数据头文件和训练报告；
- `make compile`：生成 C 模型包和 manifest；
- `make check`：再次运行编译器并比较文件摘要，同时以严格警告参数检查生成的 C 源码；
- `make test`：编译 runner，运行 24 条留出语句并执行全部检查；
- `make test-sanitize`：使用 AddressSanitizer 和 UndefinedBehaviorSanitizer 运行同一组测试；
- `make regress`：依次使用 GCC、Clang 和 Sanitizer。

## 14. 实际端到端结果

以下数据来自 `/tmp/transformer_final_test.log`。

### 14.1 分类结果

| 项目 | 结果 |
| --- | ---: |
| Keras 整句 accuracy | 24 / 24 = 1.0000000 |
| CModel 整句 accuracy | 24 / 24 = 1.0000000 |
| CModel 与 Keras 类别一致 | 24 / 24 = 1.0000000 |
| Keras 最小第一名分差 | 0.7656250 |
| CModel 最小第一名分差 | 0.4479167 |

### 14.2 三个输出的数值比较

| 输出 | 完全相同 | 全部通过的误差限制 | 最大误差 | MAE | MSE |
| --- | ---: | ---: | ---: | ---: | ---: |
| 第一编码器探针 | 506 / 6144 | 6144 / 6144 在 52 LSB 内 | 50 LSB | 6.3338216 LSB | 88.1124674 LSB² |
| 第二编码器探针 | 559 / 6144 | 6144 / 6144 在 30 LSB 内 | 28 LSB | 3.8632812 LSB | 27.8388672 LSB² |
| `intent_logits` | 70 / 768 | 768 / 768 在 20 LSB 内 | 18 LSB | 4.2109375 LSB | 29.1484375 LSB² |

CModel 输出分布为：

| 输出 | 最小值 | 最大值 | 均值 | 标准差 | INT8 两端值 | 绝对值不小于 0.95 | 不同 INT8 值 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 第一编码器探针 | -2.7500000 | 3.9687500 | -0.0021159 | 1.0413437 | 2 / 6144 | 1995 / 6144 | 195 |
| 第二编码器探针 | -2.3437500 | 2.2812500 | -0.0052338 | 0.9717475 | 0 / 6144 | 2016 / 6144 | 145 |
| `intent_logits` | -0.8125000 | 1.5625000 | 0.0241292 | 0.4842478 | 0 / 768 | 38 / 768 | 58 |

### 14.3 驱动与 CModel 统计

| 项目 | 每条语句 | 24 条语句合计 |
| --- | ---: | ---: |
| CMD128 | 131 | 3144 |
| 64-bit beat | 262 | 6288 |
| 提交批次 | 17 | 408 |
| 完成响应 | 131 | 3144 |
| CModel 周期 | 16291 | 390984 |
| cache clean | 4 | 96 |
| cache invalidate | 3 | 72 |

末尾成功信息为：

```text
classification_metrics CModel_accuracy=24/24=1.0000000 Keras_accuracy=24/24=1.0000000 agreement=24/24=1.0000000 Keras_min_margin=0.7656250 CModel_min_margin=0.4479167
CModel_vs_Keras tensor=encoder1_probe exact=506/6144 within_52_lsb=6144/6144 max_abs_error_lsb=50 mae_lsb=6.3338216 mse_lsb2=88.1124674
CModel_vs_Keras tensor=encoder2_probe exact=559/6144 within_30_lsb=6144/6144 max_abs_error_lsb=28 mae_lsb=3.8632812 mse_lsb2=27.8388672
CModel_vs_Keras tensor=intent_logits exact=70/768 within_20_lsb=768/768 max_abs_error_lsb=18 mae_lsb=4.2109375 mse_lsb2=29.1484375
PASS model=keras_transformer_intent_classifier commands_per_sample=131 cmd_bits=128 batches_per_sample=17 samples=24 submitted_bursts=408 submitted_beats=6288 responses=3144 cycles=390984
```

## 15. 相关生成文件

| 文件 | 内容 |
| --- | --- |
| `build/generated/keras_transformer.keras` | 训练后的双编码器 Keras 模型 |
| `build/generated/keras_transformer_report.json` | 语料、训练指标、Keras 三输出和分布统计 |
| `build/generated/keras_transformer_test_data.h` | 两个输入、三个 Keras INT8 参考输出、token、有效长度和标签 |
| `build/generated/keras_transformer_model.h` | 编译器生成的类型、尺寸、地址和数组声明 |
| `build/generated/keras_transformer_model.c` | 参数内嵌的 CMD128、权重、输入输出信息和提交分组 |
| `build/generated/keras_transformer.manifest.json` | 高层算子、低层操作、命令组、字节数和文件摘要 |
| `build/transformer_runner` | C 驱动加 CModel 的端到端程序 |

RNN、GRU、LSTM 和 CNN 的示例见 [`../README.md`](../README.md)。
