/*

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

class Solution {
    public List<List<Integer>> combinationSum3(int k, int target) { //k numbers with sum == target
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<Integer>();
        int[] candidates = new int[]{1,2,3,4,5,6,7,8,9};
        if(k == 0 || target < 0) return res;
        helper(res, curr, 0, candidates, target, k);
        return res;
    }
    private void helper(List<List<Integer>> res, List<Integer> curr, int st, int[] candidates, int target, int k) {
        if(target == 0 && curr.size() == k) res.add(new ArrayList<Integer>(curr));
        else if (target < 0 || curr.size() > k) return;
        else {
            for(int i = st; i < candidates.length; i++) {
                // if(i>st && candidates[i] == candidates[i-1]) continue;
                curr.add(candidates[i]);
                helper(res, curr, i+1, candidates, target-candidates[i], k);
                curr.remove((Integer)candidates[i]);
            }
        }
    }
}
