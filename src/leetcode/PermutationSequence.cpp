/*
 * [Source] https://leetcode.com/problems/permutation-sequence/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Use a vector indicate candidates. With n digits, if k/(2^(n-2)) = i, then add vec[i] to the begining
// [Corner Case]: only 1 number.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PermutationSequence.java
 */

/* Java solution
public class Solution {
    public String getPermutation(int n, int k) {
		if(k<=0) return null;
        int[] array=new int[n];
		int[] factorials=new int[n-1];
		for(int i=0; i<n; i++){
			array[i]=i+1;
		}
		int fac=1;
		for(int i=1; i<n; i++){
			fac*=i;
			factorials[i-1]=fac;
		}
		StringBuffer prev=new StringBuffer();
		getPermutation(k-1, array, array.length-1, factorials, prev);
		return prev.toString();
    }
	
	public void getPermutation(int k, int[] array, int last, int[] factorials, StringBuffer prev){
		if(last==0){
			prev.append(array[0]);
			return;
		}
		int mul=k/factorials[last-1];
		int mod=k%factorials[last-1];
		prev.append(array[mul]);
		for(int i=mul; i<last; i++){
			array[i]=array[i+1];
		}
		getPermutation(mod, array, last-1, factorials, prev);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
