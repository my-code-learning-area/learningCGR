#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

void dda(float x1, float y1, float x2, float y2) {
    float dy = (y2 - y1);		// delta y
	float dx = (x2 - x1);		// delta x
	float m = dy / dx; 		// slope
	float x = x1, y = y1;				// starting points
	float xinc, yinc;

	//setting xinc and yinc
    if(dx == 0) {
        xinc = 0.0;
        yinc = 1.0;
    } else if(m < 1.0 && x1 < x2) {
		xinc = 1.0;
		yinc = m;
	} else if(m < 1.0 && x1 > x2) { // if points are high to low
		xinc = -1.0;
		yinc = -m;
	} else if(m > 1.0 && x1 > x2) {
		xinc = 1.0 / m;
		yinc = 1.0;
	} else if(m > 1.0 && x1 < x2) {
		xinc = -(1.0 / m);
		yinc = -1.0;
	} else if(m == 1 && x1 < x2 ) {
		xinc = 1.0;
		yinc = 1.0;
	} else {
        xinc = -1.0;
        yinc = -1.0;
    }

    while (round(x) <= x2 && round(y) <= y2) { 
        glVertex2i(round(x),round(y)); //printing pixel
        x += xinc;
        y += yinc;
    }
    glVertex2i(round(x),round(y));
}

void renderFunction() {
    glClear(GL_COLOR_BUFFER_BIT);			// clearing frame buffer
    glLoadIdentity();					// 
    glPointSize(2.0);					// adjusting the size of pixel
    glClearColor(0.0, 0.0, 0.0, 0.0);			// setting background color to frame buffer
    glColor3f(0.0, 0.9, 1.0);				// ?
    glOrtho(-500.0, 500.0, -500.0, 500.0, 0.0, 1.0);		// left, right, bottom, top, nearVal, varVal
    
    glBegin(GL_LINES);					// GL_POINTS = 0; GL_LINES = 1;
        glVertex2f(500, 0);				// adding point
        glVertex2f(-500, 0);

        glVertex2f(0, 500);
        glVertex2f(0, -500);
    glEnd();						// // end of drawing

    glColor3f(1.0, 0.0, 1.0);	
    glBegin(0);
	    dda(200, 200, 100, 100); //1
	    dda(-200, 200, -100, 100); //2
	    dda(-200, -200, -100, -100); //3
        dda(200, -200, 100, -100); //3
    glEnd();

    glPointSize(3.0);					// adjusting the size of pixel
    glColor3f(1.0, 0.0, 0.0);	
    glBegin(0);
        glVertex2f(200, 200);
        glVertex2f(100, 100); //1
	    glVertex2f(-200, 200);
        glVertex2f(-100, 100); //2
	    glVertex2f(-200, -200);
        glVertex2f(-100, -100); //3
        glVertex2f(200, -200);
        glVertex2f(100, -100); //3
    glEnd();

    glFlush();						// flush frame buffers
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);				// initializing opengl
    glutInitDisplayMode(GLUT_SINGLE);			// setting display mode

    glutInitWindowPosition(100,100);			// setting window position
    glutInitWindowSize(500, 500);			// setting window size

    glutCreateWindow("OpenGL - First window demo");	// creating window using glut

    glutDisplayFunc(renderFunction);			// specifying callback function

    glutMainLoop();    					// loop for keep program running

    return 0;
}
