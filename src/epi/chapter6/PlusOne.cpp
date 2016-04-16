#include "PlusOne.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector; 
using std::cout; 
using std::endl; 

using myutils::print_vec;

namespace epi {
namespace chapter6 {
    vector<int> PlusOne::plusOne(vector<int> A) {
        ++A.back();
        for (vector<int>::iterator iter = --A.end(); iter != A.begin() && *iter == 10; --iter) {
            *iter = 0;
            ++*(iter - 1);
        }

        if (*A.begin() == 10) {
            *A.begin() = 0;
            A.insert(A.begin(), 1);
        }

        return A;
    }

    void print_vec(vector<int> A) {
        for (vector<int>::const_iterator iter = A.begin(); iter != A.end(); ++iter) {
            cout << *iter;
        }
    }

    bool PlusOne::test() {
        vector<int> input;
        input.push_back(9); input.push_back(9); input.push_back(9);
        cout << "Increase ";
        print_vec(input);
        cout << " by one is ";
        print_vec(plusOne(input));
        cout << endl;

        return true;
    }

} // chapter6
} // epi
