/*************************************************************************
	> File Name: JavaDoubleArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaDoubleArray.h"
#include "OutOfRange.h"
namespace java {
	JavaDoubleArray::JavaDoubleArray(): BridgeObject() {
		_class_name = "[D";
	}

	JavaDoubleArray::JavaDoubleArray(size_t len): JavaDoubleArray() {
		_len = len;
		_arr = new jdouble[len];
		_array = _env->NewDoubleArray(len);
		_env->SetDoubleArrayRegion(_array, 0, len, _arr);
	}

	JavaDoubleArray::JavaDoubleArray(jdoubleArray array): JavaDoubleArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jdouble[len];
				_array = _env->NewDoubleArray(len);
				jdouble* iarr = _env->GetDoubleArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jdouble) * len);
				_env->SetDoubleArrayRegion(_array, 0, len, _arr);
			}
		}
	}

	JavaDoubleArray::JavaDoubleArray(jobject obj): JavaDoubleArray(jdoubleArray(obj)) {
	}
	
	JavaDoubleArray::JavaDoubleArray(JavaDoubleArray& java_arr): JavaDoubleArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewDoubleArray(len);
			_arr = new jdouble[len];
			memcpy(_arr, java_arr._arr, sizeof(jdouble) * len);
			_env->SetDoubleArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaDoubleArray::~JavaDoubleArray() {
		//_env->ReleaseDoubleArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jdouble& JavaDoubleArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jdouble* JavaDoubleArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaDoubleArray::operator jdoubleArray() {
		return _array;
	}

	size_t JavaDoubleArray::length()const {
		return _len;
	}

	bool JavaDoubleArray::isEmpty()const {
		return _len == 0;
	}

	jdoubleArray JavaDoubleArray::getArray()const {
		return _array;
	}

}
				
			
