/*

Given a string s consists of upper/lower-case alphabets and empty space 
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 && s.charAt(i)==' ') i--;
        if(i == -1) return 0;
        int j = i; //j end of last word
        while(i >=0 && s.charAt(i)!= ' ') i--;
        return j - i;
    }
}

class Solution1 {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int lastIndex = s.lastIndexOf(' ') + 1;
        return s.length() - lastIndex;  
    }
}

