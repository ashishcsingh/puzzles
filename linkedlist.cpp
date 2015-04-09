/*
 * linkedlist.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: acs
 */

#include"linkedlist.h"
#include<iostream>
#include<cctype>
#include<cassert>
#include<stack>

namespace linkedlist {
using namespace std;
/*
 * Inserts at first location
 * 1. Create a node with data
 * 2. node's next is *head
 * 3. *head is now the new node
 */
void Insert(Node** head, int data) {
  Node* node = new Node(data);
  node->next_ = *head;
  *head = node;
  return;
}

/*
 * Print all the nodes starting head
 */
void Print(Node** head) {
   if(head==nullptr || *head==nullptr) {
      return;
   }
   Node* node = *head;
   std::cout<<"Printing nodes :";
   while(node) {
      std::cout<<" "<<node->data_;
      node = node->next_;
   }
   std::cout<<std::endl;
}

/*
 * What: Enque(int a)
 *       Inserts a into Queue formed by two stacks
 * How:  First stack is meant for all the insertions
 *       Whenever there is a request for pop
 *       Elements will be moved out of second
 *        Stack by first moving there.
 *
 */
void QueueUsingTwoStacks::Enque(int e) {
   enq_.push(e);
}

/*
 *  What: int Deque()
 *  How:  Removes element from deq_ stack.
 *        If nothing in deq_ stack then move elements from enq_ stack
 *        here.
 */
int QueueUsingTwoStacks::Deque() {
   if(deq_.empty()) {
      if(!enq_.empty()) {
         for(int i=0; i<enq_.size(); ++i) {
            deq_.push(enq_.top());
            enq_.pop();
         }
      }
   }
   if(!deq_.empty()) {
      int ret = deq_.top();
      deq_.pop();
      return ret;
   }
   cerr<<"Queue empty"<<endl;
   return -1;
}

/*
 * Split the linkedList at location "pivot".
 * And store the left node and right node in lt and gt
 *    1. Initialize *lt = nullptr, *gt = nullptr.
 *    2. Iterate through node starting head.
 *          2.1 if *node < pivot
 *              2.1.1 if(!*lt) *lt = node; lNode = node;
 *              2.1.2 else lNode->next = node; lNode = lNode->next;
 *          2.2 else
 *              2.2.1 if(!*gt) *gt = node; gNode = node;
 *              2.2.2 else gNode->next = node; gNode = gNode->next;
 */

void Split(Node* head, int pivot, Node** lt, Node** gt) {
   *lt = nullptr;
   *gt = nullptr;
   if(!head) {
      return;
   }
   Node* node = head;
   Node* lNode = nullptr;
   Node* gNode = nullptr;
   while(node!=nullptr) {
      if(node->data_ < pivot) {
         if(*lt==nullptr) {
            *lt = node;
            lNode = node;
         } else {
            lNode->next_ = node;
            lNode = lNode->next_;
         }
      }
      else {
         if(*gt==nullptr) {
            *gt = node;
            gNode = node;
         } else {
            gNode->next_ = node;
            gNode = gNode->next_;
         }
      }
      node = node->next_;
   }
   lNode->next_ = nullptr;
   gNode->next_ = nullptr;
}

/*
 * Deletes the content "$deleteMe"
 * 1. traverse through head till nullptr
 * 2. When ptr->next_->data_ is deleteMe then removes the ptr->next_
 * 3. Plumbs back the ptr->next_ to the ptr->next_->_next
 */
bool Delete(Node** head, int deleteMe) {
   if (head == nullptr || *head == nullptr) {
      return false;
   }
   while ((*head) && (*head)->data_ == deleteMe) {
      Node* node = *head;
      *head = (*head)->next_;
      delete node;
   }
   Node* node = *head;
   //Either *head is nullptr or non null with non deleteMe
   while(node && node->next_) {
      if(node->next_->data_ == deleteMe) {
         Node* temp = node->next_;
         node->next_ = node->next_->next_;
         delete temp;
      }
   }
   return true;
}

/*
 * Clean linkedlist
 * 1. Store in temp the current Node
 * 2. Then move to next while deleting the temp
 * 3. Stop at end.
 */
void Clear(Node** head) {
   if (head==nullptr || *head==nullptr) {
      return;
   }
   Node* node = *head;
   while(node!=nullptr) {
      Node* temp = node;
      node = node->next_;
      delete temp;
   }
   *head = nullptr;
}

/*
 * HasCycle(Node* node)
 * 1. Two iterators, one at double speed and one at single speed
 * 2. After initializing, if they ever meet then this list has a cycle.
 * 3. If it doesn't then stop
 */
bool HasCycle(Node* node) {
   if(node==nullptr || node->next_==nullptr) {
      return false;
   }
   Node* node1 = node;
   Node* node2 = node;
   do {
      if(node1==nullptr) {
         return false;
      } else {
         node1 = node1->next_;
      }
      if(node2==nullptr || node2->next_==nullptr) {
         return false;
      } else {
         node2 = node2->next_->next_;
      }
   } while (node1!= node2);
   return true;
}

/*
 * Allocate two variables in the stack and compare their addresses
 */
bool StackGrowsUp() {
   int a = 5;
   int b = 6;
   if(&a < &b) {
      return true;
   } else {
      return false;
   }
}

/*
 * Allocate two variables in the stack and compare their addresses
 */
bool HeapGrowsUp() {
   int* a = new int(5);
   int* b = new int(6);
   if(a < b) {
      return true;
   } else {
      return false;
   }
}

/*
 * What: A->B->C then return B
 * How:
 * FindMiddle(Node* node)
 * 1. Two iterators, one at double speed and one at single speed
 * 2. After initializing, if they ever meet then this list has a cycle return nullptr;
 * 3. If it hits nullptr then return node1 which is middle;
 * Returns: nullptr when there is a loop else the middle
 */
Node* FindMiddle(Node* node) {
   if(node==nullptr || node->next_==nullptr) {
      return nullptr;
   }
   Node* node1 = node;
   Node* node2 = node;
   do {
      if(node2==nullptr || node2->next_==nullptr) {
         return node1;
      } else {
         node2 = node2->next_->next_;
      }
      if(node1==nullptr) {
         return node1;
      } else {
         node1 = node1->next_;
      }
   } while (node1!= node2);
   return nullptr;
}

/*
 * What: Length(Node* node)
 *       Returns length
 * How: Iterate till end
 */
int Length(Node* node) {
   int len = 0;
   while(node) {
      ++len;
      node = node->next_;
   }
   return len;
}

/*
 * What: Checks if symmetric pattern like 1234321 or 123321 exists
 * How: 1* Figure out odd and even and populate stack till half
 *      2. The second pointer stepping at double speed hits the end
 *      3. The first pointer hits the center
 *      4. Push first->data into stack
 *      5. For odd skip one element
 *      6* Match first.data till end with stack data
 *      7. When mismatch between stack and first.data return false
 *      8. When one is true, end or stack-empty return false
 *      9. When both stack-empty and end then return true
 */
bool IsPalindrom(Node* head) {
   if(head==nullptr || head->next_==nullptr) {
      return true;
   }
   Node* first = head;
   Node* second = head;
   stack<int> s;
   do {
      if(second) {
         // Progress
         if(second->next_) {
            second = second->next_->next_;
         } else {
            // Odd break
            first = first->next_;
            break;
         }
      } else {
         // Even break
         break;
      }
      s.push(first->data_);
      first = first->next_;
   } while(true);
   // Now check stack with the other half
   while(true) {
      // Positive end condition
      if(first==nullptr && s.empty()) {
         return true;
      }
      // Negative end condition
      if(first==nullptr || s.empty()) {
         return false;
      }
      // Negative condition
      if(s.top() != first->data_) {
         return false;
      }
      s.pop();
      first = first->next_;
   }
}

int SumLinkedList(Node* l1, Node* l2) {
   int len1 = Length(l1);
   int len2 = Length(l2);
   Node* temp1 = l1;
   Node* temp2 = l2;
   if(len1 < len2) {
      for(int i=0; i<len1; ++i) {
         temp1 = temp1->next_;
      }
      for(int i=0; i<len2 - len1; ++i) {
         temp1->next_ = new Node(0);
         temp1 = temp1->next_;
      }
   } else if(len1 > len2) {
      for(int i=0; i<len2; ++i) {
         temp2 = temp2->next_;
      }
      for(int i=0; i<len1 - len2; ++i) {
         temp2->next_ = new Node(0);
         temp2 = temp2->next_;
      }
   }
   Reverse(&l1);
   Reverse(&l2);
   return SumLinkedListReverse(l1, l2);
}

/*
 * What:   Reverses the LinkedList
 * How:    base->next = prev after stepping node, prev
 */
void Reverse(Node** head) {
   if(head==nullptr || *head==nullptr) {
      return;
   }
   Node* node = *head;
   Node *prev = nullptr, *base = nullptr;
   while(node) {
      base = node;
      node = node->next_;
      // The important action for each iteration
      base->next_ = prev;
      prev = base;
   }
   *head = prev;
}


/*
 * What:  SumLinkedListReverse(Node* l1, Node* l2)
 *       Reverse numbers represented by l1 and l2.
 *       123 + 456, l1 = 3->2->1 and l2 = 6->5->4
 *       Return l1 and l2 that is 579
 * How: Till both not null add l1->data and l2->data
 *      Carry to also add then store in stack
 *      Pop out stack
 */
int SumLinkedListReverse(Node* l1, Node* l2) {
   stack<int> s;
   int sum = 0, carry = 0;
   while(l1!=nullptr || l2!=nullptr) {
      sum = carry;
      carry = 0;
      if(l1) {
         sum = l1->data_;
         l1 = l1->next_;
      }
      if(l2) {
         sum += l2->data_;
         l2 = l2->next_;
      }
      if(sum > 9) {
         carry = 1;
         sum = sum % 10;
      }
      s.push(sum);
   }
   s.push(carry);
   sum = 0;
   while(!s.empty()) {
      sum *= 10;
      sum += s.top();
      s.pop();
   }
   return sum;
}

/*
 * What: DistanceFromLoop(Node* node)
 *       Finds distance from start of the loop from head.
 * How: After finding loop using fast and slow pointers
 *       Keep slow pointer to start and progress till meet
 *       # of steps is distance.
 * Side effect: NA
 *
 */
int DistanceFromLoop(Node* head) {
   if(head==nullptr) {
      return 0;
   }
   Node *slow = head, *fast = head;
   // Initialize slow and fast with 1 and 2 jumps
   if(slow) {
      slow = slow->next_;
   } else {
      return 0;
   }
   if(fast->next_) {
      fast = fast->next_->next_;
   } else {
      return 0;
   }
   // Detect loop
   while(slow!=fast) {
      if(slow) {
         slow = slow->next_;
      } else {
         return 0;
      }
      if(fast && fast->next_) {
         fast = fast->next_->next_;
      } else {
         return 0;
      }
   }
   // Find distance from start
   slow = head;
   int k = 0;
   while(slow!=fast) {
      slow = slow->next_;
      fast = fast->next_;
      ++k;
   }
   return k;
}


}


