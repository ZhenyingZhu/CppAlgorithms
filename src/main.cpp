#include <iostream>
#include "SolutionCollection.h"
#include "Solution.h"
#include "SmartPtr.h"
#include "cppprimer/cppprimer.h"
#include "epi/chapter5/SwapBits.hpp"
#include "epi/chapter5/ClosestIntSameBitCount.hpp"
#include "epi/chapter5/ReverseBits.hpp"
#include "epi/chapter5/Multiply.hpp"
#include "epi/chapter5/Divide.hpp"
#include "epi/chapter5/Parity.hpp"
#include "epi/chapter5/Power.hpp"
#include "epi/chapter5/Reverse.hpp"
#include "epi/chapter5/IsPalindrome.hpp"
#include "epi/chapter5/UniformRandom.hpp"
#include "epi/chapter5/IntersectRectangle.hpp"
#include "epi/chapter6/DutchFlagPartition.hpp"
#include "epi/chapter6/PlusOne.hpp"

using std::cout;
using std::endl;

using namespace myutils;
using namespace cppprimer;
using namespace epi;
using namespace chapter5;
using namespace chapter6;

void prepareSolutions() {
    new Parity(); // Chapter 5.1
    new SwapBits(); // Chapter 5.2
    new ReverseBits(); // Chapter 5.3
    new ClosestIntSameBitCount(); // Chapter 5.4
    new Multiply(); // Chapter 5.5
    new Divide(); // Chapter 5.6
    new Power(); // Chapter 5.7
    new Reverse(); // Chapter 5.8
    new IsPalindrome(); // Chapter 5.9
    new UniformRandom(); // Chapter 5.10
    new IntersectRectangle(); // Chapter 5.11

    new DutchFlagPartition(); // Chapter 6.1
    new PlusOne(); // Chapter 6.2
    //// Chapter 6.3
    //void test_multiply_array();
    //// Chapter 6.4
    //void test_can_reach_end();

    /*
    cout << "Multiply two arbitary precision integers: " << endl;
    test_multiply_array();
    cout << "Advancing through an array: " << endl;
    test_can_reach_end();
    */
}

int main(int argc, char** argv)
{
    prepareSolutions();
    SolutionCollection::getInstance()->checkSolutions();

    cout << "**********\n" << "All done." << endl;
    return 0;
}
