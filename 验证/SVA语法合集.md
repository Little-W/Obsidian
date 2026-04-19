# SVA 语法合集笔记

这份笔记整理 SystemVerilog Assertions，也就是 SVA 的常用语法、写法和示例。重点放在日常验证里最常用的 concurrent assertion、sequence、property、采样函数和绑定方式，目标是做到可以直接对照着写。

## 1. SVA 的基本骨架

SVA 最常见的结构是：

```systemverilog
property p_name;
	@(posedge clk) disable iff (!rst_n)
		antecedent |-> consequent;
endproperty

assert property (p_name);
```

核心元素有四个：

- 采样时钟事件：`@(posedge clk)`
- 失效屏蔽条件：`disable iff (!rst_n)`
- 前件条件：`antecedent`
- 后件条件：`consequent`

SVA 里的属性通常不是“立即执行”，而是按时钟采样后在时间线上判断。

## 2. 常见声明块

### 2.1 sequence

`sequence` 用来描述时序片段。

```systemverilog
sequence s_req_ack;
	req ##[1:3] ack;
endsequence
```

含义：`req` 发生后，`ack` 在 1 到 3 个周期内出现。

示例：

```systemverilog
sequence s_req_then_ack;
	req ##1 ack;
endsequence

sequence s_req_hold_ack;
	req ##[1:3] ack;
endsequence

property p_req_ack_seq;
	@(posedge clk) disable iff (!rst_n)
		s_req_then_ack;
endproperty

assert property (p_req_ack_seq);
```

这个例子里，`s_req_then_ack` 表示请求后固定 1 个周期应答，`s_req_hold_ack` 表示应答允许在 1 到 3 个周期内到达。

### 2.2 property

`property` 用来描述可证明的时序属性。

```systemverilog
property p_req_ack;
	@(posedge clk) disable iff (!rst_n)
		req |-> ##[1:3] ack;
endproperty
```

示例说明：这是最典型的 handshake 属性，适合总线请求、消息确认和事件应答场景。

示例说明：这是最典型的 handshake 属性，适合总线请求、消息确认和事件应答场景。

示例：

```systemverilog
property p_no_overflow;
	@(posedge clk) disable iff (!rst_n)
		push && !full |-> ##1 !full;
endproperty

assert property (p_no_overflow)
	else $error("FIFO overflow protection failed");
```

这个例子用于检查 FIFO 在非满且发生 push 时，下一拍仍然不能越过 full 状态。

### 2.3 assert / assume / cover

```systemverilog
assert property (p_req_ack);
assume property (p_env_stable);
cover property  (p_seen_something);
```

- `assert property`：证明属性必须成立。
- `assume property`：把属性作为环境假设。
- `cover property`：检查某个时序目标是否能到达。

示例：

```systemverilog
property p_env_stable;
	@(posedge clk) disable iff (!rst_n)
		!($isunknown(req) || $isunknown(ack));
endproperty

assume property (p_env_stable);

property p_req_ack;
	@(posedge clk) disable iff (!rst_n)
		req |-> ##[1:3] ack;
endproperty

assert property (p_req_ack);

cover property (@(posedge clk) disable iff (!rst_n) req ##[1:3] ack);
```

这个例子里，`assume` 先约束环境信号不含 X，`assert` 验证请求应答关系，`cover` 用来确认这条路径确实能走到。

## 3. 时钟与失效条件

### 3.1 clocking event

最常用写法是：

```systemverilog
@(posedge clk)
```

也可以用多个时钟事件，但最常见还是单时钟设计。

示例：

```systemverilog
assert property (@(posedge clk) req |-> ack);
assert property (@(negedge clk) reset_sync == 1'b0);
```

这里的采样事件决定了属性在哪个边沿上取样和判断。

### 3.2 disable iff

```systemverilog
@(posedge clk) disable iff (!rst_n)
```

当 `rst_n` 无效时，属性不检查。这个写法几乎是所有 FPV/SVA 里最常见的形式。

示例：

```systemverilog
property p_data_valid;
  @(posedge clk) disable iff (!rst_n)
    valid |-> !$isunknown(data);
endproperty
```

这个例子说明复位期间不检查，避免初始化阶段的 X 值把属性误判掉。

### 3.3 default clocking / default disable iff

```systemverilog
default clocking cb @(posedge clk); endclocking
default disable iff (!rst_n);
```

这两句适合把所有属性的默认采样时钟和复位屏蔽条件统一起来。

示例：

```systemverilog
default clocking cb @(posedge clk); endclocking
default disable iff (!rst_n);

property p_ready_stable;
  ready |-> ##1 ready;
endproperty

assert property (p_ready_stable);
```

这个写法里，属性本身没有显式写时钟和 reset，但会自动继承默认配置。

## 4. 立即断言与并发断言

### 4.1 立即断言

```systemverilog
assert (a == b) else $error("a != b");
```

立即断言通常用于组合逻辑或局部检查，不是典型的时序属性。

示例：

```systemverilog
always_comb begin
	assert (addr < DEPTH) else $fatal("addr out of range");
end
```

这个例子适合做组合范围检查，不依赖时钟采样。

### 4.2 并发断言

```systemverilog
assert property (@(posedge clk) disable iff (!rst_n) req |-> ack);
```

并发断言才是 SVA 的主体，能表达跨周期的时序关系。

示例：

```systemverilog
assert property (@(posedge clk) disable iff (!rst_n)
	req |-> ##[1:2] ack
);
```

这个例子要求请求之后 1 到 2 个周期内必须看到应答。

## 5. 最常用的序列运算符

### 5.1 连接 `##n`

```systemverilog
req ##1 ack
```

表示 `req` 之后第 1 个周期出现 `ack`。

补充：`##0` 表示同一采样周期。

示例：

```systemverilog
sequence s_one_cycle_late;
	req ##1 ack;
endsequence

sequence s_same_cycle;
	req ##0 ack;
endsequence
```

`##1` 常用于普通握手，`##0` 常用于同拍条件检查。

### 5.2 区间延迟 `##[m:n]`

```systemverilog
req ##[1:3] ack
```

表示 `ack` 在 1 到 3 个周期内出现。

示例：

```systemverilog
property p_ack_window;
	@(posedge clk) disable iff (!rst_n)
		req |-> ##[1:3] ack;
endproperty
```

这个写法适合允许固定延迟范围的协议。

### 5.3 连续重复 `[*]`

```systemverilog
busy[*3]
busy[*1:4]
```

表示连续重复若干次。

示例：

```systemverilog
sequence s_busy_3;
	busy[*3];
endsequence

property p_busy_then_done;
	@(posedge clk) disable iff (!rst_n)
		s_busy_3 |-> done;
endproperty
```

这个例子表示 `busy` 连续保持 3 个周期后，后面应当进入 `done`。

### 5.4 非连续重复 `[=]`

```systemverilog
event[=2]
```

表示事件出现 2 次，但中间可以夹杂其它周期。

示例：

```systemverilog
sequence s_two_hits;
	event[=2];
endsequence
```

这个语法适合统计型描述，允许两次命中之间夹杂其它无关周期。

### 5.5 goto 重复 `[->]`

```systemverilog
event[->1]
```

表示找到第 1 次目标事件的位置。

示例：

```systemverilog
sequence s_first_req;
	req[->1];
endsequence
```

这个写法常用于只关心第一次命中点的场景。

### 5.6 逻辑组合 `and` / `or`

```systemverilog
s1 and s2
s1 or  s2
```

- `and`：两个序列都要成立。
- `or`：任一序列成立即可。

示例：

```systemverilog
sequence s_req_window;
	req ##[1:3] ack;
endsequence

sequence s_idle_window;
	idle ##1 idle;
endsequence

property p_alt_paths;
	@(posedge clk) disable iff (!rst_n)
		(s_req_window or s_idle_window);
endproperty
```

这个例子表示属性可以由两条不同的合法路径之一满足。

### 5.7 交集 `intersect`

```systemverilog
s1 intersect s2
```

要求两个序列在同一时间窗口上同时成立。

示例：

```systemverilog
sequence s_data_phase;
	req ##1 data_valid;
endsequence

sequence s_ack_phase;
	req ##1 ack;
endsequence

property p_overlap;
	@(posedge clk) disable iff (!rst_n)
		s_data_phase intersect s_ack_phase;
endproperty
```

这个例子要求两个不同序列在时间上重叠命中。

### 5.8 包含关系 `within`

```systemverilog
s1 within s2
```

表示 `s1` 发生在 `s2` 的时间范围内。

示例：

```systemverilog
sequence s_error;
	error_pulse;
endsequence

sequence s_burst;
	start ##[1:5] done;
endsequence

property p_error_inside_burst;
	@(posedge clk) disable iff (!rst_n)
		s_error within s_burst;
endproperty
```

这个例子表示错误脉冲只能出现在一次事务窗口之内。

### 5.9 全程保持 `throughout`

```systemverilog
s_hold throughout s_window
```

表示在 `s_window` 持续期间，`s_hold` 必须一直成立。

示例：

```systemverilog
property p_req_hold_until_done;
	@(posedge clk) disable iff (!rst_n)
		req |-> (req throughout (!done));
endproperty
```

这个例子表示从 `req` 拉高开始，到 `done` 出现之前，`req` 必须一直保持有效。

### 5.10 首次匹配 `first_match`

```systemverilog
first_match(req ##[1:5] ack)
```

当多种匹配路径都可能成立时，选择最早匹配的一条。

示例：

```systemverilog
property p_first_ack;
	@(posedge clk) disable iff (!rst_n)
		first_match(req ##[1:5] ack);
endproperty
```

这个例子会优先选择最早出现 `ack` 的那条路径。

### 5.11 取反 `not`

```systemverilog
not ack
```

表示该序列不能成立。

示例：

```systemverilog
property p_no_ack_same_cycle;
	@(posedge clk) disable iff (!rst_n)
		req |-> not ack;
endproperty
```

这个例子表示请求出现后的同一时刻不应该立刻看到应答。

## 6. 最常用的属性运算符

### 6.1 蕴含 `|->`

```systemverilog
req |-> ack
```

表示前件成立时，后件必须成立。后件通常从当前周期或接下来定义的时序开始判断。

示例：

```systemverilog
property p_req_implies_ack;
	@(posedge clk) disable iff (!rst_n)
		req |-> ack;
endproperty
```

这是最基础的请求应答型属性写法。

### 6.2 非重叠蕴含 `|=>`

```systemverilog
req |=> ack
```

表示前件成立后，后件从下一个周期开始检查。

示例：

```systemverilog
property p_req_next_ack;
	@(posedge clk) disable iff (!rst_n)
		req |=> ack;
endproperty
```

如果你明确要检查下一拍是否成立，就用 `|=>`。

### 6.3 until / until_with

```systemverilog
busy until done
busy until_with done
```

- `until`：`busy` 要一直成立，直到 `done` 出现。
- `until_with`：`done` 出现的那个周期也要满足组合条件。

示例：

```systemverilog
property p_busy_until_done;
	@(posedge clk) disable iff (!rst_n)
		busy until done;
endproperty

property p_busy_until_with_done;
	@(posedge clk) disable iff (!rst_n)
		busy until_with done;
endproperty
```

这两个属性经常用于事务保持和结束条件检查。

### 6.4 strong / weak

```systemverilog
strong(req ##[1:3] ack)
weak(req ##[1:3] ack)
```

- `strong`：要求序列必须最终完成。
- `weak`：允许序列在有限观察窗口里未完成。

示例：

```systemverilog
property p_strong_ack;
	@(posedge clk) disable iff (!rst_n)
		strong(req ##[1:3] ack);
endproperty

property p_weak_ack;
	@(posedge clk) disable iff (!rst_n)
		weak(req ##[1:3] ack);
endproperty
```

如果你希望序列必须完成，就用 `strong`；如果只是在有限观察窗口里检查，就用 `weak`。

### 6.5 accept_on / reject_on

```systemverilog
accept_on (flush)  req |-> ack
reject_on  (err)    req |-> ack
sync_accept_on (flush) req |-> ack
sync_reject_on  (err)   req |-> ack
```

- `accept_on`：当条件成立时，当前属性可以被接受为通过。
- `reject_on`：当条件成立时，当前属性可以被直接判失败。
- `sync_accept_on` / `sync_reject_on`：同步语义版本，常用于更严格的时序控制。

示例：

```systemverilog
property p_flush_accept;
	@(posedge clk) disable iff (!rst_n)
		accept_on (flush) req |-> ack;
endproperty

property p_error_reject;
	@(posedge clk) disable iff (!rst_n)
		reject_on (err) req |-> ack;
endproperty
```

这个例子适合带清空条件或错误中断条件的协议场景。

## 7. 常用采样函数

### 7.1 $past

```systemverilog
$past(data)
$past(data, 2)
```

读取前 1 个周期或前 N 个周期的值。

示例：

```systemverilog
property p_data_compare;
	@(posedge clk) disable iff (!rst_n)
		valid |-> (data != $past(data));
endproperty
```

这个例子检查有效数据和上一拍不相同，常用于变化检测。

### 7.2 $rose / $fell

```systemverilog
$rose(valid)
$fell(valid)
```

检测上升沿和下降沿。

示例：

```systemverilog
property p_req_rise;
	@(posedge clk) disable iff (!rst_n)
		$rose(req) |-> ##[1:3] ack;
endproperty
```

这个例子只在 `req` 的上升沿触发检查。

### 7.3 $stable / $changed

```systemverilog
$stable(data)
$changed(data)
```

检测信号是否保持不变，或者是否发生变化。

示例：

```systemverilog
property p_data_stable_when_waiting;
	@(posedge clk) disable iff (!rst_n)
		valid && !ready |-> $stable(data);
endproperty
```

这个例子适合握手等待期间的数据保持检查。

### 7.4 $isunknown

```systemverilog
$isunknown(data)
```

检测信号里是否存在 X / Z。

示例：

```systemverilog
property p_no_x_on_data;
	@(posedge clk) disable iff (!rst_n)
		valid |-> !$isunknown(data);
endproperty
```

这个例子避免有效数据中出现未知值。

### 7.5 $onehot / $onehot0

```systemverilog
$onehot(state)
$onehot0(state)
```

- `$onehot`：恰好只有 1 位为 1。
- `$onehot0`：允许全 0 或恰好 1 位为 1。

示例：

```systemverilog
property p_state_onehot;
	@(posedge clk) disable iff (!rst_n)
		$onehot(state);
endproperty

property p_state_onehot0;
	@(posedge clk) disable iff (!rst_n)
		$onehot0(state);
endproperty
```

一个适合严格编码，一个适合允许空闲态全 0 编码。

### 7.6 $countones

```systemverilog
$countones(state)
```

统计 1 的个数，常用于编码检查。

示例：

```systemverilog
property p_onehot_by_count;
	@(posedge clk) disable iff (!rst_n)
		$countones(state) == 1;
endproperty
```

这个例子和 `$onehot` 类似，但更适合你想显式写出计数约束的时候。

### 7.7 $initstate

```systemverilog
$initstate
```

在仿真或形式语境中判断是否处于初始状态，常用于启动阶段的辅助判断。

示例：

```systemverilog
property p_no_check_on_init;
	@(posedge clk)
		!$initstate |-> !$isunknown(data);
endproperty
```

这个例子说明你也可以在启动阶段显式避开初始化采样。

## 8. let 和局部变量

### 8.1 let

```systemverilog
let req_valid = req && !busy;
```

`let` 用来定义可复用的表达式，适合把复杂条件拆成小块。

示例：

```systemverilog
let req_valid = req && !busy;
let ack_ok    = ack && !$isunknown(ack);

property p_req_ack_with_let;
	@(posedge clk) disable iff (!rst_n)
		req_valid |-> ##[1:3] ack_ok;
endproperty
```

这个例子把复杂前后件拆开，让属性更容易读懂和复用。

### 8.2 property 内局部变量

```systemverilog
property p_latency;
	int d;
	@(posedge clk) disable iff (!rst_n)
		(req, d = $past(addr)) |-> ##[1:3] (ack && addr == d);
endproperty
```

局部变量适合保存中间值，帮助做跨周期比较。

示例：

```systemverilog
property p_addr_stable_until_ack;
	logic [7:0] latched_addr;
	@(posedge clk) disable iff (!rst_n)
		(req, latched_addr = addr) |-> ##[1:3] (ack && addr == latched_addr);
endproperty
```

这个例子把请求时刻的地址暂存下来，再在应答时检查地址是否保持一致。

## 9. 常见写法模板

### 9.1 请求应答

```systemverilog
property p_req_ack;
	@(posedge clk) disable iff (!rst_n)
		req |-> ##[1:3] ack;
endproperty
```

### 9.2 复位后保持默认值

```systemverilog
property p_reset_value;
	@(posedge clk) !rst_n |-> (state == IDLE);
endproperty
```

示例说明：这个属性常用于验证复位期间寄存器状态是否落到预期默认值。

### 9.3 状态机只能一热编码

```systemverilog
property p_onehot_state;
	@(posedge clk) disable iff (!rst_n)
		$onehot(state);
endproperty
```

示例说明：适合 FSM 编码约束，能快速抓出多热或非法状态。

### 9.4 使能期间数据保持稳定

```systemverilog
property p_data_stable;
	@(posedge clk) disable iff (!rst_n)
		valid && !ready |-> $stable(data);
endproperty
```

示例说明：这是握手协议里非常常见的一类检查，用来避免等待期间数据翻转。

### 9.5 请求直到完成都不能掉线

```systemverilog
property p_req_hold;
	@(posedge clk) disable iff (!rst_n)
		req |-> (req throughout (!done));
endproperty
```

示例说明：这个模板适合事务保持、锁存保持、使能保持等场景。

## 10. 常用 cover 写法

### 10.1 事件命中

```systemverilog
cover property (@(posedge clk) disable iff (!rst_n) req ##[1:3] ack);
```

示例说明：如果 cover 迟迟不命中，通常说明环境约束、激励或路径可达性有问题。

### 10.2 状态到达

```systemverilog
cover property (@(posedge clk) disable iff (!rst_n) state == DONE);
```

cover 的作用不是证明对错，而是确认某条路径是否真的可达。

示例说明：适合检查某个终态、异常态或稀有状态是否真的有机会出现。

## 11. bind 写法

当不想改 DUT 源码时，可以把断言单独绑定进去。

```systemverilog
module arb_sva(input logic clk, input logic rst_n, input logic req, input logic ack);
	property p_req_ack;
		@(posedge clk) disable iff (!rst_n)
			req |-> ##[1:3] ack;
	endproperty

	assert property (p_req_ack);
endmodule

bind arb arb_sva u_arb_sva (
	.clk  (clk),
	.rst_n(rst_n),
	.req  (req),
	.ack  (ack)
);
```

这种方式适合把协议断言和 RTL 解耦，便于复用。

示例说明：`bind` 常用于 IP 复用、第三方 RTL、或者你不希望污染 DUT 源文件的场景。

## 12. 一个完整示例

下面这个例子演示一个典型 handshake：请求发出后，ack 必须在 1 到 3 个周期内回来；如果 reset 拉低，属性暂停检查。

```systemverilog
module handshake_sva (
	input logic clk,
	input logic rst_n,
	input logic req,
	input logic ack
);

	property p_req_ack;
		@(posedge clk) disable iff (!rst_n)
			req |-> ##[1:3] ack;
	endproperty

	assert property (p_req_ack)
		else $error("ack not returned in time");

	cover property (@(posedge clk) disable iff (!rst_n) req ##[1:3] ack);

endmodule
```

解释：

- `req` 作为前件。
- `##[1:3]` 表示允许 1 到 3 周期延迟。
- `ack` 作为后件。
- `cover property` 可以帮助确认这个场景是否真的被走到过。

补充示例：如果希望请求和应答必须严格隔 1 拍，可以改成 `req |=> ack`；如果希望允许更宽松的 1 到 5 拍，则改成 `req |-> ##[1:5] ack`。

## 13. 编写时的实用规则

- 优先写清楚时钟和复位。
- 把复杂条件拆成 `let` 或局部变量。
- 对时序属性先从最小窗口开始，再逐步放宽。
- 能用明确的采样函数，就不要用不清晰的组合逻辑替代。
- 证明失败时，先分辨是设计 bug、环境假设缺失，还是属性本身写得过强。

## 14. 常用语法速查

```systemverilog
// sequence / property
sequence s_name; ... endsequence
property p_name; ... endproperty

// 断言类
assert property (p_name);
assume property (p_name);
cover  property (p_name);

// 时钟与复位
@(posedge clk) disable iff (!rst_n)

// 时序运算符
##n
##[m:n]
[*n]
[*m:n]
[=n]
[->n]
and
or
intersect
within
throughout
first_match

// 属性运算符
|->
|=>
until
until_with
strong
weak

// 采样函数
$past
$rose
$fell
$stable
$changed
$isunknown
$onehot
$onehot0
$countones
```

## 15. 小结

SVA 的核心不是把语法背完，而是把时钟、复位、前件、后件和采样方式写清楚。对日常 FPV 来说，最常用的就是 `assert property`、`cover property`、`|->`、`|=>`、`##[m:n]`、`disable iff`、`$past`、`$rose`、`$stable` 这一组。

如果你愿意，我可以下一步继续补一份“FPV + SVA 联合使用例子”，把这份语法合集和前面的 FPV 笔记串起来。
