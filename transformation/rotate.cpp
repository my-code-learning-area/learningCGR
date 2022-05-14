#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

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
    glLineWidth(5);

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

void display() {
    lineCircle(10, 13, 20, 20);


    glFlush();
}

void init() {
    int start = -30, end = 30;
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