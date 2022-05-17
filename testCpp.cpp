#include<GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>
#include<cmath>
using namespace std ;

int xl=50 ,xh=200 ,yl=50 , yh=200 ;
float u1,v1,u2,v2;

struct code
{
	int t,b,r,l;
};

code op_code(int u,int v)
{
	code c = {0,0,0,0};
	if(u<xl)
	{
		c.l=1;
	}
	if(u>xh)
	{
		c.r=1;
	}
	if(v<yl)
	{
		c.b=1;
	}
	if(v>yh)
	{
		c.t=1;
	}
	return c ;
	
}



void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}

void plotpixel(int x ,int y)
{ 
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd(); 
	
}

void DDA(float u1,float v1 ,float u2,float v2)
{
	float dx,dy,xi,yi;
	float step ;
	dx =u2-u1;
	dy =v2-v1;
	float x=u1,y=v1;
	float xinc,yinc;
	plotpixel(x,y);
	
	if (abs(dx)>abs(dy))
	{	
		step=abs(dx);
		for(int i=0;i<dx;i++)
		{
			xinc=dx/(float)step;
			yinc=dy/(float)step;
			x=x+xinc;
			y=y+yinc;
			plotpixel(x,y);
		}	
	}
	else
	{
		step=abs(dy);
		xinc=dx/(float)step;
		yinc=dy/(float)step;
		for(int i=0;i<dy;i++)
		{
			
			x=x+xinc;
			y=y+yinc;
			plotpixel(x,y);
		}
	}

		

}


void cohen()
{
	code c , c1 ,c2 ;
	float m ;
	int xi,yi;
	m=(v2-v1)/(u2-u1);
	c1=op_code(u1,v1);
	c2=op_code(u2,v2);

	while(1)
	{
		//case 1 - line is inside 
		if(c1.t==00 && c2.t==00 && c1.b==00 && c2.b==00 && c1.l==00 && c2.l==00 && c1.r==00 && c2.r==00)
		{
			break;
		}
		// case 2 - line is outside 	
		else if (((c1.t && c2.t) || (c1.b && c2.b) || (c1.r && c2.r) || (c1.l && c2.l)) != 0 )
		{ 
			u1=v1=u2=v2=0;
			break;
		}
		else 
		{
			if(c1.l == 1 || c2.l==1)
			{
				xi=xl;
				yi=v1 + m*(xl-u1);
			}
			else if(c1.r == 1 || c2.r==1)
			{
				xi=xh;
				yi=v1 + m*(xh-u1);
			}
			else if(c1.b == 1 || c2.b==1)
			{
				yi= yl;
				xi= u1+((yl-v1)/m);
			}
			else if(c1.l == 1 || c2.l==1)
			{
				yi=yh;
				xi=u1 + ((yh-v1)/m);
			}  
		}
	}
	

	DDA(xi,yi,u2,v2);
	glFlush();



}




void key(char unsigned key ,int x , int y )
{
	if(key=='c')
	{ 
		cout<<endl<<"pushed"<<endl;
	glClear(GL_COLOR_BUFFER_BIT);
		cohen();
	}		  

}


void Renderfunction()
{
	DDA(50,50,200,50);
	DDA(50,50,50,200);
	DDA(200,50,200,200);
	DDA(50,200,200,200);
	DDA(u1,v1,u2,v2);
	glFlush();
	
}




int main (int argc ,char** argv)
{	cout<<" Enter coordinates of line ";
	cout<<" \nu1 - first point x coordinate " ;
        cin>>u1; 
	cout<<" v1 - first point y coordinate " ;
        cin>>v1; 
	cout<<" u2 - second point x coordinate " ;
        cin>>u2; 
	cout<<" v2 - second point y coordinate " ;
        cin>>v2; 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Line Clipping");
	init();
	glutDisplayFunc(Renderfunction);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}