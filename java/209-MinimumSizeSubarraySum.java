/*

Given an array of n positive integers and a positive integer s, find the minimal 
length of a contiguous subarray of which the sum ≥ s. If there isn't one, 
return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of 
which the time complexity is O(n log n).

*/

class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(nums==null || nums.length == 0) return 0;
        int res = Integer.MAX_VALUE;
        int begin = 0;
        int end = 0;
        int sum = 0;
        // while(begin <= end && end < nums.length) { //works too
        while(end < nums.length) {    
            sum += nums[end];
            while(sum >= s) {
                res = Math.min(res, end-begin+1);
                sum -= nums[begin];
                ++begin;
            }
            ++end;
        }
        return res == Integer.MAX_VALUE ? 0:res;
    }
}
