#include <iostream>

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

Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2) {

}