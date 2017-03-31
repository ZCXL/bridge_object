/*************************************************************************
	> File Name: JavaShortArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_SHORT_ARRAY_H_
#define JAVA_SHORT_ARRAY_H_
#include "java.h"

namespace java {
	class JavaShortArray: public bridge::BridgeObject {
		public:
			JavaShortArray();
			JavaShortArray(size_t len);
			JavaShortArray(jshortArray);
			JavaShortArray(jobject);
			JavaShortArray(JavaShortArray&);
			~JavaShortArray();
		public:
			jshort& operator [](uint32_t index);
//			jshort* operator [](uint32_t index);
			operator jshortArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jshortArray getArray()const;

		private:
			jshortArray _array;
			jshort* _arr;
			size_t _len;
	};
}


#endif
