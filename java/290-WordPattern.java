/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between 
a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str 
contains lowercase letters separated by a single space.

*/

class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] ss = str.split(" ");
        Map<String, Integer> m1 = new HashMap();
        Map<Character, Integer> m2 = new HashMap();
        if(ss.length != pattern.length()) return false;
        for(int i = 0; i < ss.length; i++) { 
            char c = pattern.charAt(i);
            if(m2.containsKey(c) && m1.containsKey(ss[i]) 
               && (!m1.get(ss[i]).equals(m2.get(c)))) return false;
            if(m2.containsKey(c) && !m1.containsKey(ss[i])) return false;
            if(!m2.containsKey(c) && m1.containsKey(ss[i])) return false;            
            m2.put(c, i+1);
            m1.put(ss[i], i+1);
        }
        return true;          
    }
}
