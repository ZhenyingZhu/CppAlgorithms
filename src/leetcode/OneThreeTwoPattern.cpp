/*
 * [Source] https://leetcode.com/problems/132-pattern/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Solution]: Do it in reverse order. Use a stack.
// [Corner Case]:
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return false;

        // s2 > s3 > s1
        stack<int> a2; // s3 candidates come from here
        int a3 = INT_MIN;
        for (int i = len - 1; i >= 0; --i) {
            int &num = nums[i];
            if (num < a3)
                return true;

            while (!a2.empty() && a2.top() < num) {
                a3 = a2.top();
                a2.pop();
            }
            a2.push(num);
        }
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
