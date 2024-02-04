/*

Given a string s, partition s such that every substring of 
the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0) return {};
        vector<vector<string>> res;
        vector<string> curr;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j <= i; j++) {
                if(s[i] == s[j] && (i - j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
            }
        }
        helper(res, s, 0, curr, dp);
        return res;
    }
    
private:    
    void helper(vector<vector<string>>& res, string& s, int st, vector<string>& curr, vector<vector<bool>>& dp) {
        if(st == s.size()) {
            res.push_back(curr);
            // curr.clear();
            return;
        }
        for(int i = st; i<s.size(); i++) {
            if(dp[st][i]){ // [st, i] substring
                curr.push_back(s.substr(st, i-st+1));
                helper(res, s, i+1, curr, dp);
                curr.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0) return {};
        vector<vector<string>> res;
        vector<string> curr;
        helper(res, s, 0, curr);
        return res;
    }
    
private:    
    void helper(vector<vector<string>>& res, string& s, int st, vector<string>& curr) {
        if(st == s.size()) {
            res.push_back(curr);
            // curr.clear();
            return;
        }
        for(int i = st; i<s.size(); i++) {
            if(isPalindrome(s, st, i)){ // [st, i] substring
                curr.push_back(s.substr(st, i-st+1));
                helper(res, s, i+1, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

class Solution1 {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    vector<vector<vector<string>>> answers(s.size() + 1);
    answers[0] = vector<vector<string>>(1, vector<string>());
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) {
          dp[j][i] = true;
          for (auto arr : answers[j]) {
            arr.push_back(s.substr(j, i - j + 1));
            answers[i + 1].push_back(arr);
          }
        }
      }
    }
    return answers[s.size()];
  }
};
