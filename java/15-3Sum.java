/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        Arrays.sort(nums);
        int n = nums.length;
        int target = 0;
        for(int i = 0; i< n-2; i++) {
            if(i>0 && (nums[i] == nums[i-1])) continue;
            int j = i+1;
            int k = n-1;
            while(j < k) {
                if(j>i+1 && nums[j] == nums[j-1]) ++j;
                else if(k<n-1 && nums[k] == nums[k+1]) --k;
                else {
                    int sum = nums[i] + nums[j] + nums[k];
                    if( sum < target) ++j;
                    else if (sum > target) --k;
                    else {
                        List<Integer> l = new LinkedList<Integer>();
                        l.add(nums[i]);
                        l.add(nums[j]);
                        l.add(nums[k]);
                        res.add(l);
                        ++j;
                        --k;
                    }
                }
            }
        }
        return res;
    }
}
