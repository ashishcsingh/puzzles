/*
 * dyanmic_test.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: acs
 */

#include <iostream>
#include "dynamic.h"

namespace dynamic {

using namespace std;

void Test_Fibonacci() {
   cout << "Started testing Test_Fibnocci()" << endl;
   cout<<"FibonacciRecurse(10) : "<<FibonacciRecurse(10)<<endl;
   cout<<"FibonacciDynamic(10) : "<<FibonacciDynamic(10)<<endl;
   cout<<"FibonacciOptimal(10) : "<<FibonacciOptimal(10)<<endl;
   cout << "Done testing Test_Fibnocci()" << endl;
}

void Test_Dynamic() {
#ifdef TEST_DONE
#else
#endif
   Test_Fibonacci();
}

}

