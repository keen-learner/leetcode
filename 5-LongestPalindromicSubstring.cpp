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
public:
    string longestPalindrome(string s) {
        int res = 0;
        int start = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int low = i;
            int high = i;
            while(low >= 0 && high < n && s[low] == s[high] ) { // odd palindrome
                if (high-low+1 > res) {
                    res = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }
            low = i;
            high = i+1;
            while(low >= 0 && high < n && s[low] == s[high] ) { // even palindrome
                if (high-low+1 > res) {
                    res = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }
        }
        string out = "";
        for(int i = start; i < start + res; i++) out.push_back(s[i]);
        return out;
        
    }
};

// Time O(n^2)
class Solution1 {
public:
    string longestPalindrome(string s) {
        int res = 1;
        int start = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int low = i-1;
            int high = i;
            while(low >= 0 && high < n && s[low] == s[high] ) { // even palindrome
                if (high-low+1 > res) {
                    res = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }
            low = i-1;
            high = i+1;
            while(low >= 0 && high < n && s[low] == s[high] ) { // odd palindrome
                if (high-low+1 > res) {
                    res = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }
        }
        string out = "";
        for(int i = start; i < start + res; i++) out.push_back(s[i]);
        return out;
        
    }
};
