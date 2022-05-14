void rotate(int x, int y, double rotation, int mode) {
    double xr, yr;
    if(mode == 1) { // anti-clockwise
        xr = (x * cos(rotation)) + (y * (-sin(rotation)));
        yr = (x * sin(rotation)) + (y * (cos(rotation)));

    } else { // clockwise
        xr = (x * cos(rotation)) + (y * (sin(rotation)));
        yr = (x * (-sin(rotation))) + (y * (cos(rotation)));
    }

    glVertex2d(xr, yr);

    glFlush();
}

void printPoint(double xi, double yi, double x, double y);

void drawCircle(double x, double y, double r)
{
    double xi = 0;
    double yi = r;

    // // displyaing some points
    // glBegin(GL_POINTS);
    //     glVertex2f(x + xi, y + yi);
    //     glVertex2f(x + yi, y + xi);
    //     glVertex2f(x - xi, y - yi);
    //     glVertex2f(x - yi, y + xi);
    // glEnd();
    // glFlush();

    double D = 3 - 2 * r;
    while (xi <= yi)
    {
        printPoint(xi, yi, x, y);

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

        for(int i = 0; i < 2000; i++)
            for(int j = 0; j < 2000; j++) {}        
    }
    printPoint(xi, yi, x, y);


    glFlush();
}

void printPoint(double xi, double yi, double x, double y)
{
    glBegin(GL_POINTS);
        // 1st quadrant
        glVertex2f(round(x+xi), round(y+yi));
        glVertex2f(round(x+yi), round(y+xi));

        // 4th quadrant
        glVertex2f(round(x+yi), round(y-xi));
        glVertex2f(round(x+xi), round(y-yi));

        // 3rd quadrant
        glVertex2f(round(x-yi), round(y-xi));
        glVertex2f(round(x-xi), round(y-yi));

        // 2nd quadrant
        glVertex2f(round(x-yi), round(y+xi));
        glVertex2f(round(x-xi), round(y+yi));


        // 1st quadrant
        rotate(round(x+xi), round(y+yi), 0.3, 1);
        rotate(round(x+yi), round(y+xi), 0.3, 1);

        // 4th quadrant
        rotate(round(x+yi), round(y-xi), 0.3, 1);
        rotate(round(x+xi), round(y-yi), 0.3, 1);

        // 3rd quadrant
        rotate(round(x-yi), round(y-xi), 0.3, 1);
        rotate(round(x-xi), round(y-yi), 0.3, 1);

        // 2nd quadrant
        rotate(round(x-yi), round(y+xi), 0.3, 1);
        rotate(round(x-xi), round(y+yi), 0.3, 1);
    glEnd();
    glFlush();
}
