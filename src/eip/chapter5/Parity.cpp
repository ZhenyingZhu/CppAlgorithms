#include <iostream>
#include <climits>

#include "Parity.hpp"

using namespace std; 

namespace eip {
  namespace chapter5 {

    short Parity::parityBruteForce(unsigned long x) {
        short res = 0;
        while (x) {
            res += x & 1;
            x >>= 1;
        }

        return res % 2;
    }

    short Parity::parityEliminateLastOne(unsigned long x) {
        short res = 0;
        while (x) {
            res ^= 1;
            x &= x - 1;
        }

        return res;
    }

    short Parity::parity(unsigned long x) {
    /* idea: parity of x = parity(first half of x XOR last half of x)
     * unsigned long here is 32 bits, which is same as int.
     * sizeof(long) = sizeof(int) = 4 * sizeof(char)
     * So that if shift 32 at the first time,
     * (x >> 32) == x cause (x ^= x) == 0
     */
        for (size_t i = sizeof(x) * CHAR_BIT / 2; i != 0; i /= 2) {
            x ^= (x >> i);
        }
        return x & 0x1;
    }

    bool Parity::test() {
        cout << "5: " << parity(5) << endl;
        cout << "7: " << parity(7) << endl;

        return true;
    }
  }
}
