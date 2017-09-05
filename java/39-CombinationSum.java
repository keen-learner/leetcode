/*

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

*/


class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<Integer>();
        if(candidates == null || candidates.length == 0 || target < 0) return res;
        Arrays.sort(candidates);
        helper(res, curr, 0, candidates, target);
        return res;
    }
    private void helper(List<List<Integer>> res, List<Integer> curr, int st, int[] candidates, int target) {
        if(target == 0) res.add(new ArrayList<Integer>(curr));
        else if (target < 0) return;
        else {
            for(int i = st; i < candidates.length; i++) {
                curr.add(candidates[i]);
                helper(res, curr, i, candidates, target-candidates[i]);
                curr.remove((Integer)candidates[i]);
            }
        }
    }
}
