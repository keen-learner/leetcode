/*

Given inorder and postorder traversal of a tree, construct the binary tree.

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder == null || postorder.length == 0 || 
           inorder == null || inorder.length == 0) return null;
        return helper(postorder, 0, postorder.length-1, inorder, 0, postorder.length-1);        
    }

    private TreeNode helper(int[] postorder, int ps, int pe, int[] inorder, int is, int ie) {
        if(is>ie || ps>pe) return null;
        TreeNode root = new TreeNode(postorder[pe]);
        int index = is;
        for(int i = is; i <= ie; i++) {
            if(inorder[i] == root.val) {
                index = i; 
                break;
            }    
        }
        
        root.left = helper(postorder, ps, ps + index - is-1, inorder, is, index-1);
        root.right = helper(postorder, ps + index - is , pe-1, inorder, index+1, ie);
        return root;
    }    
}

