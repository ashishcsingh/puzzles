/*
 * log.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: acs
 */

#include "log.h"

void Log(LOG_LEVEL level, std::string msg) {
   if (GLOBAL_LOG_LEVEL <= level) {
      std::cout<<msg<<std::endl;
   }
}

