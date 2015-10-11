#include <iostream>
#include <cmath>

using namespace std; 

/* EPI Chapter 5.9
 * Check if a decimal interger is palindrome. 
 * Negative integer cannot be palindrome. 
 */

bool IsPalindrome(int x) {
	if (x < 0) 
		return false; 
	if (x == 0)
		return true; 

	const int kNumDigits = static_cast<int>(floor(log10(x))) + 1; 
	int msd_mask = static_cast<int>(pow(10, kNumDigits - 1)); 
	for (int i = 0; i != kNumDigits / 2; ++i) {
		if (x / msd_mask != x % 10) 
			return false; 
		else {
			x %= msd_mask; 
			msd_mask /= 100; 
			x /= 10; 
		}
	}

	return true; 
}

void test_is_palindrome() {
	const size_t arr_size = 4; 
	int arr[arr_size] = { 214747412, 12, -111, 1 };
	for (size_t ix = 0; ix != arr_size; ++ix)
		cout << arr[ix] << " is " << (IsPalindrome(arr[ix]) ? "" : "not ") << "palindrome. " << endl;
}