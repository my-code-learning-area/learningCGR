#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

int choice;
double original[4][3];
double transform[3][3];
double result[4][3];

void transfer();
void goSwitch();

void printMatrix()
{
	cout<<"Original :"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<original[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Transform :"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<transform[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Result :"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}

void matrixMult()
{
	for(int i=0;i<4;i++)
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

void transfer()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			original[i][j] = result[i][j];
		}
	}
}

void divideScreen()
{
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2i(-300,0);
		glVertex2i(300,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(0, 300);
		glVertex2i(0, -300);
	glEnd();
}

void display()
{
	divideScreen();
	
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(original[0][0], original[0][1]);
		glVertex2i(original[1][0], original[1][1]);
		glVertex2i(original[2][0], original[2][1]);
		glVertex2i(original[3][0], original[3][1]);
	glEnd();
	
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
		glVertex2i(result[0][0], result[0][1]);
		glVertex2i(result[1][0], result[1][1]);
		glVertex2i(result[2][0], result[2][1]);
		glVertex2i(result[3][0], result[3][1]);
	glEnd();
	
	glFlush();
	
	transfer();
	goSwitch();
}


void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}

double angle(double a)
{
	return (double) a*3.14f/180;
}

void translate()
{
	int tx, ty, r;
	cout<<"Enter tx and ty : ";
	cin>>tx>>ty;
	transform[0][0] = 1;
	transform[0][1] = 0;
	transform[0][2] = 0;
	transform[1][0] = 0;
	transform[1][1] = 1;
	transform[1][2] = 0;
	transform[2][0] = tx;
	transform[2][1] = ty;
	transform[2][2] = 1;
	matrixMult();
}

void rotateAC()
{
	double theta;
	cout<<"Enter rotation angle : ";
	cin>>theta;
	double ang = angle(theta);
	
	transform[0][0] = cos(ang);
	transform[0][1] = sin(ang);
	transform[0][2] = 0;
	transform[1][0] = -sin(ang);
	transform[1][1] = cos(ang);
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
	matrixMult();
}

void rotateC()
{
	double theta;
	cout<<"Enter rotation angle : ";
	cin>>theta;
	double ang = angle(theta);
	
	transform[0][0] = cos(ang);
	transform[0][1] = -sin(ang);
	transform[0][2] = 0;
	transform[1][0] = sin(ang);
	transform[1][1] = cos(ang);
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
	matrixMult();
}
void reflectX() //creation of reflection to X axix matrix
{
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
}
void reflectY() //creation of reflection to Y axix matrix
{
	transform[0][0] = -1;
	transform[0][1] = 0;
	transform[0][2] = 0;
	transform[1][0] = 0;
	transform[1][1] = 1;
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
	matrixMult();
}
void reflectO() //creation of reflection to origin matrix
{
	transform[0][0] = -1;
	transform[0][1] = 0;
	transform[0][2] = 0;
	transform[1][0] = 0;
	transform[1][1] = -1;
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
	matrixMult();
}
void reflectXY() //creation of reflection to X=Y matrix
{
	transform[0][0] = 0;
	transform[0][1] = 1;
	transform[0][2] = 0;
	transform[1][0] = 1;
	transform[1][1] = 0;
	transform[1][2] = 0;
	transform[2][0] = 0;
	transform[2][1] = 0;
	transform[2][2] = 1;
	matrixMult();
}

void goSwitch()	//switch statements for all transformations
{
	cout<<"1 : Translate"<<endl;
	cout<<"2 : Rotation Anticlockwise"<<endl;
	cout<<"3 : Rotation Clockwise"<<endl;
	cout<<"4 : Reflection X"<<endl;
	cout<<"5 : Reflection Y"<<endl;
	cout<<"6 : Reflection Origin"<<endl;
	cout<<"7 : Reflection X = Y"<<endl;
	cout<<"Choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			translate();
			break;
			
		case 2:
			rotateAC();
			break;
			
		case 3:
			rotateC();
			break;
			
		case 4:
			reflectX();
			break;
			
		case 5:
			reflectY();
			break;
			
		case 6:
			reflectO();
			break;
			
		case 7:
			reflectXY();
			break;	
		
		default :
			cout<<"Wrong Choice"<<endl;
			exit(0);
	}
	
	printMatrix();
	display();
}

void userInput()	// Take polygon input in a matrix
{
	int x,y,w;
	cout<<"input x and y co-ordinates : ";
	cin>>x>>y;
	cout<<"input width of square : ";
	cin>>w;
	
	original[0][0] = x;
	original[0][1] = y;
	original[0][2] = 1;
	original[1][0] = x+w;
	original[1][1] = y;
	original[1][2] = 1;
	original[2][0] = x+w;
	original[2][1] = y+w;
	original[2][2] = 1;
	original[3][0] = x;
	original[3][1] = y+w;
	original[3][2] = 1;
	
	goSwitch();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("N7");
	init();
	userInput();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
