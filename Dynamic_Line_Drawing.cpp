
#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

void init2D(float r, float g, float b){
    glClearColor(r,g,b,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

vector <pair<int,int> > linepoints,polygonpoints;

void display(){
    cout<<"Inside the display function\n";
    glColor3f(0,1.0,0);
    if(linepoints.size() > 0){
        cout<<"The set of end points are: "<<linepoints[0].first<<" "<<linepoints[0].second<<"\n";
        cout<<"The set of end points are: "<<linepoints[linepoints.size()-1].first<<" "<<linepoints[linepoints.size()-1].second<<"\n";
        for(int i=0; i < linepoints.size(); ++i){
            glBegin(GL_POINTS);
                glVertex2f(linepoints[i].first,linepoints[i].second);
            glEnd();
            glFlush();
        }
    }
}


void draw_line(int x1, int y1, int x2, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;incy = 1;
	if (x2 < x1) incx = -1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	linepoints.clear();
	if (dx > dy) {
		linepoints.push_back(make_pair(x,y));
		//draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else{
				e += inc2;
			}
			x += incx;
			//draw_pixel(x, y);
			linepoints.push_back(make_pair(x,y));
		}

	} else {
		//draw_pixel(x, y);
		linepoints.push_back(make_pair(x,y));
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else{
				e += inc2;
			}
			y += incy;
			//draw_pixel(x, y);
			linepoints.push_back(make_pair(x,y));
		}
	}
	display();
}


int cnt=0;
vector<pair<int,int> > points;
int start_x,start_y;
void Mymouse(int button, int state, int x,int y){
    if(points.size() < 2 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        if(points.size() == 0){
            start_x=x;start_y=500-y;
        }
        points.push_back(make_pair(x,500-y));
        cout<<"The x and y are: "<<x<<" "<<500-y<<"\n";
    }
    if(points.size() == 2){
        linepoints.clear();
        draw_line(points[0].first,points[0].second,points[1].first,points[1].second);
        points[0]=points[1];
        points.pop_back();
    }
    if(state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON){
        draw_line(start_x,start_y,points[0].first,points[0].second);
        points.clear();
    }
}


// To avoid mutliple main definitions !

int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("points and lines");
    init2D(1.0,1.0,1.0);
    glPointSize(2);
    glutMouseFunc(Mymouse);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

