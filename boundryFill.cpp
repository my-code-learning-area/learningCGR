#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

struct color {
    GLubyte r, g, b;
};

void plotPixel(int x, int y, color fc) {
    glColor3d(fc.r, fc.g, fc.b);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();

    glFlush();
}

void boundryFill(int x, int y, color bc, color fc) {
    color pc;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pc);
    cout<<pc.r<<", "<<pc.g<<", "<<pc.b<<endl;
    cout<<fc.r<<", "<<fc.g<<", "<<fc.b<<endl;
    if((pc.r != bc.r && pc.g != bc.g && pc.b != bc.b) && (pc.r != fc.r && pc.g != fc.g && pc.b != fc.b)) {
        plotPixel(x, y, fc);
        cout<<x<<", "<<y<<endl;
        boundryFill(x+1, y, bc, fc);
        boundryFill(x-1, y, bc, fc);
        boundryFill(x, y+1, bc, fc);
        boundryFill(x, y-1, bc, fc);
    } else {
        return;
    }
}

void fun() {
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
        glVertex2i(7, 35);
        glVertex2i(35, 40);
        glVertex2i(40, 10);
        glVertex2i(3, 10);

        glVertex2i(7, 35);
        glVertex2i(3, 10);
        glVertex2i(35, 40);
        glVertex2i(40, 10);
    glEnd();

    int scanLineX1 = 3 - 2;
    int scanLineX2 = 40 + 2;

    color bc = {0, 0, 0};
    color fc = {1, 0, 0};

    boundryFill(20, 20, bc, fc);

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0, 45, 0, 50);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(600, 650);

    glutCreateWindow("inside test");
    init();
    glutDisplayFunc(fun);

    glutMainLoop();

    return 1;
}
