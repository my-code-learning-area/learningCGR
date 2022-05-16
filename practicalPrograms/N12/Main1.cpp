#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
struct point  {
    double x, y;
};

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);
    glColor3d(0, 0, 1);
    glFlush();
}


void printPoints(int x, int y, point xy) {
    glBegin(GL_POINTS);
        glVertex2i(xy.x + x, xy.y + y);
        glVertex2i(xy.x + y, xy.y + x);

        glVertex2i(xy.x + x, xy.y - y);
        glVertex2i(xy.x + y, xy.y - x);
        
        glVertex2i(xy.x - x, xy.y - y);
        glVertex2i(xy.x - y, xy.y - x);
        
        glVertex2i(xy.x - x, xy.y + y);
        glVertex2i(xy.x - y, xy.y + x);
    glEnd();
    glFlush();
}

void circle(point xy, int radious) {
    int x = 0, y = radious, D = 3 - 2 * radious;

    printPoints(x, y, xy);
    while(x <= y) {
        if(D < 0) {
            D += 4*x + 6; 
        } else { // D >= 0
            D += 4 * (x - y) + 10;
            y--;
        }
        x++;

        printPoints(x, y, xy);
    }
    glFlush();
}

double angle(double r) {
    return (r * 3.14f) / 180.0f;
}

int count = 5;
void drawCircles(point xy, int radious, double rotate, int d) {
    double smallCircleRadious = 20;
    
    point txy = {(xy.x - xy.x), (xy.y + (radious + smallCircleRadious) - xy.y)};

    point axy = {(txy.x * cos(angle(rotate)) + (txy.y * (d * sin(angle(rotate))))) + xy.x, (txy.x * (-d*sin(angle(rotate))) + (txy.y * cos(angle(rotate))))+xy.y};
    circle(axy, smallCircleRadious);
    if(count) {
        count --;
        drawCircles(axy, smallCircleRadious, rotate - 15, d);
    } else {
        count = 5;
    }
}

point xy = {350, 350};
void display() {
    
}

void mouse(int btn, int state, int x, int y) {
    y = 700 - y;
    xy.x = x;
    xy.y = y;
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        double radious = 60;
        circle(xy, radious);
        drawCircles(xy, radious, 70, -1);
        drawCircles(xy, radious, 70, +1);

        point txy = {xy.x, xy.y-radious-20};
        circle(txy, 20);
        txy.y -= 20*2;
        circle(txy, 20);

        count = 0;
        drawCircles(xy, radious, 150, -1);
        count = 0;
        drawCircles(xy, radious, 150, 1);
    }
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("N12");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}