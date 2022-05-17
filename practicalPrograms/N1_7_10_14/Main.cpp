#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

int choice;
double original[5][3];
double transform[3][3];
double result[5][3];

void init() {
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
    glFlush();

    glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2i(-300,0);
		glVertex2i(300,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(0, 300);
		glVertex2i(0, -300);
	glEnd();
    glFlush();
}

double angle(double a) {   
    return (double) a*3.14f/180;
}

void matrixMult()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			double sum = 0;
			for(int k=0;k<3;k++)
			{
				sum +=  original[i][k]*transform[k][j];
			}
			result[i][j] = sum;
		}
	}
}

void display() {
    int x,y,w;
	// cout<<"input x and y co-ordinates : ";
	// cin>>x>>y;
	// cout<<"input width of square : ";
	// cin>>w;
    x = 100;
    y = 10;
    w = 50;

	original[0][0] = x;
	original[0][1] = y;
	original[0][2] = 1;

	original[1][0] = x+w;
	original[1][1] = y;
	original[1][2] = 1;
	
    original[2][0] = x + w + (w/2);
	original[2][1] = y + (w/2);
	original[2][2] = 1;

    original[3][0] = x+w;
	original[3][1] = y+w;
	original[3][2] = 1;

	original[4][0] = x;
	original[4][1] = y+w;
	original[4][2] = 1;

     //display
    glColor3d(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(original[0][0], original[0][1]);
		glVertex2i(original[1][0], original[1][1]);
		
        glVertex2i(original[2][0], original[2][1]);
		glVertex2i(original[3][0], original[3][1]);

		glVertex2i(original[4][0], original[4][1]);
	glEnd();
	glFlush();

    int tx, ty, r;


    /* // cout<<"Enter rotation angle: ";
    // cin>>tx;
    for(int tx = 0; tx < 360; tx += 10) { //40
        transform[0][0] = cos(angle(tx));
        transform[0][1] = sin(angle(tx));
        transform[0][2] = 0;
        transform[1][0] = -sin(angle(tx));
        transform[1][1] = cos(angle(tx));
        transform[1][2] = 0;
        transform[2][0] = 0;
        transform[2][1] = 0;
        transform[2][2] = 1;

        matrixMult();

        glColor3d(0,0,1);
        glBegin(GL_LINE_LOOP);
            glVertex2i(result[0][0], result[0][1]);
            glVertex2i(result[1][0], result[1][1]);
            
            glVertex2i(result[2][0], result[2][1]);
            glVertex2i(result[3][0], result[3][1]);
        glEnd();
        glFlush();
        for(int i = 0; i < 5000; i++)
            for(int j = 0; j < 5000; j++) {}
    } */

    transform[0][0] = 1;
	transform[0][1] = 0;
	transform[0][2] = 0;
	transform[1][0] = 0;
	transform[1][1] = -1;
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
    matrixMult();

    glColor3d(0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2i(result[0][0], result[0][1]);
        glVertex2i(result[1][0], result[1][1]);
        
        glVertex2i(result[2][0], result[2][1]);
        glVertex2i(result[3][0], result[3][1]);

        glVertex2i(result[4][0], result[4][1]);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("N7");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
