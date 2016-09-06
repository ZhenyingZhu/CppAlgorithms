/*
 * [Source] https://leetcode.com/problems/reverse-integer/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Convert to string, reverse it, and then reverse back.
// [Corner Case]: The sign; The origin number is not overflow but the converted one can; Origin number is 100;
class Solution {
};

// [Solution]: mode the origin number by 10, and multiple the result by 10 and add that mode result. If the result the origin number are different sign, then it is overflow.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/ReverseInteger.java
 */

/* Java solution
public class Solution {
    public int reverse(int x) {
        int num = x; 
        int res = 0; 
        while (num != 0) { // Deal with the negative situation
            res = res * 10 + num % 10; 
            num /= 10; 
        }
        return (x ^ res) >>> 31 == 1 ? -1 : res; // Not necessary
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
