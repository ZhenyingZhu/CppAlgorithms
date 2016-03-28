#ifndef SRC_EIP_SOLUTION_HPP_
#define SRC_EIP_SOLUTION_HPP_

#include <string>

namespace myutils {

class SmartPtr;

class Solution {
    /* Abstract class
     * Use a string to state the source, and a string to state a description.
     * test() runs testcases and return true or false to indicate pass or fail.
     */

    friend class SmartPtr;

public:
    virtual bool test() = 0; // verify solution is right

protected:
    Solution(std::string questionSource,
            std::string questionTitle_,
            std::string questionDescription):
        questionSource_(questionSource),
        questionTitle_(questionTitle_),
        questionDescription_(questionDescription) { }

    virtual ~Solution() { }

    inline std::string getSource() const {
        return questionSource_;
    }

    inline std::string getTitle() const {
        return questionTitle_;
    }

    inline std::string getDescription() const {
        return questionDescription_;
    }

    std::string questionSource_;
    std::string questionTitle_;
    std::string questionDescription_;
};

} // myutils

#endif /* SRC_EIP_SOLUTION_HPP_ */
