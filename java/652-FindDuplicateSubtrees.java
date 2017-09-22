/*

Given a binary tree, return all duplicate subtrees. For each kind of 
duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4


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
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        if(root == null) return res;
        Map<String, List<TreeNode>> m = new HashMap<>();
        serialize(root, m);
        for(List<TreeNode> l : m.values()) {
            if(l.size() > 1) res.add(l.get(0));
        }
        return res;
    }

    private String serialize(TreeNode root, Map<String, List<TreeNode>> m) {
        if(root == null) return "";
        String res = String.valueOf(root.val) + "," + serialize(root.left, m) + "," + serialize(root.right, m);
        if(!m.containsKey(res)) m.put(res, new ArrayList<>());
        m.get(res).add(root);    
        return res;
    }
}
