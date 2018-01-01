/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        for(int i = 0 ; i < n; ) {
            if(nums[i] > 0 && nums[i] <= n && (nums[i] != nums[nums[i]-1])) {
                Swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        for(int i = 0 ; i < n; i++) {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
    
    private void Swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
