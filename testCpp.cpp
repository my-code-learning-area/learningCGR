#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void initialize()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0, 600, 600, 0);
}

void plotpixel(int x, int y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void dda(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	float step = fmax(abs(dx), abs(dy));

	float xin = dx / step;
	float yin = dy / step;

	float x = x1;
	float y = y1;

	for(int i =0;i<step;i++)
	{
		plotpixel((int)x, (int)y);
		x += xin;
		y += yin;
	}
}


void octant(int x,int y,int p,int q)
{
	plotpixel(x+p,y+q);
	plotpixel(y+p,x+q);
	plotpixel(-y+p,x+q);
	plotpixel(-x+p,y+q);
	plotpixel(-x+p,-y+q);
	plotpixel(-y+p,-x+q);
	plotpixel(y+p,-x+q);
	plotpixel(x+p,-y+q);
}

void bresenham(float xc,float yc,float r)
{
	float x=0;
	float y=r;
	float d=3-2*r;
	while(x<y)
		{
			octant(x,y,xc,yc);
			if(d<0){
					d=d+4*x+6;	
					x=x+1;	
				}
			else{
					d=d+4*(x-y)+10;	
					x=x+1;
					y=y-1;	
				}
								
		}
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Clipping");
    initialize();
    bresenham(250,400,25);
    bresenham(500,400,25);
    bresenham(440,400,25);
    bresenham(250,400,15);
    bresenham(500,400,15);
    bresenham(440,400,15);
    dda(200,370,325,370);
    dda(200,370,200,340);
    dda(325,370,325,250);
    dda(325,250,300,250);
    dda(300,250,300,290);
    dda(300,290,250,290);	
    dda(250,300,300,300);
    dda(255,305,295,305);
    dda(295,305,295,345);
    dda(295,345,255,345);
    dda(250,300,250,350); 
    dda(255,345,255,305); 
    dda(250,350,300,350);
    dda(300,350,300,300); 
    //dda(305,305,245,305);

    dda(250,290,200,340);
    

    dda(327,370,550,370);
    dda(327,370,327,250);
    dda(550,370,550,250);
    dda(327,250,550,250);
    glutMainLoop();
}