/*************************************************************************
	> File Name: JavaFloatArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaFloatArray.h"
#include "OutOfRange.h"
namespace java {
	JavaFloatArray::JavaFloatArray(): BridgeObject() {
		_class_name = "[F";
	}

	JavaFloatArray::JavaFloatArray(size_t len): JavaFloatArray() {
		_len = len;
		_arr = new jfloat[len];
		_array = _env->NewFloatArray(len);
		_env->SetFloatArrayRegion(_array, 0, len, _arr);
	}

	JavaFloatArray::JavaFloatArray(jfloatArray array): JavaFloatArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jfloat[len];
				_array = _env->NewFloatArray(len);
				jfloat* iarr = _env->GetFloatArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jfloat) * len);
				_env->SetFloatArrayRegion(_array, 0, len, _arr);
			}
		}
	}
	
	JavaFloatArray::JavaFloatArray(jobject obj): JavaFloatArray(jfloatArray(obj)) {
	}

	JavaFloatArray::JavaFloatArray(JavaFloatArray& java_arr): JavaFloatArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewFloatArray(len);
			_arr = new jfloat[len];
			memcpy(_arr, java_arr._arr, sizeof(jfloat) * len);
			_env->SetFloatArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaFloatArray::~JavaFloatArray() {
		//_env->ReleaseFloatArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jfloat& JavaFloatArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jfloat* JavaFloatArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaFloatArray::operator jfloatArray() {
		return _array;
	}

	size_t JavaFloatArray::length()const {
		return _len;
	}

	bool JavaFloatArray::isEmpty()const {
		return _len == 0;
	}

	jfloatArray JavaFloatArray::getArray()const {
		return _array;
	}

}
				
			
