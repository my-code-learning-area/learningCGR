#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

void init() {
    int start = -300, end = 300;
    glPointSize(11);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(start, end, start, end);

    {
        glBegin(GL_LINES);
        for (int i = start; i <= end; i++)
        {
            glColor3d(0.4, 0.8, 1.0);
            glVertex2d(start, i - .5);
            glVertex2d(end, i - .5);

            glColor3d(1.0, 0.8, 1.0);
            glVertex2d(i - .5, start);
            glVertex2d(i - .5, end);
        }
        glEnd();

        // drawing x and y axis
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3d(0.0, 0.0, 0.0);
        glVertex2d(0 - .5, start);
        glVertex2d(0 - .5, end);

        glVertex2d(start, 0 - .5);
        glVertex2d(end, 0 - .5);
        glEnd();
    }

    glFlush();
}

void rotate(int x, int y, double rotation, int mode) {
    double xr, yr;
    if(mode == 1) { // anti-clockwise
        xr = (x * cos(rotation)) + (y * (-sin(rotation)));
        yr = (x * sin(rotation)) + (y * (cos(rotation)));

    } else { // clockwise
        xr = (x * cos(rotation)) + (y * (sin(rotation)));
        yr = (x * (-sin(rotation))) + (y * (cos(rotation)));
    }

    glColor3d(0, 0, 0.8);
    glVertex2d(xr, yr);

    glFlush();
}

void lineCircle(int x1, int y1, int x2, int y2) {
    glColor3d(0, 0, 1);
    glLineWidth(12);

    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();

    double rotateBy = 0.05;

    for(rotateBy; rotateBy < 6.25; rotateBy += 0.05) {
        glBegin(GL_LINES);
            rotate(x1, y1, rotateBy, 2);
            rotate(x2, y2, rotateBy, 2);
        glEnd();
        glFlush();

        for(int i = 0; i < 5000; i++)
            for(int j = 0; j < 5000; j++) {}
    } 
}

void rotateOnIT(int x1, int y1, int x2, int y2) {
    glColor3d(0, 0, 1);
    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();

    double rotateBy = 0.02;

    double xc = x1 + ((x2 - x1) / 2);
    double yc = y1 + ((y2 - y1) / 2);

    double xx1 = x1 - xc;
    double yy1 = y1 - yc;
    double xx2 = x2 - xc;
    double yy2 = y2 - yc;

    double xr1, yr1, xr2, yr2;

    glBegin(GL_LINES);
        glVertex2d(xx1 + xc, yy1 + yc);
        glVertex2d(xx2 + xc, yy2 + yc);
    glEnd();

    for(rotateBy; rotateBy < 6.26; rotateBy += 0.02) {
    // for(rotateBy; rotateBy < 36.26; rotateBy += 0.02) {
    // for(rotateBy; rotateBy < 36.26; rotateBy += 0.3) {
        xr1 = (xx1 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        yr1 = (xx1 * sin(rotateBy)) + (yy1 * (cos(rotateBy)));
        xr2 = (xx2 * cos(rotateBy)) + (yy2 * (-sin(rotateBy)));
        yr2 = (xx2 * sin(rotateBy)) + (yy2 * (cos(rotateBy)));
        
        // xr1 = (xx1 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        // yr1 = (xx1 * sin(rotateBy)) + (yy1 * (cos(rotateBy)));
        // xr2 = (xx2 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        // yr2 = (xx1 * sin(rotateBy)) + (yy2 * (cos(rotateBy)));

        // xr1 = (xx2 * cos(rotateBy)) + (yy2 * (-sin(rotateBy)));
        // yr1 = (xx1 * sin(rotateBy)) + (yy1 * (cos(rotateBy)));
        // xr2 = (xx2 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        // yr2 = (xx1 * sin(rotateBy)) + (yy2 * (cos(rotateBy)));
        
        // xr1 = (xx1 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        // yr1 = (xx1 * sin(rotateBy)) + (yy1 * (cos(rotateBy)));
        // xr2 = (xx2 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)));
        // yr2 = (xx2 * sin(rotateBy)) + (yy2 * (cos(rotateBy)));


        glBegin(GL_LINES);
            glVertex2d(xr1 + xc, yr1 + yc);
            glVertex2d(xr2 + xc, yr2 + yc);
        glEnd();
        glFlush();

        for(int i = 0; i < 1000; i++)
            for(int j = 0; j < 1000; j++) {}
        //init();
    } 
}

void display() {
    // lineCircle(10, 13, 20, 20);

    rotateOnIT(-250, 0, 250, 0);
    /* rotateOnIT(50, 50, 250, 250);
    rotateOnIT(50, -50, 250, -250);
    rotateOnIT(-50, -50, -250, -250);
    rotateOnIT(-50, 50, -250, 250);

    rotateOnIT(-40, -40, 40, 40); */


    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ok");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 1;
}