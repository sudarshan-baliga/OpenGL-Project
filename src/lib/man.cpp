#include <GL/glut.h>
#include <math.h>
//struct Man
//{
	float posX, posY, 
		headWidth = 50, headHeight = 50, 
		legWidth = 30, legGap = 5, legHeight = 80, 
		upperBodyHeight = 80, upperBodyWidth,
		handWidth = 20, handSpacing = 5, handHeight = 60, 
		headSpace = 5;

	int legColor[3] = { 1, 0, 0 }, handColor[3] = { 0, 1, 0 }, bodyColor[3] = { 1, 1, 0 }, headColor[3] = {1, 1, 1},
		elbowColor[3], kneeColor[3], jointsColor[3];

	float leftLegBottom[2], leftKnee,
		rightLegBottom[2], rightKnee,
		leftHandBottom[2], leftElbow,
		rightHandBottom[2], rightElbow,
		head[2];
//}man;
	float direction, offset, distChange;
	int onceRound;

void initMan(int x, int y)
{
	direction = 1;
	offset = 0;
	onceRound = 1;
	posX = x;
	posY = y;
	upperBodyWidth = legWidth * 2 + legGap;
	leftLegBottom[0] = leftKnee = posX;
	leftLegBottom[1] = rightLegBottom[1]  = posY - legHeight;
	rightLegBottom[0] = posX + legWidth + legGap;
	rightKnee = posX + legGap + legWidth; 

	leftHandBottom[0] = posX - handWidth - handSpacing;
	leftHandBottom[1] = rightHandBottom[1] = posY;
	rightHandBottom[0] = posX + handSpacing + upperBodyWidth;
	leftElbow = posX - handWidth - handSpacing;
	rightElbow = posX + upperBodyWidth + handSpacing;

	head[0] = posX + (upperBodyWidth - headWidth) / 2;
	head[1] = posY + upperBodyHeight + headSpace;
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
	glRectd(posX, posY - offset, posX + upperBodyWidth, posY + upperBodyHeight - offset);
	
	glColor3f(headColor[0], headColor[1], headColor[2]);
	glRectd(head[0], head[1] - offset, head[0] + headWidth, head[1] + headHeight - offset);
	
	drawLimb(leftLegBottom[0], leftLegBottom[1],
		posX, posY - offset,
		leftKnee, (posY - offset + leftLegBottom[1]) / 2,
		legWidth,
		legColor);
	
	drawLimb(rightLegBottom[0], rightLegBottom[1],
		posX + legWidth + legGap, posY - offset,
		rightKnee, (posY - offset + rightLegBottom[1]) / 2,
		legWidth,
		legColor);

	drawLimb(leftHandBottom[0], leftHandBottom[1] - offset,
		posX - handWidth - handSpacing, posY + upperBodyHeight - offset,
		leftElbow, (posY + upperBodyHeight + leftHandBottom[1] - offset - offset) / 2,
		handWidth,
		handColor);

	drawLimb(rightHandBottom[0], rightHandBottom[1] - offset,
		posX + upperBodyWidth + handSpacing, posY + upperBodyHeight - offset,
		rightElbow, (posY + upperBodyHeight + rightHandBottom[1] - offset - offset) / 2,
		handWidth,
		handColor);
}

void riverMask(int y)
{
	//glColor3f(0.23, 0.70, 0.81);
	glColor3f(0.17, 0.38, 0.49);
	glRectd(leftElbow - handWidth, 0, rightElbow + handWidth, y);
}

void jumpAction()
{
	if (direction < 20)
	{
		rightElbow += 0.05;
		leftElbow -= 0.05;
		rightKnee += 0.05;
		leftKnee -= 0.05;
		direction += 0.05;
		offset += 0.05;
	}
	else if (direction < 39)
	{
		rightElbow -= 0.05;
		leftElbow += 0.05;
		rightKnee -= 0.05;
		leftKnee += 0.05;
		direction += 0.05;
		offset -= 0.1;
		leftLegBottom[1] += 0.1;
		rightLegBottom[1] += 0.1;
	}
	else if (offset < 0)
	{
		offset += 0.05;
		leftLegBottom[1] -= 0.05;
		rightLegBottom[1] -= 0.05;
	}
	else if (onceRound)
	{
		onceRound = 0;
		leftLegBottom[1] = round(leftLegBottom[1]);
		leftKnee = round(leftKnee);
		rightLegBottom[1] = round(rightLegBottom[1]);
		rightKnee = round(rightKnee);

		leftElbow = round(leftElbow);
		rightElbow = round(rightElbow);

		offset = 0;
		distChange = 0.5;
	}
	else if (offset < 300)
	{
		offset += distChange;
		leftLegBottom[1] -= distChange;
		rightLegBottom[1] -= distChange;
		distChange += 0.01;
	}
}