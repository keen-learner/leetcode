/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if(matrix.length==0) return res;

        int l = 0, r = matrix[0].length-1;
        int t = 0, b = matrix.length-1;
        
        while(l<=r && t<=b) {
            for(int j = l; j<=r; j++) res.add(matrix[t][j]);
            for(int i = t+1; i<=b; i++) res.add(matrix[i][r]);
            for(int j = r-1; t!=b&&j>=l; j--) res.add(matrix[b][j]);
            for(int i = b-1; l!=r && i>t; i--) res.add(matrix[i][l]);
            ++t;
            --b;
            ++l;
            --r;
        }
        return res;
    }
}
