#include <iostream>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (s.empty() || wordDict.empty())
            return {};

        unordered_set<string> dict;
        int minLen = INT_MAX, maxLen = 0;
        for (string &word : wordDict) {
            int len = word.length();
            minLen = min(minLen, len);
            maxLen = max(maxLen, len);
            dict.insert(word);
        }

        vector<string> partial;
        vector<string> res;
        helper(s, 0, partial, dict, minLen, maxLen, res);
        return res;
    }

    void helper(string &s, int st, vector<string> &partial, unordered_set<string> &dict, int minLen, int maxLen, vector<string> &res) {
        int sLen = s.length();
        if (st == sLen) {
            res.push_back(constructString(partial));
            return;
        }

        for (int len = minLen; len <= maxLen && st + len <= sLen; ++len) {
            string candidate = s.substr(st, len);
            if (dict.count(candidate)) {
                partial.push_back(candidate);
                helper(s, st + len, partial, dict, minLen, maxLen, res);
                partial.pop_back();
            }
        }
    }

    string constructString(vector<string> &partial) {
        if (partial.empty())
            return "";
        string res = partial[0];
        for (int i = 1; i < (int)partial.size(); ++i) {
            res += " " + partial[i];
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    for (string &str : sol.wordBreak("catsanddog", wordDict))
        cout << "|" << str << "|" << endl;

    return 0;
}
