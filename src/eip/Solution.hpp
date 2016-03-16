#include <string>

#ifndef SRC_EIP_SOLUTION_HPP_
#define SRC_EIP_SOLUTION_HPP_

namespace eip {

class Solution {
protected:
    Solution(std::string questionSource, std::string questionDescription):
        questionSource_(questionSource),
        questionDescription_(questionDescription) { }

    virtual bool test();

    virtual ~Solution() { }

    std::string questionSource_;
    std::string questionDescription_;
};

} // eip

#endif /* SRC_EIP_SOLUTION_HPP_ */
