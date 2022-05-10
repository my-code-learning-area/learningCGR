#include<GL/glut.h>
#include<math.h>
#include "dda.h"

void translate(float points[][2], float dx, float dy){
    dda(points[0][0]*dx-dx+1, points[0][1]*dy-dy+1, points[1][0]*dx-dx+1, points[1][1]*dy-dy+1, 1);
    dda(points[0][0]*dx-dx+1, points[0][1]*dy-dy+1, points[2][0]*dx-dx+1, points[2][1]*dy-dy+1, 1);
    dda(points[3][0]*dx-dx+1, points[3][1]*dy-dy+1, points[1][0]*dx-dx+1, points[1][1]*dy-dy+1, 1);
    dda(points[2][0]*dx-dx+1, points[2][1]*dy-dy+1, points[3][0]*dx-dx+1, points[3][1]*dy-dy+1, 1);
}

void display() {
    glColor3f(0, 0, 1);
    float points[][2] = {
        {1, 1},
        {1, 5},
        {5, 1},
        {5, 5}
    };
    
    dda(points[0][0], points[0][1], points[1][0], points[1][1], 1);
    dda(points[0][0], points[0][1], points[2][0], points[2][1], 1);
    dda(points[3][0], points[3][1], points[1][0], points[1][1], 1);
    dda(points[2][0], points[2][1], points[3][0], points[3][1], 1);
    translate(points, 4, 4);
}

void init() {
    double start = -1;
    double end = 50;
    glPointSize(12);

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(start, end, start, end);
    glFlush();

     // draw x and y graphical lines
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
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("translate");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 1;
}