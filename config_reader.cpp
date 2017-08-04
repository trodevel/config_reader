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

// $Revision: 7516 $ $Date:: 2017-08-03 #$ $Author: serge $

#include "config_reader.h"              // self

#include <stdexcept>                    // std::runtime_error

// for config reading
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>        // boost::property_tree::ptree

namespace config_reader
{

class Helper
{
public:

static void iterate_and_extract( ConfigReader * res, const std::string & section_name, const boost::property_tree::ptree & pt )
{
    auto it_end = pt.end();
    for( auto it = pt.begin(); it != it_end; ++it )
    {
        const std::string & key     = it->first;
        const std::string & value   = it->second.data();

        res->insert( section_name, key, value );
    }
}

static void extract_section( ConfigReader * res, const boost::property_tree::ptree & pt )
{
    auto it_end = pt.end();
    for( auto it = pt.begin(); it != it_end; ++it )
    {
        const std::string & section_name    = it->first;

        iterate_and_extract( res, section_name, it->second );
    }
}

};

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

    Helper::extract_section( this, pt );

    return true;
}

bool ConfigReader::get_value( std::string * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    //std::cout << "get_value: section " << section_name << ", key " << key_name << std::endl;

    auto it = map_section_to_map_.find( section_name );

    if( it == map_section_to_map_.end() )
    {
        if( throw_on_error )
            throw exception( "cannot find section '" + section_name + "'" );

        return false;
    }

    auto & map = it->second;

    auto it_2 = map.find( key_name );

    if( it_2 == map.end() )
    {
        if( throw_on_error )
            throw exception( "cannot find key '" + key_name + "'" );

        return false;
    }

    * res = it_2->second;

    return true;
}

bool ConfigReader::get_value( std::string * res, const std::string & section_name, const std::string & key_name ) const
{
    return get_value( res, section_name, key_name, false );
}

bool ConfigReader::get_value_converted( std::int16_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::int16_t>( std::stoi( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( std::int32_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::int32_t>( std::stol( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( std::int64_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::int64_t>( std::stoll( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( std::uint16_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::uint16_t>( std::stoul( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( std::uint32_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::uint32_t>( std::stoul( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( std::uint64_t * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = static_cast<std::uint64_t>( std::stoull( val_str ) );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( float * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = std::stof( val_str );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}

bool ConfigReader::get_value_converted( double * res, const std::string & section_name, const std::string & key_name, bool throw_on_error ) const
{
    std::string val_str;

    if( get_value( & val_str, section_name, key_name, throw_on_error ) == false )
        return false;

    try
    {
        * res   = std::stof( val_str );

        return true;
    }
    catch( std::exception & e )
    {
        if( throw_on_error )
            throw exception( "conversion error: section '" + section_name + "', key '" + key_name + "'" );

        return false;
    }
}


void ConfigReader::insert( const std::string & section_name, const std::string & key, const std::string & value )
{
    //std::cout << "insert: section " << section_name << ", key " << key << ", value " << value << std::endl;

    auto b = map_section_to_map_[ section_name ].insert( std::make_pair( key, value ) ).second;

    if( b == false )
        throw std::runtime_error( "duplicate key '" + key + "' in section '" + section_name + "'" );
}


} //namespace config_reader
