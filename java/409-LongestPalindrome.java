/*

Given a string which consists of lowercase or uppercase letters, find the 
length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/


public class Solution {
    public int longestPalindrome(String s) {
        if(s.length() == 0) return 0;
        int[] l = new int[26];
        int[] u = new int[26];
        for(char c : s.toCharArray() ) {
            if( c >='a' && c <= 'z' ) { //lower case
                l[c-'a'] += 1;
            }
            else { //upper case
                u[c-'A'] += 1;
            }
        }
        int res = 0;
        boolean odd = false; 
        for(int i = 0; i < 26; i++ ) {
            if(l[i] % 2 == 0) res += l[i];
            else if(l[i] > 0 ) { // odd char and count atleast 1
                odd = true;
                res += l[i] - 1;
            }
            if(u[i] % 2 == 0) res += u[i];
            else if(u[i] > 0 ) { // odd char and count atleast 1
                odd = true;
                res += u[i] - 1;
            }
        }
        if(odd) res += 1;
        return res;
    }
}
