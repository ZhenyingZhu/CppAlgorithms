/*
 * [Source] https://leetcode.com/problems/the-maze-ii/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Brute force check every direction. Need to avoid cycle.
// [Corner Case]:
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        maze[hole[0]][hole[1]] = 2; // tag the hole as 2

        int minDis = maze.size() * maze[0].size();
        string res;
        vector<char> movements;
        for (char dir : "dlru") {
            helper(ball, maze, dir, movements, 0, minDis, res);
        }

        if (res.empty())
            return "impossible";
        return res;
    }

    struct MoveStatus {
        int dis;
        bool reachHole;
    };

    void helper(vector<int> ball, vector<vector<int>> &maze, char dir, vector<char> &movements, int preDis, int &minDis, string &res) {
        int oriX = ball[0], oriY = ball[1];

        MoveStatus ms = move(ball, maze, dir);
        if (ms.dis == 0) // invalid move
            return;

        int distance = ms.dis + preDis;
        if (distance > minDis)
            return;

        movements.push_back(dir);
        if (ms.reachHole) {
            if (distance < minDis) {
                minDis = distance;
                res = string(movements.begin(), movements.end());
            }
            movements.pop_back();
            return;
        }

        // tag the start point as visited
        maze[oriX][oriY] = -1;
        for (char newDir : getDir(dir)) {
            helper(ball, maze, newDir, movements, distance, minDis, res);
        }
        movements.pop_back();
        maze[oriX][oriY] = 0;
    }

    MoveStatus move(vector<int> &ball, vector<vector<int>> &maze, char dir) {
        int xInc = 0, yInc = 0;
        if (dir == 'u') {
            xInc = -1;
        } else if (dir == 'd') {
            xInc = 1;
        } else if (dir == 'l') {
            yInc = -1;
        } else {
            yInc = 1;
        }

        int &x = ball[0], &y = ball[1];
        int dis = 0;
        while (x >= 0 && x < (int)maze.size() && y >= 0 && y < (int)maze[0].size() && maze[x][y] == 0) {
            ++dis;
            x += xInc;
            y += yInc;
        }

        if (x >= 0 && x < (int)maze.size() && y >= 0 && y < (int)maze[0].size()) {
            if (maze[x][y] == -1)
                return {0, false}; // cycle detected
            if (maze[x][y] == 2)
                return {dis, true}; // reach hole
        }

        // touch board or wall, need return back
        --dis;
        x -= xInc;
        y -= yInc;
        return {dis, false};
    }

    string getDir(char dir) {
        if (dir == 'u' || dir == 'd')
            return "lr";
        return "du";
    }
};

int main() {
    Solution sol;

    vector<vector<int>> maze = {
        {0,0,0,0,0},
        {1,1,0,0,1},
        {0,0,0,0,0},
        {0,1,0,0,1},
        {0,1,0,0,0}
    };

    vector<int> ball = {4,3}, hole = {0,1};
    cout << sol.findShortestWay(maze, ball, hole) << endl;

    return 0;
}
