/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

class Solution {
public:
    string minWindow(string s, string p) {
        vector<int> pc(128, 0); //lower chars count
        string res = "";
        if(p.size() > s.size()) return res;
        
        for(int i = 0; i < p.size(); i++) {
            pc[p[i]]++;
        }
        int begin = 0;
        int end = 0;
        int counter = p.size();
        int minbegin = -1;
        int minlen = INT_MAX;
        while(end < s.size()) {
            if(pc[s[end]] > 0) --counter;
            pc[s[end]]--;
            
            while(counter == 0) { // window found
                if(end-begin+1 < minlen) {
                    minlen = end-begin+1; 
                    minbegin = begin;
                }
                pc[s[begin]]++;
                if(pc[s[begin]] > 0) ++counter;
                ++begin;
            }
            ++end;
        }
        if(minbegin == -1) return res;
        for(int i = minbegin; i < minbegin+minlen; i++) res.push_back(s[i]);
        return res;        
    }
};
