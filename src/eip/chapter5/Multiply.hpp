#ifndef SRC_EIP_CHAPTER5_MULTIPLY_HPP_
#define SRC_EIP_CHAPTER5_MULTIPLY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace eip {
namespace chapter5 {

class Multiply : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Multiply():
        Solution("Chapter 5.5",
                 "Multiply",
                 "Multiply x and y without"
                 " arithmetical operations.") { }

    bool test();

    ~Multiply() { }

    unsigned multiply(unsigned, unsigned);

private:
    unsigned add(unsigned, unsigned);
};

} // chapter5
} // eip

#endif /* SRC_EIP_CHAPTER5_MULTIPLY_HPP_ */
