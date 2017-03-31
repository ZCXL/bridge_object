/*************************************************************************
	> File Name: OutOfRange.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Wed 29 Mar 2017 03:44:20 PM UTC
 ************************************************************************/
#ifndef OUT_OF_RANGE_H_
#define OUT_OF_RANGE_H_
#include "java.h"

namespace java {
	class OutOfRange: public std::exception {
		public:
			virtual const char * what()const throw();
	};
}

#endif
