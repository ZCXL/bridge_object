/**
 * Author: zhuchao
 * Date: 16/03/2017
 */
#include "bridge.h"
#include "java.h"
#include "JObject.h"

namespace java {
    JObject::JObject(): JObject("Ljava/lang/Object;") {
        _method_init = _env->GetMethodID(_clazz, "<init>", "()V");
        _object = _env->NewObject(_clazz, _method_init);
        _method_clone = NULL;
        _method_equals = NULL;
        _method_getClass = NULL;
		_method_hashCode = NULL;
		_method_notify = NULL;
		_method_notifyAll = NULL;
		_method_toString = NULL;
		_method_wait = NULL;
		_method_wait1 = NULL;
		_method_wait2 = NULL;
    }
    JObject::JObject(jobject object): JObject("Ljava/lang/Object;") {
        if (object != NULL) {
            _object = object;
        }
    }

    JObject::JObject(std::string className): BridgeObject(className) {
    }

    JObject::~JObject() {

    }

    jobject JObject::clone() {
        if (_method_clone == NULL) {
            _method_clone = _env->GetMethodID(_clazz, "clone", "()Ljava/lang/Object;");
        }
        jobject clone_object = _env->CallObjectMethod(_object, _method_clone);
        return clone_object;
    }

    bool JObject::equals(JObject obj) {
        if (_method_equals == NULL) {
            _method_equals = _env->GetMethodID(_clazz, "equals", "(Ljava/lang/Object;)Z");
        }
        jboolean ret = _env->CallBooleanMethod(_object, _method_equals, obj._object);
        return (bool)ret;
    }

    jobject JObject::getClass() {
        if (_method_getClass == NULL) {
            _method_getClass = _env->GetMethodID(_clazz, "getClass", "()Ljava/lang/Class;");
        }
        jobject class_object = _env->CallObjectMethod(_object, _method_getClass);
        return class_object;
    }

    int JObject::hashCode() {
        if (_method_hashCode == NULL) {
            _method_hashCode = _env->GetMethodID(_clazz, "hashCode", "()I");
        }
        jint ret = _env->CallIntMethod(_object, _method_hashCode);
        return (int)ret;
    }

    void JObject::notify() {
        if (_method_notify == NULL) {
            _method_notify = _env->GetMethodID(_clazz, "notify", "()V");
        }
        _env->CallIntMethod(_object, _method_notify);
    }

    void JObject::notifyAll() {
        if (_method_notifyAll == NULL) {
            _method_notifyAll = _env->GetMethodID(_clazz, "notifyAll", "()V");
        }
        _env->CallIntMethod(_object, _method_notifyAll);
    }

    jobject JObject::toString() {
        if (_method_toString == NULL) {
            _method_toString = _env->GetMethodID(_clazz, "toString", "()Ljava/lang/String;");
        }
        jobject to_string_object = _env->CallObjectMethod(_object, _method_toString);
        return to_string_object;
    }

    void JObject::wait() {
        if (_method_wait == NULL) {
            _method_wait = _env->GetMethodID(_clazz, "wait", "()V");
        }
        _env->CallVoidMethod(_object, _method_wait);
    }

    void JObject::wait(long timeout) {
        if (_method_wait1 == NULL) {
            _method_wait1 = _env->GetMethodID(_clazz, "wait", "(J)V");
        }
        _env->CallVoidMethod(_object, _method_wait1);
    }

    void JObject::wait(long timeout, int nanos) {
        if (_method_wait2 == NULL) {
            _method_wait2 = _env->GetMethodID(_clazz, "wait", "(JI)V");
        }
        _env->CallVoidMethod(_object, _method_wait2);
    }

}
