/*

Given a non-empty string s and a dictionary wordDict containing a 
list of non-empty words, determine if s can be segmented into a 
space-separated sequence of one or more dictionary words. You may 
assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i] = s[i-1] is a word sequence
        vector<bool> dp(s.size()+1, false);
        set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i < dp.size(); i++) {
            for(int j = i-1; j >= 0; j--) {
                if(dp[j]) {
                    string w = s.substr(j, (i-1) - j + 1); //j to i-1
                    if(dict.find(w) != dict.end()) dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
