#ifndef SRC_CHAPTER5_PARITY_HPP_
#define SRC_CHAPTER5_PARITY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace eip {
namespace chapter5 {

class Parity : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Parity():
        Solution("EPI Chapter 5.1",
                "Compute Parity",
                "If there are odd 1 in the number, "
                "return 1, else return 0.") { }

    bool test() const;

    ~Parity() { }

private:
    short parityBruteForce(unsigned long) const;
    short parityEliminateLastOne(unsigned long) const;
    short parity(unsigned long) const;
};

} // chapter5
} // eip

#endif /* SRC_CHAPTER5_PARITY_HPP_ */
