/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (!is_vowel(tolower(s[i]))) {
                ++i;
            } else if (!is_vowel(tolower(s[j]))) {
                --j;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

private:
    const string vowels_ = "aeiou";
    bool is_vowel(char a){
        return vowels_.find(a) != string::npos;
    }
};


class Solution2 {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        if (j < 0) return "";
        int first = -1, last = j+1;
        while(i < j) {
            if( isVowel( tolower(s[i]) ) ) first = i;
            if( isVowel( tolower(s[j]) ) ) last = j;
            //if( isVowel(s[i]) ) first = i;
            //if( isVowel(s[j]) ) last = j;
            if(first != -1 && last != s.size() ) {swap(s[first], s[last]); first = -1; last = s.size();}
            if(first == -1)++i; 
            if(last == s.size())--j;
        }
        return s;
    }
private :
    bool isVowel(const char& c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
};
