/*

Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.


More practice:
If you have figured out the O(n) solution, try coding another solution using the 
divide and conquer approach, which is more subtle.

*/

// DP
/*
dp[n]
dp[i] gives maxSubArray from 0 to i s.t. it ends at i; 
    so dp[i] = max(dp[i-1]+nums[i], nums[i])
result is max of all dp[i]
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        //else if(n == 1) return nums[0];
        int res = nums[0];
        int run_max = nums[0];
        for(int i = 1; i < n; ++i) {
            run_max = max(nums[i], run_max+nums[i]);
            res = max(res, run_max);
        }
        return res;
    }
};
