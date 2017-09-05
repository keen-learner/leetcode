/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in 
which the depth of the two subtrees of every node never differ by more than 1.

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
    private int len = 0;
    public boolean isBalanced(TreeNode root) {
        if(root == null) {len = 0; return true;}
        boolean lstatus = isBalanced(root.left);
        int  llen = len;
        boolean rstatus = isBalanced(root.right);
        int  rlen = len;
        len = 1 + Math.max(llen, rlen);
        return lstatus && rstatus && (Math.abs(rlen - llen) <= 1);
    }
}
