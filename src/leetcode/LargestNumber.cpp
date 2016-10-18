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
    string largestNumber(vector<int>& nums) {
        vector<string> strs = convertToString(nums);
        sort(strs.begin(), strs.end(), numCompare);
        string res;
        for (string& s : strs)
            res += s;
        res.erase(0, min(res.find_first_not_of('0'), res.size()-1)); // remove leading 0
        return res;
    }

private:
    vector<string> convertToString(const vector<int>& nums) {
        vector<string> res;
        for (int num : nums) {
            vector<char> numInStr;
            if (num == 0) {
                numInStr.push_back('0');
            } else {
                while (num != 0) {
                    numInStr.push_back(num % 10 + '0');
                    num /= 10;
                }
            }
            reverse(numInStr.begin(), numInStr.end());
            res.push_back(string(numInStr.begin(), numInStr.end()));
        }
        return res;
    }

    bool static numCompare(const string& larger, const string& smaller) {
        // when a==b return false
        size_t lSize = larger.size(), sSize = smaller.size();
        if (lSize == 0 || sSize == 0)
            return false;
        for (size_t i = 0; i < max(lSize, sSize); ++i) {
            char lC = larger[i % lSize], sC = smaller[i % sSize];
            if (lC > sC)
                return true;
            if (lC < sC)
                return false;
        }
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {3, 30, 34, 5, 9};
    //vector<int> nums = {0,0};
    //vector<int> nums = {824,938,1399,5607,6973,5703,9609,4398,8247};
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << sol.largestNumber(nums) << endl;

    return 0;
}
