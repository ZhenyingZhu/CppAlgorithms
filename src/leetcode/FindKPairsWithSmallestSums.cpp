/*
 * [Source] https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

// [Solution]: Each time push a pair to result, get 1. the number from nums1 and the next number from nums2, and 2. the next number from nums1, and its unpushed pair in nums2. Push them to a priority queue.
// [Corner Case]: Cannot use two hash maps to store the next idx for nums1 and nums2, because we are only traverse nums1.
class Solution {
public:
    struct PairIdx {
        int idx1, idx2;
        int sum;
    };

    struct cmp {
        bool operator()(const PairIdx &p1, const PairIdx &p2) {
          return p1.sum > p2.sum;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty())
            return {};

        vector<pair<int, int>> res;
        priority_queue<PairIdx, vector<PairIdx>, cmp> pq;
        vector<int> nextIdx(nums1.size(), 0); // For each number in nums1, which number in nums2 is the next to valuate, which means hasn't pushed into priority_queue

        pq.push({0, 0, nums1[0] + nums2[0]});
        nextIdx[0] = 1;
        while ( !pq.empty() && k > (int)res.size() ) {
            PairIdx cur = pq.top();
            pq.pop();
            res.push_back({nums1[cur.idx1], nums2[cur.idx2]});

cout << "(" << cur.idx1 << "," << cur.idx2 << ")=";
            // add next number from nums1, and its next nums2
            int nextIdx1 = cur.idx1 + 1;
            if ( nextIdx1 < (int)nums1.size() && nextIdx[nextIdx1] < (int)nums2.size() ) {
                int idx2 = nextIdx[nextIdx1];
                pq.push( {nextIdx1, idx2, nums1[nextIdx1] + nums2[idx2]} );
                ++nextIdx[nextIdx1];
cout << "(" << nextIdx1 << "," << idx2 << ") ";
            }

            // add current number and its next number from nums2
            int nextIdx2 = nextIdx[cur.idx1];
            if ( nextIdx2 < (int)nums2.size() ) {
                pq.push( {cur.idx1, nextIdx2, nums1[cur.idx1] + nums2[nextIdx2]} );
                ++nextIdx[cur.idx1];
cout << "(" << cur.idx1 << "," << nextIdx2 << ")";
            }
cout << endl;
for (int num : nextIdx)
    cout << num << " ";
cout << endl;
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};

    for (pair<int, int> &p : sol.kSmallestPairs(nums1, nums2, 10)) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
