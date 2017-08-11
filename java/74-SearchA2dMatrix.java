/*

Write an efficient algorithm that searches for a value in an m x n 
matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

// O (log(m+n)) m - #rows, n - #cols
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        final int ro = matrix.length;
        if (ro == 0) return false;
        final int c = matrix[0].length;
        if (c == 0) return false;
        int l = 0;
        int r =  ro*c-1;
        while(l<=r) {
            int m = (l+r)/2;
            int k = matrix[m/c][m%c];
            if (target == k) return true;
            else if (target > k) {
                l = m+1;
            }
            else {
                r = m-1;;
            }
        }
        return false;
    }
}

// O(m + n)
class Solution1 {
    public boolean searchMatrix(int[][] matrix, int target) {
        final int r = matrix.length;
        if (r == 0) return false;
        final int c = matrix[0].length;
        if (c == 0) return false;
        int i = 0;
        int j =  c-1;
        while(i < r && j >= 0) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) {
                i++;
            }
            else {
                --j;
            }
        }
        return false;
    }
}
