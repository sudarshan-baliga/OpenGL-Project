
output: ./main.o ./lib/text.o ./lib/man.o
	g++ main.o ./lib/text.o ./lib/man.o -o main.GLApp -lglut -lGLU -lGL
text: ./lib/text.cpp
	g++ -c text.cpp
man: ./lib/man.cpp
	g++ -c man.cpp
main: main.cpp
	g++ -c main.cpp
