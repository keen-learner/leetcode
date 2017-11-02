/*

Given the root of a tree, you are asked to find the most frequent subtree sum. The 
subtree sum of a node is defined as the sum of all the node values formed by 
the subtree rooted at that node (including the node itself). So what is the most 
frequent subtree sum value? If there is a tie, return all the values with the 
highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

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
    public int[] findFrequentTreeSum(TreeNode root) {
        if(root == null) return new int[0];
        helper(root);
        List<Integer> res = new ArrayList<>();
        for(Map.Entry<Integer, Integer> e : m.entrySet()) {
            if(e.getValue() == maxcount) res.add(e.getKey());
        }
        
        return res.stream().mapToInt(i->i).toArray();
    }
    private Map<Integer, Integer> m = new HashMap<>();
    private int maxcount = 0;
    private int helper(TreeNode root) {
        if(root == null) return 0;
        int l = helper(root.left);
        int r = helper(root.right);
        int sum = l+r+root.val;
        m.put(sum, m.getOrDefault(sum, 0)+1);
        maxcount = Math.max(maxcount, m.get(sum));
        return sum;
    }
}
