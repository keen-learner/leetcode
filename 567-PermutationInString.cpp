/*

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

*/

class Solution {
public:
    bool checkInclusion(string p, string s) { //s=s2, p=s1 if s contains p's permutation
        vector<int> pc(128, 0); //lower chars count
        if(p.size() > s.size()) return false;
        
        for(int i = 0; i < p.size(); i++) {
            pc[p[i]]++;
        }
        int begin = 0;
        int end = 0;
        int counter = p.size();
        while(end < s.size()) {
            if(pc[s[end]] > 0) --counter;
            pc[s[end]]--;
            
            while(counter == 0) { // window found
                if(end-begin+1 == p.size()) {
                    return true;
                }
                pc[s[begin]]++;
                if(pc[s[begin]] > 0) ++counter;
                ++begin;
            }
            ++end;
        }
        return false;           
    }
};

class Solution1 {
public:
    bool checkInclusion(string p, string s) { //s=s2, p=s1
        vector<int> pc(128, 0); //lower chars count
        // string res = "";
        // if(p.size() > s.size()) return res;
        if(p.size() > s.size()) return false;
        
        for(int i = 0; i < p.size(); i++) {
            pc[p[i]]++;
        }
        int begin = 0;
        int end = 0;
        int counter = p.size();
        // int minbegin = -1;
        // int minlen = INT_MAX;
        while(end < s.size()) {
            if(pc[s[end]] > 0) --counter;
            pc[s[end]]--;
            // cout<<"s[end] : "<<s[end]<<" begin: "<<begin<<" end: "<<end<<endl;
            
            while(counter == 0) { // window found
            // cout<<"counter 0 case: s[end] : "<<s[end]<<" begin: "<<begin<<" end: "<<end<<" minbegin: "<<minbegin<<" minlen: "<<minlen<<endl;
                if(end-begin+1 == p.size()) {
                    // minlen = end-begin+1;
                    return true;
                    // minbegin = begin;
                }
                pc[s[begin]]++;
                if(pc[s[begin]] > 0) ++counter;
                ++begin;
            }
            ++end;
        }
        return false;
        // cout<<"counter end case: "<<" begin: "<<begin<<" end: "<<end<<" minbegin: "<<minbegin<<" minlen: "<<minlen<<endl;
        // if(minbegin == -1) return res;
        // for(int i = minbegin; i < minbegin+minlen; i++) res.push_back(s[i]);
        // return res;            
    }
};
