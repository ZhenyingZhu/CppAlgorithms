#include "RandomSubset.hpp"

#include <vector>
#include <unordered_map>
#include <random>
#include <iostream>
#include <algorithm>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::sort;
using myutils::vec_to_string;

namespace epi {
  namespace chapter6 {
    vector<int> RandomSubset::randomSubset(int n, int k) {
        unordered_map<int, int> changedElements;

        default_random_engine seed( (random_device()) () );

        for (int i = 0; i != k; ++i) {
            int randomIdx = uniform_int_distribution<int>{ i, n - 1 }(seed);

            auto ptr1 = changedElements.find(randomIdx);
            auto ptr2 = changedElements.find(i);
            if ( ptr1 == changedElements.end() && ptr2 == changedElements.end() ) {
                changedElements[i] = randomIdx;
                changedElements[randomIdx] = i;
            } else if ( ptr1 == changedElements.end() && ptr2 != changedElements.end() ) {
                changedElements[randomIdx] = ptr2->second;
                changedElements[i] = randomIdx;
            } else if ( ptr1 != changedElements.end() && ptr2 == changedElements.end() ) {
                changedElements[randomIdx] = i;
                changedElements[i] = ptr1->second;
            } else {
                changedElements[randomIdx] = ptr2->second;
                changedElements[i] = ptr1->second;
            }
        }

        vector<int> res;
        for (int i = 0; i != k; ++i) {
            res.push_back(changedElements[i]);
        }

        sort(res.begin(), res.end());

        return res;
    }

    bool RandomSubset::test() {
        for (int i = 0; i != 16; ++i) {
            vector<int> res = randomSubset(4, 3);
            cout << vec_to_string(res) << endl;
        }

        return true;
    }
  } // chapter6
} // epi
