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
    public String minWindow(String s, String t) { //min window in s that contains all chars in t
        if(s == null || t == null || s.length() < t.length()) return "";
        int begin = 0;
        int end = 0;
        int fbegin = 0; //final begin
        int fend = -1; //final end
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        for(char c : t.toCharArray()) {
            m.put(c, 1+m.getOrDefault(c, 0));
        }   
        int counter = m.size();
        while(end < s.length()) {
            char c = s.charAt(end);
            if(m.containsKey(c)) {
                m.put(c, m.get(c)-1);
                if(m.get(c) == 0) --counter;
            }   
            while(counter == 0) {
                if(fend == -1 || (end - begin + 1 < fend - fbegin + 1)) {
                    fbegin = begin;
                    fend = end;
                }
                char b = s.charAt(begin);
                if(m.containsKey(b)) {
                    m.put(b, 1+m.get(b));
                    if(m.get(b) == 1) ++counter;
                }
                ++begin;
            }
            ++end;
        }
        if (fend == -1) return "";
        return s.substring(fbegin, fend+1); //[fbegin, fend] substring
    }
}
