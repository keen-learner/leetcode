/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the 
answer must be a substring, "pwke" is a subsequence and not a substring.

*/

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        int start = 0;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            int j = -1;
            if(m.containsKey(s.charAt(i)) ) {
                j = m.get(s.charAt(i));
                if(j>=start) {
                    res = Math.max(res, i-1-start+1);    
                    start = j+1;
                }          
            }
            m.put(s.charAt(i),i);   
        }
        return Math.max(res, s.length()-1-start+1);       
        
        
    }
}
