/*

Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.

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
    
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums == null || nums.length == 0) return null;
        return helper(nums, 0, nums.length-1);
    }
    private TreeNode helper(int[] nums, int l , int r) {
        // NO NEED for following
        // if(l == r) {
        //     TreeNode root = new TreeNode(nums[l]);
        //     root.left = null;
        //     root.right = null;
        //     return root;
        // }
        if(l > r) return null;
        int m = l + (r-l)/2;
        TreeNode root = new TreeNode(nums[m]);
        root.left = helper(nums, l, m-1);
        root.right = helper(nums, m+1, r);
        return root;
    }
}
