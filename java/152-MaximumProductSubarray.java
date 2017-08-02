/*

 subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

public class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        if(n == 1 ) return nums[0];
        int res = nums[0];
        int run_max = nums[0];
        int run_min = nums[0];
        for(int i = 1; i < n; ++i) {
            int t = run_max;
            run_max = Math.max(nums[i], Math.max(run_max*nums[i], run_min*nums[i]));
            run_min = Math.min(nums[i], Math.min(t*nums[i], run_min*nums[i]));
            res = Math.max(res, run_max);
        }
        return res;
    }
}
