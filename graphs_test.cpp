/*
 * btree_test.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: acs
 */
#include "graphs.h"
#include <cassert>
#include <iostream>

namespace graphs {

using namespace std;

/*
 *               5
 *            /    \
 *           1       8
 *            \
 *              2
 *               \
 *                3
 */
void Test_Insert() {
   cout << "Started testing Test_Insert()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   assert(bnode->data_ == 5);
   assert(bnode->left_->data_ == 1);
   assert(bnode->right_->data_ == 8);
   assert(bnode->left_->right_->data_ == 2);
   assert(bnode->left_->right_->right_->data_ == 3);
   cout << "Done testing Test_Insert()" << endl;
}

/*
 *                10
 *               /   \
 *              5    15
 *            /  \   /    \
 *           2   7  12       20
 *          / \  /\  /\      / \
 *        1    3,6 8,11,13 16  22
 */

BNode** Test_Insert2() {
   //cout<<"Started testing Test_Insert2()"<<endl;
   BNode** bnodeAddr = new (BNode*);
   *bnodeAddr = nullptr;
   Insert(bnodeAddr, 10);
   Insert(bnodeAddr, 5);
   Insert(bnodeAddr, 15);
   Insert(bnodeAddr, 2);
   Insert(bnodeAddr, 7);
   Insert(bnodeAddr, 12);
   Insert(bnodeAddr, 20);
   Insert(bnodeAddr, 1);
   Insert(bnodeAddr, 3);
   Insert(bnodeAddr, 6);
   Insert(bnodeAddr, 8);
   Insert(bnodeAddr, 11);
   Insert(bnodeAddr, 13);
   Insert(bnodeAddr, 16);
   Insert(bnodeAddr, 22);
   assert((*bnodeAddr)->left_->left_->left_->data_ == 1);
   assert((*bnodeAddr)->left_->left_->right_->data_ == 3);
   assert((*bnodeAddr)->left_->right_->left_->data_ == 6);
   assert((*bnodeAddr)->left_->right_->right_->data_ == 8);
   //cout<<"Done testing Test_Insert2()"<<endl;
   return bnodeAddr;
}

/*
 *                100
 *               /   \
 *              99    103
 */

DNode** Test_Insert3D() {
   //cout<<"Started testing Test_Insert2()"<<endl;
   DNode** dnodeAddr = new (DNode*);
   *dnodeAddr = nullptr;
   InsertD(dnodeAddr, 100);
   InsertD(dnodeAddr, 99);
   InsertD(dnodeAddr, 103);
   //cout<<"Done testing Test_Insert2()"<<endl;
   return dnodeAddr;
}

DNode** Test_Insert2D() {
   //cout<<"Started testing Test_Insert2()"<<endl;
   DNode** dnodeAddr = new (DNode*);
   *dnodeAddr = nullptr;
   InsertD(dnodeAddr, 10);
   InsertD(dnodeAddr, 5);
   InsertD(dnodeAddr, 15);
   InsertD(dnodeAddr, 2);
   InsertD(dnodeAddr, 7);
   InsertD(dnodeAddr, 12);
   InsertD(dnodeAddr, 20);
   InsertD(dnodeAddr, 1);
   InsertD(dnodeAddr, 3);
   InsertD(dnodeAddr, 6);
   InsertD(dnodeAddr, 8);
   InsertD(dnodeAddr, 11);
   InsertD(dnodeAddr, 13);
   InsertD(dnodeAddr, 16);
   InsertD(dnodeAddr, 22);
   assert((*dnodeAddr)->left_->left_->left_->data_ == 1);
   assert((*dnodeAddr)->left_->left_->right_->data_ == 3);
   assert((*dnodeAddr)->left_->right_->left_->data_ == 6);
   assert((*dnodeAddr)->left_->right_->right_->data_ == 8);
   //cout<<"Done testing Test_Insert2()"<<endl;
   return dnodeAddr;
}

void Test_PreOrder() {
   cout << "Started testing Test_PreOrder()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   PreOrder(bnode);
   cout << "Done testing Test_PreOrder()" << endl;
}

void Test_InOrder() {
   cout << "Started testing Test_InOrder()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   InOrder(bnode);
   cout << "Done testing Test_InOrder()" << endl;
}

void Test_PostOrder() {
   cout << "Started testing Test_PostOrder()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   PostOrder(bnode);
   cout << "Done testing Test_PostOrder()" << endl;
}

void Test_Bfs() {
   cout << "Started testing Test_Bfs()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   Bfs(bnode, 8);
   Bfs(bnode, 3);
   cout << "Done testing Test_Bfs()" << endl;
}

void Test_BfsPrint() {
   cout << "Started testing Test_BfsPrint()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   BfsPrint(bnode);
   cout << endl << "Done testing Test_BfsPrint()" << endl;
}

void Test_DfsPrint() {
   cout << "Started testing Test_DfsPrint()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   DfsPrint(bnode);
   cout << endl << "Done testing Test_DfsPrint()" << endl;
}

void Test_LevelOrdering() {
   cout << "Started testing Test_LevelOrdering()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   LevelOrdering(bnode);
   cout << endl << "Done testing Test_LevelOrdering()" << endl;
}

void Test_RightSibling() {
   cout << "Started testing Test_RightSibling()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   RightSibling(bnode, 1);
   cout << endl << "Done testing Test_RightSibling()" << endl;
}

void Test_RightSibling2() {
   cout << "Started testing Test_RightSibling2()" << endl;
   BNode** bnodeAddr = Test_Insert2();
   assert(RightSibling(*bnodeAddr, 7) == 12);
   assert(RightSibling(*bnodeAddr, 20) == -1);
   cout << endl << "Done testing Test_RightSibling2()" << endl;
}

void Test_Dfs() {
   cout << "Started testing Test_Dfs()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   Dfs(bnode, 8);
   Dfs(bnode, 3);
   cout << "Done testing Test_Dfs()" << endl;
}

void Test_DfsRecursive() {
   cout << "Started testing Test_DfsRecursive()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   DfsRecursive(bnode, 8);
   DfsRecursive(bnode, 3);
   cout << "Done testing Test_DfsRecursive()" << endl;
}

void Test_VerticalOrdering() {
   cout << "Started testing Test_VerticalOrdering()" << endl;
   BNode** bnodeAddr = Test_Insert2();
   VerticalOrdering(*bnodeAddr);
   cout << "Done testing Test_VerticalOrdering()" << endl;
}

void Test_IsBst() {
   cout << "Started testing Test_IsBst()" << endl;
   BNode** bnodeAddr = Test_Insert2();
   if (IsBst(*bnodeAddr)) {
      cout << "The passed tree is BST" << endl;
   } else {
      cout << "The passed tree is NOT BST" << endl;
   }
   cout << "Done testing Test_IsBst()" << endl;
}

void Test_IsBalanced() {
   cout << "Started testing Test_IsBalanced()" << endl;
   //Positive testing
   BNode** bnodeAddr = Test_Insert2();
   if (IsBalanced(*bnodeAddr)) {
      cout << "The first passed tree is balanced" << endl;
   } else {
      cout << "The first passed tree is NOT balanced" << endl;
   }
   //Negative testing
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 3);
   if (IsBalanced(bnode)) {
      cout << "The second passed tree is balanced" << endl;
   } else {
      cout << "The second passed tree is NOT balanced" << endl;
   }
   cout << "Done testing Test_IsBalanced()" << endl;
}

void Test_Lca() {
   cout << "Started testing Test_Lca()" << endl;
   BNode** bnodeAddr = Test_Insert2();
   assert(Lca(*bnodeAddr, 11, 20) == 15);
   assert(Lca(*bnodeAddr, 6, 12) == 10);
   assert(Lca(*bnodeAddr, 3, 8) == 5);
   //assert(Lca(*bnodeAddr, 5, 8) == 5);
   cout << "LCA of 5 and 8 " << Lca(*bnodeAddr, 5, 8) << endl;
   cout << "Done testing Test_Lca()" << endl;
}

void Test_LcaD() {
   cout << "Started testing Test_LcaD()" << endl;
   DNode** dnodeAddr = Test_Insert2D();
   assert(LcaD(*dnodeAddr, 11, 20) == 15);
   assert(LcaD(*dnodeAddr, 6, 12) == 10);
   assert(LcaD(*dnodeAddr, 3, 8) == 5);
   assert(LcaD(*dnodeAddr, 5, 8) == 5);
   cout << "LCAD of 5 and 8 " << LcaD(*dnodeAddr, 5, 8) << endl;
   cout << "Done testing Test_LcaD()" << endl;
}

void Test_LcaDForrest() {
   cout << "Started testing Test_LcaDForrest()" << endl;
   DNode** dnodeAddr1 = Test_Insert2D();
   DNode** dnodeAddr2 = Test_Insert3D();
   DNode* forrest[] = { *dnodeAddr1, *dnodeAddr2 };
   assert(LcaDForrest(forrest[0], 2, 11, 20) == 15);
   assert(LcaDForrest(forrest[0], 2, 6, 12) == 10);
   assert(LcaDForrest(forrest[0], 2, 10, 103) == -1);
   cout << "Done testing Test_LcaDForrest()" << endl;
}

void Test_SortedArrayToBst() {
   cout << "Started testing Test_SortedArrayToBst()" << endl;
   //int array[] = {1,2,3,4,5,6,7,8};
   int array[] = { 1, 2, 3 };
   int length = sizeof(array) / sizeof(int);
   BNode** bnodeAddr = SortedArrayToBst(array, length);
   LevelOrdering(*bnodeAddr);
   cout << "Done testing Test_SortedArrayToBst()" << endl;
}

void Test_SortedArrayToBst2() {
   cout << "Started testing Test_SortedArrayToBst2()" << endl;
   int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
   //int array[] = {1,2,3};
   int length = sizeof(array) / sizeof(int);
   BNode** bnodeAddr = SortedArrayToBst2(array, length);
   LevelOrdering(*bnodeAddr);
   cout << "Done testing Test_SortedArrayToBst2()" << endl;
}

void Test_NextSuccessor() {
   cout << "Started testing Test_NextSuccessor()" << endl;
   BNode** bnodeAddr = Test_Insert2();
   LevelOrdering(*bnodeAddr);
   assert(NextSuccessor(*bnodeAddr, 7) == 12);
   assert(NextSuccessor(*bnodeAddr, 5) == 15);
   assert(NextSuccessor(*bnodeAddr, 20) == 1);
   assert(NextSuccessor(*bnodeAddr, 105) == -1);
   cout << "Done testing Test_NextSuccessor()" << endl;
}

void Test_PathToNodes() {
   cout << "Started testing Test_PathToNodes()" << endl;
   GNode** gnodeAddr = new (GNode*);
   *gnodeAddr = new GNode[4];
   (*gnodeAddr)[0].data_ = 0;
   (*gnodeAddr)[1].data_ = 1;
   (*gnodeAddr)[2].data_ = 2;
   (*gnodeAddr)[3].data_ = 3;

   (*gnodeAddr)[0].neighbors_ = new GNode*[2];
   (*gnodeAddr)[0].length_ = 2;
   (*gnodeAddr)[0].neighbors_[0] = &(*gnodeAddr)[1];
   (*gnodeAddr)[0].neighbors_[1] = &(*gnodeAddr)[2];

   (*gnodeAddr)[2].neighbors_ = new GNode*[1];
   (*gnodeAddr)[2].length_ = 1;
   (*gnodeAddr)[2].neighbors_[0] = &(*gnodeAddr)[3];

   cout << "Testing path from Node 0 to Node 3 : "
         << PathToNodes(&(*gnodeAddr)[0], &(*gnodeAddr)[3]) << endl;
   delete[] *gnodeAddr;
   cout << "Done testing Test_PathToNodes()" << endl;
}

// To Do:
void Test_MatchTree() {
   cout << "Started testing Test_MatchTree()" << endl;
   cout << "Done testing Test_MatchTree()" << endl;
}

void Test_CountNodesInBST() {
   cout << "Start testing Test_CountNodesInBST()" << endl;
   BNode** bnode = Test_Insert2();
   cout << "CountNodesInBST(bnode, 2, 20) : " << CountNodesInBST(*bnode, 1, 22)
         << endl;
   cout << "Done testing Test_CountNodesInBST()" << endl;
}

void Test_ShortestPathDjkstras() {
   cout << "Start Test_ShortestPathDjkstras()" << endl;
   // A -> B-> C-> D
   // A-> C-> D
   vector<vector<int> > weights { { 0, 1, 1, 1000 }, { 1000, 0, 1, 1000 }, {
         1000, 1000, 0, 1 }, { 1000, 1000, 1000, 1000 } };
   auto path = ShortestPathDjkstras(weights, 0, 3);
   for (auto move : path) {
      cout << " " << move;
   }
   cout << endl;
   cout << "Done Test_ShortestPathDjkstras()" << endl;
}

void Test_Serialize() {
   cout << "Start Test_Serialize()" << endl;
   // A -> B-> C
   SerializeNode* A = new SerializeNode();
   A->string = "A";
   SerializeNode* B = new SerializeNode();
   B->string = "B";
   SerializeNode* C = new SerializeNode();
   C->string = "C";
   A->child.push_back(B);
   B->child.push_back(C);
   vector<SerializedNode> snodes;
   Serialize(A, snodes);
   SerializeNode* root = Deserialize(snodes);
   cout<<root->string<<" -> "<<root->child[0]->string<<" -> "
         <<root->child[0]->child[0]->string<<endl;
   cout << "Done Test_Serialize()" << endl;
}

void Test_HeapSort() {
   cout << "Start Test_HeapSort()" << endl;
   int data[] {1, 2};
   cout<<"Before sorting "<<endl;
   for(int i=0; i<2; ++i) {
      cout<<data[i]<<" ";
   }
   HeapSort(data, 2);
   cout<<endl<<"After sorting "<<endl;
   for(int i=0; i<2; ++i) {
      cout<<data[i]<<" ";
   }
   cout << endl<< "Done Test_HeapSort()" << endl;
}

void Test_Dedupe() {
   cout << endl<< "Start Test_Dedupe()" << endl;
   vector<pair<int, vector<string>>> contacts = {
         {1, {"a@gmail.com", "b@gmail.com"}},
         {2, {"c@gmail.com"}},
         {3, {"c@gmail.com"}}
   };
   vector<vector<int>> allGroups = Dedupe(contacts);
   for(auto group : allGroups) {
      for(auto id: group) {
         cout<<id<<",";
      }
   }
   cout << endl<< "Done Test_Dedupe()" << endl;
}

void Test_RotateTree() {
   cout << endl<< "Start Test_RotateTree()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 2);
   Insert(&bnode, 8);
   Insert(&bnode, 1);
   Insert(&bnode, 3);
   RotateTree(bnode);
   assert(bnode->data_ == 5);
   assert(bnode->left_->data_ == 8);
   assert(bnode->right_->data_ == 2);
   assert(bnode->right_->left_->data_ == 3);
   cout << endl<< "Done Test_RotateTree()" << endl;
}


void Test_IsSameTree() {
   cout << "Started testing Test_IsSameTree()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 5);
   Insert(&bnode, 5);
   Insert(&bnode, 5);
   Insert(&bnode, 5);
   cout<<"Must be true: "<<IsSameTree(bnode)<<endl;
   Insert(&bnode, 1);
   cout<<"Must be false: "<<IsSameTree(bnode)<<endl;
   cout << endl<< "Done Test_IsSameTree()" << endl;
}

void Test_InOrderIterator() {
   cout << endl<< "Start Test_InOrderIterator()" << endl;
   BNode* bnode = nullptr;
   Insert(&bnode, 5);
   Insert(&bnode, 1);
   Insert(&bnode, 2);
   InOrderIterator itr(bnode);
   BNode* ptr;
   while((ptr = itr.Next())) {
      std::cout<<ptr->data_<<" ";
   }
   cout << endl<< "Done Test_InOrderIterator()" << endl;
}

void Test_GraphClone() {
   cout << endl<< "Start Test_GraphClone()" << endl;
   Graph src;
   src.vertices_.push_back(new Vertex(0));
   src.vertices_.push_back(new Vertex(1));
   src.vertices_.push_back(new Vertex(2));
   src.vertices_[0]->edges_.push_back(src.vertices_[1]);
   src.vertices_[0]->edges_.push_back(src.vertices_[2]);
   {
      Graph *dst = CloneGraph(src);
      assert(dst->vertices_[0]->id_ == 0);
      assert(dst->vertices_[1]->id_ == 1);
      assert(dst->vertices_[2]->id_ == 2);
      assert(dst->vertices_[0]->edges_[0]->id_ == 1);
      assert(dst->vertices_[0]->edges_[1]->id_ == 2);
   }
   cout << endl<< "Done Test_GraphClone()" << endl;
}

void Test_Graphs() {
#ifdef TEST_DONE
   Test_Insert();
   Test_Insert2();
   Test_PreOrder();
   Test_InOrder();
   Test_PostOrder();
   Test_Bfs();
   Test_Dfs();
   Test_DfsRecursive();
   Test_LevelOrdering();
   Test_BfsPrint();
   Test_DfsPrint();
   Test_RightSibling();
   Test_RightSibling2();
   Test_VerticalOrdering();
   Test_IsBst();
   Test_IsBalanced();
   Test_Lca();
   Test_LcaD();
   Test_LcaDForrest();
   Test_SortedArrayToBst();
   Test_SortedArrayToBst2();
   Test_NextSuccessor();
   Test_PathToNodes();
   Test_MatchTree();
   Test_ShortestPathDjkstras();
   Test_CountNodesInBST();
   Test_Serialize();
   Test_HeapSort();
   Test_Dedupe();
   Test_RotateTree();
   Test_IsSameTree();
#endif
   Test_InOrderIterator();
   Test_GraphClone();
}
}
