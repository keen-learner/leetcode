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

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int fn_2 = 0;
        int fn_1 = 1; 
        int fn = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                fn_1 = 0; // f[n - 1] = 0
            }
            if (!(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                fn_2 = 0; // f[n - 2] = 0
            }
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

