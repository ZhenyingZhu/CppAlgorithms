#ifndef SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_
#define SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class FindSalaryCap : myutils::Solution {
    public:
        FindSalaryCap():
            Solution("EPI Chapter 14.9",
                     "Implement a fast sorting stable algorithm for lists",
                     "Merge sort: seperate the list into two halves, and then merge.") { }

        ~FindSalaryCap() { }

        double findSalaryCap(double targetPayroll, std::vector<double> currentSalaries);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_ */
