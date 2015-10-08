#include <iostream>

using namespace std; 

/* EPI Chapter 5.7
 * Compute x ^ y. x is double and y is integer. 
 */

double Power(double x, int y) {
	double res = 1.0; 
	long long power = y;
	if (y < 0) {
		x = 1.0 / x; 
		power = -power; 
	}

	while (power) {
		if (power & 1) {
			res *= x; 
		}
		x *= x;
		power >>= 1; 
	}

	return res; 
}

void test_power() {
	for (int i = -3; i != 4; ++i) {
		cout << "3 ^ (" << i << ") = " << Power(3.0, i) << endl; 
	}
}