#include<GL/glut.h>
#include<math.h>
#include "circle.h"

void displayGrid(double start, double end) {
    // draw x and y graphical lines
    glBegin(GL_LINES);
        for(int i = start; i <= end; i++ ) {
            glColor3d(0.4, 0.8, 1.0);
            glVertex2d(start, i-.5);
            glVertex2d(end, i-.5);
            
            glColor3d(1.0, 0.8, 1.0);
            glVertex2d(i-.5, start);
            glVertex2d(i-.5, end);

        }
    glEnd();

    // drawing x and y axis
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3d(0.0, 0.0, 0.0);
        glVertex2d(0-.5, start);
        glVertex2d(0-.5, end);

        glVertex2d(start, 0-.5);
        glVertex2d(end, 0-.5);
    glEnd();
    glFlush();
}

void display() {
    // double start = -31.0, end = 31.0;
    double start = 0, end = 1100.0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(start, end, start, end);

    // glPointSize(13); // adjusting point size to draw pixel
    glPointSize(1); // adjusting point size to draw pixel
    
    displayGrid(start, end); // drawing grid

    glColor3d(1.0, 0.7, 0.2);
    glBegin(GL_POINTS);
        glVertex2d(10, 10);
    glEnd();
    glColor3d(0.2, 0.1, 0.0);
    drawCircle(550, 550, 500);
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(900, 900);

    glutCreateWindow("Circal generation using Bresenham algorithm");

    glutDisplayFunc(display);

    glutMainLoop();
    return 1;
}