#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "newCircle.h"
#include "seedFill.h"

using namespace std;

void drawSmallCircles(double x, double y, double xi, double yi, double circleRadious)
{
    drawCircle((x + xi), (y + yi), circleRadious);
    drawCircle((x + yi), (y + xi), circleRadious);

    // 4th quadrant
    drawCircle((x + yi), (y - xi), circleRadious);
    drawCircle((x + xi), (y - yi), circleRadious);

    // 3rd quadrant
    drawCircle((x - yi), (y - xi), circleRadious);
    drawCircle((x - xi), (y - yi), circleRadious);

    // 2nd quadrant
    drawCircle((x - yi), (y + xi), circleRadious);
    drawCircle((x - xi), (y + yi), circleRadious);
}

void drawCirclet(double x, double y, double r)
{
    double xi = 0;
    double yi = r;
    double circumferece = 2 * 3.14 * r;
    double diameters = circumferece / 40; // change it according needded count of circles
    double circleRadious = diameters / 2;

    double D = 3 - 2 * r;

    drawSmallCircles(x, y, xi, yi, circleRadious);
    double counter = 0;
    double counterInc = 0;

    while (xi <= yi)
    {
        if (counter < diameters )
        {
            counter += 1 + counterInc;
        }
        else
        {
            drawSmallCircles(x, y, xi, yi, circleRadious);
            counterInc += 0.065;
            counter = 0;
        }

        if (D < 0)
        {
            D += 4 * xi + 6;
            xi++;
        }
        else
        { // d>=0
            D += 4 * (xi - yi) + 10;
            xi++; // remove this line and see magic
            yi--;
        }

        // printPoint(xi, yi, x, y);
    }

    glFlush();
}

void init();

// default radious of circle
int cx = 350, cy = 350, cr = 300;

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        { // getting x,y point on mouseBtnPresse
            glPointSize(2);
            glColor3f(0, 0, 0);
            cx = x, cy = 700 - y;
        }

        if (state == GLUT_UP)
        { // getting radious on mouseBtnRelease
            glPointSize(1);
            glColor3f(0, 0, 1);
            cr = sqrt(pow(abs(x - cx), 2) + pow(abs((700 - y) - cy), 2));
        }

        glBegin(GL_POINTS);
        glVertex2i(x, 700 - y);
        glEnd();
        glFlush();
    }
}

void menu(int ch)
{
    color originalC = {255, 255, 255};
    color fillC = {255, 0, 255};
    switch (ch)
    {
    case 1:
        drawCirclet(cx, cy, cr);
        break;

    case 2:
        seedFill(cx + 12, cy, originalC, fillC);
        break;

    case 3:
        init();
        break;

    case 4:
        exit(0);
        break;
    }
}

//////////////////////////////////////////
void display()
{
    // glRasterPos2f(240, 120); // define position on the screen
    // char *string = "Text";

    // while (*string)
    // {
    //     glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
    // }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("Circal generation");
    init();

    glutDisplayFunc(display);

    glutMouseFunc(mouseClick);

    glutCreateMenu(menu);
    glutAddMenuEntry("Draw", 1);
    glutAddMenuEntry("Fill", 2);
    glutAddMenuEntry("Clear", 3);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 1;
}
//////////////////////////////////////////
void init()
{
    double start = 0.0;
    double end = 700.0;

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(start, end, start, end);
    glFlush();
}
