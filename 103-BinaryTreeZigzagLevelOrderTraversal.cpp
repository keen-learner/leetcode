/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        vector<vector<int>> res;
        vector<int> curr;
        bool straight = false;
        
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            curr.push_back(f->val);
            -- count;
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            if (count == 0) {
                if(straight) {
                    reverse(curr.begin(), curr.end());
                }
                res.push_back(curr);
                curr.clear();
                count = q.size();
                straight = !straight;
            }
        }
        return res;
    }
};

