/*
#include <iostream>
using namespace std; 

namespace chapter5 {
    /* EPI Chapter 5.2
     * Swap bits at i and j. LSB as 0, and MSB as 31.
     *
    long SwapBits(long x, int i, int j) {
        if (((x >> i) & 1) != ((x >> j) & 1)) {
            unsigned long bit_mask = (1L << i) | (1L << j);
            x ^= bit_mask;
        }

        return x;
    }

    void test_swap_bits() {
        cout << "16 swap 1 and 4: " << SwapBits(16, 1, 4) << endl;
        cout << "16 swap 1 and 3: " << SwapBits(16, 1, 3) << endl;
    }
}
*/
