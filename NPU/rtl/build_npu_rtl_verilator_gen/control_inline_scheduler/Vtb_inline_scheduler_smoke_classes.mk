# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb_inline_scheduler_smoke.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  Vtb_inline_scheduler_smoke \
  Vtb_inline_scheduler_smoke___024root__DepSet_h228d9109__0 \
  Vtb_inline_scheduler_smoke___024root__DepSet_h228d9109__1 \
  Vtb_inline_scheduler_smoke___024root__DepSet_h228d9109__2 \
  Vtb_inline_scheduler_smoke___024root__DepSet_h228d9109__3 \
  Vtb_inline_scheduler_smoke___024root__DepSet_h3889d699__0 \
  Vtb_inline_scheduler_smoke___024root__DepSet_h3889d699__1 \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__0 \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__1 \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__2 \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__3 \
  Vtb_inline_scheduler_smoke__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  Vtb_inline_scheduler_smoke__ConstPool_0 \
  Vtb_inline_scheduler_smoke___024root__Slow \
  Vtb_inline_scheduler_smoke___024root__DepSet_h228d9109__0__Slow \
  Vtb_inline_scheduler_smoke___024root__DepSet_h3889d699__0__Slow \
  Vtb_inline_scheduler_smoke___024root__DepSet_h3889d699__1__Slow \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__Slow \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__0__Slow \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h0119fdd0__1__Slow \
  Vtb_inline_scheduler_smoke_npu_inline_desc_decode__DepSet_h1a1e3372__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  Vtb_inline_scheduler_smoke__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_timing \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
