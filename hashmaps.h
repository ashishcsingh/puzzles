/*
 * hash.h
 *
 *  Created on: Oct 18, 2015
 *      Author: acs
 */

#ifndef HASHMAPS_H_
#define HASHMAPS_H_

#include<unordered_map>
#include<deque>
#include<string>
#include<ostream>
#include<vector>

#include "log.h"

namespace hashmaps {

struct UserData {
   int data;
   UserData(const UserData& ud) : data(ud.data) {}
   UserData(int dataPar) : data(dataPar) {}
   UserData() : data(0) {}
   UserData& operator=(const UserData& ud) {
      if (this != &ud) {
         data = ud.data;
      }
      return *this;
   }
};

class CacheManager {
public:
   // methods
   void Put(const std::string& key, const UserData& ud) {
      Log(VERBOSE, "[CacheManager::Put] Putting key : " + key);
      if (_hashMap.count(key) > 0) {
         Slot *slot = _hashMap[key];
         slot->ud = ud;
         slot->key = key;
         _queue.detach(slot);
         _queue.enqueue(slot);
         Log(VERBOSE, "[CacheManager::Put] Existing : " + key);
      } else {
         Slot *slot = new Slot(ud);
         if(_queue.size == _queue.capacity) {
            Log(VERBOSE, "[CacheManager::Put] capacity maxed : "
                  + std::to_string(_queue.size));
            std::string lastKey = _queue.dequeue();
            // Remove the key when dequeing
            Log(VERBOSE, "[CacheManager::Put] Removing " + lastKey);
            _hashMap.erase(lastKey);
         }
         slot->key = key;
         _queue.enqueue(slot);
         _hashMap[key] = slot;
         Log(VERBOSE, "[CacheManager::Put] New : " + key);
      }
   }

   UserData& Get(const std::string& key) {
      Log(VERBOSE, "[CacheManager::Get] Getting key : " + key);
      if (_hashMap.count(key) > 0) {
         Slot *slot = _hashMap[key];
         _queue.detach(slot);
         _queue.enqueue(slot);
         Log(VERBOSE, "[CacheManager::Get] Existing : " + key);
         return slot->ud;
      } else {
         Slot *slot = new Slot();
         if(_queue.size == _queue.capacity) {
            Log(VERBOSE, "[CacheManager::Get] capacity maxed : "
                  + std::to_string(_queue.size));
            std::string lastKey = _queue.dequeue();
            // Remove the key when dequeing
            Log(VERBOSE, "[CacheManager::Get] Removing " + lastKey);
            _hashMap.erase(lastKey);
         }
         slot->key = key;
         _queue.enqueue(slot);
         Log(VERBOSE, "[CacheManager::Get] New : " + key);
         return slot->ud;
      }
   }

   void SetCapacity(int capacity) {
      _queue.capacity = capacity;
   }
   int GetCapacity() {
      return _queue.capacity;
   }
   int GetSize() {
      return _queue.size;
   }
   static CacheManager* GetInstance();
private:
   CacheManager();
   struct Slot {
      UserData ud;
      std::string key;
      Slot *next{nullptr}, *prev{nullptr};
      Slot(const UserData& udPar) : ud(udPar) {}
      Slot() : ud(0) {}
   };
   struct Queue {
      Slot *head {nullptr}, *tail{nullptr};
      int size{0}, capacity{100};

      void enqueue(Slot* slot) {
         Log(VERBOSE, "[CacheManager::enqueue] key : " + slot->key);
         if (slot == head) {
            return;
         }
         // There some head.
         if (head != nullptr) {
            slot->next = head;
            head->prev = slot;
            head = slot;
         } else {
            head = tail = slot;
         }
         ++size;
      }

      std::string dequeue() {
         Slot* last = tail;
         tail = tail->prev;
         if (tail != nullptr) {
            tail->next = nullptr;
         } else {
            // head and tail are null.
            head = tail;
         }
         --size;
         std::string lastKey = last->key;
         delete last;
         Log(VERBOSE, "[CacheManager::dequeue] " + lastKey);
         return lastKey;
      }
      void detach(Slot* slot) {
         // It cannot be head.
         slot->prev->next = slot->next;
         if (slot->next != nullptr) {
            slot->next->prev = slot->prev;
         }
         slot->next = nullptr;
         slot->prev = nullptr;
         --size;
      }
      ~Queue() {
         while(head) {
            Slot *slot = head;
            head = head->next;
            delete slot;
         }
         tail = nullptr;
      }
   };
   std::unordered_map<std::string, Slot*> _hashMap;
   Queue _queue;
   static CacheManager *_instance;
};
std::ostream& operator<<(std::ostream& os, UserData& ud);

// Finds top count words in book with O(n.log(k)) cost.
void TopWords(std::vector<std::string>& book, std::vector<std::string>& out, int count);

}

#endif /* HASHMAPS_H_ */
