/* ****************************************************************************
 * $Id: nf2.h 6067 2010-04-01 22:36:26Z grg $
 *
 * Module: nf2.h
 * Project: NetFPGA 2 Linux Kernel Driver
 * Description: Header file for kernel driver
 *
 * Change history:
 *
 */

#ifndef _NF2_H
#define _NF2_H	1

#define NF2_DEV_NAME	"nf2"

/* Include for socket IOCTLs */
#include <linux/sockios.h>

/* Maximum number of interfaces */
#ifndef MAX_IFACE
#define MAX_IFACE	4
#endif

/*
 * Register names and locations.
 *
 * Note that these names are not necessarily identical to
 * those in netfpga/hw/common/src/defines
 */

/* CPCI registers */
#define CPCI_REG_ID			0x000
#define CPCI_REG_BOARD_ID		0x004
#define CPCI_REG_CTRL			0x008
#define CPCI_REG_RESET			0x00c
#define CPCI_REG_ERROR			0x010
#define CPCI_REG_DUMMY			0x020
#define CPCI_REG_INTERRUPT_MASK		0x040
#define CPCI_REG_INTERRUPT_STATUS	0x044
#define CPCI_REG_PROG_DATA		0x100
#define CPCI_REG_PROG_STATUS		0x104
#define CPCI_REG_PROG_CTRL		0x108
#define CPCI_REG_DMA_I_ADDR		0x140
#define CPCI_REG_DMA_E_ADDR		0x144
#define CPCI_REG_DMA_I_SIZE		0x148
#define CPCI_REG_DMA_E_SIZE		0x14c
#define CPCI_REG_DMA_I_CTRL		0x150
#define CPCI_REG_DMA_E_CTRL		0x154
#define CPCI_REG_DMA_MAX_XFER_TIME	0x180
#define CPCI_REG_DMA_MAX_RETRIES	0x184
#define CPCI_REG_CNET_MAX_XFER_TIME	0x188
#define CPCI_REG_DMA_I_PKT_CNT		0x400
#define CPCI_REG_DMA_E_PKT_CNT		0x404
#define CPCI_REG_CPCI_REG_RD_CNT	0x408
#define CPCI_REG_CPCI_REG_WR_CNT	0x40c
#define CPCI_REG_CNET_REG_RD_CNT	0x410
#define CPCI_REG_CNET_REG_WR_CNT	0x414

#define CPCI_REG_N_CLK_COUNT            0x500
#define CPCI_REG_P_MAX                  0x504
#define CPCI_REG_N_EXP                  0x508
#define CPCI_REG_P_CLK_CTR              0x510
#define CPCI_REG_RESET_CTR              0x520



/* Base address for CNET registers */
#define CNET_REG_BASE			0x400000


/* Added by nweaver for building memory manipulation
   utilities */
/* 2 MB SRAM size on current board, MAX and SIZE will
   need to be changed if upgraded to 4 MB SRAMs */
#define SRAM_SIZE                       0x200000

#define SRAM_1_BASE                     0x800000
#define SRAM_1_MAX                      0x9FFFFF

#define SRAM_2_BASE                     0xC00000
#define SRAM_2_MAX                      0xDFFFFF
/* end nweaver addition */


/* Device ID registers */
#define NF2_DEVICE_ID   0x0400000
#define NF2_REVISION    0x0400004
#define NF2_DEVICE_STR  0x0400008


/* CNET registers */
#define CNET_REG_ID			(CNET_REG_BASE + 0x000)
#define CNET_REG_CTRL			(CNET_REG_BASE + 0x004)
#define CNET_REG_RESET			(CNET_REG_BASE + 0x008)
#define CNET_REG_ERROR			(CNET_REG_BASE + 0x00C)
#define CNET_REG_ENABLE			(CNET_REG_BASE + 0x010)
#define CNET_REG_WR_SRAM1_EOP		(CNET_REG_BASE + 0x0F0)
#define CNET_REG_RD_SRAM1_EOP		(CNET_REG_BASE + 0x0F4)
#define CNET_REG_WR_SRAM2_EOP		(CNET_REG_BASE + 0x0F8)
#define CNET_REG_RD_SRAM2_EOP		(CNET_REG_BASE + 0x0FC)
#define CNET_REG_MF_STATUS_0		(CNET_REG_BASE + 0x100)
#define CNET_REG_MF_TX_PKTS_SENT_0	(CNET_REG_BASE + 0x104)
#define CNET_REG_MF_RX_PKTS_RCVD_0	(CNET_REG_BASE + 0x108)
#define CNET_REG_MF_RX_PKTS_LOST_0	(CNET_REG_BASE + 0x10C)
#define CNET_REG_MAC_CONFIG_0		(CNET_REG_BASE + 0x110)
#define CNET_REG_MF_STATUS_1		(CNET_REG_BASE + 0x140)
#define CNET_REG_MF_TX_PKTS_SENT_1	(CNET_REG_BASE + 0x144)
#define CNET_REG_MF_RX_PKTS_RCVD_1	(CNET_REG_BASE + 0x148)
#define CNET_REG_MF_RX_PKTS_LOST_1	(CNET_REG_BASE + 0x14C)
#define CNET_REG_MAC_CONFIG_1		(CNET_REG_BASE + 0x150)
#define CNET_REG_MF_STATUS_2		(CNET_REG_BASE + 0x180)
#define CNET_REG_MF_TX_PKTS_SENT_2	(CNET_REG_BASE + 0x184)
#define CNET_REG_MF_RX_PKTS_RCVD_2	(CNET_REG_BASE + 0x188)
#define CNET_REG_MF_RX_PKTS_LOST_2	(CNET_REG_BASE + 0x18C)
#define CNET_REG_MAC_CONFIG_2		(CNET_REG_BASE + 0x190)
#define CNET_REG_MF_STATUS_3		(CNET_REG_BASE + 0x1C0)
#define CNET_REG_MF_TX_PKTS_SENT_3	(CNET_REG_BASE + 0x1C4)
#define CNET_REG_MF_RX_PKTS_RCVD_3	(CNET_REG_BASE + 0x1C8)
#define CNET_REG_MF_RX_PKTS_LOST_3	(CNET_REG_BASE + 0x1CC)
#define CNET_REG_MAC_CONFIG_3		(CNET_REG_BASE + 0x1D0)
#define CNET_REG_RXQ_NUM_PKTS_0		(CNET_REG_BASE + 0x200)
#define CNET_REG_RXQ_POINTERS_0		(CNET_REG_BASE + 0x204)
#define CNET_REG_RXQ_NUM_PKTS_1		(CNET_REG_BASE + 0x240)
#define CNET_REG_RXQ_POINTERS_1		(CNET_REG_BASE + 0x244)
#define CNET_REG_RXQ_NUM_PKTS_2		(CNET_REG_BASE + 0x280)
#define CNET_REG_RXQ_POINTERS_2		(CNET_REG_BASE + 0x284)
#define CNET_REG_RXQ_NUM_PKTS_3		(CNET_REG_BASE + 0x2C0)
#define CNET_REG_RXQ_POINTERS_3		(CNET_REG_BASE + 0x2C4)

#define CNET_REG_MF_RX_PKTS_LOST_BAD_FCS_0 (CNET_REG_BASE + 0x114)
#define CNET_REG_MF_RX_PKTS_LOST_FULL_FIFO_0 (CNET_REG_BASE+0x118)
#define CNET_REG_MF_RX_GOOD_PKTS_RCVD_0     (CNET_REG_BASE+0x11C)
#define CNET_REG_MF_RX_GOOD_BYTES_RCVD_0   (CNET_REG_BASE+0x120)
#define CNET_REG_MF_TX_BYTES_SENT_0 (CNET_REG_BASE+0x124)
#define CNET_REG_MF_RX_PKTS_LOST_BAD_FCS_1 (CNET_REG_BASE+0x154)
#define CNET_REG_MF_RX_PKTS_LOST_FULL_FIFO_1 (CNET_REG_BASE+0x158)
#define CNET_REG_MF_RX_GOOD_PKTS_RCVD_1     (CNET_REG_BASE+0x15C)
#define CNET_REG_MF_RX_GOOD_BYTES_RCVD_1   (CNET_REG_BASE+0x160)
#define CNET_REG_MF_TX_BYTES_SENT_1 (CNET_REG_BASE+0x164)
#define CNET_REG_MF_RX_PKTS_LOST_BAD_FCS_2 (CNET_REG_BASE+0x194)
#define CNET_REG_MF_RX_PKTS_LOST_FULL_FIFO_2 (CNET_REG_BASE+0x198)
#define CNET_REG_MF_RX_GOOD_PKTS_RCVD_2     (CNET_REG_BASE+0x19C)
#define CNET_REG_MF_RX_GOOD_BYTES_RCVD_2   (CNET_REG_BASE+0x1A0)
#define CNET_REG_MF_TX_BYTES_SENT_2 (CNET_REG_BASE+0x1A4)
#define CNET_REG_MF_RX_PKTS_LOST_BAD_FCS_3 (CNET_REG_BASE+0x1D4)
#define CNET_REG_MF_RX_PKTS_LOST_FULL_FIFO_3 (CNET_REG_BASE+0x1D8)
#define CNET_REG_MF_RX_GOOD_PKTS_RCVD_3     (CNET_REG_BASE+0x1DC)
#define CNET_REG_MF_RX_GOOD_BYTES_RCVD_3   (CNET_REG_BASE+0x1E0)
#define CNET_REG_MF_TX_BYTES_SENT_3 (CNET_REG_BASE+0x1E4)

#define CNET_MAC_CLK_CHK_CTRL           (CNET_REG_BASE + 0xF00)
#define CNET_MAC_CLK_CHK_CNT_VALUE      (CNET_REG_BASE + 0xF04)


/* Base address for CNET PHY registers */
#define PHY_REG_BASE			0x600000

#define PHY_REG_CMD			(PHY_REG_BASE)
#define PHY_REG_STATUS			(PHY_REG_BASE)

/*
 * CPCI register masks
 */

/* ID Masks */
#define ID_VERSION			0x00FFFFFF
#define ID_REVISION			0xFF000000

/* Board ID Masks */
#define BOARD_ID			0x00000F00
#define BOARD_ID_CONTROL		0x00000001

/* Control masks */
#define CTRL_CNET_RESET			0x00000100
#define CTRL_LED			0x00000001

/* RESET masks */
#define RESET_CPCI			0x00000001

/* Error masks */
#define ERR_CNET_READ_TIMEOUT		0x02000000
#define ERR_CNET_ERROR			0x01000000
#define ERR_PROG_BUF_OVERFLOW		0x00020000
#define ERR_PROG_ERROR			0x00010000
#define ERR_DMA_TIMEOUT			0x00000400
#define ERR_DMA_RETRY_CNT_EXPIRED	0x00000200
#define ERR_DMA_BUF_OVERFLOW		0x00000100
#define ERR_DMA_RD_SIZE_ERROR		0x00000040
#define ERR_DMA_WR_SIZE_ERROR		0x00000020
#define ERR_DMA_RD_ADDR_ERROR		0x00000010
#define ERR_DMA_WR_ADDR_ERROR		0x00000008
#define ERR_DMA_RD_MAC_ERROR		0x00000004
#define ERR_DMA_WR_MAC_ERROR		0x00000002
#define ERR_DMA_FATAL_ERROR		0x00000001

#define ERR_DMA_SETUP_ERROR ( ERR_DMA_WR_MAC_ERROR | \
                               ERR_DMA_RD_MAC_ERROR | \
                               ERR_DMA_WR_ADDR_ERROR | \
                               ERR_DMA_RD_ADDR_ERROR | \
                               ERR_DMA_WR_SIZE_ERROR | \
                               ERR_DMA_RD_SIZE_ERROR )


/* Interrupt masks */
#define INT_DMA_RX_COMPLETE		0x80000000
#define INT_DMA_TX_COMPLETE		0x40000000
#define INT_PHY_INTERRUPT		0x20000000
#define INT_PKT_AVAIL			0x00000100
#define INT_CNET_ERROR			0x00000020
#define INT_CNET_READ_TIMEOUT		0x00000010
#define INT_PROG_ERROR			0x00000008
#define INT_DMA_TRANSFER_ERROR		0x00000004
#define INT_DMA_SETUP_ERROR		0x00000002
#define INT_DMA_FATAL_ERROR		0x00000001

#define INT_UNKNOWN			~(INT_DMA_RX_COMPLETE | \
					  INT_DMA_TX_COMPLETE | \
					  INT_PHY_INTERRUPT | \
					  INT_PKT_AVAIL | \
					  INT_CNET_ERROR | \
					  INT_CNET_READ_TIMEOUT | \
					  INT_PROG_ERROR | \
					  INT_DMA_TRANSFER_ERROR | \
					  INT_DMA_SETUP_ERROR | \
					  INT_DMA_FATAL_ERROR)

/* Programming status */
#define PROG_INIT			0x00010000
#define PROG_DONE			0x00000100
#define PROG_FIFO_EMPTY			0x00000002
#define PROG_IN_PROGRESS		0x00000001

/* Programming control */
#define PROG_CTRL_RESET			0x00000001

/* DMA control */
#define DMA_CTRL_MAC			0x00000300
#define DMA_CTRL_OWNER			0x00000001

/*
 * CNET register masks
 */

/* Reset masks */
#define CNET_RESET_MAC			0x0000000F
#define CNET_RESET_MAC_3		0x00000008
#define CNET_RESET_MAC_2		0x00000004
#define CNET_RESET_MAC_1		0x00000002
#define CNET_RESET_MAC_0		0x00000001

/* Error masks */
#define CNET_ERROR_TX_UNDERRUN_MAC	0x000000F0
#define CNET_ERROR_TX_UNDERRUN_MAC_3	0x00000080
#define CNET_ERROR_TX_UNDERRUN_MAC_2	0x00000040
#define CNET_ERROR_TX_UNDERRUN_MAC_1	0x00000020
#define CNET_ERROR_TX_UNDERRUN_MAC_0	0x00000010
#define CNET_ERROR_TX_OVERRUN_MAC	0x0000000F
#define CNET_ERROR_TX_OVERRUN_MAC_3	0x00000008
#define CNET_ERROR_TX_OVERRUN_MAC_2	0x00000004
#define CNET_ERROR_TX_OVERRUN_MAC_1	0x00000002
#define CNET_ERROR_TX_OVERRUN_MAC_0	0x00000001

/* Enable masks */
#define CNET_ENABLE_RX_FIFO		0x0000F000
#define CNET_ENABLE_RX_FIFO_3		0x00008000
#define CNET_ENABLE_RX_FIFO_2		0x00004000
#define CNET_ENABLE_RX_FIFO_1		0x00002000
#define CNET_ENABLE_RX_FIFO_0		0x00001000
#define CNET_ENABLE_TX_MAC		0x00000F00
#define CNET_ENABLE_TX_MAC_3		0x00000800
#define CNET_ENABLE_TX_MAC_2		0x00000400
#define CNET_ENABLE_TX_MAC_1		0x00000200
#define CNET_ENABLE_TX_MAC_0		0x00000100
#define CNET_ENABLE_DEBUG_TRISTATE	0x00000004
#define CNET_ENABLE_INGRESS_ARBITER	0x00000002
#define CNET_ENABLE_RX_DMA		0x00000001

/* MF Status masks */
#define CNET_MF_STATUS_RX_FIFO_EMPTY	0x02000000
#define CNET_MF_STATUS_RX_PKT_AVAIL	0x01000000
#define CNET_MF_STATUS_RX_NUM_PKTS	0x00FF0000
#define CNET_MF_STATUS_TX_FIFO_FULL	0x00000200
#define CNET_MF_STATUS_TX_FIFO_NO_MAX_PKT	0x00000100
#define CNET_MF_STATUS_TX_NUM_PKTS	0x000000FF

/* MAC Config masks */
#define CNET_MAC_CFG_FULL_DUPLEX	0x00000020
#define CNET_MAC_CFG_TX_FCS_SUPPLIED	0x00000010
#define CNET_MAC_CFG_RX_WANT_FCS	0x00000008
#define CNET_MAC_CFG_JUMBO_ENABLE	0x00000004

#define CNET_MAC_CFG_SPEED		0x00000002
#define CNET_MAC_CFG_1000_MBPS		0x00000002
#define CNET_MAC_CFG_100_MBPS		0x00000001
#define CNET_MAC_CFG_10_MBPS		0x00000000

#define CNET_RXQ_WR_PTR			0x00FF0000
#define CNET_RXQ_RD_PTR			0x000000FF


/* Phy register masks */
#define PHY_RD_WR			0x80000000
#define PHY_PHY				0x03000000
#define PHY_ADDR			0x001F0000
#define PHY_DATA			0x0000FFFF

#define PHY_DONE			0x80000000
#define PHY_DONE_CNT			0x001F0000

/* Defines to calculate register values */
/* CPCI Funcs */
#define NF2_GET_VERSION(x)		(x & 0xFFFFFF)
#define NF2_GET_REVISION(x)		((x & 0xFF000000) >> 24)

#define NF2_GET_BOARD_ID(x)		((x & BOARD_ID) >> 8)
#define NF2_GET_CONTROL(x)		(x & BOARD_ID_CONTROL)

#define NF2_GET_CNET_RESET(x)		((x & CTRL_CNET_RESET) >> 8)
#define NF2_GET_LED(x)			(x & CTRL_LED)

#define NF2_GET_RESET(x)		(x & RESET_CPCI)

#define NF2_GET_CNET_READ_TIMEOUT(x)	((x & ERR_CNET_READ_TIMEOUT) >> 25)
#define NF2_GET_CNET_ERROR(x)		((x & ERR_CNET_ERROR) >> 24)
#define NF2_GET_PROG_BUF_OVERFLOW(x)	((x & ERR_PROG_BUF_OVERFLOW) >> 12)
#define NF2_GET_PROG_ERROR(x)		((x & ERR_PROG_ERROR) >> 11)
#define NF2_GET_DMA_TIMEOUT(x)		((x & ERR_DMA_TIMEOUT) >> 10)
#define NF2_GET_DMA_RETRY_CNT_EXPIRED(x)	\
	((x & ERR_DMA_RETRY_CNT_EXPIRED) >> 9)
#define NF2_GET_DMA_BUF_OVERFLOW(x)	((x & ERR_DMA_BUF_OVERFLOW) >> 8)
#define NF2_GET_DMA_RD_SIZE_ERROR(x)	((x & ERR_DMA_RD_SIZE_ERROR) >> 6)
#define NF2_GET_DMA_WR_SIZE_ERROR(x)	((x & ERR_DMA_WR_SIZE_ERROR) >> 5)
#define NF2_GET_DMA_RD_ADDR_ERROR(x)	((x & ERR_DMA_RD_ADDR_ERROR) >> 4)
#define NF2_GET_DMA_WR_ADDR_ERROR(x)	((x & ERR_DMA_WR_ADDR_ERROR) >> 3)
#define NF2_GET_DMA_RD_MAC_ERROR(x)	((x & ERR_DMA_RD_MAC_ERROR) >> 2)
#define NF2_GET_DMA_WR_MAC_ERROR(x)	((x & ERR_DMA_WR_MAC_ERROR) >> 1)
#define NF2_GET_DMA_FATAL_ERROR(x)	(x & ERR_DMA_FATAL_ERROR)

#define NF2_GET_INT_DMA_TX_COMPLETE(x)	((x & INT_DMA_TX_COMPLETE) >> 31)
#define NF2_GET_INT_DMA_RX_COMPLETE(x)	((x & INT_DMA_RX_COMPLETE) >> 30)
#define NF2_GET_INT_PHY_INTERRUPT(x)	((x & INT_PHY_INTERRUPT) >> 29)
#define NF2_GET_INT_PKT_AVAIL(x)	((x & INT_PKT_AVAIL) >> 8)
#define NF2_GET_INT_CNET_ERROR(x)	((x & INT_CNET_ERROR) >> 5)
#define NF2_GET_INT_CNET_READ_TIMEOUT(x)	\
	((x & INT_CNET_READ_TIMEOUT) >> 4)
#define NF2_GET_INT_PROG_ERROR(x)	((x & INT_PROG_ERROR) >> 3)
#define NF2_GET_INT_DMA_TRANSFER_ERROR(x)	\
	((x & INT_DMA_TRANSFER_ERROR) >> 2)
#define NF2_GET_INT_DMA_SETUP_ERROR(x)	((x & INT_DMA_SETUP_ERROR) >> 1)
#define NF2_GET_INT_DMA_FATAL_ERROR(x)	(x & INT_DMA_FATAL_ERROR)

#define NF2_GET_PROG_INIT(x)		((x & PROG_INIT) >> 16)
#define NF2_GET_PROG_DONE(x)		((x & PROG_DONE) >> 8)
#define NF2_GET_PROG_FIFO_EMPTY(x)	((x & PROG_FIFO_EMPTY) >> 1)
#define NF2_GET_PROG_IN_PROGRESS(x)	(x & PROG_IN_PROGRESS)

#define NF2_GET_DMA_CTRL_MAC(x)		((x & DMA_CTRL_MAC) >> 8)
#define NF2_GET_DMA_CTRL_OWNER(x)	(x & DMA_CTRL_OWNER)

#define NF2_SET_DMA_CTRL_MAC(x)		(x << 8)


/* CNET Funcs */
#define NF2_GET_CNET_VERSION(x)		((x & 0xFFFF0000) >> 16)
#define NF2_GET_CNET_DEVICE_ID(x)	(x & 0xFFFF)

#define NF2_GET_CNET_RESET_MAC(x)		(x & CNET_RESET_MAC)

#define NF2_GET_CNET_ERROR_TX_UNDERRUN_MAC(x)	\
	((x & CNET_ERROR_TX_UNDERRUN_MAC) >> 4)
#define NF2_GET_CNET_ERROR_TX_OVERRUN_MAC(x)	\
	(x & CNET_ERROR_TX_OVERRUN_MAC)

#define NF2_GET_CNET_ENABLE_RX_FIFO(x)	((x & CNET_ENABLE_RX_FIFO) >> 12)
#define NF2_GET_CNET_ENABLE_TX_MAC(x)	((x & CNET_ENABLE_TX_MAC) >> 8)
#define NF2_GET_CNET_ENABLE_DEBUG_TRISTATE(x)	\
	((x & CNET_ENABLE_DEBUG_TRISTATE) >> 2)
#define NF2_GET_CNET_ENABLE_INGRESS_ARBITER(x)	\
	((x & CNET_ENABLE_INGRESS_ARBITER) >> 1)
#define NF2_GET_CNET_ENABLE_RX_DMA(x)	(x & CNET_ENABLE_RX_DMA)

#define NF2_GET_CNET_MF_STATUS_RX_FIFO_EMPTY(x)	\
	((x & CNET_MF_STATUS_RX_FIFO_EMPTY) >> 25)
#define NF2_GET_CNET_MF_STATUS_RX_PKT_AVAIL(x)	\
	((x & CNET_MF_STATUS_RX_PKT_AVAIL) >> 24)
#define NF2_GET_CNET_MF_STATUS_RX_NUM_PKTS(x)	\
	((x & CNET_MF_STATUS_RX_NUM_PKTS) >> 16)
#define NF2_GET_CNET_MF_STATUS_TX_FIFO_FULL(x)	\
	((x & CNET_MF_STATUS_TX_FIFO_FULL) >> 9)
#define NF2_GET_CNET_MF_STATUS_TX_FIFO_NO_MAX_PKT(x)	\
	((x & CNET_MF_STATUS_TX_FIFO_NO_MAX_PKT) >> 8)
#define NF2_GET_CNET_MF_STATUS_TX_NUM_PKTS(x)	\
	(x & CNET_MF_STATUS_TX_NUM_PKTS)

#define NF2_GET_CNET_MAC_CFG_FULL_DUPLEX(x)	\
	((x & CNET_MAC_CFG_FULL_DUPLEX) >> 5)
#define NF2_GET_CNET_MAC_CFG_TX_FCS_SUPPLIED(x)	\
	((x & CNET_MAC_CFG_TX_FCS_SUPPLIED) >> 4)
#define NF2_GET_CNET_MAC_CFG_RX_WANT_FCS(x)	\
	((x & CNET_MAC_CFG_RX_WANT_FCS) >> 3)
#define NF2_GET_CNET_MAC_CFG_JUMBO_ENABLE(x)	\
	((x & CNET_MAC_CFG_JUMBO_ENABLE) >> 2)
#define NF2_GET_CNET_MAC_CFG_SPEED(x)	\
	(x & CNET_MAC_CFG_SPEED)

#define NF2_GET_CNET_RXQ_WR_PTR(x)	((x & CNET_RXQ_WR_PTR) >> 16)
#define NF2_GET_CNET_RXQ_RD_PTR(x)	(x & CNET_RXQ_RD_PTR)


/* PHY functions */
#define NF2_SET_PHY_IS_READ(x)		(x << 31)
#define NF2_SET_PHY_SELECT(x)		(x << 24)
#define NF2_SET_PHY_ADDR(x)		(x << 16)
#define NF2_SET_PHY_DATA(x)		(x)

#define NF2_GET_PHY_DATA(x)		(x & PHY_DATA)
#define NF2_GET_PHY_DONE(x)		((x & PHY_DONE) >> 31)
#define NF2_GET_PHY_DONE_CNT(x)		((x & PHY_DONE_CNT) >> 16)


/*
 * IOCTLs
 */
#define SIOCREGREAD		SIOCDEVPRIVATE
#define SIOCREGWRITE		(SIOCDEVPRIVATE + 1)


/* MDIO registers */
#define MDIO_0_AUX_STATUS              0x0440064
#define MDIO_0_INTR_STATUS             0x0440068
#define MDIO_0_INTR_MASK               0x044006c


/* MDIO address delta between each phy base address */
#define ADDRESS_DELTA                  0x80


/* MDIO bit positions */
#define INTR_LINK_STATUS_POS           0x2
#define AUX_LINK_STATUS_POS            0x4


/*
 * Structure for transferring register data via an IOCTL
 */
struct nf2reg {
	unsigned int	reg;
	unsigned int	val;
};

#endif
