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
#include <algorithm>
#include <list>

using namespace std;

// [Solution]: Basically make end columns sort as high to low, first to last. When hit a start point, print all previous end columns. Print start column if it should prin
// [Corner Case]:
class Solution {
public:
    struct EndHeight {
        int end;
        int height;
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;

        priority_queue<EndHeight, vector<EndHeight>, function<bool(EndHeight, EndHeight)>> heights
            ( [](const EndHeight& h1, const EndHeight& h2) -> bool {return h1.height < h2.height;} );
        for (vector<int>& cur : buildings) {
            int st = cur[0], ed = cur[1], h = cur[2];
cout << "Dealing with " << st << endl;

            while (!heights.empty() && heights.top().end < st) { // end == st shouldnot pop, otherwise leads to an unexpected {end, 0}
                int end = heights.top().end;
cout << "poping " << heights.top().end << "+" << heights.top().height << endl;
                heights.pop();
                int secondHeight = heights.empty() ? 0 : heights.top().height;
cout << "here1 " << endl;
                // if two blocks should not have same heights
                pushRes(end, secondHeight, res, false);
            }

            if (heights.empty() || heights.top().height < h) {
cout << "here2 " << endl;
                pushRes(st, h, res, true);
            }

            while (!heights.empty() && heights.top().height <= h && heights.top().end <= ed) {
cout << "poping " << heights.top().end << "+" << heights.top().height << endl;
                heights.pop();
            }
            if (heights.empty() || heights.top().end < ed || heights.top().height < h) {
cout << "heights add " << ed << "+" << h << endl;
                heights.push({ed, h});
            }
        }

        while (!heights.empty()) {
            int end = heights.top().end;
            heights.pop();
            int secondHeight = heights.empty() ? 0 : heights.top().height;
cout << "here3 " << endl;
            pushRes(end, secondHeight, res, false);
        }

        return res;
    }

    void pushRes(int coordinate, int height, vector<pair<int, int>>& res, bool isUp) {
cout << "print " << coordinate << " " << height << endl;
        if (!res.empty() && res.back().first >= coordinate) {
            if (isUp) {
                res.back().second = max(res.back().second, height);
            } else {
                res.back().second = min(res.back().second, height);
            }
        } else {
            res.push_back({coordinate, height});
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    //vector<vector<int>> buildings = {{3,10,20},{3,9,19},{3,8,18},{3,7,17},{3,6,16},{3,5,15},{3,4,14}};
    vector<vector<int>> buildings = {{2,4,70},{3,8,30},{6,100,41},{7,15,70},{10,30,102},{15,25,76},{60,80,91},{70,90,72},{85,120,59}};
    vector<pair<int, int>> res = sol.getSkyline(buildings);
    for (pair<int, int>& p : res) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
