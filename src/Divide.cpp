#include <iostream>

using namespace std; 

/* EPI Chapter 5.6
 * Compute x / y with addition, substraction or/and shifting. 
 */

unsigned Divide(unsigned x, unsigned y) {
	unsigned res = 0; 
	int power = 32; 
	unsigned long long y_power = static_cast<unsigned long long>(y) << power; 

	while (x >= y) {
		while (y_power > x) {
			y_power >>= 1; 
			--power; 
		}

		res += 1U << power; 
		x -= y_power; 
	}

	return res; 
}

void test_divide() {
	for (int i = 1; i != 10; i += 3) {
		cout << "Divide " << i << " / 3 = " << Divide(i, 3) << endl; 
	}

	for (int i = 0; i != 16; i += 4) {
		cout << "Divide " << i << " / 4 = " << Divide(i, 4) << endl;
	}
}