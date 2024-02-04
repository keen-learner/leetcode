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

// Greedy Solution
class Solution3 {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0;
        int ss=-1, pp =-1;
        while(si<s.size()) {
            if(si<s.size() && pi<p.size() && (s[si]==p[pi] || p[pi]=='?')){si++; pi++;}
            else if(si<s.size() && pi<p.size() && p[pi]=='*'){ss=si; pp=pi++;}
            else if(pp!=-1 && pp <p.size()){si =ss++; pi=pp +1;}
            else return false;
        }
        while (pi<p.size() && p[pi]=='*'){pi++;}
        return pi==p.size();
    }
};

// Greedy Solution
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
// GREEDY SOLUTION
class Solution1 {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j) {
            if(p[j]=='*') { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else if(p[j]!=s[i] && p[j]!='?') {  // mismatch happens
                    if(iStar >=0) { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};

// DP solution
// Note: we have not used 2d array
class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        // if (n > 30000) return false;
        vector<bool> cur(m + 1, false);
        cur[0] = true;
        for (int j = 1; j <= n; ++ j) {
            if (p[j-1] == '*')
                cur[j] = true;
            else
                break; // if current is not '*', will not match onwards
        }
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*';
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};

// DP solution with 2D array
class Solution0 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1)); // default to all false
        
        // initialize first column and row
        dp[0][0] = true; // s and p are both ""
        for (int j = 1; j <= n; ++ j) {
            if (p[j-1] == '*')
                dp[0][j] = true;
            else
                break; // if current is not '*', will not match onwards
        }
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') // if current char match
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                // else, no match, leave as false
            }
        }
        
        return dp[m][n];
    }   
};
