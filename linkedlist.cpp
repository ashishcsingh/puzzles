/*
 * linkedlist.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: acs
 */

#include "linkedlist.h"
#include "log.h"

#include<iostream>
#include<cctype>
#include<cassert>
#include<stack>
#include<map>
#include<set>
#include<vector>

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
   if (head == nullptr || *head == nullptr) {
      return;
   }
   Node* node = *head;
   std::cout << "Printing nodes :";
   while (node) {
      std::cout << " " << node->data_;
      node = node->next_;
   }
   std::cout << std::endl;
}


/*
 * What: Remove data with val in list
 */
void DeleteVal(Node** head, int val) {
   Node *node = *head, *temp;
   while(node!= nullptr) {
      if(node->next_ && node->next_->data_ == val) {
         temp = node->next_;
         node->next_ = node->next_->next_;
         delete temp;
      }
      node = node->next_;
   }
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
   if (deq_.empty()) {
      if (!enq_.empty()) {
         for (unsigned i = 0; i < enq_.size(); ++i) {
            deq_.push(enq_.top());
            enq_.pop();
         }
      }
   }
   if (!deq_.empty()) {
      int ret = deq_.top();
      deq_.pop();
      return ret;
   }
   cerr << "Queue empty" << endl;
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
   if (!head) {
      return;
   }
   Node* node = head;
   Node* lNode = nullptr;
   Node* gNode = nullptr;
   while (node != nullptr) {
      if (node->data_ < pivot) {
         if (*lt == nullptr) {
            *lt = node;
            lNode = node;
         } else {
            lNode->next_ = node;
            lNode = lNode->next_;
         }
      } else {
         if (*gt == nullptr) {
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
   while (node && node->next_) {
      if (node->next_->data_ == deleteMe) {
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
   if (head == nullptr || *head == nullptr) {
      return;
   }
   Node* node = *head;
   while (node != nullptr) {
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
   if (node == nullptr || node->next_ == nullptr) {
      return false;
   }
   Node* node1 = node;
   Node* node2 = node;
   do {
      if (node2 == nullptr || node2->next_ == nullptr) {
         return false;
      } else {
         node2 = node2->next_->next_;
      }
      node1 = node1->next_;
   } while (node1 != node2);
   return true;
}

/*
 * Allocate two variables in the stack and compare their addresses
 */
bool StackGrowsUp() {
   int a = 5;
   int b = 6;
   if (&a < &b) {
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
   if (a < b) {
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
   if (node == nullptr || node->next_ == nullptr) {
      return nullptr;
   }
   Node* node1 = node;
   Node* node2 = node;
   do {
      if (node2 == nullptr || node2->next_ == nullptr) {
         return node1;
      } else {
         node2 = node2->next_->next_;
      }
      node1 = node1->next_;
   } while (node1 != node2);
   return nullptr;
}

/*
 * What: Length(Node* node)
 *       Returns length
 * How: Iterate till end
 */
int Length(Node* node) {
   int len = 0;
   while (node) {
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
   if (head == nullptr || head->next_ == nullptr) {
      return true;
   }
   Node* first = head;
   Node* second = head;
   stack<int> s;
   do {
      if (second) {
         // Progress
         if (second->next_) {
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
   } while (true);
   // Now check stack with the other half
   while (true) {
      // Positive end condition
      if (first == nullptr && s.empty()) {
         return true;
      }
      // Negative end condition
      if (first == nullptr || s.empty()) {
         return false;
      }
      // Negative condition
      if (s.top() != first->data_) {
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
   if (len1 < len2) {
      for (int i = 0; i < len1; ++i) {
         temp1 = temp1->next_;
      }
      for (int i = 0; i < len2 - len1; ++i) {
         temp1->next_ = new Node(0);
         temp1 = temp1->next_;
      }
   } else if (len1 > len2) {
      for (int i = 0; i < len2; ++i) {
         temp2 = temp2->next_;
      }
      for (int i = 0; i < len1 - len2; ++i) {
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
   if (head == nullptr || *head == nullptr) {
      return;
   }
   Node* node = *head;
   Node *prev = nullptr, *base = nullptr;
   while (node) {
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
   while (l1 != nullptr || l2 != nullptr) {
      sum = carry;
      carry = 0;
      if (l1) {
         sum = l1->data_;
         l1 = l1->next_;
      }
      if (l2) {
         sum += l2->data_;
         l2 = l2->next_;
      }
      if (sum > 9) {
         carry = 1;
         sum = sum % 10;
      }
      s.push(sum);
   }
   s.push(carry);
   sum = 0;
   while (!s.empty()) {
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
   if (head == nullptr) {
      return 0;
   }
   Node *slow = head, *fast = head;
   // Initialize slow and fast with 1 and 2 jumps
   if (slow) {
      slow = slow->next_;
   } else {
      return 0;
   }
   if (fast->next_) {
      fast = fast->next_->next_;
   } else {
      return 0;
   }
   // Detect loop
   while (slow != fast) {
      if (slow) {
         slow = slow->next_;
      } else {
         return 0;
      }
      if (fast && fast->next_) {
         fast = fast->next_->next_;
      } else {
         return 0;
      }
   }
   // Find distance from start
   slow = head;
   int k = 0;
   while (slow != fast) {
      slow = slow->next_;
      fast = fast->next_;
      ++k;
   }
   return k;
}

/*
 * What: Maintain and insert data in sorted way to circular list
 *       List is always circular
 * How:  if first element is bigger than insert the new at the start
 *       else till next data is found bigger loop around
 *       when next is bigger and current is smaller insert
 */
void InsertDataInSortedCircularList(Node** root, int data) {
   Log(VERBOSE,
         "[InsertDataInSortedCircularList] To insert " + to_string(data));
   Node* dataNode = new Node(data);
   // First element when root is null
   if (*root == nullptr) {
      *root = dataNode;
      dataNode->next_ = dataNode;
      Log(VERBOSE,
            "[InsertDataInSortedCircularList] Inserted " + to_string(data)
                  + " at root");
      return;
   }
   // start has bigger values then insert at start
   if ((*root)->data_ >= data) {
      dataNode->next_ = *root;
      (*root)->next_ = dataNode;
      *root = dataNode;
      Log(VERBOSE,
            "[InsertDataInSortedCircularList] Inserted " + to_string(data)
                  + " at start");
      return;
   }
   Node* node = *root;
   while (node != nullptr) {
      // next is bigger than data and current is smaller then insert between
      if (node->next_->data_ >= data) {
         dataNode->next_ = node->next_;
         node->next_ = dataNode;
         Log(VERBOSE,
               "[InsertDataInSortedCircularList] Inserted " + to_string(data)
                     + " between ");
         return;
      } else if (node->next_ == *root) {
         // Insert at the end
         dataNode->next_ = node->next_;
         node->next_ = dataNode;
         Log(VERBOSE,
               "[InsertDataInSortedCircularList] Inserted " + to_string(data)
                     + " at end ");
         return;
      } else {
         node = node->next_;
      }
   }
   Log(ERROR, "[InsertDataInSortedCircularList] Loop not found");
}

/*
 * What: Gets all leaf ids populated in children
 */
void GetAllSubChildren(map<int, vector<int>>& parentChildren, int id,
      set<int>& children) {
   children.insert(id);
   children.insert(parentChildren[id].begin(), parentChildren[id].end());
   Log(VERBOSE, "[GetAllSubChildren] Processing " + to_string(id));
   for (auto i : children) {
      if (parentChildren.count(i) > 0) {
         vector<int>& grandChildren = parentChildren[i];
         for (auto gChild : grandChildren) {
            if (children.count(gChild) == 0) {
               Log(VERBOSE,
                     "[GetAllSubChildren] Processing grand of "
                           + to_string(gChild));
               GetAllSubChildren(parentChildren, gChild, children);
            }
         }
      }
   }
}


/*
 * What: Removes duplicates and retains order.
 * How: Using hash_set maintain existence.
 * Complexity: O(N)
 */
void RemoveDuplicates1(Node *node) {
   unordered_set<int> set;
   if(!node) {
      return;
   }
   while(node) {
      set.insert(node->data_);
      if(node->next_ && set.count(node->next_->data_) > 0) {
         Node *temp = node->next_;
         node->next_ = node->next_->next_;
         delete temp;
      }
      node = node->next_;
   }
}

/*
 * What: Removes duplicates and retains order.
 * How: Without any space.
 * Complexity: O(N2)
 */
void RemoveDuplicates2(Node *node) {
   while(node) {
      Node *runner = node;
      while(runner && runner->next_) {
         if(node->data_ == runner->next_->data_) {
            Node *temp = runner->next_;
            runner->next_ = runner->next_->next_;
            delete temp;
         }
         runner = runner->next_;
      }
      node = node->next_;
   }
}

/*
 * What: PrintSubTreeWeights
 * http://www.careercup.com/question?id=5648527329853440
 * How: Using map<int,vector<int>> build parentChildren hierarchy
 */
void PrintSubTreeWeights(const list<NodeWithWeight>& nodes) {
   // Populate parent to children relation
   Log(VERBOSE,
         "[PrintSubTreeWeights] Nodes with length " + to_string(nodes.size()));
   map<int, vector<int>> parentChildren;
   for (auto& node : nodes) {
      parentChildren[node.parent_].push_back(node.id_);
   }
   Log(VERBOSE,
         "[PrintSubTreeWeights] Map with length "
               + to_string(parentChildren.size()));
   // For each node get all its subtrees' id
   for (auto& node : nodes) {
      set<int> children;
      Log(VERBOSE, "[PrintSubTreeWeights] Getting children"
            " for id " + to_string(node.id_));
      // Getting all children
      GetAllSubChildren(parentChildren, node.id_, children);
      children.insert(node.id_);
      Log(VERBOSE,
            "[PrintSubTreeWeights] Got " + to_string(children.size())
                  + " children"
                        " for id " + to_string(node.id_));
      int weight = 0;
      // Then get weight of each sub children
      for (auto id : children) {
         // Get weight by looping into nodes
         for (auto& nodeI : nodes) {
            if (nodeI.id_ == id) {
               weight += nodeI.weight_;
               Log(VERBOSE,
                     "[PrintSubTreeWeights] Got weight"
                           " for id " + to_string(nodeI.weight_) + " for "
                           + to_string(nodeI.id_));
            }
         }
      }
      cout << "Node : " << node.id_ << " sub-tree weight: " << weight << endl;
   }
}

}

