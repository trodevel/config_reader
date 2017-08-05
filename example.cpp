/*

Example.

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

// $Revision: 7529 $ $Date:: 2017-08-04 #$ $Author: serge $

#include <iostream>                         // std::cout

#include "config_reader.h"                  // ConfigReader

void test_01( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_1" );

    std::string val;

    if( cr.get_value( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_02( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_999" );

    std::string val;

    if( cr.get_value( & val, section, key ) == false )
    {
        std::cout << "OK: non-existing key '" << key << "' not found" << std::endl;
    }
    else
    {
        std::cout << "ERROR: found non-existing key '" << key << "' = '" << val << "'" << std::endl;
    }
}

void test_03( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_B" );
    std::string key( "par_1" );

    std::string val;

    if( cr.get_value( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_04( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_2" );

    std::uint16_t val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_05( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_2" );

    std::uint32_t val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_06( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_4" );

    float val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_07( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_4" );

    double val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}


void test_08( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_A" );
    std::string key( "par_5" );

    double val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_09( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_B" );
    std::string key( "par_4" );

    bool val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

void test_10( const config_reader::ConfigReader & cr )
{
    std::string section( "Section_B" );
    std::string key( "par_5" );

    bool val;

    if( cr.get_value_converted( & val, section, key ) )
    {
        std::cout << "OK: key '" << key << "' found = '" << val << "'" << std::endl;
    }
    else
    {
        std::cout << "ERROR: cannot find key '" << key << "'" << std::endl;
    }
}

int main()
{
    config_reader::ConfigReader cr;

    cr.init( "example.ini" );

    test_01( cr );
    test_02( cr );
    test_03( cr );
    test_04( cr );
    test_05( cr );
    test_06( cr );
    test_07( cr );
    test_08( cr );
    test_09( cr );
    test_10( cr );

    return 0;
}
