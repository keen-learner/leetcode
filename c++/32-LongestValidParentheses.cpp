/*

Given a string containing just the characters '(' and ')', find the length of the longest 
valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        // stk.push(-1);
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') stk.push(i);
            else { // ')' case
                if(stk.empty() || s[stk.top()] != '(' ) stk.push(i);
                else stk.pop();
            }
        }
        if(stk.empty()) return s.size();
        int a = s.size(), b = 0;
        while(!stk.empty()) {
            b = stk.top();
            stk.pop();
            res = max(res, (a-1) - (b+1) + 1); //[b+1, a-1] is valid range
            a = b;
        }
        res = max(res, (a-1) - 0 + 1); // check [0, a-1] valid range
        return res;
    }
};

class Solution1 {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            int t = stk.top();
            if(t!=-1 && s[i] == ')' && s[t] == '(') {
                stk.pop();
                res = max(res,i - stk.top());
            }
            else stk.push(i);
        }
        return res;
    }
};
