#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

struct color {
    GLubyte r, g, b;
};

int cx = 350, cy = 350, cr = 200;

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);
    glColor3d(0, 0, 0);
    glFlush();
}

void printPoints(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);

        glVertex2i(xc + x, yc - y);
        glVertex2i(xc + y, yc - x);
        
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - y, yc + x);
    glEnd();
    glFlush();
}

void circle(int xc, int yc, int radious) {
    int x = 0, y = radious, D = 3 - 2 * radious;

    printPoints(x, y, xc, yc);
    while(x <= y) {
        if(D < 0) {
            D += 4*x + 6; 
        } else { // D >= 0
            D += 4 * (x - y) + 10;
            y--;
        }
        x++;

        printPoints(x, y, xc, yc);
    }
    glFlush();
}

void fillPixel(int x, int y, color fc) {
    glColor3ub(fc.r, fc.g, fc.b);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();
}

void fill(int x, int y, color bc, color fc) {
    color pc;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pc);

    if((pc.r == bc.r) && (pc.g == bc.g) && (pc.b == bc.b)) {
        fillPixel(x, y, fc);
        fill(x + 1, y, bc, fc);
        fill(x - 1, y, bc, fc);
        fill(x, y + 1, bc, fc);
        fill(x, y - 1, bc, fc);
    }
}

double angle(double x) {
    return (x * 3.14f) / 180.0f;
}

void drawRotatedCircles(double x, double y, double r, double cr) {
    int x1, y1;
    x1 = cx - x;
    y1 = cy - y;

    int xx, yy;

    xx = (x1 * cos(angle(r))) + (y1 * (-sin(angle(r))));
    yy = (x1 * sin(angle(r))) + (y1 * cos(angle(r)));

    circle(xx + cx, yy + cy, cr);
    glFlush();
}

void mouse(int btn, int state, int x, int y) {
    y = 700 - y;
    if(btn == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) {
            cx = x;
            cy = y;
            glPointSize(2);
            glBegin(GL_POINTS);
                glVertex2d(x, y);
            glEnd();
            glFlush();
            glPointSize(1);
        } else { // state == GLUT_UP
            cr = sqrt(pow((x - cx), 2) + pow((y - cy), 2));
            glBegin(GL_POINTS);
                glVertex2d(x, y);
            glEnd();
            glFlush();
            cout<<endl<<"got the points"<<endl;
            circle(cx, cy, cr);

            //
            double r = cr;
            r = cr / 2;

            for(int i = 0; i < 360; i+=30) {
                drawRotatedCircles(cx + r, cy, i, r);
            }
            

            circle(cx, cy, r);
        }
    } else { // btn == GLUT_RIGHT_BUTTON
        color bc = {255, 255, 255};
        color fc = {200, 110, 80};
        fill(x, y, bc, fc);
        glFlush();
    }
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("N14");
    init();

    glutMouseFunc(mouse);

    glutMainLoop();
    return 1;
}