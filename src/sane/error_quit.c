/*
 *  ScanGear MP for Linux
 *  Copyright CANON INC. 2007-2016
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

#include "../cnmsstrings.h"
#include "../errors.h"

#include "error_quit.h"


int get_last_error_quit()
{
	int		ret = -1;
	int		errorCode = 0;

	DBGMSG("->\n");

	if ( lastIOErrCode ) {
		errorCode = -lastIOErrCode;
		if( errorCode != ERR_CODE_ENOSPC ) {
			errorCode = ERR_CODE_INT;
		}
	}
	else if ( lastModuleErrCode ) {
		errorCode = ERR_CODE_INT;
	}
	else {
		errorCode = lastBackendErrCode;
	}
	DBGMSG("errorCode = %d\n", errorCode );
	ret = CIJSC_ERROR_DLG_QUIT_FALSE;

	/* error occurred. */
	if ( errorCode ) {
	    CIJSC_ERROR_MSG_TABLE const * error_info = get_error_info_by_code(errorCode);
	    if ( error_info->id < 0 ) {
		    goto _EXIT;
	    }
	    ret = error_info->quit;

	}
_EXIT:
	lastBackendErrCode = 0;

	return ret;
}
