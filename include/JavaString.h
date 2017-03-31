/**
 * Author: zhuchao
 * Date: 16/03/2017
 */

#ifndef BRIDGE_STRING_H
#define BRIDGE_STRING_H
#include "java.h"
#include "JavaObject.h"
namespace java {
	class JavaObject;
	class JavaString: public bridge::BridgeObject {
		public:
			JavaString();
			JavaString(std::string &);
			JavaString(const char *);
			JavaString(jstring);
			JavaString(jobject);
//			JavaString(JavaString&);
			virtual ~JavaString();

		public:
			operator jobject();
			operator jstring();
			operator std::string();
			operator const char *();
			JavaString operator+(jstring);
			JavaString operator+(std::string&);
			JavaString operator+(char *);
			JavaString operator+(JavaString);
			JavaString operator+(JavaObject);
			friend std::ostream& operator<<(std::ostream&out, JavaString j_string);
			friend std::istream& operator>>(std::istream&in, JavaString j_string);

		private:
			std::string jstringTostring(jstring jstr);
			jstring stringTojstring(std::string str);
		private:
			std::string _str;
	};
}
#endif //BRIDGE_STRING_H
