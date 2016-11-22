/*
 * [Source] https://leetcode.com/problems/wiggle-sort-ii/
 * [Difficulty]: Medium
 * [Tag]: Srot
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// [Solution]: First sort the array. Then cut array in the middle. To ensure the order, the last element of first half must smaller than last element of the second half
// [Corner Case]: [4 5 5 6]
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        
        int firstEd = ((int)nums.size() - 1) / 2, secondEd = (int)nums.size() - 1;
        bool first= true;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (first) {
                nums[i] = tmp[firstEd--];
                first = false;
            } else {
                nums[i] = tmp[secondEd--];
                first = true;
            }
        }
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1, 5, 1, 1, 6, 4};
    //vector<int> nums = {1, 3, 2, 2, 3, 1, 1};
    vector<int> nums = {5, 5, 4, 6};
    sol.wiggleSort(nums);
    for (int& num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
