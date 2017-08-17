/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> curr = new ArrayList<Integer>();
        q.offer(root);
        int n = 1;
        while(!q.isEmpty()) {
            TreeNode t = q.poll();
            --n;
            curr.add(t.val);
            if(t.left != null) q.offer(t.left);
            if(t.right != null) q.offer(t.right);
            if(n == 0) { //level complete
                res.add(new ArrayList(curr));
                curr.clear();
                n = q.size();
            }
        }
        return res;    
    }
}
