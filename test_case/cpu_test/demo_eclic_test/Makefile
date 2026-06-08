TARGET = demo_eclic_test

NUCLEI_SDK_ROOT = $(PROJ_PATH)/ux900k_rls_pkg_lyg/ux900k/nuclei-sdk

# Uncomment either option to enable optimization for code size
# extra -flto option will make code size smaller
# Option 1
#COMMON_FLAGS := -Os -msave-restore -fno-unroll-loops -flto
# Option 2
#COMMON_FLAGS := -Os -flto

SRCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

INCDIRS = . $(PROJ_PATH)/verif/chip_top/test/c/common

include $(NUCLEI_SDK_ROOT)/Build/Makefile.base
