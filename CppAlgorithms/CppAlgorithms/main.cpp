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
// Chapter 5.6
void test_divide(); 
// Chapter 5.7
void test_power(); 
// Chapter 5.8
void test_reverse(); 
// Chapter 5.9
void test_is_palindrome(); 

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
	cout << "Multiply without arithmetical operators: " << endl; 
	test_multiply(); 
	cout << "Divide x / y: " << endl; 
	test_divide(); 
	cout << "Power x ^ y: " << endl; 
	test_power(); 
	cout << "Reverse x: " << endl;
	test_reverse(); 
	*/
	cout << "Check if x is Palindrome: " << endl;
	test_is_palindrome(); 

	return 0;
}