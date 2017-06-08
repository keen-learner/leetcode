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
public:
    int titleToNumber(string s) {
        int res = 0;
        int mult = 1;
        for(int i = s.size()-1; i >= 0; --i, mult *= 26){
            res = res + (1+s[i]-'A')*mult;
        }
        return res;
    }
};
