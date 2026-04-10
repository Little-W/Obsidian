 
**适用范围**：定点/浮点卷积前端；支持 stride / padding / dilation / groups；支持可选“上采样索引右移”（偶行/偶列采样）路径。  
**约束**：本版本**不**在 im2col 写入量化零点（ZP）或做零点偏移；**越界填充为字面 0**。ZP 与 requant 的处理应在 GEMM + 后处理阶段完成。

---

## 1. 术语

- **im2col**：把卷积感受野展开为二维矩阵（LHS），以便用 GEMM 实现卷积。
    
- **LHS / RHS**：矩阵乘左/右矩阵；本手册中 **LHS=im2col 输出**，**RHS=权重**。
    
- **Groups**：分组卷积。
    
- **Dilation**：空洞卷积扩张因子。
    

---

## 2. 设计目标

- **功能纯化**：im2col 只做几何展开与越界填充，不做任何量化零点/偏移处理。
    
- **高性能**：内存顺序连续、可对齐、便于 SIMD/向量化；支持行块化与双缓冲。
    
- **可集成**：易与 NMSIS/CMSIS-NN、TFLM 对接；量化逻辑放在后续阶段。
    

---

## 3. 接口规范

### 3.1 数据结构（建议）

```c
typedef struct { int32_t n, h, w, c; } nn_dims;
typedef struct { int32_t h, w; } nn_tile;

typedef struct {
    nn_tile stride;    // Sh / Sw
    nn_tile padding;   // 对称 padding：Ph / Pw
    nn_tile dilation;  // Dh / Dw
    // 注意：本版本不使用 input_offset / output_offset / activation
} im2col_params;

typedef struct {
    void   *buf;       // 可选工作缓冲，按需使用
    size_t  size;
} nn_context;
```

### 3.2 函数原型

```c
typedef enum { NN_OK = 0, NN_ARG_ERROR = -1, NN_SIZE_MISMATCH = -2 } nn_status;

/**
 * 生成 im2col 矩阵（按行累积），不写入量化零点、不做零点偏移：
 *   LHS shape: rows = H_out * W_out * groups
 *              cols = K_h * K_w * C_per_group
 * 溢出/越界位置统一写入字面 0。
 */
nn_status nn_im2col_s8_pure(const nn_context *ctx,
                            const im2col_params *p,
                            const nn_dims *in_dims,  const int8_t  *in,
                            const nn_dims *ker_dims, /* h=K_h, w=K_w, c=C_per_group */
                            const nn_dims *out_dims, /* h=H_out, w=W_out, c=C_out(未用) */
                            int32_t groups,
                            /* 可选上采样索引右移（2 表示右移 1 位），不用则传 NULL */
                            const nn_dims *upscale_dims,
                            /* 输出缓冲与行步长（字节） */
                            int8_t *lhs_im2col, int32_t lhs_stride_bytes);
```

> 说明：
> 
> - `lhs_stride_bytes == cols`（紧凑存）或更大（对齐/填充）。
>     
> - 权重（RHS）与量化（乘法器/移位/零点）不在本函数处理。
>     

---

## 4. 维度关系（规范）

设：

- 输入：`N, H_in, W_in, C_in`
    
- 核：`K_h, K_w, C_per_group`，组数 `G`，需 `C_in = G * C_per_group`
    
- 步幅：`S_h, S_w`; 填充（对称）：`P_h, P_w`; 空洞：`D_h, D_w`
    
- 有效核：`K_eff_h = (K_h - 1)*D_h + 1`；`K_eff_w = (K_w - 1)*D_w + 1`
    

输出空间：

```
H_out = floor((H_in + 2*P_h - K_eff_h)/S_h) + 1
W_out = floor((W_in + 2*P_w - K_eff_w)/S_w) + 1
```

LHS（im2col）：

```
rows = H_out * W_out * G
cols = K_h * K_w * C_per_group
```

组数（**Groups，记作 G**）就是**分组卷积（Grouped Convolution）里把输入通道拆分成几组分别做卷积**的那个参数。

---

### 1. 定义

在普通卷积中：

- 所有输入通道都会参与每一个卷积核的计算。
    

而在**分组卷积**中：

- 输入通道被**均匀分成 G 组**，每组单独使用一组卷积核，互不交叉。
    
- 每组卷积核只和本组的输入通道做卷积，输出通道也对应拆成 G 组。
    

数学上：

```
C_in = G * C_per_group
C_out = G * C_out_per_group
```

其中 `C_per_group` = 每组输入通道数。

---

### 2. 为什么要有 Groups

- **降低计算量和参数量**：每组卷积核只看一部分输入通道，总计算量从 `C_in * C_out` 变为 `(C_in/G * C_out)`。
    
- **增加特征独立性**：分组卷积能让每组提取的特征更独立，有利于轻量模型设计。
    
- **极端情况**：
    
    - **G = 1** → 普通卷积
        
    - **G = C_in** → 每个输入通道单独卷积，称为 **Depthwise Convolution**（深度可分离卷积的第一步）
        

---

### 3. 例子

假设输入特征图大小 `H×W`，通道数 `C_in=8`，设：

- `K_h=3, K_w=3`，每组输入通道数 `C_per_group=2`
    
- 则 `G = 8 / 2 = 4`，有 4 组
    
- 每组单独做 3×3 卷积，输出通道也按组分配
    

示意图：

```
输入通道: 0 1 | 2 3 | 4 5 | 6 7  <-- 4组
          ↑组1   ↑组2   ↑组3   ↑组4

每组独立用自己的卷积核做卷积，最后拼接输出。
```

---

### 4. im2col 中的作用

在 im2col 算法里，`groups` 决定：

- **通道切片起始地址**：每组偏移 `i_group * C_per_group`
    
- **输出行索引偏移**：每组单独有 `H_out*W_out` 行
    
- **权重矩阵布局**：每组有自己的一块权重
    

这样就能保证每组的卷积运算互不干扰，最终拼接形成完整输出。


---

## 5. 算法说明

### 5.1 主循环

对每批次 `n`（如使用）、每组 `g ∈ [0,G)`、每个输出坐标 `(oy, ox)`：

1. 计算输入窗口左上角：
    
    ```
    base_y = oy * S_h - P_h
    base_x = ox * S_w - P_w
    ```
    
2. 对每个核坐标 `(ky, kx)`：
    
    ```
    in_y = base_y + ky * D_h
    in_x = base_x + kx * D_w
    ```
    
3. 若 `(in_y, in_x)` 在 `[0..H_in-1]×[0..W_in-1]` 内，则拷贝该位置的 **C_per_group** 连续通道（来自组 g 的切片）至 LHS 当前行对应的列区间；否则向该列区间写入**字面 0**（不加零点、不做偏移）。
    

**列布局（推荐）**：  
当前行的列下标按 `((ky * K_w + kx) * C_per_group + c)`，`c∈[0,C_per_group)`。

### 5.2 分组卷积

- 组通道起始：`in_ch_base = g * C_per_group`。
    
- LHS 行号：`row = g*(H_out*W_out) + oy*W_out + ox`。
    

### 5.3 上采样索引右移（可选）

- 若 `upscale_dims && upscale_dims->h == 2`，则仅在 `in_y` 为偶数时取样，读源索引 `in_y >> 1`；否则写 0。X 方向同理。
    
- 建议在此路径下对**整行**先 `memset(0)`，满足条件的点再 `memcpy` 覆盖，减少分支与零填充代价。
    

---

## 6. 内存与对齐

- LHS 大小：`rows * cols` 字节（s8）。
    
- 建议对齐：`lhs_im2col` 起始地址 ≥16B（向量平台可 64B）；`cols` 补齐到 4/8/16 以利向量化。
    
- 可行的块化：按 `rows_block` 生成 LHS，与 GEMM 做 ping-pong 双缓冲。
    

---

## 7. 量化与后处理（本函数不做）

- **本函数不写 ZP、不做 input_offset/output_offset 处理**。
    
- 推荐在 GEMM/ACC 后：`acc = (acc + bias) * multiplier >> shift + output_zero_point`，随后再执行激活裁剪。
    
- 确保你的后处理阶段与“im2col=纯几何展开、越界=0”的假设自洽。
    

---

## 8. 参数校验

- `C_in = groups * C_per_group`，且 `K_h,K_w,S_h,S_w,D_h,D_w > 0`，`P_h,P_w ≥ 0`。
    
- 由式子得到的 `H_out,W_out > 0`。
    
- 指针非空，`lhs_stride_bytes ≥ cols`。不满足返回 `NN_ARG_ERROR/NN_SIZE_MISMATCH`。
    

---

## 9. 参考实现（C，紧凑/可移植）

```c
#include <string.h>
#include <stdint.h>

typedef struct { int32_t n, h, w, c; } nn_dims;
typedef struct { int32_t h, w; } nn_tile;
typedef struct { nn_tile stride, padding, dilation; } im2col_params;

typedef struct { void *buf; size_t size; } nn_context;

typedef enum { NN_OK = 0, NN_ARG_ERROR = -1, NN_SIZE_MISMATCH = -2 } nn_status;

static inline int32_t div_pow2_if(int32_t v, int shift) { return shift ? (v >> shift) : v; }

nn_status nn_im2col_s8_pure(const nn_context *ctx,
                            const im2col_params *p,
                            const nn_dims *in_dims,  const int8_t *in,
                            const nn_dims *ker_dims,
                            const nn_dims *out_dims,
                            int32_t groups,
                            const nn_dims *upscale, // h==2 或 w==2 表示右移一位；否则置 0/NULL
                            int8_t *lhs, int32_t lhs_stride_bytes)
{
    (void)ctx;
    if (!p || !in_dims || !ker_dims || !out_dims || !in || !lhs) return NN_ARG_ERROR;

    const int32_t N  = in_dims->n;
    const int32_t H  = in_dims->h, W  = in_dims->w, C  = in_dims->c;
    const int32_t Kh = ker_dims->h, Kw = ker_dims->w, Cg = ker_dims->c;
    const int32_t Sh = p->stride.h, Sw = p->stride.w;
    const int32_t Ph = p->padding.h, Pw = p->padding.w;
    const int32_t Dh = p->dilation.h, Dw = p->dilation.w;

    if (groups <= 0 || C != groups * Cg) return NN_ARG_ERROR;
    if (Kh <= 0 || Kw <= 0 || Sh <= 0 || Sw <= 0 || Dh <= 0 || Dw <= 0 || Ph < 0 || Pw < 0)
        return NN_ARG_ERROR;

    const int32_t Keh = (Kh - 1) * Dh + 1;
    const int32_t Kew = (Kw - 1) * Dw + 1;
    const int32_t Ho  = (H + 2*Ph - Keh) / Sh + 1;
    const int32_t Wo  = (W + 2*Pw - Kew) / Sw + 1;
    if (Ho <= 0 || Wo <= 0) return NN_SIZE_MISMATCH;

    const int32_t cols = Kh * Kw * Cg;
    if (lhs_stride_bytes < cols) return NN_ARG_ERROR;

    const int y_rshift = (upscale && upscale->h == 2) ? 1 : 0;
    const int x_rshift = (upscale && upscale->w == 2) ? 1 : 0;

    // 假定批次 N==1；如需支持 N>1，可在此外层再套一层 n 循环并加 n 偏移
    (void)N;

    for (int32_t g = 0; g < groups; ++g) {
        const int32_t in_ch_base = g * Cg;

        for (int32_t oy = 0; oy < Ho; ++oy) {
            for (int32_t ox = 0; ox < Wo; ++ox) {

                const int32_t row = g * (Ho * Wo) + oy * Wo + ox;
                int8_t *row_ptr = (int8_t *)((uint8_t*)lhs + row * (size_t)lhs_stride_bytes);

                int32_t col_off = 0;

                // 若使用右移索引路径，先整行清零
                if (y_rshift || x_rshift) {
                    memset(row_ptr, 0, (size_t)cols);
                }

                const int32_t base_y = oy * Sh - Ph;
                const int32_t base_x = ox * Sw - Pw;

                for (int32_t ky = 0; ky < Kh; ++ky) {
                    const int32_t iy = base_y + ky * Dh;
                    const int     y_ok = (iy >= 0 && iy < H) && ((iy % 2 == 0) || (y_rshift == 0));
                    const int32_t iy1  = div_pow2_if(iy, y_rshift);

                    for (int32_t kx = 0; kx < Kw; ++kx) {
                        const int32_t ix = base_x + kx * Dw;
                        const int     x_ok = (ix >= 0 && ix < W) && ((ix % 2 == 0) || (x_rshift == 0));
                        const int32_t ix1  = div_pow2_if(ix, x_rshift);

                        int8_t *dst = row_ptr + col_off;

                        if (y_ok && x_ok) {
                            const int32_t src_hw = (iy1 * (W >> x_rshift) + ix1) * C;
                            const int8_t *src    = in + src_hw + in_ch_base;
                            memcpy(dst, src, (size_t)Cg);
                        } else if (!(y_rshift || x_rshift)) {
                            // 常规路径：越界直接写字面 0
                            memset(dst, 0, (size_t)Cg);
                        }

                        col_off += Cg;
                    }
                }
            }
        }
    }
    return NN_OK;
}
```

**要点**

- **越界填 0**，不写入量化零、不做任何零点偏移。
    
- **分组偏移**两条路径都已正确处理：`+ in_ch_base`。
    
- 右移索引路径采用“整行清零 + 条件 memcpy 覆盖”，减少分支与填充代价。
    

---

## 10. 性能建议

- **列数补齐**（4/8/16）＋ **行步长对齐**（≥16/64B）以利用向量加载。
    
- **行块化 + 双缓冲**：`rows_block` 规模与 GEMM 配合；A 生成/B 乘、交替进行。
    
- **小核专用路径**：`1×1`、`3×3` 可 unroll；depthwise 可用专用 kernel 直接读输入避免大规模 im2col。
    

---

## 11. 集成说明

- **与 CMSIS/NMSIS-NN/TFLM 对接**时：请确保后续卷积核在累加/反量化阶段统一加入 `input_zero_point` 的影响（例如将输入事先减去 ZP，或在乘加后做补偿），并在最终输出加 `output_zero_point`，再做激活裁剪。
    
- **SAME/VALID**：本函数不推导 padding，需上层预先计算 `P_h/P_w` 并下发。
    
- **权重布局**：RHS 期望的维度顺序应与 `cols = K_h*K_w*C_per_group` 匹配；如需重排权重请在编译/加载阶段完成。
    

---

## 12. 测试矩阵

**必须覆盖**：

- `padding=0/1/2`，`stride=1/2`，`dilation=1/2`；
    
- `groups=1/2/4`（`C_in` 可整除）；
    
- 边界位置（左上/右下等越界）与全核覆盖；
    
- `upscale_dims` 取 `(1,1)/(2,1)/(1,2)/(2,2)`；
    
- 退化核：`1×1`、`K_h=H_in, K_w=W_in`；
    
- 与“朴素卷积 + 后处理（含 ZP 的补偿）”结果一致性（逐元素比对）。
    

---

## 13. 常见坑

- **后处理忘记补偿 ZP**：本函数没处理 ZP，若后续不补偿会产生系统性偏差。
    
- **groups 偏移遗漏**：右移索引路径尤其容易遗漏 `+ in_ch_base`。
    
- **对齐不足**：`lhs_stride_bytes` 小于 `cols` 或未按 SIMD 对齐，导致退化。
    
- **dilation 输出尺寸**：未用 `K_eff` 计算 `H_out/W_out` 会出错。
    

---

## 14. 版本记录

- **v1.1（当前）**：明确规定 im2col **不写 ZP、不做零点偏移**；越界统一填字面 0；更新参考实现与测试矩阵。
    
- v1.0：初始发布（含支持 ZP 的版本，现已弃用）。
    
