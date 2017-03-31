/*************************************
 * Author: Brother-Chao
 * Email: zhuchao1995@hotmail.com
 * Date: 2017/3/16
 * Function:
 *************************************/
#include "java.h"
#include "JavaString.h"
namespace java {
	JavaString::JavaString(): BridgeObject() {
		_class_name = "java/lang/String;";    
    }

	JavaString::JavaString(std::string& str): JavaString() {
		if (!str.empty() && str != "") {
			_str.assign(str);
		}
	}

	JavaString::JavaString(const char *c_str): JavaString() {
		if (c_str != NULL) {
			_str.assign(c_str);
		}
	}

	JavaString::JavaString(jstring java_string): JavaString() {
		if (java_string != NULL) {
			std::string tmp = jstringTostring(java_string);
			_str.assign(tmp);
		}
	}

	JavaString::JavaString(jobject obj): JavaString(jstring(obj)) {
	}

/*	JavaString::JavaString(JavaString& js): JavaString() {
		_str.assign(js._str);
	}
*/
	JavaString::~JavaString() {
	}

	JavaString::operator jobject() {
		return jobject(stringTojstring(_str));
	}

	JavaString::operator jstring() {
		return stringTojstring(_str);
	}

	JavaString::operator std::string() {
		return _str;
	}

	JavaString::operator const char*() {
		return _str.c_str();
	}

	JavaString JavaString::operator +(jstring java_string) {
		std::string tmp = jstringTostring(java_string);
		tmp = _str + tmp;
		return JavaString(tmp);
	}

	JavaString JavaString::operator +(std::string& str) {
		std::string tmp = _str + str;
		return JavaString(tmp);
	}

	JavaString JavaString::operator +(char * c_str) {
		std::string tmp(c_str);
		tmp = _str + tmp;
		return JavaString(tmp);
	}

	JavaString JavaString::operator +(JavaString j_str) {
		std::string tmp = _str + j_str._str;
		return JavaString(tmp);
	}

	JavaString JavaString::operator +(JavaObject object) {
		JavaString j_string = object.toString();
		std::string tmp = _str + j_string._str;
		return JavaString(tmp);
	}

	std::ostream& operator <<(std::ostream&out, JavaString j_string) {
		out << j_string._str;
		return out;
	}

	std::istream& operator >>(std::istream&in, JavaString j_string) {
		in >> j_string._str;
		return in;
	}

	std::string JavaString::jstringTostring(jstring jstr) {
		char *rtn = NULL;
		jclass class_string = _env->FindClass("Ljava/lang/String;");
		jstring str_encode = _env->NewStringUTF("utf-8");
		jmethodID mid = _env->GetMethodID(class_string, "getBytes", "(Ljava/lang/String;)[B");
		jbyteArray barr = (jbyteArray)_env->CallObjectMethod(jstr, mid, str_encode);
		jsize alen = _env->GetArrayLength(barr);
		jbyte* ba = _env->GetByteArrayElements(barr, JNI_FALSE);
		if (alen > 0 ) {
			rtn = (char*)malloc(alen + 1);
			memcpy(rtn, ba, alen);
			rtn[alen] = '\0';
		}

		_env->ReleaseByteArrayElements(barr, ba, 0);
		std::string tmp(rtn);
		free(rtn);
		
		return tmp;
	}

	jstring JavaString::stringTojstring(std::string str) {
		jclass str_class = _env->FindClass("Ljava/lang/String;");
		jmethodID mid = (_env)->GetMethodID(str_class, "<init>", "([BLjava/lang/String;)V");
		jbyteArray bytes = _env->NewByteArray(strlen(str.c_str()));
		_env->SetByteArrayRegion(bytes, 0, strlen(str.c_str()), (jbyte*)str.c_str());
		jstring encoding = _env->NewStringUTF("GB2312");

		return (jstring)_env->NewObject(str_class, mid, bytes, encoding);
	}
	    
}
