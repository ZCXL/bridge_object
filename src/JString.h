//
// Created by �쳬 on 2017/3/16.
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
    };
}
#endif //BRIDGE_STRING_H
