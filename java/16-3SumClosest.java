/*

Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

// Time:  O(n^2)
// Space: O(1)

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int res = Integer.MAX_VALUE;
        int min_diff = Integer.MAX_VALUE;

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // Skip duplicate.
            
            for(int j = i+1, k = nums.length-1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
    
                if (sum > target) {  // Should decrease sum.
                    --k;
                } 
                else if (sum < target) {  // Should increase sum.
                    ++j;
                } 
                else {
                    return target;
                }
    
                if (Math.abs(sum - target) < min_diff) {
                    min_diff = Math.abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;        
    }
}
