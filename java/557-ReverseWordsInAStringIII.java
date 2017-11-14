/*

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

class Solution {
    public String reverseWords(String ss) {
        char[] s = ss.toCharArray();
        for(int i = 0; i<s.length; i++) {
            if(s[i] != ' ') { // found char
                int j = i;
                while(j<s.length && s[j] != ' ') j++;
                reverse(s, i, j);
                i = j;
            }
        }
        return new String(s);      
    }
    
    private void reverse(char[] s, int i, int j) {
        --j;
        while(i<j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            --j;
        }
    }
}
