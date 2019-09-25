#include <GL/glut.h>
#include <stdio.h>

class Man
{
    int posX, posY, height, width, headWidth, headHeight, legWidth, legGap, legHeight, upperBodyWidth, upperBodyHeight, handsWidth, partsSpacing;

public:
    Man()
    {
        posX = 0;
        posY = 0;
        headWidth = 40;
        legWidth = 10;
        legGap = 5;
        handsWidth = legWidth;
        draw_man();
    }
    Man(int x, int y, int h, int w)
    {
        posX = x;
        posY = y;
        height = h;
        width = w;
        partsSpacing = 2;
        legWidth = w / 2 - 2 * partsSpacing;
        legGap = 5;
        legHeight = height * 2 / 4;
        upperBodyWidth = 2 * legWidth + legGap;
        upperBodyHeight = height / 2;
        headWidth = upperBodyWidth - upperBodyWidth / 6;
        headHeight = 20;
        handsWidth = legWidth;

        draw_man();
    }

private:
    void draw_man()
    {
        int nextLegPosX;
        glLineWidth(2.5);
        glColor3f(1, 1, 1);
        //right leg
        glRectd(posX, posY, posX + legWidth, posY + legHeight);
        nextLegPosX = posX + legWidth + legGap;
        //leftLeg
        glRectd(nextLegPosX, posY, nextLegPosX + legWidth, posY + legHeight);

        //upperBody
        glRectd(posX, posY + legHeight, posX + upperBodyWidth, posY + legHeight + upperBodyHeight);

        //head
        glRectd(posX + upperBodyWidth / 6, posY + legHeight + upperBodyHeight + partsSpacing, posX + headWidth, posY + legHeight + upperBodyHeight + headHeight);

        //hands
        //right
        glRectd(posX - handsWidth - partsSpacing, posY + legHeight, posX - partsSpacing, posY + legHeight + upperBodyHeight);
        //left
        glRectd(posX + partsSpacing + upperBodyWidth, posY + legHeight, posX + partsSpacing + upperBodyWidth + handsWidth, posY + legHeight + upperBodyHeight);
    }
};