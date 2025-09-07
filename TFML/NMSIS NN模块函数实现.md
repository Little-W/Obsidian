# NMSIS NN模块函数实现与向量加速分析报告

  ## 项目概述

  NMSIS (Nuclei Microcontroller Software Interface Standard) 是基于RISC-V的微控制器软件接口标准，其NN(Neural Network)模块提供了神经网络推理所需的各种函数实现。

  ## 统计概览

  - **总函数文件数**: 153个
- **支持向量加速的函数文件数**: 54个
- **向量加速覆盖率**: 35.3%

## 按功能模块分类分析
### 1. ActivationFunctions (激活函数)

- **函数总数**: 6个
- **向量加速函数数**: 5个
- **加速覆盖率**: 83.3%
#### 函数列表:

- ✅ **riscv_nn_activation_s16** (支持向量加速)
- ✅ **riscv_nn_activations_q15** (支持向量加速)
- ✅ **riscv_nn_activations_q7** (支持向量加速)
- ✅ **riscv_relu6_s8** (支持向量加速)
- ✅ **riscv_relu_q15** (支持向量加速)
- ✅ **riscv_relu_q7** (支持向量加速)

### 2. BasicMathFunctions (基础数学函数)

- **函数总数**: 9个
- **向量加速函数数**: 4个
- **加速覆盖率**: 44.4%
#### 函数列表:

- ✅ **riscv_elementwise_add_s16** (支持向量加速)
- ✅ **riscv_elementwise_add_s8** (支持向量加速)
- riscv_elementwise_mul_acc_s16
- riscv_elementwise_mul_s16_batch_offset
- ✅ **riscv_elementwise_mul_s16** (支持向量加速)
- riscv_elementwise_mul_s16_s8
- ✅ **riscv_elementwise_mul_s8** (支持向量加速)
- riscv_maximum_s8
- riscv_minimum_s8
### 3. ConcatenationFunctions (连接函数)

- **函数总数**: 4个
- **向量加速函数数**: 0个
- **加速覆盖率**: 0%
#### 函数列表:

- riscv_concatenation_s8_w
- riscv_concatenation_s8_x
- riscv_concatenation_s8_y
- riscv_concatenation_s8_z
### 4. ConvolutionFunctions (卷积函数)

- **函数总数**: 53个
- **向量加速函数数**: 15个
- **加速覆盖率**: 28.3%
#### 主要向量加速函数:

- ✅ **riscv_convolve_1x1_HWC_q7_fast_nonsquare** (支持向量加速)
- ✅ **riscv_convolve_HWC_q15_fast_nonsquare** (支持向量加速)
- ✅ **riscv_convolve_HWC_q7_basic** (支持向量加速)
- ✅ **riscv_convolve_HWC_q7_basic_nonsquare** (支持向量加速)
- ✅ **riscv_convolve_HWC_q7_fast** (支持向量加速)
- ✅ **riscv_convolve_HWC_q7_fast_nonsquare** (支持向量加速)
- ✅ **riscv_convolve_HWC_q7_RGB** (支持向量加速)
- ✅ **riscv_convolve_s8** (支持向量加速)
- ✅ **riscv_depthwise_conv_s8_opt** (支持向量加速)
- ✅ **riscv_depthwise_separable_conv_HWC_q7_nonsquare** (支持向量加速)

### 5. FullyConnectedFunctions (全连接函数)

- **函数总数**: 17个
- **向量加速函数数**: 6个
- **加速覆盖率**: 35.3%
#### 向量加速函数:

- ✅ **riscv_fully_connected_mat_q7_vec_q15** (支持向量加速)
- ✅ **riscv_fully_connected_mat_q7_vec_q15_opt** (支持向量加速)
- ✅ **riscv_fully_connected_q15** (支持向量加速)
- ✅ **riscv_fully_connected_q15_opt** (支持向量加速)
- ✅ **riscv_fully_connected_q7** (支持向量加速)
- ✅ **riscv_fully_connected_q7_opt** (支持向量加速)
### 6. LSTMFunctions (LSTM函数)

- **函数总数**: 2个
- **向量加速函数数**: 0个
- **加速覆盖率**: 0%
#### 函数列表:

- riscv_lstm_unidirectional_s16
- riscv_lstm_unidirectional_s8

### 7. NNSupportFunctions (NN支持函数)

- **函数总数**: 41个
- **向量加速函数数**: 15个
- **加速覆盖率**: 36.6%
#### 主要向量加速函数:

- ✅ **riscv_nn_accumulate_q7_to_q15** (支持向量加速)
- ✅ **riscv_nn_fill_q15** (支持向量加速)
- ✅ **riscv_nn_fill_q7** (支持向量加速)
- ✅ **riscv_nn_mult_q15** (支持向量加速)
- ✅ **riscv_nn_mult_q7** (支持向量加速)
- ✅ **riscv_nn_vec_mat_mult_t_s8** (支持向量加速)
- ✅ **riscv_nn_vec_mat_mult_t_svdf_s8** (支持向量加速)
- ✅ **riscv_q7_to_q15_with_offset** (支持向量加速)
- ✅ **riscv_q7_to_q7_no_shift** (支持向量加速)
- ✅ **riscv_q7_to_q7_reordered_no_shift** (支持向量加速)
### 8. PadFunctions (填充函数)

- **函数总数**: 1个
- **向量加速函数数**: 0个
- **加速覆盖率**: 0%
#### 函数列表:

- riscv_pad_s8
### 9. PoolingFunctions (池化函数)

- **函数总数**: 7个
- **向量加速函数数**: 4个
- **加速覆盖率**: 57.1%

#### 向量加速函数:

- ✅ **riscv_avgpool_s8** (支持向量加速)
- ✅ **riscv_max_pool_s8** (支持向量加速)
- ✅ **riscv_pool_q7_HWC** (支持向量加速)
### 10. ReshapeFunctions (重塑函数)

- **函数总数**: 1个
- **向量加速函数数**: 0个
- **加速覆盖率**: 0%
#### 函数列表:

- riscv_reshape_s8

### 11. SoftmaxFunctions (Softmax函数)

- **函数总数**: 8个
- **向量加速函数数**: 4个
- **加速覆盖率**: 50%

#### 向量加速函数:

- ✅ **riscv_nn_softmax_common_s8** (支持向量加速)
- ✅ **riscv_softmax_q15** (支持向量加速)
- ✅ **riscv_softmax_q7** (支持向量加速)
- ✅ **riscv_softmax_u8** (支持向量加速)

### 12. SVDFunctions (SVD函数)

- **函数总数**: 3个
- **向量加速函数数**: 1个
- **加速覆盖率**: 33.3%

#### 向量加速函数:

- ✅ **riscv_svdf_s8** (支持向量加速)

### 13. TransposeFunctions (转置函数)

- **函数总数**: 1个
- **向量加速函数数**: 0个
- **加速覆盖率**: 0%

#### 函数列表:

- riscv_transpose_s8

## 向量加速技术分析

### 使用的RISC-V向量扩展指令

NMSIS NN模块中使用了丰富的RISC-V向量扩展(RVV)指令，主要包括：

#### 1. 向量配置指令

- `__riscv_vsetvl_e8m8()` - 设置向量长度(8位元素，8倍LMUL)
- `__riscv_vsetvl_e16m4()` - 设置向量长度(16位元素，4倍LMUL)
- `__riscv_vsetvl_e32m1()` - 设置向量长度(32位元素，1倍LMUL)

#### 2. 向量加载/存储指令

- `__riscv_vle8_v_i8m8()` - 加载8位整数向量
- `__riscv_vle16_v_i16m4()` - 加载16位整数向量
- `__riscv_vse8_v_i8m8()` - 存储8位整数向量
- `__riscv_vse16_v_i16m8()` - 存储16位整数向量

#### 3. 向量算术指令

- `__riscv_vmax_vx_i8m8()` - 向量与标量最大值比较(用于ReLU)
- `__riscv_vsadd_vv_i16m8()` - 向量饱和加法
- `__riscv_vwadd_vx_i16m4()` - 向量宽化加法
- `__riscv_vwmul_vv_i32m8()` - 向量宽化乘法
- `__riscv_vredsum_vs_i32m8_i32m1()` - 向量归约求和

#### 4. 向量比较与选择指令

- `__riscv_vmv_x_s_i32m1_i32()` - 向量标量移动

### 关键函数的向量加速实现示例

#### 1. ReLU激活函数 (riscv_relu_q7.c)

```c

#if defined(RISCV_MATH_VECTOR)

uint16_t blkCnt = size & (~RVV_OPT_THRESHOLD);

size_t l;

vint8m8_t vx;

int8_t zero = 0;

  

for (; (l = __riscv_vsetvl_e8m8(blkCnt)) > 0; blkCnt -= l) {

vx = __riscv_vle8_v_i8m8(data, l);

// if data >= zero, return data, else return zero

__riscv_vse8_v_i8m8(data, __riscv_vmax_vx_i8m8(vx, zero, l), l);

data += l;

}

#endif

```


#### 2. 卷积运算 (riscv_convolve_s8.c)

```c

#if defined(RISCV_MATH_VECTOR)

uint16_t col_count = rhs_cols;

vint16m4_t a16m4, b16m4;

vint32m1_t v_temp;

size_t l;

for (; (l = __riscv_vsetvl_e16m4(blkCnt)) > 0; blkCnt -= l) {

a16m4 = __riscv_vle16_v_i16m4(ip_as_col, l);

b16m4 = __riscv_vwadd_vx_i16m4(__riscv_vle8_v_i8m2(ker_a, l), 0, l);

v_temp = __riscv_vredsum_vs_i32m8_i32m1(__riscv_vwmul_vv_i32m8(a16m4, b16m4, l), v_temp, l);

}

sum += __riscv_vmv_x_s_i32m1_i32(v_temp);

#endif

```

## 性能优化策略

### 1. 向量化优势

- **并行处理**: 一次处理多个数据元素
- **减少循环开销**: 减少循环次数和分支预测失误
- **内存带宽优化**: 连续内存访问模式
### 2. 数据类型优化

- **量化支持**: 支持int8、int16等量化数据类型
- **宽化操作**: 使用宽化指令避免溢出
- **饱和运算**: 防止数值溢出

### 3. 内存访问优化

- **批量加载**: 使用向量加载指令减少内存访问次数
- **对齐访问**: 优化内存对齐以提高性能

## 覆盖率分析

### 高覆盖率模块 (>50%)

1. **ActivationFunctions**: 83.3%
2. **PoolingFunctions**: 57.1%
3. **SoftmaxFunctions**: 50%

### 中等覆盖率模块 (30-50%)

1. **BasicMathFunctions**: 44.4%
2. **NNSupportFunctions**: 36.6%
3. **FullyConnectedFunctions**: 35.3%
4. **SVDFunctions**: 33.3%

### 低覆盖率模块 (<30%)

1. **ConvolutionFunctions**: 28.3%
2. **ConcatenationFunctions**: 0%
3. **LSTMFunctions**: 0%
4. **PadFunctions**: 0%
5. **ReshapeFunctions**: 0%
6. **TransposeFunctions**: 0%

## 总结与建议

### 优势

1. **广泛的函数覆盖**: 提供了神经网络推理所需的完整函数集
2. **向量加速支持**: 35.3%的函数支持RISC-V向量扩展加速
3. **多精度支持**: 支持int8、int16、float等多种数据精度
4. **优化实现**: 针对不同数据类型和操作提供了优化的实现

### 改进建议

1. **提高覆盖率**: 为ConcatenationFunctions、LSTMFunctions等模块添加向量加速支持
2. **性能评估**: 建立基准测试来量化向量加速的性能提升
3. **文档完善**: 为向量加速函数提供详细的性能特征文档
4. **适配性优化**: 针对不同的RISC-V向量配置提供自适应优化