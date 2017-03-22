PWD = $(shell pwd)
CXX := g++
LINKER := g++
CXXFLAGS := -pipe -Wall -O2 -g -fPIC -std=c++11
LIBS :=
INCLUDE :=
LINKFLAGS := -fPIC -shared
AR := ar
JAVA_PATH = ${JAVA_HOME}
OBJECTS = src/JString.o \
	src/JObject.o

CORE_DEPS = src/java.h \
	src/JString.h \
	src/JObject.h

DEP_INCPATH = -I$(JAVA_PATH)/include/ -I$(JAVA_PATH)/include/linux/
DEP_LDFLAGS = -L$(JAVA_PATH)/jre/lib/amd64/server/ -L$(BRIDGE_PATH)/lib/
DEP_LDLIBS = -ljvm -lbridge
INCPATH = -I src/
default:lib/libbridge_object.so lib/libbridge_object.a
	cp src/java.h include/
	cp src/JObject.h include/
	cp src/JString.h include/

lib/libbridge_object.so:$(OBJECTS)
	$(LINKER) $(DEP_LDFLAGS) $(DEP_LDLIBS) $(LINKFLAGS) -o $@ $(OBJECTS)

lib/libbridge_object.a:$(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

src/JString.o:$(CORE_DEPS) \
	src/JString.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JString.cpp

src/JObject.o:$(CORE_DEPS) \
    src/JObject.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/JObject.cpp

all:clean default

install:
	cp lib/libbridge_object.so /usr/local/lib/
	cp include/* /usr/local/include/

clean:
	rm src/*.o
	rm lib/*
	rm include/*
