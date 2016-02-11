/*
 * logics.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: acs
 */
#include "logics.h"
#include <map>
#include <vector>

namespace logics {
using namespace std;

int GCD(int a, int b) {
	while (1) {
		if (a == 0)
			return b;
		b %= a;
		if (b == 0)
			return a;
		a %= b;
	}
	return 0;
}

/*
 * What: Count variations of 1,2,3 steps to reach N steps
 * How: return 1 for n==0 is solution dependent terminal condition for recursion
 *      Bottom up approach: When n=3: count(n-1) + count(n-2) + count(n-3)
 *      count of all 1 steps + 2 steps + 3 steps
 */
int CountStairSteps(int n) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	return CountStairSteps(n - 1) + CountStairSteps(n - 2)
			+ CountStairSteps(n - 3);
}

/*
 * What: Using caching/dynamic programming
 * How:  Store in steps[] and use it
 */
int CountStairStepsDynamic_(int n, map<int, int>& steps) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (steps[n] != 0) {
		return steps[n];
	}
	steps[n] = CountStairStepsDynamic_(n - 1, steps)
			+ CountStairStepsDynamic_(n - 2, steps)
			+ CountStairStepsDynamic_(n - 3, steps);
	return steps[n];
}

int CountStairStepsDynamic(int n) {
	map<int, int> steps_;
	return CountStairStepsDynamic_(n, steps_);
}

/*
 * What: X, Y to 0,0 possible moves in right and up.
 * How:  F(x-1) + F(y-1) varieties that (X + Y)!/(X! * Y!)
 */
struct Point {
	int x_, y_;
	Point(int x, int y) :
			x_(x), y_(y) {
	}
};
bool CountRobotMovesPossible(int x, int y, vector<Point>& paths) {
	Point point(x, y);
	paths.push_back(point);
	bool success = false;
	if (x == 0 && y == 0) {
		return true;
	}
	if (x >= 1) {
		success = CountRobotMovesPossible(x - 1, y, paths);
	}
	if (!success && y >= 1) {
		success = CountRobotMovesPossible(x, y - 1, paths);
	}
	if (!success) {
		paths.pop_back();
	}
	return success;
}

int CountRobotMoves(int x, int y) {
	vector<Point> paths;
	CountRobotMovesPossible(x, y, paths);
	return paths.size();
}
}
