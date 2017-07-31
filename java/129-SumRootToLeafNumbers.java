/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    // private int cur;
    private int res;
    public int sumNumbers(TreeNode root) {
        if(root == null) return 0;
        helper(root, 0);
        return res;
    }
    
    private void helper(TreeNode root, int cur) {
        if(root.left == null && root.right == null) {
            cur = cur*10 + root.val;
            res = res + cur;
            return;
        }
        if(root.left == null && root.right != null) {
            cur = cur*10 + root.val;
            helper(root.right, cur);
            return;
        }
        if(root.left != null && root.right == null) {
            cur = cur*10 + root.val;
            helper(root.left, cur);
            return;
        }
        cur = cur*10 + root.val;
        helper(root.left, cur);
        helper(root.right, cur);
    }
}
