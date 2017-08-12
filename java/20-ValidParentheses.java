/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" 
are all valid but "(]" and "([)]" are not.

*/

public class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> m = new HashMap<>();
        m.put(')','(');
        m.put('}','{');
        m.put(']','[');
        Stack<Character> st = new Stack<>();
        for(char c : s.toCharArray()) {
            if(m.containsKey(c)) { //closing paren
                if(st.empty() || st.peek() != m.get(c)) return false;
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
}
