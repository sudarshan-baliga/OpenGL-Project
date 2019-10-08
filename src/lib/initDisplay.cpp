#include "initDisplay.h"
#include "drawText.h"
#include <GL/glut.h>

void displayInfo()
{
	float posX = glutGet(GLUT_WINDOW_WIDTH) / 2.0 - 150,
		posY = glutGet(GLUT_WINDOW_HEIGHT) / 2.0 + 60,
		textWidth;
	int offsetX, offsetY = 30;
	char usn[][11] = { "4NM16CS153", "4NM16CS151", "4NM16CS152", },
		name[][19] = { "SUDARSHAN BALIGA B", "SRIHARIVISHNU", "STALIN ROBO" },
		title[] = "RESCUE OPERATION USING HELICOPTER";

	for (int i = 0; i < 3; ++i)
	{
		glColor3ub(91, 100, 249);
		offsetX = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)usn[i]) + 40;
		draw_text(usn[i], posX, posY, GLUT_BITMAP_HELVETICA_18);

		glColor3ub(0, 183, 78);
		draw_text(name[i], posX + offsetX, posY, GLUT_BITMAP_HELVETICA_18);
		posY -= offsetY;
	}
	glColor3ub(91, 100, 249);
	offsetX = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)title);
	draw_text(title, posX - 60, posY - 50, GLUT_BITMAP_TIMES_ROMAN_24);
}