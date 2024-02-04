/*


Given a string containing only three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. 
We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.

An empty string is also valid.
Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*/

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (char c : s) {
            if (c=='(') {
                lower++;
                upper++;
            } else if (c==')') {
                lower--;               
                upper--;
            } else { // * encountered
                lower--;
                upper++;
            }
            lower = max(lower, 0);
            if (upper<0) // unmatched ')' found in the middle of string
                return false;
        }
        return lower==0;
    }
};

class Solution1 {
public:
    bool checkValidString(string s) {
        return helper(s, 0, 0);
    }
private:
    bool helper(string& s, int st, int count) {
        if(count < 0) return false;
        for(int i= st; i<s.size(); i++) {
            if(s[i] == '(') count++;
            else if(s[i] == ')') {
                count--;
                if(count<0) return false;
            }
            else { // '*'
                return helper(s, i+1, count+1) || helper(s, i+1, count-1) || helper(s, i+1, count);
            }
        }
        return count==0;
    }
};

