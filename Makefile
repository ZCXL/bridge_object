PWD = $(shell pwd)
CXX := g++
LINKER := g++
CXXFLAGS := -pipe -Wall -O1 -g -fPIC -std=c++11
LIBS :=
INCLUDE :=
LINKFLAGS := -fPIC -g -shared
AR := ar
JAVA_PATH = ${JAVA_HOME}
OBJECTS = src/JavaObject.o \
	src/JavaString.o \
	src/OutOfRange.o \
	src/JavaBooleanArray.o \
	src/JavaByteArray.o \
	src/JavaCharArray.o \
	src/JavaDoubleArray.o \
	src/JavaFloatArray.o \
	src/JavaIntArray.o \
	src/JavaLongArray.o \
	src/JavaShortArray.o

CORE_DEPS = src/java.h \
			src/common.h \
			src/OutOfRange.h \
			src/JavaString.h \
			src/JavaObject.h \
			src/JavaBooleanArray.h \
			src/JavaByteArray.h \
			src/JavaCharArray.h \
			src/JavaDoubleArray.h \
			src/JavaFloatArray.h \
			src/JavaIntArray.h \
			src/JavaLongArray.h \
			src/JavaShortArray.h \
			src/JavaObjectArray.h 

DEP_INCPATH = -I$(JAVA_PATH)/include/ -I$(JAVA_PATH)/include/linux/
DEP_LDFLAGS = -L$(JAVA_PATH)/jre/lib/amd64/server/
DEP_LDLIBS = -ljvm -lbridge
INCPATH = -I src/
INSTALL_PATH = /usr/local/include/bridge_object/
default:lib/libbridge_object.so lib/libbridge_object.a
	cp src/*.h include
lib/libbridge_object.so:$(OBJECTS)
	$(LINKER) $(DEP_LDFLAGS) $(DEP_LDLIBS) $(LINKFLAGS) -o $@ $(OBJECTS)

lib/libbridge_object.a:$(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

src/JavaObject.o:$(CORE_DEPS) \
    src/JavaObject.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaObject.cpp

src/JavaString.o:$(CORE_DEPS) \
	src/JavaString.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaString.cpp

src/OutOfRange.o:$(CORE_DEPS) \
    src/OutOfRange.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/OutOfRange.cpp

src/JavaBooleanArray.o:$(CORE_DEPS) \
    src/JavaBooleanArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaBooleanArray.cpp

src/JavaByteArray.o:$(CORE_DEPS) \
    src/JavaByteArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaByteArray.cpp

src/JavaCharArray.o:$(CORE_DEPS) \
    src/JavaCharArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaCharArray.cpp

src/JavaDoubleArray.o:$(CORE_DEPS) \
    src/JavaDoubleArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaDoubleArray.cpp

src/JavaFloatArray.o:$(CORE_DEPS) \
    src/JavaFloatArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaFloatArray.cpp

src/JavaIntArray.o:$(CORE_DEPS) \
    src/JavaIntArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaIntArray.cpp

src/JavaLongArray.o:$(CORE_DEPS) \
    src/JavaLongArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaLongArray.cpp

src/JavaShortArray.o:$(CORE_DEPS) \
    src/JavaShortArray.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JavaShortArray.cpp

all:clean default

install:
	cp lib/libbridge_object.so /usr/local/lib/
	rm -rf $(INSTALL_PATH)
	mkdir -p $(INSTALL_PATH)
	cp include/* $(INSTALL_PATH)

clean:
	rm src/*.o
	rm lib/*
	rm include/*
