#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: http://www.meetqun.net/thread-43863-1-1.html
class Solution {
public:
    vector<vector<int>> findTriangle(vector<int> &edges) {
        if (edges.size() <= 2)
            return {};

        vector<vector<int>> res;
        sort(edges.begin(), edges.end());
        int len = edges.size();
        for (int i = 0; i < len - 2; ++i) {
            for (int j = i + 1; j < len - 1; ++j) {
                int k = j + 1;
                while (k < len && edges[k] < edges[i] + edges[j]) {
                    res.push_back( {edges[i], edges[j], edges[k]} );
                    ++k;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> edges = {3, 4, 5, 6, 7};
    for (vector<int> &vec : sol.findTriangle(edges)) {
        for (int &edge : vec)
            cout << edge << " ";
        cout << endl;
    }
    return 0;
}
