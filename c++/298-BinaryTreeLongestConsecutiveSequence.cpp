/*

Given a binary tree, find the length of the longest consecutive sequence path.

 

The path refers to any sequence of nodes from some starting node to 
any node in the tree along the parent-child connections. The longest consecutive 
path need to be from parent to child (cannot be the reverse).

For example,

   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

*/

// Time:  O(n)
// Space: O(h)

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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        longestConsecutiveHelper(root, res);
        return res;
    }

    int longestConsecutiveHelper(TreeNode *root, int& res) {
        if (!root) {
            return 0;
        }

        const int left_len = longestConsecutiveHelper(root->left, res);
        const int right_len = longestConsecutiveHelper(root->right, res);

        int cur_len = 1;
        if (root->left && root->left->val == root->val + 1) {
            cur_len = max(cur_len, left_len + 1);
        }
        if (root->right && root->right->val == root->val + 1) {
            cur_len = max(cur_len, right_len + 1);
        }
        res = max(res, max(cur_len, max(left_len, right_len)));// NOTE: max of all 3 taken
        return cur_len;
    }
};
