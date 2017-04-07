/**
 * Author: zhuchao
 * Date: 16/03/2017
 */

#ifndef COMMON_H_
#define COMMON_H_
#include <jni.h>
#include "JavaObject.h"
#include "JavaString.h"

#include "JavaIntArray.h"
#include "JavaCharArray.h"
#include "JavaByteArray.h"
#include "JavaShortArray.h"
#include "JavaBooleanArray.h"
#include "JavaLongArray.h"
#include "JavaDoubleArray.h"
#include "JavaFloatArray.h"
#include "JavaObjectArray.h"

namespace java {
typedef jint				bridge_int;
typedef jboolean			bridge_boolean;
typedef jchar				bridge_char;
typedef jbyte				bridge_byte;
typedef jlong				bridge_long;
typedef jdouble				bridge_double;
typedef jfloat				bridge_float;
typedef jshort				bridge_short;
typedef JavaString			bridge_string;
typedef JavaIntArray		bridge_int_array;
typedef JavaByteArray		bridge_byte_array;
typedef JavaCharArray		bridge_char_array;
typedef JavaShortArray		bridge_short_array;
typedef JavaBooleanArray	bridge_bool_array;
typedef JavaLongArray		bridge_long_array;
typedef JavaDoubleArray		bridge_doule_array;
typedef JavaFloatArray		bridge_float_array;
#define bridge_object_array JavaObjectArray;
}
#endif
