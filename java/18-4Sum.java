/*

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in 
the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/


class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        int l, r, sum;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
        
            for (int j = i + 1; j < n - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                
                sum = target - nums[i] - nums[j];
                l = j + 1; r = n - 1;
                while (l < r) {
                    if(l >j+1 && nums[l] == nums[l-1]) {
                        ++l;
                    }
                    else if (r<n-1 && nums[r] == nums[r+1]){
                        --r;
                    }
                    else {
                        if (nums[l] + nums[r] == sum) {
                            List<Integer> t = new ArrayList<>();
                            t.add(nums[i]); t.add(nums[j]);
                            t.add(nums[l]); t.add(nums[r]);
                            res.add(t);
                            ++l; --r;
                        }    
                        else if (nums[l] + nums[r] < sum) {
                            ++l;
                        }
                        else {
                            --r;
                        }
                    }
                }
            }
        }
        return res;        
    }
}
