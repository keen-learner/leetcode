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
    public String simplifyPath(String path) {
        Stack<String> stk = new Stack<String>();
        for(String s: path.split("/")) {
            if(s.equals(".") || s.equals("")) continue;
            else if (s.equals("..") && !stk.isEmpty()) stk.pop();
            else if(!s.equals("..")) stk.push(s);
        }
        if(stk.isEmpty()) return "/";
        String res = "";
        while(!stk.isEmpty()) {
            res = "/" + stk.peek() + res;
            stk.pop();
        }
        return res;        
    }
}
