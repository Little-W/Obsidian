# SystemVerilog Assertions（SVA）完整中文教程

> **第 4 册 · 断言语言与设计规则**　版本 1.0 · 2026-10-17  
> 面向 SystemVerilog IEEE 1800 的主要并发断言语法与工程应用；具体 VC Formal 支持范围和限制见 User Guide §3.7～3.9（第 89～105 页）及附录 B（第 1109 页起）。部分标准允许的写法可能因工具版本、求解方式或多时钟条件而不可用，使用前需验证实际编译。

## 1. SVA 解决什么问题

SVA 是用 SystemVerilog 描述时间相关规则的一组语言结构。它不仅可以检查单个信号是否为正确值，还能表达“请求以后数拍内必须应答”“在握手完成之前数据必须保持稳定”等跨周期关系。SVA 可以用于仿真，亦可以在形式验证时被工具转化为逻辑属性。SVA 本身并不让环境自动合法；外部输入要求仍然需要明确的假设和复位模型。

![SVA 触发与周期关系](插图/05_SVA时序.svg)

## 2. 先理解三种角色

```systemverilog
ap_safety: assert property (@(posedge clk) disable iff (!rst_n)
                            !(write && full && !read));
as_input:  assume property (@(posedge clk) disable iff (!rst_n)
                            req |-> input_valid);
cp_full:  cover  property (@(posedge clk) disable iff (!rst_n)
                            full);
```

`assert property` 定义需要被验证的设计责任；`assume property` 描述环境向设计提供的约束；`cover property` 请求寻找满足某条行为的输入轨迹。不要把设计错误的结论改写为 `assume` 以获得更多的 `Proven`。

## 3. 并发断言的时钟、采样与失效条件

### 3.1 标准结构

```systemverilog
property p_example;
  @(posedge clk) disable iff (!rst_n)
  trigger |-> ##[1:3] response;
endproperty

ap_example: assert property (p_example);
```

- `@(posedge clk)`：属性在时钟上升沿采样。
- `disable iff (!rst_n)`：复位低有效期间关闭或中止该属性的活动求值。
- `trigger`：时序要求的触发部分；称为前件（antecedent）。
- `|->`：重叠蕴含；后件从前件序列匹配结束的那个采样周期开始。
- `##[1:3] response`：允许未来第 1、2 或 3 个采样周期响应。

SVA 并发断言在时钟事件的采样值上判断表达式，通常会看到 **NBA 非阻塞赋值更新之前**采样到的值。因此，在 `always_ff @(posedge clk)` 中用非阻塞赋值更新的寄存器，其新值通常在下一次采样沿才被断言看到。检查“状态更新后”的规则时往往需要 `|=>` 或 `$past`。

### 3.2 复位并不是采样函数历史自动清零

`disable iff` 是属性失效条件；不能将其理解为 `$past` 自动替换成复位值。比如初次进入正常工作状态时，上一拍可能仍处于复位。如果规则依赖上一拍已经处于有效工作状态，应增加 `past_valid` 寄存器或适当的 `$past(rst_n)` 前提。

```systemverilog
logic past_valid;
always_ff @(posedge clk or negedge rst_n)
  if (!rst_n) past_valid <= 1'b0;
  else        past_valid <= 1'b1;

ap_hold: assert property (@(posedge clk) disable iff (!rst_n)
  past_valid && hold |-> data == $past(data));
```

上例的 `past_valid` 为工具提供可信的前一采样点。在不同时间点立即释放/断言复位时，异步 `disable iff` 和时钟采样的交互仍应按 DUT 的实际复位语义审查。

### 3.3 default clocking / default disable iff

```systemverilog
default clocking cb @(posedge clk); endclocking
default disable iff (!rst_n);

ap_onehot: assert property ($onehot0(grant));
```

适用于同一时钟下的属性模块。多时钟或不同复位域，建议为每条关键属性显式指定时钟和失效条件，避免默认时钟覆盖不匹配的接口。

## 4. 重叠蕴含与非重叠蕴含

| 表达式 | 正确读法 | `a` 于第 5 拍成立时 |
|---|---|---|
| `a |-> b` | 同一触发位置检查 b | 第 5 拍检查 b |
| `a |=> b` | 下一个采样位置检查 b | 第 6 拍检查 b |
| `a |-> ##2 b` | 后件延迟 2 拍 | 第 7 拍检查 b |
| `a |=> ##2 b` | 下拍开始再延迟 2 拍 | 第 8 拍检查 b |

对**长度大于 1 的前件序列**，后件从前件**完成匹配的那个周期**计算，而不简单从前件的第一个周期计算。逻辑上可以把 `a |=> b` 视为 `a |-> ##1 b`（对这里简单的布尔时序表达），但是复杂序列与时间区域需要按定义分析。

## 5. sequence 和 property 的职责

```systemverilog
sequence s_accept;
  valid && ready;
endsequence

sequence s_finish_within_3;
  ##[1:3] done;
endsequence

property p_finish;
  @(posedge clk) disable iff (!rst_n)
  s_accept |-> s_finish_within_3;
endproperty

ap_finish: assert property(p_finish);
```

`sequence` 描述如何匹配一个有限时序片段；`property` 组合时序规则、蕴含、停止和其他属性运算符。复杂序列可以接受参数和局部变量，用于协议检测、延迟记录及数据关联。推荐给可重复使用的时序模式起易读的名称。

## 6. 序列连接与延迟运算符

### 6.1 固定延迟 `##n`

```systemverilog
sequence s_two_cycles;
  a ##2 b;
endsequence
```

这要求 `a` 后第二个采样时刻 `b` 成立。`a ##0 b` 要求二者在同一采样时刻满足。当 `a` 是多周期序列时，`##n` 从 `a` 匹配结束处计算。

### 6.2 范围延迟 `##[m:n]`

```systemverilog
ap_ack_1_4: assert property (@(posedge clk) disable iff (!rst_n)
  $rose(req) |-> ##[1:4] ack);
```

`ack` 可以在第 1～4 拍任一时刻满足。要注意**逐拍重新发起的并行检查**：如果 `req` 连续高 4 拍，使用 `req` 作为前件就会发起 4 条独立的响应义务。使用 `$rose(req)` 仅表示检测上升沿，仍不一定等价于总线“接受请求”的定义。

### 6.3 连续重复 `[*]`

```systemverilog
// busy 必须持续 3 拍
ap_busy: assert property (@(posedge clk) disable iff (!rst_n)
  start |-> ##1 busy[*3]);

// ready 可以延迟出现，示意有界等待
ap_wait: assert property (@(posedge clk) disable iff (!rst_n)
  start |-> (!ready)[*0:3] ##1 ready);
```

`[*3]` 表示连续 3 次匹配；`[*1:4]` 表示连续 1～4 次；`[*0:$]` 允许零次且上限无限，和后续表达式连接时可能形成意料外的空匹配。尤其是空匹配与蕴含组合，必须通过覆盖和波形验证真正在检查的规则。

### 6.4 非连续重复 `[=]` 与 goto 重复 `[->]`

```systemverilog
sequence s_three_events;
  event_a[=3];
endsequence

sequence s_second_hit;
  event_a[->2];
endsequence
```

`[=3]` 描述在一段匹配范围内出现三次非连续的 `event_a`，可在最后一次命中后继续匹配非事件周期；`[->2]` 直到第二次事件命中处结束。两者区别会改变和后续 `##1 b` 的关系，复杂协议建议先写小型波形测试确认其末端匹配位置。

## 7. 序列的组合

### 7.1 `and` / `or` / `intersect`

```systemverilog
sequence s_both;
  (a ##1 b) and (c ##2 d);
endsequence

sequence s_one;
  (a ##1 b) or (a ##2 b);
endsequence

sequence s_same_window;
  (a ##1 b) intersect (c ##1 d);
endsequence
```

`and` 要求两个序列都匹配，但它们的结束位置不要求相同；`intersect` 要求匹配区间的开始和结束一致。`or` 允许任意一个序列匹配。不要把序列 `and` 与普通同周期位运算 `&&` 混淆。

### 7.2 `throughout`：范围内持续成立

```systemverilog
ap_hold_during_busy: assert property (@(posedge clk) disable iff (!rst_n)
  start |-> (enable throughout (busy[*1:5] ##1 done)));
```

`expr throughout sequence` 表示布尔表达式在被匹配序列涉及的全部采样位置保持真。对于简单请求保持协议，通常 `req && !ack |=> req` 更直接、更易审查。

### 7.3 `within`：一个时序片段位于另一个片段范围中

```systemverilog
sequence s_short;
  a ##1 b;
endsequence
sequence s_outer;
  start ##[1:5] stop;
endsequence
sequence s_inside;
  s_short within s_outer;
endsequence
```

`within` 可以表达一个事件序列完整发生在更大序列匹配区间之内。涉及可变时长时要特别警惕匹配歧义。使用工具的 `cover` 检查预期的代表性路径。

### 7.4 `first_match`

```systemverilog
sequence s_first_ack;
  first_match(##[1:8] ack);
endsequence
```

用于从候选匹配中选取首次匹配，减少后续序列对不同匹配长度的歧义。不是所有需要“最早应答”的规则都要使用 `first_match`；如果只要求区间内任一次应答，则直接使用范围延迟更清楚。

## 8. 属性运算符：时间上的持续和终止

### 8.1 `until` 与 `until_with`

```systemverilog
ap_keep_valid: assert property (@(posedge clk) disable iff (!rst_n)
  req |-> (valid until_with ack));
```

`until` 不要求条件在终止条件发生的那个周期仍成立；`until_with` 要求在终止周期也成立。弱形式可能不要求终止条件真的出现，因此如果要求“必须最终完成”，还需要强形式或独立的有界完成检查。

### 8.2 `strong` 与 `weak`

```systemverilog
ap_eventual: assert property (@(posedge clk) disable iff (!rst_n)
  req |-> strong(##[1:$] ack));
```

`strong` 表示时序匹配最终必须结束（具体可证明性视形式应用、活性支持以及公平性而定）；`weak` 允许一些有限轨迹或无限未完成场景下的宽松解释。无条件无限等待往往困难，实际项目应先考虑规范是否可以给出合理的最大响应延迟。强活性属性通常需要假设外部持续提供时钟与资源。

### 8.3 `accept_on` / `reject_on`

属性可在规定事件发生时被提前接受或拒绝。例如，一次事务在取消信号到来后不再要求原始应答，是否“取消即成功”必须符合协议而不能仅为了避免失败。`disable iff` 通常用于复位；`accept_on` 可用于协议意义上的正常取消；`reject_on` 可用于协议明确规定的提前失败条件。两者与采样时刻有关，项目需要按工具实现验证。

## 9. 常用采样函数

| 函数 | 含义 | 典型用途 | 容易忽略的地方 |
|---|---|---|---|
| `$past(expr, n)` | 读取前 n 次采样的值 | 下一周期状态关系 | 起始历史值未定义 |
| `$rose(expr)` | 检测从非真到真的变化 | 捕获请求新事务 | 不等同于 `req && ready` |
| `$fell(expr)` | 检测从真到非真的变化 | 撤销请求 | 异步与 X 变化要谨慎 |
| `$stable(expr)` | 当前值与上一采样相同 | 等待期间数据保持 | 初始样本的比较问题 |
| `$changed(expr)` | 与上一采样不同 | 寻找状态翻转 | 重复周期持续匹配 |
| `$isunknown(expr)` | 表达式包含 X 或 Z | 仿真与 X 检查 | 二值形式模型解释可不同 |
| `$onehot(expr)` | 恰有一位为 1 | 必须存在且唯一授权 | 空闲时全零会失败 |
| `$onehot0(expr)` | 最多一位为 1 | 允许空闲的授权 | 不能保证至少有一位 |
| `$countones(expr)` | 统计为 1 的位数 | 配额/令牌检查 | 大位宽求解可能昂贵 |
| `$initstate` | 初始时间检测 | 初始化相关规则 | 工具、上下文支持需核对 |

### 9.1 `$past` 的正确使用

```systemverilog
ap_count_inc: assert property (@(posedge clk) disable iff (!rst_n)
  past_valid && $past(inc && !clear)
    |-> count == $past(count) + 1'b1);
```

这是在**当前采样周期**检查上一周期已满足加一条件后的寄存器值。若计数器会饱和或回绕，还必须补上对应前提。需要特别确认 `past_valid` 的第一个有效周期与设计运行时序一致。

### 9.2 `$stable` 的常见错误

对 `valid && !ready |=> $stable(data)` 的解释要看接口在下一拍是否仍继续 `valid`。若数据在 `valid && ready` 发生后下一拍可以自由变化，则这个规则可能过度严格。更常用且直观的条件是：

```systemverilog
ap_stable_when_stalled: assert property (@(posedge clk) disable iff (!rst_n)
  valid && !ready |=> valid && $stable(data));
```

这个写法要求：上一拍未被接受的传输，下一拍仍保持 `valid` 和数据，恰好符合很多 ready/valid 接口的要求。允许在下一拍被接受并不改变“采样的当前数据仍应保持”的要求。

## 10. 立即断言和并发断言的区别

```systemverilog
always_comb begin
  assert (!(grant[0] && grant[1]))
    else $error("two simultaneous grants");
end

ap_grant: assert property (@(posedge clk) disable iff (!rst_n)
  $onehot0(grant));
```

立即断言在过程执行时检查瞬时条件，可能受组合逻辑的调度次序、暂态变化及 X 值影响；并发断言按事件采样，便于表达时序关系。形式验证中要遵循该工具对即时/延迟断言支持的说明；不能把所有仿真调试语句当成可被形式引擎直接证明的属性。

## 11. 属性局部变量、`let` 和参数化

### 11.1 `let`：抽象复杂布尔条件

```systemverilog
let accepted(v, r) = (v && r);

ap_no_drop: assert property (@(posedge clk) disable iff (!rst_n)
  accepted(valid, ready) |-> !error);
```

`let` 表达式可复用，减少同一接口条件在几十条属性中被不同工程师写出微小差异。是否使用 `let` 由编译器支持情况决定。

### 11.2 sequence 局部变量：关联请求与响应数据

```systemverilog
property p_data_return;
  logic [7:0] saved_id;
  @(posedge clk) disable iff (!rst_n)
    (req, saved_id = req_id) |-> ##[1:4]
      (rsp && rsp_id == saved_id);
endproperty
ap_data_return: assert property (p_data_return);
```

此属性为**每一次匹配的请求**保存其标识并要求窗口内匹配应答。若允许多个并发请求且同一标识重复使用，仍需根据协议处理事务编号、队列深度、重排规则和独立超时。局部变量并非 RTL 中真的增加了寄存器，工具可能为断言引入匹配状态，过度复杂的动态序列会增加形式求解成本。

### 11.3 参数化属性

```systemverilog
module ready_valid_checker #(
  parameter int DATA_W = 32,
  parameter int RESP_MAX = 8
) (
  input logic clk, rst_n, valid, ready,
  input logic [DATA_W-1:0] data
);
  ap_stall: assert property (@(posedge clk) disable iff(!rst_n)
    valid && !ready |=> valid && $stable(data));
  cp_transfer: cover property (@(posedge clk) disable iff(!rst_n)
    valid && ready);
endmodule
```

参数化断言适合复用在多个实例；但 `RESP_MAX` 等参数如果在属性中用于常量延迟，必须遵守工具对常量表达式的要求。

## 12. `bind`：无需改动设计源码注入 SVA

```systemverilog
module counter_checker (
  input logic clk, rst_n, inc,
  input logic [3:0] count
);
  ap_range: assert property (@(posedge clk) disable iff(!rst_n)
    count <= 4'd9);
  cp_full: cover property (@(posedge clk) disable iff(!rst_n)
    count == 4'd9);
endmodule

bind counter counter_checker u_checker (
  .clk(clk), .rst_n(rst_n), .inc(inc), .count(count)
);
```

`bind` 在指定设计模块或实例上附加检查器，不必改动交付 RTL。但要确保端口名与被绑定模块一致，检查器的编译顺序正确，且顶层编译开启断言支持（例如相应流程中的 `-sva`）。**不要在形式测试文件里用 `assign` 强行驱动 DUT 的内部状态来代替外部约束**。

## 13. 常见系统级断言模板

### 13.1 复位值

```systemverilog
ap_reset_state: assert property (@(posedge clk)
  !rst_n |-> state == IDLE);
```

此示例适用于复位在该采样时钟上足够早生效，且状态在这一采样点应已为 `IDLE` 的协议模型。若同步复位在 `posedge clk` 的 NBA 才生效，应换成正确的下一拍检查；异步复位应另外确认有效瞬间与采样要求。

### 13.2 一热与互斥

```systemverilog
ap_mutex: assert property (@(posedge clk) disable iff(!rst_n)
  $onehot0(grant));
ap_one_grant_when_pending: assert property (@(posedge clk) disable iff(!rst_n)
  pending |-> $onehot(grant));
```

第二条仅适用于协议要求有请求时必须立刻授权，否则应改成有界最终授权，并定义公平条件。

### 13.3 请求—应答

```systemverilog
ap_ack: assert property (@(posedge clk) disable iff(!rst_n)
  (req && accept) |-> ##[1:3] ack);
cp_req: cover property (@(posedge clk) disable iff(!rst_n)
  req && accept);
```

该写法有一个明确的受理事件；如果 `ack` 可能与受理同周期，则窗口改成 `##[0:3]`。若协议允许接受多个请求，需要采用事务关联检查。

### 13.4 背压期间保持

```systemverilog
ap_hold: assert property (@(posedge clk) disable iff(!rst_n)
  valid && !ready |=> valid && $stable(payload));
```

对于标准 ready/valid 流控制，后一拍可以 `ready` 变为 1，此时仍须在握手时提供原来的 `payload`。

### 13.5 FIFO 不上溢、不下溢与计数范围

```systemverilog
ap_depth: assert property (@(posedge clk) disable iff(!rst_n)
  occupancy <= DEPTH);
ap_no_empty_pop: assert property (@(posedge clk) disable iff(!rst_n)
  pop_accept |-> !empty);
ap_no_full_push: assert property (@(posedge clk) disable iff(!rst_n)
  push_accept |-> (!full || pop_accept));
```

这里假定 FIFO 允许满状态同时读写（具体需看实现），`push_accept/pop_accept` 是**已接受操作**而不是原始请求。若 `push` 为请求而硬件可以拒绝，那么 `push && full` 并非必然错误。计数器溢出的检查应与接受操作和旁路条件一致。

### 13.6 超时与重试

```systemverilog
ap_timeout: assert property (@(posedge clk) disable iff(!rst_n)
  launch |-> ##[1:8] (done || timeout));
```

本例只保证在第 1～8 拍的某一拍看到完成或超时，没有保证二者互斥；如果规定互斥，另外增加 `!(done && timeout)` 断言。

### 13.7 有限状态机状态合法性

```systemverilog
ap_state_legal: assert property (@(posedge clk) disable iff(!rst_n)
  state inside {ST_IDLE, ST_REQ, ST_WAIT, ST_DONE});
```

`inside` 中的常量值必须与 RTL 一致。枚举类型有时可以使用更清晰的编码检查；该属性只能证明取值合法，不能证明所有转移符合协议。

### 13.8 安全权限控制

```systemverilog
ap_secure_write: assert property (@(posedge clk) disable iff(!rst_n)
  write_accept && secure_reg_sel |-> privileged);
```

还需要检查非法请求是否被阻止、读路径是否泄漏以及复位后的权限状态。单条写入权限断言不代表已经证明没有信息泄漏。

## 14. 空洞性、覆盖目标与不恰当假设

```systemverilog
ap_req_ack: assert property (@(posedge clk) disable iff(!rst_n)
  req |-> ##[1:3] ack);
cp_req_seen: cover property (@(posedge clk) disable iff(!rst_n)
  req);
cp_req_ack: cover property (@(posedge clk) disable iff(!rst_n)
  req ##[1:3] ack);
```

反例：如果在其他文件里写了 `assume property(!req)`，`ap_req_ack` 可能轻松被证明，但是 `cp_req_seen` 不可达。**验证环境需要既让合法关键场景可达，又排除真实接口所禁止的输入行为。**

工程里建议同时维护三类检查：设计断言；环境前提的注释与审查；关键规格场景覆盖。形式覆盖与仿真覆盖不是同一概念，应分别分析。

## 15. 容易写错的规则与修正

| 错误写法或理解 | 风险 | 推荐修正 |
|---|---|---|
| `req |-> ack` 代表“下一拍应答” | 实际检查同拍 | 使用 `req |=> ack` 或 `##1` |
| `req |=> ##2 ack` 代表延迟 2 拍 | 实际延迟 3 拍 | 使用 `req |-> ##2 ack` |
| 直接 `$past(data)` 不检查历史 | 起始周期样本无效 | 以 `past_valid` 或 `$past(rst_n)` 守卫 |
| `req |-> ##[0:$] ack` 必然要求最终应答 | 弱匹配及工具处理可能不符合意图 | 使用有界响应或合适的强活性形式 |
| `req |-> ack` 证明通过就认为请求已发生 | 前件可能不可达 | 添加 `cover property(req)` |
| 在所有周期假设 `ready=1` | 屏蔽背压缺陷 | 只根据环境规格约束 `ready` |
| 用 `$onehot(grant)` 检查允许全零的授权 | 空闲周期错误失败 | 使用 `$onehot0(grant)` |
| 用 `count < DEPTH` 当作假设 | 直接假设安全性 | 改成 `assert`，必要时增加真实输入前提 |
| 用 `disable iff(!rst_n)` 就认为复位值已被证明 | 禁用了复位期间检查 | 另写复位属性或复位启动流程 |
| `cover property(done)` 认为所有请求都能完成 | 只证明至少存在一次完成 | 对每次合法请求写断言 |

## 16. 多时钟属性、X 值与复杂语法的限制

多时钟属性在 SystemVerilog 标准中有专门的采样与序列连接规则，不能简单将两种时钟事件放入单时钟模板。不同 EDA 引擎对多时钟交叉属性支持可能有限；参考 VC Formal User Guide §3.9 的具体限制。跨时钟同步器、握手与异步 FIFO 通常需分别定义每个时钟域的责任及跨时钟的数据一致性。

`$isunknown` 在四值仿真中很直观，但传统形式证明的二值布尔编码可能与仿真中的 X 传播语义不同；检查 RTL 中 X 传播风险更适合配合 VC Formal FXP 和明确的注入/观察模型。写有 `casex`、`casez`、`unique case` 的 RTL 时，还应结合综合与仿真对 X 的不同处理方式审查。

## 17. 完整示例：有界计数器

```systemverilog
module bounded_counter (
  input  logic clk, rst_n, enable,
  output logic [3:0] count
);
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) count <= '0;
    else if (enable && count == 4'd9) count <= '0;
    else if (enable) count <= count + 4'd1;
  end
endmodule

module bounded_counter_props (
  input logic clk, rst_n, enable,
  input logic [3:0] count
);
  logic history_valid;
  always_ff @(posedge clk or negedge rst_n)
    if (!rst_n) history_valid <= 1'b0;
    else        history_valid <= 1'b1;

  ap_range: assert property (@(posedge clk) disable iff(!rst_n)
    count <= 4'd9);
  ap_wrap: assert property (@(posedge clk) disable iff(!rst_n)
    history_valid && $past(enable && count == 4'd9)
      |-> count == 4'd0);
  ap_hold: assert property (@(posedge clk) disable iff(!rst_n)
    history_valid && $past(!enable)
      |-> count == $past(count));
  cp_wrap: cover property (@(posedge clk) disable iff(!rst_n)
    count == 4'd9 ##1 count == 4'd0);
endmodule

bind bounded_counter bounded_counter_props u_fpv_props (.*);
```

这组属性涵盖取值范围、回绕、保持和覆盖；但若绑定语句通配端口遇到编译限制，可以改成显式端口连接。假定 `rst_n` 在属性检查前被适当地初始化，否则有些属性仍可能在任意初始状态下失败。若把 RTL 中 `count == 9` 错写成 `count == 10`，`ap_range` 会在可达的第 10 个状态给出反例。

## 18. 工程练习（建议自行运行与审查）

1. 将计数器回绕阈值从 9 改为 10，观察 `ap_range` 的反例；将阈值改回后重复证明。
2. 删除 `history_valid`，分析首个有效采样点 `$past` 规则的差异。
3. 为一个 2 输入仲裁器编写互斥、授权必须对应请求和竞争覆盖三类属性。
4. 为 ready/valid 通道编写背压保持、握手可达与连续握手覆盖。
5. 故意加入约束 `assume(!enable)`，观察覆盖目标为什么无法满足，并撤销该约束。

可直接使用 [案例工程](案例工程/README.md) 提供的源代码和 VC Formal Tcl 脚本进行练习。

## 19. 语法检索表

| 语法 | 类型 | 说明 |
|---|---|---|
| `@(posedge clk)` | 采样事件 | 时钟上升沿 |
| `disable iff (cond)` | 失效条件 | 条件为真时关闭正在运行的属性匹配 |
| `##n` / `##[m:n]` | 序列延迟 | 固定或范围延迟 |
| `[*n]` / `[*m:n]` | 连续重复 | 连续匹配指定次数 |
| `[=n]` | 非连续重复 | 指定次数事件出现 |
| `[->n]` | goto 重复 | 第 n 次出现时匹配结束 |
| `|->` / `|=>` | 蕴含 | 重叠 / 非重叠 |
| `and` / `or` | 序列组合 | 双方均满足 / 任意一方满足 |
| `intersect` | 序列组合 | 区间起止匹配一致 |
| `within` | 序列组合 | 序列完整包含于另一序列区间 |
| `throughout` | 序列组合 | 布尔条件覆盖序列全部采样位置 |
| `first_match` | 匹配选择 | 第一次满足的候选匹配 |
| `until` / `until_with` | 属性时间关系 | 直到条件发生（含/不含终止采样） |
| `strong` / `weak` | 匹配强度 | 终止义务强弱 |
| `$past` / `$rose` | 采样函数 | 过去值 / 上升事件 |
| `assert` / `assume` / `cover` | 属性角色 | 证明 / 环境前提 / 到达目标 |
| `bind` | 检查器注入 | 将外部 SVA 模块附加到 DUT |

## 20. 参考与责任界定

本教程独立编写，对照 IEEE 1800 的常见语法概念以及用户所给 *VC Formal User Guide* X-2025.06-SP1 §3.7～3.9、附录 B。工具具体支持范围、强活性处理、采样行为和优化由正式安装版本决定。本文示例用于教学；没有声称在用户实际 VC Formal 授权环境中运行过全部代码。
