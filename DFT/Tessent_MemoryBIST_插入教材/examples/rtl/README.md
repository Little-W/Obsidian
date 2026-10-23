# RTL 与库接入

本教材不附带工艺厂 SRAM、Tessent 商业单元库、受许可限制的 TCD 或完整商业测试平台。

`u_mem0`～`u_mem5` 是算法与配置编辑示例的实例名，不意味着这些宏已在你的设计中存在。
先用一份已经完成 TCD 验证的真实 SRAM 小顶层运行基线，再替换 site_local.tcl 的路径。
实例名必须从 `report_memory_instances` 取得；不要为匹配示例而重命名真实宏。
