/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

*/

class Solution {
    public int titleToNumber(String s) {
        int n = s.length();
        int mult = 1;
        int res = 0;
        for(int i = n-1; i>=0; i--, mult *= 26) {
            int d = 1+(int)(s.charAt(i) - 'A');
            res += d*mult;
        }
        return res;
    }
}
