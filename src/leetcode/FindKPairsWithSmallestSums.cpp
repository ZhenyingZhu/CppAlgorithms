/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

// [Solution]:
// [Corner Case]:
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
        unordered_map<int, int> nums1Idx, nums2Idx;

        pq.push({0, 0, nums1[0] + nums2[0]});
        nums1Idx[0] = 1;
        nums2Idx[0] = 1;
        while ( !pq.empty() && k > (int)res.size() ) {
cout << "before" << endl;
for (auto it = nums1Idx.begin(); it != nums1Idx.end(); ++it)
    cout << it->first << "-" << it->second << endl;
cout << endl;
for (auto it = nums2Idx.begin(); it != nums2Idx.end(); ++it)
    cout << it->first << "-" << it->second << endl;

            PairIdx cur = pq.top();
            pq.pop();
            res.push_back({nums1[cur.idx1], nums2[cur.idx2]});

cout << "(" << cur.idx1 << "," << cur.idx2 << ") = ";

            int nextIdx1 = nums1Idx[cur.idx2];
            if ( nextIdx1 < (int)nums1.size() ) {
                // add next number from nums1
                pq.push( {nextIdx1, cur.idx2, nums1[nextIdx1] + nums2[cur.idx2]} );
                nums1Idx[cur.idx2] = nextIdx1 + 1; // the number nums2[idx2] has sum up to idx1
                nums2Idx[nextIdx1 + 1] = cur.idx2;
                nums2Idx[nextIdx1] = cur.idx2 + 1;
                nums1Idx[cur.idx2 + 1] = nextIdx1;
cout << "(" << nextIdx1 << "," << cur.idx2 << ") ";
            }

            // add next number from nums2
            int nextIdx2 = nums2Idx[cur.idx1];
            if ( nextIdx2 < (int)nums2.size() ) {
                pq.push( {cur.idx1, nextIdx2, nums1[cur.idx1] + nums2[nextIdx2]} );
                nums1Idx[nextIdx2] = cur.idx1 + 1;
                nums2Idx[cur.idx1 + 1] = nextIdx2;
                nums2Idx[cur.idx1] = nextIdx2 + 1;
                nums1Idx[nextIdx2 + 1] = cur.idx1;
cout << "(" << cur.idx1 << "," << nextIdx2 << ")";
            }
cout << endl;

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums1 = {3, 22, 35, 56, 76};
    //vector<int> nums2 = {3, 22, 35, 56, 76};
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};

    //for (pair<int, int> &p : sol.kSmallestPairs(nums1, nums2, 25)) {
    for (pair<int, int> &p : sol.kSmallestPairs(nums1, nums2, 10)) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
