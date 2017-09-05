/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> curr = new ArrayList<Integer>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums == null || nums.length == 0) return res;
        Arrays.sort(nums);
        helper(res, 0, nums, curr);
        return res;
    }
    
    private void helper(List<List<Integer>> res, int st, int[] nums, List<Integer> curr) {
        res.add(new ArrayList<Integer>(curr));
        for(int i = st; i < nums.length; i++) {
            if(i > st && nums[i] == nums[i-1]) continue;
            curr.add(nums[i]);
            helper(res, i+1, nums, curr);
            curr.remove((Integer)nums[i]);
        }
    }
}
