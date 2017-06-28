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
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        
        dp[0][0] = true; // coz empty pattern and string match
        // NOTE: 0th column is set to false
        // We now set 0th row starting from column# 1 ([0][0] is true)
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty   
        // think string = '', pattern = 'a*b*'
        for (int j = 1; j <= p.size(); j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        
        for (int i = 1; i < dp.size(); i++)
            for (int j = 1; j < dp[0].size(); j++)
                if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                else if (p[j-1]=='*') 
                    dp[i][j] = dp[i][j-2] /*0 occurence of pattern char*/ || 
                    ( (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]);
                    /*check if previous char matches or is '.', then (i,j) = (i-1,j)*/
                else dp[i][j] = false;
    
        
        return dp[s.size()][p.size()];
    }
};


class Solution2 {
public:
    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true;
        // for (int i = 1; i <= m; i++)
        //     f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
        
        return f[m][n];
    }
};

