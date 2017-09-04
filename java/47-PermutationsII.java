/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
    private List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        if (nums == null || nums.length == 0) return res;
        Arrays.sort(nums);
        List<Integer> curr = new ArrayList<Integer>();
        for(int i = 0; i< nums.length; i++) curr.add(nums[i]);
        helper(0, nums.length, curr);
        return res;        
    }
    private void helper(int st, int n, List<Integer> curr) {
        if(st == n) {
            res.add(new ArrayList(curr));
            return;
        }
        for(int i = st; i < n; i++) {
            if(i > st && curr.get(i) == curr.get(i-1)) continue;
            curr.add(st, curr.get(i));
            curr.remove((int)(i+1));
            helper(st+1, n, curr);
            curr.add(i+1, curr.get(st));
            curr.remove((int)(st));
            
        }
    }
    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
