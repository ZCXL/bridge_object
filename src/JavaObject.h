/**
 * Author: zhuchao
 * Date: 16/03/2017
 */

#ifndef BRIDGE_OBJECT_H
#define BRIDGE_OBJECT_H
#include "java.h"
#include "JavaString.h"
namespace java {
	class JavaString;
    class JavaObject : public bridge::BridgeObject {
        public:
            virtual ~JavaObject();            
        public:
            virtual operator jobject();
        protected:
            JavaObject(std::string className);
        public:
            virtual JavaString toString();
			friend std::ostream& operator << (std::ostream& out, JavaObject obj);
    };
}
#endif //BRIDGE_OBJECT_H
