/*

Given an integer array, you need to find one continuous subarray that if 
you only sort this subarray in ascending order, then the whole array 
will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make 
the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

// Time : O(n), Space: O(1)
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int l = 0, r = nums.length-1;
        while(l<r && nums[l]<=nums[l+1]) ++l;
        if(l == r) return 0; // all sorted case
        while(r>l && nums[r]>=nums[r-1]) --r;
        int lmin = Integer.MAX_VALUE;
        int lmax = Integer.MIN_VALUE;
        for(int i = l; i<=r; i++) {
            lmin = Math.min(lmin, nums[i]);
            lmax = Math.max(lmax, nums[i]);
        }
        while(l>=0 && nums[l]>lmin) --l;
        while(r<nums.length && nums[r]<lmax) ++r;
        // [l+1, r-1] is the range
        return r-1 - (l+1) + 1;
    }
}

// sort solution, Time: O(n), Space: O(1)
class Solution1 {
    public int findUnsortedSubarray(int[] nums) {
        int[] t = nums.clone();
        Arrays.sort(t);
        int i = 0, j = nums.length-1;
        int k = 0;
        for(; k<nums.length && nums[k] == t[k]; k++);
        i = k;
        if(i == nums.length) return 0; //all sorted
        for(k = nums.length-1; k>=0 && nums[k] == t[k]; k--);
        j = k;
        return j - i + 1;
    }
}
