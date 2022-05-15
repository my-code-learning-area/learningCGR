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
        fill(x + 1, y + 1, bc, fc);
        fill(x - 1, y - 51, bc, fc);
        fill(x - 1, y + 1, bc, fc);
        fill(x + 1, y - 1, bc, fc);
    }
}

void display() {
    double lines[][4] = {
        {330, 480, 380, 480},
        {330, 480, 330, 380},
        {330, 380, 230, 380},
        {230, 380, 230, 330},
        {230, 330, 330, 330},
        {330, 330, 330, 230},
        {330, 230, 380, 230},
        {380, 230, 380, 330},
        {380, 330, 480, 330},
        {480, 330, 480, 380},
        {480, 380, 380, 380},
        {380, 380, 380, 480}
    };

    glLineWidth(2);

    for(int i = 0; i < (sizeof(lines)/sizeof(lines[0])); i++) {
        glBegin(GL_LINES);
            glVertex2d(lines[i][0], lines[i][1]);
            glVertex2d(lines[i][2], lines[i][3]);
        glEnd();
        glFlush();
    }

    for(int i = 0; i < 30000; i++) 
        for(int j = 0; j < 30000; j++){}
    
    init();
    double rotateBy = .5;
    double x1, y1, x2, y2;
    /* for(int i = 0; i < (sizeof(lines)/sizeof(lines[0])); i++) {
        x1 = (lines[i][0] * cos(rotateBy)) + (lines[i][1] * (-sin(rotateBy)));
        y1 = (lines[i][0] * sin(rotateBy)) + (lines[i][1] * (cos(rotateBy)));
        x2 = (lines[i][2] * cos(rotateBy)) + (lines[i][3] * (-sin(rotateBy)));
        y2 = (lines[i][2] * sin(rotateBy)) + (lines[i][3] * (cos(rotateBy)));
        glBegin(GL_LINES);
            glVertex2d(x1, y1);
            glVertex2d(x2, y2);
        glEnd();
        glFlush();
    } */
    
    for(double r = 0; r < .459; r += 0.002){
        glClear(GL_COLOR_BUFFER_BIT);

        for(int i = 0; i < (sizeof(lines)/sizeof(lines[0])); i++) {
            double xc = 350;
            double yc = 350;
            double rotateBy = r;

            double xx1 = lines[i][0] - xc;
            double yy1 = lines[i][1] - yc;
            double xx2 = lines[i][2] - xc;
            double yy2 = lines[i][3] - yc;
            
            lines[i][0] = ((xx1 * cos(rotateBy)) + (yy1 * (-sin(rotateBy)))) + xc;
            lines[i][1] = ((xx1 * sin(rotateBy)) + (yy1 * (cos(rotateBy)))) + yc;
            lines[i][2] = ((xx2 * cos(rotateBy)) + (yy2 * (-sin(rotateBy)))) + xc;
            lines[i][3] = ((xx2 * sin(rotateBy)) + (yy2 * (cos(rotateBy)))) + yc;
            glBegin(GL_LINES);
                glVertex2d(lines[i][0], lines[i][1]);
                glVertex2d(lines[i][2], lines[i][3]);
            glEnd();
            glFlush();
        }
        for(int i = 0; i < 3000; i++) 
            for(int j = 0; j < 3000; j++){}
    }

    color bc = {255, 255, 255};
    color fc = {255, 0, 0};
    fill(350, 350, bc, fc);
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