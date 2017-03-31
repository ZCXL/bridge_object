/*************************************************************************
	> File Name: JavaFloatArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_FLOAT_ARRAY_H_
#define JAVA_FLOAT_ARRAY_H_
#include "java.h"

namespace java {
	class JavaFloatArray: public bridge::BridgeObject {
		public:
			JavaFloatArray();
			JavaFloatArray(size_t len);
			JavaFloatArray(jfloatArray);
			JavaFloatArray(jobject);
			JavaFloatArray(JavaFloatArray&);
			~JavaFloatArray();
		public:
			jfloat& operator [](uint32_t index);
	//		jfloat* operator [](uint32_t index);
			operator jfloatArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jfloatArray getArray()const;

		private:
			jfloatArray _array;
			jfloat* _arr;
			size_t _len;
	};
}


#endif
