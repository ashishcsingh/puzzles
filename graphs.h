/*
 * graphs.h
 *
 *  Created on: Feb 28, 2015
 *      Author: acs
 */

#ifndef MAXNOY_BTREE_H_
#define MAXNOY_BTREE_H_

namespace graphs {

struct BNode {
   BNode* left_{nullptr};
   BNode* right_{nullptr};
   int data_{0};
   BNode(int data):data_{data}{};
};

struct DNode {
   DNode* left_{nullptr};
   DNode* right_{nullptr};
   DNode* parent_{nullptr};
   int data_{0};
   DNode(int data):data_{data}{};
};

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


//Graph
struct GNode {
   GNode(int data): data_{data} {}
   GNode() {}
   GNode** neighbors_{nullptr};
   int length_{0};
   int data_{0};
};

bool PathToNodes(GNode* src, GNode* dest);

int CountNodesInBST(BNode* root, int start, int end);

#endif /* MAXNOY_BTREE_H_ */

}
