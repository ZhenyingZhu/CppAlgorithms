/*
 * [Source] https://leetcode.com/problems/course-schedule-ii/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Graph
 * [Tag]: Topological Sort
 */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: Use a hash map to indicate depth. When depth is INT_MAX, means visiting; when it is another int, means visited. So when found a child is visiting, cycle detected. Otherwise the depth of current node is the max depth of all children + 1.
// [Corner Case]:
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        for (const pair<int, int>& edge : prerequisites) {
            graph[edge.first].insert(edge.second);
        }

        unordered_map<int, int> depth;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            if (depth.find(it->first) != depth.end()) {
                continue; // visited
            }
            if (dfs(it->first, graph, depth) == INT_MAX)
                return {}; // cannot topological sort
        }

        vector<vector<int>> levels(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (depth.find(i) == depth.end()){
                levels[numCourses - 1].push_back(i); // no requisites
            } else {
                levels[depth[i]].push_back(i);
            }
        }

        vector<int> res;
        for (vector<int>& vec : levels) {
            res.insert(res.end(), vec.begin(), vec.end());
        }
        return res;
    }

private:
    int dfs(int node, unordered_map<int, unordered_set<int>>& graph, unordered_map<int, int>& depth) {
        // if depth[node] == INT_MAX, means visiting
        // if depth[node] = any other ints, means visited
        if (depth.find(node) != depth.end()) {
            if (depth[node] == INT_MAX)
                return INT_MAX; // cycle detected
            return depth[node];
        }

        const unordered_set<int>& neighbors = graph[node];
        if (neighbors.size() == 0) { // the sink, which has depth 0
            depth[node] = 0;
            return 0;
        }

        int maxDepth = 0;
        depth[node] = INT_MAX; // tag as visiting
        for (const int& neighbor : neighbors) {
            int childDep = dfs(neighbor, graph, depth);
            if (childDep == INT_MAX)
                return INT_MAX; // cycle detected
            maxDepth = max(childDep, maxDepth);
        }

        depth[node] = maxDepth + 1;
        return maxDepth + 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<pair<int, int>> prerequisites{{1, 0}};
    //vector<int> courses = sol.findOrder(2, prerequisites);
    vector<pair<int, int>> prerequisites{{1,0},{2,0},{3,1},{3,2}};
    vector<int> courses = sol.findOrder(5, prerequisites);
    for (int& course : courses) 
        cout << course << " ";
    cout << endl;

    return 0;
}
