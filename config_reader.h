/*

INI Config Reader.

Copyright (C) 2017 Sergey Kolevatov

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

// $Revision: 7489 $ $Date:: 2017-08-02 #$ $Author: serge $

#ifndef LIB_CONFIG_READER_CONFIG_READER_H
#define LIB_CONFIG_READER_CONFIG_READER_H

#include <string>                   // std::string
#include <map>                      // std::map

namespace config_reader
{

class ConfigReader
{
public:
    typedef std::map<std::string, std::string>  MapStrToStr;
    typedef std::map<std::string, MapStrToStr>  MapStrToMapStrToStr;

public:

    ConfigReader();
    ~ConfigReader();

    bool init(
            const std::string & config_file );

    bool get_value( std::string * res, const std::string & section_name, const std::string & key_name ) const;

    void insert( const std::string & section_name, const std::string & key, const std::string & value );

private:

    MapStrToMapStrToStr   map_section_to_map_;
};

} // namespace config_reader

#endif // LIB_CONFIG_READER_CONFIG_READER_H
