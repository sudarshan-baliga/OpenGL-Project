#include <GL/glut.h>
#include <stdio.h>
#include "lib/initDisplay.h"
#include "lib/man.h"
#include "lib/backgroundItems.h"
#include "lib/helicopter.h"
int viewNumber;
float timer = 0;
int t1 = 1, firstChange = 1;
int showLadder = 0;
int laddery = 520, ladderx = 800;

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
	glTranslated(250 - (timer += 0.25), 10 - (timer / 5), 0);
	laddery -= (520 - 160) / 250;
	ladderx -= (800 - 550) / 250;
	if (laddery < 160)
		laddery = 160;
	if (ladderx < 550)
		ladderx = 550;
	if (timer == 250)
		return 1;
	return 0;
}

int changeManPos()
{
	glPushMatrix();
	glTranslated((timer += 0.25) - 100, 0, 0);
	if (timer == 200)
	{
		timer = 0;
		initMan(550, 350);
		return 1;
	}
	return 0;
}

int changeFallPos()
{
	initMan(550, 350 - ((timer += 0.25) / 2));
	if (timer == 500)
	{
		timer = 0;
		return 1;
	}
	return 0;
}
int pullMan()
{
	initMan(550, (timer += 0.25) / 2);
	laddery = timer / 2 + 70;
	if(laddery > 505)
		laddery = 505;
	if (timer == 1000)
	{
		timer = 0;
		return 1;
	}
	return 0;
}

void drawLadder(int x, int y, int x1, int y1)
{

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(x, y + 20);
	glVertex2f(x1, y1);
	glEnd();
}

int flyAway()
{
	glPushMatrix();
	glTranslated(-(timer += 0.25), 0, 0);
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
	{
		showLadder = 1;
		t1 += pullMan();
	}
	else if (t1 == 6) 
		t1 += flyAway();
	
	if(t1 != 6)
		drawMan();
	
	if (t1 == 1)
		glPopMatrix();
	if (t1 == 2 && firstChange == 1)
	{
		glPopMatrix();
		firstChange = 0;
	}
	riverMask(130);

	if (t1 == 4)
	{
		t1 += changePos();
		drawHelicopter();
		glPopMatrix();
		//drawLadder(ladderx, laddery, ladderx, 520);
	}
	else if (t1 > 4)
	{
		drawHelicopter();
		if(t1 != 6)
			drawLadder(550, laddery, 550, 520);
	}
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
	if (viewNumber)
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

int main(int argc, char *argv[])
{
	inits(argc, argv);
	glutMainLoop();
	return 0;
}
