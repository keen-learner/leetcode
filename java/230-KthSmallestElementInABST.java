/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need 
to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    private int count = 0;
    public int kthSmallest(TreeNode root, int k) {
        if(k <= 0 || root == null) return Integer.MIN_VALUE;
        if(count == k) return root.val;
        int res = 0;
        if(root.left != null) res = kthSmallest(root.left, k);
        if (count >= k) return res;
        ++count;
        if(count == k) return root.val;
        
        if(root.right != null) res = kthSmallest(root.right, k);
        return res;
    }
}
