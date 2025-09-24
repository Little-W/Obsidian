# 1) 模块端口示意

```verilog
module icb_unalign_bridge #(
  parameter XLEN         = `E203_XLEN,          // 数据位宽
  parameter ADDR_W       = `E203_ADDR_SIZE,     // 地址位宽
  parameter OUTS_DEPTH   = 4,                   // 并发请求上限（默认4）
  parameter SIZE_W       = 2                    // ICB命令size位宽（00/01/10/11 -> 1/2/4/8B）
)(
  input  wire                   clk,
  input  wire                   rst_n,

  //==== 上游（来自加速器/SA）的 ICB，从句口 ====
  input  wire                        sa_icb_cmd_valid,
  output wire                        sa_icb_cmd_ready,
  input  wire [ADDR_W-1:0]           sa_icb_cmd_addr,
  input  wire                        sa_icb_cmd_read,   // 1=读, 0=写
  input  wire [XLEN-1:0]             sa_icb_cmd_wdata,
  input  wire [XLEN/8-1:0]           sa_icb_cmd_wmask,  // 写掩码（按字节）
  input  wire [SIZE_W-1:0]           sa_icb_cmd_size,   // 访问字节数的编码
  output wire                        sa_icb_rsp_valid,
  input  wire                        sa_icb_rsp_ready,
  output wire [XLEN-1:0]             sa_icb_rsp_rdata,
  output wire                        sa_icb_rsp_err,

  //==== 下游（到系统总线）的 ICB，主设备口 ====
  output wire                        m_icb_cmd_valid,
  input  wire                        m_icb_cmd_ready,
  output wire [ADDR_W-1:0]           m_icb_cmd_addr,
  output wire                        m_icb_cmd_read,
  output wire [XLEN-1:0]             m_icb_cmd_wdata,
  output wire [XLEN/8-1:0]           m_icb_cmd_wmask,
  output wire [SIZE_W-1:0]           m_icb_cmd_size,    // 下游只发“对齐”的单拍访问
  input  wire                        m_icb_rsp_valid,
  output wire                        m_icb_rsp_ready,
  input  wire [XLEN-1:0]             m_icb_rsp_rdata,
  input  wire                        m_icb_rsp_err
);
```

> 备注：若系统 XLEN=32，则 `m_icb_cmd_size` 实际只会是 2'b10（4B对齐拍），模块内部负责把上游 1/2/4/8B 非对齐访问切分成若干个 **对齐到 XLEN** 的单拍访问并拼装响应。若 XLEN=64，原则相同（对齐到 8B）。

---

# 2) 设计目标与功能要求

## 2.1 支持的访问与对齐语义

- **上游允许非对齐访问**：`sa_icb_cmd_addr` 可为任意字节地址；`sa_icb_cmd_size` 表示访问字节数编码（典型：00=1B, 01=2B, 10=4B, 11=8B）。
    
- **下游只发对齐单拍**：将一次上游请求，按 **XLEN 字节边界** 切分为 1~2 拍（最多跨一个对齐边界）。
    
    - 例：XLEN=32（4B）
        
        - 读/写 1/2/4 字节：若未跨 4B 边界 → 1 拍；若跨界 → 2 拍。
            
        - 读/写 8 字节：必跨 4B 边界 → 2 拍。
            
    - 例：XLEN=64（8B）同理，判断是否跨 8B 边界。
        
- **写掩码与数据对齐**：对子拍计算 `wmask` 和 `wdata` 的移位与掩码，确保只改动目标字节；读则对返回数据做移位与拼接，产出与上游请求尺寸匹配的 `sa_icb_rsp_rdata`（其他位清零）。
    

## 2.2 并发（Outstanding）与标签

- 支持最多 `OUTS_DEPTH=4` 笔**上游请求并发在途**。
    
- 每个上游请求分配一个**请求ID**（tag），并在需要时派生为 1~2 个**子请求**（子拍），子请求携带（tag，子序号）。
    
- **响应回收/重组**：通过 tag 将下游子响应路由回对应的上游请求，读请求在收到全部子拍后再一次性向上游返回 `sa_icb_rsp_valid=1`。写请求可在**所有子拍下游响应到齐**后，向上游返回一个写完成响应（rdata 忽略/清零）。
    

> 注意：**不改变 ICB 单拍握手**：对上游和下游仍然是 valid/ready 一拍一握手，但本模块在内部维护“父请求/子请求”的映射与计数器。

## 2.3 时序与握手

- **上游入队**：当 `sa_icb_cmd_valid & sa_icb_cmd_ready` 成立时接收请求。
    
    - `sa_icb_cmd_ready` 由 “请求表/标签池未满 且 子请求派发队列有空间” 决定。
        
- **下游派发**：当 `m_icb_cmd_valid & m_icb_cmd_ready` 成立时成功发出一个子拍。
    
- **下游回收**：当 `m_icb_rsp_valid & m_icb_rsp_ready` 成立时接收一个子响应；若为读拍则写入拼装缓冲，若为写拍则仅更新计数与错误标志。
    
- **上游出队**：父请求的**全部子拍**响应齐备后，拉高 `sa_icb_rsp_valid`；与 `sa_icb_rsp_ready` 成功握手即完成一次上游响应。
    

## 2.4 非对齐拆分与合成规则（以 XLEN=32 为例）

设：

- `A = sa_icb_cmd_addr[1:0]` 为地址低 2 位（字节偏移 0..3）
    
- `S` 为字节数（1/2/4/8）
    
- `B = 4`（每拍4字节）
    

**是否跨界**：`A + S > B` → 需要 2 拍，否则 1 拍。

- **拍0地址**：`addr0 = {sa_icb_cmd_addr[ADDR_W-1:2], 2'b00}`
    
- **拍1地址**：`addr1 = addr0 + 4`
    
- **写数据/掩码**：将上游 `wdata/wmask` 右移 `8*A` 位作为起点，
    
    - 拍0取前 `min(S, B-A)` 字节，映射到 `addr0` 的对应字节位
        
    - 拍1（若有）取余下 `S - (B-A)` 字节，映射到 `addr1`
        
- **读数据合成**：
    
    - 收到拍0数据 `r0`：右移 `8*A` 取前半段
        
    - 若有拍1，收到 `r1`：取低 `S - (B-A)` 字节，拼接在高位
        
    - 输出 `sa_icb_rsp_rdata` 的低 `S` 字节为有效，其余清零（或按需求保留未定义）
        

> XLEN=64 时将 `B=8`，判断与移位宽度相应扩展即可；`SIZE_W=2` 的 8B 访问映射为单一原子请求（若地址8B对齐），否则拆成两拍 8B 对齐单拍。

## 2.5 错误与边界条件

- **错误聚合**：上游一次请求若任一子拍返回 `m_icb_rsp_err=1`，则最终 `sa_icb_rsp_err=1`。
    
- **禁止跨页可选**：可选项——若不允许跨页（如 4KB），当检测到 `addr0[11:0] > 0xFFC` 且需要拍1时，直接拒绝接收（`sa_icb_cmd_ready=0`）或接受后置错误标志。默认**允许**跨页，只要总线支持。
    
- **仅单拍总线假设**：下游 ICB 不支持突发，模块保证每子拍为独立单拍。
    
- **写掩码合法化**：对于上游提供的 `sa_icb_cmd_wmask`，模块会基于地址偏移与 S 再与运算；上游可传宽掩码，最终以子拍掩码为准。
    

## 2.6 流控与资源

- **请求表（父请求表）**：深度 `OUTS_DEPTH`，每项记录：
    
    - `tag`、`is_read`、`orig_addr`、`size(S)`、`wdata/wmask`（写）
        
    - `need_beats`（1或2）、`done_beats`、`err_or`
        
    - 读请求的**拼装缓冲**（可用 2×XLEN 的小寄存器或两个拍结果寄存+拼接选择器）
        
- **子请求队列**：派发 FIFO，深度≥`2*OUTS_DEPTH`（每父最多2拍）。
    
- **标签池**：简单循环分配，busy 位数组管理；当对应父请求完成且上游拿走响应后释放。
    
- **响应回写**：按 `tag` 找到父项，更新 `done_beats/err_or`，对读填入 rbuf0/rbuf1。
    

## 2.7 时序保证与旁路

- 支持**乱序回包**（不同 tag 之间），不要求子拍按序返回；同一 tag 的两个子拍多数总线也能保证按地址先后返回，但本设计无需依赖此假设。
    
- 上游**响应顺序**：按**其各自完成时刻**返回（非强制 in-order 全序）；如需强制 in-order，对请求表增加序号与“就绪但阻塞直到序号到达”的门控。默认**允许乱序完成**以提高吞吐。
    

## 2.8 配置与可选特性

- `OUTS_DEPTH` 可参数化（默认 4）。
    
- 可选：
    
    - **强制 in-order** 开关
        
    - **跨页禁止** 开关
        
    - **写合并**（当两个上游请求命中同一对齐拍时尝试合并）——默认关闭，保持设计简洁。
        

---

# 3) 典型时序（读跨界示意）

```
上游： addr=0x...03, size=4B    // A=3, S=4 → 跨4B边界，需要2拍
拍0→ 下游：addr0=...00, size=4B, read=1
拍1→ 下游：addr1=...04, size=4B, read=1
回包：r0,r1 → 右移/拼接 → sa_icb_rsp_rdata[31:0] 有效，rsp_err = r0_err | r1_err
```

---

# 4) 验收要点

1. **功能性**：非对齐 1/2/4/8B 读写正确；跨界拆分与数据拼接正确；掩码正确。
    
2. **并发性**：支持 ≥4 个父请求在途；不同 tag 乱序回包能正确合并。
    
3. **稳态吞吐**：在 `m_icb_cmd_ready` 一直为 1 的情况下，拆分后子拍能无气泡派发。
    
4. **异常**：任一子拍报错，上游报错；复位后内部表清零、无悬挂。
    
5. **时序**：关键路径不穿越大移位器（建议分拍寄存/选择），满足频率目标。
    