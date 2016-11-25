/*
 * [Source] https://leetcode.com/problems/counting-bits/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Each number after a 2^n is 1 + num - 2^n.
// [Corner Case]:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        if (num == 0)
            return res;
        res[1] = 1;

        int prePt = 0, curPt = 2;
        int exp = 2;
        while (curPt <= num) {
            if (prePt == exp) {
                prePt = 0;
                exp += exp;
            } else {
                res[curPt++] = 1 + res[prePt++];
            }
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int &i : sol.countBits(5))
        cout << i << " ";
    cout << endl;

    return 0;
}
