/*

Given an array of non-negative integers, you are initially 
positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/


// https://discuss.leetcode.com/category/63/jump-game
// https://discuss.leetcode.com/topic/50375/simple-c-solution-with-explanation
// https://discuss.leetcode.com/topic/3443/simplest-o-n-solution-with-constant-space

class Solution {
    public boolean canJump(int[] nums) {
        if(nums==null || nums.length == 0) return false;
        int res = 0;
        int n = nums.length;
        for(int i = 0; i<=res && res<n; i++) {
            res = Math.max(res, nums[i]+i);
        }
        return res>=n-1;
    }
}
