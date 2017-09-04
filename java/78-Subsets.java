/*

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> curr = new ArrayList<Integer>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums == null || nums.length == 0) return res;
        helper(res, 0, nums, curr);
        return res;
    }
    
    private void helper(List<List<Integer>> res, int st, int[] nums, List<Integer> curr) {
        res.add(new ArrayList<Integer>(curr));
        for(int i = st; i < nums.length; i++) {
            curr.add(nums[i]);
            helper(res, i+1, nums, curr);
            curr.remove((Integer)nums[i]);
        }
    }
}
