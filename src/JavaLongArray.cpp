/*************************************************************************
	> File Name: JavaLongArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaLongArray.h"
#include "OutOfRange.h"
namespace java {
	JavaLongArray::JavaLongArray(): BridgeObject() {
		_class_name = "[L";
	}

	JavaLongArray::JavaLongArray(size_t len): JavaLongArray() {
		_len = len;
		_arr = new jlong[len];
		_array = _env->NewLongArray(len);
		_env->SetLongArrayRegion(_array, 0, len, _arr);
	}

	JavaLongArray::JavaLongArray(jlongArray array): JavaLongArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jlong[len];
				_array = _env->NewLongArray(len);
				jlong* iarr = _env->GetLongArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jlong) * len);
				_env->SetLongArrayRegion(_array, 0, len, _arr);
			}
		}
	}

	JavaLongArray::JavaLongArray(jobject obj): JavaLongArray(jlongArray(obj)) {
	}
	
	JavaLongArray::JavaLongArray(JavaLongArray& java_arr): JavaLongArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewLongArray(len);
			_arr = new jlong[len];
			memcpy(_arr, java_arr._arr, sizeof(jlong) * len);
			_env->SetLongArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaLongArray::~JavaLongArray() {
		//_env->ReleaseLongArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jlong& JavaLongArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jlong* JavaLongArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaLongArray::operator jlongArray() {
		return _array;
	}

	size_t JavaLongArray::length()const {
		return _len;
	}

	bool JavaLongArray::isEmpty()const {
		return _len == 0;
	}

	jlongArray JavaLongArray::getArray()const {
		return _array;
	}

}
				
			
