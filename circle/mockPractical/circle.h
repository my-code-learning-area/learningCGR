void printPoint(double xi, double yi, double x, double y){
	glBegin(GL_POINTS);
		glVertex2d(x + xi, y + yi);
		glVertex2d(x + yi, y + xi);
		
		glVertex2d(x + yi, y - xi);
		glVertex2d(x + xi, y - yi);	
		
		glVertex2d(x - xi, y - yi);
		glVertex2d(x - yi, y - xi);
		
		glVertex2d(x - yi, y + xi);
		glVertex2d(x - xi, y + yi);		
	glEnd();
	glFlush();
}

void circle(double x, double y, double r) {
	double xi = 0, yi = r;
	double D = 3 - (2 * r);
	
	while(xi <= yi) {
		printPoint(xi, yi, x, y);
		
		if(D < 0) {
			D += (4 * xi) + 6;
		} else {
			D += (4 * (xi - yi)) + 10;
			yi --;
		}
		xi ++;
		for(int i = 0; i < 2000; i++) 
			for(int j = 0; j < 2000; j++){}
	}
	printPoint(xi, yi, x, y);
}