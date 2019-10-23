output: Source.o backgroundItems.o drawText.o initDisplay.o man.o
	g++ -o output Source.o backgroundItems.o drawText.o initDisplay.o man.o -lglut -lGLU -lGL
Source.o: Source.cpp ./lib/backgroundItems.h 
	g++ Source.cpp -lglut -lGLU -lGL 
backgroundItems.o: ./lib/backgroundItems.cpp
	g++ -c ./lib/backgroundItems.cpp  -lglut -lGLU -lGL -c
drawText.o: ./lib/drawText.cpp
	g++ -c ./lib/drawText.cpp -lglut -lGLU -lGL -c
initDisplay.o: ./lib/initDisplay.cpp
	g++ -c ./lib/initDisplay.cpp -lglut -lGLU -lGL -c
man.o: ./lib/man.cpp
	g++ -c ./lib/man.cpp -lglut -lGLU -lGL -c
clear: 
	rm ./*.o || true