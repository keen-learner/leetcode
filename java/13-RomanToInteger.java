/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/

public class Solution {
    public int romanToInt(String s) {
        int res = 0;
        Map<Character, Integer> m = new HashMap<>();
        m.put('M', 1000);
        m.put('D', 500);
        m.put('C', 100);
        m.put('L', 50);
        m.put('X', 10);
        m.put('V', 5);
        m.put('I', 1);
        for(int i = 0; i < s.length(); i++) {
            if(i > 0 && (m.get(s.charAt(i)) > m.get(s.charAt(i-1))) ) {
                res = res + m.get(s.charAt(i)) - 2*m.get(s.charAt(i-1));
            } 
            else {
                res = res + m.get(s.charAt(i));
            }
        }
        return res;
    }
}
