/*************************************
 * Author: �쳬
 * Email: zhuchao1995@hotmail.com
 * Date: 2017/3/16
 * Function:
 *************************************/
#include "java.h"
namespace java {
    JString::JString(): JString("Ljava/lang/String;") {
      _method_init = _env->GetMethodID(_clazz, "<init>", "()V");
		  _object = _env->NewObject(_clazz, _method_init);

    }
    JString::JString(std::string className): JObject(className) {

    }
    JString::~JString() {

    }
}
