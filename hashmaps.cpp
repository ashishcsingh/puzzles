/*
 * hashs.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */
#include "hashmaps.h"
#include <ostream>

namespace hashmaps {
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
}

