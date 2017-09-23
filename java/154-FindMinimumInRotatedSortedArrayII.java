/*

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

*/

class Solution {
    public int findMin(int[] nums) {
        if(nums.length == 0) return -1;
        int l = 0;
        int r = nums.length-1;
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            int m = l + (r-l)/2;
            if(nums[l] == nums[m]) ++l;
            else if(nums[m] <= nums[r]) r = m;
            else l = m+1;
        }        
        return nums[l];        
    }
}
