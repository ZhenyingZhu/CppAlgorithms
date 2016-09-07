/*
 * [Source] https://leetcode.com/problems/regular-expression-matching/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: DP. B(i, j) indicates p[0, i] == s[0, j]. 
// B(i, j) = B(i-1, j-1) && (p[i] == '.' || p[i] == s[j])
//         = p[i] == '*' && {for x = 0..j, B(i-2, x) && s[x+1..j] == p[j-1]}
// [Corner Case]: what if '**' shows up, or '*' at the beginning
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        if (p == ".*")
            return true;

        vector<vector<bool>> match(pLen + 1, vector<bool>(sLen + 1, false));
        match[0][0] = true;

        for (int pIth = 1; pIth <= pLen; ++pIth) {
            for (int sJth = 0; sJth <= sLen; ++sJth) {
                if (p[pIth - 1] == '*') {
                    // deal with wildcard

                    // Error case: p[0] should not be '*', shouldn't has '**'
                    if (pIth == 1 || p[pIth - 2] == '*')
                        return false;

                    if (sJth == 0) {
                        match[pIth][0] = match[pIth - 2][0];
                        continue; // sJth
                    }

                    for (int prevMatch = 0; prevMatch < sJth; ++prevMatch) {
                        // start from 0, means s can has no char. end at sJth - 1, means the whole s
                        if (pIth >= 2 && !match[pIth - 2][prevMatch])
                            continue;

                        // p[pIth - 1] is '*', check the char before '*'
                        if (p[pIth - 2] == '.') {
                            match[pIth][sJth] = true;
                            break; // prevMatch
                        }

                        // check if all char in s is same as previous char
                        bool allCharMatch = true;
                        for (int c = prevMatch; c < sJth; ++c) {
                            if (s[c] != p[pIth - 2]) {
                                allCharMatch = false;
                                break;
                            }
                        }
                        if (allCharMatch) {
                            match[pIth][sJth] = true;
                            break; // prevMatch
                        }
                    }
                } else {
                    // normal case
                    if (sJth == 0) {
                        match[pIth][sJth] = false;
                    } else if (p[pIth - 1] == '.' || p[pIth - 1] == s[sJth - 1]) {
                        if (match[pIth - 1][sJth - 1]) {
                            match[pIth][sJth] = true;
                        }
                    }
                } // if *
            } // sJth
        } // pIth

        return match[pLen][sLen];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    if (!sol.isMatch("a","a"))
        cout << "0 fail" << endl;
    if (sol.isMatch("aa","a"))
        cout << "1 fail" << endl;
    if (!sol.isMatch("aa","aa"))
        cout << "2 fail" << endl;
    if (sol.isMatch("aaa","aa"))
        cout << "3 fail" << endl;
    if (!sol.isMatch("aa", "a*"))
        cout << "4 fail" << endl;
    if (!sol.isMatch("aa", ".*"))
        cout << "5 fail" << endl;
    if (!sol.isMatch("ab", ".*"))
        cout << "6 fail" << endl;
    if (!sol.isMatch("aab", "c*a*b"))
        cout << "7 fail" << endl;
    if (!sol.isMatch("", ""))
        cout << "8 fail" << endl;
   if (!sol.isMatch("aab", "a*a*b"))
        cout << "9 fail" << endl;
   if (!sol.isMatch("aaab", "a*b"))
        cout << "10 fail" << endl;
   if (sol.isMatch("a", "ab*a"))
        cout << "11 fail" << endl;
   if (!sol.isMatch("aaa", "ab*ac*a"))
        cout << "12 fail" << endl;

    return 0;
}
