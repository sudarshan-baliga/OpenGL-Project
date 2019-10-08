#include <GL/glut.h>

//struct Man
//{
	float posX, posY, 
		headWidth = 40, headHeight = 40, 
		legWidth = 30, legGap = 5, legHeight = 80, 
		upperBodyHeight = 80, 
		handWidth = 20, handSpacing = 5, handHeight = 60, upperBodyWidth;
	int legColor[3] = { 1, 0, 0 }, handColor[3] = { 0, 1, 0 }, bodyColor[3] = { 1, 1, 0 }, headColor[3] = {1, 1, 1},
		elbowColor[3], kneeColor[3], jointsColor[3];

	float leftLegBottom[2], leftKnee[2],
		rightLegBottom[2], rightKnee[2],
		leftHandBottom[2], leftElbow[2],
		rightHandBottom[2], rightElbow[2];
//}man;
	float direction = 1;

void initMan(int x, int y)
{
	posX = x;
	posY = y;
	upperBodyWidth = legWidth * 2 + legGap;
	leftLegBottom[0] = leftKnee[0] = posX;
	leftLegBottom[1] = rightLegBottom[1]  = posY - legHeight;
	rightLegBottom[0] = posX + legWidth + legGap;
	leftKnee[1] = rightKnee[1] = posY - legHeight / 2;
	rightKnee[0] = posX + legGap + legWidth; 

	leftHandBottom[0] = posX - handWidth - handSpacing;
	leftHandBottom[1] = rightHandBottom[1] = posY;
	rightHandBottom[0] = posX + handSpacing + upperBodyWidth;
	leftElbow[0] = posX - handWidth - handSpacing;
	leftElbow[1] = rightElbow[1] = posY + handHeight / 2;
	rightElbow[0] = posX + upperBodyWidth + handSpacing;
}

void drawPolygon(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int color[3])
{
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawLimb(int x0, int y0, int x1, int y1, int x2, int y2, int width, int color[3])
{
	drawPolygon(x0, y0, x0 + width, y0,
		x2 + width, y2, x2, y2,
		color);
	drawPolygon(x1, y1, x1 + width, y1,
		x2 + width, y2, x2, y2,
		color);
}
void drawMan()
{
	glColor3f(bodyColor[0], bodyColor[1], bodyColor[2]);
	glRectd(posX, posY, posX + upperBodyWidth, posY + upperBodyHeight);

	
	drawLimb(leftLegBottom[0], leftLegBottom[1],
		posX, posY,
		leftKnee[0], leftKnee[1],
		legWidth,
		legColor);
	
	drawLimb(rightLegBottom[0], rightLegBottom[1],
		posX + legWidth + legGap, posY,
		rightKnee[0], rightKnee[1],
		legWidth,
		legColor);

	drawLimb(leftHandBottom[0], leftHandBottom[1],
		posX - handWidth - handSpacing, posY + upperBodyHeight,
		leftElbow[0], leftElbow[1],
		handWidth,
		handColor);

	drawLimb(rightHandBottom[0], rightHandBottom[1],
		posX + upperBodyWidth + handSpacing, posY + upperBodyHeight,
		rightElbow[0], rightElbow[1],
		handWidth,
		handColor);

	glFlush();
}

void jumpAction()
{
	if (direction < 20)
	{
		rightElbow[0] += 0.05;
		leftElbow[0] -= 0.05;
		rightKnee[0] += 0.05;
		leftKnee[0] -= 0.05;
		direction += 0.05;
	}
}