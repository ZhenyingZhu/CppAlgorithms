#include <iostream>
#include <string>

#ifndef SRC_EIP_SOLUTION_HPP_
#define SRC_EIP_SOLUTION_HPP_

namespace eip {

class Solution {
    /* Abstract class
     * Use a string to state the source, and a string to state a description.
     * test() runs testcases and return true or false to indicate pass or fail.
     */
public:
    virtual bool test();
    void getSource() {
        std::cout << questionSource_ << std::endl;
    }
    void getDescription() {
        std::cout << questionDescription_ << std::endl;
    }

protected:
    Solution(std::string questionSource, std::string questionDescription):
        questionSource_(questionSource),
        questionDescription_(questionDescription) { }

    virtual ~Solution() { }

    std::string questionSource_;
    std::string questionDescription_;
};

} // eip

#endif /* SRC_EIP_SOLUTION_HPP_ */
