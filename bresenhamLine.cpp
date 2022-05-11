#include<GL/glut.h>

void bl(int x1, int y1, int x2, int y2) {
    int x  = x1,    y = y1;
    int dx = x2-x1, dy = y2 - y1;
    int p  = (2 * dy) - dx;
    int steps;

    if(dx > dy) 
        steps = dx;
    else 
        steps = dy;

    while(steps) {
        if(p < 0 && dx > dy) {
            p += 2 * dy;
            x ++;
        } else if(p >= 0 && dx > dy) {
            p += (2 * dy) - (2 * dx);
            x ++;
            y ++;
        } else if(p < 0 && dx < dy) {
            p += 2 * dx;
            y ++;
        } else if(p >= 0 && dx < dy) {
            p += (2 * dx) - (2 * dy);
            x ++;
            y ++;
        }
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();

        steps --;
    }
}

void display() {
    glColor3d(0, 0, 0);
    bl(10, 10, 20, 20);
    bl(10, 10, 10, 25);
    glFlush();
}

void init() {
    int start = -2, end = 30;
    glPointSize(20);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(start, end, start, end);

    {    // draw x and y graphical lines
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

}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("hii");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 1;
}