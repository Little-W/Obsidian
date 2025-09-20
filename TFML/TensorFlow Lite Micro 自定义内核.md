# TensorFlow Lite Micro 自定义内核实现指南

  

基于对 CMSIS-NN 实现的分析和 TensorFlow Lite Micro (TFLM) 架构的研究，本文档总结了自定义内核需要实现的核心函数和接口。

## 1. 核心数据结构

### TFLMRegistration

```cpp

struct TFLMRegistration {

void* (*init)(TfLiteContext* context, const char* buffer, size_t length);

void (*free)(TfLiteContext* context, void* buffer);

TfLiteStatus (*prepare)(TfLiteContext* context, TfLiteNode* node);

TfLiteStatus (*invoke)(TfLiteContext* context, TfLiteNode* node);

void (*reset)(TfLiteContext* context, void* buffer);

int32_t builtin_code;

const char* custom_name;

};

```

## 2. 必需实现的函数

### 2.1 初始化函数 (Init)

**函数签名：**

```cpp

void* InitOp(TfLiteContext* context, const char* buffer, size_t length);

```

**功能：**

- 分配操作所需的持久内存

- 初始化操作数据结构

- 解析操作参数（如果有的话）

**实现要点：**

- 使用 `context->AllocatePersistentBuffer()` 分配内存

- 返回指向分配内存的指针，该指针将存储在 `node->user_data` 中

- 如果无需持久数据，可返回 `nullptr`

**示例：**

```cpp

void* InitAdd(TfLiteContext* context, const char* buffer, size_t length) {

TFLITE_DCHECK(context->AllocatePersistentBuffer != nullptr);

return context->AllocatePersistentBuffer(context, sizeof(OpData));

}

```

### 2.2 准备函数 (Prepare)

**函数签名：**

```cpp

TfLiteStatus PrepareOp(TfLiteContext* context, TfLiteNode* node);

```

**功能：**

- 验证输入输出张量的类型和形状

- 计算量化参数

- 预分配临时缓冲区

- 设置输出张量的形状和类型

**实现要点：**

- 使用 `micro_context->AllocateTempInputTensor()` 和 `micro_context->AllocateTempOutputTensor()` 获取张量信息

- 验证张量兼容性

- 计算量化相关参数

- 使用 `micro_context->DeallocateTempTfLiteTensor()` 释放临时张量

**示例：**

```cpp

TfLiteStatus PrepareAdd(TfLiteContext* context, TfLiteNode* node) {

TFLITE_DCHECK(node->user_data != nullptr);

TFLITE_DCHECK(node->builtin_data != nullptr);

  

MicroContext* micro_context = GetMicroContext(context);

  

TfLiteTensor* input1 = micro_context->AllocateTempInputTensor(node, 0);

TF_LITE_ENSURE(context, input1 != nullptr);

TfLiteTensor* input2 = micro_context->AllocateTempInputTensor(node, 1);

TF_LITE_ENSURE(context, input2 != nullptr);

TfLiteTensor* output = micro_context->AllocateTempOutputTensor(node, 0);

TF_LITE_ENSURE(context, output != nullptr);

  

// 验证张量类型

TF_LITE_ENSURE_EQ(context, input1->type, output->type);

TF_LITE_ENSURE_MSG(context, input1->type == input2->type,

"Hybrid models are not supported on TFLite Micro.");

  

// 计算操作数据

OpData* data = static_cast<OpData*>(node->user_data);

auto* params = reinterpret_cast<TfLiteAddParams*>(node->builtin_data);

TF_LITE_ENSURE_STATUS(

CalculateOpData(context, params, input1, input2, output, data));

  

micro_context->DeallocateTempTfLiteTensor(input1);

micro_context->DeallocateTempTfLiteTensor(input2);

micro_context->DeallocateTempTfLiteTensor(output);

  

return kTfLiteOk;

}

```

### 2.3 执行函数 (Eval/Invoke)

**函数签名：**

```cpp

TfLiteStatus EvalOp(TfLiteContext* context, TfLiteNode* node);

```


**功能：**

- 执行实际的计算操作

- 处理不同数据类型的分支

- 调用优化的计算内核（如 CMSIS-NN）

**实现要点：**

- 使用 `tflite::micro::GetEvalInput()` 和 `tflite::micro::GetEvalOutput()` 获取运行时张量

- 根据张量类型分支处理

- 调用相应的计算函数

- 处理广播等特殊情况

**示例：**

```cpp

TfLiteStatus EvalAdd(TfLiteContext* context, TfLiteNode* node) {

auto* params = reinterpret_cast<TfLiteAddParams*>(node->builtin_data);

  

const TfLiteEvalTensor* input1 = tflite::micro::GetEvalInput(context, node, 0);

const TfLiteEvalTensor* input2 = tflite::micro::GetEvalInput(context, node, 1);

TfLiteEvalTensor* output = tflite::micro::GetEvalOutput(context, node, 0);

  

TFLITE_DCHECK(node->user_data != nullptr);

const OpData* data = static_cast<const OpData*>(node->user_data);

  

if (output->type == kTfLiteFloat32 || output->type == kTfLiteInt32) {

TF_LITE_ENSURE_OK(context, EvalAdd(context, node, params, data, input1, input2, output));

} else if (output->type == kTfLiteInt8 || output->type == kTfLiteInt16) {

TF_LITE_ENSURE_OK(context, EvalAddQuantized(context, node, params, data, input1, input2, output));

} else {

MicroPrintf("Type %s (%d) not supported.", TfLiteTypeGetName(output->type), output->type);

return kTfLiteError;

}

  

return kTfLiteOk;

}

```

### 2.4 释放函数 (Free) - 可选


**函数签名：**

```cpp

void FreeOp(TfLiteContext* context, void* buffer);

```


**功能：**

- 释放在 Init 函数中分配的资源

- 清理操作特定的数据

**实现要点：**

- 通常在 TFLM 中不需要实现，因为使用的是持久缓冲区

- 如果有特殊资源管理需求才需要实现

### 2.5 重置函数 (Reset) - 可选

**函数签名：**

```cpp

void ResetOp(TfLiteContext* context, void* buffer);

```

**功能：**

- 重置操作的内部状态

- 主要用于有状态的操作（如 RNN）

## 3. 注册函数


每个操作需要提供注册函数来创建 `TFLMRegistration` 结构：

```cpp

TFLMRegistration Register_OP_NAME() {

return tflite::micro::RegisterOp(InitOp, PrepareOp, EvalOp);

}

  

// 对于特定数据类型的优化版本

TFLMRegistration Register_OP_NAME_INT8() {

return tflite::micro::RegisterOp(InitOp, PrepareOp, EvalOpInt8);

}

```

## 4. 辅助工具函数

### 4.1 张量访问函数

```cpp

// 获取输入张量

const TfLiteEvalTensor* input = tflite::micro::GetEvalInput(context, node, index);

  

// 获取输出张量

TfLiteEvalTensor* output = tflite::micro::GetEvalOutput(context, node, index);

  

// 获取张量数据

const float* input_data = tflite::micro::GetTensorData<float>(input);

float* output_data = tflite::micro::GetTensorData<float>(output);

  

// 获取张量形状

const RuntimeShape input_shape = tflite::micro::GetTensorShape(input);

```

### 4.2 量化相关函数

```cpp

// 计算量化乘数

QuantizeMultiplierSmallerThanOneExp(real_multiplier, &multiplier, &shift);

  

// 计算激活范围

CalculateActivationRangeQuantized(context, activation, output, &activation_min, &activation_max);

```

## 5. 最佳实践
### 5.1 错误处理


- 使用 `TF_LITE_ENSURE()` 宏进行条件检查

- 使用 `TF_LITE_ENSURE_STATUS()` 检查函数返回状态

- 使用 `MicroPrintf()` 输出错误信息
### 5.2 内存管理


- 优先使用持久缓冲区而非动态分配

- 在 Prepare 阶段分配临时张量并及时释放

- 避免在 Eval 阶段进行内存分配

### 5.3 性能优化

- 为不同数据类型提供专门的实现

- 利用硬件加速库（如 CMSIS-NN）

- 处理广播和特殊形状情况

- 考虑缓存友好的内存访问模式

### 5.4 类型支持

支持的主要数据类型：

- `kTfLiteFloat32`：32位浮点

- `kTfLiteInt8`：8位量化整数

- `kTfLiteInt16`：16位量化整数

- `kTfLiteInt32`：32位整数

## 6. 文件结构建议

典型的内核实现文件结构：

```

my_op.cc // 主实现文件

my_op.h // 头文件（如果需要）

my_op_test.cc // 单元测试

```

## 7. 集成到构建系统

在 CMakeLists.txt 或 Makefile 中添加：

```cmake

target_sources(tflite-micro PRIVATE

kernels/my_op.cc

)

```

## 8. 常见需要实现的层和操作


### 8.1 基础算术操作


这些是最常见的需要优化实现的操作：


**加法运算 (Add)**

- 支持元素级加法和广播加法

- 需要处理 int8、int16、float32 类型

- CMSIS-NN 提供：`arm_elementwise_add_s8()`, `arm_elementwise_add_s16()`


**乘法运算 (Mul)**

- 元素级乘法操作

- 量化参数处理复杂

- CMSIS-NN 提供：`arm_elementwise_mul_s8()`


**减法运算 (Sub)**

- 类似加法但需要处理负数

- 广播支持

### 8.2 激活函数

**ReLU 系列**

- ReLU: `max(0, x)`

- ReLU6: `min(6, max(0, x))`

- Leaky ReLU: `x > 0 ? x : alpha * x`


**其他激活函数**

- Sigmoid: `1 / (1 + exp(-x))`

- Tanh: `tanh(x)`

- Softmax: 归一化指数函数
### 8.3 卷积操作

**2D 卷积 (Conv2D)**

- 最重要的 CNN 操作

- CMSIS-NN 提供多种优化实现：

- `arm_convolve_s8()`

- `arm_convolve_1x1_s8_fast()` - 1x1 卷积优化

- `arm_convolve_wrapper_s8()` - 通用包装器

**深度可分离卷积 (DepthwiseConv2D)**

- MobileNet 等轻量模型的核心

- CMSIS-NN: `arm_depthwise_conv_s8()`

**转置卷积 (TransposeConv2D)**

- 上采样操作

- 语义分割等任务需要

### 8.4 池化操作

**平均池化 (AveragePool2D)**

- CMSIS-NN: `arm_avgpool_s8()`

**最大池化 (MaxPool2D)**

- CMSIS-NN: `arm_max_pool_s8()`

**全局平均池化 (GlobalAveragePool2D)**

- 替代全连接层减少参数

### 8.5 全连接层

**全连接 (FullyConnected)**

- 矩阵乘法的特殊形式

- CMSIS-NN: `arm_fully_connected_s8()`

### 8.6 标准化操作

**批归一化 (BatchNormalization)**

- 训练时常用，推理时可融合到卷积

- 需要处理 scale、offset、mean、variance

**层归一化 (LayerNormalization)**

- Transformer 模型必需

### 8.7 形状操作

**重塑 (Reshape)**

- 改变张量形状但保持元素总数

**转置 (Transpose)**

- 改变张量维度顺序

**连接 (Concatenation)**

- 沿指定轴连接多个张量

**分割 (Split)**

- 将张量沿指定轴分割

### 8.8 高级操作

**注意力机制相关**

- Multi-Head Attention

- Scaled Dot-Product Attention

**RNN/LSTM 相关**

- LSTM: 长短期记忆网络

- GRU: 门控循环单元

- CMSIS-NN 提供 LSTM 支持
### 8.9 量化相关操作

**量化 (Quantize)**

- 浮点到整数的转换

- 需要处理 scale 和 zero_point

**反量化 (Dequantize)**

- 整数到浮点的转换
### 8.10 实现优先级建议

**高优先级（必需）：**

1. Conv2D (int8/int16)

2. DepthwiseConv2D

3. FullyConnected

4. Add, Mul, Sub

5. ReLU, ReLU6

6. AveragePool2D, MaxPool2D

7. Reshape, Transpose


**中等优先级：**

1. BatchNormalization

2. Concatenation, Split

3. Softmax, Sigmoid

4. GlobalAveragePool2D


**低优先级（特殊需求）：**

1. LSTM, GRU

2. LayerNormalization

3. 自定义激活函数

4. TransposeConv2D

### 8.11 CMSIS-NN 支持情况

  

基于当前 TFLM 项目中实际使用的 CMSIS-NN 函数，支持的主要操作包括：

#### 8.11.1 卷积操作

```cpp

// 标准卷积

arm_convolve_wrapper_s8() // 8位卷积通用包装器

arm_convolve_1x1_s8_fast() // 1x1卷积优化版本

arm_convolve_s8() // 基础8位卷积

arm_convolve_s16() // 16位卷积


// 深度可分离卷积

arm_depthwise_conv_wrapper_s8() // 8位深度卷积包装器

arm_depthwise_conv_wrapper_s4() // 4位深度卷积包装器

arm_depthwise_conv_s16() // 16位深度卷积

  
// 转置卷积

arm_transpose_conv_wrapper_s8() // 8位转置卷积包装器

arm_transpose_conv_s8_get_buffer_size() // 获取缓冲区大小

arm_transpose_conv_s8_get_reverse_conv_buffer_size() // 获取反向卷积缓冲区大小

```

#### 8.11.2 全连接层

```cpp

arm_fully_connected_wrapper_s8() // 8位全连接包装器

arm_fully_connected_s8() // 8位全连接基础版本

arm_fully_connected_s4() // 4位全连接

arm_fully_connected_s16() // 16位全连接

arm_fully_connected_s8_get_buffer_size() // 获取8位全连接缓冲区大小

arm_fully_connected_s16_get_buffer_size() // 获取16位全连接缓冲区大小

```

#### 8.11.3 池化操作

```cpp

arm_avgpool_s8() // 8位平均池化

arm_avgpool_s16() // 16位平均池化

arm_maxpool_s8() // 8位最大池化

arm_maxpool_s16() // 16位最大池化

```

#### 8.11.4 激活函数

```cpp

arm_relu_q7() // 7位ReLU

arm_relu_q15() // 15位ReLU

arm_softmax_s8() // 8位Softmax

arm_softmax_s8_s16() // 8位输入16位输出Softmax

arm_softmax_s16() // 16位Softmax

```

#### 8.11.5 算术运算

```cpp

arm_elementwise_add_s8() // 8位元素级加法

arm_elementwise_add_s16() // 16位元素级加法

arm_elementwise_mul_s8() // 8位元素级乘法

arm_elementwise_mul_s16() // 16位元素级乘法

arm_maximum_s8() // 8位最大值

arm_minimum_s8() // 8位最小值

```

#### 8.11.6 形状操作

```cpp

arm_transpose_s8() // 8位转置

arm_pad_s8() // 8位填充

```

#### 8.11.7 循环神经网络

```cpp

arm_lstm_unidirectional_s8() // 8位单向LSTM

arm_lstm_unidirectional_s16() // 16位单向LSTM

arm_svdf_s8() // 8位SVDF

arm_svdf_state_s16_s8() // 16位状态8位SVDF

arm_svdf_s8_get_buffer_size() // 获取SVDF缓冲区大小

```

#### 8.11.8 矩阵操作

```cpp

arm_batch_matmul_s8() // 8位批量矩阵乘法

arm_batch_matmul_s16() // 16位批量矩阵乘法

```

#### 8.11.9 辅助函数

```cpp

arm_vector_sum_s8() // 8位向量求和

arm_vector_sum_s8_s64() // 8位向量求和64位累加

arm_nn_mat_mult_kernel_q7_q15() // q7-q15矩阵乘法内核

arm_nn_mat_mult_kernel_q7_q15_reordered() // 重排序矩阵乘法内核

```

#### 8.11.10 传统CMSIS-NN函数（v1.0兼容）

```cpp

arm_convolve_HWC_q7_basic() // HWC格式基础q7卷积

arm_convolve_HWC_q7_fast() // HWC格式快速q7卷积

arm_convolve_HWC_q15_basic() // HWC格式基础q15卷积

arm_convolve_HWC_q15_fast() // HWC格式快速q15卷积

arm_depthwise_separable_conv_HWC_q7() // HWC格式深度可分离卷积

arm_maxpool_q7_HWC() // HWC格式q7最大池化

arm_avepool_q7_HWC() // HWC格式q7平均池化

arm_softmax_q7() // q7 Softmax

arm_softmax_q15() // q15 Softmax

```

## 9. 示例：完整的操作实现框架

```cpp

#include "tensorflow/lite/micro/kernels/kernel_util.h"

#include "tensorflow/lite/micro/micro_log.h"

  

namespace tflite {

  

namespace {

constexpr int kInputTensor = 0;

constexpr int kOutputTensor = 0;

  

struct OpData {

// 操作特定的数据

};

  

void* InitMyOp(TfLiteContext* context, const char* buffer, size_t length) {

TFLITE_DCHECK(context->AllocatePersistentBuffer != nullptr);

return context->AllocatePersistentBuffer(context, sizeof(OpData));

}

  

TfLiteStatus PrepareMyOp(TfLiteContext* context, TfLiteNode* node) {

// 实现准备逻辑

return kTfLiteOk;

}

  

TfLiteStatus EvalMyOp(TfLiteContext* context, TfLiteNode* node) {

// 实现执行逻辑

return kTfLiteOk;

}

  

} // namespace

  

TFLMRegistration Register_MY_OP() {

return tflite::micro::RegisterOp(InitMyOp, PrepareMyOp, EvalMyOp);

}

  

} // namespace tflite

```

这个框架提供了实现 TFLM 自定义内核的完整指导，确保与现有的 CMSIS-NN 实现保持一致的架构和最佳实践。