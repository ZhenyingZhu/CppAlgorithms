#include <iostream>
#include <stdexcept>

#include "ClosestIntSameBitCount.hpp"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

using std::invalid_argument;

namespace eip {
namespace chapter5 {
    unsigned long ClosestIntSameBitCount::closestIntSameBitCount(unsigned long x) {
        for (int i = 0; i != 31; ++i) {
            if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
                unsigned long bit_mask = (1UL << i) | (1UL << (i + 1));
                return x ^= bit_mask;
            }
        }

        throw invalid_argument("All bits are 0 or 1.");
    }

    bool ClosestIntSameBitCount::test() {
        std::cout << "11: " << closestIntSameBitCount(11) << std::endl;
        std::cout << "8: " << closestIntSameBitCount(8) << std::endl;
        //std::cout << "0: " << closestIntSameBitCount(0) << std::endl;
        return true;
    }

} // chapter5
} // eip
