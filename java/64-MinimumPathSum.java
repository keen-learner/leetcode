/*

Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

// DP
// Time: O(mn) Space: O(mn)  
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid == null) return 0;
        int m = grid.length;
        int n = grid[0].length;
        int[] dp = new int[n];
        dp[0] = grid[0][0];

        for(int j =1 ; j<n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }

        for(int i = 1; i < m; i++) {
            int[] temp = Arrays.copyOf(dp, n);
            for(int j = 0; j<n; j++) {
                dp[j] = grid[i][j] + Math.min(temp[j], j-1>=0?dp[j-1]:Integer.MAX_VALUE);
            }
        }
        return dp[n-1];
    }
}

// DP
// Time: O(mn) Space: O(mn)  
class Solution1 {
    public int minPathSum(int[][] grid) {
        if(grid == null) return 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        // dp[0][0] = 0;
        for(int j =1 ; j<n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i = 1 ; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j<n; j++) {
                dp[i][j] = grid[i][j] + Math.min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
}
