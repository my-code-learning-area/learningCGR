void putPixels(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
        glVertex2d(xc + x, yc + y);
        glVertex2d(xc + y, yc + x);

        glVertex2d(xc + x, yc - y);
        glVertex2d(xc + y, yc - x);

        glVertex2d(xc - x, yc - y);
        glVertex2d(xc - y, yc - x);

        glVertex2d(xc - x, yc + y);
        glVertex2d(xc - y, yc + x);
    glEnd();

}

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;

    glBegin(GL_POINTS);
        glVertex2d(xc + x, yc + y);
        glVertex2d(xc + y, yc + x);
        glVertex2d(xc + x, yc - y);
        glVertex2d(xc - y, yc + x);
    glEnd();
    
    double p = 1 - r;

    while(x < y) {
        if(p <= 0) {
            x ++;
            p += 2 * x + 1;
        } else {
            x ++;
            y --;
            p += 2 * (x - y) + 1;
        }

        putPixels(x, y, xc, yc); 
    }
}