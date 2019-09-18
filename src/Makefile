
output: ./main.o ./lib/text.o
	g++ main.o ./lib/text.o -o main.GLApp -lglut -lGLU -lGL
text: ./lib/text.cpp
	g++ -c text.cpp
main: main.cpp
	g++ -c main.cpp
