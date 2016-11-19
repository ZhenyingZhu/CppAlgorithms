/*
 * [Source] https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Either previous day result(which means no sell today), or the max of each day i before previous day, and the profix from day i + 2 to today.
// [Corner Case]:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        vector<int> dp(prices.size() + 2, 0);
        for (size_t ed = 1; ed < prices.size(); ++ed) {
            int maxTemp = dp[2 + ed - 1];
            for (size_t st = 0; st < ed; ++st) {
                maxTemp = max( maxTemp, dp[2 + st - 2] + max(0, prices[ed] - prices[st]) );
            }
            dp[2 + ed] = maxTemp;
            maxProfit = max(maxProfit, maxTemp);
        }
        return maxProfit;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> prices = {1, 2, 3, 0, 2};
    //vector<int> prices = {1, 7, 2, 4};
    vector<int> prices = {6, 1, 6, 4, 3, 0, 2};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
