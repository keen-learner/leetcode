/*

A message containing letters from A-Z is being encoded 
to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine 
the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

class Solution {
    public int numDecodings(String s) {
        if(s.length() == 0 || s.charAt(0) == '0') return 0;
        if(s.length() == 1) {
            if(s.charAt(0) >= '1' && s.charAt(0) <= '9') return 1;
        }
        int fn_2 = 0;
        int fn_1 = 1;
        int fn = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(i) == '0') {
                if(s.charAt(i-1) == '1' || s.charAt(i-1) == '2') {
                    fn = i-2>=0?fn_2:1;
                }
                else fn = 0;
            }
            else {
                fn = fn_1;
                if(s.charAt(i-1) == '1' || 
                   (s.charAt(i-1) == '2' && (s.charAt(i) >= '1' && s.charAt(i) <= '6')) ) {
                    fn += i-2>=0?fn_2:1;
                }
            }
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}
