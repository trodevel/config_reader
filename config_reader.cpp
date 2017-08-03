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

// $Revision: 7492 $ $Date:: 2017-08-02 #$ $Author: serge $

#include "config_reader.h"              // self

#include <iostream>                         // std::cout
#include <stdexcept>                    // std::runtime_error

// for config reading
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>        // boost::property_tree::ptree

namespace config_reader
{

void iterate_and_extract( ConfigReader * res, const std::string & section_name, const boost::property_tree::ptree & pt )
{
    auto it_end = pt.end();
    for( auto it = pt.begin(); it != it_end; ++it )
    {
        const std::string & key     = it->first;
        const std::string & value   = it->second.data();

        res->insert( section_name, key, value );
    }
}

void extract_section( ConfigReader * res, const boost::property_tree::ptree & pt )
{
    auto it_end = pt.end();
    for( auto it = pt.begin(); it != it_end; ++it )
    {
        const std::string & section_name    = it->first;

        iterate_and_extract( res, section_name, it->second );
    }
}

ConfigReader::ConfigReader()
{
}

ConfigReader::~ConfigReader()
{
}

bool ConfigReader::init(
        const std::string & config_file )
{
    if( config_file.empty() )
        return false;

    boost::property_tree::ptree pt;

    boost::property_tree::ini_parser::read_ini( config_file, pt );

    extract_section( this, pt );

    return true;
}

bool ConfigReader::get_value( std::string * res, const std::string & section_name, const std::string & key_name ) const
{
    std::cout << "get_value: section " << section_name << ", key " << key_name << std::endl;

    auto it = map_section_to_map_.find( section_name );

    if( it == map_section_to_map_.end() )
    {
        return false;
    }

    auto & map = it->second;

    auto it_2 = map.find( key_name );

    if( it_2 == map.end() )
    {
        return false;
    }

    * res = it_2->second;

    return true;
}

void ConfigReader::insert( const std::string & section_name, const std::string & key, const std::string & value )
{
    std::cout << "insert: section " << section_name << ", key " << key << ", value " << value << std::endl;

    auto b = map_section_to_map_[ section_name ].insert( std::make_pair( key, value ) ).second;

    if( b == false )
        throw std::runtime_error( "duplicate key '" + key + "' in section '" + section_name + "'" );
}


} //namespace config_reader
