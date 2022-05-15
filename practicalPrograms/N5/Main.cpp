#include<GL/glut.h>
#include<math.h>

struct color {
    GLubyte r, g, b;
};

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(0, 700, 0, 700);
    glColor3d(0, 0, 0);
    glFlush();
}

void fill(int x, int y, color bc, color fc) {
    color c;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
    if((c.r == bc.r) && (c.g == bc.g) && (c.b == bc.b)) {
        glBegin(GL_POINTS);
            glColor3ub(fc.r, fc.g, fc.b);
            glVertex2d(x, y);
        glEnd();
        glFlush();
        fill(x + 2, y, bc, fc);
        fill(x - 2, y, bc, fc);
        fill(x, y + 2, bc, fc);
        fill(x, y - 2, bc, fc);
    }
}

void display() {
    double lines[][4] = {
        // for horizontal lines
        {250, 450, 451, 450},
        {250, 400, 450, 400},
        {250, 350, 450, 350},
        {250, 300, 450, 300},
        {250, 250, 450, 250},

        // for vertical lines
        {250, 250, 250, 450},
        {300, 250, 300, 450},
        {350, 250, 350, 450},
        {400, 250, 400, 450},
        {450, 250, 450, 451},
    };

    for(int i = 0; i < (sizeof(lines)/sizeof(lines[0])); i++) {
        glBegin(GL_LINES);
            glVertex2d(lines[i][0], lines[i][1]);
            glVertex2d(lines[i][2], lines[i][3]);
        glEnd();
        glFlush();
    }

    int xc = 250 + ((450 - 250) / 2);
    int yc = 250 + ((450 - 250) / 2);
    glPointSize(2);
    glLineWidth(2);
    glBegin(1);
        glVertex2d(xc, yc);
    glEnd();
    glFlush();


    for(int i = 0; i < 35000; i++) 
        for(int j = 0; j < 35000; j++){}

    init();

    for(double r = 0; r < 3.96; r += 0.02) {
        glClear(GL_COLOR_BUFFER_BIT);
        for(int i = 0; i < (sizeof(lines)/sizeof(lines[0])); i++) {
            double rotateBy = r;

            double x1 = ((cos(rotateBy)*(lines[i][0]-xc)) + ((lines[i][1]-yc)*(-sin(rotateBy)))) + xc;
            double y1 = ((sin(rotateBy)*(lines[i][0]-xc)) + (cos(rotateBy)*(lines[i][1]-yc))) + yc;
            
            double x2 = ((cos(rotateBy)*(lines[i][2]-xc)) + (-sin(rotateBy)*(lines[i][3]-yc))) + xc;
            double y2 = ((sin(rotateBy)*(lines[i][2]-xc)) + (cos(rotateBy)*(lines[i][3]-yc))) + yc;

            glBegin(GL_LINES);
                glVertex2d(x1, y1);
                glVertex2d(x2, y2);
            glEnd();
            glFlush();
        }

        // for(int i = 0; i < 2000; i++) 
        //     for(int j = 0; j < 2000; j++) {}
    }
    color bc = {255, 255, 255};
    color fc = {190, 80, 30};
    fill(420, 320, bc, fc);
    fill(420, 380, bc, fc);
    fill(350, 380, bc, fc);
    fill(280, 380, bc, fc);
    fill(350, 320, bc, fc);
    fill(280, 320, bc, fc);
    fill(350, 250, bc, fc);
    fill(350, 450, bc, fc);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);

    glutCreateWindow("N4");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 1;
}