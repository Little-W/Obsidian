# FPGA PPA Timing/Area Optimization Knowledge

本文只保留可复用的 FPGA RTL 优化经验、时序优化方法和设计边界。不在这里保存
单次实验的脚本、日志、报告路径、提交号、benchmark 分数或 PPA 数字；这些内容
应放在独立的实验记录中。

## 1. 使用原则

### 1.1 先固定问题，再改 RTL

任何 PPA 优化都先明确：

* 目标配置、器件、时钟、综合或实现阶段。
* 目标 hierarchy 和面积预算。
* 功能边界、性能底线和允许改变的微架构语义。
* 当前关键路径簇，而不是只盯住一条最差路径。

配置、频率、hierarchy 和实现阶段不同的报告不能直接比较。OOC 适合筛选方向，
post-route 才能决定是否保留改动。

### 1.2 先修语义，再优化 QoR

综合 warning、前后仿真不一致、位宽不确定、未定义 reset 或协议歧义没有解决前，
不要继续追逐 WNS 或 LUT。时序优化建立在稳定语义上；否则综合器可能优化出与仿真
不同的硬件，后续所有 PPA 结论都不可信。

### 1.3 一次只改变一个路径簇

每次修改应明确回答三个问题：

1. 要切断或缩短哪条组合锥。
2. 新状态、寄存器、mux 或协议由谁拥有。
3. 功能、时序、面积和性能分别可能受什么影响。

不要把 bypass、FIFO、预测器、cache 和流水级调整混在同一次改动中。单主题改动
才能判断路径是被真正切断，还是仅迁移到另一个模块。

### 1.4 实验记录与知识库分离

知识库记录“为什么这样设计”。独立实验记录保存配置、原始报告、日志、源码版本、
数值和保留或回退原因。这样知识库不会被过期结果淹没，同时仍可追溯具体结论。

## 2. 标准优化流程

### 2.1 建立可比基线

基线至少应包含功能状态、性能基线、目标 hierarchy 的资源使用和目标阶段的时序。
基线不是为了堆积数字，而是为了保证后续每个结论都有相同的比较口径。

### 2.2 按路径簇分析，而不是按模块名猜测

从多个 worst paths 提取共同模式，常见簇包括：

* branch/flush/PC clock enable。
* forwarding、bypass、dispatch operand 和 writeback release。
* AXI request、response credit、FIFO ready 和 cache miss control。
* predictor lookup、training 和 RAM read/write conflict。
* reset、valid、clock enable 和高扇出选择信号。

同一个模块可能同时属于多个路径簇；优化应围绕真实 launch、logic cone、fanout 和
endpoint 进行，而不是按文件或模块名称下手。

### 2.3 先确定 ownership，再插入寄存器

寄存器不是自动优化。只有明确请求、响应、payload、slot、commit ID 和 flush 由谁
拥有，寄存器边界才会缩短路径而不破坏时序语义。每个跨边界对象都应有：

* `valid` 或等价 live token。
* 唯一身份，例如 epoch、generation、slot 或 commit ID。
* flush、kill、backpressure 和重用时的处理规则。
* 明确的数据稳定期和消费点。

### 2.4 修改后的最低验证集合

每个结构改动都应重新检查：

* 相关 ISA、异常、flush、load/store、branch 和多周期单元语义。
* 目标配置的性能指标没有被无意破坏。
* 综合、实现和 hierarchy 资源报告使用了相同口径。
* 关键路径是否被切断，而不是转移到了全局控制或另一条数据锥。

## 3. Timing 优化方法

### 3.1 切断跨级组合长链

最危险的典型形态是：

```text
late data -> wide operand mux -> compare/add -> branch/flush -> global CE
```

不要把晚到的 LSU、RAM、AXI 或 writeback 数据组合接到 branch、redirect、flush、
PC 或全局 clock enable。正确的做法是先在 producer 或既有流水边界登记结果，
consumer 在下一拍通过局部 bank、token 或已登记 operand 读取。

### 3.2 高扇出控制必须局部化

高扇出 `ready`、`valid`、flush、redirect、reset、cache hit、FIFO status 和 selector
通常比一段普通数据逻辑更难收敛。把判断移到实际 owner，并只向外输出窄 token：

* response FIFO 自己维护 room 和 credit。
* cache 或 tracker 自己维护 slot 可用性。
* branch/recovery 只把稳定的 redirect 结果传给 IFU。
* WBU/HDU 用已登记的 completion 或 retire token 释放状态。

不要把一个局部事件重新组合成全局 `ready` 或 `clock enable`。

### 3.3 数据与控制分离

宽 payload 应留在 RAM、bank 或拥有它的流水级；跨边界只传 hit、source、owner、
valid、epoch、commit ID 等窄控制信息。常见分解是：

```text
early tag/check -> registered narrow token -> local data select -> normal release
```

这种分解既缩短宽 mux，也避免将数据 RAM、响应握手和 branch 控制串到同一拍。

### 3.4 Forwarding、bypass 和 writeback 分层

三种路径不能混用：

* **Forwarding**：在 dispatch/issue 前替换 operand 或解除 RAW。
* **Bypass**：在 EXU/FU 局部向下一拍 consumer 提供已登记结果。
* **Writeback**：更新架构状态并释放 scoreboard/commit ownership。

HDU 决定 source、依赖和 bank；EXU 只做局部 mux；WBU 负责架构可见性。若 EXU
重新做 commit-ID、rd 命中或全局依赖判断，容易形成重复比较和更深控制锥。

### 3.5 固定延时与变延时 producer 必须分开 release

固定延时 ALU 结果可由已知流水级和 bank write 时刻释放。LSU、RAM、AXI、MUL/DIV
等变延时 producer 必须由真实 completion、有效身份和 owner 状态释放。不能用地址、
请求握手、预测 hit 或“理论上应返回”的条件提前放行 consumer。

对于 normal LSU release，至少匹配 completion valid、dependency token、commit ID 和
consumer source。只影响当前等待的 consumer，避免同一完成事件反复 hold 或错误唤醒
wait slot。

### 3.6 地址路径在发射前解决

MEM/JALR 地址和 branch target 通常在 dispatch/issue 时就需要稳定。EXU-local bypass
只能修正进入 EXU 后的 operand，不能修复已经计算并被下游消费的地址。地址依赖应由：

* dispatch forwarding；
* 已登记的 hold/issue operand；
* 共享且已被仲裁的地址运算器；

在发射前解决，而不是把晚到数据接回地址或 PC 路径。

### 3.7 同步 RAM 的延迟必须显式建模

同步 BRAM/LUTRAM 的数据不会在请求同拍稳定可用。请求、地址、tag、metadata 和
response identity 应跨越明确的读延迟。不要为性能恢复不存在的同拍 RAM bypass；
这通常会把 RAM read、控制判断和 branch/flush 串成新的关键路径。

### 3.8 FIFO 与 credit 的优化要保持协议容量

`count` 比较、full/empty、push/pop 和 response-ready 常处于关键路径。局部维护
registered status flag 可以缩短比较锥，但必须保持：

* FIFO 深度和 outstanding 能力。
* 同拍 push/pop 的真实语义。
* response ordering 和 backpressure。
* flush、invalidate、error response 和 slot 回收。

满 FIFO 不应从同拍异步 response 或 cache decision 借用未来空槽；将可用容量延后到
下一拍通常更容易收敛，也更容易证明正确。

### 3.9 mux 结构和 selector 是时序结构的一部分

逻辑等价的 `case`、优先级链、one-hot OR 和多层 mux 在 FPGA 上可能产生不同的
LUT packing、routing 和 fanout。优化 mux 时：

* 先缩小选择信号的作用域，再重排数据选择。
* 让已登记的 source 选择既有 mux，而不是叠加外层 mux。
* 宽数据保持并行 bank，尽量只切换窄 selector。
* 不要仅把 select 拆成高低半或复制 selector，就假设关键路径被切断。

### 3.10 宏和 profile 必须隔离综合结构

性能配置、扩展指令、cache、predictor 和流水级变体应使用 `generate` 隔离结构，
而不是仅把信号常量化。disabled 配置不应保留无用 mux 输入、寄存器、RAM port 或
高扇出控制。任何 macro-on 优化都必须确认不会污染 macro-off baseline。

### 3.11 IF/AXI 请求路径：只在 backpressure 时登记完整 payload

IF request 的 `ARVALID` 不应依赖 late redirect。正常可握手时可保留零气泡路径；
只有在 backpressure 时才锁存完整请求 payload。该 payload 至少包含地址、epoch、
command identity 和所有 response 路由所需 metadata。

redirect 只能替换未发出的 command。已发出的旧请求可以完成和 drain，但不得弹出
新的 command，也不得让旧 epoch response 进入当前 IF/ID。epoch/generation 的作用
是把“物理完成”与“架构可见”分开。

### 3.12 同步 predictor：请求和响应都要有身份

BTB、BHT、TAGE 等同步存储不能只增加一拍读延迟。请求和返回必须带 slot、generation
和 epoch，只有身份匹配的 response 才能解除 command 阻塞。redirect、slot 重用和
alternate path 都要丢弃 stale response。

若 predictor 在读写同一 index，需要定义 RAM 数据与 pending update 的 forwarding
优先级。将 request、read/compare、RMW decision 和 ordered write 分开，可以避免
same-index conflict 在组合路径中蔓延。

### 3.13 recovery、retire 和 side effect 走本地 token

branch recovery 应在执行边界后形成已接受的 bundle，再传给 CTRL/IFU。bundle 包含
target、sequential successor、预测 metadata 和精确 rollback identity；它不能重新
依赖晚到的 operand、LSU 数据或 predictor lookup。

raw flush/retire 事件留在实际 owner 处理取消和 ingress hold，其他模块消费已登记
token。对 pending owner-RAM、scoreboard 或 WBU 写入，只按精确 identity 抑制相关
操作。interrupt priority、wrong-path store/CSR/SYS/CLINT suppression 必须在这个
边界内保持明确。

### 3.14 可直接复用的 RTL 写法

以下写法的目标是让综合结构、状态边界和位宽意图显式可见。它们不是替代路径分析的
通用魔法，仍需确认应用后没有把控制锥接到新的关键 endpoint。

#### 3.14.1 先从 RTL 写法预判硬件结构

改写前先判断综合器大概率会生成什么，而不是只看 RTL 是否更短：

| RTL 写法 | 常见推断 | 写法优化方向 |
| --- | --- | --- |
| 多级 `if/else` | priority chain | 只有业务确有优先级时保留；否则改为互斥选择或并行条件。 |
| 宽 `case` | mux tree | 缩小 selector 作用域，先形成局部候选，再在 owner 内选择。 |
| `array[index]` | RAM 或大 mux | 明确读写时序、端口和 reset，确认工具实际推断。 |
| 变量移位 | barrel shifter | 限制动态位数、分级或移出关键控制路径。 |
| 宽 payload reset | reset mux 与高 fanout | 仅 reset valid/state，payload 用 valid 保护。 |

#### 3.14.2 组合逻辑先给默认值，再表达互斥性

`always_comb` 先为每个输出和 next-state 给默认值，所有 `case` 都给 `default`，避免
latch 和不完整选择。只有条件在语义上确实互斥时才使用 `unique case`；若业务要求
优先级，应明确保留 priority chain，而不是让优先级由遗漏的默认赋值产生。

```systemverilog
always_comb begin
    state_d  = state_q;
    result_d = default_result;

    unique case (op_class)
        OP_ALU: result_d = alu_result;
        OP_LSU: result_d = lsu_result;
        OP_MUL: result_d = mul_result;
        default: ;
    endcase
end
```

#### 3.14.3 分离 payload 与 valid/reset

对无效时不可见的流水 payload，只登记数据；reset、flush 和 kill 只作用于 valid。
这样可避免宽 payload 的 reset mux 和 reset fanout，同时保留明确的架构可见性。

```systemverilog
always_ff @(posedge clk) begin
    if (pipe_en) begin
        payload_q <= payload_d;
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        valid_q <= 1'b0;
    end else if (flush) begin
        valid_q <= 1'b0;
    end else if (pipe_en) begin
        valid_q <= valid_d;
    end
end
```

这只适用于 payload 被 `valid_q`、owner 或 identity 完全保护的场景；架构状态、
FSM、pointer 和必须确定的控制位仍应按语义 reset。

#### 3.14.4 用 `generate` 裁掉不用的结构

功能开关应决定 elaboration 后是否存在 mux、寄存器、RAM port 和控制锥，而不是只
决定最终输出值。

```systemverilog
generate
    if (ENABLE_FEATURE) begin : gen_feature
        assign feature_o = complex_feature_path;
    end else begin : gen_no_feature
        assign feature_o = 1'b0;
    end
endgenerate
```

不要把 `ENABLE_FEATURE ? complex_feature_path : 1'b0` 当作同义替代。若复杂表达式
同时参与公共控制或共享 mux，常量化可能仍改变无关 profile 的结构与 fanout。

#### 3.14.5 先扩展到目标位宽，再组合 control

参数化拼接、零宽 repetition、unsized literal 和隐式 signed conversion 容易造成
综合 warning 或不同工具行为。先赋给目标宽度的中间信号，再进行 mask、mux 或端口
连接，能使位宽意图清楚且避免零宽表达式。

```systemverilog
logic [DECINFO_W-1:0] alu_info_ext;

assign alu_info_ext = alu_info;
assign dec_info_o  = {DECINFO_W{is_alu}} & alu_info_ext;
```

跨模块连接也显式截取或扩展地址、ID 和常量宽度；不要让端口连接承担隐式截断。

#### 3.14.6 从稳定字段派生 operand，而不是重复寄存

如果 operand 可由已打拍的 instruction、`rs1`、`rs2` 或 decode 唯一推导，就不应
为每个功能单元再保存一份 sidecar。先把派生值扩展到目标宽度，再在本地选择：

```systemverilog
logic [DATA_W-1:0] csr_zimm_ext;
logic [DATA_W-1:0] csr_operand;

assign csr_zimm_ext = inst_q[19:15];
assign csr_operand  = inst_q[14] ? csr_zimm_ext : rs1_q;
```

只删除真正可再派生的数据。若字段跨越 flush、stall、replay 或 exception 边界后不再
稳定，就必须保留必要的 payload 或 identity。

#### 3.14.7 用紧凑 source 编码驱动一次局部 mux

在 dispatch/HDU 侧完成依赖和 producer 选择，跨流水只传紧凑 source/bank 编码；
EXU 按该编码做一个局部选择。这样避免多份 `*_pass_*` 或 `*_bank_*` 控制同时穿过
流水，也避免在 consumer 处重复 rd/commit-ID 比较。

```systemverilog
always_comb begin
    operand_d = gpr_value;
    unique case (bypass_src_q)
        BYPASS_ALU: operand_d = alu_bank_q;
        BYPASS_LSU: operand_d = lsu_bank_q;
        BYPASS_MUL: operand_d = mul_bank_q;
        default:    operand_d = gpr_value;
    endcase
end
```

`bypass_src_q` 必须在本 mux 前稳定；变延时 producer 只能在真实 bank write/completion
后被编码为可选 source。

#### 3.14.8 GPR 同地址短路限制在寄存器堆边界

GPR 读写同地址的短路可以保留在 register-file 边界，只比较稳定的 write enable、
地址和已登记 write data。不要把完整 WBU arbitration、completion 或远端控制组合
拉回 GPR 读口。

```systemverilog
assign rs1_data = (wb_we && (wb_rd == rs1_addr) && (rs1_addr != '0)) ?
                  wb_data : gpr_mem[rs1_addr];
```

更复杂的 RAW、WAW、commit-ID 和 producer 选择仍由 HDU/scoreboard 在发射前处理；
GPR short-cut 不是替代全局依赖管理的路径。

#### 3.14.9 FIFO 的远端状态使用已登记 flag

若 `count` 比较位于关键锥，可在 FIFO owner 内基于实际 `push_fire`/`pop_fire` 更新
next-state，并把 `empty_q`/`full_q` 作为远端唯一可见状态。远端模块不能直接组合消费
`count_d`、response payload 或同拍释放的 slot。

```systemverilog
always_comb begin
    count_d = count_q;
    unique case ({push_fire, pop_fire})
        2'b10: count_d = count_q + 1'b1;
        2'b01: count_d = count_q - 1'b1;
        default: ;
    endcase
    empty_d = (count_d == '0);
    full_d  = (count_d == DEPTH);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        count_q <= '0;
        empty_q <= 1'b1;
        full_q  <= 1'b0;
    end else begin
        count_q <= count_d;
        empty_q <= empty_d;
        full_q  <= full_d;
    end
end
```

此写法的前提是 `DEPTH`、同拍 push/pop、flush 和 response ordering 已被完整定义；
status flag 不是可以跳过协议容量检查的快捷方式。

#### 3.14.10 RAM payload 保持 reset-free 单写口

可由 valid 限定可见性的 tag/data、FIFO payload 和 bypass data 应使用局部同步写口，
避免在 payload array 上加入 reset 或远端 handshake 组合 write-enable。

```systemverilog
always_ff @(posedge clk) begin
    if (write_fire) begin
        data_mem[write_addr] <= write_data;
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        valid_mem <= '0;
    end else begin
        valid_mem <= valid_mem_d;
    end
end
```

读路径先用 valid/tag/identity 判定，再在拥有 RAM 的本地级选择数据。这样更利于
RAM inference，也不会把宽 data read 或外部 ready 拉进全局控制路径。

#### 3.14.11 最小 live metadata 与共享运算器

wait slot、owner table 或小型 outstanding table 只保留退休、恢复和依赖真正需要的
`valid`、destination、write enable、identity、异常和 side-effect metadata。完整
instruction/payload 留在实际 owner，避免多个功能单元镜像整包状态。

对于确实互斥或已仲裁的 requestor，可集中选择 `{op1, op2, operation}` 后共享
add/sub、compare、shift 或多周期算术单元，结果按 owner 返回。条件 branch 若同拍
还需要 target 计算，不能为了省一个 adder 将 compare 和 `PC + imm` 强行串在一条
运算链上；应前置 target 或保留必要资源。

#### 3.14.12 保持仿真和综合等价、优先可移植 RTL

不要用 `initial`、`ifndef SYNTHESIS`、仿真专用 alias 或 test-only state 承载功能
状态、控制依赖或 testbench 必需接口。功能状态由真实 reset/valid 表达，观测通过
bind、trace 或 testbench 层完成。

数据选择和共享优先采用可移植 RTL、紧凑 encoding 和明确状态复用；不要用器件原语
伪造数据 mux 优势。原语只应用于确有器件级功能需求且不会掩盖结构问题的场景。

## 4. P6/F0-F1 的可复用方法

### 4.1 保持结构边界

P6 的 F0/F1 frontend 应与既有执行核心通过明确的参数和 `generate` 边界连接。
不要把前端流水级语义隐式传入较短 pipeline，或让 P6 sideband 改写默认配置的
端口、旁路协议和综合结构。

### 4.2 前端请求、cache miss 与 response credit

将 request ownership、miss issue、response credit 和 cache hit delivery 分开管理。
固定 request skid、局部 credit、registered hit/miss issue 和 payload prefill 都是
可用工具；关键原则是由各自 owner 保存状态，跨边界只传窄 token。

避免把 tag lookup、miss reservation、response room 或 invalidate 判断反馈到全局
ready。任何预取、同拍回收或额外 shadow 都应先确认它没有把控制锥重新接回 IFU。

### 4.3 branch 与 normal LSU

条件分支消费 delayed normal-LSU 结果时，不要把原始 LSU response 拉回 dispatch、
BRU 或 IFU。应在已有 dispatch/EXU 边界维护 branch 专用 local mirror：

* dispatch 生成 source/valid sideband。
* `dispatch_pipe` 或 EXU 捕获 branch operand 的 after-edge 值。
* 既有 bypass source mux 完成最终选择，避免额外 outer mux。
* branch/redirect 只消费已登记 operand 或窄 direction token。

这保留 delayed load 语义，同时防止 normal LSU data 进入 branch、redirect 和 PC 的
组合 fast path。

### 4.4 hot cache：早判定、局部取数、沿原协议释放

hot cache 的 tag/hit 可在较早阶段判定，但跨边界只传 hit 和必要 metadata。data RAM
选择留在 EXU LSU，随后沿原有 load writeback、HDU release 和 local bypass 路径前进。
不要把 hit data 或 late lookup 直接接入 dispatch branch operand。

cache tag/data 应与 valid/reset 分离：reset 或 invalidate valid，payload 使用可推断
RAM 的局部写口。store mutation 先在 LSU-local event 中登记，再更新 hot cache，避免
外部 write handshake 直接进入 RAM write-enable 或 dispatch conflict cone。

### 4.5 PC、预测器和 cache capacity

redirect/predicted successor 可保存在并行 PC bank 中，cache/backpressure 只控制窄
selector。不要使用宽 resolved-PC shadow 或把 PC data mux 扩散到所有 consumer。

ordered miss overlap 需要每个 outstanding request 的 metadata、invalidate-kill 和
response ordering；容量释放应基于已登记状态，不应依赖同拍异步回包。

### 4.6 P6 应避免的方向

以下方向通常只是移动路径或增加新扇出，应以特别严格的后端分析对待：

* 宽 PC shadow、宽 branch descriptor 或 RAM data snapshot。
* 仅复制 branch/ALU bank 或 selector，而没有切断原始 LSU-to-branch 控制链。
* 把 BPU training 或 lookup 反馈接到 branch operand、PC 或全局 ready。
* 将 hot-cache lookup、commit-hot 或 WBU 远端控制拉回 dispatch。
* 把 I-cache invalidate、response pop 或 writeback completion 做成跨模块组合捷径。

## 5. 面积优化方法

### 5.1 删除可再派生的信息

只保存不能由 instruction、operand、decode、commit ID 或既有 metadata 推导的信息。
重复的 operand register、重复的地址、重复的 control sidecar 和多处 shadow 都会增加
FF、mux 和 routing。删除前必须确认 flush、stall、replay 和 consumer 时序仍有足够
信息。

### 5.2 Reset 只覆盖架构可见或有效状态

payload、RAM data、bypass bank 和无效 FIFO 内容通常不需要 reset。reset valid、
owner、状态机和必须确定的控制位；数据由 valid 或 identity 限定可见性。这样可减少
reset mux、fanout 和阻碍 RAM inference 的异步 reset。

### 5.3 控制编码和 payload 打包

使用足够窄且语义明确的 encoding。disabled feature 的字段、无用 sideband 和重复的
one-hot 信息应在 generate 边界裁掉。压缩前确认 debug、exception、flush 和跨阶段
消费点不会依赖被删除字段。

### 5.4 FIFO/RAM 写法按目标器件判断

小 FIFO、LUTRAM、BRAM、寄存器阵列和 shift register 的最优写法依赖端口数、读延迟、
reset、深度、宽度和目标 FPGA。先确认工具推断出的真实结构，再决定是否改写 RTL；
不要仅凭代码行数或抽象模型判断面积。

### 5.5 共享运算器需先建立仲裁

只有请求者互斥或已被明确仲裁时，才共享 add/sub、compare、shift 或多周期算术单元。
功能单元保留协议、异常和所有权；共享 datapath 接受稳定的 `{op1, op2, operation}`
请求并向对应 consumer 返回结果。不能先删除独立运算器，再补冒险和 target 计算。

### 5.6 Probe 和调试逻辑留在 testbench

综合 RTL 中的 debug counter、宽 probe、字符串、性能统计和仅用于观测的 shadow
会消耗 LUT/FF 并改变 fanout。可综合设计只保留功能必需状态，观测应放在 testbench、
bind、trace interface 或综合排除的专用逻辑中。

## 6. 综合语义与正确性边界

### 6.1 明确位宽、常量和默认赋值

所有移位、拼接、符号扩展、参数表达式和零宽分支都应显式处理。不要依赖工具对
unsized constant、截断、signed conversion 或零宽 replication 的隐式解释。

### 6.2 valid、identity 和 flush 必须同步演化

任何可延迟、重放、取消或复用的对象都需要同时携带 valid 与 identity。仅清 valid
不足以解决 stale response；仅保存地址也无法区分 slot reuse。epoch、generation、
commit ID 和 owner token 必须在分配、完成、flush 和回收时一致更新。

### 6.3 side effect 必须有唯一可见点

GPR、CSR、store、interrupt、cache mutation 和 predictor training 都应有明确的提交或
发布边界。wrong-path 或 killed response 只能被 drain，不能更新架构状态、RAM 或
全局预测状态。

## 7. 性能保护方法

### 7.1 用 stall 分类决定优先级

将性能损失区分为 IF miss、AXI backpressure、load-use、load-to-branch、scoreboard
full、branch rollback、multi-cycle FU 和 cache conflict。针对占比最大的 stall cluster
设计补偿，而不是先扩大预测表、恢复组合前递或复制 datapath。

### 7.2 性能补偿不能破坏时序边界

性能优化优先选择：

* 减少真实等待而不是伪造同步 RAM 的同拍数据。
* 通过局部 token、bank 或预登记 metadata 解除 stall。
* 保持 payload/local data 在 owner 内，跨边界只走窄控制。
* 保持 outstanding、response ordering、flush 和 side effect 的协议。

任何以“少等一拍”为目标的组合 shortcut，都应先检查是否重新连接了 LSU、HDU、
dispatch、BRU、IFU 或全局 CE。

## 8. 反模式

* 用 OOC 正向结果直接宣称后端收敛。
* 为改善一条路径，将 late data 接入 branch、flush、PC 或全局 CE。
* 用 request handshake、tag hit 或地址预测提前释放变延时 consumer。
* 为了省面积缩小 FIFO/outstanding，却没有评估性能和协议容量。
* 把 macro-on 结构优化无条件应用到 baseline。
* 仅复制 selector、bank 或 descriptor，却不消除原始数据/控制依赖。
* 用 `keep`、`dont_touch`、`max_fanout` 等属性掩盖结构问题。
* reset 所有 payload，或把 probe/debug 留在可综合 RTL。
* 将实验数字、日志和源码快照混入方法论文档。

## 9. 最短执行清单

1. 固定配置、频率、hierarchy 和验收阶段。
2. 聚类关键路径，找出实际数据锥和控制锥。
3. 明确 owner、valid、identity、flush 和 backpressure。
4. 只改一个路径簇，优先传窄 token、保留局部宽数据。
5. 检查 forwarding、bypass、writeback 和 release 的层级是否仍清楚。
6. 检查同步 RAM、FIFO capacity、response ordering 和 side effect。
7. 用同口径综合和后端报告验证结构是否真正改善。
8. 将数值、日志和源码快照放入独立实验记录；知识库只更新可复用结论。

## 10. 最短记忆版

* 先语义，后 QoR。
* 先看路径簇，后改模块。
* late data 不进 branch/flush/PC/global CE。
* 宽数据留 local，跨级只传窄 token。
* owner、valid、identity、flush 必须一起设计。
* forwarding、bypass、writeback 各司其职。
* 变延时结果只由真实 completion release。
* 同步 RAM 的延迟必须显式建模。
* `ready`、credit、FIFO 和 response 不借未来容量。
* P6 的前端、预测器、recovery 和 LSU 都要有明确的注册边界。
* OOC 用于筛选，后端用于验收。
* 记录实验事实，沉淀结构方法。
