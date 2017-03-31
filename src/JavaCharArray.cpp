/*************************************************************************
	> File Name: JavaCharArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaCharArray.h"
#include "OutOfRange.h"
namespace java {
	JavaCharArray::JavaCharArray(): BridgeObject() {
		_class_name = "[C";
	}

	JavaCharArray::JavaCharArray(size_t len): JavaCharArray() {
		_len = len;
		_arr = new jchar[len];
		_array = _env->NewCharArray(len);
		_env->SetCharArrayRegion(_array, 0, len, _arr);
	}

	JavaCharArray::JavaCharArray(jcharArray array): JavaCharArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jchar[len];
				_array = _env->NewCharArray(len);
				jchar* iarr = _env->GetCharArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jchar) * len);
				_env->SetCharArrayRegion(_array, 0, len, _arr);
			}
		}
	}
	
	JavaCharArray::JavaCharArray(jobject obj): JavaCharArray(jcharArray(obj)) {
	}
	
	JavaCharArray::JavaCharArray(JavaCharArray& java_arr): JavaCharArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewCharArray(len);
			_arr = new jchar[len];
			memcpy(_arr, java_arr._arr, sizeof(jchar) * len);
			_env->SetCharArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaCharArray::~JavaCharArray() {
		//_env->ReleaseCharArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jchar& JavaCharArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jchar* JavaCharArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaCharArray::operator jcharArray() {
		return _array;
	}

	size_t JavaCharArray::length()const {
		return _len;
	}

	bool JavaCharArray::isEmpty()const {
		return _len == 0;
	}

	jcharArray JavaCharArray::getArray()const {
		return _array;
	}

}
				
			
