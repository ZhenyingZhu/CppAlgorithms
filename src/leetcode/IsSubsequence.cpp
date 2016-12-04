/*
 * [Source] https://leetcode.com/problems/is-subsequence/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 * [Tag]: Greedy
 */

#include <iostream>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class SolutionSingleRun {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;

        int sIdx = 0;
        for (char &c : t) {
            if (c == s[sIdx]) {
                ++sIdx;
                if (sIdx == (int)s.length())
                    return true;
            }
        }
        return false;
    }
};

// [Solution]: Not complete. I think a trie tree might helpful?
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
