/*

Given an array of size n, find the majority element. The majority element is the element that 
appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

// NOTE: we also have hash and sorting approach
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length; // n >=1 given
        int res = nums[0];
        int c = 1;
        for(int i = 1; i<n; i++) {
            if(nums[i] == res) ++c;
            else if(c == 0) {
                c = 1;
                res = nums[i];
            }
            else --c;
        }
        // we know solution exists; otherwise need to verify it exists
        return res;
    }
}
