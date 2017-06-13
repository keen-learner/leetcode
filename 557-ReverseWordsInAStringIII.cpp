/*

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

class Solution {
public:
    string reverseWords(string s) {
       auto i = 0;
       for (auto j = 0; j <= s.size(); ++j) { // NOTE: j <= s.size()
           if(s[j] == ' ' || j == s.size()) {
                reverse(s.begin() + i, s.begin() + j);
                i = j+1;
           }
       }
       return s;
    }
};

