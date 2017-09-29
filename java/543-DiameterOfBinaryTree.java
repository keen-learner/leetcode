/*

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        return depth(root)[0];
    }

    private int[] depth(TreeNode root) { // return [max, depth]
        int[] res = new int[2];
        if(root == null) return res;
        int[] l = depth(root.left);
        int[] r = depth(root.right);
        res[0] = Math.max(l[1]+r[1], Math.max(l[0], r[0])); //max
        res[1] = 1 + Math.max(l[1], r[1]); //depth
        return res;
    }
}

class Solution1 {
    private int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return res;
        depth(root); // return depth and update res
        return res;
    }
    private int depth(TreeNode root) {
        if(root == null) return 0;
        int l = depth(root.left);
        int r = depth(root.right);
        res = Math.max(res, l+r);
        return 1+ Math.max(l, r);
    }
}

