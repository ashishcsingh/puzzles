/*
 * threads.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: acs
 */

#include "threads.h"

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

namespace threads {

using namespace std;

mutex m;

inline bool match(const std::string &pattern, std::string word) {
	if (pattern.size() != word.size())
		return false;
	for (size_t i = 0; i < pattern.size(); i++)
		if (pattern[i] != '.' && pattern[i] != word[i])
			return false;
	return true;
}

vector<string> find_matches(string pattern, deque<string> &backlog) {
	vector<string> results;
	for (;;) {
		m.lock();
		if (backlog.size() == 0) {
			m.unlock();
			return results;
		}
		string word = backlog.front();
		backlog.pop_front();
		m.unlock();
		if (match(pattern, word))
			results.push_back(word);
	}
}

Racer::Racer(int numThreads) {
	_numThreads = numThreads;
}

void Racer::print(int id, const string& msg) {
	lock_guard<mutex> locker(_mPrint);
	cout << "Thread : " << id << " " << msg << endl;
}

void Racer::race(int id) {
	print(id, "staring");
	unique_lock<mutex> lock(_m);
	print(id, "waiting");
	_cv.wait(lock, [=]() {return _ready;});
	print(id, "racing");
	lock.unlock();
	// Let other race.
	_cv.notify_one();
}

void Racer::begin(Racer& r) {
	for (unsigned i = 0; i < _numThreads; ++i) {
		_threads.push_back(thread(&Racer::race, &r, i + 1));
	}
	cout << "Begin by notifying one" << endl;
	lock_guard<mutex> lock(_m);
	_ready = true;
	_cv.notify_one();
}

void Racer::end() {
	for (auto& t : _threads) {
		t.join();
	}
	cout << "End all" << endl;
}

}

