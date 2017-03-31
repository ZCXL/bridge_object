/*************************************************************************
	> File Name: JavaShortArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaShortArray.h"
#include "OutOfRange.h"
namespace java {
	JavaShortArray::JavaShortArray(): BridgeObject() {
		_class_name = "[S";
	}

	JavaShortArray::JavaShortArray(size_t len): JavaShortArray() {
		_len = len;
		_arr = new jshort[len];
		_array = _env->NewShortArray(len);
		_env->SetShortArrayRegion(_array, 0, len, _arr);
	}

	JavaShortArray::JavaShortArray(jshortArray array): JavaShortArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jshort[len];
				_array = _env->NewShortArray(len);
				jshort* iarr = _env->GetShortArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jshort) * len);
				_env->SetShortArrayRegion(_array, 0, len, _arr);
			}
		}
	}

	JavaShortArray::JavaShortArray(jobject obj): JavaShortArray(jshortArray(obj)) {
	}
	
	JavaShortArray::JavaShortArray(JavaShortArray& java_arr): JavaShortArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewShortArray(len);
			_arr = new jshort[len];
			memcpy(_arr, java_arr._arr, sizeof(jshort) * len);
			_env->SetShortArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaShortArray::~JavaShortArray() {
		_env->ReleaseShortArrayElements(_array, _arr, 0);
		delete[] _arr;
	}
	
	jshort& JavaShortArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jshort* JavaShortArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaShortArray::operator jshortArray() {
		return _array;
	}

	size_t JavaShortArray::length()const {
		return _len;
	}
	
	bool JavaShortArray::isEmpty()const {
		return _len == 0;
	}

	jshortArray JavaShortArray::getArray()const {
		return _array;
	}

}
				
			
