/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m<=0 && n<=0) return 0;

        vector<int> dp(n, 0);
        for(int j = 0; j < n && obstacleGrid[0][j] != 1; j++) dp[j] = 1;
        
        for(int i = 1; i<m; i++) {
            for(int j =0; j<n; j++) {
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else {
                    dp[j] = (j-1 >= 0 ? dp[j-1]:0) + dp[j];   
                }
            }
        }
        return dp[n-1];       
    }
};

class Solution1 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m<=0 && n<=0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j < n && obstacleGrid[0][j] != 1; j++) dp[0][j] = 1;
        for(int i = 0; i < m && obstacleGrid[i][0] != 1; i++) dp[i][0] = 1;
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];   
                }
            }
        }
        return dp[m-1][n-1];        
    }
};
