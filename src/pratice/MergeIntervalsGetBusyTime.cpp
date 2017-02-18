#include <iostream>
#include <vector>
#include <list>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-218632-1-1.html

struct Interval {
    int start, end;
    Interval(int s, int e): start(s), end(e) { }
};

class MergedIntervalsLinkedList {
public:
    MergedIntervals(): totalTime(0) {
    }

    void addInterval(Interval interval) {
        auto it = intervalList.begin();
        while (it != intervalList.end() && it->end < interval.start)
            ++it;

        if (it == intervalList.end()) {
            intervalList.push_back(interval);
            totalTime += interval.end - interval.start;
            return;
        }

        if (it->start > interval.end) {
            intervalList.insert(it, interval);
            totalTime += interval.end - interval.start;
            return;
        }

        int st = min(interval.start, it->start);
        int ed = max(interval.end, it->end);
        while (it != intervalList.end() && it->start <= interval.end) {
            totalTime -= it->end - it->start;
            ed = max(ed, it->end);
            auto deleteIt = it;
            ++it;
            intervalList.erase(deleteIt);
        }

        totalTime += ed - st;
        intervalList.insert(it, Interval(st, ed));
    }

    int getTotalBusyTime() {
        return totalTime;
    }

    void printIntervals() {
        for (auto it = intervalList.begin(); it != intervalList.end(); ++it) {
            cout << "[" << it->start << "," << it->end << "] ";
        }
        cout << endl;
    }

private:
    list<Interval> intervalList;
    int totalTime;
};

int main() {
    MergedIntervals mi;

    vector<Interval> input = { {1,3}, {5,6}, {2,5} };
    for (Interval &i : input) {
        mi.addInterval(i);
        mi.printIntervals();
        cout << mi.getTotalBusyTime() << endl;
    }

    return 0;
}
