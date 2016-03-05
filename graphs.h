/*
 * graphs.h
 *
 *  Created on: Feb 28, 2015
 *      Author: acs
 */

#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>
#include <string>
#include <stack>
#include <memory>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace graphs {

struct BNode {
   BNode* left_ { nullptr };
   BNode* right_ { nullptr };
   int data_ { 0 };
   BNode(int data) :
         data_ { data } {
   }
   ;
};

struct Node {
   Node *left { nullptr }, *right { nullptr };
   char data;
   Node(char c) :
         data(c) {
   }
};

struct NodeInt {
   NodeInt *left, *right;
  int data;
  NodeInt(int data=0, NodeInt *left=nullptr, NodeInt *right=nullptr)
  : left(left), right(right), data(data){}
};

void RotateTree(BNode* node);

struct DNode {
   DNode* left_ { nullptr };
   DNode* right_ { nullptr };
   DNode* parent_ { nullptr };
   int data_ { 0 };
   DNode(int data) :
         data_ { data } {
   }
   ;
};

// To serialize a graph
struct SerializeNode {
   std::string string;
   std::vector<SerializeNode*> child;
};

// Using the following
struct SerializedNode {
   std::string string;
   int id;
   int parent;
};

void Serialize(SerializeNode* root, std::vector<SerializedNode>& snodes);
SerializeNode* Deserialize(std::vector<SerializedNode>& snodes);
void Heapify(int data[], int length);
void HeapSort(int data[], int length);
void Insert(BNode** root, int data);
void PreOrder(BNode* root);
void PostOrder(BNode* root);
void InOrder(BNode* root);
BNode* Bfs(BNode* root, int data);
void BfsPrint(BNode* root);
void DfsPrint(BNode* root);
BNode* Dfs(BNode* root, int data);
void DfsRecursive(BNode* root, int data);
void LevelOrdering(BNode* root);
int RightSibling(BNode* root, int data);
//Vertical Ordering
void VerticalOrdering(BNode* root);
int MinWidth(BNode* node, int width);
int MaxWidth(BNode* node, int width);
void PrintWidth(BNode* node, int printWidth, int currentWidth);
bool IsBst(BNode* node);
bool IsBalanced(BNode* node);
int Lca(BNode* root, int a, int b);
bool ChildTree(BNode* parent, BNode* child);
bool IsSameTree(BNode* node);

//Node with parent_
void InsertD(DNode** root, int data);
DNode* DfsD(DNode* root, int data);
int LcaD(DNode* root, int a, int b);
int LengthParentD(DNode* node);
int LcaDForrest(DNode forrestStart[], int forrestLength, int a, int b);

BNode** SortedArrayToBst(int array[], int length);
void BinarySearchInsertion(BNode** bnodeAddr, int array[], int start, int end);
BNode* BinarySearchInsertion2(int array[], int start, int end);
BNode** SortedArrayToBst2(int array[], int length);
int NextSuccessor(BNode* root, int node);
std::vector<int> ShortestPathDjkstras(std::vector<std::vector<int>>& weights,
      int src, int dest);

/*
 * What: In-order traserval
 * How:  Next() will select next element in BST.
 */
class InOrderIterator {
   std::stack<BNode*> stack_;
public:
   void recurseLeft(BNode* BNode);
   /*
    * Push current and all elems on left to stack.
    */
   InOrderIterator(BNode* BNode);
   /*
    * Recursively traverse to-pop right element.
    */
   BNode* Next();
};

// contact_id (int) and associated emails, will return merged contact_ids.
std::vector<std::vector<int>> Dedupe(
      std::vector<std::pair<int, std::vector<std::string>>>& contacts);

//Graph
struct GNode {
   GNode(int data) :
         data_ { data } {
   }
   GNode() {
   }
   GNode** neighbors_ { nullptr };
   int length_ { 0 };
   int data_ { 0 };
};

// Graph with flexibility to addChild and checkChild.
struct VNode {
   // Public Members.
   std::vector<VNode*> edges;
   int id;
   // Methods.
   VNode(int newId) :
         id(newId) {
   }
   void AddChild(VNode* child) {
      edges.push_back(child);
   }
   bool IsChild(VNode* child);
};

bool PathToNodes(GNode* src, GNode* dest);
int CountNodesInBST(BNode* root, int start, int end);
//Print path to leaf node.
void PrintPathToNode(Node *head, std::list<Node*>& path);
// Print flipped level ordering.
void FlipLevelOrdering(Node* node);
// Longest path from root.
void MaxLengthPath(NodeInt *node, std::list<NodeInt*>& maxPath,
      std::list<NodeInt*>& path, unsigned& maxPathLen);
//Get all paths from root to leaf.
void GetAllPaths(NodeInt *NodeInt, std::list<int>& path, std::list<std::list<int>>& allPaths);
//Get sum of all paths from root to leaf.
int GetSumAllPaths(NodeInt *root);
/*
 * What: Graph made from vertices
 */
struct Vertex {
   std::vector<Vertex*> edges_;
   int id_;
   Vertex(int id) :
         id_(id) {
   }
};
struct Graph {
   std::vector<Vertex*> vertices_;
   ~Graph() {
      for (auto& v : vertices_) {
         delete v;
      }
   }
};
// Clones graph.
Graph* CloneGraph(Graph& src);

//Resolve Dependencies.
class DependencyResolver {
   std::unordered_map<std::string, std::unordered_set<std::string>> dependencies_;
public:
   DependencyResolver(
         const std::unordered_map<std::string, std::vector<std::string>>& data);
   const std::unordered_set<std::string>& GetDependencies(
         const std::string& component);
};

class CommonAncestor {
public:
   CommonAncestor(Node* root) {
      root_ = root;
   }
   char GetCommonAncestor(char data1, char data2);
private:
   // Methods.
   char LastCommonElem(std::list<char>& path1, std::list<char>& path2);
   void GetPath(Node* node, std::list<char>& path);
   // Members.
   Node *root_;
   std::list<char> path1_, path2_;
   char data1_, data2_;
};

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
class StateNode {
public:
   StateNode(const std::string& name);
   void AddConnection(StateNode* conn);
   unsigned MatchLength(const std::string& match);
   std::vector<StateNode*>& GetConnections();
   const std::string& GetName();
private:
   std::string name_;
   std::vector<StateNode*> connections_;
};

class MapGraph {
public:
   MapGraph(std::vector<StateNode*>& states, std::vector<std::string>& dict);
   std::string FindLongestWord();
   bool ExistsStartingState(StateNode* state, const std::string& word);
   bool ExistsAllStates(const std::string& word);
private:
   std::vector<StateNode*>& states_;
   std::vector<std::string>& dict_;
};

}
#endif /* GRAPTH_H */
