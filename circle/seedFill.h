// 1
struct color{ // define structure to get color object
    GLubyte r, g, b; // GLubyte is user defined datatype by OpenGL
};

// 3
void fillPixel(int x, int y, color fillColor) {
    // step 1: set the color in glColor3ub (ub for unsigned byte [as we are using GLubyte datatype in structure])
    glColor3ub(fillColor.r, fillColor.g, fillColor.b);
    // step 2: fill the pixel
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

// 2
void seedFill(int x, int y, color oldColor, color fillColor) { // performing flood fill (4 symmetry)
    color c;
    // color is an object of color structure ( struct color{...}; )

    //// step 1: get color of current pixel (x, y)
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
    // x, y is location of pizel
    // 1, 1 is size of pixel
    // GL_RGB: we will get color in RGB format
    // GL_UNSIGNED_BYTE: to tell the datatype of values; (we defined GLubyte datatypes in structure of color); will return values for GLubyte datatype

    //// step 2: if pixel color is equals to [oldColor/backgroudColor/previousColor] then fill the color
    if((c.r == oldColor.r) && (c.g == oldColor.g) && (c.b == oldColor.b)) { 
        // we have RGB values stored in structure object variables; inorder to access the variable we usually access it by objectname.variable name
        
        fillPixel(x, y, fillColor);
        //// step3: fill the color

        seedFill(x + 1, y, oldColor, fillColor);
        seedFill(x - 1, y, oldColor, fillColor);
        seedFill(x, y + 1, oldColor, fillColor);
        seedFill(x, y - 1, oldColor, fillColor);
        //// step4: similarly call the function for side pixels also, this is 4 symmetry flood fill algorithm
    }
}