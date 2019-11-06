#include <GL/glut.h>
#include <math.h>
//struct Man
//{
float pos2X, pos2Y,
headWidth2 = 25, headHeight2 = 25,
legWidth2 = 15, legGap2 = 2.5, legHeight2 = 40,
upperBodyHeight2 = 40, upperBodyWidth2,
handWidth2 = 10, handSpacing2 = 2.5, handHeight2 = 30,
headSpace2 = 2.5;

float legColor2[3] = { 1, 0, 0 }, handColor2[3] = { 255 / 255.0,192 / 255.0,203 / 255.0 }, 
bodyColor2[3] = { 0, 0, 1}, headColor2[3] = { 1, 1, 1 },
elbowColor2[3], kneeColor2[3], jointsColor2[3];

float leftLegBottom2[2], leftKnee2,
rightLegBottom2[2], rightKnee2,
leftHandBottom2[2], leftElbow2,
rightHandBottom2[2], rightElbow2,
head2[2];
//}man;
float direction2, offset2, distChange2;
int onceRound2, handLeft = 0;
int dh = 0; //drawing hand

void initMan2(int x, int y)
{
	direction2 = 1;
	offset2 = 0;
	onceRound2 = 1;
	pos2X = x;
	pos2Y = y;
	upperBodyWidth2 = legWidth2 * 2 + legGap2;
	leftLegBottom2[0] = leftKnee2 = pos2X;
	leftLegBottom2[1] = rightLegBottom2[1] = pos2Y - legHeight2;
	rightLegBottom2[0] = pos2X + legWidth2 + legGap2;
	rightKnee2 = pos2X + legGap2 + legWidth2;

	leftHandBottom2[0] = pos2X - handWidth2 - handSpacing2;
	leftHandBottom2[1] = rightHandBottom2[1] = pos2Y;
	rightHandBottom2[0] = pos2X + handSpacing2 + upperBodyWidth2;
	leftElbow2 = pos2X - handWidth2 - handSpacing2;
	rightElbow2 = pos2X + upperBodyWidth2 + handSpacing2;

	head2[0] = pos2X + (upperBodyWidth2 - headWidth2) / 2;
	head2[1] = pos2Y + upperBodyHeight2 + headSpace2;
}

void drawPolygon2(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, float color2[3])
{
	glColor3fv(color2);
	glBegin(GL_POLYGON);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawLimb2(int x0, int y0, int x1, int y1, int x2, int y2, int width2, float color2[3])
{
	drawPolygon2(x0, y0, x0 + width2, y0,
		x2 + width2, y2, x2, y2,
		color2);
	drawPolygon2(x1, y1, x1 + width2, y1,
		x2 + width2, y2, x2, y2,
		color2);
}
void drawMan2()
{
	glColor3fv(bodyColor2);
	glRectd(pos2X, pos2Y - offset2, pos2X + upperBodyWidth2, pos2Y + upperBodyHeight2 - offset2);

	glColor3fv(headColor2);
	glRectd(head2[0], head2[1] - offset2, head2[0] + headWidth2, head2[1] + headHeight2 - offset2);

	drawLimb2(leftLegBottom2[0], leftLegBottom2[1],
		pos2X, pos2Y - offset2,
		leftKnee2, (pos2Y - offset2 + leftLegBottom2[1]) / 2,
		legWidth2,
		legColor2);

	drawLimb2(rightLegBottom2[0], rightLegBottom2[1],
		pos2X + legWidth2 + legGap2, pos2Y - offset2,
		rightKnee2, (pos2Y - offset2 + rightLegBottom2[1]) / 2,
		legWidth2,
		legColor2);


	int temp = handHeight2;

	if (handLeft)
	{
		glColor3fv(handColor2);
		glRectf(pos2X - handSpacing2, pos2Y + upperBodyHeight2,
			pos2X - handSpacing2 - handHeight2, pos2Y + upperBodyHeight2 - handWidth2);
	}
	else
		drawLimb2(leftHandBottom2[0], leftHandBottom2[1] - offset2 + temp,
			pos2X - handWidth2 - handSpacing2, pos2Y + upperBodyHeight2 - offset2 + temp,
			leftElbow2, (pos2Y + upperBodyHeight2 + leftHandBottom2[1] - offset2 - offset2) / 2 + temp,
			handWidth2,
			handColor2);
	

	drawLimb2(rightHandBottom2[0], rightHandBottom2[1] - offset2 + temp,
		pos2X + upperBodyWidth2 + handSpacing2, pos2Y + upperBodyHeight2 - offset2 + temp,
		rightElbow2, (pos2Y + upperBodyHeight2 + rightHandBottom2[1] - offset2 - offset2) / 2 + temp,
		handWidth2,
		handColor2);
}

void setHandLeft(int x)
{
	handLeft = x;
}