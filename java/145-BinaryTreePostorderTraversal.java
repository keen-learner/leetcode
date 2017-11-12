/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List <Integer> res = new ArrayList<>();
        TreeNode dummy = new TreeNode(0);
        dummy.left = root;
        TreeNode prev = null;
        TreeNode curr = dummy;
        while (curr != null) {
            if(curr.left == null) { // no left, go right
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
                    List<Integer> temp = trace_back(curr.left, prev);
                    for(Integer n: temp) res.add(n);
                    prev.right = null;
                    curr = curr.right;
                }
            }
        }
        return res;
    }
    private List<Integer> trace_back(TreeNode from, TreeNode to) {
        List<Integer> temp = new ArrayList<>();
        TreeNode curr = from;
        while(curr!=to) {
            temp.add(curr.val);
            curr = curr.right;
        }
        temp.add(to.val);
        Collections.reverse(temp);
        return temp;
    }
}

class Solution1 {
    public List<Integer> postorderTraversal(TreeNode root) {
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
                temp.visited = true;
                s.push(temp);
                s.push(new Node(temp.t.right, false));
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
