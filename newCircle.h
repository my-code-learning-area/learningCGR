void printPoint(int xi, int yi, int x, int y);

void drawCircle(int x, int y, int r)
{
    int xi = 0;
    int yi = r;

    // displyaing some points
    glBegin(GL_POINTS);
        glVertex2d(x + xi, y + yi);
        glVertex2d(x + yi, y + xi);
        glVertex2d(x - xi, y - yi);
        glVertex2d(x - yi, y + xi);
    glEnd();
    glFlush();

    double D = 3 - 2 * r;
    while (xi <= yi)
    {
        if (D < 0)
        {
            D += 4 * xi + 6;
            xi++;
        }
        else
        { // d>=0
            D += 4 * (xi - yi) + 10;
            xi++; // remove this line and see magic
            yi--;
        }

        printPoint(xi, yi, x, y);
    }

    glFlush();
}

void printPoint(int xi, int yi, int x, int y)
{
    glBegin(GL_POINTS);
        // 1st quadrant
        glVertex2d(round(x+xi), round(y+yi));
        glVertex2d(round(x+yi), round(y+xi));

        // 4th quadrant
        glVertex2d(round(x+yi), round(y-xi));
        glVertex2d(round(x+xi), round(y-yi));

        // 3rd quadrant
        glVertex2d(round(x-yi), round(y-xi));
        glVertex2d(round(x-xi), round(y-yi));

        // 2nd quadrant
        glVertex2d(round(x-yi), round(y+xi));
        glVertex2d(round(x-xi), round(y+yi));
    glEnd();
    glFlush();
}