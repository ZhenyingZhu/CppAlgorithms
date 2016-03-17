#ifndef SRC_CHAPTER5_PARITY_HPP_
#define SRC_CHAPTER5_PARITY_HPP_

namespace eip {
namespace chapter5 {

class Parity : public Solution {
public:
    Parity() {
        Solution("EPI Chapter 5.1",
                "If there are odd 1 in the number," +
                " return 1, else return 0."
                );
    }
    bool test();
private:
    short parityBruteForce(unsigned long);
    short parityEliminateLastOne(unsigned long);
    short parity(unsigned long);
};

} // chapter5
} // eip

#endif /* SRC_CHAPTER5_PARITY_HPP_ */
