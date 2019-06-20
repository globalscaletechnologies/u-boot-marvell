/*
 * Copyright (C) 2016 Stefan Roese <sr@denx.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _CONFIG_MVEBU_ARMADA_37XX_H
#define _CONFIG_MVEBU_ARMADA_37XX_H

#define CONFIG_DEFAULT_CONSOLE		"console=ttyMV0,115200 "\
					"earlycon=ar3700_uart,0xd0012000"

/* USB 2.0 */
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS 1

/* USB 3.0 */
#define CONFIG_SYS_USB_XHCI_MAX_ROOT_PORTS 2

#include <configs/mvebu_armada-common.h>

/*
 * High Level Configuration Options (easy to change)
 */
#define CONFIG_NR_DRAM_BANKS	4

/*
 * I2C
 */
#define CONFIG_I2C_MV
#define CONFIG_SYS_I2C_SLAVE		0x0

/* Environment in MMC */
#define CONFIG_SYS_MMC_ENV_DEV		1 /* 0 means sdio, 1 means mmc. */

/*
 * Ethernet Driver configuration
 */
#define CONFIG_MVNETA		/* Enable Marvell Gbe Controller Driver */
#define CONFIG_PHY_MARVELL


/*
 * PCI configuration
 */
#ifdef CONFIG_PCIE_ADVK
#define CONFIG_CMD_PCI
#endif


#undef BOOT_TARGET_DEVICES
#undef CONFIG_EXTRA_ENV_SETTINGS

#define SDBOOT		\
					"sdboot=mmc dev 0; " \
					"ext4load mmc 0:1 $kernel_addr_r $image_name; " \
					"ext4load mmc 0:1 $fdt_addr_r $fdt_name; " \
					"setenv bootargs $console root=/dev/mmcblk0p1 rw rootwait " \
					"net.ifnames=0 biosdevname=0 $extra_params; " \
					"booti $kernel_addr_r - $fdt_addr_r\0"

#define EMMCBOOT	\
					"emmcboot=mmc dev 1; " \
					"ext4load mmc 1:1 $kernel_addr_r $image_name; " \
					"ext4load mmc 1:1 $fdt_addr_r $fdt_name; " \
					"setenv bootargs $console " \
					"root=PARTUUID=89708921-01 rw rootwait " \
					"net.ifnames=0 biosdevname=0 $extra_params; " \
					"booti $kernel_addr_r - $fdt_addr_r\0"

#define FACTORYBOOT	\
					"recovery=usb reset; " \
					"fatload usb 0 $loadaddr sheeva64-recovery.bin; " \
					"source $loadaddr\0"

#undef BOOTENV
#define BOOTENV		\
					EMMCBOOT \
					SDBOOT \
					FACTORYBOOT

#define CONFIG_EXTRA_ENV_SETTINGS		\
	"fdt_name=boot/" CONFIG_DEFAULT_DEVICE_TREE ".dtb\0"		\
	"image_name=boot/Image\0"			\
	"kernel_addr_r=0x7000000\0"		\
	"initrd_addr=0xa00000\0"		\
	"initrd_size=0x2000000\0"		\
	"fdt_addr_r=0x6f00000\0"		\
	"loadaddr=0x7000000\0"			\
	"fdt_high=0xffffffffffffffff\0"		\
	"hostname=marvell\0"			\
	"netdev=eth0\0"				\
	"ethaddr=00:51:82:11:22:00\0"		\
	"eth1addr=00:51:82:11:22:01\0"		\
	"console=" CONFIG_DEFAULT_CONSOLE "\0"	\
	BOOTENV

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND		"run emmcboot"

#endif /* _CONFIG_MVEBU_ARMADA_37XX_H */
