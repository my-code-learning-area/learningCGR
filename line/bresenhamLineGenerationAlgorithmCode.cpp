#include<GL/glut.h>

struct line {
    double x1, y1, x2, y2;
};

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(-350, 350, -350, 350);
    glColor3d(0.2, 0.5, 1);
    glFlush();
}

void bresenhamLine(line l) {
    double x = l.x1;
    double y = l.y1;
    double dx = abs(l.x2 - l.x1);
    double dy = abs(l.y2 - l.y1);
    double xi = l.x1 < l.x2? 1 : -1;
    double yi = l.y1 < l.y2? 1 : -1;

    double steps = dx > dy ? dx : dy;

    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();

    if(dx == 0) { // line is on y
        while(steps) {
            glBegin(GL_POINTS);
                glVertex2d(x, y += yi);
            glEnd();
            glFlush();
            steps --;
        }
        return;
    }
    
    if(dy == 0) { // line is on x
        while(steps) {
            glBegin(GL_POINTS);
                glVertex2d(x += xi, y);
            glEnd();
            glFlush();
            steps --;
        }
        return;
    }

    if(dx > dy) { // line is inclient to x axix
        double D = (2 * dy) - dx;
        while(steps) {
            if(D >= 0) {
                x += xi;
                y += yi;
                D += 2 * (dy - dx);
            } else { // D < 0
                x += xi;
                D += 2 * dy;
            }
            glBegin(GL_POINTS);
                glVertex2d(x, y);
            glEnd();
            glFlush();
            steps --;
        }
    } else { // line is inclient to y axis
        double D = (2 * dx) - dy;
        while(steps) {
            if(D >= 0) {
                x += xi;
                y += yi;
                D += 2 * (dx - dy);
            } else { // D < 0
                y += yi;
                D += 2 * dx;
            }
            glBegin(GL_POINTS);
                glVertex2d(x, y);
            glEnd();
            glFlush();
            steps --;
        }
    }
}

void display() {

    // 1st quadrant
    line f1 = {50, 200, 50, 50};
    bresenhamLine(f1);
    
    line f2 = {200, 50, 50, 50};
    bresenhamLine(f2);

    line f3 = {200, 200, 50, 50};
    bresenhamLine(f3);
    
    line f4 = {150, 200, 50, 50};
    bresenhamLine(f4);
    
    line f5 = {200, 150, 50, 50};
    bresenhamLine(f5);
    
    // 2nd quadrant
    line s1 = {-50, 200, -50, 50};
    bresenhamLine(s1);
    
    line s2 = {-200, 50, -50, 50};
    bresenhamLine(s2);

    line s3 = {-200, 200, -50, 50};
    bresenhamLine(s3);
    
    line s4 = {-150, 200, -50, 50};
    bresenhamLine(s4);
    
    line s5 = {-200, 150, -50, 50};
    bresenhamLine(s5);
    
    // 3rd quadrant
    line t1 = {-50, -200, -50, -50};
    bresenhamLine(t1);
    
    line t2 = {-200, -50, -50, -50};
    bresenhamLine(t2);

    line t3 = {-200, -200, -50, -50};
    bresenhamLine(t3);
    
    line t4 = {-150, -200, -50, -50};
    bresenhamLine(t4);
    
    line t5 = {-200, -150, -50, -50};
    bresenhamLine(t5);
    
    // 4th quadrant
    line l1 = {50, -200, 50, -50};
    bresenhamLine(l1);
    
    line l2 = {200, -50, 50, -50};
    bresenhamLine(l2);

    line l3 = {200, -200, 50, -50};
    bresenhamLine(l3);
    
    line l4 = {150, -200, 50, -50};
    bresenhamLine(l4);
    
    line l5 = {200, -150, 50, -50};
    bresenhamLine(l5);

    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("code of bresenham line generation algorithm");
    init();

    glutDisplayFunc(display);
    glFlush();

    glutMainLoop();

    return 1;
}