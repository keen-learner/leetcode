/*


Given a binary tree, imagine yourself standing on the right side of it, return 
the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res, int l) {
        if(!root) return;
        if(l == res.size()) res.push_back(root->val);
        helper(root->right, res, 1+l);
        helper(root->left, res, 1+l);
    }
};

class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        vector<int> res;
        if(!root) return res;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right)q.push(t->right);
            --count;
            if(!count) {
                count = q.size();
                res.push_back(t->val);
            }
        }
        return res;
    }
};
