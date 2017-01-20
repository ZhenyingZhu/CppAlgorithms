/*
 * [Source] https://leetcode.com/problems/concatenated-words/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Trie
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// [Solution]: Sort the string from short to long. Then try break current string with previous strings
// [Corner Case]:
class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty())
            return {};

        sort(words.begin(), words.end(), compare);
        unordered_set<string> wordSet;
        wordSet.insert(words[0]);
        int minLen = words[0].length();

        vector<string> res;
        for (int i = 1; i < (int)words.size(); ++i) {
            string &str = words[i];
            if (canConstruct(str, minLen, wordSet)) {
                res.push_back(str);
            }
            wordSet.insert(str);
        }
        return res;
    }

    bool canConstruct(string str, int minLen, unordered_set<string> &wordSet) {
        int len = str.length();
        if (len == 0)
            return true;
        if (len < minLen)
            return false;

        for (int width = minLen; width <= len; ++width) {
            if (wordSet.count( str.substr(0, width) ) == 0)
                continue;
            if ( canConstruct(str.substr(width), minLen, wordSet) )
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    for (string &str : sol.findAllConcatenatedWordsInADict(words))
        cout << str << " ";
    cout << endl;

    return 0;
}
