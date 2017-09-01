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
    public boolean checkInclusion(String s1, String s2) { // if s2 contains permutation of s1
        if(s1 == null || s2 == null || s2.length() < s1.length()) return false;
        int begin = 0;
        int end = 0;
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        for(char c : s1.toCharArray()) {
            m.put(c, 1+m.getOrDefault(c, 0));
        }
        int counter = m.size();
        while(end < s2.length()) {
            char c = s2.charAt(end);
            if(m.containsKey(c)) {
                m.put(c, m.get(c)-1);
                if(m.get(c) == 0) --counter;
            }
            while(counter == 0) {
                if(end - begin + 1 == s1.length()) return true;
                char b = s2.charAt(begin);
                if(m.containsKey(b)) {
                    m.put(b, 1+m.get(b));    
                    if(m.get(b) == 1) ++counter;
                }
                ++begin;
            }   
            ++end;
        }
        return false;
        
    }
}
