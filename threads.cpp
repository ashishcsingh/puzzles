/*
 * threads.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: acs
 */

#include "threads.h"

#include <fstream>
#include <iostream>
#include <string>

namespace threads {

using namespace std;

std::mutex m;

inline bool match( const std::string &pattern, std::string word )
{
    if ( pattern.size() != word.size() )
        return false;
    for ( size_t i = 0 ; i < pattern.size() ; i++ )
        if ( pattern[ i ] != '.' && pattern[ i ] != word[ i ] )
            return false;
    return true;
}

vector<string> find_matches( string pattern, deque<string> &backlog )
{
    vector<string> results;
    for ( ; ; ) {
        m.lock();
        if ( backlog.size() == 0 ) {
            m.unlock();
            return results;
        }
        string word = backlog.front();
        backlog.pop_front();
        m.unlock();
        if ( match( pattern, word ) )
            results.push_back( word );
    }
}

}

