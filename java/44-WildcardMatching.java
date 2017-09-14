/*

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

*/

// https://discuss.leetcode.com/category/52/wildcard-matching
// https://discuss.leetcode.com/topic/21577/my-three-c-solutions-iterative-16ms-dp-180ms-modified-recursion-88ms
// https://discuss.leetcode.com/topic/7266/c-dp-solution
// https://discuss.leetcode.com/topic/17901/accepted-c-dp-solution-with-a-trick
// https://www.youtube.com/watch?v=3ZDZ-N0EPV0

class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        boolean[][] dp = new boolean[1+m][1+n];
        dp[0][0] = true;
        for(int j = 1; j<=n; j++) {
            if(p.charAt(j-1) == '*') dp[0][j] = true;
            else break;
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') dp[i+1][j+1] = dp[i][j];
                else if(p.charAt(j) == '*') {
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                }
                // else dp[i+1][j+1] = false /*Not Required; default is false*/
            }
        }
        return dp[m][n];
    }
}
