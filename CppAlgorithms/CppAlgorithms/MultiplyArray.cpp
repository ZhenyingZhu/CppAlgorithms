#include <vector>
#include <iostream>

using std::vector; 
using std::cout; 
using std::endl; 


/* Chapter 6.3
 * Multiple two arbitary-precision array presented integers
 */

// PlusOne
void print_vec(vector<int> A); 

vector<int> Multiply(vector<int> num1, vector<int> num2) {
	bool is_negative = (num1.front() < 0 && num2.front() >= 0) || (num1.front() >= 0 && num2.front() < 0); 
	num1.front() = abs(num1.front()), num2.front() = abs(num2.front()); 
	reverse(num1.begin(), num1.end()); 
	reverse(num2.begin(), num2.end()); 

	vector<int> res(num1.size() + num2.size(), 0); 
	for (vector<int>::size_type i = 0; i != num1.size(); ++i) {
		for (vector<int>::size_type j = 0; j != num2.size(); ++j) {
			res[i + j] += num1[i] * num2[j]; 
			res[i + j + 1] += res[i + j] / 10; 
			res[i + j] %= 10; 
		}
	}

	while (res.size() != 1 && res.back() == 0)
		res.pop_back(); 
	reverse(res.begin(), res.end()); 
	if (is_negative)
		res.front() *= -1; 
	return res; 
}

void test_multiply_array() {
	vector<int> num1 = { 9, 9, 9 };
	vector<int> num2 = { -9, 9 }; 
	print_vec(num1); 
	cout << " * "; 
	print_vec(num2); 
	cout << " = "; 
	print_vec(Multiply(num1, num2)); 
	cout << endl; 
}

