/*************************************************************************
	> File Name: JavaIntArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaIntArray.h"
#include "OutOfRange.h"
namespace java {
	JavaIntArray::JavaIntArray(): BridgeObject() {
		_class_name = "[I";
	}

	JavaIntArray::JavaIntArray(size_t len): JavaIntArray() {
		_len = len;
		_arr = new jint[len];
		_array = _env->NewIntArray(len);
		_env->SetIntArrayRegion(_array, 0, len, _arr);
	}

	JavaIntArray::JavaIntArray(jintArray array): JavaIntArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jint[len];
				_array = _env->NewIntArray(len);
				jint* iarr = _env->GetIntArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jint) * len);
				_env->SetIntArrayRegion(_array, 0, len, _arr);
			}
		}
	}

	JavaIntArray::JavaIntArray(jobject obj): JavaIntArray(jintArray(obj)) {
	}
	
	JavaIntArray::JavaIntArray(JavaIntArray& java_arr): JavaIntArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewIntArray(len);
			_arr = new jint[len];
			memcpy(_arr, java_arr._arr, sizeof(jint) * len);
			_env->SetIntArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaIntArray::~JavaIntArray() {
//		_env->ReleaseIntArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jint& JavaIntArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jint* JavaIntArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaIntArray::operator jintArray() {
		return _array;
	}

	size_t JavaIntArray::length()const {
		return _len;
	}
	
	bool JavaIntArray::isEmpty()const {
		return _len == 0;
	}

	jintArray JavaIntArray::getArray()const {
		return _array;
	}

}
				
			
