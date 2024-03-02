SDK_PREFIX := dummy-prefix-to-remove-warning-
CONFIG_ENVIRONMENT := FPGA_UART
THIS_DIR := $(subst config.mk,.,$(lastword $(MAKEFILE_LIST)))
include $(THIS_DIR)/lib/targets/configs/config-a730-default.mk
DEMO_APP := fsbl
