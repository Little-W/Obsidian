# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb_npu_single_core.mk for the caller.

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
  Vtb_npu_single_core \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__0 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__1 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__2 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__3 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__4 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__5 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__6 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__7 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__8 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__9 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__10 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__11 \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__12 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__0 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__1 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__2 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__3 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__4 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__5 \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__6 \
  Vtb_npu_single_core__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  Vtb_npu_single_core__ConstPool_0 \
  Vtb_npu_single_core___024root__Slow \
  Vtb_npu_single_core___024root__DepSet_h8f5b9f25__0__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__0__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__1__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__2__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__3__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__4__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__5__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__6__Slow \
  Vtb_npu_single_core___024root__DepSet_h6a9dcc3f__7__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  Vtb_npu_single_core__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_timing \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
