/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

public class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int i = -1;
        for(int j = 0; j<n;) {
            if(nums[j] != 0) {
                ++i;
                swap(nums, i, j);
            }
            ++j;
        }
        
    }
    private void swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
