#include <GL/glut.h>
#include <stdio.h>
#include "lib/text.h"

void displayInfo()
{
    float windowWidth, windowHeight, posX, posY, textWidth;
    int offsetX, offsetY;
    char member1[] = "4NM16CS153 Sudarshan Baliga",
         member2[] = "4NM16CS151 Srihari Vishnu",
         member3[] = "4NM16CS152 Stalin Robo",
         title[] = "Flood rescue simulation";
    //put the below code in separate thread for handling window size change
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    posX = windowWidth / 2;
    posY = windowHeight / 2;
    offsetY = 25;
    glColor3f(1.0, 1.0, 1.0);
    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)member1);
    draw_text(member1, posX - offsetX / 2, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)member2);
    draw_text(member2, posX - offsetX / 2, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

    offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)member3);
    draw_text(member3, posX - offsetX / 2, posY, GLUT_BITMAP_HELVETICA_18);
    posY -= offsetY;

    offsetX = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)title);
    draw_text(title, posX - offsetX / 2, posY, GLUT_BITMAP_TIMES_ROMAN_24);
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
    glClearColor(0, 0.882, 0.827, 1);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flood rescue");
    glutDisplayFunc(display);
    glutReshapeFunc(on_resize);
    init();
    glutMainLoop();
    return 0;
}