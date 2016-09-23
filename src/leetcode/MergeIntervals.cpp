/*
 * [Source] https://leetcode.com/problems/merge-intervals/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// [Solution]: sort by start, then check if previous end is larger than next start. If so, overlap.
// [Corner Case]: 0 intervals.
class Solution {
private:
    bool static intervalCompare(const Interval& smaller, const Interval& larger) {
        return smaller.start < larger.start;
    }

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int len = intervals.size();
        if (len == 0)
            return res;

        sort(intervals.begin(), intervals.end(), intervalCompare);
        int intSt = intervals[0].start, intEd = intervals[0].end;
        for (int i = 1; i < len; ++i) {
            const Interval& cur = intervals[i];
            if (cur.start > intEd) {
                res.push_back(Interval(intSt, intEd));
                intSt = cur.start;
                intEd = cur.end;
            } else {
                intEd = max(intEd, cur.end);
            }
        }
        res.push_back(Interval(intSt, intEd));

        return res;
    }
};

// helper
void printIntervalVec(const vector<Interval>& vec) {
    for (const Interval& interval : vec) {
        cout << "{" << interval.start << "," << interval.end << "} ";
    }
    cout << endl;
}

/* Java solution
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals.size()<=1) return intervals;
		sortIntervals(intervals, 0, intervals.size()-1);
		List<Interval> result=new ArrayList<Interval>();
		int s=intervals.get(0).start;
		int e=intervals.get(0).end;
		for(int i=1; i<intervals.size(); i++){
			if(intervals.get(i).start>e){
				result.add(new Interval(s, e));
				s=intervals.get(i).start;
				e=intervals.get(i).end;
			}else if(intervals.get(i).end>e){
				e=intervals.get(i).end;
			}
		}
		result.add(new Interval(s, e));
		return result;
    }
	
	public void sortIntervals(List<Interval> intervals, int start, int end){
		if(start>end) return;
		int mid=(start+end)/2;
		int st=intervals.get(mid).start;
		swap(intervals, mid, end);
		int pt=start-1;
		for(int i=start; i<end; i++){
			if(intervals.get(i).start<st){
				pt++;
				swap(intervals, pt, i);
			}
		}
		pt++;
		swap(intervals, pt, end);
		sortIntervals(intervals, start, pt-1);
		sortIntervals(intervals, pt+1, end);
	}
	
	public void swap(List<Interval> intervals, int a, int b){
		int tmpS=intervals.get(a).start;
		int tmpE=intervals.get(a).end;
		intervals.get(a).start=intervals.get(b).start;
		intervals.get(a).end=intervals.get(b).end;
		intervals.get(b).start=tmpS;
		intervals.get(b).end=tmpE;
    }
}
 */

// [Solution]: use heap to do the sort
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/MergeIntervals.java
 */

int main() {
    Solution sol;

    vector<Interval> vec = {{1,3},{2,6},{8,10},{15,18}};
    printIntervalVec(sol.merge(vec));

    return 0;
}
