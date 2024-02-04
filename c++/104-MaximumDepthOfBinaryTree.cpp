/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return (1+max(maxDepth(root ->left), maxDepth(root ->right)));
    }
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        int res = 0;

        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            -- count;
            
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            if (count == 0) {
                ++res;
                count = q.size();
            }
        }
        return res;
    }
};
