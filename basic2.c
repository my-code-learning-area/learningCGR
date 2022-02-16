#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction() {
    glClear(GL_COLOR_BUFFER_BIT);			// clearing frame buffer
    glLoadIdentity();					// 
    glPointSize(5.0);					// adjusting the size of pixel
    glClearColor(0.0, 0.0, 0.0, 0.0);			// setting background color to frame buffer
    glColor3f(0.0, 0.9, 1.0);				// ?
    glOrtho(-10.0, 500.0, -10.0, 400.0, 00, 1.0);		// left, right, bottom, top, nearVal, varVal
    		
    glBegin(GL_LINES);					// GL_POINTS = 0; GL_LINES = 1;
        glVertex2f(0, 0);				// adding point
	glVertex2f(0, 100);
	glVertex2f(0, 0);
	glVertex2f(0, -100);
	glVertex2f(100, 0);
	glVertex2f(-100, 0);
    glEnd();						// // end of drawing
    
    glBegin(0);
	glVertex2f(20,20);
    glEnd();

    glFlush();						// flush frame buffers
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);				// initializing opengl
    glutInitDisplayMode(GLUT_SINGLE);			// setting display mode

    glutInitWindowPosition(100,50);			// setting window position
    glutInitWindowSize(500, 400);			// setting window size

    glutCreateWindow("OpenGL - First window demo");	// creating window using glut

    glutDisplayFunc(renderFunction);			// specifying callback function

    glutMainLoop();    					// loop for keep program running

    return 0;
}
