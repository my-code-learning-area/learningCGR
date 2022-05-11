#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
void rotate(int x, int y, int rotation, int mode) {
    if(mode = 1) { // anti-clockwise
        cout<<sin(rotation);
    } else { // clockwise

    }
}

void display() {
    int x = 10, y = 10;
    glBegin(1);
        glVertex2d(x, y);
    glEnd();

    rotate(x, y, 45, 1);
    glFlush();
}

void init() {
    int start = -30, end = 30;
    glPointSize(20);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3d(0, 0, 1);

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