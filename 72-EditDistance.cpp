/*
// http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

// DP solution
class Solution {
public:
    int minDistance(string s1, string s2) {
        const auto m = s1.size();
        const auto n = s2.size();
        vector<vector<int>> dp (m+1, vector<int>(n+1));
        for(int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j<= n; ++j) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min (min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};


// recursive solution
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        const auto m = word1.size();
        const auto n = word2.size();
        if(m == 0) return n;
        else if (n == 0) return m;
        return helper(word1, m, word2, n);
    }
    
    int helper(string s1, int m, string s2, int n) {
        if(m == 0) return n;
        else if (n == 0) return m;
        if(s1[m-1] == s2[n-1]) return helper(s1, m-1, s2, n-1);
        
        return 1 + min(helper(s1, m-1, s2, n-1), min(helper(s1, m-1, s2, n), helper(s1, m, s2, n-1)));
    }
};


