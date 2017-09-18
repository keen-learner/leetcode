/*

Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, 
and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the 
answer is guaranteed to be fit in 32-bit signed int.

*/

class Solution {
    public int findNumberOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        int[] cnt = new int[nums.length];
        int res = 1;
        Arrays.fill(dp, 1);
        Arrays.fill(cnt, 1);
        for(int i = 1; i<nums.length; i++) {
            for(int j =i-1; j>=0; --j) {
                if(nums[i] >nums[j]) {
                    if(dp[j]+1>dp[i]) {
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j]+1==dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            res = Math.max(res, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i<nums.length; i++) {
            if(dp[i] == res) ans += cnt[i];
        }
        return ans;
    }
}
