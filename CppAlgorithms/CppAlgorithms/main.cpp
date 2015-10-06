#include <iostream>

using std::cout; 
using std::endl; 

// Chapter 5.1
void test_parity(); 
// Chapter 5.2
void test_swap_bits(); 
// Chapter 5.4
void test_cloest_int_same_bit_count(); 
// Chapter 5.5
void test_multiply(); 

int main()
{
	cout << "Chapter 5" << endl; 
	/*
	cout << "Compute Parity: " << endl;
	test_parity(); 
	cout << "Swap Bits: " << endl; 
	test_swap_bits(); 
	cout << "Cloest Int Same Bit Count: " << endl; 
	test_cloest_int_same_bit_count(); 
	*/
	cout << "Multiply without arithmetical operators: " << endl; 
	test_multiply(); 
	return 0; 
}