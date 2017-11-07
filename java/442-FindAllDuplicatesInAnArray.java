/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length; // array can have [1,n] range
        for(int i = 0; i<n;) {
            if(nums[nums[i]-1] != nums[i]) {
                swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        
        int j = 0;
        List<Integer> res = new ArrayList<>();
        while(j<n ) {
            if(nums[j] != j+1) res.add(nums[j]);
            j++;
        }
        return res;        
    }
    
    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    
}
