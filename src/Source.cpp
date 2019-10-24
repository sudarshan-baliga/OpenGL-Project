#include <GL\glut.h>
#include <stdio.h>
#include "initDisplay.h"
#include "man.h"
#include "backgroundItems.h"
#include "helicopter.h"
int viewNumber;
float timer = 0;
int t1 = 1;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

int changePos()
{
	glPushMatrix();
	glTranslated(250 - (timer++), 10 - (timer/5), 0);
	if (timer == 250)
		return 1;
	return 0;
}

int changeManPos()
{
	glPushMatrix();
	glTranslated((timer++)-100, 0, 0);
	if (timer == 100)
	{
		timer = 0;
		return 1;
	}
	return 0;
}

int changeFallPos()
{
	initMan(500, 350 - (timer++ / 2));
	if (timer == 500)
	{
		timer = 0;
		return 1;
	}
	return 0;
}
int pullMan()
{
	initMan(500, 100 + (timer++) / 2);
	if (timer == 500)
	{
		timer = 0;
		return 1;
	}
	return 0;
}
int flyAway()
{
	glPushMatrix();
	glTranslated(-(timer++), 0, 0);
	return 0;
}
void disp()
{
	drawBackground(350);
	drawRiver(250);

	if (t1 == 1)
		t1 += changeManPos();
	else if (t1 == 2)
		t1 += jumpAction();
	else if (t1 == 3)
		t1 += changeFallPos();
	else if (t1 == 5)
		t1 += pullMan();
	else if (t1 == 6)
		t1 += flyAway();

	drawMan();
	if (t1 == 1)
		glPopMatrix();
	
	riverMask(200);

	if (t1 == 4)
	{
		t1 += changePos();
		drawHelicopter();
		glPopMatrix();
	}
	else if (t1 > 4)
		drawHelicopter();

	if (t1 == 6)
		glPopMatrix();
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