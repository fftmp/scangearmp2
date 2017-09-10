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

#include <gtk/gtk.h>

#include "support.h"
#include "callbacks.h"
#include "cnmsstrings.h"
#include "errors.h"

#include "errordlg.h"

int CIJSC_UI_error_show( SGMP_Data *data, GtkWidget *parent )
{
	int		index_id, index_mes;
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
	data->last_error_quit = CIJSC_ERROR_DLG_QUIT_FALSE;
	
	/* error occurred. */
	if ( errorCode ) {
		if ( parent ) {
			if( GTK_WIDGET_VISIBLE( parent ) ) {
				gtk_widget_set_sensitive( parent, FALSE );
			}
		}
		
		/* get error id. */
		for( index_id = 0; index_id < sizeof( error_index_table ) / sizeof( CIJSC_ERROR_INDEX_TABLE ) ; index_id++ ) {
			if ( error_index_table[index_id].code == errorCode ) {
				break;
			}
		}
		DBGMSG("index_id = %d\n", index_id );
		if ( index_id == ( sizeof( error_index_table ) / sizeof( CIJSC_ERROR_INDEX_TABLE ) ) ) {
			goto _EXIT;
		}
		/* get error message. */
		for( index_mes = 0; error_msg_table[index_mes].id >= 0 ; index_mes++ ) {
			if ( error_msg_table[index_mes].id == error_index_table[index_id].id ) {
				break;
			}
		}
		DBGMSG("index_mes = %d\n", index_mes );
		if ( error_msg_table[index_mes].id < 0 ) {
			goto _EXIT;
		}
		gtk_label_set_label( GTK_LABEL ( data->label_error_msg ), gettext( error_msg_table[index_mes].msg ) );
		switch ( error_msg_table[index_mes].type ){
			case CIJSC_ERROR_DLG_TYPE_OK :
				gtk_widget_hide( data->button_error_cancel );
				gtk_widget_show( data->button_error_ok );
				gtk_widget_grab_focus( data->button_error_ok );
				break;
			case CIJSC_ERROR_DLG_TYPE_OK_CANCEL :
				gtk_widget_show( data->button_error_cancel );
				gtk_widget_show( data->button_error_ok );
				if( error_msg_table[index_mes].id == CIJSC_ERROR_SAVE_OVERWRITE ) {
					gtk_widget_grab_focus( data->button_error_cancel );
				}
				else {
					gtk_widget_grab_focus( data->button_error_ok );
				}
				break;
			default:
				break;
		}
		ret = error_msg_table[index_mes].quit;
		data->last_error_quit = ret;
		gtk_widget_show( data->dialog_error );
		gtk_main();
	}
_EXIT:
	if ( errorCode ) {
		if ( parent ) {
			if( GTK_WIDGET_VISIBLE( parent ) ) {
				gtk_widget_set_sensitive( parent, TRUE );
			}
		}
	}
	/* clear lastBackendErrCode */
	lastBackendErrCode = 0;
	
	return ret;
}
