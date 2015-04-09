/*
 * logics_test.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: acs
 */

#include "logics.h"
#include <iostream>
#include <cassert>

namespace logics {

using namespace std;
void Test_GCD() {
   cout<<"Started testing Test_GCD()"<<endl;
   cout<<"GCD(4, 3) "<<GCD(4,3)<<endl;
   assert(GCD(10, 5) == 5);
   cout<<"Done testing Test_GCD()"<<endl;
}

void Test_CountStairSteps() {
   cout<<"Start testing Test_CountStairSteps()"<<endl;
   cout<<"Varitation of steps "<<endl;
   for(int i=1; i<=5; ++i) {
      cout<<"   CountStairSteps "<<i<<" :  = "<<CountStairSteps(i)<<endl;
   }
   cout<<"Done testing Test_CountStairSteps()"<<endl;
}


void Test_CountStairStepsDynamic() {
   cout<<"Start testing Test_CountStairStepsDynamic()"<<endl;
   cout<<"Varitation of steps "<<endl;
   for(int i=1; i<=5; ++i) {
      cout<<"   CountStairSteps "<<i<<" :  = "<<CountStairStepsDynamic(i)<<endl;
   }
   cout<<"Done testing Test_CountStairStepsDynamic()"<<endl;
}

void Test_CountRobotMoves() {
   cout<<"Start testing Test_CountRobotMoves()"<<endl;
   cout<<"CountRobotMoves(5, 8) : "<<CountRobotMoves(5, 8)<<endl;
   cout<<"Done testing Test_CountRobotMoves()"<<endl;
}



void Test_Logics() {
#ifdef TEST_DONE
   Test_GCD();
#else
   Test_CountStairSteps();
   Test_CountStairStepsDynamic();
   Test_CountRobotMoves();
#endif
}
}
