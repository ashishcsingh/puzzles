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
#include <unordered_map>

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
      std::vector<std::pair<int,std::vector<std::string>>>& contacts);

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

bool PathToNodes(GNode* src, GNode* dest);
int CountNodesInBST(BNode* root, int start, int end);

/*
 * What: Graph made from vertices
 */
struct Vertex {
   std::vector<Vertex*> edges_;
   int id_;
   Vertex(int id) : id_(id) {}
};
struct Graph {
   std::vector<Vertex*> vertices_;
   ~Graph() {
      for(auto& v: vertices_) {
         delete v;
      }
   }
};
// Clones graph.
Graph* CloneGraph(Graph& src);
}
#endif /* GRAPTH_H */
