verification_ai_skills/
├── .agent/
│   ├── skills/
│   │   ├── uvc_orchestrator/
│   │   │   └── scripts/
│   │   │       ├── eda_buddy_executor.py
│   │   │       └── run_regression.py
│   │   ├── pdf_to_markdown/
│   │   ├── vector_index/
│   │   ├── uvc_planning/
│   │   │   ├── grading/
│   │   │   └── sub_prompts/
│   │   ├── uvc_generator/
│   │   └── eda_yaml_generator/
│   │       └── scripts/
│   │           └── gen_eda_yamls.py
│   └── workflows/
│       └── uvc_verif_planning.md
│
├── verification_mcp_server/
│   ├── server.py
│   └── scripts/
│       ├── pdf_to_markdown.py
│       ├── plan_to_pdf.py
│       ├── uvm_mermaid_gen.py
│       └── vector_index.py
│
├── examples/
│   ├── README.md
│   ├── spec/
│   │   └── simple_axi_stream_spec.md
│   └── plan/
│       └── verif_plan_axi_stream_master_example.yaml
│
├── dummy_uvm/
├── Output/
├── eda_buddy/
├── Documents/
├── .github/workflows/
├── .gitmodules
├── .gitignore
├── README.md
└── check_cache.py
![[Pasted image 20261015164549.png]]
![[Pasted image 20261015164639.png]]
![[Pasted image 20261015164658.png]]

可以参考的架构agent设计：
![[Pasted image 20261015165000.png]]

安全流程，并发很重要！！！

研发顺序！
![[Pasted image 20261015205939.png]]
![[Pasted image 20261021171758.png]]
![[Pasted image 20261021172222.png]]
![[Pasted image 20261021174602.png]]
![[Pasted image 20261021174926.png]]
这是uvm core agent的职责
![[Pasted image 20261025163049.png]]

建议的仓库实现：
uvm-verification-agent/
│
├── codex-rs/                  # Fork Codex
│   ├── core/                 # 通用 Agent Runtime
│   ├── app-server/           # 客户端协议
│   └── ...
│
├── uvm-domain/               # 我们的领域内核
│   ├── requirements/
│   ├── vplan/
│   ├── environment/
│   ├── workflow/
│   ├── gates/
│   ├── regression/
│   ├── debug/
│   ├── coverage/
│   ├── evidence/
│   └── policies/
│
├── uvm-tools/                # 验证工具适配
│   ├── dvfm/
│   ├── vcs/
│   ├── questa/
│   ├── verdi/
│   └── formal/
│
├── uvm-skills/               # 领域知识与操作指导
│
├── gateway/                  # 多用户、任务调度、协议
│
└── qt-client/                # Windows/Linux 客户端

gate门禁的意思：

![[Pasted image 20261025172036.png]]

各类开源项目的优点
![[Pasted image 20261103153203.png]]
![[Pasted image 20261103155225.png]]