/*
 * dynamic.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: acs
 */

#include "dynamic.h"
#include <cmath>
#include <vector>
#include <algorithm>

namespace dynamic {
using namespace std;

template<typename T>
T abs(T par) {
   if (par < 0) {
      par *= -1;
   }
   return par;
}

/*
 * What: Fibnocci using dynamic programming
 * How: Make use of the same array
 * Complexity: Time O(n), Space O(n)
 */
int FibonacciDynamic(int val) {
   int fib[val + 1];
   fib[0] = 0;
   fib[1] = 1;
   for (int i = 2; i <= val; ++i) {
      fib[i] = fib[i - 1] + fib[i - 2];
   }
   return fib[val];
}

/*
 * What: Fibnocci using recursive programming
 * How: Make use stack
 * Complexity: Time O(2 power n)
 */
int FibonacciRecurse(int n) {
   if (n <= 1) {
      return n;
   }
   return FibonacciRecurse(n - 1) + FibonacciRecurse(n - 2);
}

/*
 * What: Distinct means unique combinations
 * How: 1,2 all options will be Fib()
 */
int DistinctOptions(vector<int>& points, int val) {
   vector<int> table(val + 1, 0);
   for (auto p : points) {
      ++table[p];
   }
   for (auto p : points) {
      for (unsigned i = p; i < points.size(); ++i) {
         table[i] += table[i - p];
      }
   }
   return table[val];
}

/*
 * What: Options means all combinations without uniqueness
 * How: 1,1,2,2 will cover all {1,2,1,2}
 * Idea is table[0] stores 1.
 */
int Options(vector<int>& points, int val) {
   vector<int> table(val + 1, 0);
   table[0] = 1;
   for (auto p : points) {
      for (unsigned i = p; i < points.size(); ++i) {
         table[i] += table[i - p];
      }
   }
   return table[val];
}

/*
 * What: Fibnocci using iterative programming
 * How:
 * Complexity: Time O(n), space O(1)
 */
int FibonacciOptimal(int n) {
   int first = 1, second = 0, next;
   for (int i = 0; i < n; ++i) {
      next = first + second;
      first = second;
      second = next;
   }
   return next;
}

/*
 * What: Checks if sum from a node to leaf is goalSum.
 * How: OR of left path and right path.
 */
bool IsSumOnPath1(Node* node, int parentSum, int goalSum) {
   if (!node) {
      return false;
   }
   if (node->data + parentSum == goalSum) {
      return true;
   }
   return IsSumOnPath1(node->left, node->data + parentSum, goalSum)
         || IsSumOnPath1(node->right, node->data + parentSum, goalSum);
}

/*
 * What: Using DP make look efficient.
 * How: Cached searches along with cache populating of SumOnPath.
 */
bool IsSumOnPath2(Node* node, int parentSum, int goalSum,
      unordered_map<Node*, unordered_set<int>>& cache) {
   if (!node) {
      return false;
   }
   if (cache[node].count(goalSum)) {
      //cout<< "Cache hit for goalSum : "<<goalSum<<"@node"<<node->data<<endl;
      return true;
   }
   cache[node].insert(node->data + parentSum);
   if (node->data + parentSum == goalSum) {
      return true;
   }
   bool result = IsSumOnPath2(node->left, node->data + parentSum, goalSum,
         cache)
         || IsSumOnPath2(node->right, node->data + parentSum, goalSum, cache);
   if (result) {
      cache[node].insert(goalSum);
   }
   return result;
}

/*
 * What: Finds the max diff of non overlapping sum.
 * How:  First from left to right and from right to left
 *       store min and max as pairs then
 *       find max diff where left contributes either min and max.
 *       http://www.careercup.com/question?id=19286747
 */
int FindMaxDiffSum(const vector<int>& list) {
   int size = list.size();
   vector<pair<int, int>> left(list.size()), right(size);
   // Get min and max from left to right.
   left[0].first = list[0];
   left[0].second = list[0];
   for (int i = 1; i < list.size(); ++i) {
      left[i].first = min(left[i - 1].first, 0) + list[i];
      left[i].second = max(left[i - 1].second, 0) + list[i];
   }
   // Get min and max from right to left.
   right[size - 1].first = list[size - 1];
   right[size - 1].second = list[size - 1];
   for (int i = size - 2; i >= 0; --i) {
      right[i].first = min(right[i + 1].first, 0) + list[i];
      right[i].second = max(right[i + 1].second, 0) + list[i];
   }
   int output = 0;
   for (int i = 0; i < size - 1; ++i) {
      output = max(output, abs(left[i].first - right[i + 1].second));
      output = max(output, abs(left[i].second - right[i + 1].first));
   }
   return output;
}

/*
 * What: Computes Height of the tree
 * How: Max of Height(Left node+1) and Height(right node + 1)
 *      Caches height in the map.
 */
int Height(Node* node, int height, unordered_map<Node*, int>& map) {
   if (node == nullptr) {
      return height;
   }
   auto index = map.find(node);
   if (index == map.end()) {
      int result = max(Height(node->left, height + 1, map),
            Height(node->right, height + 1, map));
      map[node] = result;
      return result;
   } else {
      return index->second;
   }
}

/*
 * What: Checks of the node is balanced
 * How: If height difference is more than 1 between left and right
 *       Or if left or right is not balanced then return false
 */
bool IsBalanced(Node* node) {
   if (node == nullptr) {
      return true;
   }
   unordered_map<Node*, int> map;
   if ((abs(Height(node->left, 1, map) - Height(node->right, 1, map)) > 1)
         || !IsBalanced(node->left) || !IsBalanced(node->right)) {
      return false;
   }
   return true;
}

/*
 * What: Compute Water inside Bar Graph.
 * How: Compute max from left and right for each elem.
 *      Then compute Sum of water as min(maxLeft, maxRight) - elem.
 */
unsigned ComputeWater(const vector<int>& bar) {
   vector<pair<int, int>> maxLen(bar.size());
   int leftMax = 0, rightMax = 0;
   // Compute max for left side.
   maxLen[0].first = 0;
   for (auto i = 0; i < bar.size(); ++i) {
      if (bar[i] > leftMax) {
         leftMax = bar[i];
      }
      maxLen[i].first = leftMax;
   }
   // Compute max for right side.
   maxLen[bar.size() - 1].second = 0;
   for (int i = bar.size() - 1; i >= -1; --i) {
      if (bar[i] > rightMax) {
         rightMax = bar[i];
      }
      maxLen[i].second = rightMax;
   }
   int sum = 0;
   int lowest = 0;
   for (auto i = 0; i < bar.size(); ++i) {
      lowest = min(maxLen[i].first, maxLen[i].second);
      sum += max(lowest - bar[i], 0);
   }
   return sum;
}

/*
 * What: Skip passed color for house and find min.
 */
int GetMinimumPaintCost(const vector<vector<int>>& cache, int house,
      int color) {
   int min = INT_MAX;
   for (int i = 0; i < cache.size(); ++i) {
      if (i == color) {
         continue;
      }
      if (min > cache[house][i]) {
         min = cache[house][i];
      }
   }
   return min;
}

/*
 * What: Total minimum cost to paint house.
 * How: Using dynamic programming make min cost
 *      for the next house and return the sum.
 */
int SumMinPaint(const vector<vector<int>>& cost) {
   auto cache = cost;
   for (int house = 1; house < cost.size(); ++house) {
      for (int color = 0; color < cost.size(); ++color) {
         cache[color][house] = GetMinimumPaintCost(cache, house - 1, color)
               + cost[house][color];
      }
   }
   int min = INT_MAX;
   for (int i = 0; i < cache.size(); ++i) {
      if (min > cache[cache.size() - 1][i]) {
         min = cache[cache.size() - 1][i];
      }
   }
   return min;
}

/*
 * What: Min counts of coin denomination to meet target
 * How: Remember the previous results and decrease one coin per move.
 */
const int INF = INT_MAX - 1;
int MinCoinsDp(int target, const vector<int>& coins, vector<int>& cache) {
   if(target < 0) {
      return INF;
   }
   if(target == 0) {
      return 0;
   }
   if (cache[target] != INF) {
      return cache[target];
   }
   int output = INF;
   for(int i=0; i<coins.size(); ++i) {
      output = min(output, MinCoinsDp(target - coins[i], coins, cache) + 1);
   }
   cache[target] = output;
   return output;
}

}

