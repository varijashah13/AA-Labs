// intersection of 2 lines

#include <iostream>
using namespace std;
struct Point{
	int x;
	int y;
};


bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
   	 q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    return true;

    return false;
}


int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
   		 (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; 

    return (val > 0)? 1: 2; 
}


bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    
    if (o1 != o2 && o3 != o4)
   	 return true;

    
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}



int main(){
	struct Point p1,p2,p3,p4;
	cout << "Enter co ordinates of first point" << endl;
	cin >> p1.x >> p1.y;
	cout << "Enter co ordinates of second point" << endl;
	cin >> p2.x >> p2.y;
	cout << "Enter co ordinates of third point" << endl;
	cin >> p3.x >> p3.y;
	cout << "Enter co ordinates of fourth point" << endl;
	cin >> p4.x >> p4.y;
	if(doIntersect(p1,p2,p3,p4)==true)
	cout << "They Intersect!! " << endl;
	else
	cout << "Do not Intersect"  << endl;
    
    
    
    
    
}


// Graham Scan


#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
	int x, y;
};

Point p0;

Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2)
{
Point *p1 = (Point *)vp1;
Point *p2 = (Point *)vp2;


int o = orientation(p0, *p1, *p2);
if (o == 0)
	return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

return (o == 2)? -1: 1;
}

void convexHull(Point points[], int n)
{

int ymin = points[0].y, min = 0;
for (int i = 1; i < n; i++)
{
	int y = points[i].y;

	if ((y < ymin) || (ymin == y &&
		points[i].x < points[min].x))
		ymin = points[i].y, min = i;
}
swap(points[0], points[min]);


p0 = points[0];
qsort(&points[1], n-1, sizeof(Point), compare);


int m = 1; // Initialize size of modified array
for (int i=1; i<n; i++)
{
	
	while (i < n-1 && orientation(p0, points[i],
									points[i+1]) == 0)
		i++;


	points[m] = points[i];
	m++; // Update size of modified array
}

if (m < 3) return;

stack<Point> S;
S.push(points[0]);
S.push(points[1]);
S.push(points[2]);

for (int i = 3; i < m; i++)
{
	while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
		S.pop();
	S.push(points[i]);
}

while (!S.empty())
{
	Point p = S.top();
	cout << "(" << p.x << ", " << p.y <<")" << endl;
	S.pop();
}
}

int main()
{
	Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
					{0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = sizeof(points)/sizeof(points[0]);
	convexHull(points, n);
	return 0;
}

