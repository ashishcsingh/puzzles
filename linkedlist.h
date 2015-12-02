#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace linkedlist {
using namespace std;
struct Node {
   Node* next_ { nullptr };
   int data_ { 0 };
   Node(int data) :
         data_(data) {
   }
};
void Insert(Node**, int);
bool Delete(Node**, int);
int Length(Node* node);
void Reverse(Node**);
void DeleteVal(Node **head, int val);
void Print(Node**);
void Clear(Node**);
void Split(Node* head, int pivot, Node** lt, Node** gt);
bool HasCycle(Node* head);
int DistanceFromLoop(Node* head);
int SumLinkedListReverse(Node* l1, Node* l2);
int SumLinkedList(Node* l1, Node* l2);
Node* FindMiddle(Node *head);
bool StackGrowsUp();
bool HeapGrowsUp();
bool IsPalindrom(Node* head);
void InsertDataInSortedCircularList(Node** root, int data);
// Using HashMap.
void RemoveDuplicates1(Node *node);
// Without any space.
void RemoveDuplicates2(Node *node);
// All smaller towards left and larger on right.
Node* PartitionList(Node *node, int data);
// Kth from the last.
Node* KthLastElem(Node *node, int k);

class QueueUsingTwoStacks {
public:
   void Enque(int a);
   int Deque();
private:
   stack<int> enq_;
   stack<int> deq_;
};

/*
 * What: HashMapWithLast
 *       Get(), Delete(), Put(), Has() and Last()
 * How: Using a list<> to locate the last referred element for Last.
 *      Search in the reverse order to keep the latest as last.
 */
template<typename K, typename V>
class HashMapWithLast {
   std::unordered_map<K, V> _map;
   std::list<K> _access;
public:
   void Put(const K& key, const V& value) {
      if(!Has(key)) {
         addNewAccess(key);
      }
      _map[key] = value;
   }
   V Get(const K& key) {
      updateAccess(key);
      return _map[key];
   }
   bool Has(const K& key) {
      return _map.count(key) > 0;
   }
   void Delete(const K& key) {
      deleteAccess(key);
      _map.erase(key);
   }
   K Last() {
      return _access.back();
   }
private:
   void updateAccess(const K& key) {
      if (Last()!= key) {
         deleteAccess(key);
         addNewAccess(key);
      }
   }

   void deleteAccess(const K& key) {
      for(auto it = _access.rbegin(); it!=_access.rend(); ++it) {
         if (*it == key) {
            it++;
            _access.erase((it).base());
            break;
         }
      }
   }
   void addNewAccess(const K& key) {
      _access.push_back(key);
   }
};

template<class T>
class Queue {
public:
   struct Node {
      T data_ { 0 };
      Node* next_ { nullptr };
      Node() :
            data_ { 0 } {
      }
      ;
      Node(const T& data) :
            data_ { data } {
      }
   };
   void Push(const T& data) {
      Node* node = new Node(data);
      if (!head_) {
         head_ = back_ = node;
      } else {
         back_->next_ = node;
         back_ = back_->next_;
      }
   }
   void Pop() {
      if (!head_) {
         return;
      } else {
         //Just one node
         if (back_ == head_) {
            back_ = nullptr;
         }
         Node* node = head_;
         head_ = head_->next_;
         delete node;
      }
   }
   T Front() {
      return head_->data_;
   }
   bool Empty() {
      return !head_;
   }
private:
   Node* head_ { nullptr };
   Node* back_ { nullptr };
};

struct NodeWithWeight {
   int id_ { 0 };
   int parent_ { 0 };
   int weight_ { 0 };
   NodeWithWeight(int id, int parent, int weight) :
         id_ { id }, parent_ { parent }, weight_ { weight } {
   }
};
void PrintSubTreeWeights(const std::list<NodeWithWeight>& nodes);

template<typename T>
struct SmartPtr {
   T* ptr_;
   SmartPtr(T* ptr) : ptr_(ptr) {}
   ~SmartPtr() {
      delete ptr_;
   }
   T* Get() {
      return ptr_;
   }
   T& operator->() {
      return *this;
   }
};

}
#endif
