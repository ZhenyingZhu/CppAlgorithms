/*
#include <iostream>
#include <cmath>
#include <climits>

using namespace std; 

namespace chapter5 {
    /* EPI Chapter 5.8
     * Reverse digits of an integer. Leave sign unchanged.
     *

    long long Reverse(int x) {
        bool is_negative = x < 0;
        long long res = 0, x_remaining = abs(x);

        while (x_remaining) {
            res = res * 10 + x_remaining % 10;
            x_remaining /= 10;
        }

        return is_negative ? -res : res;
    }

    void test_reverse() {
        cout << "Reverse -123: " << Reverse(-123) << endl;
        cout << "Reverse " << INT_MAX << ": " << Reverse(INT_MAX) << endl;
    }
}
*/
