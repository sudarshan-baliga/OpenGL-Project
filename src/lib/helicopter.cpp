#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
int tailX, frontX, topY, botY, tailWidth, tailLength, segmentWidth, windSheildGap, bladeLength, bladeWidth;
bool showRescuer, showSurvivor;

void drawCircle(float radius, int x, int y)
{
	//glColor3f(0.23, 0.7, 0.81);
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = 0; i < 2 * 3.14; i += 0.001)
	{
		glVertex2f(cos(i)*radius + x, 0.75*sin(i)*radius + y);
	}
	glEnd();
	glPointSize(1);
}

void drawHelicopterSkeleton(int midX, int midY, int scale)
{
	tailX = midX + 0.3 * scale;
	frontX = midX - 0.4 * scale;
	topY = midY + 0.1 * scale;
	botY = midY - 0.07 * scale;
	tailWidth = (topY - botY) / 4;
	segmentWidth = (midX - frontX) / 3;
	windSheildGap = 7;
	//front portion body
	glColor3ub(223, 86, 68);
	glBegin(GL_POLYGON);
	glVertex2f(frontX, midY);
	glVertex2f(frontX, midY + tailWidth / 2);
	glVertex2f(frontX + segmentWidth, topY);
	glVertex2f(frontX + 2 * segmentWidth, topY);
	glVertex2f(midX, midY + tailWidth / 2);
	glVertex2f(midX, midY - tailWidth / 2);
	glVertex2f(frontX + 2 * segmentWidth, botY);
	glVertex2f(frontX + segmentWidth, botY);
	glVertex2f(frontX, midY - tailWidth / 2);
	glEnd();
	//tail
	glBegin(GL_POLYGON);
	glVertex2f(midX, midY);
	glVertex2f(midX, midY + tailWidth / 2);
	glVertex2f(tailX, midY + tailWidth / 5);
	glVertex2f(tailX, midY - tailWidth / 5);
	glVertex2f(midX, midY - tailWidth / 2);
	glEnd();

	//tailExtension
	glBegin(GL_POLYGON);
	glVertex2f(tailX, midY + tailWidth / 5);
	glVertex2f(tailX + tailWidth / 5, midY + tailWidth);
	glVertex2f(tailX + tailWidth, midY + tailWidth);
	glVertex2f(tailX, midY - tailWidth / 5);
	glEnd();
	
	//windShields
	glColor3ub(51, 79, 93);
	glBegin(GL_POLYGON);
	glVertex2f(frontX + 2 * windSheildGap, midY + windSheildGap);
	glVertex2f(frontX + segmentWidth - windSheildGap / 2, topY - windSheildGap);
	glVertex2f(frontX + segmentWidth - windSheildGap / 2, midY + windSheildGap);
	glEnd();
	//pilot
	glColor3ub(0, 0, 1);
	glBegin(GL_POLYGON);
		glVertex2f(frontX + segmentWidth / 2 + 3, midY + windSheildGap);
		glVertex2f(frontX + segmentWidth / 2 + 3, midY + windSheildGap + 15);
		glVertex2f(frontX + segmentWidth - windSheildGap / 2 - 6, midY + windSheildGap + 15);
		glVertex2f(frontX + segmentWidth - windSheildGap / 2 - 6, midY + windSheildGap);
	glEnd();
	//eyes
	glColor3ub(255, 255, 255);
	drawCircle(1, frontX + segmentWidth / 2 + 6, midY + 15);
	drawCircle(1, frontX + segmentWidth - windSheildGap / 2 - 10, midY + 15);
	glColor3ub(51, 79, 93);
	
	//windsheld 2
	glBegin(GL_POLYGON);
	glVertex2f(frontX + segmentWidth, topY - windSheildGap);
	glVertex2f(frontX + 2 * segmentWidth - windSheildGap / 2, topY - windSheildGap);
	glVertex2f(frontX + 2 * segmentWidth - windSheildGap / 2, midY + windSheildGap);
	glVertex2f(frontX + segmentWidth, midY + windSheildGap);
	glEnd();
	if(showRescuer) 
	{
		//rescuer
		glColor3ub(1, 0, 0);
		glBegin(GL_POLYGON);
			glVertex2f(frontX + segmentWidth  + 8 , midY + windSheildGap);
			glVertex2f(frontX + segmentWidth  + 8, midY + windSheildGap + 15);
			glVertex2f(frontX + segmentWidth  + 25, midY + windSheildGap + 15);
			glVertex2f(frontX + segmentWidth  + 25, midY + windSheildGap);
		glEnd();
		//rescuer eyes
		glColor3ub(255, 255, 255);
		drawCircle(1, frontX + segmentWidth  + 14,  midY + windSheildGap + 8);
		drawCircle(1, frontX + segmentWidth  + 24,  midY + windSheildGap + 8);
		glColor3ub(51, 79, 93);
	}
	//survivor
	if(showSurvivor)
	{
		glColor3ub(0, 0, 0);
		glBegin(GL_POLYGON);
			glVertex2f(frontX + segmentWidth  + 38 , midY + windSheildGap);
			glVertex2f(frontX + segmentWidth  + 38, midY + windSheildGap + 15);
			glVertex2f(frontX + segmentWidth  + 55, midY + windSheildGap + 15);
			glVertex2f(frontX + segmentWidth  + 55, midY + windSheildGap);
		glEnd();
		// survivor eyes
		glColor3ub(255, 255, 255);
		drawCircle(1, frontX + segmentWidth  + 44,  midY + windSheildGap + 8);
		drawCircle(1, frontX + segmentWidth  + 54,  midY + windSheildGap + 8);
	}
	//blade holder
	glColor3ub(224, 223, 219);
	glBegin(GL_POLYGON);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2, topY);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2, topY + tailWidth);
	glVertex2f(frontX + segmentWidth + segmentWidth / 3, topY + tailWidth);
	glVertex2f(frontX + segmentWidth + segmentWidth / 3, topY);
	glEnd();
}

//make sure drawHelicopterSkeleton() is called first to set parameters
void drawBlades()
{
	int translation = 3;
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2, topY + tailWidth);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2 - bladeLength, topY + bladeWidth - translation);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2 - bladeLength, topY + 1.5 * bladeWidth + translation);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2, topY + 1.5 * bladeWidth);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2 + bladeLength, topY + 1.5 * bladeWidth + translation);
	glVertex2f(frontX + segmentWidth + segmentWidth / 2 + bladeLength, topY + bladeWidth - translation);
	glVertex2f(frontX + segmentWidth + segmentWidth / 3, topY + bladeWidth);
	glEnd();
}

void drawHelicopter()
{
	drawHelicopterSkeleton(700, 550, 500);
	bladeLength = 500 / 4;
	bladeWidth = tailWidth;
	drawBlades();
}