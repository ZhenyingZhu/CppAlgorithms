#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-218628-2-1.html

class Solution {
public:
    int waysKnightCanJump(int m, int n, int step) {
        vector<unordered_set<int>> visited(step); // since can jump back to previous cell. just don't repeat compute same cell for same steps
        unordered_set<int> targets;
        dirs = {
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
        };

        helper(m, n, 0, step, visited, targets);
        return targets.size();
    }

    void helper(int x, int y, int k, int step, vector<unordered_set<int>> &visited, unordered_set<int> &targets) {
        if (k == step) {
            targets.insert(getIdx(x, y));
            return;
        }

        if (visited[k].count(getIdx(x, y))) {
            return;
        }

        visited[k].insert(getIdx(x, y));
        for (vector<int> &dir : dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
                continue;
            helper(newX, newY, k + 1, step, visited, targets);
        }
    }

    int getIdx(int x, int y) {
        return x * 8 + y;
    }

    vector<vector<int>> dirs;
};

int main() {
    Solution sol;

    cout << sol.waysKnightCanJump(2, 2, 2) << endl;

    return 0;
}
