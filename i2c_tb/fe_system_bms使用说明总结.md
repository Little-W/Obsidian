# fe 系统 bms 使用说明总结

来源：`C:\Users\yusen\Downloads\fe_system.html`

## 一句话概览

`bms.py` 是前端仿真与回归编排脚本，用于基于 `test_lib` 用例解析 `vcs_com` 和多层 `cfg`，组织 `vlogan` / `vcs` 编译、`simv` 仿真，以及通过 LSF 或 EMAN 提交回归任务。

## 运行环境与主要能力

- 面向 Linux / EDA 集群环境，路径和命令以类 Unix 习惯为准。
- 非交互场景默认可通过 LSF 提交任务。
- 非 `-eman` 模式主要用于单例仿真。
- `-eman` 模式用于 VC Execution Manager 回归，支持多用例、目录展开、用例 count、覆盖率合并等。

## 用例与工程路径约定

- 用例路径必须位于包含 `test_lib` 的目录树下。
- 命令中传入的是不带 `.tc` 后缀的用例路径，例如：

```bash
bms .../test_lib/.../my_case
```

- 对应目录下需要存在同名 `.tc` 文件：

```text
.../test_lib/.../my_case/my_case.tc
```

- 工程根目录是 `test_lib` 的上一级。
- 编译控制目录优先使用：

```text
<proj>/vcs_com
```

- 若不存在 `<proj>/vcs_com`，则兼容使用 `<proj>/Makefile` 所在目录来放置 `vcs_com` 文件。

## 单例仿真

基本命令：

```bash
bms <用例路径> [选项]
```

关键行为：

- 默认全量重新编译。
- `-f` / `-fast`：快速模式，复用已有编译结果，仅适用于非 `-eman`。
- `-c`：非 `-eman` 下先清理目标运行目录再执行。
- `-d` / `-dump`：开启波形。
- `-cov`：启用覆盖率相关编译和仿真选项。
- `-R` / `--run-suffix`：给运行目录增加后缀。
- `-q`、`--ncore`、`-m`：分别控制 LSF 队列、核数和内存 GB。

## 常用参数速查

| 参数 | 用途 |
| --- | --- |
| `tc` | 用例路径；`-eman` 下可传多个路径或目录，目录会递归收集 `.tc` |
| `-f` / `-fast` | 复用编译结果，仅非 `-eman` |
| `-c` | 非 `-eman` 下清理后再跑 |
| `-genlib` / `-lib` | 生成或复用可复用编译库 |
| `-d` / `-dump` | 开波形 |
| `-cov` | 启用覆盖率；`-eman -cov` 时参与 EMAN merge |
| `-R` / `--run-suffix` | 运行目录后缀 |
| `-q` | LSF 队列 |
| `--ncore` | 核数 |
| `-m` | 内存 GB |
| `-eman` | 生成并提交 EMAN 回归 |
| `-num` | EMAN 各用例执行次数，可用逗号和多用例对齐 |
| `-j` | EMAN build/test nodes，默认 50 |
| `-s` / `--seed` | 随机种子 |
| `--emc` / `xxx.emc` | 直跑已有 `.emc` |

## EMAN 两种入口

### 1. 由 bms 生成 `.emc` 后提交

使用 `-eman` 且传入用例或目录时，`bms` 会根据模板生成 `.emc`，再启动 `eman`。

模板查找顺序：

- 环境变量 `BMS_EMAN_TEMPLATE` 指定的路径。
- `<proj>/regr/eman_template.emc`。
- `<proj>/vcs_com/eman_template.emc`。

生成行为：

- 写入模板占位符。
- 生成 `builds` / `tests` YAML 块。
- 在本机或调度侧启动 `eman`。

关键路径与参数：

- `-session_name` 由 `bms` 生成。
- 单用例形式类似：

```text
build_<用例名>_session_<用户>_<时间戳>
```

- 多用例形式类似：

```text
<N>builds_session_<用户>_<时间戳>
```

- `-top_run_dir` 形如：

```text
<debug_base>/eman/eman_regression/eman_rundir/eman_rundir_YYYYMMDD_HHMMSS
```

- `debug_base` 默认是 `test_lib/debug`，可通过 `BMS_EMAN_DEBUG_DIR` 覆盖。
- `.emc` 内部 build/test 的 `run_dir` 仍可基于 `$$EMAN_SESSION_NAME` 表达，它与 `top_run_dir` 不是同一层级。

示例：

```bash
bms -eman <case_or_dir> -num 10 -j 50 -cov
```

### 2. 直跑已有 `.emc`

命令：

```bash
bms --emc /path/to/run.emc [-cov]
```

或：

```bash
bms -eman /path/to/run.emc
```

注意：

- 直跑 `.emc` 不经过 `bms` 编译流程。
- `bms` 不会额外传入 `-session_name` 或 `-top_run_dir`。
- 会话名和顶层运行目录由 EMAN 默认值或外部配置决定。
- 执行时工作目录会切到 `.emc` 所在目录。

## `vcs_com` 与 `cfg`

### `vcs_com` 分段

`vcs_com` 中包含编译和 elaboration 分段，常见段名包括：

- `[VLOGAN]`
- `[VCS_RTL_ELAB]`
- `[VCS_TEST_ELAB]`

脚本也支持中文标题形式。

### `cfg` 叠加规则

`cfg` 是全局配置与用例侧目录配置的叠加结果。常见指令包括：

- `+COMP+`
- `+VIP+`
- `+COV_COMP+`
- `+COV_SIM+`
- `+RTL_ELAB+`
- `+TEST_ELAB+`
- `+SIM+`
- `+RTL_FILE+`
- `+VERIF_FILE+`
- `rtl_file=`
- `verif_file=`

## `cfg` 加选项

`+...+` 用于在对应选项串上追加内容。行内空格会按照 shell 规则拆分为多个 token，因此写法需要和传给 `vlogan` / `vcs` 的参数保持一致。

常见加选项：

| 选项 | 含义 |
| --- | --- |
| `+COMP+` | 追加共用编译 / vlogan 选项 |
| `+VIP+` | 追加 VIP 相关选项 |
| `+COV_COMP+` | 追加覆盖率编译侧选项 |
| `+COV_SIM+` | 追加覆盖率仿真侧选项 |
| `+RTL_ELAB+` | 追加 RTL elaboration 选项 |
| `+TEST_ELAB+` | 追加 Test elaboration 选项 |
| `+SIM+` | 追加仿真参数 |
| `+RTL_FILE+` / `rtl_file=` | 指定 RTL filelist |
| `+VERIF_FILE+` / `verif_file=` | 指定验证 filelist |

`+SIM+` 还可以指定仿真前后脚本：

```text
+PRE_SIM=<cmd>
+POST_SIM=<cmd>
```

## `cfg` 减选项

`-...-` 用于从已经按顺序累积的同类选项中按 token 剔除内容。

规则要点：

- 减选项行后的内容也会按 shell 规则分词。
- 只有与当前累积列表中完全一致的 token 才会被移除。
- 减选项常用于子目录或单个 `.tc` 中关闭上层 `cfg` 已添加的开关。
- 写法需要与对应 `+...+` 加入时的 token 写法一致，包括拆词方式。

常见减选项：

| 减选项 | 从哪类累积中剔除 |
| --- | --- |
| `-COMP-` | 共用编译 / vlogan 类 `comp` 选项 |
| `-VIP-` | `vip` 选项 |
| `-COV_COMP-` | 覆盖率编译侧 `cov_comp` |
| `-COV_SIM-` | 覆盖率仿真侧 `cov_sim` |
| `-RTL_ELAB-` | RTL elaboration 追加段 `rtl_elab` |
| `-TEST_ELAB-` | Test elaboration 追加段 `test_elab` |
| `-SIM-` | `+SIM+` 追加的仿真 argv，不含 pre/post |

正式写法是大写关键字并在两侧带减号，例如 `-COMP-`。口语里的 `-comp` 通常指同一类能力，但不是正式 cfg 写法。

## 首次使用建议

- 先选择小范围用例验证路径、`cfg` 叠加和编译选项是否符合预期。
- 单例跑通后再扩大到 EMAN 多用例回归。
- 覆盖率、LSF 队列、EMAN 项目配置和许可证策略以实际集群环境为准。
- 修改 `cfg` 时特别注意 token 粒度；减选项是否生效取决于能否精确匹配此前加入的 token。

