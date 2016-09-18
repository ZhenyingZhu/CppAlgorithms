/*
 * [Source] https://leetcode.com/problems/next-permutation/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Find the first number that is larger than its successor from end, swap it with the first number that is larger than it, and sort numbers after it.
// [Corner Case]: dup. last num
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/NextPermutation.java
 */

/* Java solution
public class Solution {
    public void nextPermutation(int[] num) {
        if(num == null || num.length <= 1) {
            return; 
        }
        int i, j; 
        for(i = num.length - 2; i >= 0; --i) {
            if(num[i] < num[i + 1]) {
                break; 
            }
        }
        if(i < 0) { // Alreay at the end. 
            Arrays.sort(num); 
            return; 
        }
        int key = num[i]; 
        for(j = num.length - 1; j >= 0; --j) {
            if(num[j] > key) {
                break; // At least i + 1 
            }
        }
        // swap
        num[i] = num[j]; 
        num[j] = key; 
        Arrays.sort(num, i + 1, num.length); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
