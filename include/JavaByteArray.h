/*************************************************************************
	> File Name: JavaByteArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_BYTE_ARRAY_H_
#define JAVA_BYTE_ARRAY_H_
#include "java.h"

namespace java {
	class JavaByteArray: public bridge::BridgeObject {
		public:
			JavaByteArray();
			JavaByteArray(size_t len);
			JavaByteArray(jbyteArray);
			JavaByteArray(jobject);
			JavaByteArray(JavaByteArray&);
			~JavaByteArray();
		public:
			jbyte& operator [](uint32_t index);
//			jbyte* operator [](uint32_t index);
			operator jbyteArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jbyteArray getArray()const;

		private:
			jbyteArray _array;
			jbyte* _arr;
			size_t _len;
	};
}


#endif
