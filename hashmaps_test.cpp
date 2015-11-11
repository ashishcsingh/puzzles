/*
 * hashmaps_test.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */

#include "hashmaps.h"
#include <memory>
#include <iostream>

namespace hashmaps {
using namespace std;

void Test_CacheManager() {
   cout << "Started testing Test_CacheManager()" << endl;
   unique_ptr<CacheManager> cm (CacheManager::GetInstance());
   cm->SetCapacity(3);
   cm->Put("Ashish", 5);
   cm->Put("Sakshi", 4);
   cm->Put("Other", 6);
   // Normal data insertion check.
   cout<<"Should be 5 "<<cm->Get("Ashish")<<endl;
   // Now the oldest element "Ashish" must be out.
   cm->Put("Test", 7);
   /*
    * Ashish should out of Cache and then when accessing non-existence value
    * It should get set to the defaults.
    */
   cout<<"Should be 0 "<<cm->Get("Ashish")<<endl;
   cout << "Done testing Test_CacheManager()" << endl;
}


void Test_TopWords() {
   cout << "Started testing Test_TopWords()" << endl;
   vector<string> s {"word", "words", "hello", "hello", "super", "random"};
   vector<string> o;
   TopWords(s, o, 2);
   for(auto& w: o) {
      cout<<w<<" ";
   }
   cout<<endl;
   cout << "Done testing Test_TopWords()" << endl;
}


void Test_HashMaps() {
   Test_CacheManager();
   Test_TopWords();
}
}

