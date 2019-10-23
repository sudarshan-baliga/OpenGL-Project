#include <GL/glut.h>
#include <iostream>
using namespace std;
int tailX, frontX, topY, botY, tailWidth, tailLength, segmentWidth, windSheildGap, bladeLength, bladeWidth;

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
    glBegin(GL_POLYGON);
    glVertex2f(frontX + segmentWidth, topY - windSheildGap);
    glVertex2f(frontX + 2 * segmentWidth - windSheildGap / 2, topY - windSheildGap);
    glVertex2f(frontX + 2 * segmentWidth - windSheildGap / 2, midY + windSheildGap);
    glVertex2f(frontX + segmentWidth, midY + windSheildGap);
    glEnd();

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
    glVertex2f(frontX + segmentWidth + segmentWidth / 2 + bladeLength, topY +  bladeWidth - translation);
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