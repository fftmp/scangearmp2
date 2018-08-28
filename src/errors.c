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

#include <stddef.h> //NULL
#include "cnmsstrings.h"
#include "errors.h"

CIJSC_ERROR_MSG_TABLE error_msg_table[] = {
	{ CIJSC_ERROR_NO_DEV,			STR_CNMS_LS_010_07,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_CONNECT_FAILED,	STR_CNMS_LS_010_05,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_TRUE, },
	{ CIJSC_ERROR_DEVICE_CANCEL,	STR_CNMS_LS_010_01,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_DEVICE_BUSY,		STR_CNMS_LS_010_03,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_TRUE, },
	{ CIJSC_ERROR_NO_PAPER,			STR_CNMS_LS_010_08,		CIJSC_ERROR_DLG_TYPE_OK_CANCEL, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_DEVICE_ADF_CANCEL,STR_CNMS_LS_010_02,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_DEVICE_OTHER,		STR_CNMS_LS_010_04,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_TRUE, },
	{ CIJSC_ERROR_SAVE_NO_FILE_NAME,STR_CNMS_LS_008_03,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_SAVE_OVERWRITE,	STR_CNMS_LS_008_04,		CIJSC_ERROR_DLG_TYPE_OK_CANCEL, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_SAVE_NO_ACCESS,	STR_CNMS_LS_008_05,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_SAVE_INVALID_DIR,	STR_CNMS_LS_008_06,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_SAVE_OTHER,		STR_CNMS_LS_008_07,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_FALSE, },
	{ CIJSC_ERROR_SAVE_DISK_FULL,	STR_CNMS_LS_010_06,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_TRUE, },
	{ CIJSC_ERROR_INTERNAL,			STR_CNMS_LS_010_09,		CIJSC_ERROR_DLG_TYPE_OK, CIJSC_ERROR_DLG_QUIT_TRUE, },
	{ -1,	NULL, -1, -1, },
};

CIJSC_ERROR_INDEX_TABLE error_index_table[] = {
	{ BERRCODE_CONNECT_NO_DEVICE,			CIJSC_ERROR_NO_DEV },
	{ BERRCODE_CANCELD_BY_STOP,				CIJSC_ERROR_DEVICE_CANCEL },
	{ BERRCODE_SCANNER_BUSY_COPYING,		CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_SCANNER_BUSY_PRINTING,		CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_SCANNER_BUSY_PRINTERMNT,		CIJSC_ERROR_DEVICE_OTHER },
	{ 101,									CIJSC_ERROR_CONNECT_FAILED },
	{ BERRCODE_CONNECT_FAILED,				CIJSC_ERROR_CONNECT_FAILED },
	{ 162,									CIJSC_ERROR_CONNECT_FAILED },
	{ 172,									CIJSC_ERROR_CONNECT_FAILED },
	{ 173,									CIJSC_ERROR_CONNECT_FAILED },
	{ ERR_CODE_ENOSPC,						CIJSC_ERROR_SAVE_DISK_FULL },
	{ ERR_CODE_INT,							CIJSC_ERROR_INTERNAL },
	{ BERRCODE_DEVICE_NOT_AVAILABLE,		CIJSC_ERROR_DEVICE_BUSY },
	{ BERRCODE_DEVICE_INITIALIZE,			CIJSC_ERROR_DEVICE_BUSY },
	{ BERRCODE_SYSTEM,						CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_CANCELED_ADF,				CIJSC_ERROR_DEVICE_ADF_CANCEL },
	{ BERRCODE_ADF_JAM,						CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_ADF_COVER_OPEN,				CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_ADF_NO_PAPER,				CIJSC_ERROR_NO_PAPER },
	{ BERRCODE_ADF_PAPER_FEED,				CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_ADF_MISMATCH_SIZE,			CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_DEVICE_NOT_AVAILABLE_LAN,	CIJSC_ERROR_CONNECT_FAILED },
	{ BERRCODE_DEVICE_NOT_AVAILABLE_LAN_LOCK,	CIJSC_ERROR_CONNECT_FAILED },
	{ BERRCODE_SCANNER_LOCKED,					CIJSC_ERROR_DEVICE_OTHER },
	{ BERRCODE_SCANNER_CONNECT_FAILED_USB,		CIJSC_ERROR_CONNECT_FAILED },
	{ BERRCODE_SCANNER_CONNECT_FAILED_LAN,		CIJSC_ERROR_CONNECT_FAILED },

	{ BERRCODE_SAVE_NO_FILE_NAME,		CIJSC_ERROR_SAVE_NO_FILE_NAME },
	{ BERRCODE_SAVE_OVERWRITE,			CIJSC_ERROR_SAVE_OVERWRITE },
	{ BERRCODE_SAVE_NO_ACCESS,			CIJSC_ERROR_SAVE_NO_ACCESS },
	{ BERRCODE_SAVE_INVALID_DIR,		CIJSC_ERROR_SAVE_INVALID_DIR },
	{ BERRCODE_SAVE_OTHER,				CIJSC_ERROR_SAVE_OTHER },
};

CIJSC_ERROR_MSG_TABLE const * get_error_info_by_code(int err)
{
  unsigned long index_id, index_mes;
  for( index_id = 0; index_id < sizeof( error_index_table ) / sizeof( CIJSC_ERROR_INDEX_TABLE ) ; index_id++ ) {
          if ( error_index_table[index_id].code == err ) {
                  break;
          }
  }
  if ( index_id == ( sizeof( error_index_table ) / sizeof( CIJSC_ERROR_INDEX_TABLE ) ) ) {
          return &error_msg_table[sizeof(error_msg_table) / sizeof(CIJSC_ERROR_MSG_TABLE) - 1];
  }
  /* get error message. */
  for( index_mes = 0; error_msg_table[index_mes].id >= 0 ; index_mes++ ) {
          if ( error_msg_table[index_mes].id == error_index_table[index_id].id ) {
                  return &error_msg_table[index_mes];
          }

  }
  __builtin_unreachable();
}
