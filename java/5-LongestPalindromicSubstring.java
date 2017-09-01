/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

*/

// Time O(n^2)
class Solution {
    public String longestPalindrome(String s) {
        int begin = 0;
        int end = 0;
        for(int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i;
            while(l>=0 && r < s.length() && s.charAt(l) == s.charAt(r)) { //odd length
                if(r-l+1 > end - begin + 1) {
                    begin = l;
                    end = r;
                }
                --l;
                ++r;
            }   
            l = i;
            r = i+1;
            while(l>=0 && r < s.length() && s.charAt(l) == s.charAt(r)) { //even length
                if(r-l+1 > end - begin + 1) {
                    begin = l;
                    end = r;
                }
                --l;
                ++r;
            }   
        }   
        return s.substring(begin, end + 1);      
    }
}
