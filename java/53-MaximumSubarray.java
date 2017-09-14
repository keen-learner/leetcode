/*

Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.


More practice:
If you have figured out the O(n) solution, try coding another solution using the 
divide and conquer approach, which is more subtle.

*/

class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0 || nums == null) return 0;
        int n = nums.length;
        // int[] dp = new int[n];
        int runmax = nums[0];
        int res = nums[0];
        for(int i = 1; i<n; i++) {
            runmax = Math.max(nums[i], runmax+nums[i]);
            res = Math.max(res, runmax);
        }
        return res;
    }
}

class Solution1 {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0 || nums == null) return 0;
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i<n; i++) {
            dp[i] = Math.max(nums[i], dp[i-1]+nums[i]);
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
