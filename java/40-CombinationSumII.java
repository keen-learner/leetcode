/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

NOTE: here C can have duplicates, but have to use each element once

*/

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
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
                if(i>st && candidates[i] == candidates[i-1]) continue;
                curr.add(candidates[i]);
                helper(res, curr, i+1, candidates, target-candidates[i]);
                curr.remove((Integer)candidates[i]);
            }
        }
    }
}
