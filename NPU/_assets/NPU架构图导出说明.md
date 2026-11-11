# NPU 架构图源与导出

可编辑Draw.io文件是图源。架构生成器写入明确的模块、端点与折线，导出器只消费这些图源，不单独编辑PNG。六图分别说明系统连接、命令/存储控制、执行集群、数值流、L1 bank 存储及 MIF 并发事务。

```sh
python3 docs/_assets/generate_npu_spec_drawio.py --group architecture --only \
  npu_system_architecture npu_command_storage_architecture \
  npu_internal_architecture npu_int_fp_int_flow \
  npu_l1_banked_storage_architecture npu_mif_burst_architecture
python3 docs/_assets/export_npu_architecture.py \
  npu_system_architecture npu_command_storage_architecture \
  npu_internal_architecture npu_int_fp_int_flow \
  npu_l1_banked_storage_architecture npu_mif_burst_architecture
```

导出需要Python、Pillow、Noto Sans CJK SC字体和Inkscape。导出器仅支持这些架构图使用的矩形、文字和显式折线子集，不替代Draw.io的任意自动布局。它检查文本容纳、非目标模块/文字区域穿越和不同连接的交叉/重合，再输出SVG及1800像素宽PNG。

SVG/PNG发布前仍需人工核对箭头方向、模块归属、控制与数据含义。几何检查不能证明RTL连接正确；正文与源端口核查另由设计文档审查完成。其他时序图和状态图应使用其原图源及对应导出方式，不能套用本子集导出器。

## 执行单元与存储模块图

下面这些模块图复用相同的 Draw.io 源与导出检查器。当前 Matrix-Vector 图区分 Direct、Scalar、Vector 的任务入口与共享 PE；L1BUF 图区分普通客户端和分阶段面板载荷；Complex 图将双逻辑 FMA 请求入口与单个物理混合 FMA 算术流水分开画出。更新 RTL 后应先修改生成器，再重建 `.drawio`，最后同时导出 SVG/PNG。

```sh
python3 docs/_assets/generate_npu_spec_drawio.py --group module --only \
  npu_matrix_vector_submodules npu_l1buf_submodules npu_complex_submodules \
  npu_cfe_submodules
python3 docs/_assets/export_npu_architecture.py \
  npu_matrix_vector_submodules npu_l1buf_submodules npu_complex_submodules \
  npu_cfe_submodules
```

图中物理资源数量、客户端数、接口位宽和默认参数均以 RTL 实例层级为准；生成器中的文字属于图源内容，必须随参数或连线变化一并复核，不能只重导出旧图源。
