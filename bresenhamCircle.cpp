#include<GL/glut.h>
#include<math.h>

void drawCircle(double x, double y, double radious) {
    x = 0, y = radious;
    glVertex2d(0, radious);
    glVertex2d(radious, 0);
    glVertex2d(0, -radious);
    glVertex2d(-radious, 0);

    double D = 3 - 2 * radious;

    double temp = 0.5;

    while(x <= y) {
        if(D < 0) {
            D += 4 * x + 6;
            x += 1;
        } else if (D >= 0) {
            D = D + 4 * (x - y) + 10;
            x += 1;
            y -= 1;
        }
        if(temp > 1) {
            temp = 0;
        } else {
            temp += 0.1;
        }
        glColor3d(temp, 0, temp - 0.2);
        // 1st quadrant
        glVertex2d(round(x), round(y));
        glVertex2d(round(y), round(x));

        // 4th quadrant
        glVertex2d(round(y), round(-x));
        glVertex2d(round(x), round(-y));

        // 3rd quadrant
        glVertex2d(round(-y), round(-x));
        glVertex2d(round(-x), round(-y));

        // 2nd quadrant
        glVertex2d(round(-y), round(x));
        glVertex2d(round(-x), round(y));
    }
}

void display() {
    double start = -21.0, end = 21.0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(start, end, start, end);

    glPointSize(13); // adjusting point size to draw pixel
    
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

    glColor3d(1.0, 0.7, 0.2);
    glBegin(GL_POINTS);
        drawCircle(0, 0, 10);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Circal generation using Bresenham algorithm");

    glutDisplayFunc(display);

    glutMainLoop();
    return 1;
}