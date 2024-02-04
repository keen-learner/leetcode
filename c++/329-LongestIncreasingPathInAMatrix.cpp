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

class Solution1{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0)); // dp[i][j] : max path that ends here
        int res = 0;
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[i].size(); j++) {
                if(dp[i][j] == 0) {
                    res = max(res, dfs(matrix, dp, i, j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int t = 0;
        for(vector<int>dir : dirs) {
            int x = i+dir[0];
            int y = j + dir[1];
            if(x>=0 && x < matrix.size() && y >= 0 && y< matrix[0].size() 
               && matrix[x][y]<matrix[i][j] ) {
                t = max(t, dfs(matrix, dp, x, y));
            }
        }
        dp[i][j] = 1 + t;
        return dp[i][j];
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0)); // dp[i][j] : max path that ends here
        int res = 0;
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[i].size(); j++) {
                if(dp[i][j] == 0) {
                    res = max(res, dfs(matrix, dp, i, j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        int a = 0; int b = 0; int c = 0; int d = 0;
        // go left
        if(i-1>=0 && matrix[i-1][j] < matrix[i][j]) a = dfs(matrix, dp, i-1, j);
        
        // go right
        if(i+1<matrix.size() && matrix[i+1][j] < matrix[i][j]) b = dfs(matrix, dp, i+1, j);
        
        // go top 
        if(j-1>=0 && matrix[i][j-1] < matrix[i][j]) c = dfs(matrix, dp, i, j-1);
        
        // go bottom
        if(j+1<matrix[0].size() && matrix[i][j+1] < matrix[i][j]) d = dfs(matrix, dp, i, j+1);
        dp[i][j] = 1+ max(a, max(b, max(c,d)));
        return dp[i][j];
    }
};
