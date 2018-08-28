/*
 *  ScanGear MP for Linux
 *  Copyright CANON INC. 2007-2017
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 *
 * NOTE:
 *  - As a special exception, this program is permissible to link with the
 *    libraries released as the binary modules.
 *  - If you write modifications of your own for these programs, it is your
 *    choice whether to permit this exception to apply to your modifications.
 *    If you do not wish that, delete this exception.
*/


#ifndef	_ERRORS_H_
#define	_ERRORS_H_

#include <errno.h>
#include "../usr/include/cnmstype.h"

#ifdef	_GLOBALS_
	#define	GLOBAL
#else
	#define	GLOBAL	extern
#endif

GLOBAL CNMSInt32 lastIOErrCode
#ifdef	_GLOBALS_
 = 0
#endif
;

GLOBAL CNMSInt32 lastBackendErrCode
#ifdef	_GLOBALS_
 = 0
#endif
;

GLOBAL CNMSInt32 lastModuleErrCode
#ifdef	_GLOBALS_
 = 0
#endif
;

#define set_errno() {lastIOErrCode = errno;}
#define set_module_error() {lastModuleErrCode = 1;}


#define ERR_CODE_ENOSPC		(-ENOSPC)
#define ERR_CODE_INT		(-999)

/* BackendErrCode */
#define BERRCODE_CANCELD_BY_STOP			(110)
#define BERRCODE_SCANNER_BUSY_COPYING		(112)
#define BERRCODE_SCANNER_BUSY_PRINTING		(113)
#define BERRCODE_SCANNER_BUSY_PRINTERMNT	(114)
#define BERRCODE_DEVICE_NOT_AVAILABLE		(140)
#define BERRCODE_DEVICE_INITIALIZE			(141)
#define BERRCODE_SYSTEM						(250)
#define BERRCODE_CANCELED_ADF				(111)
#define BERRCODE_ADF_JAM					(103)
#define BERRCODE_ADF_COVER_OPEN				(104)
#define BERRCODE_ADF_NO_PAPER				(105)
#define BERRCODE_ADF_PAPER_FEED				(9)
#define BERRCODE_ADF_MISMATCH_SIZE			(118)

#define BERRCODE_CONNECT_FAILED					(155)
#define BERRCODE_DEVICE_NOT_AVAILABLE_LAN		(145)
#define BERRCODE_DEVICE_NOT_AVAILABLE_LAN_LOCK	(146)
#define BERRCODE_SCANNER_LOCKED					(189)
#define BERRCODE_SCANNER_CONNECT_FAILED_USB		(156)
#define BERRCODE_SCANNER_CONNECT_FAILED_LAN		(157)

#define BERRCODE_CONNECT_NO_DEVICE				(9999)

#define BERRCODE_SAVE_NO_FILE_NAME			(1001)
#define BERRCODE_SAVE_OVERWRITE				(1002)
#define BERRCODE_SAVE_NO_ACCESS				(1003)
#define BERRCODE_SAVE_INVALID_DIR			(1004)
#define BERRCODE_SAVE_OTHER					(1005)

/* error dialog message type */
enum{
	CIJSC_ERROR_NO_DEV = 0,
	CIJSC_ERROR_CONNECT_FAILED,
	CIJSC_ERROR_DEVICE_CANCEL,
	CIJSC_ERROR_DEVICE_BUSY,
	CIJSC_ERROR_NO_PAPER,
	CIJSC_ERROR_DEVICE_ADF_CANCEL,
	CIJSC_ERROR_DEVICE_OTHER,
	CIJSC_ERROR_SAVE_NO_FILE_NAME,
	CIJSC_ERROR_SAVE_OVERWRITE,
	CIJSC_ERROR_SAVE_NO_ACCESS,
	CIJSC_ERROR_SAVE_INVALID_DIR,
	CIJSC_ERROR_SAVE_OTHER,
	CIJSC_ERROR_SAVE_DISK_FULL,
	CIJSC_ERROR_INTERNAL,
};

enum{
	CIJSC_ERROR_DLG_TYPE_OK = 0,
	CIJSC_ERROR_DLG_TYPE_OK_CANCEL,
};

typedef struct {
	const int		id;
	const char		*msg;
	const int		type;
	const int		quit;
} CIJSC_ERROR_MSG_TABLE;

/* error dialog type */
enum{
	CIJSC_ERROR_DLG_QUIT_FALSE = 0,
	CIJSC_ERROR_DLG_QUIT_TRUE,
};

typedef struct {
	const int		code;
	const int		id;
} CIJSC_ERROR_INDEX_TABLE;

CIJSC_ERROR_MSG_TABLE const * get_error_info_by_code(int err);

#endif	/* _ERRORS_H_ */
