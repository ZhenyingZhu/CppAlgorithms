#include "NextPermutation.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::sort;
using myutils::vec_to_string;
using std::invalid_argument;

namespace epi {
  namespace chapter6 {
    bool NextPermutation::isOneOfPerm(int num, const vector<int> perm) {
        vector<int> cpy(perm);
        while (num) {
            vector<int>::iterator iter = find(cpy.begin(), cpy.end(), num % 10);
            if (iter == cpy.end())
                return false;

            cpy.erase(iter);
            num /= 10;
        }

        return true;
    }

    vector<int> NextPermutation::nextPermutationBruteForce(const vector<int> perm) {
        vector<int> res;

        if (perm.size() == 0)
            return res;

        int sum = 0;

        bool theLastPerm = true;
        for (size_t i = 0; i != perm.size(); ++i) {
            if (perm[i] >= 10 || perm[i] < 0)
                throw invalid_argument("Element not in 0 ~ 9");

            if (i != 0)
                if (perm[i] > perm[i - 1])
                    theLastPerm = false;

            sum = sum * 10 + perm[i];
        }

        if (theLastPerm)
            return res;

        while (true) {
            ++sum;
            if (isOneOfPerm(sum, perm)) {
                break;
            }
        }

        while(sum) {
            res.insert(res.begin(), sum % 10);
            sum /= 10;
        }
        return res;
    }

    vector<int> NextPermutation::nextPermutation(const vector<int> perm) {
        if (perm.size() == 0 || perm.size() == 1)
            return vector<int>();

        vector<int> res(perm);

        vector<int>::iterator iter = res.end() - 2;
        for (; iter >= res.begin(); --iter) {
            if ( *iter < *(iter + 1) )
                break;
        }

        if (iter < res.begin())
            return vector<int>();

        int last = *(res.end() - 1), pos = iter - res.begin();
        res.pop_back();
        sort(iter, res.end());
        res.insert(res.begin() + pos, last);
        return res;
    }

    bool NextPermutation::test() {
        vector<int> perm1 = {1, 0, 2, 3};
        vector<int> perm2 = {1, 0, 3, 2};
        vector<int> perm3 = {0, 3, 2, 1};
        vector<int> perm4 = {3, 2, 1, 0};
        vector<vector<int>> perms = {perm1, perm2, perm3, perm4};

        for (vector<int> perm : perms) {
            if (nextPermutationBruteForce(perm) != nextPermutation(perm)) {
                cout << "Should be: " << vec_to_string(nextPermutationBruteForce(perm)) << endl;
                cout << "Result: " << vec_to_string(nextPermutation(perm)) << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter6
} // epi
