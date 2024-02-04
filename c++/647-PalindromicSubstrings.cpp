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
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int low = i;
            int high = i;
            while(low >= 0 && high < n && s[low] == s[high] ) { // odd palindrome
                ++count;
                --low;
                ++high;
            }
            low = i;
            high = i+1;
            while(low >= 0 && high < n && s[low] == s[high] ) { // even palindrome
                ++count;
                --low;
                ++high;
            }            
        }
        return count;
    }
};
