/*

Given an array of integers nums and a positive integer k, find whether 
it's possible to divide this array into k non-empty subsets whose sums 
are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

*/

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        if(nums==null || nums.length==0 || k==0) return false;
        
        int sum = 0;
        for(int n:nums) sum+= n;
        if(sum%k!=0) return false;
        
        int[] sums = new int[k];
        // sort nums in descending order to optimize    
        return dfs(nums, sums, sum/k, 0);
    }
    
    private boolean dfs(int[] nums, int[] sums, int target, int id) {
        if(id == nums.length) return true;
        for(int i = 0; i < sums.length; i++) {
            if(sums[i] + nums[id] > target) continue;
            sums[i] += nums[id];
            if(dfs(nums, sums, target, id + 1)) return true;
            sums[i] -= nums[id];
            if(sums[i] == 0) break; // optimization
        }
        return false;
    } 
}

