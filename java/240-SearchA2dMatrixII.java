/*

Write an efficient algorithm that searches for a value in 
an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

*/


// O(m + n)
public class Solution {
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
