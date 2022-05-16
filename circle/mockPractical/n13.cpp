/*
Problem Statement:
    N13: write a program in opengl on linux platorm to draw a design shown on right using 
		bresenham circle drawing algorithm.
    User should only give center co-ordinates and radious. rest should be drawn automatically.
    Use mouse/without mouse to plot the points.

Name: Sumit Uttamrao Kawale;
Rollno: 23357;
class: SE-11
batch: G-11


g++ n13.cpp -o n13 -lglut -lGL -lGLU -lGLU; ./n13
*/

#include <GL/glut.h>
#include <math.h>
#include "circle.h"
#include<iostream>
using namespace std;

void drawSmallCircles(double xi, double yi, double x, double y, double smallRadious) {
	circle(x + xi, y + yi, smallRadious);
	circle(x + yi, y + xi, smallRadious);
	
	circle(x + yi, y - xi, smallRadious);
	circle(x + xi, y - yi, smallRadious);	
	
	circle(x - xi, y - yi, smallRadious);
	circle(x - yi, y - xi, smallRadious);
	
	circle(x - yi, y + xi, smallRadious);
	circle(x - xi, y + yi, smallRadious);
}

void bangleCircle(double x, double y, double r) {
	double xi = 0, yi = r;
	double D = 3 - (2 * r);
	

	// getting diameter and radious of small circles (will print on bangle)
	double smallDiameter = (2 * 3.14 * r) / 40;
	double smallRadious = (smallDiameter) / 2;
	
	double count = 1;
	double countInce = 0;

	drawSmallCircles(xi, yi, x, y, smallRadious);
	
	while(xi <= yi) {
		if(count < smallDiameter-1) {	
			count += 1 + countInce;
		} else {	
			drawSmallCircles(xi, yi, x, y, smallRadious);
			countInce += 0.065;	
			count = 0;	
		}
		
		if(D < 0) {
			D += (4 * xi) + 6;
		} else {
			D += (4 * (xi - yi)) + 10;
			yi --;
		}
		xi ++;
		
		//printPoint(xi, yi, x, y);
	}
	
	circle(x + xi, y + yi, smallRadious);
	circle(x + xi, y - yi, smallRadious);	
	circle(x - xi, y - yi, smallRadious);
	circle(x - xi, y + yi, smallRadious);
	glFlush();
}

void display() {
	int x=350;
	int y=350;
	int r=50;
	bangleCircle(x, y, r);
	int miniCircleR = (((2 * 3.14 * r)/40)/2);
	int inCircleR = r - miniCircleR;
	circle(x, y, inCircleR);
	circle(x, y, r - miniCircleR*2);
	
	x=350;
	y=350;
	r=100;
	bangleCircle(x, y, r);
	miniCircleR = (((2 * 3.14 * r)/40)/2);
	inCircleR = r - miniCircleR;
	circle(x, y, inCircleR);
	circle(x, y, r - miniCircleR*2);
	
	x=350;
	y=350;
	r=200;
	bangleCircle(x, y, r);
	miniCircleR = (((2 * 3.14 * r)/40)/2);
	inCircleR = r - miniCircleR;
	circle(x, y, inCircleR);
	circle(x, y, r - miniCircleR*2);
	
	x=350;
	y=350;
	r=300;
	bangleCircle(x, y, r);
	miniCircleR = (((2 * 3.14 * r)/40)/2);
	inCircleR = r - miniCircleR;
	circle(x, y, inCircleR);
	circle(x, y, r - miniCircleR*2);
	
}

void init() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	gluOrtho2D(0, 700, 0, 700);
	glColor3d(0, 0, 1);
	
	glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    
    glutCreateWindow("N13");
    init();
    glutDisplayFunc(display);
    glFlush();
    
    glutMainLoop();
    return 1;
}