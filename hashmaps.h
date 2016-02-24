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
#include<list>
#include<mutex>
#include<utility>
#include "log.h"

namespace hashmaps {

// Struct for Nodes.
template<typename K, typename V>
struct Hashnode {
   K key;
   V value;
   Hashnode *next { nullptr };
   Hashnode(K k, V v) :
         key(k), value(v) {
   }
};

// Class Hashmap for key and value map.
template<typename K = int, typename V = std::string>
class Hashmap {
public:
   V Get(K key) {
      int loc = Hasher(key) % size_;
      if (map_[loc] == nullptr) {
         map_[loc] = new Hashnode<K, V>(key, V());
         return map_[loc]->value;
      }
      Hashnode<K, V> *node = map_[loc], *prev = node;
      while (node != nullptr) {
         if (node->key == key) {
            return node->value;
         }
         prev = node;
         node = node->next;
      }
      prev = new Hashnode<K, V>(key, V());
      return prev->value;
   }
   void Put(K key, V value) {
      int loc = Hasher(key) % size_;
      if (map_[loc] == nullptr) {
         map_[loc] = new Hashnode<K, V>(key, value);
         return;
      }
      Hashnode<K, V> *node = map_[loc], *prev = node;
      while (node != nullptr) {
         if (node->key == key) {
            node->value = value;
            return;
         }
         prev = node;
         node = node->next;
      }
      prev = new Hashnode<K, V>(key, value);
   }
   Hashmap(int size = 100) :
         size_(size) {
      map_ = new Hashnode<K, V>*[size_];
      for (int i = 0; i < size_; ++i) {
         map_[i] = nullptr;
      }
   }
   virtual ~Hashmap() {
      for (int i = 0; i < size_; ++i) {
         Hashnode<K, V> *node = map_[i], *prev = node;
         while (node != nullptr) {
            prev = node;
            node = node->next;
            delete prev;
         }
      }
      delete[] map_;
   }
protected:
   int Hasher(const K& key) const {
      return reinterpret_cast<int>(key);
   }
   int size_;
   Hashnode<K, V>** map_;
};

/*
 * What: Generic Set that offers RandomRemove().
 * How:  Using a vector and unordered_map locate the random loc.
 */
template<typename T>
class SetRandom {
   std::unordered_map<T, int> map_;
   std::vector<T> seq_;
public:
   bool Add(T t) {
      if (map_.count(t) > 0) {
         return false;
      }
      seq_.push_back(t);
      map_[t] = seq_.size() - 1;
      return true;
   }

   /*
    * Keep moving the last elem to deleted loc and update.
    */
   bool Remove(T t) {
      if (map_.count(t) == 0) {
         return false;
      }
      int loc = map_[t];
      int last = seq_.size() - 1;
      seq_[loc] = seq_[last];
      T lastElem = seq_.back();
      seq_.pop_back();
      map_[lastElem] = loc;
      map_.erase(t);
      return true;
   }
   bool RandomRemove() {
      if (seq_.size() == 0) {
         return false;
      }
      int randomLoc = random() % seq_.size();
      T remove = seq_[randomLoc];
      Remove(remove);
      return true;
   }
   bool Exists(T t) {
      if (map_.count(t) > 0) {
         return true;
      } else {
         return false;
      }
   }
};

struct UserData {
   int data;
   UserData(const UserData& ud) :
         data(ud.data) {
   }
   UserData(int dataPar) :
         data(dataPar) {
   }
   UserData() :
         data(0) {
   }
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
         if (_queue.size == _queue.capacity) {
            Log(VERBOSE,
                  "[CacheManager::Put] capacity maxed : "
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
         if (_queue.size == _queue.capacity) {
            Log(VERBOSE,
                  "[CacheManager::Get] capacity maxed : "
                        + std::to_string(_queue.size));
            std::string lastKey = _queue.dequeue();
            // Remove the key when dequeing
            Log(VERBOSE, "[CacheManager::Get] Removing " + lastKey);
            _hashMap.erase(lastKey);
         }
         slot->key = key;
         _hashMap[key] = slot;
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
      Slot *next { nullptr }, *prev { nullptr };
      Slot(const UserData& udPar) :
            ud(udPar) {
      }
      Slot() :
            ud(0) {
      }
   };
   struct Queue {
      Slot *head { nullptr }, *tail { nullptr };
      int size { 0 }, capacity { 100 };

      void enqueue(Slot* slot) {
         Log(VERBOSE, "[CacheManager::enqueue] key : " + slot->key);
         if (slot == head) {
            return;
         }
         // There is some head.
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
         while (head) {
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
void TopWords(std::vector<std::string>& book, std::vector<std::string>& out,
      int count);

// Phonebook lookup by name and phone.

struct Person {
   std::string name;
   std::string phone;
   Person(const std::string& nameP, const std::string& phoneP) :
         name(nameP), phone(phoneP) {
   }
};

class Phonebook {

private:
   std::unordered_map<std::string, std::string> mapPhoneToName_;
   std::unordered_map<std::string, std::string> mapNameToPhone_;
   std::mutex m_;

public:
   std::string LookUpByName(const std::string& name);
   std::string LookUpByPhone(const std::string& phone);
   void RemovePerson(const Person& person);
   void AddPerson(const Person& person);
   Phonebook(const std::list<Person>& people);
};

// Returns list of all numbers that add to sum.
std::vector<std::pair<int, int>> PairSum(std::vector<int> nums, int sum);
// Return unique dividers of a num.
std::vector<std::pair<int, int>> PairUniqueDivider(int num);

/*
 * What: Returns random node as Next()
 *       Can remove and add Node in constant time.
 * How: Using unordered_map and vector access random content.
 */
template<typename T>
class RandomLoadBalancer {
private:
   std::unordered_map<T, int> map_;
   std::vector<T> seq_;
public:
   bool Add(T host) {
      if(map_.count(host) > 0) {
         return false;
      }
      seq_.push_back(host);
      map_[host] = seq_.size() - 1;
      return true;
   }
   bool Remove(T host) {
      if(map_.count(host) == 0) {
         return false;
      }
      T lastElem = seq_.back();
      int deleteLoc = map_[host];
      map_[lastElem] = deleteLoc;
      seq_[deleteLoc] = lastElem;
      seq_.pop_back();
      map_.erase(host);
      return true;
   }
   T Next() {
      int randomLoc = random() % seq_.size();
      return seq_[randomLoc];
   }
};

}

#endif /* HASHMAPS_H_ */
