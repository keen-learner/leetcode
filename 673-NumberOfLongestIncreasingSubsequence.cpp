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
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);

        int res = 1;
        for(int i = 1; i<nums.size(); i++) {
            for(int j = i-1; j>=0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < 1+dp[j]) {
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if (dp[i] == 1+dp[j]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            res = max(res, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < dp.size(); i++) {
            if(res == dp[i]) ans += cnt[i];
        } 
        return ans;
    }
};
