/*

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

*/

// https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

class Solution {
    public int getSum(int a, int b) {
        if(b == 0) return a;
        if(a == 0) return b;
        while(b!=0) {
            int res = a^b;
            int c = (a&b)<<1;
            a = res;
            b = c;
        }
        return a;
    }
}
