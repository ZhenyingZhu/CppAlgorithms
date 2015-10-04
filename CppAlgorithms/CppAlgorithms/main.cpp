#include <iostream>

using std::cout; 
using std::endl; 

// Chapter 5.1
void test_parity(); 
// Chapter 5.2
void test_swap_bits(); 

int main()
{
	cout << "Chapter 5" << endl; 
	/*
	cout << "Compute Parity: " << endl;
	test_parity(); 
	*/
	cout << "Swap Bits: " << endl; 
	test_swap_bits(); 

	return 0; 
}