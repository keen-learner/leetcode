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

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 0) return 0;
        map<char, int> m;
        for(int i = 0; i < s.size(); i++) ++m[s[i]];
        int res = 0;
        bool odd = false;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second % 2 == 0) res += it->second;
            else if(it->second > 0) {
                res += it->second -1;
                odd = true;
            }
        }
        if(odd) return res + 1;
        return res;
    }
};
