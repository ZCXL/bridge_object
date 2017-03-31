/*************************************************************************
	> File Name: JavaDoubleArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_DOUBLE_ARRAY_H_
#define JAVA_DOUBLE_ARRAY_H_
#include "java.h"

namespace java {
	class JavaDoubleArray: public bridge::BridgeObject {
		public:
			JavaDoubleArray();
			JavaDoubleArray(size_t len);
			JavaDoubleArray(jdoubleArray);
			JavaDoubleArray(jobject);
			JavaDoubleArray(JavaDoubleArray&);
			~JavaDoubleArray();
		public:
			jdouble& operator [](uint32_t index);
	//		jdouble* operator [](uint32_t index);
			operator jdoubleArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jdoubleArray getArray()const;

		private:
			jdoubleArray _array;
			jdouble* _arr;
			size_t _len;
	};
}


#endif
