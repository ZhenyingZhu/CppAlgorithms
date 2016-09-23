/*
 * [Source] https://leetcode.com/problems/maximum-subarray/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 * [Tag]: Divide and Conquer
 */

#include <iostream>

using namespace std;

// [Solution]: Keep add to sum. If smaller than 0, reset sum to be 0.
// [Corner Case]: If all cells are negative. If first cell is negative.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/MaximumSubarray.java
 */

// [Solution]: Divide to two parts. 
/* Java solution
public class Solution {
    public int maxSubArray(int[] A) {
	// Divide and conquer, worse than the interative method. 
		return maxSubArray(A, 0, A.length-1);
    }

	public int maxSubArray(int[] A, int st, int ed){
		if(st==ed) return A[st];
		int md=(st+ed)/2;
		int leftSum=0;
		int sum=0;
		for(int i=md-1; i>=st; i--){
			sum+=A[i];
			if(sum>leftSum) leftSum=sum;
		}
		int rightSum=0;
		sum=0;
		for(int i=md+1; i<=ed; i++){
			sum+=A[i];
			if(sum>rightSum) rightSum=sum;
		}
		int midCross=leftSum+A[md]+rightSum;
		int notCross=Math.max(maxSubArray(A, st, md),maxSubArray(A, md+1, ed));
		return Math.max(midCross, notCross);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
