
# compiler switches
CXX := g++
CXXFLAGS += -Wall -fPIC -std=c++11
CPPFLAGS += -std=c++11 -I${EXT_DIR}/boost
ifeq ($(BUILD_CONFIG),debug)
	CXXFLAGS += -g 
endif
LDFLAGS += -shared -L${EXT_DIR}/boost/lib

# targets and rules
SOURCES := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,${SOURCES})
TARGET := $(notdir $(shell pwd))
ifeq (${PLATFORM},cygwin)
	TARGET := ${TARGET}.dll
endif
ifeq (${PLATFORM},linux)
	TARGET := lib${TARGET}.so
endif

${TARGET} : ${OBJS}
	${CXX} ${LDFLAGS} -Wl,-soname,$@ -o $@ $^

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c "$<"

%.u : %.cpp
	$(shell $(CXX) -MM $(CPPFLAGS) -c $< \
		| sed 's/$*\.o\:/$*\.o\ $@\:/g' > $@)

-include ${SOURCES:.cpp=.u}