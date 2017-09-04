/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
    private List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> permute(int[] nums) {
        if (nums == null || nums.length == 0) return res;
        return helper(nums, 0);
    }
    
    public List<List<Integer>> helper(int[] nums, int st) {
        int n = nums.length;
        if(st == n) {
            List<Integer> t = new ArrayList<Integer>();
            for(int i = 0; i < n; i++) t.add(nums[i]);
            res.add(t);
            return res;
        }
        for(int i = st; i < n; i++) {
            swap(nums, st, i);
            helper(nums, st+1);
            swap(nums, st, i);
        }
        return res;
    }
    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    
}
