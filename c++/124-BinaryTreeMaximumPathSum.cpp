/*

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting 
node to any node in the tree along the parent-child connections. The path must 
contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        helper(root, res); //will return max downward path through root; but will update res
        return res;
    }
private:
    int helper(TreeNode* root, int& res) {
        if(!root) return 0;
        int lmax = helper(root->left, res);
        int rmax = helper(root->right, res);
        int mx = max(root->val, max(root->val+lmax, root->val+rmax));
        res = max(res, max(mx, root->val+lmax+rmax));
        return mx;
    }
};
