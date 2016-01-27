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
#include <condition_variable>

namespace threads {
std::vector<std::string> find_matches( std::string pattern, std::deque<std::string> &backlog);


class Racer {
   std::condition_variable _cv;
   std::mutex _m;
   bool _ready {false};
   unsigned _numThreads;
   std::vector<std::thread> _threads;
   std::mutex _mPrint;
   void print(int id, const std::string& msg);
public:
   void race(int id);
   void begin(Racer& r);
   void end();
   Racer(int numThreads);
};

class Semaphore {
public:
   Semaphore(int count = 0) : count_(count) {}
   inline void Wait() {
      std::unique_lock<std::mutex> lock(mutex_);
      cv_.wait(lock, [this]() { return count_ > 0; });
      --count_;
   }
   inline void Notify() {
      std::unique_lock<std::mutex> lock(mutex_);
      ++count_;
      lock.unlock();
      cv_.notify_one();
   }
private:
   std::condition_variable cv_;
   std::mutex mutex_;
   int count_;
};

}
#endif /* THREADS_H_ */
