/*

You are a professional robber planning to rob houses along a street. Each 
house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security system 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each 
house, determine the maximum amount of money you can rob tonight without 
alerting the police.

*/

public class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        int fn_2 = 0;
        int fn_1 = nums[0];
        int fn = 0;
        for(int i = 1; i<nums.length; i++) {
            fn = Math.max(fn_1, fn_2+nums[i]);
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}
