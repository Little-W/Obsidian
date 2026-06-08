TARGET = demo_coremark_test

NUCLEI_SDK_ROOT = $(PROJ_PATH)/ux900k_rls_pkg_lyg/ux900k/nuclei-sdk

TOOLCHAIN ?= nuclei_gnu

CORE    := ux900k
# Adjust CPU_SERIES according to passed CORE
ifneq ($(findstring 20,$(CORE)),)
CPU_SERIES ?= 200
else ifneq ($(findstring 30,$(CORE)),)
CPU_SERIES ?= 300
else ifneq ($(findstring 60,$(CORE)),)
CPU_SERIES ?= 600
else ifneq ($(findstring 90,$(CORE)),)
CPU_SERIES ?= 900
else ifneq ($(findstring 1000,$(CORE)),)
CPU_SERIES ?= 1000
else
CPU_SERIES ?= 300
endif

-include toolchain_$(TOOLCHAIN).mk

COMMON_FLAGS := $(BENCH_FLAGS)
COMMON_FLAGS += -DITERATIONS=800 -DPERFORMANCE_RUN=1 -DCFG_SIMULATION
ifeq ($(TOOLCHAIN),terapines)
COMMON_FLAGS +=
else
COMMON_FLAGS += -DFLAGS_STR=\""$(COMMON_FLAGS)"\"
endif

STDCLIB ?= newlib_small

SRCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

INCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

DOWNLOAD = rom
include $(NUCLEI_SDK_ROOT)/Build/Makefile.base
