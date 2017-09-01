/*

Given a non-empty string s and a dictionary wordDict containing a list 
of non-empty words, determine if s can be segmented into a 
space-separated sequence of one or more dictionary words. You may 
assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead 
of a set of strings). Please reload the code definition to get the latest changes.

*/

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1];
        Arrays.fill(dp, false);
        dp[0] = true; //dp[i] - means if [0,i-1] substring can be word break or not
        Set<String> dict = new HashSet(wordDict); //if wordDict is null, then exception
        for(int i = 0; i < s.length(); i++) { 
            for(int j = i; j >= 0; j--) {
                if(dp[j] == true) {
                    String temp = s.substring(j, i+1); //[j, i] substring
                    if(dict.contains(temp)) {
                        dp[i+1] = true;
                    }
                }
            }
        }
        
        return dp[s.length()];
    }
}
