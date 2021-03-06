/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many 
distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        auto fn_1 = 2;
        auto fn_2 = 1;
        int f;
        for(int i = 3; i<=n; i++) {
            f = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = f;
        }
        return f;
    }
};
