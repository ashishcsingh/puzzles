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
   Node *left { nullptr }, *right { nullptr };
   int data;
   Node(int dataPar) :
         data(dataPar) {
   }
};

bool IsBalanced(Node* node);
int Height(Node* node, int height, std::unordered_map<Node*, int>& map);

bool IsSumOnPath1(Node* node, int parentSum, int goalSum);
// Using DP.
bool IsSumOnPath2(Node* node, int parentSum, int goalSum,
      std::unordered_map<Node*, std::unordered_set<int>>& cache);

int FindMaxDiffSum(const std::vector<int>& list);
unsigned ComputeWater(const std::vector<int>& bar);
// Total minimum cost to paint house.
int SumMinPaint(const std::vector<std::vector<int>>& cost);
// Min counts of coin denomination to meet target
int MinCoinsDp(int target, const std::vector<int>& coins, std::vector<int>& cache);
// Count int to char conversion.
int CountDigitToChar(const std::string& str, int index);
// Check sum exists.
int SumExists(const std::vector<int>& data, int sum);
// Count coin denominations.
int TotalCoinDenoms(int target, const std::vector<int>& coinDenoms, int coinItr);
// Count coin denominations using DP.
int TotalCoinDenomDP(unsigned target, std::vector<int>& coins);
}

#endif /* DYNAMIC_H_ */
