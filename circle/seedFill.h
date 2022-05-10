struct color{
    GLubyte r, g, b;
};

void fillPixel(int x, int y, color fillColor) {
    glPointSize(1);
    glColor3ub(fillColor.r, fillColor.g, fillColor.b);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

void seedFill(int x, int y, color oldColor, color fillColor) { // performing flood fill (4 symmettry)
    color c;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
    if((c.r == oldColor.r) && (c.g == oldColor.g) && (c.b == oldColor.b)) {
        fillPixel(x, y, fillColor);
        seedFill(x + 1, y, oldColor, fillColor);
        seedFill(x - 1, y, oldColor, fillColor);
        seedFill(x, y + 1, oldColor, fillColor);
        seedFill(x, y - 1, oldColor, fillColor);
    }
}