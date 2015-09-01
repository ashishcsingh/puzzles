/*
 * threads_test.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: acs
 */

#include "threads.h"
#include "threads_test.h"
#include <iostream>

namespace threads {

using namespace std;

template<class ASYNC>
void print_results( ASYNC &f, string &pattern, int threadno )
{
    vector<string> words = f.get();
    cerr << "Found " << words.size()
         << " matches for " << pattern
         << " in thread " << threadno
         << endl;
    for ( auto s : words )
        cout << s << "\n";
}

void Test_WordSearch()
{
    string pattern = "c..per";

    string words[] = {"copper", "cloper",  "subject" };
    deque<string> backlog;
    for(auto word: words) {
        backlog.push_back( word );
    }
    auto f1 = async( launch::async, find_matches, pattern, ref(backlog) );
    auto f2 = async( launch::async, find_matches, pattern, ref(backlog) );
    auto f3 = async( launch::async, find_matches, pattern, ref(backlog) );
    print_results( f1, pattern, 1 );
    print_results( f2, pattern, 2 );
    print_results( f3, pattern, 3 );
}

/*
 * What: Using Lambda spawn thread to compute twice for 10.
 * How: Spawn and then get();
 */
void Test_Twice() {
   vector<future<int>> futures;
   for(int i = 0; i < 10; ++i) {
      futures.push_back(async([] (int n) { return 2*n;}, i));
   }
   for(auto &f: futures) {
      cout<<f.get()<<endl;
   }
}

void Test_Threads() {
   Test_WordSearch();
   Test_Twice();
}
}


