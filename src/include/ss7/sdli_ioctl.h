/*****************************************************************************

 @(#) src/include/ss7/sdli_ioctl.h

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

#ifndef __SDLI_IOCTL_H__
#define __SDLI_IOCTL_H__

/* This file can be processed by doxygen(1). */

#include <linux/ioctl.h>

#define	SDL_IOC_MAGIC	'd'

/*
 *  PROTOCOL VARIANT AND OPTIONS
 */

#define	SDL_IOCGOPTIONS	_IOR(	SDL_IOC_MAGIC,	 0,	lmi_option_t	)
#define	SDL_IOCSOPTIONS	_IOW(	SDL_IOC_MAGIC,	 1,	lmi_option_t	)

/*
 *  CONFIGURATION
 */

#ifdef __KERNEL__
#ifdef _MPS_SOURCE
typedef struct sdl_timers {
	mblk_t *t9;			/* T9 timer */
} sdl_timers_t;
#else				/* _MPS_SOURCE */
typedef struct sdl_timers {
	toid_t t9;			/* T9 timer */
} sdl_timers_t;
#endif				/* _MPS_SOURCE */
#endif				/* __KERNEL__ */

#define SDL_SYNCS 4

typedef struct sdl_config {
	const char *ifname;		/* interface name */
	volatile sdl_ulong ifflags;	/* interface flags */
#	define	SDL_IF_UP		(1<< 0)	/* device enabled */
#	define	SDL_IF_RX_RUNNING	(1<< 1)	/* Rx running */
#	define	SDL_IF_TX_RUNNING	(1<< 2)	/* Tx running */
#	define	SDL_IF_RX_UP		(1<< 3)	/* Rx up */
#	define	SDL_IF_TX_UP		(1<< 4)	/* Tx up */
#	define	SDL_IF_RX_MON		(1<< 5)	/* Rx monitoring */
#	define	SDL_IF_AUTOCONFIG	(1<< 6)	/* Autoconfigure */
#	define	SDL_IF_TX_OCD		(1<< 6)	/* Tx open-circuit */
#	define	SDL_IF_TX_SCD		(1<< 7)	/* Tx short-circuit */
#	define	SDL_IF_TX_LOLITC	(1<< 8)	/* Tx i/f loss of tx clock */
#	define	SDL_IF_TX_LOTC		(1<< 9)	/* Tx loss of tx clock */
#	define	SDL_IF_RX_LRCL		(1<<10)	/* Rx line i/f carrier loss */
#	define	SDL_IF_RX_ILUT		(1<<11)	/* Rx input level under thresh */
#	define	SDL_IF_RX_RLOS		(1<<12)	/* Rx loss of sync */
#	define	SDL_IF_RX_FRCL		(1<<13)	/* Rx frame carrier loss */
#	define	SDL_IF_RX_RUA1		(1<<14)	/* Rx unframed all ones */
#	define	SDL_IF_RX_RYEL		(1<<15)	/* Rx yellow alarm */
#	define	SDL_IF_RX_RRA		(1<<16)	/* Rx remote alarm */
#	define	SDL_IF_RX_LORC		(1<<17)	/* Rx loss of rx clock */
#	define	SDL_IF_RX_LUP		(1<<18)	/* Rx loop-up code */
#	define	SDL_IF_RX_LDN		(1<<19)	/* Rx loop-down code */
#	define	SDL_IF_RX_SPARE		(1<<20)	/* Rx spare code */
#	define	SDL_IF_RX_RDMA		(1<<21)	/* Rx dist MF alarm */
#	define	SDL_IF_RX_RSAZ		(1<<22)	/* Rx sig. all zeros */
#	define	SDL_IF_RX_RSAO		(1<<23)	/* Rx sig. all ones */
#	define	SDL_IF_RX_RAIS		(1<<24)	/* Rx AIS-CI */
#	define	SDL_IF_RX_B8ZS		(1<<25)	/* Rx B8ZS codeword */
#	define	SDL_IF_RX_16ZD		(1<<26)	/* Rx 16-zeros */
#	define	SDL_IF_RX_8ZD		(1<<27)	/* Rx 8-zeros */
#	define	SDL_IF_TX_TUA1		(1<<28)	/* Tx unframed all ones */
#	define	SDL_IF_TX_CUSTD		(1<<29)	/* Tx customer disconnect */
	sdl_ulong iftype;		/* interface type */
#	define	SDL_TYPE_NONE		0	/* unknown/unspecified */
#	define	SDL_TYPE_V35		1	/* V.35 interface */
#	define	SDL_TYPE_DS0		2	/* DS0 channel */
#	define	SDL_TYPE_DS0A		3	/* DS0A channel */
#	define	SDL_TYPE_E1		4	/* full E1 span */
#	define	SDL_TYPE_T1		5	/* full T1 span */
#	define	SDL_TYPE_J1		6	/* full J1 span */
#	define	SDL_TYPE_ATM		7	/* ATM SSCF */
#	define	SDL_TYPE_PACKET		8	/* other packet */
	sdl_ulong ifrate;		/* interface rate */
#	define	SDL_RATE_NONE		0
#	define	SDL_RATE_DS0A		56000
#	define	SDL_RATE_DS0		64000
#	define	SDL_RATE_T1		1544000
#	define	SDL_RATE_J1		1544000
#	define	SDL_RATE_E1		2048000
#	define	SDL_RATE_T2		6312000
#	define	SDL_RATE_E2		8488000
#	define	SDL_RATE_E3		34368000
#	define	SDL_RATE_T3		44736000
	sdl_ulong ifgtype;		/* group type */
#	define	SDL_GTYPE_NONE		0	/* */
#	define	SDL_GTYPE_T1		1	/* */
#	define	SDL_GTYPE_E1		2	/* */
#	define	SDL_GTYPE_J1		3	/* */
#	define	SDL_GTYPE_ATM		4	/* */
#	define	SDL_GTYPE_ETH		5	/* */
#	define	SDL_GTYPE_IP		6	/* */
#	define	SDL_GTYPE_UDP		7	/* */
#	define	SDL_GTYPE_TCP		8	/* */
#	define	SDL_GTYPE_RTP		9	/* */
#	define	SDL_GTYPE_SCTP		10	/* */
#	define	SDL_GTYPE_T2		11	/* */
#	define	SDL_GTYPE_E2		12	/* */
#	define	SDL_GTYPE_E3		13	/* */
#	define	SDL_GTYPE_T3		14	/* */
#	define	SDL_GTYPE_OC3		15	/* */
#	define	SDL_GTYPE_OC12		16	/* */
#	define	SDL_GTYPE_OC48		17	/* */
#	define	SDL_GTYPE_OC192		18	/* */
	sdl_ulong ifgrate;		/* interface group rate */
#	define	SDL_GRATE_NONE		0
#	define	SDL_GRATE_T1		1544
#	define	SDL_GRATE_J1		1544
#	define	SDL_GRATE_E1		2048
#	define	SDL_GRATE_T2		6312
#	define	SDL_GRATE_E2		8488
#	define	SDL_GRATE_E3		34368
#	define	SDL_GRATE_T3		44736
#	define	SDL_GRATE_OC3		155520
#	define	SDL_GRATE_OC12		622080
#	define	SDL_GRATE_OC48		2488320
#	define	SDL_GRATE_OC192		9953280
	sdl_ulong ifmode;		/* interface mode */
#	define	SDL_MODE_NONE		0	/* */
#	define	SDL_MODE_DSU		1	/* */
#	define	SDL_MODE_CSU		2	/* */
#	define	SDL_MODE_DTE		3	/* */
#	define	SDL_MODE_DCE		4	/* */
#	define	SDL_MODE_CLIENT		5	/* */
#	define	SDL_MODE_SERVER		6	/* */
#	define	SDL_MODE_PEER		7	/* */
#	define	SDL_MODE_ECHO		8	/* */
#	define	SDL_MODE_REM_LB		9	/* */
#	define	SDL_MODE_LOC_LB		10	/* */
#	define	SDL_MODE_LB_ECHO	11	/* */
#	define	SDL_MODE_TEST		12	/* */
#       define  SDL_MODE_IDLE           13      /* */
#       define  SDL_MODE_MW             14      /* */
#       define  SDL_MODE_SIG            15      /* */
	sdl_ulong ifgmode;		/* interface group mode */
#	define	SDL_GMODE_NONE		0	/* no loopback */
#	define	SDL_GMODE_LOC_LB	1	/* loopback locally asserted */
#	define	SDL_GMODE_REM_LB	2	/* loopback remotely asserted */
#	define	SDL_GMODE_BOTH_LB	3	/* loopback locally and remotely asserted 
						 */
	sdl_ulong ifgcrc;		/* group CRC type */
#	define	SDL_GCRC_NONE		0	/* */
#	define	SDL_GCRC_CRC4		1	/* */
#	define	SDL_GCRC_CRC5		2	/* */
#	define	SDL_GCRC_CRC6		3	/* */
#	define	SDL_GCRC_CRC6J		4	/* */
	sdl_ulong ifclock;		/* interface clock */
#	define	SDL_CLOCK_NONE		0	/* */
#	define	SDL_CLOCK_INT		1	/* */
#	define	SDL_CLOCK_EXT		2	/* */
#	define	SDL_CLOCK_LOOP		3	/* */
#	define	SDL_CLOCK_MASTER	4	/* */
#	define	SDL_CLOCK_SLAVE		5	/* */
#	define	SDL_CLOCK_DPLL		6	/* */
#	define	SDL_CLOCK_ABR		7	/* */
#	define	SDL_CLOCK_SHAPER	8	/* */
#	define	SDL_CLOCK_TICK		9	/* */
	sdl_ulong ifcoding;		/* interface coding */
#	define	SDL_CODING_NONE		0	/* */
#	define	SDL_CODING_NRZ		1	/* */
#	define	SDL_CODING_NRZI		2	/* */
#	define	SDL_CODING_AMI		3	/* */
#	define	SDL_CODING_B6ZS		4	/* */
#	define	SDL_CODING_B8ZS		5	/* */
#	define	SDL_CODING_HDB3		6	/* */
#	define	SDL_CODING_AAL1		7	/* */
#	define	SDL_CODING_AAL2		8	/* */
#	define	SDL_CODING_AAL5		9	/* */
	sdl_ulong ifframing;		/* interface framing */
#	define	SDL_FRAMING_NONE	0	/* */
#	define	SDL_FRAMING_CCS		1	/* */
#	define	SDL_FRAMING_CAS		2	/* */
#	define	SDL_FRAMING_SF		3	/* */
#	define	SDL_FRAMING_ESF		4	/* */
#	define	SDL_FRAMING_D4		SDL_FRAMING_SF
	sdl_ulong ifblksize;		/* interface block size */
	volatile sdl_ulong ifleads;	/* interface leads */
#	define	SDL_LEAD_DTR		(1<<0)	/* for V.35 DTR lead set or clr */
#	define	SDL_LEAD_RTS		(1<<1)	/* for V.35 RTS lead set or clr */
#	define	SDL_LEAD_DCD		(1<<2)	/* for V.35 DCD lead get */
#	define	SDL_LEAD_CTS		(1<<3)	/* for V.35 CTS lead get */
#	define	SDL_LEAD_DSR		(1<<4)	/* for V.35 DSR lead get */
	volatile sdl_ulong ifbpv;	/* bipolar violations (E1/T1) */
	volatile sdl_ulong ifalarms;	/* interface alarms (E1/T1) */
#	define	SDL_ALARM_RED		(1<<0)	/* for E1/T1 Red Alarm */
#	define	SDL_ALARM_BLU		(1<<1)	/* for E1/T1 Blue Alarm */
#	define	SDL_ALARM_YEL		(1<<2)	/* for E1/T1 Yellow Alarm */
#	define	SDL_ALARM_REC		(1<<3)	/* for E1/T1 Alarm Recovery */
#	define	SDL_ALARM_DMF		(1<<4)	/* for E1 Distant MF Alarm */
	volatile sdl_ulong ifrxlevel;	/* interface rxlevel */
	volatile sdl_ulong iftxlevel;	/* interface txlevel */
#	define	SDL_TXLEVEL_NONE	0
#	define	SDL_TXLEVEL_DSX_133FT	1
#	define	SDL_TXLEVEL_DSX_266FT	2
#	define	SDL_TXLEVEL_DSX_399FT	3
#	define	SDL_TXLEVEL_DSX_533FT	4
#	define	SDL_TXLEVEL_DSX_666FT	5
#	define	SDL_TXLEVEL_CSU_0DB	1
#	define	SDL_TXLEVEL_CSU_8DB	6
#	define	SDL_TXLEVEL_CSU_15DB	7
#	define	SDL_TXLEVEL_CSU_23DB	8
#	define	SDL_TXLEVEL_75OHM_NM	1
#	define	SDL_TXLEVEL_120OHM_NM	2
#	define	SDL_TXLEVEL_75OHM_PR	3
#	define	SDL_TXLEVEL_120OHM_PR	4
#	define	SDL_TXLEVEL_75OHM_HRL	5
#	define	SDL_TXLEVEL_120OHM_HRL	6
#	define	SDL_TXLEVEL_MON_0DB	9
#	define	SDL_TXLEVEL_MON_12DB	10
#	define	SDL_TXLEVEL_MON_20DB	11
#	define	SDL_TXLEVEL_MON_26DB	11
#	define	SDL_TXLEVEL_MON_30DB	11
#	define	SDL_TXLEVEL_MON_32DB	12
	volatile sdl_ulong ifsync;	/* current interface sync src (E1/T1) */
	sdl_ulong ifsyncsrc[SDL_SYNCS];	/* interface sync src (E1/T1) */
} sdl_config_t;

#define	SDL_IOCGCONFIG	_IOR(	SDL_IOC_MAGIC,	 2,	sdl_config_t	)
#define	SDL_IOCSCONFIG	_IOWR(	SDL_IOC_MAGIC,	 3,	sdl_config_t	)
#define	SDL_IOCTCONFIG	_IOWR(	SDL_IOC_MAGIC,	 4,	sdl_config_t	)
#define	SDL_IOCCCONFIG	_IOR(	SDL_IOC_MAGIC,	 5,	sdl_config_t	)

/*
 *  STATE
 */

typedef struct sdl_statem {
	volatile sdl_ulong tx_state;
	volatile sdl_ulong rx_state;
} sdl_statem_t;

#define	SDL_STATE_IDLE		0x00
#define	SDL_STATE_IN_SERVICE	0x01
#define	SDL_STATE_CONGESTED	0x02

#define	SDL_IOCGSTATEM	_IOR(	SDL_IOC_MAGIC,	6,	sdl_statem_t	)
#define	SDL_IOCCMRESET	_IOR(	SDL_IOC_MAGIC,	7,	sdl_statem_t	)

/*
 *  STATISTICS
 */

typedef struct sdl_stats {
	lmi_sta_t header;
	sdl_ulong rx_octets;
	sdl_ulong tx_octets;
	sdl_ulong rx_overruns;
	sdl_ulong tx_underruns;
	sdl_ulong rx_buffer_overflows;
	sdl_ulong tx_buffer_overflows;
	sdl_ulong lead_cts_lost;
	sdl_ulong lead_dcd_lost;
	sdl_ulong carrier_lost;
} sdl_stats_t;

#define	SDL_IOCGSTATSP	_IOR(	SDL_IOC_MAGIC,	 8,	sdl_stats_t	)
#define	SDL_IOCSSTATSP	_IOWR(	SDL_IOC_MAGIC,	 9,	sdl_stats_t	)
#define	SDL_IOCGSTATS	_IOR(	SDL_IOC_MAGIC,	10,	sdl_stats_t	)
#define	SDL_IOCCSTATS	_IOW(	SDL_IOC_MAGIC,	11,	sdl_stats_t	)

/*
 *  EVENTS
 */
typedef struct sdl_notify {
	sdl_ulong events;
#	define	SDL_EVT_LOST_SYNC	0x0000001
#	define	SDL_EVT_SU_ERROR	0x0000002
#	define	SDL_EVT_TX_FAIL		0x0000004
#	define	SDL_EVT_RX_FAIL		0x0000008
} sdl_notify_t;

#define	SDL_IOCGNOTIFY	_IOR(	SDL_IOC_MAGIC,	12,	sdl_notify_t	)
#define	SDL_IOCSNOTIFY	_IOW(	SDL_IOC_MAGIC,	13,	sdl_notify_t	)
#define	SDL_IOCCNOTIFY	_IOW(	SDL_IOC_MAGIC,	14,	sdl_notify_t	)

/*
 *  PASS
 */
typedef struct sdl_pass {
	sdl_long index;			/* lower multiplex index */
	sdl_ulong cmd;			/* embedded input-output control comand */
	/* followed by cmd specific structure */
} sdl_pass_t;

#define	SDL_IOCCPASS	_IOWR(	SDL_IOC_MAGIC,	15,	sdl_pass_t	)

#define	SDL_IOCCDISCTX	_IO(	SDL_IOC_MAGIC,	16	)
#define	SDL_IOCCCONNTX	_IO(	SDL_IOC_MAGIC,	17	)

#define	SDL_IOC_FIRST	 0
#define	SDL_IOC_LAST	17
#define	SDL_IOC_PRIVATE	32

#endif				/* __SDLI_IOCTL_H__ */
