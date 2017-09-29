/*


Given a binary tree, imagine yourself standing on the right side of it, return 
the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) return res;        
        helper(root, res, 0);
        return res;
    }
    void helper(TreeNode root, List<Integer> res, int l) {
        if(root == null) return;
        if(l == res.size()) res.add(root.val);
        helper(root.right, res, 1+l);
        helper(root.left, res, 1+l);
    }
}

class Solution1 {
    public List<Integer> rightSideView(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int count = 1;
        List<Integer> res = new ArrayList<>();
        if(root == null) return res;
        while(!q.isEmpty()){
            TreeNode t = q.peek();
            q.poll();
            if(t.left != null) q.offer(t.left);
            if(t.right !=  null) q.offer(t.right);
            --count;
            if(count == 0) {
                count = q.size();
                res.add(t.val);
            }
        }
        return res;
    }
}

