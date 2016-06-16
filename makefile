CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall -std=c++11 $(DEBUG)

SOURCES =			\
	src/SolutionCollection.cpp			\
	src/SmartPtr.cpp			\
	src/MyUtils.cpp			\
	src/cppprimer/StringOperations.cpp			\
	src/cppprimer/CollectionErase.cpp			\
	src/cppprimer/TestQuery.cpp			\
	src/cppprimer/BulkItem.cpp			\
	src/cppprimer/HelloWorld.cpp			\
	src/cppprimer/MapOperations.cpp			\
	src/cppprimer/TestWordQuery.cpp			\
	src/cppprimer/QueueOperations.cpp			\
	src/cppprimer/AndQuery.cpp			\
	src/cppprimer/TextQuery.cpp			\
	src/cppprimer/NotQuery.cpp			\
	src/cppprimer/Query.cpp			\
	src/cppprimer/OrQuery.cpp			\
	src/cppprimer/WordsTransform.cpp			\
	src/epi/chapter5/Reverse.cpp			\
	src/epi/chapter5/SwapBits.cpp			\
	src/epi/chapter5/Divide.cpp			\
	src/epi/chapter5/Multiply.cpp			\
	src/epi/chapter5/IsPalindrome.cpp			\
	src/epi/chapter5/IntersectRectangle.cpp			\
	src/epi/chapter5/Power.cpp			\
	src/epi/chapter5/Parity.cpp			\
	src/epi/chapter5/ClosestIntSameBitCount.cpp			\
	src/epi/chapter5/ReverseBits.cpp			\
	src/epi/chapter5/UniformRandom.cpp			\
	src/epi/chapter6/DutchFlagPartition.cpp			\
	src/epi/chapter6/PlusOne.cpp			\
	src/epi/chapter6/Multiply.cpp			\
	src/epi/chapter6/CanReachEnd.cpp			\
	src/epi/chapter6/DeleteDuplicates.cpp			\
	src/epi/chapter6/BuyAndSellStockOnce.cpp			\
	src/epi/chapter6/BuyAndSellStockTwice.cpp			\
	src/epi/chapter6/GeneratePrimes.cpp			\
	src/epi/chapter6/ApplyPermutation.cpp			\
	src/epi/chapter6/NextPermutation.cpp			\
	src/epi/chapter6/RandomSampling.cpp			\
	src/epi/chapter6/OnlineRandomSample.cpp			\
	src/epi/chapter6/ComputeRandomPermutation.cpp			\
	src/epi/chapter6/RandomSubset.cpp			\
	src/epi/chapter6/NonuniformRandomNumberGeneration.cpp			\
	src/epi/chapter6/IsValidSudoku.cpp			\
	src/epi/chapter6/MatrixInSprialOrder.cpp			\
	src/epi/chapter6/RotateMatrix.cpp			\
	src/epi/chapter6/GeneratePascalTriangle.cpp			\
	src/epi/chapter7/InterconvertIntStr.cpp			\
	src/epi/chapter7/ConvertBase.cpp			\
	src/epi/chapter7/SSDecodeColID.cpp			\
	src/epi/chapter7/ReplaceAndRemove.cpp			\
	src/epi/chapter7/IsPalindrome.cpp			\
	src/epi/chapter7/ReverseWords.cpp			\
	src/epi/chapter7/PhoneMnemonic.cpp			\
	src/epi/chapter7/LookAndSay.cpp			\
	src/epi/chapter7/RomanToInteger.cpp			\
	src/epi/chapter7/GetValidIPAddress.cpp			\
	src/epi/chapter7/SnakeString.cpp			\
	src/epi/chapter7/RLE.cpp			\
	src/epi/chapter7/RabinKarp.cpp			\
	src/epi/chapter8/MergeTwoSortedLists.cpp			\
	src/epi/chapter8/ReverseSublist.cpp			\
	src/epi/chapter8/HasCycle.cpp			\
	src/epi/chapter8/OverlappingNoCycleLists.cpp			\
	src/epi/chapter8/OverlappingLists.cpp			\
	src/epi/chapter8/DeletionFromList.cpp			\
	src/epi/chapter8/RemoveKthLast.cpp			\
	src/epi/chapter8/RemoveDuplicates.cpp			\
	src/epi/chapter8/CyclicallyRightShiftList.cpp			\
	src/epi/chapter8/EvenOddMerge.cpp			\
	src/epi/chapter8/IsLinkedListAPalindrome.cpp			\
	src/epi/chapter8/ListPivoting.cpp			\
	src/epi/chapter8/AddTwoNumbers.cpp			\
	src/epi/chapter9/MaxStack.cpp			\
	src/epi/chapter9/Eval.cpp			\
	src/epi/chapter9/IsWellFormed.cpp			\
	src/epi/chapter9/ShortestEquivalentPath.cpp			\
	src/epi/chapter9/SetJumpOrder.cpp			\
	src/epi/chapter9/ExamineBuildingsWithSunset.cpp			\
	src/epi/chapter9/BinaryTreeDepthOrder.cpp			\
	src/epi/chapter9/CircularQueue.cpp			\
	src/epi/chapter9/StackQueue.cpp			\
	src/epi/chapter9/QueueWithMax.cpp			\
	src/epi/chapter10/IsBalanced.cpp			\
	src/epi/chapter10/IsSymmetric.cpp			\
	src/epi/chapter10/LCA.cpp			\
	src/epi/chapter10/LCAWithParent.cpp			\
	src/epi/chapter10/SumRootToLeaf.cpp			\
	src/epi/chapter10/HasPathSum.cpp			\
	src/epi/chapter10/BSTInSortedOrder.cpp			\
	src/epi/chapter10/PreorderTraversal.cpp			\
	src/epi/chapter10/FindKthNodeBinaryTree.cpp			\
	src/epi/chapter10/FindSuccessor.cpp			\
	src/epi/chapter10/InorderTraversal.cpp			\
	src/epi/chapter10/BinaryTreeFromPreorderInorder.cpp			\
	src/epi/chapter10/ReconstructPreorder.cpp			\
	src/epi/chapter10/CreateListOfLeaves.cpp			\
	src/epi/chapter10/ExteriorBinaryTree.cpp			\
	src/epi/chapter10/ConstructRightSibling.cpp			\
	src/epi/chapter10/BinaryTreeLocking.cpp			\
	src/epi/chapter11/TopK.cpp			\
	src/epi/chapter11/MergeSortedArrays.cpp			\
	src/epi/chapter11/SortKIncreasingDecreasingArray.cpp			\
	src/epi/chapter11/SortApproximatelySortedData.cpp			\
	src/epi/chapter11/FindClosestKStars.cpp			\
	src/epi/chapter11/OnlineMedian.cpp			\
	src/epi/chapter11/KLargestInBinaryHeap.cpp			\
	src/epi/chapter11/StackByHeap.cpp			\
	src/epi/chapter12/SearchFirstOfK.cpp			\
	src/epi/chapter12/SearchEntryEqualToItsIndex.cpp			\
	src/epi/chapter12/SearchSmallest.cpp			\
	src/main.cpp

SOURCES_MAIN = src/main.cpp

OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_MAIN = $(SOURCES_MAIN:.cpp=.o)

EXECUTABLES = cppalgorithms

.PHONY: all
all: $(EXECUTABLES)

cppalgorithms: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLES)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OBJECTS_MAIN) $(EXECUTABLES)
