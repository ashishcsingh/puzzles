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

namespace threads {
std::vector<std::string> find_matches( std::string pattern, std::deque<std::string> &backlog);
}
#endif /* THREADS_H_ */
