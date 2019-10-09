#include <GL\glut.h>
#include <stdio.h>
#include "initDisplay.h"
#include "man.h"
#include "backgroundItems.h"

int viewNumber;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void disp()
{
	drawBackground(350);
	drawRiver(250);
	jumpAction();
	drawMan();
	riverMask(200);
}

void render()
{
	glutPostRedisplay();
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (viewNumber == 0)
		displayInfo();
	else if (viewNumber)
		disp();
	glFlush();
}

void keyFunc(unsigned char key, int x, int y)
{
	viewNumber += 1;
	if(viewNumber)
		initMan(500, 350);
}

void inits(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flood Rescue");
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);
	glutKeyboardFunc(keyFunc);
	glPointSize(1);
}

int main(int argc, char* argv[]) 
{
	inits(argc, argv);
	glutMainLoop();
	return 0;
}