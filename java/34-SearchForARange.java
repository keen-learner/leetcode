/*

Given an array of integers sorted in ascending order, find the 
starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[]{-1, -1};
        int n = nums.length;
        int st = lower_bound(nums, target);
        if(st == n || (nums[st] != target)) return new int[]{-1, -1};
        System.out.println(st);
        int end = lower_bound(nums, target+1);
        return new int[] {st, end-1};
        
    }
    
    // for NNNYYY; gives index if first Y
    private int lower_bound(int[] nums, int target) {
        int l = 0;
        int r = nums.length;
        while(l<r) {
            int m = l + (r-l)/2;
            if(nums[m] < target) l = m+1;
            else r = m;
        }
        return l; // for size 1 array; just returning 0
    }
}
