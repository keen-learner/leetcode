/*

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

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
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        TreeNode* prev = NULL;
        int res = INT_MAX;
        helper(root, prev, res);
        return res;
    }
    
    void helper(TreeNode* root, TreeNode*& prev, int& res) {
        if(root->left) helper(root->left, prev, res);
        if(prev) res = min(res, root->val - prev->val);
        prev = root;
        if(root->right) helper(root->right, prev, res);
    }
};
