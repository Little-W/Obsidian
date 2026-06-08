TARGET := demo_dhrystone_test

NUCLEI_SDK_ROOT = $(PROJ_PATH)/ux900k_rls_pkg_lyg/ux900k/nuclei-sdk

TOOLCHAIN ?= nuclei_gnu
CORE    := ux900k
# supported mode
## ground: ground rules for dhrystone
## best: best effort rules for dhrystone
DHRY_MODE ?= ground

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
CPU_SERIES ?= 900
endif

-include toolchain_$(TOOLCHAIN).mk

COMMON_FLAGS := $(BENCH_FLAGS)

SRCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

C_SRCDIRS = .

INCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

STDCLIB ?= newlib_small

include $(NUCLEI_SDK_ROOT)/Build/Makefile.base
