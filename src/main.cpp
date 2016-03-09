#include <iostream>
#include "cppprimer/cppprimer.h"
#include "eip/chapter5/Parity.hpp"

using std::cout;
using std::endl;

using namespace cppprimer;
using namespace eip;
using namespace chapter5;

//// Chapter 5.2
//void test_swap_bits();
//// Chapter 5.4
//void test_cloest_int_same_bit_count();
//// Chapter 5.5
//void test_multiply();
//// Chapter 5.6
//void test_divide();
//// Chapter 5.7
//void test_power();
//// Chapter 5.8
//void test_reverse();
//// Chapter 5.9
//void test_is_palindrome();
//// Chapter 5.11
//void test_intersect_rectangle();
//// Chapter 6.1
//void test_dutch_flag_partition();
//// Chapter 6.2
//void test_plus_one();
//// Chapter 6.3
//void test_multiply_array();
//// Chapter 6.4
//void test_can_reach_end();

int main(int argc, char** argv)
{
    cout << "Chapter 5.1" << endl;
    cout << "Compute Parity: " << endl;
    Parity().test_parity();
    /*
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
    cout << "Check if x is Palindrome: " << endl;
    test_is_palindrome();
    cout << "Find intersect of rectangles: " << endl;
    test_intersect_rectangle();
    cout << "Increment an arbitrary-precision integer: " << endl;
    test_plus_one();
    cout << "Dutch Flag Partition: " << endl;
    test_dutch_flag_partition();
    cout << "Multiply two arbitary precision integers: " << endl;
    test_multiply_array();
    cout << "Advancing through an array: " << endl;
    test_can_reach_end();
    */

    return 0;
}
