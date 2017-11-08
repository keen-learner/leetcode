/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/


class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        int l = 0, r = n-1;
        int t = 0, b = n-1;
        int num = 0;
        
        while(l<=r && t<=b) {
            for(int j = l; j<=r; j++) matrix[t][j] = ++num;
            for(int i = t+1; i<=b; i++) matrix[i][r] = ++num;
            for(int j = r-1; t!=b&&j>=l; j--) matrix[b][j] = ++num;
            for(int i = b-1; l!=r && i>t; i--) matrix[i][l] = ++num;
            ++t;
            --b;
            ++l;
            --r;
        }
        return matrix;
        
    }
}
