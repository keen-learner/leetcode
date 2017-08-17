/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> curr = new ArrayList<>();
        q.offer(root);
        boolean flag = true;
        int n = 1;
        while(!q.isEmpty()) {
            System.out.println("1");
            TreeNode t = q.poll();
            --n;
            curr.add(t.val);
            if(t.left != null) q.offer(t.left);
            if(t.right != null) q.offer(t.right);
            if(n == 0) { //level complete
                if(flag == true) {
                    res.add(new ArrayList<>(curr));
                }
                else {
                    List<Integer> temp = new ArrayList<>(curr);
                    Collections.reverse(temp);
                    res.add(temp);
                }
                flag = !flag;
                curr.clear();
                n = q.size();
            }
        }
        return res;         
    }
}
