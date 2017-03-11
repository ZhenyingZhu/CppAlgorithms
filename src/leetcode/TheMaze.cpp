/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int> start, vector<int> destination) {
        // dir: 0: left, 1: down, 2: right, 3: up
        return dfs(maze, start[0], start[1], destination[0], destination[1]);
    }

private:
    bool dfs(vector<vector<int>> &maze, int curX, int curY, int desX, int desY) {
        if (maze[curX][curY] == 2)
            return false;
        maze[curX][curY] = 2; // visited

        for (int i = 0; i < 4; i++) {
            vector<int> next = findNext(maze, curX, curY, i, desX, desY);
            if (next[0] == desX && next[1] == desY)
                return true;
            if (next[0] == -1 && next[1] == -1)
                continue;

            if (dfs(maze, next[0], next[1], desX, desY)) {
                cout << "(" << next[0] << "," << next[1] << ")" << endl;
                return true;
            }
        }

        maze[curX][curY] = 0;
        return false;
    }

    vector<int> findNext(vector<vector<int>> &maze, int x, int y, int dir, int desX, int desY) {
        int preX = x, preY = y;
        while (x >= 0 && x < (int)maze.size() && y >= 0 && y < (int)maze[0].size() && maze[x][y] != 1) {
            preX = x;
            preY = y;
            x += dirs[dir];
            y += dirs[dir + 1];
        }
        if ( (x == preX && y == preY) || maze[preX][preY] == 2 )
            return {-1, -1};
        return {preX, preY};
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> maze = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0}
    };
    cout << sol.hasPath(maze, {0,4}, {3,2}) << endl;

    return 0;
}
