/*

Given an unsorted array return whether an increasing subsequence 
of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/

class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        if(n <3) return false;
        int c1 = Integer.MAX_VALUE;
        int c2 = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++) {
            if(nums[i] <= c1) c1 = nums[i];
            else if(nums[i] <= c2) c2 = nums[i];
            else return true;
        }
        return false;
    }
}
