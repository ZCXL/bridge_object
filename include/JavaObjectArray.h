/*************************************************************************
	> File Name: JavaObjectArray.h
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Thu 30 Mar 2017 08:41:32 AM UTC
 ************************************************************************/
#ifndef JAVA_OBJECT_ARRAY_H_
#define JAVA_OBJECT_ARRAY_H_
#include "java.h"
#include "OutOfRange.h"

namespace java {
	template<class T>
	class JavaObjectArray: public bridge::BridgeObject {
		public:
			JavaObjectArray(size_t len);
			JavaObjectArray(jobjectArray);
			JavaObjectArray(jobject);
			JavaObjectArray();
			virtual ~JavaObjectArray();
		public:
			jobject operator [](uint32_t index);
			operator jobjectArray();
		public:
			size_t length()const;
			bool isEmpty()const;
			jobjectArray getArray()const;

		private:
			jobjectArray _array;
			jobject* _arr;
			size_t _len;
			std::string _className;
	};
	template<class T>
	JavaObjectArray<T>::JavaObjectArray(): BridgeObject() {
		T a;
		std::string className = a.getClassName();
		_class_name = "[" + className;
		_className = className;
		_clazz = _env->FindClass(className.c_str());
		_len = 0;
	}

	template<class T>
	JavaObjectArray<T>::JavaObjectArray(size_t len): JavaObjectArray() {
		_len = len;
		_array = _env->NewObjectArray(len, _clazz, NULL);
		_arr = new jobject[len];
		for (int i = 0; i < len; i++) {
			jobject tmp = NULL;
			if (_className.compare(0, 1, "[") != 0) {
				tmp = _env->AllocObject(_clazz);
				_arr[i] = tmp;
				_env->SetObjectArrayElement(_array, i, _arr[i]);
			}
		}
	}

	template<class T>
	JavaObjectArray<T>::JavaObjectArray(jobjectArray array): JavaObjectArray() {
		if (array != NULL) {
		    size_t len = _env->GetArrayLength(array);
			if (len > 0) {
			    _len = len;
			    _array = _env->NewObjectArray(len, _clazz, NULL);
			    _arr = new jobject[len];
			    for (int i = 0; i < len; i++) {
					_arr[i] = _env->GetObjectArrayElement(array, i);
					_env->SetObjectArrayElement(_array, i, _arr[i]);
			    }
			}
		}
	}

	template<class T>
	JavaObjectArray<T>::JavaObjectArray(jobject obj): JavaObjectArray(jobjectArray(obj)) {
	}

	template<class T>
	JavaObjectArray<T>::~JavaObjectArray() {
	    delete[] _arr;
	}

	template<class T>
	jobject JavaObjectArray<T>::operator [](uint32_t index) {
		if (index < _len) {
		    return _arr[index];
		} else {
		    throw OutOfRange();
		}
	}

	template<class T>
	JavaObjectArray<T>::operator jobjectArray() {
	    return _array;
	}

	template<class T>
	size_t JavaObjectArray<T>::length()const {
		return _len;
	}

	template<class T>
	bool JavaObjectArray<T>::isEmpty()const {
		return _len == 0;
	}

	template<class T>
	jobjectArray JavaObjectArray<T>::getArray()const {
		return _array;
	}
}

#endif

