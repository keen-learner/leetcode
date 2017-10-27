/*


Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix == null || matrix.length==0 ) return 0;
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        for(int[] r: dp) Arrays.fill(r, 0);
        int res = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(dp[i][j] == 0) {
                    dfs(matrix, dp, i, j);
                    res = Math.max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
    
    private void dfs(int[][] matrix, int[][] dp, int i, int j){
        if(dp[i][j] !=0) return ;
        int a = 0; int b = 0; int c = 0; int d = 0;
        // go left
        if(i-1>=0 && matrix[i-1][j] < matrix[i][j]) {dfs(matrix, dp, i-1, j); a= dp[i-1][j]; }
    
        // go right
        if(i+1<matrix.length && matrix[i+1][j] < matrix[i][j]) {dfs(matrix, dp, i+1, j); b = dp[i+1][j]; } 
    
        // go top 
        if(j-1>=0 && matrix[i][j-1] < matrix[i][j]) { dfs(matrix, dp, i, j-1); c = dp[i][j-1];}
    
        // go bottom
        if(j+1<matrix[0].length && matrix[i][j+1] < matrix[i][j]) { dfs(matrix, dp, i, j+1); d = dp[i][j+1];}
        dp[i][j] = 1+ Math.max(a, Math.max(b, Math.max(c,d)));
        
    }
}
