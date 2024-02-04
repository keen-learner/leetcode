/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/

class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stringstream ss(path);
        stack<string> stk;
        while(getline(ss, s, '/')) {
            if(s == "." || s == "") continue;
            else if (s == ".." && !stk.empty()) stk.pop();
            else if(s != ".." ) stk.push(s);
        }
        if(stk.empty()) return "/";
        string res = "";
        while(!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res;
    }
};
