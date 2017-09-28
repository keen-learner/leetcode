/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num <=1) return true;
        int l = 1;
        int r = num/2;
        while(l <= r) {
            int m = l + (r-l)/2;
            if((long)m * m == num) return true;
            else if ((long)m * m < num) l = m+1;
            else r = m-1;
        }
        return false;
    }
};
