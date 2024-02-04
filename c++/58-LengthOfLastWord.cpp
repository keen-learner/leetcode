/*

Given a string s consists of upper/lower-case alphabets and empty space 
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

class Solution1 {
public:
    int lengthOfLastWord(string s) {
        const auto is_space = [](const char c) { return isspace(c); };
        const auto it = find_if_not(s.rbegin(), s.rend(), is_space);
        const auto jt = find_if(it, s.rend(), is_space);
        return distance(it, jt);
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        
        for(i = s.size()-1; i>=0 && s[i] == ' '; --i);
        if(i == -1) return 0;
        // i non space
        int j = i;
        while(i>=0) {
            --i;
            if(s[i] == ' ') break;
        }
        // if(i == -1) return s.size();
        ++i;
        return j -i +1;
    }
};


