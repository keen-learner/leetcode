/*

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

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

class Solution1 {
    public void connect(TreeLinkNode root) {
        if(root == null) return;
        Queue<TreeLinkNode> q = new LinkedList<>();
        q.offer(root);
        int n = 1;
        while(!q.isEmpty()) {
            TreeLinkNode t = q.poll();
            if(n == 1) t.next = null;
            else t.next = q.peek();
            --n;
            if(t.left != null) q.offer(t.left);
            if(t.right != null) q.offer(t.right);
            if(n == 0) { //level complete
                n = q.size();
            }
        }
        return;  
    }
}
