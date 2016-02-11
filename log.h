/*
 * log.h
 *
 *  Created on: Apr 22, 2015
 *      Author: acs
 */

#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <string>

enum LOG_LEVEL {
	DEBUG = 0, TRIVIA, VERBOSE, INFO, ERROR, LOG_SIZE
};

#ifndef GLOBAL_LOG_LEVEL
#define GLOBAL_LOG_LEVEL INFO
#endif

void Log(LOG_LEVEL level, std::string msg);

#endif /* LOG_H_ */
