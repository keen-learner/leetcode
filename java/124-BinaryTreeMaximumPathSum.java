/*

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the parent-child 
connections. The path must contain at least one node and does 
not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
public class Solution {
    private int res;
    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        res = Integer.MIN_VALUE;
        helper(root);
        return res;
    }
    private int helper(TreeNode root) {
        if(root == null) return 0;
        int lmax = helper(root.left);
        int rmax = helper(root.right);
        int mx = Math.max(root.val, Math.max(lmax+root.val, rmax+root.val));
        res = Math.max(res, Math.max(mx, root.val+lmax+rmax));
        return mx;
    }
}
