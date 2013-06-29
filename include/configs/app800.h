/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian@popies.net>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * Configuation settings for the AT91SAM9M10G45EK board(and AT91SAM9G45EKES).
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/hardware.h>

#define CONFIG_AT91_LEGACY
#define CONFIG_ATMEL_LEGACY		/* required until (g)pio is fixed */

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK      32768
#define CONFIG_SYS_AT91_MAIN_CLOCK      12000000 /* from 12 MHz crystal */
#define CONFIG_SYS_HZ		        1000

#define CONFIG_HMI800
#define CONFIG_AT91FAMILY

#define CONFIG_CMDLINE_TAG		/* enable passing of ATAGs	*/
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_DISPLAY_CPUINFO

#define CONFIG_CMD_BOOTZ
#define CONFIG_OF_LIBFDT

/* Partitions */
#define MT_FLASH_BOOTSTRAP                0x00000000
#define MT_FLASH_BOOTSTRAP_END            0x0003FFFF
#define MT_FLASH_BOOTSTRAP_SIZE           0x00040000
#define MT_FLASH_UBOOT                    0x00040000
#define MT_FLASH_UBOOT_END                0x0009FFFF
#define MT_FLASH_UBOOT_SIZE               0x00060000
#define MT_FLASH_ENV                      0x000A0000
#define MT_FLASH_ENV_END                  0x000BFFFF
#define MT_FLASH_ENV_SIZE                 0x00020000
#define MT_FLASH_KERNEL                   0x000C0000
#define MT_FLASH_KERNEL_END               0x003BFFFF
#define MT_FLASH_KERNEL_SIZE              0x00300000
#define MT_FLASH_CONFIG                   0x003C0000
#define MT_FLASH_CONFIG_END               0x004BFFFF
#define MT_FLASH_CONFIG_SIZE              0x00100000
#define MT_FLASH_SOFTWARE                 0x004C0000
#define MT_FLASH_SOFTWARE_END             0x0FFFFFFF
#define MT_FLASH_SOFTWARE_SIZE            0x0FB40000

#define MT_RAM_KERNEL             0x70000000
#define MT_RAM_UBOOT              0x70000000
#define MT_RAM_ROOTFS             0x70000000
#define MT_RAM_SOFTWARE           0x70000000

/* general purpose I/O */
#define CONFIG_ATMEL_LEGACY		/* required until (g)pio is fixed */
#define CONFIG_AT91_GPIO
#define CONFIG_AT91_GPIO_PULLUP	1	/* keep pullups on peripheral pins */

/* serial console */
#define CONFIG_ATMEL_USART
#define CONFIG_USART_BASE		ATMEL_BASE_DBGU
#define	CONFIG_USART_ID			ATMEL_ID_SYS

/* LCD */
#define CONFIG_LCD
#define LCD_BPP				LCD_COLOR8
#define CONFIG_LCD_LOGO
#undef LCD_TEST_PATTERN
#define CONFIG_LCD_INFO
#define CONFIG_LCD_INFO_BELOW_LOGO
#define CONFIG_SYS_WHITE_ON_BLACK
#define CONFIG_ATMEL_LCD
#define CONFIG_ATMEL_LCD_RGB565
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
/* board specific(not enough SRAM) */
#define CONFIG_AT91SAM9G45_LCD_BASE		0x73E00000

/* LED */
#define CONFIG_AT91_LED
#define	CONFIG_RED_LED		AT91_PIN_PD31	/* this is the user1 led */
#define	CONFIG_GREEN_LED	AT91_PIN_PD0	/* this is the user2 led */

#define CONFIG_BOOTDELAY	3

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>
#undef CONFIG_CMD_BDI
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMI
#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_LOADS

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_NAND
#define CONFIG_CMD_USB

/* SDRAM */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE           ATMEL_BASE_CS6
#define CONFIG_SYS_SDRAM_SIZE		256 * 1024 * 1024

#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_SDRAM_BASE + 4 * 1024 - GENERATED_GBL_DATA_SIZE)

/* No NOR flash */
#define CONFIG_SYS_NO_FLASH

/* NAND flash */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_ATMEL
#define CONFIG_SYS_MAX_NAND_DEVICE		1
#define CONFIG_SYS_NAND_BASE			ATMEL_BASE_CS3
#define CONFIG_SYS_NAND_DBW_8
/* our ALE is AD21 */
#define CONFIG_SYS_NAND_MASK_ALE		(1 << 21)
/* our CLE is AD22 */
#define CONFIG_SYS_NAND_MASK_CLE		(1 << 22)
#define CONFIG_SYS_NAND_ENABLE_PIN		AT91_PIN_PC14
#define CONFIG_SYS_NAND_READY_PIN		AT91_PIN_PC8

#endif

/* Ethernet */
#define CONFIG_MACB
#define CONFIG_RMII
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_RESET_PHY_R

/* USB */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_ATMEL
#define CONFIG_USB_ATMEL_CLK_SEL_UPLL
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS	2
#define CONFIG_DOS_PARTITION
#define CONFIG_USB_STORAGE

#define CONFIG_SYS_LOAD_ADDR		0x22000000	/* load address */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		0x23e00000

/* bootstrap + u-boot + env in nandflash */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET		MT_FLASH_ENV
/* #define CONFIG_ENV_OFFSET_REDUND	0x100000 */
#define CONFIG_ENV_SIZE			0x20000

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define CONFIG_BOOTCOMMAND								\
	"run nand_boot"
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"console=ttyS0,115200\0"					\
	"mtdparts=atmel_nand:256k(bootstrap)ro,384k(uboot)ro,128k(env),3M(kernel)ro,-(rootfs)\0"	\
	"root=/dev/mtdblock4 rw rootfstype=jffs2\0" 			\
	"destenv=nand erase " TOSTRING(MT_FLASH_ENV) " " TOSTRING(MT_FLASH_ENV_SIZE) "\0"	\
	"destconf=nand erase " TOSTRING(MT_CONFIG_ENV) " " TOSTRING(MT_FLASH_CONFIG_SIZE) "\0"	\
	"serverip=192.168.1.117\0"					\
	"ipaddr=192.168.1.121\0"					\
	"ethaddr=aa:bb:45:32:65:7f\0"					\
	"tftpdir=/tftpboot/mt\0"					\
	"bootfile=uImage\0"					\
	"rootpath=/tftpboot/mt/rootfs\0"					\
	"update_uboot=tftp " TOSTRING(MT_RAM_UBOOT) " ${tftpdir}/u-boot.bin; nand erase " 	\
	  TOSTRING(MT_FLASH_UBOOT) " " TOSTRING(MT_FLASH_UBOOT_SIZE) "; nand write " 		\
	  TOSTRING(MT_RAM_UBOOT) " " TOSTRING(MT_FLASH_UBOOT) " " TOSTRING(MT_FLASH_UBOOT_SIZE)	"\0"	\
        "update_kernel=tftp " TOSTRING(MT_RAM_KERNEL) " ${tftpdir}/${bootfile}; nand erase "	\
          TOSTRING(MT_FLASH_KERNEL) " " TOSTRING(MT_FLASH_KERNEL_SIZE) "; nand write "	\
          TOSTRING(MT_RAM_KERNEL) " " TOSTRING(MT_FLASH_KERNEL) " " TOSTRING(MT_FLASH_KERNEL_SIZE) "\0"	\
        "update_software=tftp " TOSTRING(MT_RAM_SOFTWARE) " ${tftpdir}/rootfs.jffs2; nand erase "	\
          TOSTRING(MT_FLASH_SOFTWARE) " " TOSTRING(MT_FLASH_SOFTWARE_SIZE) "; nand write.jffs2 "		\
          TOSTRING(MT_RAM_SOFTWARE) " " TOSTRING(MT_FLASH_SOFTWARE) "${filesize}\0"	\
	"net_boot=run netargs; tftp " TOSTRING(MT_RAM_KERNEL) " ${tftpdir}/${bootfile}; bootm " TOSTRING(MT_RAM_KERNEL) "\0"	\
	"netargs=sete bootargs console=${console} root=/dev/nfs rw nfsroot=${serverip}:${rootpath},tcp "	\
	  "ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off\0"	\
	"nand_boot=run nandargs; nand read " TOSTRING(MT_RAM_KERNEL) " " TOSTRING(MT_FLASH_KERNEL) " " TOSTRING(MT_FLASH_KERNEL_SIZE) ";"     \
	  "bootm " TOSTRING(MT_RAM_KERNEL) "\0"		\
	"nandargs=sete bootargs console=${console} mtdparts=${mtdparts} root=${root}\0"


#define CONFIG_BAUDRATE			115200

#define CONFIG_SYS_PROMPT		"U-Boot> "
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_HUSH_PARSER

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		ROUND(3 * CONFIG_ENV_SIZE + 128*1024, 0x1000)

#endif
