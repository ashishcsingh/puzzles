#ifndef _MAXNOY_LINKEDLIST_H
#define _MAXNOY_LINKEDLIST_H

#include <stack>
#include <list>

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

class QueueUsingTwoStacks {
public:
   void Enque(int a);
   int Deque();
private:
   stack<int> enq_;
   stack<int> deq_;
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
      Node(T data) :
            data_ { data } {
      }
   };
   void Push(T data) {
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
}
#endif
