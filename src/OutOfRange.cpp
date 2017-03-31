/*************************************************************************
	> File Name: OutOfRange.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Wed 29 Mar 2017 03:47:06 PM UTC
 ************************************************************************/
#include "OutOfRange.h"
namespace java {
	const char * OutOfRange::what()const throw() {
		return "Out of range for array";
	}
}
