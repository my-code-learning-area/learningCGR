#include<GL/glut.h>
#include <cmath>
using namespace std;

int line_co_ordinates[4], i = 0;

void BSA_Algo(int xi, int yi, int xf, int yf)
{

	int P; // variable for dicision parameter
	//// step: calculate dy and dx of line (|value| should be absolute)
	int dx = abs(xf - xi); // xi: initial x, xf: final f; similar with y
	int dy = abs(yf - yi);
	int x = xi, y = yi;

	//// step: calculate x_change and y_change (-1/+1)
	int x_change = xi > xf ? -1 : 1;
	int y_change = yi > yf ? -1 : 1;

	//// step: plot fist pixel
	glVertex2i(x, y);

	//// step: if line is horizontal.. draw it and return
	if (dx == 0) // drawing vertical line
	{
		glBegin(GL_POINTS);
		for (int i = 1; i < dy; i++)
		{
			y += y_change;
			glVertex2i(x, y);
		}
		glEnd();
		return;
	}

	//// step: if line is vertical.. draw it and return
	if (dy == 0) // drawing horizontal line
	{
		glBegin(GL_POINTS);
		for (int i = 1; i < dx; i++)
		{
			x += x_change;
			glVertex2i(x, y);
		}
		glEnd();
		return;
	}

	glBegin(GL_POINTS);
	//// step: if the line is inclient to x axis then-
	if (dx > dy)
	{
		// step: calculate decision parameter by using formule [2dy - dx]
		P = 2 * dy - dx; //(2dy - dx)
		for (int i = 0; i < dx; i++)
		{
			if (P > 0)
			{
				y += y_change;
				P = P + 2 * (dy - dx); // p += 2(dy - dx)
			}
			else // if (P <= 0)
			{
				P += 2 * dy; // p += 2dy
			}

			x += x_change;
			glVertex2i(x, y);
		}
	}
	//// step: if the line is inclient to y axis then-
	else // if (dy >= dx)
	{
		P = 2 * dx - dy;
		for (int i = 0; i < dy; i++)
		{
			if (P > 0)
			{
				x += x_change;
				P = P + 2 * (dx - dy); // p += 2(dx - dy)
			}
			else // if (P <= 0)
			{
				P += 2 * dx; // p += 2dx
			}

			y += y_change;
			glVertex2i(x, y);
		}
	}
	glEnd();
}

void mouse_input(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && i < 4)
	{
		line_co_ordinates[i] = x - 300;
		i = i + 1;
		line_co_ordinates[i] = 300 - y;
		i = i + 1;
	}
	if (i == 4)
	{
		glColor3f(1.0, 0.0, 0.0);
		BSA_Algo(line_co_ordinates[0], line_co_ordinates[1], line_co_ordinates[2], line_co_ordinates[3]);
		glutSwapBuffers();
		i = 0;
	}
}

void render_function()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300, 300, -300, 300);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	BSA_Algo(0, 0, 300, 0);
	BSA_Algo(0, 0, 0, 300);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL - Bresenham Line Generation Algo");
	glutDisplayFunc(render_function);
	glutMouseFunc(mouse_input);
	glutMainLoop();
	return 0;
}