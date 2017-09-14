/*

Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for(int j = 1; j<n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++) {
            vector<int> temp(dp);
            for(int j = 0; j<n; j++) {
                dp[j] = min(temp[j], j-1>=0?dp[j-1]:INT_MAX) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};
