/*

Given a string, find the first non-repeating character in it and 
return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

// we can either traverse string twice or map twice
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(auto &c : s) {
            m[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};

class Solution1 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        int res = s.size();        
        for(auto &p : m) {
            if(p.second.first == 1) res = min(res, p.second.second);
        }
        return res == s.size() ? -1 : res;
    }
};
