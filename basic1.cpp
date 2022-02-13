//#include<GL/gl.h>  //openGL api header file
//#include<GL/glu.h> //openGL utility livrary
#include<GL/glut.h>  // openGL utility toolkit	// both above are included in glut library // provides function to make openGL lot easier and the functions for to interact with the windows api because opengl library does not support openWindow and all the stuff, it uses windows/operating system api for that
///////////////////opengl is dependent on operating system///////////////////

void display(); //funciton will sent as callback funciton to the apis

void init() { // to clear color to yellow
	glClearColor(1.0, 1.0, 0.0, 1.0); // 0 to 1 // when glClear() function is called, the framebuffer will cleared to yellow color
}

int main(int argc, char** argv) { // argv is array of string which contains command and arguments
	glutInit(&argc, argv);		// alwas put this line in every opengl program
	glutInitDisplayMode(GLUT_RGB); // adding display mode
	
	// before creating window.. initialize some functions to the window
	glutInitWindowPosition(500,200); // specify it or window will position randomly
	glutInitWindowSize(500, 350);

	//creating window using glut
	glutCreateWindow("Learning OpenGL - Window 1");
	
	//specify the callback funciton to the api (api will call that funciton whenever it needs)
	glutDisplayFunc(display); // callback funciton shall not take any arguments and has return type as void

	init();

	glutMainLoop(); // if this loop terminates.. out program will terminate // the loop continiously running our program
}

/*
by default the background color of window is black
and dimentions 500, 500
*/

void display() {
	// before drawing anything on window we just need to clear it
	// because we might have some drawings leaft from previous frame
	glClear(GL_COLOR_BUFFER_BIT); // 1. clear // cleares frame buffere, deapth buffer,... // we cleared the frame buffer to the default color and the default color is black. so the frame buffer is cleared to black
	glLoadIdentity(); // 2. reset // resets all the transmission of the current matrix you are currently in. it resets the matrix (resets our co-ordinates system);
	
	// 3. draw
	

	glFlush(); // 4. display // will display frame buffer on the screen	
} 































/*#include <GL/glut.h>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}*/
