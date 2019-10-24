#include <GL/glut.h>

void drawRiver(int y)
{
	//glColor3f(0.23, 0.70, 0.81);
	glColor3f(0.17, 0.38, 0.49);
	glRectd(0, 0, glutGet(GLUT_WINDOW_WIDTH), y);
}
void drawLand(int y)
{
	//glColor3f(0.6, 0.46, 0.32);
	//glColor3f(0.64, 0.46, 0.29);
	glColor3f(0.51, 0.36, 0.23);
	glRectd(0, 0, glutGet(GLUT_WINDOW_WIDTH), y);
}
void drawBackground(int y)
{
	glColor3f(0.39, 0.84, 1);
	glRectd(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	drawLand(y);
}