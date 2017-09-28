/*


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        helper(res, curr, n, n);
        return res;
    }
    void helper(vector<string>& res, string& curr, int remOpenCnt, int remCloseCnt) {
        if(remOpenCnt == 0 && remCloseCnt == 0) {res.push_back(curr); return;}
        if(remOpenCnt < 0 || remCloseCnt < 0 || remCloseCnt < remOpenCnt) return;
        curr.push_back('(');
        helper(res, curr, remOpenCnt-1, remCloseCnt);
        curr.pop_back();
        curr.push_back(')');
        helper(res, curr, remOpenCnt, remCloseCnt-1);
        curr.pop_back();
    }
};
