#include <iostream>

using namespace std; 

/* EPI Chapter 5.4
 * Find the cloest integer that has same weight as the given number. 
 * Weight is count as number of set bits. 
 */

unsigned long ClosestIntSameBitCount(unsigned long x) {
	for (int i = 0; i != 31; ++i) {
		if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
			unsigned long bit_mask = (1UL << i) | (1UL << (i + 1)); 
			return x ^= bit_mask; 
		}
	}

	throw invalid_argument("All bits are 0 or 1."); 
}

void test_cloest_int_same_bit_count() {
	cout << "11: " << ClosestIntSameBitCount(11) << endl; 
	cout << "8: " << ClosestIntSameBitCount(8) << endl;
	// cout << "0: " << ClosestIntSameBitCount(0) << endl;
}