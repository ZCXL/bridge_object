/*************************************************************************
	> File Name: JavaLongArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_LONG_ARRAY_H_
#define JAVA_LONG_ARRAY_H_
#include "java.h"

namespace java {
	class JavaLongArray: public bridge::BridgeObject {
		public:
			JavaLongArray(size_t len);
			JavaLongArray(jlongArray);
			JavaLongArray(jobject);
			JavaLongArray(JavaLongArray&);
			~JavaLongArray();
		protected:
			JavaLongArray();
		public:
			jlong& operator [](uint32_t index);
	//		jlong* operator [](uint32_t index);
			operator jlongArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jlongArray getArray()const;

		private:
			jlongArray _array;
			jlong* _arr;
			size_t _len;
	};
}


#endif
