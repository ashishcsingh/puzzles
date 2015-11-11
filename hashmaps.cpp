/*
 * hashs.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */
#include "hashmaps.h"
#include <ostream>
#include <queue>

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

}

