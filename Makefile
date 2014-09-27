
all : Main

Main : CppLab/Main.cpp
	g++ -Wall -g -o Main CppLab/Main.cpp

clean:
	rm -f CppLab/*.u CppLab/*.o Main

