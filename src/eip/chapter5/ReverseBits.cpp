#include "ReverseBits.hpp"

#include <iostream>
#include <climits>

#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"
#include "SwapBits.hpp"

namespace eip {
namespace chapter5 {
    void ReverseBits::swapTwoBits(long &x, int i, int j) {
        // This solution comes from chapter 5.2
        if ( (x >> i & 0x1) == (x >> j & 0x1) )
            return;

        long bitMask = (1U << i | 1U << j);
        x ^= bitMask;
    }

    long ReverseBits::reverseBitsBruteForce(long x) {
        int size = sizeof(x) * CHAR_BIT / 8; // shorten it to 8 bits

        for (auto i = 0; i != size / 2; ++i)
            swapTwoBits(x, i, size - 1 - i);

        return x;
    }

    long ReverseBits::reverseBits(long x) {
        return x;
    }

    bool ReverseBits::test() {
        std::cout << reverseBits(1) << std::endl;

        return true;
    }
} // chapter5
} // eip
