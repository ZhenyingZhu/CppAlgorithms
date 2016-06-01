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
#include "epi/chapter6/Multiply.hpp"
#include "epi/chapter6/CanReachEnd.hpp"
#include "epi/chapter6/DeleteDuplicates.hpp"
#include "epi/chapter6/BuyAndSellStockOnce.hpp"
#include "epi/chapter6/BuyAndSellStockTwice.hpp"
#include "epi/chapter6/GeneratePrimes.hpp"
#include "epi/chapter6/ApplyPermutation.hpp"
#include "epi/chapter6/NextPermutation.hpp"
#include "epi/chapter6/RandomSampling.hpp"
#include "epi/chapter6/OnlineRandomSample.hpp"
#include "epi/chapter6/ComputeRandomPermutation.hpp"
#include "epi/chapter6/RandomSubset.hpp"
#include "epi/chapter6/NonuniformRandomNumberGeneration.hpp"
#include "epi/chapter6/IsValidSudoku.hpp"
#include "epi/chapter6/MatrixInSprialOrder.hpp"
#include "epi/chapter6/RotateMatrix.hpp"
#include "epi/chapter6/GeneratePascalTriangle.hpp"
#include "epi/chapter7/InterconvertIntStr.hpp"
#include "epi/chapter7/ConvertBase.hpp"
#include "epi/chapter7/SSDecodeColID.hpp"
#include "epi/chapter7/ReplaceAndRemove.hpp"
#include "epi/chapter7/IsPalindrome.hpp"
#include "epi/chapter7/ReverseWords.hpp"
#include "epi/chapter7/PhoneMnemonic.hpp"
#include "epi/chapter7/LookAndSay.hpp"
#include "epi/chapter7/RomanToInteger.hpp"
#include "epi/chapter7/GetValidIPAddress.hpp"
#include "epi/chapter7/SnakeString.hpp"
#include "epi/chapter7/RLE.hpp"
#include "epi/chapter7/RabinKarp.hpp"
#include "epi/chapter8/MergeTwoSortedLists.hpp"
#include "epi/chapter8/ReverseSublist.hpp"
#include "epi/chapter8/HasCycle.hpp"
#include "epi/chapter8/OverlappingNoCycleLists.hpp"
#include "epi/chapter8/OverlappingLists.hpp"
#include "epi/chapter8/DeletionFromList.hpp"
#include "epi/chapter8/RemoveKthLast.hpp"
#include "epi/chapter8/RemoveDuplicates.hpp"
#include "epi/chapter8/CyclicallyRightShiftList.hpp"
#include "epi/chapter8/EvenOddMerge.hpp"
#include "epi/chapter8/IsLinkedListAPalindrome.hpp"
#include "epi/chapter8/ListPivoting.hpp"
#include "epi/chapter8/AddTwoNumbers.hpp"
#include "epi/chapter9/MaxStack.hpp"
#include "epi/chapter9/Eval.hpp"
#include "epi/chapter9/IsWellFormed.hpp"
#include "epi/chapter9/ShortestEquivalentPath.hpp"
#include "epi/chapter9/SetJumpOrder.hpp"
#include "epi/chapter9/ExamineBuildingsWithSunset.hpp"
#include "epi/chapter9/BinaryTreeDepthOrder.hpp"
#include "epi/chapter9/CircularQueue.hpp"
#include "epi/chapter9/StackQueue.hpp"
#include "epi/chapter9/QueueWithMax.hpp"
#include "epi/chapter10/IsBalanced.hpp"
#include "epi/chapter10/IsSymmetric.hpp"
#include "epi/chapter10/LCA.hpp"

using std::cout;
using std::endl;

using namespace myutils;
using namespace cppprimer;
using namespace epi;
using namespace chapter5;
using namespace chapter6;
using namespace chapter7;
using namespace chapter8;
using namespace chapter9;
using namespace chapter10;

void prepareSolutions() {
//    new Parity(); // Chapter 5.1
//    new SwapBits(); // Chapter 5.2
//    new ReverseBits(); // Chapter 5.3
//    new ClosestIntSameBitCount(); // Chapter 5.4
//    new epi::chapter5::Multiply(); // Chapter 5.5
//    new Divide(); // Chapter 5.6
//    new Power(); // Chapter 5.7
//    new Reverse(); // Chapter 5.8
//    new IsPalindrome(); // Chapter 5.9
//    new UniformRandom(); // Chapter 5.10
//    new IntersectRectangle(); // Chapter 5.11
//
//    new DutchFlagPartition(); // Chapter 6.1
//    new PlusOne(); // Chapter 6.2
//    new epi::chapter6::Multiply(); // Chapter 6.3
//    new CanReachEnd(); // Chapter 6.4
//    new DeleteDuplicates(); // Chapter 6.5
//    new BuyAndSellStockOnce(); // Chapter 6.6
//    new BuyAndSellStockTwice(); // Chapter 6.7
//    new GeneratePrimes(); // Chapter 6.8
//    new ApplyPermutation(); // Chapter 6.9
//    new NextPermutation(); // Chapter 6.10
//    new RandomSampling(); // Chapter 6.11
//    new OnlineRandomSample(); // Chapter 6.12
//    new ComputeRandomPermutation(); // Chapter 6.13
//    new RandomSubset(); // Chapter 6.14
//    new NonuniformRandomNumberGeneration(); // Chapter 6.15
//    new IsValidSudoku(); // Chapter 6.16
//    new MatrixInSprialOrder(); // Chapter 6.17
//    new RotateMatrix(); // Chapter 6.18
//    new GeneratePascalTriangle(); // Chapter 6.19
//
//    new InterconvertIntStr(); // Chapter 7.1
//    new ConvertBase(); // Chapter 7.2
//    new SSDecodeColID(); // Chapter 7.3
//    new ReplaceAndRemove(); // Chapter 7.4
//    new epi::chapter7::IsPalindrome(); // Chapter 7.5
//    new ReverseWords(); // Chapter 7.6
//    new PhoneMnemonic(); // Chapter 7.7
//    new LookAndSay(); // Chapter 7.8
//    new RomanToInteger(); // Chapter 7.9
//    new GetValidIPAddress(); // Chapter 7.10
//    new SnakeString(); // Chapter 7.11
//    new RLE(); // Chapter 7.12
//    new RabinKarp(); // Chapter 7.13
//
//    new MergeTwoSortedLists(); // Chapter 8.1
//    new ReverseSublist(); // Chapter 8.2
//    new HasCycle(); // Chapter 8.3
//    new OverlappingNoCycleLists(); // Chapter 8.4
//    new OverlappingLists(); // Chapter 8.5
//    new DeletionFromList(); // Chapter 8.6
//    new RemoveKthLast(); // Chapter 8.7
//    new RemoveDuplicates(); // Chapter 8.8
//    new CyclicallyRightShiftList(); // Chapter 8.9
//    new EvenOddMerge(); // Chapter 8.10
//    new IsLinkedListAPalindrome(); // Chapter 8.11
//    new ListPivoting(); // Chapter 8.12
//    new AddTwoNumbers(); // Chapter 8.13
//
//    new MaxStack(); // Chapter 9.1
//    new Eval(); // Chapter 9.2
//    new IsWellFormed(); // Chapter 9.3
//    new ShortestEquivalentPath(); // Chapter 9.4
//    new SetJumpOrder(); // Chapter 9.5
//    new ExamineBuildingsWithSunset(); // Chapter 9.6
//    new BinaryTreeDepthOrder(); // Chapter 9.7
//    new CircularQueue(); // Chapter 9.8
//    new StackQueue(); // Chapter 9.9
//    new QueueWithMax(); // Chapter 9.10
//
    new IsBalanced(); // Chapter 10.1
    new IsSymmetric(); // Chapter 10.2
    new LCA(); // Chapter 10.3

}

int main(int argc, char** argv)
{
    prepareSolutions();
    SolutionCollection::getInstance()->checkSolutions();

    cout << "**********\n" << "All done." << endl;
    return 0;
}
