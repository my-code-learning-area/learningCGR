#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>
using namespace std;

void ddaFunction() {
	float x2 = 100.0, y2 = -100.0;    		// (x1, y1)
	float x1 = 415.0, y1 = -384.0;  		// (x2, y2)

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


	glBegin(GL_POINTS); // opengl draw pixel
		// incrementing and previous pixel to get next pixel
		cout<<endl<<endl<<"=================================================================================================================================="<<endl;
		cout<<"(xn,yn) - incremented	|	plot (x, y) - rounded	|	slope = m	|	x-increment	|	y-increment  "<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
		while (round(x) <= x2 && round(y) <= y2) { 

			cout<<"(x,y)=("<<x<<","<<y<<");\t|\t"<<"(r(x),r(y))=("<<round(x)<<","<<round(y)<<");\t|\t"<<"m="<<m<<";\t|\t"<<"xinc="<<xinc<<";\t|\t"<<"yinc="<<yinc<<endl;
			glVertex2i(round(x),round(y)); //printing pixel
			x += xinc;
			y += yinc;
		}
		cout<<"(x,y)=("<<x<<","<<y<<");\t|\t"<<"(r(x),r(y))=("<<round(x)<<","<<round(y)<<");\t|\t"<<"m="<<m<<";\t|\t"<<"xinc="<<xinc<<";\t|\t"<<"yinc="<<yinc<<endl;
		cout<<"=================================================================================================================================="<<endl;
		glVertex2i(round(x),round(y)); //printing pixel
	glEnd(); // closing opengl draw pixel
	glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);

    glutCreateWindow("OpenGL - DDA");

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	//glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(ddaFunction);

    glutMainLoop();

    return 0;
}
