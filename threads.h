/*
 * threads.h
 *
 *  Created on: Aug 31, 2015
 *      Author: acs
 */

#ifndef THREADS_H_
#define THREADS_H_

#include <vector>
#include <string>
#include <deque>
#include <future>
#include <mutex>
#include <functional>
#include <thread>

namespace threads {
std::vector<std::string> find_matches( std::string pattern, std::deque<std::string> &backlog);


class Racer {
   std::condition_variable _cv;
   std::mutex _m;
   bool _ready {false};
   unsigned _numThreads;
   std::vector<std::thread> _threads;
public:
   void race(int id);
   void begin(Racer& r);
   void end();
   Racer(int numThreads);
};

}
#endif /* THREADS_H_ */
