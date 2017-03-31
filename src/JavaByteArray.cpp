/*************************************************************************
	> File Name: JavaByteArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaByteArray.h"
#include "OutOfRange.h"
namespace java {
	JavaByteArray::JavaByteArray(): BridgeObject() {
		_class_name = "[B";
	}

	JavaByteArray::JavaByteArray(size_t len): JavaByteArray() {
		_len = len;
		_arr = new jbyte[len];
		_array = _env->NewByteArray(len);
		_env->SetByteArrayRegion(_array, 0, len, _arr);
	}

	JavaByteArray::JavaByteArray(jbyteArray array): JavaByteArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jbyte[len];
				_array = _env->NewByteArray(len);
				jbyte* iarr = _env->GetByteArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jbyte) * len);
				_env->SetByteArrayRegion(_array, 0, len, _arr);
			}
		}
	}

	JavaByteArray::JavaByteArray(jobject obj): JavaByteArray(jbyteArray(obj)){
	}
	
	JavaByteArray::JavaByteArray(JavaByteArray& java_arr): JavaByteArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewByteArray(len);
			_arr = new jbyte[len];
			memcpy(_arr, java_arr._arr, sizeof(jbyte) * len);
			_env->SetByteArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaByteArray::~JavaByteArray() {
		//_env->ReleaseByteArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jbyte& JavaByteArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jbyte* JavaByteArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaByteArray::operator jbyteArray() {
		return _array;
	}

	size_t JavaByteArray::length()const {
		return _len;
	}

	bool JavaByteArray::isEmpty()const {
		return _len == 0;
	}

	jbyteArray JavaByteArray::getArray()const {
		return _array;
	}

}
				
			
