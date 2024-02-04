/*

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        int base = (int)'A';
        while(1) {
            res = char(((n-1) % 26) + base) + res;
            n = (n-1)/26;
            if(n == 0) break;
        }
        return res;
    }
};
