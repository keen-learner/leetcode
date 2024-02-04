/*

Given a non-negative integer c, your task is to decide whether 
there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False

*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        int l = 0;
        int r = sqrt(c);
        while(l <= r) {
            int m = l*l + r*r;
            if(m == c) return true;
            else if ( m < c) ++l;
            else --r;
        }   
        return false;         
    }
};
