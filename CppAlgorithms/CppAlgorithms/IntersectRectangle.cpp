#include <iostream>
#include <algorithm>

using namespace std; 

/* EPI Chapter 5.11
 * Find intersect rectangle of two rectangles. 
 * Boundaries touch also count as intersect. 
 */

struct Rectangle {
	int x, y, width, height; 
};

ostream& operator<< (ostream &os, const Rectangle &rec) {
	os << "(" << rec.x << "," << rec.y << ") " << "w: " << rec.width << " h: " << rec.height; 
	return os; 
}

bool IsIntersect(const Rectangle &R1, const Rectangle &R2) {
	return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
		R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
}

Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2) {
	if (IsIntersect(R1, R2)) {
		return{ max(R1.x, R2.x), max(R1.y, R2.y),
			min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
			min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)}; 
	}
	return{ 0, 0, -1, -1 }; 
}

void test_intersect_rectangle() {
	Rectangle r1 = { 1, 2, 3, 2 }; 
	Rectangle r2 = { 2, 1, 3, 2 }; 
	cout << IntersectRectangle(r1, r2) << endl; 
}