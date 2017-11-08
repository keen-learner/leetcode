/*

Given a Binary Search Tree and a target number, return true if there exist 
two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

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
    public boolean findTarget(TreeNode root, int k) {
        if(root == null) return false;
        int req = k - root.val;
        if(s.contains(req)) return true;
        s.add(root.val);
        return findTarget(root.left, k) || findTarget(root.right, k);
    }

    private Set<Integer> s = new HashSet<>();

}


