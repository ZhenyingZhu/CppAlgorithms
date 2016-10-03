/*
 * [Source] https://leetcode.com/problems/balanced-binary-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Count the height of left and right subtree, and compare.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BalancedBinaryTree.java
 */

/* Java solution
public class Solution {
    public boolean isBalanced(TreeNode root) {
		int height=comHeight(root);
		if(height==-1) return false;
		return true;
    }
	
	public int comHeight(TreeNode root){
		if(root==null) return 0;
		int lDepth=comHeight(root.left);
		int rDepth=comHeight(root.right);
		if(lDepth==-1 || rDepth==-1) return -1;
		if(Math.abs(lDepth-rDepth)>1){
			return -1;
		}
		return Math.max(lDepth+1, rDepth+1);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
