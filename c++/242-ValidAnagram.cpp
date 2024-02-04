/*

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

// http://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/

// Time:  O(n)
// Space: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> count;
        for(int i = 0; i<s.size(); i++) {
            ++count[s[i]];
            --count[t[i]];
        }
        auto it = count.begin();
        while(it != count.end()) {
            if(it->second != 0) return false;
            ++it;
        }

        return true;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};
