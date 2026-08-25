# DFT Agent Design

## Scope

This project automates **Design for Test**, not density-functional theory. It is a local, evidence-first assistant for three bounded surfaces:

1. FAN_ATPG experiment selection over an existing ISCAS circuit whitelist.
2. Diagnosis and supervised replay of the official DFTC1 course labs.
3. A generated, from-scratch scan-insertion baseline for a small catalogue of pinned open-source Verilog designs.

It is not a signoff system. Production timing, power, physical implementation, DFT architecture, compression, pattern generation, and release all require a qualified DFT engineer.

## Architecture

```text
PyQt6 GUI / dft-flow CLI
          |
          v
ToolCallingAgent (local Ollama model; planning and tool selection only)
          |
          +-- FAN runner: fixed profiles -> isolated artifacts/runs
          +-- DFTC tutor: reviewed skills -> /media/6/...DFTC1_agent_workspaces
          +-- External runner: pinned RTL -> /media/6/...DFT_agent_external_workspaces
                                                |
                                                v
                                         dc_shell generated Tcl
                                                |
                                                v
                             skill_result.json -> two validation snapshots
                                                |
                                                v
                                  deterministic supervisor conclusion
```

The language model never receives a shell, Python interpreter, filesystem write API, arbitrary Tcl API, or a tool to clone repositories. It can only request named Python tools with schema-validated arguments.

## Trust Boundaries

| Boundary | Rule |
| --- | --- |
| Official DFTC source and existing runtime copy | Read-only evidence; every new run is staged elsewhere. |
| Open-source source catalogue | Shallow clone at a manifest-pinned commit. Source must be clean and its listed RTL files must exist before staging. Repository scripts are never run. |
| Mutable execution workspaces | A fresh timestamped workspace contains generated Tcl, a copied RTL subset, raw log, reports, DDC, SPF, evidence JSON and validation JSON. |
| Model response | Never considered execution evidence. It is replaced by a deterministic conclusion after a mutating tool call. |
| Engineer approval | Required even for `verified`, because validation proves recorded execution integrity, not design signoff. |

## External RTL Baseline

`data/external_dft_projects.json` is the source of truth. It lists the source URL, exact commit, top module, clock, reset polarity, and every allowed RTL file. `ExternalDftProjectRunner` applies these checks in order:

1. Resolve an exact project ID from the manifest.
2. Require `git rev-parse HEAD` to equal the pinned commit and `git status --porcelain` to be empty.
3. Copy only listed `.v`/`.sv` files into `flow/rtl` in a new workspace and hash each copy in `stage.json`.
4. Generate the V-2023.12 Tcl driver rather than reading project scripts.
5. Invoke `/usr/local/bin/dc_shell -no_gui -f agent_external_baseline.tcl` with a 1,200 s timeout.
6. Capture a combined raw log, parse `Error:`/`Fatal:`, verify required reports and exports, then persist `skill_result.json`.
7. Independently read execution metadata, report acceptance, logs and crash artifacts twice. Both snapshots must hash identically and all three roles must pass to obtain `verified`.

The generated flow reads RTL, elaborates and links against `sc_max.db`, creates the manifest clock/reset DFT declarations, compiles, creates a protocol, runs pre-DFT DRC, previews one scan chain, inserts DFT, runs post-DFT DRC, emits scan-path evidence, DDC, mapped Verilog, and SPF. The tool uses supported automatic test ports rather than inventing ports in the upstream design.

Each project also declares a minimum post-DFT estimated coverage in the manifest. A zero-violation DRC with coverage below that threshold is `blocked`; exported files alone never satisfy the baseline. This is an execution-quality gate, not a substitute for ATPG signoff.

## Light Diagnosis and Repair Authority

The Agent has deliberately narrow problem-solving authority:

1. `diagnose_external_dft_project` re-validates the latest evidence and returns a factual diagnosis.
2. If the diagnostics match a known current-tool template mismatch, it returns one exact `approved_actions` value.
3. `attempt_approved_external_dft_repair` accepts only that returned action, uses the already-reviewed modern template, stages a new workspace, reruns, and double-validates.
4. Unclassified errors return `engineer_review`; the Agent cannot guess a Tcl patch, alter constraints, suppress errors, or edit RTL.

Current catalogue remedies are `report_design -summary` removal for current DC and allowing `insert_dft` to create supported test ports instead of naming a nonexistent ScanEnable port. This design gives the model a real, bounded diagnosis-and-retry loop without granting arbitrary design mutation.

Some projects also have an explicitly reviewed staged-only compatibility transform. For example, the pinned FreeCores I2C source carries `// synopsys enum_state` comments that the current HDL reader treats as an unsupported legacy pragma. The runner replaces that exact comment with `// legacy enum_state` in the copied workspace only, checks that each expected source occurrence exists exactly once, records the transform in `stage.json`, and never alters the clone.

## Hallucination Controls

* Every mutating result supplies paths, return code, timeout state, parsed diagnostics and report predicates.
* `execution_auditor` checks that generated files reside under the correct staged root and that the final process ended cleanly.
* `report_auditor` rereads report predicates rather than trusting previously stored Boolean flags.
* `skeptic_auditor` searches captured logs and acceptance reports for diagnostics plus Synopsys crash artifacts.
* The three checks are executed twice. A stable fingerprint is mandatory.
* The runtime supervisor replaces an LLM claim with `verified`, `blocked`, or `needs_review`, including evidence paths and blockers.
* Expert feedback is stored per episode and only approved or corrected examples are exported for SFT. LoRA adapters must clear a holdout evaluation before use.

## Models and Context

The default is local Ollama `qwen3:4b-instruct`, with `num_ctx=32768` and concurrency one. Its tool call is intentionally short: tools return bounded summaries while logs remain in workspaces. `qwen3.5:4b` is installed as an evaluation candidate but is not the default because it was less reliable at this framework's final tool-call JSON protocol. If tool-call latency or parser retries become material, use deterministic CLI skills for mutation and preserve episodes as correction data; do not expand shell access to compensate.

For an external execution or diagnosis goal that names exactly one manifest project ID, `run_agent` uses the same constrained runner through `policy_external_agent` rather than waiting on a small model to serialize a large tool result. It records an ordinary episode and tool trace, stages and verifies exactly as the Agent tool would, and returns the deterministic supervisor conclusion. Ambiguous external names are rejected. This fallback is a reliability boundary, not additional execution privilege.

## Operations

```bash
conda run -n tf_2_18 python -m pip install -r requirements.txt
conda run -n tf_2_18 python -m pip install -e .
conda run -n tf_2_18 dft-flow external-list
conda run -n tf_2_18 dft-flow external-inspect --project secworks_aes
conda run -n tf_2_18 dft-flow external-run --project secworks_aes
conda run -n tf_2_18 dft-flow external-diagnose --project secworks_aes
```

Use `requirements-dev.txt` for tests and `requirements-train.txt` only for vetted LoRA work. Verify a prior run with the `cross_validation.json` next to its `skill_result.json`; do not infer success from the presence of a DDC or a 0 shell return code alone.
