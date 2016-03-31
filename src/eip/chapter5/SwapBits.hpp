/*
 * SwapBits.hpp
 *
 *  Created on: Mar 30, 2016
 *      Author: zhu91
 */

#ifndef SRC_EIP_CHAPTER5_SWAPBITS_HPP_
#define SRC_EIP_CHAPTER5_SWAPBITS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

namespace eip {
namespace chapter5 {

class SwapBits : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    SwapBits():
        Solution("EPI Chapter 5.2",
                "Swap Bits",
                "Swap bits at i and j. "
                "LSB as 0, and MSB as 31.") { }

    bool test();

    ~SwapBits() { }

    long swapBits(long x, int i, int j);

};

} // chapter5
} // eip

#endif /* SRC_EIP_CHAPTER5_SWAPBITS_HPP_ */
