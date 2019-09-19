#include <GL/glut.h>
#include <stdio.h>
#include "lib/text.h"

void displayInfo()
{
    float windowWidth, windowHeight, posX, posY, textWidth;
    int offsetX, offsetY;
    char usn1[] = "4NM16CS153",
         usn2[] = "4NM16CS151",
         usn3[] = "4NM16CS152",
         name1[] = "SUDARSHAN BALIGA B",
         name2[] = "SRIHARI VISHNU",
         name3[] = "STALIN ROBO",
         title[] = "RESCUE OPERATION USING HELICOPTER";
    //put the below code in separate thread for handling window size change
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    posX = windowWidth / 2 - 150;
    posY = windowHeight / 2 + 60;
    offsetY = 30;

    glColor3ub(91, 100, 249);
    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)usn1) + 40;
    draw_text(usn1, posX, posY, GLUT_BITMAP_HELVETICA_18);
    glColor3ub(0, 183, 78);
    draw_text(name1, posX + offsetX, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

    glColor3ub(91, 100, 249);
    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)usn2) + 40;
    draw_text(usn2, posX, posY, GLUT_BITMAP_HELVETICA_18);
    glColor3ub(0, 183, 78);
    draw_text(name2, posX + offsetX, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

    glColor3ub(91, 100, 249);
    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)usn3) + 40;
    draw_text(usn3, posX, posY, GLUT_BITMAP_HELVETICA_18);
    glColor3ub(0, 183, 78);
    draw_text(name3, posX + offsetX, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

   glColor3ub(91, 100, 249);
    offsetX = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)title);
    draw_text(title, posX - 60, posY - 50, GLUT_BITMAP_TIMES_ROMAN_24);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    displayInfo();
    glFlush();
}

void on_resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}

void init(void)
{
    // glClearColor(0, 0.882, 0.827, 1);
    glClearColor(0, 0, 0, 1);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 599.0, 0.0, 599.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flood rescue");
    glutDisplayFunc(display);
    glutReshapeFunc(on_resize);
    init();
    glutMainLoop();
    return 0;
}