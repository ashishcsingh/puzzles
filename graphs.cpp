/*
 * graphs.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: acs
 */
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include "graphs.h"

namespace graphs {
using namespace std;

BNode* Bfs(BNode* root, int data) {
   if(root==nullptr) {
      return nullptr;
   }
   queue<BNode*> q;
   q.push(root);
   while(!q.empty()) {
      //progress
      BNode* node = q.front();
      q.pop();
      //perform operation
      if(data == node->data_) {
         cout<<"Found node using Bfs "<<data<<endl;
         return node;
      }
      //Add children
      if(node->left_) {
         q.push(node->left_);
      }
      if(node->right_) {
         q.push(node->right_);
      }
   }
   cout<<"Not found using Bfs "<<data<<endl;
   return nullptr;
}


void BfsPrint(BNode* root) {
   if(root==nullptr) {
      return;
   }
   queue<BNode*> q;
   q.push(root);
   while(!q.empty()) {
      //progress
      BNode* node = q.front();
      q.pop();
      //perform operation
      cout<<" "<<node->data_;
      //Add children
      if(node->left_) {
         q.push(node->left_);
      }
      if(node->right_) {
         q.push(node->right_);
      }
   }
}

void DfsPrint(BNode* root) {
   if(root==nullptr) {
      return;
   }
   stack<BNode*> s;
   s.push(root);
   while(!s.empty()) {
      //progress
      BNode* node = s.top();
      s.pop();
      //perform operation
      cout<<" "<<node->data_;
      //Add children
      if(node->left_) {
         s.push(node->left_);
      }
      if(node->right_) {
         s.push(node->right_);
      }
   }
}


void LevelOrdering(BNode* root) {
   if(root==nullptr) {
      return;
   }
   queue<BNode*> q;
   q.push(root);
   while(!q.empty()) {
      //progress
      int size = q.size();
      for(int i=0; i<size; ++i) {
         BNode* node = q.front();
         q.pop();
         //perform operation
         cout<<node->data_<<" ";
         //Add children
         if(node->left_) {
            q.push(node->left_);
         }
         if(node->right_) {
            q.push(node->right_);
         }
      }
      cout<<endl;
   }

   return;
}



int RightSibling(BNode* root, int data) {
   if(root==nullptr) {
      return -1;
   }
   queue<BNode*> q;
   q.push(root);
   bool printNextData = false;
   while(!q.empty()) {
      //progress
      int size = q.size();
      printNextData = false;
      for(int i=0; i<size; ++i) {
         BNode* node = q.front();
         q.pop();
         //perform operation
         if(printNextData) {
            cout<<"Found next sibling : "<<node->data_;
            return node->data_;
         }
         if(data == node->data_) {
            printNextData = true;
         }
         //Add children
         if(node->left_) {
            q.push(node->left_);
         }
         if(node->right_) {
            q.push(node->right_);
         }
      }
   }

   return -1;
}

BNode* Dfs(BNode* root, int data) {
   if(root == nullptr) {
      return nullptr;
   }
   stack<BNode*> s;
   s.push(root);
   while(!s.empty()) {
      //progress
      BNode* node = s.top();
      s.pop();
      //Do operation
      if(node->data_ == data) {
         cout<<"Found node using DFS "<<data<<endl;
         return node;
      }
      //add children
      if(node->left_) {
         s.push(node->left_);
      }
      if(node->right_) {
         s.push(node->right_);
      }
   }
   cout<<"Not found using Dfs "<<data<<endl;
   return nullptr;
}



DNode* DfsD(DNode* root, int data) {
   if(root == nullptr) {
      return nullptr;
   }
   stack<DNode*> s;
   s.push(root);
   while(!s.empty()) {
      //progress
      DNode* node = s.top();
      s.pop();
      //Do operation
      if(node->data_ == data) {
         cout<<"Found node using DFS "<<data<<endl;
         return node;
      }
      //add children
      if(node->left_) {
         s.push(node->left_);
      }
      if(node->right_) {
         s.push(node->right_);
      }
   }
   cout<<"Not found using Dfs "<<data<<endl;
   return nullptr;
}

void DfsRecursive(BNode* root, int data) {
   if(root==nullptr) {
      return;
   }
   if(root->data_== data) {
      cout<<"Found node using DfsRecursive "<<data<<endl;
   }
   DfsRecursive(root->left_, data);
   DfsRecursive(root->right_, data);
}

void Insert(BNode** root, int data) {
   if(*root == nullptr) {
      *root = new BNode(data);
   } else {
      BNode* bnode = *root;
      BNode* dataNode = new BNode(data);
      while(1) {
         if(bnode->data_ > data) {
            if(bnode->left_) {
               bnode = bnode->left_;
            } else {
               bnode->left_ = dataNode;
               break;
            }
         } else {
            if(bnode->right_) {
               bnode = bnode->right_;
            } else {
               bnode->right_ = dataNode;
               break;
            }
         }
      }
   }
}

void InsertD(DNode** root, int data) {
   if(*root == nullptr) {
      *root = new DNode(data);
   } else {
      DNode* dnode = *root;
      DNode* dataNode = new DNode(data);
      while(1) {
         if(dnode->data_ > data) {
            if(dnode->left_) {
               dnode = dnode->left_;
            } else {
               dnode->left_ = dataNode;
               dataNode->parent_ = dnode;
               break;
            }
         } else {
            if(dnode->right_) {
               dnode = dnode->right_;
            } else {
               dnode->right_ = dataNode;
               dataNode->parent_ = dnode;
               break;
            }
         }
      }
   }
}

void PreOrder(BNode* node) {
   if(node) {
      cout<<node->data_<<" ";
      PreOrder(node->left_);
      PreOrder(node->right_);
   }
}

void PostOrder(BNode* node) {
   if(node) {
      PreOrder(node->left_);
      cout<<node->data_<<" ";
      PreOrder(node->right_);
   }
}

void InOrder(BNode* node) {
   if(node) {
      PreOrder(node->left_);
      PreOrder(node->right_);
      cout<<node->data_<<" ";
   }
}


/*
 * Finds the minimum width
 * By comparing the (left path - 1) and (right path + 1)
 */
int MinWidth(BNode* node, int width) {
   if(node == nullptr) {
      return width;
   }
   return min(MinWidth(node->left_, width - 1), MinWidth(node->right_, width + 1));
}

/*
 * Finds the maximum width
 * By comparing the (left path - 1) and (right path + 1)
 */
int MaxWidth(BNode* node, int width) {
   if(node == nullptr) {
      return width;
   }
   return max(MaxWidth(node->right_, width + 1), MaxWidth(node->left_, width - 1));
}

/*
 * Prints the data when currentWidth = printWidth
 * Use InOrder to explore all the nodes.
 */
void PrintWidth(BNode* node, int printWidth, int currentWidth) {
   if(node==nullptr) {
      return;
   }
   PrintWidth(node->left_, printWidth, currentWidth - 1);
   if(printWidth == currentWidth) {
      cout<<" "<<node->data_;
   }
   PrintWidth(node->right_, printWidth, currentWidth + 1);
}

/*
 * Prints vertical Ordering
 *         12
 *        /  \
 *       5    15
 *
 *  Prints:
 *   5  (left most)
 *   12 (center)
 *   15 (right most)
 */
void VerticalOrdering(BNode* node) {
   int minWidth = MinWidth(node, 0);
   int maxWidth = MaxWidth(node, 0);
   for(int i=minWidth; i<=maxWidth; ++i) {
      PrintWidth(node, i, 0);
      cout<<endl;
   }
}

/*
 * Checks if the node leads to a BST
 * If left data is ever greater than parent data
 * Or if right data is ever lesser than parent data
 * return false
 * else return true
 */
bool IsBst(BNode* node) {
   if(node==nullptr) {
      return true;
   }
   if(node->left_) {
      if(node->left_->data_ > node->data_) {
         return false;
      }
   }
   if(node->right_) {
      if(node->right_->data_ < node->data_) {
         return false;
      }
   }
   return IsBst(node->left_) && IsBst(node->right_);
}


/*
 * Computes Height of the tree
 * Max of Height(Left node+1) and Height(right node + 1)
 */
int Height(BNode* node, int height) {
   if(node == nullptr){
      return height;
   }
   return max(Height(node->left_, height+1), Height(node->right_, height + 1));
}

/*
 * Checks of the node is balanced
 * If height difference is more than 1 between left and right
 * Or if left or right is not balanced then return false
 */
bool IsBalanced(BNode* node) {
   if(node==nullptr) {
      return true;
   }
   if((abs(Height(node->left_, 1) - Height(node->right_, 1)) > 1)
         || !IsBalanced(node->left_)
         || !IsBalanced(node->right_)) {
      return false;
   }
   return true;
}

/*
 * Keep traversing through nodes for a and b using binary search.
 * At each node traversal check
 * if it's the same traversal else
 * report the change in traversal node as the LCA.
 */
int Lca(BNode* root, int a, int b) {
   BNode* node = root;
   while(node!=nullptr) {
      if(node->data_ > a && node->data_ > b) {
         node = node->left_;
      } else if(node->data_ < a && node->data_ < b) {
         node = node->right_;
      } else {
         return node->data_;
      }
   }
   return -1;
}

int LengthParentD(DNode* node) {
   int length = 0;
   while(node) {
      length++;
      node=node->parent_;
   }
   return length;
}

/*
 * DNode tree is not a binary search tree.
 * So, use DFS and locate the a and b
 * Traverse back to cover difference in length to root
 * Then traverse again till both point to same node
 */
int LcaD(DNode* root, int a, int b) {
   DNode* aNode = DfsD(root, a);
   DNode* bNode = DfsD(root, b);

   if(!(aNode && bNode)) {
      return -1;
   }

   int lengthA = LengthParentD(aNode);
   int lengthB = LengthParentD(bNode);
   //find the difference in length and cover it
   if(lengthA > lengthB) {
      for(int i=0; i<(lengthA - lengthB); ++i) {
         aNode = aNode->parent_;
      }
   } else {
      for(int i=0; i<(lengthB - lengthA); ++i) {
         bNode = bNode->parent_;
      }
   }
   //Move on till common nodes are found
   while(aNode && bNode && aNode!=bNode) {
      aNode = aNode->parent_;
      bNode = bNode->parent_;
   }
   return aNode->data_;
}

/*
 * forrestStart and lengthForrest define array of root nodes
 * if they are found together in the specified root then find lca
 */
int LcaDForrest(DNode forrestStart[], int forrestLength, int a, int b) {
   for(int i=0; i<forrestLength; ++i) {
      int lca = LcaD(forrestStart+i, a, b);
      if(lca != -1) {
         return lca;
      }
   }
   return -1;
}

/*
 * Recursively inserts center into BinaryTree
 */
void BinarySearchInsertion(BNode** bnodeAddr, int array[], int start, int end) {
   if(start <= end) {
      int center = (start + end)/2;
      cout<<"Inserting "<<array[center]<<endl;
      Insert(bnodeAddr, array[center]);
      if(start == end) {
         return;
      }
      BinarySearchInsertion(bnodeAddr, array, start, center-1);
      BinarySearchInsertion(bnodeAddr, array, center + 1, end);
   }
}

/*
 * Recursively inserts center into BinaryTree
 */
BNode* BinarySearchInsertion2(int array[], int start, int end) {
   if(start <= end) {
      int center = (start + end)/2;
      BNode* bnode = new BNode(array[center]);
      bnode->left_ = BinarySearchInsertion2(array, start, center-1);
      bnode->right_ = BinarySearchInsertion2(array, center + 1, end);
      return bnode;
   }
   return nullptr;
}


/*
 * Sorted array to BST
 */
BNode** SortedArrayToBst2(int array[], int length) {
   BNode** bnodeAddr = new (BNode *);
   *bnodeAddr = BinarySearchInsertion2(array, 0, length-1);
   return bnodeAddr;
}


/*
 * Sorted array to BST
 */
BNode** SortedArrayToBst(int array[], int length) {
   BNode** bnodeAddr = new (BNode *);
   *bnodeAddr = nullptr;
   BinarySearchInsertion(bnodeAddr, array, 0, length-1);
   return bnodeAddr;
}

/*
 * Level Ordering
 * When found data node then set a flag to
 *  immidiately return the next element.
 */
int NextSuccessor(BNode* root, int node) {
   if(root==nullptr) {
      return -1;
   }
   queue<BNode*> q;
   q.push(root);
   bool nextSuccessor = false;
   while(!q.empty()) {
      int size = q.size();
      for(int i=0; i<size; ++i) {
         //transition
         BNode* current = q.front();
         q.pop();
         if(nextSuccessor) {
            return current->data_;
         }
         //operation
         //Setting flag to look for the next data
         if(current->data_ == node) {
            nextSuccessor = true;
         }
         //Explore
         if(current->left_) {
            q.push(current->left_);
         }
         if(current->right_) {
            q.push(current->right_);
         }
      }
   }
   //Representing value not found
   return -1;
}

/*
 * What: Test if tree:ta and tree:tb are same
 * How: if traversal paths and data match for both return true
 */
bool MatchTree(BNode* ta, BNode* tb) {
   if(ta == nullptr && tb == nullptr) {
      return true;
   }
   if (ta==nullptr || tb==nullptr) {
      return false;
   }
   if(ta->data_!= tb->data_) {
      return false;
   } else {
      return (MatchTree(ta->left_, tb->left_) && MatchTree(ta->right_, tb->right_));
   }
}


/*
 * What: Test if parent tree contains child tree
 * How: Test left and right in parent tree for child node
 *      When found match data and then
 *      Explore both the sub tree in the same way
 *      Match left and right for null and value
 */
bool ChildTree(BNode* parent, BNode* child) {
   if(child==nullptr) {
      return true;
   }
   if(parent==nullptr) {
      return false;
   }
   if(parent->data_ == child->data_) {
      if (MatchTree(parent, child)) {
         return true;
      }
   }
   if(ChildTree(parent->left_, child) || ChildTree(parent->right_, child)) {
      return true;
   }
   return false;
}

/*
 * What: Test if in a graph src has a path to dest.
 * How: Use DFS, if a neighbor is dest then return true
 *
 */
bool PathToNodes(GNode* src, GNode* dest) {
   stack<GNode*> s;
   s.push(src);
   set<GNode*> visited;
   while(!s.empty()) {
      // pop
      GNode* node = s.top();
      s.pop();
      // if node is not visited
      if(visited.find(node)==visited.end()) {
         visited.insert(node);
         // explore neighbors
         int i = 0;
         while(i < node->length_) {
            //check if reached destination
            if(node->neighbors_[i] == dest) {
               return true;
            }
            // push non visited children to stack
            if(visited.find(node->neighbors_[i])==visited.end()) {
               s.push(node->neighbors_[i]);
            }
            ++i;
         }
      }
   }
   // not reachable
   return false;
}


}



