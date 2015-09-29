#include <iostream>
using namespace std; 

/* EPI Chapter 5.1. 
 * If there are odd 1 in the number, return 1, 
 * Else return 0. 
 */
short ParityBruteForce(unsigned long x) {
	short res = 0; 
	while (x) {
		res += x & 1; 
		x >>= 1; 
	}

	return res % 2; 
}

short Parity(unsigned long x) {
	short res = 0; 
	while (x) {
		res ^= 1; 
		x &= x - 1; 
	}

	return res; 
}

int test_parity() {
	cout << "5: " << Parity(5) << endl;
	cout << "7: " << Parity(7) << endl;

	return 0; 
}