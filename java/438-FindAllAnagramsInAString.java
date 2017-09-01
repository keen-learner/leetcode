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

ass Solution {
    public List<Integer> findAnagrams(String s, String p) { //find anagrams of p in s
        List<Integer> res = new ArrayList<>();
        if(s == null || p == null || s.length() < p.length()) return res; 
        int begin = 0;
        int end = 0;
        int fbegin = 0; //final begin
        int fend = -1; //final end
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        for(char c : p.toCharArray()) {
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
                if(end - begin + 1 == p.length()) {
                    res.add(begin);
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
 
        return res;       
    }
}
