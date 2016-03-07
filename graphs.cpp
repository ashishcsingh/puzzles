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
#include <list>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<utility>
#include<climits>

#include "graphs.h"
#include "log.h"

namespace graphs {
using namespace std;

/*
 * What: Bfs
 * How: Explore tree using BFS
 *      Using queue.
 */
BNode* Bfs(BNode* root, int data) {
   if (root == nullptr) {
      return nullptr;
   }
   queue<BNode*> q;
   q.push(root);
   while (!q.empty()) {
      //progress
      BNode* node = q.front();
      q.pop();
      //perform operation
      if (data == node->data_) {
         cout << "Found node using Bfs " << data << endl;
         return node;
      }
      //Add children
      if (node->left_) {
         q.push(node->left_);
      }
      if (node->right_) {
         q.push(node->right_);
      }
   }
   cout << "Not found using Bfs " << data << endl;
   return nullptr;
}

/*
 * What: RotateTree()
 * How: Rotates tree from right to left.
 * Input
          (0)
          / \
         /   \
       (1)     (2)
       / \     / \
     (3) (4) (5) (6)


    Output
             (0)
             / \
            /   \
          (2)     (1)
          / \     / \
        (6) (5) (4) (3)
 */
void RotateTree(BNode* node) {
   if (node == nullptr) {
      return;
   }
   stack<BNode*> s;
   s.push(node);
   while (!s.empty()) {
      // take out top.
      BNode* cur = s.top();
      s.pop();
      // swap left and right
      if (cur != nullptr) {
         swap(cur->left_, cur->right_);
         s.push(cur->left_);
         s.push(cur->right_);
      }
   }
}

/*
 * What: Heapify()
 * How: The largest element traverses to top
 *      by comparing all sub parents to its two children
 *      All the way up.
 */
void Heapify(int data[], int length) {
   for (int i = length / 2; i >= 1; --i) {
      if (data[i - 1] < data[2 * i - 1]) {
         swap(data[i - 1], data[2 * i - 1]);
      }
      if ((i % 2) && data[i - 1] < data[2 * i]) {
         swap(data[i - 1], data[2 * i]);
      }
   }
}

/*
 * What: HeapSort()
 * How: Heapify() for N to 2
 *      Keep swapping the largest elem to last
 */
void HeapSort(int data[], int length) {
   for (int i = length - 1; i > 0; --i) {
      Heapify(data, i + 1);
      swap(data[0], data[i]);
   }
}

void BfsPrint(BNode* root) {
   if (root == nullptr) {
      return;
   }
   queue<BNode*> q;
   q.push(root);
   while (!q.empty()) {
      //progress
      BNode* node = q.front();
      q.pop();
      //perform operation
      cout << " " << node->data_;
      //Add children
      if (node->left_) {
         q.push(node->left_);
      }
      if (node->right_) {
         q.push(node->right_);
      }
   }
}

/*
 * What: Serialize a graph with string data
 * How: Assign an id and parent id.
 *      Traverse tree using DFS
 *      Keep assigning a new id to the current node and set
 *      parentId as the parent's id. Use map to identify parents.
 *
 */
void Serialize(SerializeNode* root, vector<SerializedNode>& snodes) {
   if (root == nullptr) {
      return;
   }
   cout << "Test input " << root->string << " -> " << root->child[0]->string
         << " -> " << root->child[0]->child[0]->string << endl;
   // Maps ids for parent linking.
   std::map<SerializeNode*, int> smap;
   SerializedNode snode;
   // root's parent is 0.
   int sequencer = 0;
   int parentSequence = sequencer;
   snode.parent = parentSequence;
   // node/root's id starts with 1.
   snode.id = ++sequencer;
   snode.string = root->string;
   // storing for linking parentId.
   smap[root] = snode.id;
   stack<SerializeNode*> s;
   snodes.push_back(snode);
   s.push(root);
   while (!s.empty()) {
      SerializeNode* node = s.top();
      s.pop();
      parentSequence = smap[node];
      // Explore all children and add to serialized;
      for (auto child : node->child) {
         snode.parent = parentSequence;
         snode.id = ++sequencer;
         snode.string = child->string;
         smap[child] = snode.id;
         snodes.push_back(snode);
         s.push(child);
      }
   }
   for (auto n : snodes) {
      Log(VERBOSE, "[Serialize] string " + n.string);
      Log(VERBOSE, "[Serialize] id " + to_string(n.id));
      Log(VERBOSE, "[Serialize] parent " + to_string(n.parent));
   }
}

/*
 * What: Deserialize
 * How:  Load into a map
 *       While traversing vector<SerializedNode>
 *       keep on referring parent to add a child node.
 */
SerializeNode* Deserialize(vector<SerializedNode>& snodes) {
   map<int, SerializeNode*> smap;
   SerializeNode* root = nullptr;
   for (auto snode : snodes) {
      if (smap.count(snode.id) == 0) {
         Log(VERBOSE, "[Deserialize] string " + snode.string);
         Log(VERBOSE, "[Deserialize] id " + to_string(snode.id));
         Log(VERBOSE, "[Deserialize] parent " + to_string(snode.parent));
         SerializeNode* node = new SerializeNode();
         node->string = snode.string;
         smap[snode.id] = node;
      }
   }
   for (auto snode : snodes) {
      if (snode.parent == 0) {
         root = smap[snode.id];
         continue;
      }
      smap[snode.parent]->child.push_back(smap[snode.id]);
   }
   return root;
}

void DfsPrint(BNode* root) {
   if (root == nullptr) {
      return;
   }
   stack<BNode*> s;
   s.push(root);
   while (!s.empty()) {
      //progress
      BNode* node = s.top();
      s.pop();
      //perform operation
      cout << " " << node->data_;
      //Add children
      if (node->left_) {
         s.push(node->left_);
      }
      if (node->right_) {
         s.push(node->right_);
      }
   }
}

void LevelOrdering(BNode* root) {
   if (root == nullptr) {
      return;
   }
   queue<BNode*> q;
   q.push(root);
   while (!q.empty()) {
      //progress
      int size = q.size();
      for (int i = 0; i < size; ++i) {
         BNode* node = q.front();
         q.pop();
         //perform operation
         cout << node->data_ << " ";
         //Add children
         if (node->left_) {
            q.push(node->left_);
         }
         if (node->right_) {
            q.push(node->right_);
         }
      }
      cout << endl;
   }

   return;
}

int RightSibling(BNode* root, int data) {
   if (root == nullptr) {
      return -1;
   }
   queue<BNode*> q;
   q.push(root);
   bool printNextData = false;
   while (!q.empty()) {
      //progress
      int size = q.size();
      printNextData = false;
      for (int i = 0; i < size; ++i) {
         BNode* node = q.front();
         q.pop();
         //perform operation
         if (printNextData) {
            cout << "Found next sibling : " << node->data_;
            return node->data_;
         }
         if (data == node->data_) {
            printNextData = true;
         }
         //Add children
         if (node->left_) {
            q.push(node->left_);
         }
         if (node->right_) {
            q.push(node->right_);
         }
      }
   }

   return -1;
}

BNode* Dfs(BNode* root, int data) {
   if (root == nullptr) {
      return nullptr;
   }
   stack<BNode*> s;
   s.push(root);
   while (!s.empty()) {
      //progress
      BNode* node = s.top();
      s.pop();
      //Do operation
      if (node->data_ == data) {
         cout << "Found node using DFS " << data << endl;
         return node;
      }
      //add children
      if (node->left_) {
         s.push(node->left_);
      }
      if (node->right_) {
         s.push(node->right_);
      }
   }
   cout << "Not found using Dfs " << data << endl;
   return nullptr;
}

DNode* DfsD(DNode* root, int data) {
   if (root == nullptr) {
      return nullptr;
   }
   stack<DNode*> s;
   s.push(root);
   while (!s.empty()) {
      //progress
      DNode* node = s.top();
      s.pop();
      //Do operation
      if (node->data_ == data) {
         cout << "Found node using DFS " << data << endl;
         return node;
      }
      //add children
      if (node->left_) {
         s.push(node->left_);
      }
      if (node->right_) {
         s.push(node->right_);
      }
   }
   cout << "Not found using Dfs " << data << endl;
   return nullptr;
}

void DfsRecursive(BNode* root, int data) {
   if (root == nullptr) {
      return;
   }
   if (root->data_ == data) {
      cout << "Found node using DfsRecursive " << data << endl;
   }
   DfsRecursive(root->left_, data);
   DfsRecursive(root->right_, data);
}

void Insert(BNode** root, int data) {
   if (*root == nullptr) {
      *root = new BNode(data);
   } else {
      BNode* bnode = *root;
      BNode* dataNode = new BNode(data);
      while (1) {
         if (bnode->data_ > data) {
            if (bnode->left_) {
               bnode = bnode->left_;
            } else {
               bnode->left_ = dataNode;
               break;
            }
         } else {
            if (bnode->right_) {
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
   if (*root == nullptr) {
      *root = new DNode(data);
   } else {
      DNode* dnode = *root;
      DNode* dataNode = new DNode(data);
      while (1) {
         if (dnode->data_ > data) {
            if (dnode->left_) {
               dnode = dnode->left_;
            } else {
               dnode->left_ = dataNode;
               dataNode->parent_ = dnode;
               break;
            }
         } else {
            if (dnode->right_) {
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
   if (node) {
      cout << node->data_ << " ";
      PreOrder(node->left_);
      PreOrder(node->right_);
   }
}

void InOrder(BNode* node) {
   if (node) {
      InOrder(node->left_);
      cout << node->data_ << " ";
      InOrder(node->right_);
   }
}

void PostOrder(BNode* node) {
   if (node) {
      PostOrder(node->left_);
      PostOrder(node->right_);
      cout << node->data_ << " ";
   }
}

/*
 * What: IsSameTree
 * How: Base case:
 *      Null or both children null return true
 *      If left or right has different data then root
 *          then return false.
 *      return AND of left and right recursion
 */
bool IsSameTree(BNode* node) {
   if (!node || (!node->left_ && !node->right_)) {
      return true;
   }
   if (node->left_ && (node->data_ != node->left_->data_)) {
      return false;
   }
   if (node->right_ && (node->data_ != node->right_->data_)) {
      return false;
   }
   return IsSameTree(node->left_) && IsSameTree(node->right_);
}

/*
 * Finds the minimum width
 * By comparing the (left path - 1) and (right path + 1)
 */
int MinWidth(BNode* node, int width) {
   if (node == nullptr) {
      return width;
   }
   return min(MinWidth(node->left_, width - 1),
         MinWidth(node->right_, width + 1));
}

/*
 * Finds the maximum width
 * By comparing the (left path - 1) and (right path + 1)
 */
int MaxWidth(BNode* node, int width) {
   if (node == nullptr) {
      return width;
   }
   return max(MaxWidth(node->right_, width + 1),
         MaxWidth(node->left_, width - 1));
}

/*
 * Prints the data when currentWidth = printWidth
 * Use InOrder to explore all the nodes.
 */
void PrintWidth(BNode* node, int printWidth, int currentWidth) {
   if (node == nullptr) {
      return;
   }
   PrintWidth(node->left_, printWidth, currentWidth - 1);
   if (printWidth == currentWidth) {
      cout << " " << node->data_;
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
   for (int i = minWidth; i <= maxWidth; ++i) {
      PrintWidth(node, i, 0);
      cout << endl;
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
   if (node == nullptr) {
      return true;
   }
   if (node->left_) {
      if (node->left_->data_ > node->data_) {
         return false;
      }
   }
   if (node->right_) {
      if (node->right_->data_ < node->data_) {
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
   if (node == nullptr) {
      return height;
   }
   return max(Height(node->left_, height + 1), Height(node->right_, height + 1));
}

/*
 * Checks of the node is balanced
 * If height difference is more than 1 between left and right
 * Or if left or right is not balanced then return false
 */
bool IsBalanced(BNode* node) {
   if (node == nullptr) {
      return true;
   }
   if ((abs(Height(node->left_, 1) - Height(node->right_, 1)) > 1)
         || !IsBalanced(node->left_) || !IsBalanced(node->right_)) {
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
   while (node != nullptr) {
      if (node->data_ > a && node->data_ > b) {
         node = node->left_;
      } else if (node->data_ < a && node->data_ < b) {
         node = node->right_;
      } else {
         return node->data_;
      }
   }
   return -1;
}

int LengthParentD(DNode* node) {
   int length = 0;
   while (node) {
      length++;
      node = node->parent_;
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

   if (!(aNode && bNode)) {
      return -1;
   }

   int lengthA = LengthParentD(aNode);
   int lengthB = LengthParentD(bNode);
   //find the difference in length and cover it
   if (lengthA > lengthB) {
      for (int i = 0; i < (lengthA - lengthB); ++i) {
         aNode = aNode->parent_;
      }
   } else {
      for (int i = 0; i < (lengthB - lengthA); ++i) {
         bNode = bNode->parent_;
      }
   }
   //Move on till common nodes are found
   while (aNode && bNode && aNode != bNode) {
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
   for (int i = 0; i < forrestLength; ++i) {
      int lca = LcaD(forrestStart + i, a, b);
      if (lca != -1) {
         return lca;
      }
   }
   return -1;
}

/*
 * Recursively inserts center into BinaryTree
 */
void BinarySearchInsertion(BNode** bnodeAddr, int array[], int start, int end) {
   if (start <= end) {
      int center = (start + end) / 2;
      cout << "Inserting " << array[center] << endl;
      Insert(bnodeAddr, array[center]);
      if (start == end) {
         return;
      }
      BinarySearchInsertion(bnodeAddr, array, start, center - 1);
      BinarySearchInsertion(bnodeAddr, array, center + 1, end);
   }
}

/*
 * Recursively inserts center into BinaryTree
 */
BNode* BinarySearchInsertion2(int array[], int start, int end) {
   if (start <= end) {
      int center = (start + end) / 2;
      BNode* bnode = new BNode(array[center]);
      bnode->left_ = BinarySearchInsertion2(array, start, center - 1);
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
   *bnodeAddr = BinarySearchInsertion2(array, 0, length - 1);
   return bnodeAddr;
}

/*
 * Sorted array to BST
 */
BNode** SortedArrayToBst(int array[], int length) {
   BNode** bnodeAddr = new (BNode *);
   *bnodeAddr = nullptr;
   BinarySearchInsertion(bnodeAddr, array, 0, length - 1);
   return bnodeAddr;
}

/*
 * Level Ordering
 * When found data node then set a flag to
 *  immidiately return the next element.
 */
int NextSuccessor(BNode* root, int node) {
   if (root == nullptr) {
      return -1;
   }
   queue<BNode*> q;
   q.push(root);
   bool nextSuccessor = false;
   while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
         //transition
         BNode* current = q.front();
         q.pop();
         if (nextSuccessor) {
            return current->data_;
         }
         //operation
         //Setting flag to look for the next data
         if (current->data_ == node) {
            nextSuccessor = true;
         }
         //Explore
         if (current->left_) {
            q.push(current->left_);
         }
         if (current->right_) {
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
   if (ta == nullptr && tb == nullptr) {
      return true;
   }
   if (ta == nullptr || tb == nullptr) {
      return false;
   }
   if (ta->data_ != tb->data_) {
      return false;
   } else {
      return (MatchTree(ta->left_, tb->left_)
            && MatchTree(ta->right_, tb->right_));
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
   if (child == nullptr) {
      return true;
   }
   if (parent == nullptr) {
      return false;
   }
   if (parent->data_ == child->data_) {
      if (MatchTree(parent, child)) {
         return true;
      }
   }
   if (ChildTree(parent->left_, child) || ChildTree(parent->right_, child)) {
      return true;
   }
   return false;
}

/*
 * What: If all the nodes are at the same place for both the trees
 * How:
 */
bool MatchTree2(BNode* parent, BNode* child) {
   if (parent == nullptr && child == nullptr) {
      return true;
   }
   if (parent == nullptr || child == nullptr) {
      return false;
   }
   if (parent->data_ == child->data_) {
      return MatchTree2(parent->left_, child->left_)
            && MatchTree2(parent->right_, child->right_);
   }
   return false;
}

/*
 * What: Checks if the parent Tree contains Child Tree
 * How:  compare parent's current data with child
 *       return exact match
 *       else recursively call for left and right
 */
bool ChildTree2(BNode* parent, BNode* child) {
   if (child == nullptr) {
      return true;
   }
   if (parent == nullptr) {
      return false;
   }
   if (parent->data_ == child->data_) {
      return MatchTree(parent, child);
   }
   return ChildTree2(parent->left_, child) || ChildTree2(parent->right_, child);
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
   while (!s.empty()) {
      // pop
      GNode* node = s.top();
      s.pop();
      // if node is not visited
      if (visited.find(node) == visited.end()) {
         visited.insert(node);
         // explore neighbors
         int i = 0;
         while (i < node->length_) {
            //check if reached destination
            if (node->neighbors_[i] == dest) {
               return true;
            }
            // push non visited children to stack
            if (visited.find(node->neighbors_[i]) == visited.end()) {
               s.push(node->neighbors_[i]);
            }
            ++i;
         }
      }
   }
   // not reachable
   return false;
}

/*
 * What: In between start and end find count of nodes
 * How:  think leaf node, count is if current data is in range.
 *       Then a node with only one left node.
 *       currentNode + leftNode;
 *       similarly current + leftNode + rightNode
 */
int CountNodesInBST(BNode* root, int start, int end) {
   if (root == nullptr) {
      return 0;
   }
   int count = 0;
   if (root->data_ >= start && root->data_ <= end) {
      count++;
   }
   count += CountNodesInBST(root->left_, start, end)
         + CountNodesInBST(root->right_, start, end);
   return count;
}

/* What: Finds the shortest path from src to dest nodes
 *       weights contain adjencency matrix with weights
 *       For not connected nodes add high cost
 * How:  distance[] and previous[] maintains the cost to move from source
 *       previous nodes details.
 *       Take out unvisited node from src with lowest distance cost
 *       update distance[] and previous[] for any traversal via a neighbor node
 *       Keep exploring till you visited all the nodes
 *       When computing path from dest node in previous[],
 *       keep exploring all the nodes till source
 *       Reverse the constructed path
 */
std::vector<int> ShortestPathDjkstras(std::vector<std::vector<int>>& weights,
      int src, int dest) {
   // Initialize weights, previous and distance
   int length = weights.size();
   vector<int> distance(length, INT_MAX), previous(length, -1);
   list<int> unvisited;
   unvisited.push_back(src);
   distance[src] = 0;
   for (int v = 0; v < length; ++v) {
      unvisited.push_back(v);
   }
   // Algorithm
   while (!unvisited.empty()) {
      // Find the closest node
      int min = INT_MAX, u = -1, v;
      for (auto v : unvisited) {
         if (min > distance[v]) {
            min = distance[v];
            u = v;
         }
      }
      // Update distance cost
      for (v = 0; v < length; ++v) {
         int distUToV = distance[u] + weights[u][v];
         if (distance[v] > distUToV) {
            previous[v] = u;
            distance[v] = distUToV;
         }
      }
      unvisited.remove(u);
   }
   // Get path from previous array
   vector<int> path;
   int prev = dest;
   for (int i = 0; i < length; ++i) {
      path.push_back(prev);
      if (prev == src) {
         break;
      }
      prev = previous[prev];
   }
   // Reverse path
   int i = 0, j = path.size() - 1;
   while (i < j) {
      swap(path[i], path[j]);
      ++i;
      --j;
   }
   return path;
}

vector<int> dfs(const int& contact,
      unordered_map<string, vector<int>>& mapEmailContacts,
      unordered_map<int, vector<string>>& mapContactEmails,
      unordered_set<int>& unvisited) {
   vector<int> connectedContacts;
   unordered_set<int> contactSet;
   stack<int> s;
   s.push(contact);
   while (!s.empty()) {
      int current = s.top();
      s.pop();
      // remove the current from unvisited.
      unvisited.erase(current);
      connectedContacts.push_back(current);
      //find all the connected.
      for (auto& email : mapContactEmails[current]) {
         for (auto& c : mapEmailContacts[email]) {
            // Get rid of duplicates.
            if (unvisited.count(c) > 0) {
               contactSet.insert(c);
            }
         }
      }
      // Get rid of duplicates.
      for(auto c: contactSet) {
         s.push(c);
      }
      contactSet.clear();
   }
   return connectedContacts;
}

/*
 * What: Merges contacts by common emails.
 * How: Using DFS to traverse common email across two contacts.
 */
vector<vector<int>> Dedupe(vector<pair<int, vector<string>>>& contacts) {
   // prepare maps.
   unordered_map<int, vector<string>> mapContactEmails;
   unordered_map<string, vector<int>> mapEmailContacts;
   for(auto& c : contacts) {
      for(auto& email : c.second) {
         mapContactEmails[c.first].push_back(email);
         mapEmailContacts[email].push_back(c.first);
      }
   }
   // add unvisited.
   unordered_set<int> unvisited;
   for(auto& c:mapContactEmails) {
      unvisited.insert(c.first);
   }
   vector<vector<int>> output;
   while(!unvisited.empty()) {
      auto connectedContacts = move(
      dfs(*unvisited.begin(), mapEmailContacts,
            mapContactEmails, unvisited));
      output.push_back(connectedContacts);
   }
   return output;
}

void InOrderIterator::recurseLeft(BNode* BNode) {
   if (!BNode) {
      return;
   }
   stack_.push(BNode);
   recurseLeft(BNode->left_);
}

/*
 * Push current and all elems on left to stack.
 */
InOrderIterator::InOrderIterator(BNode* BNode) {
   recurseLeft(BNode);
}

/*
 * Recursively traverse to-pop right element.
 */
BNode* InOrderIterator::Next() {
   if (stack_.size() == 0) {
      return nullptr;
   }
   BNode* cur = stack_.top();
   stack_.pop();
   recurseLeft(cur->right_);
   return cur;
}

/*
 * What: Clones graph
 * How: Copies all vertex(s)
 *      And then copies all edges
 */
Graph* CloneGraph(Graph& src) {
   std::unordered_map<Vertex*, Vertex*> map;
   Graph *dst = new Graph;
   for (auto& v : src.vertices_) {
      Vertex *newV = new Vertex(v->id_);
      map[v] = newV;
      dst->vertices_.push_back(newV);
   }
   for (auto& srcV : src.vertices_) {
      for (auto& srcE : srcV->edges_) {
         map[srcV]->edges_.push_back(map[srcE]);
      }
   }
   return dst;
}

/*
 *  What: Prints path to leaf node
 *  How: Using DFS keep pushing current node.
 *       When found leaf then print paths from passed parm.
 *       Pop current node when done covering left and right nodes.
 */
void PrintPathToNode(Node *head, list<Node*>& path) {
   // Base condition.
   if (!head) {
      return;
   }
   // Push the current node before printing.
   path.push_back(head);
   // Leaf condition.
   if (!head->left && !head->right) {
      for (auto& n : path) {
         cout << n->data;
      }
      cout << endl;
      return;
   }
   // Using DFS.
   PrintPathToNode(head->left, path);
   PrintPathToNode(head->right, path);
   // Need to pop out the current element.
   path.pop_back();
}

/*
 * What: Resolves dependencies between strings.
 *       A - > null
 *       B -> A
 *       C -> B
 *       Then C is dependent on A and B
 * How: First :  In an unodered_set keep populating all direct dependencies.
 *      Second:  Keep placing all direct dependencies
 *      Complexity : O(N2)
 */
DependencyResolver::DependencyResolver(
      const unordered_map<string, vector<string>>& data) {
   // First iteration to store all dependencies as is.
   for (const auto& d : data) {
      dependencies_[d.first].insert(d.second.begin(), d.second.end());
   }
   // Get all dependencies and insert its deep dependencies.
   for (auto& c : dependencies_) {
      unordered_set<string> extra;
      for (auto cdeps : c.second) {
         extra.insert(dependencies_[cdeps].begin(), dependencies_[cdeps].end());
      }
      c.second.insert(extra.begin(), extra.end());
   }
}

const unordered_set<string>& DependencyResolver::GetDependencies(
      const string& component) {
   return dependencies_[component];
}

bool VNode::IsChild(VNode* child) {
   stack<VNode*> s;
   unordered_set<VNode*> visited;
   s.push(this);
   visited.insert(this);
   while (!s.empty()) {
      VNode* cur = s.top();
      s.pop();
      // Unvisited inserted into stack.
      for (auto e : cur->edges) {
         if (e->id == child->id) {
            return true;
         }
         if (visited.insert(e).second) {
            s.push(e);
         }
      }
   }
   return false;
}
/*
 * What: Gets common ancestor in a binary tree.
 * How:  Capture path to nodes and then find the
 *       common element.
 */
char CommonAncestor::GetCommonAncestor(char data1, char data2) {
   list<char> path;
   data1_ = data1;
   data2_ = data2;
   GetPath(root_, path);
   return LastCommonElem(path1_, path2_);
}

/*
 * What: Captures when the last element differs.
 * How:  Proceed by saving the common element till
 *       it differs.
 */
char CommonAncestor::LastCommonElem(std::list<char>& path1,
      std::list<char>& path2) {
   auto itr1 = path1.begin();
   auto itr2 = path2.begin();
   char result = -1;
   for (; itr1 != path1.end() && itr2 != path2.end(); ++itr1, ++itr2) {
      if (*itr1 == *itr2) {
         result = *itr1;
      } else {
         break;
      }
   }
   return result;
}

/*
 * What: Capture paths to path1_ and path2_
 *       for data1 and data2.
 * How:  Keep traversing left and right when done
 *       pop out the current elem from path on stack.
 */
void CommonAncestor::GetPath(Node* node, list<char>& path) {
   if (node == nullptr) {
      return;
   }
   if (node->data == data1_) {
      path1_ = path;
   }
   if (node->data == data2_) {
      path2_ = path;
   }
   if (path1_.size() > 0 && path2_.size() > 0) {
      return;
   }
   path.push_back(node->data);
   GetPath(node->left, path);
   GetPath(node->right, path);
   path.pop_back();
}

/*
 * What: States and their connection represents String graph.
 *       Find the longest valid word that can be made from the
 *       connecting state names.
 * How:  Two class, one meant for capturing state name.
 *       second for map with all states and dictionary for valid names.
 *       It takes already made states and words.
 *       Base condition: When state name matches the request return true.
 *       Progression: sub-string of states and children checked for a match.
 */
StateNode::StateNode(const string& name) {
   name_ = name;
}

void StateNode::AddConnection(StateNode* conn) {
   connections_.push_back(conn);
}

/*
 * What: return length of matched string with state name.
 * How: length being the upper bound returned total matched chars.
 */
unsigned StateNode::MatchLength(const string& match) {
   unsigned i = 0;
   if (match.length() == 0 || name_.length() == 0) {
      return 0;
   }
   while (i < match.length() && match[i] == name_[i]) {
      ++i;
   }
   return i;
}

vector<StateNode*>& StateNode::GetConnections() {
   return connections_;
}

const string& StateNode::GetName() {
   return name_;
}

MapGraph::MapGraph(vector<StateNode*>& states, vector<string>& dict) :
      states_(states), dict_(dict) {
}

/*
 * What: If state and connections can make up the word.
 * How: Check substr and its connections.
 */
bool MapGraph::ExistsStartingState(StateNode* state, const string& word) {
   unsigned matchedLen = state->MatchLength(word);
   if (matchedLen == word.length()) {
      return true;
   }
   for (unsigned i = 1; i <= matchedLen; ++i) {
      string leftWord = word.substr(i);
      for (auto conn : state->GetConnections()) {
         if (ExistsStartingState(conn, leftWord)) {
            return true;
         }
      }
   }
   return false;
}

bool MapGraph::ExistsAllStates(const string& word) {
   for (auto state : states_) {
      if (ExistsStartingState(state, word)) {
         return true;
      }
   }
   return false;
}

string MapGraph::FindLongestWord() {
   string longestWord;
   unsigned max = 0;
   for (auto word : dict_) {
      if (max < word.length() && ExistsAllStates(word)) {
         if (max < word.length()) {
            max = word.length();
            longestWord = word;
         }
      }
   }
   return longestWord;
}

/*
 * What: FlipLevelOrdering
 *
 *
 *         A                <-
 *		 B        C            ->
 *  D     E       G            <-
 *    H   I J     K            ->
 *  OUTPUT: A, B, C, G, E, D, H, I, J, K
 *
 */
void FlipLevelOrdering(Node *root) {
   if (root == nullptr) {
      return;
   }
   queue<Node*> q;
   q.push(root);
   vector<char> v;
   bool flip = false;
   while (!q.empty()) {
      // Capture the size outside the loop.
      int size = q.size();
      v.clear();
      for (int i = 0; i < size; ++i) {
         Node *node = q.front();
         q.pop();
         v.push_back(node->data);
         if (node->left) {
            q.push(node->left);
         }
         if (node->right) {
            q.push(node->right);
         }
      }
      // Flip directions.
      if (flip) {
         flip = false;
         for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
         }
         cout << endl;
      } else {
         // Reverse order.
         flip = true;
         for (int i = v.size() - 1; i >= 0; --i) {
            cout << v[i] << " ";
         }
         cout << endl;
      }
   }
}

/*
 * What: Finds the longest path from root.
 * How: Pushing and poping path and checking max length.
 */
void MaxLengthPath(NodeInt *node, list<NodeInt*>& maxPath, list<NodeInt*>& path, unsigned& maxPathLen) {
  if(!node) {
    return;
  }
  path.push_back(node);
  if(path.size() > maxPathLen) {
    maxPathLen = path.size();
    maxPath = path;
  }
  MaxLengthPath(node->left, maxPath, path, maxPathLen);
  MaxLengthPath(node->right, maxPath, path, maxPathLen);
  path.pop_back();
}


/*
 * What: Gets all paths from root to leaf.
 * How: Push and pop and detect and copy path to allPaths.
 */
void GetAllPaths(NodeInt *NodeInt, list<int>& path, list<list<int>>& allPaths) {
   if(!NodeInt) {
      return;
   }
   path.push_back(NodeInt->data);
   if(NodeInt->left == nullptr && NodeInt->right == nullptr) {
      allPaths.push_back(path);
      // Debug.
      for(auto& n : path) {
         cout<<n<<" ";
      }
      cout<<endl;
   }
   GetAllPaths(NodeInt->left, path, allPaths);
   GetAllPaths(NodeInt->right, path, allPaths);
   path.pop_back();
}

/*
 * What: Get all sums of all paths.
 */
int GetSumAllPaths(NodeInt *root) {
   list<int> path;
   list<list<int>> allPaths;
   GetAllPaths(root, path, allPaths);
   int lSum = 0, gSum = 0, ten = 1;
   for(auto& p : allPaths) {
      lSum = 0;
      ten = 1;
      for(auto& n: p) {
         lSum *= 10;
         lSum += n;
      }
      gSum += lSum;
   }
   return gSum;
}


/*
 * What: Sets alignment in cache (int, vector<Node*>)
 * How: Using BFS and hashmap to track width moves from left to right.
 */
void SetAlignment(NodeInt *root, unordered_map<int, vector<int>>& cache,
      int& minAligned, int& maxAligned) {
   if(!root) {
      return;
   }
   queue<NodeInt*> q;
   unordered_map<NodeInt*, int> alignMap;
   q.push(root);
   alignMap[root] = 0;
   while(!q.empty()) {
      NodeInt* node = q.front();
      q.pop();
      // Store nodes in reference to width.
      cache[alignMap[node]].push_back(node->data);
      // Also store min and max here.
      minAligned = min(minAligned, alignMap[node]);
      maxAligned = max(maxAligned, alignMap[node]);
      if(node->left) {
         q.push(node->left);
         alignMap[node->left] = alignMap[node] - 1;
      }
      if(node->right) {
         q.push(node->right);
         alignMap[node->right] = alignMap[node] + 1;
      }
   }
}

/*
 * What: Prints tree from leftmost width to right most width.
 * How: Using BFS and hashmap to track width moves from left to right.
 */
void PrintTreeHorizontal(NodeInt *root) {
   unordered_map<int, vector<int>> cache;
   int minAligned = 0, maxAligned = 0;
   SetAlignment(root, cache, minAligned, maxAligned);
   for(int i=minAligned; i<=maxAligned; ++i) {
      for(auto& n: cache[i]) {
         cout<<n<<" ";
      }
   }
}


/*
 * What: Sets the content in matrix using alignment hashmap.
 */
void SetAlignment(NodeInt *root, vector<vector<int>>& matrix, int height) {
   if(!root) {
      return;
   }
   queue<NodeInt*> q;
   unordered_map<NodeInt*, pair<int,int>> alignMap;
   q.push(root);
   // Alignment stores (x, y).
   // matrix stores [Y rows][X cols]
   alignMap[root] = make_pair(height, 0);
   while(!q.empty()) {
      NodeInt* node = q.front();
      q.pop();
      // Store the current loc (x, y)
      matrix[alignMap[node].second][alignMap[node].first] = node->data;
      if(node->left) {
         q.push(node->left);
         alignMap[node->left].first = alignMap[node].first - 1;
         alignMap[node->left].second = alignMap[node].second + 1;
      }
      if(node->right) {
         q.push(node->right);
         alignMap[node->right].first = alignMap[node].first + 1;
         alignMap[node->right].second = alignMap[node].second + 1;
      }
   }
}

/*
 * What: Gets the height of a tree.
 */
int GetHeightTree(NodeInt *node, int height) {
   if(!node) {
      return height;
   }
   return max(GetHeightTree(node->left, height + 1), GetHeightTree(node->right,
            height + 1));
}


/*
 * What: Prints the tree by considering its relative positions.
 * Tree height: 3
 *   1
 *  2 3
 * 4 6 7
 */
void PrintTree(NodeInt *root) {
   int height = GetHeightTree(root, 0);
   cout<<"Tree height: "<<height<<endl;
   vector<vector<int>> matrix;
   for(int i=0; i<height; ++i) {
      vector<int> row(height * 2, INT_MAX);
      matrix.push_back(move(row));
   }
   SetAlignment(root, matrix, height);
   for(int i = 0; i<height; ++i) {
      for(int j = 0; j<height * 2; ++j) {
         if(matrix[i][j] == INT_MAX) {
            cout<<" ";
         } else {
            cout<<matrix[i][j];
         }
      }
      cout<<endl;
   }
}

}

