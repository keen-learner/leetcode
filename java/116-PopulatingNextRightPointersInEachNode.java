/*

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If 
there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves 
are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */

public class Solution {
    public void connect(TreeLinkNode root) {
        if(root == null) return;
        root.next = null;
        while(root != null) {
            TreeLinkNode curr = root;
            while(curr != null) {
                if(curr.left != null) curr.left.next = curr.right;
                if(curr.right != null) curr.right.next = curr.next!=null?curr.next.left:null;
                curr = curr.next;
            }
            root = root.left;
        }
    }       
}

// same as 117. Populating Next Right Pointers in Each Node II
class Solution1 {
    public void connect(TreeLinkNode root) {
        if(root == null) return;
        root.next = null;
        while(root != null) {
            TreeLinkNode curr = root;
            while(curr != null) {
                if(curr.left != null) curr.left.next = curr.right != null ? curr.right:getLeftmostFromNextLevel(curr);
                if(curr.right != null) curr.right.next = getLeftmostFromNextLevel(curr);
                curr = curr.next;
            }
            if(root.left != null) root = root.left;
            else if(root.right != null) root = root.right;
            else root = getLeftmostFromNextLevel(root);
        }
    }
    private TreeLinkNode getLeftmostFromNextLevel(TreeLinkNode curr) {
        TreeLinkNode temp = curr.next;
        while(temp != null) {
            if(temp.left != null) return temp.left;
            if(temp.right != null) return temp.right;
            temp = temp.next;
        }
        return null;
    }        
}
