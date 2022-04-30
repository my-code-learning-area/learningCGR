/** //// DDA ////
* name:   sumit uttamrao kawale
* rollno: 23358
* class:  se-11
* batch:  g-11
*
**/
#include<GL/glut.h> 
#include<math.h>
#include<iostream>
using namespace std;

void dda(int x1, int y1, int x2, int y2, int type) {
    // type = 1 (simple line); 2 = (dashed line); 3 = (dotted line)
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

    int countDot = 1;
    for(int i = 0; i < (abs(dx) > abs(dy) ? abs(dx) : abs(dy)); i++) {
        if (type == 2){ // dashed
            if(countDot < 3) {
                glVertex2d(round(x), round(y));
                countDot++;
            } else if(countDot < 5) {
                countDot++;
            } else {
                countDot = 0;
            }
        } else if(type == 3){ // dotted
            if(countDot) {
                countDot --;
                glVertex2d(round(x), round(y));
            } else {
                countDot ++;
            }
        } else { // simple
            glVertex2d(round(x), round(y));
        } 

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
        glVertex2d(e, 0-.5);
        glVertex2d(s, 0-.5);

        glVertex2d(0-.5, e);
        glVertex2d(0-.5, s);

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

    //printing simple line
    glColor3d(1.0, 0.5, 0.0);
    glBegin(GL_POINTS);
        dda(1, 1, 15, 15, 1);
    glEnd();

    // printing dashed line
    glColor3d(.5, 0.0, 1.0);
    glBegin(GL_POINTS);
        dda(4, 1, 18, 15, 2);
    glEnd();

    // printing dotted line
    glColor3d(0.5, 1.0, 0.0);
    glBegin(GL_POINTS);
        dda(1, 4, 15, 18, 3);
    glEnd();

    // printing solid line
    glColor3d(.2, 0.1, 0.0);
    glBegin(GL_POINTS);
        dda(1, 8, 11, 18, 4);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);

    glutCreateWindow("Bresenham Line Generation Algorithm");

    glutDisplayFunc(display);

    glutMainLoop();

    return 1;
}
