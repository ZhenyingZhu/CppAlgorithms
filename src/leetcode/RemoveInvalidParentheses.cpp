/*
 * [Source] https://leetcode.com/problems/remove-invalid-parentheses/
 * [Difficulty]: Hard
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Brute force DFS, iterate through all possible value, and then pick those longest results.
// [Corner Case]: Since there are other chars, need to make sure 1. not out of length, 2. those chars need to be removed for each try
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> valid;

        vector<char> pre;
        helper(s, 0, pre, 0, 0, valid);

        int maxLen = 0;
        for (int i = 0; i < (int)valid.size(); ++i) {
            maxLen = max((int)valid[i].length(), maxLen);
        }

        vector<string> res;
        for (int i = 0; i < (int)valid.size(); ++i) {
            if ( (int)valid[i].length() == maxLen && find(res.begin(), res.end(), valid[i]) == res.end() )
                res.push_back(valid[i]);
        }
        return res;
    }

    void helper(string& s, int idx, vector<char>& pre, int lCnt, int rCnt, vector<string>& res) {
        if (lCnt < rCnt)
            return;

        if (idx >= (int)s.length()) {
            if (lCnt == rCnt) {
                res.push_back( string(pre.begin(), pre.end()) );
            }
            return;
        }

        int curLen = pre.size();

        while (idx < (int)s.length() && s[idx] != '(' && s[idx] != ')') {
            pre.push_back(s[idx]);
            ++idx;
        }

        // not add parenthese
        helper(s, idx + 1, pre, lCnt, rCnt, res);

        if (idx < (int)s.length()) {
            // add parenthese
            if (s[idx] == '(') {
                pre.push_back('(');
                helper(s, idx + 1, pre, lCnt + 1, rCnt, res);
            } else {
                pre.push_back(')');
                helper(s, idx + 1, pre, lCnt, rCnt + 1, res);
            }
        }

        pre.erase(pre.begin() + curLen, pre.end());
    }
};

int main() {
    Solution sol;

    //vector<string> res = sol.removeInvalidParentheses("()())()");
    vector<string> res = sol.removeInvalidParentheses("n");
    for (string& str : res)
        cout << str << endl;

    return 0;
}
