/*
 * bits_test.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: acs
 */

#include "bits.h"
#include <cassert>
#include <iostream>

namespace bits {

using namespace std;

void Test_LedBoard() {
   cout << "Started testing Test_LedBoard()" << endl;
   LedBoard lb(64, 64);
   lb.SetBit(5, 5);
   assert(lb.ReadBit(5,5));
   lb.SetBit(50, 5);
   assert(lb.ReadBit(50,5));
   lb.Reset();
   cout<<"Drawling rectangle "<<endl;
   lb.DrawRect(5,5,50,50);
   cout<<"Drawling diagnols line "<<endl;
   lb.DrawLine(50,50,5,5);
   lb.DrawLine(5,50,50,5);
   lb.PrintScreen();
   cout<<endl;
   cout << "Done testing Test_LedBoard()" << endl;
}


void Test_Bits() {
#ifdef TEST_DONE
#endif
   Test_LedBoard();
}
}


