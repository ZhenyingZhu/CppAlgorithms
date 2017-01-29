/*
 * [Source] https://leetcode.com/problems/find-mode-in-binary-tree/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Mode is the number that shows most often than other numbers
// [Corner Case]:
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> nodeCnt;
        traverse(root, nodeCnt);

        int maxCnt = 0;
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); ++it) {
             maxCnt = max(maxCnt, it->second);
        }

        vector<int> res;
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); ++it) {
            if (it->second == maxCnt)
                res.push_back(it->first);
        }
        return res;
    }

    void traverse(TreeNode *node, unordered_map<int, int> &nodeCnt) {
        if (node == NULL)
            return;

        ++nodeCnt[node->val];
        traverse(node->left, nodeCnt);
        traverse(node->right, nodeCnt);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
