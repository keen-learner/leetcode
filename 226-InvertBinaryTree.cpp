/*

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root-> right);
        return root;
    }
};

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> stk;
        stk.push(root);
    
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left, p->right);
            }
        }
        return root;
    }
    
};

