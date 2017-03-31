/*************************************************************************
	> File Name: JavaIntArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_INT_ARRAY_H_
#define JAVA_INT_ARRAY_H_
#include "java.h"

namespace java {
	class JavaIntArray: public bridge::BridgeObject {
		public:
			JavaIntArray();
			JavaIntArray(size_t len);
			JavaIntArray(jintArray);
			JavaIntArray(jobject);
			JavaIntArray(JavaIntArray&);
			~JavaIntArray();
		public:
			jint& operator [](uint32_t index);
//			jint* operator [](uint32_t index);
			operator jintArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jintArray getArray()const;

		private:
			jintArray _array;
			jint* _arr;
			size_t _len;
	};
}


#endif
