output: Source.o backgroundItems.o drawText.o initDisplay.o man.o helicopter.o
	g++ -o output Source.o backgroundItems.o drawText.o initDisplay.o man.o helicopter.o -lglut -lGLU -lGL
Source.o: Source.cpp ./lib/backgroundItems.h ./lib/helicopter.h ./lib/drawText.h ./lib/initDisplay.h ./lib/man.h
	g++ Source.cpp -lglut -lGLU -lGL -c
backgroundItems.o: ./lib/backgroundItems.cpp
	g++ -c ./lib/backgroundItems.cpp  -lglut -lGLU -lGL -c
drawText.o: ./lib/drawText.cpp
	g++ -c ./lib/drawText.cpp -lglut -lGLU -lGL -c
initDisplay.o: ./lib/initDisplay.cpp
	g++ -c ./lib/initDisplay.cpp -lglut -lGLU -lGL -c
man.o: ./lib/man.cpp
	g++ -c ./lib/man.cpp -lglut -lGLU -lGL -c
helicopter.o: ./lib/helicopter.cpp
	g++ -c ./lib/helicopter.cpp -lglut -lGLU -lGL -c
clear: 
	rm ./*.o || true