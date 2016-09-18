/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]:
// [Corner Case]: words have dup. not start from s index 0.
class Solution {
private:
    int deleteHead(const string& s, int head, unordered_map<string, int>& showedStrings, const int len) {
        string remove = s.substr(head, len);
        --showedStrings[remove];
        return head + len;
    }

    void findHelper(const string& s, int st, const unordered_map<string, int>& freq, const int len, const int total, vector<int>& res) {
        unordered_map<string, int> showedStrings;

        int head = st;
        int found = 0;
        for (int i = st; i <= s.length() - len; i += len) {
            string cur = s.substr(i, len);
            const auto it = freq.find(cur);
            if ( it == freq.end() ) {
                findHelper(s, i + len, freq, len, total, res);
                return;
            }

            ++found;
            ++showedStrings[cur];

            while (showedStrings[cur] > it->second) {
                head = deleteHead(s, head, showedStrings, len);
                --found;
            }

            if (found == total) {
                res.push_back(head);
                head = deleteHead(s, head, showedStrings, len);
                --found;
            }

        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0)
            return res;

        unordered_map<string, int> freq;
        for (const string& word : words) {
            ++freq[word]; // it works!
        }

        int len = words[0].length();
        for (int i = 0; i < len; ++i) {
            findHelper(s, i, freq, len, words.size(), res);
        }

        return res;
    }

};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> words = {"bar","foo","the"};
    vector<int> res = sol.findSubstring("barfoofoobarthefoobarman", words);
    for (const int& i : res)
        cout << i << ",";
    cout << endl;

    return 0;
}
