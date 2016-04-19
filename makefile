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
