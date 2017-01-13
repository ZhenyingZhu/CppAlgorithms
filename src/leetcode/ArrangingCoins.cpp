/*
 * [Source] https://leetcode.com/problems/arranging-coins/
 * [Difficulty]: Easy
 * [Tag]: Binary Search
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int arrangeCoins(int n) {
        long st = 0, ed = n;
        while (st + 1 < ed) {
            long md = st + (ed - st) / 2;
            long num = (1 + md) * md / 2;
            if (num > (long)n)
                ed = md;
            else
                st = md;
        }
        if ( (1 + ed) * ed / 2 <= n )
            return ed;
        return st;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
