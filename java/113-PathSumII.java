/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root == null) return res;
        List<Integer> curr = new ArrayList<Integer>();
        helper(res, curr, root, 0, sum);
        return res;
    }
    
    private void helper(List<List<Integer>> res, List<Integer> curr, TreeNode root, int currsum, int sum) {
        if(root == null) return;
        curr.add(root.val);
        currsum += root.val;
        if(root.left == null && root.right == null && currsum == sum) { //leaf node with required sum
            res.add(new ArrayList<Integer>(curr));
            curr.remove(curr.size()-1);
            currsum -= root.val;
            return;
        } 
        helper(res, curr, root.left, currsum, sum);
        helper(res, curr, root.right, currsum, sum);
        curr.remove(curr.size()-1);
        currsum -= root.val;
    }
}
