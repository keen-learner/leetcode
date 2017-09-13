/*

Given a non-empty array containing only positive integers, find if 
the array can be partitioned into two subsets such that the sum 
of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/

class Solution {
    public boolean canPartition(int[] nums) {
        if(nums == null || nums.length == 0) return false;
        int sum = 0;
        for(int n :nums) sum += n;
        if(sum % 2 == 1) return false;
        
        sum /= 2;
        // boolean[][] dp = new boolean[1+nums.length][1 + sum];
        boolean[] dp = new boolean[1 + sum];
        // for(int i = 0; i<nums.length; i++) Arrays.fill(dp[i], false);
        Arrays.fill(dp, false);
        dp[0][0] = true;
        
        for(int i = 0; i<nums.length; i++) {
            for(int j = sum; j>0; j--) {
                dp[j] = dp[j] || (j >= nums[i] ? dp[j-nums[i]]:false); 
            }
        }
        return dp[sum];   
    }
}

class Solution1 {
    public boolean canPartition(int[] nums) {
        if(nums == null || nums.length == 0) return false;
        int sum = 0;
        for(int n :nums) sum += n;
        if(sum % 2 == 1) return false;
        
        sum /= 2;
        boolean[][] dp = new boolean[1+nums.length][1 + sum];
        for(int i = 0; i<nums.length; i++) Arrays.fill(dp[i], false);
        dp[0][0] = true;
        
        for(int i = 0; i<nums.length; i++) {
            for(int j = 1; j<=sum; j++) {
                dp[i+1][j] = dp[i][j] || (j >= nums[i] ? dp[i][j-nums[i]]:false); 
            }
        }
        return dp[nums.length][sum];   
    }
}
