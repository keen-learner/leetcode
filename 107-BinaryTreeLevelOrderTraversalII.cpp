/*

Given a binary tree, return the bottom-up level order traversal of its 
nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        vector<vector<int>> res;
        vector<int> curr;
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            curr.push_back(f->val);
            -- count;
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            if (count == 0) {
                res.push_back(curr);
                curr.clear();
                count = q.size();
            }
        }
        reverse(res.begin(), res.end());
        // Following works too:
        // for(int i = 0, j = res.size()-1; i < j; ++i, --j) {
        //     swap(res[i], res[j]);
        // }
        return res;
    }
};

