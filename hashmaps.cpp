/*
 * hashs.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */
#include "hashmaps.h"
#include <ostream>
#include <queue>
#include <string>
#include <mutex>
#include <unordered_set>

namespace hashmaps {
using namespace std;

CacheManager* CacheManager::_instance = nullptr;
CacheManager* CacheManager::GetInstance() {
   if (_instance!= nullptr) {
      return _instance;
   } else {
      _instance = new CacheManager();
      return _instance;
   }
}
CacheManager::CacheManager() {}
std::ostream& operator<<(std::ostream& os, UserData& ud) {
   return os<<ud.data;
}

/*
 *    What: Gets top count words from book.
 *    How:  Using unordered_map keep count of occurences.
 *          Then using min_heap on count keep top iterators of map.
 *          Populate using iterators the top count strings (as value).
 */
void TopWords(vector<string>& book, vector<string>& out, int count) {
   unordered_map<string, int> map;
   // Insert all words.
   for(auto& w: book) {
      ++map[w];
   }
   // Sort all word counts using min_heap.
   typedef unordered_map<string,int>::iterator typeMapItr;
   // Liverage iterator in min_heap and compare by count.
   struct compare {
      bool operator() (const typeMapItr& lhs, const typeMapItr& rhs) const {
         return lhs->second > rhs->second;
      }
   };
   priority_queue<typeMapItr, vector<typeMapItr>, compare> pq;
   int inserted = 0;
   for(auto itr=map.begin(); itr!=map.end(); ++itr) {
      // First count should get inserted without checks.
      if(inserted < count) {
         pq.push(itr);
      } else {
         // New inserts must pop out top lowest element.
         if(pq.top()->second < itr->second) {
            pq.pop();
            pq.push(itr);
         }
      }
      ++inserted;
   }
   // Clear the output vector.
   out.clear();
   while(!pq.empty()) {
      auto itr = pq.top();
      pq.pop();
      out.push_back(itr->first);
   }
}

/*
 * What: Phonebook class organizes phone and name for easy look up
 * How: Using hashmaps and via thread safe way.
 */
string Phonebook::LookUpByName(const string& name) {
   auto p = mapNameToPhone_.find(name);
   if (p == mapNameToPhone_.end()) {
      return "Not found";
   } else {
      return p->second;
   }
}
string Phonebook::LookUpByPhone(const string& phone) {
   auto n = mapPhoneToName_.find(phone);
   if (n == mapPhoneToName_.end()) {
      return "Not found";
   } else {
      return n->second;
   }
}
void Phonebook::RemovePerson(const Person& person) {
   lock_guard<mutex> lock(m_);
   mapNameToPhone_.erase(person.name);
   mapPhoneToName_.erase(person.phone);
}
void Phonebook::AddPerson(const Person& person) {
   lock_guard<mutex> lock(m_);
   mapNameToPhone_[person.name] = person.phone;
   mapPhoneToName_[person.phone] = person.name;
}

Phonebook::Phonebook(const list<Person>& people) {
   lock_guard<mutex> lock(m_);
   for(auto& p : people) {
      mapNameToPhone_[p.name] = p.phone;
      mapPhoneToName_[p.phone] = p.name;
   }
}


/*
 * What: Returns list of all numbers that add to sum.
 * How:  Using unordered_set capture all numbers.
 *       Then see if sum-num exists if yes then save.
 */
vector<pair<int,int>> PairSum(vector<int> nums, int sum) {
   unordered_set<int> set(nums.begin(), nums.end());
   vector<pair<int,int>> result;
   for(auto i : set) {
      if(set.count(sum - i) > 0) {
         result.push_back(make_pair(i, sum - i));
      }
   }
   return result;
}

/*
 * What : Return unique dividers of a num.
 * How:     i: 1 to N check i % n == 0 and
 *          set.count(i) && set.count(n/i) == 0 then
 *          insert i and set.insert(n/i) and result.push_back(make_pair(i, n/i))
 */
vector<pair<int,int>> PairUniqueDivider(int num) {
   unordered_set<int> set;
   vector<pair<int,int>> result;
   for(int i=1; i<num; ++i) {
      if(num % i == 0 && set.count(i)==0 && set.count(num/i)==0) {
         set.insert(i);
         result.push_back(make_pair(i, num/i));
      }
   }
   return result;
}

}

