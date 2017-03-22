//
// Created by �쳬 on 2017/3/16.
//

#ifndef BRIDGE_OBJECT_H
#define BRIDGE_OBJECT_H
#include "bridge.h"
#include "java.h"
namespace java {
    class JObject: bridge::BridgeObject {
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
    private:
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
