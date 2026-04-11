## 1. VC Formal

VC Formal is a formal verification platform for RTL and gate-level designs. Instead of relying on random simulation, it turns design intent, constraints, and assertions into solvable logic problems, which helps expose defects across a much larger state space. It is especially effective for finding boundary-condition bugs, protocol violations, deadlocks, missing connections, and incorrect timing assumptions early in the design cycle.

## 1.1 Typical Use Cases

- Protocol checking: verify whether interfaces such as AXI, APB, AHB, FIFO, and handshake channels satisfy timing and behavioral requirements.
- Assertion verification: prove key design rules, state-transition conditions, and exception handling paths with SVA.
- CDC/RDC analysis: check whether cross-clock-domain and cross-reset-domain signals have metastability risks, handshake issues, or reset-release hazards.
- Equivalence and regression confirmation: confirm that behavior remains consistent after optimization, bug fixes, or refactoring.
- Safety-critical design: suitable for CPU control logic, bus arbitration, state machines, privilege control, and exception responses.
- Hard-to-cover corner cases: extreme input combinations, rare state transitions, unreachable-state checks, and deep deadlock analysis.

## 1.2 Common Apps

The exact app names may vary slightly by version and license, but VC Formal usually includes the following capabilities:

- Base App: the basic entry point for loading the design, constraints, properties, and run environment.
- Assertion App: proves SVA assertions or analyzes counterexamples; this is one of the most commonly used apps.
- Connectivity App: checks module ports, bus connections, bit widths, unconnected signals, and miswires.
- CDC App: analyzes clock-domain crossings and identifies missing synchronizers, single-bit or multi-bit CDC risks, and handshake issues.
- RDC App: analyzes reset-domain crossings and checks reset-release ordering, reset synchronization, and reset-glitch risks.
- FSM App: analyzes state machines and identifies dead states, invalid transitions, uncovered states, and encoding issues.
- Equivalence / ECO capabilities: verifies functional consistency after changes and is commonly used for post-fix regression signoff.
- Coverage Analysis: analyzes formal coverage and helps determine which states, properties, or paths have not yet been proven.
- Debug / Waveform capabilities: inspect counterexamples, trace paths, and locate trigger conditions so proof failures can be mapped back to design defects.

### 1.2.1 Tool Quick Reference

- FPV: Functional Proof Verification, mainly used to verify functional behavior, protocol constraints, and key assertions.
- SEQ: Sequential analysis, focused on sequential behavior, power analysis, and timing reuse scenarios.
- FTA: Testbench Analyzer, used to check whether the testbench itself contains issues that could hide design bugs.
- DPV: Datapath Validation, used to verify datapaths, arithmetic logic, and combinational paths.
- CC: Connectivity Checking, used to check whether ports are connected correctly, widths match, and nothing is left floating or miswired.
- FCA: Coverage Analyzer, used to determine which properties, states, or paths have not yet been proven.
- FXP: X-Propagation Verification, used to inspect risks caused by unknown-value propagation.
- FSV: Hardware Security Verification, used to find backdoors, illegal states, and sensitive control-path risks.
- FRV: Customer Deliverables / Protocol Compliance, focused on deliverable checks and protocol compliance verification.
- AEP: Auto Checks, used for batch rule checks.
- FLP: Low Power, used to check power gating, isolation, and wake-up logic.
- FuSa: Functional Safety, used for safety-critical designs and safety-mechanism checks.

## 1.3 Practical Tips

- Make constraints explicit, especially clocks, resets, enables, and environmental assumptions; otherwise you may end up proving the wrong thing.
- Start with a small set of key properties, then expand gradually to the full module.
- For complex designs, check interface protocols and state machines first, then move on to deeper safety properties.
- When a counterexample appears, do not fix only the assertion; first determine whether it is a design bug, a missing environmental assumption, or an overly strong property.

## 1.4 Summary

The value of VC Formal is in finding issues early, covering deeper state spaces, and proving correctness. If the design contains critical control logic, cross-clock or cross-reset paths, or protocol-oriented interfaces, it is often more effective than simulation alone.

## 1.5 Coverage Analyzer

Coverage Analyzer answers two questions: what parts of the design have not been proven yet, and whether the current formal results are complete enough. It does not replace assertion proving; instead, it evaluates verification depth from a coverage perspective.

### 1.5.1 What It Solves

- Finds uncovered states, paths, branches, and properties.
- Helps determine whether a proof failure is caused by a real design issue or by insufficient coverage goals or constraints.
- Helps move from “proof succeeded” to “proof is complete,” instead of stopping too early after only a small set of proven properties.
- Identifies verification blind spots in complex modules, such as specific FSM branches, exception-return paths, or rare handshake scenarios.

### 1.5.2 Typical Inputs and Outputs

- Inputs usually include the design, assertions, constraints, coverage goals, and data generated by earlier verification runs.
- Outputs are coverage reports that show which goals were hit, which were missed, and which paths are reachable but not yet proven.
- In the flow shown in the figure, Coverage Analyzer combines VCS-side merged.vdb and VC Formal-side vcst_rtdb, then uses URG to generate the final coverage report.

### 1.5.3 How to Read the Flow Diagram

- The VCS Coverage flow is simulation-oriented: compile the DUT and testbench, run multiple tests, then merge the results into merged.vdb.
- The Formal Coverage Analyzer flow is formal-oriented: first use Tcl to read the design, clocks, resets, grid options, and resource limits, then enter the vcf shell for analysis.
- On the formal side, an exclusion file can be used to remove items that should not be counted, so the report is not overwhelmed by noise.
- URG finally merges results from different sources and produces the unified coverage report.

### 1.5.4 When It Is Most Useful

- When assertions already pass, but you are not sure whether the verification has reached the critical boundaries.
- When the design is large and state-rich, and you need to know whether verification is concentrated on only a few easy-to-hit paths.
- When you want to combine simulation coverage and formal coverage for convergence signoff.
- When you need clearer evidence of verification quality for review or reporting.

### 1.5.5 Important Caveats

- High coverage does not mean the design is correct; it must be interpreted together with assertion proofs and counterexample analysis.
- Weak constraints can make the coverage report look impressive while contributing little real value.
- Use exclusion files carefully so that important targets are not accidentally removed.
- For complex designs, focus first on high-value targets and then expand to finer-grained coverage items.

## 1.6 Startup Script

This script is an FPV startup and initialization script. Its main purpose is to prepare the design, assertions, clocks, resets, and initial state before entering the formal verification flow. The structure is standard: set the mode, read the design, define clocks and resets, then perform initialization.

```tcl
set_fml_appmode FPV

############################################################
## Setup Specific to DUT
############################################################
set design traffic
signoff_config -type (toggle)

############################################################
## Compile & Setup
############################################################
## Compilation Step
read_file -top $design -format sverilog -sva \
  -vcs {-f ../design/filelist +define+INLINE_SVA \
  ../sva/traffic.sva}

## Clock Definitions
create_clock clk -period 100

## Reset Definitions
create_reset rst -sense high

## Initialisation Commands
sim_run -stable
sim_save_reset

#check_fv
```

### 1.6.1 Line-by-Line Explanation

- set_fml_appmode FPV: switch VC Formal into FPV mode, which is functional proof verification.
- set design traffic: specify traffic as the DUT to be analyzed.
- signoff_config -type (toggle): configure signoff settings; the figure shows a toggle-type setup.
- read_file -top $design -format sverilog -sva: read the top design and include SVA files.
- -vcs {-f ../design/filelist +define+INLINE_SVA ../sva/traffic.sva}: use a VCS-style file list and macro definition for compilation, and add traffic.sva as the assertion file.
- create_clock clk -period 100: define clock clk with a period of 100.
- create_reset rst -sense high: define reset rst as active-high.
- sim_run -stable: let the simulation/initial state settle.
- sim_save_reset: save the reset state as one of the starting points for later analysis.
- #check_fv: a comment marker indicating that the next step is usually the formal check phase.

### 1.6.2 Execution Order

- First set the tool mode and DUT.
- Then compile the RTL and assertion files together.
- Next define the clock and reset to make the verification environment explicit.
- Then run the initialization steps and save a usable initial state.
- Finally move into the actual check_fv-style formal verification flow.

### 1.6.3 How to Understand the Script

- The script is essentially building a minimal usable FPV environment.
- The first half brings the design into the tool; the second half defines the verification starting point.
- If the clock, reset, or assertion files are wrong, the proof results will be misleading, so this is one of the most important preparation stages in formal verification.
