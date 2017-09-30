/*

Given a binary search tree (BST) with duplicates, find all the mode(s) (the 
most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that 
the implicit stack space incurred due to recursion does not count).

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
    int maxfreq = 0;
    Map<Integer, Integer> m = new HashMap();    
    
    public int[] findMode(TreeNode root) {
        helper(root); 
        List<Integer> res = new ArrayList();
        for(Map.Entry<Integer, Integer> e : m.entrySet()) {
            if(e.getValue() == maxfreq) res.add(e.getKey());
        }
        int[] f = new int[res.size()];
        for(int i = 0; i<res.size(); i++) f[i] = res.get(i);
        return f;
    }

    void helper(TreeNode root) {
        if(root == null) return;
        helper(root.left);
        m.put(root.val, m.getOrDefault(root.val, 0) + 1);
        maxfreq = Math.max(maxfreq, m.get(root.val));
        helper(root.right);
    }        
}
