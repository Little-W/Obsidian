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

### 2.2 property

`property` 用来描述可证明的时序属性。

```systemverilog
property p_req_ack;
	@(posedge clk) disable iff (!rst_n)
		req |-> ##[1:3] ack;
endproperty
```

### 2.3 assert / assume / cover

```systemverilog
assert property (p_req_ack);
assume property (p_env_stable);
cover property  (p_seen_something);
```

- `assert property`：证明属性必须成立。
- `assume property`：把属性作为环境假设。
- `cover property`：检查某个时序目标是否能到达。

## 3. 时钟与失效条件

### 3.1 clocking event

最常用写法是：

```systemverilog
@(posedge clk)
```

也可以用多个时钟事件，但最常见还是单时钟设计。

### 3.2 disable iff

```systemverilog
@(posedge clk) disable iff (!rst_n)
```

当 `rst_n` 无效时，属性不检查。这个写法几乎是所有 FPV/SVA 里最常见的形式。

### 3.3 default clocking / default disable iff

```systemverilog
default clocking cb @(posedge clk); endclocking
default disable iff (!rst_n);
```

这两句适合把所有属性的默认采样时钟和复位屏蔽条件统一起来。

## 4. 立即断言与并发断言

### 4.1 立即断言

```systemverilog
assert (a == b) else $error("a != b");
```

立即断言通常用于组合逻辑或局部检查，不是典型的时序属性。

### 4.2 并发断言

```systemverilog
assert property (@(posedge clk) disable iff (!rst_n) req |-> ack);
```

并发断言才是 SVA 的主体，能表达跨周期的时序关系。

## 5. 最常用的序列运算符

### 5.1 连接 `##n`

```systemverilog
req ##1 ack
```

表示 `req` 之后第 1 个周期出现 `ack`。

补充：`##0` 表示同一采样周期。

### 5.2 区间延迟 `##[m:n]`

```systemverilog
req ##[1:3] ack
```

表示 `ack` 在 1 到 3 个周期内出现。

### 5.3 连续重复 `[*]`

```systemverilog
busy[*3]
busy[*1:4]
```

表示连续重复若干次。

### 5.4 非连续重复 `[=]`

```systemverilog
event[=2]
```

表示事件出现 2 次，但中间可以夹杂其它周期。

### 5.5 goto 重复 `[->]`

```systemverilog
event[->1]
```

表示找到第 1 次目标事件的位置。

### 5.6 逻辑组合 `and` / `or`

```systemverilog
s1 and s2
s1 or  s2
```

- `and`：两个序列都要成立。
- `or`：任一序列成立即可。

### 5.7 交集 `intersect`

```systemverilog
s1 intersect s2
```

要求两个序列在同一时间窗口上同时成立。

### 5.8 包含关系 `within`

```systemverilog
s1 within s2
```

表示 `s1` 发生在 `s2` 的时间范围内。

### 5.9 全程保持 `throughout`

```systemverilog
s_hold throughout s_window
```

表示在 `s_window` 持续期间，`s_hold` 必须一直成立。

### 5.10 首次匹配 `first_match`

```systemverilog
first_match(req ##[1:5] ack)
```

当多种匹配路径都可能成立时，选择最早匹配的一条。

### 5.11 取反 `not`

```systemverilog
not ack
```

表示该序列不能成立。

## 6. 最常用的属性运算符

### 6.1 蕴含 `|->`

```systemverilog
req |-> ack
```

表示前件成立时，后件必须成立。后件通常从当前周期或接下来定义的时序开始判断。

### 6.2 非重叠蕴含 `|=>`

```systemverilog
req |=> ack
```

表示前件成立后，后件从下一个周期开始检查。

### 6.3 until / until_with

```systemverilog
busy until done
busy until_with done
```

- `until`：`busy` 要一直成立，直到 `done` 出现。
- `until_with`：`done` 出现的那个周期也要满足组合条件。

### 6.4 strong / weak

```systemverilog
strong(req ##[1:3] ack)
weak(req ##[1:3] ack)
```

- `strong`：要求序列必须最终完成。
- `weak`：允许序列在有限观察窗口里未完成。

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

## 7. 常用采样函数

### 7.1 $past

```systemverilog
$past(data)
$past(data, 2)
```

读取前 1 个周期或前 N 个周期的值。

### 7.2 $rose / $fell

```systemverilog
$rose(valid)
$fell(valid)
```

检测上升沿和下降沿。

### 7.3 $stable / $changed

```systemverilog
$stable(data)
$changed(data)
```

检测信号是否保持不变，或者是否发生变化。

### 7.4 $isunknown

```systemverilog
$isunknown(data)
```

检测信号里是否存在 X / Z。

### 7.5 $onehot / $onehot0

```systemverilog
$onehot(state)
$onehot0(state)
```

- `$onehot`：恰好只有 1 位为 1。
- `$onehot0`：允许全 0 或恰好 1 位为 1。

### 7.6 $countones

```systemverilog
$countones(state)
```

统计 1 的个数，常用于编码检查。

### 7.7 $initstate

```systemverilog
$initstate
```

在仿真或形式语境中判断是否处于初始状态，常用于启动阶段的辅助判断。

## 8. let 和局部变量

### 8.1 let

```systemverilog
let req_valid = req && !busy;
```

`let` 用来定义可复用的表达式，适合把复杂条件拆成小块。

### 8.2 property 内局部变量

```systemverilog
property p_latency;
	int d;
	@(posedge clk) disable iff (!rst_n)
		(req, d = $past(addr)) |-> ##[1:3] (ack && addr == d);
endproperty
```

局部变量适合保存中间值，帮助做跨周期比较。

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

### 9.3 状态机只能一热编码

```systemverilog
property p_onehot_state;
	@(posedge clk) disable iff (!rst_n)
		$onehot(state);
endproperty
```

### 9.4 使能期间数据保持稳定

```systemverilog
property p_data_stable;
	@(posedge clk) disable iff (!rst_n)
		valid && !ready |-> $stable(data);
endproperty
```

### 9.5 请求直到完成都不能掉线

```systemverilog
property p_req_hold;
	@(posedge clk) disable iff (!rst_n)
		req |-> (req throughout (!done));
endproperty
```

## 10. 常用 cover 写法

### 10.1 事件命中

```systemverilog
cover property (@(posedge clk) disable iff (!rst_n) req ##[1:3] ack);
```

### 10.2 状态到达

```systemverilog
cover property (@(posedge clk) disable iff (!rst_n) state == DONE);
```

cover 的作用不是证明对错，而是确认某条路径是否真的可达。

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
