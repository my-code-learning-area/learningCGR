#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "newCircle.h"
#include "seedFill.h"

using namespace std;

void init();

// default radious of circle
int cx = 350, cy = 350, cr = 300;

void mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) { // getting x,y point on mouseBtnPresse
            glPointSize(2);
            glColor3f(0,0,0);
            cx = x, cy = 700 - y;
        } 

        if(state == GLUT_UP) { // getting radious on mouseBtnRelease
            glPointSize(1);
            glColor3f(0,0,1);
            cr = sqrt(pow(abs(x - cx), 2) + pow(abs((700 - y) - cy), 2));
        }

        glBegin(GL_POINTS);
            glVertex2i(x, 700 - y);
        glEnd();
        glFlush();	
    } 
}

void menu(int ch) {
    color originalC = {255, 255, 255};
    color fillC     = {0, 0, 255};
    switch(ch) {
        case 1:
            drawCircle(cx, cy, cr);
        break;

        case 2:
            seedFill(cx+1, cy, originalC, fillC);
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
void display() {

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
void init() {
    double start = 0.0;
    double end = 700.0;

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(start, end, start, end);
    glFlush();
}
