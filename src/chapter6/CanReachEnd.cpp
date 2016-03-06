#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::cout;
using std::endl;

namespace chapter6 {
    /* Chapter 6.4
     * Each non-negative interger in an array indicate how far it can go from this cell.
     */

    // define in PlusOne
    void print_vec(vector<int> A);

    bool CanReachEnd(const vector<int> &max_advance_steps) {
        int furthest_reach_so_far = 0, last_index = max_advance_steps.size() - 1;
        for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) {
            furthest_reach_so_far = max(furthest_reach_so_far, max_advance_steps[i] + i);
        }

        return furthest_reach_so_far >= last_index;
    }

    void test_can_reach_end() {
        int temp_arr1[] = { 3, 3, 1, 0, 2, 0, 1 };
        vector<int> a ( temp_arr1, temp_arr1 + sizeof(temp_arr1) / sizeof(temp_arr1[0]) );
        int temp_arr2[] = { 3, 2, 0, 0, 2, 0, 1 };
        vector<int> b ( temp_arr2, temp_arr2 + sizeof(temp_arr2) / sizeof(temp_arr2[0]) );

        cout << "In <";
        print_vec(a);
        cout << ">, can ";
        if (!CanReachEnd(a))
            cout << "not ";
        cout << "reach the end. " << endl;

        cout << "In <";
        print_vec(b);
        cout << ">, can ";
        if (!CanReachEnd(b))
            cout << "not ";
        cout << "reach the end. " << endl;

    }

}
