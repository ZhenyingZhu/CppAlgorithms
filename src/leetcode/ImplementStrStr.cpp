/*
 * [Source] https://leetcode.com/problems/implement-strstr/
 * [Difficulty]: Easy
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Two level for loop
// [Corner Case]: the pattern is longer than search string
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ImplementStrStr.java
 */

/* Java solution
public class Solution {
    public String strStr(String haystack, String needle) {
        if(haystack == null || needle == null || needle.length() == 0) {
            return haystack; 
        }
        if(haystack.length() < needle.length()) {
            return null; 
        }
        int j; 
        for(int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if(haystack.charAt(i) == needle.charAt(0)) {
                for(j = 1; j < needle.length(); ++j) {
                    if(haystack.charAt(i + j) != needle.charAt(j)) {
                        break; 
                    }
                }
                if(j == needle.length()) {
                    return haystack.substring(i); 
                }
            }
        }
        return null; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
