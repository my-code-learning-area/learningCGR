#include<GL/freeglut.h>
#include<GL/glut.h>
#include<math.h>

void renderFunction();

int main(int argc, char **argv) {
    glutInit(&argc, argv); // initializing opengl
    glutInitDisplayMode(GLUT_SINGLE); // display mode = single

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Bresenham's Line Generation Algorithm");

    glutDisplayFunc(renderFunction);

        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.9, 1.0);
        glOrtho(-500.0, 500.0, -500.0, 500.0, 0.0)

    glutMainLoop();

    return 0;
}

void renderFunction() {

}