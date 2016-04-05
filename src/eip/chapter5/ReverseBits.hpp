#ifndef SRC_EIP_CHAPTER5_REVERSEBITS_HPP_
#define SRC_EIP_CHAPTER5_REVERSEBITS_HPP_

#include <unordered_map>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace eip {
namespace chapter5 {

class ReverseBits : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    ReverseBits():
        Solution("Chapter 5.3",
                 "Reverse all bits",
                 "Reverse bits from LSB to MSB.") { }

    bool test();

    ~ReverseBits() { }

    long reverseBitsBruteForce(long x, int length);
    long reverseBits(long x);

private:
    std::unordered_map<long, long> precomputedReverse_;

    void swapTwoBits(long &x, int i, int j);
    void computeReverseTable(int length);
};

} // chapter5
} // eip

#endif /* SRC_EIP_CHAPTER5_REVERSEBITS_HPP_ */
