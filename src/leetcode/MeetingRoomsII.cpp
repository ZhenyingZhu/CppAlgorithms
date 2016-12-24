/*
 * [Source] https://leetcode.com/problems/meeting-rooms-ii/
 * [Difficulty]: Medium
 * [Tag]: Heap
 * [Tag]: Greedy
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// [Solution]: Use a priority queue to store ends. Every time pick the smallest end and see if the new interval and fit into this room. Otherwise increase the room number
// [Corner Case]:
class Solution {
public:
    static bool smaller(const Interval &int1, const Interval &int2) {
        return int1.start < int2.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), smaller);
        priority_queue<int, vector<int>, greater<int>> ends;

        int rooms = 0;
        for (Interval &inter : intervals) {
            if (ends.empty() || ends.top() > inter.start) {
                ++rooms;
            } else {
                ends.pop();
            }
            ends.push(inter.end);
        }
        return rooms;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<Interval> intervals = {{0, 15},{0, 10},{15, 20}};
    cout << sol.minMeetingRooms(intervals) << endl;

    return 0;
}
