/*
 * logics.h
 *
 *  Created on: Mar 19, 2015
 *      Author: acs
 */

#ifndef _MAXNOY_LOGICS_H
#define _MAXNOY_LOGICS_H

namespace logics {
int GCD(int a, int b);
// Child taking 1, 2, 3, count varieties of steps
int CountStairSteps(int n);
// Using dynamic programming
int CountStairStepsDynamic(int n);
// Robot moving to x,y one right or one up, count variety
int CountRobotMoves(int x, int y);
}

#endif

