/*

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

class Solution {
    public int countSubstrings(String s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i;
            while(l>=0 && r < s.length() && s.charAt(l) == s.charAt(r)) { //odd length
                --l;
                ++r;
                ++count;
            }
            l = i;
            r = i+1;
            while(l>=0 && r < s.length() && s.charAt(l) == s.charAt(r)) { //even length
                --l;
                ++r;
                ++count;
            }
        }
        return count;
    }
}
