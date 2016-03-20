#ifndef SRC_EIP_SOLUTION_HPP_
#define SRC_EIP_SOLUTION_HPP_

#include <string>

class SmartPtr;

class Solution {
    /* Abstract class
     * Use a string to state the source, and a string to state a description.
     * test() runs testcases and return true or false to indicate pass or fail.
     */

    friend class SmartPtr;

protected:
    Solution(std::string questionSource, std::string questionDescription):
        questionSource_(questionSource),
        questionDescription_(questionDescription) { }

    virtual ~Solution() { }

    inline std::string getSource() const {
        return questionSource_;
    }

    inline std::string getDescription() const {
        return questionDescription_;
    }

    std::string questionSource_;
    std::string questionDescription_;

private:
    virtual bool test() const = 0; // verify solution is right
};

#endif /* SRC_EIP_SOLUTION_HPP_ */
