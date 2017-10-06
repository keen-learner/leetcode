/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square 
containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mm) {
        if(mm.size()==0 || mm[0].size() == 0) return 0;
        int m = mm.size();
        int n = mm[0].size();
        vector<int> dp(n, 0);
        int res = 0;
       
        for(int j = 0; j < n; j++) { // 0th row
            dp[j] = mm[0][j]-'0';
            res = max(res, dp[j]);
        }

        for(int i = 1; i < m; i++) {
            vector<int> t = dp;
            for(int j = 0; j < n; j++) {
                if(mm[i][j] == '1'){
                    dp[j] = 1 + min(t[j-1], min(t[j], j-1>=0?dp[j-1]:0));
                    res = max(res, dp[j]);    
                }
                else dp[j] = 0;
            }
        }
        
        return res*res;
    }
};

class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& mm) {
        if(mm.size()==0 || mm[0].size() == 0) return 0;
        int m = mm.size();
        int n = mm[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; i++) { // 0th column
            dp[i][0] = mm[i][0]-'0';
            res = max(res, dp[i][0]);
        }
        for(int j = 0; j < n; j++) { // 0th row
            dp[0][j] = mm[0][j]-'0';
            res = max(res, dp[0][j]);
        }

        for(int i = 1; i < m; i++) { 
            for(int j = 1; j < n; j++) {
                if(mm[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    res = max(res, dp[i][j]);    
                }
                else dp[i][j] = 0;
            }
        }
        
        return res*res;
    }
};
