/*
#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

void init2D(float r, float g, float b){
    glClearColor(r,g,b,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(){
        glClear(GL_COLOR_BUFFER_BIT);
}

vector<pair<int,int> > intersction_points,linepoints;
/*void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}*/

/*
int draw_line(pair<int,int> p1,pair<int,int> p2){
    if(p1.first > p2.first){
        swap(p1,p2);
    }
    //cout<<"The points are: "<<p2.second<<" "<<p1.second<<" "<<p2.first<<" "<<p1.first<<"\n";
    double slope = (1.00*p2.second - 1.00*p1.second)/(1.00*p2.first - 1.00*p1.first);
    //cout<<"The slope is: "<<slope<<"\n";
    if(slope >= 1){
        //step in y
        linepoints.push_back(make_pair(p1.first,p1.second));
        int dely = p2.second - p1.second, delx = p2.first - p1.first;
        int pk=2*dely - delx;
        int xval = p1.first+1,yval = p1.second;
        linepoints.push_back(make_pair(xval,(pk > 0)?(yval + 1):(yval)));
        int i=0;
        while(linepoints[i+1].first != p2.first){
            i+=1;
            xval++;
            if(pk < 0){
                pk = pk + 2*dely;
                linepoints.push_back(make_pair(xval,(pk > 0)?(linepoints[i].second + 1):(linepoints[i].second)));
            }
            else{
                pk = pk + 2*dely - 2*delx;
                linepoints.push_back(make_pair(xval,(pk > 0)?(linepoints[i].second + 1):(linepoints[i].second)));
            }
        }
    }
    else{
        //step in x
        linepoints.push_back(make_pair(p1.first,p1.second));
        int dely = p2.second - p1.second, delx = p2.first - p1.first;
        int pk=2*dely - delx;
        int xval = p1.first+1,yval = p1.second;
        linepoints.push_back(make_pair(xval,(pk > 0)?(yval + 1):(yval)));
        int i=0;
        while(linepoints[i+1].first != p2.first){
            i+=1;
            xval++;
            if(pk < 0){
                pk = pk + 2*dely;
                linepoints.push_back(make_pair(xval,(pk > 0)?(linepoints[i].second + 1):(linepoints[i].second)));
            }
            else{
                pk = pk + 2*dely - 2*delx;
                linepoints.push_back(make_pair(xval,(pk > 0)?(linepoints[i].second + 1):(linepoints[i].second)));
            }
        }
    }
    //displaymain();
    linepoints.clear();
}

int cnt=0;
vector<pair<int,int> > points;
void Mymouse(int button, int state, int x,int y){
    if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        points.push_back(make_pair(x,500-y));
        cout<<"The x and y are: "<<x<<" "<<500-y<<"\n";
    }
    else if(button == GLUT_RIGHT_BUTTON){
        glColor3f(0,1,0);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);
            for(int i=0; i < points.size(); ++i){
                glVertex2d(points[i].first,points[i].second);
            }
        glEnd();
        glFlush();
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
    // To increase the point size
    glutMouseFunc(Mymouse);
    //---------------------
    glPointSize(3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}*/
