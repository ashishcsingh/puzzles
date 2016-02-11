/*
 * threads_test.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: acs
 */

#include "threads.h"
#include "threads_test.h"
#include <iostream>
#include<functional>
#include<tuple>

namespace threads {

using namespace std;

template<class ASYNC>
void print_results(ASYNC &f, string &pattern, unsigned threadno) {
	vector<string> words = f.get();
	cerr << "Found " << words.size() << " matches for " << pattern
			<< " in thread " << threadno << endl;
	for (auto s : words)
		cout << s << "\n";
}

void Test_WordSearch() {
	cout << "Started Test_WordSearch()" << endl;
	string pattern = "c..per";
	string words[] = { "copper", "cloper", "subject" };
	deque<string> backlog;
	for (auto word : words) {
		backlog.push_back(word);
	}
	auto f1 = async(launch::async, find_matches, pattern, ref(backlog));
	auto f2 = async(launch::async, find_matches, pattern, ref(backlog));
	auto f3 = async(launch::async, find_matches, pattern, ref(backlog));
	print_results(f1, pattern, 1);
	print_results(f2, pattern, 2);
	print_results(f3, pattern, 3);
	cout << "Done Test_WordSearch()" << endl;
}

/*
 * What: Using Lambda spawn thread to compute twice for 10.
 * How: Spawn and then get();
 */
void Test_Twice() {
	cout << "Started Test_Twice()" << endl;
	vector<future<int>> futures;
	for (int i = 0; i < 10; ++i) {
		futures.push_back(async([] (int n) {return 2*n;}, i));
	}
	for (auto &f : futures) {
		cout << f.get() << endl;
	}
	cout << "Done Test_Twice()" << endl;
}

void Test_Racer() {
	cout << "Started Test_Racer()" << endl;
	Racer r(10);
	r.begin(r);
	r.end();
	cout << "Done Test_Racer()" << endl;
}

typedef tuple<int, string> tuple_type;
tuple_type promiseTupleData(future<tuple_type>& f) {
	tuple_type t = f.get();
	get<0>(t) += 20;
	get<1>(t) += " completed";
	return t;
}

void Test_PromiseTupleData() {
	cout << "Started Test_Racer()" << endl;
	int i = 10;
	string s { "hello" };
	auto t = make_tuple(i, s);
	promise<tuple_type> p;
	future<tuple_type> f = p.get_future();
	auto fRet = async(launch::async, promiseTupleData, ref(f));
	p.set_value(t);
	tuple_type tRet = fRet.get();
	cout << " Int Sent : " << i << endl;
	cout << " String Sent : " << s << endl;
	cout << " Int Return : " << get<0>(tRet) << endl;
	cout << " String Return  :  " << get<1>(tRet) << endl;
	cout << "Done Test_Racer()" << endl;
}

ReadWriteMutex m_;
void readFunc() {
	ReadWriteLock lock(m_, READ);
	cout << "Reading and sleeping" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void writeFunc() {
	ReadWriteLock lock(m_, WRITE);
	cout << "Writing and sleeping" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Test_ReadWriteLock() {
	cout << "Start Test_ReadWriteLock()" << endl;
	thread t[3];
	// Reader lock for 1 seconds.
	t[0] = thread(readFunc);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	// Reader lock for 1 seconds.
	t[1] = thread(readFunc);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	// Writer lock for 1 seconds.
	t[2] = thread(writeFunc);
	t[0].join();
	t[1].join();
	t[2].join();
	cout << "Done Test_ReadWriteLock()" << endl;
}

void Test_Threads() {
#ifdef TEST_DONE
	Test_WordSearch();
	Test_Twice();
#endif
	Test_Racer();
	Test_PromiseTupleData();
	Test_ReadWriteLock();
}
}

