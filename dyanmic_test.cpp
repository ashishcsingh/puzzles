/*
 * dyanmic_test.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: acs
 */
#include "dynamic.h"

namespace dymamic {
int FactorialRecurse(int n) {
   if(n <=1) {
      return 1;
   }
   return n * FactorialRecurse(n-1);
}

int Fibonacci(int n) {
   int first = 1, second = 0, next;
   for(int i=0; i<n; ++i) {
      next = first + second;
      first = second;
      second = next;
   }
   return next;
}
}



