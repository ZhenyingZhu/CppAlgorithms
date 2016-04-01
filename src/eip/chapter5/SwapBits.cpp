#include "SwapBits.hpp"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

namespace eip {
namespace chapter5 {
    long SwapBits::swapBits(long x, int i, int j) {
        if (((x >> i) & 1) != ((x >> j) & 1)) {
            unsigned long bit_mask = (1L << i) | (1L << j);
            x ^= bit_mask;
        }

        return x;
    }

    bool SwapBits::test() {
        if (swapBits(16, 1, 4) == 2 &&
                swapBits(16, 1, 3) == 16)
            return true;

        return false;
    }
} // chapter5
} // eip
