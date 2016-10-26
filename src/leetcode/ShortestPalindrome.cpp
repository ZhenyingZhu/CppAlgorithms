/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        vector<vector<int>> matrix(s.length(), vector<int>(s.length(), 2));
        for (int i = (int)s.length() - 1; i >= 0; --i) {
            if (isPalindrome(s, 0, i, matrix)) {
                return construct(s, i + 1);
            }
        }
        return s; // should not reach here
    }

private:
    bool isPalindrome(string& s, int st, int ed, vector<vector<int>>& matrix) {
        if (s[st] != s[ed])
            return false;
        if (matrix[st][ed] == 0)
            return false;
        if (matrix[st][ed] == 1)
            return true;

        if (st + 2 >= ed || isPalindrome(s, st + 1, ed - 1, matrix)) {
            matrix[st][ed] = 1;
            return true;
        }
        matrix[st][ed] = 0;
        return false;
    }

    string construct(string& s, int palLen) {
cout << palLen << endl;
        string tmp = s.substr(palLen, s.length() - palLen);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.shortestPalindrome("abcd") << endl;
    cout << sol.shortestPalindrome("aacecaaa") << endl;

    return 0;
}
