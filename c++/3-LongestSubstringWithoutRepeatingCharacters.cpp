/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer 
must be a substring, "pwke" is a subsequence and not a substring.

*/

// Time 0(n), Space O(d) d-char set size
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(s.size() == 0) return res;
        unordered_map<char, int> m;        
        int begin = 0;
        int end = 0;
        int counter = 0; //tracks duplicates
        while(end < s.size()) {
            ++m[s[end]];
            if(m[s[end]] > 1) ++counter;
            
            while(counter > 0) {
                if(m[s[begin]]>1) --counter;
                --m[s[begin]];
                ++begin;
            }
            res = max(res, end-begin+1);
            ++end;    
        }
        return res;
    }
};

// Time 0(n), Space O(d) d-char set size
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> m;        
        const int n = s.size();
        int start = 0;
        for(int i = 0; i < n; i++) { 
            auto it = m.find(s[i]);
            if(it != m.end() && (m[s[i]] >= start)) { //char found
                
                res = max(res, i-1 - start + 1);
                start = it->second+1;
                
            }
            m[s[i]] = i;
        }
        return max(res, n-1 - start + 1);
    }
};


// O(n3) brute force
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        set<char> h;
        const auto n = s.size();
        for(int size = 1; size <= n; size++) { // length i substring
            for(int i = 0; i <= n -size; i++ ) {
                h.clear();
                for(int j = i; j-i+1<=size; j++ ) {
                    h.insert(s[j]); 
                }
                if(h.size() == size) res = max(res, size);
            }
        }
        return res;
    }
};
