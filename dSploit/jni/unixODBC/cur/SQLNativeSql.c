/*********************************************************************
 *
 * unixODBC Cursor Library
 *
 * Created by Nick Gorham
 * (nick@lurcher.org).
 *
 * copyright (c) 1999 Nick Gorham
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 **********************************************************************
 *
 * $Id: SQLNativeSql.c,v 1.2 2009/02/18 17:59:18 lurcher Exp $
 *
 * $Log: SQLNativeSql.c,v $
 * Revision 1.2  2009/02/18 17:59:18  lurcher
 * Shift to using config.h, the compile lines were making it hard to spot warnings
 *
 * Revision 1.1.1.1  2001/10/17 16:40:15  lurcher
 *
 * First upload to SourceForge
 *
 * Revision 1.1.1.1  2000/09/04 16:42:52  nick
 * Imported Sources
 *
 * Revision 1.1  1999/09/19 22:22:50  ngorham
 *
 *
 * Added first cursor library work, read only at the moment and only works
 * with selects with no where clause
 *
 *
 **********************************************************************/

#include <config.h>
#include "cursorlibrary.h"

SQLRETURN CLNativeSql(
    SQLHDBC            connection_handle,
    SQLCHAR            *sz_sql_str_in,
    SQLINTEGER         cb_sql_str_in,
    SQLCHAR            *sz_sql_str,
    SQLINTEGER         cb_sql_str_max,
    SQLINTEGER         *pcb_sql_str )
{
    CLHDBC cl_connection = (CLHDBC) connection_handle; 

    /*
     * the cursor lib will take a part in this
     */

    return SQLNATIVESQL( cl_connection,
           cl_connection -> driver_dbc,
           sz_sql_str_in,
           cb_sql_str_in,
           sz_sql_str,
           cb_sql_str_max,
           pcb_sql_str );
}