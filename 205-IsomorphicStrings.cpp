/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character 
while preserving the order of characters. No two characters may map to 
the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/

/*
check last position of curr character; 
should be same for both the strings
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> m1(256, -1);
        vector<int> m2(256, -1);
        for(int i = 0; i < s.size(); i++) {
            // cout<<"i: "<<i<<endl;
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};

// Time:  O(n)
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> s2t(256, 0); 
        vector<bool> t2s(256, false);
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && !t2s[t[i]]) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = true;
            }
            else if ((s2t[s[i]] == 0 && t2s[t[i]]) || s2t[s[i]] != t[i]) {
                // Contradict mapping.
                return false;
            }
        }
        return true;
    }
};

// Time:  O(n)
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> s2t(256, 0), t2s(256, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i]) {
                // Contradict mapping.
                return false;
            }
        }
        return true;
    }
};
