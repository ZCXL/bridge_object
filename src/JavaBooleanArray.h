/*************************************************************************
	> File Name: JavaBooleanArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 01:45:54 PM UTC
 ************************************************************************/
#ifndef JAVA_BOOLEAN_ARRAY_H_
#define JAVA_BOOLEAN_ARRAY_H_
#include "java.h"

namespace java {
	class JavaBooleanArray: public bridge::BridgeObject {
		public:
			JavaBooleanArray();
			JavaBooleanArray(size_t len);
			JavaBooleanArray(jbooleanArray);
			JavaBooleanArray(jobject);
			JavaBooleanArray(JavaBooleanArray&);
			~JavaBooleanArray();
		public:
			jboolean& operator [](uint32_t index);
			//jboolean* operator [](uint32_t index);
			operator jbooleanArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jbooleanArray getArray()const;

		private:
			jbooleanArray _array;
			jboolean* _arr;
			size_t _len;
	};
}


#endif
