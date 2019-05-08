#
# Copyright (C) 2018 Marvell International Ltd.
#
# SPDX-License-Identifier: GPL-2.0+
# https://spdx.org/licenses
#

ifeq ($(CONFIG_BOARD_CONFIG_EEPROM), y)
  ifeq ($(CONFIG_BOARD_CONFIG_EEPROM_FLASH), y)
    obj-$(CONFIG_BOARD_CONFIG_EEPROM_FLASH)	+= cfg_eeprom_sf.o
  else
    obj-$(CONFIG_BOARD_CONFIG_EEPROM)	+= cfg_eeprom.o
  endif
endif

obj-$(CONFIG_MVEBU_SAR)	+= sar.o
