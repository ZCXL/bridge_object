/**
 * Author: zhuchao
 * Date: 16/03/2017
 */

#ifndef BRIDGE_OBJECT_H
#define BRIDGE_OBJECT_H
#include "bridge.h"
#include "java.h"
#include <jni.h>
namespace java {
    class JObject: public bridge::BridgeObject, public _jobject {
    public:
        JObject();
        JObject(jobject object);
        virtual ~JObject();
    protected:
        JObject(std::string className);
        virtual jobject clone();
    public:
        virtual bool equals(JObject obj);
        virtual jobject getClass();
        virtual int hashCode();
        virtual void notify();
        virtual void notifyAll();
        virtual jobject toString();
        virtual void wait();
        virtual void wait(long timeout);
        virtual void wait(long timeout, int nanos);
    protected:
        jmethodID _method_init;
        jmethodID _method_clone;
        jmethodID _method_equals;
        jmethodID _method_getClass;
        jmethodID _method_hashCode;
        jmethodID _method_notify;
        jmethodID _method_notifyAll;
        jmethodID _method_toString;
        jmethodID _method_wait;
        jmethodID _method_wait1;
        jmethodID _method_wait2;
    };
}
#endif //BRIDGE_OBJECT_H
