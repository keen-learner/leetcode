/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/


// https://discuss.leetcode.com/topic/6183/my-concise-recursive-and-dp-solutions-with-full-explanation-in-c/2
// https://www.youtube.com/watch?v=l3hda49XcDE

class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        boolean[][] dp = new boolean[1+m][1+n];
        dp[0][0] = true;
        for(int j = 1; j <=n; j++) if(j-1>0 && p.charAt(j-1) == '*') dp[0][j] = dp[0][j-2]; 
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') dp[i+1][j+1] = dp[i][j];
                else if (p.charAt(j) == '*') {
                    dp[i+1][j+1] = dp[i+1][j-1] || 
                        (( p.charAt(j-1) == s.charAt(i) || p.charAt(j-1) == '.')  && dp[i][j+1]);
                }
                else dp[i+1][j+1] = false;
            }
        }
        return dp[m][n];
    }
}


