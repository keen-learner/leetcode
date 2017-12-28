/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one 
duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

public class Solution {
    public int FindDuplicate(int[] nums) {
        int l = 1;
        int r = nums.Length-1;
        while(l<=r) {
            if(l == r) return l;
            int m = l + (r-l)/2;
            int count = 0;
            for(int i = 0; i < nums.Length; i++) {
                if(nums[i] >= l && nums[i] <= m) ++count;
            }
            if(count > m-l+1) r = m;
            else l = m+1;
        }
        return -1;
    }
}
