#include <iostream>

using namespace std; 

/* EPI Chapter 5.5
 * Multiply x and y without arithmetical operations. 
 */

unsigned Add(unsigned a, unsigned b) {
	unsigned tmpa = a, tmpb = b, k = 1, c = 0, res = 0;
	while (tmpa || tmpb) {
		unsigned ak = a & k, bk = b & k;
		unsigned tmpc = (ak & bk) | (ak & c) | (bk & c);
		res |= ak ^ bk ^ c;
		c = tmpc << 1;  k <<= 1; tmpa >>= 1; tmpb >>= 1;
	}
	return (res | c);
}

unsigned Multiply(unsigned x, unsigned y) {
	unsigned res = 0; 
	while (x) {
		if (x & 1) {
			res = Add(res, y); 
		}
		x >>= 1; y <<= 1; 
	}
	return res; 
}

void test_multiply() {
	for (unsigned i = 0; i != 10; ++i) {
		for (unsigned j = i; j != 10; ++j) {
			cout << i << " * " << j << " = " << Multiply(i, j) << endl; 
		}
	}
}