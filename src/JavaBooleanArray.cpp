/*************************************************************************
	> File Name: JavaBooleanArray.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Tue 28 Mar 2017 02:42:44 PM UTC
 ************************************************************************/
#include "JavaBooleanArray.h"
#include "OutOfRange.h"
namespace java {
	JavaBooleanArray::JavaBooleanArray(): BridgeObject() {
		_class_name = "[Z";
	}

	JavaBooleanArray::JavaBooleanArray(size_t len): JavaBooleanArray() {
		_len = len;
		_arr = new jboolean[len];
		_array = _env->NewBooleanArray(len);
		_env->SetBooleanArrayRegion(_array, 0, len, _arr);
	}

	JavaBooleanArray::JavaBooleanArray(jbooleanArray array): JavaBooleanArray() {
		if (array != NULL) {
			size_t len = _env->GetArrayLength(array);
			if (len > 0) {
				_len = len;
				_arr = new jboolean[len];
				_array = _env->NewBooleanArray(len);
				jboolean* iarr = _env->GetBooleanArrayElements(array, JNI_FALSE);
				memcpy(_arr, iarr, sizeof(jboolean) * len);
				_env->SetBooleanArrayRegion(_array, 0, len, _arr);
			}
		}
	}
	
	JavaBooleanArray::JavaBooleanArray(jobject obj): JavaBooleanArray(jbooleanArray(obj)) {
	}

	JavaBooleanArray::JavaBooleanArray(JavaBooleanArray& java_arr): JavaBooleanArray() {
		size_t len = java_arr.length();
		if (len > 0) {
			_len = len;
			_array = _env->NewBooleanArray(len);
			_arr = new jboolean[len];
			memcpy(_arr, java_arr._arr, sizeof(jboolean) * len);
			_env->SetBooleanArrayRegion(_array, 0, len, _arr);
		}
	}

	JavaBooleanArray::~JavaBooleanArray() {
		//_env->ReleaseBooleanArrayElements(_array, _arr, 0);
		_env->DeleteLocalRef(_array);
		delete[] _arr;
	}
	
	jboolean& JavaBooleanArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr[index];
		} else {
			throw OutOfRange();
		}
	}

	/*jboolean* JavaBooleanArray::operator [](uint32_t index) {
		if (!(index >= _len)) {
			return _arr + index;
		} else {
			return NULL;
		}
	}*/
	
	JavaBooleanArray::operator jbooleanArray() {
		return _array;
	}

	size_t JavaBooleanArray::length()const {
		return _len;
	}

	bool JavaBooleanArray::isEmpty()const {
		return _len == 0;
	}

	jbooleanArray JavaBooleanArray::getArray()const {
		return _array;
	}

}
				
			
