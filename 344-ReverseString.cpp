/*

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

*/

class Solution {
public:
    string reverseString(string s) {
        int i  = 0;
        int j = s.length()-1;
        while(i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        return s;
    }
};

class Solution1 {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }
};


class Solution2 {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

