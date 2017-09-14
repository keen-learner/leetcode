/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many 
distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
    public int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int fn = 0;
        int fn_1 = 1;
        int fn_2 = 1;
        for(int i = 2; i<=n; i++) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}
