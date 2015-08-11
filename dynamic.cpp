/*
 * dynamic.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: acs
 */

#include "dynamic.h"
#include <cmath>

namespace dynamic {
using namespace std;

/*
 * What: Fibnocci using dynamic programming
 * How: Make use of the same array
 * Complexity: Time O(n), Space O(n)
 */
int FibonacciDynamic(int val) {
   int fib[val + 1];
   fib[0] = 0;
   fib[1] = 1;
   for(int i=2; i<=val; ++i) {
      fib[i] = fib[i-1] + fib[i-2];
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

}

