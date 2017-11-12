/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
    public List < Integer > inorderTraversal(TreeNode root) {
        List < Integer > res = new ArrayList < > ();
        TreeNode prev = null;
        TreeNode curr = root;
        while (curr != null) {
            if(curr.left == null) { // no left, go right
                res.add(curr.val);
                curr = curr.right;
            } 
            else { 
                prev  = curr.left;
                while(prev.right!=null && prev.right!=curr) prev = prev.right;
                if(prev.right == null) { // create threading and go left
                    prev.right = curr;
                    curr = curr.left;
                } 
                else { //remove threading and go right
                    prev.right = null;
                    res.add(curr.val);
                    curr = curr.right;
                }
            }
        }
        return res;
    }
}

class Solution2 {
    public List < Integer > inorderTraversal(TreeNode root) {
        List < Integer > res = new ArrayList < > ();
        Stack < TreeNode > stack = new Stack < > ();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }
        return res;
    }
}


class Solution1 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) return res;
        Stack<Node> s = new Stack<>();
        Node t = new Node(root, false);
        s.push(t);
        while(!s.isEmpty()) {
            Node temp = s.pop();
            if(temp.t == null) {
                
            } else if (temp.visited) {
                res.add(temp.t.val);
            } else {
                s.push(new Node(temp.t.right, false));
                temp.visited = true;
                s.push(temp);
                s.push(new Node (temp.t.left, false));
            }
        }
        return res;
    }
    class Node{
        boolean visited;
        TreeNode t;
        public Node(TreeNode n, boolean flag) {
            t = n;
            visited = flag;
        }
    }
}
