/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length; // array can have [1,n] range
        for(int i = 0; i<n;) {
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        int j = 0;
        while(j<n && nums[j] == j+1) j++;
        return j+1;
    }
    
    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
