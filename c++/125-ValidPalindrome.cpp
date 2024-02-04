/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } 
            else if (!isalnum(s[j])) {
                --j;
            } 
            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } 
            else {
                ++i, --j;
            }
        }
        return true;
    }
};

// Time:  O(n)
// Space: O(1)
// Iterator solution.
class Solution2 {
public:    
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = prev(s.end());
        //auto right = s.end(); --right;
        while (left < right) { 
            if (!isalnum(*left)) {
                ++left;
            } 
            else if (!isalnum(*right)) {
                --right; 
            } 
            else if (tolower(*left) != tolower(*right)) {
                return false;
            } 
            else {
                ++left, --right;
            }
        }
        return true;
    }
};
