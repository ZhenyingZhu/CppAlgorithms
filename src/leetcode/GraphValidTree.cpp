/*
 * [Source] https://leetcode.com/problems/graph-valid-tree/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Graph
 * [Tag]: Union Find
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

// [Solution]: Use level. If two nodes are each neighbors, if there level different by 1, they are parent-child. Otherwise there is a cycle.
// [Corner Case]: Extra nodes that not connect to the graph
class Solution {
public:
    struct NodeLevel {
        int id, level;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.empty())
            return n == 1;

        unordered_map<int, unordered_set<int>> graph;
        for (pair<int, int> &edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }

        unordered_map<int, int> visited;
        stack<NodeLevel> visiting;
        visiting.push({graph.begin()->first, 0});
        while (!visiting.empty()) {
            NodeLevel node = visiting.top();
            visiting.pop();
            visited[node.id] = node.level;

            unordered_set<int> &neighbors = graph[node.id];
            for (auto neighborIt = neighbors.begin(); neighborIt != neighbors.end(); ++neighborIt) {
                if (visited.count(*neighborIt)) {
                    if (visited[*neighborIt] != node.level - 1)
                       return false;
                } else {
                    visiting.push({*neighborIt, node.level + 1});
                }
            }
        }
        return (int)visited.size() == n;
    }
};

int main() {
    Solution sol;

    //vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    //vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    //vector<pair<int, int>> edges = {{0, 1}, {1, 3}, {3, 4}};
    vector<pair<int, int>> edges = {};
    cout << sol.validTree(1, edges) << endl;

    return 0;
}
