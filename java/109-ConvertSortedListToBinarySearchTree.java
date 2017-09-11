/*

Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

*/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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
    private ListNode curr = null;
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null) return null;
        ListNode runner = head;
        int n = 0;
        while (runner != null) {
            ++n;
            runner = runner.next;
        }
        curr = head;
        return helper(n);
    }
    
    private TreeNode helper(int n) {
        if(curr == null || n == 0 ) return null;
        int m = n/2;
        TreeNode left = helper(m);
        TreeNode root = new TreeNode(curr.val);
        curr = curr.next;
        root.right = helper(n - m - 1);
        root.left = left;
        return root;
    }
}
