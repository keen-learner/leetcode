/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

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

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n;
        while(l < r) {
            int m = l + (r-l)/2;
            if(matrix[m/n][m%n] >= target) r = m;
            else l = m+1;
        }
        return l < m*n && matrix[l/n][l%n] == target;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return false;
        const int n = matrix[0].size();
        if (n == 0) {
            return false;
        }

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } 
            else if (matrix[i][j] > target) {
                --j;
            } 
            else {
                ++i;
            }
        }

        return false;
    }
};
