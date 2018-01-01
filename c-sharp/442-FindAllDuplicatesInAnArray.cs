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

public class Solution {
    public IList<int> FindDuplicates(int[] nums) {
        int n = nums.Length;
        IList<int> res = new List<int>();
        for(int i = 0; i<n;) {
            if(nums[i] > 0 && nums[i] <= n && (nums[i] != nums[nums[i]-1])) {
                Swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        for(int i = 0 ; i < n; i++) {
            if(nums[i] != i+1) res.Add(nums[i]);
        }
        return res;
    }
    
    private void Swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
