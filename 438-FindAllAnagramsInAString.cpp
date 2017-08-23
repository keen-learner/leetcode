/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0); //lower chars count
        vector<int> res;
        if(p.size() > s.size()) return res;
        
        for(int i = 0; i < p.size(); i++) {
            pc[p[i]-'a']++;
        }
        int begin = 0;
        int end = 0;
        int counter = p.size();
        while(end < s.size()) {
            if(pc[s[end]-'a'] > 0) --counter;
            pc[s[end]-'a']--;
            cout<<"s[end] : "<<s[end]<<" begin: "<<begin<<" end: "<<end<<endl; 
            
            while(counter == 0) { // window found
                cout<<"counter 0 case: s[end] : "<<s[end]<<" begin: "<<begin<<" end: "<<end<<endl; 
                if(end-begin+1 == p.size()) res.push_back(begin);
                pc[s[begin]-'a']++;
                if(pc[s[begin]-'a'] > 0) ++counter;
                ++begin;
            }
            ++end;
        }
        return res;
    }  
};

class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0); //lower chars count
        vector<int> sc(26, 0);
        vector<int> res;
        if(p.size() > s.size()) return res;
        for(int i = 0; i < p.size(); i++) {
            pc[p[i]-'a']++;
            sc[s[i]-'a']++;
        }
        for(int i = p.size(); i < s.size(); i++) {
            if(pc == sc) res.push_back(i-p.size());
            --sc[s[i-p.size()]-'a'];
            sc[s[i]-'a']++;
        }
        if(pc == sc) res.push_back(s.size()-p.size());
        return res;
    }
    
};
