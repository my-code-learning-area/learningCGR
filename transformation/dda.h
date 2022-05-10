
void dda(int x1, int y1, int x2, int y2, int type) {
    // type = 1 (simple line); 2 = (dashed line); 3 = (dotted line)
    double dx = x2 - x1;
    double dy = y2 - y1;
    double m = abs(dy / dx);

    double xinc, yinc;
    double x = x1, y = y1;

    if(dx == 0) { //y
        xinc = 0;
        yinc = 1;
    } else if(m == 1 && x2 > x1) { //m
        xinc = 1;
        yinc = 1;
    } else if(m == 1 && x2 < x1) { //-m
        xinc = -1;
        yinc = -1;
    } else if (m < 1 && x2 > x1) { //x
        xinc = 1;
        yinc = m;
    } else if (m < 1 && x2 < x1) { //-x
        xinc = -1;
        yinc = -m;
    } else if (m > 1 && y2 > y1) { //y
        xinc = 1 / m;
        yinc = 1;
    } else if (m > 1 && y2 < y1) { //-y
        xinc = -(1 / m);
        yinc = -1;
    }

    int countDot = 1;
    for(int i = 0; i < (abs(dx) > abs(dy) ? abs(dx) : abs(dy)); i++) {
        glBegin(GL_POINTS);
			if (type == 2){ // dashed
				if(countDot < 3) {
					glVertex2d(round(x), round(y));
					countDot++;
				} else if(countDot < 5) {
					countDot++;
				} else {
					countDot = 0;
				}
			} else if(type == 3){ // dotted
				if(countDot) {
					countDot --;
					glVertex2d(round(x), round(y));
				} else {
					countDot ++;
				}
			} else { // simple
				glVertex2d(round(x), round(y));
			} 

			x += xinc;
			y += yinc;
        glEnd();
        glFlush();
    }
	
	glBegin(GL_POINTS);
    glVertex2d(round(x), round(y));
	glEnd();
    glFlush();
    
}