/*
 * [Source] https://leetcode.com/problems/kth-largest-element-in-an-array/
 * [Difficulty]: Medium
 * [Tag]: Heap
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <vector>
#include <climits>
#include <list>

using namespace std;

// [Solution]: Use a list for candidates. O(kn)
class SolutionSlow {
public:
    int findKthLargest(vector<int>& nums, int k) {
        list<int> candidates;
        for (int& num : nums) {
            if (candidates.empty() || num > candidates.back()) {
                candidates.push_back(num);
            } else {
                list<int>::iterator it = candidates.begin();
                for (; it != candidates.end(); ++it) {
                    if (*it >= num)
                        break;
                }
                candidates.insert(it, num);
            }
            if ((int)candidates.size() > k) {
                candidates.pop_front();
            }
cout << "num: " << num << endl;
for (int& c : candidates)
    cout << c << " ";
cout << endl;
        }
        return candidates.front();
    }
};

// [Solution]: Use a k size min heap to insert the candidates. O(logkN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap = {INT_MIN};
        for (int& num : nums) {
            insertHeap(heap, num);
            if ((int)heap.size() > k + 1)
                popHeap(heap);
        }
        return heap[1];
    }

private:
    void insertHeap(vector<int>& heap, int val) {
cout << "insert " << val << endl;
        heap.push_back(val);
        int cur = heap.size() - 1, par = cur / 2;
        while (par != 0 && heap[cur] < heap[par]) {
            swap(heap[cur], heap[par]);
            cur = par;
            par = cur / 2;
        }
printVec(heap);
    }

    int popHeap(vector<int>& heap) {
cout << "pop" << endl;
        if (heap.size() == 1) // empty
            return INT_MIN;
        int min = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();

        int cur = 1, left = 2, right = 3;
        while (left < (int)heap.size()) {
            int smaller = left;
            if (right < (int)heap.size()) {
                smaller = heap[left] > heap[right] ? right : left;
            }
            if (heap[cur] < heap[smaller])
                break;

            swap(heap[cur], heap[smaller]);
            cur = smaller;
            left = cur * 2;
            right = cur * 2 + 1;
        }
printVec(heap);
        return min;
    }

    // helper
    void printVec(vector<int>& vec) {
        for (int& num : vec)
            cout << num << " ";
        cout << endl;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3,2,1,5,6,4};
    cout << sol.findKthLargest(nums, 2) << endl;

    return 0;
}
