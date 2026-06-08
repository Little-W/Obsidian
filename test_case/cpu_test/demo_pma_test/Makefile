TARGET = demo_pma_test

NUCLEI_SDK_ROOT = $(PROJ_PATH)/ux900k_rls_pkg_lyg/ux900k/nuclei-sdk

SRCDIRS = . src $(PROJ_PATH)/verif/chip_top/test/c/common

INCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common inc

COMMON_FLAGS := -O2

# DOWNLOAD mode must be a mode
# such as external ddr/sram, core local ilm is not ok which will bypass cache
DOWNLOAD ?= sram

ifeq ($(DOWNLOAD),ddr)
COMMON_FLAGS += -DBIG_ROW_SIZE
endif

include $(NUCLEI_SDK_ROOT)/Build/Makefile.base
