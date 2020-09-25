/*

INI Config Reader.

Copyright (C) 2020 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 13840 $ $Date:: 2020-09-25 #$ $Author: serge $

#ifndef LIB_CONFIG_READER__GET_VALUE_H
#define LIB_CONFIG_READER__GET_VALUE_H

#define GET_VALUE( _cr, _cfg, _v, _s, _toe )               _cr.get_value( & _cfg-> _v, _s, #_v, _toe )
#define GET_VALUE_CONVERTED( _cr, _cfg, _v, _s, _toe )     _cr.get_value_converted( & _cfg-> _v, _s, #_v, _toe )

#endif // LIB_CONFIG_READER__GET_VALUE_H
