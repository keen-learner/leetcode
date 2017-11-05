/*
ORiGINAL :
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array 
return its index, otherwise return -1.

You may assume no duplicate exists in the array.

THIS QUESTION:
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int l = 0;
        int r = n-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return true;
            else if(nums[l] == nums[m]) ++l;
            else if (nums[l] <= nums[m]) { // left half sorted
                if(target >= nums[l] && target < nums[m]) r = m-1;
                else l = m+1;
            }
            else {
                if(target > nums[m] && target <= nums[r]) l = m+1;
                else r = m-1;
            }
        }
        return false;        
    }
}
