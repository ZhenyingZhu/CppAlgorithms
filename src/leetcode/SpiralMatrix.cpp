/*
 * [Source] https://leetcode.com/problems/spiral-matrix/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Mark the visited cells. If touch a marked cell or board, turn right. Use a direction vector to indicate which direction.
class Solution {
};

/* Java solution
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> result=new ArrayList<Integer>();
        if(matrix==null || matrix.length<=0 || matrix[0].length<=0) return result;
		int m=matrix.length;
		int n=matrix[0].length;
		int total=m*n;
		int[] xDir={0, 1, 0, -1};
		int[] yDir={1, 0, -1, 0};
		int pt=0;
		int i=0;
		int x=0; 
		int y=-1;
		while(i<total){
			for(int a=0; a<n; a++){
				x+=xDir[pt];
				y+=yDir[pt];
				result.add(matrix[x][y]);
				i++;
			}
			pt++;
			if(pt==4) pt=0;
			n--;
			m--;
			for(int b=0; b<m; b++){
				x+=xDir[pt];
				y+=yDir[pt];
				result.add(matrix[x][y]);
				i++;
			}
			pt++;
			if(pt==4) pt=0;
		}
		return result;
    }
}
 */

// [Solution]: Use the ith row as offset. To avoid go back, need be careful about the middle.
// [Corner Case]: middle is a line. middle is a square. middle is a dot.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SpiralMatrix.java
 */

// [Solution]: recursive call with left top and right end corrdinate.

int main() {
    Solution sol;

    return 0;
}
