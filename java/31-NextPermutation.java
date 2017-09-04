/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length-1;
        for(; i > 0; i--) {
            if(nums[i-1] < nums[i]) break;
        }
        if(i == 0) {
            reverse(nums, 0, nums.length-1);
            return;
        }
        
        int j = i-1;
        int k = i;
        while(k<nums.length && nums[k]>nums[j]) k++;
        swap(nums, j, k-1);
        reverse(nums, j+1, nums.length-1);
    }
    private void reverse(int[] nums, int i, int j) {
        while(i < j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i;
            --j;
        }
    }
    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
