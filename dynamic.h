/*
 * dynamic.h
 *
 *  Created on: Mar 12, 2015
 *      Author: acs
 */

#ifndef DYNAMIC_H_
#define DYNAMIC_H_

#include<vector>
#include<unordered_map>
#include<unordered_set>

namespace dynamic {
int FibonacciRecurse(int val);
int FibonacciDynamic(int val);
int FibonacciOptimal(int val);

struct Node {
   Node *left {nullptr}, *right{nullptr};
   int data;
   Node(int dataPar) : data(dataPar) {}
};

bool IsBalanced(Node* node);
int Height(Node* node, int height, std::unordered_map<Node*, int>& map);

bool IsSumOnPath1(Node* node, int parentSum, int goalSum);
// Using DP.
bool IsSumOnPath2(Node* node, int parentSum, int goalSum, std::unordered_map<Node*,
      std::unordered_set<int>>& cache);

int FindMaxDiffSum(const std::vector<int>& list) ;
}

#endif /* DYNAMIC_H_ */
