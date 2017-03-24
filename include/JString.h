//
// Created by ÷Ï≥¨ on 2017/3/16.
//

#ifndef BRIDGE_STRING_H
#define BRIDGE_STRING_H
#include "bridge.h"
#include "java.h"
namespace java {
    class JString: JObject {
    public:
        JString();
        virtual ~JString();

    protected:
        JString(std::string className);

	private:
		jmethodID _method_init;
    };
}
#endif //BRIDGE_STRING_H
