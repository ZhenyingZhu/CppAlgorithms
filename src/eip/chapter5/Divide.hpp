#ifndef SRC_EIP_CHAPTER5_DIVIDE_HPP_
#define SRC_EIP_CHAPTER5_DIVIDE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace eip {
namespace chapter5 {

class Divide : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Divide():
        Solution("Chapter 5.6",
                 "Divide",
                 "Divide x and y using only addition,"
                 " subtraction, and shifting.") { }

    bool test();

    ~Divide() { }

    unsigned divide(unsigned, unsigned);

};

} // chapter5
} // eip

#endif /* SRC_EIP_CHAPTER5_DIVIDE_HPP_ */
