/*
 * ClosestIntSameBitCount.hpp
 *
 *  Created on: Mar 31, 2016
 *      Author: zhu91
 */

#ifndef SRC_EIP_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_
#define SRC_EIP_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

namespace eip {
namespace chapter5 {

class ClosestIntSameBitCount : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    ClosestIntSameBitCount():
        Solution("EPI Chapter 5.4",
                "Closest integer that has same 1 bits",
                "Find the closest integer that has same "
                "weight as the given number. Weight "
                "is count as number of set bits.") { }

    bool test();

    ~ClosestIntSameBitCount() { }

    unsigned long closestIntSameBitCount(unsigned long x);

};

} // chapter5
} // eip

#endif /* SRC_EIP_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_ */
