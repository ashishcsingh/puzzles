/*
 * hashmaps_test.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */

#include "hashmaps.h"
#include <memory>
#include <iostream>
#include <cassert>

namespace hashmaps {
using namespace std;

void Test_CacheManager() {
   cout << "Started testing Test_CacheManager()" << endl;
   unique_ptr<CacheManager> cm(CacheManager::GetInstance());
   cm->SetCapacity(3);
   cm->Put("Ashish", 5);
   cm->Put("Sakshi", 4);
   cm->Put("Other", 6);
   // Normal data insertion check.
   cout << "Should be 5 " << cm->Get("Ashish") << endl;
   // Now the oldest element "Ashish" must be out.
   cm->Put("Test", 7);
   /*
    * Ashish should out of Cache and then when accessing non-existence value
    * It should get set to the defaults.
    */
   cout << "Should be 0 " << cm->Get("Ashish") << endl;
   cout << "Done testing Test_CacheManager()" << endl;
}

void Test_TopWords() {
   cout << "Started testing Test_TopWords()" << endl;
   vector<string> s { "word", "words", "hello", "hello", "super", "random" };
   vector<string> o;
   TopWords(s, o, 2);
   for (auto& w : o) {
      cout << w << " ";
   }
   cout << endl;
   cout << "Done testing Test_TopWords()" << endl;
}

void Test_Phonebook() {
   cout << "Started testing Test_Phonebook()" << endl;
   list<Person> people;
   people.push_back(Person("Sakshi", "408-121-1212"));
   people.push_back(Person("Ashish", "508-121-1212"));
   people.push_back(Person("Girish", "608-121-1212"));
   Phonebook pb(people);
   pb.AddPerson(Person("Amita", "708-121-12121"));
   cout << "Phone of Ashish : " << pb.LookUpByName("Ashish") << endl;
   cout << "Phone of Sakshi : " << pb.LookUpByName("Sakshi") << endl;
   cout << "Name of 408-121-1212 : " << pb.LookUpByPhone("408-121-1212")
         << endl;
   cout << "Phone of unknown : " << pb.LookUpByName("Unknown") << endl;
   cout << "Done testing Test_Phonebook()" << endl;
}

void Test_PairSum() {
   cout << "Start testing Test_PairSum()" << endl;
   vector<int> v { 2, 4, 5, 6, 7 };
   auto r = PairSum(v, 9);
   for (auto p : r) {
      cout << p.first << " " << p.second << endl;
   }
   cout << "Done testing Test_PairSum()" << endl;
}

void Test_PairUniqueDivider() {
   cout << "Start testing Test_PairUniqueDivider()" << endl;
   auto r = PairUniqueDivider(12);
   for (auto p : r) {
      cout << p.first << " " << p.second << endl;
   }
   cout << "Done testing Test_PairUniqueDivider()" << endl;
}

void Test_Hashmap() {
   cout << "Start testing Test_Hashmap()" << endl;
   Hashmap<int, string> map;
   cout << "Putting hashmap" << endl;
   map.Put(10, "San Jose");
   cout << "Getting hashmap" << endl;
   cout << map.Get(10) << endl;
   cout << "Done testing Test_Hashmap()" << endl;

}

void Test_SetRandomTest() {
   cout << "Start testing Test_SetRandomTest()" << endl;
   SetRandom<string> set;
   set.Add("Ashish");
   assert(set.Add("Ashish") == false);
   set.Add("Sakshi");
   assert(set.Exists("Sakshi") == true);
   set.RandomRemove();
   cout << "Done testing Test_SetRandomTest()" << endl;
}

void Test_HashMaps() {
#ifdef TEST_DONE
   Test_CacheManager();
   Test_TopWords();
#endif
   Test_Phonebook();
   Test_PairSum();
   Test_PairUniqueDivider();
   Test_Hashmap();
   Test_SetRandomTest();
}
}

