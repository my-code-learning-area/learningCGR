#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

void dda(float x1, float y1, float x2, float y2);

void renderFunction() {
    glClear(GL_COLOR_BUFFER_BIT);			// clearing frame buffer
    glLoadIdentity();					// 
    glClearColor(0.0, 0.0, 0.0, 0.0);			// setting background color to frame buffer
    gluOrtho2D(-110.0, 110.0, -110.0, 110.0);		// left, right, bottom, top, nearVal, varVal
    
    glBegin(1);					// GL_POINTS = 0; GL_LINES = 1;
        glColor3f(0.0, 0.9, 1.0);				// ?
        glVertex2d(0.0,  100);
        glVertex2d(0.0,  -100);
        
        glColor3f(1.0, 0.9, 0.0);				// ?
        glVertex2d(-100, 0);
        glVertex2d(100, 0);
    glEnd();						// // end of drawing
    
    glPointSize(5.0);					// adjusting the size of pixel
    glBegin(0);
        glColor3f(1,1,1);
        glVertex2d(0,0);

    glEnd();

    glPointSize(2);					// adjusting the size of pixel
    glBegin(GL_POINTS);
        glColor3f(0.5,0.2,1);
        dda(10, 10, 10, 100); //3
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