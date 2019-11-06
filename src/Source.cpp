#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "lib/initDisplay.h"
#include "lib/man.h"
#include "lib/man2.h"
#include "lib/backgroundItems.h"
#include "lib/helicopter.h"
int viewNumber;
float timer = 0;
int t1 = 1, firstChange = 1;
int laddery = 520, ladderx = 800;
float splashRad = 0, drawSplash = 0;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void drawSemiCircle1(float radius, int x, int y)
{
	//glColor3f(0.23, 0.7, 0.81);
	glColor3f(0, 0.5, 1);
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = 0; i < 3.14; i += 0.001)
	{
		glVertex2f(cos(i)*radius + x, 0.75*sin(i)*radius + y);
	}
	glEnd();
	glPointSize(1);
}

void drawSemiCircle2(float radius, int x, int y)
{
	//glColor3f(0.23, 0.7, 0.81);
	glColor3f(0, 0.5, 1);
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = 3.14; i < 6.28; i += 0.001)
	{
		glVertex2f(cos(i)*radius + x, 0.75*sin(i)*radius + y);
	}
	glEnd();
	glPointSize(1);
}

void DrawSplashHalf1()
{
	if (splashRad == 120)
		return;
	if (splashRad < 80)
		drawSemiCircle1(splashRad, 570, 130);
	if (splashRad > 40)
		drawSemiCircle1(splashRad - 40, 570, 130);
}
void DrawSplashHalf2()
{
	if (splashRad == 120)
	{
		drawSplash = 0;
		splashRad = 0;
		return;
	}
	if (splashRad < 80)
		drawSemiCircle2(splashRad, 570, 130);
	if (splashRad > 40)
		drawSemiCircle2(splashRad - 40, 570, 130);
	splashRad += 0.25;
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
	initMan(300 + (timer += 0.25), 350);
	if (timer == 250)
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
	if (timer == 360)
		drawSplash = 1;
	if (timer == 500)
	{
		timer = 0;
		return 1;
	}
	return 0;
}
int pullMan()
{
	initMan(550, (timer += 0.25) / 2 + 170);
	laddery = timer / 2 + 70 + 175;
	if (laddery > 545)
	{
		timer = 0;
		return 1;
	}
	return 0;
}

int dropLadder()
{
	showRescuer = false;
	laddery = 600 - (timer += 0.25) / 2;
	if (laddery < 175)
	{
		timer = 0;
		setHandLeft(1);
		return 1;
	}
	return 0;
}

void drawLadder(int x, int y, int x1, int y1)
{
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(x, y - 20);
	glVertex2f(x1, y1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 70, y - 20);
	glVertex2f(x1 + 70, y1);
	glEnd();
	for (int i = y - 10; i < y1; i += 30)
	{
		glBegin(GL_LINES);
		glVertex2f(x, i);
		glVertex2f(x + 70, i);
		glEnd();
	}
	initMan2(575, laddery - 70);
	drawMan2();
	if (laddery - 110 == 130)
	{
		splashRad = 0;
		drawSplash = 1;
	}
}

int flyAway()
{
	showRescuer =true;
	showSurvivor = true;
	glPushMatrix();
	glTranslated(-(timer += 0.25), 0, 0);
	return 0;
}
void disp()
{
	drawBackground(350);
	drawRiver(250);

	if (t1 == 1)
	{
		showRescuer = true;
		t1 += changeManPos();
		drawMan();
	}
	else if (t1 == 2)
	{
		t1 += jumpAction();
		drawMan();
	}
	else if (t1 == 3)
	{
		t1 += changeFallPos();
		if (drawSplash)
			DrawSplashHalf1();
		drawMan();
	}
	else if (t1 == 4)
	{
		if (drawSplash)
			DrawSplashHalf1();
		drawMan();
		t1 += changePos();
		drawHelicopter();
		glPopMatrix();
	}
	else if (t1 == 5)
	{
		if (drawSplash)
			DrawSplashHalf1();
		t1 += dropLadder();
		drawMan();
		drawLadder(550, laddery, 550, 520);
		drawHelicopter();
	}
	else if (t1 == 6)
	{
		if (drawSplash)
			DrawSplashHalf1();
		t1 += pullMan();
		drawMan();
		drawLadder(550, laddery, 550, 520);
		drawHelicopter();
	}
	else if (t1 == 7)
	{
		t1 += flyAway();
		drawHelicopter();
		glPopMatrix();
	}
	riverMask(130);
	if (drawSplash)
		DrawSplashHalf2();
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
		initMan(300, 350);
}

void inits(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("rescue operation using helicopter");
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
