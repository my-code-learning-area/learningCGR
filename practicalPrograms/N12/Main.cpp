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

double angle(double x) {
    return (x * 3.14f) / 180.0f;
}

int count = 5;
void drawCirclesLeft(point xy, int radious, double rotate) {
    double smallCircleRadious = 20;
    
    point txy = {(xy.x - xy.x), (xy.y + (radious + smallCircleRadious) - xy.y)};

    point cxy = {(txy.x * cos(angle(rotate)) + (txy.y * (-sin(angle(rotate))))) + xy.x, (txy.x * sin(angle(rotate)) + (txy.y * cos(angle(rotate))))+xy.y};
    circle(cxy, smallCircleRadious);
    if(count) {
        count --;
        drawCirclesLeft(cxy, smallCircleRadious, rotate - 10);
    } else {
    }
}

void drawCirclesRight(point xy, int radious, double rotate) {
    double smallCircleRadious = 20;
    
    point txy = {(xy.x - xy.x), (xy.y + (radious + smallCircleRadious) - xy.y)};

    point axy = {(txy.x * cos(angle(rotate)) + (txy.y * sin(angle(rotate)))) + xy.x, (txy.x * (-sin(angle(rotate))) + (txy.y * cos(angle(rotate))))+xy.y};
    circle(axy, smallCircleRadious);
    if(count) {
        count --;
        drawCirclesRight(axy, smallCircleRadious, rotate - 10);
    }
}

void display() {
    point xy = {350, 350};
    circle(xy, 50);
    count = 5;
    drawCirclesLeft(xy, 50, 60);
    count = 5;
    drawCirclesRight(xy, 50, 60);
    point txy = {350, 350};
    count = 1;
    drawCirclesLeft(txy, 50, 179);
    drawCirclesLeft(txy, 50, 145);
    drawCirclesRight(txy, 50, 148);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("N12");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
}