/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to 
reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 && n<=0) return 0;
        vector<int> dp(n, 1);
        
        for(int i = 1; i<m; i++) {
            for(int j =1; j<n; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

class Solution0 {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 && n<=0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j<n; j++) dp[0][j] = 1;
        for(int i = 0; i<m; i++) dp[i][0] = 1;
        
        for(int i = 1; i<m; i++) {
            for(int j =1; j<n; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

// https://discuss.leetcode.com/category/70/unique-paths
// https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations/2
// https://discuss.leetcode.com/topic/19613/math-solution-o-1-space

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        return nCr (m + n - 2, min(m, n) - 1);
    }
private:
    int nCr (int n, int r) {
        long long_result = 1;
        for (int i = 0; i != r; ++i) {
            // from n - r + 1 (when i = 0) to n (when i = r - 1)
            long_result *= (n - r + 1 + i);
            // from 1 (when i = 0)         to r (when i = r - 1)
            long_result /= (i + 1);
        }
        return (int) long_result;
    }
};

// DP SOLUTIONS :
class Solution2 {
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};

class Solution3 {
    public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(n, 1);
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) 
                cur[j] = cur[j - 1] + pre[j];
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};

class Solution4 {
    public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                cur[j] += cur[j - 1]; 
        return cur[n - 1];
    }
}; 

