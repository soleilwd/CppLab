
HEADERS := $(wildcard CppLab/*.h)
SOURCES := $(wildcard CppLab/*.cpp)

all : Main

Main : $(HEADERS) $(SOURCES) 
#	echo $(HEADERS)
#	echo $(SOURCES)
	g++ -Wall -g -o Main CppLab/Main.cpp

clean:
	rm -f CppLab/*.u CppLab/*.o Main

