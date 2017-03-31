/*************************************************************************
	> File Name: JavaCharArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_CHAR_ARRAY_H_
#define JAVA_CHAR_ARRAY_H_
#include "java.h"

namespace java {
	class JavaCharArray: public bridge::BridgeObject {
		public:
			JavaCharArray();
			JavaCharArray(size_t len);
			JavaCharArray(jcharArray);
			JavaCharArray(jobject);
			JavaCharArray(JavaCharArray&);
			~JavaCharArray();
		public:
			jchar& operator [](uint32_t index);
			//jchar* operator [](uint32_t index);
			operator jcharArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jcharArray getArray()const;

		private:
			jcharArray _array;
			jchar* _arr;
			size_t _len;
	};
}


#endif
