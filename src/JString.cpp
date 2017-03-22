/*************************************
 * Author: ÷Ï≥¨
 * Email: zhuchao1995@hotmail.com
 * Date: 2017/3/16
 * Function:
 *************************************/
#include "java.h"
namespace java {
    JString::JString(): JString("Ljava.lang.String;") {

    }
    JString::JString(std::string className): JObject(className) {

    }
    JString::~JString() {

    }
}
