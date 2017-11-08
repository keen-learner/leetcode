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
    public String convertToTitle(int n) {
        if(n<=0) return "";
        StringBuilder res = new StringBuilder();
        while(n>0) { // or n!=0
            char ch = (char)((int)'A' + ((n-1) % 26));
            res.append(ch);
            n = (n-1)/26;
        }
        return res.reverse().toString();
    }
}


// Time: O(logn) if string concatenation considered O(1)
class Solution1 {
    public String convertToTitle(int n) {
        if(n<=0) return "";
        String res = "";
        while(n>0) { // or n!=0
            char ch = (char)((int)'A' + ((n-1) % 26));
            res = ch + res;
            n = (n-1)/26;
        }
        return res;
    }
}
