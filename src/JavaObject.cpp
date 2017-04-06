/**
 * Author: zhuchao
 * Date: 16/03/2017
 */
#include "java.h"
#include "JavaObject.h"

namespace java {
    JavaObject::JavaObject(std::string className): BridgeObject(className) {
    }

    JavaObject::~JavaObject() {

    }

	JavaObject::operator jobject() {
		return _object;
	}

	JavaString JavaObject::toString() {
		return "JavaObject";
	}

	std::ostream& operator << (std::ostream& out, JavaObject obj) {
		out << obj.toString() << std::endl;
		return out;
	}
}
