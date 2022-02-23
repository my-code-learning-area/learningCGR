#include<GL/glut.h> 
#include<math.h>
#include<iostream>
using namespace std;

void dda(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double m = abs(dy / dx);

    double xinc, yinc;
    double x = x1, y = y1;

    if(dx == 0) { //y
        xinc = 0;
        yinc = 1;
    } else if(m == 1 && x2 > x1) { //m
        xinc = 1;
        yinc = 1;
    } else if(m == 1 && x2 < x1) { //-m
        xinc = -1;
        yinc = -1;
    } else if (m < 1 && x2 > x1) { //x
        xinc = 1;
        yinc = m;
    } else if (m < 1 && x2 < x1) { //-x
        xinc = -1;
        yinc = -m;
    } else if (m > 1 && y2 > y1) { //y
        xinc = 1 / m;
        yinc = 1;
    } else if (m > 1 && y2 < y1) { //-y
        xinc = -(1 / m);
        yinc = -1;
    }
    cout<<"dy = "<<dy<<endl<<"dx = "<<dx<<endl<<"m = "<<m<<endl<<"(xinc, yinc) = ("<<xinc<<", "<<yinc<<")"<<endl;

    for(int i = 0; i < (abs(dx) > abs(dy) ? abs(dx) : abs(dy)); i++) {
        glVertex2d(round(x), round(y));

        x += xinc;
        y += yinc;
    }
    glVertex2d(round(x), round(y));
    
}

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-1, 21, -1, 21);

    glBegin(GL_LINES); // for border lines of pixels
        int i = 1, s = -1, e = 21;

        glColor3d(0.0, 0.0, 0.0); // for drawing x and y axis
        glVertex2d(e - 0.5, 0);
        glVertex2d(s - 0.5, 0);

        glVertex2d(0, e - 0.5);
        glVertex2d(0, s - 0.5);

        //////////////////////////////////////////////////

        for(i; i <= e; i++) {
            glColor3d(0.2, 1.0, 0.8);
            glVertex2d(i - 0.5, s - 0.5);
            glVertex2d(i - 0.5, e - 0.5);

            glColor3d(0.2, 0.8, 1.0);
            glVertex2d(s - 0.5, i - 0.5);
            glVertex2d(e - 0.5, i - 0.5);
        }
    glEnd();

    glPointSize(22);
    glColor3d(1.0, 0.5, 0.0);
    glBegin(GL_POINTS);
        dda(1, 1, 5, 5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);

    glutCreateWindow("DDA - Digital Differential Analizer");

    glutDisplayFunc(display);

    glutMainLoop();

    return 1;
}
