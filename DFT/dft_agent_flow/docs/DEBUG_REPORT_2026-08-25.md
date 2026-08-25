# Agent Debug Report: 2026-08-25

## Objective

Establish an auditable local DFT Agent in `tf_2_18`, diagnose historical DFTC lab compatibility issues, expand the model context to 32K, and add a repeatable from-scratch DFT baseline for external RTL.

## Environment Observed

| Item | Observed value |
| --- | --- |
| Conda environment | `tf_2_18`, Python 3.10.18 |
| DFT launcher | `/usr/local/bin/dc_shell` |
| Library used by generated external baseline | `/media/6/Projects/DFTC1_2010.03-ori/ref/db/sc_max.db` |
| Local default model | Ollama `qwen3:4b-instruct` |
| Model context | 32,768 tokens; one concurrent request |
| Candidate model retained for evaluation | `qwen3.5:4b` |

## DFTC Evidence State

The completed supervised course replay verified the approved execution evidence for Labs 4A through 10, with Lab 12 intentionally remaining blocked. The Lab 12 report contains `Error: Only -scan option supported currently`, so a clean scan-chain fragment cannot be promoted to course completion. This is an expected safeguard, not a failed validator.

The DFTC runner stages every course execution under `/media/6/Projects/DFTC1_agent_workspaces`, writes `skill_result.json`, then runs two independent validation snapshots. The validator rejects a zero process exit if the log/report contains `Error:` or if expected evidence is absent.

## External Catalogue

Three repositories were shallow-cloned without running repository scripts. The manifest pins these exact source revisions:

| ID | Repository | Commit | Top |
| --- | --- | --- | --- |
| `secworks_aes` | `https://github.com/secworks/aes.git` | `80dc4718e1dcbbdb4b0dd1bdb393d8f7b98981dc` | `aes` |
| `secworks_sha256` | `https://github.com/secworks/sha256.git` | `837c5cc396f001d18f2c765721c585716eb439ae` | `sha256` |
| `freecores_i2c` | `https://github.com/freecores/i2c.git` | `3b067f00ccced753b0502024766a51f58f3e04bc` | `i2c_master_top` |

## First AES Baseline: Diagnostic Failure

The first generated AES run was deliberately retained as failure evidence in workspace `20260825T115946Z_secworks_aes_4232454f`.

| Observation | Result |
| --- | --- |
| Process exit | 0 |
| Parsed diagnostics | `report_design -summary` unsupported; redirect failed; a nonexistent ScanEnable port was supplied |
| Pre-DFT DRC | 0 violations |
| Post-DFT DRC | 0 violations; 2,987 valid scan cells; estimated coverage 100% |
| Validator conclusion | `blocked` |

This shows why exit status and attractive downstream reports cannot be treated as a pass. The skeptic role correctly found the earlier errors and the report auditor rejected the malformed read/link report.

## Template Repair and AES Rerun

The generated modern-tool template was corrected in the trusted executor, not by editing AES RTL:

1. Replace unsupported `report_design -summary` with `report_design`.
2. Remove the attempt to bind `ScanEnable` to a port that does not exist in the source; allow `insert_dft` to create supported test ports.

Fresh workspace `20260825T120123Z_secworks_aes_aa0a4bc2` then produced return code 0, no parsed diagnostics, all required reports/exports, two stable validation snapshots and `cross_validation.status=verified`. Post-DFT evidence reports 0 violations, 2,987 valid scan cells, and 100% estimated test coverage. This confirms the generated baseline execution only; it does not sign off AES timing, scan architecture, or ATPG.

## Model Behavior

`qwen3:4b-instruct` successfully selects constrained tools in normal DFTC operation, but one external-flow natural-language session entered prolonged tool-protocol retry without yielding evidence. The subprocess was interrupted after several minutes; no result was claimed. This is treated as a model/tool-protocol failure, not an RTL or DFT result.

Mitigation now in code:

* Mutations are available through short deterministic CLI tools as well as the LLM Agent.
* Post-mutation conclusions are generated from `cross_validation.json` rather than the model's final prose.
* The Agent has a compact diagnosis/retry capability for two known template mismatches, while unknown failures stop for engineering review.
* The failed episode should be marked `corrected` or `rejected` through the feedback tool when its episode file exists; this gives future SFT work a concrete tool-selection/protocol sample.

## Final Verification

The following commands completed after the implementation changes:

| Check | Result |
| --- | --- |
| `python -m pytest -q` in `tf_2_18` | 25 passed in 6.33 s |
| AES modern generated baseline | `verified`; fresh workspace `20260825T120123Z_secworks_aes_aa0a4bc2`; post-DFT estimated coverage 100.00% |
| SHA-256 generated baseline | `verified`; fresh workspace `20260825T121219Z_secworks_sha256_a16f40c9`; post-DFT estimated coverage 99.97% |
| SHA-256 policy-Agent objective | `verified`; Agent episode `20260825T122054Z_6a7f65c8e2`, staged workspace `20260825T121938Z_secworks_sha256_7223c4ca` |
| I2C generated baseline after staged pragma compatibility transform | `blocked`; workspace `20260825T121739Z_freecores_i2c_f41a0032`; process clean and DRC reports exist, but 1.97% is below the manifest 90.0% gate |
| I2C policy-Agent diagnosis | `engineer_review`; it returns no automatic action because the remaining issue is inadequate coverage rather than a known tool-template mismatch |
| GUI | Adds a fourth, icon-labelled `开源 RTL` goal tab with fixed project selection and execution/diagnosis mode |

The external source clones remained clean at their pinned commits after all staging and execution. The I2C result is intentionally not passed: the automated compatibility fix proves that the source can be parsed and scan inserted, but it does not solve test quality. That distinction is the desired behavior of the new quality gate.
