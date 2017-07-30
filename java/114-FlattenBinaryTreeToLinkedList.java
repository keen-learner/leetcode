/*

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points 
to the next node of a pre-order traversal.

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
    public void flatten (TreeNode root) {
        while (root != null) {
            if(root.left != null && root.right != null) {
                TreeNode t = root.left;
                while(t.right != null) t = t.right;
                t.right = root.right;
            }
            if(root.left != null) root.right = root.left;
            root.left = null;
            root = root.right;
        }
    }
}

class Solution1 {
    private TreeNode prev = null;
    public void flatten (TreeNode root) {
        if(root == null) return;
        flatten (root.right);
        flatten(root.left);
        root.right = prev;
        root.left = null;
        prev = root; 
    }
}
