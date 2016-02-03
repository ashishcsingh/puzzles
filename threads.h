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

class Semaphore {
public:
   Semaphore(int count = 0) :
         count_(count) {
   }
   inline void Wait() {
      std::unique_lock<std::mutex> lock(mutex_);
      cv_.wait(lock, [this]() {return count_ > 0;});
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

enum LockType {
   READ, WRITE
};

/*
 * What: Implements READ/WRITE (Shared/Exclusive) Lock.
 */
class ReadWriteMutex {
private:
   std::condition_variable cv_;
   std::mutex m_;
   int readerCount_ { 0 };
   bool writeCount_ { false };
public:
   void Lock(LockType type) {
      if (type == READ) {
         std::unique_lock<std::mutex> lock(m_);
         cv_.wait(lock, [this] {return !writeCount_;});
         ++readerCount_;
         lock.unlock();
         cv_.notify_one();
      } else if (type == WRITE) {
         std::unique_lock<std::mutex> lock(m_);
         cv_.wait(lock, [this] {return !writeCount_ && readerCount_ == 0;});
         writeCount_ = true;
         lock.unlock();
         cv_.notify_one();
      }
   }

   void Unlock(LockType type) {
      if (type == READ) {
         std::unique_lock<std::mutex> lock(m_);
         --readerCount_;
         lock.unlock();
         cv_.notify_one();
      } else if (type == WRITE) {
         std::unique_lock<std::mutex> lock(m_);
         writeCount_ = false;
         lock.unlock();
         cv_.notify_one();
      }
   }
};

class ReadWriteLock {
private:
   ReadWriteMutex& m_;
   LockType type_;
public:
   ReadWriteLock(ReadWriteMutex& m, LockType type = READ) :
         m_(m), type_(type) {
      m_.Lock(type_);
   }
   ~ReadWriteLock() {
      m_.Unlock(type_);
   }
};

std::vector<std::string> find_matches(std::string pattern,
      std::deque<std::string> &backlog);

class Racer {
   std::condition_variable _cv;
   std::mutex _m;
   bool _ready { false };
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

}
#endif /* THREADS_H_ */
