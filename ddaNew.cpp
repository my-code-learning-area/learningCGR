#include<GL/glut.h>
#include<math.h>

void dda(int x1, int y1, int x2, int y2) {
    int x = x1; int y = y1;
    int dx = x2 - x1;
    if(dx == 0) {
        dx = 1;
    }
    int dy = y2 - y1;

    double m = dy / dx;
    
    double xn, yn;
    int steps = 0;

    if(dx > dy) {
        steps = dx;
    } else {
        steps = dy;
    }

    if(m < 1) {
        xn = 1;
        yn = m;
    } else if(m > 1) {
        xn = 1.0f / m;
        yn = 1;
    }

    while(steps) {
        glBegin(GL_POINTS);
            glVertex2d(x, y);
        glEnd();
        glFlush();
        x = round(x + xn);
        y = round(y + yn);

        steps --;
    }
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
}

void display() {
    glColor3d(0, 0, 0);

    dda(1, 1, 5, 10);

    glFlush();
}

void init() {
    int start = -1, end = 25;
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(start, end, start, end);

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

    glPointSize(18);

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("dda - digital differential analyzer");

    init();
    glutDisplayFunc(display);
    glFlush();

    glutMainLoop();
    return 1;
}