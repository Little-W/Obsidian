TARGET = cpu_enable_mmu_test

NUCLEI_SDK_ROOT = $(PROJ_PATH)/ux900k_rls_pkg_lyg/ux900k/nuclei-sdk

DOWNLOAD=sram

COMMON_FLAGS :=  -gdwarf-4 -gstrict-dwarf

SRCDIRS = . src $(PROJ_PATH)/verif/chip_top/test/c/common

INCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common inc

include $(NUCLEI_SDK_ROOT)/Build/Makefile.base
