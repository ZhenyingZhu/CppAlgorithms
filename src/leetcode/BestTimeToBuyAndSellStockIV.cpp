/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int maxProfitTimeOut(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if ((int)prices.size() <= k)
            return maxProfitBetween(prices);

        vector<vector<int>> kTransAtEd(k + 1, vector<int>(prices.size(), 0));
        for (int time = 1; time <= k; ++time) {
            for (size_t ed = 1; ed < prices.size(); ++ed) {
                kTransAtEd[time][ed] = kTransAtEd[time][ed - 1]; // buy and sell at ed
                for (size_t st = 0; st < ed; ++st) {
                    int diff = prices[ed] - prices[st];
                    if (diff > 0) {
                        kTransAtEd[time][ed] = max(kTransAtEd[time][ed], kTransAtEd[time - 1][st] + diff);
                    }
                }
            }
        }
        return kTransAtEd[k][prices.size() - 1];
    }


    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if (prices.size() <= k)
            return maxProfitBetween(prices);

        vector<int> global(k + 1, 0), local(k + 1, 0);
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
for (size_t i = 0; i <= k; ++i)
    cout << local[i] << " ";
cout << endl;
for (size_t i = 0; i <= k; ++i)
    cout << global[i] << " ";
cout << endl;
        return global[k];
    }

private:
    int maxProfitBetween(vector<int>& prices) {
        int maxProfit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            maxProfit += diff > 0 ? diff : 0;
        }
        return maxProfit;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> prices = {1, 0, 1, 0, 2, 0, 3};
    cout << sol.maxProfit(3, prices) << endl;

    return 0;
}
