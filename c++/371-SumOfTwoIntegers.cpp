/*

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

*/

// https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a; //for case b = 0
        while(b!=0) {
            sum = a ^ b;
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return sum;
    }
};
