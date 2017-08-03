/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

public class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int k =2;
        if(n<k) return n;
        int i = 0;
        int j =1;
        for( j = 1; j<n; ++j) {
            if(i < k-1 || nums[j] != nums[i] || nums[i] != nums[i-k+1]) nums[++i] = nums[j];
        }
        return i+1;
        
    }
}
