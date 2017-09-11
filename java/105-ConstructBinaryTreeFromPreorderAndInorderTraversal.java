/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder == null || preorder.length == 0 || 
           inorder == null || inorder.length == 0) return null;
        return helper(preorder, 0, preorder.length-1, inorder, 0, preorder.length-1);
    }
    private TreeNode helper(int[] preorder, int ps, int pe, int[] inorder, int is, int ie) {
        if(is>ie || ps>pe) return null;
        TreeNode root = new TreeNode(preorder[ps]);
        int index = is;
        for(int i = is; i <= ie; i++) {
            if(inorder[i] == root.val) {
                index = i; 
                break;
            }    
        }
        
        root.left = helper(preorder, ps+1, ps + index - is, inorder, is, index-1);
        root.right = helper(preorder, ps + index - is + 1, pe, inorder, index+1, ie);
        return root;
    }
}
