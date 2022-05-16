#include<GL/glut.h>

void plotCircle(int x, int y, double xi ,double yi){

	glBegin(GL_POINTS);
		glVertex2i(x+xi, y+yi);
		glVertex2i(x+yi, y+xi);

		glVertex2i(x+yi, y-xi);
		glVertex2i(x+xi, y-yi);

		glVertex2i(x-xi, y-yi);
		glVertex2i(x-yi, y-xi);

		glVertex2i(x-yi, y+xi);
		glVertex2i(x-xi, y+yi);

	glEnd();
	glFlush();
}

void circles(int x, int y, int r){
	
	double xi, yi, D;
	xi = 0;
	yi = r;

	D = 3 - 2*r;

	while(xi<=yi){
		plotCircle(x, y, xi, yi);	
		if(D<0){
			D = D + (4*xi) + 6;
			xi = xi + 1;
		}else{
			D = D + (4*(xi - yi)) + 10;
			xi = xi + 1;
			yi = yi - 1;
		}
		
	}
	plotCircle(x, y, xi, yi);
	
	
}

void display(){

	circles(350,350,250);

}

void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	gluOrtho2D(0,700,0,600);
	glColor3f(0,0,0);
	glFlush();
}

int main(int argv, char** argc){

	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(20,40);
	glutInitWindowSize(700,600);

	glutCreateWindow("Circle");	
	
	init();

	glutDisplayFunc(display);
	glutMainLoop();

}