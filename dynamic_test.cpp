/*
 * dyanmic_test.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: acs
 */

#include <iostream>
#include <cassert>
#include "dynamic.h"

namespace dynamic {

using namespace std;

void Test_Fibonacci() {
   cout << "Started testing Test_Fibnocci()" << endl;
   cout << "FibonacciRecurse(10) : " << FibonacciRecurse(10) << endl;
   cout << "FibonacciDynamic(10) : " << FibonacciDynamic(10) << endl;
   cout << "FibonacciOptimal(10) : " << FibonacciOptimal(10) << endl;
   cout << "Done testing Test_Fibnocci()" << endl;
}

void Test_SumOnPath() {
   cout << "Started testing Test_SumOnPath()" << endl;
   Node *node = new Node(5);
   node->left = new Node(2);
   node->right = new Node(8);
   node->left->left = new Node(1);
   node->left->right = new Node(3);
   node->right->left = new Node(6);
   node->right->right = new Node(9);
   unordered_map<Node*, unordered_set<int>> cache;
   assert(IsSumOnPath1(node, 0, 22));
   assert(IsSumOnPath2(node, 0, 22, cache));
   assert(IsSumOnPath1(node, 0, 19));
   assert(IsSumOnPath2(node, 0, 19, cache));
   assert(!IsSumOnPath1(node, 0, 100));
   assert(!IsSumOnPath2(node, 0, 100, cache));
   cout << "Done testing Test_SumOnPath()" << endl;
}

void Test_FindMaxDiffSum() {
   cout << "Start Test_FindMaxDiffSum()" << endl;
   vector<int> list { 5, 2, 1, 3, 5, 6 };
   cout << FindMaxDiffSum(list) << endl;
   cout << "Done Test_FindMaxDiffSum()" << endl;
}

void Test_IsTreeBalanced() {
   cout << "Start Test_IsTreeBalanced()" << endl;
   Node b1(1), b2(2), b3(3), b4(4), b5(5), b6(6);
   b1.left = &b2;
   b1.right = &b3;
   b2.left = &b4;
   b2.right = &b5;
   b3.right = &b6;
   cout << IsBalanced(&b1) << endl;
   cout << "Done Test_IsTreeBalanced()" << endl;
}

void Test_BarWater() {
   cout << "Start Test_BarWater()" << endl;
   vector<int> bar { 1, 0, 1, 0, 1 };
   cout << "Total water " << ComputeWater(bar) << endl;
   cout << "Done Test_BarWater()" << endl;
}

void Test_SumMinPaint() {
   cout<<"Start testing Test_SumMinPaint()"<<endl;
   vector<vector<int>> paintCost {{1,2,3},{2,1,4},{5,1,4}};
   cout<<SumMinPaint(paintCost)<<endl;
   cout<<"Done testing Test_SumMinPaint()"<<endl;
}

const int INF = INT_MAX - 1;
void Test_MinCoinCountingDp() {
   cout<<"Start testing Test_MinCoinCountingDp()"<<endl;
   vector<int> coins {1,5,10};
   vector<int> cache(22, INF);
   cout<<MinCoinsDp(21, coins, cache)<<endl;
   cout<<"Done testing Test_MinCoinCountingDp()"<<endl;
}

void Test_CountDigitToChar() {
   cout<<"Start testing Test_CountDigitToChar()"<<endl;
   string str{"121"};
   cout<<CountDigitToChar(str, 0)<<endl;
   cout<<"Start testing Test_CountDigitToChar()"<<endl;
}

void Test_SumExists() {
   cout<<"Start testing Test_SumExists()"<<endl;
   vector<int> data {1,2,3,5,6,7,8,10};
   assert(SumExists(data, 15) > 0);
   assert(SumExists(data, 13) > 0);
   assert(SumExists(data, 50) <= 0);
   cout<<"Done testing Test_SumExists()"<<endl;
}

void Test_TotalCoinDenomsWithoutDP() {
   cout<<"Start testing Test_SumExists()"<<endl;
   vector<int> coins{1,5,10};
   for(int i=9; i<12; ++i) {
      cout<<"For target without DP: "<<i<<" "<<TotalCoinDenoms(i, coins, 0)<<endl;
   }
   cout<<"Done testing Test_SumExists()"<<endl;
}

void Test_TotalCoinDenomsWithDP() {
   cout<<"Start testing Test_SumExists()"<<endl;
   vector<int> coins{1,5,10};
   for(int i=9; i<12; ++i) {
      cout<<"For target with DP: "<<i<<" "<<TotalCoinDenomDP(i, coins)<<endl;
   }
   cout<<"Done testing Test_SumExists()"<<endl;
}

void Test_Dynamic() {
#ifdef TEST_DONE
#else
#endif
   Test_Fibonacci();
   Test_SumOnPath();
   Test_FindMaxDiffSum();
   Test_IsTreeBalanced();
   Test_BarWater();
   Test_SumMinPaint();
   Test_MinCoinCountingDp();
   Test_CountDigitToChar();
   Test_SumExists();
   Test_TotalCoinDenomsWithoutDP();
   Test_TotalCoinDenomsWithDP();
}
}

