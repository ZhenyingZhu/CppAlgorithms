/*
 * [Source] https://leetcode.com/problems/russian-doll-envelopes/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

// [Solution]: Sort the array by first, then use 2D DP.
// [Corner Case]:
class Solution {
public:
    static bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first > p2.first) {
            return false;
        } else if (p1.second < p2.second) {
            return true;
        }
        // same emvelope return false
        return false;
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), smaller);

        vector<int> nums(envelopes.size(), 1);
        int res = 1;
        for (int cur = 1; cur < (int)envelopes.size(); ++cur) {
            pair<int, int> &curEnv = envelopes[cur];
            int maxNum = 1;
            for (int pre = cur - 1; pre >= 0; --pre) {
                pair<int, int> &preEnv = envelopes[pre];
                if (curEnv.first > preEnv.first && curEnv.second > preEnv.second)
                    maxNum = max(nums[pre] + 1, maxNum);
            }
            nums[cur] = maxNum;
            res = max(maxNum, res);
        }

        return res;
    }

/* Trying to use O(nlogn) DP but too complicate. Can sort with second desc
    int maxEnvelopesNotFinish(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), smaller);

for (pair<int, int> &p : envelopes)
    cout << p.first << "," << p.second << " ";
cout << endl;

        vector<pair<int, int>> lastOfLen;
        for (pair<int, int> &envelope : envelopes) {
            int lastSmaller = binarySearch(lastOfLen, envelope);

            if (lastSmaller == (int)lastOfLen.size()) {
                lastOfLen.push_back(envelope);
            } else {
                pair<int, int> &small = lastOfLen[lastSmaller];
                // lastSmaller cannot be same as envelope
                // 1. lastSmaller has same first
                if (small.first == envelope.first) {
                    // envelope cannot be the next one, and lastSmaller has smaller second
                    continue;
                }

                // 2. lastSmaller has same second
                if (small.second == envelope.second) {
                    // envelope cannot be the next one, and lastSmaller has smaller first
                    continue;
                }

                // 3. Too complicate.
            }
        }

        return 0;
    }
*/
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<pair<int, int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

    cout << sol.maxEnvelopes(envelopes) << endl;

    return 0;
}
